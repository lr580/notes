# 基础

## 基本概念

### 使用

#### 安装

随机参考官方文档了。

[官方代码仓库](https://github.com/golang/go) [官方文档](https://go.dev/doc/tutorial/getting-started) [下载](https://go.dev/dl/)

安装，对 windows 而言直接下安装包无脑 next 即可。检查安装：

```sh
go version
go env
```

#### vscode

vscode 的话，直接安装名为 go 的插件。[参考](https://blog.csdn.net/sanqima/article/details/132030537)。GOPATH 环境变量会自己好，不用管。

设置 GOROOT 环境变量

配置插件：右击插件-扩展设置。

测试代码：(`hello.go`)

```go
package main
import "fmt"
func main() {
	fmt.Println("hello world!")
}
```

命令行：`go run hello.go`。
