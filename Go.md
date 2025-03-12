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

#### 运算

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
type i32 int32
type dbFunc func(int, int) int
```

```go
var vv i32 = 666
fmt.Println(vv)
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

##### 常规

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

##### 常用方法

反向使用字符串 contains，可以求当前字符是否是某几个字符的一个

```go
if strings.ContainsRune("aeiou", b) { // ...
```



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
```

可以省略长度

```go
var d = [...]int{1437, 580}
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

### 异常

#### panic

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



## 常用包

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

time.Duration 是 time 包定义的一个类型， 它代表两个时间点之间经过的时间， 以纳秒为单位。 time.Duration 表示一段时间间隔， 可表示的最长时间段大约 290 年  

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

