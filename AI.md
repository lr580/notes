部分理论参考 `机器学习.md` 和 `Python.md` 相关库(PyTorch 等)。

> 科研相关部分 (交通流量预测) 暂未公开，预定内容不变后可能公开。但有一些我的仓库公开了。

## 大模型

### LLM

### 编程工具

#### 概述

> 其他：Cursor，CodeBuddy，Trae，Qoder 等。

使用 API 中转如 [privnode](https://privnode.com/)。

在 Linux 的 `~/` 对 Windows 是 `%USERPROFILE%`。

#### Codex

##### 配置

[官网](https://github.com/openai/codex) OpenAI (GPT) 家的。

安装后，安装 Vscode 的插件，可以拖拽到右侧侧边栏 (CHAT)。

配置 (API 中转)：

在 `~/.codex`。新建两个文件：

`auth.json`

```json
{
  "OPENAI_API_KEY": "sk-替换为对应APIKEY"
}
```

`config.toml` (model 可以改，如果换模型；base_url 替换对应的)

```toml
model_provider = "privnode"
model = "gpt-5-codex"
model_reasoning_effort = "high"
disable_response_storage = true

[model_providers.privnode]
name = "Privnode"
base_url = "https://us1.api.renice.cc/v1"
wire_api = "responses"
#env_key = "custom"
requires_openai_auth = true
```

##### 使用

在 `log` 有日志。在 `sessions/YYYY/MM/DD` 有 jsnol 会话记录。

在项目根目录，创建系统提示词，可以新建一个 `AGENTS.md`，里边的内容就是提示词。例如一个内容为：

```md
请你总是以中文诗词的输出格式回答我的问题。
```

在该目录下打开 codex 对话，会发现有效果。

##### 自定义MCP

MCP 服务器就是提供特定格式接口的 RPC 服务器，向这个服务器发送请求。一个 Python 原生服务器例子。一个 MCP  可以提供多个调用的 RPC。

使用步骤：

1. 先启动挂着服务器

   ```sh
   python src/mcp_server.py
   ```

2. 注册 MCP 

   ```sh
   codex mcp add local-secret-service --url http://127.0.0.1:8718
   ```

   > 删除：
   >
   > ```sh
   > codex mcp remove local-secret-service
   > ```

3. 打开 codex cli，输入提示词即可调用，如：

   ```
   调用MCP方法 local-secret-service
   ```

完整代码例子(codex 生成，可以用 fastapi 等简化，这里略。)

> 接口列表：
>
> MCP / JSON-RPC 接口
>
> - `POST /`：所有 LLM 相关流量都通过根路径完成。服务会解析单个或批量 JSON-RPC 请求并传入 `_handle_rpc_call`，在没有 `id` 时视作通知并不返回值（`src/mcp_server.py:115`）。
> - `initialize`（必要）：LLM 在注册连接后立即调用，用于完成握手并确认协议版本、工具/资源能力位。服务返回 `protocolVersion`（默认 `2025-06-18`）、`capabilities` 以及 `serverInfo`（`src/mcp_server.py:152`）。
> - `tools/list`（必要）：Codex CLI 或其它 MCP 客户端用它列出可用工具；响应根据 `MANIFEST["tools"]` 构造。LLM 借此获知 `get_secret` 以及输入参数结构（`src/mcp_server.py:160`、`src/mcp_server.py:185`）。
> - `resources/list`（半必要/空能力）：当前固定返回空数组，表示没有资源端点。LLM 会当作能力探测的一部分，以确认只需调用工具即可，但结果不影响核心功能（`src/mcp_server.py:164`）。
> - `tools/call`（必要）：LLM 真正执行操作时触发。只接受 `name="get_secret"`，`arguments.include_metadata` 控制是否把来源附加在文本中；未知工具会返回 `-32000` 错误，供 LLM 做回退处理（`src/mcp_server.py:168`、`src/mcp_server.py:172`）。
>
> LLM 端使用方式
>
> 1. Codex CLI 通过 `codex mcp add local-secret-service --url http://127.0.0.1:8718` 注册服务，随后自动执行 `initialize` → `tools/list` → `resources/list` 来建立上下文（`README.md:89`）。
> 2. 当用户在会话中请求秘钥时，LLM 调用 `tools/call`，按需设置 `include_metadata=true/false` 来决定响应文本是否带来源说明；服务会把秘钥封装成 `content` 数组返回（`src/mcp_server.py:175`）。
> 3. `SECRET_VALUE` 被写死为 `codex-hardcoded-secret`，LLM 只能读到该示例值；若要用于真实机密，需要开发者改写常量或接入安全存储（`src/mcp_server.py:42`）。
> 4. `MCP_HOST`、`MCP_PORT` 允许部署者调整监听地址，LLM 端只需获知最终 URL 即可连接；多实例或远程部署时尤其有用（`src/mcp_server.py:207`）。
>
> HTTP/REST 接口
>
> - `GET /manifest`（额外/诊断）：直接返回硬编码的 `MANIFEST`，用于在懒加载或人工调试时查看可用工具、描述和输入 schema。LLM 一般不会主动访问此接口，但在接入前的自动化探测中可以读取它以校验能力（`src/mcp_server.py:19`、`src/mcp_server.py:53`）。
> - `GET /status`（额外/诊断）：返回 `{ "status": "ok" }`，供健康检查或监控确认端口在线。LLM 不会使用该接口，通常由外部探针或脚本调用（`src/mcp_server.py:57`）。
> - `POST /invoke`（额外/调试）：接受形如 `{"tool": "get_secret", "params": {"include_metadata": true}}` 的 JSON，有且仅有 `get_secret` 可调用。该接口主要供人工/脚本调试，LLM 不会直接走 REST 路径（`src/mcp_server.py:63`）。

```python
"""
Simple standalone MCP-compatible HTTP service that exposes a get_secret tool.

Run with:
    python src/mcp_server.py
Override MCP_HOST / MCP_PORT (optional) to change listen address.
"""

from __future__ import annotations

import json
import logging
import os
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, HTTPServer
from typing import Any, Dict, List, Optional


MANIFEST: Dict[str, Any] = {
    "name": "local-secret-service",
    "version": "1.0.0",
    "description": "Local MCP service that returns a stored secret via get_secret.",
    "tools": [
        {
            "name": "get_secret",
            "description": "Return the stored secret. Optionally include the retrieval metadata.",
            "input_schema": {
                "type": "object",
                "properties": {
                    "include_metadata": {
                        "type": "boolean",
                        "description": "Whether to include the secret source metadata.",
                        "default": False,
                    }
                },
            },
        }
    ],
}


SECRET_VALUE = "codex-hardcoded-secret"
"""Fixed secret returned by the MCP service."""


class MCPHTTPServer(HTTPServer):
    """Customized server class to keep typing hints consistent."""


class MCPRequestHandler(BaseHTTPRequestHandler):
    server: MCPHTTPServer

    def do_GET(self) -> None:  # noqa: N802
        if self.path == "/manifest":
            self._send_json(MANIFEST)
            return
        if self.path == "/status":
            self._send_json({"status": "ok"})
            return

        self._send_json({"error": "Not Found"}, status=HTTPStatus.NOT_FOUND)

    def do_POST(self) -> None:  # noqa: N802
        content_length = int(self.headers.get("Content-Length", 0))
        body = self.rfile.read(content_length) if content_length else b"{}"

        if self.path == "/":
            self._handle_rpc(body)
            return

        if self.path != "/invoke":
            self._send_json({"error": "Not Found"}, status=HTTPStatus.NOT_FOUND)
            return

        try:
            payload = json.loads(body)
        except json.JSONDecodeError:
            self._send_json({"error": "Invalid JSON payload"}, status=HTTPStatus.BAD_REQUEST)
            return

        tool = payload.get("tool")
        params = payload.get("params") or {}

        if tool == "get_secret":
            self._handle_get_secret(params)
            return

        self._send_json(
            {"error": f"Unknown tool '{tool}'", "supported_tools": [tool["name"] for tool in MANIFEST["tools"]]},
            status=HTTPStatus.BAD_REQUEST,
        )

    def log_message(self, format: str, *args: Any) -> None:  # noqa: A003
        logging.info("%s - %s", self.address_string(), format % args)

    def _handle_get_secret(self, params: Dict[str, Any]) -> None:
        include_metadata = bool(params.get("include_metadata"))

        result: Dict[str, Any] = {"secret": SECRET_VALUE}
        if include_metadata:
            result["source"] = "constant:SECRET_VALUE"

        self._send_json({"result": result})

    def _send_json(self, payload: Dict[str, Any], status: HTTPStatus = HTTPStatus.OK) -> None:
        data = json.dumps(payload).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    # === JSON-RPC / MCP handling ===

    def _handle_rpc(self, body: bytes) -> None:
        try:
            payload = json.loads(body) if body else {}
        except json.JSONDecodeError:
            self._send_json({"error": "Invalid JSON payload"}, status=HTTPStatus.BAD_REQUEST)
            return

        if isinstance(payload, list):
            responses: List[Dict[str, Any]] = []
            for call in payload:
                response = self._handle_rpc_call(call)
                if response is not None:
                    responses.append(response)

            if responses:
                self._send_json(responses)  # type: ignore[arg-type]
            else:
                self._send_json({}, status=HTTPStatus.NO_CONTENT)
            return

        response = self._handle_rpc_call(payload)
        if response is None:
            self._send_json({}, status=HTTPStatus.NO_CONTENT)
        else:
            self._send_json(response)

    def _handle_rpc_call(self, call: Dict[str, Any]) -> Optional[Dict[str, Any]]:
        method = call.get("method")
        rpc_id = call.get("id")
        params = call.get("params") or {}

        logging.info("RPC call received: method=%s id=%s params=%s", method, rpc_id, params)

        if rpc_id is None:
            logging.info("Notification received for method=%s; acknowledging without response", method)
            return None

        if method == "initialize":
            result = {
                "protocolVersion": params.get("protocolVersion", "2025-06-18"),
                "capabilities": {"tools": {"listChanged": False}, "resources": {"listChanged": False}},
                "serverInfo": {"name": MANIFEST["name"], "version": MANIFEST["version"]},
            }
            return self._rpc_result(rpc_id, result)

        if method == "tools/list":
            result = {"tools": self._rpc_tools(), "nextCursor": None}
            return self._rpc_result(rpc_id, result)

        if method == "resources/list":
            result = {"resources": [], "nextCursor": None}
            return self._rpc_result(rpc_id, result)

        if method == "tools/call":
            name = params.get("name")
            arguments = params.get("arguments") or {}

            if name != "get_secret":
                return self._rpc_error(rpc_id, code=-32000, message=f"Unknown tool '{name}'")

            include_metadata = bool(arguments.get("include_metadata"))
            text = SECRET_VALUE
            if include_metadata:
                text = f"secret: {SECRET_VALUE}\nsource: constant:SECRET_VALUE"

            result = {"content": [{"type": "text", "text": text}], "isError": False}
            return self._rpc_result(rpc_id, result)

        return self._rpc_error(rpc_id, code=-32601, message=f"Method '{method}' not implemented")

    def _rpc_tools(self) -> List[Dict[str, Any]]:
        tools: List[Dict[str, Any]] = []
        for tool in MANIFEST["tools"]:
            tools.append(
                {
                    "name": tool["name"],
                    "description": tool.get("description", ""),
                    "inputSchema": tool.get("input_schema", {}),
                }
            )
        return tools

    def _rpc_result(self, rpc_id: Any, result: Dict[str, Any]) -> Dict[str, Any]:
        return {"jsonrpc": "2.0", "id": rpc_id, "result": result}

    def _rpc_error(self, rpc_id: Any, *, code: int, message: str) -> Dict[str, Any]:
        return {"jsonrpc": "2.0", "id": rpc_id, "error": {"code": code, "message": message}}


def run() -> None:
    logging.basicConfig(level=logging.INFO, format="[%(asctime)s] %(levelname)s: %(message)s")

    host = os.environ.get("MCP_HOST", "127.0.0.1")
    port = int(os.environ.get("MCP_PORT", "8718"))

    server = MCPHTTPServer((host, port), MCPRequestHandler)

    logging.info("Serving MCP on http://%s:%d", host, port)
    logging.info(
        "Use tool 'get_secret' via POST /invoke with payload {\"tool\": \"get_secret\", \"params\": {\"include_metadata\": true}}"
    )

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        logging.info("Shutting down MCP service...")
    finally:
        server.server_close()


if __name__ == "__main__":
    run()
```

手动调用测试：

```bash
# 查看 manifest
curl http://127.0.0.1:8718/manifest

# 调用工具
curl -X POST http://127.0.0.1:8718/invoke `
  -H "Content-Type: application/json" `
  -d "{\"tool\":\"get_secret\",\"params\":{\"include_metadata\":true}}"
```

#### Claude Code

[官网](https://code.claude.com/) ANTHROPIC (Claude-Sonnet 等) 家的。

注意英文文档比官方中文全。安装后参考配置。(不一定行，用 privnode 的话直接用他的一键配置)

`~/.claude` 的 `settings.json`。

```json
{
  "env": {
    "ANTHROPIC_BASE_URL": "https://hk.api.renice.cc",
    "ANTHROPIC_AUTH_TOKEN": "sk-xxx"
  }
}
```

### 对话工具

#### 概述

> 其他：元宝，豆包等。

#### Cherry Studio

[官网](https://www.cherry-ai.com/)。可以放缩大小，支持 MCP 等。

#### Chatbox

[官网](https://chatboxai.app/zh/)。API 配置好后，不必开改善网络兼容性，记得换联网搜索为免费的。