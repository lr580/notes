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

##### 格式化

go fmt 主要用于格式化文档， 让所有人的代码风格保持一致  

```sh
go fmt main.go
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

##### 命名规范

要求：

1. 数字、 字母、 下划线组成  
2. 标识符开头不能是数字  
3. 标识符不能是保留字和关键字  
4. 区分大小写

建议：

1. 变量名称建议用名词， 方法名称建议用动词  
2. 变量命名一般采用驼峰式， 当遇到特有名词（缩写或简称， 如 DNS） 的时候， 特有名词根据是否私有全部大写或小写

代码风格：

1. 代码每一行结束后不用写分号（ ;）  

2. 左括号紧接着语句不换行

3. 运算符左右建议各加一个空格  ` a = b + c`

4. go fmt 主要用于格式化文档， 让所有人的代码风格保持一致  

   ```sh
   go fmt main.go
   ```

   

##### var

```go
var 变量名 类型 = 表达式
```

如

```go
var name string = "lr580 中文"
var name2 = "自动类型推断所以name2=string"
```

一次多个

```go
var name1, name2 string
name1 = "张3"
name2 = "李4"
```

多个定义+赋值 (类型推导了，根据等式右边推断了 a 的类型)

```go
var a, b, c = 1/3, 1.0/3, false
```

多个声明+指定

```go
var (a string
    b int
    c bool) // 括号可以单独一行，但 a,b,c要不同行
a = "张3"
b = 10
c = true
```

上面的括号也可以写成：

```go
var (
    a string
    b int
    c bool
)
```

批量+赋值

```go
var (
    a string = "张3"
    b int    = 10
    c bool   = true
)
```

不赋值会有默认值，但**声明了变量但不使用会报错**。Go 编译器要求所有声明的变量都必须被使用

```go
var x int
fmt.Println(x) // 0
```

> 整型和浮点型变量的默认值为 0。 字符串变量的默认值为空字符串。 布尔型变量默认为 false。 切片、 函数、 指针变量的默认为 nil  

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

```go
m1, m2, m3 := 10, 20, 30
fmt.Println(m1, m2, m3)
```

##### 匿名变量

```go
func getInfo() (int, string) {
    return 10, "张三"
}
func main() {
    _, username := getInfo()
    fmt.Println(username)
}
```

匿名变量不占用命名空间， 不会分配内存， 所以匿名变量之间不存在重复声明  

_多用于占位， 表示忽略值。  

#### 常量

##### 使用

常量的声明和变量声明非常类似， 只是把 var 换成了 const， 常量在定义的时候必须赋值  

```go
const lr = 580
const (
    pi = 3.1415
    e = 2.7182
)
```

const 同时声明多个常量时， 如果省略了值则表示和上面一行的值相同  

```go
const (
    n1 = 100
    n2
    n3
)
fmt.Println(n1, n2, n3)
```

常量声明了可以不使用

##### iota

iota 是 golang 语言的常量计数器,

只能在常量的表达式中使用。

iota 在 const 关键字出现时将被重置为 0(const 内部的第一行之前)， const 中每新增一行常量声明将使 iota 计数一次(iota 可理解为 const 语句块中的行索引)

1. iota 只能在常量的表达式中使用  

  ```go
  // fmt.Println(iota) 不可以
  ```

2. 每次 const 出现时， 都会让 iota 初始化为 0.  

  ```go
  const a = iota // a=0
  const (
      b = iota //b=0
      c //c=1
  )
  ```

3. const iota 使用_跳过某些值 

  ```go
  const (
      n1 = iota //0
      n2 //1
      _
      n4 //3
  )
  ```

4. iota 声明中间插队 

  ```go
  const (
      n1 = iota //0
      n2 = 100 //100
      n3 = iota //2
      n4 //3
  )
  const n5 = iota //0
  ```

5. 多个 iota 定义在一行  

   ```go
   const (
       a, b = iota + 1, iota + 2 //1,2
       c, d //2,3
       e, f //3,4
   )
   ```

### 数据类型

#### 概述

##### 分类

语言中数据类型分为： 基本数据类型和复合数据类型

基本数据类型有：整型、 浮点型、 布尔型、 字符串

复合数据类型有：数组、 切片、 结构体、 函数、 map、 通道（channel） 、 接口等

##### 类型

输出类型：

```go
var num int64 = 580
fmt.Printf("值:%v 类型%T", num, num) // 值:580 类型int64
```

##### 占用字节数

unsafe.Sizeof(n1) 是 unsafe 包的一个函数， 可以返回 n1 变量占用的字节数  

```go
import (
    "fmt"
    "unsafe"
)
// ...
fmt.Println(unsafe.Sizeof(num))  // 8
fmt.Println(unsafe.Sizeof(true)) // 1
```

##### 类型转换

强制类型转换， 没有隐式类型转换  

```go
var num1 int8
num1 = 127
num2 := int32(num1)
fmt.Printf("值:%v 类型%T", num2, num2) //值:127 类型 int32
```

```go
var a int16 = 580
var b int32 = 1437
var c = int32(a) + b*1000 // 不转报错
fmt.Println(c)
```



#### 整型

整型分为以下两个大类：

有符号整形按长度分为： int8、 int16、 int32、 int64

对应的无符号整型： uint8、 uint16、 uint32、 uint64

默认 int 是多少取决于操作系统位数是多少，如 64 位 int = int64，uint 同理

> 在使用 int 和 uint 类型时， 不能假定它是 32 位或 64 位的整型， 而是考虑 int 和 uint可能在不同平台上的差异  
>
> 实际项目中整数类型、 切片、 map 的元素数量等都可以用 int 来表示。 在涉及到二进制传输、 为了保持文件的结构不会受到不同编译目标平台字节长度的影响， 不要使用 int 和 uint  ：为了确保跨平台的一致性，建议使用具有明确长度的整数类型

uintptr 是无符号整型， 用于存放一个指针

```go
var num int64
num = 580
fmt.Printf("值:%v 类型%T", num, num) // 值:580 类型int64
```

类型转换可以直接转，如 `num2 := int32(num1)`

更多格式

```go
x4 := 1_000_000_007
fmt.Printf("%b %o %x %d\n", x4, x4, x4, x4) // 不同进制
// 111011100110101100101000000111 7346545007 3b9aca07 1000000007
x5 := 0x1p31 //可以用指数，等价于 1 * 2^31, 也可以 1p-31,默认 float
x5--
fmt.Printf("%v %b %x\n", int(x5), int(x5), x5+1) // 不过小数也可以 %x，这里就是原汤化原食输出 0x1p31
```

#### 浮点型

支持两种浮点型数： float32 和 float64。 这两种浮点型数据格式遵循 IEEE 754 标准： float32 的浮点数的最大范围约为 3.4e38， 可以使用常量定义： math.MaxFloat32。 float64 的浮点数的最大范围约为 1.8e308， 可以使用一个常量定义： math.MaxFloat64。  

浮点数默认是 float64  

```go
num := 2. / (2.5 + .5)
fmt.Printf("%f, %.2f, %T\n", num, num, num)
// 0.666667, 0.67, float64
```

#### 布尔值

bool true / false

布尔类型变量的默认值为 false

Go 语言中不允许将整型强制转换为布尔型；在 go 语言中数值类型没法直接转换成 bool 类型 bool 类型也没法直接转换成数值类型  

布尔型无法参与数值运算， 也无法与其他类型进行转换。

```go
fmt.Println(unsafe.Sizeof(true)) // 1
```

#### 字符串

##### 基础

双引号；string；反引号可以多行；len 求长度

```go
var s = `即得易见平凡
仿照上例显然` // 不要对齐不然会有多余空格
fmt.Println(s, len(s)) //一个中文3个长度
```

要修改字符串， 需要先将其转换成[]rune 或[]byte， 完成后再转换为 string。 无论哪种转换，都会重新分配内存， 并复制字节数组  

```go
s := "abc蓝莓熊"
fmt.Println(s[0], s[3]) // 97 232；中文不能取下标，见字符一节
```

##### 常用函数

字符串拼接：+ 或 `fmt.Sprintf` (后者常用其他类型转 str)

```go
var str1 = "主席树"
var str2 = "可持久化权值线段树"
fmt.Println(str1 + str2)
var str3 = fmt.Sprintf("%v=%v", str1, str2)
fmt.Println(str3)
```

strings 包有常用库函数：

```go
var str4 = "020--5800---5800"
fmt.Println(strings.Split(str4, "--")) // [020 5800 -5800]
fmt.Println(strings.Contains(str4, "5800"))
fmt.Println(strings.HasPrefix(str4, "020"))
fmt.Println(strings.HasSuffix(str4, "0")) // all true
fmt.Println(strings.Index(str4, "20"))    // 1
fmt.Println(strings.Index(str4, "3"))     // -1
fmt.Println(strings.LastIndex(str4, "0"))
fmt.Println(strings.Join([]string{"020", "5800", "5800"}, "-"))
```

##### 类型转换

###### 其他->字符串

```go
package main

import (
	"fmt"
	"strconv"
)

func main() {
	// 通过strconv  把其他类型转换成string类型
	/* FormatInt
	参数1：int64 的数值
	参数2：传值int类型的进制*/
	var i int = 20
	str1 := strconv.FormatInt(int64(i), 10)
	fmt.Printf("值：%v 类型：%T\n", str1, str1)

	/* 参数 1：要转换的值
	参数 2：格式化类型 'f'（-ddd.dddd）、
		 'b'（-ddddp±ddd，指数为二进制）、
		 'e'（-d.dddde±dd，十进制指数）、
		 'E'（-d.ddddE±dd，十进制指数）、
		 'g'（指数很大时用'e'格式，否则'f'格式）、
		 'G'（指数很大时用'E'格式，否则'f'格式）。
	 参数 3: 保留的小数点 -1（不对小数点格式化）
	 参数 4：格式化的类型 传入 64  32*/
	var f float32 = 20.231363
	str2 := strconv.FormatFloat(float64(f), 'f', 4, 32)
	fmt.Printf("值：%v 类型：%T\n", str2, str2) // 四舍五入

	str3 := strconv.FormatBool(true) //没有任何意义
	fmt.Printf("值：%v 类型：%T\n", str3, str3)

	a := 'b' //没有任何意义
	str4 := strconv.FormatUint(uint64(a), 10)
	fmt.Printf("值：%v 类型：%T\n", str4, str4) //值：98 类型：string
}
```

###### 字符串->其他

```go
x, _ := strconv.ParseInt("580", 10, 64)
fmt.Printf("值：%v 类型：%T\n", x, x)
f, _ := strconv.ParseFloat("580.1437", 64)
fmt.Printf("值：%v 类型：%T\n", f, f)
b, _ := strconv.ParseBool("true")
fmt.Printf("值：%v 类型：%T\n", b, b)
```

#### 字符

单引号，可以是汉字

uint8 类型， 或者叫 byte 型， 代表了 ASCII 码的一个字符。

rune 类型， 代表一个 UTF-8 字符。

当需要处理中文、 日文或者其他复合字符时， 则需要用到 rune 类型。 rune 类型实际是一个int32

Go 使用了特殊的 rune 类型来处理 Unicode， 让基于 Unicode 的文本处理更为方便， 也可以使用 byte 型进行默认字符串处理， 性能和扩展性都有照顾

```go
a := '张'       //rune
fmt.Println(a) // 24352而不是字符，且sizeof=4，无法len
fmt.Printf("%T %c\n", a, a) // int32 张
```

```go
s := "12345 下海打鲸鱼"
for i := 0; i < len(s); i++ { // byte
    fmt.Printf("%v(%c)", s[i], s[i])
}
fmt.Println()
for _, c := range s { // rune
    fmt.Printf("%v(%c)", c, c)
}
fmt.Println()
/* 49(1)50(2)51(3)52(4)53(5)32( )228(ä)184(¸)139()230(æ)181(µ)183(·)230(æ)137()147()233(é)178(²)184(¸)233(é)177(±)188(¼)
49(1)50(2)51(3)52(4)53(5)32( )19979(下)28023(海)25171(打)40120(鲸)40060(鱼)*/
```



## 函数

函数外边的每个语句都必须以关键字开始（var、 const、 func 等）  

函数可以不按顺序，即上面的函数调用下面的函数

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

整数指数会报错：

```go
x4 := 1_000_000_007
fmt.Printf("%e %e\n", x4, float32(x4))
// %!e(int=1000000007) 1.000000e+09
```

小数也可以二进制输出，即 %x

```go
x := 1.0 / 4
fmt.Printf("%b %o %x", x, x, x)
// 4503599627370496p-54 %!o(float64=0.25) 0x1p-02
```

浮点默认 6 位：

```go
num := 2. / (2.5 + .5)
fmt.Printf("%f, %.2f, %T\n", num, num, num)
// 0.666667, 0.67, float64
```

高精度第三方包：[decimal](https://github.com/shopspring/decimal)

科学计数法 

```go
fmt.Printf("%f\n", 1e9+7) // 大小写e都行
```



## 包

### 基本用法

导包

```go
import "fmt"
```

```go
import (
    "fmt"
    "math"
)
```



> ### 常用包
