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

#### 常用指令

##### 代理

```sh
go env -w GOPROXY=https://goproxy.io/
go env -w GOPROXY=https://goproxy.cn,direct # 我用的
```

##### 安装

`go install` 是 Go 语言的一个常用命令，用于编译并安装 Go 包或可执行程序。它会将编译后的二进制文件安装到 `$GOPATH/bin` 目录（或 `$GOBIN` 目录）中，方便全局使用。

- 安装第三方工具或命令行程序（如 `goimports`、`gopls` 等）。
- 安装本地开发的 Go 程序。

```sh
go install [package]@[version]
```

如

```sh
go install golang.org/x/tools/cmd/goimports@latest
go install ./cmd/myapp
```

默认情况下，`go install` 会将二进制文件安装到 `$GOPATH/bin` 目录。

如果设置了 `$GOBIN`，则会安装到 `$GOBIN` 目录。

可以通过以下命令查看安装路径：

```sh
go env GOPATH
go env GOBIN
```

### 常识

#### 特点

[参考:大地(本笔记全部入门部分多有参考)](https://www.bilibili.com/video/BV1Rm421N7Jy/) 

> Go 语言不仅拥有静态编译语言的安全和高性能， 而且又达到了动态语言开发速度和易维护性。 有人形容 Go 语言： Go = C + Python , 说明 Go 语言既有 C 语言程序的运行速度， 又能达到 Python 语言的快速开发  
>
> 它的应用场景是目前互联网非常热门的几个领域，比如 WEB 开发、 区块链开发、 大型游戏服务端开发、 分布式/云计算开发  

#### 版本

> Go1.11 版本之后无需手动配置环境变量， 使用 go mod 管理项目， 也不需要非得把项目放到 GOPATH 
>
> 指定目录下， 你可以在你磁盘的任何位置新建一个项目。
>
> Go1.13 以后可以彻底不要 GOPATH 了

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

命令行：`go run hello.go` 直接运行。

编译成 exe 然后运行：`go build hello.go`，`./hello`。[菜鸟](https://m.runoob.com/go/go-tutorial.html)

#### 语法常识

后缀 `.go`

不使用分号

注释 C 风格

## 数据结构

### 变量

#### 定义

##### var

```go
var 变量名 类型 = 表达式
```

如

```go
var name string = "lr580 中文"
```

##### :=

在函数内部， 可以使用更简略的 := 方式声明并初始化变量。

注意： 短变量只能用于声明局部变量， 不能用于全局变量的声明  

```go
n := 10
```

例如：

```go
package main
import "fmt"
func main() {
	var name string = "lr580 是笨蛋"
	name2 := "lr581 不是笨蛋"
	fmt.Println(name)
	fmt.Println(name2)
}
```

## I/O

### 标准I/O

fmt 包里面给我们提供了一些常见的打印数据的方法， 比如： Print 、 Println、 Printf， 在我们实际开发中 Println、 Printf 用的非常多  

#### 输出

##### 常规

传入多个参数，逗号分隔。

- `Println` 在不同参数加空格末尾加换行，
- `Print` 不加空格，末尾无换行

```go
package main
import "fmt"
func main() {
	fmt.Println("一二", 2, 1/3)
	fmt.Println("我从来有", "觉得", "学GO", "开心过")
	fmt.Print("我从来没有", "觉得", "做科研")
	fmt.Print("开心过")
}
```

输出：

```
一二 2 0
我从来有 觉得 学GO 开心过
我从来没有觉得做科研开心过
```

##### 格式化

格式化输出 `Printf` [参考](https://www.cnblogs.com/jasmine456/p/18338866)

> - `%v`：值的默认格式表示。
> - `%+v`：结构体字段名和值的格式表示。
> - `%#v`：Go 语法表示的值。
> - `%T`：值的类型。
> - `%%`：百分号字面量。
>
> 对于特定类型：
>
> - `%d`：整数 (十进制)。
> - `%b`：整数 (二进制)。
> - `%o`：整数 (八进制)。
> - `%x`，`%X`：整数 (十六进制)。
> - `%f`：浮点数。
> - `%e`，`%E`：科学计数法格式的浮点数。
> - `%s`：字符串。
> - `%q`：双引号围绕的字符串。
> - `%t`：布尔值。

```go
i := 580
s := "hello"
fmt.Printf("整数: %d ", i)
fmt.Printf("字符串: %s ", s)
fmt.Printf("布尔值: %t\n", true)
```

输出

```
123 字符串: hello 布尔值: true
```



## 包

### 基本用法

导包

```go
import "fmt"
```



> ### 常用包
