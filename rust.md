# Rust

## 基础

### 环境

[官网](https://www.rust-lang.org/zh-CN/tools/install) 下 rustup，然后运行，等待其下载相关内容并自动安装。运行安装时会提示 path 的位置。

vscode 安装 `rust-analyzer`，语法高亮 `rust-syntax`，依赖分析 `crates`，项目配置管理 `better toml`，测试 `rust test lens`，等。[参考](https://blog.csdn.net/inthat/article/details/121519036)

在 vscode 测试 hell world：`a.rs`

```rust
fn main() {
    println!("一二三");
}
```

ctrl+alt+n 运行。

rust 版本测试：

```sh
rustc -V
rustc --version
```

包/项目测试：(如果文件夹已存在，cd 进去 `cargo init`)

```sh
cargo new hellworld
```

cd 进去跑：

```sh
cargo build
cargo run
```

> 只在 cargo 项目内有效，零散文件无效。文档注释：
>
> ```rust
> /// a+b problem
> ///
> /// # Examples
> ///
> /// ```
> /// let x = add(1, 2);
> /// ```
> fn add(a: i32, b: i32) -> i32 {
>     return a + b;
> }
> fn main() {
>     println!("{}", add(1437, 580));
> }
> ```
>
> Cargo 具有 cargo doc 功能，开发者可以通过这个命令将工程中的说明注释转换成 HTML 格式的说明文档。

挂 git 时，可以忽略一些生成的可执行文件等，可以加 `.gitignore`：(GPT)

```gitignore
# Rust/Cargo specific
/target/
/cargo.lock
*.exe
*.pdb

# IDE/editor specific
/.vscode/
/.idea/
/.idea_modules/
*.iml
*.ipr
*.iws

# Generated files
Cargo.toml.orig
Cargo.lock.orig
```



### cargo

添加依赖，在 `Cargo.toml` 的 `dependencies` 添加，如：

```ini
[dependencies]
reqwest = "0.11.4"
```

> 如果装不了包，挂个梯子。

在执行 `cargo build` 或者 `cargo run` 命令时，Cargo 会自动下载并安装依赖，然后编译并构建项目。如果依赖的版本号不正确，Cargo 会给出相应的提示信息，可以根据提示信息调整版本号。

可以运行 `cargo test`，类似 spring 的 `src/test`。对所有被 main 所引用故能被扫描到的模块里，如果有函数有 `#[test]`，就会被执行测试。

主函数参数：如 `cargo run -- init`，接收参数代码示例：

```rust
let args: Vec<String> = env::args().collect();
    if let Some(arg1) = args.get(1) {
        if arg1 == "init" {
```



## 语法

语句加分号。跟 C++ 相似(如大括号规则等)。

注释同 C。可以用 `///` 注释，函数前作为说明注释显示在文档里，支持 md。

非面向对象。

不支持 null 引用。

### 变量

#### 基本语法

强类型，但能自动判断变量类型。默认是不可变变量，如果要求能重新赋值，需要加 `mut` 关键字。

```rust
let mut z = 1437;
print!("z={}", z);
z = 580;
print!(" z={}", z);
// z = "6"; 不行
```

不可变变量可以重新 let，此时可以修改类型，但常量 `const` 不可以。

```rust
let a = 114514;
print!("a={}", a);
let a = "哈?";
print!(" a={}", a);
```

可以声明类型：

```rust
let b : u32 = 998244353; 
print!(" b={}", b);
```

常量 `const` 必须声明类型。常量名字要大写，不然会被编译器警告。

```rust
const C : i64 = 666;
print!(" c={}", C);
```

重影是指用同一个名字重新代表另一个变量实体，其类型、可变属性和值都可以变化。但可变变量赋值仅能发生值的变化。

语句是执行某些操作且没有返回值的步骤。表达式有计算步骤且有返回值。如赋值是表达式，let是语句。可以用大括号代码块写复杂表达式，如：

```rust
let y = {
    let x = 3;
    x + 1
}; //注意x+1之后没有分号，否则是语句
```



#### 基本数据类型

> - 所有整数类型，例如 i32 、 u32 、 i64 等。
> - 布尔类型 bool，值为 true 或 false 。
> - 所有浮点类型，f32 和 f64。
> - 字符类型 char。
> - 仅包含以上类型数据的元组（Tuples）。

有 `8,16,32,64,128` 位的有符号和无符号，分别是 `i,u`。如 `i8,u128`。

> isize 和 usize 两种整数类型是用来衡量数据大小的，它们的位长度取决于所运行的目标平台，如果是 32 位架构的处理器将使用 32 位位长度整型

整数的表示法：`0x`,`0o`,`0b`。十进制可以用下划线隔开，表示诸如千这样的概念。`u8` 类型还可以表示字节，如 `b'A'`。

```rust
let e = 98_222;
print!(" e={}", e); //98222
```

浮点数有 `f32`,`f64`。默认表示 `f64`。

Rust 不支持 **++** 和 **--**。

```rust
let mut f = 2.;
print!(" f={}", f);
f = 1. / 3.; // 1/3报错，不能转类型过去
print!(" f={}", f);
```

布尔值是 `bool`，取 `true` / `false`。

字符是 `char`，四个字节，unicode 标量。U+0000 到 U+D7FF 和 U+E000 到 U+10FFFF

> 一般推荐使用字符串储存 UTF-8 文字（非英文字符尽可能地出现在字符串中）。由于中文文字编码有两种（GBK 和 UTF-8），所以编程中使用中文字符串有可能导致乱码的出现，这是因为源程序与命令行的文字编码不一致，所以在 Rust 中字符串和字符都必须使用 UTF-8 编码，否则编译器会报错。

类型转换用 as，如：

```rust
let l = 2;
let li = l as usize; 
```

类型简写：

```rust
type uz = usize;
```



#### 复合类型

元组用 `()` 包括一组类型可以不同的数据。

```rust
let g: (i32, f64, u8) = (500, 6.4, 1);
let (g1, g2, g3) = g;
println!(" {} {} {}", g1, g2, g3);
let h = (3, 4, 5, 6);
let (h1, h2, h3, h4) = h;
println!("{}", h1 + h2 + h3 + h4);
```

数组用 `[]` 包括一组类型相同的数据。

```rust
let k = [1, 1, 4, 5, 1, 4];
let l: [i32; 7] = [1, 9, 1, 9, 8, 1, 0];
let m = [6; 5]; //[6,6,6,6,6]
let m0 = m[0];
let k5 = k[5];
let l1 = l[1];
// m[0] = 7; //数组不可变
println!("{} {} {}", m0, k5, l1);
```

数组加 mut 可变，但元组加了也不可变。

```rust
let mut p = [6, 7, 8];
p[2] = 666;
println!("{}", p[2]);
```

数组取长度：`.len()`。元组没有。

输出：

```rust
#[derive(Debug)]
fn nxx() {
    let w = [1, 2, 3];
    println!("{}", w.len());
    println!("{:?}", w); //[1, 2, 3]
}
```



#### 所有权

##### 基本规则

C/C++ 手动管理内存，Java 用 JVM 管理。Rust 用所有权管理内存。规则如下：

- Rust 中的每个值都有一个变量，称为其所有者。
- 一次只能有一个所有者。
- 当所有者不在程序运行范围时，该值将被删除。

变量范围/可行域：从声明变量开始有效直到变量所在域结束。

```rust
{
    // 在声明以前，变量 s 无效
    let s = "runoob";
    // 这里是变量 s 的可用范围
}
// 变量范围已经结束，变量 s 无效
```

Rust 之所以没有明示释放的步骤是因为在变量范围结束的时候，Rust 编译器自动添加了调用释放资源函数的步骤。

##### 移动与克隆

变量与数据交互方式主要有移动（Move）和克隆（Clone）两种：

移动：

```rust
let x = 5;
let y = x;
println!("{} {}", x, y);
```

数据是"基本数据"类型的数据，不需要存储到堆中，仅在栈中的数据的"移动"方式是直接复制。

```rust
let s1 = String::from("hello");//类似于长度不确定的数据，需要在堆中存储
let s2 = s1;
println!("{}, world!", s1); // 错误！s1 已经失效 (移动)
//如果s1="hello",则不会这样,s1,s2都可用
```

为了满足所有权，s1 失效时会释放该字符串，则 s2 用不了。为了解决这个问题，语法规定只要发生上述情况，自动失效 s1，把字符串移动给 s2 用。所以需要克隆，堆里真的会存两份字符串，才能满足，即：

```rust
fn main() {
    let s1 = String::from("hello");
    let s2 = s1.clone();
    println!("s1 = {}, s2 = {}", s1, s2);
}
```

如果将变量当作参数传入函数，那么它和移动的效果是一样的。

```rust
fn man() {
    let s = String::from("hello");
    // s 被声明有效

    takes_ownership(s);
    // s 的值被当作参数传入函数
    // 所以可以当作 s 已经被移动，从这里开始已经无效
    // println!("{}", s);//达咩

    let x = 5;
    // x 被声明有效

    makes_copy(x);
    // x 的值被当作参数传入函数
    // 但 x 是基本类型，依然有效
    // 在这里依然可以使用 x 却不能使用 s

} // 函数结束, x 无效, 然后是 s. 但 s 已被移动, 所以不用被释放


fn takes_ownership(some_string: String) {
    // 一个 String 参数 some_string 传入，有效
    println!("{}", some_string);
} // 函数结束, 参数 some_string 在这里释放

fn makes_copy(some_integer: i32) {
    // 一个 i32 参数 some_integer 传入，有效
    println!("{}", some_integer);
} // 函数结束, 参数 some_integer 是基本类型, 无需释放
```

被当作函数返回值的变量所有权将会被移动出函数并返回到调用函数的地方，而不会直接被无效释放。

```rust
fn man2() {
    let s1 = gives_ownership();
    // gives_ownership 移动它的返回值到 s1

    let s2 = String::from("hello");
    // s2 被声明有效

    let s3 = takes_and_gives_back(s2);
    // s2 被当作参数移动, s3 获得返回值所有权
    println!("{} {}", s1, s3);
    // println!("{}", s2); //nope
} // s3 无效被释放, s2 被移动, s1 无效被释放.

fn gives_ownership() -> String {
    let some_string = String::from("hello");
    // some_string 被声明有效

    return some_string;
    // some_string 被当作返回值移动出函数
}

fn takes_and_gives_back(a_string: String) -> String {
    // a_string 被声明有效

    a_string // a_string 被当作返回值移出函数
}
```

##### 引用与租借

\& 运算符可以取变量的"引用"。

```rust
fn main() {
    let s1 = String::from("hello");
    let s2 = &s1;
    println!("s1 is {}, s2 is {}", s1, s2);
}
```

当一个变量的值被引用时，变量本身不会被认定无效。因为"引用"并没有在栈中复制变量的值。

引用不会获得值的所有权。

引用只能租借（Borrow）值的所有权。

引用本身也是一个类型并具有一个值，这个值记录的是别的值所在的位置。

```rust
fn main() {
    let s1 = String::from("hello");

    let len = calculate_length(&s1);

    println!("The length of '{}' is {}.", s1, len);
}

fn calculate_length(s: &String) -> usize {
    s.len()
}
```

> ```rust
> fn main() {
>     let s1 = String::from("hello");
>     let s2 = &s1;
>     let s3 = s1;
>     println!("{}", s2);
> }
> ```
>
> 这段程序不正确：因为 s2 租借的 s1 已经将所有权移动到 s3，所以 s2 将无法继续租借使用 s1 的所有权。如果需要使用 s2 使用该值，必须重新租借：
>
> ```rust
> fn main() {
>     let s1 = String::from("hello");
>     let mut s2 = &s1;
>     let s3 = s1;
>     s2 = &s3; // 重新从 s3 租借所有权
>     println!("{}", s2);
> }
> ```

如果尝试利用租借来的权利来修改数据会被阻止。

```rust
fn main() {
    let s1 = String::from("run");
    let s2 = &s1;
    println!("{}", s2);
    s2.push_str("oob"); // 错误，禁止修改租借的值
    println!("{}", s2);
}
```

可变租借：对基本数据类型需要解引用。

```rust
let mut xx = 5;
let yy = &mut xx;
*yy = 666;
println!("{}", xx); //不能同时输出 xx, yy 但是可以分两次 println
```

```rust
fn main() {
    let mut s1 = String::from("run");
    // s1 是可变的

    let s2 = &mut s1;
    // s2 是可变的引用

    s2.push_str("oob");
    println!("{}", s1);
}
```

可变引用与不可变引用相比除了权限不同以外，可变引用不允许多重引用，但不可变引用可以。有可变引用之后连不可变引用都不给了。

```rust
fn abss() {
    let mut x = 5;
    let y = &mut x;
    *y = 6;
    println!("{}", x);
    let z = & x;
    // *y = 7;//没有这行z就能输出，有就不行
    // let z = &x;//有的话无论放哪都不行
    println!("{}", z);
}
```

> 这个代码也不行：
>
> ```rust
> let mut s = String::from("hello");
> let r1 = &mut s;
> let r2 = &mut s;
> println!("{}, {}", r1, r2);
> ```

Rust 对可变引用的这种设计主要出于对并发状态下发生数据访问碰撞的考虑，在编译阶段就避免了这种事情的发生。

由于发生数据访问碰撞的必要条件之一1是数据被至少一个使用者写且同时被至少一个其他使用者读或写，所以在**一个值被可变引用时不允许再次被任何引用**。



垂悬引用（Dangling References）在 Rust 语言里不允许出现，如果有，编译器会发现它。

```rust
fn main() {
    let reference_to_nothing = dangle();
}

fn dangle() -> &String {
    let s = String::from("hello");

    &s
}
```

很显然，伴着 dangle 函数的结束，其局部变量的值本身没有被当作返回值，被释放了。但它的引用却被返回，这个引用所指向的值已经不能确定的存在，故不允许其出现。

#### 生命周期

##### 生命周期注释

```rust
fn longer(s1: &str, s2: &str) -> &str {
    if s2.len() > s1.len() {
        s2
    } else {
        s1
    }
}
```

longer 函数取 s1 和 s2 两个字符串切片中较长的一个返回其引用值。但只这段代码不会通过编译，原因是返回值引用可能会返回过期的引用，例如：

```rust
fn main() {
    let r;
    {
        let s1 = "rust";
        let s2 = "ecmascript";
        r = longer(s1, s2);
    }
    println!("{} is longer", r);
}
```

生命周期注释是描述引用生命周期的办法。

虽然这样并不能够改变引用的生命周期，但可以在合适的地方声明两个引用的生命周期一致。

生命周期注释用单引号开头，跟着一个小写字母单词：

```rust
&i32        // 常规引用
&'a i32     // 含有生命周期注释的引用
&'a mut i32 // 可变型含有生命周期注释的引用
```

```rust
fn longer<'a>(s1: &'a str, s2: &'a str) -> &'a str {
    if s2.len() > s1.len() {
        s2
    } else {
        s1
    }
}
```

用泛型声明来规范生命周期的名称，随后函数返回值的生命周期将与两个参数的生命周期一致。随后：

```rust
fn main() {
    let r;
    {
        let s1 = "rust";
        let s2 = "ecmascript";
        r = longer(s1, s2);
        println!("{} is longer", r);
    }
}
```

早期 Rust 不支持生命周期自动判断，所有的生命周期必须严格声明，但主流稳定版本的 Rust 已经支持了这个功能。

```rust
fn main() {
    struct Str<'a> {
        content: &'a str
    }
    let s = Str {
        content: "string_slice"
    };
    println!("s.content = {}", s.content);
}
```

```rust
impl<'a> Str<'a> {
    fn get_content(&self) -> &str {
        self.content
    }
}
```

##### 静态生命周期

生命周期注释有一个特别的：'static 。所有用双引号包括的字符串常量所代表的精确数据类型都是 &'static str ，'static 所表示的生命周期从程序运行开始到程序运行结束。

#### 字符串

两种常用的字符串类型：str 和 String。str 是 Rust 核心语言类型，字符串切片（String Slice），常常以引用的形式出现（&str）。

凡是用双引号包括的字符串常量整体的类型性质都是 &str。

String 类型是 Rust 标准公共库提供的一种数据类型，它的功能更完善——它支持字符串的追加、清空等实用的操作。String 和 str 除了同样拥有一个字符开始位置属性和一个字符串长度属性以外还有一个容量（capacity）属性。

String 和 str 都支持切片，切片的结果是 &str 类型的数据。

有一个快速的办法可以将 String 转换成 &str：

```rust
let s1 = String::from("hello");
let s2 = &s1[..];
```

有方法 `.len()`。

可以格式化，如：

```rust
let app_name : &String = ...;
return format!("Hello {app_name}!"); //String
```



##### String

```rust
let string = String::new();
```

```rust
let one = 1.to_string();         // 整数到字符串
let float = 1.3.to_string();     // 浮点数到字符串
let slice = "slice".to_string(); // 字符串切片到字符串
```

```rust
let hello = String::from("السلام عليكم");
let hello = String::from("Dobrý den");
let hello = String::from("Hello");
let hello = String::from("שָׁלוֹם");
let hello = String::from("नमस्ते");
let hello = String::from("こんにちは");
let hello = String::from("안녕하세요");
let hello = String::from("你好");
let hello = String::from("Olá");
let hello = String::from("Здравствуйте");
let hello = String::from("Hola");
```

追加：

```rust
let mut s = String::from("run");
s.push_str("oob"); // 追加字符串切片
s.push('!');       // 追加字符
```

```rust
let s1 = String::from("Hello, ");
let s2 = String::from("world!");
let s3 = s1 + &s2;
```

```rust
let s1 = String::from("tic");
let s2 = String::from("tac");
let s3 = String::from("toe");
let s = s1 + "-" + &s2 + "-" + &s3;
```

```rust
let s1 = String::from("tic");
let s2 = String::from("tac");
let s3 = String::from("toe");
let s = format!("{}-{}-{}", s1, s2, s3);
```

```rust
let s = "你好";
let len = s.len();//5
```

```rust
let s = "hello你好";
let len = s.chars().count();//7
```

```rust
fn main() {
    let s = String::from("hello中文");
    for c in s.chars() {
        println!("{}", c);
    }
}
```

```rust
fn main() {
    let s = String::from("EN中文");
    let a = s.chars().nth(2);//中
    println!("{:?}", a);
}
```

nth 函数是从迭代器中取出某值的方法，请不要在遍历中这样使用！因为 UTF-8 每个字符的长度不一定相等

```rust
fn main() {
    let s = String::from("EN中文");
    let sub = &s[0..2];//0..3不行
    println!("{}", sub);
}
```



#### 切片类型

是 `[,)` 的左闭右开区间。

```rust
fn main() {
    let s = String::from("broadcast");

    let part1 = &s[0..5];
    let part2 = &s[5..9];

    println!("{}={}+{}", s, part1, part2);
}
```

Rust 中的字符串类型实质上记录了字符在内存中的起始位置和其长度。

```rust
..y //等价于 0..y
x.. //等价于位置 x 到数据结束
.. //等价于位置 0 到结束
```

被切片引用的字符串禁止更改其值

```rust
fn main() {
    let mut s = String::from("runoob");
    let slice = &s[0..3];
    s.push_str("yes!"); // 错误
    println!("slice = {}", slice);
}
```

注意：切片结果必须是引用类型，但开发者必须自己明示这一点



数组切片：

```rust
fn main() {
    let arr = [1, 3, 5, 7, 9];
    let part = &arr[0..3];
    for i in part.iter() {
        println!("{}", i);
    }
}
```



#### 结构体

##### 普通

结构体的每个成员叫做"字段"。

```rust
struct Site {
    domain: String,
    name: String,
    nation: String,
    found: u32
}
```

Rust 里 struct 语句仅用来定义，不能声明实例，结尾不需要 **;** 符号，而且每个字段定义之后用 **,** 分隔。

实例化：

```rust
let runoob = Site {
    domain: String::from("www.runoob.com"),
    name: String::from("RUNOOB"),
    nation: String::from("China"),
    found: 2013
};
```

好处是不仅使程序更加直观，还不需要按照定义的顺序来输入成员的值。

如果正在实例化的结构体有字段名称和现存变量名称一样的，可以简化书写。

```rust
let domain = String::from("www.runoob.com");
let name = String::from("RUNOOB");
let runoob = Site {
    domain,  // 等同于 domain : domain,
    name,    // 等同于 name : name,
    nation: String::from("China"),
    traffic: 2013
};
```

想要新建一个结构体的实例，其中大部分属性需要被设置成与现存的一个结构体属性一样，仅需更改其中的一两个字段的值，可以使用结构体更新语法：

```rust
let site = Site {
    domain: String::from("www.runoob.com"),
    name: String::from("RUNOOB"),
    ..runoob
};
```

注意：..runoob 后面不可以有逗号。这种语法不允许一成不变的复制另一个结构体实例，意思就是说至少重新设定一个字段的值才能引用其他实例的值。

##### 元组结构体

更简单的定义和使用结构体的方式：**元组结构体**。

元组结构体是一种形式是元组的结构体。

与元组的区别是它有名字和固定的类型格式。它存在的意义是为了处理那些需要定义类型（经常使用）又不想太复杂的简单数据：

```rust
struct Color(u8, u8, u8);
struct Point(f64, f64);
let black = Color(0, 0, 0);
let origin = Point(0.0, 0.0);
println!("black = ({}, {}, {})", black.0, black.1, black.2);
println!("origin = ({}, {})", origin.0, origin.1);
```

结构体必须掌握字段值所有权，因为结构体失效的时候会释放所有字段。

##### 输出

结构体的输出：(导入调试库 `#[derive(Debug)]`)

```rust
#[derive(Debug)]

struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };

    println!("rect1 is {:?}", rect1);
}
```

结果：

```
rect1 is Rectangle { width: 30, height: 50 }
```

如果属性较多的话可以使用另一个占位符 `{:#?}` 。

输出结果：

```rust
rect1 is Rectangle {
    width: 30,
    height: 50
}
```

##### 方法

结构体方法的第一个参数必须是 &self，不需声明类型，因为 self 不是一种风格而是关键字

```rust
struct Rectangle {
    width: u32,
    height: u32,
}
   
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };
    println!("rect1's area is {}", rect1.area());
}
```

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn wider(&self, rect: &Rectangle) -> bool {
        self.width > rect.width
    }
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };
    let rect2 = Rectangle { width: 40, height: 20 };

    println!("{}", rect1.wider(&rect2));
}
```

结构体 impl 块可以写几次，效果相当于它们内容的拼接

##### 关联函数

不含 `self` 参数。

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn create(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }
}

fn main() {
    let rect = Rectangle::create(30, 50);
    println!("{:?}", rect);
}
```

##### 单元结构体

结构体可以只作为一种象征而无需任何成员：

```rust
struct UnitStruct;
```

我们称这种没有身体的结构体为单元结构体（Unit Struct）。

#### 枚举类

##### 常规

```rust
#[derive(Debug)]

enum Book {
    Papery, Electronic
}

fn main() {
    let book = Book::Papery;
    println!("{:?}", book); //Papery
}
```



```rust
enum Book {
    Papery(u32),
    Electronic(String),
}
let book = Book::Papery(1001);
let ebook = Book::Electronic(String::from("url://..."));
```

```rust
enum Book {
    Papery { index: u32 },
    Electronic { url: String },
}
let book = Book::Papery{index: 1001};
```

Rust 通过 match 语句来实现分支结构。

```rust
fn main() {
    enum Book {
        Papery {index: u32},
        Electronic {url: String},
    }
   
    let book = Book::Papery{index: 1001};
    let ebook = Book::Electronic{url: String::from("url...")};
   
    match book {
        Book::Papery { index } => {
            println!("Papery book {}", index);//输出这个
        },
        Book::Electronic { url } => {
            println!("E-book {}", url);
        }
    }
}
```

match 块也可以当作函数表达式来对待，它也是可以有返回值的，但是所有返回值表达式的类型必须一样：

```rust
match 枚举类实例 {
    分类1 => 返回值表达式,
    分类2 => 返回值表达式,
    ...
}
```

如果把枚举类附加属性定义成元组，在 match 块中需要临时指定一个名字：

```rust
enum Book {
    Papery(u32),
    Electronic {url: String},
}
let book = Book::Papery(1001);

match book {
    Book::Papery(i) => {
        println!("{}", i);
    },
    Book::Electronic { url } => {
        println!("{}", url);
    }
}
```

##### Option

```rust
enum Option<T> {
    Some(T),
    None,
}
```

定义一个可以为空值的类：

```rust
let opt = Option::Some("Hello");
```

```rust
fn main() {
    let opt = Option::Some("Hello");
    match opt {
        Option::Some(something) => {
            println!("{}", something);
        },
        Option::None => {
            println!("opt is nothing");
        }
    }
}
```

如果你的变量刚开始是空值，以初始值为空的 Option 必须明确类型

```rust
let opt: Option<&str> = Option::None;
```

由于 Option 是 Rust 编译器默认引入的，在使用时可以省略 Option:: 直接写 None 或者 Some()。

Option 是一种特殊的枚举类，它可以含值分支选择：

```rust
fn main() {
    let t = Some(64);
    match t {
        Some(64) => println!("Yes"),
        _ => println!("No"),
    }
}
```

> `unwrap()` 是 Rust 中 `Option` 和 `Result` 两种枚举类型的方法，用于获取其中的值。
>
> 具体来说，`Option` 和 `Result` 都是用于处理可能不存在或者可能出错的值的类型。`Option` 表示一个可能存在的值，它有两个变体，`Some` 表示存在值，`None` 表示不存在值。`Result` 表示一个可能出错的值，它也有两个变体，`Ok` 表示操作成功，包含操作的结果，`Err` 表示操作失败，包含错误信息。
>
> `unwrap()` 方法可以用于获取 `Option` 和 `Result` 中的值。如果 `Option` 中存在值，`unwrap()` 方法将返回该值，否则将会 panic。如果 `Result` 操作成功，`unwrap()` 方法将返回操作的结果，否则将会 panic，并将错误信息作为 panic 的参数。

#### 泛型

##### 基本

做一个泛型求 max：

```rust
fn max<T>(array: &[T]) -> T {
    let mut max_index = 0;
    let mut i = 1;
    while i < array.len() {
        if array[i] > array[max_index] {
            max_index = i;
        }
        i += 1;
    }
    array[max_index]
}
```

结构体/枚举类的泛型：

```rust
struct Point<T> {
    x: T,
    y: T
}
let p1 = Point {x: 1, y: 2};
let p2 = Point {x: 1.0, y: 2.0};
```

```rust
struct Point<T1, T2> {
    x: T1,
    y: T2
}
```

```rust
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

fn main() {
    let p = Point { x: 1, y: 2 };
    println!("p.x = {}", p.x());
}
```

```rust
impl Point<f64> {
    fn x(&self) -> f64 {
        self.x
    }
}
```

```rust
impl<T, U> Point<T, U> {
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}
```

##### 关联类型

定义抽象类型。

```rust
trait MyTrait {
    type Item;

    fn get_item(&self) -> Self::Item;
}
```

```rust
struct MyStruct {}

impl MyTrait for MyStruct {
    type Item = i32;

    fn get_item(&self) -> Self::Item {
        42
    }
}

```



#### 特性

##### 常规

特性（trait）概念接近于 Java 中的接口（Interface），但两者不完全相同。特性与接口相同的地方在于它们都是一种行为规范，可以用于标识哪些类有哪些方法。

```rust
trait Descriptive {
    fn describe(&self) -> String;
}
```


格式：

```
impl <特性名> for <所实现的类型名>
```

```rust
struct Person {
    name: String,
    age: u8
}
impl Descriptive for Person {
    fn describe(&self) -> String {
        format!("{} {}", self.name, self.age)
    }
}
```

Rust 同一个类可以实现多个特性，每个 impl 块只能实现一个。

显然特性的用途是作参数：

```rust
fn output(object: impl Descriptive) {
    println!("{}", object.describe());
}
```


这是一种风格类似泛型的语法糖，这种语法糖在有多个参数类型均是特性的情况下十分实用：

```rust
fn output<T: Descriptive>(object: T) {
    println!("{}", object.describe());
}
```

```sh
fn output_two<T: Descriptive>(arg1: T, arg2: T) {
    println!("{}", arg1.describe());
    println!("{}", arg2.describe());
}
```

特性作类型表示时如果涉及多个特性，可以用 **+** 符号表示，例如：

```rust
fn notify(item: impl Summary + Display)
fn notify<T: Summary + Display>(item: T)
```

仅用于表示类型的时候，并不意味着可以在 impl 块中使用。

复杂的实现关系可以使用 where 关键字简化，例如：

```rust
fn some_function<T: Display + Clone, U: Clone + Debug>(t: T, u: U)
```

```rust
fn some_function<T, U>(t: T, u: U) -> i32
    where T: Display + Clone,
          U: Clone + Debug
```

综合例子：

```rust
trait Comparable {
    fn compare(&self, object: &Self) -> i8;
}

fn max<T: Comparable>(array: &[T]) -> &T {
    let mut max_index = 0;
    let mut i = 1;
    while i < array.len() {
        if array[i].compare(&array[max_index]) > 0 {
            max_index = i;
        }
        i += 1;
    }
    &array[max_index]
}

impl Comparable for f64 {
    fn compare(&self, object: &f64) -> i8 {
        if &self > &object { 1 }
        else if &self == &object { 0 }
        else { -1 }
    }
}

fn main() {
    let arr = [1.0, 3.0, 5.0, 4.0, 2.0];
    println!("maximum of arr is {}", max(&arr));
}
```

由于需要声明 compare 函数的第二参数必须与实现该特性的类型相同，所以 Self （注意大小写）关键字就代表了当前类型（不是实例）本身。

作返回值：

```rust
fn person() -> impl Descriptive {
    Person {
        name: String::from("Cali"),
        age: 24
    }
}
```

但是有一点，特性做返回值只接受实现了该特性的对象做返回值且在同一个函数中所有可能的返回值类型必须完全一样。比如结构体 A 与结构体 B 都实现了特性 Trait，下面这个函数就是错误的：

```rust
fn some_function(bool bl) -> impl Descriptive {
    if bl {
        return A {};
    } else {
        return B {};
    }
}
```

条件实现：

```rust
struct A<T> {}

impl<T: B + C> A<T> {
    fn d(&self) {}
}
```

这段代码声明了 A<T> 类型必须在 T 已经实现 B 和 C 特性的前提下才能有效实现此 impl 块。

##### 默认特性

这是特性与接口的不同点：接口只能规范方法而不能定义方法，但特性可以定义方法作为默认方法，因为是"默认"，所以对象既可以重新定义方法，也可以不重新定义方法使用默认的方法

```rust
trait Descriptive {
    fn describe(&self) -> String {
        String::from("[Object]")
    }
}

struct Person {
    name: String,
    age: u8
}

impl Descriptive for Person {
    fn describe(&self) -> String {
        format!("{} {}", self.name, self.age)
    }
}

fn main() {
    let cali = Person {
        name: String::from("Cali"),
        age: 24
    };
    println!("{}", cali.describe());
}
```

##### 动态

使用 `dyn` 关键字可以显式地声明一个 trait 对象是动态的。例如，下面的代码定义了一个 `Animal` trait 和两个实现该 trait 的结构体 `Dog` 和 `Cat`：

```rust
trait Animal {
    fn make_sound(&self);
}
struct Dog;
struct Cat;
impl Animal for Dog {
    fn make_sound(&self) {
        println!("Woof!");
    }
}
impl Animal for Cat {
    fn make_sound(&self) {
        println!("Meow!");
    }
}
let animals: Vec<Box<dyn Animal>> = vec![
    Box::new(Dog),
    Box::new(Cat),
];
for animal in animals {
    animal.make_sound();
}
```

实现多态。

动态 trait 对象只能通过指针或引用来访问，因为其大小在编译期是不确定的。同时，使用动态 trait 对象也需要考虑额外的性能开销和运行时类型检查的安全性。

#### 集合

集合（Collection）是数据结构中最普遍的数据存放形式

##### vector

```rust
let mut vector: Vec<i32> = Vec::new(); // 创建类型为 i32 的空向量
let mut vector = vec![1, 2, 4, 8];     // 通过数组创建向量
vector.push(16);
vector.push(32);
println!("{:?}", vector);
```

append 方法用于将一个向量拼接到另一个向量的尾部

```rust
fn main() {
    let mut v1: Vec<i32> = vec![1, 2, 4, 8];
    let mut v2: Vec<i32> = vec![16, 32, 64];
    v1.append(&mut v2);
    println!("{:?}", v1);
}
```

get 取值：

```rust
fn main() {
    let mut v = vec![1, 2, 4, 8];
    println!("{}", match v.get(0) {
        Some(value) => value.to_string(),
        None => "None".to_string()
    });
}
```

因为向量的长度无法从逻辑上推断，get 方法无法保证一定取到值，所以 get 方法的返回值是 Option 枚举类，有可能为空。

这是一种安全的取值方法，但是书写起来有些麻烦。如果能够保证取值的下标不会超出向量下标取值范围，也可以使用数组取值语法：

```rust
println!("{}", v[1]);
```

```rust
fn main() {
    let v = vec![100, 32, 57];
    for i in &v {
        println!("{}", i);
    }
}
```

```rust
fn main() {
    let mut v = vec![100, 32, 57];
    for i in &mut v {
        *i += 50;
    }
}
```

> 复制和排序：
>
> ```rust
> let li = l[i] as usize; //强转 vec<i32> 的某个元素
> let ri = r[i] as usize;
> let mut a = nums[li..=ri].to_vec();
> a.sort();
> ```
>
> 二分搜索 (lower_bound)
>
> ```rust
> fn bsearch(v: &Vec<i32>, x: i32) -> usize {
>     v.partition_point(|&y| y < x)
> }
> fn main() {
>     //           0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
>     let v = vec![1, 1, 1, 2, 2, 2, 2, 3, 5, 8, 8];
>     println!("{}", bsearch(&v, 1));
> }
> ```

##### map

```rust
use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();

    map.insert("color", "red");
    map.insert("size", "10 m^2");

    println!("{}", map.get("color").unwrap());
    for p in map.iter() {
        println!("{:?}", p);
    }
}
```

这里没有声明散列表的泛型，是因为 Rust 的自动判断类型机制。

使用 insert 方法添加新的键值对的时候，如果已经存在相同的键，会直接覆盖对应的值。如果想"安全地插入"，就是在确认当前不存在某个键时才执行的插入动作，可以这样

```rust
map.entry("color").or_insert("red");
```

已经确定有某个键的情况下如果想直接修改对应的值，有更快的办法：

```rust
use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();
    map.insert(1, "a");
   
    if let Some(x) = map.get_mut(&1) {
        *x = "b";
    }
}
```

#### 全局变量

```rust
/*维护全局变量的单例模式 */
use lazy_static::lazy_static;
use std::sync::Mutex;
lazy_static! { //懒汉模式
    pub static ref GLOBAL: Mutex<Global> = Mutex::new(Global::new());
}
use std::collections::HashMap;
use crate::auth_node::AuthNode;
type AuthMap = HashMap<usize, AuthNode>;
pub struct Global {
    pub authmap: AuthMap,
}
impl Global {
    fn new() -> Global {
        Global {
            authmap: HashMap::new(),
        }
    }
}
```

```rust
let mut global = crate::resource::GLOBAL.lock().unwrap();
global.authmap.insert(node.id, node);
```

或者安全一点：

```rust
let mut global = match crate::resource::GLOBAL.lock() {
    Ok(guard) => guard,
    Err(poisoned) => poisoned.into_inner(),
};
```



### I/O

#### 标准

##### 输出

`!` 代表宏规则，而不是函数。有 `println!` 和 `print!`。前者自动换行。

可以格式化。基本规则是 `{}` 占位。一个占位符可以占多个位，要标号。

```rust
let x = 1;
println!("x={}", x);
let y = "哈哈";
println!("x={},y={}", x, y);
println!("{0}+{0}={1}", x, x + x);
```

输出普通的 `{}`，则写 `{{}}`。

```rust
println!("{{}} is brace.");
```

##### 输入

简单的输入：(会包含换行，只能读一行内含空格的全部内容)

```rust
use std::io::stdin;

fn main() {
	let mut str_buf = String::new();
    stdin().read_line(&mut str_buf)
        .expect("Failed to read line.");
    println!("Your input line is \n{}", str_buf);
}
```

目前 Rust 标准库还没有提供直接从命令行读取数字或格式化数据的方法，我们可以读取一行字符串并使用字符串识别函数处理数据

#### 文件

##### 读

```rust
use std::fs;

fn main() {
    let text = fs::read_to_string("D:\\text.txt").unwrap();
    println!("{}", text);
}
```

但如果要读取的文件是二进制文件，我们可以用 std::fs::read 函数读取 u8 类型集合：

```rust
use std::fs;

fn main() {
    let content = fs::read("D:\\text.txt").unwrap();
    println!("{:?}", content);
}
```

一次读五个：

```rust
use std::io::prelude::*;
use std::fs;

fn main() {
    let mut buffer = [0u8; 5];
    let mut file = fs::File::open("D:\\text.txt").unwrap();
    file.read(&mut buffer).unwrap();
    println!("{:?}", buffer);
    file.read(&mut buffer).unwrap();
    println!("{:?}", buffer);
}
```

##### 写

一次性覆盖写入，不存在就新建：

```rust
use std::fs;

fn main() {
    fs::write("D:\\text.txt", "FROM RUST PROGRAM")
        .unwrap();
}
```

流方式写入，与上面等价：

```rust
use std::io::prelude::*;
use std::fs::File;

fn main() {
    let mut file = File::create("D:\\text.txt").unwrap();
    file.write(b"FROM RUST PROGRAM").unwrap();
}
```

打开的文件一定存放在可变的变量中才能使用 File 的方法

追加：

```rust
use std::io::prelude::*;
use std::fs::OpenOptions;

fn main() -> std::io::Result<()> {
   
    let mut file = OpenOptions::new()
            .append(true).open("D:\\text.txt")?;

    file.write(b" APPEND WORD")?;

    Ok(())
}
```

OpenOptions 是一个灵活的打开文件的方法，它可以设置打开权限，除append 权限以外还有 read 权限和 write 权限，如果我们想以读写权限打开一个文件可以这样写：

```rust
use std::io::prelude::*;
use std::fs::OpenOptions;

fn main() -> std::io::Result<()> {
   
    let mut file = OpenOptions::new()
            .read(true).write(true).open("D:\\text.txt")?;

    file.write(b"COVER")?;

    Ok(())
}
```



### 流程控制

#### 条件

##### if

不需要用小括号。 if 不存在单语句不用加 {} 的规则，不允许使用一个语句代替一个块。

```rust
fn main() {
    let number = 3;
    if number < 5 {
        println!("条件为 true");
    } else if number < 100 {
        println!("条件为 dsds");
    } else {
        println!("条件为 false");
    }
}
```

Rust 中的条件表达式必须是 bool 类型，跟 java 类似。

可以用 if else 三元表达式。

```rust
fn main() {
    let a = 3;
    let number = if a > 0 { 1 } else { -1 };
    println!("number 为 {}", number);
}
```

两个函数体表达式的类型必须一样，且必须有一个 else 及其后的表达式块。

```rust
fn sgn(a: i32) -> i32 {
    if a > 0 {1} else {if a<0 {-1} else {0} }
}
```

##### match

match 对整数、浮点数、字符和字符串切片引用（&str）类型的数据进行分支选择。其中，浮点数类型被分支选择虽然合法，但不推荐这样使用，因为精度问题可能会导致分支错误。

对非枚举类进行分支选择时必须注意处理例外情况，即使在例外情况下没有任何要做的事 **.** 例外情况用下划线 **_** 表示：

```rust
fn main() {
    let t = "abc";
    match t {
        "abc" => println!("Yes"),
        _ => {},
    }
}
```

##### if let

```rust
let i = 0;
match i {
    0 => println!("zero"),
    _ => {},
}
```

等价于：

```rust
let i = 0;
if let 0 = i {
    println!("zero");
} //可以在之后添加一个 else 块来处理例外情况。
```

if let 语法可以认为是只区分两种情况的 match 语句的"语法糖"（语法糖指的是某种语法的原理相同的便捷替代品）。

```rust
fn main() {
    enum Book {
        Papery(u32),
        Electronic(String)
    }
    let book = Book::Electronic(String::from("url"));
    if let Book::Papery(index) = book {
        println!("Papery {}", index);
    } else {
        println!("Not papery book");
    }
}
```



#### 循环

##### while

```rust
fn main() {
    let mut number = 1;
    while number != 4 {
        println!("{}", number);
        number += 1;
    }
    println!("EXIT");
}
```

没有 do while，没有 C 风格 for，有 python 风格 for。

```rust
fn main() {
    let a = [10, 20, 30, 40, 50];
    for i in a.iter() {
        println!("值为 : {}", i);
    }
}
```

遍历 `[0..5)`：

```rust
fn main() {
let a = [10, 20, 30, 40, 50];
    for i in 0..5 { //注意 0..5 不是数组,类型不等于a的类型
        //[0,5] 就 0..=5
        println!("a[{}] = {}", i, a[i]);
    }
}
```

> 逆序：`for i in (1..=10).rev() {`

##### loop

无限循环结构 loop：

```rust
fn main() {
    let s = ['A', 'U', 'R', 'O', 'R', 'A'];
    let mut i = 0;
    loop {
        let ch = s[i];
        if ch == 'O' {
            break;
        }
        println!("\'{}\'", ch);
        i += 1;
    }
}
```

loop 循环可以通过 break 关键字类似于 return 一样使整个循环退出并给予外部一个返回值

```rust
fn main() {
    let s = ['A', 'U', 'R', 'O', 'R', 'A'];
    let mut i = 0;
    let location = loop {
        let ch = s[i];
        if ch == 'O' {
            break i;
        }
        i += 1;
    };
    println!(" \'O\' 的索引为 {}", location);
}
```



#### 错误处理

程序中一般会出现两种错误：可恢复错误(如文件访问错误，有可能是被占用，等待即可)和不可恢复错误(越界)。

Rust 中没有 Exception。

对于可恢复错误用 Result<T, E> 类来处理，对于不可恢复错误使用 panic! 宏来处理。

```rust
fn main() {
    panic!("error occured"); //类似raise
    println!("Hello, Rust");
}
```

回溯是不可恢复错误的另一种处理方式，它会展开运行的栈并输出所有的信息，然后程序依然会退出。我们可以找到我们编写的 panic! 宏触发的错误。

可恢复错误概念十分类似于 Java 编程语言中的异常。实际上在 C 语言中我们就常常将函数返回值设置成整数来表达函数遇到的错误，在 Rust 中通过 Result<T, E> 枚举类作返回值来进行异常表达：

```rust
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

在 Rust 标准库中可能产生异常的函数的返回值都是 Result 类型的。例如：当我们尝试打开一个文件时：

```rust
use std::fs::File;

fn main() {
    let f = File::open("hello.txt");
    match f {
        Ok(file) => {
            println!("File opened successfully.");
        },
        Err(err) => {
            println!("Failed to open the file.");
        }
    }
}
```

或：

```rust
use std::fs::File;

fn main() {
    let f = File::open("hello.txt");
    if let Ok(file) = f {
        println!("File opened successfully.");
    } else {
        println!("Failed to open the file.");
    }
}
```

如果想使一个可恢复错误按不可恢复错误处理，Result 类提供了两个办法：unwrap() 和 expect(message: &str) ：

```rust
use std::fs::File;

fn main() {
    let f1 = File::open("hello.txt").unwrap();
    let f2 = File::open("hello.txt").expect("Failed to open.");
}
```

两者的区别在于 expect 能够向 panic! 宏发送一段指定的错误信息。

可恢复错误传递：

```rust
fn f(i: i32) -> Result<i32, bool> {
    if i >= 0 { Ok(i) }
    else { Err(false) }
}

fn main() {
    let r = f(10000);
    if let Ok(v) = r {
        println!("Ok: f(-1) = {}", v); //ok
    } else {
        println!("Err");
    }
}
```

```rust
fn g(i: i32) -> Result<i32, bool> {
    let t = f(i);
    return match t {
        Ok(i) => Ok(i),
        Err(b) => Err(b)
    };
}
```



```rust
fn f(i: i32) -> Result<i32, bool> {
    if i >= 0 { Ok(i) }
    else { Err(false) }
}

fn g(i: i32) -> Result<i32, bool> {
    let t = f(i)?;
    Ok(t) // 因为确定 t 不是 Err, t 在这里已经是 i32 类型
}

fn main() {
    let r = g(10000);
    if let Ok(v) = r {
        println!("Ok: g(10000) = {}", v); //ok
    } else {
        println!("Err");
    }
}
```

**?** 符的实际作用是将 Result 类非异常的值直接取出，如果有异常就将异常 Result 返回出去，否则往下执行。所以，? 符仅用于返回值类型为 Result<T, E> 的函数，其中 E 类型必须和 ? 所处理的 Result 的 E 类型一致。

```rust
fn judge(i: i32) -> Result<i32, bool> {
    if i % 2 == 0 {
        Ok(i)
    } else {
        Err(false)
    }
}
fn g(i: i32) -> Result<i32, bool> {
    println!("running with {}", i);
    let t = judge(i)?;
    println!("Okay {}", t);
    Ok(t)
}
fn afters(r: Result<i32, bool>) {
    if let Ok(v) = r {
        println!("Good: {}", v);
    } else {
        println!("Bad");
    }
}
fn wt() {
    let r1 = g(1);
    let r2 = g(2);
    afters(r1);
    afters(r2);
}
```

到此为止，Rust 似乎没有像 try 块一样可以令任何位置发生的同类异常都直接得到相同的解决的语法，但这样并不意味着 Rust 实现不了：我们完全可以把 try 块在独立的函数中实现，将所有的异常都传递出去解决。实际上这才是一个分化良好的程序应当遵循的编程方法：应该注重独立功能的完整性。

但是这样需要判断 Result 的 Err 类型，获取 Err 类型的函数是 kind()。

```rust
use std::io;
use std::io::Read;
use std::fs::File;

fn read_text_from_file(path: &str) -> Result<String, io::Error> {
    let mut f = File::open(path)?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

fn main() {
    let str_file = read_text_from_file("hello.txt");
    match str_file {
        Ok(s) => println!("{}", s),
        Err(e) => {
            match e.kind() {
                io::ErrorKind::NotFound => {
                    println!("No such file");
                },
                _ => {
                    println!("Cannot read the file");
                }
            }
        }
    }
}
```





### 函数

#### 基本

函数语法：

```rust
fn <函数名> ( <参数> ) <函数体>
```

Rust 函数名称的命名风格是小写字母以下划线分割。 Rust不在乎在何处定义函数，只需在某个地方定义它们即可。

```rust
fn main() { //等效于fn main() -> () {
    println!("Hello, world!");
    another_function();
}

fn another_function() {
    println!("Hello, runoob!");
}
```

参数必须定义类型，返回值也必须定义，除非void(即空元组)。Rust 不支持自动返回值类型判断，果没有明确声明函数返回值的类型，函数将被认为是"纯过程"，不允许产生返回值，return 后面不能有返回值表达式。这样做的目的是为了让公开的函数能够形成可见的公报。

```rust
fn add(a: i32, b: i32) -> i32 {
    return a + b;
}
```

> 可简写为：
>
> ```rust
> fn add(a: i32, b: i32) -> i32 {
>     a + b
> }
> ```

数组参数：

```rust
fn nxx() {
    let w = [1, 2, 3];
    //println!("{}", w.len());
    println!("{:?}", psum(&w));
}
fn psum(a: &[i32]) -> i32 {
    let mut sum = 0;
    for i in a {
        sum += (*i) * (*i);
    }
    sum
}
```

内嵌函数：

```rust
fn main() {
    fn five() -> i32 {
        5
    }
    println!("five() 的值为: {}", five());
}
```

函数体表达式并不能等同于函数体，它不能使用 return 关键字。

#### 主函数

main 函数是主函数。主函数是个无参函数，环境参数需要开发者通过 std::env 模块取出

```rust
fn main() {
    let args = std::env::args();
    println!("{:?}", args);
}
```

如：

```rust
Args { inner: ["D:\\_lr580\\program\\C\\normal6\\hellworld3.exe"] }
```

Args 结构体中有一个 inner 数组，只包含唯一的字符串，代表了当前运行的程序所在的位置。

如果执行：

```sh
.\hellworld3.exe a b c
```

输出：

```rust
Args { inner: ["D:\\_lr580\\program\\C\\normal6\\hellworld3.exe", "a", "b", "c"] }
```

#### 闭包

闭包是可以保存进变量或作为参数传递给其他函数的匿名函数。闭包相当于 Rust 中的 Lambda 表达式，格式如下：

```rust
|参数1, 参数2, ...| -> 返回值类型 {
    // 函数体
}
```

```rust
fn main() {
    let inc = |num: i32| -> i32 {
        num + 1
    };
    println!("inc(5) = {}", inc(5));
}
```

闭包可以省略类型声明使用 Rust 自动类型判断机制：

```rust
fn main() {
    let inc = |num| {
        num + 1
    };
    println!("inc(5) = {}", inc(5));
}
```

闭包默认是借用，如果要拥有加 move：

```rust
#[test]
fn test() {
    let name = "白茶".to_string();
    let greeting = || {
        println!("Fuck {}", name); //调用外部变量
    };
    greeting();
    println!("Fuck {} again", name);
}
```

```rust
fn main() {
    let name = String::from("Alice");
    let greeting = move || {
        println!("Hello, {}!", name);
    };
    greeting(); // 输出 "Hello, Alice!"
    //println!("{}", name); // 编译时错误，因为 name 的所有权已经被移动
}
```

异步：

```rust
|| async {}
```



### 组织管理

对于一个工程来讲，组织代码是十分重要的。

Rust 中有三个重要的组织概念：箱、包、模块。

#### 箱

crate

"箱"是二进制程序文件或者库文件，存在于"包"中。

"箱"是树状结构的，它的树根是编译器开始运行时编译的源文件所编译的程序。

注意："二进制程序文件"不一定是"二进制可执行文件"，只能确定是是包含目标机器语言的文件，文件格式随编译环境的不同而不同。

#### 包

package

当我们使用 Cargo 执行 new 命令创建 Rust 工程时，工程目录下会建立一个 Cargo.toml 文件。工程的实质就是一个包，包必须由一个 Cargo.toml 文件来管理，该文件描述了包的基本信息以及依赖项。

一个包最多包含一个库"箱"，可以包含任意数量的二进制"箱"，但是至少包含一个"箱"（不管是库还是二进制"箱"）。

当使用 cargo new 命令创建完包之后，src 目录下会生成一个 main.rs 源文件，Cargo 默认这个文件为二进制箱的根，编译之后的二进制箱将与包名相同。

#### 模块

module

对于一个软件工程来说，我们往往按照所使用的编程语言的组织规范来进行组织，组织模块的主要结构往往是树。Java 组织功能模块的主要单位是类，而 JavaScript 组织模块的主要方式是 function。

这些先进的语言的组织单位可以层层包含，就像文件系统的目录结构一样。Rust 中的组织单位是模块（Module）。

```rust
mod nation {
    mod government {
        fn govern() {}
    }
    mod congress {
        fn legislate() {}
    }
    mod court {
        fn judicial() {}
    }
}
```

Rust 中的路径分隔符是 **::** 。

路径分为绝对路径和相对路径。绝对路径从 crate 关键字开始描述。相对路径从 self 或 super 关键字或一个标识符开始描述。例如：

```rust
crate::nation::government::govern(); //绝对 
nation::government::govern(); //相对
```

每一个 Rust 文件的内容都是一个"难以发现"的模块。

```rust
// main.rs
mod second_module;

fn main() {
    println!("This is the main module.");
    println!("{}", second_module::message());
}
```

```rust
// second_module.rs
pub fn message() -> String {
    String::from("This is the 2nd module.")
}
```

结果：

```
This is the main module.
This is the 2nd module.
```



#### 访问权限

默认情况下，如果不加修饰符，模块中的成员访问权将是私有的。

如果想使用公共权限，需要使用 pub 关键字。

对于私有的模块，只有在与其平级的位置或下级的位置才能访问，不能从其外部访问。

```rust
mod nation {
    pub mod government {
        pub fn govern() {}
    }

    mod congress {
        pub fn legislate() {}
    }
   
    mod court {
        fn judicial() {
            super::congress::legislate();
        }
    }
}

fn main() {
    nation::government::govern();
}
```

如果模块中定义了结构体，结构体除了其本身是私有的以外，其字段也默认是私有的。所以如果想使用模块中的结构体以及其字段，需要 pub 声明

```rust
mod back_of_house {
    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}
pub fn eat_at_restaurant() {
    let mut meal = back_of_house::Breakfast::summer("Rye");
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);
}
fn main() {
    eat_at_restaurant()
}
```

枚举类枚举项可以内含字段，但不具备类似的性质:

```rust
mod SomeModule {
    pub enum Person {
        King {
            name: String
        },
        Quene
    }
}

fn main() {
    let person = SomeModule::Person::King{
        name: String::from("Blue")
    };
    match person {
        SomeModule::Person::King {name} => {
            println!("{}", name); //blue
        }
        _ => {}
    }
}
```

#### use

use 关键字能够将模块标识符引入当前作用域，解决了局部模块路径过长的问题。：

```rust
mod nation {
    pub mod government {
        pub fn govern() {}
    }
}

use crate::nation::government::govern;

fn main() {
    govern();
}
```

存在两个相同的名称，且同样需要导入，我们可以使用 as 关键字为标识符添加别名：

```rust
mod nation {
    pub mod government {
        pub fn govern() {}
    }
    pub fn govern() {}
}
   
use crate::nation::government::govern;
use crate::nation::govern as nation_govern;

fn main() {
    nation_govern();
    govern();
}
```

use 关键字可以与 pub 关键字配合使用：

```rust
mod nation {
    pub mod government {
        pub fn govern() {}
    }
    pub use government::govern;
}

fn main() {
    nation::govern();
}
```

导入多个：

```rust
use std::thread::{sleep, spawn};
```



#### 标准库

[Rust 官方标准库字典](https://doc.rust-lang.org/stable/std/all.html)

```rust
use std::f64::consts::PI;

fn main() {
    println!("{}", (PI / 2.0).sin());
}
```

所有的系统库模块都是被默认导入的，所以在使用的时候只需要使用 use 关键字简化路径就可以方便的使用了。

#### 对象

面向对象的编程语言通常实现了数据的封装与继承并能基于数据调用方法。

Rust 不是面向对象的编程语言，但这些功能都得以实现

封装就是对外显示的策略，在 Rust 中可以通过模块的机制来实现最外层的封装，并且每一个 Rust 文件都可以看作一个模块，模块内的元素可以通过 pub 关键字对外明示。这一点在"组织管理"章节详细叙述过。

"类"往往是面向对象的编程语言中常用到的概念。"类"封装的是数据，是对同一类数据实体以及其处理方法的抽象。在 Rust 中，我们可以使用结构体或枚举类来实现类的功能：

```rust
pub struct ClassName {
    pub field: Type,
}

pub impl ClassName {
    fn some_method(&self) {
        // 方法函数体
    }
}

pub enum EnumName {
    A,
    B,
}

pub impl EnumName {
    fn some_method(&self) {

    }
}
```

```rust
//second.rs
pub struct ClassName {
    field: i32,
}

impl ClassName {
    pub fn new(value: i32) -> ClassName {
        ClassName {
            field: value
        }
    }

    pub fn public_method(&self) {
        println!("from public method");
        self.private_method();
    }

    fn private_method(&self) {
        println!("from private method");
    }
}
//main.rs
mod second;
use second::ClassName;

fn main() {
    let object = ClassName::new(1024);
    object.public_method();
}
```

几乎其他的面向对象的编程语言都可以实现"继承"，并用"extend"词语来描述这个动作。

继承是多态（Polymorphism）思想的实现，多态指的是编程语言可以处理多种类型数据的代码。在 Rust 中，通过特性（trait）实现多态。有关特性的细节已在"特性"章节给出。但是特性无法实现属性的继承，只能实现类似于"接口"的功能，所以想继承一个类的方法最好在"子类"中定义"父类"的实例。

总结地说，Rust 没有提供跟继承有关的语法糖，也没有官方的继承手段（完全等同于 Java 中的类的继承），但灵活的语法依然可以实现相关的功能。

### 并发

#### 线程

##### 创建

```rust
use std::thread;
use std::time::Duration;

fn spawn_function() {
    for i in 0..5 {
        println!("spawned thread print {}", i);
        thread::sleep(Duration::from_millis(1));
    }//注意，main跑完会马上杀死这个进程，所以不会输出完
}

fn main() {
    thread::spawn(spawn_function);

    for i in 0..3 {
        println!("main thread print {}", i);
        thread::sleep(Duration::from_millis(1));
    }
}
```

闭包写法：

```rust
use std::thread;
use std::time::Duration;

fn main() {
    thread::spawn(|| {
        for i in 0..5 {
            println!("spawned thread print {}", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    for i in 0..3 {
        println!("main thread print {}", i);
        thread::sleep(Duration::from_millis(1));
    }
}
```

##### join

join 方法可以使子线程运行结束后再停止运行程序。

```rust
use std::thread;
use std::time::Duration;

fn main() {
    let handle = thread::spawn(|| {
        for i in 0..5 {
            println!("spawned thread print {}", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    for i in 0..3 {
        println!("main thread print {}", i);
        thread::sleep(Duration::from_millis(1));
    }

    handle.join().unwrap(); //就是阻塞的意思,直到做完了这一行完毕
    println!("Done");
}//不会像上面一样子进程没跑完就挂了
```

##### move

```rust
use std::thread;

fn main() {
    let s = "hello";
    let handle = thread::spawn(|| {
        println!("{}", s);
    });
    handle.join().unwrap();
}
```

在子线程中尝试使用当前函数的资源，这一定是错误的！因为所有权机制禁止这种危险情况的产生，它将破坏所有权机制销毁资源的一定性。我们可以使用闭包的 move 关键字来处理：

```rust
use std::thread;
fn main() {
    let s = "hello";
    let handle = thread::spawn(move || {
        println!("{}", s);
    });
    handle.join().unwrap();
}
```

##### 消息传递

Rust 中一个实现消息传递并发的主要工具是通道（channel），通道有两部分组成，一个发送者（transmitter）和一个接收者（receiver）。

std::sync::mpsc 包含了消息传递的方法：

```rust
use std::thread;
use std::sync::mpsc;

fn main() {
    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let val = String::from("hi");
        tx.send(val).unwrap();
    });

    let received = rx.recv().unwrap();
    println!("Got: {}", received);
}
```

子线程获得了主线程的发送者 tx，并调用了它的 send 方法发送了一个字符串，然后主线程就通过对应的接收者 rx 接收到了。



#### 异步

##### async

[参考](https://blog.csdn.net/shebao3333/article/details/106851398/)

> 首先看一个交替显示信息的多线程程序：
>
> ```rust
> use std::thread::{sleep, spawn};
> use std::time::Duration;
> 
> fn sleepus() {
>     for i in 1..=10 {
>         println!("Sleepus {}", i);
>         sleep(Duration::from_millis(500));
>     }
> }
> 
> fn interruptus() {
>     for i in 1..=5 {
>         println!("Interruptus {}", i);
>         sleep(Duration::from_millis(1000));
>     }
> }
> 
> fn main() {
>     let sleepus = spawn(sleepus);
>     let interruptus = spawn(interruptus);
>     sleepus.join().unwrap();
>     interruptus.join().unwrap();
> }
> ```
>
> 或者：
>
> ```rust
> fn main() {
>     let sleepus = spawn(sleepus); //副走这个
>     interruptus(); //主线走这个
>     sleepus.join().unwrap();
> }
> ```

`cargo.toml` 添加依赖：

```ini
async-std = { version = "1.2.0", features = ["attributes"] }
```

该依赖可以让主函数可以 async。

需要在 cargo 里，点击 run 运行项目，而不是 ctrl+alt+n，才可以。

与上面等效的一个异步函数是：

```rust
use async_std::task::{sleep, spawn};
use std::time::Duration;

async fn sleepus() {
    for i in 1..=10 {
        println!("Sleepus {}", i);
        sleep(Duration::from_millis(500)).await;
    }
}

async fn interruptus() {
    for i in 1..=5 {
        println!("Interruptus {}", i);
        sleep(Duration::from_millis(1000)).await;
    }
}

#[async_std::main]
async fn main() {
    let sleepus = spawn(sleepus());
    interruptus().await;

    sleepus.await;
}
```

在函数定义前添加async主要做了以下3个事：

- 这将允许在函数体内使用.await语法
- 它修改了函数的返回类型。async fn foo() -> Bar 实际上返回的是 `impl std::future::Future<Output=Bar>`
- 它自动将结果值封装进一个新的Future对象

> 在Rust的标准库中有一个名为Future的trait，Future有一个关联类型Output。这个trait的意思是：我承诺当我完成任务时，会给你一个类型为Output的值。例如你可以想象一个异步HTTP客户端可能会这样实现：

> ```rust
> impl HttpRequest {
>     fn perform(self) -> impl Future<Output=HttpResponse> { ... }
> }
> ```

也就是说 async sleepus 等价于：

```rust
fn sleepus() -> impl std::future::Future<Output=()> {
    async {
        for i in 1..=10 {
            println!("Sleepus {}", i);
            sleep(Duration::from_millis(500)).await;
        }
    }
}
```

对 sleep 的 `.await`，如果删了，就起不到 sleep 的作用，即马上输出 10 次。因此，该 sleep 生成的是一个 Future。

将 async 删掉，改写为：

```rust
fn sleepus() -> impl std::future::Future<Output=()> {
    for i in 1..=10 {
        println!("Sleepus {}", i);
        sleep(Duration::from_millis(500));
    }
    async_std::future::ready(())
}
```

将 std 改写为自己的：

```rust
use std::pin::Pin;
use std::task::{Context, Poll};

impl Future for DoNothing {
    type Output = ();

    fn poll(self: Pin<&mut Self>, ctx: &mut Context) -> Poll<Self::Output> {
        unimplemented!()//编译器不报错，运行报错
    }
}
//将unimplemented!()改成Poll::Ready(())
```

简化 sleepus 的定义：

```rust
fn sleepus() -> impl Future<Output=()> {
    DoNothing
}
```

修改为：

```rust
async fn sleepus() {
    DoNothing.await
}
```

因此，await 的本质是，从 donoting 里提取 output 的值。

## 第三方库

### 基础

#### 异步

```rust
[dependencies]
futures = "0.3"
tokio = { version = "1.16.1", features = ["full"] }
```

主函数是异步函数时，需要如下：

```rust
#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    //xxx.await?;
    Ok(())
}
```

同理，对测试，有：

```rust
#[tokio::test]
```



### 网络

#### reqwest

```ini
[dependencies]
reqwest = { version = "0.11", features = ["blocking", "json"] }
```

这里启用了 `blocking` 和 `json` 功能，前者表示使用同步的 HTTP 请求方式，后者表示使用 JSON 解析功能。

##### get

一个简单的例子：

```rust
use reqwest::blocking::get;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // 目标 URL
    let url = "http://httpbin.org/get";//可以自己试试访问
    // 发送 GET 请求
    let response = get(url)?;
    // 获取响应内容
    let body = response.text()?;
    println!("{}", body);
    Ok(())
}

```

##### post

(向下文的 `actix-基本` 服务器发送)：



#### actix

web 服务框架。

[参考](https://blog.csdn.net/weixin_37957321/article/details/126633315) [官方文档](https://actix.rs/docs/)

```properties
[dependencies]
actix-web = "4"
```





##### 基本

一个监听 get 和 post，使用两种方法定义路由的服务器：

将其放在 `test/test01.rs`

```rust
use actix_web::{get, post, web, App, HttpResponse, HttpServer, Responder};

#[get("/")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello world!")
}

#[post("/echo")]
async fn echo(req_body: String) -> impl Responder {
    HttpResponse::Ok().body(req_body)
}

async fn manual_hello() -> impl Responder {
    HttpResponse::Ok().body("Hey there!")
}

//#[actix_web::main]
#[actix_web::test]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(hello)
            .service(echo)
            .route("/hey", web::get().to(manual_hello))
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
```

对 get 请求，可以直接用 http 浏览器检测 `http://127.0.0.1:8080/`。

> 也可以用 python 测试：
>
> ```python
> import requests
> response=requests.get('http://127.0.0.1:8080/')
> print(response.status_code) #200
> print(response.text) #'Hello world!'
> response=requests.post('http://127.0.0.1:8080/echo',data="oops")
> print(response.text) #'oops' ,status code同上
> ```

主函数里：

```rust
mod test {
    pub mod test01;
}
fn main() {
    println!("Hello, world!");
}
```

`pub mod test01;` 会冒出一个 `run tests`，点击后(也可以在上述 main 上方点，但必须先pub)，http 浏览器访问即可。

> 如果 `error: linking with link.exe failed: exit code: 1104`，证明启动着 test，先关掉跑着的 test。



##### 服务器状态

服务器信息存储。

```rust
use actix_web::{get, web, App, HttpServer};

// This struct represents state
struct AppState {
    app_name: String,
}

#[get("/")]
async fn index(data: web::Data<AppState>) -> String {
    let app_name = &data.app_name; // <- get app_name
    format!("Hello {app_name}!") // <- response with app_name
}
#[actix_web::test]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .app_data(web::Data::new(AppState {
                app_name: String::from("Actix Web"),
            }))
            .service(index)
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
```

> ```python
> requests.get('http://127.0.0.1:8080/').text
> ```

[这里](https://actix.rs/docs/extractors) 的底部有其他写法。

##### 路由

```rust
use actix_web::{get, web, App, HttpServer};
#[get("/show")]
async fn show_users() -> String {
    "Fuck, there's no user at all.".to_string()
}
#[actix_web::test]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        let scope = web::scope("/users").service(show_users);
        App::new().service(scope)
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
```

> ```python
> requests.get('http://127.0.0.1:8080/users/show').text
> ```

##### guard

根据访问的 URL 的不同选择回答：

```rust
use actix_web::{web, App, HttpServer, HttpResponse, guard};
#[actix_web::test]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(
                web::scope("/")
                    .guard(guard::Host("127.0.0.1"))
                    .route("", web::to(|| async { HttpResponse::Ok().body("IP") })),
            )
            .service(
                web::scope("/")
                    .guard(guard::Host("localhost"))
                    .route("", web::to(|| async { HttpResponse::Ok().body("hostname") })),
            )
            .route("/", web::to(HttpResponse::Ok))
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
```

> ```python
> requests.get('http://127.0.0.1:8080/').text
> requests.get('http://localhost:8080/').text
> ```

##### configure

动态调整路由。

```rust
use actix_web::{web, App, HttpResponse, HttpServer};

// this function could be located in a different module
fn scoped_config(cfg: &mut web::ServiceConfig) {
    cfg.service(
        web::resource("/test")
            .route(web::get().to(|| async { HttpResponse::Ok().body("test") }))
            .route(web::head().to(HttpResponse::MethodNotAllowed)),
    );
}

// this function could be located in a different module
fn config(cfg: &mut web::ServiceConfig) {
    cfg.service(
        web::resource("/app")
            .route(web::get().to(|| async { HttpResponse::Ok().body("app") }))
            .route(web::head().to(HttpResponse::MethodNotAllowed)),
    );
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .configure(config)
            .service(web::scope("/api").configure(scoped_config))
            .route(
                "/",
                web::get().to(|| async { HttpResponse::Ok().body("/") }),
            )
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
```

> ```
> /         -> "/"
> /app      -> "app"
> /api/test -> "test"
> ```



##### server

同时启动 4 个 HTTP 服务器：

```rust
use actix_web::{web, App, HttpResponse, HttpServer};

#[actix_web::main]
async fn main() {
    HttpServer::new(|| App::new().route("/", web::get().to(HttpResponse::Ok))).workers(4);
    // <- Start 4 workers
}
```

```rust
async fn my_handler() -> impl Responder {
    tokio::time::sleep(Duration::from_secs(5)).await; // <-- Ok. Worker thread will handle other requests here
    "response"
}
```

如果要支持 HTTPS，先装个 openssl, windows 参考 [这里](https://www.cnblogs.com/telwanggs/p/16923020.html)，记得配 path。检验：

```sh
openssl version -a
```

在根目录下，在 powerful shell 下执行：

```sh
openssl req -x509 -newkey rsa:4096 -nodes -keyout key.pem -out cert.pem -days 365 -subj '/CN=localhost'
```

> 生成了一个自签名的 X.509 证书。具体而言，它做了以下几件事情：(GPT)
>
> 1. `-newkey rsa:4096`：生成一个 RSA 4096 位的密钥对。
> 2. `-nodes`：不加密私钥，这样生成的私钥文件就不需要输入密码才能使用。
> 3. `-keyout key.pem`：将生成的私钥保存到 key.pem 文件中。
> 4. `-out cert.pem`：将生成的证书保存到 cert.pem 文件中。
> 5. `-days 365`：指定证书的有效期为 365 天。
> 6. `-subj '/CN=localhost'`：指定证书的主题为 /CN=localhost，也就是证书的 common name 字段为 localhost。

无密码版本：

```sh
openssl rsa -in key.pem -out nopass.pem
```

> 从 `key.pem` 文件中读取一个加密的私钥，并将其写入到 `nopass.pem` 文件中，同时不再需要输入密码才能使用这个私钥。(GPT)

更新环境：(不行的话重启一下全部 vscode)

```properties
[dependencies]
actix-web = { version = "4", features = ["openssl"] }
openssl = { version = "0.10" }
```

参考 [这里](https://blog.csdn.net/weixin_47610359/article/details/128012583)，装 vcpkg，先 `git clone "https://github.com/microsoft/vcpkg"`，然后运行 `bootstrap-vcpkg.bat`，然后加 path，之后就好了。

power shell 跑：

```sh
vcpkg intergrate install
```

配全局变量，将 `OPENSSL_DIR` 设为 openssl 根目录。然后从浏览器搞 `https://127.0.0.1/` 尝试访问，开启下面的服务器：

```rust
use actix_web::{get, App, HttpRequest, HttpServer, Responder};
use openssl::ssl::{SslAcceptor, SslFiletype, SslMethod};

#[get("/")]
async fn index(_req: HttpRequest) -> impl Responder {
    "Welcome!"
}

#[actix_web::test]
async fn main() -> std::io::Result<()> {
    // load TLS keys
    // to create a self-signed temporary cert for testing:
    // `openssl req -x509 -newkey rsa:4096 -nodes -keyout key.pem -out cert.pem -days 365 -subj '/CN=localhost'`
    let mut builder = SslAcceptor::mozilla_intermediate(SslMethod::tls()).unwrap();
    builder
        .set_private_key_file("nopass.pem", SslFiletype::PEM)
        .unwrap();
    builder.set_certificate_chain_file("cert.pem").unwrap();

    HttpServer::new(|| App::new().service(index))
        .bind_openssl("127.0.0.1:8080", builder)?
        .run()
        .await
}
```

> ```python
> requests.get('https://127.0.0.1:8080',verify=False).text
> ```
>
> ```python
> #失败的
> response = requests.get('https://127.0.0.1:8080', cert=(r'D:\_lr580\program\trys\c4\testweb\cert.pem',r'D:\_lr580\program\trys\c4\testweb\nopass.pem'),verify=False)
> ```

如果要验证安全，可以查怎么把证书添加到自己的电脑。



##### 路径参数

```rust
use actix_web::{get, web, App, HttpServer, Result};

/// extract path info from "/users/{user_id}/{friend}" url
/// {user_id} - deserializes to a u32
/// {friend} - deserializes to a String
#[get("/users/{user_id}/{friend}")] // <- define path parameters
async fn index(path: web::Path<(u32, String)>) -> Result<String> {
    let (user_id, friend) = path.into_inner();
    Ok(format!("Welcome {}, user_id {}!", friend, user_id))
}

#[actix_web::test]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| App::new().service(index))
        .bind(("127.0.0.1", 8080))?
        .run()
        .await
}
```

> ```python
> requests.get('http://127.0.0.1:8080/users/1/friend2').text
> requests.get('http://127.0.0.1:8080/users/user1/friend2').status_code #404
> requests.get('http://127.0.0.1:8080/users/user1/friend2').text
> #'can not parse "user1" to a u32'
> ```

也可以用结构体：

```properties
serde = { version = "1.0", features = ["derive"] }
```

```rust
use actix_web::{get, web, Result};
use serde::Deserialize;

#[derive(Deserialize)]
struct Info {
    user_id: u32,
    friend: String,
}

/// extract path info using serde
#[get("/users/{user_id}/{friend}")] // <- define path parameters
async fn index(info: web::Path<Info>) -> Result<String> {
    Ok(format!(
        "Welcome {}, user_id {}!",
        info.friend, info.user_id
    ))
}

#[actix_web::test]
async fn main() -> std::io::Result<()> {
    use actix_web::{App, HttpServer};
    HttpServer::new(|| App::new().service(index))
        .bind(("127.0.0.1", 8080))?
        .run()
        .await
}
```

也可以这么搞：

```rust
use actix_web::{get, HttpRequest, Result};
#[get("/users/{user_id}/{friend}")] // <- define path parameters
async fn index(req: HttpRequest) -> Result<String> {
    let name: String = req.match_info().get("friend").unwrap().parse().unwrap();
    let userid: i32 = req.match_info().query("user_id").parse().unwrap();

    Ok(format!("Welcome {}, user_id {}!", name, userid))
}

#[actix_web::test]
async fn main() -> std::io::Result<()> {
    use actix_web::{App, HttpServer};

    HttpServer::new(|| App::new().service(index))
        .bind(("127.0.0.1", 8080))?
        .run()
        .await
}
```

##### 参数处理

```rust
use actix_web::{get, HttpRequest, Result};
#[get("/users/{user_id}/{friend}")] // <- define path parameters
async fn index(req: HttpRequest) -> Result<String> {
    let name: String = req.match_info().get("friend").unwrap().parse().unwrap();
    let userid: i32 = req.match_info().query("user_id").parse().unwrap();

    Ok(format!("Welcome {}, user_id {}!", name, userid))
}

use actix_web::{post, web};
use serde::Deserialize;

#[derive(Deserialize)]
struct Info {
    username: String,
}

// this handler gets called if the query deserializes into `Info` successfully
// otherwise a 400 Bad Request error response is returned
#[get("/")]
async fn index2(info: web::Query<Info>) -> String {
    format!("Welcome {}!", info.username)
}

/// deserialize `Info` from request's body
#[post("/submit")]
async fn submit(info: web::Json<Info>) -> Result<String> {
    Ok(format!("Welcome {}!", info.username))
}

#[actix_web::test]
async fn main() -> std::io::Result<()> {
    use actix_web::{App, HttpServer};

    HttpServer::new(|| App::new().service(index).service(index2).service(submit))
        .bind(("127.0.0.1", 8080))?
        .run()
        .await
}
```

> ```python
> import requests
> pam = {"username":"name1"}
> print(requests.get('http://127.0.0.1:8080/users/1/name').text)
> print(requests.get('http://127.0.0.1:8080/',params=pam).text)
> print(requests.post('http://127.0.0.1:8080/submit',json=pam).text)
> ```

表单数据处理：

```rust
#[derive(Deserialize)]
struct FormData {
    username: String,
}

/// extract form data using serde
/// this handler gets called only if the content type is *x-www-form-urlencoded*
/// and the content of the request could be deserialized to a `FormData` struct
#[post("/idx/")]
async fn index3(form: web::Form<FormData>) -> Result<String> {
    Ok(format!("Welcome {}!", form.username))
}
```

> ```python
> print(requests.post('http://127.0.0.1:8080/idx/',data=pam).text)#不是json=了
> ```





大小限制和自定义错误处理器：

> ```rust
> use actix_web::{error, web, App, HttpResponse, HttpServer, Responder};
> use serde::Deserialize;
> 
> #[derive(Deserialize)]
> struct Info {
>     username: String,
> }
> 
> /// deserialize `Info` from request's body, max payload size is 4kb
> async fn index(info: web::Json<Info>) -> impl Responder {
>     format!("Welcome {}!", info.username)
> }
> 
> #[actix_web::main]
> async fn main() -> std::io::Result<()> {
>     HttpServer::new(|| {
>         let json_config = web::JsonConfig::default()
>             .limit(4096)
>             .error_handler(|err, _req| {
>                 // create custom error response
>                 error::InternalError::from_response(err, HttpResponse::Conflict().finish())
>                     .into()
>             });
> 
>         App::new().service(
>             web::resource("/")
>                 // change json extractor configuration
>                 .app_data(json_config)
>                 .route(web::post().to(index)),
>         )
>     })
>     .bind(("127.0.0.1", 8080))?
>     .run()
>     .await
> }
> ```





### 数据库

#### mongodb

[官方文档](https://mongodb.github.io/mongo-rust-driver/manual/installation_features.html)

```properties
[dependencies]
futures = "0.3"
tokio = { version = "1.16.1", features = ["full"] }

[dependencies.mongodb]
version = "2.1.0"
default-features = false
features = ["async-std-runtime"]

[source.crates-io]
replace-with = 'sjtu'
[source.sjtu]
registry = "https://mirrors.sjtug.sjtu.edu.cn/git/crates.io-index.git"
```

一个简单的增删查例子：

```rust
mod mongo; //main.rs
#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    mongo::echo();
    mongo::test().await?;
    Ok(())
}
```

```rust
//rust.rs
pub fn echo() {
    println!("模块可用");
}
use mongodb::options::FindOptions;
use mongodb::{options::ClientOptions, Client};
use mongodb::{bson::{doc, Document}, Collection};
use futures::stream::TryStreamExt;

pub async fn get_conn() -> Result<Client, mongodb::error::Error> {
    let mut options = ClientOptions::parse("mongodb://localhost:27017").await?;
    options.app_name = Some("auth".to_string());
    let client = Client::with_options(options)?;
    Ok(client)
}
use std::error::Error;
pub async fn test() -> Result<(), Box<dyn Error>> {
    let client = get_conn().await?;
    let db = client.database("testmongo");
    let coll: Collection<Document> = db.collection("test");
    coll.delete_many(doc!{}, None).await?;
    let doc = doc! {"name":"Rust用","age":-1};
    coll.insert_one(doc, None).await?;
    let options = FindOptions::builder().build();
    let cursor = coll.find(None, options).await?;
    let mut cursor_stream = cursor.into_stream(); // 将 Cursor 转换为流
    while let Some(result) = cursor_stream.try_next().await? { // 使用 try_next 方法获取文档
        println!("{:#?}", result);
    }
    println!("Done testing");
    Ok(())
}
```

如果要传参数，可以考虑关键修改：

```rust
let mongo_url : String = ... ;
mongo::test(&mongo_url).await?;
pub async fn get_conn(url:&String) -> 
ClientOptions::parse(url).await?;
pub async fn test(url:&String) ->
get_conn(url).await?;
```



### 文件

#### 配置项读写

[官网](https://github.com/zonyitoo/rust-ini)

```ini
rust-ini = "0.18"
```

在根目录(即 `src/` 外)放测试文件 `config.ini`：

```ini
[database]
mongo_url=mongodb://localhost:27017
```

编写：`ini_plugin.rs` (如果写 `iniPlugin.rs` 会警告我命名不规范)

```rust
use ini::Ini;
pub fn get_property(file_path: &str, section: Option<&str>, key: &str) -> String {
    let conf = Ini::load_from_file(file_path).unwrap();
    let section = conf.section(section).unwrap();
    let value = section.get(key).unwrap();
    value.to_string()
}
```

主函数调用：

```rust
mod ini_plugin;
//...
let mongo_url = ini_plugin::get_property("config.ini", Some("database"), "mongo_url");
println!("{}", mongo_url);
```



#### json化

```properties
serde_json = "1.0"
bson = "2.6.1"
```

写一个自定义结构体序列化反序列化的例子：(`auth_node.rs`)

```rust
use bson::{doc, oid::ObjectId};
use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
struct AuthNode {
    _id: Option<ObjectId>,
    id: usize,
    father: usize,
    name: String,
}
impl AuthNode {
    pub fn new(id: usize, father: usize, name: String) -> Self {
        AuthNode {
            _id: None,
            id,
            father,
            name,
        }
    }
}

pub fn test() {
    let nd = AuthNode::new(1, 1, "root".to_string());
    println!("{:?}", nd);
    let doc = bson::ser::to_document(&nd).unwrap();
    println!("{:?}", doc);
    let nd2 : AuthNode = bson::from_document(doc).unwrap();
    println!("{:?}", nd2);
}
```

```rust
mod auth_node;
auth_node::test();
```



> 为对象通用化：
>
> ```rust
> use bson::{Document};
> use serde::{Deserialize, Serialize};
> 
> pub trait BsonConvert {
>     fn to_document(&self) -> Document;
>     fn from_document(doc: Document) -> Self
>     where Self: Sized + for<'de> Deserialize<'de>;
> }
> 
> /** 为所有将来实现该 trait 的结构体实现方法 */
> impl<T: Serialize + for<'de> Deserialize<'de> + 'static> BsonConvert for T {
>     fn to_document(&self) -> Document {
>         bson::to_document(self).unwrap()
>     }
> 
>     fn from_document(doc: Document) -> Self {
>         bson::from_document(doc).unwrap()
>     }
> }
> ```
>
> ```rust
> let mut nd = crate::auth_node::AuthNode::new(0, 0, "root".to_string());
> nd._id = Some(bson::oid::ObjectId::new());
> let doc = nd.to_document();
> ```
>
> 



## 例子

### 习题

#### 力扣

- 温度转换

  vec 基本运行

- 无矛盾的最佳球队

  结构体排序

- 等差子数组

  vec切片

- 强密码检测器

  OOP 字符串

- 字符流

  字符串 取模溢出 全局常量
  
- 删除最短的子数组使剩余数组有序

  二分搜索

- 全O(1)的数据结构

  vec套map, set, String复制
  
- 和相等的子数组

  map遍历
  
- 统计只差一个字符的子串数目

  map套set pair String 遍历 查询 type简写
  
- 最短公共超序列

  String str 子串 拼接
  
- 统计字典序元音字符串的数目

  二维数组
  
- 两点之间不包含任何点的最宽垂直区域

  二维数组 排序
  
- 两数之和

  hashmap if-let-some 类型转换 raise(panic)
  
- 算术三元组的数目

  数组max

- 两数相加

  Option Box 手写链表
  
- 隐藏个人信息

  字符串 拼接 遍历 数字检测 match
  
- 多边形三角剖分的最低得分

  函数内函数 递归 &mut参数 二维动态数组
  
- 交换一次的先前排列

  map-lowerbound 复制vec改为mut 逆序遍历 map元素覆盖 some
  
- 合并石头的最低成本

  数组

- 负二进制转换

  i64 字符串去前导0,拼接 常量str数组



##### 2469\.温度转换

[题目](https://leetcode.cn/problems/convert-the-temperature/)

我的代码：

```rust
impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        let mut ans: Vec<f64> = Vec::new();
        ans.push(celsius + 273.15);
        ans.push(celsius * 1.8 + 32.0);
        return ans;
    }
}
```

> 本地调试：
>
> ```rust
> mod sol{
>     pub struct Solution {}
>     impl Solution {
>         pub fn convert_temperature(celsius: f64) -> Vec<f64> {
>             let mut ans: Vec<f64> = Vec::new();
>             ans.push(celsius + 273.15);
>             ans.push(celsius * 1.8 + 32.0);
>             return ans;
>         }
>     }
> }
> fn main() {
>     let result = sol::Solution::convert_temperature(36.5);
>     println!("Kelvin: {}, Fahrenheit: {}", result[0], result[1]);
> }
> ```

更优：

```rust
impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        vec![celsius + 273.15, celsius * 1.80 + 32.00]
    }
}
```



##### 1626\.无矛盾的最佳球队

[题目](https://leetcode.cn/problems/best-team-with-no-conflicts/)

```rust
impl Solution {
    pub fn best_team_score(scores: Vec<i32>, ages: Vec<i32>) -> i32 {
        let n = scores.len(); //不能as i32,因为下文要开数组用
        let mut pr: Vec<(i32, i32)> = scores
        .iter()
        .zip(ages.iter())
        .map(|(&a, &b)| (a, b))//不能|&a, &b|
        .collect();
        use std::cmp::Ordering;
        pr.sort_by(|a, b| {
            let cmp = a.1.cmp(&b.1);//第二个i32为第一关键字升序
            if cmp == Ordering::Equal {
                a.0.cmp(&b.0)//第一个关键字升序
            } else {
                cmp
            }
        });
        let mut dp = vec![0; n];//初始全0
        let mut ans = 0;
        for i in 0..n {
            let mut mx = 0;
            for j in 0..i {
                if pr[j].0 <= pr[i].0 {
                    mx = mx.max(dp[j]);
                }
            }
            dp[i] = mx + pr[i].0;
            ans = ans.max(dp[i]);
        }
        ans
    }
}
```



##### 410\.分割数组的最大值

[题目](https://leetcode.cn/problems/split-array-largest-sum/)

```rust
mod lc410 {
    pub struct Solution {}
    impl Solution {
        pub fn split_array(nums: Vec<i32>, k: i32) -> i32 {
            //不unwrap的话是Option,即vec为空判断
            let mut lf = *nums.iter().max().unwrap();
            let mut rf = nums.iter().sum();
            let mut ans = std::i32::MAX;//max
            while lf <= rf {
                let cf = lf + (rf - lf) / 2;
                let mut cnt = 1;
                let mut sum = 0;
                for i in 0..nums.len() {
                    if sum + nums[i] > cf {
                        sum = nums[i];
                        cnt += 1;
                    } else {
                        sum += nums[i];
                    }
                }
                if cnt > k {
                    lf = cf + 1;
                } else {
                    ans = ans.min(cf);
                    rf = cf - 1;
                }
            }
            ans
        }
    }
}
fn main() {
    use lc410::Solution;
    println!("{}", Solution::split_array(vec![7, 2, 5, 10, 8], 2));
    println!("{}", Solution::split_array(vec![1, 2, 3, 4, 5], 2));
    println!("{}", Solution::split_array(vec![1, 4, 4], 3));
    println!("{}", Solution::split_array(vec![1, 2, 3, 4, 5], 1));
    println!("{}", Solution::split_array(vec![2, 3, 1, 1, 1, 1, 1], 5));
}
```



##### 1630\.等差子数组

[题目](https://leetcode.cn/problems/arithmetic-subarrays/)

```rust
impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let n = nums.len();
        let m = l.len();
        let mut ans = vec![false; m]; //not n
        for i in 0..m {
            let li = l[i] as usize; //强转
            let ri = r[i] as usize;
            let mut a = nums[li..=ri].to_vec();//切片返回迭代器转vec
            a.sort();
            let mut ok = true;
            let d = a[1] - a[0];
            for j in 2..a.len() {
                if a[j] - a[j - 1] != d {
                    ok = false;
                    break; //剪
                }
            }
            ans[i] = ok;
        }
        ans
    }
}
```



##### 420\.强密码检测器

[题目]()

```rust
mod lc420 {
    fn insert(str_slice: &str, idx: usize, ch: char) -> String {
        let mut new_str = String::with_capacity(str_slice.len() + 1);
        new_str.push_str(&str_slice[..idx]);
        new_str.push(ch);
        new_str.push_str(&str_slice[idx..]);
        new_str
    }
    fn get_index_ranges(input: &str) -> Vec<[usize; 2]> {
        let mut ranges = vec![];
        let mut start = 0;
        let mut end = 0;
        for (i, c) in input.char_indices() {
            if i > 0 && c != input.chars().nth(i - 1).unwrap() {
                ranges.push([start, end]);
                start = i;
            }
            end = i;
        }
        ranges.push([start, end]);
        ranges
    }
    fn remove(s: &str, index: usize) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        chars.remove(index);
        chars.iter().collect()
    }
    fn get_bin(v: &Vec<[usize; 2]>) -> [Vec<usize>; 6] {
        let mut arr: [Vec<usize>; 6] = Default::default();
        for i in 0..v.len() {
            let len = v[i][1] - v[i][0] + 1;
            if len <= 2 {
                arr[len].push(i);
            } else {
                arr[len % 3 + 3].push(i);
            }
        }
        arr
    }
    fn get_mid(rng: &[usize; 2]) -> usize {
        (rng[0] + rng[1] + 1) / 2
    }
    fn get_len(rng: &[usize; 2]) -> usize {
        rng[1] - rng[0] + 1
    }

    pub struct Solution {
        has_lower: bool,
        has_upper: bool,
        has_digit: bool,
        psw: String,
        n: usize,
        res: i32,
    }
    impl Solution {
        pub fn new(password: &str) -> Self {
            let has_lower = password.chars().any(|c| c.is_ascii_lowercase());
            let has_upper = password.chars().any(|c| c.is_ascii_uppercase());
            let has_digit = password.chars().any(|c| c.is_ascii_digit());
            Solution {
                has_lower,
                has_upper,
                has_digit,
                psw: String::from(password),
                n: password.len(),
                res: 0,
            }
        }
        fn insert_any(&mut self, idx: usize) {
            let mut prv = '_';
            if idx > 0 {
                prv = self.psw.chars().nth(idx - 1).unwrap();
            }
            let mut nxt = '_';
            if idx < self.psw.len() {
                nxt = self.psw.chars().nth(idx).unwrap();
            }
            if !self.has_lower {
                self.has_lower = true;
                if prv != 'a' && nxt != 'a' {
                    self.psw = insert(&self.psw, idx, 'a')
                } else if prv != 'b' && nxt != 'b' {
                    self.psw = insert(&self.psw, idx, 'b')
                } else {
                    self.psw = insert(&self.psw, idx, 'c')
                }
            } else if !self.has_upper {
                self.has_upper = true;
                if prv != 'A' && nxt != 'A' {
                    self.psw = insert(&self.psw, idx, 'A')
                } else if prv != 'B' && nxt != 'B' {
                    self.psw = insert(&self.psw, idx, 'B')
                } else {
                    self.psw = insert(&self.psw, idx, 'C')
                }
            } else {
                self.has_digit = true;
                if prv != '0' && nxt != '0' {
                    self.psw = insert(&self.psw, idx, '0')
                } else if prv != '1' && nxt != '1' {
                    self.psw = insert(&self.psw, idx, '1')
                } else {
                    self.psw = insert(&self.psw, idx, '2')
                }
            }
            self.n += 1;
            self.res += 1;
        }
        fn remove(&mut self, idx: usize) {
            self.psw = remove(&self.psw, idx);
            self.n -= 1;
            self.res += 1;
        }
        fn remove_any(&mut self) {
            let rng = get_index_ranges(&self.psw);
            let bin = get_bin(&rng);
            let order = vec![3, 4, 5, 2, 1];
            for j in 0..order.len() {
                let i = order[j];
                if bin[i].len() > 0 {
                    self.remove(get_mid(&rng[bin[i][0]]));
                    break;
                }
            }
            // if bin[3].len() > 0 {
            //     self.remove(get_mid(&rng[bin[3][0]]));
            // } else if bin[4].len() > 0 {
            //     self.remove(get_mid(&rng[bin[4][0]]));
            // } else if bin[5].len() > 0 {
            //     self.remove(get_mid(&rng[bin[5][0]]));
            // } else if bin[2].len() > 0 {
            //     self.remove(get_mid(&rng[bin[2][0]]));
            // } else {
            //     self.remove(get_mid(&rng[bin[1][0]]));
            // }
        }
        fn update_any(&mut self, idx: usize) {
            self.insert_any(idx);
            self.remove(idx + 1);
            self.res -= 1;
        }
        fn update_cnt(&mut self, rng: &[usize; 2]) {
            let mut l = rng[0] + 2;
            let r = rng[1];
            while l <= r {
                self.update_any(l);
                l += 3;
            }
        }
        pub fn strong_password_checker(password: String) -> i32 {
            let mut sol = Solution::new(&password);
            if sol.n < 6 {
                let rng = get_index_ranges(&sol.psw);
                for i in 0..rng.len() {
                    if get_len(&rng[i]) >= 3 {
                        sol.insert_any(get_mid(&rng[i]));
                    }
                }
                while sol.n < 6 {
                    sol.insert_any(0);
                }
            }
            while sol.n > 20 {
                sol.remove_any();
            }
            loop {
                let rng = get_index_ranges(&sol.psw);
                let bin = get_bin(&rng);
                let order = vec![3, 4, 5];
                let mut fix = false;
                for j in 0..order.len() {
                    let i = order[j];
                    for k in 0..bin[i].len() {
                        sol.update_cnt(&rng[bin[i][k]]);
                        fix = true;
                    }
                    // if bin[i].len() > 0 {
                    // bin[i].sort_by(|&x, &y| rng[x][0].cmp(&rng[y][0]));
                    // println!("mid {}",get_mid(&rng[bin[i][0]]));
                    // sol.update_any(get_mid(&rng[bin[i][0]]));
                    // }
                }
                if !fix {
                    break;
                }
            }
            while !sol.has_digit || !sol.has_lower || !sol.has_upper {
                sol.insert_any(0);
            }
            println!("psw = {}", sol.psw);
            sol.res
        }
    }
}
fn main() {
    use lc420::Solution;
    let psw = String::from("lr580");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("lrrr");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("rrrrr");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("lrrrr");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("lR580");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("aa");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("ab");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("ac");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("aaaabbaabbbbbaabbaabbaaababbbaaaabbbabbaaaaaabbbab");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("BaaaaBaBBBBBaaBaBBBaBaBBBaaBaBaBaaBaBaBBaaaBaBaaB0");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    println!("{}", Solution::strong_password_checker(psw));
    let psw = String::from("abcdef");
    println!("{}", Solution::strong_password_checker(psw));
}
//aaaabbaabbbbbaabbaabbaaababbbaaaabbbabbaaaaaabbbab 32
//BaaaaBaBBBBBaaBaBBBaBaBBBaaBaBaBaaBaBaBBaaaBaBaaB0 30
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 36
```

交题时不能有 struct，所以封了一下，变成了：

```rust
mod lc420s {
    //...
}
impl Solution {
    pub fn strong_password_checker(password: String) -> i32 {
        lc420s::Solution::strong_password_checker(password)
    }
}
```



##### 1032\.字符流

[题目]()

```rust
const P: usize = 37;
const DT: usize = 'a' as usize;
fn hash(s: &str) -> usize {
    let mut h = 0 as usize;
    for i in 0..s.len() {
        h = h.wrapping_mul(P); //自动取模溢出，否则panik
        h = h.wrapping_add(s.chars().nth(i).unwrap() as usize - DT);
    }
    h
}

struct StreamChecker {
    s: [Vec<usize>; 26],
    len: [Vec<usize>; 26],
    h: Vec<usize>,
    p: Vec<usize>,
}

impl StreamChecker {
    fn new(words: Vec<String>) -> Self {
        let mut s: [Vec<usize>; 26] = Default::default();
        let mut len: [Vec<usize>; 26] = Default::default();
        for i in 0..words.len() {
            let ch = words[i].chars().nth(words[i].len() - 1).unwrap(); //可以试试 .last()?
            let lch = ch as usize - DT;
            s[lch].push(hash(&words[i]));
            len[lch].push(words[i].len());
        }
        let h: Vec<usize> = vec![0];
        let p: Vec<usize> = vec![1];
        StreamChecker { s, len, h, p }
    }

    fn hash(&self, l: usize, r: usize) -> usize {
        let n = r - l + 1;
        self.h[r].wrapping_sub(self.h[l - 1].wrapping_mul(self.p[n]))
    }

    fn query(&mut self, letter: char) -> bool {
        let newh = self.h[self.h.len() - 1]
            .wrapping_mul(P)
            .wrapping_add(letter as usize - DT);
        self.h.push(newh);
        let newp = self.p[self.p.len() - 1].wrapping_mul(P);
        self.p.push(newp);
        let j = letter as usize - DT;
        let r = self.p.len() - 1;
        for i in 0..self.len[j].len() {
            if self.len[j][i] > r {
                continue;
            }
            let l = r - self.len[j][i] + 1;
            if self.hash(l, r) == self.s[j][i] {
                return true; //不可以不写 return
            }
        }
        false
    }
}

fn main() {
    let s = vec![String::from("cd"), String::from("f"), String::from("kl")];
    let mut sol = StreamChecker::new(s);
    println!("{}", sol.query('d'));
    for ch in 'a'..='l' { //可以枚举 str
        println!("{}", sol.query(ch));
    }
}
```



##### 1574\.删除最短的子数组使剩余数组有序

[题目](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

```rust
fn lower_bound(v: &Vec<i32>, x: i32) -> usize {
    v.partition_point(|&y| y < x)
}
struct Solution {}
impl Solution {
    pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
        let mut incf = 0; //单调前缀[0,inc]
        let mut incb = arr.len() - 1; //单调后缀 [incb,n)
        for i in 1..arr.len() {
            if arr[i] >= arr[i - 1] {
                incf += 1;
            } else {
                break;
            }
        }
        for i in (0..(arr.len() - 1)).rev() {
            if arr[i] <= arr[i + 1] {
                incb -= 1;
            } else {
                break;
            }
        }
        if incb <= incf {
            return 0;
        }
        let a = arr[incb..].to_vec();
        // println!("{} {} {:?}", incf, incb, a);
        let mut ans = arr.len() - 1 - incf;
        ans = ans.min(incb);
        for i in 0..=incf {
            let j = lower_bound(&a, arr[i]);
            // println!("{} {} {}", j, arr[i], incb + j - i - 1);
            ans = ans.min(incb + j - i - 1);
        }
        ans as i32
    }
}
fn main() {
    let arr = vec![1, 2, 3, 10, 4, 2, 3, 5];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
    let arr = vec![5, 4, 3, 2, 1];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
    let arr = vec![1, 2, 2, 3];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
    let arr = vec![1, 4, 3, 7, 5, 8, 1];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
    let arr = vec![1, 2, 3, 3, 10, 1, 3, 3, 5];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
    let arr = vec![16, 10, 0, 3, 22, 1, 14, 7, 1, 12, 15];
    println!("{}", Solution::find_length_of_shortest_subarray(arr));
}
```

> 交题时不要交 struct 那一行，main 也删了



##### 432\.全O(1)的数据结构

[题目](https://leetcode.cn/problems/all-oone-data-structure/)

```rust
use std::collections::HashMap;
use std::collections::HashSet;
struct AllOne {
    n: usize, //bin的下标是[0,n]
    mx: usize,
    mi: usize,
    bin: Vec<HashSet<String>>,
    h: HashMap<String, usize>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AllOne {
    fn new() -> Self {
        let mut bin: Vec<HashSet<String>> = vec![];
        bin.push(HashSet::new());
        bin[0].insert(String::from(""));
        let mut h: HashMap<String, usize> = HashMap::new();
        h.entry(String::from("")).or_insert(0);
        AllOne {
            n: 0,
            mx: 0,
            mi: 0,
            bin,
            h,
        }
    }

    fn update_mi_mx(&mut self, v: usize, t: usize) {
        if self.bin[v].len() == t {
            self.mx = 0;
            self.mi = 0;
            for i in 1..self.bin.len() {
                if self.bin[i].len() > 0 {
                    self.mx = i;
                    if self.mi == 0 {
                        self.mi = i;
                    }
                }
            }
        }
    }

    fn inc(&mut self, key: String) {
        let mut cnt = *self.h.entry(key.clone()).or_insert(0);
        self.bin[cnt].remove(&key); //根据有无返回boolean
        cnt += 1;
        self.mx = self.mx.max(cnt);
        if self.mx > self.n {
            self.n += 1;
            self.bin.push(HashSet::new());
        } // self.bin.resize_with(self.mx + 1, HashSet::new);
          // if self.mi == 0 {
          //     self.mi = cnt;
          // }
        self.bin[cnt].insert(key.clone());
        *self.h.get_mut(&key).unwrap() = cnt;
        // println!("ti {} {}", cnt , self.bin[cnt].len());
        self.update_mi_mx(cnt - 1, 0);
        self.update_mi_mx(cnt, 1);
        // println!("incd {} {}", self.mi, self.mx);
    }

    fn dec(&mut self, key: String) {
        let mut cnt = *self.h.get_mut(&key).unwrap();
        self.bin[cnt].remove(&key);
        // println!("td {} {}", cnt , self.bin[cnt].len());
        if cnt == 1 {
            self.h.remove(&key);
            self.update_mi_mx(cnt, 0);
        } else {
            cnt -= 1;
            *self.h.get_mut(&key).unwrap() = cnt;
            self.bin[cnt].insert(key.clone());
            self.update_mi_mx(cnt + 1, 0);
        }
        // println!("deld {} {}", self.mi, self.mx);
    }

    fn get_max_key(&self) -> String {
        self.bin[self.mx].iter().next().unwrap().clone()
    }

    fn get_min_key(&self) -> String {
        self.bin[self.mi].iter().next().unwrap().clone()
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * let obj = AllOne::new();
 * obj.inc(key);
 * obj.dec(key);
 * let ret_3: String = obj.get_max_key();
 * let ret_4: String = obj.get_min_key();
 */
fn main() {
    test4();
    test3();
    test2();
    test1();
}
fn test4(){
    let mut obj = AllOne::new();
    obj.inc(String::from("hello"));
    obj.inc(String::from("hello"));
    obj.inc(String::from("world"));
    obj.inc(String::from("world"));
    obj.inc(String::from("hello"));
    obj.dec(String::from("world"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
    obj.inc(String::from("world"));
    obj.inc(String::from("world"));
    obj.inc(String::from("leet"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
    obj.inc(String::from("leet"));
    obj.inc(String::from("leet"));
    println!("{}", obj.get_min_key());
}
fn test3() {
    let mut ojb = AllOne::new();
    ojb.inc(String::from("hello"));
    ojb.inc(String::from("world"));
    ojb.inc(String::from("hello"));
    ojb.dec(String::from("world"));
    ojb.inc(String::from("hello"));
    ojb.inc(String::from("shit"));
    println!("{}", ojb.get_max_key());
    ojb.dec(String::from("hello"));
    ojb.dec(String::from("hello"));
    ojb.dec(String::from("hello"));
    println!("{}", ojb.get_max_key());
}
fn test2() {
    let mut obj = AllOne::new();
    obj.inc(String::from("a"));

    obj.inc(String::from("b"));
    obj.inc(String::from("b"));
    obj.inc(String::from("b"));
    obj.inc(String::from("b"));
    obj.dec(String::from("b"));
    obj.dec(String::from("b"));

    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
}
fn test1() {
    let mut obj = AllOne::new();
    obj.inc(String::from("lr580"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
    obj.dec(String::from("lr580"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
    obj.inc(String::from("baicha"));
    obj.inc(String::from("baicha"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
    obj.inc(String::from("fff"));
    println!("{}", obj.get_max_key());
    println!("{}", obj.get_min_key());
}
```



##### 2395\.和相等的子数组

[题目](https://leetcode.cn/problems/find-subarrays-with-equal-sum/)

```rust
use std::collections::HashMap;
// struct Solution {}
impl Solution {
    pub fn find_subarrays(nums: Vec<i32>) -> bool {
        let mut s = vec![0; nums.len() + 1];
        for i in 0..nums.len() {
            s[i + 1] = nums[i] + s[i];
        }
        let mut h: HashMap<i32, i32> = HashMap::new();
        for l in 0..s.len() {
            // for r in (l + 1)..s.len() { //一开始读错题了
            for r in (l + 2)..=(l + 2) { 
                if r >= s.len() {
                    continue;
                }
                let cnt = h.entry(s[r] - s[l]).or_insert(0);
                *cnt += 1;
            }
        }
        for (k, v) in &h {
            if *v > 1 {
                return true;
            }
        }
        false
    }
}
```

更优的做法是，插入时发现 =1 return true 即可，不需要遍历。

##### 1638\.统计只差一个字符的子串数目

[题目](https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/)

```rust
const P0: i32 = 131;
const P1: i32 = 10007;
fn fill(s: &String, h: &mut Vec<i32>) {
    for i in 0..s.len() {
        h[i + 1] = h[i]
            .wrapping_mul(P0)
            .wrapping_add(s.chars().nth(i).unwrap() as i32);
    }
}
fn hash(l: usize, r: usize, h: &Vec<i32>, p: &Vec<i32>) -> i32 {
    if l > r || r >= h.len() || l >= h.len() {
        return 0;
    }
    h[r].wrapping_sub(h[l - 1].wrapping_mul(p[r - l + 1]))
}
use std::collections::{HashMap, HashSet};
type Hmap = HashMap<i32, HashSet<i32>>; //hmap 命名会 warning
type Hmap2 = HashMap<(i32, i32), HashSet<i32>>;
fn pre(h: &Vec<i32>, p: &Vec<i32>) -> Hmap2 {
    let mut m: Hmap2 = HashMap::new();
    for l in 1..h.len() {
        for r in l..h.len() {
            for k in l..=r {
                let hl = hash(l, k - 1, &h, &p);
                let hr = hash(k + 1, r, &h, &p);
                let k2 = (l as i32).wrapping_mul(P1).wrapping_add(r as i32);
                m.entry((hl, hr)).or_insert(HashSet::new()).insert(k2);
            }
        }
    }
    m
}
fn pre2(h: &Vec<i32>, p: &Vec<i32>) -> Hmap {
    let mut m: Hmap = HashMap::new();
    for l in 1..h.len() {
        for r in l..h.len() {
            let h = hash(l, r, &h, &p);
            let k = (l as i32).wrapping_mul(P1).wrapping_add(r as i32);
            m.entry(h).or_insert(HashSet::new()).insert(k);
        }
    }
    m
}
pub struct Solution {}
impl Solution {
    pub fn count_substrings(s: String, t: String) -> i32 {
        let n = s.len();
        let m = t.len();
        let mn = n.max(m);
        let mut p: Vec<i32> = vec![0; mn + 1]; //长度不确定不能用array
                                               //必须声明类型,不然乘不了
        p[0] = 1;
        for i in 1..=mn {
            p[i] = p[i - 1].wrapping_mul(P0);
        }
        let mut hs = vec![0; n + 1];
        let mut ht = vec![0; m + 1];
        fill(&s, &mut hs);
        fill(&t, &mut ht);
        let mt = pre(&ht, &p);
        let mut ans = 0 as i32;
        for l in 1..hs.len() {
            for r in l..hs.len() {
                let mut bin: HashSet<i32> = HashSet::new();
                for k in l..=r {
                    let hl = hash(l, k - 1, &hs, &p);
                    let hr = hash(k + 1, r, &hs, &p);
                    if mt.contains_key(&(hl, hr)) {
                        let vs = mt.get(&(hl, hr)).unwrap();
                        bin.extend(&*vs);
                    }
                }
                ans += bin.len() as i32;
            }
        }
        let ms2 = pre2(&hs, &p);
        let mt2 = pre2(&ht, &p);
        for (k, vs) in ms2.iter() {
            if !mt2.contains_key(&k) {
                continue;
            }
            let vs2 = mt2.get(&k).unwrap();
            let cnt = vs.len() as i32;
            let cnt2 = vs2.len() as i32;
            ans -= cnt * cnt2;
        }
        ans
    }
}
fn main() {
    // println!("{}", Solution::count_substrings(
    //     "asdadasdsadsadsdsdsadasdsdsasd".to_owned(),
    //     "asdsadasss".to_owned(),
    // ));
    println!(
        "{}",
        Solution::count_substrings("aba".to_owned(), "baba".to_owned(),)
    );
    println!(
        "{}",
        Solution::count_substrings("ab".to_owned(), "bb".to_owned(),)
    );
    println!(
        "{}",
        Solution::count_substrings("a".to_owned(), "a".to_owned(),)
    );
    println!(
        "{}",
        Solution::count_substrings("abe".to_owned(), "bbc".to_owned(),)
    );
}
```



##### 1092\.最短公共超序列

[题目](https://leetcode.cn/problems/shortest-common-supersequence/)

> ```rust
> struct Solution {}
> /** t 是否是子串 */
> fn issub(s: &str, t: &str) -> bool {
>     let mut j = 0;
>     for i in 0..s.len() {
>         let sc = s.chars().nth(i);
>         let tc = t.chars().nth(j);
>         if sc == tc {
>             j += 1;
>             if j == t.len() {
>                 return true;
>             }
>         }
>     }
>     false
> }
> fn extend(s: &String, t: &String) -> String {
>     let mut res = s.clone() + &t;
>     for i in 1..t.len() {
>         let ts = &t[0..i];
>         if issub(&s[..], ts) {
>             println!("{} {} {} {} {} {}", i, ts, &t[i..], s.clone() + &t[i..], s.len() + (t.len() - i), res.len());
>         }
>         if issub(&s[..], ts) && s.len() + (t.len() - i) < res.len() {
>             res = s.clone() + &t[i..];
>         }
>     }
>     if issub(&s[..], &t[..]) {
>         res = s.clone();
>     }
>     res
> }
> impl Solution {
>     pub fn shortest_common_supersequence(str1: String, str2: String) -> String {
>         "x".to_string()
>     }
> }
> fn main() {
>     println!("{}", issub("abac", "aac"));
>     println!("{}", issub("abac", "abac"));
>     println!("{}", issub("abac", "ca"));
>     println!("{}", extend(&"abac".to_string(), &"aac".to_string()));
>     println!("{}", extend(&"abac".to_string(), &"abac".to_string()));
>     println!("{}", extend(&"abac".to_string(), &"ca".to_string()));
>     println!("{}", extend(&"abac".to_string(), &"baba".to_string()));
>     println!("{}", extend(&"abac".to_string(), &"aaac".to_string()));
>     println!("{}", extend(&"abac".to_string(), &"g".to_string()));
> }
> ```



##### 1641\.统计字典序元音字符串的数目

[题目](https://leetcode.cn/problems/count-sorted-vowel-strings/)

```rust
impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        let _n = (n + 1) as usize;
        let mut dp = Vec::with_capacity(_n);
        for _ in 0.._n {
            dp.push(vec![0; 5]);
        }
        for i in 0..5 {
            dp[0][i] = 1;
        }
        for i in 1.._n {
            for j in 0..5 {
                for k in 0..=j {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        dp[_n - 1][4]
    }
}
```



##### 1637\.两点之间不包含任何点的最宽垂直区域

[题目](https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/)

我的：

```rust
impl Solution {
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut a = vec![0; n];
        for i in 0..n {
            a[i] = points[i][0];
        }
        a.sort();
        let mut ans = 0;
        for i in 1..n {
            ans = ans.max(a[i] - a[i - 1]);
        }
        ans
    }
}
```

其他人的写法：

```rust
impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|a, b| a[0].cmp(&b[0]));
        (1..points.len()).fold(0, |ret, i| ret.max(points[i][0] - points[i - 1][0]))
    }
}
```

```rust
impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|x, y| {
            x[0].cmp(&y[0])
        });
        let mut ans = 0;
        for v in points.windows(2).into_iter() {
            ans = std::cmp::max(ans,v[1][0]-v[0][0])
        }

        ans
    }
}
```

```rust
impl Solution {
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        let mut points: Vec<i32> = points.into_iter().map(|point| point[0]).collect();
        points.sort();
        let mut ans: i32 = 0;
        for window in points.windows(2) {
            ans = ans.max(window[1] - window[0]);
        }
        ans
    }
}
```

```rust
impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        let mut ret = 0;

        points.sort_unstable_by_key(|p| p[0]);

        for i in 1..points.len() {
            ret = ret.max(points[i][0] - points[i - 1][0]);
        }

        ret
    }
}
```



##### 1\.两数之和

[题目](https://leetcode.cn/problems/two-sum/)

```rust
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut m = HashMap::new();
        let n = nums.len();
        for i in 0..n {
            let v = target - nums[i];
            if let Some(j) = m.get(&v) {
                return vec!(*j as i32, i as i32); //或[ ]
            }
            m.insert(nums[i], i);
        }
        vec![0, 1] //panic!("not found")
    }
}
```



##### 2367\.算术三元组的数目

[题目](https://leetcode.cn/problems/number-of-arithmetic-triplets/)

```rust
impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let n = nums.len();
        let mx = *nums.iter().max().unwrap() as usize;
        let mut bin = vec![0; mx + 1];
        for i in 0..n {
            bin[nums[i] as usize] += 1;
        }
        let t = diff as usize;
        let mut ans = 0;
        if t >= mx {
            return 0;
        }
        for i in t..=(mx - t) { //mx-t如果t>mx会变无穷
            ans += bin[i] * bin[i - t] * bin[i + t];
        }
        ans
    }
}
```



##### 2\.两数相加

[题目](https://leetcode.cn/problems/add-two-numbers/)

```rust
pub struct Solution {}
// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}
//Box 是一个智能指针类型，用于在堆上分配和存储数据。

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}
impl Solution { //只交这个
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        //根据return自动把Option<Unkonwn>推断
        let mut res = None;
        let mut p = &mut res;
        let mut carry = 0;
        //as_ref 方法的作用是将一个具有所有权的值（例如一个 Box 智能指针）转换为一个只有引用的值（例如一个 &T 引用），以便在不需要所有权的情况下访问该值
        let mut lfs = l1.as_ref();
        let mut rfs = l2.as_ref();
        //注意 is_some 方法
        while lfs.is_some() || rfs.is_some() || carry > 0 {
            let mut sum = carry;
            //ln 是 *Box<ListNode>,注意 if let Some 的用法
            if let Some(ln) = lfs {
                sum += ln.val;
                lfs = ln.next.as_ref();
            }
            if let Some(rn) = rfs {
                sum += rn.val;
                rfs = rn.next.as_ref();
            }
            carry = sum / 10;
            let node = ListNode::new(sum % 10);
            *p = Some(Box::new(node));
            //as_mut 是一个用于将可变引用转换为其他类型的方法。它允许您将一个可变引用从一种类型转换为另一种类型，从而允许您在不改变变量的所有权的情况下对其进行修改
            p = &mut p.as_mut().unwrap().next;
        }
        res
    }
}
pub fn test() {}

```



##### 831\.隐藏个人信息

[题目](https://leetcode.cn/problems/masking-personal-information/)

```rust
struct Solution {}
impl Solution {
    pub fn mask_pii(s: String) -> String {
        let t = s.to_lowercase();
        // if t.contains('@') {
        if let Some(idx) = t.find('@') {
            //注意chars, nth 方法都是O(n) --GPT
            let first = t.chars().nth(0).unwrap().to_string();
            let res = first + "*****" + &t[idx - 1..];
            return res;
        } else {
            let mut num = String::new();
            for c in t.chars() {
                if c.is_numeric() {
                    num.push(c);
                }
            }
            let last = &num[num.len() - 4..];
            return match num.len() {
                10 => "***-***-".to_string() + last,
                11 => "+*-***-***-".to_string() + last,
                12 => "+**-***-***-".to_string() + last,
                13 => "+***-***-***-".to_string() + last,
                _ => panic!("Oops!"),
            };
        }
    }
}
```

> 其他人的写法：
>
> ```rust
> impl Solution {
>     pub fn mask_pii(s: String) -> String {
>         if let Some(index) = s.find('@') {
>             return s[0..1].to_lowercase() + "*****" + &s[(index-1)..].to_lowercase();
>         }
> 
>         let mut count = 0;
>         let mut num_str = String::new();
> 
>         s.chars().rev().for_each(|c| {
>             if c >= '0' && c <= '9' {
>                 count += 1;
> 
>                 if count <= 4 {
>                     num_str.insert(0, c);
>                 }
>             }
>         });
> 
>         if count == 10 {
>             "***-***-".to_string() + &num_str
>         } else {
>             "+".to_string() + &"*".repeat(count - 10) + &"-***-***-".to_string() + &num_str
>         }
>     }
> }
> ```
>
> ```rust
> impl Solution {
>     pub fn mask_pii(s: String) -> String {
>         const COUNTRY: [&'static str; 4] = ["", "+*-", "+**-", "+＊＊＊-"];
>         if s.contains('@') {
>             let s = s.to_lowercase();
>             let mut s = s.split('@');
>             let mut t = s.next().unwrap().chars();
>             format!(
>                 "{}＊＊＊**{}@{}",
>                 t.next().unwrap(),
>                 t.next_back().unwrap(),
>                 s.next().unwrap()
>             )
>         } else {
>             let s = s
>                 .replace("+", "")
>                 .replace("-", "")
>                 .replace("(", "")
>                 .replace(")", "")
>                 .replace(" ", "");
>             let c = s.len() - 10;
>             format!("{}＊＊＊-＊＊＊-{}", COUNTRY[c], &s[s.len() - 4..])
>         }
>     }
> }
> ```



##### 1039\.多边形三角剖分的最低得分

[题目](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)

想不到怎么闭包做递归的语法，所以只能搞函数了，但是因为作用域，必须传参数。

```rust
impl Solution {
    pub fn min_score_triangulation(v: Vec<i32>) -> i32 {
        let n = v.len();
        let mut dp = vec![vec![0; n]; n];
        fn calc(v: &[i32], dp: &mut Vec<Vec<i32>>, l: usize, r: usize) -> i32 {
            if dp[l][r] != 0 {
                return dp[l][r];
            }
            if l + 2 > r {
                return 0;
            }
            if l + 2 == r {
                return v[l] * v[l + 1] * v[r];
            }
            let mut ans = i32::MAX;
            for k in l + 1..r {
                ans = ans.min(v[l] * v[k] * v[r] + calc(v, dp, l, k) + calc(v, dp, k, r));
            }
            dp[l][r] = ans;
            ans
        };
        calc(&v, &mut dp, 0, n - 1)
    }
}
```



##### 1052\.交换一次的先前排列

[题目](https://leetcode.cn/problems/previous-permutation-with-one-swap/)

```rust
use std::collections::BTreeMap;
impl Solution {
    pub fn prev_perm_opt1(arr: Vec<i32>) -> Vec<i32> {
        let n = arr.len();
        let mut h: BTreeMap<i32, usize> = BTreeMap::new();
        let mut ans: Vec<i32> = Vec::new();
        ans.extend(arr);
        for i in (0..n).rev() {
            if i + 1 != n {
                let v = ans[i];
                if let Some(j) = h.range(..v).next_back().map(|(&_k, &v)| (v)) {
                    let k = ans[i];
                    ans[i] = ans[j];
                    ans[j] = k;
                    break;
                }
            }
            h.insert(ans[i], i);
        }
        ans
    }
}
```



##### 1000\.合并石头的最低成本

[题目](https://leetcode.cn/problems/minimum-cost-to-merge-stones/)

fake:

> ```rust
> impl Solution {
>     pub fn merge_stones(stones: Vec<i32>, k: i32) -> i32 {
>         let n = stones.len();
>         if (n as i32 - 1) % (k - 1) != 0 {
>             return -1;
>         }
>         let mut s = vec![0; n + 1];
>         for i in 0..n {
>             s[i + 1] += s[i] + stones[i];
>         }
>         let sum = |l, r| s[r] - s[l - 1];
>         let mut dp = vec![vec![0; n + 1]; n + 1];
>         let mut len = k as usize;
>         while len <= n {
>             for r in len..=n {
>                 let l = r + 1 - len;
>                 let len2 = len - (k as usize - 1);
>                 let mut mi = i32::MAX;
>                 for l2 in l..=r + 1 - len2 {
>                     let r2 = l2 + len2 - 1;
>                     let res = sum(l, r) + dp[l2][r2];
>                     mi = mi.min(res);
>                 }
>                 dp[l][r] = mi;
>             }
>             len += k as usize - 1;
>         }
>         dp[1][n]
>     }
> }
> ```



##### 1017\.负二进制转换

[题目](https://leetcode.cn/problems/convert-to-base-2/)

```rust
impl Solution {
    pub fn base_neg2(n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }
        let mut v = n as i64;
        let mut i = 1 as i64;
        let mut ip = 2 as i64;
        const TOP: i64 = 30;
        while i < TOP {
            v += ip;
            i += 2;
            ip *= 4;
        }
        i -= 2;
        ip /= 4;
        assert!(i == TOP - 1);
        // println!("v={} i={} ip={}", v, i, ip);
        let mut ans = String::new();
        let c = ["01", "00", "11", "10"];
        while i > 0 {
            let r = v / ip;
            v %= ip;
            ans += c[r as usize];
            // println!("r={} ans={}", r, ans);
            i -= 2;
            ip /= 4;
        }
        if v == 0 {
            ans += "0";
        } else {
            ans += "1";
        }
        // println!("v={} ans={}", v, ans);
        ans.trim_start_matches('0').to_string()
    }
}
```





### 项目

#### 网挑鉴权

##### 模块加载

###### 同目录

main 直接调用的话，就 mod 一下。

```rust
//mongo.rs
pub fn echo() {
    println!("模块可用");
}
```

同一文件夹下：

```rust
//main.rs
mod mongo;
fn main() {
    mongo::echo();
}
```

其他文件要调用其他文件，首先 main 里 mod，然后其他文件里用绝对路径即 `crate::`。

> ```rust
> mod test_module;
> mod db_util;
> mod ini_plugin;
> mod mongo;
> mod auth_node;
> #[tokio::main]
> async fn main() -> Result<(), Box<dyn std::error::Error>> {
>     test_module::test().await;
>     Ok(())
> }
> ```
>
> ```rust
> use mongodb::Collection;
> use mongodb::bson::{doc, Document};
> pub async fn test() {
>     let db = crate::db_util::get_db().await;
>     let col: Collection<Document> = db.collection("test");
>     let mut nd = crate::auth_node::AuthNode::new(0, 0, "root".to_string());
>     nd._id = Some(bson::oid::ObjectId::new());
>     let doc = bson::ser::to_document(&nd).unwrap();
>     let res = col.delete_many(doc! {}, None).await.unwrap();
>     println!("deletes: {}", res.deleted_count);
>     let res = col.insert_one(doc, None).await.unwrap();
>     println!("inserted: {}", res.inserted_id);
>     println!("Done");
> }
> ```

###### 不同目录

设有 `test/test01.rs`，则：

```rust
mod test {
    pub mod test01;
}
use test::test01::func;
```

