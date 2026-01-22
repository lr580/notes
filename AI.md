部分理论参考 `机器学习.md` 和 `Python.md` 相关库(PyTorch 等)。

> 科研相关部分 (交通流量预测) 暂未公开，预定内容不变后可能公开。但有一些我的仓库公开了。

## 大模型

### LLM

> codex 生成：以下内容聚焦截至 2025 年 12 月公开披露的主流大模型，汇总厂商动态、特性以及可预见的不足，并给出选型建议。

> 国外厂商
>
> - GPT-5.2 / GPT-4o 家族（OpenAI）
> - Claude 3.5 Sonnet（Anthropic）
> - Gemini 3 Flash（Google）
> - Meta Llama 3（8B/70B，Meta） 开源
> - Mistral Large 2（Mistral AI）
> - Grok 系列（xAI）
>
> 国内厂商
>
> - DeepSeek R1 / DeepSeek-V3（DeepSeek）
> - Qwen2.5 / Qwen-Plus（阿里云通义）
> - Doubao 系列（字节跳动）
> - Hunyuan 系列（腾讯）
> - Kimi K2 系列（月之暗面 / Moonshot AI）
> - ERNIE 4.0 Turbo（百度）
> - SenseNova 5.0（商汤科技）
> - GLM-4.1V-9B-Thinking（智谱 AI）
> - Spark All-in-One + DeepSeek（华为 × 科大讯飞）
> - LongCat-Flash 系列（美团）
> - MiMo 系列（小米）



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

`config.toml` (model 可以改，如果换模型；base_url 替换对应的)，注意有 v1

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

MCP 服务器就是提供特定格式接口的 RPC 服务器，向这个服务器发送请求。一个 Python 原生服务器例子。一个 MCP  可以提供多个调用的 RPC。以一个 HTTP 模式为例。

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

##### 配置

[官网](https://code.claude.com/) ANTHROPIC (Claude-Sonnet 等) 家的。

注意英文文档比官方中文全。安装后参考配置。(不一定行，用 privnode 的话直接用他的一键配置)

`~/.claude` 的 `settings.json`。项目级别就根目录的 `.claude` 下对应。修改配置后必须重启 CLI 才能生效。注意不要有 v1

```json
{
  "env": {
    "ANTHROPIC_BASE_URL": "https://hk.api.renice.cc",
    "ANTHROPIC_AUTH_TOKEN": "sk-xxx"
  }
}
```

配置优先级: 项目配置 > 全局配置 > 系统环境变量

对 Linux，可以在 `~/.bashrc` 里：

```sh
export ANTHROPIC_BASE_URL="https://hk.api.renice.cc"
export ANTHROPIC_AUTH_TOKEN="sk-xxx"
```



##### 使用

在项目根目录创建 CLAUDE.md 文件，提供项目特定的上下文。如有下面文件，可以直接说 `开始执行任务`。

```markdown
我希望在当前目录完成一个基于 Python FastAPI 的本地 MCP 服务器，它提供 2 个 tools，分别输出两个固定的字符串输出作为测试。

请你编写代码，完成该任务。并写 md 文档：①告诉我如何本地运行 MCP 服务器，并让 claude code 配置和能调用该 MCP。②总结一个 MCP 服务器的技术要点，即模型调用什么接口，流程等。
```

##### 自定义MCP

安装已有的 MCP：

```sh
claude mcp add github-server -- npx -y @modelcontextprotocol/server-github
```

以一个 stdio 的 MCP 为例(按需启调用，用完关闭)，代码在最后：

```sh
# 查看已配置的 MCP 服务器列表
claude mcp list

# 添加一个 stdio 的 MCP，非全局可用
claude mcp add --transport stdio test-mcp-server -- python "D:\_lr580_desktop\codes\mcpTest\mcp_server.py"

# 会显示该服务器提供的所有工具
claude mcp get test-mcp-server

# 启用/禁用特定服务器
claude mcp enable test-mcp-server
claude mcp disable test-mcp-server

# 删除服务器配置
claude mcp remove test-mcp-server

# 查看服务器详细信息
claude mcp get test-mcp-server
```

使用，如对话：`调用你现有本地MCP里的全部工具`

> 手动添加或检查：`%USERPROFILE%\.claude.json`，如找到：
>
> ```json
> {
>   "projects": {
>     "D:/_lr580_desktop/codes/mcpTest": {
>       "mcpServers": {
>         "test-mcp-server": {
>           "type": "stdio",
>           "command": "python",
>           "args": ["D:\\_lr580_desktop\\codes\\mcpTest\\mcp_server.py"],
>           "env": {}
>         }
>       }
>     }
>   }
> }
> ```

本地测试可用性：(需要在 linux bash，如 git / claude，但 powershell / cmd 不行)

```sh
# 初始化
echo '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{}}' | python mcp_server.py

# 获取工具列表
echo '{"jsonrpc":"2.0","id":2,"method":"tools/list"}' | python mcp_server.py

# 调用 test_tool_1
echo '{"jsonrpc":"2.0","id":3,"method":"tools/call","params":{"name":"test_tool_1"}}' | python mcp_server.py
```

调用流程

> 1. **初始化阶段**: Claude Code 启动时，通过 stdin/stdout 与 MCP 服务器建立通信，发送 `initialize` 请求
> 2. **发现阶段**: Claude Code 调用 `tools/list` 方法获取可用工具列表
> 3. **选择阶段**: 模型根据用户请求和工具描述，决定调用哪个工具
> 4. **执行阶段**: 模型通过 `tools/call` 方法调用选定的工具，传递必要的参数
> 5. **响应阶段**: MCP 服务器执行工具逻辑，返回结果给模型
> 6. **整合阶段**: 模型将工具返回的结果整合到回复中，呈现给用户

完整服务端代码：

```python
import json
import sys
from typing import Any, Dict, List


class MCPServer:
    """基于 stdio 的 MCP (Model Context Protocol) 服务器"""

    def __init__(self):
        self.tools = [
            {
                "name": "test_tool_1",
                "description": "第一个测试工具，返回固定字符串",
                "inputSchema": {
                    "type": "object",
                    "properties": {},
                    "required": []
                }
            },
            {
                "name": "test_tool_2",
                "description": "第二个测试工具，返回固定字符串",
                "inputSchema": {
                    "type": "object",
                    "properties": {},
                    "required": []
                }
            }
        ]

    def handle_request(self, request: Dict[str, Any]) -> Dict[str, Any]:
        """处理 MCP 请求"""
        method = request.get("method")

        if method == "tools/list":
            return {
                "tools": self.tools
            }

        elif method == "tools/call":
            params = request.get("params", {})
            tool_name = params.get("name")

            if tool_name == "test_tool_1":
                return {
                    "content": [{
                        "type": "text",
                        "text": "这是来自测试工具1的固定输出：Hello from MCP Test Tool 1!"
                    }]
                }
            elif tool_name == "test_tool_2":
                return {
                    "content": [{
                        "type": "text",
                        "text": "这是来自测试工具2的固定输出：Welcome to MCP Test Tool 2!"
                    }]
                }
            else:
                return {
                    "content": [{
                        "type": "text",
                        "text": f"错误：未知的工具 '{tool_name}'"
                    }],
                    "isError": True
                }

        elif method == "initialize":
            return {
                "protocolVersion": "2024-11-05",
                "capabilities": {
                    "tools": {}
                },
                "serverInfo": {
                    "name": "test-mcp-server",
                    "version": "1.0.0"
                }
            }

        else:
            return {
                "error": {
                    "code": -32601,
                    "message": f"Method not found: {method}"
                }
            }

    def run(self):
        """运行 MCP 服务器（stdio 模式）"""
        # 确保输出不带缓冲
        sys.stdout.reconfigure(line_buffering=True)

        for line in sys.stdin:
            try:
                # 解析 JSON-RPC 请求
                request = json.loads(line.strip())

                # 处理请求
                response = self.handle_request(request)

                # 构建 JSON-RPC 响应
                json_rpc_response = {
                    "jsonrpc": "2.0",
                    "id": request.get("id"),
                    "result": response
                }

                # 输出响应
                print(json.dumps(json_rpc_response), flush=True)

            except json.JSONDecodeError as e:
                # JSON 解析错误
                error_response = {
                    "jsonrpc": "2.0",
                    "id": None,
                    "error": {
                        "code": -32700,
                        "message": f"Parse error: {str(e)}"
                    }
                }
                print(json.dumps(error_response), flush=True)

            except Exception as e:
                # 其他错误
                error_response = {
                    "jsonrpc": "2.0",
                    "id": request.get("id") if 'request' in locals() else None,
                    "error": {
                        "code": -32603,
                        "message": f"Internal error: {str(e)}"
                    }
                }
                print(json.dumps(error_response), flush=True)


if __name__ == "__main__":
    server = MCPServer()
    server.run()

```

### 对话工具

#### 概述

> 其他：元宝，豆包等。

#### Cherry Studio

[官网](https://www.cherry-ai.com/)。可以放缩大小，支持自动 MCP，抓包等。

#### Chatbox

[官网](https://chatboxai.app/zh/)。API 配置好后，不必开改善网络兼容性，记得换联网搜索为免费的。