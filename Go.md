



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

#### 包管理

go mod

> 在 Golang1.11 版本之前如果我们要自定义包的话必须把项目放在 GOPATH 目录。 Go1.11 版本之后无需手动配置环境变量， 使用 go mod 管理项目， 也不需要非得把项目放到 GOPATH指定目录下， 你可以在你磁盘的任何位置新建一个项目 , Go1.13 以后可以彻底不要 GOPATH  

##### init

在我们项目目录中用 go mod 命令生成一个 go.mod 文件管理我们项目的依赖

```sh
go mod init 项目名字
```

会在当前目录生成 `go.mod`，内容如下 (第一行module 项目名字)

```go
module golearn

go 1.24.0
```

如果有包，格式如下：

```go
require github.com/shopspring/decimal v1.4.0
```

> 还有 `go.sum` 文件，是自动生成的文件，用于校验依赖的完整性和一致性，它记录了依赖模块的版本、哈希值
>

##### get

安装包

cd 到项目目录，假设有包 `https://github.com/shopspring/decimal`

```go
go get github.com/shopspring/decimal
```

`-u` 标志的作用是：

- 更新依赖：它会强制更新指定的包及其依赖项到最新的版本（遵循 `go.mod` 文件中定义的版本约束）。
- 下载缺失的依赖：如果本地缺少某些依赖包，`-u` 会自动下载它们。

```go
go get -u github.com/gin-gonic/gin
```

##### install

编译并安装当前项目或指定的包，生成可执行文件，使用 `go install`

也可以装包

##### tidy

引入包以后可以使用 go mod tidy 增加丢失的 module 去掉未用的 module  

```go
go mod tidy
```

会删掉代码里从未用过的包。清理 `go.sum`

##### 其他

- download： download modules to local cache (下载依赖的 module 到本地 cache))
- edit： edit go.mod from tools or scripts (编辑 go.mod 文件)
- graph： print module requirement graph (打印模块依赖图))
- init： initialize new module in current directory (再当前文件夹下初始化一个新的module, 创建 go.mod 文件))
- tidy： add missing and remove unused modules (增加丢失的 module， 去掉未用的module)
- vendor： make vendored copy of dependencies (将依赖复制到 vendor 下)
- verify： verify dependencies have expected content (校验依赖 检查下载的第三方库有没有本地修改， 如果有修改， 则会返回非 0， 否则验证成功。 )
- why： explain why packages or modules are needed (解释为什么需要依赖)

### 常识

#### 特点

[参考:大地(本笔记全部入门部分多有参考)](https://www.bilibili.com/video/BV1Rm421N7Jy/) 

> Go 语言不仅拥有静态编译语言的安全和高性能， 而且又达到了动态语言开发速度和易维护性。 有人形容 Go 语言： Go = C + Python , 说明 Go 语言既有 C 语言程序的运行速度， 又能达到 Python 语言的快速开发  
>
> 它的应用场景是目前互联网非常热门的几个领域，比如 WEB 开发、 区块链开发、 大型游戏服务端开发、 分布式/云计算开发  

编译型语言

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

> 实际上可以中文命名变量名

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

**不赋值会有默认值**，但**声明了变量但不使用会报错**。Go 编译器要求所有声明的变量都必须被使用

```go
var x int
fmt.Println(x) // 0
```

> 整型和浮点型变量的默认值为 0。 字符串变量的默认值为空字符串。 布尔型变量默认为 false。 切片、 函数、 指针变量的默认为 nil  

##### :=

在函数内部， 可以使用更简略的 := 方式声明并初始化变量。

这是声明变量+初始化。如果要对已声明变量赋值，直接 = 即可。

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

##### 全局变量

全局变量是定义在函数外部的变量， 它在程序整个运行周期内都有效。 在函数中可以访问到全局变量  

```go
package main
import "fmt"
var lr = 58
func main() {
	lr *= 10
	fmt.Println(lr)
}
```

如果局部变量和全局变量重名， 优先访问局部变量，也就是大括号作用域。和 C 一样，可以凭空加大括号区分作用域

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

### 运算

#### 计算

##### 算术

整数除法整除

取余：`余数=被除数-(被除数/除数)*除数`，与 C 一样，不允许小数取余

```go
fmt.Println(10%3, -10%3, 10%-3, -10%-3) // 1 -1 1 -1
```

`++ --` 不是运算符，是语句，所以不能 `a = b++`，且只有 `a++` 没有 `++a`。支持小数(这点同 C)。

```go
i := 1.2
i++
fmt.Println(i) // 2.2
```

##### 逻辑

关系：`== != >= > <= <` 

```go
fmt.Println(3 > 2.9) // true
```

逻辑：`&& || !`，短路。`&&` 优先级高(同常规语言)

```go
func f1() bool {
	fmt.Println("f1")
	return false //若true，不执行f2,f3
}
func f2() bool {
	fmt.Println("f2")
	return false // 短路，不执行f3
}
func f3() bool {
	fmt.Println("f3")
	return true
}
// ...
if f1() || f2() && f3() { // 输出 f1, f2，不输出 f3, ok
    fmt.Println("ok")
}
```

##### 赋值

`= += -= *= /= %=`

##### 位运算

`& | ^ << >>` 分别是左移，右移 即 `001 -> 010` 和 `001 -> 000`。`>` 是 `->` 箭头方向。

#### 运算

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

##### 初始值

当你声明了一个变量 , 但却还并没有赋值时 , golang 中会自动给你的变量赋值一个默认零值。 这是每种类型对应的零值  

```go
bool -> false
numbers -> 0
string-> ""
pointers -> nil
slices -> nil
maps -> nil
channels -> nil
functions -> nil
interfaces -> nil
```

array 不能和 nil 比较，切片可以

##### type

类似 C/C++ typedef, using

```go
type i32 int32 // 自定义类型
type dbFunc func(int, int) int
type integer = int // 1.9 版本：别名
```

```go
var vv i32 = 666
fmt.Println(vv)
var a integer = 6
```

自定义类型和别名的区别：别名等价原本，自定义不等

```go
var a integer = 6
var b i32 = 6
fmt.Printf("%T %T\n", a, b) // int main.i32
```

type 可以放函数内或外，type 定义结构体也是

### 数据类型

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

###### byte[]

```go
fmt.Println([]byte("a你好")) // [97 228 189 160 229 165 189]
fmt.Println(string([]byte{97, 228, 189, 160, 229, 165, 189}))
// "a你好"
```



#### 字符

##### 常规

单引号，可以是汉字

byte 型， 本质是 uint8 类型， 代表了 ASCII 码的一个字符。

rune 类型， 代表一个 UTF-8 字符。

当需要处理中文、 日文或者其他复合字符时， 则需要用到 rune 类型。 rune 类型实际是一个int32

Go 使用了特殊的 rune 类型来处理 Unicode， 让基于 Unicode 的文本处理更为方便， 也可以使用 byte 型进行默认字符串处理， 性能和扩展性都有照顾

```go
// a := 'c'  // rune
a := '张' //rune
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

##### 常用方法

反向使用字符串 contains，可以求当前字符是否是某几个字符的一个

```go
if strings.ContainsRune("aeiou", b) { // ...
```

#### 复数

`complex64` 表示一个由两个 `float32` 类型的浮点数组成的复数，其中第一个浮点数表示实部，第二个浮点数表示虚部；还有 `complex128`，有内置方法 `real(), imag()`，有四则运算。构造：`c1 := complex(1.0, 2.0)` 为 1+2i

### 数组

#### array

##### 初始化

数组的长度是类型的一部分， 也就是说 [5]int 和 [10]int 是两个不同的类型  

> 数组对应的类型是 Slice（切片） ， Slice 是可以增长和收缩的动态序列  

0-indexed，越界panic

指定长度、初始值来初始化：

```go
var a [3]int
var b = [3]int{5, 8}
for i := 0; i < 3; i++ {
    fmt.Println(a[i] + b[i]) // 5 8 0
}
var c = []string{"白茶", "绿茶", "阿帕茶"}
fmt.Println(c) // 可以直接输出数组 [白茶 绿茶 阿帕茶]
var intArr2 [5]int = [...]int{1, -1, 9, 90, 12}
// var a, b [3]int 两个一样形状的数组
```

可以省略长度

```go
var d = [...]int{1437, 580} //大括号赋值 }单独一行的话最后一个元素要,
fmt.Printf("%T\n", d) // [2]int
arr := [...]int{1, 3, 5, 7, 8}
```

可以离散地赋值

```go
var e = [...]int{1: 10, 5: 80}
var f = [8]int{7: 9}
fmt.Println(e, f) // [0 10 0 0 0 80] [0 0 0 0 0 0 0 9]
```

##### 使用

输出 `%T` 可以得到长度信息，`len` 函数也可以得到长度，下面是两种遍历

```go
a := [3]int{1, 2, 3}
b := a // 复制
b[0] = 100
fmt.Println(a, b)   // [1 2 3] [100 2 3]
fmt.Println(a != b) // 但是不支持 >, <
b[0] = a[0]
fmt.Println(a == b)
for i := 0; i < len(a); i++ {
    fmt.Println(a[i])
}
for i, v := range a {
    fmt.Println(i, v)
}
```

##### 多维

只有第一次层可以推导长度，不可以用到其他维度

```go
s := [...][2]string{
    {"张三", "张量"},
    {"李四", "李性思维"},
    {"王舞", "酒吧舞"},//需要逗号这一行，无论[3][2]还是[...][2]都需要
}
fmt.Println(len(s), s) // 3 [[张三 张量] [李四 李性思维] [王舞 酒吧舞]]
```

多维数组 for i, v 的遍历 v 是一维数组，复制。

```go
a := [...][3]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
for _, row := range a {
    row[0] *= 2 // a 不变
}
fmt.Println(a)
```



##### 传值

不管几维，函数会复制整个数组

```go
func t2(x [3]int) { // 一定要写固定的长度，不能写[]int，多维同理
	for i := 0; i < len(x); i++ {
		x[i] *= 2
	}
	fmt.Println(x)
}
// ...
t2(a) // [2 4 6]
fmt.Println(a) // [1 2 3]
```

#### 切片

切片 slice 是一个拥有相同类型元素的可变长度的序列。 它是基于数组类型做的一层封装。它非常灵活， 支持自动扩容。

切片是一个引用类型， 它的内部结构包含地址、 长度和容量

切片的本质就是对底层数组的封装， 它包含了三个信息： 底层数组的指针、 切片的长度（len）和切片的容量（cap）  

##### 定义

如果不初始化是空，初始化一个空就不是

```go
var a []string
var b = []int{}
var c = []bool{false, true}
fmt.Println(a, b, c)              // [] [] [false true]
fmt.Println(a == nil, b == nil)   // true false
fmt.Printf("%T %T %T\n", a, b, c) // []string []int []bool
```

##### 运算

遍历与数组一样。不支持slice之间比较 `==, !=`，但可以与 nil 比较(见上面代码)

一个 nil 值的切片并没有底层数组；一个 nil 值的切片长度和容量都是 0。 但不能说一个长度和容量都是 0 的切片一定是 nil。所以要判断一个切片是否是空的， 要是用 len(s) == 0 来判断， 不应该使用 s == nil 来判断。  

```go
var s1 []int //len(s1)=0;cap(s1)=0;s1==nil
s2 := []int{} //len(s2)=0;cap(s2)=0;s2!=nil
s3 := make([]int, 0) //len(s3)=0;cap(s3)=0;s3!=nil
```

可以用类似 python 代码的方法用数组转切片，修改数组的切片影响数组本身

```go
ar := [5]int{99, 82, 44, 35, 3}
ar1 := ar[1:4]
ar1[0] *= 10 // 修改原数组，对 ar, ar1-4 都影响
ar2 := ar[1:]
ar3 := ar[:4]
ar4 := ar[:]
fmt.Println(ar1, ar2, ar3, ar4)
// [820 44 35] [820 44 35 3] [99 820 44 35] [99 820 44 35 3]
```

切片的长度就是它所包含的元素个数。

切片的容量是从它的第一个元素开始数， 到其底层数组元素末尾的个数。切片 s 的长度和容量可通过表达式 len(s) 和 cap(s) 来获取

切片可以再切，基于切片下标继续索引

切片是引用数据类型，修改切片会修改它的底层数组

```go
a := [...]string{"北京", "上海", "广州", "深圳", "成都", "重庆"}
fmt.Printf("a:%v type:%T len:%d cap:%d\n", a, a, len(a), cap(a))
b := a[1:3]
fmt.Printf("b:%v type:%T len:%d cap:%d\n", b, b, len(b), cap(b))
c := b[1:5]
fmt.Printf("c:%v type:%T len:%d cap:%d\n", c, c, len(c), cap(c))
//a:[北京 上海 广州 深圳 成都 重庆] type:[6]string len:6 cap:6
//b:[上海 广州] type:[]string len:2 cap:5
//c:[广州 深圳 成都 重庆] type:[]string len:4 cap:4
//第一个切片显然，从起点开始还有5个元素；第二个就是还有4个(cap)
// fmt.Println(b[2]) 不可以：越界
fmt.Println(c[0]) // 广州
c[0] = "星环城"
fmt.Println(a) // [北京 上海 星环城 深圳 成都 重庆]
```

##### make

不基于数组，动态创建切片，传入 T, size (元素数), cap (容量) 三个参数

```go
d := make([]int, 3, 5)
d[2] = 580
fmt.Println(d, len(d), cap(d)) // [0 0 580] 3 5
```

##### 添加

内建函数 append()可以为切片动态添加元素，每个切片会指向一个底层数组，这个数组的容量够用就添加新增元素。当底层数组不能容纳新增的元素时，切片就会自动扩容，扩完了再 append，所以我们通常都需要用原变量接收 append 函数的返回值 

```go
a := make([]int, 3, 5)
for i := 1; i <= 10; i++ {
    a = append(a, i)
    fmt.Printf("%v %d %d %p\n", a, len(a), cap(a), a)
}
```

append()函数还支持一次性追加多个元素 ，以及追加切片

```go
var b []int
b = append(b, 12, 34, 56)
fmt.Println(b)
c := []int{44, 888}
b = append(b, c...)
fmt.Println(b)
```

没有删除切片元素的专用方法， 使用切片本身的特性来删除元素  

```go
a := []int{30, 31, 32, 33, 34, 35, 36, 37}
// 要删除索引为 2 的元素
a = append(a[:2], a[3:]...)
fmt.Println(a) //[30 31 33 34 35 36 37]
```

##### 扩容

扩容策略：可查看 $GOROOT/src/runtime/slice.go 源码

> ```go
> newcap := old.cap
> doublecap := newcap + newcap
> if cap > doublecap {
>     newcap = cap
> } else {
>     if old.len < 1024 {
>         newcap = doublecap
>     } else {
>         // Check 0 < newcap to detect overflow
>         // and prevent an infinite loop.
>         for 0 < newcap && newcap < cap {
>             newcap += newcap / 4
>         }
>         // Set newcap to the requested cap when
>         // the newcap calculation overflowed.
>         if newcap <= 0 {
>             newcap = cap
>         }
>     }
> }
> ```
>
> 1. 如果新申请容量（cap） 大于 2 倍的旧容量（old.cap） ， 最终容量（newcap）就是新申请的容量（cap）  
> 2. 否则判断， 如果旧切片的长度小于 1024， 则最终容量(newcap)就是旧容量(old.cap)的两倍
> 3. 否则判断， 如果旧切片长度大于等于 1024， 则最终容量（newcap） 从旧容量（old.cap）开始循环增加原来的 1/4， 直到最终容量（newcap） 大于等于新申请的容量(cap)
> 4. 如果最终容量（cap） 计算值溢出， 则最终容量（cap） 就是新申请容量（cap） 
>
> 切片扩容还会根据切片中元素的类型不同而做不同的处理， 比如 int 和 string类型的处理方式就不一样。  

##### 复制

```go
b := []int{1, 4, 3, 7}
c := make([]int, 4, 4)
copy(c, b)
c[0] *= 2
fmt.Println(b, c)
```

##### 排序

sort 包可以对切片(但不能数组)排序 [文档](https://golang.org/src/sort)

```go
import (
	"fmt"
	"sort"
)
func h3() {
	a := []int{1, 4, 3, 7, 5, 8, 1}
	sort.Ints(a)
	fmt.Println(a)
}
```

其他类型，如 `sort.Float64s`, `sort.Strings`。

逆序排序：

```go
s := []string{"ABC", "abc", "0123", "ad"}
sort.Sort(sort.Reverse(sort.StringSlice(s)))
fmt.Println(s)
```

#### map

##### 定义

无序的基于 key-value 的数据结构，引用类型，初始化才能使用

map 类型的变量默认初始值为 nil， 需要使用 make()函数来分配内存，可以指定容量也可以不指定，没有 cap 有 len

```go
score := make(map[string]int, 8)
score["lr"] = 580
score["ac"] = 100
fmt.Printf("%v %T", score, score)
//map[ac:100 lr:580] map[string]int
occur := map[byte]bool{}
```

带初始值：

```go
score2 := map[string]string{
    "lr":    "580@ac.com",
    "lr580": "https://github.com/lr580",
}
fmt.Println(score2)
vowels := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
```

##### 使用

取下标返回两个值，分别代表值，是否存在(不存在值变成该类型零值)

```go
v, ok := score2["lr"]
fmt.Println(v, ok) // 580@ac.com true
v, ok = score2["LR"]
fmt.Println(v, ok) //  false
```

可以直接拿来 if (如果 value 是 bool)

```go
if vowels[word[j]] {
    occur[word[j]] = true
}
```

遍历：(无序) 元素顺序与添加键值对的顺序无关  

```go
for k, v := range score2 {
    fmt.Println(k, v)
} // 若 for k := range scoreMap，只遍历键
```

删除：存在就删除，不存在就不操作

```go
delete(score2, "lr")
```

类似 C++，不存在时要赋值会有默认值

```go
score["AA"]++
fmt.Println(score) // AA 项是 1
```



##### 嵌套结构

如 slice 的元素是 map

```go
var mapSlice = make([]map[string]string, 3)
for index, value := range mapSlice {
    fmt.Printf("index:%d value:%v\n", index, value)
}
fmt.Println("after init")
// 对切片中的 map 元素进行初始化
mapSlice[0] = make(map[string]string, 10)
mapSlice[0]["name"] = "小王子"
mapSlice[0]["password"] = "123456"
mapSlice[0]["address"] = "海淀区"
for index, value := range mapSlice {
    fmt.Printf("index:%d value:%v\n", index, value)
}
// index:0 value:map[address:海淀区 name:小王子 password:123456]
// index:1 value:map[]
// index:2 value:map[]
```

map 的元素是 slice

```go
var sliceMap = make(map[string][]string, 3)
fmt.Println(sliceMap)
fmt.Println("after init")
key := "中国"
value, ok := sliceMap[key]
if !ok { // 执行
    value = make([]string, 0, 2)
    fmt.Println("init")
}
value = append(value, "北京", "上海")
sliceMap[key] = value
fmt.Println(sliceMap) // map[中国:[北京 上海]]
```

### 指针

##### 基本

跟 C 一样，& 取地址，* 取变量值；类型是 *int 等。

```go
a := 10
var b *int = &a // 可以不写类型
c := &a         // 等价
*b *= 2
fmt.Printf("%p %v %T\n", a, c, c)
fmt.Println(b, *b, &b)
// %!p(int=20) 0xc0001060a8 *int
// 0xc0001060a8 20 0xc000108058
```

##### 函数

```go
func modify(a *int) {
	*a *= 2
}
// ...
a := 580
modify(&a)
fmt.Println(a) // 1160
```

##### new

```go
var a *int
a = new(int) // 默认值0
b := new(int)
*b = 100
fmt.Println(*a, *b)
```

##### 数组指针

指针数组

```go
var p [3]*int
a, b, c := 10, 20, 30
p[0], p[1], p[2] = &a, &b, &c
fmt.Println(*p[0], *p[1], *p[2])
```

数组指针

```go
a := [3]int{5, 8}
var p *[3]int = &a
fmt.Println(p[0], p[1], p[2]) // 两个取值等效
fmt.Println((*p)[0], (*p)[1], (*p)[2])
```

二维

```go
arr := [2][3]int{{1, 2, 3}, {7, 8, 9}}
p := &arr
for i := 0; i < len(p); i++ {
    for j := 0; j < len(p[i]); j++ {
        p[i][j] *= 10
        fmt.Printf("%d ", p[i][j])
    }
}
```

##### 结构体指针

在 Golang 中支持对结构体指针直接使用.来访问结构体的成员  

`p2.name` 对指针 `p2` 等价于 `(*p2).name`

### 结构体

> #### 基本
>

Golang 中没有“类”的概念，不面向对象；不支持重载运算符

##### 定义

```go
var p1 node
p1.x, p1.y = 5, 80
fmt.Println(p1) // {5 80}
fmt.Printf("%v %#v %T\n", p1, p1, p1)
// {5 80} main.node{x:5, y:80} main.node
```

带初始化：

```go
p5 := node{58, 1437}
p6 := node{
    58,
    1437,
} // 注意区别：逗号与否
fmt.Println(p5, p6)
```

或者 new，但注意这时候类型是指针

```go
var p2 = new(node)
p2.x, p2.y = 5, 80
fmt.Println(p2) // &{5 80}
fmt.Printf("%v %#v %T %T\n", p2, p2, p2, *p2)
// &{5 80} &main.node{x:5, y:80} *main.node main.node
```

或者本质 new：

```go
p3 := &node{}
p4 := &node{5, 80}
fmt.Println(p3, p4) // &{0 0} &{5 80}
```

不按顺序 / partial 赋值的话，可以附 key；指针或一般都这样

```go
p7 := node{y: 6}
p8 := node{x: 7} // 只7不行
fmt.Println(p7, p8)
```

##### 权限

结构体（struct）的字段和方法的访问控制是通过命名规则来实现的，而不是通过关键字

结构体名称单词首字母可以大写也可以小写， 大写表示这个结构体是公有的， 在其他的包里面可以使用。 小写表示这个结构体是私有的， 只有这个包里面才能使用

对结构体的字段，同样如此。如果结构体本身是小写字母开头的，那么即使它的字段或方法是大写字母开头的，也无法在包外部访问，因为结构体本身是私有的

```go
// 定义一个公有结构体
type Person struct {
    Name string // 公有字段
    age  int    // 私有字段
}
```

##### 方法

给类型（结构体， 自定义类型） 定义方法。 所谓方法就是定义了接收者的函数  

定义方法：在参数列表前，添加 `(变量名 结构体类型)`，可以是指针也可以不是，区别在于复制与否(传值传址)

非本地类型不能定义方法， 也就是说我们不能给别的包的类型定义方法  

> 接收者中的参数变量名在命名时， 官方建议使用接收者类型名的第一个小写字母， 而不是 self、 this 之类的命名。 例如， Person 类型的接收者变量应该命名为 p，Connector 类型的接收者变量应该命名为 c 等

```go
type mint int
func (i mint) lowbit() mint {
	return i & -i
}
func (i *mint) double() {
	*i *= 2
}
func (i *mint) set(v int) {
	*i = mint(v)
}
// ...
var x mint = 10
fmt.Println(x.lowbit())
x.double()
x.set(580)
```

##### 数组

```go
p := []Node{Node{13, 31}, Node{3, 0}, Node{0, 1}}
```

##### 匿名字段

只有数据类型，无成员属性名称

匿名字段默认采用类型名作为字段名， 结构体要求字段名称必须唯一， 因此一个结构体中同种类型的匿名字段只能有一个  

```go
type student struct {
	no string
	string
	int
}
s := student{"lr580", "AC", 580}
fmt.Println(s.no, s.string, s.int)
```

##### 嵌套结构体

一个结构体中可以嵌套包含另一个结构体或结构体指针，当然也可以是匿名的

嵌套的字段唯一的时候，可以直接用字段

```go
type ns_pair struct {
	node
	student
}
// ...
ns := ns_pair{node{5, 80}, student{"lr580", "AC", 580}}
fmt.Println(ns, ns.x, ns.no, ns.node.x)
```

访问结构体成员时会先在结构体中查找该字段， 找不到再去匿名结构体中查找

  ```go
  type xnode struct {
  	x int
  	node
  }
  // ...
  xn := xnode{580, node{5, 80}}
  fmt.Println(xn.x, xn.node.x) // 580 5
  ```

```go
type nodepair struct {
	p1 node
	p2 node
}
// ...
pr := nodepair{node{5, 80}, node{6, 91}}
fmt.Println(pr.p1.x, pr.p2.y)
```

##### 继承

嵌套匿名结构体指针，根据上述嵌套的穿透规则，可以实现继承的功能。指针避免不必要的复制。

```go
type monster struct {
	name string
}

func (m *monster) enter() {
	fmt.Println(m.name, "comming!")
}

type goblin struct {
	weapon string
	*monster
}

func (g *goblin) attack() {
	fmt.Printf("goblin %s attack with %s\n", g.name, g.weapon)
}
// ...
m := &monster{"Gin"}
m.enter()
g := &goblin{"404 Not Found", &monster{"goroutine"}}
g.enter()
g.attack()
```

##### Tag

Tag 是结构体的元信息， 可以在运行的时候通过反射的机制读取出来。 Tag 

在结构体字段的后方定义， 由一对反引号包裹起来， 具体的格式如下：

```
key1:"value1" key2:"value2"
```

结构体 tag 由一个或多个键值对组成。 键与值使用冒号分隔， 值用双引号括起来。 同一个结构体字段可以设置多个键值对 tag， 不同的键值对之间使用空格分隔

为结构体编写 Tag 时， 必须严格遵守键值对的规则。 结构体标签的解析代码的容错能力很差， 一旦格式写错， 编译和运行时都不会提示任何错误， 通过反射也无法正确取值。 例如不要在 key 和 value 之间添加空格。  

### 接口

一种抽象数据类型， Golang 中接口定义了对象的行为规范， 只定义规范不实现。 接口中定义的规范由具体的对象来实现  

接口（interface） 是一组函数 method 的集合， Golang 中的接口不能包含任何变量，接口中的所有方法都没有方法体，参数列表和返回值列表中的参数变量名可以省略  

接口在命名时， 一般会单词后面添加 er， 如有写操作的接口叫 Writer， 有字符串功能的接口叫 Stringer 等

只需要一个变量含有接口类型中的所有方法， 那么这个变量就实现了这个接口；一个结构体也可以实现多个接口  

##### 定义

基本使用：

- 如果结构体中的方法是值接收者， 那么实例化后的结构体值类型和结构体指针类型都可以赋值给接口变量  
- 如果结构体中的方法是指针接收者， 那么实例化后结构体指针类型都可以赋值给接口变量，结构体值类型没法赋值给接口变量  

```go
type Bar interface {
	Test()
	FryRice()
}
type TesterBar struct{}
func (t TesterBar) Test() { // 不能 * 参数，不然只能指针是接口
	fmt.Println("一位测试工程师走进了酒吧")
}
func (t TesterBar) FryRice() {
	fmt.Println("测试工程师点了一份炒饭\n服务器崩溃")
}
func main() {
	var b Bar = TesterBar{}
	b.Test()
	b.FryRice()
}
```

用作函数：

```go
func goTest(b Bar) {
	b.Test()
	b.FryRice()
}
// ...
var t TesterBar = TesterBar{}
goTest(t) // goTest(TesterBar{})
```

##### 空接口

golang 中的接口可以不定义任何方法， 没有定义任何方法的接口就是空接口。 

空接口表示没有任何约束， 因此任何类型变量都可以实现空接口。

空接口在实际项目中用的是非常多的， 用空接口可以表示任意数据类型

```go
var x interface{}
x = "现在是字符串"
fmt.Println(x)
fmt.Printf("%T %v\n", x, x) // string 现在是字符串
v := 580
x = v
fmt.Println(x)              // 但是无法 x * 10
fmt.Printf("%T %v\n", x, x) // int 580
```

使用空接口实现可以接收任意类型的函数参数  

```go
func print(x interface{}) {
	fmt.Println(x)
}
// ...
print(1. / 3)
```

使用空接口实现可以保存任意值的字典，切片，数组

```go
var lrInfo = map[string]interface{}{}
lrInfo["name"] = "lr580"
lrInfo["age"] = -580
lrInfo["alive"] = false
fmt.Println(lrInfo)
var slice = []interface{}{1 / 3, 1. / 3, false, "张三"}
fmt.Println(slice)
var arr = [3]interface{}{1 / 3, 1. / 3, false}
fmt.Println(arr)
fmt.Printf("%T %T %T", lrInfo, slice, arr)
// map[string]interface {} []interface {} [3]interface {}
```

##### 类型断言

一个接口的值（简称接口值） 是由一个具体类型和具体类型的值两部分组成的。 这两部分分别称为接口的动态类型和动态值  

使用类型断言，返回变量和断言布尔值。

```go
var x interface{}
x = "让我们说中文"
v, ok := x.(string) // 判断失败不行，这里只能 string，会编译错误
fmt.Println(v, ok)
fmt.Printf("%T %T", v, ok) // string bool
```

如果未知，可以用 switch

```go
func typeof(x interface{}) {
	switch v := x.(type) {
	case int:
		fmt.Println("int")
	case string:
		fmt.Println("string")
	default:
		fmt.Println("unknown", v) // 一定要用到v不然报错
	}
}
// ...
typeof(int64(2))
```

##### 接口嵌套

```go
type fooer interface {
	foo()
}
type barer interface {
	bar()
}
type foobarer interface {
	fooer
	barer
}
type foobar struct{}
func (f foobar) foo() {
	fmt.Println("foo")
}
func (f foobar) bar() {
	fmt.Println("bar")
}
// ...
var fb foobarer
fb = foobar{}
fb.foo()
fb.bar()
```



## 流程控制

### 条件判断/循环

#### if

`if` 等语句的代码块必须使用大括号 `{}` 包裹，即使代码块中只有一行代码

```go
score := 30
if score%2 == 0 {
    fmt.Println("even")
} else if score%2 == 1 {
    fmt.Println("odd")
} else {
    fmt.Println("inPossible")
}
```

可以添加赋值语句，变量局部作用域，if 外不可用

```go
score := 30
if score := 31; score%2 == 1 {
    fmt.Println("no even")
}
fmt.Println(score) // 30
```

#### for

##### 基本

三种基本写法

```go
for i := 0; i < 5; i++ {
    fmt.Println(i)
}
i := 0
for ; i < 3; i++ {
    fmt.Println(i)
}
for i < 5 {
    fmt.Println("i=", i)
    i++
}
```

Go 语言中**没有 while 语句**，可以用 for 代替

死循环，continue break

```go
j := 0
for { // 或 for ;; {
    j++
    if j%2 == 0 {
        continue
    }
    if j >= 5 {
        break
    }
    fmt.Println(j)
}
```

##### range

for range 遍历数组、 切片、 字符串、 map 及通道（channel）  

返回值：

- 数组、 切片、 字符串返回索引和值。
- 返回键和值。
- 通道（channel） 只返回通道内的值

```go
s := "Go买卖" // 中文字符正常输出
for i, v := range s {
    fmt.Printf("index:%d, value:%c\n", i, v)
} // index = 0, 1, 2, 5 (一个中文3个字符)
```

##### 多重循环跳出

break

```go
label1:
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			if i*j >= 8 {
				break label1
			}
			fmt.Println(i, j, i*j)
		}
	}
```

continue：对标签所在的循环开启下一轮

```go
label2:
for i := 0; i < 5; i++ {
    for j := 0; j < 5; j++ {
        for k := 0; k < 5; k++ {
            if i+j+k > 8 {
                fmt.Println(i, j, k, i+j+k)
                continue label2 // 进入 i++ 的最外层
            }
        }
    }
}
```



#### switch

`switch` 语句不需要显式使用 `break`，因为 Go 的 `switch` 默认只会执行匹配的 `case` 块，然后自动跳出 `switch` 语句

```go
s := "哈哈"
switch s { // 输出haha，不用break
case "哈":
    fmt.Println("ha")
case "哈哈":
    fmt.Println("haha")
case "哈哈哈":
    fmt.Println("hahaha")
default:
    fmt.Println("Everything is set.")
}
```

多值：

```go
switch m := 3; m { // 可以缩写跟 if 一样
case 1, 3, 5, 7, 8, 10, 12:
    fmt.Println("31 days")
case 4, 6, 9, 11:
    fmt.Println("30 days")
default:
    fmt.Println("28/29 days")
}
```

分支还可以使用表达式， 这时候 switch 语句后面不需要再跟判断变量  

```go
a := 1
b := 2
switch {
case a < b || a > b:
    fmt.Println("a != b")
case a == b:
    fmt.Println("a == b")
}
```

fallthrough 语法可以执行满足条件的 case 的下一个 case， 是为了兼容 C 语言中的 case  

```go
s = "a"
switch {
case s == "a":
    fmt.Println("a")
    fallthrough
case s == "b":
    fmt.Println("b")
case s == "c":
    fmt.Println("c")
default:
    fmt.Println("...")
} // 输出 a,b
```

#### goto

```go
	n := 10
	if n > 5 {
		goto label3
	}
	fmt.Println("No going here")
label3:
	fmt.Println("ends here")
```

### 函数

Go 语言中支持： 函数、 匿名函数和闭包  

#### 常规

##### 定义

函数外边的每个语句都必须以关键字开始（var、 const、 func 等）  

函数可以不按顺序，即上面的函数调用下面的函数

**不支持默认参数**

函数名： 由字母、 数字、 下划线组成。 但函数名的第一个字母不能是数字。 在同一个包内， 函数名也称不能重名  

返回值：返回值由返回值变量和其变量类型组成， 也可以只写返回值的类型， 多个返回值必须用()包裹， 并用,分隔，没有可以不写

```go
func f0() {
	fmt.Println("让我挣开 让我明白 放手你的DL")
}
```

```go
func add(x int, y int) int {
	return x + y
}
```

```go
func swap(x int, y int) (int, int) {
	return y, x
}
```

函数的参数中如果相邻变量的类型相同， 则可以省略类型，   

```go
func intSum(x, y int) int {
	return x + y
}
```

##### 调用

```go
func main() {
	f0()
	fmt.Println(add(1437, 581))
	a, b := 5, 80
	a, b = swap(a, b)
	fmt.Println(a, b)
}
```

返回两个值，可以直接传入需要两个值的函数，其他同理

```go
fmt.Println(intSum(calc(5, 3))) //两个自定义函数都传入两个int参数
```

##### 可变参数

可变参数通常要作为函数的最后一个参数，作为一个切片使用

```go
func powSum(p int, x ...int) int64 {
	var ans int64
	for _, v := range x {
		var vp int64 = 1
		for i := 1; i <= p; i++ {
			vp *= int64(v)
		}
		ans += vp
	}
	return ans
} // fmt.Println(powSum(2, 3, 4)) // 3^2+4^2
```

##### 返回值

除了跟上文一样直接常规的返回值，还可以函数定义时可以给返回值命名， 并在函数体中直接使用这些变量， 最后通过 return 关键字返回  

```go
func calc(x, y int) (sum, sub int) {
    sum = x + y
    sub = x - y
    return
}
```

```go
fmt.Println(calc(5, 3))
```

#### 高阶

##### 函数变量

```go
type dbFunc func(int, int) int
func add(x, y int) int {
	return x + y
}
func sub(x, y int) int {
	return x - y
}
```

```go
var f dbFunc
f = add
fmt.Println(f(5, 3))
f = sub
fmt.Println(f(5, 3))
```

```go
fmt.Printf("%T -- %T\n", add, f) 
//func(int, int) int -- main.dbFunc
```

##### 高阶函数

函数作为参数：

```go
func add(x, y int) int {
	return x + y
}
//type dbFunc func(int, int) int
//func f2(x, y int, f dbFunc) int {
func f2(x, y int, f func(int, int) int) int {
	return f(x, y)
}
```

```go
fmt.Println(f2(5, 3, add))
```

函数做返回值：

```go
func getOp(op string) func(int, int) int { // 或 dbFunc
	if op == "+" {
		return add
	}
	return sub
}
```

```go
var op = getOp("+")
fmt.Println(op(5, 3))
```

##### 匿名函数

```go
ff := func(x, y int) int {
    return x * y
}
fmt.Println(ff(8, 9))
func(x, y int) {
    fmt.Println(x * y)
}(10, 11)
```

##### 闭包

闭包可以理解成“定义在一个函数内部的函数“。 在本质上， 闭包是将函数内部和函数外部连接起来的桥梁。 或者说是函数和其引用环境的组合体  

```go
package main

import "fmt"

func adder() func(int) int {
	var x int
	return func(y int) int {
		x += y
		return x
	}
}
func main() {
	var f = adder()
	fmt.Println(f(10)) //10
	fmt.Println(f(20)) //30
	fmt.Println(f(30)) //60
	f1 := adder()
	fmt.Println(f1(40)) //40
	fmt.Println(f1(50)) //90
}
```

变量 f 是一个函数并且它引用了其外部作用域中的 x 变量， 此时 f 就是一个闭包。 在 f 的生命周期内， 变量 x 也一直有效  

简化：

```go
func adder2(x int) func(int) int {
	return func(y int) int {
		x += y
		return x
	}
}
func t2() {
	var f = adder2(10)
	fmt.Println(f(10)) //20
	fmt.Println(f(20)) //40
	fmt.Println(f(30)) //70
	f1 := adder2(20)
	fmt.Println(f1(40)) //60
	fmt.Println(f1(50)) //110
}
```

例子2：

```go
func makeSuffixFunc(suffix string) func(string) string {
	return func(name string) string {
		if !strings.HasSuffix(name, suffix) {
			return name + suffix
		}
		return name
	}
}
```

```go
jpgFunc := makeSuffixFunc(".jpg")
txtFunc := makeSuffixFunc(".txt")
fmt.Println(jpgFunc("test")) //test.jpg
fmt.Println(txtFunc("test")) //test.txt
```

#### defer

defer 语句会将其后面跟随的语句进行延迟处理。 在 defer 归属的函数即将返回时， 将延迟处理的语句按 defer 定义的逆序进行执行， 也就是说， 先被 defer 的语句最后被执行， 最后被 defer 的语句， 最先被执行。  

能非常方便的处理资源释放问题。 比如：资源清理、 文件关闭、 解锁及记录时间  

```go
fmt.Println("start")
defer fmt.Println(1)
defer fmt.Println(2)
defer fmt.Println(3)
fmt.Println("end") // 输出 start end 3 2 1
```

return 语句在底层并不是原子操作，返回操作分三步：①赋值返回值、②执行defer、③执行返回(RET指令)

如：

```go
func f1() int {
	x := 5
	defer func() {
		x++
	}()
	return x
}
func f2() (x int) {
	defer func() {
		x++
	}()
	return 5
}
func f3() (y int) {
	x := 5
	defer func() {
		x++
	}()
	return x
}
func f4() (x int) {
	defer func(x int) {
		x++
	}(x)
	return 5
}
func t4() {
	fmt.Println(f1()) //5
	fmt.Println(f2()) //6
	fmt.Println(f3()) //5
	fmt.Println(f4()) //5
}
```

上面例子，

1. 返回值=x，x++，返回返回值
2. 返回值命名为x，x=5，x++，返回x
3. 返回值命名为y，y=x，x++，返回y
4. 返回值命名为x，x=5，同名参数x(x2)=5，x2++，返回x

```go
func cal(index string, a, b int) int {
	ret := a + b
	fmt.Println(index, a, b, ret)
	return ret
}
func t5() {
	x := 1
	y := 2
	defer cal("AA", x, cal("A", x, y))
	fmt.Println("=X")
	x = 10
	defer cal("BB", x, cal("B", x, y))
	fmt.Println("=Y")
	y = 20
}
```

输出：(defer 计算是顺序的，返回是逆序的，参数值就是当时顺序的值)

```
A 1 2 3
=X
B 10 2 12
=Y
BB 10 12 22
AA 1 3 4
```

#### 内置函数

- close：关闭 channel
- len：求长度， 比如 string、 array、 slice、 map、 channel
- new：分配内存， 主要用来分配值类型， 比如 int、 struct。 返回的是指针
- make：分配内存， 主要用来分配引用类型， 比如 chan、 map、 slice
- append：用来追加元素到数组、 slice 中
- panic、recover：错误处理



- min, max 函数 1.21.0 开始

  ```go
  fmt.Println(max(2, 3))
  fmt.Println(min(1, 1, 4, 0.5))
  ```

  

#### init函数

没有参数也没有返回值。 init()函数在程序运行时自动被调用执行， 不能在代码中主动调用它

执行顺序：全局声明、init、main。不管声明在init前后，都是先声明

```go
func init() {
	fmt.Println(x)
}
var x = 1
```

### 异常

> #### panic
>

##### panic

panic可以在任何地方引发

```go
panic("直接报错，并且这一行下面的不会执行，参数是报错信息")
```

```
panic: 直接报错，并且这一行下面的不会执行，参数是报错信息

goroutine 1 [running]:
main.main()
	d:/_lr580_desktop/codes/golang/lgo-013.go:111 +0x3d
exit status 2
```

##### recover

通过recover 将程序恢复回来， 继续往后执行。 recover 只有在 defer 调用的函数中有效  

```go
func funcA() {
	fmt.Println("func A")
}
func funcB() {
	defer func() {
		err := recover() // 有错误的话，err 就是 panic 字符串
		//如果程序出出现了 panic 错误,可以通过 recover 恢复过来
		if err != nil {
			fmt.Println("recover in B")
		}
        // 或： if err := recover(); err != nil {
	}()
	panic("panic in B")
}
func funcC() {
	fmt.Println("func C")
}
func t6() {
	funcA()
	funcB()
	funcC()
}
```

输出

```
func A
recover in B
func C
```

##### 捕获异常

故可以捕获异常，包括非 panic 触发的异常：

```go
func fn2() {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("抛出异常给管理员发送邮件")
			fmt.Println(err)
		}
	}()
	num1 := 10
	num2 := 0
	res := num1 / num2
	fmt.Println("res=", res)
}
//抛出异常给管理员发送邮件
//runtime error: integer divide by zero
```

##### 传递异常

一层层地传递异常：

```go
func readFile(fileName string) error { // error 是一种类型
	if fileName == "main.go" {
		return nil // 无异常
	} //import "errors"
	return errors.New("读取文件失败") // 有异常
}
func fn3() {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("程序出现异常，发送报警邮件给管理员")
			fmt.Println(err)
		}
	}()
	err := readFile("mian.go")
	if err != nil {
		panic(err) // 抛出异常
	}
	fmt.Println("无事发生")
}
```

### 包

#### 基本用法

##### 概念

###### 包的分类

包可以分为三种： 1、 系统内置包 2、 自定义包 3、 第三方包  

- 系统内置包: Golang 语言给我们提供的内置包， 引入后可以直接使用， 如 fmt、 strconv、 strings、sort、 errors、 time、 encoding/json、 os、 io 等。
- 自定义包： 开发者自己写的包
- 第三方包： 属于自定义包的一种， 需要下载安装到本地后才可以使用， 如"github.com/shopspring/decimal"包解决 float 精度丢失问题

###### 包

包（package） 是多个 Go 源码的集合， 一个包可以简单理解为一个存放多个.go 文件的文件夹。 该文件夹下面的所有 go 文件都要在代码的第一行添加如下代码， 声明该文件归属的包  

```go
package 包名
```

一个文件夹下面直接包含的文件只能归属一个 package， 同样一个 package 的文件不能在多个文件夹下。

包名可以不和文件夹的名字一样， 包名不能包含 - 符号。

包名为 main 的包为应用程序的入口包， 这种包编译后会得到一个可执行文件， 而编译不包含 main 包的源代码则不会得到可执行文件

###### 顺序

从 main 包开始检查其导入的所有包， 每个包中又可能导入了其他的包。 Go 编译器由此构建出一个树状的包引用关系， 再根据引用顺序决定编译顺序， 依次编译这些包的代码，特别对 init 而言，顺序遵循：

- import 的包，按字典序排列，先后引入
- 同一个包有多个代码文件，字典序
- 一个包 import 了另一个包，先执行被引用的，构成树状

非 main 包的 main 函数不会被执行，会 warning

```go
// lgo-018.go
package main
import (
	"fmt"
	_ "golearn/testpa"       // fun3.go 文件
	alias "golearn/testpack" // fun1, gun1 文件两个 init 函数
	"golearn/testpack2"      // fun2, 而外引用了其他包的 fun4
)
```

输出

```
init fun3
init fun1
init gun1
init fun4
init fun2
```

##### 导包

import 只能写在函数外，函数声明前

```go
import "fmt"
```

```go
import (
    "fmt"
    "math"
)
```

第三方包和其他包之间，会默认加一个空行

##### 自定义包

在一个包中引用另外一个包里的标识符（如变量、 常量、 类型、 函数等） 时， 该标识符必须是对外可见的（public） 。 在 Go 语言中只需要将标识符的首字母大写就可以让标识符对外可见了  

如在当前目录下新建 `testpack/` 目录，当前 `go.mod` 的项目名字是 `golearn`，包名叫 `tpack`，代码为 `testpack/fun1.go`

```go
package tpack
var pwd = 1437 // 私有
var Lr = 580   // 公有
func PrintLR() int {
	return pwd*1000 + Lr
}
```

在根目录下的 `lgo-018.go` 调用上面的包：

```go
package main
import (
	"fmt"
	"golearn/testpack"
)
func main() {
	fmt.Println(tpack.Lr)
}
```

可以定义别名：通常用于导入的包名太长或者导入的包名冲突的情况  

```go
package main
import (
	"fmt"
	alias "golearn/testpack" // 默认会别名 tpack，跟上面一样
)
func main() {
	fmt.Println(alias.PrintLR())
}
```

如果现在有与文件夹同名的，如 `testpack2/` 目录下，`fun2.go` 如下：

```go
package testpack2
var AC = 100
```

那么就不会自动定义别名，当然也可以：

```go
import "golearn/testpack2" // 部分代码
fmt.Println(testpack2.AC)
```

##### 匿名导入

只希望导入包， 而不使用包内部的数据时， 可以使用匿名导入包，这样无法使用任何变量和函数，那么就用 `_` 做别名，一般是希望执行 init 函数

```go
import _ "golearn/testpack2"
```

可以避免不使用它的变量和函数而被自动删掉 import

### 多线程

#### 理论

> 并发： 多个线程同时竞争一个位置， 竞争到的才可以执行， 每一个时间段只有一个线程在执行。
>
> 并行： 多个线程可以同时执行， 每一个时间段， 可以有多个线程同时执行。通俗的讲多线程程序在单核 
>
> CPU 上面运行就是并发， 多线程程序在多核 CUP 上运行就是并行， 如果线程数大于 CPU 核数， 则多线程程序在多个 CPU 上面运行既有并行又有并发

##### 协程

协程： 可以理解为用户级线程， 这是对内核透明的， 也就是系统并不知道有协程的存在， 是完全由用户自己的程序进行调度的。 Golang 的一大特色就是从语言层面原生支持协程， 在函数或者方法前面加 go 关键字就可创建一个协程。 可以说 Golang 中的协程就是goroutine   

多协程和多线程： Golang 中每个 goroutine (协程) 默认占用内存远比 Java 、 C 的线程少。OS 线程（ 操作系统线程） 一般都有固定的栈内存（通常为 2MB 左右） ,一个 goroutine (协程) 占用内存非常小， 只有 2KB 左右， 多协程 goroutine 切换调度开销方面远比线程要少。这也是为什么越来越多的大公司使用 Golang 的原因之一  

##### 主线程

golang 中的主线程： （可以理解为线程/也可以理解为进程） ， 在一个 Golang 程序的主线程上可以起多个协程。 Golang 中多协程可以实现并行或者并发

主线程执行完毕，不管协程是否执行完毕，都会终止程序，参见下面 `go` 一节代码例子 

##### 管道

管道是 Golang 在语言级别上提供的 goroutine 间的通讯方式， 我们可以使用 channel 在多个 goroutine 之间传递消息。 如果说 goroutine 是 Go 程序并发的执行体， channel 就是它们之间的连接。 channel 是可以让一个 goroutine 发送特定值到另一个 goroutine 的通信机制  

Golang 的并发模型是 CSP（Communicating Sequential Processes） ， 提倡通过通信共享内存而不是通过共享内存而实现通信  

Go 语言中的管道（channel） 是一种特殊的类型，遵循 FIFO，每一个管道都是一个具体类型的导管， 也就是声明 channel 的时候需要为其指定元素类型  

##### 死锁

如，当所有活跃的goroutine（主goroutine + 4个消费者）均处于阻塞状态，且无其他goroutine可推进任务时，Go运行时会检测到**死锁**，抛出错误：

```
fatal error: all goroutines are asleep - deadlock!
```

这是明确的运行时错误，而非消费者陷入“死循环”（死循环指持续占用CPU的循环，而此处是阻塞等待）

#### goroutine

##### go

go 指令执行一个函数，`go f()`，以协程方式执行它

```go
package main
import (
	"fmt"
	"time"
)
func test() {
	for i := 1; i <= 10; i++ {
		fmt.Println("test in", i)
		time.Sleep(100 * time.Millisecond)
	}
}
func main() {
	go test()
	for i := 1; i <= 3; i++ {
		fmt.Println("main in", i)
		time.Sleep(100 * time.Millisecond)
	}
}
```

main 执行完毕，所有协程强制终止。可能的输出：

```go
main in 1
test in 1
test in 2
main in 2
main in 3
test in 3
test in 4
```

##### waitgroup

`sync` 包的 `Waitgroup`，有常用方法：

1. `wg.Add(x)` 添加x个信号量
2. `wg.Done()` 减少一个信号量
3. `wg.Wait()` 直到信号量为0时继续往下执行，否则阻塞

主程序与 test 并发，并等待 test 执行完毕：

```go
package main
import (
	"fmt"
	"sync"
	"time"
)
var wg sync.WaitGroup
func test() {
	for i := 1; i <= 10; i++ {
		fmt.Println("test in", i)
		time.Sleep(100 * time.Millisecond)
	}
	wg.Done()
}
func main() {
	wg.Add(1)
	go test()
	for i := 1; i <= 3; i++ {
		fmt.Println("main in", i)
		time.Sleep(100 * time.Millisecond)
	}
	wg.Wait()
}
```

另一种思路：直接在 `test()` 函数第一行：

```go
defer wg.Done()
```

同理，可以扩展到多个 goroutine 并发

##### GOMAXPROCS

`runtime` 包，可以求出当前计算机 CPU 数。(多少核)

```go
cpuNum := runtime.NumCPU()
fmt.Println(cpuNum) // 如 16
runtime.GOMAXPROCS(cpuNum - 1) // 设置
```

#### 管道

##### 定义

channel 是一种类型， 一种引用类型。 声明管道类型的格式如下  

```go
// 声明
var ch1 chan int
var ch2 chan bool
var ch3 chan []int
```

或：

```go
// 声明并创建
ch1 := make(chan int, 10) // 容量为10
ch2 := make(chan bool, 4)
ch3 := make(chan []int, 3)
// 如果已经声明
```

无容量(无缓冲)

```go
h := make(chan int)
```

##### 使用

管道有发送（send） 、 接收(receive） 和关闭（close） 三种操作。发送和接收都使用<-符号  

```go
ch1 <- 580   // 发送数据
num := <-ch1 // 接收数据
fmt.Println(num)
// fmt.Println(<-ch1) // 没有数据，会报错
// <-ch1 // 接收数据，原地丢弃忽略
```

##### 关闭

```go
close(ch1) // 关闭通道
```

关于关闭管道需要注意的事情是， 只有在通知接收方 goroutine 所有的数据都发送完毕的时候才需要关闭管道。 管道是可以被垃圾回收机制回收的， 它和关闭文件是不一样的， 在结束操作之后关闭文件是必须要做的， 但关闭管道不是必须的  

对一个关闭的管道再发送值就会导致 panic

对一个关闭的管道进行接收会一直获取值直到管道为空。

对一个关闭的并且没有值的管道执行接收操作会得到对应类型的零值  

关闭一个已经关闭的管道会导致 panic

##### 阻塞

如果创建管道的时候没有指定容量， 那么我们可以叫这个管道为无缓冲的管道  

当要发送数据，而超过管道容量时(如没有任何容量的管道)，会报错；只要管道的容量大于零， 那么该管道就是有缓冲的管道， 管道的容量表示管道中能存放元素的数量  

##### 遍历

在遍历之前，必须关闭管道。

```go
ch := make(chan int, 10)
ch <- 10
ch <- 40
close(ch)
for val := range ch {
    fmt.Println(val)
}
```

##### 单向管道

比如限制管道在函数中只能发送或只能接收  

```go
var ch2 chan<- int // 只写
ch2 = make(chan int, 3)
ch2 <- 580
var ch3 <-chan int // 只读 (只读无法被关闭)
fmt.Printf("%T %v %v", ch3, ch3, ch2)
// <-chan int <nil> 0xc0000a6080
```

使用场景：作用于函数参数，使得虽然是同一个管道，但在某些函数只能读，在某些函数只能写，见下文质数例子。

##### 多路复用

select 的使用类似于 switch 语句， 它有一系列 case 分支和一个默认的分支。 每个 case 会对应一个管道的通信（接收或发送） 过程。 select 会一直等待， 直到某个 case 的通信操作完成时， 就会执行 case 分支对应的语句  

```go
ic := make(chan int, 10)
for i := 1; i <= 10; i++ {
    ic <- i * 580
}
sc := make(chan string, 5)
for i := 1; i <= 5; i++ {
    sc <- fmt.Sprintf("string %d", i)
}
for { // 执行结果：随机读取一个，然后读完了no receive
    select {
    case v := <-ic:
        fmt.Println("ic", v)
    case v := <-sc:
        fmt.Println("sc", v)
    default:
        fmt.Println("No receive")
        // break 无法跳出
        return
    }
}
```

##### 多线程

实例

> ##### 边生产边消费

一个生产者，4个消费者抢：

```go
thing := make(chan string, 2)
wg.Add(5)
go func() { // 一个生产者
    defer wg.Done()
    for i := 1; i <= 20; i++ {
        fmt.Println("producer produce thing", i)
        thing <- fmt.Sprintf("thing %d", i)
        time.Sleep(200 * time.Millisecond)
    }
    close(thing)
}()
for i := 0; i < 4; i++ { // 多个消费者
    go func(i int) {
        defer wg.Done()
        for x := range thing {
            fmt.Printf("consumer %d got %s\n", i, x)
        }
    }(i) // 观察到按照 0,1,2,3,...的顺序消费
}
wg.Wait()
fmt.Println("All done")
```

> ##### 例：质数计算

多线程计算质数并使用管道输出

```go
import (
	"fmt"
	"runtime"
	"sync"
	"time"
)
// 可以证明是边生产边消费的
var wg sync.WaitGroup

func producer(n int, a chan<- int) {
	defer wg.Done()
	fmt.Println("生产者开始生产")
	for i := 2; i <= n; i++ {
		a <- i
	}
	close(a)
	fmt.Println("生产者生产完毕")
}
func consumer(a <-chan int, p chan<- int) {
	started := false
	for x := range a {
		if !started {
			fmt.Println("消费者开始消费")
			started = true
		}
		isPrime := true
		for i := 2; i*i <= x; i++ {
			if x%i == 0 {
				isPrime = false
				break
			}
		}
		if isPrime {
			p <- x
		}
	}
	fmt.Println("消费者消费完毕")
	wg.Done()
}
func main() {
	start := time.Now()
	n := int(1e7)
	a := make(chan int, n)
	p := make(chan int, n)
	m := 4 // 线程数
	wg.Add(m + 1)
	go producer(n, a)
	for i := 0; i < m; i++ {
		go consumer(a, p)
	}
	wg.Wait()
	// 单线程 3.95ms, 4线程 1.3ms
	fmt.Println("执行完毕，需要：", time.Since(start))
	fmt.Println("素数个数：", len(p))
	close(p) // 必须要关闭
	// 是有序的
	// for x := range p {
	// 	fmt.Println(x)
	// }
}
```

#### 并发安全

##### race

首先看一个经典多线程++问题：

```go
// lgo-020.go
var wg sync.WaitGroup
cnt := 0
wg.Add(100)
for i := 0; i < 100; i++ {
    go func() {
        for j := 0; j < 100; j++ {
            cnt++
            time.Sleep(time.Millisecond)
        }
        wg.Done()
    }()
}
wg.Wait()
fmt.Println(cnt) // 如 9961
```

命令 `go build -race lgo-020.go` 用于编译 Go 源代码文件 `lgo-020.go`，并且在编译过程中启用数据竞争检测（race detection）

生成的可执行文件在运行时，如果检测到数据竞争，会在控制台输出相关的警告信息，帮助你定位和修复并发问题

```go
go build -race lgo-020.go
./lgo-020
```

如告诉代码行数：

```
==================
WARNING: DATA RACE
Read at 0x00c00000a1b8 by goroutine 8:
  main.main.func1()
      D:/_lr580_desktop/codes/golang/lgo-020.go:178 +0x37
```

##### 互斥锁

sync 中的 Mutex结构体类型表示。 sync.Mutex 类型只有两个公开的指针方法， Lock 和 Unlock。 Lock 锁定当前的共享资源， Unlock 进行解锁  

使用互斥锁能够保证同一时间有且只有一个 goroutine 进入临界区， 其他的 goroutine 则在等待锁； 当互斥锁释放后， 等待的 goroutine 才可以获取锁进入临界区， 多个 goroutine 同时等待一个锁时， 唤醒的策略是随机的  

```go
fmt.Println("begin")
cnt := 0
var wg sync.WaitGroup
wg.Add(100)
var mutex sync.Mutex
t := time.Now()
for i := 0; i < 100; i++ {
    go func() {
        for j := 0; j < 100; j++ {
            mutex.Lock()
            cnt++
            mutex.Unlock()
            time.Sleep(time.Millisecond)
        }
        wg.Done()
    }()
}
wg.Wait()
fmt.Println("执行完毕，需要：", time.Since(t)) // 158ms
fmt.Println(cnt) // 10000
```

缺点：锁住的代码不并行，而是串行了

##### 读写锁

修改的数据要同步， 这样其他goroutine 才可以感知到。 所以真正的互斥应该是读取和修改、 修改和修改之间， 读和读是没有互斥操作的必要

写锁可以让多个读操作并发， 同时读取， 但是对于写操作是完全互斥的。 当一个 goroutine 进行写操作的时候， 其他 goroutine 既不能进行读操作， 也不能进行写操作  

```go
var mutex sync.RWMutex
var wg sync.WaitGroup
cnt := 0
wg.Add(13)
t := time.Now()
for i := 0; i < 3; i++ {
    go func() {
        defer wg.Done()
        for j := 0; j < 100; j++ {
            mutex.Lock() // 写锁
            cnt++
            mutex.Unlock()
            time.Sleep(time.Millisecond)
        }
    }()
}
for i := 0; i < 10; i++ {
    go func() {
        defer wg.Done()
        for j := 0; j < 100; j++ {
            mutex.RLock() // 读锁
            fmt.Println(cnt)
            mutex.RUnlock()
            time.Sleep(time.Millisecond)
        }
    }()
}
wg.Wait()
fmt.Println("执行完毕，需要：", time.Since(t))
fmt.Println(cnt)
```

##### 异常处理



## 常用内置包

### I/O

fmt 包里面给我们提供了一些常见的打印数据的方法， 比如： Print 、 Println、 Printf， 在我们实际开发中 Println、 Printf 用的非常多  

#### 标准I/O

##### 输出

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

> - `%v`：值的默认格式表示。可以输出数组、切片等。
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
> - `%p`：地址

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

占位符变量缺失不会报错，占位地方变成如 `%!s(MISSING)` 的字符串。

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

地址直接传入变量名即可，没有取地址符之类的。输出如 `0xc0000200a0`

```go
fmt.Printf("%v %d %d %p\n", a, len(a), cap(a), a)
// [0 0 0 1] 4 5 0xc00000c420
```

##### 输入

- `fmt.Scanf`，类似 C 语言，占位符也差不多

  ```go
  fmt.Scanf("%s %d", &name, &age)
  ```

- `fmt.Scan`，读取多个变量，直到遇到空白字符

  ```go
  var name string
  var age int
  fmt.Print("Enter your name and age: ")
  fmt.Scan(&name, &age) // 如输入 lr580 580 回车
  fmt.Printf("Hello, %s! You are %d years old.\n", name, age)
  ```

- `fmt.Scanln`，同 Scan，遇到换行结束

#### 文件I/O

可能会用到：`os` 包和 `io` 包。缓冲 `bufio` 包

##### 打开

记得关闭。go 风格申请资源的时候下一行就可以 defer 关闭，这样可以按照申请顺序关闭

```go
file, err := os.Open("lgo-022.go") // 读取自己，或 ./lgo-022.go
defer file.Close()
if err != nil {
    fmt.Println("Error", err)
    return
}
fmt.Println(file) // 地址如 &{0xc0000a06c8}
```

Open 后得到 `*os.File`，该类型实现了 `os.Reader` 方法

##### 读取

```go
package main
import (
	"fmt"
	"io"
	"os"
)
func main() {
	file, err := os.Open("lgo-022.go")
	defer file.Close()
	if err != nil {
		fmt.Println("Error", err)
		return
	}
    
	var content []byte
	var tmp = make([]byte, 128)
	for {
		n, err := file.Read(tmp)
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Println("Error", err)
			return
		}
		content = append(content, tmp[:n]...)
	}
	fmt.Println(string(content)) // 足以处理中文
}
```

##### 缓冲读

Reader 逐行读，如输出行号

```go
func testfile2(file *os.File) {
	reader := bufio.NewReader(file)
	for i := 1; ; i++ {
		line, err := reader.ReadString('\n')
		if len(line) != 0 {
			fmt.Printf("[%v] %v", i, line)
		}
		if err != nil {
			if err != io.EOF {
				fmt.Println("Error", err)
			}
			break
		}
	}
}
```

##### 整读

只需要文件路径，非常方便的封装方法。

```go
func testfile3(path string) {
	content, err := os.ReadFile(path) // []byte
	if err != nil {
		fmt.Println("Error", err)
		return
	}
	fmt.Println(string(content))
}
// testfile3("lgo-022.go")
```

也可以拿到 `os.Reader` 后读：

```go
content, err2 := io.ReadAll(file)
if err2 != nil {
    fmt.Println("Error", err2)
    return
}
fmt.Println(string(content))
```

##### 写入

flag int 模式，或起来，常见的有：

- `os.O_WRONLY` 只写
- `os.O_CREATE` 创建 (已存在覆盖)
- `os.O_RDONLY` 只读
- `os.O_RDWR` 读写
- `os.O_TRUNC` 清空
- `os.O_APPEND` 追加

perm 权限：八进制数 r 读04，w 写02，x 执行01，三个八进制分别对应从高到低是文件所有者、组用户、其他用户。`perm` 参数用于指定新创建文件的权限。如果文件已经存在，`perm` 参数会被忽略。

然后用 `.WriteString` 或 `.Write` 来写东西。

```go
file, err := os.OpenFile("a.txt", os.O_CREATE|os.O_WRONLY, 0666)
if err != nil {
    fmt.Println("Error", err)
    return
}
defer file.Close()
str := "随便\n写点什么"
file.Write([]byte(str))
file.WriteString("再写点东西，第二种写入方法")
```

##### 缓冲写

对可写 flag 文件：

```go
writer := bufio.NewWriter(file)
for i := 0; i < 10; i++ {
    writer.WriteString(fmt.Sprintf("第%v行\n", i+1))
}
writer.Flush()
```

##### 直接写

```go
str := "Company Dream: It's My Go!!!!"
err := os.WriteFile("a.txt", []byte(str), 0666)
if err != nil {
    fmt.Println("Error", err)
    return
}
```

##### ioutil

> `ioutil` 包中的一些函数已经被移到了 `os` 和 `io` 包中，在新版本显示 depreciated
>
> - `ioutil.WriteFile` → `os.WriteFile`
> - `ioutil.ReadAll` → `io.ReadAll`
> - `ioutil.ReadDir` → `os.ReadDir`
> - `ioutil.TempFile` → `os.CreateTemp`
> - `ioutil.TempDir` → `os.MkdirTemp`

#### 文件处理

##### 移动

移动/重命名。只能在同一个磁盘内操作。

```go
err := os.Rename("a.txt", "D:/a.txt") // 剪贴文件
if err != nil {
    fmt.Println("Error", err)
    return
}
```

##### 复制

> 一种手写逻辑是，读文件，然后新建文件写，达到复制的效果。另一种逻辑是文件流。当然都不如调库：

```go
src, err := os.Open("lgo-022.go")
if err != nil {
    fmt.Println("Error", err)
    return
}
defer src.Close()

dst, err := os.Create("D:/a.txt") // 新建文件
if err != nil {
    fmt.Println("Error", err)
    return
}
defer dst.Close()

len, err := io.Copy(dst, src)
if err != nil {
    fmt.Println("Error", err)
    return
}
fmt.Println("Copy", len, "bytes")
```

##### 删除

`err := os.Remove(path)`，也可以做剪贴的事。也可以删除（空）目录。

删除目录 `os.RemoveAll`

```go
err = os.RemoveAll("abc")
if err != nil {
    fmt.Println("Error", err)
    return
}
```

#### 目录处理

##### 新建目录

单层和多层：

```go
var err error
err = os.Remove("abc/") // 或 abc 也行
if err != nil {
    fmt.Println("Error", err)
    return
}
err = os.Mkdir("abc", 0666) // 或 ./abc ./abc/ abc/
if err != nil {
    fmt.Println("Error", err)
    return
}
err = os.MkdirAll("abc/def/ghi", 0666)
if err != nil {
    fmt.Println("Error", err)
    return
}
```

### 数学

#### math

##### 常量

```go
math.MinInt
```

##### 函数

```go
func Abs(x float64) float64 // 对于整数类型，Go 语言没有内置的绝对值函数
```

### 时间

#### time

##### Now

Time 对象。取当前时间

```go
now := time.Now()
fmt.Println(now)
// 2025-03-12 18:29:48.5373521 +0800 CST m=+0.000000001
year := now.Year()
month := now.Month()
day := now.Day()
hour := now.Hour()
minute := now.Minute()
second := now.Second()
fmt.Printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second)
```

> ```go
> // 24 小时制
> fmt.Println(now.Format("2006-01-02 15:04:05"))
> // 12 小时制
> fmt.Println(now.Format("2006-01-02 03:04:05"))
> fmt.Println(now.Format("2006/01/02 15:04"))
> fmt.Println(now.Format("15:04 2006/01/02"))
> fmt.Println(now.Format("2006/01/02"))
> ```
>
> 输出的是 now 的时间，但是按 format 的格式

##### 构造

基于时间戳或字符串构造

时间戳是自 1970 年 1 月 1 日（08:00:00GMT） 至当前时间的总毫秒数。 它也被称为 Unix 时间戳（UnixTimestamp） 。

基于时间戳可以构造上面的 Time 对象。

Time 转时间戳：

```go
timestamp1 := now.Unix() //时间戳
timestamp2 := now.UnixNano() //纳秒时间戳
fmt.Printf("current timestamp1:%v\n", timestamp1)
fmt.Printf("current timestamp2:%v\n", timestamp2)
// 1741775621 1741775621568192500
```

时间戳转 Time：

```go
var timestamp int64 = 1587880013
timeObj := time.Unix(timestamp, 0) //将时间戳转为时间格式
year := timeObj.Year() //年
// ... 同上面
fmt.Printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second)
```

字符串转 Time 转时间戳：

```go
t := "2019-01-08 13:50:30"            //时间字符串
timeTemplate := "2006-01-02 15:04:05" //常规类型
stamp, _ := time.ParseInLocation(timeTemplate, t, time.Local)
fmt.Println(stamp.Unix())
```

##### 时间间隔

time.Duration 是 time 包定义的一个类型(本质上是int64，基本单位是纳秒)， 它代表两个时间点之间经过的时间， 以纳秒为单位。 time.Duration 表示一段时间间隔， 可表示的最长时间段大约 290 年  

time 包中定义的时间间隔类型的常量如下  

```go
const (
    Nanosecond Duration = 1
    Microsecond = 1000 * Nanosecond
    Millisecond = 1000 * Microsecond
    Second = 1000 * Millisecond
    Minute = 60 * Second
    Hour = 60 * Minute
)
```

##### 运算

基于时间间隔，运算加减和比较。方法有：

- Add 做时间加减

- Sub 求两个时间的间隔

  `time.Since(x)` 求从 `x` 时间到当前时间的间隔

- Equal 判断时间是否相等

  Before, After 判断是否在参数时间之前/后

```go
now := time.Now()
later := now.Add(time.Hour)
fmt.Println(later)
dur := later.Sub(now)
fmt.Println(dur)         // 1h0m0s
fmt.Println(dur.Hours()) // 1
fmt.Println(now.Sub(later))
fmt.Println(now.Equal(later.Add(now.Sub(later))))
fmt.Println(now.Before(later), later.After(now)) // all true
```

##### 定时器

每一秒执行一次：

```go
ticker := time.NewTicker(time.Second)
n := 0
for i := range ticker.C {
    fmt.Println(i)
    // i 是 Time, 输出当前时间 (不断严格+1s)
    n++
    if n > 5 {
        ticker.Stop()
        break
    }
}
```

##### sleep

```go
fmt.Println("abc")
time.Sleep(time.Second)
fmt.Println("abc again 1 sec later")
```

##### 计时器

```go
start := time.Now()
var x int64 = 580
for i := 0; i < 1e8; i++ {
    x += int64(i)
}
fmt.Println(x)
fmt.Println(time.Since(start)) // 13.3413ms
fmt.Println(time.Since(start).Microseconds()) // 13341
```

### 文本处理

#### json

JSON(JavaScript Object Notation) 是一种轻量级的数据交换格式。 易于人阅读和编写。 同时也易于机器解析和生成。 RESTfull Api 接口中返回的数据都是 json 数据  

序列化和反序列化主要通过"encoding/json"包

##### 序列化

```go
package main
import (
	"encoding/json"
	"fmt"
)
type Student struct {
	ID     int
	Gender string
	name   string // 私有
	Sno    string
}
func main() {
	{
		s1 := Student{1, "男", "张三", "480"}
		var s, _ = json.Marshal(s1) // s:[]byte
		fmt.Println(s, string(s))
        // [123 34 73 68 34 58 49 44 34 71 101 110 100 101 114 34 58 34 231 148 183 34 44 34 83 110 111 34 58 34 52 56 48 34 125] {"ID":1,"Gender":"男","Sno":"480"}
	}
}
```

第二个返回值是错误信息，可以 `if err != nil` 判断失败。

对嵌套结构体、数组等同理。

##### 反序列化

接上例(Student)。

```go
var s2 Student
err := json.Unmarshal(s, &s2)
if err != nil {
    fmt.Println(err)
}
fmt.Println(s2) // {1 男  480}
```

##### Tag

可以用标签，`json:"xxx"`，修改 json 里对该字段的命名；`xxx,omitempty` 

```go
type Node struct {
	PointX int `json:"x"`
	PointY int `json:"y,omitempty"`
}
// ...
p := []Node{Node{13, 31}, Node{3, 0}, Node{0, 1}}
for i := 0; i < len(p); i++ {
    s, _ := json.Marshal(p[i])
    fmt.Println(string(s))
    p2 := Node{}
    json.Unmarshal(s, &p2)
    fmt.Println(p2) // 只会赋值json中有的字段，其他保持原本的值
}
```

### 反射

##### 基本概念

反射是指在程序运行期间对程序本身进行访问和修改的能力。 正常情况程序在编译时， 变量被转换为内存地址， 变量名不会被编译器写入到可执行部分。 在运行程序时， 程序无法获取自身的信息。 支持反射的语言可以在程序编译期将变量的反射信息， 如字段名称、 类型信息、结构体信息等整合到可执行文件中， 并给程序提供接口访问反射信息， 这样就可以在程序运行期获取类型的反射信息， 并且有能力修改它们  

> ORM:对象关系映射（ Object Relational Mapping， 简称 ORM） 是通过使用描述对象和数据库之间映射的元数据， 将面向对象语言程序中的对象自动持久化到关系数据库中。

Golang 支持的反射：

1. 反射可以在程序运行期间动态的获取变量的各种信息， 比如变量的类型 类别
2. 如果是结构体， 通过反射还可以获取结构体本身的信息， 比如结构体的字段、 结构体的方法、 结构体的 tag
3. 通过反射， 可以修改变量的值， 可以调用关联的方法

Go 变量分为类型信息： 预先定义好的元信息、值信息：程序运行过程中可动态变化的。

在 GoLang 的反射机制中， 任何接口值都由是一个具体类型和具体类型的值两部分组成的。

在 GoLang 中， 反射的相关功能由内置的 reflect 包提供， 任意接口值在反射中都可以理解为由 reflect.Type 和 reflect.Value 两部分组成 ， 并且 reflect 包 提供了 reflect.TypeOf 和reflect.ValueOf 两个重要函数来获取任意对象的 Value 和 Type

在反射中关于类型还划分为两种： 类型（Type） 和种类（ Kind） 。 因为在 Go 语言中我们可以使用 type 关键字构造很多自定义类型， 而种类（Kind） 就是指底层的类型， 但在反射中，当需要区分指针、 结构体等大品种的类型时， 就会用到种类（Kind） 。 举个例子， 我们定义了两个指针类型和两个结构体类型， 通过反射查看它们的类型和种类。  

> 反射不应该被滥用，原因有以下两个。
>
> 1. 基于反射的代码是极其脆弱的， 反射中的类型错误会在真正运行的时候才会引发 panic 那很可能是在代码写完的很长时间之后。
>
> 2. 大量使用反射的代码通常难以理解

##### TypeOf

分别输出 name, kind

```go
package main

import (
	"fmt"
	"reflect"
)

func testReflect(x interface{}) {
	t := reflect.TypeOf(x)
	fmt.Println(t, t.Name(), t.Kind())
}
func main() {
	var x1 float32 = 12.5
	testReflect(x1)  // float32 float32 float32
	testReflect(100) // int int int
	var a *float32   // 无论指向与否，输出一样
	testReflect(a)   // *float32   ptr
	type myint int64 //自定义类型
	var b myint
	testReflect(b) // main.myint myint int64
	// main是包的意思，放函数外也是main.myint
	var c rune     // 别名
	testReflect(c) // int32 int32 int32
	type person struct {
		name string
		age  int
	}
	var d = person{"lr580", 580}
	testReflect(d) // main.person person struct
	var f = []int{99, 82, 44, 353}
	testReflect(f) // []int  slice
}
```

```go
type Kind uint
const (
    Invalid Kind = iota // 非法类型
    Bool // 布尔型
    Int // 有符号整型
    Int8 // 有符号 8 位整型
    Int16 // 有符号 16 位整型
    Int32 // 有符号 32 位整型
    Int64 // 有符号 64 位整型
    Uint // 无符号整型
    Uint8 // 无符号 8 位整型
    Uint16 // 无符号 16 位整型
    Uint32 // 无符号 32 位整型
    Uint64 // 无符号 64 位整型
    Uintptr // 指针
    Float32 // 单精度浮点数
    Float64 // 双精度浮点数
    Complex64 // 64 位复数类型
    Complex128 // 128 位复数类型
    Array // 数组
    Chan // 通道
    Func // 函数
    Interface // 接口
    Map // 映射
    Ptr // 指针
    Slice // 切片
    String // 字符串
    Struct // 结构体
    UnsafePointer // 底层指针
)
```

##### ValueOf

reflect.Value 与原始值之间可以互相转换，如：

```go
var a int64 = 100
v := reflect.ValueOf(a)
var av = v.Int() + 58 //int64
fmt.Println(v, av)    // 100, 158
fmt.Printf("%T\n", v) // reflect.Value
```

同理有 `v.Float()` 方法，对浮点类型。

switch 判断类型 (可以拿来判断的，见上文 Kind const)

```go
var a int64 = 100
k := reflect.ValueOf(a).Kind()
switch k {
case reflect.Int64:
    fmt.Println("int64")
// ...
default:
    fmt.Println("other")
}
```

##### Elem()

需要注意函数参数传递的是值拷贝， 必须传递变量地址才能修改变量值。 而反射中使用专有的 Elem()方法来获取指针对应的值  

```go
var a int64 = 100
ad := &a // *int64
v = reflect.ValueOf(ad)
fmt.Println(v)  // 0xc0001060a8
v2 := v.Elem()  // 取地址元素值
fmt.Println(v2) // 100
if v2.Kind() == reflect.Int64 {
    v2.SetInt(580) // 在这里可以不判断 if
}
fmt.Println(a, v2) // 580 580
```

##### 结构体

1. `Field(int)`  根据索引， 返回索引对应的结构体字段
2. `NumField()` 几个子段
3. `FieldByName(string)` 根据给定字符串返回字符串对应的结构体字段
4. `FieldByNameFunc(match func(string) bool) (StructField,bool)` 根据传入的匹配函数匹配需要的字段
5. `NumMethod() Int` 返回该类型的方法集中方法的数目
6. `Method(int)` 返回该类型方法集中的第 i 个方法
7. `MethodByName(string)(Method, bool)` 根据方法名返回该类型方法集中的方法

子段结构体有的成员：[src](http://golang.org/ref/spec#Uniqueness_of_identifiers)

> ```go
> type StructField struct {
>     Name string // Name 是字段的名字
>     PkgPath string //PkgPath 是非导出字段的包路径， 对导出字段该字段为""
>     Type Type // 字段的类型
>     Tag StructTag // 字段的标签
>     Offset uintptr // 字段在结构体中的字节偏移量
>     Index []int // 用于 Type.FieldByIndex 时的索引切片
>     Anonymous bool // 是否匿名字段
> }
> ```

如：查询、使用

```go
package main

import (
	"fmt"
	"reflect"
)

// student结构体
type Student struct {
	Name  string `json:"name1" form:"username"`
	Age   int    `json:"age"`
	Score int    `json:"score"`
}

func (s Student) GetInfo() string {
	var str = fmt.Sprintf("姓名:%v 年龄:%v 成绩:%v", s.Name, s.Age, s.Score)
	return str
}

func (s *Student) SetInfo(name string, age int, score int) {
	s.Name = name
	s.Age = age
	s.Score = score
}

func (s Student) Print() {
	fmt.Println("这是一个打印方法...")
}

// 打印字段
func PrintStructField(s interface{}) {

	//判断参数是不是结构体类型
	t := reflect.TypeOf(s)
	v := reflect.ValueOf(s)
	if t.Kind() != reflect.Struct && t.Elem().Kind() != reflect.Struct {
		fmt.Println("传入的参数不是一个结构体")
		return
	}

	//1、通过类型变量里面的Field可以获取结构体的字段
	field0 := t.Field(0)
	fmt.Printf("%#v \n", field0)      //reflect.StructField{Name:"Name", PkgPath:"", Type:(*reflect.rtype)(0x4adf20), Tag:"json:\"name\"", Offset:0x0, Index:[]int{0}, Anonymous:false}
	fmt.Println("字段名称：", field0.Name) // Name (按定义顺序)
	fmt.Println("字段类型：", field0.Type)
	fmt.Println("字段Tag：", field0.Tag.Get("json")) //name1
	fmt.Println("字段Tag：", field0.Tag.Get("form"))
	//2、通过类型变量里面的FieldByName可以获取结构体的字段
	fmt.Println("----------------------")
	field1, ok := t.FieldByName("Age")
	if ok {
		fmt.Println("字段名称：", field1.Name)
		fmt.Println("字段类型：", field1.Type)
		fmt.Println("字段Tag：", field1.Tag.Get("json"))
	}

	//3、通过类型变量里面的NumField获取到该结构体有几个字段

	var fieldCount = t.NumField()
	fmt.Println("结构体有", fieldCount, "个属性")

	//4、通过值变量获取结构体属性对应的值

	fmt.Println(v.FieldByName("Name"))
	fmt.Println(v.FieldByName("Age"))
	fmt.Println("----------------------")
	for i := 0; i < fieldCount; i++ {
		fmt.Printf("属性名称:%v 属性值:%v 属性类型:%v 属性Tag:%v\n", t.Field(i).Name, v.Field(i), t.Field(i).Type, t.Field(i).Tag.Get("json"))
	}

}

// 打印执行方法
func PrintStructFn(s interface{}) {

	t := reflect.TypeOf(s)
	v := reflect.ValueOf(s)
	if t.Kind() != reflect.Struct && t.Elem().Kind() != reflect.Struct {
		fmt.Println("传入的参数不是一个结构体")
		return
	}
	//1、通过类型变量里面的Method可以获取结构体的方法
	method0 := t.Method(0)    //和结构体方法的顺序没有关系，和结构体方法的ASCII有关系 // 按字典序排序
	fmt.Println(method0.Name) //GetInfo
	fmt.Println(method0.Type) //func(*main.Student) string

	fmt.Println("--------------------------")
	//2、通过类型变量获取这个结构体有多少个方法

	method1, ok := t.MethodByName("Print")
	if ok {
		fmt.Println(method1.Name) //Print
		fmt.Println(method1.Type) //func(*main.Student)
	}
	fmt.Println("--------------------------")
	//3、通过《值变量》执行方法 （注意需要使用值变量，并且要注意参数） v.Method(0).Call(nil) 或者v.MethodByName("Print").Call(nil)
	// v.Method(1).Call(nil)
	v.MethodByName("Print").Call(nil) // 会调用, call 传入参数调用
	// 得到返回值 info1
	info1 := v.MethodByName("GetInfo").Call(nil)
	fmt.Println(info1) //长为1的数组，第一个元素是返回值
	//4、执行方法传入参数 （注意需要使用《值变量》，并且要注意参数,接收的参数是[]reflect.Value的切片）

	var params []reflect.Value
	params = append(params, reflect.ValueOf("李四"))
	params = append(params, reflect.ValueOf(23))
	params = append(params, reflect.ValueOf(99))
	v.MethodByName("SetInfo").Call(params) //执行方法传入参数

	info2 := v.MethodByName("GetInfo").Call(nil)
	fmt.Println(info2)

	// 5、获取方法数量

	fmt.Println("方法数量:", t.NumMethod())

}

func main() {
	stu1 := Student{
		Name:  "小明",
		Age:   15,
		Score: 98,
	}
	PrintStructField(stu1)
	PrintStructFn(&stu1)

	fmt.Printf("%#v\n", stu1) // main.Student{Name:"李四", Age:23, Score:99}
}
```

如：修改

```go
package main

import (
	"fmt"
	"reflect"
)

// student结构体
type Student struct {
	Name  string `json:"name"`
	Age   int    `json:"age"`
	Score int    `json:"score"`
}

// 反射修改结构体属性
func reflectChangeStruct(s interface{}) {
	t := reflect.TypeOf(s)
	v := reflect.ValueOf(s)

	if t.Kind() != reflect.Ptr {
		fmt.Println("传入的不是结构体指针类型")
		return
	} else if t.Elem().Kind() != reflect.Struct {

		fmt.Println("传入的不是结构体指针类型")
		return
	}
	//修改结构体属性的值
	name := v.Elem().FieldByName("Name")
	name.SetString("小李")

	age := v.Elem().FieldByName("Age")
	age.SetInt(22)

}
func main() {
	stu1 := Student{
		Name:  "小明",
		Age:   15,
		Score: 98,
	}
	reflectChangeStruct(&stu1)

	fmt.Printf("%#v\n", stu1) //main.Student{Name:"小李", Age:22, Score:98}
}
```



## 第三方包

### 数值

```sh
go get github.com/shopspring/decimal
```

参考官网文档，如：

```go
fee, _ := decimal.NewFromString(".035")
taxRate, _ := decimal.NewFromString(".08875")
fmt.Println(fee.Add(taxRate)) // 0.12375
```

# 框架

## Gin

[官网](https://gin-gonic.com/zh-cn/)

### 基础

#### 安装使用

```go
go get -u github.com/gin-gonic/gin
```

