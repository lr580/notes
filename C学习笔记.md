# 前言

## 备注

<p align="right">--made by lr580</p>

由于本蒟蒻知识水平和精力有限，其中内容可能会存在错误、片面以及不全面的地方，欢迎指出和纠错~

> - 强烈建议使用typora阅读并打开大纲，这样可以看到目录。*(shift+ctrl+3)*
> - 如果发现typora数学公式无法渲染出来(typora第一次一般都加载不出来)，重新打开本文档
> - 由于本文档较大，typora加载需要一定的时间(本机测试半分钟以上)

## 更新日志

- 20/9/18,开始编写本笔记，从《算法竞赛入门经典》的第二章开始记笔记，其他有待补充
- 20/10/8 完成C的知识网络(主要来源:《C语言程序设计》)，为12627词
- 20/10/26整合部分内容，添加C++部分，重新改版部分笔记。此时约2.2万词(误差向上不超过3千词)
- 20/11/4 完成C++知识网络，现49576词
- 20/11/17 修改了部分编排，将数据结构独立成了一级标题。现51950词
- 20/12/12 修改了数据结构编排。增加了一些内容。现58145词
- 21/1/17 大量增加了算法/数据结构的内容和例题，现100664词
- 21/2/1 将动态规划章在算法中独立为二级标题，现123642词
- 21/3/11 大量增加了算法/数据结构的内容和例题，现170648词
- 21/3/21 修改了较多二/三/四级标题的编排，增加了算法内容，现185592词
- 21/5/31 增加了较多的算法/数据结构内容和例题，现239079词

# C - 知识网络

## 运算

### 代码规范

#### 标识符命名规则

1. 以字母或下划线开头
2. 不允许使用C关键字作为标识符
3. 只能由英文字母、数字0、下划线组成
4. 不长于65535字节
5. 建议函数名动词(+名词);变量名(形容词+)名词linux/unix下划线分单词

#### 代码调试

1. 程序测试只能证明代码有错，而不能证明代码无错
2. 白盒/玻璃盒/结构测试：使用测试用例，让程序尽可能多的分支情况被执行到
3. 黑盒/功能测试：后期的测试，检验功能是否正确
4. 通常需要调试边界，因为边界出错率一般更高
5. 采用增量测试：新代码，测试排错同步进行，已有旧代码一般不会有错
6. 不要急于修改bug，思考一下修改后会不会引发其他缺陷；修改完要对所有同类bug一并修改；
7. 断言(assert.h)，表达：assert(逻辑表达式);

#### 结构化编程

1. 结构清晰，容易阅读，容易修改，容易验证
2. 为了好结构，允许在可容忍范围内牺牲效率

#### 模块化编程

1. 自顶而下，逐步求精
2. 分而治之，每部分功能专门化，高聚合，低耦合
3. 信息隐藏，函数封装
4. 每个函数前写注释描述功能及其形参，最好有例子，和异常状态说明，入口可以检测参数有效性
5. 应增加函数健壮性(robustness)，专门处理一些非法输入和不正确使用，善于防御性编程
6. 函数规模尽量在50行以内
7. 如果一个功能需要重复三次或以上，建议写成函数
8. 尽量不要在函数用全局变量
9. 

#### 代码规范

##### 代码块

1. 一行一条语句，一行定义一个变量；便于注释和阅读
2. 定义时初始化
3. if,for,while,do等独占一行，循环体一律用{}，无论是否单行

##### 对齐与缩进

1. {}各独占一行，与引用者左对齐
2. 梯形层次的缩进
3. 4空格或Tab缩进一次

##### 空行与空格

1. 函数定义结束后加一个空行
2. 函数体内，关系密切的数行代码之间空行
3. 关键字后空格,如if,for
4. 函数名后不加空格
5. 赋值，算术，关系，逻辑等运算符前后各加一个空格，单目运算符除外
6. 表达式很长的for和if，为了紧凑适当去掉一些空格
7. 左圆括号后紧跟，右圆括号，逗号和分号向前紧跟，例如：f(x, y, z)
8. 函数参数逗号及for分号后加一个空格
9. 长行拆分

##### 注释

1. 重要文件首部，对程序功能，编程者，变成日期，和版本号等其他信息注释说明，一般C用/**/,C++//
2. 自定义函数前面说明函数接口
3. 重要语句右方，如定义非通用变量，函数调用，长多重嵌套语句块结束处，注释
4. 重要语句上方，尤其是语义转折处，对功能和原理解释
5. 注释不是翻译程序，不写做了什么，写想做什么和如何做，应画龙点睛
6. 编写代码编写注释，修改代码一并修改
7. 供他人使用的函数必须严格注释
8. *自动文档工具：Doxygen*



### 变量常量

#### 常量的表示方法

> 常量不以标识符表示而直接使用，称为幻数

##### 数

有符号整型 -1,0,377

无符号整型 30u, 50U

长整型 -256l,1024L(long long则LL或ll，不允许Ll或lL)

无符号长整型 30lu(大小写任意共四种，顺序可以颠倒,ull同)

双精度实型  实型可以写成1.0,1e3,.2,-.2,2.,-.7

​						0.0可以写成0.或.0，不可以写成.

​	指数形式 -2e-3 0E0 1不可以省略

单精度实型 1.25F  1.25e-2f

长双精度实型 1.25L  .3l

##### 字符

字符常量 'a'

- 在ASCII码里，实际上能够在终端上显示的只有78个

字符串字面量(字符串常量) "a"

字符串常量的\0结束表示可以不显式地写出

双引号里边可以有单引号，反之也是，不需要转义符

#### #define

很大的常量通常定义在main外，用：

```c
#define 变量名 值
```

很大的变量（一般是数组）同理

可以define个寂寞，如#define LOCAL

这种应用可以是：

```c
#ifdef LOCAL
	printf("normal mode\n");
#endif
```

```c
//或者是
#ifdef XXX
	;
#else
#	include <....>
#endif
```

```c
//或者是
#ifndef XXX
	#define XXX
#endif
```

```c
//或者是
#if 表达式1
#elif 表达式2
#else
#endif
```

```c
//预处理运算符 defined
#if defined(x.h)
```

```c
//抛出错误
#error Fuck off
```





末尾可以加/* */类注释,//不行

可以跨行定义，如：

```c
#define SD "fuck \
off!" /*注意左对齐*/
```



可以使用变量，例如：

```c
#define ALL(x) x.begin(),x.end()
#define SQUARE(x) ((x)*(x))
```

```c
#define TWO 2
#define FOUR TWO+TWO
```

重定义时最好撤销定义：

```c
#define A 3
#undef A
#define A 4
```



可以字符串化：

```c
#define PSQR(x) printf("It x is %d", ((x)*(x)))
//上面的X是字符串X，不会被X替代，但下面的会被代码中的替代：
#undef PSQR(x) //大概是这样吧
#define PSQR(x) printf("It " #x " is %d", ((x)*(x)))
//in main
int y = 5;
PSQR(y); //It y is 25
PSQR(1);//It 1 is 1
```

类似于字符串的连接：使用##

```c
#define XK(n) str ## n
```

##### 举例：

```c
#define INF 0x7fffffff 
#define ull unsigned long long //代替typedef
```

#### 全局变量

一般使用在：

1. 类型固定（程序升级而不改变）
2. 很有限的地方需要修改
3. 很多地方需要调用或输出

全局变量数组会被初始化，其二进制位均为0

#### 变量的生存期

声明变量：存储类型 类型名 变量名 (=初始值)，例如static int x=3;

> 按生存期分静态、动态变量。（作用域分局部和全局）
>
> 变量赋初值可以分为编译和运行两个阶段。
>
> 只有在使用时才为该类型变量分配内存的存储类型说明是auto和register
>
> 全局变量，静态变量的初值是在编译时指定的； 局部变量如果没有指定初值，则其初值不确定。
>
> 存储类型不能复用，如auto register

##### 自动变量 auto

默认的方法。当退出语句块时自动释放内存，仅能被语句块内代码访问。

自动变量定义时不会自动初始化

##### 静态变量 static

静态变量与程序共存亡。静态变量也分局部变量和全部变量（看定义的位置）。

递归函数不同层级共用一个static

##### 外部变量 extern

可以初始化为0

与整个程序共存亡。

当使用另一个源代码里的变量作extern时，可以作修改。

##### 寄存器变量 register

默认大多是。能够让程序更小执行更快。不能是全局变量。

### 数据类型

基本类型为基本整型、长整型、长长整型、短整型、无符号整型、单精度实型、双精度实型、长双精度实型、字符型、枚举类型；构造类型为数组、结构体和共用体；除此之外还有指针类型和无类型。

|   英文    | 中文 |   字节大小   |  换算  |
| :-------: | :--: | :----------: | :----: |
|   b bit   | 比特 |   代表0/1    |        |
|  B Byte   | 字节 |              | 1B=8b  |
|  KB kilo  |  K   |   一千字节   | 2^10B  |
|  MB mega  |  兆  |     百万     | 2^20B  |
|  GB giga  |  吉  |  十亿/千兆   | 2^30B  |
|  TB tera  |  太  |     万亿     | 2^40B  |
|  PB peta  |  拍  |    千万亿    | 2^50B  |
|  EB exab  |  艾  |    百亿亿    | 2^60B  |
| ZB zetta  |  泽  |   十万亿亿   | 2^70B  |
| YB yotta  |  尧  |   一亿亿亿   | 2^80B  |
| BB bronto |      |  一千亿亿亿  | 2^90B  |
|  NB nona  |      | 一百万亿亿亿 | 2^100B |
| DB dogga  |      |  十亿亿亿亿  | 2^110B |

#### 数组

```c
int x[] = {1,2,3};
/*定义整形数组，长度可给可不给(如x[3],x[5])，下标从0开始*/
//除初始化不允许出现{}给数组赋值
```

```c
//定义二维数组：两两等效
short matrix[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
short matrix[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

short matrix[3][4] = {{1,2,3,0},{4,5,0,0},{6,0,0,0}};
short matrix[][4] = {{1,2,3},{4,5},{6}};
//多余的位置都变成了0
//万一误写成matrix[i,j]，根据逗号运算符，结果为matrix[j]，且无报错
```

注意，定义在全局的会被初始化，如int的为0

非全局，开memset或for

```c
short matrix[5] = {0};
```

上面的方法只能初始化为0，其他值无效，只给首个元素。



一般情况下，声明数组的长度比预期使用的大些

```c
char s[1020];
```

向函数传入一维数组：f(array)，一般还要传它的长度

是传址（本质上是传指针即地址）

> main里边最多约2MB的内存，所以数组(以long double为例)在main里边的最大长度为129502。所以建议放main之外。或者设动态数组。

数组长度为变量(如取决于scanf的)，多维下部分编译器有时候不允许

##### 常用操作

###### scanf输入

整组录入(一般是字符数组)不用取地址

非整组录入的代码示例：

```c
int x, n = 0;
while(scanf("%d", &x) == 1)
    a[n++] = x;
```

###### 批量定义

注意：mem系的值都是每一位的值，如0或1，memset一般都是用0的。

在(string.h)

memset(数组名, 值,  大小)

如果完全，大小是sizeof(该数组名)，也可以sizeof(类型)*长度

例如：sizeof(double)*10

###### 复制

在(string.h)

memcpy(待复制数组名, 模板数组名, 大小)

###### 取长度

sizeof(数组名)/sizeof(数据类型)

​	注意：在函数中不能这么做，只能传入数组长度，虽然说可以用sizeof(数据类型)*长度，假定长度已知

#### char

char为$-128 \to 127$($-2^7 \to 2^7-1$)，1字节

unsigned char为$0 \to 255(0 \to 2^8-1)$，占1字节(1B)

数字和字母 序号(0开始)与ASCII转化：

n = c - 'a'或'A';   n = c - '0';

正值是ascii，负是中文或其他

如果八进制，写成\o, \oo, \ooo, o为一个八进制数字

十六进制，写\xh, h为十六进制数字串

> 在C++char默认有无符号视操作环境而定，char, signed charm unsigned char是三种数据类型

#### char数组

定义：

```c
char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
//如果没有\0，则不是字符串，仅仅是一个字符数组，等效于：
char str[] = {"Hello"};
char str[] = "Hello";

char weekday[][10] = {"Monday", ... , "Sunday"};
//10必须要写，初始化后其他多余的地方都变成了\0

//分开定义，无缝连接
char longs[] = "This is the ..."
    "and this is the ...";
```



注意，手动(一般通过循环)赋值的char数组最后应当有\0

函数可以返回char数组指针

##### 常用操作

###### 取长度

<string.h>

strlen(数组名)

###### 复制

<string.h>

strncpy(待复制数组, 父本数组+起始下标, 复制长度)

返回指向待复制数组的指针

如果复制时知道复制完了也没有复制到\0，那应该在末尾手动加一个

其实也有strcpy的，但是没那么健壮性

###### 比较

<string.h>

strcmp(数组1, 数组2) 相同返回0

不同的话字典序的比较结果(前者大是1，小是-1)

字典序比较：出现不同时，不同的那一位的int值，大的就大(fw>fW)

​		前面一直相同，长的就大(aa<aab)

###### 连接

<string.h>

strcat(数组1,数组2) 等同于python的a+b

建议使用strncat提升健壮性(数组1,数组2,追加最大字符数)

###### IO

<stdio.h>

sprintf(), sscanf() 同printf,scanf,第一个参数改为char数组名

###### 查找

<string.h>

strchr(char数组, 待查找int)

在字符串查找单个字符，找不到返回NULL，即0

如果找到了，返回指针，当前位置为首次出现该字符的位置

例如：“2334”找3,printf那个指针(%s)是"334"

##### 指针式

允许如下赋值：

```c
char b[5],*p=b;
p="abcd";//不能写成*p
```

#### int

范围：C99至少16位，2字节；多数情况下是4字节

32位时是-2147483648 ~ 2147483647即-2^31^~2^31^-1，约2.1e9

补码表示法：-n的内部是2^32-n

#### long

long int 或简写为long，下同

-2147483648~2147483647

即-2^31^~2^31^-1，4字节

#### long long

范围-2^63^~2^63^-1，8字节

即-9223372036854775808~9223372036854775807 约9.2e18

#### float

4字节

-3.40282e38~3.40282e38

一般精度(有效位数)是小数点后7位

#### double

8字节

-1.79769e308~1.79769e308

一般精度是16位(C++ 15)

#### long double

若long double,12字节(或8，该操作系统为8)

18--19 (-4931)--(4632)

##### 判断double是否为int

```c
x-(int)x<=EPS //方法一：EPS 一般取1e-6
```

```c++
x==floor(x) //方法二,cmath库
```

#### short

-2^15 ~ 2^15-1(即-32768 ~ 32767)；2字节

#### unsigned

使得原取值范围-X~X-1 变为0~2X-1

即-2^K^~2^K^-1变为0~2^k+1^-1，不改变字节



#### 结构体

##### 定义

###### 方法一

定义：

```c
struct 结构名{属性定义，例如double x,y;};
```

函数调用的参数: struct 结构名 变量名

普通调用：结构变量名.属性名



可以同时定义一个变量：

```c
struct 结构名{...} 变量名;
```

可以只定义孤独的变量：

```c
struct {...} 变量名;
```

那么传该结构体作函数变量将难以实现。(用struct {...}为参数等方法也不行)

###### 方法二

定义：

```c
typedef struct {属性定义;}结构名;//另一说法
其实还可以： typedef long long llong;
```

```c
typedef struct 结构名{...}结构简名;
等于方法一加上 typedef struct 结构名 结构简名;
//一般结构名小写，结构简名大写
//调用时就能够把struct 结构名 简化成 结构简名
//此时不能同时定义一个变量
```

支持位字段

```c
typedef struct wwww{int x:8,y:24;} W; W ac;
printf("%d\n",sizeof ac);//int有32位，两int以char,1.5short的方式共用该内存，总4B
```

##### 赋值

```c
结构变量.成员 = 值；
结构变量1 = 结构变量2
```

> 如果成员是指针，结果是获得的指针指向同一个内存

由于该性质，可以用一般的swap方法交换结构体(t=a;a=b;b=t;)

> 结构体的size一般取整块乘，如int i,char c, float a得12。

##### 结构体数组

###### 初始化

```c
结构简名(或 struct 结构名) 变量名[] = {{这里按成员顺序依次输入即可}, {}...};//如果出现嵌套，多几个大括号咯
```

只能在初始化时使用

##### 结构体指针

###### 指向

```c
结构简名(或 struct 结构名)* 指针名 = &结构体变量;
```

###### 调用

```c
非指针.成员名
指针->成员名 
或 (*指针).成员名
//出现嵌套时，只需要在自己指向那个这么做，其他如常
指针->成员名1(该成员不是指针).成员名2
```

###### 结构体数组指针

```c
(指针+i)->成员名 或 (*(指针+i)).x
```

##### 函数参数

可以传地址，传成员或传整个结构体（作为形参）

当然也可以传结构体数组

> 从效率而言，用结构体指针更好

同样，可以返回一个结构体

##### 位域

只有bool,int,char,enum可以被定义位域；union没必要定义位域。定义方法：

```c++
数据类型 成员属性名 : 二进制位数
```

表明该成员属性只占据多少个二进制位。

> 不同编译器处理方法不同。

##### 备注

1. 结构体变量的所占内存字节数不一定等于成员之和，往往大于。
2. 对于char x,y;int a;大小为2int，而char x;int a;char y;大小为3int。
3. 声明不能包含其本身，但是可以包含指向其本身的指针
4. 存储区是连续的

#### 共用体

又称联合

定义：

```c
union 名称{成员定义};
//同结构体，可以使用typedef的简写
```

初始化：

```c
共用体名 变量名 {.成员名=值};//只能赋值一个成员
```

##### 备注

1. 共用体占内存空间大小取决于成员中占内存空间最多的那个成员变量
2. C89只能初始化首个成员，C99无限制
3. 不能参与比较，不能作为函数参数
4. 常应用于int与double混合

#### 枚举

定义：

```c
enum 枚举标签{名, 名2, ...}; //默认名值为0，名2为1...
enum 枚举标签{名, 名2, ...} 变量名; 
enum {名, 名2, ...} 变量名; //下面就不举例这两种了
enum 枚举标签{名=值1, 名2, ...} ; //从值1开始递增
enum 枚举标签{名=值1, 名2=值2, ...} ;//自定义
enum 枚举标签{名, ... 名n=值1, ...};//名n前从0开始
```

使用：

```c
a=xxx;//xxx是名 ,a为常量
b=(enuma.xxx)2;//转为枚举型，必须强转
```

1. 不能对枚举内的名在定义后再赋值(视为const)

使用enum变量示例如下：

```c++
enum z { X = 3, Y, Z = 0, W, K, A, B };
z a = X; //或enum z a = X
cout << a;
a = (z)4;
a = Z;
cout << a;
```

#### 指针

##### 定义

数据类型* 变量名 = 地址 ；如 int *pt = &a;

​	意思是把某变量1的地址存放在该指针中

定义指针一定要初始化，如果没有明确的对象，指向NULL

只有void类型指针可以指向任意变量(用于指定前不知道数据类型的情况)。

##### 指向

对一般一维数组，

```c
p代表&a[0],p+i代表&a[i],*p代表a[0],*(p+i)代表a[i]
```

对于列举数组元素的四种方法：

```c
a[i] *(p+i)  *p(另有p++)  p[i](另有p++)
```

第二种方法效率最高

同样，在函数中，也这有四种调用方法

其中，对应第二、第四种方法，传入指针变量，其余传入数组



对二维数组

```c
记a[行][列]
```

则行地址为：&a[i]或a+i, *(p+i)

列地址为：a[i]+j  *(a[i] + j) 

这两个在用数组本身和行指针均异常，列指针报错：列值:

```c
*(*(a+i)+j)   (*(a+i))[j]
```

定义行指针： 

```c
类型 (*p)[第二维长] = array 或 &array[0];//不加括号是指针数组
```

使用行指针调用二维数组跟二维数组本身一致

定义列指针： 

```c
类型*p = *array 或array[0]或&array[0][0];
```

使用列指针调用二维数组跟使用普通指针一致

```c
*(p+i*列数+j)或p[i*列数+j]
```

对于char数组，若 char *ptr = str,则：

$*ptr 代表 str[0]， 所以可以 *ptr ='a'$



此外，常常使用指针数组对char数组一一对应，由于对指针本身进行排序操作比较节省机器算力，一般会通过排序指针间接排序char数组（往往是非常大的），即以索引排序代替物理排序，提高效率



##### 运算

```c
a代表指针，*a代表内容
使用*号，例如 *a = *a + 1;
    又如 (*a)++; 值加一
取指针当前值，然后指针移位；*a++;
```

##### 指针移位

指针变量+（-）int，表示移位的多少，可以增一减一运算

```c
int sum(int* a, int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i];
    return ans;
}
int main()
{
	int a[] = {1,2,3,4};
    printf("%d\n", sum(a+1, 3));//移了一位
    return 0;
}
```

##### 指针运算

```c
int n = x - y;//x,y是同一数组的两个指针
//取到的数组等效于python的array[x:y]
//也就是取左闭右开区间[x,y)
```

##### 指针类型强转

```c
int cmp(const void *a, const void *b)
    return *(int*)a - *(int*)b;
//其中的(int*)表示强转万能指针a为int指针a
```

##### 函数指针

格式：返回值类型 (* 指针名)(函数的参数类型及其参数名字)

例如：void f(int n, int (*compare)(int a, int b));

int g(int a, int b);

使用时：g(3, f);

对应的调用函数是：if( (*compare)(x,y)  && i)

可以不写参数：

```c
#include <stdio.h>
int fx(int x)
{
    return x*x;
}
int add(int x, int y)
{
    return x*y;
}
int h(int (*f)(), int a, int b)
{
    return f(a,b);
}
signed main()
{
    int (*g)();
    g=fx;
    printf("%d\n",g(5));
    printf("%d",h(add,5,-1));
    return 0;
}
```

##### const

const数据只能由前导const指针指向。

###### const 类型 *p 或 类型 const *p

p是指针变量，指向常量(*p常量，p变量)

意思是不能通过p修改p指向的内存的值；但被指变量本身可以被修改(如果没有const限定)；p可以重新指向别的变量。

###### 类型* const p

p常量，*p变量

意思是不能让p在初始化之后再重新指向别的值，但可以通过p修改值

###### const 类型* const p

p常量，*p常量

> 加多很多个const也一样

##### 指针数组

```c
指针数组 int *p[3];
指向二维数组的指针(第二维为3) int (*p)[3];//即列指针
```

举例：

```c
int (*p)[3], *q[3];
printf("%d %d\n", sizeof p, sizeof q);
int x[][3]={4,5,6,7,8,9};
p=x;
printf("%d ",p[0][1]);
int w=-1;
q[2]=&w;
printf("%d",*q[2]);
```

##### 使用举例

1.变量交换

```c
void swap(int* a, int* b)
{
    int t = *a; *a = *b; *b = t;
}
int main()
{
    int a = 3, b = 4;
    swap(&a, &b);
    return 0;
}

//c++版本：强制传址
void swap2(int& a, int& b)
{
    int t = a; a = b; b = t;
}
```

2.函数返回多个参数

```c
void f(int a, int*b, int*c)
{
    *b = a+1;
    *c = a*a;
}
//...
f(3, &x, &y);
```

3.函数指针简化升降序

```c
void SelectionSort(int a[], int n, int (*compare)(int a, int b))
{
    //...
    if((*compare)(a[j], a[j+1])) x+=1;
}
int Ascending(int a, int b)
{
    return a<b;
}
int Descending(int a, int b)
{
    return a>b;
}  
SelectionSort(matrix, 15, Ascending);
SelectionSort(matrix, 15, Descending);
```

4.返回在子函数建立的临时值，如scanf的值，返回一个字符指针，这个指针p通过strcpy(p, str)获取实际值。

##### 补充

- 什么二级指针，函数指针数组之类的东西，C++PP那本书有，感觉没多大实际作用就不细看了，第七章p264这样(一说p247)

#### 动态数组

C程序将使用4块内存储区，从低端开始，第一块为只读内存区，存放机器代码、字符串字面量等只读数据；第二块是静态存储区，存放全局变量和静态变量；其余是动态存储区，下方的堆(heap)调用动态内存分配函数分配，上方的栈(zhan4)(stack)存放局部变量，函数形参，返回数据等，最顶层是命令行参数(不在动态存储区)

栈分配效率很高，容量有限，可能栈溢出、



使用<stdlib.h>

申请动态内存：（以int为例）

```c
int *pi = NULL;
pi = (int *)malloc(n*sizeof(int))
    //或(int *)calloc(10, sizeof(int))
    //一般使用calloc，因为还能初始化为0
    //虽然即便如此一般来说也需要memset一下
if(pi == NULL)//分配失败
    exit(1);
```

修改动态内存：

```c
realloc(pi, n*sizeof(int));
```

释放内存：

```c
free(pi);
//释放完一般手动设置为NULL
```

```c
//多个动态数组申请和释放的模板：
p1 = (int *)calloc(64, sizeof(int))
if(p1==NULL) goto EXIT;//或者一个布尔值或return（子函数的话），但下面的代码还会执行，还是这样好
//p2,p3……同理
EXIT:
if(p1!=NULL) free(p1);
//p2,p3……同理，注意不是else if
```

如果是二维动态数组：

```c
int *pi = (int *)calloc(m*n, sizeof(int));//获得列指针
int (*p2)[5] = (int (*)[5])calloc(3*5,sizeof(int));//行指针
//5*3也行，15也行，都一样
```

### 优先级与结合性

|      |               运算符                |                             含义                             |   运算类型   | 结合方向 |
| :--: | :---------------------------------: | :----------------------------------------------------------: | :----------: | :------: |
|  1   |             ()[]->.++--             | 圆括号、函数参数表；数组元素下标；指向结构体成员；引用结构体成员；后缀增1，减1 |              | 自左向右 |
|  2   | ! ~ ++ -- - * & (类型标识符) sizeof | 逻辑非；按位取反；前缀增1，减1；取负；间接寻址运算符；取地址运算符；强制类型转换运算符；计算字节数运算符 |   单目运算   | 自右向左 |
|  3   |                * / %                |                       乘，除，整数求余                       | 双目算术运算 | 自左向右 |
|  4   |                 + -                 |                            加，减                            | 双目算术运算 | 自左向右 |
|  5   |                << >>                |                          左移，右移                          |    位运算    | 自左向右 |
|  6   |              < <= > >=              |                小于，小于等于，大于，大于等于                |   关系运算   | 自左向右 |
|  7   |               ==  !=                |                         等于、不等于                         |   关系运算   | 自左向右 |
|  8   |                  &                  |                            按位与                            |    位运算    | 自左向右 |
|  9   |                  ^                  |                           按位异或                           |    位运算    | 自左向右 |
|  10  |                 \|                  |                            按位或                            |    位运算    | 自左向右 |
|  11  |                 &&                  |                            逻辑与                            |   逻辑运算   | 自左向右 |
|  12  |                \|\|                 |                            逻辑或                            |   逻辑运算   | 自左向右 |
|  13  |                 ?:                  |                          条件运算符                          |   三目运算   | 自右向左 |
|  14  | = += -= *= /= %= &= ^= \|= <<= >>=  |                 赋值运算符；复合的赋值运算符                 |   双目运算   | 自右向左 |
|  15  |                  ,                  |                          逗号运算符                          | 顺序求值运算 | 自左向右 |

备注：

1. 第二优先级里，增1减1的优先级高于其他的，例如：-n++是先增后取负。
2. 逗号表达式返回最右边的值，如x=(2,3);得到3

举例1：这样的代码是合法的。

```c
int x=3, y=x+1;
```

举例2：从右往左，例如下面输出3,2,1

``````C
int i=1;
printf("%d %d %d", i++, i++, i++);
``````

举例3:

```c
int x[5] = {10,20,30,40,50};
int *pt = x;//下面两行代码含义不同
++*pt;//值增
*++pt;//指针移位
```

右结合即从右向左，例如?:?:则右边是内层，左边是外层，相当于右边加了括号，先考虑右边，故称作右结合，左结合同理。

### 常规运算

#### 数据类型转换

从低到高为：

```c
char  short  int  unsigned  long  unsigned long  float  double
```

混合转换方法：

- 有long double 转为long double
- 否则，如果有一个double/float 转double/float
- 否则，有unsigned long ，转unsigned long
- 若一个long，一个unsigned int,也转unsigned long
- 否则，有long/unsigned int转long/unsigned long
- 否则转int

向上类型转换，对于正负数的位补足机制不同，分别为符号拓展(补1)和零拓展。

#### 加

接近溢出时可以如下做加法：a+b写成a+(b-a)

```c
(l+r)/2  ->  l+(r-l)/2
```

#### 乘

多个相乘除，交替乘除来避免数据溢出

#### 除

/  整数对整数整除，支持负数(直接数学理解即可，

​	例如-2/3=0,-6/2=-3,-6/-3=2)

​	任意一个是浮点，先把另一个转化为浮点，后返回浮点结果

注意0/负数=-0，在输出时可能会导致不符合题意//python也是

处理：当然是特判了

##### 上取整

c=(a+b-1)/b;*//实现了a除以b结果上取整。*
$$
c=\frac{a+b-1}b=\frac{a-1}b+1
$$
直接套公式即可。(也可以用ceil)

#### 取模

只能是两个整型(signed)(负数意义下直接理解即可)

#### 自增

理论说是前缀比后缀快，但是我的调试好像反了。

#### 赋值

```c
int a; a=1;
int a = 1;
a = b = 3;
(c  = getchar()) != EOF;
a[x=0][y=n-1] = 1;
a[++x][y] = ++total;
```

```c
//赋值的连等性：
int a=1,b=100,c=10000;
a+=b+=c;//等效于a+=(b+c),b+=c 即先b+=c,再a+=b
```

#### 示例/模板

##### 一奇一偶判定

```c
(bool)((a+b)%2)
```

### 逻辑运算

逻辑运算符是短路运算符（整体的值确定后，后面不再计算,其实python也是）

例如&&得到假后，||得到真后



对0或0.0使用非运算符(!)得到1,对非零实数使用得到0



如果a>b>c，执行顺序是(a>b) >c,前者是0或1，其他连续判断同理



==判断强烈建议把常量写在左边！



### 位运算

对象：char和int,不能是float等

#### 按位与 &

均1得1

应用：

- 可以用于清零某些位
- %2计算可以使用&1计算，加快速度
- 测试x对应于y的值是否为1，用if(x&y)
- 一个char与31进行运算，得到在字母表里的顺序(从1开始)，如'a'&31=1, 'Z'&31=26

#### 按位或 |

有1得1

应用：

- 可以执行加1操作，如树的左右子节点为：

  ```c++
  p<<1;   p<<1|1;
  ```

- 

#### 按位异或 ^

10得1，可以认为是不进位的加法

异或满足交换律、结合律、消去律，有单位元$0$，自己与自己运算得单位元

应用：

①

由于

```python
bin(ord('0')) = '0b110000'
bin(ord('9')) = '0b111001'
```

故，将isdigit==1的char c转为ascii对应的int c，即int(c)#python，可以这么做：int k = c ^ '0';

做法二是&15即可。

因此可以构造函数从str转int。

②布尔值取反，使用：

```c
x ^= 1;
```

③汉明码

#### 按位取反 ~

反转01

应用：

可以用于加密

可以对布尔值取反

#### 左移位 <<

x<<n

位足够时，n=1等同于扩大一倍

特别注意，位运算时如果知道位是long long的，应当LL，如1LL<<60

应用：

1. #define INFTY (1<<30)

#### 右移位 >>

对于正数，n=1等同于x/2（python的int(x/2)），所以二分法可以：l+r>>1

对于负数，等同于round(x/2.0)，负数的移位结果不会大于-1

应用：

1. 如果要取一个(正)数x的第i-1位，可以使用(x>>i)&1

#### 内建函数

**1.__builtin_popcount(unsigned int n)**

该函数时判断n的二进制中有多少个1

```c
int n = 15; //二进制为1111
cout<<__builtin_popcount(n)<<endl;//输出4
```

**2.__builtin_parity(unsigned int n)**
该函数是判断n的二进制中1的个数的奇偶性

```c
int n = 15;//二进制为1111
int m = 7;//111
cout<<__builtin_parity(n)<<endl;//偶数个，输出0
cout<<__builtin_parity(m)<<endl;//奇数个，输出1
```

**3.__builtin_ffs(unsigned int n)**
该函数判断n的二进制末尾最后一个1的位置，从一开始

```c
int n = 1;//1
int m = 8;//1000
cout<<__builtin_ffs(n)<<endl;//输出1
cout<<__builtin_ffs(m)<<endl;//输出4
```

**4.__builtin_ctz(unsigned int n)**
该函数判断n的二进制末尾后面0的个数，当n为0时，和n的类型有关

```c
int n = 1;//1
int m = 8;//1000
cout<<__builtin_ctzll(n)<<endl;//输出0
cout<<__builtin_ctz(m)<<endl;//输出3
```

**5. __builtin_clz (unsigned int x)**
返回前导的0的个数。

```c++
int n = 1;	//1
int m = 8;	//1000
cout<< 32 - __builtin_clz(n) <<endl;	//输出1
cout<< 64 - __builtin_clzll(m) <<endl;	//输出4
```

### 宏

注意：

- 宏定义后面可以加注释，两种格式均可，不会被宏代替

#### define系

见运算-变量常量和条件判断

##### 常见的简写用法

```c
#define loop(i,a,b) for(register int i=(a);i<(b);i++)
typedef long long ll;//不可以#define long long ll
```

###### 拓展

```c++
#define up(a,b,c) for (int a(b),a##end(c);a<=a##end;++a)
#define down(a,c,b) for (int a(b),a##end(c);a>=a##end;--a)
#define uup(a,c,b) for (int a(b),a##end(c);a<=a##end;++a)
#define udown(a,b,c) for (int a(b),a##end(c);a>=a##end;--a)
#define endl '\n'
#define debug(...) fprintf(stderr,__VA_ARGS__)
```

##### 区分typedef

typedef可以前面多个内容空格隔开，最后一个内容是简写：

```c
typedef long long ll;
typedef struct a{...} A;
```

define是一个内容代替多个：

```c
#define int long long
```

##### 加括号警告

> 内联函数+传引用更爽，如果不需要多类型重载

```c++
#define dis(x) (abs((m)-(x)))/*注意m和x的括号*/
```

补充：

1. define不受大括号影响，例如：

   ```c
   if(0)
   {
       #define PI 55
   }
   printf("%d",PI);//可以运行
   ```

2. define的作用域是从define开始到undef(如果有)或文档尾(无undef)，用法如：#undef PI

3. 宏函数函数名和参数列表间不要加空格，如：

   ```c
   #define rep(i,a,b)  for(ll i=a;i<b; ++i) //正确
   #define rep (i,a,b) for(ll i=a;i<b; ++i) //错误
   ```

4. 数字开头和符号不能作为宏名，如全角括号。

   ```c++
   #define （ ( //错误
   #define abc ( //正确
   #define , abc //错误
   #define a! xxx //warning
   #define 1 2 //错误
   #define 1ab 2//错误
   #define (gg 3 //错误
   ```

   

#### include系

略

#### if系

见define系和C-知识网络 - 条件判断

#### 报错

##### error

抛出错误

```c
#error OH NO!
```

##### warning

同理

#### pragma

##### message

在编译器输出一条注释：

```c++
#pragma message("Hello world!")
```

##### 屏蔽警告

```c++
#pragma warning(disable:4996)//屏蔽一条
#pragma warning(disable:4996 6031)//屏蔽多条
```

##### GCC

如下是一些用于加速的头文件

```c++
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
```

> ```c++
> #define fastcall __attribute__((optimize("-O3")))//如果O0表示无任何优化，常用于学习编译原理
> #pragma GCC optimize(2)
> #pragma GCC optimize(3)
> #pragma GCC optimize("Ofast")
> #pragma GCC optimize("inline")
> #pragma GCC optimize("-fgcse")
> #pragma GCC optimize("-fgcse-lm")
> #pragma GCC optimize("-fipa-sra")
> #pragma GCC optimize("-ftree-pre")
> #pragma GCC optimize("-ftree-vrp")
> #pragma GCC optimize("-fpeephole2")
> #pragma GCC optimize("-ffast-math")
> #pragma GCC optimize("-fsched-spec")
> #pragma GCC optimize("unroll-loops")
> #pragma GCC optimize("-falign-jumps")
> #pragma GCC optimize("-falign-loops")
> #pragma GCC optimize("-falign-labels")
> #pragma GCC optimize("-fdevirtualize")
> #pragma GCC optimize("-fcaller-saves")
> #pragma GCC optimize("-fcrossjumping")
> #pragma GCC optimize("-fthread-jumps")
> #pragma GCC optimize("-funroll-loops")
> #pragma GCC optimize("-freorder-blocks")
> #pragma GCC optimize("-fschedule-insns")
> #pragma GCC optimize("inline-functions")
> #pragma GCC optimize("-ftree-tail-merge")
> #pragma GCC optimize("-fschedule-insns2")
> #pragma GCC optimize("-fstrict-aliasing")
> #pragma GCC optimize("-falign-functions")
> #pragma GCC optimize("-fcse-follow-jumps")
> #pragma GCC optimize("-fsched-interblock")
> #pragma GCC optimize("-fpartial-inlining")
> #pragma GCC optimize("no-stack-protector")
> #pragma GCC optimize("-freorder-functions")
> #pragma GCC optimize("-findirect-inlining")
> #pragma GCC optimize("-fhoist-adjacent-loads")
> #pragma GCC optimize("-frerun-cse-after-loop")
> #pragma GCC optimize("inline-small-functions")
> #pragma GCC optimize("-finline-small-functions")
> #pragma GCC optimize("-ftree-switch-conversion")
> #pragma GCC optimize("-foptimize-sibling-calls")
> #pragma GCC optimize("-fexpensive-optimizations")
> #pragma GCC optimize("inline-functions-called-once")
> #pragma GCC optimize("-fdelete-null-pointer-checks")
> 
> #pragma GCC optimize(3)
> #pragma GCC target("avx")
> #pragma GCC optimize("Ofast")
> #pragma GCC optimize("inline")
> #pragma GCC optimize("-fgcse")
> #pragma GCC optimize("-fgcse-lm")
> #pragma GCC optimize("-fipa-sra")
> #pragma GCC optimize("-ftree-pre")
> #pragma GCC optimize("-ftree-vrp")
> #pragma GCC optimize("-fpeephole2")
> #pragma GCC optimize("-ffast-math")
> #pragma GCC optimize("-fsched-spec")
> #pragma GCC optimize("unroll-loops")
> #pragma GCC optimize("-falign-jumps")
> #pragma GCC optimize("-falign-loops")
> #pragma GCC optimize("-falign-labels")
> #pragma GCC optimize("-fdevirtualize")
> #pragma GCC optimize("-fcaller-saves")
> #pragma GCC optimize("-fcrossjumping")
> #pragma GCC optimize("-fthread-jumps")
> #pragma GCC optimize("-funroll-loops")
> #pragma GCC optimize("-fwhole-program")
> #pragma GCC optimize("-freorder-blocks")
> #pragma GCC optimize("-fschedule-insns")
> #pragma GCC optimize("inline-functions")
> #pragma GCC optimize("-ftree-tail-merge")
> #pragma GCC optimize("-fschedule-insns2")
> #pragma GCC optimize("-fstrict-aliasing")
> #pragma GCC optimize("-fstrict-overflow")
> #pragma GCC optimize("-falign-functions")
> #pragma GCC optimize("-fcse-skip-blocks")
> #pragma GCC optimize("-fcse-follow-jumps")
> #pragma GCC optimize("-fsched-interblock")
> #pragma GCC optimize("-fpartial-inlining")
> #pragma GCC optimize("no-stack-protector")
> #pragma GCC optimize("-freorder-functions")
> #pragma GCC optimize("-findirect-inlining")
> #pragma GCC optimize("-fhoist-adjacent-loads")
> #pragma GCC optimize("-frerun-cse-after-loop")
> #pragma GCC optimize("inline-small-functions")
> #pragma GCC optimize("-finline-small-functions")
> #pragma GCC optimize("-ftree-switch-conversion")
> #pragma GCC optimize("-foptimize-sibling-calls")
> #pragma GCC optimize("-fexpensive-optimizations")
> #pragma GCC optimize("-funsafe-loop-optimizations")
> #pragma GCC optimize("inline-functions-called-once")
> #pragma GCC optimize("-fdelete-null-pointer-checks")
> ```

## 输入和输出

### Standard IO

均位于stdio.h

#### printf

printf("字符串内容", 可变变量(0个或以上)，对应每个占位符)

返回值：如果成功，则返回写入的字符总数(含\n)，否则返回一个负数。



提示：不像python结尾自动有\n，需要自己补充

常用模板：

```c
/*1.首次输出与其余不同*/
int first=1;
if(first) first=0; else printf("xxx");
printf("yyy");
//循环后：printf("tail\n");
```

#### scanf

scanf("占位符", 1个或以上变量(一般取地址，例如&a，数组不取))

返回值：如果成功，该函数返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF。

不读走最后的回车，也不从输入缓冲区弄走

常用格式：

```c
//读取和存储所有数据，以空格分开
int a[MAXN];//可能在main之外
int x,n=0;
while(scanf("%d", &x) == 1)
    a[n++] = x;
```

```c
//读取和操作单串字符串 - 方法1 
char c[LEN]；
scanf("%s", c);
for(int i=0;i<strlen(c);i++)//(需要string.h)
    //操作
```

常见细节：

- %d读入-0跟读入0是等效的
- %d会处理掉任意多个前导0

##### 连续输入常用模版

以A+B问题问题

1.连续输入多对，每行一对

```c
int a,b;
    while(scanf("%d%d", &a, &b) != EOF)//cb ctrl+c退出,vs ctrl+z+回车
        printf("%d\n", a + b);
```

> 如果要数组统计个数：

```c++
while(EOF!=scanf("%d",&a[n++])); n--;//EOF那次也n++了
```

2.在1.的基础上，首行是连续输入的次数

```c
int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)//如果t不用，也可以while(t--)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
```

3.在1.的基础上，输入0 0表示结束

```c
int a,b;
    while(1)
    {
        scanf("%d%d", &a, &b);
        if(a==0 && b==0) break;
        printf("%d\n", a + b);
    }
```

##### 错误输入处理

不重输：

```c
//模版1：
if( 2 != scanf("%d%d", &a, &b) )
{
    printf("Error!\n");
    fflush(stdin);
    //return ???
}
```

重输数字数据：

```c
//模版1：
ret = scanf("%d", &x);
while(1 != ret)
{
    while(getchar() != '\n');//清楚输入缓冲区非法字符
    printf("You wrong!\n");
    ret = scanf("%d", &x);
}
```

#### getchar

等同于fgetc(stdin),读取一个字符

使用举例：

```c
int readchar()//读非换行字符
    for(;;)
    {
        int ch = getchar();
        if(ch != 10 && ch != 13) return ch;//\n,\r
    }
```

遇过遇到EOF，返回-1

#### putchar

输出一个字符

#### getch

大同getchar，但无须等到按回车，按一下响应一下

返回输入的值的ASCII，出错返回-1，不会在屏幕回显它

不过在<conio.h>

#### gets

C11被正式删除，不推荐使用

参数是s，不指明最大字符数，类似于python的input

最后的回车会从输入缓冲区读走，不作为字符串的一部分

#### puts

输出字符串，并自带回车；类似于python的print

C++下不能通过OJ编译。

可以使用：while(puts(var))，因其返回值为str指针或NULL(未读取成功)下fgets同。

#### fgets式

格式为fgets(char数组, 读取长度, stdin)//fgetc同理

近似于gets

注意：输出的后尾在该电脑调试为\b\0，也就是实际长度加了一，理应当len=strlen(var)-1；部分OJ可能没有\b，切记注意

可以通过如下过程清理：sscanf(p,"%s", p);

#### sprintf

给字符串用的

sprintf(char数组, 后同printf)

#### 注意

%s读入不含空格、tab、回车的字符串，存入字符数组s

Windows下，输入完毕后按Enter，后按Ctrl+Z，最后按Enter结束输入；Linux按Ctrl+D

回车换行符：Windows:\r 和\n，Linux是\n，MacOS是\r

Windows下读Windows文件，fgetc,getchar会吃掉\r只剩下\n，但在Linux系统读该文件，不会如此

在VS使用scanf，必须有以下代码之一：(当然也可以直接关了SDL)

```c++
#pragma warning(disable:4996)
#pragma warning(disable:4996 6031)//返回值也不理
//#pragma warning(disable:4996 6031 6066 4477)//longlong也不理//???
```

### 重定向

<stdio.h>

freopen(运行路径文件完整名(a.txt), "r", stdin);

freopen(运行路径文件完整名, "w", stdout);

此后printf和scanf将使用文件

dos命令提示符，可以用<输入重定向,>输出

如f.exe < in.txt

f.exe > out.txt

可以关闭文件：

```c
fclose(stdin);
fclose(stdout);
```

宏定义简写：

```c
#define Open(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define Close fclose(stdin);fclose(stdout);
```

### 文件

文件分两种：文本文件(ASCII码文件)，二进制文件。

二进制文件把整个数字作为二进制值存储。

EOF等于-1,在stdio.h定义

```c
FILE *fin, *fout;//定义文件指针
fin = fopen("data.in", "rb");
//如果失败返回空指针NULL
fout = fopen("data.out", "wb");
fscanf(fin, "...", (&)var);
fprintf(fout, "...");
fclose(fin);
fclose(fout);
```

打开方式有：

- r 必须已经存在
- w 无论是否存在
- a 无论是否存在
- +与上述组合，表示读写，如a+
- b 与上述组合，表示二进制

```c
fgetc(fin); //从fin读取一个字符，返回读到的单个字符
```

```c
fgets(buf, maxn, fin); //buf是字符数组
```

```c
fputc(ch, fp);
fputs(str, fp);
```

```c
//按数据块读写文件
fread(buf, size, count, fp);
//返回实际读取的数据块个数

fwrite(buf, size, count, fp);
//buf是待输出数据块起始地址
//size是每个数据块大小
//count是最多允许写入的数据块个数
//返回实际写入的数据块个数

//可以读写整个数组乃至结构体数组
```

```c
//随机访问
fseek(fp, offset, fwe);
//offset常量数据加L，正前负后移动（使得大于64kb的文件无问题）
//fwe为SEEK_SET/0,SEEK_CUR/1,SEEK_END/2，代表文件起始，当前和文件结束；
//调用成功返回0
rewind(fp);//重置指针
ftell(fp);//相对SEEK_SET返回当前位置
fflush(fp);//无条件把缓冲区所有数据写入物理设备
//stdin,stdout,stderr代表标准输入，标准输出，标准错误输出，可以填入fp
```

模板：

```c
//纯读：
while( (ch=fgetc(fp)) != EOF) putchar(ch);
```

```c
feof(fp)//检查是否到达文件尾部，指向EOF返回非0，否则0
//读完所有内容再进行读文件操作时才会返回真
//可以是
ch=fgetc(fp);
while(!feof(fp)){putchar(ch);ch=fgetc(fp);}
```

### 占位符

默认表示是print的用法，部分scanf也能用

#### 类型

%% %本身，即使无占位符和可变参数，也要这样才能输出%

%d 带符号(省略正号)十进制整数

​	如果是%D，只会输出单个D，%O,%U,%P同理

​	下面%F,%S则什么也不输出

%u 无符号十进制整数

%o 无符号八进制整数，不输出前导符0

%x(%X) 无符号十六进制输出，不输出前导0x

%c 一个字符(%C也行)

%s 字符串

%f 默认六位

%e(%E) 指数形式 会有0占位

#g(%G) 以f或e中宽度较小的一种使用，且不输出无意义的0

%p 地址（对应&var）

#### 格式

%03d

%3d 右对齐（空格填在左边），如果超过了数字范围不生效

​	%-3d 左对齐

​    *居中有待补充*

%.f 整数(四舍五入) =%.0lf

%.3f 小数点后三位小数(四舍五入)

上述数字可以用*代替，数字占多一个占位符，例如：

``````C
 printf("%.*f", 2, 0.6666);
``````

l 修饰 d,o,x,u输出long，如ld

ll 修饰long long  或者说%I64d(是i的大写)具体如下：

- 强烈推荐使用C++输入输出，在C时注意点如下：
- Linux系统下%lld
- Windows下的MinGW的gcc是%I64d，VC2008是%lld

unsigned long long也使用%lld输出！

L 修饰f,e,g输出long double

h 修饰short，如hd

#### scanf的用法

1. 连续多个占位符，默认中间是任意多个空白字符(空格、制表和换行)
2. 非占位符的普通内容表示严格按照这样的输入
3. *表示任意可忽略内容(搭配使用，如 %\*c)
4. 可以用长度占位：
5. %c可以读取空格和回车等转义符，连续输入时规避方法如下：
   1. 在%c前加一个空格(或\n或*)
   2. 在下一次scanf前getchar一次
   3. 如果不是连续的输入流，还可以fflush(stdin)

#### 其他

C99中，double输出必须用%f，输入用%lf

C89和C++输入输出都可以用%lf

直接用C++编译(.cpp而不是.c)对应后者



long long的输入用%lld,但在MinGW的gcc，用%I64d,

VC2008用%lld

常用C++的输入输出流或自定义输入输出方法



### 转义符

``````c
/*
\\代表\本身,一般都要这样输出的
\n 换行
\r 回车不换行 如：23\r=23;23\r1=13
\0 空字符
\t 水平制表
\v 垂直制表(输出一个奇怪的字符)
\b 退格 退格后会覆盖掉前一格的字符 显示结果如23\b=23;23\b4=24
\f 走纸换页(输出一个上箭头)
\a 响铃提示声(例如win10的噔噔咚)
\"
\'
\?
\ddd 1到3位八进制，d代表数字如\027 \101=65='A'  \065=53='5'
	范围是000~377，超过该范围不能显示，但strlen在000~777仍在1长，
	在0+两个任意字符也算1长，非0+0~7外的字符算3长，
	两个0~7内+一个0~7算2长 超出3位超出部分都算单长
\xhh 1到2位十六进制，如\xFF \xab \x+非十六进制报错
	\x+十六进制+非十六进制算2长 \x+任意长十六进制算1长
\u 1到4个十六进制，表示unicode //da tr is hs
*/
//注意不要随便转义，如\1，转义的结果往往很迷幻，如\065=5,\65=5
``````

取消转义：

```c
使用：R"+*(   )+*"，那么将输出括号里边的，如：
R"+*(""" """ """ """ a)+*" → """ """ """ """ a
```

## 条件判断

### if

格式：if(条件) {代码块/语句块(block of statements)}或单行代码，下同(花括号 curly brace)

(else if(条件) {代码块})

(else {代码块})

### ?:

a?b:c 是 if(a) b else c

### #if

> 所有的#if系列都有#elif和#else(#ifdef系无#elif)

```c++
//永假判断：
#if 0
	printf("3");
#endif
```

#### #ifdef

```c
#ifdef 常量名
	//代码(块)
#endif
```

等同于：

```c
#if defined(标识符)
//..
#endif
```

应用：写头文件时预防重定义报错：

```c
//head.h
#ifndef HEAD_H
#define HEAD_H
//头文件里面的内容
#endif
```



#### #ifndef

同理，并且有等效表达式，举例如下：

```c++
#if!defined(gg)
#pragma message("12334")
#endif
```

### switch

switch(表达式或变量)

{

case 常量1:

语句1;break;

case 常量2:

……

default:

语句n;

}

注意：

1. 常量也可以是运算结果
2. default可以没有
3. case的本质就是goto，所以如果末尾没有break会一直执行直到结尾
4. 内部不需要代码块，无论多少行代码
5. 可以多个case一起：case 1:case 2:case 3:语句;
6. 一般将出现频率高的放在最前面
7. 只能用整型量在case
8. case 的值不能是变量，const也不行，define可以

### goto

goto xpos;

xpos:

常用于：

- 快速跳出多重循环
- 跳去共同的出口，处理错误情况

## 循环

### for

格式：for(初始化; 执行条件; 调整){代码块}

``````c
for(int i=1;i<=n;i++)
    printf("%d\n", i);
``````

变量如果在初始化处定义，for外查无此变量

分号内部条件多样，用逗号分开

​	但是条件处不是这样的

任何一块可以留空，而for(;;)是死循环，除非有break;

用于延时：for(int i=1;i<50000000;i++){;}

### while

while(执行条件){循环体}

### do-while

do{循环体}while(执行条件);  

## 函数

定义：返回值类型 函数名(参数类型 参数名)

①在main前就定义完整

②main前复刻一个定义+;(参数名可以不要)，后完整定义

注意要点：

1. 显然在函数内局部数组在函数结束后内存被释放，所以不能由函数外的指针指向后在函数外继续调用。
2. 从右往左执行

### 参数

#### 一般参数

对于数组而言，除(从左到右)第一维外，其他维度必须跟参数列表内一致，如：

```c++
void f(int a[3][3])//可以写成 a[][3]或(*a)[3]，不可以*a[3]
{
    cout<<a[1][1]<<endl;
}
void g(int a[3]) //可以写成a[]或*a
{
    cout<<a[1]<<endl;
}
void h(int a[2][3][4]) //可以写成a[][3][4]或(*a)[3][4]
{
    cout<<a[1][1][1]<<endl;
}
int b[5][3],d[100],e[5][3][4];
b[1][1]=0x7fffffff;
f(b);
d[1]=-0x7fffffff;
g(d);
e[1][1][1]=-1;
h(e);
```

#### 传址与传值

传值(形式参数)的有：结构体

传址(实际参数)的有：数组

> 实参可以是常量、变量或表达式等任意类型
>
> 如果形参和实参的类型不一致,以形参类型为准
>
> 形参是虚拟的，不占用存储单元；函数形参可以说明为register 变量

#### 默认参数

伪实现方法，注意，define的f1,f2及原f必须相互区分，不能写成f,f

```c
#define f1(x) f(x, 3)
#define f2() f1(4)
int f(int a, int b)
{
    return a+b;
}
int main()
{
    printf("%d %d %d\n", f2(), f1(1), f(1,1));
    return 0;
}
```

#### 可变参数

应用举例：

```c
#include <stdio.h>
#include <stdarg.h>//支持可变参数的标准库
double average(int num, ...)//...代表可变参数接收
{
    va_list x;//存储可变变量的数组
    double sum = 0.;
    va_start(x, num);//声明长度
    for(int i = 0; i < num; i++)
        sum += va_arg(x, int);//获取下一个
    va_end(x);//表示结束
    return sum/num;
}
int main()
{
    printf("%.2f\n", average(3, 3, 3, 4));//3.33
    return 0;
}
```

理论上，可以用可变参数的方法实现默认参数（默认参数放在后面）//dack

### 返回值

可以是数组外的一切东西

#### 默认返回值

若调用一个非void函数，且此函数中没有return语句，返回一个不确定的值

[int:1

### 递归

每个迭代原则上都可以转化为递归，反之不然（如汉诺塔）

但为了提高效率，尽量用迭代替代递归



允许main函数递归自己

### main

#### 命令行参数

是对main函数而言的，需要使用的话：

```c
int main(int argc, char *argv[])//或**argv
```

假设用cmd执行a.exe ts1 ts2

则：argc=3,第一个为a.exe，后两个argv为"ts1" "ts2"

#### 格式

标准的说，应该是

```c
int main(void)
{
    return 0;
}
```

但下面的写法都没问题：

```c
int main()
{
    return 0;
}

int main()//注意里面真的是空的，其实别的函数也行
{
    
}

void main()
{
    
}
```

下面写法会给warning:

```c
main()
{
    return 0;
}

main
{
    
}
```

### 特点

1. 函数内部也可以定义函数

## 常用函数

### 数字处理

#### 随机数

stdlib.h

##### 置随机数种子

srand(seed);

seed一般是time(NULL)，需要time.h

##### 取随机数

RAND_MAX不大于32767，默认取到0~32767之间整数

即rand()

若需要[0,x]，则rand()%(x+1)

需要[a,a+b-1]则rand()%b+a

或者说[a,b]则rand()%(b-a+1) +a

上界不要大于RAND_MAX，否则容易出现锯齿化现象，即取到的不是连续的

#### math库

##### floor

去除小数点后数字，保留整数(返回值是double)

##### sqrt

返回算术平方根

若输入负数，返回-1.#IND00(%f显示)

##### pi

有常量M_PI，但也可以自己算：//因为有些编译器没有

``````C
const double pi = acos(-1.0); //-1也行，其他方法也行
const double pi = atan(1.0)*4;
``````

##### 三角函数

角度转弧度

``````C
r= = n*pi/180.0;
``````

直接使用：sin, cos, tan 接弧度

##### hypot

传入两边直角边长，输出斜边长

### 时间处理

#### 计时

##### 程序运行时间

```c
#include <time.h>
printf("%.2f", (double)clock() / CLOCKS_PER_SEC);
```

注意：该时间包括输入(scanf)所用时间；详见下方示例代码

#### 延时

##### 方法一

<windows.h>

标准C写作sleep()，VS和Code::Blocks写作Sleep()

参数代表毫秒。

##### 方法二

```c
#include <time.h>//C++用ctime
#include <stdio.h>
int main()
{
    float sec;
    scanf("%f",&sec);
    clock_t st = sec * CLOCKS_PER_SEC;
    clock_t bg = clock();
    printf("Begin!\n");
    while(clock() - bg < st);
    printf("Done!\n");
    return 0;
}
```

#### 日期

time.h

- [`struct tm`](https://zh.cppreference.com/w/c/chrono/tm) 表示日历时间，接近通常表示时间的方法。

  ```cpp
  struct tm {
    int tm_sec; // 秒
    int tm_min; // 分
    int tm_hour; // 时
    int tm_mday; // 日
    int tm_mon; // 月份下标，从 0 开始
    int tm_year; // 自 1900 的年数
    int tm_wday; // 自星期日的天数
    int tm_yday; // 自元旦的天数
    int tm_isdst; // 是否考虑夏令时
  };
  ```

- [`time_t`](https://zh.cppreference.com/w/c/chrono/time_t) 表示从纪元起[以秒为单位](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_types.h.html)的时间，计算方便 

  ```cpp
  typedef long time_t;
  ```

- [`mktime`](https://zh.cppreference.com/w/c/chrono/mktime) 能根据 `struct tm` 中已知的信息推出未知的信息，同时返回相应的 `time_t`。

  ```cpp
  time_t mktime(struct tm* time);
  ```

- [`localtime`](https://zh.cppreference.com/w/c/chrono/localtime) 能把 `time_t` 转换成对应的 `struct tm`。

  ```cpp
  struct tm* localtime(const time_t* timer);
  ```

举例：一个精确到秒的时间增加$width-1$位长$-1$的秒后的时间是多少(p2655)

```c++
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // 用 UTC，避免时区带来的问题
  setenv("TZ", "/usr/share/zoneinfo/UTC", 1);
  unsigned n;
  scanf("%u", &n);
  while (n--) {
    struct tm time;
    unsigned width;
    scanf("%u%d%d%d%d%d%d", &width, &time.tm_year, &time.tm_mon, &time.tm_mday, &time.tm_hour, &time.tm_min, &time.tm_sec);
    time.tm_year -= 1900;
    time.tm_mon--;
    // 不考虑夏令时
    time.tm_isdst = 0;
    // 把时间戳加上 width 位有符号整数的最大值，就能得到最后的有效时间
    time_t timer = mktime(&time) + ((1U << (width - 1)) - 1);
    struct tm* end = localtime(&timer);
    printf("%d %d %d %d %d %d\n", end->tm_year + 1900, end->tm_mon + 1, end->tm_mday, end->tm_hour, end->tm_min, end->tm_sec);
  }
  return 0;
}
```



### 字符处理

#### 转化

<stdlib.h>

##### atoi

转为整型，舍弃小数点后

##### atol

转为长整型，舍弃小数点后

##### atof

转为双精度实型

#### 判断类型

<ctype.h>

##### isalpha

(hos)输入char，是小写，返回2，大写,返回1，其他返回0

##### isupper, islower

##### isdight

是回1，否2

##### isprint, isspace, iscntrl

略

##### tolower,toupper

返回小写，大写(原本是不转化)

### 系统处理

#### 退出

<stdlib.h>

exit(code)//code一般是0或EXIT_SUCCESS

一般用在非main函数

#### 屏幕控制

##### system

<stdlib.h>

该函数传入的参数将会作为一条cmd语句并执行，执行期间如果遇到了任何反馈(如报错)将会直接输出。常用语句有：

"cls" 清屏

"PAUSE" 等待用户回应

##### 转到命令行坐标

<windows.h> //大概

```c
//坐标的定义：
typedef struct_COORD
{
    SHORT X;
    SHORT Y;
} COORD;
COORD pos = {x,y};//0开始代表左上，橫x纵y
```

```c
void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(houtput, pos);
}
```

##### 改变颜色

```c
BOOL setconsolecolor(unsigned int wattr)
{
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
    if(houtput == INVALID_HANDLE_VALUE) return FALSE;
    return SetConsoleTextAttribute(houtput, wattr);
}
```

颜色如下：

16种文字颜色，16种背景颜色，组合256种

字节的低4位控制前景色，高4位控制背景色(均是高亮+红+绿+蓝)

例如：0x0e黑色背景，亮黄前景；0x0c黑色背景，亮红前景。

##### 隐藏光标

```c
void hidecursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO io;
    GetConsoleCursorInfo(handle, &io);
    io.bVisible = 0;
    SetConsoleCursorInfo(handle, &io);
}
```

#### 检测按键

##### kbhit

<conio.h> 用户输入时返回非0，否则0

#### 文件

##### 新建文件夹

如果文件读写中open一个不存在的路径，不会进行新建操作，为此要新建一个文件夹。

<direct.h>

使用mkdir函数传入一个参数作为路径，该参数必须是C风格的字符串。将会在路径下新建这个文件夹，如果已经存在，不会产生报错。

## 特点

高效、简洁、快速、可移植性

面向过程

## 注意要点

### 踩过的坑

```c
1. 全局数组变量不可以使用const int来定义长度，只能用define或幻数。但是在C++可以用static const。
2. 全局域不能赋值，如w=3;memset等。
3. for(int i-0;i<h;i++) ×
4. if(com[0]='i') ×
5. 太大的数组不能放在局部变量，例如int x[1000][1000]。在C这个全局也不行，但C++可以，不过C里short x就可以的。short的话局部也可以。
6.输入错误：first √  frist ×
7.-1073741819 (0xC0000005)可能的原因有：printf里占位符数量不一致或出了问题，例如%Sum=lld
8.int n;scanf("%d", n);//是错误的，应该要&n，不然后面用到n来迭代就一个死循环了
9.c[1]是第二个字符，不是第一个！
10.scanf空格致死，用gets类似于python的input
11.for(int i=0, j=0;；)即便之前有int j，此处的j是新的，不是之前的。
12.500*500!=25000 = 250000
13.连等号见祖宗：x==y==z 变为bool==z，这不是python!!
14. (a+=x)%=m不是%=x 不然会RE
15.看混1和l，进而把1和l(left)互混而导致离谱的错误
16.看混i和1，例如1<<(i-1)写成i<<(i-1)
17.不要先输入再初始化
18.把f[x]=y写成f[x]=f[y]造成的错误
19.for(int i=9;i==0;) printf("%d",i--);一次都不执行
20.双向遍历一个数组，for(i=0,j=len;i<j;++i,--j)改为len-1
21.计算分数5/7 -> (double)5/7
22.*++p之后p移位了！所以输出p不再从一开始输出
23.字符串的操作函数注意事后加上\0
24.不要把repe写成rep(即<=与<)
25.l和1看混造成暴死(二分搜素)
26.不要把i和1写混了，尤其是位运算，特别容易出错！
27.不要把for(i=;k;i??)看成for(i=;i<k;i??)然后用rep简化
28.注意初始条件和第一次变化不要冲突而让第一次变化变化了两次
29.用三点坐标和根号公式计算三角形面积，最后p-a,p-b,p-c算成了减去点的坐标而不是边而暴死(当然用叉乘好多了)
```

12.注意多重循环的跳出

```c++
for(...)
{
    while(...) continue; 
} ×
    
for(...)
{
    bool ctn=false;
    while(...) {ctn=true; break;}
    if(ctn) continue;
} √
```

13.三分比较逻辑值的返回问题(如大于0返回1，等于0，小于1)

```c
if(a!=b)return a>b;
return 0;  ×
    
return a-b; √
```

14.不要把while() xx写成while(); xx; //而且很难纠错

15.如果可以，尽量避免浮点运算，如分数同时乘最小公倍数。百元白鸡警告。(错因：x/3每个值有三种情况值一样)

16.min变量初始化为可能的最大值再大

17.容易重名的变量：

- n (num, N即length)  当for(i<n)和n的操作并存

18.数据溢出专题

- 1e5*1e5就是会爆int，虽然理论上没爆，算之前强转一下
- 用int sum累加double的值，导致丢失，即便double本身也是int过来的，但是可能变成了.99999,再int就无了，损失精度



### 期末考

#### 已错题

1. ```c
   for(int i=9;i==0;) printf("%d",i--);一次都不执行
   ```

2. 嵌套这两个字不要写错

3. fseek的第二个参数要加L

4. 正确的赋值语句：

   ```c
   char b[5],*p=b;p="abcd";//而不是*p="abcd";
   ```

5. 倒置字符串，填空题：

   ```c
   for(i=0;j=strlen(str)_____;i<j;i++,j--)//填-1
   ```

6. 函数指针的用法：

   ```c
   参数为 double(*f)() ，调用：t=0.5+f(a)
   指向： double(*f)();f=g;//g是double f(double x)函数
   ```

7. 转移符+任意字符(哪怕不能转移)等于1长度；
   遇到\0立刻停止了,如："abcd\0ef\og"长度为4

8. ```c
   char *p,*q;则p=&q不正确
   ```

9. 数组长度=字符串长度+1

10. 如果函数值的类型与返回值类型不一致，以函数值类型为准

11. fputc有两个参数，第二个是fp

12. scanf%s遇到空格就读停，如"how is the weather"只读入how
    也鉴于这个原因，只读字符串的如无说明可用gets，可读空格

13. 夹杂字符串和其他(或字符串)的读入，记得%*c或fflush

14. 计算分数5/7 -> (double)5/7

15. *++p之后p移位了！所以输出p不再从一开始输出

16. 不要理所当然地看某个程序，尤其是未给出功能时，一定要走纸每一步

17. 字符串的操作函数注意事后加上\0

18. 已定义一个整型变量x，则表达式x=1,x++,x+2的值为：2

    解题要点：逗号当成分号，所以x+2无意义

19. 字符常量赋值，''\65'合法(八进制化为十进制为53),'\028'不合法，其中\02是一个字符，8是第二个字符，值是56，所以值为02\*256+'8'=512+56=568

20. 对`*char* s[] **=** "\t\v\\\0which\n"`，sizeof是11，strlen是3，即字符串长为3

#### 注意的题

1. sizeof double为8

2. ```c
   n=i=2,++i,i++的值为3，n的值为2；不会先执行++i再n=i=2
   ```

3. 表达：malloc函数的返回值类型为(空)指针

4. 有些题一开始没说输入的值，但是后来说了，注意看

5. 写程序题除非明确说“部分源程序已给出”，否则一律写完整程序

#### 失误丢分

1. ```c
   二维数组a,*(a[1]+2)看成了*(a[0]+2)所以算成了*a[2][0]
   ```

2. 看反“正确的是”，“错误的是”

3. 下标与序数的关系(下标+1=序数)，注意序数列表

4. 数组计算失误(忘了记录结果输出了上一次的值)

5. (!x)==(x!=0) 值为0

6. \0写成了/0

### 不同的标准

这里给的可能不全……

1. 注释：C89只有/* */，而C99加了//
2. for的初始化赋值：C89不允许
3. 

### 技巧

#### 标准头

##### C++

```c++
#include <bits/stdc++.h>
using namespace std;
#define BIG 0x7fffffff
#define BBIG 0x7fffffffffffffff
#define re register
#define il inline
typedef long long ll;
#define rep(i,a,b) for(long long i=a;i<b;i++)
signed main()
{
    return 0;
}
```

#### 换int

将int main改成signed main

然后使用：

```c++
#define int long long
```

#### 卡常

##### 快读

###### getchar

```c++
#define fast_io
#ifdef fast_io
const int _IB=1e6;
char _ibuf[_IB],*_s,*_t;
#define getchar()\
 (_s==_t&&(_t=(_s=_ibuf)+fread(_ibuf,1,_IB,stdin),_s==_t)?EOF:*_s++)
#endif
```



### 其他

1. 操作全局变量有风险，谨慎使用
2. C89不能用变量定义数组大小，但C99允许

# C++ - 知识网络

## 运算

### 万能头文件

```cpp
#include<bits/stdc++.h>
```

 **bits/stdc++的缺点**

- bits/stdc++.h 不是GNU C++库的标准头文件，所以如果你在一些编译器（除了GCC）上编译你的代码，可能会失败，比如MSVC没有这个头文件。比如POJ就不可以用。
- 使用它会包含很多不必要的东西，并且会增加编译时间
- 这个头文件不是C++标准的一部分，所以是不可移植的，应该尽量避免。比如vs就没有这个头，要自己手动装。
- 尽管标准中有一些通用的头文件，但还是应该避免使用它来代替特定的头文件，因为编译器在每次编译转换单元时都实际地读取并解析每个包含的头文件(包括递归包含的头文件)。

**bits/stdc++的优点**

- 在比赛中,使用这个文件是一个好主意,当你想减少时间浪费在做选择的时候;特别是当你的排名对时间很敏感的时候。
- 这还减少了编写所有必要头文件的所有杂务。
- 你不必为使用的每个函数都记住GNU c++的所有STL。

### 运算符重载

格式：

```c++
返回值类型 operator 运算符 (参数) //可选const
{
    ....
    return ...;
}
```

重载为类的成员函数时，函数参数个数比原来的操作数少一个(后置++，--除外)，第一个操作数是调用函数的对象，非成员函数时，操作数等于参数个数。

对于后置++，--，为了区分于前后置，应当在重载后置即x++时加上一个整型形参，在运算中不起任何作用，只用于区分前置和后置++，--。

是否为成员函数时，重载的等价不相同，如：

- `A.operator+(B) operator+(A,B)`
- `A.operator++() operator++(A)`
- `A.operator++(0) operator++(A,0)`

注意：

- 由于进行`a+b=c`赋值没有意义，可以把+,-运算符重载返回常对象
- 重载[],=时通常返回引用加快速度，避免复制构造
- 重载[]时可重载两个，一个是常函数，返回常对象引用，一个不是，便于当有const实例时可以区分开
- =运算符的默认隐含重载是对每个数据成员执行=运算符
- =,[],(),->只能被重载为成员函数
- 派生类的=总会隐藏基类的=
- 类型转换函数如`operator int()`不需要写返回值，只能是成员函数
- 重载了<和=之后，并不可以直接调用!=,<=,>=等函数，但是对应函数符可以调用

当加载了utility头文件时，代码允许仅通过重载小于号和等于号一共两次重载完成所有的逻辑判断。需要使用命名空间std::rel_ops。



#### 举例

##### +,++,<<

```c++
class point
{
public:
    double x,y;
    point(double x, double y):x(x),y(y){}
    point operator+(const point& b) const {return point(x+b.x,y+b.y);}
    point& operator++(){++x,++y; return* this;}//有返回值仅仅为了支持复合运算
    point& operator++(int) {++(*this); return* this;}
    void prt()const{printf("(%.2lf, %.2lf)\n",x,y);}
};
ostream & operator<<(ostream &out, const point& a)
{//写成const& point a暴毙
    out<<"("<<a.x<<", "<<a.y<<")\n";
    return out;
}
signed main()
{
    point pa(3,5),pb(-3,4);
    (pa+pb).prt();
    ++pa;//++重载为void时这行也可以运行，但(++pa).prt();不可以
    pa.prt();
    (++pa).prt();
    (pa++).prt();
    pa.prt();
    cout<<pa<<pb;
    return 0;
}
```



```c++
Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}
total = t1 + t2;//两种使用方法
total = t1.operator+(t2);
```

```c++
Time operator-(const Time &t) const;
Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1 = t.minutes + 60*t.hours;
    int tot2 = minutes + 60*hours;
    diff.minutes = (tot2-tot1)%60;
    diff.hours = (tot2-tot1)/60;
    return diff;
}
```

```C++
Time operator*(double n) const;
Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 0 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
A = B * 2.75;//ok
A = 2.75 * B;//fail，参见友元
```

```c++
char &operator[](int i) const;
char &STR::operator[](int i) {return str[i]};
```



##### [],=,type*

```c++
#include <bits/stdc++.h>
using namespace std;
template<class t>
class arr
{
public:
    t* nr;
    size_t size;
    arr(size_t sz)
    {
        size=sz;
        nr=new t[size];
    }
    ~arr(){delete [] nr;}
    arr(const arr<t>& x)
    {
        size=x.size;
        nr=new t[size];
        for(size_t i=0;i<size;++i) nr[i]=x.nr[i];
    }
    arr<t>& operator=(const arr<t>& x)
    {
        if(&x!=this)
        {
            if(size!=x.size)
            {
                delete [] nr;
                size=x.size;
                nr=new t[size];
            }
            for(size_t i=0;i<size;++i) nr[i]=x.nr[i];
        }
        return* this;
    }
    t& operator[] (int n){return nr[n];}
    const t& operator[] (int n) const {return nr[n];}
    operator t*(){return nr;}
    operator const t*() {return nr;}
};
signed main()
{
    arr<int> a(5);
    a[2]=3,a[3]=3; cout<<(++a[3])*a[2]<<endl;
    arr<int> b(a);
    b[2]=-3; cout<<b[2]*a[2]<<endl;
    int* c=a; c[2]=5; cout<<a[2]*b[3]<<endl;
    arr<int> d(6); d[3]=10;
    arr<int> e=d; cout<<(++e[3])*d[3]<<endl;
    return 0;
}
```

##### <,==,utilty

```c++
#include <iostream>
#include <utility>
typedef int ll;
using namespace std;
using namespace std::rel_ops;
class judge
{
public:
    ll v;
    judge(ll x) : v(x) {}
    bool operator<(judge x) const { return v < abs(x.v); }
    // bool operator>(judge x) const { return v > abs(x.v); }
    bool operator==(judge x) const { return v == abs(x.v); }
    // bool operator!=(judge x) const { return v != abs(x.v); }
};
signed main()
{
    judge a(2), b(-2), c(-1), d(3);
    cout << (a >= d) << endl;
    cout << (a != b) << endl;
    return 0;
}
```





#### 限制

1. 重载的运算符(有些例外情况)不必是成员函数，但必须至少有一个操作数是用户定义的类型。
2. 重载后的运算符必须至少有一个操作数是用户定义的类型。
3. 重载不能修改操作数，如把双目运算符改为单目运算符。
4. 不能创建新运算符，如**
5. 不能重载如下运算符：
   1. sizeof
   2. . (成员运算符)
   3.  .* (成员指针运算符)
   4. 作用域解析运算符
   5.  ?: 条件运算符
   6. typeid 一个RTTI运算符
   7. const_cast, dynamid_cast, reinterpret_cast, static_casst 这四种强制转换运算符
6. 下列运算符只能通过成员函数重载：
   1. = 赋值运算符
   2. () 函数调用运算符
   3. [] 下标运算符
   4.  -> 通过指针访问类成员的运算符



允许重载的运算符如下：//未含附录E总结

```c++
+ - * / % ^ & | ~= ! = < > 
+= -= *= /= %= ^= &= |= << >> >>= <<=
== != <= >= && || ++ -- , ->* ->
() [] new delete new [] delete[]
```

#### 友元

友元包括友元函数、友元类、友元成员函数。

##### 友元函数

让函数称为类的友元，可以赋予该函数与类的成员函数相同的访问权限，即可以访问私有成员等。

常规运算符重载，还是会带来问题，如：

```c++
A=B*2不可以换成A=2*B
```

虽然可以通过告知每个人只按照前者编写，即采用服务器友好-客户警惕(server-friendly, client-beware)的解决方案，但是也可以通过非成员函数解决。（大多数运算符都可以通过成员或非成员函数来重载）非成员函数不由对象调用，使用所有值(包括对象)都是显式参数。

非成员函数可以如下：

```c++
Time operator*(double m, const Time &t);
```

然而上述函数无法直接访问类的私有数据，至少常规非成员函数不能访问。如果添加友元关键字friend，才可以让访问权限与成员函数相同：

```c++
friend Time operator*(double m, const Time &t);
```

注意：

- 不能使用成员运算符调用该函数
- 只在函数原型使用friend关键字，函数定义不要使用。

那么可以：

```c++
Time operator*(double m, const Time &t)
{return t*m};//上述的运算符重载形式直接调用就好啦
```

使用友元函数重载cout<<的举例：

```c++
friend ostream &operator<<(ostream &os, const Time &t);
ostream &operator<<(ostream &os, const Time &t)
{
    os<<t.hours<":"<<t.minutes;
    return os;//保证多次<<能够顺利
}
```



注意：友元函数定义和方法定义只能二选一，例如下面只能二选一：(略去了函数原型)

```c++
Stonewt Stonewt::operator+(const Stonewt &wt) const
{
    double pds = pounds + st.pounds;
    Stonewt sum(pds);
    return sum;
}
```

```c++
Stonewt operator+(const Stonewt &st, const Stonewt &st2)
{
    double pds = st1.pounds + st2.pounds;
    Stonewt sum(pds);
    return sum;
}
```



应用举例：(一个友元函数跨两个类)

```c++
friend bool operator<(const STR &st1, const STR &st2)
bool operator<(const STR &st1, const STR &st2)
{return strcmp(st1.str,st2.str)<0}
```

```c++
#include <iostream>
using namespace std;
class Car;
class Boat
{
public:
    Boat():weight(0){}
    Boat(double w):weight(w){}
    friend double getTotalWeight(const Boat& x, const Car& y);
private:
    double weight;
};
class Car
{
public:
    Car():weight(0){}
    Car(double w):weight(w){}
    friend double getTotalWeight(const Boat& x, const Car& y)
    {
        return y.weight+x.weight;
    }
private:
    double weight;
};
int main()
{
    Car c(20);
    Boat b(30);
    cout<<"Total weight is "<<getTotalWeight(b,c)<<" tons.\n";
    return 0;
}
```



##### 友元类

友元类所有方法都可以访问原始类的私有成员和保护成员。友元类的所有成员函数都是友元成员函数。若A类是B类的友元类，则A类的所有成员函数都是B类的友元函数，即B可以访问A类的私有、保护成员。友元定义放公有私有里好像都行(但建议放公有)。在类里写友元类的意思是这个类允许被写的类使用自己的私有成员。

友元关系无法继承，没有传递性，友元是单向关系。

###### 单向友元类

```c++
class Tv
{
public://注意这里先公有后私有
    friend class Remote;//Remote是Tv的友元类，这里之前不必有Remote声明
    //甚至下面没有Remote也不会报错(假定没有用到相关的内容)
    ...
    bool volup();
private:
    int volume;
    int channal;
    ...
};
class Remote
{
public:
    bool volup(Tv &t) {return t.volup();}
    void set_chan(Tv &t, int c){t.channel = c;}
};
Tv s42;
Remote grey;
grey.volup(s42);
grey.set_chan(s42, 28);
```

###### 双向友元类

```c++
class Tv
{
friend class Remote;
public:
    void buzz(Remote &r);
};
class Remote
{
friend class Tv;
public:
    void bool volup(Tv &t) {t.volup()；}
};
inline void Tv::buzz(Remote &r) {;}
```

在上面的例子中，对于使用Remote对象的Tv方法，原型可在Remote类声明前声明，必须在Remote类声明后定义。

##### 友元成员函数

使用前向定义(forward declaration)避免循环依赖。

```c++
class Tv;
class Remote {};//涉及的可以只包含方法声明，但仍可以使用inline关键字。
class Tv //同理
{
public:
    friend void Remote::set_chan(Tv &t, int c);
};
```

###### 共同友元

函数需要访问两个类的私有数据，但函数不能成为两个类的成员函数；不过可以是一个类的成员和一个类的友元，也可以是两个类的友元，即共同友元。

```c++
class Analyzer;//前向定义
class Probe
{//用a给p同步
	friend void sync(Analyzer &a, const Probe &p);
    friend void sync(Probe &a, const Analyzer &p); 
};
class Analyzer
{
    friend void sync(Analyzer &a, const Probe &p);
    friend void sync(Probe &a, const Analyzer &p); 
};
inline void sync(Analyzer &a, const Probe &p) {}
inline void sync(Probe &a, const Analyzer &p) {}
```



### 优先级

结合性：从左到右(L-R)，从右到左(R-L)

具体如下：(最高优先级为第一位，同级按结合性顺序运算)

1. 

   - :: 作用域解析运算符

2.  L-R 

   -  (表达式)  分组
   - () 函数调用
   - () 值构造，即type(expr)
   - [] 数组下标
   - -> 间接成员运算符
   - . 直接成员运算符
   - const_cast 专用类型转换
   - dynamic_cast 专用类型转换
   - reinterpret_cast 专用类型转换
   - static_cast 专用类型转换
   - typeid 类型标识
   - ++ 后缀加1运算符*(???)*
   - -- 后缀减1运算符

3. *全是一元运算符*    R-L  

   - ! 逻辑非
   - ~ 位非
   - +一元加号(即正号)
   - -一元减号(即负号)
   - ++ 前缀加1运算符
   - --前缀减1运算符
   - & 地址
   - *解除引用(间接值)
   - ()类型转换，即(type)expr
   - sizeof 长度(单位：字节)
   - new 动态分配内存
   - new[] 动态分配数组
   - delete 动态释放内存
   - delete[] 动态释放数组

4.  L-R 

   - .* 成员解除引用
   - ->* 间接成员解除引用

5. 全是二元运算符 L-R

   - *乘
   - /除
   - %模(余数)

6. 全是二元运算符 L-R

   - +加
   - -减

7. L-R

   - << 左移

   -  ```c++
     >>右移
     ```

8. L-R

   - < 小于

   - <= 小于或等于

   - ```c++ 
     > 大于
     ```

   -  ```c++
     >= 大于或等于
     ```

9. L-R

   - == 等于
   - != 不等于

10. 一元运算符 L-R

    - & 按位与AND

11. L-R

    - ^按位异或XOR

12. L-R

    - |按位或OR

13. L-R

    - &&逻辑与

14. L-R

    - ||逻辑或

15. R-L

    - ?:条件

16. R-L

    - =简单赋值

    - *=乘并赋值

    - /=除并赋值

    - %=求模并赋值

    - +=加并赋值

    - -=减并赋值

    - &=按位与并赋值

    - |=按位或并赋值

    - ^=按位异或并赋值

    - <<=左移并赋值

    - ```c++
      >>=右移并赋值
      ```

17. L-R

    - throw 引发异常

18. L-R

    - ，将两个表达式合并成一个

### 异常

异常处理的基本机制是随着函数层逐级传递，直到被捕获，如果一直不被捕获，那么运行系统捕获异常并终止程序。

#### try

##### 简单模版

```c++
try//通常在while里
{
    ...
    //任何代码（可以不在try而在try调用的函数里有：）
    if(...) throw STR;//throw字符串常量就好了，不要扔string，字符串变量当然也可以扔
}
catch(const char *s)//获取STR;注意const不可以省略
{//可以输出这个s，如cout<<s
    ...//获取throw后执行的代码块，通常continue/break
}
```

不像python也不像其他代码块，格式必须这样要求：

1. 大括号必须有
2. const char *s必须有，这里就是定义，不要扔别的如s指针直接给过来，也不要给string，就这样得了



##### 构造、析构

若catch是值，那么复制异常对象，如果是引用，初始化方法是该引用指向异常对象。异常抛出后，从进入try开始，到异常被抛出时，这期间栈上构造(未析构)的所有对象都会被自动析构，析构顺序与构造顺序相反，这个过程称为栈的解旋unwinding。具体看例子：

```c++
class demo
{
public:
    ll v;
    demo(ll x) : v(x) { cout << "new " << x << endl; }
    ~demo() { cout << "delete " << v << endl; }
};
demo a(1);
try
{
    demo b(2);
    demo b2(20);
    throw 580;
    demo c(3);
}
catch (ll)
{
    demo d(4);
}
demo e(5);
```

另，应该尽量保证析构函数不要抛出异常。



##### 错误类型版

拓展开来，throw的东西不一定是字符串，可以是任意内容，如代表错误序号的整数，而catch处就应该是整数；这是一种通过类型不同进行错误区分的方法，还有catch(...)表达式，表示接受剩下的所有错误类型，举例如下：

```c++
#include <iostream>
typedef int ll;
using namespace std;
struct err1
{
    string io = "er ty1";
} e1;
struct err2
{
    string io = "er ty2";
} e2;
void f(ll v)
{
    try
    {
        switch (v)
        {
        case 1:
            throw e1;
            break;
        case 2:
            throw e2;
            break;
        case 3:
            throw 3.3;
            break;
        case 4:
            throw 580;
            break;
        default:
            throw "qwq";
            break;
        }
    }
    catch (err1 x)
    {
        cout << "err1" << x.io << endl;
    }
    catch (err2 x)
    {
        cout << "err2" << x.io << endl;
    }
    catch (double x)
    {
        cout << "err 3" << x << endl;
    }
    catch (int x)
    {
        cout << "err 4" << x << endl;
    }
    catch (...)
    {
        cout << "err nor\n";
    }
}
signed main()
{
    for (int i = 1; i <= 6; ++i)
        f(i);
    return 0;
}
```



##### 异常类型

可以通过异常类型，在一个try跟多个catch，每个捕捉不同的异常类型。

```c++
class bad
{
public:
    double v1;
    double v2;
    bad(double a=0, double b=0) :v1(a), v2(b) {}
    const char *msg();
};
inline const char* bad::msg()
{
    return "oh no\n";
}//假设有类似的bad2, bad3
try
{
    cin>>b>>c;
    if(c==0) throw bad(b,c);
}
catch(bad &x)
{
    cout<<x.msg();
}
catch(bad2 &y)
{
    bad2.show();//假设有这个方法
}
```

当捕获第一个错误时，可以通过continue(+while)跳过第二个错误，其他同理。

##### 传递

如果try……catch不在主函数内，或者存在多级，需要在catch处重新throw一次。



如果有一个异常类继承层次结构，应当将捕获位于层次结构最下面的异常类catch语句放在最前面，将捕获基类异常的catch语句放在最后面。

```c++
class b1 {...};
class b2 : public b1 {...};
class b3 : public b2 {...};
void duper()
{
    ...
    if(t1) throw b1();
    if(t2) throw b2();
    if(t3) throw b3();
}
...
try
{
    duper();
}
catch(b1 &be) {...}
catch(b2 &be) {...}
catch(b3 &be) {...}
```



不带参数的throw可以传递当前的异常：

```c++
void g()
{
    try
    {
        throw 3;
    }
    catch (ll)
    {
        throw;
    }
}
try
{
    g();
}
catch (ll v)
{
    cout << v << endl;
}
```



##### exception类

exception库

```c++
class b1 : public exception
{
public://exception也有what的
    const char* what() {return "123";}
}
try{...}
catch(exception &e) {cout<<e.what()<<endl;}
//当然也可以catch多次如果有多个派生类
```

##### stdexcept

头文件stdexcept

有两个exception的派生类：

```c++
class logic_error : public exception
{
public:
    explicit logic_error(const string& what_arg);
}
//domain_error同理
```



错误类型类名：

- logic_error (头stdexcept)
  - length_error 长度超过最大允许值的对象创建
  - out_of\_range 参数值不在允许范围内
  - out\_of_bounds 
  - invalid_argument 无效参数
  - domain_error (定义域) 先决条件不足
- runtime_error (头stdexcept)
  - range_error
  - overflow_error
  - underflow_error (下溢:浮点最小非零值)
- bad_alloc (头文件~~new~~ exception) new失败
- bad_cast (头new) dynamic\_cast 失败
- bad_typeid (头typeinfo) 空指针typeid
- bad_exception (头typeinfo) 函数执行抛出了声明不允许的异常而调用unexpected时，unexpected抛出fun不允许的异常，且fun异常有bad\_exception时，在fun抛出
- ios\_base::failure (头ios) C++输入输出流错误

可以如下：

```c++
try{...}
catch(out_of_bounds &oe) {...}
catch(logic_error &oe) {...}
catch(exception &oe) {...}//还记得继承传递么
```

###### 示例

```c++
struct Big {doule stuff[20000];};
Big *pb;
try
{
	pb = new Big[10000];//1.6e9 bytes
}
catch(bad_alloc &ba)
{
    cout<<ba.what()<<endl;//输出std::bad_alloc
    exit(EXIT_FAILURE);
}
```

尝试获取编译错误之外的错误类型的方法：

```c++
try
{
    ll *x = new ll[999999999999999999LL];
}
catch (const exception &e)
{
    cerr << e.what() << '\n';
}
```

自己抛标准错误示例：

```c++
try
{
    throw runtime_error("RE is great!"); //中文乱码
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
}
```





#### assert

assert库

assert(表达式) 同python

当你加载了assert,不允许重载assert作为函数使用

#### abort

cstdlib库

abort()主动抛出错误，结束程序

#### noexcept

关键字或运算符。

##### 关键字

函数后加，表明该函数不会出错

> 0 warning(s), 0 error(s).

```c++
double marm() noexcept;
```

##### 运算符



#### 异常接口

函数的声明定义，表示这个函数可能抛出的所有错误类型：

```c++
返回值类型 函数名(参数) throw(类型A, ...);
```

不声明throw的函数可以抛任意类型错误；声明throw()的函数不可以抛任何类型异常。

如果一个函数抛出了声明之外的异常，unexcept函数会调用，默认行为是调用terminate函数终止程序。



## 数据

### 常规

POD(plain old data)

#### 常量型

##### char

可以用\u+4位八进制数字 表示ISO 10646码的字符，\U十六位，连续多个就串多个字符了。

##### 常量

```c++
//在头文件<climits> - 代表数据范围，是最大值(不是上界)
INT_MAX
SHRT_MAX
LONG_MAX
LLONG_MAX
CHAR_MAX
SCHAR_MAX//signed
UCHAR_MAX//unsigned，其他同理，放在前方，如ULLONG

MIN同理
    
CHAR_BIT //一般是8
```

用途：对于用户输入的数据，如果在这个范围之外，直接给报错

#### 初始化

与C不同，C++可以使用诸如：

```c++
int x{3};
int y{};//默认是0 等同于 int y = {};上同。
//这种里面的值不可以缩窄，例如int x = 3.0可以;{3.0}不可以
```

#### 数据类型

##### auto

auto 自动根据初始化的值决定选什么类型

##### bool

布尔值 true false

sizeof实质为1(byte)而不是1bit

因而不能进行按位取反来模拟!运算符，会导致：

~true->-2

~false->-1



wcha_t 宽字节型

- 其常量用L前缀，如L'P' 或 L"s1234"

char16_t 长16位无符号字符，用u前缀

char32_t 长32位无符号字符，用U前缀

##### 转化

- 含long double转之
- 含double转之
- 含float转之
- 其他整型转int
- 异类出现无符号，转为更高类
- 同类出现无符号，如果有符号不能表示无符号可能取值，有符号转无符号，否则无符号转有符号

注意：C++强转允许有第二种格式，即数据类型(量)

##### decltype

根据某变量数据类型给下一个变量赋数据类型，如：

```c++
int x;
decltype(x) y;

long indeed(int);
decltype(indeed(6)) k;//注意：不会执行该函数

//左值化：
int x;
decltype((x)) z;//z为int & ,da ck
decltype(x) y;//y为int

//允许反复调用同一个结果，使用typedef
typedef decltype(f(x)+g(x)) dt;
dt var1;
```

##### typeid

头文件typeinfo，若空指针，引发bad_typeid异常

> 不能对void用

对一个类型关键字或表达式使用，返回type_info对象的常引用，该对象有方法name，重载了==和!=。输出类型名字(不同编译器命名方法不一样)。

```c++
#include <bits/stdc++.h>
using namespace std;
class fuck{};
signed main()
{
    cout<<typeid(1+2).name()<<endl;
    cout<<typeid(float).name()<<endl;
    const type_info &iof=typeid(fuck);
    fuck* f1=new fuck,f2=fuck(),&f3=f2,*&f4=f1;
    cout<<iof.name()<<endl;
    cout<<typeid(f1).name()<<' '<<typeid(f2).name()<<' '<<typeid(f3).name()<<' '<<typeid(f4).name()<<endl;
    return 0;//如果*f1和*f4，那么类型同f2与f3
    
}
```

对于基类指针实际指向派生类，会返回派生类：

```c++
class fuck{public:virtual ~fuck(){}};//注意没有这样的话f里全部输出fuck
class ff:public fuck{};
void f(fuck *p)
{
    cout<<typeid(p).name()<<" "<<typeid(*p).name()<<endl;
    if(typeid(*p)==typeid(fuck)) cout<<"fuck!!!\n";
}
fuck a; ff b; f(&a); f(&b);
```

建议仅在必要时使用typeid。

##### wchar_t

> 不一定都支持

C++关键字wchar\_t，用于解决因各种把两个char当一个来显示中文等其他编码时可能会遇到的各种问题，如错误取子串、错误size和错误查找(如一个字的后半段和另一个字的前半段组合成了一个新字能够被错误地找到)。

> 常见汉字编码有GB-18030,GBK,GB-2312,BIG5,Unicode

每一个宽字节单字符用L前缀表示，如：

```c++
wchar_t c = L'你';
```

宽字节字符串是string，常量也用L，如：

```c++
wstring s = L"招生减章";
```

宽string可以用一般string的方法，如：

```c++
wstring s = L"招生减章";
if (s.find(L'我') == wstring::npos)
    cout << "404 NOT FOUND!";
```

cout输出宽字节char会输出其编码；不可以输出wstring。

在所有流之前加上w，就是宽流，如wistream,wcin，可以用于输入输出宽字符。

可以设定配置，如：

```c++
locale loc(".936");
wcout.imbue(loc);
```

事实上，在本机需要如下配置，方可显示：

```c++
ios::sync_with_stdio(false);
locale::global(locale(""));
setlocale(LC_CTYPE, "");    // MinGW gcc.
wcout.imbue(locale("")); //这个可以不要
```

测试输出：

```c++
wcout << L'我' << L"人以汉字";
```



#### 变量

**生存期**

存储连续性：

- 自动存储持续性：函数定义中声明的变量(包括函数参数)，创建于所属程序或代码块被创建，内存释放于执行完该函数或代码块。(不能使用C关键字auto,在C++11,register显式指出变量是自动的)
- 静态存储持续性：函数定义外定义的变量和static。生存期是整个程序运行期间。
- 线程存储持续性：(C++11)thread_local声明，生存期为线程生存期。可以与extern或static结合使用。
- 动态存储持续性：new。创建于被分配(使用new)，释放于delete或程序结束。也被称为自由存储(free store)或堆(heap)。

通常而言，编译器使用三块独立的内存，一块用于静态变量(可能再细分)，一块用于自动变量，一块用于动态存储。

**作用域**(scope)。名称在文件(翻译单元translation unit)的多大范围内可见。

**链接性**(linkage)描述了名称在不同单元间共享。链接性为外部的名称在文件间共享，内部的只能由一个文件中的函数共享。自动变量的名称没有链接性，不能共享。

作用域：

- 局部：定义它的代码块内可用。
- 全局(文件作用域)：在定义位置到为文件结尾均可用。

静态变量的作用域是全局还是局部取决于其如何被定义。在函数原型作用域(function prototype scope)使用的名称只在包含参数列表的括号内可用，在名称空间中声明的变量的作用域为整个名称空间。全局作用域是名称空间作用域的特例。

函数作用域是整个类或整个名称空间，不能是局部。



静态持续变量有三种链接性：外部链接性、内部链接性(当前文件)、无链接性(当前代码块或函数)。静态变量不用栈等特殊装置管理，而使用固定的内存块。静态变量所有位均为0(zero-initialized)。

在代码块外定义的为外部链接性，但有关键字static为内部链接性。无链接性使用static且在代码块内定义。

如果对一个变量，初始化时没有足够的信息，将会被动态初始化，如：

```c++
const double pi = 4.0 * atan(1.0);
```

C++11可以使用关键字constexpr创建常量表达式。

```c++
constexpr double pi = 4.0 * atan(1.0);
```



**外部变量**是链接性为外部的变量，存储持续性为静态，作用域为整个文件，又称全局变量(相对于局部的自动变量)。

每个使用外部变量的文件，都必须声明它。单定义规则(ODR, one definition rule),变量只有一次定义，可以用定义(definition,定义声明, defining declaration)会给变量分配存储空间；或引用声明(referencing declaration，声明declaration)，不给变量分配存储空间。

引用声明使用关键字extern，只需要在一个文件包含该变量的定义(参ODR)，在其他实用这个变量个文件，必须使用extern声明。在定义的文件，用不用效果一样。

引用声明：

```c++
extern double var;
var++;//修改外部变量
```

不能同名外部变量，只可以如下：

```c++
int x=1;//file 1
static int x=2;//file 2
```



**存储说明符**(storage class specifier)或cv-限定符(cv-qualifier)的C++关键字提供了存储有关的信息，如register,static,extern,mutable。

##### volatile

即使代码没有改变某个内存单元，其值也能发生改变，如系统时间，跨程序共享数据。使用该关键字后，在两次调用某变量时，将不会被缓存到寄存器(两次之间可能会被别的修改)。

##### mutable

在结构(或类)，即使某个变量为const，其成员也可以被修改：

```c++
struct data
{
    char name[30]; mutable int accesses;
};
const data veep = {"Clodde", 0};
veep.accesses++;
```

##### const

在C++，默认情况下全局变量为外部链接性，而const全局变量为内部的。但如果希望改回外部，则可以：

```c++
extern const int MAX = 99999;//[头文件不可以这样
在这种情况下，所有使用该常量的文件都要用const声明它。//datr
```

#### 枚举

##### 作用域内枚举

常规枚举如果多个枚举定义的枚举量相同会冲突。C++11提供新的枚举，声明如下：(可以用struct代替class)

```c++
enum class egg {Small, Medium, Large, Jumbo};
enum class shirt {Small, Medium, Large, Xlarge};
```

调用如下：(可以用于enum类间比较，不可以与其他类比较)

```c++
egg choice egg::Large;
```

更常用的调用如下：

```c++
int ci = (int)egg::Large;
cout<<(int)shirt::Small<<endl;
```

#### alignof

对于数据类型(包括结构)，返回其对其要求字节。如：

```c++
struct thing{char ch; int a; double x;};
cout<<alignof(thing)<<endl;//也可以是一个实例alignof(v)
```



### 数组

初始化

```c++
double x[4] {1,2,3,4};//ok,rest 0
int y[10] = {};//ok, all 0
```

在大括号里的都不可以向下转换。

### 指针

C允许void指针隐式转换为其他类型的指针，C++只能显式转换。

C++11可以使用nullptr关键字指向空

```c++
char *p1 = nullptr;
```

#### new

等效于C的动态数组malloc。在堆(heap)寻找内存块。

用法：

```c++
int *ps = new int;
int *ps = new int (6);//初始化 ，如果是空括号等效于(0):对象同理(类未定义构造函数时)
int *ps = new int {};//???
int *ps = new int {3};
point *ps = new point {1.0, -1.0};//初始化

int *ps = new int [10];//动态数组
int *ps = new int [4] {1,2,3,4};//初始化动态数组
```

用完记得delete，等同于C的free。允许对空指针使用delete

```c++
delete ps; //类会调用析构函数
delete [] ps;//动态数组
```

new和delete是可替换的(replaceable)，可以自定义。



多维数组：

```c++
float (*cp)[25][10];
cp = new float[10][25][10];
delete [] cp;
```



允许使用指定的内存块：

```c++
char buf[500], buf0[50], *p1;
int *p2;
p2 = new (buf) int[20]; //结构体等同理 
p1 = new (buf0 + N*sizeof(char)) char;//偏移
```

将无法delete。

new分配失败会抛出异常。

特别注意，如果需要取大小，不能够直接sizeof，因为这样得到的是指针的内存大小。

##### nothrow

失败时返回空指针的new

```c++
int *pi = new (nothrow) int;
if(pi==0) {...}
```



#### cast指针

##### dynamic_cast

> 见数据-类-RTTI。

##### const_cast

用于改变值为const/volatile的变量。语法同dynamic_cast。(High是Low的基类)

> const_cast <type-name> expression

```c++
High bar;
const High *pb = &bar;
High *pb = const_cast<High *>(pb);
const Low *p1 = const_cast<const Low *>(pb);//不可，改变了类名。普通转换就行:Low *p1 = (Low *) (pbar);
```



对于如下例子：

```c++
void change(const int*pt, int n)
{
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}
int pop1 = 38320;
const int pop2 = 2000;
change(&pop1, -103);//可以修改
change(&pop2, -103);//不能修改，前后pop2不变
```

> 解释：change里指针声明为const，所以不能修改指向的int；pc删除了const，本可以修改，但仅当指向的值不是const才可以。

对常对象使用没有意义，因为转换时会生成普通对象的副本。

对对象成员使用的示例：

```c++
const point& ele(int idx) const
{
    assert(idx>=0&&idx<size);
    return points[idx];
}
point& ele(int idx)
{
    return const_cast<point&>(
    	static_cast<const pointarr*>(this)->ele(idx));
}
```



##### static_cast

> [c的类型转换可以认为是static_cast]

语法同上。向上、下转换是合法的。

```c++
High bar;//High是Low的基类，Pond是无关的类
Low blow;
High *pb = static_cast<High *> (&blow);
Low *pl = static_cast<Low *> (&bar);
Pond *pmer = static_cast<Pond *>(&blow);//不可
```

可以通过派生类指针直接获得基类指针，但反过来时必须使用`static_cast`。

同时，void指针和一般指针的关系可以类推基类和派生类的关系。

引用的类型转换规则与指针一致。

然而，派生类对象可以转基类，反过来未必可行(未定义构造函数时)。

基类转派生类时，如果实际指向不一致，那么获得的指针有可能并不是要求的类型，而只得到了一个基类new的指针。

如果A类型是B类型的虚拟指正，B类型指针可以隐含转换为A，但A无法`static_cast`隐含转化为B。

多次转换时，如果中途出现了void指针，需要保证起始指针类型完全一致，否则会不正确。

##### reinterpret_cast

```c++
struct dat {short a; short b;}
long value = 0xA224B118;
dat *pd = reinterpret_cast<dat *>(&value);//value?
```

可以指针转为存储指针表示的整型，不能转为更小的整型或浮点型。不能将函数指针转数据指针，反之亦然。

> 如果用这样转化的指针去修改被指向的值(类型不同)，一般会出问题。慎用该类型。(一般都不用)

##### lexical_cast

头文件"boost/lexical_cast.hpp"

将任意其他类型转string

```c++
string wt = boost::lexical_cast<string>(intvar);
```

#### 智能指针类

包含auto_ptr(已经摒弃), share_ptr(可以多个指一个),unique_ptr，基本功能是自动释放内存。在头文件memory。

> 还有一个weak_ptr

```c++
share_ptr<double> pd;
double *p_reg = new double;
```

##### auto_ptr

memory头

智能指针类



### 引用

#### 左值引用

类似于指针，但不同于指针，有点像一个变量的别名。其实质地址与被引用变量地址相同。(因此如果定义后进行赋值操作是对原变量赋值)

```c++
int &acopy = a;
//那么acopy的操作，如acopy++都会影响到a，因为他们地址相同。
```

引用不能先声明再赋值。引用像const指针(指针的指向const)，所以声明时必须赋值，且不能改变初始化再指向其他对象。

引用在函数参数很常用。

```c++
void swapv(int &a, int &b)
{int t=a;a=b;b=t;}
swapv(x,y);//不必&x,&y
```

不能在函数传表达式或幻数给引用，如swapv(3, 1+a);前后均不合法。

引用只能在初始化时指定被引用对象，之后便不能够更改。

如果要传const来引用，必须声明为参数const 数据类型 &varname，实际上这种写法然并卵。

对于结构体，不需要用->运算符。

允许通过返回值形式连续引用，如f(f(x))

对于类的引用，在函数内设置的类属性，在外部不会改变，如：

```c++
void tr(ostream &os)
{
    os.width(12);
    os<<"H3"<<endl;
}
```

即便执行过tr(cout),那么在main等其他函数，也不会被改变。

数组不能引用，只能指针[



使用引用的原因可能有：

- 修改值
- 某个很大的数据对象，提高运行速度(复制拷贝和直接用当然是后者更快了)

#### 右值引用

在左值引用基础上，右值引用可以有表达式和幻数。//好像有点问题da ck

```c++
double && rref = 6.0;
double j = 15.0;
double && jref = 2.0 * j + 18.4;//48.5
cout<<rref<<endl;
cout<<jref<<endl;
```

一个重要的应用是可以用于移动语义(move semantics)，即在大数据复制时，只转接(指针)而不实际复制：

```c++
class Useless
{
private:
    int n;
    char *pc;
    static int ct;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless &f);//常规复制构造函数
    Useless(Useless &&f);//移动构造
    ~Useless();
    Useless operator+(const Useless &f)const;
}
Useless::Useless(){++ct; n=0; pc=nullptr;}
Useless::Useless(int k):n(k){++ct;pc=new char[n];}
Useless::Useless(int k char ch):n(k)
{
    ++ct; pc = new char[n];
    for(int i=0;i<n;i++) pc[i]=ch;
}
Useless::Useless(const Useless &f):n(f.n)
{
    ++ct; pc = new char[n];
    for(int i=0;i<n;i++) pc[i] = f.pc[i];
}
Useless::Useless(const Useless &&f):n(f.n)
{
    ++ct; pc = f.pc; f.pc=nullptr; f.n=0;
}
Useless::~Useless() {delete [] pc;}
Useless Useless::operator+(const Useless &f)const
{
    Useless temp = Useless(n+ f.n);//移动语义
    for(int i=0;i<n;i++) temp.pc[i]=pc[i];
    for(int i=n;i<temp.n;i++)temp.pc[i]=f.pc[i-n];
    return temp;
}
Useless one(10, 'x');
Useless two = one;
Useless three(20, '0');
Useless four(one+three);//移动构造

//如果要复制赋值和移动赋值
Useless &Useless::operator=(const Useless &f)
{
    if(this == &f) return *this;
    delete [] pc;
    n=f.n; pc = new char[n];
    for(int i=0;i<n;i++) pc[i] = f.pc[i];
    return *this;
}
Useless &Useless::operator=(Useless &&f)
{
    if(this == &f) reeturn *this;
    delete [] pc;
    n=f.n; pc=f.pc; f.n=0; f.pc=nullptr;
    return *this;
}
```

可以使用move函数强转右值引用：

```c++
Useless four = move(one);
```



### 类

类是用户定义的一种数据类型。类描述了一种数据类型的全部属性（包括可使用它执行的操作）。

对象是根据数据格式规范创建的实体。

区别于面向过程编程(POP,  process oriented programming)，面向对象编程(OOP, object oriented programming)具有一些新的特点。

过程性编程时，首先考虑遵循的步骤(zhou4)，然后考虑如何表示这些数据，而OOP首先考虑数据，不仅考虑如何表示数据，还要考虑如何使用数据。从用户的角度考虑对象，描述对象所需的数据以及用户与数据交互需要的操作，然后设计出程序。

类规范由两部分组成：

- 类声明：以数据成员的方式描述数据部分；以**成员函数**(**方法**)的方式描述公有借口。
- 类方法定义：实现类成员函数。成员函数可以就地定义，也可以用原型表示。

接口是一个共两个系统交互时使用的共享框架。

一种规范是将类名首字母大写。

与结构体不同，类是一种新的数据类型。

定义类还可以表示更通用的**抽象数据类型**(**ADT**, abstract data type)，如栈。

> 可以使用UML(统一建模语言)表示对象。此处略。

在复杂工程里，一般把类的声明(和内联定义)放在一个.h，类的定义放在另外的.cpp里，后者需要include前者。也可在后者include其他需要用到的库，而最终主函数只需要include前者。

> 自定义类型数据由多个基本类型或自定义类型元素组成，称为**群体数据**，将其封装起来就是**群体类**。

#### 访问控制

使用类对象的程序都可以直接访问公有部分(public)，但只能通过公有成员函数或友元函数访问对象的私有(private)成员。

数据隐藏：防止程序直接访问数据。

封装：将实现细节放在一起并将它们与抽象分开。类设计尽可能将公有接口与实现细节分开。公有接口表示设计的抽象组件。将实现的细节隐藏在私有部分，或将类函数定义和类声明放在不同的文件，就是封装的一个例子。

使用关键字private(可以省略)和public控制，例如：

```c++
class World
{
private:
    float mass;
    char name[20];
    void set_mass(){mass = NOR_MASS;}
public:
    void echo(void);
    ...
}
```

类与结构的区别之一在于，结构的默认访问类型是public，类是private。

还有第三种关键字：protected。protected与private类似。在类外只能用公有类成员访问protected部分类成员。但派生类的成员可以直接访问基类的保护成员，但不能访问基类的私有成员。虽然如此，还是建议不要使用保护访问控制，而通过基类方法使派生类能够访问积累数据，采用私有访问控制。

> 在保护派生或私有派生时，基类方法若在派生类外可用，可用using的方法重新定义访问权限：//但这种方法已经即将不被支持
>
> ```c++
> public:
> using valarray<double>::min;
> using valarray<double>::operator[];
> ```

- 关键字不必按照特定顺序出现也不只能出现一次(如public,private,public)；但一般public出现在最先。

C++11可以在类定义中初始化成员：

```c++
int mem1 = 10;
double mem2 {12.3};
```

> 类名不能跟成员属性名冲突



#### 成员函数

定义成员函数时，使用作用域解析运算符标识函数所属的类，类方法可以访问类的private组件(而无需写限定名)，如：

```c++
void Stock::update(double price)
```

则标识符update()具有类作用域(class scope)，Stock类的其他成员函数不必使用作用域解析运算符而使用update()方法。其中Stock::update()是函数的限定名，update()是非限定名。



定义的位于类声明中的函数自动成为内联函数。在类声明之外定义成员函数并使之内联需要使用inline限定符(在函数定义处)。

如果在头文件初始化，将出现多个初始化语句副本从而引发错误。应当在包含类方法的文件中初始化。

> 成员函数的定义只占一分内存，不会有多少个实例占据多少个内存。

在类内定义的函数都是内联函数；在类外含inline关键字定义的也是内联函数(类内声明不一定要inline)。否则是普通函数。

##### const成员函数

如果创建了const成员：

```c++
const Stock land = Stock("N");
land.show();//会报错
```

为了解决上面的问题(常对象只能调用常函数)，那么需要创建const成员函数，如：

```c++
void show() const;
void Stock::show() const;
```

一般而言，只要类方法不修改调用对象，就应该声明为const

常函数内把对象本身视为常对象。

可以在相同的参数下重载，那么一般对象调用一般函数，常对象调用常函数，例如：

```c++
class ac
{
public:
	int x, y;
	ac() {}
	ac(int x, int y) :x(x), y(y) {}
	void prt() { cout << x + y << endl; }
	void prt() const { cout << x * y << endl; }
	void prt2() const { cout << x - y << endl; }
	void prt2() { cout << x / y << endl; }
};
ac x(10, 2);
const ac y(48, 9); //下面四个输出各不相同
x.prt();
y.prt();
x.prt2();
y.prt2();
```

##### 静态成员函数

不能通过对象调用静态成员函数。静态成员函数不能使用this指针。若静态成员函数在公有部分声明，可以使用类名和作用域解析运算符调用，其定义/原型如下：

```c++
static int Nums() {return num_t;}
```

调用如下：

```c++
int count = STR::Nums();
```

由于静态成员函数不与特定对象关联，所以只能使用静态数据成员。除非是通过参数传入的。

> 不能加const关键字

##### 禁用方法

方法一：通过伪私有方法禁用某个运算符

```c++
class Queue
{
private:
    Queue(const Queue &q):qsize(0){}
    Queue& operator=(const Queue &q){return *this;}
};
```

这样将无法进行下列操作：

```c++
Queue q2(q1);
q2 = q1;
```

方法二：delete

在声明中：

```c++
Someclass(const Someclass &) = delete;
```

##### 成员函数指针

定义对象的成员函数指针，使用如下格式：

```c++
成员函数返回值类型 (类名::*指针名)(函数参数) (可选)const=&类名::成员函数名
double (line::*fxptr)() const=&line::length;
```

对于实例和实例指针，调用如下：

```c++
(实例名.*指针函数名)(函数参数)
(指针名->*指针函数名)(函数参数)
```

如：

```c++
class line
{
public:
    line(const point&p1, const point& p2):p1(p1),p2(p2),len(-1){}
    double length() const;
private:
    point p1,p2;
    mutable double len;
};
double line::length() const
{
    if(len<0)
        len=sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)  );
    return len;
}
point x={5,5},y={6,6};
line xy(x,y);
line *xyp=&xy;
double (line::*fxptr)() const=&line::length;
cout<<(xy.*fxptr)();
cout<<(xyp->*fxptr)();
```



#### 对象

创建的新对象都有自己的存储空间，存储内部变量和类成员；但同一个类所有对象共享同一组类方法。调用成员函数被称为发送信息。成员名可以如下区分：(后者比较推荐)

```c++
添加 m_ 的前缀 或 _ 的后缀
```



创建对象：

```c++
Stock obj1;
Stock obj1 = Stock(...);//见构造函数
Stock obj1 = {...};//或没有等号，或乃至{}也行。
Stock *obj1 = new Stock(...);//或{...}
Bozo d(6);//只有一个参数
Bozo d = 6;//只有一个参数
```

创建对象数组：

```c++
Stock sto[4] = 
{
    Stock("1",1.0,1), Stock("2"),
    Stock(), Stock("4",4.0,4)
};//下标2的元素用了默认构造函数
```

> 一般不对对象使用memcpy/memcmp/memset函数。

##### 前向引用声明

有两个类或多个互相引用时，为了防止循环依赖，需要先预先声明一个类。但是在该预声明类被定义前，仍不可以定义一个该类的对象或在内联成员函数中使用该类(但可以使用指针或引用)。即只能使用被声明的符号，而不能涉及其的任何细节，包括该类的成员函数或成员属性。

```c++
class B;
class A
{
public:
    void f(B b);
}
class B
{
public:
    void f(A a);
}
```

##### 返回值

由于：

- 返回对象会调用复制构造函数，返回引用不会。如果被返回的对象是局部变量，不应该按引用方式返回，应该返回对象。
- 直接引用不用搞副本，对于比较大的来说效率更高，也不会调用到诸如复制构造函数之类的东西。
- 在继承使用虚函数时，被定义为接受基类引用参数的函数可以接受派生类。

因此更常常按引用而不是

按值来传递对象。然而，有些方法必须返回对象，例如需要一个临时创建的对象：

```c++
Vector Vector::operator+(const Vector &b) const
{return Vector(x+b.x,y+b.y);}
```

##### const

###### 常对象

是const的实例，只能在初始化时赋值，其他时候不能改变其成员变量。常对象只能被常引用，不能被普通传引用。

###### 常数据成员

只能通过初始化列表获得初值，且必须获得初值。(即不允许再有x(){}的声明，必须给一个初始值，如：x():y(0){})

###### 常引用

const 类型& 变量名

普通引用不能传引用常对象；常引用的一切对象都视为常对象。

##### mutable

作用在一个成员属性上，可以让常对象函数修改这个成员属性，举例如下：

```c++
struct point
{
    int x,y;
};
class line
{
public:
    line(const point&p1, const point& p2):p1(p1),p2(p2),len(-1){}
    double length() const;
private:
    point p1,p2;
    mutable double len;
};
double line::length() const
{
    if(len<0)
        len=sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)  );
    return len;
}
point x={5,5},y={6,6};
line xy(x,y);
cout<<xy.length();
```



#### 构造函数

用于构造新对象，将值赋给它们的数据成员。构造函数没有声明类型(返回值)。函数名为类名。参数名不能与类成员相同。指针和左值引用不会调用构造函数和析构函数。

> 如果未声明，则默认构造函数为：（详见默认构造函数节）
>
> ```c++
> 类名() {}
> ```
>
> 一旦声明了构造函数，那么默认构造函数将不会被创建。若此时没有不带输入参数的构造函数，那么就不能创建实例而不初始化(会报错)。故一般而言会补上上述的一个重载构造函数。

构造函数中如果有其他对象的作为成员函数(内嵌对象)，那么会先调用这些析构函数，然后再调用主函数的。

特别注意，不能使用typedef简写的方法来搞构造函数名，但是define方法可以。



举例：

```c++
Stock(const string &co, long n=0, double pr=0.0);
Stock::Stock(const string &co, long n, double pr)
{
    company = co;//company,shares,share_val是成员属性
    if(n<0) cerr<<"You cannot input a negative;\n";
    else shares = n;
    share_val = pr;
    set_tot();//成员函数
}
```

显式调用构造函数：

```c++
Stock food = Stock("World Cabbage", 250, 1.25);
```

隐式调用构造函数：

```c++
Stock food("World Cabbage", 250, 1.25);
```

> 也可以用大括号的方法调用。

new方法显式调用：

```c++
Stock *food = new Stock("World Cabbage", 250, 1.25);
```

无法使用对象来调用构造函数，构造函数构造对象前对象不存在。



如：

```c++
public:
	ll x, y;
	po(ll x, ll y) :x(x), y(y) { cout << "build Po: " << x << ',' << y << endl; }
	po(po& a) :x(a.x), y(a.y) { cout << "copy Po: " << x << ',' << y << endl; }
};
class li
{
public:
	po a, b;
	li(po x, po y) :a(x), b(y) 
	{
		/*a = x;b = y;*/ //会报错：没有合适的默认构造函数
		cout << "build line:" << a.x << ',' << a.y << " ; " << b.x << ',' << b.y << endl;
	}
	li(li& k) :a(k.a), b(k.b)
	{
		cout << "copy line:" << a.x << ',' << a.y << " ; " << b.x << ',' << b.y << endl;
	}
};
po a1 = { 1,1 }, a2 = { 2,2 }, a3 = { 3,3 }, a4 = a1;
cout << endl;
li s1 = { a1,a2 }, s2 = { a3,a4 }, s3 = s1;
```



##### 默认构造函数

如果没有提供任何构造函数，则自动提供默认构造函数：

```c++
Stock::Stock() {}
Stock food;//构造对象
```

当提供了构造函数时，如果想要创建未初始化的对象，必须提供如上的默认构造函数，或使用函数重载定义另一个构造函数，如：

```c++
Stock::Stock()
{
    company = "NONAME";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
```

在设计类时，通常应提供对所有类成员做隐式初始化的默认构造函数，如上。

那么便可：

```c++
Stock first;//隐式调用默认构造函数
Stock first = Stock();//显式调用
Stock *first = new Stock;//隐式调用
Stock first("123");//非默认构造函数的隐式形式
Stock first();//同
```

不过仍然是使用默认参数定义所有参数可能会比较方便。

可以显式声明使用默认函数：

```c++
Someclass() = default;
```

###### 委托构造函数

构造函数包含其他构造函数已有的代码。

```c++
//声明无所谓顺序，如N();N(int);N(int, double);...
N::N(int kk, double xx, string stt):k(kk),x(xx),st(stt);
N::N():N(0,0.01,"Oh");
N::N(int kk):N(kk,0.01,"oh");
```



##### 类型转换

如果拥有只有一个参数的构造函数或因为有默认参数而可以只填写一个参数的构造函数，那么可以如下对一个类构造：

```c++
Stock second = "456";
```

也可以这样传入参数代替类参数。或返回这样的值而转成返回这样的类。

如果不希望进行上述的隐式转换，那么可以使用关键字explicit来声明构造函数。(那么有 类名(参数)和变量名(参数)两种方法，大括号和等号都不可以)

在自动转换中，int可以转为long/double，所以有这两种构造函数而使用int来转换可能会出现二义性。

如果需要逆运算，即把类实例转换一个普通变量，需要重载类型转换的转换函数，注意以下几点：

- 转换函数必须是类方法
- 转换函数不能指定返回类型
- 转换函数不能有参数

举例如下：

```c++
operator int() const;
Stock::operator int() const 
{return int(0.5+shares);}
```

那么将可以执行如下示例：

```c++
int a = stock1;
cout << int(stock1);
```

在不存在二义性时，也允许逆转换的自动类型转换。也允许使用explicit关键字来限制隐式转换。

##### 复制构造函数

原型：

```c++
Stock(const Stock&);
```

一般会有默认复制构造函数，将逐个复制非静态成员(成员复制也称浅复制)。是按值复制。

如果一些类成员是使用new初始化的、指向数据的指针，vector等动态数据结构，必须定义复制构造函数，进行深复制。浅复制只复制指针信息。

调用：

```c++
Stock b(a);//a,b都是Stock类实例
Stock c=a;
```

函数调用对象实例是传值，所以会调用一次复制构造函数。而调用对象引用不会。由于函数内变量生存期缘故，返回一个对象时也调用复制构造函数。

例如：

```c++
class ts
{
public:
	ll x, y;
	ts() {}
	ts(ll a, ll b) :x(a), y(b) {}
	ts(const ts& a) :x(a.x), y(a.y + 1){cout << x << ends << y << endl;}
};//不加const会炸
ts f(ts y){return y;}//传入复制一次，返回复制一次
ts a = { 5,5 };
ts b = f(a);//b为5 7
```

> 部分编译器会针对复制构造函数做优化，避免不必要的复制构造函数调用。

##### 成员初始化列表

对于常量可以初始化而不能赋值。对于const数据成员，使用如下方法：

举例：(qsize为常量)

```c++
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}
```

或：

```c++
Queue::Queue(int qs):qsize(qs), front(NULL), rear(NULL), items(0) {};
```

注意：

- 这种格式只能用于构造函数
- 必须用这种格式才初始化非静态const数据成员(before C++11)
- 必须用这种格式初始化引用数据成员和没有默认构造函数的内嵌对象
- 数据成员被初始化顺序与类声明顺序相同

##### 显函数

关联字explicit，表明只可以显式转换调用

，否则可以隐式转换(下面第二行三种)

```c++
f(po(1));
f((po)1); f(static_cast<po> 1); f(1);
```

#### 析构函数

对象过期时，程序自动调用一个特殊的成员函数，即析构函数。

析构函数没有参数，可以没有返回值和声明类型，原型和定义如下：

```c++
~Stock();
Stock::~Stock(){}
```

上述定义是默认析构函数的定义。

通常不应该在代码中显式调用析构函数。如果创建了静态存储类对象，则析构函数在程序结束时自动被调用；如果创建自动存储类对象，则在程序执行完代码块时自动被调用；如果通过new创建，那么它将驻留在栈内存或自由存储区，当delete释放内存时被调用。如果创建临时对象完成特定操作，结束对象时自动调用。

临时调用的例子：

```c++
Stock s1 = Stock("123", 4, 5);//初始化，可能会创建临时对象，也可能不会
s1 = Stock("456", 1, 2);//临时调用，创建了临时对象，且s1其实会被改变，在这一行结束那就调用一次析构函数了。
```

备注：

1. 析构函数可以是虚函数。主对象的析构函数执行后，内嵌对象的析构函数被执行(顺序与在组合类定义出现的次序相反)。

2. 所有对象实例会在主函数return 0前调用析构函数，且次序与构造函数次序相反。

   例如：

   ```c++
   class line
   {
   public:
       line(const point&p1, const point& p2):p1(p1),p2(p2),len(-1){cout<<"born!"<<p1.x<<" "<<p1.y<<endl;}
       ~line(){cout<<"dying!"<<p1.x<<" "<<p1.y<<endl;}
   private:
       point p1,p2;
   };
   line xy(x,y);
   line yx(y,x);//显然等效于line xy(x,y),yx(y,x);
   cout<<"gg\n";
   ```

3. 浅复制得到一个类，如果类中有类成员，那么有可能会在析构时先后调用两次析构造成错误

#### this指针

指向用来调用成员函数的对象(this被作为隐藏参数传递给方法，对常函数而言这就是个前导常指针)。一般来说，所有的类方法都将this指针设置为调用它的对象的地址。例如，在一个成员函数中，下面的代码：

```c++
tot_val = share_val * shares;
```

其实就是：

```c++
this->tot_val = this->share_val * this->shares;
```

每个成员函数（包括构造函数和析构函数）都有this指针。如果需要引用整个调用对象，则可以用*this。如果在函数后面使用const将this限定，那么不能使用this修改对象的值。

this是对象的地址，是对象本身；*this是指针指向的值。例如，可以这样写一个比较函数，其中返回值为Stock&表示返回调用对象本身而不是其副本：

```c++
const Stock& topval(const Stock &s) const;
const Stock& Stock::topval(const Stock &s) const
{
    if(s.total_val > total_val) return s;
    else return *this;
}
```

使用示例：

```c++
const Stock *top = &stocks[0];
for(int st=1;st<STKS;st++)
    top = &top->topval(stocks[st]);
```

#### 作用域

类中定义的名称(类数据成员名、类成员函数名)作用域是整个类。所以调用公有成员函数，必须通过对象；定义成员函数必须使用作用域解析运算符。

使用类成员名，根据上下文使用直接成员运算符(.)、间接成员运算符(->)或作用域解析运算符。

##### 指针/引用

指向/左值引用公有成员：

```c++
int *p=&xy.g;
int &pp=xy.g;
```

##### 静态变量

在类声明中声明常量只是描述了对象的形式而无创建对象，所以创建前并无效果。要达到整个类共用的常量，可以如下操作：

方法1：枚举，作用域为整个类。

```c++
enum {MAX = 9999};
double costs[MAX];//都是private里的
```

方法2：使用static

```c++
static const int MAX = 9999; //不const不能过
double costs[MAX];//都是private里的
```

如果要在外部初始化(内部声明)，则：(可以不const,声明const的也可以)

```c++
int CLASSNAME::MAX = 9999;
```

如果是模板类，则：

```c++
template<typename T>
int CLASSNAME<T>::MAX = 9999;
```

举例：

```c++
class xy 
{
public:
	static int cnt;
	xy() { ++cnt; }
    ~xy() {--cnt; }//类实例数的计数需要在析构函数减去
};
int xy::cnt = 10;//注意要写int
xy a, b, c;
cout << xy::cnt;
```

指向/左值引用公有静态变量：

```c++
int *p=&line::cnt;
int &p=line::cnt;
```

指针指向公有静态成员函数：

```c++
返回值类型 (*指针名字)(参数)=类名::静态成员函数名
```

如:

```c++
private:
 static double show(int k){return 0.0;}
...
//main
double (*pptr)(int)=line::show;
```



#### 继承

特性从一个类(**基类**)传递给另一个类(**派生类**)的语言特性为继承。基类可以引用指向派生类的对象而无需进行强转，所以可以定义接受基类引用作为参数的函数，而传入基类或派生类作为参数。

继承分为公有继承、保护继承和私有继承（默认）。

> 通常会有许多抽象基类(ABC, abstract base class)。
>
> 可以从ABC派生出具体(concrete)类。

使用本身是另一个类的对象的类成员的方法称为包含(containment)、组合(composition)或层次化(layering)。包含、私有继承、保护继承用于实现has-a关系。选择has-a或is-a一般根据实际情况而定。

一个子类可以有一个到多个父类(单继承/多继承)。在多重继承中，有直接基类和间接基类。

##### 公有继承

公有继承最常用，建立is-a(is-a-kind-of)关系，即派生类对象也是基类对象，可以对基类对象执行的任何操作对派生类都可行。

公有继承的基类公有成员和保护成员保持不变，私有成员不可被派生类访问。

公有继承不建议建立has-a,is-implemented-as-a,uses-a,不能建立is-like-a关系。

> 对于非多态类的公有继承需要慎重，一般采用其他继承

公有派生：

```c++
class c2 : public c1
{
    ...
};
```

那么c2对象将具有以下特征：

- 派生类对象存储了基类的数据成员(派生类继承了基类的实现)
- 派生类对象可以使用基类的方法(派生类继承了基类的接口)

构造函数声明的写法：(构造函数不能被继承)

```c++
c2 (一堆参数);
c2 (新的参数, c1 &cc1);//重载
```

函数定义：

```c++
c2::c2 (一堆参数) : c1(这些参数) {...;}
c2::c2 (新参数, c1 &cc1) : c1(cc1)
{
    对新参数和新数据成员的操作;//当然也可以用列表的
}
```

派生类不能直接访问基类的私有成员，必须通过基类的方法访问。具体而言，派生类构造函数必须使用基类构造函数。会自动调用基类的析构函数。

创建派生类对象时，程序首先创建基类对象。如果不调用基类构造函数，程序将使用默认的基类构造函数。

派生类对象过期时，先调用派生类析构函数，再调用基类析构函数。

基类指针可以在不进行显式类型转换情况下指向派生类指针；基类引用可以在不进行显式类型转换情况下引用派生类对象。但基类指针或引用不能调用派生类的方法。

可以将派生类隐式或显式复制给基类，调用默认复制构造函数、隐式重载赋值运算符。

举例：

```c++
class e0
{
public:
    int a,b;
    e0(int a, int b):a(a),b(b) {}
};
class e1:public e0
{
public:
    int c;
    e1(int a, int b, int c):e0(a,b),c(c) {}
};
class e2:public e1
{
public:
    int d;
    e2(int a, int b, int c, int d):e1(a,b,c),d(d) {}
};
class e3
{
public:
    int e;
    e3(int e):e(e) {}
};
class e4:public e2,public e3
{
public:
    int f;
    e4(int a, int b, int c, int d, int e, int f):e2(a,b,c,d),e3(e),f(f) {}
};
signed main()
{
    e4 y(1,3,5,7,9,11);
    printf("%d %d %d %d %d %d\n",y.a,y.b,y.c,y.d,y.e,y.f);
    return 0;
}
```



###### 多态

可以用两种机制实现多态公有继承：

- 在派生类重定义基态方法
- 使用虚方法

声明虚方法，使用关键字virtual在基类和派生类的函数声明，定义不用，则会根据对象的类型而不是引用或指针的类型选择方法。

将派生类引用/指针转为基类的，被称为向上强制转换(upcasting)，使得公有继承不需要显式类型转换。反之是向下强制转换(downcasting)，在不使用显式类型转换时是不允许的。

> 也通常会为基类声明一个虚析构函数，确保释放派生对象时，按正确的顺序调用析构函数。如果析构函数不是虚的，只会调用对应于指针类型的析构函数。所以虚析构函数可以确保正确的析构函数被调用。

举例如下：

```c++
virtual void show() const;//c1,c2均有
c1 a(3);
c2 b(4);//a是基类对象,b是派生类对象
c1 &cref = a;
cref.show();//c1::show
c1 &cref = b;
cref.show();//c2::show
```

注意，在派生类方法中调用基类方法(通常很常用)，必须使用作用域解析运算符，否则将形成递归。

> 联编(binding)是编译器将源代码中函数调用解释为执行特定函数代码快的过程。因为虚函数的存在，使得静态(/早期)联编转换成了在程序运行时选择正确的虚方法的动态(/晚期)联编。使用静态联编效率更高。编译器处理虚函数时会给每个对象添加一个保存了一个指向函数地址数组(虚函数表，virtual function table, vtbl)的隐藏成员。

- 基类方法声明使用virtual使在基类以及所有派生类(含派生类派生的类)的该方法都是虚方法

- 构造函数不能是虚函数，析构函数应当是虚函数。一般习惯哪怕不用也如下定义：

  ```c++
  virtual ~BaseClass() {}
  ```

- 友元不能是虚函数。只有成员才能是虚函数。但友元函数可以使用虚成员函数。

- 在继承类重载成员函数，会隐藏基类成员函数，不构成多态。所以如果重定义继承的方法，应确保与原型完全相同；如果返回类型是基类引用或指针，则可以修改为指向派生类的引用或指针：返回类型协变(covariance of return type)，允许返回类型随类类型变化而变化。不适用于参数。

- 如果基类声明被重载了，应该派生类重定义所有基类版本。否则会被隐藏。如果不需要修改，新定义可以只调用基类版本。

###### 纯虚函数

pure virtal function。声明方法：结尾处为=0，如：

```c++
virtual double Area() const=0;//Area没有定义，虽然允许有
virtual void Withdraw(double amt) = 0;
```

类声明包含纯虚函数时，不能创建该类的对象。包含纯虚函数的类只用作基类。ABC至少包含一个纯虚函数。

在原型中使用=0指出类是抽象基类，类中可不定义该函数。

###### override

覆盖一个虚函数。不是关键字(final同理)，可以用作变量名。用在派生类。

```c++
virtual void f(char *ch) const override {...;}
```

###### final

禁用派生类覆盖特定的虚方法。用在基类。

```c++
virtual void f(char ch) const final {...}
```

##### 动态内存分配

如果基类使用了动态内存分配，必须包含析构函数、复制构造函数和重载赋值运算符：

```c++
virtual ~baseC();
baseC(const baseC &rs);
baseC& operator=(const baseC &rs);
```

如果这个基类的派生类没有使用动态内存分配，则它不需要定义这些。

如果派生类用了动态内存分配，必须定义显式析构函数、复制构造函数和重载赋值运算符。

##### 友元

友元不是成员函数，不能使用作用域解析运算符指出使用哪个函数。以重载<<为例，可以如下操作：

```c++
friend ostream& operator<<(ostream &os, const bc &rs);//基类声明
friend ostream& operator<<(ostream &os, const cc &rs);//继承类声明
ostream& operator<<(ostream &os, const bc &rs)
{
    os<<rs.x<<","<<rs.y;
    return os;
}//基类定义
ostream& operator<<(ostream &os, const cc &hs)
{
    os<<(const bc&)hs;//调用上面的友元函数
    os<<","<<rs.id;//新的家伙
    return os;
}
```

##### 私有继承

> 一般情况应用较少

has-a关系实现途径。基类公有成员和保护成员都将成为派生类的私有成员，基类的私有成员不可以被访问。基类方法能在派生类成员函数使用。第三代类不能够使用基类的公有方法。

私有继承创建未被命名的继承对象并添加到类中。子对象(subobject)表示通过继承或包含添加的对象。

使用关键字private或省略，来使用私有继承。

```c++
class student : private string, private valarray<double>
```

如果希望基类工具公有，可以使用作用域解析运算符：

```c++
const string& Student::Average() const
{return ARR::sum()/ARR:size();}//ARR为valarray基类
```

如果要使用基类对象本身，应该使用强转：

```c++
const string& Student::Name() const
{return (const string&)*this;}//string是基类之一
```

友元不属于类，通过显式转换可以调用正确的函数：

```c++
ostream& operator<<(ostream &os, const Student &stu)
{
    os<<(const string &) stu <<endl;
    return os;
}
```

上述例子，引用stu不会自动转为string引用，因为私有继承若不显式类型转换，不能将指向派生类的引用或指针赋给基类引用或指针。即使是公有继承，不转换也会导致递归。

下两种情况可能比较适合私有继承而不是包含类：

- 需要重新定义虚函数
- 访问保护成员



##### 保护继承

关键字protected。

```c++
class student :protected string, protected valarray<double>;
```

基类的公有成员和保护成员都成为派生类保护成员，私有成员不可以被访问



。第三代类可以使用。

##### 多重继承

multiple inheritance, MI。每个基类都要加关键字，除非是private可以省略。共有MI也表示is-a关系。

如果多个直接基类共同来自于一个间接基类，派生类要调用间接基类的成员，那么需要通过其中一个直接基类的作用域解析运算符来调用。不能够通过using的方法，只能每次使用时都作用域解析，例如：

```c++
class c0
{
public:
    int x=5;
    void f(int y){printf("c0 %d\n",x*y);}
};
class c1:public c0{};
class c2:public c0{};
class c3:public c1,public c2{};
signed main()
{
    c3 c;
    c.c1::x=6,c.c2::x=5;//两个不同的变量
    printf("add %d\n",c.c1::x+c.c2::x);//11
    c.c1::f(3);
    return 0;
}
```

```c++
class c1
{
public:
    c1(ll x = 0) : v0(x) {}
    ll v0;
};
class c2 : public c1
{
};
class c3 : public c1
{
};
class c4 : public c2, public c3
{
public:
    c4(ll x = 0) { c2::v0 = 3; }; //不允许初始化列表用c2::v0，不允许调用c1()作为初始化列表
};
signed main()
{
    c4 q(1);
    cout << (++q.c2::v0);
    return 0;
}
```



##### 虚基类

如果多个直接基类共同来自于一个间接基类，同名数据成员在内存中有多个副本，同一个函数名有多个映射，造成了内存浪费。如果设为虚基类，那么就只有一个副本/映射。而且在派生类中，可以直接不使用作用域解析运算符直接访问虚基类(间接基类)的成员(函数/属性)。

使用举例如下：

```c++
class c0
{
public:
    int x=5;
    void f(int y){printf("c0 %d\n",x*y);}
};
class c1:virtual public c0{};
class c2:public virtual c0{};
class c3:public c1,public c2{};
signed main()
{
    c3 c;
    c.c1::x=6,c.c2::x=1;//都是同一个变量，最后为1
    printf("add %d\n",c.c1::x+c.c2::x);//1+1=2
    c.c2::f(3);//1*3=3
    c.x=10;//此时可以如此调用了
    c.f(-2);
    return 0;
}
```



> 假设A是基类，B、C是A的派生类，D是B、C的派生类，那么，当如下操作时会出现二义性：
>
> ```c++
> D x;
> A *p = (A*) &x;
> ```

为解决上述问题，可以使用虚基类(virtual base class),作用于B和C：

```c++
class B : virtual public A
class C : public virtual A  //关键字顺序无关
class D : public B, public C
```

则需要把原来的D的构造函数：

> ```c++
> D(const A &wk, int p, int v):B(wk,p),C(wk,v){}
> ```

改为：

```c++
D(const A &wk, int p, int v):A(wk),B(wk,p),C(wk,v){}
```

举例如下：

```c++
class d0
{
public:
    int a,b;
    d0(int aa, int bb):a(aa),b(bb){}
};
class d1:virtual public d0
{
public:
    int g1;
    d1(int aa, int bb, int gg):d0(aa,bb),g1(gg){}
};
class d2:virtual public d0
{
public:
    int g2;
    d2(int aa, int bb, int gg):d0(aa,bb),g2(gg){}
};
class d3:virtual public d0
{
public:
    int g3=-5;
    d3(int aa, int bb):d0(aa,bb){}
};
class d4:public d1, public d2, public d3
{
public:
    int k;
    d4(int aa, int bb, int g1, int g2, int kk):
        d0(aa,bb),d1(aa,bb,g1),d2(aa,bb,g2),d3(aa,bb),k(kk) {}
};
signed main()
{
    d4 z(1,2,3,4,5);
    printf("%d %d %d %d %d %d\n",z.a,z.b,z.g1,z.g2,z.g3,z.k);
    return 0;
}
```

如果类有间接虚基类，除非只需要使用该虚基类默认构造函数，否则必须显式调用该虚基类的某个构造函数。注意对于非虚基类上面的写法非法。

MI中方法的二义性可以通过函数重载或using解决。

构造函数执行顺序：

- 如果有直接/间接虚基类，先执行它的构造函数
- 有其他基类，按照声明顺序执行(不再执行它们的虚基类)
- 初始化类的成员
- 构造函数程序体

> 更多例子：
>
> 1) 不使用初始化列表调用基类构造
>
> ```c++
> #include <bits/stdc++.h>
> typedef long long ll;
> #define re register
> using namespace std;
> class b0
> {
> public:
>     b0(ll x = 0) : v0(x) {}
>     ll v0;
> };
> class b1 : virtual public b0
> {
> public:
>     b1(ll x = 0) : v1(x) { v0 = x * x; }
>     ll v1;
> };
> class b2 : public virtual b0
> {
> public:
>     b2(ll x = 0) : v2(x) { v0 = x + 100; }
>     ll v2;
> };
> class b3 : public b1, public b2
> {
> public:
>     b3(ll x = 0) : v3(x) { v0 = pow(2, x); }
>     //而非virtual不允许操作v0,
>     //非virtual不允许通过初始化列表跨级访问成员
>     //允许的操作：b3(ll x = 0) : b0(x), v3(x) {}，而非virtual不允许
>     ll v3;
> };
> signed main()
> {
>     b1 a(3);
>     cout << a.v0 << a.v1 << endl;
>     b2 b(6);
>     cout << b.v0 << b.v2 << endl;
>     b3 c(9);
>     cout << c.v0 << c.v3 << endl;
>     return 0;
> }
> ```
>
> 



##### 继承构造函数

只有一个基类时，不声明构造函数则默认使用基类的。

基类有多个不同的构造函数，可以在派生类中：

```c++
using baseC::baseC;
```

其他函数同理。当使用了作用域解析运算符时，可以并存两个参数不同的重载函数。即使用同一个函数名根据参数的不同可以调用两个不同的重载函数。例如：

```c++
#include <bits/stdc++.h>
using namespace std;
class b1
{
public:
    int x;
    void f(int y){printf("b1 %d\n",x+y);}
    //假设f无参数，下面有无参数的调用，没有using时直接报错
};
class b2:public b1
{
public:
    using b1::f;//没有这一行时，下面都调用b2::f
    void f(double y){printf("b2 %lf\n",x+y);}
};
signed main()
{
    b1 a; a.x=10;
    b2 b; b.x=100;
    b.f(1);
    b.f(-1.0);
    return 0;
}
```



派生类构造函数执行顺序：

- 调用基类构造函数(按继承声明顺序从左到右)
- 对派生类新增成员对象初始化(顺序为类中声明顺序)
- 执行派生类构造函数体内内容

举例：

```c++
class b1
{
public:
    b1(int i){cout<<"b1 "<<i<<endl;}
};
class b2
{
public:
    b2(int i){cout<<"b2 "<<i<<endl;}
};
class b3
{
public:
    b3(int i){cout<<"b3 "<<i<<endl;}
};
class dd:public b2,public b1,public b3
{
public:
    b1 x1;
    b2 x2;
    b3 x3;
    dd(int a, int b, int c, int d):b1(a),x1(a*a),x2(b*b),x3(c*c),b2(b),b3(c)//必须6个都被初始化，否则报错
        {cout<<"dd "<<a+b+c+d<<endl;}
};//先b2 b1 b3 然后按public中x1,x2,x3顺序构造，最后输出dd，即参数列表顺序不影响结果
dd df(1,3,6,10);//析构函数的顺序与上面的顺序完全相反
```

##### 类型兼容规则

- 派生类对象可以隐式转化为基类对象

- 派生类对象可以初始化基类的引用

  ```c++
  fa &a=b;//a(fa)是基类，b是派生类
  ```

- 派生类指针可以隐式转化为基类指针

当派生类声明了一个同名函数时，即使参数列表与基类的同名函数不一致，基类的所有同名函数都将被隐藏。但是可以使用作用域解析运算符重新调用基类的函数。

```c++
//写法一：
class bx
{
public:
    void prt(int x, int y){cout<<x*y;}
};
class by:public bx
{
public:
    void prt(int x){cout<<x;}
};
bx bbx;
by bby;
bby.prt(0);
bby.bx::prt(2,3);
```

```c++
//写法二
class bx
{
public:
    void prt(int x, int y){cout<<x*y;}
};
class by:public bx
{
public:
    using bx::prt;
    void prt(int x){cout<<x;}
};
bx bbx;
by bby;
bby.prt(0);
bby.prt(2,3);
```



#### 嵌套

一个类声明另一个类，称为嵌套类(nested class)。

```c++
template <typename T>
class beta
{
private:
    class hold//当然放外边更好，也可以只声明如class hold;
    {
    private:
        V val;
    public:
        hold(V v=0) : val(v) {}
        void show() const {cout<<val<<endl;}
        V value() const {return val;}
    };
    hold<T> q;
    hold<int> n;
public:
    beta(T t, int i):q(t), n(i) {}
    template<typename U>
    U blab(U u, T t) 
    {return (n.Value()+q.Value())*u/t;}
    void Show() const {q.show(); n.show();}
};
beta<double> guy(3.5,3);
guy.show();
cout<<guy.blab(10,2.3)<<endl;
```

对于只声明，后定义的情况，如下定义：

```c++
template<typename T>
	template<typename V>//必须这样写
	class beta<T>::hold
    {
    private:
        V val;
    public:
        hold(V v=0) : val(v) {}
        void show() const {cout<<val<<endl;}
        V Value() const {return val;}
    };
template<typename T>
	template<typename V>
	V beta<T>::blab(V u, T t)
    {return (n.Value()+q.Value())*u/t;}
```

如果嵌套类A在私有部分声明，只有类内作用域。如果在保护部分声明，派生类和本类B内有作用域。如果公有部分声明，外部也可以使用，但必须包含类限定符。如：B::A var;

#### 虚函数

虚函数是类成员函数。

```c++
virtual 函数类型 函数名(形参表)
```

虚函数声明只能出现在类定义的函数原型声明中，不能在成员函数实现时

不能声明虚构造函数，可以声明虚析构函数

满足如下三点时，触发多态：

- 赋值兼容规则
- 声明虚函数
- 成员函数调用/指针、引用访问虚函数

> 若使用对象名访问虚函数，进行静态绑定；虚函数一般不声明为内联函数，一般是动态绑定

使用示例如下：

```c++
#include <bits/stdc++.h>
using namespace std;
class b1
{
public:
    virtual void display() const;
};//假设不写virtual，则f都是b1 dp
void b1::display() const {cout<<"b1 dp\n";}//不必须放外边，但放外边时不加virtual,下同
class b2:public b1
{
public:
    void display() const;
};//这个和b3的声明写不写virtual无所谓
void b2::display() const {cout<<"b2 dp\n";}
class b3:public b2
{
public:
    void display() const;
};
void b3::display() const {cout<<"b3 dp\n";}
void f(b1* ptr) {ptr->display();}//必须传指针,传对象不会引发多态
signed main()
{
    b1 x1; b2 x2; b3 x3;
    f(&x1); f(&x2); f(&x3);//不要漏了&
    x1.display(); x2.display(); x3.display();
    return 0;//甚至可以x3.x2::display()
}
```

> 分析：
>
> - b1,b2,b3是同一类族共有派生，满足赋值兼容规则
> - 派生类未显式给出虚函数声明，遵循下列规则判定函数成员是否是虚函数：
>   - 函数与基类虚函数是否同名、有相同参数个数和类型、相同返回值或满足赋值兼容规则的指针/引用型返回值
> - 满足上述条件后，派生类函数确认为虚函数，覆盖基类虚函数，隐藏与基类同名的所有其他重载

在派生类构造时调用基类构造函数内的虚函数时，必然指向基类，析构函数也指向基类

多个虚函数举例：

```c++
class d1
{
public:
    void dp() const { cout << "qwq!\n"; }
};
class d2 : public d1
{
public:
    virtual void dp() const { cout << "d2\n"; }
};
class d3 : public d2
{
public:
    void dp() const { cout << "d3\n"; }
};
class d4 : public d2
{
public:
    void dp() const { cout << "d4\n"; }
};
class d5 : public d1
{
public:
    void dp() const { cout << "d5\n"; }
};
void f(d1 &a) { a.dp(); }
void g(d2 &a) { a.dp(); }
signed main()
{
    d1 a1;
    d2 a2;
    d3 a3;
    d4 a4;
    d5 a5;
    f(a1);
    f(a2);
    f(a3);
    f(a4);
    f(a5);
    g(a2);
    g(a3);
    g(a4);
    return 0;
}
```

有效性问题，可以用动态指针判定：

```c++
#include <bits/stdc++.h>
typedef long long ll;
#define re register
using namespace std;
class b0
{
public:
    virtual void f() { cout << "b0 f\n"; }
};
class b1 : public b0
{
public:
    void f() { cout << "b1 f\n"; }
    virtual void g() { cout << "b1 g\n"; }
};
class b2 : public b1
{
public:
    void g() { cout << "b2 g\n"; }
};
void f(b0 *p)
{
    p->f();
    b1 *q = dynamic_cast<b1 *>(p);
    if (q)
        q->g();
}
signed main()
{
    b0 a0;
    b1 a1;
    b2 a2;
    f(&a0);
    f(&a1);
    f(&a2);
    return 0;
}
```



##### 虚析构函数

虚析构函数应用于灵活处理delete问题，如果通过基类指针创建了派生类对象，然后需要删除基类指针对象时，需要使用虚函数才能触发派生类析构函数，否则只会触发基类的。

```c++
#include <bits/stdc++.h>
using namespace std;
class b1
{
public:
    virtual ~b1();//不virtual的话f(x)不执行~b2只执行~b1，virutal才都执行
};
b1::~b1(){cout<<"b1 dying\n";}
class b2:public b1
{
public:
    int *p,n;
    b2(int n):n(n){p=new int(n);}
    ~b2();//必须有
};
b2::~b2() {delete p; cout<<"b2 dying\n";}
void f(b1* x){cout<<"ro sth...\n"; delete x;}
signed main()
{
    b1 *x=new b2(6);
    f(x);
    b2 *y=new b2(7);
    cout<<y->n;//但是不可以x->n
    f(y);
    return 0;
}
```

##### 纯虚函数

纯虚函数是基类中声明的虚函数，不定义具体操作内容，派生类自行给出定义，格式：

```c++
virtual 函数类型 函数名(形参表)=0;
```

基类纯虚函数不可以给出函数的实现部分。URL为abstract构造型。

**抽象类**是含纯虚函数的类。抽象类的意义是统一各派生类的接口。抽象类无法实例化。但允许创建抽象类的指针和引用，实现多态。

```c++
#include <bits/stdc++.h>
using namespace std;
class b1
{
public:
    virtual void dp() const=0;
};
class b2:public b1
{
public:
    void dp() const;
};
void b2::dp() const {cout<<"b2 dp\n";}
class b3:public b2
{
public:
    void dp() const;
};
void b3::dp() const {cout<<"b3 dp\n";}
void f(b1* p) {p->dp();}
signed main()
{
    b3 x3; b2 x2; f(&x2); f(&x3);
    return 0;
}
```



#### RTTI

运行阶段类型识别Runtime Type Identification,只适用于包含虚函数的类。

- 转换前必须是指向多态类型的指针/引用

  > 多态类型有虚表，所以支持RTTI

- dynamic_cast使用一个指向基类的指针生成一个指向派生类的指针；如果不可行，返回0即空指针；如果转引用不可行，会抛出异常

- typeid返回一个指出对象的类型的值

- type_info存储有关特定类型的信息

- 可以转换为void指针，具体步骤是先转为实际指针，然后再转成void指针

```c++
*pg = new SuperbClass(1);
if(ps = dynamic_cast<SuperbClass *>(pg))
    cout<<...;
```

dynamic_cast使得类层次结构进行向上转换。

使用举例如下：

```c++
#include <bits/stdc++.h>
using namespace std;
class b1
{
public:
    virtual void f1(){cout<<"b1 dp\n";}
    virtual ~b1(){}
};
class b2:public b1
{
public:
    virtual void f1(){cout<<"b2 dp\n";}
    virtual void f2(){cout<<"b2 dfs\n";}
};
class b3:public b2
{
public:
    virtual void f1(){cout<<"b3 dp\n";}
    virtual void f2(){cout<<"b3 dfs\n";}
};
void f(b1* p)
{
    p->f1();
    b2* d=dynamic_cast<b2*>(p);
    if(d) d->f2();
}
signed main()
{
    b1 x1; b2 x2; b3 x3;
    f(&x1); f(&x2); f(&x3);//最后输出了b3 dfs
    return 0;
}
```





typeid返回对type_info的引用，后者在typeinfo头文件

```c++
typeid(Myclass) == typeid(*pg)
```

若空指针，引发bad_typeid异常



#### 函数符

函数对象(function object)是行为类似于函数的对象，是泛化的函数。普通函数和重载了operator()的类对象都是函数对象。

使用STL的函数对象，需要头文件functional。

functor，是以函数方式与()结合使用的任意对象，包括函数名、指向函数的指针和重载了()的类对象。

> 例如：
>
> ```c++
> class Linear
> {
> private:
>     double slope, y0;
> public:
>     Linear(double s1_ = 1, double y_ = 0):slope(s1_), y0(y_) {}
>     double operator()(double x){return y0+slope*x;}
> };
> Linear f1;
> Linear f2(2.5,10.0);
> cout<<f1(12.5)<<endl<<f2(0.4);
> ```

函数符依据参数数目可以分类为：

- 生成器(generator)不用参数的函数符。
- 一元函数(unary function)用一个参数可以调用的函数符。返回bool值的一元函数是谓词(predicate)。
- 二元函数(binary function)用两个参数可以调用的函数符。返回bool值的二元函数是二元谓词(binary predicate)。

函数符可以当成函数参数，操作格式是类名()，举例如下：

```c++
class mulClass
{
public:
    ll operator()(ll x, ll y) const { return x * y; }
};
ll a[] = {1, 2, 3, 4, 5};
cout << accumulate(a, a + 5, 10, mulClass());
```





##### 预定义函数符

头文件functional，这些函数符都是内联函数

```c++
plus<double> f;
cout<<f(1,2.1)<<endl;
ll a[] = {1, 2, 3, 4, 5};
cout << accumulate(a, a + 5, 1000., divides<ll>()) << endl; //地板除
cout << accumulate(a, a + 5, 1000.0, divides<double>()) << endl; //进行运算的的不是double那也没辙
```

> 可用的函数符如下：
>
> - plus +
> - minus -
> - multiplies *(times在老式)
> - divides /
> - modulus %
> - negate -
> - equal_to ==
> - not_equal_to !=
> - greater >
> - less <
> - greater_equal >=
> - less_equal <=
> - logical_and &&
> - logical_or ||
> - logical_not !

使用举例：

```c++
class judge
{
public:
    ll v;
    judge(ll x) : v(x) {}
    bool operator<(judge k) const { return abs(v) < abs(k.v); }
    bool operator==(judge k) const { return abs(v) == abs(k.v); }
};
judge a(-2), b(2), c(1), d(-3);
judge js[] = {a, b, c, d};
sort(js, js + 4, less<judge>());
for (auto i : js)
    cout << i.v << endl;
```



##### 偏函数

使用bind

固定一个参数，用bind1st(f, 参数);

```c++
double a[] = {36,39,42,45,48}, b[5]
transform(a,a+5,b,bind1st(multiplies<double>(),2.5));
for(auto i:b) cout<<i<<" ";
```

同理有bind2nd



##### 关联类型

associated types，在STL中定义了unary\_function和binary\_function基类，原型为：

```c++
template <class Arg, class Result>
struct unary_function
{
    typedef Arg argument_type;
    typedef Result result_type;
};
template <class Arg1, class Arg2, class Result>
struct binary_function
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};
```



##### 函数适配器

作用：将一种函数对象转化为另一种符合要求的函数对象，可以分为四类：

- 绑定适配器 bind adaptor
- 组合适配器 composite adaptor
- 指针函数适配器 pointer function adaptor
- 成员函数适配器 member function adaptor

STL的函数适配器如下：

- bind1st 绑定适配器 将数值绑定到二元函数的第一个参数，适配成一元函数
- bind2nd 同理
- unary_negate 组合适配器 将一元谓词返回值适配成其逻辑反
- binary_negate 同理
- pointer_to_unary_function 指针函数适配器 普通一元函数指针适配成一元函数
- pointer_to_binary_function 同理
- mem_fun_t 成员函数适配器，将无参数类成员函数适配成一元函数对象，第一个参数为该类的指针类型
- mem_fun_ref_t 第一个参数为该类的引用类型
- mem_fun1_t 适配成二元
- mem_fun1_ref_t 同理
- const_mem_fun_t 无参数类常量成员函数适配成一元函数对象，第一个参数是该类常量指针
- const_+其他三个同理



函数适配器辅助函数：

- bind1st 辅助构造bind1st适配器实例
- bind2nd
- not1
- not2
- prt_fun 辅助构造一般函数指针的pointer_to_u(bi)nary_function适配器实例
- mem_fun 辅助构造mem_fun_t等成员函数适配器实例，返回一元/二元函数对象
- mem_fun_ref 同理



举例：

```c++
ll a[] = {580, 581, 578, 582};
auto res = find_if(a, a + 4, bind2nd(greater<ll>(), 580));
if (res == a + 4)
    cout << "nth fi.d\n";
else
    cout << "i pos " << (res - a) << " wo v=" << *res << endl;
```

```c++
inline bool co_prime(ll a, ll b) { return 1 == __gcd(a, b); }
ll a[] = {2, 87, 581, 5800, 97};
auto p = find_if(a, a + 5, not1(bind2nd(greater<ll>(), 580)));
cout << *p << endl;
p = find_if(a, a + 5, bind2nd(not2(greater<ll>()), 580));
cout << *p << endl; //等效
auto fx = bind1st(ptr_fun(co_prime), 580);//为了可以适配
p = find_if(a, a + 5, fx);
cout << *p;
```

```c++
struct sth
{
    ll v;
    sth(ll x) : v(x) {}
    void prt() const { printf("[%d]\n", v); }
};
sth a(3), b(-2), c(1), x[] = {a, b, c};
sth *y[] = {&a, &b, &c};
for_each(x, x + 3, mem_fun_ref(&sth::prt));//一般容器ref
for_each(y, y + 3, mem_fun(&sth::prt));//指针容器不ref
```



#### 补充

成员函数属性总结表

| 函数       | 继承性 | 成员/友元 | 默认生成 | 成为虚函数 | 有无返回类型 |
| ---------- | ------ | --------- | -------- | ---------- | ------------ |
| 构造函数   | 否     | 成员      | 能       | 否         | 否           |
| 析构函数   | 否     | 成员      | 能       | 能         | 否           |
| =          | 否     | 成员      | 能       | 能         | 能           |
| &          | 能     | 任意      | 能       | 能         | 能           |
| 转换函数   | 能     | 成员      | 否       | 能         | 否           |
| ()         | 能     | 成员      | 否       | 能         | 能           |
| []         | 能     | 成员      | 否       | 能         | 能           |
| ->         | 能     | 成员      | 否       | 能         | 能           |
| op=        | 能     | 任意      | 否       | 能         | 能           |
| new        | 能     | 静态成员  | 否       | 否         | void*        |
| delete     | 能     | 静态成员  | 否       | 否         | void         |
| 其他运算符 | 能     | 任意      | 否       | 能         | 能           |
| 其他成员   | 能     | 成员      | 否       | 能         | 能           |
| 友元       | 否     | 友元      | 否       | 否         | 能           |

继承方式表

| 特征             | 公有继承             | 保护继承             | 私有继承             |
| ---------------- | -------------------- | -------------------- | -------------------- |
| 公有成员变为     | 派生类公有成员       | 派生类保护成员       | 派生类私有成员       |
| 保护成员变为     | 派生类保护成员       | 派生类保护成员       | 派生类私有成员       |
| 私有成员变为     | 只能通过基类接口访问 | 只能通过基类接口访问 | 只能通过基类接口访问 |
| 能否隐式向上转换 | 是                   | 是(只能在派生类中)   | 否                   |

### 结构体

结构体与类的区别在于，结构体的默认访问类型为public，类为private，其余完全可以使用类的内容。

> 结构体可以使用大括号赋值需要满足没有用户定义的构造函数(事实上有也可以)、基类和虚函数。//da tr

初始化：

```c++
struct st
{
    ...//同C
};
st var;//C还要写struct一次，但C++不用
st v2 = {};//同C,或者C++的话等号也可以不要了的
```



```c++
//运用举例：
#include <iostream>
using namespace std;
struct Point//结构Point
{
    int x, y;
    Point(int x=0, int y=0):x(x), y(y) {}//构造函数，等同于python的__init__
    //x=0等同于python的默认参数
    //x(x)是成员变量赋值，等效于this->x=x
    //this是指向当前对象的指针即(*this).x
};

Point operator + (const Point& A, const Point& B)
{
    return Point(A.x + B.x , A.y + B.y);
}

ostream& operator << (ostream &out, const Point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}//定义point的输出方式

int main()
{
    Point a, b(1,2);
    a.x = 3;
    cout << a+b << "\n";
    return 0;
}
```

#### 联合体

union，也可以用数据成员、成员函数、控制访问权限，默认也是public。与struct区别同C。

联合体各个对象成员，不可以有自定义构造函数、析构函数和重载复制赋值运算符，对象的子对象也都不可以有。不可以继承，不支持多态。

联合体可以不声明名称，则成员属性可以按名字直接访问。

### string

库string

```c++
<string> //在这个头文件里
```

注意：

1. string很慢，sstream更慢
2. endl很慢，'\n'更快。endl会进行一些清空缓存处理[?]



初始化构造函数：

```c++
string one("Lottery Winner!");
string two(20, '*');//类似python字符乘法
string three(one);//复制，不过当然不是指针了
string four();//空的，长度为0
string five(one, 10);//取长度复制
string six(one+1,one+10);//取区间复制
string seven(&one[1],&one[10]);//等效于six
string eight(one, 1, 16);//从下标1开始，共取16个字符
string nine = {'1', '2'};
```

输入:

```c++
cin >> str;
或getline(cin, str);
或operator>>(cin,str);//cin.operator>>(str);
```



**允许的简单运算**：

- 复制：str1 = str2

- 连接：str + str2或char  ;当然1+=也可以

- 比较(双等号、大于小于或不等号):可以string,char*同类或之间的比较；逐个比较字典序(足以到空是0，所以最小)，直至可以确认，例如：

  ```c++
  "zbc" > "ffff" 
  "zbc" > "zba"
  "zbc" > "zb"
  ```

  

取长度：length()方法 或size()方法

查找:

- find()方法或rfind()方法，可以找字符(用""或''都可以)或字符串，返回首次出现的下标rfind的首次等效于find的末次。如果找不到，返回-1。
- find_first_of(),find_last_of(),find_first_not_of(),find_last_not_of()方法，只要任何一个参数内字符符合条件，就返回下标。

反转：reverse(str.begin() ,str.end());//algorithm库

内存块大小：capacity()方法

取子串：//疑似linux不可用

- str.substr(a) 返回[a,last]的str
-  str.substr(a,b) 返回[a,a+b]的str
-  str.back() 返回最后一个字符

插入：insert(a,b) 将char数组/string b插入到位置a(原下标为a的将往后退)

统计：count(str.begin(),str.end(),charv);//algorithm

reserve(n)方法请求内存块的最小长度//da tr

与C风格互转：

- char数组转str直接赋值如：string svar = cvar
- 逆转需要用c_str()方法，方可在如printf的%s输出

其他类型转str  to_string

-  整型直接，正号省略
- 小数自带六位小数点

转其他类型

- stoi, stol, stof  //dack 头文件

在末尾增加单种字符：s.append(数目, char)



#### stringstream

在头文件sstream中

常用于处理一行内不定个数据，格式如下：

```c++
stringstream ss;
string s;
getline(cin, s);
while(ss>>a) cout<<a<<endl;//即处理数据
```

创建：stringstream 字符串流名(string变量名)

获取单个：字符串流名 >> 获取到的变量名

##### ostringstream

对应ostream，用法同理

##### istringstream

同理

可以实现其它数据类型与string互转，例如：

```c++
//int -> string
ostringstream outs; //输出字符串流
int x = 12; 
outs << x; //向输出字符串流中输出x的内容 
string a=outs.str(); //利用字符串流的str函数获取流中的内容

//string -> int
string a="12";
istringstream ins(a); //输入字符串流，流的内容初始化为a
int x; 
ins >> x; //从is流中读入并存入x中
```



### 模板

模版template。函数模板是通用的函数描述，即使用泛型来定义函数

格式：

```c++
template<typename T>//有些版本用class代替typename
```

> class和typename的区别：typename强调后面的标识符是一个数据类型，而不对其进行语法分析，凡是在模板中引用的、依赖于模板参数的数据类型，必须用typename修饰，否则不被解析为一个数据类型

需要在每个需要用到的结构定义、函数定义使用

这样将传入任意数据类型，例如：

```c++
template<typename T>
T sum(T* begin, T* end)
{
    T *p = begin;
    T ans = 0;
    for(T *p = begin; p != end; p++)
        ans = ans + *p;
    return ans;
}

//main里使用：
double a[] = {1.1, 2.2, 3.3, 4.4};
    cout << sum(a, a+4) << "\n";
```

> 使用时编译器以模板生成一个函数，称为函数模板的**实例化**，生成的函数称为**实例**

- 函数模板编译时不生成任何目标代码，实例才有目标代码(实际生成函数实例的数目是按需决定的)
- 被多个源文件引用的模板，应当同函数体放在同一个头文件，而不能只把声明放在头文件(因为编译时对每个文件分开编译)
- 函数指针指向模板实例，不可以指向模板本身

> 函数模板、类模板成员函数、类模板静态成员定义都应该放在头文件
>
> 函数模板和类模板成员函数不一定是内联函数，

当然可以有多个类型：

```c++
template <class T1, class T2>
void f(T1 x, T2 y)
{
    T1 x2 = x*x;
    T2 y2 = y/2;
    ...
}
```

可以提供默认参数：

```c++
template <class T1, class T2 = int>
```

这个在类模版里使用是很实用的。

> 当然如果某个写起来很长的template经常用，也可以typedef一下的



对结构体：

```c++
template<typename T>
struct Point
{
    T x, y;
    Point(T x=0, T y=0):x(x), y(y) {}
};

template<typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B)
{
    return Point<T>(A.x + B.x , A.y + B.y);
}

template<typename T>
ostream& operator << (ostream &out, const Point<T>& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

Point<double> c(1.1, 2.2), d(3.3, 4.4);
Point<int> b[] = {Point<int>(1,2), Point<int>(3,4), Point<int>(5,6), Point<int>(7,8)};

```

#### 具体化

具体化包含隐式实例化、显式实例化和显式具体化。//da uds

显式具体化(explicit specialization)：在使用模版的同时，对于某些特定情况，不使用模版。对给定函数，可以有非模板函数、模板函数、显示具体化模板函数及其重载版本。显示具体化原型和定义……。具体化优先于常规模板，非模板函数优先于具体化和常规模板。

显式具体化样例：

```c++
template <class T>
void swapv(T &, T &);
template <> void swapv<point>(point &, point &);//显式具体化
//或
template <> void swapv(point &, point &);
```



模板并非函数定义，但使用某数据类型的模版实例(instantiation)时函数定义，这种实例化方法称为隐式实例化(implicit instantiation)。

直接命令编译器创造特定的实例，可以显式实例化(explicit instantiation)。意思是使用这个模版生成该类型的函数定义。而具体化的意思是不要使用这个模版生成定义，应专门使用为这个类型显式定义的函数定义，这些原型有自己的函数定义。

```c++
template void swapv<point>(point &， point &);
```



不能在同一文件使用同一类型的显式实例化和显式具体化。

##### 隐式实例化

例如：

```c++
Array<int, 10> stuff;
Array<double, 5> *pt = new Array<double, 5>;
```

##### 显式实例化

例如：

```c++
template class Array<string, 100>;
```

> 对类模板的显式实例化的同时，成员函数和静态数据成员的定义也会实例化
>
> 使用该方法，可以在源文件穷举会被实例化的实例，在源文件提前定义

##### 显式具体化

是特定类型（用于替换模板中的泛型）的定义。可能需要在为特殊类型实例化时，对模板进行修改使其行为不同。可以用到显式具体化。类模板的特化。

例如：

```c++
template <typename T> SortedArray {...};
template <typename T> SortedArray <const char*>//??? 原文是<const char char*>
{
    ...
};
SortedArray<int> sa;//用第一个一般的定义
SortedArray<const char*> sbl//用下面特殊的定义
```

具体化还可以区分指针与非指针的同一类型版本

##### 部分具体化

partial specialization，类模板的偏特化，例如：

```c++
template <class c1, class c2> class Pair {...};
template <class T1> class Pair<T1, int> {...};
template <> class Pair <int, int> {...};
Pair<double, double> p1;//用第一个
Pair<double, int> p2;//用第二个，部分具体化
Pair<int, int> p3;//用第三个，显式具体化
```

```c++
template <class c1, class c2, class c3> class Trio{...};
template <class c1, class c2> class Trio<c1,c2,c2>{...};
template <class c1> class Trio<c1,*c1,*c1>{...};//跟第二个不一样
```

偏特化可以固定参数、也可以将参数范围缩小：

```c++
template<class t> class x {};
template<class t> class x<t*> {};
template<class t> class x<const t*> {};
```

函数重载可以达到偏特化的效果：

```c++
template<class t> t f(t a, t b) {};
template<class t> t* f(t* a, t* b) {};
```

举例：

```c++
#include <bits/stdc++.h>
using namespace std;
template<class t, int n>
class stk//静态栈
{
public:
    int size,now;
    t* nr;
    stk()
    {
        size=n;
        now=0;
        nr=new t[size];
    }
    ~stk() {delete[] nr; cout<<"qwq\n";}
    void push(t v) {nr[now++]=v;}
    t pop() {return nr[--now];}
    t top() {return nr[now-1];}
};
template<int n>
class stk<bool, n>
{
public:
    int size,now;
    int* nr;
    enum{ ui=sizeof(unsigned)*8};
    stk()
    {
        nr=new int[1+(n-1)/ui];
    }
    ~stk() {delete[] nr; cout<<"wqw\n";}
    void push(bool v)
    {
        int idx=++now/ui;
        (nr[idx]<<=1)|=(v?1:0);
    }
    bool pop()
    {
        int idx=now--/ui;
        bool r=nr[idx]&1;
        nr[idx]>>=1;
        return r;
    }
    bool top() {return nr[now/ui]&1;}
};
signed main()
{
    stk<int,10> s;
    s.push(3); cout<<s.top()<<endl;
    s.push(6); cout<<s.top()<<endl;
    s.pop(); cout<<s.top()<<endl;
    stk<bool,10> b;
    s.push(true); cout<<s.top()<<endl;
    s.push(false); cout<<s.top()<<endl;
    s.pop(); cout<<s.top()<<endl;
    return 0;
}
```





#### 类模版

注：使用类模板的非成员函数需要声明为函数模板，否则无法确定类参数实例如

```c++
template<class t>void f(c<t> x);
```



举例：

```c++
template <class Type>//或typename，下同
class Stack
{
private:
    enum {MAX=10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    ...
}
template <class Type>//若类外定义，则每一个成员函数都要这般
Stack<Type>::Stack() {top=0;}
```

使用方法就跟上面的差不多了。



如果使用指针，示例如下：

```c++
template <class Type>
class Stack
{
private:
    enum {SIZE=10};
    int stacksize;
    Type *items;
    int top;
public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack &st);
    ~Stack(delete [] items;)
    bool isempty() {return top==0;}
    bool isfull() {reurn top==stacksize;}
    bool push(const Type &item);
    bool pop(Type &item);
    Stack &operator=(const Stack &st);
}

template <class Type>
Stack<Type>::Stack(const Stack &st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for(int i=0;i<top;i++) items[i]=st.items[i];
}
template <class Type>
bool Stack<Type>::push(const Type& item)
{
    if(top<stacksize)
    {
        items[top++] = item;
        return true;
    }
    else return false;
}
template <class Type>
bool Stack<Type>::pop(Type &item)
{
    if(top>0)
    {
        item = items[--top];
        return true;
    }
    else return false;
}
template <class Type>
Stack<Type> Stack<Type>::operator=(const Stack<Type> &st)
{
    if(this == &st) return 8this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for(int i=0;i<top;i++) items[i]=st.items[i];
    return *this;
}
```

##### 表达式参数

非类型(non-type)/表达式(expression)参数，举例如下：

```c++
template <class T, int n>
class ArrayTP
{
private:
    T ar[n];
}
```

表达式参数可以是整型、枚举、引用或指针。例如：double m 不合法但 double *rm合法。

模版代码不能修改参数值，不能使用参数地址，如n++或&n。

上面的功能可以用构造函数(传参数)同等地实现。

##### 嵌套

模板类可以作基类、组件类、其他模版的类型参数：

```c++
template <typename T>
class Array
{
private:
    T entry;
};
template <typename T>
class GArray : public Array<T> {...};
template <typename T>
class Stack
{
    Array<T> ar;
}
Array<Stack<int> > asi;
```

当然也可以递归使用：

```c++
Array<Array<int, 5>, 10> t;
```

还有作为参数：

```c++
template<template<typename T> class Thing>
class crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() {};
    bool push(int a, double x)
    {return s1.push(a) && s2.push(x);}
    bool pop(int &a, int &x)
    {return s1.pop(a) && s2.pop(x);}
};
Crab<Stack> nebula;
int ni,nb,a,b;
cin>>ni>>nb;
nebula.push(ni,nb);
nebula.pop(a,b);
cout<<a<<" "<<b<<endl;
```

当然可以混用模板参数和常规参数：

```c++
template<template<typename T> class Thing, typename U, typename V>
class Crab
{
private:
    Thing<U> s1;
    Thing<V> s2;
}
Crab<Stack, int, double> nebula;
```

##### 友元

###### 非模板

```c++
template <class T>
class HF
{
    friend void report(HF<T>&);
};
void reports(HF<int> &) {}//定义
void reports(HF<int> &) {}
```

###### 约束模板

```c++
template <typename T> void counts();
template <typename T >void report(T &);
template <typename T>
class HF
{
public:
    friend void counts<T> ();
    friend void report<>(HF<T> &);
}
template <typename T>
void counts(){cout<HF<T>::ct}//里面可得用T啊……
//ct是一个static
template <typename T>
void report(T &hf) {cout<<hf.item<<endl;}
```

###### 非约束模板

```c++
template<typename T>
class HF
{
    template<typename C, typename D> friend void show(C &, D &);
}
template<typename C, typename D> void show(C &c, D &d)
{cout<<c.item<<","<<d.item<<endl;}
```



代码示例：

```c++
#include <stdio.h>
template <class t>
class Vector
{
public:
    int d=0;//维度
    t* v = nullptr;//动态数组
    Vector(){}
    Vector(int dd):d(dd)
    {
        v=new t [dd];
    }
    template <class u>
    Vector(int dd, u dv):d(dd)
    {
        v=new t [dd];
        for(register int i=0;i<d;++i)
        {
            v[i]=dv[i];
        }
    }
    ~Vector()
    {
        delete[] v;
    }
    //template <class u>
    //Vector<u> operator = (const Vector<u> &x)
    //{
        /*Vector z=Vector(x.d);
        const char err[] = "Error： 维度不相同不可以相加！";
        if(x.d!=d) throw err;
        for(register int i=0;i<d;++i)
        {
            z.v[i]=x.v[i];
            printf("%d\n",z.v[i]);
        }
        return z;*/
    //}
    template <class u>
    Vector<u> operator + (const Vector<u> &x) const
    {
        Vector z=Vector(d);
        //const char err[] = "Error： 维度不相同不可以相加！";
        if(x.d!=d) throw "Error： 维度不相同不可以相加！"; //虽然没搞懂，但是throw err不行
        for(register int i=0;i<d;++i)
        {
            z.v[i]=v[i]+x.v[i];
        }
        return z;
    }
};

__int32 main()
{
    Vector<int> a(2), b(2), d(3);
    a.v[0]=1,a.v[1]=2,b.v[0]=-1,b.v[1]=3;
    Vector<int> c(2),e(4);
    c=a+b;
    printf("(%d, %d)\n",c.v[0],c.v[1]);
    try
    {
        e=a+d;
    }
    catch(const char* s)
    {
        printf("%s\n",s);
    }
    return 0;
}
```



#### 包装器

warpper。也叫适配器adapter。当在模板函数里使用静态变量时，往往不如人意(实际创造的实例化非常多，而不是单个)，为此可以使用包装器解决。

使用头文件functional

```c++
function<double(double)> e1 = f1;
function<double(double)> e2 = f2;
uf(y, e1);
uf(y, e2);
```

或者这样调用：

```c++
typedef function<double(double)> ef;
uf(y, ef(f1));
uf(y, ef(f2));
```

#### 可变参数模版

省略号可以表示元运算符(meta-operator)

```c++
template<typename... Args>
void show(Args... args){...}
```

Args是模板参数包(parameter pack)，args是函数参数包。可以传入任意类型的0至任意多个参数。

展开参数包需要用到递归，为了避免无限递归，修改上述例子如下：

```c++
void show(){}
template<typename T, typename... Args>
void show(T value, Args... args)
{
    cout<<value<<",";
    show(args...);
}
```

当然也可以把只有一个元素的处理放到最先那个show里，实现特判格式输出。

#### 模板元

可以使用模板让本该在程序运行计算的内容给编译器计算

```c++
#include <bits/stdc++.h>
using namespace std;
template<unsigned n>
struct fact{enum{v=n*fact<n-1>::v}; };
//枚举值当整型常量使用，因为枚举值在编译时计算，所以可以匿名枚举定义常量,静态成员常量也可以实现匿名枚举的功能
template<> struct fact<0>{enum{v=1}; };//递归初始状态
const int m=6;//必须加const
int arr[fact<m>::v];
signed main()
{
    return 0;
}
```

也可以做成模板处为常数的函数：

```c++
//template<unsigned n>
//inline double power(double v) {return v*power<n-1>(v);}
//template<> double power<1>(double) {return v;}
template<unsigned n>
struct power{
    template<class t> static t v(t x) {return x*power<n-1>::v(x);}
};
template<> struct power<1> {
    template<class t> static t v(t x) {return x;}
};
template<unsigned n, class t>
inline t pows(t x){return power<n>::v(x);}
signed main()
{
    int y; double x;
    scanf("%lf%d",&x,&y);
    printf("%lf %d\n",pows<3>(x),pows<10>(y));
    return 0;
}
```





### 容器

容器(container)是容纳、包含一组元素的对象。包括顺序容器(sequence container)和关联容器(associative container)。

> 包含deque、list、queue、priority_queue、stack、vector、map、multimap、set、forward_list、unordered_map、unordered_multimap、unorder_set、unorder_multiset。
>
> vector和deque是随机访问容器，vector,deque,list是顺序容器；list,set,multiset,map,multimap是可逆容器，(multi)set,(multi)map是关联容器

容器的基本特征：

| 表达式        | 返回类型       | 说明     | 复杂度   |
| ------------- | -------------- | -------- | -------- |
| X::iterator   | 指向T的迭代器  |          | 编译时间 |
| X::value_type | T              |          | 编译时间 |
| X u           |                |          | 固定     |
| X()           |                | 匿名     | 线性     |
| X u(a)        |                |          | 线性     |
| r = a         |                |          | 线性     |
| (&a)->X()     | X&             |          | 线性     |
| a.begin()     | iterator       |          | 固定     |
| a.end()       | iterator       |          | 固定     |
| a.size()      | unsigned int   |          | 固定     |
| a.swap(b)     | void           | b是容器  | 固定     |
| a==b          | 可转为bool     |          | 线性     |
| a!=b          | 可转为bool     |          | 线性     |
| X u(rv)       |                | 移动构造 | 线性     |
| X u = rv      |                |          |          |
| a = rv;       | X&             |          | 线性     |
| a.cbegin()    | const iterator |          | 固定     |
| a.cend()      | const iterator |          | 固定     |

执行操作所需时间从快到慢依次为：

- 编译时间
- 固定时间
- 线性时间

> vector是可直接访问的线性群体，stack和queue是顺序访问的线性群体

基本方法有构造函数(不传任何参数，即`S s1`)，有逻辑运算符(`==,!=`和四个不等号)，有begin,end,clear,empty,size,swap方法，按元素逐个比较。理论上，empty比size高效，swap比手写高效。

容器的迭代器有s::iterator和s::const_iterator(只读不写，指向const容器)

容器有可逆容器的子概念，可逆容器有随机访问容器的子概念。STL容器都是可逆容器，非标准库模板如slist(单向链表)仅提供前向迭代器。

逆向遍历，使用`--`运算符，或者使用可逆容器，通过`rbegin`和`rend`获取你想迭代器，分别获取当前指向最后一个元素和第一个元素之前一个元素的迭代器

逆向迭代器： s::reverse_iterator s::const_reverse_iterator

迭代器和逆向迭代器可以相互转化，对一个迭代器p使用s::reverse_iterator(p)获取对应的逆向迭代器，获取后的迭代器p2通过迭代器方法base()得到原迭代器p，其中p2指向的元素与p指向的元素的前一个元素相同，如：

```c++
s.rbegin()==SS:reverse_iterator(s.end());
s.rbegin().base()==s.end();
s.rend()==SS::reverse_iterator(s.begin());
s.rend().base()==s.begin();
```



#### 序列

**序列**(sequence)包含deque、forward_list、list、queue、priority_queue、stack和vector。不严格来说，array也是。

基本要求：

| 表达式          | 返回类型 | 说明                |
| --------------- | -------- | ------------------- |
| X a(n,t)        |          |                     |
| X(n,t)          |          |                     |
| X a(i,j)        |          | 初始化为[i,j]的内容 |
| X(i,j)          |          |                     |
| a.insert(p,t)   | 迭代器   |                     |
| a.insert(p,n,t) | void     |                     |
| a.insert(p,i,j) | void     |                     |
| a.erase(p)      | 迭代器   |                     |
| a.erase(p,q)    | 迭代器   |                     |
| a.clear()       | void     |                     |

deque、list、queue、priority_queue、stack、vector还支持下列草操作，复杂度是固定时间。

| 表达式          | 返回 | 含义                  | 容器              |
| --------------- | ---- | --------------------- | ----------------- |
| a.front()       | T&   | *a.begin()            | vector,list,deque |
| a.back()        | T&   | *--a.end()            | vector,list,deque |
| a.push_front(t) | void | a.insert(a.begin(),t) | list,deque        |
| a.push_back(t)  | void | a.insert(a.end(),t)   | vector,list,deque |
| a.pop_front(t)  | void | a.erase(a.begin())    | list,deque        |
| a.pop_back(t)   | void | a.erase(--a.end())    | vector,list,deque |
| a[n]            | T&   | *(a.begin()+n)        | vector,deque      |
| a.at(t)         | T&   | *(a.begin()+n)        | vector,deque      |

#### 顺序容器

如vector,deque,list。

通用方法：//da tr w

```c++
S s(n,t);//n个t元素构成
S s(n); //n个元素
S s(q1,q2); //将迭代器[q1,q2)区间内数据作为s元素
s.assign(n,t); //同上
s.assign(n);
s.assign(q1,q2);
s.insert(p1,t);//在s的迭代器p1位置插入t(加在原p1，原p1往后退)，返回迭代器指向新插入的元素
s.insert(p1,n,t);//插入n个t，(实测返回第一个t所在迭代器)
s.insert(p1,q1,q2);//插入迭代器区间，返回q1所在迭代器
s.erase(p1);//删除p1指向的元素，并返回被删除元素迭代器
s.erase(p1,p2);//删除迭代器区间，返回区间外下一个元素迭代器
s.front();//引用
s.back();
s.resize(n);//多删少补
s.push_back(t);
s.pop_back();
s.push_front(t);//vector不支持，下同
s.pop_front();
```

举例：

```c++
vector<int> v={1,2,3};
v.insert(v.begin()+1,0);
for(auto i:v) cout<<i<<' ';//1 0 2 3
auto k=v.insert(v.begin()+1,2,0);
cout<<*k;//0
++k;++k;++k; cout<<*k;//2
```

```c++
vector<int> p={-1,-2,-3,-4},q={1,2,3};
auto k=q.erase(q.begin()+1);
k++;
cout<<*k;//k是2,*(--k)是1
auto m=p.erase(p.begin()+1,p.begin()+2);//区间长是1！
cout<<*m<<endl;
cout<<*(m+1)<<endl;
cout<<*(m-1)<<endl;//注意这时候返回-1而不是-2，-2不再可访问
```

```c++
vector<int> p={-1,-2,-3,-4},q={-1,2,3};
cout<<(p<q);
```

> 向vector插入元素有可能让所有迭代器失效

有插入迭代器，是一种适配器，通过接口指定元素指定位置插入元素，有：front_insert_iterator, back_insert_iterator, insert_iterator

通过函数front_inserter, back_inserter和inserter(s, iter)构造

#### 关联容器

关联容器(associative container)将值和键关联在一起。有set、multiset、map、multimap。

> 关联容器依靠平衡二叉树实现，也就是实际上是升序排序的，遍历必然是升序的
>
> 插入和删除不会让任何已有迭代器、指针、引用失效

关联容器可以划分为单重关联容器和多重关联容器，依据是键值是否可以重复；还可以分为简单关联容器(元素就是键)和二元关联容器(键值对)

键必须可比较大小，且必须严格弱序，即不允许`x<x`，必须有非自反性。有传递性，对于<和==都必须成立，且定义`==`是`!(x<y)&&!(y<x)`。

共有方法：

```c++
S s(q1,q2);//单重去重，多重照常
s.insert(t);//返回值是pair<iterator,bool>,成功bool为true，否则为false
//如果是多重容器，返回iterator
s.insert(p,t);//p是插入建议位置，有概率可以提高效率,总是返回迭代器
s.insert(p1,p2);//对每个迭代器区间元素执行单一insert，返回void
s.erase(p1);//删除p1指向的元素
s.erase(p1,p2);//删除区间元素
s.erase(k);//删除所有键为k的元素，返回被删除个数，可能是0，即可以尝试去删除不存在的元素
s.find(k);//寻找键为k的元素，返回迭代器，找不到返回end迭代器
s.lower_bound(k);//第一个键值不小于k的元素迭代器
s.upper_bound(k);//第一个键值大于k的元素迭代器
s.equal_range(k);//返回pair<bg,ed>迭代器区间，包含所有键值为k的元素即
//bg==s.lower_bound(),ed=s.upper_bound()
s.count(k);//有多少个键为k的元素
```

举例：

```c++
set<int> s={1,1,2,3};
auto k=s.insert(2);
cout<<*(k.first)<<' '<<k.second<<endl;
auto p=s.insert(4);
cout<<*(p.first)<<' '<<p.second<<endl;
```

```c++
multiset<int> ms={1,1,3};
auto x=ms.insert(3);
cout<<*x;
```

```c++
auto k=s.insert(s.begin(),4);
cout<<*k;
```

```c++
set<int> s={9,5,1,1,2,3};
cout<<*s.lower_bound(3)<<endl<<*s.upper_bound(3)<<endl;
cout<<s.count(1)<<endl<<s.count(0);
```



### vector

在库vector

不定长数组，模板类

定义：

```c++
vector<数据类型>变量名;
vector<数据类型>变量名 {元素数};
vector<数据类型>变量名 (长度);
vector<数据类型>变量名 (长度, 初始值);
vector<数据类型>变量名 = 变量名2;
vector<数据类型>变量名(变量名2);
```



允许符合，如

```c++
vector<pair<int, int>> a;
```

size()方法读取大小，返回size\_t，在头文件cstddef定义(一般无需include;同理迭代器举例是ptrdiff\_t，是有符号的)

resize(size, value)方法改变大小并初始化，默认value0

push_back()方法尾部加元素

> emplace_back()是push_back的优化版，区别如下：
>
> emplace_back()在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造。而且调用形式更加简洁，直接根据参数初始化临时对象的成员。(当然int之类的也能用)是C++11的新特性。

pop_back()删除最后一个元素

clear()方法清空 复杂度$\Omicron(1)$，因为只清空长度不硬删除

front()方法返回首元素的引用，例如：c.front() = 3;

back()方法同理

[]直接访问某个元素

v.begin()表示首，可以+-数值进行指针移位，v.end()同

rbegin(),rend()可以进行反向输出。(返回reverse_iterartor)

```c++
for(auto p = a.rbegin();p != a.rend();p++) cout<<*p<<endl;
for(auto p = a.end()-1;p>=a.begin();p--) cout<<*p<<" ";//话说end(),begin(),--也可以的
```

上两个成员函数返回值是迭代器，记作p

insert(p, value)插入 O(n)

insert(p, b1, b2);将[b1,b2]内元素插入到p位置前面

erase(p)删除 也可以用诸如x.end()-1;O(n) 

> 删除并不会实际上减少空间，若需要实际减少空间，可以：
>
> ```c++
> vector<t>(s.begin(),s.end()).swap(s);//临时vector与其互换
> ```
>
> 插入和删除越接近头部越慢

erase(p, q)删除区间[p,q)的元素

> 如：erase(s.begin(),s.begin()+2)删除头两个元素。

整理：sort(v.begin(), v.end())

复制：copy(a.begin(),a.end(),b.begin())，注意b要有足够的空间，可以初始化时给。

capacity() 返回容量(不一定等于实际大小)

reserve(n) 若当前容量大于等于n什么也不做，否则扩大到不小于n

> 反复动态分配空间时，提前reserve效率更高
>
> 发生容量拓展时，会使所有迭代器、指针、引用失效，尾部删除、任意位置插入、删除会使相应位置之后失效

遍历：

```c++
void printv(vector<数据类型> V)
{
    for(int i=0;i<V,size();i++) cout<<V[i]<<" ";
    cout<<endl;
}
```

vector仍可能存在越界问题。

#### 多维vector

```c++
vector<vector<int> > x; //√
vector<vector<int>> x; //×
vector<vector<int> > x(10, vector<int>(20));
```

则

```c++
x.size() == 10;
s[0].size() == 20;
```

自然可以任意修改变量值：

```c++
x[2][3] = 3;
```

遍历示例：

```c++
for(auto i:x)
{
    for(auto j:i)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}
```

多维的话……话说resize不香嘛……

虽然也是可以的：

```c++
vector< vector< vector<int> > > x(5,vector<vector<int>>(8,vector<int>(10)));

vector< vector< vector<int> > > x(5,vector<vector<int>>(8,vector<int>(10, 1)));
//1是初始值


vector< vector< vector<int> > > vector_3D_5(n，vector_2D_4);
                                            
vector< vector< vector<int> > > vector_3D_5(n);
//仅仅指定一维大小。当然二维也可以这样的。
```

```c++
vector<vector<vector<vector<int>>>>  x(3,vector<vector<vector<int>>>(5,vector< vector<int>>(7,vector<int>(10,1))));
```



### 迭代器

迭代器是泛化的指针。提供顺序访问容器每个元素的方法。

> 使用独立于STL容器的迭代器需要包含iterator头文件

STL根据迭代器功能，将其分类为五类，其中，前向迭代器(forward iterator)是输入迭代器(input iterator)和输出迭代器(output iterator)的子概念，双向迭代器(bidirectional iterator)是前向迭代器的子概念，随机访问迭代器(random access iterator)是双向迭代器的子概念。

输入迭代器从序列中读取元素，不一定可以写入到序列，支持对序列不可重复的单向遍历，支持`==,!=,*,->,* ++`运算符，其中`*p++`为`T t=*p;++p;return t;`，特别注意若`p1==p2`，不保证`++p1==++p2,*(++p1)==*(++p2)`，不保证读入的序列可重复

输出迭代器向序列写入元素，不保证可以读取，输出迭代器还有`*p=t,*p++=t`即`*p=t,++p`运算符。要求写入操作和自增操作必须交替进行，如果连续两次自增或连续两次写入，都会有可能出错。

前向迭代器可以读写数据，支持可重复单向遍历，即意味着若`p1==p2`则有`++p1==++p2`。不要求写入和自增交替进行。

双向迭代器支持反向移动，即`--p,p--`，后置自增等效于`P p2=p1;--p1;return p2;`

随机访问迭代器支持更多操作符，如`p+=n,-=n,+n,n+,-n,-p2,p1 op p2,p[n]`,op是四个逻辑不等号运算符之一。例如vector迭代器是随机访问迭代器。

设p1,p2是输入迭代器，则`[p1,p2)`代表它们的区间，若`p1==p2`，则是空区间，若指向容器的元素或p1>p2,则区间不合法。若存在自然数n,p1+n==p2，则区间合法。

使用举例如下：

```c++
template<class t, class ist, class ost>
void f(ist bg, ist ed, ost res)
{
    vector<t> s;
    for(;bg!=ed;++bg) s.push_back(*bg);//将输入迭代器转随机访问迭代器
    sort(s.begin(),s.end());
    copy(s.begin(),s.end(),res);
}
double a[5]={1.2,2.4,0.8,3.3,3.2};
f<double>(a,a+5,ostream_iterator<double>(cout,", ")); cout<<endl; //记得f的<double>，这里要加<double>是因为vector要用，若t s是不需要的……且如果t不是第一个模板参数，还要先填上前两个参数
f<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));
```





用于对STL容器元素迭代处理，指向特定位置，

拥有如下运算符：

- ++
  - ++p 前置自增让迭代器指向下一个元素，表达式返回对p1自身的引用
  - p++ 后置自增让迭代器指向下一个元素，表达式返回类型不确定(前向迭代器是确定的)
- ==,!= 判断迭代器是否指向同一位置
- = 赋值
- *返回元素

begin()和end()指向开头和末尾

迭代器的本质是指针。

举例：

```c
vector<int> iterator it;
for(it=v.begin();it!=v.end();it++) cout<<*it;
//it++是指向变化，(*it)++是值增1；当然auto也很香
```

> 其实用基于范围的for更香不是吗。

可以使用next函数进行移位，比方说list不能+1操作，但是可以next，返回值是迭代器。

```c++
auto k = next(x.begin());
```

> 对于迭代器，还有通过继承基本迭代器自己创建迭代器等细节内容，在教材书p470-p475，以后如果有需要再看

#### 分类

除了最基本的迭代器，还可以有输入迭代器、输出迭代器、正向(前向)迭代器、双向迭代器、随机访问迭代器。

| 功能             | 输入 | 输出 | 正常 | 双向 | 随机 |
| ---------------- | ---- | ---- | ---- | ---- | ---- |
| 解除引用读取     | 有   | 无   | 有   | 有   | 有   |
| 解除引用写入     | 无   | 有   | 有   | 有   | 有   |
| 固定和可重复排序 | 无   | 无   | 有   | 有   | 有   |
| 自增             | 有   | 有   | 有   | 有   | 有   |
| 自减             | 无   | 无   | 无   | 无   | 有   |
| i[n]             | 无   | 无   | 无   | 无   | 有   |
| i±n              | 无   | 无   | 无   | 无   | 有   |
| i±=n             | 无   | 无   | 无   | 无   | 有   |

在iterator头文件，有这些迭代器：

- ostream_iterator
- istream_iterator
- reverse_iterator
- back_insert_iterator
- front_insert_iterator
- insert_iterator

> 一个使用示例见数据-set

### array

库array 长度是固定的

定义：array<数据类型, 长度> var;

array<数据类型, 长度> var = {v, v2, ...};

#### valarray

库valarray。无push_back和insert。

valarray<数据类型> v

valarray<数据类型> v = {v1, v2 ...}

构造函数参数(const 数据类型*, int)

可以使用：

[]

size

sum

max

min

val数组转val<bool>，可以：

```c++
valarray<bool> vb = n > 9;//n是valarray<double>
```

切片：

```c++
v[slice(1,4,3)] = 10;//索引为1,4,7,10的赋值
vb(v[slice(1,4,3)]);
```

### set

库set

根据元素值进行排序的集合，所插入元素在集合里唯一，不存在重复。时刻保持有序(升序)。

如果希望降序：

```c++
set<int, greater<int> > s;//greater是比较函数
```

排序方法如下：

1. 对于等长度整型数组，和相同，则某一项大的在前，如排序为[2,1],[1,2]
2. 默认升序排列

定义同vector

可以set<类型> var{数组, 数组+len}来获取数组的set化//python

但vector不可以

加入元素：

- insert(元素值) 方法
- insert(sp, se)方法植入闭区间

插入元素后呈现升序排列 [O(logn) 平衡树

元素数：size()方法

删除元素：

- erase(元素值)方法
- erase(迭代器)方法 ，如x.end()

clear()

find()有，返回迭代器，无，返回末尾end()

- find方法对于查找数组，当然实质上就是找的是数组地址，毋庸置疑


并集set_union(Ab, Ae, Bp, Be, 输出迭代器)//algorithm

交集set_intersection

差set_difference

输出元素：

```c++
for(set<string>::iterator it = 变量名.begin(); it != 变量名.end(); it++)
    cout << *it << "\n";
```

使用示范：(集中)

```c++
//iostream,algorithm,iterator,set,string
string s1[6] = {"fuck", "shit", "fuck", "suck", "hell", "damn"};
string s2[6] = {"fuck", "asssole", "wtf", "motherfucker", "die", "djck"};
set<string> A{s1, s1+6};
set<string> B{s2, s2+6};
ostream_iterator<string, char> out(cout, " ");
copy(A.begin(), A.end(), out); cout<<endl;
copy(B.begin(), B.end(), out); cout<<endl;
set_union(A.begin(), A.end(), B.begin(), B.end(), out); cout<<endl;
set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); cout<<endl;
set_difference(A.begin(), A.end(), B.begin(), B.end(), out); cout<<endl;
set_difference(B.begin(), B.end(), A.begin(), A.end(), out); cout<<endl<<"C:";
set<string> C;
set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                 insert_iterator<set<string> >(C, C.begin()));
copy(C.begin(), C.end(), out); cout<<endl;
C.insert("evil");
copy(C.begin(), C.end(), out); cout<<endl<<"next:";
copy(C.lower_bound("shit"), C.end(), out); cout<<endl;
copy(C.lower_bound("evil"), C.end(), out); cout<<endl;
copy(C.lower_bound("evil"), C.upper_bound("fuck"), out); cout<<endl<<"next:";
copy(C.lower_bound("evil"), C.upper_bound("dick"), out); cout<<endl;
```

注意：

- 虽然说在即合理元素唯一，但是如果插入了两个相同的数组元素(指的是数组的值一样)，还是不可以的
- 不可以使用[]方法

#### multiset

库set。键可以与多个值关联。如包含的内容可以是1、2、2、3。//datrz

#### unordered_set

哈希表#include <unordered_set>

unordered_set<int> h

仍旧可以保持元素的唯一性

insert(v) 返回插入位置迭代器，支持++和--(而set不支持)

erase(v)

find(v)

### map

库map，又名映射，字典

类似于python的dict

定义：map<key数据类型, value数据类型> 变量名;

以key排序，默认升序排序。降序同set理。

//以值(value)作为排序标准，各键(key)唯一，不重复。

[count方法：若有查找key，返回1，否则0

新元素：①T[key] = value

②T.insert(make_pair(key, value) )

删除：T.erase(key)

查找:pair<key类型,value类型> target = *T.find(key)

- 其实返回值是一个迭代器，找不到返回end迭代器

调用：先pair<key类型,value类型> item = it [或map[i];

​	后first调用key,second调用value

for方法：map<key类型,value类型>::iterator it;

for(it=T.begin();it!=T.end();it++)

新建：

#### multimap

头文件map。键和值类型可以不一样。

定义：

```c++
multimap<键类型, 值类型> 变量名;
```

使用示范：

```c++
//map,string,iostream,algorithm
typedef pair<const int, string> Pair;
typedef multimap<int, string> Mapcode;
Mapcode codes;
codes.insert(Pair(2, "Do you think so?"));
codes.insert(Pair(1, "We love python"));
codes.insert(Pair(2, "As you think so."));
codes.insert(Pair(1, "We hate c++"));//second不会给排序的
for(auto i:codes) cout<<"<"<<i.first<<","<<i.second<<"> "; cout<<endl;
pair<Mapcode::iterator, Mapcode::iterator> rg = codes.equal_range(2);
for(auto it=rg.first;it!=rg.second;++it) cout<<(*it).second<<endl;
```

#### unordered_map

> 比map快一点，大概50%至多

即哈希表[字典]#include <unordered_map>

举例//da ck

unordered_map<string, int>hash;

hash.insert({string, int});

hash.find(string);

- 可以用诸如hash.find(s)!=hash.end()的判断
- 查找成功，使用hash.find(s)->second输出值

hash.count(string);

hash.erase(string);

hash[key] = v;

### stack

库stack

定义:stack<数据类型> 名称;

压栈:s.push(value);

弹栈:s.pop();

输出栈顶:s.top();

输出大小:s.size();

是否栈空:s.empty();

### list

库list，是双向链表

不会自动排序，不可以进行迭代器加法，不可以用[]操作符

list<数据类型> 变量名;

size()返回元素数

begin() end() 返回迭代器p

push_front(x)开头添加

push_back(x)

pop_front()

pop_back()

insert(p,x) 返回该位置迭代器p

erase(p) 删除某个位置的元素

- erase(pb, pe)删除某个闭区间的元素

> 被删除元素迭代器、引用、指针失效

clear() //O(n)

merge(list &x)合并两个链表，合并后x为空。如果两个链表都已经按升序排好序，那么合并后也是升序的。无返回值。

remove(v) 删除所有v，如果没有什么也不干。无返回值。O(n)。

- remove_if(f)删除所有符合条件的

sort()无返回值。升序排序。O(nlogn)。

splice(iterator pos, list x)将x的内容插入到pos前面,pos往后推，x变为空。O(n)。无返回值。

> splice(pos,x,q)将x中迭代器q指向的内容置pos，x中删掉q
>
> splice(pos,x,q1,q2)，迭代器区间[q1,q2)，同理

unique()无返回值。将连续相同元素压缩为单个元素。O(n)。size当然会变。

遍历:

```c++
int i=0;
for(list<类型>::iterator it=v.begin();it!=v.end();it++){
    if(i++) printf(" "); printf("%d", *it);
}printf("\n");
```

#### forward_list

单向链表。不可反转容器。

#### initializer_list

### queue

库queue

定义:queue<数据类型> 名称;

入队:s.push(value);

离队:s.pop();

输出队首:s.front();

输出队尾:s.back();

输出大小:s.size();

是否队空:empty();

清空模拟clear:

```c++
while(!q.empty())q.pop();
```

#### priority_queue

堆

库queue 

定义priority_queue<数据类型> 名称;

顶部：top()方法

弹出pop()方法(默认是值最大先出)

- 如果要最小，取相反数输入，再取相反数输出，或：

- ```c++
  priority_queue<int, vector<int>,greater<int>>q;
  ```

压入push(key)方法

对于类的堆，要定义>方法，例如：

```c++
struct node { ll i, v; };
inline bool operator>(const node& x, const node& y) 
{ return x.v > y.v; }
priority_queue<node, vector<node>, greater<node>> q;//最小堆
```



#### deque

库deque，double-end queue，双端队列

效果同python::list，支持首尾+插入

定义类似。

支持push_back(),push_front(),pop_back(),pop_front()

支持at(idx), [], front(), back()

支持insert(pos, elem), insert(pos, n, elem)插入重复多个, insert(pos, beg, end)插入左闭右开区间数据

支持clear(),erase(beg, end), erase(pos)

> 删除元素会让被删除元素失效，任意位置插入和删除会使得所有迭代器、指针、引用失效，位置越靠近中间越慢

### pair

库iostream，也可以是库utility

定义

```c++
pair<首数据类型, 尾数据类型> 变量名;
pair<首数据类型, 尾数据类型> 变量名 (首, 尾);
pair<首数据类型, 尾数据类型> 变量名 = {首, 尾};
```

赋值:p = make_pair(首, 尾);

p={首,尾};

调用:p.first() p.second();

比较：p1.first<p2.first则p1<p2,>同理

若first同，对second同理

### bitset

头文件bitset

声明：

```c++
bitset<位数> var;
bitset<d> s1(12);
string str="100110";
bitset<d> s2(str);
//如果是整型，那么填充时会自动转换为二进制，如果是字符串，但是其中出现了 0/1 以外的字符，就会爆炸
```

方法：

1. 基本的位操作，如：$s|=s<<w[i];$
2. .count()计算1的个数
3. .any()是否存在1
4. .none()是否不存在1
5. .set()全设为1
6. .reset()全设为0
7. .flip()按位取反

上述函数可以传一个参数，则只对该位操作

## 循环

### for

#### 基于范围

有两种写法，一个是传值，一个是传值，示例如下：

```c++
double k[] = {1.2, 1.3, 1.4, 1.5};
for(double i : k) cout<<i<<endl;
for(double &pi : k)
{
    pi++;
    cout<<pi<<endl;
}
```

数组，以及vector都可以（for的格式是一样的）

可以像python那样搞多个元素的迭代：

```c++
for (auto [x, y] : seg)
    if (x > R)
    {
        cnt ++ ;
        L = x, R = y;
    }
	else R = max(R, y);
```

### for-each

头文件algorithm

```c++
void show(int p){cout<<p<<" ";}
int a[] = {1,2,3,4,5};
for_each(a, a+5, show);
```

对vector如下：

```c++
for_each(b.begin(),b.end(), [](int it)->void{cout<<it<<" ";} );
```



## 输入和输出

将stdio.h换成cstdio，其他库的变换格式同理

但是更常用的是iostream库

### 标准输入输出

#### cin, cout

iostream  

优点：舍弃占位符

缺陷：运行慢

cin >> a >> b >> c >> d;读取多个变量

cin >> a >>b; 读取两个变量

cin>>a;读取一个变量

cout << a << "\n"; 输出两个内容

注：

- endl可以代替\n,但endl很慢，'\n'更快。endl会进行一些清空缓存处理[?]；ends可以代替空格(建议不要使用，可能会WA)。

- 对于小数，默认保留六位**有效数字**，如果大于六位数，用指数输出

- 不能够输出结构体的成员，如：s[3].i[2], i为int数组。

- 如果要直接输出逻辑表达式的结果，表达式要加括号，因为<<优先级的问题。输出的值是int。但是可以通过cout.setf(ios_base::boolalpha)设置修改。

- cin读char，会跳过空白字符

- 如果要稍微提高cin,cout的速度，那么可以使用如下代码：

  ```c++
  ios::sync_with_stdio(false);//关闭同步流
  cin.tie(0);//da ck;或nullptr代替0,cout也可
  ```
  
- 输入结束，Ctrl+Z (windows) 或 Ctrl+D(Linux)

- Windows换行是\n\r，而二进制下不会，Linux是\n
```
  
  那么在这之后，将不能使用cin,cout,scanf,printf,gets,puts,getchar等C风格IO。虽然平时也不推荐使用gets

允许的输入模版：

​```c++
char ch;
for(int i=0;cin>>ch;i++)
```

##### 退出问题

调试过程中，可以通过ctrl+c或ctrl+z+Enter退出，后者只在C++有用

以下格式可以实现：

###### cin

```c++
char ch;while(cin>>ch)cout<<ch;
```

也可以写成这样:

```c++
char ch;cin>>ch; if(!cin) ...
```

###### EOF

```c++
char ch;while( (ch = cin.get()) != EOF) cout<<ch;
```

###### cin.fail

```c++
do{
    cin.get(ch);
    cout<<ch;
}while(!cin.fail());
```

> fail是failbit(输入操作未能读取预期的字符或输出操作没有写入预期字符)或badbit(流被破坏)其一为真就为真；其他的流状态还有eofbit，goodbit，good(所有为都被清除),bad()对应badbit,eof()对应eofbit，rdstate()返回流状态;exceptions()返回一个位掩码指出那些标记导致异常被引发。exceptions(iostate ex)设置哪些状态将导致clear()引发异常；clear(iostate s)设置流状态，默认为goodbit，setstate(iostate s)即调用clear(rdstate()|s)

###### cin.eof

```c++
do{
    cin.get(ch);
    cout<<ch;
}while(!cin.eof());
```

###### 例子

直到输入错误停止：

```c++
cin.exceptions(ios_base::failbit);
    int sum=0, input;
    try
    {
        while(cin>>input) sum+=input;
    }
    catch(ios_base::failure &bf)
    {
        cout<<bf.what()<<endl<<"See that? Your input is shit!\n";
    }
    cout<<sum<<endl<<"last:"<<input;//input错误时重置为0[假设是enter，否则是上一个成功读入的数)
```

##### 清除

###### 空格

使用cin>>ws读取所有空格，适用于前有cin后有cin.getline的情景。

> skipws的意思是在用>>读取数据之前跳过空格（此时空格依然存在），ws的意思是读取后面的所有空格（空格被跳过）

使用示例：

```c++
char x[20];//设输入123    456 7，输出123\n456 7
string y;
cin >> ws >> x;
cin >> y;
cout << y << endl;
cin >> ws;
cin.getline(x, 20);
cout << x;
```

###### 缓存区

使用cin.clear()

或flush(cout),cout<<flush

其实最好是使用模版：

```c++
if(cin.fail()&&!cin.eof())
{
    cin.clear();
    while(!isspace(cin.get()));//不需要cctype库
}
```

示例：(仅检测a，如果输入错误置为0)

```c++
int a,b;
cin>>a;
if(cin.fail()&&!cin.eof())
{
    cin.clear();
    while(!isspace(cin.get()));
}
cin>>b;
cout<<a+b;
```



##### 场宽

iomanip

setw(n)<<var表示n宽右对齐输出var 只生效一次

cout<<xxx<<setw<<yy<<endl;

也可以用width方法 即cout.width(n) 

###### 填充

cout.fill(char)方法，设置属性，不是一次性。

##### 格式

一般都要用iomanip库

注意cin和cout都能用。

setf一般一次设置一个，如果两个，应当如此：

```c++
cout.setf(f1,f2);//返回值可以记忆，类型为ios_base::fmtflags
```

当第二个参数为如下第一层时，第一个参数如下第二层为：

- ios_base::basefield
  - ios_base::dec
  - ios_base::oct
  - ios_base::hex
- ios_base::floatfield
  - ios_base::fixed
  - iod_base::scientific
- ios_base::adjustfield
  - ios_base::left
  - ios_base::right
  - ios_base::internal 符号或基数前缀左对齐，值右对齐

###### 默认

0.0(或0.等)会显示为0

###### 对齐

cout.width(n) 右对齐

要左对齐可以前搞个std::left

```c++
cout<<std::left<<setw(6)<<3;//dack
```

也可以cout<<setiosflags(ios_base::left) 这个是持久的，关闭使用resetiosflags，参数相同



###### 小数位

cout.precision(n)表示保留n-1位小数位显示，注意n=0同n=1,n<0同n=6同默认

或cout<<precision(n)，自己调试是这一个之后才会有用的，而且也是一直有用。

但是如果0.0会用0表示，其他.0同理，为了避免这种情况，应当：

cout<<setiosflags(ios::fixed);

cout<<setprecision(n);那么这里的n就不是n-1位玄学了，就是n位了。当然int还是不会显示为小数的。2.0就正常了罢。

###### 进制

iostream头文件即可

hex,oct,dec分别代表十六进制、八进制、十进制(默认)

```c++
cout<<hex<<17<<endl;
cout<<dec<<18<<endl;
cout<<oct<<9<<endl;
```

如果要二进制，需要头文件bitset，如：

```c++
cout<<bitset<sizeof(unsigned long) * 8>(1UL << 27)<<endl;
cout<<(1UL << 27)<<endl;//普通输出
```

上述的*8代表8个hex位，即32个位。

十六进制英文字符默认小写，如果需要大写：

```c++
cout.setf(ios_base::uppercase)//x也会大写
```

默认不显示前缀，如要显示，使用：

```c++
cout.setf(ios_base::showbase)//十六0x，八0，十无
```

###### 禁用科学计数法

cout.setf(ios_base::fixed, ios_base::floatfield);

###### 正号

cout.setf(ios_base::showpos)正数和0，0.0会显示正号

###### 布尔值

布尔值显示为小写英文(0和1不会)

cout.setf(ios_base::boolalpha)

###### 记忆

例如：

```c++
cout<<1./3<<endl;
ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
streamsize prec = cout.precision(3);//prec是初始的6位
cout<<1./3<<endl;//现在是3位
cout.precision(1);
cout<<1./3<<endl;//现在是1位
cout.setf(orig, ios_base::floatfield);
cout.precision(prec);
cout<<1./3<<endl;//现在是默认的6位
```

可以清除记忆：

```c++
cout.unsetf(ios_base::boolshowpoint)//对应showpoint
cout.unsetf(ios_base::boolalpha)//其他控制符都是一样的，除了no的清除向非no的看齐，如：noshowbase的unsetf是showbase，同showbase的unsetf
```

###### 所有标记

可以一次设置多个，用按位或组合flag。

- skipws 输入跳过空白
- left 左对齐，用fill填充
- right
- internal 在规定宽度内指定的前缀后，指定的数值前，插入填充
- dec 十进制
- oct 八进制
- hex 十六进制
- showbase 前缀表示整数
- showpoint 浮点数显示小数点和尾0
- uppercase 十六进制大写，科学计数法E
- showpos 非负数显示正号
- scientific 科学计数法
- fixed 定点格式显示浮点数值(没有指数部分)
- unitbuf 每次插入后转储并清空缓冲区



##### 模版

#### cin.get

若传入参数为char同c的getchar

用法：cin.get();或cin.get(c);其中c为char

其实ch = cin.get()也行，那么还可以判断ch!=EOF

因为cin.get()返回值是int(ascii码)，不能够连用操作。如果达到文件尾，返回EOF。cin.get(c)返回istream对象引用或false(文件尾).



若传入参数为char*，则cin.get(chars, len);注意len-1为实际读取长度，因为\0考虑在内。

注意读到换行符会直接停止。



若没有参数，则也会第一个行(直到换行)。



可以复合拼接使用，如cin.get(...).get();第一个必须有参数。这也是推荐的格式，否则读完一次下一次就没了。反正要把\n给吃掉。

总之当要读取字符(不用cin读，用get,getline等，当然cin用了也没什么影响)而上一个换行没有被读走，都可以这么复合以下，例如：(cin>>year).get();

#### cin.getline

用法：cin.getline(char[], len, stopchar)

注意读取到的内容实际长度是len-1,因为最后一个是\0

如果在到达len之前读到stopchar，那么停止，不会读入stopchar，下次读取也不会管stopchar

示例：

```c++
char x[20];
cin.getline(x, 10, '9');
cout<<x;
cin.getline(x, 10, 'x');
cout<<x;
输入12393x输出1233
```

当stopchar为'\n'时,才是意义上的getline

当stopchar留空时，默认为'\n'

当len留空而stopchar存在时，实质上stopchar不生效，部分情况下效果等同于stopchar为'\n'，也是读到换行就停，部分情况会异常。个人推测是把stopchar的int数值当成了len。

#### getline

用法：getline(cin, string, stopchar)

大部分相似于cin.getline()，但注意char*变成了string而且不需要规定长度

同样可以省略stopchar,则默认为'\n',stopchar不会被读入到string中。

#### cerr, clog

用法同cout

#### cout.put

cout.put(char)同putchar()，当然了用cout也可以输出char

可以连续，如cout.put(c1).put(c2)

#### printf,scanf

cstdio头文件

#### write

cout.write(char*, n)输出前几个字符。string不行。

#### cin.ignore

返回istream引用；参数int=1,int=EOF,表示连续丢弃多少个字符或直到到达某个特殊字符。

#### 补充

cin其他方法：

- read(char* c, int n)读取指定数目n并读入c，不会在输入后面加入空值字符使之转化为字符串
- peek()返回输入中的下一个字符而不抽取输入例中的字符
- gcount()返回最后一个非格式化抽取方法读取的字符数 ??
- putback()将一个字符插入到输入字符串中，被插入的字符是下一条输入语句读取的首个字符

### 文件读写

fstream库

#### 创建

##### 只写

```c++
ofstream fw;
fw.open(路径);//以w方式
```

如果构造函数指定文件名，构造时自动打开。

##### 只读

```c++
ifstream fw;
fw.open("1.txt");
```

##### 更多方式

读和写的函数格式都可以一样，下面是两种不同的格式，均可以用：

ifstream fin(路径*(jing4)*, mode);

ofstream fout();

fout.open(路径 mode);

mode如下：

- ios_base::in 只读
- ios_base::out 只写(自身按位或表示r+；再加trunc为w+)
- ios_base::ate 打开并移到文件尾
- ios_base:app 追加(与out搭配为a)
- ios_base:trunc 覆盖(与out按位或也可以表示w)
- ios_base::binary 二进制
- c++mode C++模式

如果要多种同用，使用按位或操作符。同时使用in和out将得到读写模式。

#### 检测已打开

```c++
boolvar = fw.is_open()
```

#### 关闭

```c++
fw.close();
```

析构函数会自动调用关闭的

#### 使用

##### 只写

```c++
fw << chararray;
```

##### 只读

```c++
fw >> chararray;
cout << chararray;
```

如果读一个空文件，可能输出乱码。

###### 判断正常读取

fw.good()或直接以fw>>ca返回的布尔值为判断。

##### 二进制读写

###### 写

模式可以是:out+app+binary

```c++
fout.write((char *)&p1 , sizeof(p1));
//p1是任意内容，如结构体。
```

###### 读

模式可以是in+binary

```c++
fin.read()
```

##### 随机存储

###### seekg

fin.seekg(距离, 参照系)

距离单位是字节；参照系如下：

- ios_base::beg 开始(默认)
- ios_base::cur 当前
- ios_base::end 结尾

如fin.seekg(112)将指向第112个字节(首个字节编号为0)，是文件第113个字节。

可以利用streampos v = n * sizeof(类型);seekg(v)来跳跃访问。

###### tellg, tellp

tellg返回输入流当前指针位置；tellp返回输出流。都是以字节为单位，从开始处计算。

fstream中返回值相同；istream和ostream管理同一个文件，输入和输出互相独立。

##### temnam

生成随机文件名。

```c++
常量L_tmpnam(本机14)和TMP_MAX(本机32767)是持仓量
限制文件名包含字符数，确保当前目录中不生成重复文件名情况下tmpnam() 最多可调用次数
头文件cstdio/iostream
```

```c++
char pn[L_tmpnam] = {'\0'};
for(int i=0;i<10;i++)
{
    tmpnam(pn);
    cout<<pn<<endl;
}
```

在库iostream即可使用。

### 流

C++标准库有面向对象的输入输出软件包，即I/O流类库。

**流**是一种抽象，负责在数据的生产者和数据的消费者之间建立联系，并管理数据的流动。程序与外界进行信息交换时，程序对象建立流对象，并使之与外界文件对象联机链接。程序操作流对象使之对文件对象产生作用，程序运行时可以将流对象视作文件对象的化身。

凡是数据从一个地方传输到另一个地方的操作都叫做流操作。基本操作有从流中读取和向流中插入。

iostream声明了4个流对象：cin,cout,cerr,clog

- cin
- cout 标准输出流 命令行中用>重定向
- cerr 标准错误输出流，没有缓冲，发送即输出 2>重定向
- clog 有缓冲，缓冲满时被输出

> cin是输入流迭代器的一个实例，cout是输出流迭代器的一个实例istream_iterator类的默认构造函数返回指向输入流结束的实例，与之比较可以判断当前是否到达了输入流结束
>
> 所有I/O流列表：抽象流基类ios(头文件ios，同名不再说明)；输入流istream(通用输入流和其他输入流基类),ifstream(头fstream,文件输入流),istringstream(头sstream，字符串输入流)；输出流同理ostream,ofstream,ostringstream(头sstream)；输入输出流类iostream(头istream),fstream,stringstream(头sstream)；流缓冲类streambuf(抽象类),filebuf(磁盘文件，头fstream)，stringbuf(头sstream)。如果需要这些类的前向声明，可以用头iosfwd

> 输入流用*可以访问刚刚读取的元素，->直接访问类或结构元素的成员，++读取下一个元素；输出流也有++运算符，但没有意义

#### 输入流迭代器

istream\_iterator

`template<class t> istream_iterator<t>` ，是输入迭代器

举例：

```c++
istream_iterator<int>(cin); //cin输入流
istream_iterator<int>(); //cin EOF
```



#### 输出流迭代器

ostream_iterator

输出迭代器

举例：

```c++
ostream_iterator<double>(cout,"\t"); //cout输出流，以\t分割每个元素，注意不能用单引号作第二个参数
```



#### 文件输出流

意思是输出到文件，即写入文件

open\_mode如下：(ios_base::)

- app 文件尾追加数据
- ate 打开已有文件并找到文件尾
- in 打开输入文件，对输出流使用则不删除已有内容
- out 输出(默认有)
- trunc 存在则删除内容，若out但无ate,app和in，则隐含为此
- binary 二进制文本

可以使用put方法写到输出流(不受宽度、填充方式影响)，而cout<<put受影响。

write方法写二进制数据，第一个参数一般用reinerpret_cast char\*转要写的内容，第二个参数是被写的内容的sizeof。写二进制数据被称为对象的串行化。含有指针的对象不能直接write，这包括本身内置指针的string。可以使用boost库的Serialization库处理该问题。

seekp方法随机访问，tellp返回位置

错误处理方法：

- bad 若不可恢复错误，返回非0值
- fail 不可恢复错误或预期条件返非0，用零参量调用clear前，错误标记已经被清除，是!运算符的重载(即默认是这个)
- good 所有错误标记和文件结束标记都清除返回非0
- eof 遇到EOF返回非0
- clear 设置内部错误状态，如果默认参量调用，清除所有错误位
- rdstate 返回错误状态



#### 文件输入流

(输入流open\_mode只有in和binary)

get方法读入数据包括空白字符，>>不包括。

read方法传入参数建议是reinterpret_cast\<char\*\>(&要写入的实例),sizeof实例

有seekg和tellg



## 函数

### main

不允许main函数递归自己

#### 格式

下面的互相搭配(8种)都是不会报错和警告的：

```c++
int main   main //或signed，但其他都不行！
(void)  ()
return 0;   //不写
```

不写的方法在别的函数会warning



如果使用void，会报错：

```c++
void main()
```

### 内联函数

内联函数比常规函数稍快，但占用更多内存(调用n次将包含代码的n个副本)。C语言的宏用于定义函数则有点类似于此。

内联函数不能递归。

内联函数不使用单定义规则。但同一函数的所有内联定义必须相同。

inline只是对编译器的一个要求，不能确保一定会转为inline（递归函数、过于复杂的函数不转），而一些简单的函数编译器也会默认转inline。

### 参数

#### 位置参数

在函数声明中，无任何位置参数代表该参数尚未给出，而不代表无任何参数；后者使用void说明。

函数调用对象实例是传值，所以会调用一次复制构造函数。而调用对象引用不会。

#### 默认参数

必须从右向左添加默认值，方法同python

填写参数必须从左到右填写，不能跳过任何参数。

如果函数有声明，可以在声明中定义默认参数，在定义中则不必再定义。

以传入对象参数为例，可以有四种方法(假设对象名为po)：

```c++
f(po(1)); f((po)1); f(static_cast<po> 1); f(1);
```

### 重载

函数多态(函数重载)可以使用多个同名函数，允许函数有多种形式。

非重载情况下，如果填入的参数不与任何一个原型匹配，那将会执行强转。而重载且产生歧义的非匹配参数，如一个unsigned int对多态int, long将会报错。

不能重载一个只有const状态不同的函数。也不能重载参数类型完全一致的函数。

#### 重载解析

overloading resolution。大致过程如下：⇋ ⇌ ↕ ⇄ ⇅ ⇆

1. 创建候选函数列表，其中包含与被调用函数的名称相同的函数和函数模板。

2. 使用候选函数列表创建可行函数列表。从最佳到最差的匹配如下：

   1. 完全匹配。其中，完全匹配允许无关紧要的转换，如：

      ```c++
      T⇋T&
      T[]→*T
      T(argument list)→T*(argument list) //???
      T→const T
      T→volatile T
      T*→const T*
      T*→volatile T*
      ```

      常规函数优先于模板(包括显式具体化)。如果均是模版函数，更具体的优先(显式具体化)。最具体不一定意味着显式具体化，而意味着哪种类型转换最少。

   2. 提升转换。如char/short转int,float转double

   3. 标准转换。如int转char,long转double

   4. 用户自定义转换，如类声明中定义的转换.(???)

3. 确定是否有最佳可行函数，有用无报错。

### 链接性

不允许在一个函数(如main)中定义另外一个函数。所有函数存储连续性都自动是静态的，默认情况下，函数链接性为外部。如果要设置为内部链接性，使用static，必须同时在原型和函数定义使用关键字。

如果需要查询C语言链接，使用：

```c++
extern "C" void f(int);
```

否则默认为C++语言链接，即：

```c++
extern "C++" void f(int);
```

等效于：

```c++
extern void f(int);
```

### 返回类型后置

可以在最后写返回类型，如：

```c++
auto f2(double, int) -> double;
等价于： double f2(double, int);
```

主要用途：运行前未知的返回值：

```c++
template<typename T, typename U>
auto eff(T t, U u) -> decltype(T*U) {...}
```



### 匿名函数

又名lambda函数。

头文件functional(第二种方式不用)

```c++
function <void (int)> show = [](int n)->void{cout<<n<<" ";};//其实可以用auto，那也不用头文件了
int a[] = {1,2,3,4,5};
for_each(a, a+5, show);
```

```c++
for_each(a, a+5, [](int n)->void{cout<<n<<" ";});
```

特征：

- 使用[]代替了函数名

- 可以不声明返回类型(类似于delctype)

  ```c++
  [](int x){return x%3==0;}
  ```

可以访问变量：

```c++
int c;
c = count_if(x.begin(),x.end(),[](int x){return x%13==0;});
//改为：
int c;
for_each(x.begin(),x.end(),[&c](int x){c+=x%13==0;});
```

可以访问所有自动变量：

```c++
int c1=0, c2=0;
for_each(n.begin(),n.end(),[&](int x){c1+=x%3==0;c2+=x%13==0;});
```



### 补充

1. 函数内不能定义函数，但是可以定义类，所以可以定义函数符。
2. 由于函数内变量生存期缘故，返回一个对象时也调用复制构造函数。

## 格式

### 命名空间

using

默认用using namespace std;

可以仅仅略写一个，如using std::cout;那么cout可以略写

规定std是系统保留的命名空间，不应在其中定义新的类、函数或模板，但是可以对已有的std命名空间内的模板进行特化



**声明区域**(declaration region)，是可以在其中进行声明的区域，如全局变量的声明区域是所在文件，函数内变量声明区域是所在代码块。

**潜在作用域**(potential scope)，变量的潜在作用域从声明点开始到声明区域结尾，比声明区域小。

**作用域**(scope)是变量对于程序而言可见的范围。作用域小于等于潜在作用域。



**名称空间**(namespace)可以是全局的，也可以位于另一个名称空间中，但不能位于代码块中，默认情况下，名称空间中声明的名称是外部链接性的，除非它引用了常量。

```c++
namespace Jack
{
    double pail;
    void fetch();
    struct Well {...};
}
```

在用户定义的名称空间外，还存在全局名称空间(global namespace)，对应于文件级声明区域。全局变量位于全局名称空间中。

名称空间是开放(open)的，可以把名称加入到已有的名称空间中，如上述例子把pail,fetch,Well加入到了Jack中。



作用域解析符:: 使用名称空间来限定该名字。未被装饰的名称称为未限定的名称(unqualified name)，包含名称空间的名称(std::cout)被称为限定的名称(qualified name)。

例如，在main(或其他)函数内和全局都有一个变量x，调用方法分别举例如下：

```c++
cout<<x<<endl;
cout<<::x<<endl;
```



using声明由被限定的名称和它前面的关键字组成。

```c++
using Jack::fetch;
```

作用是将特定的名称添加到它所属的声明区域中。

using编译时让一个名称空间内所有名称都可用，如：

```c++
using namespace Jack;
```

使用了using编译时，在代码块内新建的变量等，将会默认为该名称空间内的；如果新的变量名与名称空间冲突，那么将隐藏名称空间内的变量。但是如果已有变量名再用using编译，发现名称空间内有重名，那么将会出错。



如果系统不支持名称空间，可以将这两行代码：

```c++
#include <iostream>
using namespace std;
```

修改为：

```c++
#include <iostream.h>
```



#### 嵌套

```c++
namespace elements
{
    namespace fire
    {
        int flame; ...
    }
    float water; ...
}
```

那么：

```c++
using namespace elements::fire;
```



名称空间内可以使用using编译和using声明：

```c++
namespace myth
{
    using Jack::fetch;
    using namespace elements;
}
```

那么访问fetch可以两者之一：

```c++
myth::fetch
Jack::fetch
```

因而，using编译指令是**可传递**的，即：

> A op B 且 B op C 则 A op C

那么只要using编译了myth，会自动编译elements及Jack::fetch



#### 别名

```c++
namespace name2 = name1;
using name2::v;//等效于using name1::v;
```

#### 匿名名称空间

其内部的变量等效于内部链接的静态变量(即无需::在本文件内可直接引用)

```c++
namespace
{
    int var1;
}
```

一般不希望被其他源代码引用的代码部分可以放到这里面。那么extern无法调用这里的内容。

#### typedef式

下面的例子两两等价：(非模板时)

```c++
typedef const char * pc1;
using pc1 = const char*;
```

```c++
typedef const int *(*pal)[10];
using pa1 = const int *(*)[10];
```

差别在于，typedef不能模版部分具体化，using可以。

```c++
template <typename T>
using ax = std::array<T, 12>;
```



#### 应用

在跨文件中，头文件.h和对应的文件.cpp对应的区域都要使用namespace，当然在.cpp中只需要补充函数定义之类的。



一些指导原则：

- 使用在已命名的名称空间中声明的变量，而不是使用外部全局变量、静态全局变量
- 如果开发了一个函数库或类库，将其放在一个名称空间中。C++当前提倡将标准函数库放在std中。如cmath，而math.h没有名称空间。
- 仅将编译指令using作为一种将旧代码转换为使用名称空间的权宜之计
- 不要在头文件使用using编译指令，这样掩盖了要让哪些名称可用；另外，包含头文件的顺序可能影响程序的行为；如果要用，应该放在所有预处理编译指令#include之后
- 导入名称后，首选使用作用域解析运算符或using声明的方法
- 对于using声明，首选将作用域设置为局部而不是全局

### 保留字

保留字是不能(应)用作声明标识*(shi2)*符的字符串，分为：

- 关键字
- 替代标记(alternative token)
- C++库保留字

> final override不是关键字，但是也尽量不要用来作标识符
>
> main cout iostream也不是关键字，当然也不应当这么去做。

#### 替代标记

可以替代运算符：

```c++
cout<< (1 and 0) <<endl;
```

具体有：

```c++
and &&
and_eq &=
bitand &
bitor |
compl ~
not !
not_eq !=
or ||
or_eq |=
xor ^
xor_eq ^=
```

#### C++库保留名称

保留给C++库使用的名称，如：

```c++
CHAR_BIT
```

以及以两个下划线加字母开头、单个下划线开头加字母的标识符。

## 标准模板库

STL，Standard Template Library，标准模板库，是一组用于处理各种容器对象的模板。STL具有容器概念和容器类型。概念是具有名称(如容器序列容器、关联容器等)的通用类别；容器类型是可用于创建具体容器对象的模板。

> 除STL外，还有TR1(C++ technical report 1)的实现库Boost，提供了诸如array,unordered\_map,拓展bind偏函数,regex,date time等，具体可以参考[这里](http:www.boost.org)

STL算法库有：(前三条在algorithm，后一条在numeric)

- 非修改式序列操作，如*find,for_each*。
- 修改式序列操作
- 排序和相关操作
- 通用数字运算

有些算法同时有就地算法(in-place algorithm，如sort)，有的用复制版本(copying algorithm)，复制版本以_copy为结尾。

有些可以传入执行条件，使用_if结尾，如replace的。也有结合版本的，先输入copy后if，两条下划线。

用概念(concept)来描述泛型程序设计中作为参数的数据类型所需具备的功能，内涵是功能，外延是具备这些功能的所有数据类型，如Iterable。具备一个概念所需功能的数据类型可以称为是这一个概念的一个模型(model)。若概念B的模型一定是概念A的模型，那么概念B是概念A的子概念，或精炼(refinement)。

适配器(adapter)是用于为已有对象提供新的接口的对象，并不提供新的功能，仅仅提供新接口

STL函数可以分为四类：(前三类algorithm)

- 不可变序列算法 non-mutating algorithms 不直接修改所操作的容器内容的算法

  具体有`for_each,find,find_if,adjacent_find(相邻而重复),find_first_of,find_end,count,count_if,mismatch(找不匹配点),equal,search(子序列),search_n(连续n次子序列)`

- 可变序列算法(mutating algorithms)能够修改操作的容器

  具体有：`copy,copy_n(复制前n个),copy_backward,fill,fill_n(填充前n),generate(计算并替换),generate_n,partition(满足关系的放在不满足的之前以重排),stable_partition,rotate(旋转交替排列),rotate_copy(结果复制到另一个容器),unique,unique_copy,random_shuffle,remove(删除所有特定值),remove_if,remove_copy,remove_copy_if,replace,replace_copy_if,reverse,reverse_copy,swap,iter_swap(元素互换),swap_ranges(区间中元素交换),transform`

- 排序和搜索算法

  具体有：排序算法`sort,stable_sort,partial_sort(部分排序，未排序部分相对不变),partial_sort_copy,nth_element(以第n个元素为依据，使得左侧小于它，右侧大于)`，二分搜索算法`binary_search,lower_bound,upper_bound,equal_range(返回上下限)`，合并有序区间算法`merge,inplace_merge(代替原有序列)`，最值算法`min,max,min_element(所在位置),max_element`，排序相关算法`lexicographical_compare(字典序),next_permutation,prev_permutation`，有序序列集合操作`includes(区间包含),set_union(并),set_intersection(交),set_difference,set_symmetric_difference`，堆相关`make_heap(建堆),pop_heap(取顶),push_heap(添加元素),sort_heap(排序)`

- 数值算法(numeric库) 

  具体有：`accumulate,partial_sum(前缀和数组),adjacent_difference(差分数组),inner_product(向量内积)`

### 头文件特点

头文件可以包含：

- 函数原型（不可函数定义，除非函数是内联的；如果包含函数定义，在同一个程序的两个文件包含该头文件，则会包含两个函数定义，引发出错）
- 内联函数
- #define或const常量
- 结构声明
- 类声明
- 模版声明



头文件的写法：

- 尖括号的文件会在主机系统文件系统查找
- 双引号的文件首先查找当前工作目录或源代码目录或其他目录



头文件模板：(以myhd.h为例)

1. 防止重复引用错误。在同一个文件中只能将同一头文件包含一次。

   ```c++
   #ifndef MYHD_H_
   #define MYHD_H_
   ...
   #endif//头文件尾部
   ```

2. 



### 数学

库ratio支持有理算数库。

#### min，max

库alorithm

比较的东西必须是同类型的，哪怕int和short也不能进行比较

vs因冲突而不允许使用，如果要用，#define NOMINMAX

两两比较就两个参数；如果需要比较函数可以传多一个参数

多个比较可以用大括号括起，只需要一个参数：

```c++
auto k=max({2,3,7,5});
cout<<k;
```

##### min_element,max_element

返回容器内第一个最值位置

#### abs

库cmath

#### accumulate

库numeric

类似于Python的reduce，参数列表如下：

```c++
accumulate(迭代器头部，迭代器尾部，初始值，函数参数)
```

返回运算结果，举例如下：

```c++
#include <iostream>
#include <numeric>
typedef int ll;
using namespace std;
ll add(ll x, ll y) { return x + y; }
ll mul(ll x, ll y) { return x * y; }
signed main()
{
    ll a[] = {1, 2, 3, 4, 5};
    cout << accumulate(a, a + 5, 1, add) << endl;
    cout << accumulate(a, a + 5, 10, mul);
    return 0;
}
```

#### partial_sum

计算一维前缀和

##### adjacent_difference

计算一维差分

```c++
ll x[] = {2, 2, 3, 2, 3}, s[5], d[5];
partial_sum(x, x + 5, s);
adjacent_difference(x, x + 5, d);
for (auto i : s)
    cout << i << endl;
cout << endl;
for (auto i : d)
    cout << i << endl;
```

#### inner_product

向量内积

```c++
ll x[] = {2, 2, 3, 2, 3}; //计算自己的范数平方
cout << inner_product(x, x + 5, x, 0);//初始为0
```





### 字符和数组

#### to_string

string库，功能顾名思义， stringvar = to_string(anyvar)

#### sort

algorithm库

排序后为升序

对象：任意定义了小于运算符的对象

排序对象是普通数组，则用sort(array, array+n)调用

对象是vector，用sort(v.begin(), v.end())调用

第三个参数可以是一个函数如bool lessX(const Point &p1, const Point &p2) {return p1.x<p2.x;}的lessX

或者使用匿名函数

```c++
sort(v.begin(), v.end(), [](int x, int y){return x>y;});
```

如果要重载，一定要重载小于号，而且参数格式严格如下，不能漏后一个const(不开传引用可以不用const)

```c++
bool operator<(const edge& x)const{return d<x.d;}
inline bool operator<(const edege& x, const edge& y){...}
```

不能够有多个cmp函数重载

##### 注意

先后顺序问题：

如果要保证在所有被筛选数据相同的情况下，保持一个LIFO或FIFO的关系，必须使用一个额外的序号成员变量(一般这种都是struct或class)，而不是默认最后返回1或0，因为在排序过程中，可能会打破原有的顺序。例如：

```c++
bool cmp(people a, people b)
{
    if(a.y!=b.y) return a.y<b.y;
    if(a.m!=b.m) return a.m<b.m;
    if(a.d!=b.d) return a.d<b.d;
    return a.i>b.i;//LIFO
}
```

##### partial_sort

```c++
partial_sort(lf,cf,rf);
```

保证\[lf,cf)有序，\[cf,rf\]按本来的相对顺序。

```c++
ll x[] = {1, 6, 2, 5, 4, 3};
partial_sort(x, x + 3, x + 6);
for (auto i : x)
    cout << i << endl;
```



#### next_permulation

修改一个容器，使其成为自身的下一个排列(如all变成lal，再次调用变成lla；而abc一共可能有6种)。

返回值bool，当不再有下一个排列时，返回false，否则true。

一般是先默认sort，后使用。

示例如下：

```c++
string x;
cin>>x;
sort(x.begin(),x.end());
do{cout<<x<<endl;}while(next_permutation(x.begin(),x.end()));
```



#### lower_bound,upper_bound

lower_bound(array, array+k,x)//一般k为LEN

查找大于或等于x的第一个位置

upper_bound找大于。//da cks

以二分搜索向左第一个数为例：

```c++
int d = lower_bound(a,a+n,f)-a;
if(f!=a[d]) printf("-1");
else printf("%d", d+1);
```

默认对上升序列使用，如果要对下降序列使用，需要加greater如下

指针写法：

```c++
*upper_bound(d1+1,d1+1+len1,a[i],greater<int>())=a[i];
```

将vector于二分插入结合，可以实现$O(logn)$的有序插入

#### find

find(array, array+k, v)返回位置；也可以begin(),end()

##### find_if

find(a,a+k,一元谓词) 返回位置(找不到则end)

如果迭代器first>last，那么循环查找，先找first后元素，再找last前元素

#### remove

remove(pb, pe, v)删除闭区间内所有v值，但不改变容器长度；返回迭代器，指向真实长度(假设改变)+1。

#### advance

使迭代器前进n个元素，适用于所有迭代器，第一个参数是迭代器引用，第二个参数是整数距离，表示前进或后退的单位(正负控制)。

#### distance

distance(x,y)返回两个指针/迭代器的位置，需要保证后者不在前者前面

例如:A[distance(A, lower_bound(A,A+LEN,4))]=4

#### transform

algorithm头文件

```c++
double a[] = {36,39,42,45,48};
vector<double> ap(a,a+5), bp(5);
ostream_iterator<double, char> out(cout, " ");
transform(ap.begin(),ap.end(),out,f); cout<<endl;
transform(ap.begin(),ap.end(),bp.begin(),f);
for(auto i:bp) cout<<i<<" ";
```

数组和容器都可以。

```c++
double a[] = {36,39,42,45,48}, b[5];
ostream_iterator<double, char> out(cout, " ");
transform(a,a+5,out,f); cout<<endl;
transform(a,a+5,b,f);
for(auto i:b) cout<<i<<" ";
```

也可以两个数组/容器操作：

```c++
double a[] = {36,39,42,45,48}, b[5], c[] = {1,2,3,4,5};
transform(a,a+5,c,b,multiplies<double>());
for(auto i:b) cout<<i<<" ";
```

也可以是迭代器：

```c++
transform(istream_iterator<double>(cin),istream_iterator<double>(),
              ostream_iterator<double>(cout,"|"),
              [](double x){return x*x;} );
```

> 上述代码将输入流(EOF结束)所有double平方后输出，间隔为\|



#### random_shuffle

algorithm库，打乱元素

```c++
random_shuffle(a.begin(),a.end());
```

注意要置随机数种子

```c++
srand(time(NULL));//需要algotirhm以及ctime
```



#### unique

```cpp
int ans=unique(a,a+n)-a;//给数组a去重，并保留ans=去重后非伪的长度
```

#### binary_search

#### nth_element

```cpp
nth_element(a,a+k,a+n);//使容器a+k元素左边都小于它，右边都大于它
```

```c++
ll x[] = {1, 5, 9, 2, 3, 6, 8, 10};
nth_element(x, x + 1, x + 8);
for (auto i : x)
    cout << i << endl;
```



#### max_element

```c++
*max_element(array.begin(),array.end())//获取最大元素，即python的max函数
```

#### fill

```c++
fill(dis+1,dis+n+1,inf);
```

#### merge

merge函数的作用是：将两个有序的序列合并为一个有序的序列。函数参数：merge(first1,last1,first2,last2,result,compare);

//firs1t为第一个容器的首迭代器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，last2为容器的末迭代器，result为存放结果的容器，comapre为比较函数（可略写，默认为合并为一个升序序列）。

##### inplace_merge

对一个容器的两个有序子区间合并，不占用额外空间，返回值放在原容器

```c++
inplace_merge(lf,cf,rf)
```

```c++
ll x[] = {1, 5, 9, 2, 3, 6, 8, 10};
inplace_merge(x, x + 3, x + 8);
for (auto i : x)
    cout << i << endl;
```



#### mismatch

```c++
mismatch(first1,last1,first2)
mismatch(first1,last1,first2,comp)
```

寻找两个序列第一次不相同的位置，返回pair，分别是不相同时a,b的位置迭代器(相同时可以判断\*first==\*second，也可以判断迭代器的位置)，实际搜索长度取决于first1和first2哪个长

举例：

```c++
inline bool cmp(ll a, ll b) { return abs(a - b) <= 1; }
ll a[] = {1, 2, 3, 5, 10}, b[] = {1, 2, 3, 6, 18}, c[] = {1, 2}, d[] = {0, 1, 2};
auto m1 = mismatch(c, c + 2, d + 1);
cout << *m1.first << ',' << *m1.second << endl;
m1 = mismatch(a, a + 5, b);
cout << *m1.first << ',' << *m1.second << endl;
m1 = mismatch(a, a + 5, b, cmp);
cout << *m1.first << ',' << *m1.second << endl;
```

#### search

连续$k$个$v$的起始位置

```c++
search(first,last,k,v,comp)
```

举例：

```c++
ll a[] = {1, 7, 2, 7, 3, 7, 7, 4};
auto p = search_n(a, a + 8, 2, 7);
cout << (p - a) << endl;
```

#### copy

如果两个迭代器是同一个容器的，且第二个迭代器在第一个迭代器区间内，必须用copy\_backward

#### remove

是假删除，要实现真删除释放空间，需要再次调用erase。返回删除后迭代器尾部。

```c++
vector<ll> x = {1, 3, 2, 3, 4, 3, 3, 5};
x.erase(remove(x.begin(), x.end(), 3), x.end());
// cout << remove(x.begin(), x.end(), 3) - x.begin() << endl; //如果这样是假删除，还是可以遍历到的，返回值是x.begin()+4
for (auto i : x)
    cout << i << endl;
```

#### replace

将所有符合要求元素进行替换

```c++
ll x[] = {1, 3, 2, 3, 4};
replace(x, x + 5, 3, 580);
for (auto i : x)
    cout << i << endl;
```

#### rotate

```c++
rotate(lf,cf,rf);//置换区间[lf,cf),[cf,rf]
```

```c++
ll x[] = {1, 2, 3, 4, 5};
rotate(x, x + 3, x + 5);
for (auto i : x)
    cout << i << endl;
```



#### generate

执行生成器函数，将结果放到迭代器区间

```c++
inline ll nex()
{
    static ll k = 1;
    return (k *= 2);
}
generate(b, b + 5, nex);
for (auto i : b)
    printf("%d ", i);
putchar('\n');
```

#### for_each

对迭代器每个元素传入一个一元函数里执行操作

```c++
ll a[] = {87, 4, 25, 5800}; 
for_each(a, a + 4, [](ll x)
         { cout << __gcd(580, x) << endl; });
```

#### lexicographical_compare

以字典序比较两个序列

```c++
ll x[] = {1, 3, 2, 4}, y[] = {1, 222, 6, 333};
auto k = lexicographical_compare(x, x + 4, y, y + 4);
cout << k << endl; //x字典序大于y
```





### 随机数

#### 常规

库cstdlib

rand()生成[0, RAND_MAX]内随机均匀整数；RAND_MAX至少是2^15-1折合32767；

获取[0, n-1]之间整数，用rand()%n产生

n大于RAND_MAX时，随机数精度不好，会锯齿化

置随机数种子（只执行一次）

srand(参数)

参数一般选择time(NULL) ，该函数在ctime定义

#### 拓展

random库

### 时期

#### 时间

chrono库提供处理时间间隔途径

#### 日期

### 正则表达式

regex库

### 并行

原子操作(atomic operation)库提供了头文件：

- atomic

线程支持库提供头文件：

- thread
- mutex
- condition_variable
- future



### 其他

#### exit

exit(EXIT_FAILURE);//exit(1);

#### swap

交换两个变量,<iostream.h>

#### reverse

在algorithm库

应用：反转begin和end，可以是str,stack等

## 特点

C++是C的超集，任何有效的C程序都是有效的C++程序。

支持泛型编程(generic programming)，即使重用代码和抽象通用概念的技术更简单。泛型是创建不依赖于具数据体类型的代码。

多态：为运算符和函数创造多个定义，根据上下文确定使用哪个

- 强制多态(强转类型)
- 重载多态(函数和运算符重载)（前两者统称专用多态，后两者通用多态）
- 参数类型化多态(模板)
- 包含多态(虚函数)

自下而上(bottom-up)的编程，从低级组织(如类)到高级组织(如程序)的处理过程。

语言链接性(language linking)。C中，一个名称对应一个函数。C++不一定，所以执行名称矫正或名称修饰，为重载函数生成不同的符号名称，称为C++语言连接。

集成开发环境(IDE intergrated developed environment)，不同编译器用不同的后缀名，如cc,cxx,cpp,cp,C

## 注意要点

1.main之前加入一行代码

```c++
using namespace std;
```

若无这行代码，cin需要用std::cin

如果写着代码突然发现有什么东西说未定义，如max,queue，大概是没开using namespace std;

2.不能在全局域进行赋值操作，如cstring的memset

3.不能定义名为如下的变量，如果使用了bits/stdc++.h

- y1或y0或yn(建议用ny)
- prev
- tm

4.

# 数据结构

数据的逻辑结构：集合(不是数学集合，不唯一性)、线性表、树、图

数据的存储结构：顺序、链式、索引、散列

## 线性结构

### 顺序表

顺序表 sequence list，若可以以$\Omicron(1)$获取任意元素的下标/位置，是随机存取 random access结构。

线性表的数据元素具有相同的数据类型。

按位查找get O(1)

按值locate、遍历、插入删除 O(n)

大小事先已知

> 序偶关系(a,b) 指的是$a,b$互为前驱和后继

### 链表

Linked Table，数组是连续存储，随机访问的线性表，链表是分散存储，连续访问的线性表。有至多一个直接前驱和至多一个直接后驱。

#### 单向链表

又名线性链表。单链表 singly linked list。

特点：用任意不一定是连续的存储单元来存储线性表的数据，长度不固定。只能顺序访问。

每个元素称为节点。每个节点包括数据域和指针域，指针域指向下一个节点。末节点指针域指向NULL。头指针，等效于数组变量名。头指针丢失会导致整个链表丢失。

往往为了方便而添加空头结点。所有操作时间复杂度均为O(n)，因为搜索的过程是n。频繁插入删除、长度变数大/未知可用。





##### 定义

```c
typedef struct link
{
    int data;
    struct link *next;
} LINK;
LINK *x = NULL;//初始化
```

以下默认升序排列。

```c
//注：一般就算是新建也用插入的好，这个是不会给排序的
LINK *addnode(LINK *head, int data)
{
    LINK *p = NULL, *pr = head;
    p = (LINK *)malloc(sizeof(LINK));
    if(p==NULL)
    {
        printf("No enough memory to alloocate!\n");
        exit(0);
    }
    if(head==NULL)   head = p;
    else
    {
        while(pr->next != NULL) pr = pr->next;
        pr->next = p;
    }
    p->data = data;
    p->next = NULL;
    return head;
}
```

##### 插入

```c
LINK *insertnode(LINK *head, int data)
{
    LINK *pr = head, *p = head, *temp = NULL;
    p = (LINK *)malloc(sizeof(LINK));
    if(p==NULL)
    {
        printf("No enough memory to alloocate!\n");
        exit(0);
    }
    p->next = NULL;
    p->data = data;
    if(head == NULL) head = p;
    else
    {//规定链表是升序存储的
        while(pr->data<data && pr->next != NULL)
        {
            temp = pr;
            pr = pr->next;
        }
        if(pr->data >= data)
        {
            if(pr==head)
            {
                p->next = head;
                head = p;
            }
            else
            {
                pr = temp;
                p->next = pr->next;
                pr->next = p;
            }
        }
        else pr->next = p;
    }
    return head;
}
```

##### 删除

```c
LINK *delnode(LINK *head, int data)
{//假设data不重复
    LINK *p = head, *pr = head;
    if(head == NULL)
    {
        printf("Empty linked table!\n");
        return head;
    }
    while(data != p->data && p->next!=NULL)
    {
        pr = p;
        p = p->next;
    }
    if(data == p->data)
    {
        if(p==head) head=p->next;
        else pr->next = p->next;
        free(p);
    }
    else printf("Not found!\n");
    return head;
}
```

##### 清空

```c
//退出程序前必须如此
void delallnode(LINK *head)
{
    LINK *p = head, *pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
```

##### 输出

```c
void shownode(LINK *head)
{
    LINK *p = head;
    int i=1;
    while(p != NULL)
    {
        printf("%-4d%d\n",i,p->data);
        p=p->next;
        i++;
    }

}
```

##### C++版

```c++
#include <bits/stdc++.h>
using namespace std; //个人实现版
struct lt
{//linktable which has an empty head pointer.
    int v = 0;
    lt* next = nullptr;
};
void insert(lt *head, int i, int v)
{//after insert, lt[i]=v, origin lt[i]=lt[i+1]
    if(i<0) throw "Index less than zero.\n";
    lt* temp = head;
    while(i--)
    {
        temp = temp->next;
        if(temp == nullptr) throw "Index out of range.\n";
    }
    lt* nx = temp->next;
    lt* nw = new lt;
    nw->v = v;
    temp->next = nw;
    nw->next = nx;
}
void erase(lt *head, int v)
{
    lt* old = head;
    lt* temp = head->next;
    if(temp==nullptr) throw "An empty linktable.\n";
    while(temp->v != v)
    {
        old = temp;
        temp = temp->next;
        if(temp == nullptr) throw "Cannot find the value.\n";
    }
    old->next = temp->next;
    delete temp;
}
void pop(lt *head, int i)
{
    if(i<0) throw "Index less than zero.\n";
    lt *old = nullptr;
    lt *temp = head;
    while(i-->=0)
    {
        old = temp;
        temp = temp->next;
        if(temp == nullptr) throw "Index out of range.\n";
    }
    old->next = temp->next;
    delete temp;
}
int get(lt *head, int i)
{
    if(i<0) throw "Index less than zero.\n";
    lt* temp = head;
    while(i-->=0)
    {
        temp = temp->next;
        if(temp == nullptr) throw "Index out of range.\n";
    }
    return temp->v;
}
void printall(lt *head, string sep=" ", string finish="\n")
{
    lt* temp = head->next;
    if(temp==nullptr) throw "An empty linktable.\n";
    cout<<temp->v;
    for(temp=temp->next; temp!=nullptr; temp=temp->next)
    {
        cout<<sep<<temp->v;
    }
    cout<<finish;
}
int locate(lt *head, int v)
{
    int i=0;
    lt* temp = head->next;
    while(temp->v != v)
    {
        temp = temp->next;
        if(temp == nullptr) throw "Cannot find the value.\n";
        i++;
    }
    return i;
}
int len(lt *head)
{
    lt* temp = head->next;
    int i=0;
    while(temp!=nullptr)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
```



##### 使用示例

```c
//示例1：如何调用上面的函数
int main()
{
    int i=0;
    char c;
    LINK *head = NULL;//初始化
    shownode(head);
    head = addnode(head, 3);//记得head=这个操作，否则是不会更新的
    head = addnode(head, 4);
    shownode(head);
    head = insertnode(head, 1);
    shownode(head);
    head = insertnode(head, 2);
    shownode(head);
    head = insertnode(head, 9);
    shownode(head);
    head = delnode(head, 4);
    shownode(head);
    head = delnode(head, 9);
    shownode(head);
    head = delnode(head, 1);
    shownode(head);
    head = delnode(head, 100);
    delallnode(head);
    return 0;
}
```

#### 双向链表

可以在表头设置一个特殊节点以简化链表的实现，称为头结点或标兵节点，不包含实际数据，但可以更容易实现删除的操作。插入删除开销加倍，存储空间增加。

##### 定义

```c
struct dnode{
    int key;
    struct dnode *prev, *next;
} DN;
```

##### 初始化

```c
DN *nil = NULL;
nil = (DN *)malloc(sizeof(DN));
nil->next = nil;
nil->prev = nil;
```

##### 插入

```c
void insertdn(int key)
{//nil是插入者的前方
    DN *x = (DN *)malloc(sizeof(DN));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    x->prev = nil;
}
```

##### 搜索

```c
DN* seadn(int key)
{//nil是头结点
    DN*cur = nil->next;
    while(cur != nil && cur->key != key) 
        cur = cur->next;
    return cur;
}//O(n)
```

##### 删除

```c
void deldn(DN* t)//t首先用搜索搞到
{
    if(t==nil) return;//nil是头结点
    t->prev->next = t->next;
    t->next->prev = t->prev;
}//O(n)
//首元素是nil->next,尾元素是nil->prev
```

##### C++版

```c++
#include <bits/stdc++.h>
using namespace std;//个人实现
template<class T>
struct dblt
{
    T v=0;
    dblt *next=nullptr, *prev=nullptr;
    void push(T v)
    {
        dblt<T> *tmp = nullptr;
        if(next==nullptr)//empty dblt
        {
            tmp = new dblt<T>;
            tmp->next = tmp->prev = this;
            this->next = this->prev = tmp;
        }
        else
        {
            tmp = new dblt<T>;
            tmp->next = this;
            tmp->prev = this->prev;
            this->prev->next = tmp;
            this->prev = tmp;
        }
        tmp->v=v;
    }
    void printall(char sep=' ', char fin='\n') const
    {
        dblt<T> *tmp = this->next;
        if(tmp==nullptr) return;//empty dblt
        while(tmp!=this)
        {
            cout<<tmp->v<<sep;
            tmp = tmp->next;
        }
        cout<<fin;
    }
    int length() const
    {
        int len=0;
        dblt<T> *tmp = this->next;
        if(tmp==nullptr) return len;
        while(tmp!=this)
        {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    T operator [](int x) const
    {
        dblt<T> *tmp = this->next;
        if(tmp==nullptr) throw "Empty linktable.\n";
        if(x<0) throw "Invalid negative index.\n";
        while(x--)
        {
            tmp = tmp->next;
            if(tmp==this) throw "Index out of range.\n";
        }
        return tmp->v;
    }
    dblt<T>* get(int x) const
    {
        dblt<T> *tmp = this->next;
        if(tmp==nullptr) throw "Empty linktable.\n";
        if(x<0) throw "Invalid negative index.\n";
        while(x--)
        {
            tmp = tmp->next;
            if(tmp==this) throw "Index out of range.\n";
        }
        return tmp;
    }
    void insert(int i, int x)
    {
        if(i==this->length()) this->push(x);//tmp=this->prev;
        else
        {
            dblt<T> *tmp = this->get(i)->prev;
            dblt<T> *nw = new dblt<T>;
            nw->v=x;
            nw->prev=tmp;
            nw->next=tmp->next;
            tmp->next->prev=nw;
            tmp->next=nw;
        }
    }
    void erase(int i)
    {
        dblt<T> *tmp = this->get(i);
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
    }
    int find(int x) const
    {
        int i=0;
        dblt<T> *tmp = this->next;
        if(tmp==nullptr) throw "Empty linktable.\n";
        while(tmp!=this)
        {
            if(tmp->v==x) return i;
            tmp = tmp->next;
            i++;
        }
        throw "Not found.\n";
    }
    int rfind(int x) const
    {
        int i=this->length()-1;
        dblt<T> *tmp = this->prev;
        if(tmp==nullptr) throw "Empty linktable.\n";
        while(tmp!=this)
        {
            if(tmp->v==x) return i;
            tmp = tmp->prev;
            i--;
        }
        throw "Not found.\n";
    }
};
```

#### 循环链表

通常附设头结点

可以用尾指针循环链表

next为尾：停止遍历

#### 循环双链表

通常带头结点

插入和删除比较方便

#### 静态链表

用数组实现的链表。

竞赛常用

a[N]   next[N]

插入删除修改游标

不能解决表长问题

### 栈

堆栈stack，是限定性线性表

新加元素是压入堆栈push,删除元素是弹出堆栈pop，运算方式是后进先出LIFO:last input first output；可以使用链表方式存储栈



以下代码，首个表示非链表，第二个表示链表，以int为数据为例

下面代码没有判断栈空

##### 定义

```c
typedef struct stack
{//一个它是类数组而不是类元素
    int data[N];
    int top;
} STACK;
STACK a;
a.top = 0;//初始化
```

```c
typedef struct stack
{
    int data;
    struct stack *next;
}STACK;
STACK *top = NULL;//初始化
```

##### 压入

```c
void pushstack(STACK *stack, int data)
{//等效于stack->data[stack->top++] = data;
    memcpy(&stack->data[stack->top], &data, sizeof(int));//这行我不理解
    stack->top = stack->top + 1;
}
```

```c
STACK *push(STACK *top, int data)
{
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));//无写ifNULL检测
    p->data = data;
    p->next = top;
    top = p;
    return top;
}
```

##### 弹出

```c
int popstack(STACK *stack)
{//不能用减1运算符合并为一行
    stack->top -= 1;
    return stack->data[stack->top];
}
```

```c
STACK *pop(STACK *top)
{
    STACK *p;
    if(top==NULL) return NULL;
    else
    {
        p = top;
        top = top->next;
        free(p);
    }
    return top;
}
```

##### 示例

```c
	STACK stack;//非链表
    stack.top = 0;//初始化！
    pushstack(&stack, 3);//注意取地址
    pushstack(&stack, 4);
    printf("%d\n", popstack(&stack));
    pushstack(&stack, 5);
    printf("%d\n", popstack(&stack));
    printf("%d\n", popstack(&stack));
```

```c
int main()//链表
{
    STACK *top = NULL;//初始化
    top = push(top, 3);
    top = push(top, 4);
    printf("%d\n", top->data);
    top = pop(top);
    printf("%d\n", top->data);
    return 0;
}
```

一个C++版本(非链表)如下(.h和.cpp)：

```c++
#infdef STACK_H_
#define STACK_H_
typedef unsigned long Item;
class Stack
{
private:
    enum {MAX=10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
}
#endif
//ano file
#include "stack.h"
Stack::Stack() {top = 0;}
bool Stack::isempty() const {return top==0;}
bool Stack::isfull() const {return top==MAX;}
bool Stack::push(const Item &item)
{
    if(top<MAX)
    {
        items[top++] = item;
        return true;
    }
    else return false;
}
bool Stack::pop(Item &item)
{
    if(top>0)
    {
        item = items[--top];
        return true;
    }
    else return false;
}
```

> 一种指针版本的写法见C++ - 数据 - template - 类模版

#### 顺序栈

用顺序表实现栈

初始top=-1(空栈)

is_empty, get_top pop push 均O(1)

#### 链栈

链表实现栈

均 O(1)

#### 单调栈

一般而言，给定区间求最值用线段树；给定最值求区间用单调栈。

##### 例题

###### 单调栈(模板)

找出一个数组(下标从1算)的每个元素其后面首个大于它的元素的下标，查无则0

```c++
#include <bits/stdc++.h>
#define MAXN 3000002
using namespace std;
int n,a[MAXN],uf,sta[MAXN],ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=(1<<31)-1;
    for(int i=1;i<=n;i++)
    {
        while(uf && a[sta[uf]]<a[i])
        {
            ans[sta[uf--]]=i;
        }
        sta[++uf]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}
```

###### 小鱼比身高

> (oj)有$n$条鱼，身高为$h_i$，设左数第$i$条鱼与它左边第一条高度大于等于它的鱼之间隔了$c_i$条鱼(如果没有这样的鱼它前面的鱼总数就是$c_i$)，求各$c_i$。
>
> $1\le n\le10^5,1\le h_i\le10^9$

**解法1**

(个人解法)

可以尝试倒序逆向思维。并维护一个单调递减的栈(注意存下标而不是存身高值！)，从右往左迭代，当前检测的鱼身高如果比栈顶鱼身高要小，那么入栈。否则，一直弹栈，并更新被弹栈的下标$j$的结果$c_j$为当前下标与它的差值减1。注意要在第一条鱼之前放一条身高无限大的假想鱼作为特判。直到不能弹栈之后，将该鱼入栈。画图模拟易证解法正确。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
int s[mn],ed,n,v,a[mn],r[mn];
signed main()
{
    scanf("%d",&n); a[0]=0x7ffffffa;
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=n;i>=0;--i)
    {
        if(!(!ed||a[s[ed]]>a[i])) while(ed&&a[s[ed]]<=a[i])
            r[s[ed]]=s[ed]-i-1,--ed;
        s[++ed]=i;
    }
    for(int i=1;i<=n;++i) printf("%d\n",r[i]);
    return 0;
}
```

**解法2**

(答案)顺着来走即可。手算模拟一次易知解法正确。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[MAXN], ans[MAXN];

int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = INF;
    stack<ll> st;
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (st.size())
        {
            if (a[st.top()] < a[i])
            {
                st.pop();
            }
            else
            {
                ans[i] = i - st.top() - 1;
                break;
            }
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}
```



### 队列

queue，是线性表

从队尾(rear)插入元素，为入队/进队，从队首(front)删除元素，为离队/出队。先进先出FIFO:first input,first output特点。

假满：当front,rear都指向长度时，不能入队和离队，可以用循环队列来解决这个问题，则队空标志仍为front=rear，队满标志为(rear+1)%LEN == front，并保留一个空单元，避免与队空标志冲突，所以可以存放LEN-1个元素。

##### 定义

```c
typedef struct queue
{
    int data[NQ];
    int front;
    int rear;
} QUEUE;
```

```c
typedef struct queue2
{
    int data;
    struct queue2 *front;
    struct queue2 *rear;
} QUEUE2;
```

或者简单点，直接使用数组。（下面以数组为例）

##### 入队

```c
void enqueue(int x)
{//尾部是虚的
    if(head == (tail + 1)%LEN) return;//队满
    q[tail] = x;
    tail = (tail + 1) % LEN;
}
```

```c++
bool Queue::enqueue(const Item &item)
{
    if(isfull()) return false;
    Node *add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if(front==NULL) front=add;
    else rear->next=add;
    rear=add;
    return true;
}
```

##### 离队

```c
int dequeue()
{
    if(head==tail) exit(1);//队空
    int x=Q[head];
    head = (head + 1) % LEN;
    return x;
}
```

```c++
bool Queue::dequeue(Item &item)
{
    if(front==NULL) return false;
    item = front->item;
    Node *temp = front;
    items--;
    front = front->next;
    delete temp;
    if(items==0) rear=NULL;
    return true;
}
```



##### 队空

```c
return head == tail;
```

##### 队满

```c
return head == (tail + 1)%LEN;
```

##### 举例

#### 单向队列

入队O(1)，出队O(n)

#### 循环队列

入队 出队O(1)

队空 head->=tail

队满 tail->=head

#### 链队列

建议也加上头结点

#### 单调队列

是元素按某种标准单调递增或单调递减的队列。

实现方法：数组(头尾指针)、deque、手写链表。

##### 例题

###### 滑动区间最小值

> 一个含有n项的数列，求出每一项的前m个数到它(不含它)的区间内最小值。若前面无数输出0.输入n,m,数列

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000002
pair<int, int> q[MAXN];
int n,m,v,hd,qt;
signed main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&v);
    printf("0\n");
    q[qt++] = {1,v};
    for(int i=2;i<=n;++i)
    {
        printf("%d\n",q[hd].second);
        scanf("%d",&v);
        while(hd<qt && i>=m+q[hd].first)  hd++;
        while(hd<qt && v<q[qt-1].second) qt--;
        q[qt++] = {i,v};
    }
    return 0;
}
```

### 哈希表

原始哈希 直接寻址法(基数排序？)

O 1的存储和提取



查询 h(value)返回bool，为真在数组，否则不在



除法哈希法

h(k)=k%m m=len(array),m!=2^n



乘法哈希法

#### STL

STL unordered_map

unordered_map<string, int>hash;

hash.insert({string, int});

hash.find(string);

hash.count(string);

hash.erase(string);

#### 例题

##### 集合相似度

> (天梯)定义两个整数集合的相似度为公有元素数/共有元素数。给定n个集合和k个询问，求集合相似度。
>
> ($1\le n\le50,1\le len\le10^4,v\in int,1\le k\le2000$)

这题直接用set处理会超时，可以使用有序下的归并排序思维进行统计。注：这题set比unordered\_set快。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 53
#define mm 10003
ll a[mn][mm],n,k,len[mn],m,v,x,y,i,j,fs;
set<ll> vis[mn];
signed main()
{
    scanf("%d",&n);
    for(ll i=1;i<=n;++i)
    {
        for(scanf("%d",&m);m;--m)
        {
            scanf("%d",&v);
            if(vis[i].find(v)==vis[i].end())
            {
                vis[i].insert(v);
                a[i][len[i]++]=v;
            }
        }
        sort(a[i],a[i]+len[i]);
    }
    for(scanf("%d",&k);k;--k)
    {
        scanf("%d%d",&x,&y);
        i=0,j=0,fs=0;
        while(i<len[x]&&j<len[y])
        {//&&就行，一方超过之后另一个将不可能再重合
            if(a[x][i]==a[y][j]) ++i,++j,++fs;
            else if(a[x][i]>a[y][j]) ++j;//不是++i
            else ++i;
        }
        printf("%.2lf%%\n",100.0*fs/(len[x]+len[y]-fs));
    }
    return 0;
}
```

##### Gitignore

> (icpc45上海)
>
> Your git project (you don't need to be familiar with git to solve this problem) has some files that should be ignored from synchronizing. You need to calculate the minimum number of lines needed for gitignore.
>
>  Formally, your project is a folder. A folder can have files and sub folders. There are no empty folders (i.e. folders without any files or sub folders inside). Initially, the git software will synchronize all the files in your project. However, you can specify some files and folders in the settings (which is called gitignore) to exclude them from synchronizing. For each line in gitignore, you can specify either a file or all the files in a folder. You can **not** ignore the whole project folder (i.e. an empty line in gitignore).
>
>  You are given paths for all the files in the project and whether they should be ignored or shouldn't. Your task is to calculate the minimum number of lines for gitignore.
>
> The input contains several test cases. The first line contains a single positive integer T which is the number of test cases. For each test case, you are first given two non-negative numbers n and m. And then n non-empty lines of file paths that should be **ignored**, and m non-empty lines of file paths that should **not** be ignored.
>
> The paths are strings containing lower-cased English alphabets and slashes ('/') only. Slashes are used to separate folders, sub folders and file name. For exapmle, "a/b/c/d" indicates folder "a" in the project folder, folder "b" in folder "a", folder "c" in "b" and file "d" in folder "c". All the paths are valid, specifically:
>
> \1. The path is non-empty and it always indicates a file (i.e. the path does not end with a slash).
> \2. The path does not start with a slash.
> \3. Folder names and file names are non-empty (i.e. there are no consecutive slashes).
> \4. File paths are always unique (i.e. all the paths in a test case are different).
> \5. In a folder, no sub folders and files share the same names. For example, there won't be two files "a/b/a" and "a/b/a/d" in one test case. However, files "a/b/a" and a/b/b"are allowed.
>
> 1≤n+m≤100 holds and in the whole input there are no more than 1,000 characters in file paths (i.e. the sum of lengths of file path strings in the whole input file is no more than 1,000).
>
> output T lines of non-negative integers, the minimum number of gitignore lines for each test case.

注意文件夹不是不可以同名，是子下面不可以而已，例如a/b/c和d/b/e是合法的

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 1010
#define sc(x) scanf("%lld",&x)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
unordered_map<string,ll> stt;
string fn[mn];
ll _,n,m,nm,ie,r;
signed main()
{
    for(sc(_);_;--_)
    {
        sc(n),sc(m),nm=n+m,r=n;
        stt.clear();
        repe(i,1,nm) cin>>fn[i];
        repe(i,n+1,nm)
        {
            string t=""; ie=fn[i].size();
            rep(j,0,ie)
            {
                t+=fn[i][j];
                if(fn[i][j]=='/') stt[t]=1;
            }
        }
        repe(i,1,n)
        {
            string t=""; ie=fn[i].size();
            rep(j,0,ie)
            {
                t+=fn[i][j];
                if(fn[i][j]=='/')
                {
                    if(stt[t]==0) stt[t]=2;
                    else if(stt[t]==1) continue;
                    else {--r; break;}
                }
            }
        }
        printf("%lld\n",r);
    }
    return 0;
}
```

### ST表

sparse table 稀疏表

作用：RMQ(Range Minimum/Maximum Query)问题，即区间最值问题，以$O(nlogn)$预处理，$O(1)$查询

条件：静态表，即只初始化不修改

使用倍增方法，构建二维数组$a[N][log(N)+1]//或第二维更高$

```c++
a[i][j]意义为区间[i,i+2^j-1]
如a[2][0]为[2,2],a[2][2]为[2,5]
```

倍增可以处理能够可重复贡献的问题，即对于一个二元运算符，对自身使用后返回自身，即xRx=x，比如区间最值问题max，与，或，区间GCD，区间LCM。

#### 实现

以最大值为例

##### 初始化

```c++
log2[2]=1,log2[1]=0;//或不用，下面i=2，开bits库可能会重名
for(int i=3;i<n;++i) log2[i]=log2[i/2]+1;
```

```c++
for(int j=1;j<=ND;j++)//ND为第二维长度
{
    for(int i=1;i+(1<<j)<=n+1;i++)
    {
        a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
    }
}
```

解释：线段右端在$n$之内，即$i+2^j -1\le n\Rightarrow i+2^j\le n+1$

##### 查询

查询[l,r]的最大值

```c++
int k=log2[r-l+1];//预处理
printf("%d\n", max(a[l][k], a[r-(1<<k)+1][k]));
```

解释：右区间左端点$x$是$x+2^k-1=r\Rightarrow x=r-2^k+1$

也可以不预处理log2，那么使用内建位运算函数，以int为例，则：

```c++
int k = 31 - __builtin_clz(r-l+1); //clz统计r-l+1的二进制长度
```



#### 例题

##### 查单词

> 给定n个单词(仅含大小写)和m个询问，求范围$[x,y]$内字典序最大的单词(处理过程不区分大小写，但输出原输入)。$1\le n\le5\times10^4,1\le m\le3\times10^5$

个人解法：ST表(未加离散优化)

```c++
#include <bits/stdc++.h>
using namespace std;
#define lg 17
#define mn 50010
typedef int ll;
ll n,m,lgn[mn],x,y;
char cp[mn][lg][lg],st[mn][lg][lg];
signed main()
{
    scanf("%d%d",&n,&m);
    for(ll i=2;i<=n;++i) lgn[i]=lgn[i/2]+1;
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",cp[i][0]);
        strcpy(st[i][0],cp[i][0]);
        for(ll j=0,je=strlen(cp[i][0]);j<je;++j) st[i][0][j]=tolower(cp[i][0][j]);
    }
    for(ll j=1;j<=16;++j)
    {
        for(ll i=1;i+(1<<j)<=n+1;++i)
        {
            ll r=strcmp(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            if(r>=0||(i+(1<<(j-1))>n)) strcpy(st[i][j],st[i][j-1]),
                strcpy(cp[i][j],cp[i][j-1]);
            else strcpy(st[i][j],st[i+(1<<(j-1))][j-1]),
                strcpy(cp[i][j],cp[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--)
    {
        scanf("%d%d",&x,&y);
        ll k=lgn[y-x+1];
        ll r=strcmp(st[x][k],st[y-(1<<k)+1][k]);
        if(r>=0) printf("%s\n",cp[x][k]);
        else printf("%s\n",cp[y-(1<<k)+1][k]);
    }
    return 0;
}
```



### 堆

即优先级队列，是有序数组。分最大堆/大根堆(最大值在队首)和最小堆/小根堆。

#### 实现

实现(以小根堆、1为下标始为例)：

##### 插入

```c++
void put(int d)
{
 int now,next;
 heap[++heap_size]=d;
 now=heap_size;
 while(now>1)
 {
  next=now>>1;
  if(heap[now]>=heap[next]) return;
  swap(heap[now],heap[next]);
  now=next;           
 }    
}
```

##### 取队首

```c++
return heap[1];
```

##### 队首出队

```c++
int del()
{
 int now,next,res;
 res=heap[1];
 heap[1]=heap[heap_size--];
 now=1;
 while(now*2<=heap_size)
 {
  next=now*2;
  if(next<heap_size&&heap[next+1]<heap[next]) next++;
  if(heap[now]<=heap[next]) return res;
  swap(heap[now],heap[next]);
  now=next;                      
 } 
}
```

#### 例题

##### 黑匣子

> 插入n个输入，在插入k个的时候查询第k小的数。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
ll n, m, th, a[MAXN], q, bf = 1;
priority_queue<ll> da;
priority_queue<ll, vector<ll>, greater<ll>> dy;
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%d", &a[i]);
	repe(i, 1, m)
	{
		scanf("%d", &q);
		repe(j, bf, q)
		{
			da.push(a[j]);
			if (da.size() == i) dy.push(da.top()), da.pop();
		}
		bf = q + 1;
		printf("%d\n", dy.top());
		da.push(dy.top()); dy.pop();
	}
	return 0;
}
```

### 环

*[首尾相连的数组是环]*，可能需要大量的跨首尾工作，为此，可以把环复制一份，开二倍长度。则有a[i]=a[i+n]的互换关系。也可以用(i+k)%n的方法或i%n+1（有意义下标从1开始时）

### 块

分块是一种思维，而利用这种思维可以构造出块状数组这一数据结构。

分块和块状数组。将一个整体划分为若干个小块，整块整体处理，零散块单独处理。将长度为$n$的数组划分为$a$块，每块长度$\lfloor\frac na\rfloor$，区间边缘零散块单独暴力处理

可以证明，当$a=\lfloor\sqrt n\rfloor$时，整块不会太少，零散块不会太多，相对最优，总体时间复杂度是$\Omicron(\sqrt n)$ (证明方法：均值不等式)

对比之下，线段树和树状数组是对数复杂度，所以分块并不会比它们更优。分块数组可以看成是高度为$3$的数，全体是第一层，块是第二层，元素是第三层。

块状数组维护的信息不需要满足结合律，也不需要层层之间传递标记。

预处理：

```c++
int sq = sqrt(n);
for (int i = 1; i <= sq; ++i)
{
    st[i] = n / sq * (i - 1) + 1; // st[i]表示i号块的第一个元素的下标
    ed[i] = n / sq * i; // ed[i]表示i号块的最后一个元素的下标
}
ed[sq] = n;

for (int i = 1; i <= sq; ++i)
    for (int j = st[i]; j <= ed[i]; ++j)
        bel[j] = i; // 表示j号元素归属于i块

for (int i = 1; i <= sq; ++i)
    size[i] = ed[i] - st[i] + 1;//每块的大小
```



#### 例题

##### 线段树1

> 给定数列和两种操作，将区间每一个数加k或求区间和(同线段树题目)$\lim 10^5$

事实上仅仅比线段树解法稍慢，理论上慢了一个常数$\frac{\sqrt n}{\log n}$，试验中慢了约100ms

```c++
#define mn 100010
#define ms 320
ll n, m, cmd, lf, rf, k, bl[ms], br[ms], be[mn], laz[ms], a[mn], ns, bs[ms], bq[ms];
void change()
{
    if (be[lf] == be[rf])//零散块
        repe(i, lf, rf) a[i] += k, bs[be[i]] += k;
    else
    {//零散块两个+整块一堆，记得懒标签laz，否则复杂度无任何优化
        repe(i, lf, br[be[lf]]) a[i] += k, bs[be[i]] += k;
        repe(i, bl[be[rf]], rf) a[i] += k, bs[be[i]] += k;
        rep(i, be[lf] + 1, be[rf]) laz[i] += k;
    }
}
ll query()
{
    re ll s = 0;
    if (be[lf] == be[rf])
        repe(i, lf, rf) s += a[i] + laz[i];
    else
    {//记得加上懒标签
        repe(i, lf, br[be[lf]]) s += a[i] + laz[be[i]];
        repe(i, bl[be[rf]], rf) s += a[i] + laz[be[i]];
        rep(i, be[lf] + 1, be[rf]) s += bs[i] + laz[i] * bq[i];
    }
    return s;//不返回见祖宗
}
signed main()
{
    n = read(), m = read(), ns = sqrt(n);
    repe(i, 1, n) a[i] = read();
    repe(i, 1, ns)
    {
        bl[i] = n / ns * (i - 1) + 1;
        br[i] = n / ns * i;
    }
    br[ns] = n; //最后一块大小有变，其他都是等大小的
    repe(i, 1, ns) repe(j, bl[i], br[i]) be[j] = i, bs[i] += a[j];//每一块存储的信息是bs，是块的和
    repe(i, 1, ns) bq[i] = br[i] - bl[i] + 1;
    while (m--)
    {
        cmd = read(), lf = read(), rf = read();
        if (cmd == 1)
        {
            k = read();
            change();
        }
        else
            printf("%lld\n", query());
    }
    return 0;
}
```





### 例题

##### 数组左移

> (作业)将长为$n$的数组每个元素往左移动$i$位(小于$0$移到数组后边)，要求时间复杂度$\Omicron(n)$，空间复杂度$\Omicron(1)$。

个人解法：gcd分组

将第一个数移动$i$位，$\Omicron(1)$，然后将移动到的新位置数继续移动$i$位……当$\gcd(n,i)=1$时，一定每个移动的位置都是唯一的，移动时不会走进子数组循环。一共移动$n$次，时间复杂度是$\Omicron(n)$。

若$\gcd(n,i)=k$，那么分成$k$组，每一组第一个元素是组序号，每一组都进行如上操作。时间复杂度是$\Omicron(\log n+k\frac nk)=\Omicron(n)$。

代码如下：

```c++
void swap_integer(int &a, int &b) //不消耗任何辅助空间的交换整型变量
{
    a ^= b ^= a ^= b;
}

int gcd(int a, int b) //最大公因数，时间复杂度O(log max(a,b))
{
    return b ? gcd(b, a % b) : a;
}

void RRotate(int *a, int k, int n) //只能确保空间复杂度是O(1)
{                           //这个给定的接口无法获取数组长度……
    int g = gcd(n, k); //将[0,n)区间划分为等长的g组，长为n/g
    //对g组，每组内逐k步置换，换n/g次，时间复杂度是O(g*(n/g))=O(n)
    for (int h = 0; h < g; ++h)
    {
        int t = a[h]; //辅助空间
        //i是当组已交换次数，j是当前操作的移位下标
        for (int i = 0, j = (n + h - k) % n; i < n / g; ++i)
        {
            swap_integer(a[j], t);
            j = (j - k + n) % n; //减法取模公式
        }
    }
}
```



标准解法：将数组分段为$i$长和$n-i$长的两段，两段分别reverse，然后整个数组再reverse，得到答案。代码如下：

```c++
void RRotate(ll *a, ll k, ll n)
{
    reverse(a, a + k);
    reverse(a + k, a + n);
    reverse(a, a + n);
}
```





##### 拉马车

> (蓝桥)每人开局有固定顺序的卡牌，每人依次出最先那张入栈，如果出牌后栈里有两张重复的牌，则一直在栈顶取牌放到自己的牌队尾直到这两张牌都被拿走。当一个玩家出牌后牌空结束游戏，输出另一个玩家的牌。

个人实现版本。这题的难点在于结束判定，事实上如果确实不会判，可以用大次数偏分。(也可以开任一玩家的牌堆set判重)

```c++
#include <bits/stdc++.h>
using namespace std;
vector<char> pt[2],p;
map<char,int> ps;
string tmp;
int n,lp,cnt;
char c,cc;
signed main()
{
	for(int i=0;i<2;++i)
	{
		cin>>tmp;
		n=tmp.size();
		for(int j=0;j<n;++j) pt[i].push_back(tmp[j]);
	}
	for(;true;lp^=1,++cnt)
	{
		c=pt[lp].front();
		p.push_back(c);
		++ps[c];
		pt[lp].erase(pt[lp].begin());
		if(ps[c]>1)
		{
			while(ps[c])
			{
				cc=p.back();
				pt[lp].push_back(cc);
				--ps[cc];
				p.pop_back();
			}
			lp^=1;
		}
		if(!pt[lp].size()) break;
		if(cnt>10000) return printf("-1")&0;//注意结束特判
	}
	lp^=1,n=pt[lp].size();
	for(int i=0;i<n;++i) printf("%c",pt[lp][i]);
	return 0;
}
```



## 树

### 普通树

tree，非线性数据结构，存在一对多关系，一个父节点有零到多个子节点

数的元素叫节点。无任何节点的树是空树。一棵非空树有且仅有一个根。每棵子树也是一棵树。节点分为根节点，分支节点/非终端节点，叶子节点/终端节点。

若兄弟节点按照大小有序排列，称为有序树。

有根节点的树称为有根树。其节点具有父子关系。同深度的其他节点称为兄弟节点。根的深度(depth)为0，即从根到节点的路径长。

有根树某节点的子节点数称为度(degree)。节点到叶节点的最大路径长叫做高(height)。根节点高度最大。树高=节点高+节点深度。

树节点的度是其子树数，数度和 = 节点数 - 1

#### 数据实现

```c++
struct Node {int parent, left, right;};
//分别代表：父节点，最左侧子节点；右侧紧邻的兄弟节点
struct Node T[MAX];
//或
int parent[MAX], left[MAX], right[MAX];
```

parent不存在是根，left不存在是叶。right不存在时最右侧子节点。

#### 深度

```c++
//非递归写法 - 求单个
int getdepth(struct Node u)
{
    int d=0;
    while(T[u].parent != NIL)//NIL也可以就是NULL或-1
    {//区分，这里的Node不是指针是下标，故用-1，否则NULL
        u = T[u].parent;
        d++;
    }
    return 0;
}

//递归写法 - 从根节点开始求所有
void setdepth(int u, int p)//p初始值为0
{
    D[u] = p;
    if(T[u].right != NIL) setdepth(T[u].right,p);
    if(T[u].left != NIL) setdepth(T[u].left,p+1);
}
```

#### 举例

##### 求度数

###### 1

> 已知度为 $4$ 的树，度为 $i(i\ge 1)$ 的节点个数有 $i$ 个，问该树叶子节点有多少个

叶子节点度为 $0$ ，设有 $x$ 个。总节点数 $n=x+1+2+3+4$ 。

树度和 $S$ 满足 $S=n-1=x+1^2+2^2+3^2+4^2$ ，故 $x=21$ 。

#### 遍历

```c++
//表示子节点列表 (仅下一度，不连续直到空节点)
void printchilden(int u)
{
    c = T[u].left;
    while(c!=NIL)
    {
        cout<<c<<" ";
        c = T[c].right;
    }
}
```

##### DFS/BFS

同一优先级时，以从小到大为例重心

树若以某点为根，使得该树最大子树的结点数最小，那么这个点则为该树的重心，一棵树可能有多个重心。

**性质：**

1. 树上所有的点到树的重心的距离之和是最短的，如果有多个重心，那么总距离相等。
2. 插入或删除一个点，树的重心的位置最多移动一个单位。
3. 若添加一条边连接2棵树，那么新树的重心一定在原来两棵树的重心的路径上。

**求法：**

*f*[*u*]表示以u为根的总距离，size[u]表示以u为根的子树的大小（结点数，如果用于求解带权题目，如需要乘权值，即距离*权重=加权距离，下文结点数均指此）。

显然，ans=min(f[i],1<=i<=n)

首先我们任意以一个点为根dfs一遍，求出以该点为根的总距离。方便起见，我们就以1为根。

接下来就是转移，对于每个u能达到的点v，有：

$f[v]=f[u]+size[1]-2*size[v]$

**证明：**

当根从u变为v的时候，v的子树的所有节点原本的距离要到u，现在只要到v*v*了，每个结点的距离都减少1，那么总距离就减少size[v]，同时，以v为根的子树以外的所有节点，原本只要到u就行了，现在要到v，每个节点的路程都增加了1，总路程就增加了size[1]-size[v]，其中size[1]就是我们预处理出来的整棵树的大小，减去size[v]就是除以v为根的子树以外的结点数。

**例题：**

有一棵二叉树，其中，结点中的数字表示结点中居民的人口，现在要求在某个结点上建立一个医院，使所有居民所走的路程之和为最小。

```c++
#include <cstdio>
#define rep(i, m, n) for(register int i = m; i <= n; ++i)
#define INF 2147483647
#define Open(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define Close fclose(stdin);fclose(stdout);
using namespace std;
inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * w;
}
const int MAXN = 10010;
struct Edge{
	int next, to;
}e[MAXN << 1];
int head[MAXN], num, w[MAXN], n, size[MAXN];
long long ans = INF, f[MAXN];
inline void Add(int from, int to){
	e[++num].to = to;
	e[num].next = head[from];
	head[from] = num;
}
void dfs(int u, int fa, int dep){ //预处理f[1]和size
    size[u] = w[u];
	for(int i = head[u]; i; i = e[i].next){
	   if(e[i].to != fa)
	     dfs(e[i].to, u, dep + 1), size[u] += size[e[i].to];
	}
	f[1] += w[u] * dep;
}
void dp(int u, int fa){  //转移
    for(int i = head[u]; i; i = e[i].next)
       if(e[i].to != fa)
         f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to, u);
    ans = min(ans, f[u]); //取最小值
}
int a, b;
int main(){
    //Open("hospital");
    ans *= ans;
    n = read();
    rep(i, 1, n){
       w[i] = read();
       a = read(); b = read();
       if(a) Add(i, a), Add(a, i);
       if(b) Add(i, b), Add(b, i);
    }
    dfs(1, 0, 0);
    dp(1, 0);
    printf("%lld\n", ans);
    //Close;
    return 0;
}
```

###### 深入虎穴

> (天梯)跟定一个树形迷宫，如果输入0代表是一个入口，求最深的入口
>
> ($1\le n\le10^5$)

直接BFS既可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 100002
#define re register
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;++i)
#define rede(i,a,b) for(re ll i=a;i>=b;++i)
ll n,fa[mn],k,mx=1,d[mn],v,mxi=1;
queue<int> q;
signed main()
{
    scanf("%d",&n);
    repe(i,1,n)
    {
        scanf("%d",&k);
        repe(j,1,k)
        {
            scanf("%d",&v);
            fa[v]=i;
        }
        if(!k)
        {
            d[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll h=q.front(),g=h,cn=0,ok=1;
        q.pop();
        while(fa[g])
        {
            if(d[fa[g]]<d[g]+1)
            {
                d[fa[g]]=d[g]+1;
                ++cn;
            }
            else
            {
                ok=false;
                break;
            }
            g=fa[g];
        }
        if(ok&&cn>mx)
        {
            mx=cn;
            mxi=h;
        }

    }
    printf("%d",mxi);
    return 0;
}
```



#### 树的直径

##### 两次DFS

###### 解法一

个人实现版本(头部为标准头01)

```c++
#define big 0x7ffffffa
#define mn 200002
ll n, u, v, cnt, hd[mn], rot, mxd;
bool vis[mn];
struct edge
{
	ll to, nx;
} e[mn << 1];
il void adde(ll& u, ll& v)
{
	e[++cnt] = { v,hd[u] };
	hd[u] = cnt;
}
void dfs(ll x, ll fa, ll d)
{
	vis[x] = true;
	if (d > mxd)
	{
		mxd = d, rot = x;
	}
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!vis[toi]) dfs(toi, x, d + 1);
	}
}
signed main()
{
	n = read();
	rep(i, 1, n) u = read(), v = read(), adde(u, v), adde(v, u);
	dfs(1, 0, 0); mxd = 0; memset(vis, 0, sizeof vis);
	dfs(rot, 0, 0);
	printf("%lld", mxd);
	return 0;
}
```

#### 最近公共祖先

LCA，least common ancestors

##### 暴力法

略。复杂度n^2^。每次找深度比较大的一个点，然后这个点往上跳一次，直到相遇。

##### 倍增法

预处理复杂度nlogn，单次查询时间复杂度logn。

每个点的祖先都是他自己。这是倍增的基础。

链式前向星实现版本

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500002
int n,m,s,x,y,hd[MAXN],tot,d[MAXN],fa[MAXN][22],lg[MAXN];
struct lt
{
    int t,nx;
} e[MAXN<<1];
inline void add(int &x, int &y)
{
    e[++tot].t = y;
    e[tot].nx = hd[x];
    hd[x] = tot;
}
void dfs(int no, int faa)
{
    fa[no][0] = faa;
    d[no] = d[faa]+1;
    for(register int i=1;i<=lg[d[no]];++i)
    {
        fa[no][i] = fa[fa[no][i-1]][i-1];
    }
    for(register int i=hd[no];i;i=e[i].nx)
    {
        if(e[i].t!=faa) dfs(e[i].t,no);
    }
}
inline int lca(int &x, int &y)
{
    if(d[x]<d[y]) swap(x,y);
    while(d[x]>d[y])
    {
        x=fa[x][lg[d[x]-d[y]]-1];
    }
    if(x==y) return x;
    for(register int k=lg[d[x]]-1;k>=0;--k)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(register int i=1;i<=n-1;++i)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(register int i=1; i<=n; ++i)
    {
        lg[i] = lg[i-1] + (i== 1<<lg[i-1]);//这个lg比下取整lg都大1
    }
    dfs(s,0);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}
```

##### RMQ

```c++
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s,tot=0,cnt=0;
int head[1000100],nxt[1000100],to[1000100];
int fir[1000100],ver[1000100],r[1000100];
int f[20][1000100],rec[20][1000100];
int read()
{
    int x=0,flag=0;
    char ch=getchar();
    if(ch=='-') flag=1;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x*=10,x+=ch-'0',ch=getchar();
    if(flag) return -x;
    return x;
}
void addedge(int x,int y)
{
    cnt++;
    nxt[cnt]=head[x];
    head[x]=cnt;
    to[cnt]=y;
}
void dfs(int u,int dep)//dfs处理出三个数组
{
	fir[u]=++tot,ver[tot]=u,r[tot]=dep;
	for(int i=head[u];i!=-1;i=nxt[i])
	{
		int v=to[i];
		if(!fir[v])
		{
			dfs(v,dep+1);
			ver[++tot]=u,r[tot]=dep;
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read(),m=read(),s=read();
	for(int i=1;i<n;i++)
	{
		int x,y;
		x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}
	dfs(s,1);
    //ST表求RMQ，不会ST表的童鞋先去做一下ST表模板。。。
	for(int i=1;i<=tot;i++)
		f[0][i]=r[i],rec[0][i]=ver[i];
	for(int i=1;i<=log(tot)/log(2);i++)
		for(int j=1;j<=tot-(1<<i)+1;j++)
		{
			if(f[i-1][j]<f[i-1][j+(1<<(i-1))])
				f[i][j]=f[i-1][j],rec[i][j]=rec[i-1][j];
			else f[i][j]=f[i-1][j+(1<<(i-1))],rec[i][j]=rec[i-1][j+(1<<(i-1))];
		}
    //rec记录的是区间内深度最小值的编号
	for(int i=1;i<=m;i++)
	{
		int l,r;
		l=read(),r=read();
		l=fir[l],r=fir[r];
		if(l>r) swap(l,r);
		int k=0;
		while((1<<k)<=r-l+1) k++;
		k--;
        if(f[k][l]<f[k][r-(1<<k)+1]) printf("%d\n",rec[k][l]);
        else printf("%d\n",rec[k][r-(1<<k)+1]);//常见的ST表输出
	}
	return 0;
}
```

##### tarjan

预处理时间复杂度n，路径压缩下并查集支持的m次查找复杂度为m<即每次都是1的复杂度。链式前向星实现版本。

```c++
#include<bits/stdc++.h>
using namespace std;
template<typename Type>inline void read(Type &xx)
{
    Type f=1;char ch;xx=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())xx=xx*10+ch-'0';
    xx*=f;
}
struct edge
{
    int to,next;
}e[1000001];//边的储存
struct questions
{
    int to,next,same,num;
    bool flag;
    questions(){flag=false;}
}q[1000001];//询问的储存，flag=false表示还没回答，num表示是第几个询问，same储存与这个询问相同的询问序号。
bool b[500001];
int head[500001],que[500001],father[500001];
int n,m,s,nume=0,numq=0,ans[500001];
void add_edge(int x,int y)
{
    e[++nume].to=y;
    e[nume].next=head[x];
    head[x]=nume;
    e[++nume].to=x;
    e[nume].next=head[y];
    head[y]=nume;
}
void add_que(int x,int y,int k)
{
    q[++numq].to=y;
    q[numq].same=numq+1;
    q[numq].next=que[x];
    q[numq].num=k;
    que[x]=numq;
    q[++numq].to=x;//询问要储存到两个点的链表序列里，删的时候也要一起删
    q[numq].same=numq-1;
    q[numq].next=que[y];
    q[numq].num=k;
    que[y]=numq;
}
int find(int x)//并查集
{
    if(father[x]!=x)father[x]=find(father[x]);
    return father[x];
}
void unionn(int x,int y)//并查集
{
    father[find(y)]=find(x);
}
void LCA(int point,int f)//point是当前搜索节点，f是它的父亲
{
    for(int i=head[point];i!=0;i=e[i].next)//遍历与point相连的所有边
        if(e[i].to!=f&&!b[e[i].to])
        {
            LCA(e[i].to,point);
            unionn(point,e[i].to);//合并
            b[e[i].to]=1;
        }
    for(int i=que[point];i!=0;i=q[i].next)//遍历与point相关的询问
        if(!q[i].flag&&b[q[i].to])//如果另一个点遍历过了并且该询问没有回答过
        {
            ans[q[i].num]=find(q[i].to);//记录下答案
            q[i].flag=1;
            q[q[i].same].flag=1;//把两个点上的询问都去掉
        }
}
int main()
{
    read(n);read(m);read(s);
    for(int i=1,x,y;i<=n-1;i++)
    {
        father[i]=i;
        read(x);read(y);
        add_edge(x,y);
    }
    father[n]=n;
    for(int i=1,x,y;i<=m;i++)
    {
        read(x);read(y);
        add_que(x,y,i);
    }
    LCA(s,0);
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
```

##### 树上k级祖先

> 给定n点有根树，q次询问(根据x,k求x的第k级祖先，得到ans)每次询问的x和k根据给定随机数和给定的计算方式求出。输出$xor_{i=1}^qi\times ans_i$

###### 长链剖分

复杂度$\Omicron(n\log n)-\Omicron(1)$或说$\Omicron(n\log n+q)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 500002
#define ui unsigned int
ll n, g[MAXN], d[MAXN], f[MAXN][20], son[MAXN], dep[MAXN], top[MAXN];
ll q, rt, ans, o, x, k;
vector<ll> e[MAXN], u[MAXN], v[MAXN];
long long res;
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x;
}
void dfs1(ll x)
{
	dep[x] = d[x] = d[f[x][0]] + 1;
	for (auto y : e[x])
	{
		f[y][0] = x;
		for (ll i = 0; f[y][i];++i) f[y][i + 1] = f[f[y][i]][i];
		dfs1(y);
		if (dep[y] > dep[x]) dep[x] = dep[y], son[x] = y;
	}
}
void dfs2(ll x, ll p)
{
	top[x] = p;
	if (x == p)
	{
		o = x;
		repe(i, 0, dep[x] - d[x])
			u[x].push_back(o), o = f[o][0];
		o = x;
		repe(i, 0, dep[x] - d[x])
			v[x].push_back(o), o = son[o];
	}
	if (son[x]) dfs2(son[x], p);
	for (auto y : e[x]) if (y != son[x]) dfs2(y, y);
}
inline ll ask(ll x, ll k)
{
	if (!k) return x;
	x = f[x][g[k]], k -= 1 << g[k];
	k -= d[x] - d[top[x]], x = top[x];
	return k >= 0 ? u[x][k] : v[x][-k];
}
signed main()
{
	scanf("%d%d%d", &n, &q, &s);
	g[0] = -1;
	repe(i, 1, n) scanf("%d", &f[i][0]), e[f[i][0]].push_back(i),
		g[i] = g[i >> 1] + 1;
	rt = e[0][0];
	dfs1(rt);
	dfs2(rt, rt);
	repe(i, 1, q)
	{
		x = (get(s) ^ ans) % n + 1;
		k = (get(s) ^ ans) % d[x];
		res ^= 1LL * i * (ans = ask(x, k));
	}
	printf("%lld", res);
	return 0;
}
```

###### 树剖LCA

$\Omicron(n+q\log n)$

```c++
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0,fh=1;char c=getchar();
	while(c>57 or c<48){if(c=='-')fh=-1;c=getchar();}
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 500005
int n,m,u,v,cnt,fa[MN],siz[MN],w[MN],top[MN],dep[MN],id[MN],ID[MN];
vector<int>edge[MN];
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
			fa[edge[x][i]]=x;
			dep[edge[x][i]]=dep[x]+1;
			dfs1(edge[x][i]);
			siz[x]+=siz[edge[x][i]];
			if(siz[w[x]]<siz[edge[x][i]])w[x]=edge[x][i];
		}
}
void dfs2(int x){
	id[x]=++cnt;
	ID[cnt]=x;
	if(w[x]){top[w[x]]=top[x];dfs2(w[x]);}
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=w[x]){
			top[edge[x][i]]=edge[x][i];
			dfs2(edge[x][i]);
		}
}
int rt;
int jump(int x,int k){
	while(k>=id[x]-id[top[x]]+1&&x!=rt){
		k-=(id[x]-id[top[x]]+1);
		x=fa[top[x]];
	}
	return ID[id[x]-k];
}
#define ui unsigned int
ui S;
#define LL long long
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return S = x; 
}
int main(){
	n=read();m=read();scanf("%u",&S);
	rt=1;
	for(int i=1;i<=n;++i){
		fa[i]=read();
		if(!fa[i])rt=i;
		else edge[fa[i]].push_back(i);
	}
	dep[rt]=1;dfs1(rt);
	top[rt]=rt;dfs2(rt);
	LL ans=0;
	int lstans=0;
	for(int i=1;i<=m;++i){
		int x=(get(S)^lstans)%n+1;
		int k=(get(S)^lstans)%dep[x];
		lstans=jump(x,k);
		ans^=(LL)i*lstans;
	}
	printf("%lld\n",ans);
	return 0;
}
```

###### 二分优化树剖LCA

$\Omicron(n\log n+q\log\log n)$

```c++
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0,fh=1;char c=getchar();
	while(c>57 or c<48){if(c=='-')fh=-1;c=getchar();}
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 500005
int n,m,u,v,cnt,fa[MN],siz[MN],w[MN],top[MN],dep[MN],id[MN],ID[MN];
int FA[MN][19],CNT[MN];
vector<int>edge[MN];
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
			fa[edge[x][i]]=x;
			dep[edge[x][i]]=dep[x]+1;
			dfs1(edge[x][i]);
			siz[x]+=siz[edge[x][i]];
			if(siz[w[x]]<siz[edge[x][i]])w[x]=edge[x][i];
		}
}
int rt;
void dfs2(int x){
	id[x]=++cnt;
	ID[cnt]=x;
	if(top[x]==x){
		int p=top[fa[top[x]]];
		FA[x][0]=x;FA[x][1]=p;
		for(int i=1;i<=CNT[p];++i)FA[x][i+1]=FA[p][i];
		CNT[x]=CNT[p]+1;
	}
	if(w[x]){top[w[x]]=top[x];dfs2(w[x]);}
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=w[x]){
			top[edge[x][i]]=edge[x][i];
			dfs2(edge[x][i]);
		}
}
int jump(int x,int k){
	if(k<id[x]-id[top[x]]+1) return ID[id[x]-k];
	int y=top[x];
	int l=0,r=CNT[y]+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(k<dep[x]-dep[FA[y][mid]]+1)r=mid;
			else l=mid;
	}
	k-=dep[x]-dep[FA[y][l]]+1;
	x=fa[FA[y][l]];
	return ID[id[x]-k];
}
#define ui unsigned int
ui S;
#define LL long long
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return S = x; 
}
int main(){
	n=read();m=read();scanf("%u",&S);
	rt=1;
	for(int i=1;i<=n;++i){
		fa[i]=read();
		if(!fa[i])rt=i;
		else edge[fa[i]].push_back(i);
	}
	dep[rt]=1;dfs1(rt);
	top[rt]=rt;dfs2(rt);
	LL ans=0;
	int lstans=0;
	for(int i=1;i<=m;++i){
		int x=(get(S)^lstans)%n+1;
		int k=(get(S)^lstans)%dep[x];
		lstans=jump(x,k);
		ans^=(LL)i*lstans;
	}
	printf("%lld\n",ans);
	return 0;
}
```

###### 树剖LCA分块

$\Omicron(n\sqrt{\log n}+q\sqrt{\log n})$

```c++
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c=getchar();
	while(c>57 or c<48){c=getchar();}
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 500005
int n,m,u,v,cnt,fa[MN],siz[MN],w[MN],top[MN],dep[MN],id[MN],ID[MN],up[MN];
vector<int>edge[MN];
const int len=3;
void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
		fa[edge[x][i]]=x;
		dep[edge[x][i]]=dep[x]+1;
		dfs1(edge[x][i]);
		siz[x]+=siz[edge[x][i]];
		if(siz[w[x]]<siz[edge[x][i]])w[x]=edge[x][i];
	}
}
void dfs2(int x){
	id[x]=++cnt;
	ID[cnt]=x;
	if(w[x]){top[w[x]]=top[x];dfs2(w[x]);}
	if(x==top[x]){
		int p=x;
		for(int i=1;i<=len;++i){if(top[fa[p]]==1)break;p=top[fa[p]];}
		up[x]=p;
	}
	else up[x]=up[top[x]];
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=w[x]){
			top[edge[x][i]]=edge[x][i];
			dfs2(edge[x][i]);
		}
}
int rt;
int jump(int x,int k){
	while(k>=dep[x]-dep[up[x]]+1){
		k-=(dep[x]-dep[up[x]]+1);
		x=fa[up[x]];
	}
	while(k>=id[x]-id[top[x]]+1){
		k-=(id[x]-id[top[x]]+1);
		x=fa[top[x]];
	}
	return ID[id[x]-k];
}
#define ui unsigned int
ui S;
#define LL long long
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return S = x; 
}
int main(){
	n=read();m=read();scanf("%u",&S);
	rt=1;
	for(int i=1;i<=n;++i){
		fa[i]=read();
		if(!fa[i])rt=i;
		else edge[fa[i]].push_back(i);
	}
	dep[rt]=1;dfs1(rt);
	top[rt]=rt;dfs2(rt);
	LL ans=0;
	int lstans=0;
	for(int i=1;i<=m;++i){
		int x=(get(S)^lstans)%n+1;
		int k=(get(S)^lstans)%dep[x];
		lstans=jump(x,k);
		ans^=(LL)i*lstans;
	}
	printf("%lld\n",ans);
	return 0;
}

```

##### 树上点距离

随便设一个点是根节点，跑LCA。距离每一半都是$深度[x]-深度[lca]$。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
int n,m,s,x,y,hd[MAXN],tot,d[MAXN],fa[MAXN][22],lg[MAXN];
struct lt
{
    int t,nx;
} e[MAXN<<1];
inline int read()
{
    char p = 0; int r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
inline void add(int &x, int &y)
{
    e[++tot].t = y;
    e[tot].nx = hd[x];
    hd[x] = tot;
}
void dfs(int no, int faa)
{
    fa[no][0] = faa;
    d[no] = d[faa]+1;
    for(register int i=1;i<=lg[d[no]];++i)
    {
        fa[no][i] = fa[fa[no][i-1]][i-1];
    }
    for(register int i=hd[no];i;i=e[i].nx)
    {
        if(e[i].t!=faa) dfs(e[i].t,no);
    }
}
inline int lca(int x, int y)
{
    if(d[x]<d[y]) swap(x,y);
    while(d[x]>d[y])
    {
        x=fa[x][lg[d[x]-d[y]]-1];
    }
    if(x==y) return x;
    for(register int k=lg[d[x]]-1;k>=0;--k)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int main()
{
    scanf("%d",&n); s=1;
    for(register int i=1;i<=n-1;++i)
    {
        x=read();y=read();
        add(x,y);
        add(y,x);
    }
    for(register int i=1; i<=n; ++i)
    {
        lg[i] = lg[i-1] + (i== 1<<lg[i-1]);
    }
    dfs(1,0);
    for(scanf("%d",&m);m;m--)
    {
        x=read();y=read();
        printf("%d\n", d[x]+d[y]-(d[lca(x,y)]<<1));
    }
    return 0;
}
```

##### 例题

是树上前缀和的基础。

###### 可莉的蹦蹦炸弹

> (oj)有$n$个一列编号为$1\sim n$的炸弹，当点燃一个炸弹，这个炸弹一定会向左跳到它左边的另一个编号的炸弹上，如此直到最左侧的炸弹；输入$n,m$，输入$n-1$个数$a_2,a_3,\cdots,a_n$代表编号$i$的炸弹跳到$a_i$上，有$m$次询问，$l,r$，表示点燃第$r$个炸弹，问至少多少次爆炸后，编号小于等于$l$的炸弹会炸
>
> $2\le n\le2\times10^5,1\le m\le10^5,1\le a_i<i,1\le l<r\le n$

这题假设使用BFS，时间复杂度是$\Omicron(nm)$会超时。本题假设把小于等于$l$改成等于$l$大概可用LCA(但是没必要)。本题主要是使用了LCA里的祖先倍增思路。

建$1$为根节点的有根树，注意到子节点一定大于父亲节点，所以往上跳时符合单调性。从一个点到另一个点的距离即所求。可以从$r$开始倍增，跳到刚好到$l$之后，用预处理的深度求这次和$r$的距离，以这次倍增的上一步为新的$r$，反复这个过程；也可以倒过来倍增(答案而言，顺着来时间更短)，个人代码如下：

顺倍增代码：

```c++
#define mn 200010
struct edge
{
    ll to,nx;
} e[mn<<1];
struct node
{
    ll i,t;
};
ll n,m,ff,trf;
ll hd[mn],cnt,v,lf,rf,vis[mn],d[mn],fa[mn][22],lg[mn];
il void adde(ll u, ll v)
{
     e[++cnt]={v,hd[u]};
     hd[u]=cnt;
}
void dfs(ll no, ll faa)
{
    fa[no][0]=faa;
    d[no]=d[faa]+1;
    repe(i,1,lg[d[no]])
    {
        fa[no][i] = fa[fa[no][i-1]][i-1];
    }
    for(re ll i=hd[no];i;i=e[i].nx)
    {
        if(e[i].to!=faa) dfs(e[i].to,no);
    }
}
void narrow(ll rf, ll& a1)
{
    re ll dep=0,icf;
    while(1)
    {
        icf=fa[rf][dep];
        if(icf<=lf)
        {
            a1=min(a1,d[trf]-d[icf]);
            if(dep&&fa[rf][dep-1]>lf)
            {
                narrow(fa[rf][dep-1],a1);
            }
            break;
        }
        else
        {
            ++dep;
        }
    }
}
signed main()
{
    n=read();m=read();
    repe(i,2,n)
    {
        v=read();
        adde(i,v);
        adde(v,i);
    }
    repe(i,1,n)
    {
        lg[i]=lg[i-1]+(i==(1<<lg[i-1] ) );
    }
    dfs(1,0);
    repe(i,1,m)
    {
        lf=read();
        rf=read();
        trf=rf;
        re ll a1=d[rf];
        narrow(rf,a1);
        printf("%lld\n",a1);
    }
    return 0;
}
```

逆倍增代码：

```c++
void narrow(ll rf)
{
    re ll dep = lg[d[rf] - 1] - 1, icf = lf + 1;
    rede(j, dep, 0)
    {
        icf = fa[rf][j];
        if (icf <= lf)
        {
            ans = min(ans, d[trf] - d[icf]);
        }
        else
            break;
    }
    if (icf > lf)
        narrow(icf);
}
```

更优思路：事实上不需要预处理深度和对数数组，只需要祖先倍增数组。

如果$fa[x][0]>l$，必然存在唯一非负整数$y$,使得：
$$
fa[x][y+1]\le l,fa[x][y]>l
$$
并且更进一步，如果$fa[fa[x][y]][0]>l$，则存在唯一非负整数$z$，使得：
$$
fa[fa[x][y]][z+1]\le l,fa[fa[x][y]][z]>l
$$
根据预处理祖先数组的递推式$fa[x][y+1]=fa[fa[x][y]][y]$：

假设$z\ge y$，那么很容易发现$fa[x][y+1]<l$，不符合上面第一条式子，于是：
$$
z<y
$$
所以根据上面的结论，可以从最大$2$的幂倒着倍增，可以一直递归，每次碰到$\ge l$就把碰到的$j$深度累加。最后答案加上$1$即可。时间比顺推稍优。

代码如下：

```c++
void dfs(ll no, ll faa)
{
    fa[no][0] = faa;
    repe(i, 1, 20)
    {
        fa[no][i] = fa[fa[no][i - 1]][i - 1];
    }
    for (re ll i = hd[no]; i; i = e[i].nx)
    {
        if (e[i].to != faa)
            dfs(e[i].to, no);
    }
}
signed main()
{
    n = read();
    m = read();
    repe(i, 2, n)
    {
        v = read();
        adde(i, v);
        adde(v, i);
    }
    dfs(1, 0);
    repe(i, 1, m)
    {
        lf = read();
        rf = read();
        re ll a1 = 0;
        rede(j, 20, 0)
        {
            if (fa[rf][j] > lf)
            {
                rf = fa[rf][j];
                a1 += (1 << j);
            }
        }
        printf("%lld\n", a1 + 1);
    }
    return 0;
}
```



###### 多次路径查询

> 题意：每个节点存储H或G，输入n,m代表n个节点m次查询；输入字符串依次代表每个节点存储的值；输入n行有向边(u,v)，输入m次查询u,v,c询问从u走到v(u,v相等则代表一个点，否则代表路径)是否含c，是输出1，否输出0

**连通块做法：**

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define rep(i,a,b) for(int i=a;i<=b;++i)
int fa[MAXN],n,m,u,v;
char c[MAXN],ch;
int finds(int k)
{
    if(k!=fa[k]) return fa[k]=finds(fa[k]);
    return k;
}
void unite(int u, int v)
{
    fa[finds(u)]=finds(v);
}
signed main()
{
    scanf("%d%d%*c",&n,&m);
    rep(i,1,n)
    {
        c[i]=getchar();
        fa[i]=i;
    }
    rep(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        if(c[u]==c[v]) unite(u,v);
    }
    rep(i,1,m)
    {
        scanf("%d%d%*c%c",&u,&v,&ch);
        if(finds(u)==finds(v) && ch!=c[u]) putchar('0');
        else putchar('1');
    }
    return 0;
}
```

**树上前缀和做法：**

由查询公式：

点权路径和:

```c++
sumx+sumy-sumlca-sumfalca; //falca是f[lca][0]
```

边权路径和：

```c++
sumx+sumy-2*sumlca
```

可得如下：

```c++
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
#define N 100005
int n,m,h[N],tot;
struct edge{
	int to,nxt;
}e[N<<1];
void add(int x,int y){
	e[++tot].to=y;e[tot].nxt=h[x];h[x]=tot;
}
char s[N];
int H[N],G[N],f[N][20],t,d[N];
void dfs(int x,int fa){
	d[x]=d[fa]+1;f[x][0]=fa;
	if(s[x]=='H')H[x]=1;
	else G[x]=1;
	H[x]+=H[fa];G[x]+=G[fa];//树上前缀和
	rep(i,1,t)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].nxt)
	  if(e[i].to!=fa)dfs(e[i].to,x);
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=t;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=t;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main(){
	//freopen("milkvisits.in","r",stdin);
	//freopen("milkvisits.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i,1,n-1){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	t=log2(n);
	dfs(1,0);
	//cout<<endl<<endl;
	//rep(i,1,n)printf("%d %d\n",H[i],G[i]);
	//cout<<endl<<endl;
	int x,y;char op[2];
	rep(i,1,m){
		scanf("%d%d%s",&x,&y,op);
		int val,L=lca(x,y);
		if(op[0]=='H')val=H[x]+H[y]-H[L]-H[f[L][0]];
		else val=G[x]+G[y]-G[L]-G[f[L][0]];//前缀和查询
		if(val)putchar('1');
		else putchar('0');
		//cout<<val<<" "<<L<<endl;
	}
	putchar('\n');
	return 0;
}
```

###### 仓鼠找sugar

> 求树上两条路径是否相交

两条路径分别求出两个端点的最近公共祖先，该祖先在另一条路径上，则相交

判定方法为几何相加：
$$
|AB|+|BC|=|AC|
$$
代码如下：

**倍增法**

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
struct edge { ll nx, to; } e[MAXN<<1];
ll n, t, cnt, hd[MAXN], d[MAXN], dp[MAXN][18], lg[MAXN], ui, vi;
bool vis[MAXN];
inline void adde(ll& u, ll& v)
{
	e[++cnt] = { hd[u],v };
	hd[u] = cnt;
}
void build(ll k, ll v)
{
	vis[k] = true, d[k] = v;
	for (ll i = hd[k]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!vis[toi]) dp[toi][0] = k, build(toi, v + 1);
	}
}
void prep(ll k)
{
	vis[k] = false;
	repe(i, 1, lg[d[k]]) dp[k][i] = dp[dp[k][i - 1]][i - 1];
	for (ll i = hd[k]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (vis[toi]) prep(toi);
	}
}
ll lca(ll a, ll b)
{
	if (d[a] < d[b]) swap(a, b);
	while (d[a] > d[b]) a = dp[a][lg[d[a] - d[b]]];
	if (a == b) return a;
	rede(i, lg[d[a]], 0) if (dp[a][i] != dp[b][i])
		a = dp[a][i], b = dp[b][i];
	return dp[a][0];
}
inline ll dis(ll a, ll b)
{
	ll c = lca(a, b);
	return abs(d[c] - d[a]) + abs(d[c] - d[b]);
}
signed main()
{
	scanf("%d%d", &n, &t);
	rep(i, 1, n) scanf("%d%d", &ui, &vi), adde(ui, vi), adde(vi, ui);
	build(1, 0);
	repe(i, 1, n) lg[i] = lg[i - 1] + ((1 << (lg[i - 1] + 1)) == i);
	prep(1);
	for (ll a, b, c, d, x, y; t; --t)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		x = lca(a, b), y = lca(c, d);
		if (dis(a, y) + dis(b, y) == dis(a, b) ||
			dis(c, x) + dis(d, x) == dis(c, d)) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
```

**树链剖分**

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 100000+15 
using namespace std;
vector<int>vec[MAXN];
int n,q,v,u,a,b,c,d;
int deep[MAXN],dad[MAXN],size[MAXN],top[MAXN];
int dfs(int x){
    size[x]=1;
    deep[x]=deep[dad[x]]+1;
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]){
            dad[vec[x][i]]=x;
            dfs(vec[x][i]);
            size[x]+=size[vec[x][i]]; 
        } 
} 
int dfs1(int x){
    int t=0;
    if(!top[x])    top[x]=x;
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]&&size[vec[x][i]]>size[t])
            t=vec[x][i];
    if(t){
        top[t]=top[x];
        dfs1(t);
    }    
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]&&vec[x][i]!=t)
            dfs1(vec[x][i]);
}
int LCA(int x,int y){
    for(;top[x]!=top[y];){
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        x=dad[top[x]];
    }
    if(deep[x]>deep[y])    swap(x,y);
    return x;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1);
    dfs1(1);
    for(int i=1;i<=q;i++){
        cin>>a>>b>>c>>d;
        int S=LCA(a,b);
        int T=LCA(c,d);
        if(deep[S]<deep[T]){
            swap(S,T);
            swap(a,c);
            swap(b,d);
        }    
        if(LCA(S,c)==S||LCA(S,d)==S)    cout<<"Y"<<endl;
        else    cout<<"N"<<endl;
    }
}
```

###### 紧急集合

> 各边边权为1，从树上三个点出发，求一个目的点及其最小路径和

两两求LCA，可以发现必然有一个重复点，并且可以发现不重复点必然是最优解，设深度为d，最小路径和为：
$$
d_a+d_b+d_c-(d_{lca(a)}+d_{lca(b)}+d_{lca(c)})
$$
解法二：目的是三个LCA深度最大的一个，可以得知，最深的是不重复的。

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 500002
ll fa[MAXN][19], lg[MAXN], d[MAXN], t, hd[MAXN], cnt;
ll n, m, ui, vi, ans, t1, t2, t3, a, b, c, ts;
struct edge { ll f, to, nx; } e[MAXN << 1];
inline void adde(ll& u, ll& v)
{
	e[++cnt] = { u,v,hd[u] };
	hd[u] = cnt;
}
inline ll lca(ll x, ll y)
{
	if (d[x] < d[y]) swap(x, y);
	while (d[x] > d[y]) x = fa[x][lg[d[x] - d[y]] - 1];
	if (x == y) return x;
	rede(i, lg[d[x]], 0) if (fa[x][i] != fa[y][i])
		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void dfs(ll x, ll f)
{
	d[x] = d[f] + 1;
	fa[x][0] = f;
	for (ll i = 1; (1 << i) <= d[x]; ++i)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (toi != f) dfs(toi, x);
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d%d", &ui, &vi), adde(ui, vi), adde(vi, ui);
	dfs(1, 0);
	repe(i, 1, n) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	repe(i, 1, m)
	{
		scanf("%d%d%d", &a, &b, &c);
		t1 = lca(a, b), t2 = lca(a, c), t3 = lca(b, c);
		if (t1 == t2) ts = t3;
		else if (t1 == t3) ts = t2;
		else ts = t1;
		printf("%d %d\n", ts, d[a] + d[b] + d[c] - d[t1] - d[t2] - d[t3]);
	}
	return 0;
}
```

###### 货车运输

> n点m边无向无环图，各边有载重限制，现有q次询问，求(u,v)间的最小边。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
#define BIG 0x7fffff
#define L 17
struct edge { ll to, nx, w; } e[100002];
struct seg { ll x, y, d; } s[50002];
ll cnt, n, m, hd[MAXN], dep[MAXN], f[MAXN], fa[MAXN][L + 2], w[MAXN][L + 2], q;//数组第二维长度跟循环的L不一样
bool vis[MAXN];
inline bool cmp(const seg& x, const seg& y) { return x.d > y.d; }
inline ll finds(ll x)
{
	while (f[x] != x) x = f[x] = f[f[x]];
	return x;
}
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,hd[u],w };
	hd[u] = cnt;
}
inline void kruskal()
{
	sort(s + 1, s + 1 + m, cmp);
	repe(i, 1, n) f[i] = i;
	repe(i, 1, m)
	{
		ll x = s[i].x, y = s[i].y, fx = finds(x), fy = finds(y);
		if (fx != fy)
		{
			f[fx] = fy;
			adde(x, y, s[i].d);
			adde(y, x, s[i].d);
		}
	}
}
void dfs(ll x)
{
	vis[x] = true;
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll y = e[i].to;
		if (vis[y]) continue;
		dep[y] = dep[x] + 1;
		fa[y][0] = x;
		w[y][0] = e[i].w;
		dfs(y);
	}
}
inline ll lca(ll x, ll y)
{
	if (finds(x) != finds(y)) return -1;
	ll ans = BIG;
	if (dep[x] > dep[y]) swap(x, y);
	rede(i, L, 0) if (dep[fa[y][i]] >= dep[x])
	{
		if (fa[x][i] != fa[y][i])
		{
			ans = min(ans, w[y][i]);
			y = fa[y][i];
		}
	}
	if (x == y) return ans;
	rede(i, L, 0) if (fa[x][i] != fa[y][i])
	{
		ans = min(ans, min(w[x][i], w[y][i]));
		x = fa[x][i], y = fa[y][i];
	}
	return min(ans, min(w[x][0], w[y][0]));
}
signed main()
{
	ll ui, vi, wi;
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		scanf("%d%d%d", &ui, &vi, &wi);
		s[i] = { ui,vi,wi };
	}
	kruskal();
	repe(i, 1, n) if (!vis[i])
	{
		dep[i] = 1;
		dfs(i);
		fa[i][0] = i;
		w[i][0] = BIG;
	}
	repe(i, 1, L) repe(j, 1, n)
	{
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
		w[j][i] = min(w[j][i - 1], w[fa[j][i - 1]][i - 1]);//别写成j i
	}
	for (scanf("%d", &q); q; --q)
	{
		scanf("%d%d", &ui, &vi);
		printf("%d\n", lca(ui, vi));
	}
	return 0;
}
```

#### 树链剖分

将一棵有根树切分成若干条链。每个节点轻重与否取决于以其为根的子树节点数的大小。

定义 **重子节点** 表示其(直接)子节点中子树最大的子结点。如果有多个子树最大的子结点，取其一。如果没有子节点，就无重子节点。定义 **轻子节点** 表示剩余的所有子结点。从这个结点到重子节点的边为 **重边**。到其他轻子节点的边为 **轻边**。若干条首尾衔接的重边构成 **重链**。把落单的结点也当作重链，那么整棵树就被剖分成若干条重链。

树剖的实现分两个 DFS 的过程。第一个 DFS 记录每个结点的父节点（father）、深度（deep）、子树大小（size）、重子节点（hson）。第二个 DFS 记录所在链的链顶（top，应初始化为结点本身）、重边优先遍历时的 DFS 序（dfn）、DFS 序对应的节点编号（rank）。

性质：

1. DFS序新编号的重建树，保证子树`x`的节点范围是`[x,x+siz[x]-1]`。因此，对于重建树，可以使用线段树等结构维护节点值。
2. 任意一条路径可以表示为不超过$\Omicron(\log n)$条连续重链(或部分重链)。

因此初始化的时间复杂度是$\Omicron(n)$，使用线段树维护时，单路径查询的时间复杂度是$\Omicron(\log^2n)$，单子树查询的时间复杂度是$\Omicron(\log n)$。



##### 例题

###### 轻重链剖分

> 给定n点树，1 x y z将x到y的最短路所有节点加z，2 x y输出x到y最短路所有节点和，3 x z将x为根节点的子树内所有节点值加z，4 x查询x为根节点的子树内所有节点值和。根节点为r。结果对mod取模。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 200002
ll n, m, r, mod, en, hd[mn], w[mn], wt[mn], a[mn << 2], laz[mn << 2];
ll son[mn], id[mn], fa[mn], cnt, dep[mn], siz[mn], top[mn], res, ui, vi;
struct edge { ll to, nx; } e[mn];
il void adde(ll& u, ll& v)
{
	e[++en] = { v,hd[u] }; hd[u] = en;
}
#define mkcf ll cf=(lf+rf)>>1
#define lson rt<<1,lf,cf
#define rson rt<<1|1,cf+1,rf
#define len (rf-lf+1)
il void pushdown(ll rt, ll ln)
{
	laz[rt << 1] += laz[rt];
	laz[rt << 1 | 1] += laz[rt];
	a[rt << 1] += laz[rt] * (ln - (ln >> 1));
	a[rt << 1 | 1] += laz[rt] * (ln >> 1);
	a[rt << 1] %= mod;
	a[rt << 1 | 1] %= mod;
	laz[rt] = 0;
}
il void build(ll rt, ll lf, ll rf)
{
	if (lf == rf)
	{
		a[rt] = wt[lf];
		if (a[rt] > mod) a[rt] %= mod;
		return;
	}
	mkcf; build(lson); build(rson);
	a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
}
il void query(ll rt, ll lf, ll rf, ll llf, ll rrf)
{
	if (llf <= lf && rf <= rrf)
	{
		(res += a[rt]) %= mod;
		return;
	}
	else
	{
		if (laz[rt]) pushdown(rt, len);
		mkcf;
		if (llf <= cf) query(lson, llf, rrf);
		if (rrf > cf) query(rson, llf, rrf);
	}
}
il void upd(ll rt, ll lf, ll rf, ll llf, ll rrf, ll k)
{
	if (llf <= lf && rf <= rrf) laz[rt] += k, a[rt] += k * len;
	else
	{
		if (laz[rt]) pushdown(rt, len);
		mkcf;
		if (llf <= cf) upd(lson, llf, rrf, k);
		if (rrf > cf) upd(rson, llf, rrf, k);
		a[rt] = (a[rt << 1] + a[rt << 1 | 1]) % mod;
	}
}
il ll rquery(ll x, ll y)
{
	ll ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res = 0;
		query(1, 1, n, id[top[x]], id[x]);
		(ans += res) %= mod;
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	res = 0;
	query(1, 1, n, id[x], id[y]);
	(ans += res) %= mod;
	return ans;
}
il void rupd(ll x, ll y, ll k)
{
	k %= mod;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		upd(1, 1, n, id[top[x]], id[x], k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	upd(1, 1, n, id[x], id[y], k);
}
il ll rqson(ll x)
{
	res = 0;
	query(1, 1, n, id[x], id[x] + siz[x] - 1);
	return res;
}
il void rupds(ll x, ll k)
{
	upd(1, 1, n, id[x], id[x] + siz[x] - 1, k);
}
il void dfs1(ll x, ll f, ll deep)
{
	dep[x] = deep, fa[x] = f, siz[x] = 1;
	ll mxson = -1;
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll y = e[i].to;
		if (y == f) continue;
		dfs1(y, x, deep + 1);
		siz[x] += siz[y];
		if (siz[y] > mxson) son[x] = y, mxson = siz[y];
	}
}
il void dfs2(ll x, ll topf)
{
	id[x] = ++cnt, wt[cnt] = w[x], top[x] = topf;
	if (!son[x]) return;
	dfs2(son[x], topf);
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll y = e[i].to;
		if (y == fa[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}

signed main()
{
	scanf("%d%d%d%d", &n, &m, &r, &mod);
	repe(i, 1, n) scanf("%d", w + i);
	rep(i, 1, n)
	{
		scanf("%d%d", &ui, &vi);
		adde(ui, vi); adde(vi, ui);
	}
	dfs1(r, 0, 1), dfs2(r, r), build(1, 1, n);
	for (ll k, x, y, z; m; --m)
	{
		scanf("%d%d", &k, &x);
		if (k == 1) scanf("%d%d", &y, &z), rupd(x, y, z);
		else if (k == 2)
			scanf("%d", &y), printf("%d\n", rquery(x, y));
		else if (k == 3) scanf("%d", &y), rupds(x, y);
		else printf("%d\n", rqson(x));
	}
	return 0;
}
```

#### Prufer序列

是一种支持将无根树压缩为长度为$n-2$，每个数范围在$[1,n]$的序列。

从树构造Prufer序列，每次选择编号最小的叶节点并删除，然后序列里记录它连接的节点。

从Prufer序列构造树，从左往右遍历，当前点为 $p_i$，我们找出编号最小的叶子节点 x，并将 x与$p_i$相连，将$p_i$的度减去 1。如此操作 n-2 次就行了。

1. 一个数在 Prufer 序列里的出现次数是其度数减一，因为每个点都有成为叶子节点的时候，这时我们直接把它删去，使其度数减 1 不会记录到 Prufer 序列中，而其余时刻将其度数减 11 都会使其在 Prufer 序列中的出现次数多 1，故 u在 Prufer 序列里的出现次数为 $deg_u-1$。
2. 最后剩余的两个点中一定有一个点编号为 n——因为无论如何树中一定会存在至少两个叶子节点，而 n永远不会成为编号较小的那一个，故 n永远不会被删去。
3. 由 n个点组成的无根树个数为 $n^{n-2}$，这同时也说明了由 n个点组成的无根树与长度为 n-2，值域为$ [1,n]$ 的序列构成了双射关系

##### 互转实现

时间复杂度$\Omicron(n)$，使用指针代替堆找最小值。

> 设f是父亲序列，p是Prufer序列，互相转化并输出转化后序列的$xor_{o=1}^{len}i\times a_i$。

代码如下：(m=1是父亲序列转Prufer序列，m=2相反)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5000002
ll n, m, f[MAXN], p[MAXN], d[MAXN];
long long ans;
signed main()
{
	scanf("%d%d", &n, &m);
	if (m == 1)
	{
		rep(i, 1, n) scanf("%d", f + i), ++d[f[i]];
		for (ll i = 1, j = 1; i <= n - 1; ++i, ++j)
		{
			while (d[j]) ++j;
			p[i] = f[j];
			while (i <= n - 2 && !--d[p[i]] && p[i] < j)
				p[i + 1] = f[p[i]], ++i;
		}
		repe(i, 1, n - 2) ans ^= 1LL * i * p[i];
	}
	else
	{
		repe(i, 1, n - 2) scanf("%d", p + i), ++d[p[i]];
		p[n - 1] = n;
		for (ll i = 1, j = 1; i < n; ++i, ++j)
		{
			while (d[j]) ++j;
			f[j] = p[i];
			while (i < n && !--d[p[i]] && p[i] < j)
				f[p[i]] = p[i + 1], ++i;
		}
		rep(i, 1, n) ans ^= 1LL * i * f[i];
	}
	printf("%lld", ans);
	return 0;
}
```

#### 例题

##### 罗莎莉亚的伐木工作

> (oj)给定可能含重边的树，点和边都有编号。可以将一个点的两个边取走，求最多可以取走多少边，并输出一个方案。
>
> $2\le n\le2\times10^5,n-1\le m\le2\times10^5$

结论：对$m$边连通图，可以匹配$\lfloor\dfrac n2\rfloor$组边，匹配方法：以一个点为根DFS。对于DFS中的子树，对于每条边，其连接的子树如果有一条边无法匹配，这条边与之匹配；否则，若空闲边为空，这条边加入空闲列表，若空闲有边，这条边与之匹配。最后如果这个子树还有空闲边，返回还有一条边无法匹配。注意DFS要以点为基础且只能走一次。

```c++
#define mn 200010
vector<pair<ll, ll>> g[mn]; //点，边
vector<pair<ll, ll>> ans;
ll n, m, u, v, vis[mn];
ll dfs(ll u)
{
    vis[u] = 1; //0 unvis; 1 visiting; 2 done
    ll e0 = 0;
    for (ll i = 0, ie = g[u].size(); i < ie; ++i)
    {
        v = g[u][i].first;
        ll e1 = g[u][i].second;
        if (vis[v] == 1) //不能走回来
        {
            continue;
        }
        if (vis[v] == 0)
        {
            ll e2 = dfs(v); //以v为顶点的子树都匹配后，剩下的边
            if (e2 != 0)
            {
                ans.push_back({e1, e2});
                e1 = 0; //这条边满足了使命
            }
        }
        if (e1 != 0) //若这条边不满足使命就入栈(栈长2时自动匹配并清空栈)
        {
            if (e0 != 0)
            {
                ans.push_back({e0, e1});
                e0 = 0;
            }
            else
            {
                e0 = e1;
            }
        }
    }
    vis[u] = 2; //该点的子树的边都完成了匹配
    return e0; //v为顶点的子图(子树)匹配完后还剩下的边
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(u), sc(v);
        g[u].push_back({v, i}), g[v].push_back({u, i});
    }
    dfs(1);
    printf("%lld\n", ans.size());
    for (ll i = 0, ie = ans.size(); i < ie; ++i)
    {
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    }
    return 0;
}
```



### 二叉树

binary tree

特点为：

1. 每个节点最多两个子树
2. 左子树和右子树有序
3. 任何子树都区分左或右 //??
4. 有五种基本形态：
   1. 空树
   2. 只有一个根节点
   3. 根节点只有左子树
   4. 根节点只有右子树
   5. 根节点有左右子树

满二叉树：所有分支节点都存在左子树和右子树，所有叶子节点都在同一层

完全二叉树：有n的节点的二叉树有序编号，i节点与同样深度的满二叉树中i节点在二叉树位置完全相同，即除了最后一层，其他每一层节点数都满，不满的缺少的节点也都在右边的树叫做完全二叉树。完全二叉树节点数为n，则树高为log(n,2)。

满二叉树一定是完全二叉树，反之不然。

搜索二叉树：每棵子树头结点值比各左子树所有值都大，比右小。

遍历方法：(以三层满二叉树1,23,4567为例)

1. 先序遍历 1245367(假定优先左分支)
2. 中序遍历 4251637
3. 后序遍历 4526731
4. 层序遍历 1234567

有 $n$ 个节点的二叉树(双指针)有 $n+1$ 个空指针： 有 $n-1$ 条边，一条边占用一个指针，所以为 $2n-(n-1)=n+1$ 

相似地对 $k$ 叉树有 $kn-(n-1)$

#### 举例

###### 1

> 有 $100$ 个节点的完全二叉树的叶子结点数为?

最后一个节点是叶子节点，其父亲是最后一个非叶子节点，为 $\lfloor\dfrac{100}2\rfloor=50$ ，所以叶子结点数 $100-50=50$ 。

#### 定义

```c
//如果是完全二叉树，直接使用一个数组，根节点为0，某节点为i，其左右节点分别为2i-1,2i+1
```

```c
typedef struct bitnode
{
    int data;
    struct bitnode *lc;
    struct bitnode *rc;
} BT;
BT *root = NULL;
```

```c++
//非链表结构：
struct Node(int parent, left, right;);
```

#### 转化

```c
BT *crtree(int *a, int n)
{//int数组转完全二叉树
    BT *pn[n];
    for(int i=0;i<n;i++)
    {
        pn[i] = (BT *)malloc(sizeof(BT));
        if(pn[i] == NULL) {printf("Failed to allocate!\n"); exit(1);}
        pn[i]->lc = NULL;
        pn[i]->rc = NULL;
        pn[i]->data = a[i];
    }
    for(int i=0;i<n/2;i++)
    {
        pn[i]->lc = pn[2*(i+1)-1];
        pn[i]->rc = pn[2*(i+1)];
    }
    return pn[0];
}
```

#### 高度

```c
//以非链表结构为例
int setheight(int u)
{
    int h1 = 0, h2 = 0;
    if(T[u].left!=NIL) h1=setheight(T[u].left)+1;
    if(T[u].right!=NIL) h2=setheight(T[u].right)+1;
    return H[u] = (h1>h2?h1:h2);
}
```

#### 先序遍历

```c
int pot(BT *root, void(*visit)(int))
{//pre order traverse
    if(root == NULL) return 1;
    (*visit)(root->data);
    if(pot(root->lc, visit))
    {
        if(pot(root->rc, visit))
        {
            return 1;
        }
    }
    return 0;
}
//visit用法举例
void visitprint(int n)
{
    printf("%-3d", n);
}
pot(root, visitprint);
```

#### 中序遍历

```c
int mot(BT *root, void(*visit)(int))
{//mid order traverse
    if(root == NULL) return 1;
    if(mot(root->lc, visit))
    {
        (*visit)(root->data);
        if(mot(root->rc, visit))
        {
            return 1;
        }
    }
    return 0;
}
```

#### 后序遍历

```c
int ppot(BT *root, void(*visit)(int))
{//post order traverse
    if(root == NULL) return 1;
    if(ppot(root->lc, visit))
    {
        if(ppot(root->rc, visit))
        {
            (*visit)(root->data);
            return 1;
        }
    }
    return 0;
}
```

#### 层序遍历

如果是线性存的，直接遍历既可。如果是动态存的，BFS既可。

##### 例题

###### 完全二叉树的层序遍历

> (天梯)一个二叉树，如果每一个层的结点数都达到最大值，则这个二叉树就是**完美二叉树**。对于深度为 *D* 的，有 *N* 个结点的二叉树，若其结点对应于相同深度完美二叉树的层序遍历的前 *N* 个结点，这样的树就是**完全二叉树**。给定一棵完全二叉树的后序遍历，请你给出这棵树的层序遍历结果。输入在第一行中给出正整数 *N*（≤30），即树中结点个数。第二行给出后序遍历序列，为 *N* 个不超过 100 的正整数。同一行中所有数字都以空格分隔。在一行中输出该树的层序遍历序列。所有数字都以 1 个空格分隔，行首尾不得有多余空格。

个人解法：思路见代码

```c++
ll lay[mn],a[mn],v,ni=1,nf=2,n,vis[mn];
void goDown()
{
    nf=ni<<1; //忘记暴死
    while(nf<=n&&!vis[nf])
    {
        ni=nf;
        nf<<=1;
    }
}
signed main()
{
    lay[1]=1;
    repe(i,2,100) lay[i]=lay[i/2]+1;
    scanf("%d",&n);
    repe(h,1,n)
    {
        scanf("%d",&v);
        goDown();
        vis[ni]=true;
        a[ni]=v;
        if((ni&1)==0&&!vis[ni+1]&&ni<n) ++ni; //条件一个都不能少，第一个记得加括号
        else ni>>=1;
    }
    printf("%d",a[1]);
    repe(i,2,n) printf(" %d",a[i]);
    return 0;
}
```

标准解法：后序遍历的递归

```c++
int pos = 1;
void Ctree(int x) {
	if( x>n ) {
		return ;
	}
	Ctree(2*x);
	Ctree(2*x+1);
	t[x] = a[pos++];//a是输入数组,t是层序数组
}
```



#### 例题

##### 二求一

```c
int main()
{
    int a[] = {1,2,3,4,5,6,7}, n=7;
    BT *root = NULL;
    root = crtree(a, n);
    printf("%\n", root->data);
    pot(root, visitprint); printf("\n");
    mot(root, visitprint); printf("\n");
    ppot(root, visitprint); printf("\n");
    return 0;
}
```

###### 先中求后

```c++
//输入先序遍历和中序遍历，返回后序遍历
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n,pos;
vector <int> pre,in,post;
void rec(int l, int r)
{
    if(l >= r || pos >= n) return;
    cout<<pos<<endl;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m+l,r);
    post.push_back(root);
}

void solve()
{
    pos = 0;
    //cout<<pre[pos]<<endl;
    rec(0, n);//pre.size());
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<post[i];
    }
    cout<<endl;
}
int main()
{
    int k;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>k;
        pre.push_back(k);
    }
    for(int i=0; i<n; i++)
    {
        cin>>k;
        in.push_back(k);
    }
    solve();
    return 0;
}
```

###### 中后求先

```c++
//输入中序和后续，返回先序
#include <bits/stdc++.h>
using namespace std;
void f(string m, string p)
{
    if(!m.size()) return;
    char c = p[p.size()-1];
    int cp = m.find(c);
    cout<<c;
    f(m.substr(0,cp), p.substr(0,cp));
    f(m.substr(cp+1), p.substr(cp, m.size()-1-cp));
}
int main()
{
    string in, post;
    cin>>in>>post;
    f(in,post);
    return 0;
}
```

###### 中后求层

> (天梯 树的遍历)给定节点数，后序和中序遍历，键值为互不相等的正整数，求层序遍历。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 32
#define mm 100002
typedef long long ll;
ll af[mn],cf[mn],n,r[mm],mri;
void gene(ll lf, ll rf, ll vi, ll id)
{
    r[id]=af[vi];
    mri=max(mri,id);
    if(lf==rf) return;
    ll i;
    for(i=lf;i<=rf;++i) if(cf[i]==af[vi]) break;
    if(i-1>=lf) gene(lf,i-1,vi-rf+i-1,id<<1);
    if(i+1<=rf) gene(i+1,rf,vi-1,id<<1|1);
}
signed main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i) scanf("%lld",af+i);
    for(ll i=1;i<=n;++i) scanf("%lld",cf+i);
    gene(1,n,n,1);
    printf("%lld", r[1]);
    for(ll i=2;i<=mri;++i) if(r[i]) printf(" %lld",r[i]);
    return 0;
}
```

动态版本(更稳定)：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 33
typedef int ll;
ll n,af[mn],cf[mn],cn=1;
struct tree
{
    ll v=0;
    tree* lf=nullptr, *rf=nullptr;
};
tree* r, *te;
void build(ll lf, ll rf, ll vi, tree*& h)
{
    h=new tree;
    h->v=af[vi];
    if(lf==rf) return;
    ll i;
    for(i=lf;i<=rf;++i) if(cf[i]==af[vi]) break;
    if(i-1>=lf) build(lf,i-1,vi-(rf+1-i),h->lf);
    if(i+1<=rf) build(i+1,rf,vi-1,h->rf);
}
queue<tree*> q;
void prt(ll v)
{
    if(cn==1) cn=0,printf("%d",v);
    else printf(" %d",v);
}
signed main()
{
    scanf("%d",&n);
    for(ll i=1;i<=n;++i) scanf("%d",af+i);
    for(ll i=1;i<=n;++i) scanf("%d",cf+i);
    build(1,n,n,r);
    q.push(r);
    while(!q.empty())
    {
        te=q.front();
        q.pop();
        prt(te->v);
        if(te->lf) q.push(te->lf);
        if(te->rf) q.push(te->rf);
    }
    return 0;
}
```

###### 中后求层

> (天梯)给定中序遍历和前序遍历，求镜面翻转后的层序遍历。键值互不相等，节点数$n$满足$1\le n\le30$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 35
ll cf[mn],bf[mn],n,cnt;
struct tree
{
    ll v;
    tree* lc, *rc;
    tree(){lc=rc=nullptr;}
};
queue<tree*> q;
tree* cre(ll bl, ll br, ll cl, ll cr)
{
    if(cl>cr) return nullptr;
    tree* rot=new tree;
    rot->v=bf[bl];
    ll k=1;
    while(cf[k]!=bf[bl]) ++k;
    rot->rc=cre(bl+1,bl+k-cl,cl,k-1);
    rot->lc=cre(bl+k-cl+1,br,k+1,cr);
    return rot;
}
signed main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i) scanf("%lld",cf+i);
    for(ll i=1;i<=n;++i) scanf("%lld",bf+i);
    tree* fa=cre(1,n,1,n);
    q.push(fa);
    while(!q.empty())
    {
        fa=q.front();
        q.pop();
        printf("%lld",fa->v);
        if(++cnt<n) putchar(' ');
        if(fa->lc) q.push(fa->lc);
        if(fa->rc) q.push(fa->rc);
    }
    return 0;
}
```

微调自中后求层动态版的一个版本：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 33
typedef int ll;
ll n,af[mn],cf[mn],cn=1;
struct tree
{
    ll v=0;
    tree* lf=nullptr, *rf=nullptr;
};
tree* r, *te;
void build(ll lf, ll rf, ll vi, tree*& h)
{
    h=new tree;
    h->v=af[vi];
    if(lf==rf) return;
    ll i;
    for(i=lf;i<=rf;++i) if(cf[i]==af[vi]) break;
    if(i-1>=lf) build(lf,i-1,vi+1,h->rf);
    if(i+1<=rf) build(i+1,rf,vi+i-lf+1,h->lf);
}
queue<tree*> q;
void prt(ll v)
{
    if(cn==1) cn=0,printf("%d",v);
    else printf(" %d",v);
}
signed main()
{
    scanf("%d",&n);
    for(ll i=1;i<=n;++i) scanf("%d",cf+i);
    for(ll i=1;i<=n;++i) scanf("%d",af+i);
    build(1,n,1,r);
    q.push(r);
    while(!q.empty())
    {
        te=q.front();
        q.pop();
        prt(te->v);
        if(te->lf) q.push(te->lf);
        if(te->rf) q.push(te->rf);
    }
    return 0;
}
```

##### 中序情况数

输入先序和后序遍历，求中序情况数。

问题转化为找只有一个子节点的根节点，这种情况必然有两个分支，然后乘法原理即可。

###### 朴素

```c++
#include <bits/stdc++.h>
using namespace std;
#define STRL 252
#define rep(i,a,b) for(int i=a;i<b;++i)
int p, xs, ys;
char x[STRL], y[STRL];
signed main()
{
	scanf("%s%s", x, y);
	xs = strlen(x); ys = strlen(y);
	rep(i, 0, xs) rep(j, 1, ys)
		if (x[i] == y[j] && x[i + 1] == y[j - 1]) ++p;
	printf("%lld", 1LL << p);
	return 0;
}
```

###### 离散化

```c++
#include <bits/stdc++.h>
#define mod 1000000007
#define mn 100002
typedef long long ll;
ll n,a[mn],b[mn],c[mn],r=1;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
signed main()
{
    scanf("%lld",&n);
    repe(i,1,n) scanf("%lld",a+i);
    repe(i,1,n) scanf("%lld",b+i),c[b[i]]=i;
    repe(i,1,n)
    {
        ll k=c[a[i]];
        if(i!=n && a[i+1]==b[k-1]) (r<<=1)%=mod;
    }
    return printf("%lld",r),0;
}
```

##### 其他

###### 这是二叉搜索树吗

> (天梯)定义二叉树的镜像为所有左右子树对换位置后得到的树。给出n和长为n的整数序列，判断是否为二叉树或其镜像的先序遍历，如果是，输出该二叉树的后序遍历。($1\le n\le10^3$)

注意题意中的输出，如果输入的是镜像，输出的也是镜像。关键点在于能否建树成功的判定和建树的逻辑代码。判定建树失败的条件是子树的右边范围未能达到父树的范围。由于树的层数较高，不能使用2n左右型静态建树，由于建立一般静态树过于复杂，所以采用动态数据结构更为方便。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1005];
struct tree
{
    ll v;
    tree* lc,* rc;
};
bool build(ll lf, ll rf, tree*& root, ll ay)
{
    if(lf>rf) return true;
    ll pos=lf+1,cpa=a[lf];
    while(pos<=rf&&((ay==0&&a[pos]<cpa)||(ay==1&&a[pos]>=cpa))) ++pos;
    ll cf=pos;
    while(pos<=rf&&((ay==1&&a[pos]<cpa)||(ay==0&&a[pos]>=cpa))) ++pos;
    if(pos<=rf) return false;
    root=new tree;
    root->v=cpa;
    root->lc=root->rc=nullptr;
    return build(lf+1,cf-1,root->lc,ay)&&build(cf,rf,root->rc,ay);
}
void post(tree* t, ll cnt)
{
    if(t==nullptr) return;
    post(t->lc,cnt+1);
    post(t->rc,cnt+1);
    if(cnt) printf("%lld ",t->v);
    else printf("%lld",t->v);
}
signed main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;++i) scanf("%lld",a+i);
    tree* t1=nullptr, *t2=nullptr;
    if(build(0,n-1,t1,0))
    {
        printf("YES\n");
        post(t1,0);
    }
    else if(build(0,n-1,t2,1))
    {
        printf("YES\n");
        post(t2,0);
    }
    else printf("NO\n");
    return 0;
}
```

### 特殊二叉树

#### 搜索二叉树

> 事实上很多时候用vector/multiset + lower&upper_bound可以替代

BST（Binary Search Tree），二叉搜索树/二叉排序树。

搜索二叉树左子树的节点键值小于或等于其父节点键值，右大于或等于。

在二叉搜索树执行中序遍历，将获得升序排列的键值序列。

```c++
//实现插入、查找、查找下一个、查找下一个最小、删除
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;//注意这个NIL这样就行了
void inserti(int k)
{
    Node *y=NIL;
    Node *x=root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x!=NIL)
    {
        y=x;
        if(z->key<x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if(y == NIL) root = z;
    else
    {
        if(z->key < y->key) y->left = z;
        else y->right = z;
    }
}

void inorder(Node *u)//先序
{
    if(u==NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u)//中序
{
    if(u==NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

Node *findi(Node *u, int k)
{
    while(u != NIL && k != u->key)
    {
        if(k<u->key) u=u->left;
        else u = u->right;
    }
    return u;
}

Node *treeMininum(Node *x)
{
    while(x->left != NIL) x = x->left;
    return x;
}

Node *treeSuccessor(Node *x)
{
    if(x->right != NIL) return treeMininum(x->right);
    Node *y = x->parent;
    while(y!=NIL && x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}

void treeDelete(Node *z)
{
    Node *y;
    Node *x;

    if(z->left == NIL || z->right == NIL) y=z;
    else y = treeSuccessor(z);

    if(y->left != NIL) x = y->left;
    else x = y->right;

    if(x!= NIL) x->parent = y->parent;

    if(y->parent == NIL) root = x;
    else
    {
        if(y==y->parent->left) y->parent->left=x;
        else y->parent->right = x;
    }

    if(y!=z) z->key = y->key;
    free(y);
}

int main()
{
    int n, i, x;
    string com;
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        cin>>com;
        if(com[0] == 'f')
        {
            scanf("%d", &x);
            Node *t = findi(root, x);
            if(t!=NIL) printf("yes\n");
            else printf("No\n");
        }
        else if(com=="insert")
        {
            scanf("%d", &x);
            inserti(x);
        }
        else if(com=="print")
        {
            inorder(root); printf("\n");
            preorder(root); printf("\n");
        }
        else if(com == "delete")
        {
            scanf("%d", &x);
            treeDelete(findi(root, x));
        }
    }
    return 0;
}

```

##### 例题

###### 是否完全二叉搜索树

> (天梯)给定$n(1\le n\le20)$，和长为$n$的左子树大的值各不同的二叉搜索树生成序列，输出层序遍历，并求其是否是完全二叉树。

个人解法：

```c++
struct tree
{
    ll ly=0,v=0;
    tree* lf=nullptr, *rf=nullptr;
};
ll n,lar[25],v,st=1,mlr,ok=1,x[1<<20];
tree *r = nullptr;
void insert(tree*& h, ll ly, ll id)//注意*&，不然暴死
{
    if(h==nullptr)
    {
        h=new tree;
        h->v=v;
        h->ly=ly;
        mlr=max(mlr,ly);
        ++lar[ly];
        x[id]=true;
        return;
    }
    if(v>h->v)
    {
        insert(h->lf,ly+1,id<<1);
    }
    else
    {
        insert(h->rf,ly+1,id<<1|1);
    }
}
void prt(ll v)
{
    if(st) st=0,printf("%d",v);
    else printf(" %d",v);
}
signed main()
{
    scanf("%d",&n);
    repe(i,1,n)
    {
        scanf("%d",&v);
        insert(r,1,1);
    }
    queue<tree*> q;
    q.push(r);
    while(!q.empty())
    {
        tree* t=q.front();
        q.pop();
        prt(t->v);
        if(t->lf) q.push(t->lf);
        if(t->rf) q.push(t->rf);
    }
    repe(i,1,n) if(!x[i]) {ok=false; break;}
    printf(ok?"\nYES":"\nNO");
    return 0;
}

```



#### Splay

搜索二叉树的一种。它通过不断将某个节点旋转到根节点，使得整棵树仍然满足二叉查找树的性质，并且保持平衡而不至于退化为链。

##### 例题

###### 文艺平衡树

> 对一个静态区间n，连续进行m次翻转，输出最终答案。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 200002
struct node
{
	ll ch[2], ff, v, size, mark;
	void init(ll x, ll fa)
	{
		ff = ch[0] = ch[1] = 0; size = 1; v = x; ff = fa;
	}
} t[mn];
ll n, rot, m, tot, lf, rf;
il void pushuf(ll x)
{
	t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + 1;
}
il void pushdf(ll x)
{
	if (t[x].mark)
	{
		t[t[x].ch[0]].mark ^= 1;
		t[t[x].ch[1]].mark ^= 1;
		t[x].mark = 0;
		swap(t[x].ch[0], t[x].ch[1]);
	}
}
il void rotate(ll x)
{
	ll y = t[x].ff;
	ll z = t[y].ff;
	ll k = (t[y].ch[1] == x);
	t[z].ch[t[z].ch[1] == y] = x;
	t[x].ff = z;
	t[y].ch[k] = t[x].ch[k ^ 1];
	t[t[x].ch[k ^ 1]].ff = y;
	t[x].ch[k ^ 1] = y;
	t[y].ff = x;
	/*printf("[%d %d %d %d %d %d]\n", t[z].ch[t[z].ch[1] == y],
		t[x].ff, t[y].ch[k], t[t[x].ch[k ^ 1]].ff, t[x].ch[k ^ 1],
		t[y].ff);*/
	pushuf(y), pushuf(x);
}
il void splay(ll x, ll tg)
{
	while (t[x].ff != tg)
	{
		ll y = t[x].ff; ll z = t[y].ff;
		if (z != tg)
			((t[z].ch[1] == y) ^ (t[y].ch[1] == x)) ? rotate(x) : rotate(y);
		rotate(x);
		//printf("%d %d\n", t[x].ff, tg);
	}
	if (!tg) rot = x;
}
il void insert(ll x)
{
	ll u = rot, ff = 0;
	while (u) ff = u, u = t[u].ch[x > t[u].v];
	//printf("[%d %d %d]\n", x, u, ff);
	u = ++tot;
	if (ff) t[ff].ch[x > t[ff].v] = u;
	t[u].init(x, ff);
	splay(u, 0);
}
il ll kth(ll k)
{
	ll u = rot;
	while (1)
	{
		pushdf(u);
		if (t[t[u].ch[0]].size >= k) u = t[u].ch[0];
		else if (t[t[u].ch[0]].size + 1 == k) return u;
		else k -= t[t[u].ch[0]].size + 1, u = t[u].ch[1];
	}
}
void write(ll u)
{
	pushdf(u);
	if (t[u].ch[0]) write(t[u].ch[0]);
	if (t[u].v > 1 && t[u].v < n + 2) printf("%d ", t[u].v - 1);
	if (t[u].ch[1]) write(t[u].ch[1]);
}
il void wk(ll lf, ll rf)
{
	lf = kth(lf), rf = kth(rf + 2);
	splay(lf, 0), splay(rf, lf);
	t[t[t[rot].ch[1]].ch[0]].mark ^= 1;
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n + 2) insert(i);
	while (m--)scanf("%d%d", &lf, &rf), wk(lf, rf);
	write(rot);
	return 0;
}
```



#### 二叉堆

Binary Heap

若最大深度-1的节点仅存在一个是仅有左子节点而无右子节点的树也称之为(近似)完全二叉树，当完全二叉树中节点键值恒小于等于（或大于等于）其父节点键值时，称之为最大堆（最小堆）。

可以用一维数组存储二叉堆，以下标1为起点。则给定下标i，通过[0.5i]，2*i,2*i+1分别访问父节点，左子节点，右子节点。

二叉堆常应用于管理优先级队列。优先取出最大键值的队列称为最大优先级队列（Priority Queue），可以通过最大堆实现。最小键值同理。

##### 数组转最大堆

复杂度为H*sum(k=1 to logH:k/(2^k))=O(H),H为二叉堆大小
$$
\Omicron(H\sum_{k=1}^{\log H}\frac k{2^k})=\Omicron(H)
$$

```c++
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2000000
int H, A[MAX+1];
void maxHeapify(int i)
{
    int l = 2*i, r = 2*i+1, largest;

    //i,l,r中找largest
    if(l<=H && A[l] > A[i]) largest = l;
    else largest = i;
    if(r<=H && A[r] > A[largest]) largest = r;
    
    //从i所在深度开始一直往下递归
    if(largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main()
{
    cin >> H;
    for(int i=1;i<=H;i++) cin>>A[i];
    for(int i=H/2;i>=1;i--) maxHeapify(i);//从第一个含子节点的开始执行！
    for(int i=1;i<=H;i++) cout<<" "<<A[i]; cout<<endl;
    return 0;
}

```

如果转最小堆，只需要把largest那两个值判断改反就好了。

##### 优先级队列插入和删除元素

```c++
int extract()
{
    int maxv;
    if(H<1) return -INFTY;//堆向下溢出
    maxv = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return maxv;
}

void increaseKey(int i, int key)
{
    if(key<A[i]) return;
    A[i] = key;
    while(i>1 && A[i/2] < A[i])
    {
        swap(A[i], A[i/2]);
        i/=2;
    }
}

void insert(int key)
{
    A[++H] = -INFTY;
    increaseKey(H, key);
}
```

##### 例题

###### 关于堆的判断

> (天梯)给定$n(1\le n\le10^3)$和$m(1\le m\le20)$，给定小根堆插入序列，值$v\in[-10^4,10^4]$，给定$m$个询问，判定：
>
> - x is the root
> - x and y are siblings
> - x is the parent of y
> - x is a child of y
>
> 输出T或F。

本题的二叉堆部分十分简单，反而难点是输入输出。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 1002
#define mm 22
typedef int ll;
ll h[mn],n,m,v;
map<ll,ll> idx;
string s,t;
char jud[]="FT";
void hpdf(ll i)
{
    if(i<=1) return;
    ll f=i>>1;
    if(h[i]<h[f])
    {
        swap(h[i],h[f]);
        hpdf(f);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(ll i=1;i<=n;++i)
    {
        scanf("%d",&v);
        h[i]=v;
        hpdf(i);
    }
    for(ll i=1;i<=n;++i) idx[h[i]]=i;
    cin.ignore();
    while(m--)
    {
        getline(cin,s);
        stringstream ss(s);
        ll a,b;
        ss>>a;
        if(s.find("root")!=-1)
        {
            printf("%c\n",jud[a==h[1]]);
        }
        else if(s.find("siblings")!=-1)
        {
            ss>>t>>b;
            printf("%c\n", jud[(idx[a]^idx[b])==1]);
        }
        else if(s.find("parent")!=-1)
        {
            ss>>t>>t>>t>>t>>b;
            printf("%c\n", jud[(idx[b]>>1)==idx[a]]);
        }
        else if(s.find("child")!=-1)
        {
            ss>>t>>t>>t>>t>>b;
            printf("%c\n", jud[(idx[a]>>1)==idx[b]]);
        }
    }
    return 0;
}
```

###### 舞蹈课

> 输入n代表n个人，输入BG字符串代表第i个人性别，输入n个数字代表舞技。接下来舞技相差最小且(相差相同时)最左的一对(不能跨越选对，只能选最相邻的)BG会出列跳舞，直到不能匹配。求匹配数和按顺序输出跳舞的对的序号(mini, maxi)。

因为是模拟题，所以思路不存在障碍。当初不当的想法如下：

> 构建两个双向静态链表，存B和G，其有4个伪指针(存下标)，代表前后自身和前后异性。因此可以用双向链表的复杂度增添O(1)和定位删除O(1)因为不是检索删除所以不是O(n)。成员为下标和舞技。建立一个双向静态链表p，成员为舞技差，有两个伪指针。对其按题意快排。(疑问1：快排后伪指针是否挂掉了，是否需要伪指针)
>
> 模拟时，按顺序遍历p的元素，遍历的时候对访问到的B和G各自执行删除操作，即将其前后(如果存在)的B和G的伪指针进行变动，并且它们相关的p进行删除。这时发现删除和寻找，以及插入新的p成员的时间复杂度远超想象，哪怕进行二分优化或哈希优化(但就不能排序了，或者每次插入都要排)十分困难，最终放弃。

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 200002
struct tog
{
	ll x, y, d;
	friend bool operator < (const tog& a, const tog& b)
	{
		if (a.d != b.d) return a.d > b.d;
		return a.x > b.x;
	}
};
priority_queue<tog, vector<tog> > p;
int n, anslen, q[MAXN], st, nd;
pair<ll, ll> ans[MAXN];
char gen[MAXN];
bool vis[MAXN], man[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> gen;
	repe(i, 1, n)
	{
		if (gen[i - 1] == 'B') man[i] = true;
		cin >> q[i];
	}
	rep(i, 1, n)
	{
		if (man[i] != man[i + 1])
		{
			p.push({ i,i + 1,abs(q[i] - q[i + 1]) });
		}
	}
	while (!p.empty())
	{
		st = p.top().x;
		nd = p.top().y;
		p.pop();
		if (!vis[st] && !vis[nd])
		{
			vis[st] = vis[nd] = true;
			ans[++anslen].first = st;
			ans[anslen].second = nd;
			while (st > 0 && vis[st]) --st;//检索有无新生成
			while (nd <= n && vis[nd])++nd;
			if (st > 0 && nd <= n && man[st] != man[nd])
				p.push({ st,nd,abs(q[st] - q[nd]) });
		}//st > 0 && nd <= n省略就完了
	}
	cout << anslen << endl;
	repe(i, 1, anslen) cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}
```



#### 笛卡尔树

是一棵节点编号满足二叉搜索树，且节点权值满足小根堆的树。支持以$\Omicron(n)$建树。

##### 例题

###### 笛卡尔数

> 给定n和节点1~n的权值($p_i$)，构建笛卡尔树，并输出：
> $$
> xor_{i=1}^ni\times(l_i+1),xor_{i=1}^ni\times(r_i+1)
> $$
> 其中$l_i,r_i$是节点i的左右节点的编号。$1\le n\le10^7,p$序列是$1\sim n$的一个乱序序列。

显然$10^7\times10^7>int$，需要开long long。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10000002
inline ll read() {
    char p = 0; ll r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
ll n, a[MAXN], stk[MAXN], ls[MAXN], rs[MAXN], pos, top;
long long lf, rf;
signed main()
{
    n = read();
    repe(i, 1, n)
    {
        a[i] = read();
        while (pos && a[stk[pos]] > a[i]) --pos;
        if (pos) rs[stk[pos]] = i;
        if (pos < top) ls[i] = stk[pos + 1];
        stk[top = ++pos] = i;
    }
    repe(i, 1, n)
        lf ^= 1LL * i * (ls[i] + 1), rf ^= 1LL * i * (rs[i] + 1);
    printf("%lld %lld", lf, rf);
    return 0;
}
```

###### 树的序

> 从给定一个生成序列可以构建唯一的一棵二叉搜索树，求出由该树反构建的字典序最小的生成序列。

事实上，可以直接构建二叉搜索树然后再先序遍历，得到的一定是正解。然而存在树退化为链的可能性因此可能TLE。

逆转权值和编号，将权值(输入值)作为编号，编号作为权值建笛卡尔树，先序遍历得所求。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
inline ll read() {
    char p = 0; ll r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
ll n, a[MAXN], stk[MAXN], ls[MAXN], rs[MAXN], pos, top;
void dfs(ll x)
{
    if (x) printf("%d ", x), dfs(ls[x]), dfs(rs[x]);
}
signed main()
{
    n = read();
    repe(i, 1, n) a[read()] = i;
    repe(i, 1, n)
    {
        pos = top;
        while (pos && a[stk[pos]] > a[i]) --pos;
        if (pos) rs[stk[pos]] = i;
        if (pos < top) ls[i] = stk[pos + 1];
        stk[top = ++pos] = i;
    }
    dfs(stk[1]);
    return 0;
}
```

这题也可以用优化平衡树过。复杂度是$\Omicron(n\log n)$

#### 左偏树

一种支持以$\Omicron(\log n)$进行合并的堆。

**外节点**：左/右儿子是空节点的节点。

**距离**：子树中与它最近的外节点到它的距离。空节点距离为-1。

性质：

- 满足小根堆/大根堆(父节点小于/大于子节点)
- 左偏：左儿子的距离大于等于右儿子的距离。
- 节点距离=右儿子的距离+1
- 距离为n的左偏树至少有$2^{n+1}-1$个节点，最少时是满二叉树。
- 有n个节点的左偏树的根节点距离为$\Omicron(\log_2n)$



##### 例题

###### 左偏树

> 一开始有n个小根堆(仅包含一个数)，输入1 x y合并第x,y个数所在的小根堆；输入2 x输出第x个数所在的小根堆的最小数并删除这个最小数，如果第x个数已经被删除，输出-1且无视删除操作

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll n, m, op, x, y, lc[MAXN], rc[MAXN], d[MAXN], rt[MAXN];
bool tf[MAXN];
struct node
{
	ll i, v;
	bool operator<(const node& x)const
	{
		return v == x.v ? i < x.i : v < x.v;
	}
} v[MAXN];
inline ll finds(ll x)
{
	while (x != rt[x]) x = rt[x] = rt[rt[x]];
	return x;
}
ll merge(ll x, ll y)
{
	if (!x || !y) return x + y;
	if (v[y] < v[x]) swap(x, y);
	rc[x] = merge(rc[x], y);
	if (d[lc[x]] < d[rc[x]]) swap(lc[x], rc[x]);
	d[x] = d[rc[x]] + 1;
	return x;
}
signed main()
{
	d[0] = -1;
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%d", &v[i].v), v[i].i = i, rt[i] = i;
	while (m--)
	{
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			scanf("%d", &y);
			if (tf[x] || tf[y]) continue;
			x = finds(x), y = finds(y);
			if (x != y) rt[x] = rt[y] = merge(x, y);
		}
		else
		{
			if (tf[x])
			{
				printf("-1\n");
				continue;
			}
			x = finds(x);
			printf("%d\n", v[x].v);
			tf[x] = true;
			rt[lc[x]] = rt[rc[x]] = rt[x] = merge(lc[x], rc[x]);
			lc[x] = rc[x] = d[x] = 0;
		}
	}
	return 0;
}
```



### 平衡树

> 事实上用vector/multiset + lower&upper_bound可以通过平衡树的模板(提高+)

### 线段树

线段树是二叉搜索树。叶节点代表点，其余节点代表区间。

> 以区间[1,4]为例，第一层为1-4，第二层为1-2,3-4，第三层为1,2,3,4

一般用于维护大数据量、经常发生修改(一般只加，当然别的操作可以灵活变型)的数组的前缀和，以及由前缀和可以计算的任何其他值(符合结合律的，如max,min,xor)，如前缀积。还可以用于模拟、DP等。而且空间经过离散化以后也可以相对压缩，所以适用范围线段树更加广一些。显然时间复杂度是nlogn。一种相似的结构，**树状数组**能够更好地实现该目标。

凡是符合结合律的二目操作都可以使用线段树。*反例：swap操作。*

注意，线段树长度比区间长度大4倍。

#### 实现1

##### 构造

递归写法

```c++
void build(int left,int right,int index)
{
    tree[index].left=left;
    tree[index].right=right;
    if(left==right) return ;//注意代码顺序；若该行放在最先应当是left<right才正确。
    int mid=(right+left)>>1;
    build(left,mid,index<<1);
    build(mid+1,right,(index<<1)+1);
}
```

##### 修改单点

```c++
void my_plus(int index,int dis,int k)
{
    tree[index].num+=k;
    if(tree[index].left==tree[index].right) return ;
    if(dis<=tree[index<<1].right)
        my_plus(index<<1,dis,k);
    if(dis>=tree[(index<<1)+1].left)
        my_plus((index<<1)+1,dis,k);
}
```

##### 查询单点

```c++
void search(int index,int dis)
{
    ans+=tree[index].num;
    if(tree[index].left==tree[index].right)
        return ;
    if(dis<=tree[index*2].right)
        search(index*2,dis);
    if(dis>=tree[index*2+1].left)
        search(index*2+1,dis);
}
```

##### 区间查询

```c++
void search(int index,int l,int r)
{
    if(tree[index].left>=l && tree[index].right<=r)
    {
        ans+=tree[index].num;//也可以用传引用参数int &ans
        return ;
    }
    if(tree[index*2].right>=l)//也可以用位运算
        search(index*2,l,r);
    if(tree[index*2+1].left<=r)
        search(index*2+1,l,r);
}
```

##### 区间修改

//不会用，直接调用不对

```c++
void pls(int index,int l,int r,int k)
{
    if(tree[index].left>=l && tree[index].right<=r)
    {
        tree[index].num+=k;
        return ;
    }
    if(tree[index*2].right>=l)
        pls(index*2,l,r,k);
    if(tree[index*2+1].left<=r)
        pls(index*2+1,l,r,k);
}
```

##### 区间最值

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 100005
#define re register
#define INF 0x7fffffff

struct tree
{
	int l,r,Min=INF;
}s[(maxn<<2)+5];

int n,m,L,R,data[maxn];

void update(int p)
{
	s[p].Min=min(s[p<<1].Min,s[p<<1|1].Min);
}

void build(int p,int l,int r)
{
	s[p].l=l;
	s[p].r=r;
	if(l==r)
	{
		s[p].Min=data[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	update(p); 
}

inline int ask(int p,int l,int r)
{
	if(l==s[p].l&&s[p].r==r) return s[p].Min; 
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return ask(p<<1,l,r);
	if(l>mid) return ask(p<<1|1,l,r);
	return min(ask(p<<1,l,mid),ask(p<<1|1,mid+1,r));
} 

int main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++) scanf("%d",&data[i]);
	build(1,1,n);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&L,&R);
		printf("%d ",ask(1,L,R)); 
	}
	return ~~(0-0);
}
```

#### 实现2

##### 代码

引入懒标记，将nlogn复杂度降为logn或更低。

懒标记的作用是记录每次、每个节点要更新的值，也就是delta,但线段树的优点不在于全记录（全记录依然很慢qwq），而在于传递式记录。

整个区间都被操作，记录在公共祖先节点上；只修改了一部分，那么就记录在这部分的公共祖先上；如果四环以内只修改了自己的话，那就只改变自己

需要在每次区间的查询修改时pushdown一次，以免重复或者冲突或者爆炸。

对于复杂度而言，由于完全二叉树的深度不超过logn，那么单点修改显然是O(logn)的，区间修改的话，由于我们的这个区间至多分logn个子区间，对于每个子区间的查询是O(1)的，所以复杂度自然是O(logn)不过带一点常数

```c++
int n;
int ans[MAXN*4];
inline int ls(int p){return p<<1;}//左儿子 
inline int rs(int p){return p<<1|1;}//右儿子 
void push_up_sum(int p){//维护sum
    t[p]=t[lc(p)]+t[rc(p)];
}//	向上不断维护区间操作 

void push_up_min(int p){//维护max and min
    t[p]=min(t[lc(p)],t[rc(p)]);//或max             
}
void build(ll p,ll l,ll r)
{
  if(l==r){ans[p]=a[l];return ;}
  //如果左右区间相同，那么必然是叶子节点啦，只有叶子节点是被真实赋值的
  ll mid=(l+r)>>1;
  build(ls(p),l,mid);
  build(rs(p),mid+1,r);
//此处由于我们采用的是二叉树，所以对于整个结构来说，可以用二分来降低复杂度，否则树形结构则没有什么明显的优化
  push_up(p);
//此处由于我们是要通过子节点来维护父亲节点，所以pushup的位置应当是在回溯时。
} 
inline void f(ll p,ll l,ll r,ll k)
{
   tag[p]=tag[p]+k;
   ans[p]=ans[p]+k*(r-l+1);
   //由于是这个区间统一改变，所以ans数组要加元素个数次啦 
}
//我们可以认识到，f函数的唯一目的，就是记录当前节点所代表的区间 
inline void push_down(ll p,ll l,ll r)
{
   ll mid=(l+r)>>1;
   f(ls(p),l,mid,tag[p]);
   f(rs(p),mid+1,r,tag[p]);
   tag[p]=0;
   //每次更新两个儿子节点。以此不断向下传递 
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k)
{
   //nl,nr为要修改的区间
   //l,r,p为当前节点所存储的区间以及节点的编号 
   if(nl<=l&&r<=nr)
   {
   	ans[p]+=k*(r-l+1);
   	tag[p]+=k;
   	return ;
   }
   push_down(p,l,r);
   //回溯之前（也可以说是下一次递归之前，因为没有递归就没有回溯） 
   //由于是在回溯之前不断向下传递，所以自然每个节点都可以更新到 
   ll mid=(l+r)>>1;
   if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
   if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
   push_up(p);
   //回溯之后 
}
ll query(ll q_x,ll q_y,ll l,ll r,ll p)
{
	ll res=0;
	if(q_x<=l&&r<=q_y)return ans[p];
	ll mid=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
	if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
	return res;
}
```

##### 使用示例

###### 区间求和和只增更新

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define mkcf long long cf=lf+rf>>1
long long a[MAXN],ans[MAXN<<2],tag[MAXN<<2],x,y,k,n,m,c;
inline long long lfs(long long x) {return x<<1;}
inline long long rfs(long long x) {return x<<1|1;}
inline void push_up(long long p) {ans[p]=ans[lfs(p)]+ans[rfs(p)];}
void initt(long long p, long long lf, long long rf)
{
    tag[p]=0LL;
    if(lf==rf)
    {
        ans[p]=a[lf];
        return;
    }
    mkcf;
    initt(lfs(p),lf,cf);
    initt(rfs(p),cf+1,rf);
    push_up(p);
}
inline void add(long long p, long long lf, long long rf, long long &k)
{
    tag[p]+=k;
    ans[p]+=k*(rf-lf+1);
}
inline void push_down(long long p, long long lf, long long rf)
{
    mkcf;
    add(lfs(p),lf,cf,tag[p]);
    add(rfs(p),cf+1,rf,tag[p]);
    tag[p]=0;
}
inline void upd(long long &loi, long long &roi, long long lf, long long rf, long long p, long long &k)
{
    if(loi<=lf && rf<=roi)
    {
        add(p,lf,rf,k);
        return;
    }
    push_down(p,lf,rf);
    mkcf;
    if(loi<=cf) upd(loi,roi,lf,cf,lfs(p),k);
    if(roi>cf)upd(loi,roi,cf+1,rf,rfs(p),k);
    push_up(p);
}
long long seam(long long &loi, long long &roi, long long lf, long long rf, long long p)
{
    long long res = 0;
    if(loi<=lf && rf<=roi)
    {
        return ans[p];
    }
    mkcf;
    push_down(p,lf,rf);
    if(loi<=cf) res+=seam(loi,roi,lf,cf,lfs(p));
    if(roi>cf)res+=seam(loi,roi,cf+1,rf,rfs(p));
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    initt(1,1,n);
    while(m--)
    {
        scanf("%d%d%d",&c,&x,&y);
        if(c==1)
        {
            scanf("%d",&k);
            upd(x,y,1,n,1,k);
        }
        else
        {
            printf("%lld\n", seam(x,y,1,n,1));
        }
    }
    return 0;
}
```

###### 单点修改和区间求和

while(m--)内改为如下：

```c++
scanf("%lld%lld%lld",&c,&x,&y);//或%d
if(c==1)
{
    temp = y-a[x];//temp在全局开了；在这里开也无妨，为了避免妨碍传引用
    a[x] = y;
    upd(x,x,1,n,1,temp);
}
else
{
    printf("%lld\n", seam(x,y,1,n,1));
}
```

###### 区间加/乘和区间查询

mul是乘法的lazytag，add是加法的lazytag

```c++
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:6031)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 100002
#define initmp mul[p] = 1; add[p] = 0
#define mkcf ll cf=lf+rf>>1
#define mkcfp ll cf=alf[p]+arf[p]>>1
#define suit if (lf <= alf[p] && arf[p] <= rf)
typedef long long ll;
ll a[MAXN], alf[MAXN << 2], arf[MAXN << 2], add[MAXN << 2], mul[MAXN << 2], sum[MAXN << 2];
ll mod, n, m, c, x, y, w;
inline void prt(ll* z)
{
	rep(i, 1, n << 2)
	{
		printf("%lld ", z[i]);
	} putchar('\n');
}
inline void pushuf(ll p) { sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod; }
inline void pushdf(ll p)
{
	ll k = mul[p], b = add[p];
	sum[p << 1] = (sum[p << 1] * k + b * (arf[p << 1] - alf[p << 1] + 1)) % mod;
	sum[p << 1 | 1] = (sum[p << 1 | 1] * k + b * (arf[p << 1 | 1] - alf[p << 1 | 1] + 1)) % mod;
	mul[p << 1] = (mul[p << 1] * k) % mod;
	mul[p << 1 | 1] = (mul[p << 1 | 1] * k) % mod;
	add[p << 1] = (add[p << 1] * k + b) % mod;
	add[p << 1 | 1] = (add[p << 1 | 1] * k + b) % mod;
	initmp;
}
void build(ll p, ll lf, ll rf)
{
	initmp;
	alf[p] = lf; arf[p] = rf;
	if (lf == rf)
	{
		sum[p] = a[lf];
		return;
	}
	mkcf;
	build(p << 1, lf, cf);
	build(p << 1 | 1, cf + 1, rf);
	pushuf(p);
}
void mkadd(ll p, ll lf, ll rf, ll& v)
{
	suit
	{
		sum[p] = (sum[p] + v * (arf[p] - alf[p] + 1)) % mod;
		add[p] = (add[p] + v) % mod;
		return;
	}
	pushdf(p);
	mkcfp;
	if (lf <= cf) mkadd(p << 1, lf, rf, v);
	if (cf < rf) mkadd(p << 1 | 1, lf, rf, v);
	pushuf(p);
}
void mkmul(ll p, ll lf, ll rf, ll& v)
{
	suit
	{
		sum[p] = (sum[p] * v) % mod;
		mul[p] = (mul[p] * v) % mod;
		add[p] = (add[p] * v) % mod;
		return;
	}
	pushdf(p);
	mkcfp;
	if (lf <= cf) mkmul(p << 1, lf, rf, v);
	if (cf < rf) mkmul(p << 1 | 1, lf, rf, v);
	pushuf(p);
}
ll query(ll p, ll lf, ll rf)
{
	suit return sum[p] % mod;
	pushdf(p);
	ll ans = 0;
	mkcfp;
	if (lf <= cf) ans = query(p << 1, lf, rf) % mod;
	if (cf < rf) ans = (ans + query(p << 1 | 1, lf, rf)) % mod;
	return ans % mod;
}
signed main()
{
	scanf("%lld%lld%lld", &n, &m, &mod);
	rep(i, 1, n) scanf("%lld", &a[i]);
	build(1, 1, n);
	while (m--)
	{
		scanf("%lld%lld%lld", &c, &x, &y);
		if (c == 3) printf("%lld\n", query(1, x, y));
		else if (c == 2)
		{
			scanf("%lld", &w);
			mkadd(1, x, y, w);
		}
		else
		{
			scanf("%lld", &w);
			mkmul(1, x, y, w);
		}
	}
	return 0;
}
```



###### 多个线段树

5e5的点数和查询/修改数妥妥超时

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500003
#define MOD 1000000007
#define mkcf ll cf=lf+rf>>1
typedef long long ll;
#define il inline
char c;
ll a[MAXN],b[MAXN],a1[MAXN<<2],t1[MAXN<<2],a2[MAXN<<2],t2[MAXN<<2],x,y,k,n,m,temp,temp2,in2;
il ll lfs(ll x) {return x<<1;}
il ll rfs(ll x) {return x<<1|1;}
il void push_up(ll p, ll *obj) {obj[p]=obj[lfs(p)]+obj[rfs(p)];}
void initt(ll p, ll lf, ll rf, ll *obj, ll *objt, ll cmd)
{
    objt[p]=0LL;
    if(lf==rf)
    {
        if(cmd==1) obj[p]=a[lf];
        else obj[p]=b[lf];
        return;
    }
    mkcf;
    initt(lfs(p),lf,cf,obj,objt,cmd);
    initt(rfs(p),cf+1,rf,obj,objt,cmd);
    push_up(p,obj);
}
il void add(ll p, ll lf, ll rf, ll &k, ll *obj, ll *objt)
{
    objt[p]+=k;
    objt[p]%=MOD;
    obj[p]+=k*(rf-lf+1);
    obj[p]%=MOD;
}
il void push_down(ll p, ll lf, ll rf, ll *obj, ll *objt)
{
    mkcf;
    add(lfs(p),lf,cf,objt[p],obj,objt);
    add(rfs(p),cf+1,rf,objt[p],obj,objt);
    objt[p]=0;
}
il void upd(ll &loi, ll &roi, ll lf, ll rf, ll p, ll &k, ll *obj, ll *objt)
{
    if(loi<=lf && rf<=roi)
    {
        add(p,lf,rf,k,obj,objt);
        return;
    }
    push_down(p,lf,rf,obj,objt);
    mkcf;
    if(loi<=cf) upd(loi,roi,lf,cf,lfs(p),k,obj,objt);
    if(roi>cf) upd(loi,roi,cf+1,rf,rfs(p),k,obj,objt);
    push_up(p,obj);
}
ll seam(ll &loi, ll &roi, ll lf, ll rf, ll p, ll *obj, ll *objt)
{
    ll res=0LL;
    if(loi<=lf && rf<=roi) return obj[p];
    mkcf;
    push_down(p,lf,rf,obj,objt);
    if(loi<=cf) res+=seam(loi,roi,lf,cf,lfs(p),obj,objt)%MOD;
    if(roi>cf) res+=seam(loi,roi,cf+1,rf,rfs(p),obj,objt)%MOD;
    return res;
}
ll fpm(ll x, ll power, ll mod) {
    x %= mod;
    ll ans = 1;
    for (; power; power >>= 1, (x *= x) %= mod)
    	if(power & 1) (ans *= x) %= mod;
    return ans;
}
il void prt()
{
    for(int i=1;i<=n<<2;i++) printf("%d ", a1[i]); printf("\n");
    for(int i=1;i<=n<<2;i++) printf("%d ", t1[i]); printf("\n");
    for(int i=1;i<=n<<2;i++) printf("%d ", a2[i]); printf("\n");
    for(int i=1;i<=n<<2;i++) printf("%d ", t2[i]); printf("\n");
}
signed main()
{
    in2=fpm(2,MOD-2,MOD);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i]*a[i];
    }
    initt(1,1,n,a1,t1,1);
    initt(1,1,n,a2,t2,2);
    //prt();
    while(m--)
    {
        scanf("\n%c%d%d",&c,&x,&y);
        if(c=='Q')
        {
            temp=seam(x,y,1,n,1,a1,t1);
            //printf("%lld ",temp);
            temp2=seam(x,y,1,n,1,a2,t2);
            //printf("%lld ",temp2);
            temp=(temp*temp+temp2)%MOD;
            //printf("%lld ",temp);
            temp=temp*in2%MOD;
            //printf("%lld ",temp);
            printf("%lld\n",temp);
        }
        else
        {
            temp=(y-a[x]+MOD)%MOD;
            a[x]=y;
            upd(x,x,1,n,1,temp,a1,t1);
            //prt();
            temp=(y*y-b[x]+MOD)%MOD;
            b[x]=y*y%MOD;
            upd(x,x,1,n,1,temp,a2,t2);
            //prt();
        }
    }
    return 0;
}
```

#### 个人实现

##### 基本型

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 100002
#define mkcf ll cf=lf+rf>>1
ll m,n,a[mn],d[mn<<2],b[mn<<2],lc,rc,cmd,k;//b是懒标签
void build(ll lf, ll rf, ll rot)
{
    if(lf==rf)
    {
        d[rot]=a[lf];
        return;
    }
    mkcf;
    build(lf,cf,rot<<1);
    build(cf+1,rf,rot<<1|1);
    d[rot]=d[rot<<1]+d[rot<<1|1];
}
inline void push_down(ll& lf, ll& cf, ll& rf, ll& rot)
{
    d[rot<<1]+=b[rot]*(cf-lf+1);
    d[rot<<1|1]+=b[rot]*(rf-cf);
    b[rot<<1]+=b[rot],b[rot<<1|1]+=b[rot],b[rot]=0;
}
void add(ll& lc, ll& rc, ll lf, ll rf, ll rot, ll& k)
{
    if(lf>=lc&&rf<=rc)//节点自己更新，懒标签代表左右儿子未更新
    {
        d[rot]+=k*(rf-lf+1);
        b[rot]+=k;//+=是因为可能有多个修改才对应一个查询
        return; //同理所以push_down的变化量不是k
    }
    mkcf;
    if(b[rot]) push_down(lf,cf,rf,rot);//可以加&&lf!=rf，但基本无影响(而且很多其他线段树操作是不允许加的)，更甚一步，add和query都不需要if(b[rot])判定，这样做的代价仅仅是常数变差一点点
    if(cf>=lc) add(lc,rc,lf,cf,rot<<1,k);
    if(cf<rc) add(lc,rc,cf+1,rf,rot<<1|1,k);
    d[rot]=d[rot<<1]+d[rot<<1|1];
}
ll query(ll& lc, ll& rc, ll lf, ll rf, ll rot)
{
    if(lf>=lc&&rf<=rc) return d[rot];
    mkcf;
    ll res=0;
    if(b[rot])  push_down(lf,cf,rf,rot);
    if(cf>=lc) res+=query(lc,rc,lf,cf,rot<<1);//这个+=或=均可
    if(cf<rc) res+=query(lc,rc,cf+1,rf,rot<<1|1);//这个只能+=
    return res;//记得return
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i) scanf("%lld",a+i);
    build(1,n,1);
    while(m--)
    {
        scanf("%lld%lld%lld",&cmd,&lc,&rc);
        if(cmd==1) scanf("%lld",&k),add(lc,rc,1,n,1,k);
        else if(cmd==2) printf("%lld\n",query(lc,rc,1,n,1));
    }
    return 0;
}
```

可能的错误bugs方向：

- init处a[lf]写成了a[i]
- 线段树没开四倍长
- query没有pushdown
- 弄混懒标签和值，query时直接求和懒标签
- pushdown函数写不对
- add和query的区间范围判反
- 递归判定将lc,rc写成lf,rf
- add只更新了完全包含节点，没有更新父节点，或者更新错漏了懒标签和值
- add父节点更新为子节点的和把`=`写成`+=`死无葬身之地 (d=写成d+=)

##### 懒标签

###### 区间开关

即每次区间操作把1置0，把0置1。则记录的是区间内有多少个1,。注意懒标签的累加，所以使用\^=1记录懒标签(布尔值)，区间操作是用区间长度减去本来的值。如果一开始全0不需要建树。参考代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mn 100002
#define mkcf ll cf=lf+rf>>1
ll m,n,a[mn],d[mn<<2],b[mn<<2],lc,rc,cmd,k;
inline void push_down(ll& lf, ll& cf, ll& rf, ll& rot)
{
    d[rot<<1]=(cf-lf+1)-d[rot<<1];
    d[rot<<1|1]=(rf-cf)-d[rot<<1|1];
    b[rot<<1]^=1,b[rot<<1|1]^=1,b[rot]=0;
}
void add(ll& lc, ll& rc, ll lf, ll rf, ll rot)
{
    if(lf>=lc&&rf<=rc)
    {
        d[rot]=(rf-lf+1)-d[rot];
        b[rot]^=1;
        return;
    }
    mkcf;
    if(b[rot]) push_down(lf,cf,rf,rot);//注意不要设lf!=rf
    if(cf>=lc) add(lc,rc,lf,cf,rot<<1);
    if(cf<rc) add(lc,rc,cf+1,rf,rot<<1|1);
    d[rot]=d[rot<<1]+d[rot<<1|1];
}
ll query(ll& lc, ll& rc, ll lf, ll rf, ll rot)
{
    if(lf>=lc&&rf<=rc) return d[rot];
    mkcf;
    ll res=0;
    if(b[rot])  push_down(lf,cf,rf,rot);
    if(cf>=lc) res+=query(lc,rc,lf,cf,rot<<1);
    if(cf<rc) res+=query(lc,rc,cf+1,rf,rot<<1|1);
    return res;
}
signed main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&cmd,&lc,&rc);
        if(cmd==0) add(lc,rc,1,n,1);
        else if(cmd==1) printf("%d\n",query(lc,rc,1,n,1));
    }
    return 0;
}
```

###### 区间加乘

注意要点如下：

- 设置两个懒标记(加和乘)
- 乘法懒标记初始值是1，不是0
- 区间乘法的更新会连带加法的更新，且注意累乘
- 加法懒标签的更新前，儿子加法懒标签乘以父亲的乘法懒标签，再加父亲的加法懒标签
- push_down操作要先乘后加，即儿子乘以乘法懒标签，再加区间长度乘以加法懒标签

```c++
#include <iostream>
#include <cstdio>
using namespace std;
//题目中给的p
int p;
//暂存数列的数组
long long a[100007];
//线段树结构体，v表示此时的答案，mul表示乘法意义上的lazytag，add是加法意义上的
struct node{
    long long v, mul, add;
}st[400007];
//buildtree
void bt(int root, int l, int r){
//初始化lazytag
    st[root].mul=1;
    st[root].add=0;
    if(l==r){
        st[root].v=a[l];
    }
    else{
        int m=(l+r)/2;
        bt(root*2, l, m);
        bt(root*2+1, m+1, r);
        st[root].v=st[root*2].v+st[root*2+1].v;
    }
    st[root].v%=p;
    return ;
}
//核心代码，维护lazytag
void pushdown(int root, int l, int r){
    int m=(l+r)/2;
//根据我们规定的优先度，儿子的值=此刻儿子的值*爸爸的乘法lazytag+儿子的区间长度*爸爸的加法lazytag
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
//很好维护的lazytag
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
//把父节点的值初始化
    st[root].mul=1;
    st[root].add=0;
    return ;
}
//update1，乘法，stdl此刻区间的左边，stdr此刻区间的右边，l给出的左边，r给出的右边
void ud1(int root, int stdl, int stdr, int l, int r, long long k){
//假如本区间和给出的区间没有交集
    if(r<stdl || stdr<l){
        return ;
    }
//假如给出的区间包含本区间
    if(l<=stdl && stdr<=r){
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return ;
    }
//假如给出的区间和本区间有交集，但是也有不交叉的部分
//先传递lazytag
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud1(root*2, stdl, m, l, r, k);
    ud1(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//update2，加法，和乘法同理
void ud2(int root, int stdl, int stdr, int l, int r, long long k){
    if(r<stdl || stdr<l){
        return ;
    }
    if(l<=stdl && stdr<=r){
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return ;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud2(root*2, stdl, m, l, r, k);
    ud2(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//访问，和update一样
long long query(int root, int stdl, int stdr, int l, int r){
    if(r<stdl || stdr<l){
        return 0;
    }
    if(l<=stdl && stdr<=r){
        return st[root].v;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    return (query(root*2, stdl, m, l, r)+query(root*2+1, m+1, stdr, l, r))%p;
}
int main(){
    int n, m;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    bt(1, 1, n);
    while(m--){
        int chk;
        scanf("%d", &chk);
        int x, y;
        long long k;
        if(chk==1){
            scanf("%d%d%lld", &x, &y, &k);
            ud1(1, 1, n, x, y, k);
        }
        else if(chk==2){
            scanf("%d%d%lld", &x, &y, &k);
            ud2(1, 1, n, x, y, k);
        }
        else{
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
```

#### zwk树

##### 例题

###### 数学计算

> 对初始为1的变量进行n次操作，(1 x)让其乘x再取模，(2 x)撤销第x次操作(保证为1操作被撤销)，每次操作后输出该变量

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 400002
ll d[MAXN], n, m, t, mod, p, a, b;
signed main()
{
	for (scanf("%lld", &t); t; --t)
	{
		scanf("%lld%lld", &n, &mod);
		for (m = 1; m <= n; m <<= 1);
		fill(d + 1, d + m + n + 2, 1);
		repe(i, 1, n)
		{
			scanf("%lld%lld", &a, &b);
			a == 1 ? d[p = i + m] = b % mod : d[p = b + m] = 1;
			while (p >>= 1) d[p] = d[p << 1] * d[p << 1 | 1] % mod;
			printf("%lld\n", d[1]);
		}
	}
	return 0;
}
```

一般线段树写法：

```c++
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
struct Segment{
    ll val;
}st[400010];
ll t;
ll q, mod;
ll opt, m[100010];
void build(ll p, ll l, ll r) {
    if (l == r) {
        st[p].val = 1;
        return;
    }
    ll mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    st[p].val = (st[p << 1].val * st[p << 1 | 1].val) % mod;
}
void change(ll p, ll l, ll r, ll pos, ll v) {
    if (l == r) {
        st[p].val = v;
        return;
    }
    ll mid = (l + r) >> 1;
    if (pos <= mid) change(p << 1, l, mid, pos, v);
    else change(p << 1 | 1, mid + 1, r, pos, v);
    st[p].val = (st[p << 1].val * st[p << 1 | 1].val) % mod;
}
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &q, &mod);
        build(1, 1, q);
        for (ll i = 1; i <= q; i++) {
            scanf("%lld%lld", &opt, &m[i]);
            if (opt == 1) {
                change(1, 1, q, i, m[i]);
                printf("%lld\n", st[1].val);
            } else {
                change(1, 1, q, m[i], 1);
                printf("%lld\n", st[1].val);
            }
        }
    }
    return 0;
}
```

#### 主席树

可持久化线段树，每次作修改/查询将取得一个版本。运行方式类似于git的版本管理。基于线段树的数据结构。对于每次操作可以新增一条变动链，长为$\log n$。因为复杂的指向关系，每个节点必须维护左右节点编号和值。具体操作见例题。

主席树的空间建议是所维护区间长度的$20$倍。这次因为每次操作最坏情况新增点数为$\lceil\log n\rceil+1$（1是根节点），$n$次修改增加$n\log n$的节点数。所以直接使用`n<<5`即可。

##### 例题

###### 可持久化数组

> 对于每次操作保存一个副本，下次操作基于曾经的某个副本。操作为单点修改或单点查询。数据规模为$10^6$。

```c++
#include <bits/stdc++.h>
#define re
using namespace std;
typedef int ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 1000010
#define mkcf ll cf = (lf + rf) >> 1
struct tree
{
    ll lf, rf, v;
} t[mn << 5];
ll top, a[mn], n, m, ver[mn], rt, cmd, x, y;
ll clone(ll ori)
{
    t[++top] = t[ori];
    return top;
}
ll build(ll lf, ll rf)
{
    ll p = ++top;
    if (lf == rf)
    {
        t[p].v = a[lf];
        return p;
    }
    mkcf;
    t[p].lf = build(lf, cf);
    t[p].rf = build(cf + 1, rf);
    return p;
}
ll update(ll orip, ll lf, ll rf, ll x, ll v) //单点修改a[x]=v
{
    ll p = clone(orip);
    if (lf == rf)
    {
        t[p].v = v;
        return p;
    }
    mkcf;
    if (x <= cf)
        t[p].lf = update(t[p].lf, lf, cf, x, v);
    else
        t[p].rf = update(t[p].rf, cf + 1, rf, x, v);
    return p;
}
ll query(ll p, ll lf, ll rf, ll x) //不必更新版本
{
    if (lf == rf)
        return t[p].v;
    mkcf;
    if (x <= cf)
        return query(t[p].lf, lf, cf, x);
    return query(t[p].rf, cf + 1, rf, x);
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
        sc(a[i]);
    ver[0] = build(1, n);
    for (ll i = 1; i <= m; ++i)
    {
        sc(rt), sc(cmd), sc(x);
        if (cmd == 1)
        {
            sc(y);
            ver[i] = update(ver[rt], 1, n, x, y);
        }
        else
        {
            printf("%d\n", query(ver[rt], 1, n, x));
            ver[i] = ver[rt];
        }
    }
    return 0;
}
```



###### 静态区间第k小

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 200002
#define mkcf ll cf=(lf+rf)>>1
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
ll n, q, m, cnt, a[mn], b[mn], t[mn];
ll sum[mn << 5], l[mn << 5], r[mn << 5];//其实*18就够了
il ll build(ll lf, ll rf)
{
	ll rt = ++cnt; sum[rt] = 0; mkcf;
	if (lf < rf) l[rt] = build(lf, cf), r[rt] = build(cf + 1, rf);
	return rt;
}
il ll upd(ll pre, ll lf, ll rf, ll x)
{
	ll rt = ++cnt; mkcf;
	l[rt] = l[pre], r[rt] = r[pre], sum[rt] = sum[pre] + 1;
	if (lf < rf)
	{
		if (x <= cf) l[rt] = upd(l[pre], lf, cf, x);
		else r[rt] = upd(r[pre], cf + 1, rf, x);
	}
	return rt;
}
il ll ask(ll u, ll v, ll lf, ll rf, ll k)
{
	if (lf >= rf) return lf;
	mkcf; ll x = sum[l[v]] - sum[l[u]];
	if (x >= k) return ask(l[u], l[v], lf, cf, k);
	else return ask(r[u], r[v], cf + 1, rf, k - x);
}
signed main()
{
	n = read(), q = read();
	repe(i, 1, n) a[i] = read(), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	t[0] = build(1, m);
	repe(i, 1, n)
	{
		ll tp = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		t[i] = upd(t[i - 1], 1, m, tp);
	}
	while (q--)
	{
		ll x = read(), y = read(), z = read();
		printf("%d\n", b[ask(t[x - 1], t[y], 1, m, z)]);
	}
	return 0;
}
```

###### 单点修改和查询

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 1000002
#define mkcf ll cf=(lf+rf)>>1
#define llf lc[o],lf,cf
#define rrf rc[o],cf+1,rf
ll a[mn], n, m, q, rt[mn * 20], p, o, x;//ceil(lg(mn))=20
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
struct president {
	ll lc[mn * 20], rc[mn * 20], val[mn * 20], cnt;
	il void build(ll& o, ll lf, ll rf)
	{
		o = ++cnt; if (lf == rf) { val[o] = a[rf]; return; }
		mkcf; build(llf), build(rrf);
	}
	il void ins(ll& o, ll lf, ll rf, ll pre, ll q, ll v)
	{
		o = ++cnt; lc[o] = lc[pre], rc[o] = rc[pre], val[o] = val[pre];
		if (lf == rf) { val[o] = v; return; }
		mkcf;
		if (q <= cf) ins(llf, lc[pre], q, v);
		else ins(rrf, rc[pre], q, v);
	}
	il ll query(ll o, ll lf, ll rf, ll q)
	{
		if (lf == rf) return val[o]; mkcf;
		if (q <= cf) return query(llf, q); else return query(rrf, q);
	}
} t;
signed main()
{
	n = read(), m = read();
	repe(i, 1, n) a[i] = read();
	t.build(rt[0], 1, n);
	repe(i, 1, m)
	{
		p = read(), o = read(), x = read();
		if (o == 1) t.ins(rt[i], 1, n, rt[p], x, read());
		else printf("%d\n", t.query(rt[p], 1, n, x)), rt[i] = rt[p];
	}
	return 0;
}
```

#### 应用

##### 线段覆盖

基本问题为：对公差为1的有限等差数列，用若干个区间进行覆盖，求未被覆盖的项数。

> 例题：区间从1开始，到n，有m次覆盖，为闭区间[x,y]。

给出模板：

###### 线段树

> 该模板WA，具体原因待查。

```c++
#include<bits/stdc++.h>
#define re
#define repe(i,l,r) for(re int i=l;i<=r;++i)
#define IT set<node>::iterator
using namespace std;

int n,m,x,y;

struct node{
    int l,r;
    mutable int v;
    node(int L,int R=-1,int V=0):l(L),r(R),v(V) {}
    bool operator <(const node &o)const{
        return l<o.l;
    }
};

set<node> s;

inline IT split(re int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos)
      return it;
    --it;
    int L=it->l;
    int R=it->r;
    int V=it->v;
    s.erase(it);
    s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
}

inline void assign_val(re int l,re int r,re int val=0){
    IT itr=split(r+1),itl=split(l);
    s.erase(itl,itr);
    s.insert(node(l,r,val));
}

inline int query(re int l,re int r){
    int res=0;
    IT itr=split(r+1),itl=split(l);
    for(;itl!=itr;++itl)
      res+=(itl->r-itl->l+1)*(itl->v);
    return res;
}

signed main(){
    scanf("%d%d",&n,&m);
    s.insert(node(0,n,1));
    assign_val(0,0,0);//原模板对应0到n，所以特判一下，但挂了
    repe(i,1,m){
        scanf("%d%d",&x,&y);
        assign_val(x,y,0);
    }
    printf("%d\n",query(0,n));
    return 0;
}
```

###### 珂朵莉树

```c++
#include<bits/stdc++.h>
#define re
#define repe(i,l,r) for(re int i=l;i<=r;++i)
#define IT set<node>::iterator
using namespace std;

int n,m,x,y;

struct node{
    int l,r;
    mutable int v;
    node(int L,int R=-1,int V=0):l(L),r(R),v(V) {}
    bool operator <(const node &o)const{
        return l<o.l;
    }
};

set<node> s;

inline IT split(re int pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos)
      return it;
    --it;
    int L=it->l;
    int R=it->r;
    int V=it->v;
    s.erase(it);
    s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
}

inline void assign_val(re int l,re int r,re int val=0){
    IT itr=split(r+1),itl=split(l);
    s.erase(itl,itr);
    s.insert(node(l,r,val));
}

inline int query(re int l,re int r){
    int res=0;
    IT itr=split(r+1),itl=split(l);
    for(;itl!=itr;++itl)
      res+=(itl->r-itl->l+1)*(itl->v);
    return res;
}

signed main(){
    scanf("%d%d",&n,&m);
    s.insert(node(0,n,1));
    assign_val(0,0,0);//原模板对应0~n，所以直接把[0,0]覆盖掉
    repe(i,1,m){
        scanf("%d%d",&x,&y);
        assign_val(x,y,0);
    }
    printf("%d\n",query(0,n));
    return 0;
}
```

##### 按位取反

> XOR的艺术。有长为n的01串，m次操作，0 l r表示将[l,r]按位取反；1 l r查询[l,r]有多少个1.

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
#define mkcf ll cf = lf + rf >> 1
ll n, m, p, l, r, a[MAXN], add[MAXN << 2], sum[MAXN << 2];
inline void getup(ll k) { sum[k] = sum[k << 1] + sum[k << 1 | 1]; }
inline void build(ll lf, ll rf, ll v)
{
	if (lf == rf) { sum[v] = a[lf]; return; }
	mkcf;
	build(lf, cf, v << 1);
	build(cf + 1, rf, v << 1 | 1);
	getup(v);
}
inline void pushdown(ll v, ll len)
{
	if (add[v])
	{
		add[v << 1] ^= 1;
		add[v << 1 | 1] ^= 1;
		sum[v << 1] = (len - (len >> 1)) - sum[v << 1];
		sum[v << 1 | 1] = (len >> 1) - sum[v << 1 | 1];
		add[v] = 0;
	}
}
inline ll query(ll l, ll r, ll lf, ll rf, ll v)
{
	if (lf >= l && rf <= r) return sum[v];
	pushdown(v, rf - lf + 1);
	mkcf, tot = 0;
	if (l <= cf) tot += query(l, r, lf, cf, v << 1);
	if (cf + 1 <= r) tot += query(l, r, cf + 1, rf, v << 1 | 1);
	return tot;
}
inline void upd(ll l, ll r, ll lf, ll rf, ll v)
{
	pushdown(v, rf - lf + 1);
	if (lf >= l && rf <= r)
	{
		add[v] ^= 1;
		sum[v] = rf - lf + 1 - sum[v];
		return;
	}
	ll cf = lf + rf >> 1;
	if (l <= cf) upd(l, r, lf, cf, v << 1);
	if (cf + 1 <= r) upd(l, r, cf + 1, rf, v << 1 | 1);
	getup(v);
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%1d", &a[i]);
	build(1, n, 1);
	while (m--)
	{
		scanf("%d%d%d", &p, &l, &r);
		if (p) printf("%d\n", query(l, r, 1, n, 1));
		else upd(l, r, 1, n, 1);
	}
	return 0;
}
```

##### 删除和最值查询

> 维护长为n的序列a
>
> 对命令1 k，删除第k个数，右边的数全部左移一位(下标减一)
>
> 对命令2 l r, 查询闭区间[l,r]内最小值和最大值

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
#define BIG 0x7ffffffa
struct node
{
	ll l, r, mi, mx, n;
} tr[MAXN << 2];
ll n, m, a[MAXN], ami, amx, c, lfc, rfc;
#define mkn ll n1 = tr[fa << 1].n, n2 = tr[fa << 1 | 1].n
void build(ll lf, ll rf, ll fa)
{
	tr[fa].l = lf, tr[fa].r = rf;
	if (lf == rf)
	{
		tr[fa].mx = tr[fa].mi = a[lf];
		tr[fa].n = 1;
		return;
	}
	ll cf = (lf + rf) >> 1;
	build(lf, cf, fa << 1);
	build(cf + 1, rf, fa << 1 | 1);
	tr[fa].mx = max(tr[fa << 1].mx, tr[fa << 1 | 1].mx);
	tr[fa].mi = min(tr[fa << 1].mi, tr[fa << 1 | 1].mi);
	tr[fa].n = tr[fa << 1].n + tr[fa << 1 | 1].n;
}
void query(ll lf, ll rf, ll fa)
{
	if (lf == 1 && rf == tr[fa].n)
	{
		ami = min(ami, tr[fa].mi);
		amx = max(amx, tr[fa].mx);
		return;
	}
	mkn;
	if (lf <= n1 && rf > n1) query(lf, n1, fa << 1), query(1, rf - n1, fa << 1 | 1);
	else if (lf <= n1 && rf <= n1) query(lf, rf, fa << 1);
	else if (lf > n1 && rf <= n1 + n2) query(lf - n1, rf - n1, fa << 1 | 1);
}
void del(ll ni, ll fa)
{
	if (tr[fa].l == tr[fa].r)
	{
		--tr[fa].n, tr[fa].mi = BIG, tr[fa].mx = -BIG;
		return;
	}
	mkn;
	if (ni <= n1) del(ni, fa << 1);
	else del(ni - n1, fa << 1 | 1);
	tr[fa].n = tr[fa << 1].n + tr[fa << 1 | 1].n;
	tr[fa].mx = max(tr[fa << 1].mx, tr[fa << 1 | 1].mx);
	tr[fa].mi = min(tr[fa << 1].mi, tr[fa << 1 | 1].mi);
}

signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%d", &a[i]);
	repe(i, 1, n << 2) tr[i].mi = BIG, tr[i].mx = -BIG;
	build(1, n, 1);
	while (m--)
	{
		scanf("%d%d", &c, &lfc);
		if (c == 1) del(lfc, 1);
		else
		{
			ami = BIG, amx = -BIG;
			scanf("%d", &rfc);
			query(lfc, rfc, 1);
			printf("%d %d\n", ami, amx);
		}
	}
	return 0;
}
```

##### 其他例题

###### hard query problem

> (oj)对区间进行两种操作，一是区间计算数位和来取代原本的值，二是求区间最小值。
>
> $1\le n,m\le10^5,1\le a\le10^{18}$

经验表明，注意到数位和最多进行三次(不是两次，不要用全$9$来算……)，所以如果对线段树某个节点已经累计过三次懒标签，那么查询时就可以直接返回了，进行剪枝。每次区间计算只更新懒标签，而每次区间查询时对查询到的地方都要强制全部更新(但是由于最多只会更新三次，所以复杂度并不算高)。

```c++
#define mn 100010
#define mkcf ll cf = lf + rf >> 1
#define lfs p << 1
#define rfs p << 1 | 1
ll n, m, a[mn], o, lc, rc, z[mn << 2], v[mn << 2], ans, zcnt[mn << 2], done[mn << 2];
void build(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        v[p] = a[lf];
        return;
    }
    mkcf;
    build(lf, cf, lfs);
    build(cf + 1, rf, rfs);
    v[p] = min(v[lfs], v[rfs]);
}
il void pushdown(ll &lf, ll &rf, ll &p)
{
    z[lfs] += z[p], z[rfs] += z[p], z[p] = 0;
    zcnt[lfs] += z[p], zcnt[rfs] += z[p];
}
void upd(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        rep(h, 0, min(3LL, z[p]))
        {
            if (v[p] < 10)
                break;
            ll t = 0;
            for (; v[p]; v[p] /= 10)
                t += v[p] % 10;
            v[p] = t;
        }
        z[p] = 0;
        return;
    }
    mkcf;
    pushdown(lf, rf, p);
    upd(lf, cf, lfs);
    upd(cf + 1, rf, rfs);
    v[p] = min(v[lfs], v[rfs]);
}
void add(ll lf, ll rf, ll p)
{
    if (lf >= lc && rf <= rc)
    {
        ++z[p];
        ++zcnt[p];
        return;
    }
    mkcf;
    pushdown(lf, rf, p);
    if (cf >= lc)
        add(lf, cf, lfs);
    if (cf < rc)
        add(cf + 1, rf, rfs);
    v[p] = min(v[lfs], v[rfs]);
}
void query(ll lf, ll rf, ll p)
{
    if (lf >= lc && rf <= rc)
    {
        if (!done[p])
            upd(lf, rf, p);
        if (zcnt[p] >= 3)
            done[p] = true;
        ans = min(ans, v[p]);
        return;
    }
    mkcf;
    pushdown(lf, rf, p);
    if (cf >= lc)
        query(lf, cf, lfs);
    if (cf < rc)
        query(cf + 1, rf, rfs);
}
signed main()
{
    memset(v, 0x3f, sizeof v);
    sc(n), sc(m);
    repe(i, 1, n) sc(a[i]);
    build(1, n, 1);
    while (m--)
    {
        sc(o), sc(lc), sc(rc), ans = 0x7ffffffffffffffa;
        if (o == 1)
            add(1, n, 1);
        else
        {
            query(1, n, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```

###### Game Theory

> 定义$01$串$s$的分数$f(s)$，若$s$全$0$，$f(s)=0$，否则，有$k$个$1$，$s'=s$且$s'[k]\oplus1$，$f(s)=f(s')+1$。给定$n$长$s$和$q$个区间翻转，求每次翻转后$f(s)$值$\mod 998244353$。$1\le n,q\le2\times10^5$

求$f$函数的过程，一定是从$k$位置开始每次相隔一个位置的修改，直至最后修改成全$0$。

一种理想情况是前$k-1$个全$0$，后$k$个全$1$，那么从第$k$位开始，往前直到消耗一个最近的$0$，然后回到下一位$k+1$，如此往返(如果没有0就往前到头然后返回)。

不消耗$0$往前到头返回时，位置为$p$的$1$贡献$2p$。有$0$时，$0$的位置是$p$，提前返回，减少了$2p$的贡献。而对于每个$1$，自己还要往后移一位，所以都加$1$贡献。

非理想情况可以类推。可以得到答案为：前$k-1$个里$0$的贡献+后$k$的$1$的贡献+$k$。

可以使用线段树维护区间翻转的模板，简单得到线段树代码，完整题解如下：

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 200010
#define mod 998244353
struct segtree
{
    ll c[2], s[2], laz; //c是计数；s是二倍序数和
} t[mn << 2];
#define lfs r << 1
#define rfs r << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void pushup(ll r)
{
    for (ll i = 0; i < 2; ++i)
    {
        t[r].c[i] = t[lfs].c[i] + t[rfs].c[i];
        t[r].s[i] = t[lfs].s[i] + t[rfs].s[i];
    }
}
void rev(ll r)
{
    swap(t[r].c[0], t[r].c[1]);
    swap(t[r].s[0], t[r].s[1]);
}
void pushdown(ll r)
{
    if (!t[r].laz)
    {
        return;
    }
    t[r].laz = 0;
    t[lfs].laz ^= 1, t[rfs].laz ^= 1;
    rev(lfs), rev(rfs);
}
char s[mn];
void build(ll r, ll lf, ll rf)
{
    //多次建树需要初始化
    t[r].c[0] = t[r].c[1] = t[r].s[0] = t[r].s[1] = t[r].laz = 0;
    if (lf == rf)
    {
        ll i = s[lf] - '0';
        ++t[r].c[i], t[r].s[i] += lf * 2;
        return;
    }
    mkcf;
    build(lfs, lf, cf), build(rfs, cf + 1, rf);
    pushup(r);
}
ll n, q, lc, rc, ty, lb, rb, k, r1, r2;
void update(ll r, ll lf, ll rf)
{
    if (lc <= lf && rf <= rc)
    {
        rev(r);
        t[r].laz ^= 1;
        return;
    }
    pushdown(r);
    mkcf;
    if (lc <= cf)
        update(lfs, lf, cf);
    if (cf < rc)
        update(rfs, cf + 1, rf);
    pushup(r);
}
ll query(ll r, ll lf, ll rf)
{
    if (lc > rc)
        return 0;
    if (lc <= lf && rf <= rc)
        return t[r].s[ty];
    pushdown(r);
    mkcf;
    ll res = 0;
    if (lc <= cf)
        res += query(lfs, lf, cf);
    if (cf < rc)
        res += query(rfs, cf + 1, rf);
    return res;
}

signed main()
{
    while (scanf("%lld%lld", &n, &q) != EOF)
    {
        scanf("%s", s + 1);
        build(1, 1, n);
        while (q--)
        {
            sc(lb), sc(rb), lc = lb, rc = rb;
            update(1, 1, n);
            k = t[1].c[1];
            if (k == 0)
            {
                printf("0\n");
                continue;
            }
            lc = k, rc = n, ty = 1, r1 = query(1, 1, n);
            lc = 1, rc = k - 1, ty = 0, r2 = query(1, 1, n);
            printf("%lld\n", (r1 - r2 - k) % mod);
        }
    }
    return 0;
}
```



###### 降雨量

> 定义x年的降雨量是自y年以来最多的，即在区间(y,x]内最大值点为x(而不是单调递增)，现有n个升序年份及其降雨量(年份可能残缺)，有m组询问(y,x)，判断命题正确与否，输出true,false或maybe

先二分找出第一个不小于x*x*的位置，和y的位置，不妨假设为st和ed，然后判断边界的年份是否相等，并查询出st+1到ed-1的最大值（因为要取出中间一段的最大值，用其和两端比较，注意判断左端点年份不确定时要查询st到ed的最大值）。

先判false

1、当右端点年份确定，且中间年份最大降雨量大于等于右端点降雨量

2、当左端点年份确定，且中间年份最大降雨量大于等于左端点降雨量

3、当左右端点年份都确定，且左端点降雨量小于等于右端点降雨量

再判maybe

1、当左右端点之差不等于左右端点年份之差（等价于年份不连续，也就是我前面所说的更好的判断区间连续的方法）

2、左端点年份不确定

3、右端点年份不确定

（因为已经切掉false的情况了，那么剩下的情况中可以直接照上面的判断！）

最后判断true;若上面情况都不满足，那么肯定是true

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
ll n, m, num[MAXN], ls[MAXN], rs[MAXN], yr[MAXN], co[MAXN];
bool f[MAXN];
struct node { ll ans, f; };
inline void pushup(ll rt)
{
	if (rs[rt << 1] + 1 == ls[rt << 1 | 1])
		f[rt] = f[rt << 1] & f[rt << 1 | 1];
	rs[rt] = rs[rt << 1 | 1];
	ls[rt] = ls[rt << 1];
	num[rt] = max(num[rt << 1], num[rt << 1 | 1]);
}
void build(ll lf, ll rf, ll rt)
{
	if (lf == rf)
	{
		rs[rt] = ls[rt] = yr[lf];
		num[rt] = co[lf];
		f[rt] = true;
		return;
	}
	ll cf = (lf + rf) >> 1;
	build(lf, cf, rt << 1);
	build(cf + 1, rf, rt << 1 | 1);
	pushup(rt);
}

node query(ll l, ll r, ll lf, ll rf, ll rt)
{
	if (l <= lf && r >= rf)
	{
		return { num[rt],f[rt] };
	}
	ll cf = (lf + rf) >> 1;
	node tmp = { 0,1 };
	if (l <= cf)
	{
		node x = query(l, r, lf, cf, rt << 1);
		tmp = { max(tmp.ans,x.ans),tmp.f & x.f };
	}
	if (r > cf)
	{
		node x = query(l, r, cf + 1, rf, rt << 1 | 1);
		tmp = { max(tmp.ans,x.ans),tmp.f & x.f };
	}
	return tmp;
}

signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d%d", &yr[i], &co[i]);
	build(1, n, 1);
	for (scanf("%d", &m); m; m--)
	{
		ll x, y;
		scanf("%d%d", &x, &y);
		if (x >= y)
		{
			printf("false\n");
			continue;
		}
		ll st = lower_bound(yr + 1, yr + 1 + n, x) - yr;
		ll ed = lower_bound(yr + 1, yr + 1 + n, y) - yr;
		ll op = 0;
		bool flf = yr[st] == x, frf = yr[ed] == y;
		if (!flf) --st;
		if (st + 1 <= ed - 1) op = query(st + 1, ed - 1, 1, n, 1).ans;
		if (op >= co[ed] && frf || co[st] < co[ed] && flf && frf || 
			op >= co[st] && flf) printf("false\n");
		else if (ed - st != yr[ed] - yr[st] || !flf || !frf) printf("maybe\n");
		else printf("true\n");
	}
	return 0;
}
```

###### 相同物品

> (oj)$n$个柜子(编号从1开始)，每个柜子一开始放了一个编号为$a_i$的物品。维护下面的操作：
>
> - `1 x` 取走第$x$个柜子的物品(保证此时存在物品)
> - `2 l r` 判断$[l,r]$内的未被取走的物品是否有两个编号相同
>
> $1\le n,q\le 5\times10^5,1\le a_i\le10^6,1\le x,l\le r\le n$

思路见代码注释：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define sc(x) scanf("%d", &x)
#define mn 500010
ll n, q, a[mn], v, i;
// 维护编号为v的双向链表
ll index_before[mn]; //第i个柜子的编号上一次出现的下标 即 链表prev
ll last_pos[mn];     //v最后一次出现的下标是last_pos[v] 即链表v的尾部指针
ll index_after[mn];  //第i个柜子的编号下一次出现的下标 即 链表next

//区间[lc,rc]内不重复的充要条件是index_before[i]或index_after[i]均不在这个区间内
//任取其一判断即可，这里取index_before[i]
//合并物品，构造线段树，每个节点维护的区间代表这个区间内的编号最近会在上一次重复的下标
//只需要对区间内每个index_before取最值；显然max操作可以维护线段树
ll t[mn << 2], lc, rc, res, cmd, pos;
#define lfs p << 1
#define rfs p << 1 | 1
#define mkcf ll cf = (lf + rf) >> 1
void build(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = index_before[lf];
        return;
    }
    mkcf;
    build(lf, cf, lfs);
    build(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}
void query(ll lf, ll rf, ll p)
{
    if (lc <= lf && rf <= rc)
    {
        res = max(res, t[p]);
        return;
    }
    mkcf;
    if (cf >= lc)
        query(lf, cf, lfs);
    if (cf < rc)
        query(cf + 1, rf, rfs);
}
void fix(ll lf, ll rf, ll p)
{
    if (lf == rf)
    {
        t[p] = v;
        return;
    }
    mkcf;
    if (cf >= pos)
        fix(lf, cf, lfs);
    else
        fix(cf + 1, rf, rfs);
    t[p] = max(t[lfs], t[rfs]);
}

signed main()
{
    sc(n), sc(q);
    for (ll i = 1; i <= n; ++i)
    {
        sc(v);
        //下面三行代码实际上在维护编号为v的双向链表
        index_before[i] = last_pos[v];
        index_after[last_pos[v]] = i;
        last_pos[v] = i;
        a[i] = v;
    }
    build(1, n, 1); //不build见祖宗
    while (q--)
    {
        sc(cmd);
        if (cmd == 2)
        {
            sc(lc), sc(rc), res = 0;
            query(1, n, 1);
            printf("%d\n", res >= lc);
        }
        else
        {
            sc(i);
            //双向链表删除节点
            lc = index_before[i], rc = index_after[i];
            if (lc)
                index_after[lc] = rc;
            if (rc)
                index_before[rc] = lc;

            //线段树修改
            //编号为0的双向链表不计重复，均头结点指向0
            pos = i, v = 0, fix(1, n, 1);
            //双向链表的后继节点指向更新 对线段树生效
            if (rc)
                pos = rc, v = lc, fix(1, n, 1);
        }
    }
    return 0;
}
```





### 树状数组

> 大纲分类时放在此处是为了跟线段树作对比，但实质上树状数组的内部实现用数组，是线性结构。~~虽然线段树等二叉树也可以用数组实现。~~

作用：区间修改和查询(如区间和)。结构本质与线段树相同，但时间复杂度和空间复杂度都比线段树低。

从1开始。

#### 实现

##### lowbit

返回一个二进制数从左往右数去掉第二个(若有)及以上的所有1的值，如：

> 0100(2) = 0100(2)
>
> 1010(2) = 0010(2)
>
> 1111(2) = 0001(2)

位运算代码：

```c++
inline int lowbit(int k){return k & -k;}
```

##### 单点修改

```c++
inline void add(int x,int k)
{
    while(x<=n)
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}
```

只加类可以简化为：

```c++
for (ll i = x; i <= n; i += lowbit(i)) a[i] += y;
```

##### 区间查询

```c++
inline int sum(int x)//1到x
{
    int ans=0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
inline int sump(int l, int r) {return sum(r)-sum(l-1);}
```

同理可以用for简化sum函数。

#### 使用示例

###### 前n项和查询和单点修改

```c++
#include <bits/stdc++.h>
#define MAXN 500002
using namespace std;
typedef long long ll;
int n,m,c,x;
ll a[MAXN],k;
inline int lowbit(int &k){return k & -k;}
inline void addsg(int x, ll &v)
{
    while(x<=n)
    {
        a[x]+=v;
        x+=lowbit(x);
    }
}
inline ll sumo(int x)
{
    ll ans = 0LL;
    while(x!=0)
    {
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}
inline ll sump(int &l, int r) {return sumo(r)-sumo(l-1);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        addsg(i,k);
    }
    while(m--)
    {
        scanf("%d%d%lld",&c,&x,&k);
        if(c==1)
        {
            addsg(x,k);
        }
        else
        {
            printf("%lld\n", sump(x,k));
        }
    }
    return 0;
}
```

###### 区间修改和单点查询

使用差分处理原数组，即可原样操作

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500002
typedef long long ll;
inline int lowbit(int &x)
{
    return x & -x;
}
ll t[MAXN],bf,no,k;
int n,m,c,x,y;
inline void add(int x, ll d)
{
    while(x<=n)
    {
        t[x]+=d;
        x+=lowbit(x);
    }
}
ll ask(int x)
{
    ll r=0LL;
    while(x)
    {
        r+=t[x];
        x-=lowbit(x);
    }
    return r;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&no);
        add(i,no-bf);
        bf=no;
    }
    while(m--)
    {
        scanf("%d%d",&c,&x);
        if(c==1)
        {
            scanf("%d%lld",&y,&k);
            add(x,k);
            add(y+1,-k);//差分操作，重点
        }
        else
        {
            printf("%lld\n",ask(x));
        }
    }
    return 0;
}
```

###### 静态区间最小值

```c++
#include <bits/stdc++.h>
//#pragma warning(disable:6031)
#define MAXN 100002
const int BIG = 0x7fffffff;
using namespace std;
int tr[MAXN], n, m, lf, rf, a[MAXN];
inline int lowbit(int& k)
{
	return k & -k;
}
inline void add(int x, int& k)
{
	while (x <= n)
	{
		if (k < tr[x]) tr[x] = k;//这两行换成min(tr[x],k)也可
		else return;//但是那样的话会慢些
		x += lowbit(x);
	}
}
inline int query(int lf, int rf)
{
	int drt = rf, res = BIG;
	while (drt >= lf)
	{
		if (drt - lowbit(drt) > lf)
		{
			res = min(res, tr[drt]);
			drt -= lowbit(drt);
		}
		else
		{
			res = min(res, a[drt]);
			--drt;
		}
	}
	return res;
}
signed main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)//不能在下面那个for
	{
		tr[i] = BIG;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	while (m--)
	{
		scanf("%d%d", &lf, &rf);
		printf("%d ", query(lf, rf));
	}
	return 0;
}
```

###### 单点修改和区间最大值

> 单点修改把当前值与输入值取max  (p1531)

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 200002
ll tr[MAXN], a[MAXN], n, m, lf, rf, ans, drt;
inline ll lowbit(ll& k) { return k & -k; }
char c;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, n)
	{
		cin >> a[i];
		for (ll j = i; j <= n; j += lowbit(j)) tr[j] = max(tr[j], a[i]);
	}
	while (m--)
	{
		cin >> c >> lf >> rf;
		if (c == 'Q')
		{
			ans = 0;
			while (rf>=lf)
			{
				while (rf - lowbit(rf) >= lf)
				{
					ans = max(ans, tr[rf]);
					rf -= lowbit(rf);
				}
				ans = max(ans, a[rf]);
				--rf;
			}
			cout << ans << endl;
		}
		else
		{
			a[lf] = max(a[lf], rf);
			for (ll j = lf; j <= n; j += lowbit(j)) tr[j] = max(tr[j], rf);
		}
	}
	return 0;
}
```

###### 动态中位数

> 输出一个数组的前1,3,5...项的中位数

注：本题还可以用双优先队列、二分+vector两种方法实现。

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,tot;
const int maxn=1e5+10;
int bit[maxn];
int a[maxn],b[maxn];

inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int pos,int x)
{
	for(int i=pos;i<=tot;i+=lowbit(i))bit[i]+=x;
}
inline int find_kth(int k)
{
	int ans=0,now=0;				//这里主要解释一下这个的原理 ans就是答案，now是比当前找到的数的小的数字的个数。 
	for(int i=20;i>=0;i--)			//2^20可以说很大了，满足我们的需求了，我们按照20倍增就可以 
	{
		ans+=(1<<i);			//先让答案加上去，试试 
		if(ans>tot||now+bit[ans]>=k)ans-=(1<<i);//如果超了总体的最大值（防止数组越界），或者是 超过了k个，就退回去，这里注意是大于等于，因为要考虑有重复元素，所以我们找的其实是一个满足小于他的个数小于k的最大数。。（可能不好理解，跑两遍样例就行了） 
		else now+=bit[ans];//能加就加上，这里不用怕加到了原来的数，因为树状数组的结构使这个新倍增出来的数就是多出来的那一条枝 
	}
	return ans+1;//然后加上1就是答案啦 
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[++tot]);		//读个入 
		b[tot]=a[tot];
	}
	sort(a+1,a+1+n);				//排个序 
	tot=unique(a+1,a+1+tot)-a-1;	//去个重 
	for(int i=1;i<=n;i++)b[i]=lower_bound(a+1,a+1+tot,b[i])-a;//离散化一下 
	for(int i=1;i<=n;i++)
	{
		add(b[i],1);			//动态加点 
		if(i&1)printf("%d\n",a[find_kth((i+1)>>1)]);//查kth 
	}
	return 0;
}
```

###### MooFestG

> 给定n头牛(v听力,x坐标)，x范围为[1,20000]，牛两两沟通，发出声音为max(v1,v2)*|x1-x2|，求声音和

先按音量升序快排，然后遍历，那么每次必然会于前面所有遍历过的牛沟通，且max(v,vi)=vi，**解决了max的问题**；之后可以**拆绝对值分类讨论**，求解出：对于每次遍历，新增加的音量为：
$$
v_i\times(n_{已遍历牛\&x<x_i}\times x_i-\sum_{已遍历牛\&x<x_i} x)\\+v_i\times(\sum_{已遍历牛\&x>x_i} x-n_{已遍历牛\&x>x_i}\times x_i)
$$
用一个树状数组维护坐标轴1~x 上已出现牛数，再用一个维护1~x 上出现的牛的坐标和

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 20002
struct node
{
	ll v, x;
};
inline bool cmp(const node& a, const node& b) { return a.v < b.v; }
ll cn[MAXN], cv[MAXN], n, ans, j, z;
node m[MAXN];
inline void add(ll* tr, ll p, ll k)
{
	for (ll i = p; i <= z; i += i & -i) tr[i] += k;
}
inline ll sea(ll* tr, ll p)
{
	ll res = 0;
	for (ll i = p; i; i -= i & -i) res += tr[i];
	return res;
}
inline ll seap(ll* tr, ll lf, ll rf) { return sea(tr, rf) - sea(tr, lf - 1); }
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld%lld", &m[i].v, &m[i].x), z = max(z, m[i].x);
	sort(m + 1, m + 1 + n, cmp);
	repe(i, 1, n)
	{
		j = m[i].x;
		ans += m[i].v * (j * (sea(cn, j - 1)
			- seap(cn, j + 1, z)) - sea(cv, j - 1) + seap(cv, j + 1, z));
		add(cn, j, 1);
		add(cv, j, j);
	}
	printf("%lld", ans);
	return 0;
}
```

> 此题也可以用分治法

###### 配对统计

> 对配对$(x,y)$，对所有$i\in[1,n]-\{x\}$，满足$|a_x-a_y|\le|a_x-a_i|$，则$(x,y)$是好的配对；有$n$个数，$m$组询问$l,r$，$r_i$代表第$i$次询问的好的配对数，求$\sum_{i=1}^mr_i\times i$。
> 数据保证所有n个数互不相等。

首先排序，由于数不相等，排序后可以拆绝对值，好的配对一定是排序后相邻的两个数。

$(a_2,a_1)$和$(a_n,a_{n-1})$一定是好的配对。

令$vp=a_i-a_{i-1},vq=a_{i+1}-a_i$，若$vp=vq$则它们都是好的配对，否则差值较小的那对是好的配对。易证故略。

至此已经找出了$[1,n]$内所有好的配对，而查询时若干子区间。可以对查询排序，然后倒序查询，查询时动态更新树状数组，即可求得答案。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 300002
struct node { ll x, id; } a[MAXN << 1], mix[MAXN << 1];
struct rng { ll lf, rf, id; } b[MAXN << 1];
ll n, m, lf, rf, c[MAXN << 1], ans[MAXN << 1], h, res;
inline bool cmp(const node& x, const node& y) { return x.x < y.x; }
inline bool cmq(const rng& x, const rng& y)
{
	return x.lf != y.lf ? x.lf < y.lf : x.rf < y.rf;
}
inline void add(node x, node y)
{
	mix[++h].x = min(x.id, y.id);
	mix[h].id = max(x.id, y.id);
}
inline ll lowbit(const ll& x) { return x & -x; }
inline void addsg(ll no, ll k)
{
	while (no <= n) c[no] += k, no += lowbit(no);
}
inline ll query(ll no)
{
	ll resw = 0;
	while (no) resw += c[no], no -= lowbit(no);
	return resw;
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, n) scanf("%lld", &a[i].x), a[i].id = i;
	sort(a + 1, a + 1 + n, cmp);
	add(a[2], a[1]);
	add(a[n], a[n - 1]);
	rep(i, 2, n)
	{
		ll vp = abs(a[i].x - a[i - 1].x);
		ll vn = abs(a[i + 1].x - a[i].x);
		if (vp == vn) add(a[i], a[i - 1]), add(a[i + 1], a[i]);
		else if (vp < vn) add(a[i], a[i - 1]);
		else add(a[i + 1], a[i]);
	}
	sort(mix + 1, mix + 1 + h, cmp);
	repe(i, 1, m) scanf("%lld%lld", &b[i].lf, &b[i].rf), b[i].id = i;
	sort(b + 1, b + 1 + m, cmq);
	ll no = h;
	rede(i, m, 1)
	{
		while (mix[no].x >= b[i].lf) addsg(mix[no].id, 1), --no;
		ans[b[i].id] = query(b[i].rf);
	}
	repe(i, 1, m) res += i * ans[i];
	printf("%lld\n", res);
	return 0;
}
```





### 并查集

有关系的点连成树；所有树的集合是森林，在这里为DisJointSet

#### 极简版

```c++
int fa[MAXN];//记得初始化
int finds(int k)
{
    if(k!=fa[k]) return fa[k]=finds(fa[k]);
    return k;
}
void unite(int u, int v)
{
    fa[finds(u)]=finds(v);
}
```

#### 简化版

> 不要用传引用盲目优化，否则可能出事

```c++
class DisJointSet//简化版
{
public:
    vector<int> p;
    int len;//不连通个数
    DisJointSet(int size)
    {
        p.resize(size+1);//从1计算
        for(int i=1;i<=size;i++) p[i]=i;
        len = size;
    }
    bool same(int x, int y)//当不需要判断时可以省略，非必要
    {
        return finds(x)==finds(y);
    }
    void unite(int x, int y)
    {
        int fx = finds(x), fy=finds(y);
        if(fx!=fy) len--;
        link(fx,fy);
    }
    int finds(int x)
    {
        while(x!=p[x]) x=p[x];
        return x;
    }
    void link(int x, int y)
    {
        p[x]=y;
    }
};
```

#### 树高版

```c++
class DisJointSet
{
public:
    vector<int> rank, p;
    DisJointSet(){}
    DisJointSet(int size)
    {
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i=0;i<size;i++) makeSet(i);
    }
    void makeSet(int x)
    {
        p[x] = x;//根节点序号
        rank[x] = 0;//高度
    }
    bool same(int x, int y)//同根节点
    {
        return findSet(x) == findSet(y);
    }
    void unite(int x, int y)
    {
        link(findSet(x),findSet(y));
    }
    void link(int x, int y)
    {
        if(rank[x]>rank[y])
        {
            p[y]=x;
        }
        else
        {
            p[x]=y;
            if(rank[x]==rank[y]) rank[y]++;
        }
    }
    int findSet(int x)
    {
        if(x!=p[x]) p[x] = findSet(p[x]);//路径压缩
        return p[x];
    }
};
```

初始化获得size个孤立点，从0计数

#### 添加关系

```c++
ds.unite(a,b); //a,b是两个点
```

#### 查询两个点是否互质

```c++
if(ds.same(a,b))
```

#### 查找互质总数

```c++
for(int i=0;i<m;i++)//方法1(eid)，m是size
{
    team.insert(ds.findSet(i));//team是set
}
n=team.size();//n为所求
```

```c++
int ans=0//方法2：每个互质子森林只有一个节点其祖先为自身
for(int i=0;i<n;i++)
{
    if(i==dj.p[i]) ans++;
}
```

```c++
//方法3
/*首先确立长度为ans=rf-lf+1
每次进行合并操作时判定(finds!=finds才合并)，且ans--
直接输出ans*/
```



#### 循环写法

例题：洛谷3367，且简化了树的合并和抹去了rank(因为题目不要求算)

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,z,x,y,fa[10005];//fa[i]是第i号节点的祖先
inline int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    //让x和x的父亲变成他的父亲的父亲
    //直到找到祖先才结束循环(x==fa[x])就意味着找到爹了
    return x;
}
//循环版找爹函数
/*
//再附上递归版本的找爹函数
inline int find(int x) 
{
    if (x==fa[x]) return x;
    //不停的递归查找
    return fa[x]=find(fa[x]);
    //路径压缩，可以缩短时间
}
*/
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
    {
        fa[i]=i;
        //并查集的初始化
    }
    while(m--)
    {
        cin>>z>>x>>y;
        int a=find(x),b=find(y);
        //ab分别去找自己的爹
        if(z==1)
        {
            fa[a]=b;
            //并查集的合并操作，及将x点祖先的爹记为y点的祖先
        }
        if(z==2)
        {
            if(a==b) 
            {
                puts("Y");
                //爹一样就说明X与Y是在同一集合内，输出Y
            }
            else 
            {
                puts("N");
                //否则就说明X与Y是在同一集合内，输出N
            }
        } 
    }
    return 0;
}
```

#### 种类并查集

基本思路是有几种关系类别构造多少倍长的并查集，对于每个元素，使用它自身i和它的匿名对立者i+n，每次建立对立关系时将匿名对立者与第二人合并。但最终只查找i~n。

##### 例题

###### 敌友

> 有n个人m条关系，E a b代表a和b是敌人，F a b代表a和b是朋友；敌人的敌人是朋友，朋友的朋友是朋友；朋友间一定会结成同一帮派，求帮派数

使用反集。解法二是照搬二分图。

```c++
#include<bits/stdc++.h>
using namespace std;
int s,n,m,a,b,f[2500];
char ch;
int find(int x){
    if(f[x]!=x)f[x]=find(f[x]);//查找+路径压缩，如果没有祖先就回溯
    return f[x];
}
int main(){
    cin>>n>>m;//本题scanf洛谷会死
    for(int i=1;i<=2*n;i++){
        f[i]=i;//初始化，千万不能漏
    }
    for(int i=1;i<=m;i++){
        cin>>ch>>a>>b;
        if(ch=='F'){
            f[find(a)]=find(b);//合并
        }else{
            f[find(a+n)]=find(b);
            f[find(b+n)]=find(a);//反集合并
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==i)s++;
    }
    cout<<s;//祖先数就是团伙数
}
```

###### 食物链

> 存在食物环A->B->C->A，有n种动物，m条判断。判断类型为1 i j表示i,j同属A/B/C大类,2 i j表示i->j。先出现的判断在不产生矛盾的情况下变成真理。求m条判断中谬论数。(输入n,m,依次输入判断)

构建三倍并查集，其中i是自身，i+n是匿名猎物，i+2n是匿名天敌

```c++
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:6031)
#define MAXN 150002
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ANS {++ans;continue;}//printf("[%d %d %d]\n",cmd,x,y);
int fa[MAXN], n, k, ans, cmd, x, y, n3;
inline int finds(int k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
signed main()
{
	scanf("%d%d", &n, &k);
	n3 = n + n + n;
	rep(i, 1, n3) fa[i] = i;
	while (k--)
	{
		scanf("%d%d%d", &cmd, &x, &y);
		if (x > n || y > n) ANS;
		if (cmd == 1)
		{
			if (finds(x + n) == finds(y) || finds(x) == finds(y + n)) ANS;//或后者改为x+2n与y
			fa[finds(x)] = finds(y);
			fa[finds(x + n)] = finds(y + n);
			fa[finds(x + n + n)] = finds(y + n + n);
		}
		else
		{
			if (finds(x) == finds(y) || finds(x) == finds(y + n)) ANS;//如果同类相食或反向捕食(y+n是天敌)，是谬论
			fa[finds(x + n)] = finds(y);
			fa[finds(x + n + n)] = finds(y + n);
			fa[finds(x)] = finds(y + n + n);
		}
	}
	printf("%d", ans);
	return 0;
}
```

#### 加权并查集

##### 例题

#### 例题

##### 家族祖先

> 输入#string表示他是父亲，接下来若干+string都是他的儿子，输入?string询问他最早的祖先，输入$结束程序

将互质集的int改为string，直接套用即可，而不是新增一系列对接映射让string转int。

```c++
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define MAXN 50002
using namespace std;
unordered_map<string, string> p;
char ch;
string nam, fnam;
string finds(string & x)
{
	while (x != p[x]) x = p[x] = p[p[x]];
	return x;
}
signed main()
{
	while (1)
	{
		cin >> ch;
		if (ch == '$') break;
		cin >> nam;
		if (ch == '#')
		{
			fnam = nam;
			if (p[nam] == "") p[nam] = nam;
		}
		else if (ch == '+')
		{
			p[nam] = fnam;
		}
		else
		{
			cout << nam << ' ' << finds(nam) << endl;
		}
	}
	return 0;
}
```

##### 七段码

> (蓝桥)七个数字管(合成8字)，至少有一个发光，且发光区域相连，求一共可以表示多少种字符？

首先注意到不能单纯检测只要没有孤立点就算是，因为可能会有孤立块(左上+右下)。这题的解法是并查集。

```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> v[10];
bool se[10];
int fa[10];
int ans;
int finds(int k)
{
	while(fa[k]!=k) k=fa[k]=fa[fa[k]];
	return k;
}
#define prt for(int j=1;j<=7;++j){if(se[j]) printf("%c ",'a'-1+j);}printf(":%d %d\n",i,ans);
signed main()
{
	v[1].push_back(2);
	v[1].push_back(6);
	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(7);
	v[3].push_back(2);
	v[3].push_back(4);
	v[3].push_back(7);
	v[4].push_back(3);
	v[4].push_back(5);
	v[5].push_back(4);
	v[5].push_back(6);
	v[5].push_back(7);
	v[6].push_back(5);
	v[6].push_back(1);
	v[6].push_back(7);
	v[7].push_back(2);
	v[7].push_back(3);
	v[7].push_back(5);
	v[7].push_back(6);
	for(int i=0;i<128;++i)
	{
		int c=0,k=i;
		for(int j=1;j<=7;++j)
		{
			if(k&1) se[j]=true,++c;
			else se[j]=false;
			k>>=1;
		}
		bool die=false;
		if(c==1)//可以简化掉
		{
			++ans;
			//prt
			continue;
		}
		for(int j=1;j<=7;++j) fa[j]=j;
		for(int j=1;j<=7;++j)
		{
			if(!se[j]) continue;
			int len=v[j].size();
			for(int k=0;k<len;++k)
			{
				if(se[v[j][k]])
				{
					fa[finds(v[j][k])]=finds(j);
				}
			}
		}
		set<int> s;
		for(int j=1;j<=7;++j)
		{
			if(se[j])
			{
				s.insert(fa[finds(j)]);//不finds会死
			}
		}
		if(s.size()==1) ++ans;
		//prt
	}
	printf("%d",ans);
	return 0;
}
```

##### 家庭房产

> (天梯)输入n($1\le n\le1000$)个房产信息，先输入自己、父母的独有四位数编号(如丧考妣则-1)，然后输入后代数k($0\le k\le 5$)，然后输入k个后代编号，然后输入这个人有的房产数和房产总面积。
>
> 首先输出家庭个数(所有有亲属关系的人都属于同一个家庭)，然后输出家庭信息：家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积。其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。

一定要注意先输出家庭个数，不要忘记。然后就是并查集裸题了，注意可以直接把根节点编号设置为最小编号，也可以不设置，而在后续处理，两种做法都有实际价值。实际上前者更加方便。

(个人解法)最小编号根节点

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 10010
int fa[mn],n,id,ids,hn[mn],hw[mn],mem[mn],vis[mn];
int finds(int k)
{
    while(fa[k]!=k) k=fa[k]=fa[fa[k]];
    return k;
}
vector<int> gr;
inline bool cmp(int x, int y)
{
    double xa=1.0*hw[x]/mem[x];
    double ya=1.0*hw[y]/mem[y];
    if(abs(xa-ya)>1e-3) return xa>ya;
    return x<y;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=10000;++i) fa[i]=i,mem[i]=1;
    while(n--)
    {
        vector<int> v;
        int ffa,tem,a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b==-1) b=a;
        if(c==-1) c=a;
        ffa=min(finds(a),min(finds(b),finds(c)));
        vis[a]=vis[b]=vis[c]=1;
        int m;
        scanf("%d",&m);
        vector<int> mmp;
        for(int i=0;i<m;++i)
        {
            scanf("%d",&tem);
            mmp.push_back(tem);
            int tfa=fa[tem];
            ffa=min(ffa,finds(tem));
            vis[tem]=1;
        }
        fa[finds(a)]=fa[finds(b)]=fa[finds(c)]=ffa;
        for(int i=0;i<m;++i)
        {
            fa[finds(mmp[i])]=ffa;
        }
        int hhn,hhw;
        scanf("%d%d",&hhn,&hhw);
        hn[ffa]+=hhn;
        hw[ffa]+=hhw;
    }
    for(int i=0;i<=10000;++i)
    {
        if(!vis[i]) continue;
        int tar=finds(i);
        if(tar!=i)
        {
            hn[tar]+=hn[i];
            hw[tar]+=hw[i];
            mem[tar]++;
        }
        else
        {
            gr.push_back(i);
        }
    }
    sort(gr.begin(),gr.end(),cmp);
    printf("%d\n",gr.size());
    for(int i=0;i<gr.size();++i)
    {
        printf("%04d %d %.3lf %.3lf\n",gr[i], mem[gr[i]],
               1.0*hn[gr[i] ]/mem[gr[i] ],1.0*hw[gr[i] ]/mem[gr[i] ]  );
    }
    return 0;
}
```

(方法二)后续处理设置最小成员法

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 10010
#define md 10000
int fa[mn],n,id,ids,hn[mn],hw[mn],vis[mn];
int finds(int k)
{
    while(fa[k]!=k) k=fa[k]=fa[fa[k]];
    return k;
}
void fuck(int x, int y)
{
    fa[finds(x)]=finds(y);
}
void die(int a, int x)
{
    if(x!=-1)
    {
        fuck(a,x);
        vis[x]=1;
    }
}
struct dead
{
    int mi,mem;
    double an,aw;
    inline bool operator<(const dead& x)const
    {
        if(abs(aw-x.aw)>1e-3)
        {
            return aw>x.aw;
        }
        return mi<x.mi;
    }
};
set<int> beach;
map<int,int> fx,fm,fn,fw;
vector<dead> r;
signed main()
{
    for(int i=0;i<md;++i) fa[i]=i;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        vis[a]=1;
        die(a,b);
        die(a,c);
        int m,tmp;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&tmp);
            die(a,tmp);
        }
        scanf("%d%d",&hn[a],&hw[a]);
    }
    for(int i=0;i<md;++i)
    {
        if(!vis[i]) continue;
        int x=finds(i);
        beach.insert(x);
        if(fx.find(x)==fx.end()||fx[x]>i)
        {
            fx[x]=i;
        }
        ++fm[x];
        fn[x]+=hn[i];
        fw[x]+=hw[i];
    }
    for(auto i:beach)
    {
        r.push_back({fx[i],fm[i],1.0*fn[i]/fm[i],1.0*fw[i]/fm[i]});
    }
    sort(r.begin(),r.end());
    printf("%d\n",r.size());
    for(int i=0;i<r.size();++i)
    {
        printf("%04d %d %.3lf %.3lf\n",r[i].mi,r[i].mem,r[i].an,r[i].aw);
    }
    return 0;
}
```

##### 修改数组

> (蓝桥)给定长为n的数组，依次检查每个数，如果在其之前出现过这个数，就给它加一，直到它不再出现过，输出最终的该数组。
>
> ($1\le n\le10^5,1\le a_i\le10^6$)

该题并不可以用哈希表、线段树/树状数组、ST表来解决。但是可以使用并查集实现，关键点在于每次插入一个数将其父节点指向比它大1的数的父节点，这样可以保证并查集压缩路径时始终保证父节点是最大的，无需重写树高版并查集。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 1000000
int fa[mn+2],n,v,r;
int finds(int k)
{
    while(k!=fa[k]) k=fa[k]=fa[fa[k]];
    return k;
}
signed main()
{
    for(int i=1;i<=mn;++i) fa[i]=i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&v);
        printf("%d ",r=finds(v));
        fa[r]=finds(r+1);
    }
    return 0;
}
```

##### 红色警报

> (天梯)有$n(0\le n\le500)$个城市，有$m(0\le m\le5000)$条道路，不保证给出的通路没有重复。有$k$次攻占，每次攻占会使一个之前没攻占的城市沦陷。如果沦陷之后改变了国家的连通性，那么需要发出红色警报。注意：若该国本来就不完全连通，是分裂的k个区域，而失去一个城市并不改变其他城市之间的连通性，则不要发出警报。
>
> 对每个被攻占的城市，如果它会改变整个国家的连通性，则输出`Red Alert: City k is lost!`，其中`k`是该城市的编号；否则只输出`City k is lost.`即可。如果该国失去了最后一个城市，则增加一行输出`Game Over.`。

直接每次暴力重建并查集，并不会超时。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 502
#define mm 5002
typedef int ll;
ll n,m,k,u,v,e[mn][mm],es[mn],ori,fa[mn],dels,nw;
bool del[mn];
inline void adde(ll& u, ll& v)
{
    e[u][es[u]++]=v;
}
inline int finds(ll k)
{
    while(fa[k]!=k) k=fa[k]=fa[fa[k]];
    return k;
}
void initfa()
{
    for(ll i=0;i<n;++i) fa[i]=i;
}
inline void unite(ll u, ll v)
{
    fa[finds(u)]=finds(v);
}
int stat()
{
    ll r=0;
    for(ll i=0;i<n;++i) if(fa[finds(i)]==i) ++r;
    return r;
}
signed main()
{
    scanf("%d%d",&n,&m);
    initfa();
    while(m--)
    {
        scanf("%d%d",&u,&v);
        adde(u,v);
        adde(v,u);
        unite(u,v);
    }
    ori=stat();
    for(scanf("%d",&k);k;--k)
    {
        scanf("%d",&u);
        del[u]=true;
        initfa();
        for(ll i=0;i<n;++i) if(!del[i])
        {
            for(ll j=0;j<es[i];++j) if(!del[e[i][j]])
            {
                unite(e[i][j],i);
            }
        }
        nw=stat();
        if(nw>ori+1)
        {
            printf("Red Alert: City %d is lost!\n",u);
        }
        else
        {
            printf("City %d is lost.\n",u);
        }
        if(++dels>=n) printf("Game Over.\n");
        ori=nw;
    }
    return 0;
}

```

##### 社交集群

> (天梯)一个“社交集群”是指部分兴趣爱好相同的人的集合。你需要找出所有的社交集群。输入在第一行给出一个正整数 N（≤1000），为社交网络平台注册的所有用户的人数。于是这些人从 1 到 N 编号。随后 N 行，每行按以下格式给出一个人的兴趣爱好列表：
>
> *K* *i*: *h* *i*[1] *h* *i*[2] ... *h* *i*[*K* *i*]
>
> 其中*K* *i*(>0)是兴趣爱好的个数，*h* *i*[*j*]是第*j*个兴趣爱好的编号，为区间 [1, 1000] 内的整数。首先在一行中输出不同的社交集群的个数。随后第二行按非增序输出每个集群中的人数。数字间以一个空格分隔，行末不得有多余空格。

首先这题不能开set直接筛，因为这样已经分好的集群无法合并。其次这题不能直接并查兴趣$h$，不然就成了统计兴趣数目而不是人数。可以将输入数据按兴趣拆解成兴趣数个数组，存有这个兴趣的人。对每个数组跑一次并查集。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define re register
#define il inline
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;--i)
#define rede(i,a,b) for(re ll i=a;i>=b;--i)
#define big 0x7ffffffa
#define mn 1005
ll fa[mn],gn[mn];
vector<ll> v[mn];
il ll finds(ll k)
{
    while(k!=fa[k]) k=fa[k]=fa[fa[k]];
    return k;
}
signed main()
{
    re ll n,k,h,gs=1,h0,fx,fy;
    scanf("%d",&n);
    repe(i,1,n) fa[i]=i;
    repe(e,1,n)
    {
        scanf("%d:",&k);
        repe(j,1,k)
        {
            scanf("%d",&h);
            v[h].push_back(e);
        }
    }
    repe(i,1,1000)
    {
        h0=v[i].size();
        if(h0>1)
        {
            fx=finds(v[i][0]);
            rep(j,1,h0)
            {
                fa[finds(v[i][j])]=fx;
            }
        }
    }
    repe(i,1,n) ++gn[finds(i)];
    sort(gn+1,gn+1+n,greater<ll>());
    while(gn[gs]) ++gs;
    printf("%d\n%d",gs-1,gn[1]);
    rep(i,2,gs) printf(" %d",gn[i]);
    return 0;
}
```



##### 二分图

> 无向加权图，将点分成两部分以断开部分边，使大权边尽可能减少，求分割后最大边权。

此题拓展开来，可以解决朋友-敌人关系并查集的模板。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 20002
#define MAXM 100003
struct edge
{
	int u, v, w;
} e[MAXM];
inline bool cmp(edge &a, edge &b)
{
	return a.w > b.w;
}
int n, m, ui, vi, wi, fa[MAXN], en[MAXN];
inline int find(int k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
inline void unite(int x, int y)
{
	fa[find(x)] = find(y);
}
inline bool check(int x, int y)
{
	return find(x) == find(y);
}
signed main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e, e + m, cmp);
	for (int i = 0; i <= m; ++i)
	{
		if (check(e[i].u, e[i].v))
		{
			printf("%d",e[i].w);
			break;
		}
		if (!en[e[i].u]) en[e[i].u] = e[i].v;
		else unite(en[e[i].u], e[i].v);
		if (!en[e[i].v]) en[e[i].v] = e[i].u;
		else unite(en[e[i].v], e[i].u);
	}
	return 0;
}
```

##### 单调栈

用并查集实现区间最值查询。（输入m,d代表有m次操作），操作有A k表示末端加入值为(t+k)%d，Q k表示查询最后k个值的最大值存于t并输出。

```c++
#include <bits/stdc++.h>
//#pragma warning(disable:6031)
#define MAXN 200002
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<=b;++i)
ll m, d, fa[MAXN], v[MAXN], idx[MAXN], cnt, n, x, bf, aval[MAXN];
char c;
inline ll finds(ll& k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> d;
	while (m--)
	{
		cin >> c >> x;
		if (c == 'A')
		{
			(x += bf) %= d;
			v[++n] = x;
			fa[n] = n;
			while (x > aval[cnt] && cnt)
			{
				fa[idx[cnt]] = n;
				--cnt;
			}
			idx[++cnt] = n;
			aval[cnt] = x;
		}
		else
		{
			x = n - x + 1;
			bf = v[finds(x)];
			cout << bf << '\n';
		}
	}
	return 0;
}
```

## 图

#### 基本概念

graph，非线性数据结构，存在一对多，多对多关系

由**顶点**vertex(又名**节点**Node)的集合V和边edge的集合e组成，表示为二元组G=(V,E)，|V|表示顶点数，|E|表示边数。

若G每条边都有方向，称**有向图**，否则**无向图**。有向边也可以叫做**弧**(Arc)。有向边的起点(tail)和终点(head)也被称为端点(endpoint)。

与顶点u相连的边数称为顶点u的**度**(degree)。有向图里一个顶点出发的边的总数称为**入度**，指向一个顶点的边的总数称为**出度**。

边带权值的图称为**带权**(加权)**图**。权可以表示距离、关联强度、成本等属性信息。加权无向图两点之间只有一种权值，加权有向图可以有两个。

两个定点有边连接，称为两个顶点**相邻**(lin2, not ling2)(adjacent)。相邻顶点的序列是**路径**(path)。起点和终点重合的路径是**圈**(或**环**cycle)。若任意两个顶点u,v都存在从u到v的路径，称为**连通图**。删除之后会导致图失去连通性的边为**桥**(Bridge)    //或者说无向图若存在边(u,v)，则顶点u和v相邻.相邻顶点的序列为v0,v1,...,vn是路径。

无圈有向图为**有向无环图**(Directed Acyclic Graph,**DAG**)，无圈连接图是树。

对于两个图G1,G2，如果G2的顶点集合和边集合都是G1的顶点集合和边集合的子集，那么G2是G1的**子图**。

**途径**(walk)/**链**(chain)，点和边的交错序列，首尾是点(有时简写忽略边)。通常，边的数量(无权)/权和(加权)是途径的**长度**。**迹**(trail)是边互不相同的途径。**路径**(path)/**简单路径**(simple path)，除首尾点，其余点互不相同的迹。**回路**(circuit)是首尾点相同的迹。**环/圈**(cycle)/**简单回路/简单环**(simple circuit)是首尾点相同的路径。

两点连通/可达是两点间存在一条途径。连通图是任意两点连通的无向图，强联通是任意两点联通的有向图，弱连通是有向图转无向图后成为连通图的图。

连通块/**连通分量**(Connected Components)。对一个连通性未知的图G，其极大联通子图是G的连通分量。G的联通子图中，若包含G2的图只有G2，那么G2就是G的**极大联通子图**。如果某连通分量对任意两个顶点u,v都有从u出发能够到达v且从v出发能到达u，称**强连通分量**(Strongly Connected Components)，可以用DFS生成，该量可以解决给定加权有向图求以指定顶点为根的最小有向树问题。

**割点**(cut vertex/articulation point)，在无向连通图中，如果将割点点及所有连接该点的边去掉，图不再联通。

有流通过的有向图，各边设置了容量的为**流网络**。从起点流向终点最大流量问题为最大流问题。(Edmonds-Karp/Dinic算法)。对图G=(V,E)，若M为E的子集，M的任意两条边没有共通端点，则M为G的**匹配**，边数最多的匹配为**最大匹配**，可以用最大流算法求出。

最小路径覆盖就是在一个有向图中，找出最少的路径，使得这些路径经过了所有的点。最小路径覆盖分为**最小不相交路径覆盖**和**最小可相交路径覆盖**。最小不相交路径覆盖：每一条路径经过的顶点各不相同。最小可相交路径覆盖：每一条路径经过的顶点可以相同。

> 在元素值动态变化的数列，快速求出指定范围内最小元素，或所有元素之和，应该使用**线段树**(Segment tree)。

**仙人掌图**（cactus）是一种无向连通图，它的每条边最多只能出现在一个简单回路里面。从直观上说，可以把仙人掌图理解为允许存在回路的树。但是仙人掌图和树之间有个本质的不同，仙人掌图可以拥有多个支撑子图（spanning subgraph），而树的支撑子图只有一个（它自身）。

**支撑子图**（spanning subgraph）：支撑子图也是原图的子图，这种子图可以比原来少一些边，但是不能破坏图的连通性，也不能去除原来图上的任何顶点。“支撑”的概念类似于我们熟知的“最小支撑树”。仙人掌图的支撑子图数是不删边($1$)+删任意一个环的一条边+删任意两个环的各一条边+……。根据数学公式，即化简为$(1+c_1)(1+c_2)\dots$。



图主要以**邻接矩阵**(Adjacency Matrices)或**邻接表**(Adjacency List)表示，也可以使用**链式前向星**存储。

```c
邻接表表示中，V每个顶点都用一个表表示，总计|V|个表Adj[|V|]表示图。对顶点u，邻接表Adj[u]包含所有与(u,v1)相连的顶点v1(其中(u,v1)是集合E中的边)，即Adj[u]由G中所有与u相邻的顶点组成。
邻接矩阵是二维数组，i指向j则[i][j]为1，否则0；无向图相互指向，即呈右上左下对称形式。
链式前向星有待补充
```

邻接矩阵的优点：

- 通过M [u] [v] 直接引用边(u,v)，只需O(1)确定顶点u,v间关系
- 更改M [u] [v]就能完成边的添加和删除，简单高效O(1)

缺点：

- 消耗内存为顶点数平方，若边较少（**稀疏图**），浪费大量内存
- 只能记录u,v的一个关系，无法在有向加权图表示两种边关系

邻接表的优点：

- 内存空间与边数成正比

缺点：

- 设u的度为n，调查u与v的关系时，需要O(n)搜索邻接表。但大部分算法如DFS,BFS只需要对特定顶点的相邻顶点一次遍历即可，影响并不大
- 难以有效删除边



图的**遍历**：从某个顶点出发，按照某种方式访问所有顶点，每个顶点只访问一次。

**深度优先搜索**(Depth-First Search,DFS)

1. 从某个顶点V0出发，先访问V0
2. 访问V0第一个邻接点，以此为新顶点，访问它的所有邻接点，直到以它出发所有顶点均被访问，然后回溯到V0下一个未访问邻接点，重复之

**广度优先搜索**(Breadth-Frist Search, BFS)

1. 先访问V0
2. 依次访问V0各个未被访问邻接点
3. 依次访问邻接点的未被访问邻接点。如果VI在VK之前被访问，VI的邻接点在VK的邻接点之前被访问。重复之
4. 若仍有未访问顶点，随机取一个作为起始点，重复上述

树的先序遍历是BFS，层序遍历是DFS。

图的基本算法是**搜索**，即系统访问所有顶点或部分顶点的集合。广度优先搜索常用作求最短路径。

**生成树**(Spanning Tree)可以通过BFS或DFS获得，且结果不唯一。**最小生成树**(Minimun spanning tree,MST)是各边权值和最小的生成树。**最短路径问题**(Shortest Path Problem)是求顶点s,d之间各边权值总和最小的路径。**单源最短路径**(Single Source Shotest Path,SSSP)，在图G中，求给定顶点s到其他所有顶点之间的最短路径。**全点对间最短路径**(All Pairs Shortest Path,APSP)，在图G中，求每一对顶点之间最短路径。对于权值非负加权图G，若顶点s到所有顶点都存在路径，那么一定存在一棵以s为根，包含s到G所有顶点最短路径的生成树，即**最短路径生成树**(Shortest Path Spanning Tree)。

#### 链式前向星

> 实验表明链式前向星比邻接表快数(平均3)倍(不开O2加速，开则1~2倍)

常规写法：

```c++
struct edge
{
    int to,d,nx;//to是下一条边的节点,d是权,nx是同结点的下一条出边
} e[MAXE];//MAXE边的条数,区分于MAXN；无向图是两倍，即<<1
int hd[MAXN],cnt;//点的个数cnt,若点有权，加一个数组存
inline void adde(int u, int v, int w)//增加有向边,[可传引用]
{
    e[++cnt].d=w;//若边无权，可以把成员d删掉
    e[cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;//hd[u]是u结点的第一条出边
    //如果有必要，可以加一个.from成员，表示出发节点，显然.from=u
}
for(int i=hd[temp.p];i;i=e[i].nx)//遍历一般用e[i].to
//从1开始计数，即最小结点序号为1；否则遍历时i>=0为持续条件，或~i
```

对象写法：

```c++
struct edge//da ck 这个好像是从0存边的
{
	int u,v,w,next;
	edge(int U=0,int V=0,int W=0,int N=0):u(U),v(V),w(W),next(N){}
};edge e[MAXM<<1];
inline void add_edge(int u,int v,int w)
{
	e[++en]=edge(u,v,w,eh[u]);eh[u]=en;
}
```

快写宏模板

```c++
struct edge
{
	ll to, nx;
} e[MAXM];
ll hd[MAXN], cnt;
#define fore(x) for(ll i=hd[x];i;i=e[i].nx)
#define toi e[i].to
inline void adde(ll& x, ll& y)
{
	e[++cnt].nx = hd[x];
	e[cnt].to = y;
	hd[x] = cnt;
}
```

使用结构体简化：

```c++
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { hd[u],v,w };
	hd[u] = cnt;
}
```



#### DFS

下面两种方法复杂度是O(|V|^2)，不适用于规模较大的图。规模较大要用邻接表实现高速算法。

算法描述为：

- 将最初访问的顶点压栈
- 栈中有顶点时，循环下列操作：
  - 访问栈顶顶点u
  - 从u移动至v时，压栈v。若u不存在未访问点，弹栈u。

```c
//输出DFS并输出每个点的起始时间戳和终结时间戳
//输入结构为N:点下标 度 相邻点下标1 ...
#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n, M[N][N];
int color[N], d[N], f[N], tt;//tt是时间戳变量

void dfs_visit(int u)
{
    int v;
    color[u] = GRAY;
    d[u] = ++tt;//起始时间戳
    for(v=0;v<n;v++)
    {
        if(M[u][v]==0) continue;
        if(color[v] == WHITE) dfs_visit(v);
    }
    color[u] = BLACK;
    f[u] = ++tt;//终结时间戳
}

void dfs()
{
    int u;
    for(u=0;u<n;u++) color[u] = WHITE;
    tt=0;
    for(u=0;u<n;u++) if(color[u]==WHITE) dfs_visit(u);
    for(u=0;u<n;u++) printf("%d %d %d\n",u,d[u],f[u]);
}

int main()
{
    int u,v,k,i,j;
    scanf("%d", &n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) M[i][j] = 0;

    for(i=0;i<n;i++)
    {
        scanf("%d%d", &u, &k);
        //u--;
        for(j=0;j<k;j++)
        {
            scanf("%d", &v);
            //v--;
            M[u][v] = 1;
        }
    }
    dfs();
    return 0;
}
```

##### 例题

###### 公共可访问点数

对于n点m边有向图[可能有环]，从其中指定若干k点出发，求存在多少个点使得从k个指定点出发这些点均可到达。

> 错误解法：拓补排序，因为可能有环

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1002
#define MAXM 10002
#define rep(i,a,b) for(int i=a;i<=b;++i)
struct edge
{
    int to,nx;
} e[MAXM];
int hd[MAXN],cnt,n,m,k,ans,d[MAXN],ui,vi;
bool vis[MAXN];
inline void adde(int &u, int &v)
{
    e[++cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
vector<int> ks;
void dfs(int h)
{
    d[h]++;
    vis[h]=true;
    if(d[h]>=k) ans++;
    for(int i=hd[h];i;i=e[i].nx)
    {
        int toi=e[i].to;
        if(!vis[toi]) dfs(toi);
    }
}
signed main()
{
    scanf("%d%d%d",&k,&n,&m);
    rep(i,1,k)
    {
        scanf("%d",&ui);
        ks.push_back(ui);
    }
    rep(i,1,m)
    {
        scanf("%d%d",&ui,&vi);
        adde(ui,vi);
    }
    for(auto i:ks)
    {
        rep(j,1,n) vis[j]=false;
        dfs(i);
    }
    printf("%d",ans);
    return 0;
}
```

###### 最大可到达节点

> n点m边有向无权图，序号从1到n，求每个点可到达的最大编号的点。

建立反图，从大到小dfs，可得答案：

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define repe(i,a,b) for(int i=a;i<=b;++i)
struct edge
{
    int to,nx;
} e[MAXN];
int hd[MAXN],cnt,n,m,ans,ui,vi,res[MAXN];
bool vis[MAXN];
inline void adde(int &u, int &v)
{
    e[++cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
void dfs(int h, int &hi)
{
    if(vis[h]) return;
    vis[h]=true;
    res[h]=max(res[h],hi);
    for(int i=hd[h];i;i=e[i].nx) dfs(e[i].to,hi);
}
signed main()
{
    scanf("%d%d",&n,&m);
    repe(i,1,m)
    {
        scanf("%d%d",&ui,&vi);
        adde(vi,ui);
    }
    for(int i=n;i>=1;--i) dfs(i,i);
    repe(i,1,n) printf("%d ",res[i]);
    return 0;
}
```

###### 分考场

> (蓝桥)有n个考生，m对相互认识关系，相互认识的考生不能在同一考场，求最少设多少个考场？($n\le100$)

看到数据量很小，可以考虑DFS。

```c++
#include <bits/stdc++.h>
using namespace std;
int h[102],n,m,a,b,c[102][102],g[102][102],cn;
void dfs(int x, int ci)
{
	if(ci>=cn) return;//剪枝，如果还没分完，就已经大于等于分完的方案，不用继续了(不取等TLE)
	if(x>n)//已经分完了
	{
		cn=min(ci,cn);
		return;
	}
	if(ci)
	{
		for(int i=1;i<=ci;++i)
		{
			int j=0;
			while(c[i][j] && !g[x][c[i][j]]) ++j;
			if(!c[i][j])
			{
				c[i][j]=x;
				dfs(x+1,ci);
				c[i][j]=0;
			}
		}
	}
	c[ci+1][0]=x;
	dfs(x+1,ci+1);
	c[ci+1][0]=0;
}
signed main()
{
	for(scanf("%d%d",&n,&m);m;--m)
	{
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
	}
	cn=n;
	dfs(1,0);
	printf("%d",cn);
	return 0;
}
```

###### 作物杂交

> (蓝桥)有n种作物，成熟时间$T_i$，有m种作物已经有，有$k$对作物$a,b$可以杂交获得$c$，用时为$a,b$成熟时间的较大者。求要获得作物$t$最少需要多久。(输入$n,m,k,t,T_i,m_i,(a_i,b_i,c_i)$，$1\le n\le 2000,2\le m\le n$,$1\le k\le10^5,1\le T\le n$，输入保证有解)

由于可能有自环重边(题目没说没有)，所以不可以考虑拓补排序。由于同一种植物可能会被多次使用，所以不可以考虑删点，同理不可以考虑删边。最终只得到了dfs方法。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 2002
#define big 0x7ffffff;
#define ses pair<int,int>
bool get[mn];
vector<ses> g[mn];
int n,m,k,t,st[mn],dp[mn],ui,vi,wi;
int dfs(int tg, ses cp)
{
	int u=cp.first,v=cp.second;
	if(!get[u]) for(int i=0,ie=g[u].size();i<ie;++i)
		dp[u]=min(dp[u],dfs(u,g[u][i]));
	if(!get[v]) for(int i=0,ie=g[v].size();i<ie;++i)
		dp[v]=min(dp[v],dfs(v,g[v][i]));
	if(!get[u]||!get[v]) return big;
	get[tg]=true;
	return max(st[u],st[v])+max(dp[u],dp[v]);
}
signed main()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=n;++i) scanf("%d",st+i),dp[i]=big;
	for(int i=1;i<=m;++i) scanf("%d",&ui),get[ui]=true,dp[ui]=0;
	for(int i=1;i<=k;++i) scanf("%d%d%d",&ui,&vi,&wi),g[wi].push_back({ui,vi});
	for(int i=0,ie=g[t].size();i<ie;++i) dp[t]=min(dp[t],dfs(t,g[t][i]));
	return printf("%d",dp[t]),0;
}
```

###### 网络寻路

> (蓝桥)X 国的一个网络使用若干条线路连接若干个节点。节点间的通信是双向的。某重要数据包，为了安全起见，必须恰好被转发两次到达目的地。该包可能在任意一个节点产生，我们需要知道该网络中一共有多少种不同的转发路径。源地址和目标地址可以相同，但中间节点必须不同。输入数据保证任意两点最多只有一条边连接，并且没有自己连自己的边，即不存在重边和自环。
>
> $1\le n,\frac m{10}\le 10000$

题意是寻找经过4个节点(首尾可以相同)的路径数。

解法一：DFS

```c++
#include<iostream>
#include<vector>
using namespace std;

const int N=10010;
int n,m,ans;
vector<int> v[N];
void create(int n)
{
	int x,y;
	for(int i=1;i<=n;i++){				//录入数据 
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
void dfs(int pos,int num,int pre)		//分别表示：当前节点编号、当前dfs深度、前两个位置的节点编号 
{
	if(num==4){
		ans++;
		return;
	}
	for(int i=0;i<v[pos].size();i++){
		if(v[pos][i]==pre) continue;
		dfs(v[pos][i],num+1,pos);
	}
}

int main()
{
	cin>>n>>m;
	create(m);
	for(int i=1;i<=n;i++) dfs(i,1,0);	//num需初始化为1，pre可初始化为0 
	cout<<ans<<endl;
	return 0;
}
```

解法二：DFS(循环实现)

```c++
#include<iostream>
#include<vector>
using namespace std;

int n,m;
void create(vector<int> v[],int n)
{
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
int search(vector<int> v[])
{
	int f2,f3,sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++){
			f2=v[i][j];
			for(int k=0;k<v[f2].size();k++){
				f3=v[f2][k];
				if(i==f3) continue;					//第1个点不能与第3个点相同 
				for(int l=0;l<v[f3].size();l++){
					if(f2==v[f3][l]) continue;		//第2个点不能与第4个点相同 
					sum++;
				}
			}
		}
	}
	return sum;
}

int main()
{
	cin>>n>>m;
	vector<int> v[n+1];
	create(v,m);
	cout<<search(v)<<endl; 
	return 0;
}
```

解法三：度的计算(最优解)

枚举中间线段(第二、第三个点)，由于没有自环和重边，枚举输入的边必然都是合理的第二、第三个点，而它们的入度-1代表它们可以连接的除了这条边之外还有多少个新边，根据乘法原理，答案是它们相乘再乘以二(无向图可以反向走一次)。

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,d[10002],u[100002],v[100002]; long long ans;
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%d%d",u+i,v+i),++d[u[i]],++d[v[i]];
	for(int i=1;i<=m;++i) ans+=((d[u[i]]-1)*(d[v[i]]-1))<<1;
	printf("%lld",ans);
	return 0;
}
```

###### 危险系数

> (蓝桥)有无向图，定义$x,y$的危险系数为$x,y$互连有多少个不可或缺的中间点，输入$n,m,(u,v),a,b$，求$a,b$的危险系数。$2\le n\le1000,0\le m\le2000$，无自环。

解法一：DFS

```c++
#include <bits/stdc++.h>
#define mn 1002
int cnt[mn],cr[mn],ay[mn],tot,ans,hd[mn],n,m,a,b,res;
struct edge
{
	int to, nx;
} e[mn<<1];
inline void adde(int& ui, int& vi)
{
	e[++tot]={vi,hd[ui]};
	hd[ui]=tot;
}
void dfs(int u, int v, int ni)
{
	cr[u]=1,ay[ni]=u;//ay:当前搜索路径下每个节点分别是什么点 
	if(u==v)
	{
		++ans; //从u到v有一条新的可走的路 
		for(int i=0;i<=ni;++i) ++cnt[ay[i]];//当前路径所有点加一出现次数 
		return;
	}
	for(int i=hd[u];i;i=e[i].nx)
	{
		int ut=e[i].to;
		if(cr[ut]==1) continue;
		dfs(ut,v,ni+1);
		cr[ut]=0;//回溯 
	}
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,ui,vi;i<=m;++i) scanf("%d%d",&ui,&vi),adde(ui,vi),adde(vi,ui);
	scanf("%d%d",&a,&b);
	dfs(a,b,0);//下面如果一个点的出现次数等于通路数，则该点必不可少 
	for(int i=1;i<=n;++i) if(cnt[i]==ans) ++res;
	printf("%d",res-2);//去掉a,b自身 
	return 0;
}
```

方法二：缩点(略) //学会再补

#### BFS

算法描述为：

- 将起点s入队
- 非队空时，循环如下：
  - 离队u访问
  - 将u所有未访问点入队，d[v]=d[u]+1//d为深度

```c++
//输出BFS并输出每个点举例原点下标0的距离
//输入结构为N:点下标 度 相邻点下标1 ...
#include<iostream>
#include<queue>
using namespace std;
static const int N=100;
static const int INFTY = (1<<21);
int n, M[N][N];
int d[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    for(int i=0;i<n;i++) d[i]=INFTY;
    d[s]=0;
    int u;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int v=0;v<n;v++)
        {
            if(M[u][v]==0) continue;
            if(d[v]!=INFTY) continue;//类color作用
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<" "<<(d[i]==INFTY?(-1):d[i])<<endl;
}

int main()
{
    int u,k,v;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) M[i][j]=0;
    for(int i=0;i<n;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            cin>>v;
            M[u][v]=1;
        }
    }
    bfs(0);
    return 0;
}
//邻接表的栈式BFS算法参见连通分量的举例算法
```

**DFS+BFS从小到大节点示例：**

```c++
#include <bits/stdc++.h> //个人实现版本
using namespace std;
#define MAXN 100002
set<int> e[MAXN];
bool vis[MAXN];
int n,m,u,v;
void dfs(int i)
{
    printf("%d ",i);
    vis[i]=true;
    for(auto j:e[i])
    {
        if(!vis[j]) dfs(j);
    }
}
void bfs(int i)
{
    queue<int> q;
    int j;
    q.push(i);
    while(!q.empty())
    {
        j=q.front();q.pop();
        if(!vis[j])
        {
            printf("%d ",j);
            vis[j]=true;
            for(auto k:e[j])
            {
                if(!vis[k]) q.push(k);
            }
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&u,&v);
        e[u].insert(v);
    }
    dfs(1); putchar('\n');
    for(int i=1;i<=n;++i) vis[i]=false;
    bfs(1);
    return 0;
}
```

##### 例题

###### 最短路计数

> 有无向无权图(MAXN=1e6,MAXM=4e6)，求顶点1到1~n各点的最短路的数量。含自环和重边，重边应当算多条最短路。

```c++
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
const int MAXM=4e6;
const int MOD=1e5+3;
struct edge
{
    int to,nx;
} e[MAXM];
int hd[MAXN],cnt,n,m,ui,vi,res[MAXN],dep[MAXN];
bool vis[MAXN];
inline void adde(int &u, int &v)
{
    e[++cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
queue<int> q;
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&ui,&vi);
        adde(ui,vi);
        adde(vi,ui);
    }
    vis[1]=true;
    dep[1]=0;
    res[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int h=q.front();
        q.pop();
        for(int i=hd[h];i;i=e[i].nx)
        {
            int toi=e[i].to;
            if(!vis[toi])
            {
                vis[toi]=true;
                dep[toi]=dep[h]+1;
                q.push(toi);
            }
            if(dep[toi]==dep[h]+1)
            {
                (res[toi]+=res[h])%=MOD;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d\n",res[i]);
    }
    return 0;
}
```

> 本题有其他做法，如SPFA、dijkstra(堆优化)。

#### 连通分量

强连通分量(SCC, strong connected component)

生成dfs树的过程，一次探路可能会碰到已走的点，这样的边：

1. 如果这两个点无父子关系(有共同父亲不算)，则是横叉边
2. 如果有父子关系，则是后向边



以未访问顶点为起点循环DFS/BFS，给每轮搜索到的顶点分配不同的编号，用O(1)判断指定两个顶点是否是同一组。

由于这样的图一般是稀疏图，所以采用邻接表。总体算法复杂度是O(|V|+|E|)。

##### 实现

###### 1

```c++
//本程序包含了邻接表的栈式BFS算法;小bug:color不从1开始


#include <iostream>
#include <vector>
#include <stack>
using namespace std;
static const int NIL = 1;
static const int MAX = 100000;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c)
{
    stack<int> S;
    S.push(r);
    color[r] = c;
    while(!S.empty())
    {
        int u = S.top();
        S.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(color[v] == NIL && color[v] != c)
            {
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void prtcolor()
{
    for(int i=0;i<n;i++) cout<<color[i]<<" "; cout<<endl;
}

void assignColor()
{
    int id=1;
    for(int i=0;i<n;i++) color[i] = NIL;
    for(int u=0;u<n;u++) if(color[u]==NIL) {dfs(u, id++); dprtcolor();}
}

int main()
{
    int s,t,m,q;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);//无向图
    }
    assignColor();
    prtcolor();
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>s>>t;
        if(color[s]==color[t]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
```

###### 2

```c++
#define N 30100
//N为最大点数
#define M 150100
//M为最大边数
int n, m;//n m 为点数和边数
 
struct Edge{
	int from, to, nex;
	bool sign;//是否为桥
}edge[M<<1];
int head[N], edgenum;
void add(int u, int v){//边的起点和终点
	Edge E={u, v, head[u], false};
	edge[edgenum] = E;
	head[u] = edgenum++;
}
 
int DFN[N], Low[N], Stack[N], top, Time; //Low[u]是点集{u点及以u点为根的子树} 中(所有反向弧)能指向的(离根最近的祖先v) 的DFN[v]值(即v点时间戳)
int taj;//连通分支标号，从1开始
int Belong[N];//Belong[i] 表示i点属于的连通分支
bool Instack[N];
vector<int> bcc[N]; //标号从1开始
 
void tarjan(int u ,int fa){  
	DFN[u] = Low[u] = ++ Time ;  
	Stack[top ++ ] = u ;  
	Instack[u] = 1 ;  
 
	for (int i = head[u] ; ~i ; i = edge[i].nex ){  
		int v = edge[i].to ;  
		if(DFN[v] == -1)
		{  
			tarjan(v , u) ;  
			Low[u] = min(Low[u] ,Low[v]) ;
			if(DFN[u] < Low[v])
			{
				edge[i].sign = 1;//为割桥
			}
		}  
		else if(Instack[v]) Low[u] = min(Low[u] ,DFN[v]) ; 		
	}  
	if(Low[u] == DFN[u]){  
		int now;
		taj ++ ; bcc[taj].clear();
		do{
			now = Stack[-- top] ;  
			Instack[now] = 0 ; 
			Belong [now] = taj ;
			bcc[taj].push_back(now);
		}while(now != u) ;
	}
}
 
void tarjan_init(int all){
	memset(DFN, -1, sizeof(DFN));
	memset(Instack, 0, sizeof(Instack));
	top = Time = taj = 0;
	for(int i=1;i<=all;i++)if(DFN[i]==-1 )tarjan(i, i); //注意开始点标！！！
}
vector<int>G[N];
int du[N];
void suodian(){
	memset(du, 0, sizeof(du));
	for(int i = 1; i <= taj; i++)G[i].clear();
	for(int i = 0; i < edgenum; i++){
		int u = Belong[edge[i].from], v = Belong[edge[i].to];
		if(u!=v)G[u].push_back(v), du[v]++;
	}
}
void init(){memset(head, -1, sizeof(head)); edgenum=0;}
```



##### 例题

###### The Cow Prom S

> 给定有向图，求图点数大于1的强连通分量数

1. 按照深度优先遍历的方式遍历这张图。

2. 遍历当前节点所出的所有边。在遍历过程中：

   ( 1 ) 如果当前边的终点还没有访问过，访问。

   回溯回来之后比较当前节点的low值和终点的low值。将较小的变为当前节点的low值。（因为遍历到终点时有可能触发了2）

   ( 2 ) 如果已经访问过，那我们一定走到了一个之前已经走过的点（终点的时间戳一定比当前的小）

   则比较当前节点的low值和终点的dfn值。将较小的变为当前节点的low值

3. 在回溯过程中，对于任意节点u用其出边的终点v的low值来更新节点u的low值。因为节点v能够回溯到的已经在栈中的节点，节点u也一定能够回溯到。因为存在从u到v的直接路径，所以v能够到的节点u也一定能够到。

4. 当一个节点的dfn值和low值相等时，这个节点是一个强联通分量的“根”。压栈，输出。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 20002
#define MAXM 200002
struct edge { ll to, nx; } e[MAXM];
ll hd[MAXN], cnt, n, m, dfn[MAXN], low[MAXN], co[MAXN], num[MAXN], conum, st;
bool ud[MAXN], vis[MAXN];
stack<ll> s;
inline void adde(ll& u, ll& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
inline void paint(ll& x)
{
	s.pop();
	co[x] = conum;
	++num[conum];
	vis[x] = false;
}
void tarjan(ll x)
{
	dfn[x] = low[x] = ++st;
	s.push(x);
	vis[x] = ud[x] = true;
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!dfn[toi])//小心别写成x
		{
			tarjan(toi);//小心别写成x
			low[x] = min(low[x], low[toi]);
		}
		else if (vis[toi]) low[x] = min(low[x], dfn[toi]);
	}
	if (low[x] == dfn[x])
	{
		++conum;
		while (s.top() != x)
		{
			ll t = s.top();
			paint(t);
		}
		paint(x);
	}
}
signed main()
{
	ll ui, vi, ans = 0;
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		scanf("%d%d", &ui, &vi);
		adde(ui, vi);
	}
	repe(i, 1, n) if (!ud[i]) tarjan(i);
	repe(i, 1, conum) if (num[i] > 1) ++ans;
	printf("%d", ans);
	return 0;
}
```

###### 割点

> 给定无向图，求割点数和所有割点

如果dfs树根节点有两棵或以上子树，是割点。是非根节点，维护dfn[u]表示顶点u第几个被（首次）访问，low[u]表示顶点u及其子树中的点，通过非父子边（回边），能够回溯到的最早的点（dfn最小）的dfn值（但不能通过连接u与其父节点的边）。对于边(u, v)，如果low[v]>=dfn[u]，此时u就是割点。

> 显然如果节点U的所有孩子节点可以不通过父节点U而访问到U的祖先节点,
> 那么说明此时去掉节点U不影响图的连通性,U就不是割点。
> 相反,如果节点U至少存在一个孩子顶点，必须通过父节点U才能访问到U的祖先节点,
> 那么去掉节点U后，顶点U的祖先节点和孩子节点就不连通了,说明U是一个割点。

假设当前顶点为u，则默认low[u]=dfn[u]，即最早只能回溯到自身。

有一条边(u, v)，如果v未访问过，继续DFS，DFS完之后，low[u]=min(low[u], low[v])；

如果v访问过（且u不是v的父亲），就不需要继续DFS了，一定有dfn[v]<dfn[u]，low[u]=min(low[u], dfn[v])。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 20002
#define MAXM 100002
struct edge { ll to, nx; } e[MAXM << 1];
ll n, m, idx, cnt, tot, hd[MAXN], dfn[MAXN], low[MAXN], ui, vi;
bool cut[MAXN];
inline void adde(ll& x, ll& y)
{
	e[++cnt].to = y;
	e[cnt].nx = hd[x];
	hd[x] = cnt;
}
void tarjan(ll u, ll fa)
{
	dfn[u] = low[u] = ++idx;
	ll child = 0;
	for (ll i = hd[u]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!dfn[toi])//尚未访问
		{
			//printf("%d %d\n", u, toi);
			tarjan(toi, fa);
			low[u] = min(low[u], low[toi]);
			if (low[toi] >= dfn[u] && u != fa) cut[u] = true;
			if (u == fa) ++child;
		}
		low[u] = min(low[u], dfn[toi]);
	}
	if (child >= 2 && u == fa) cut[u] = true;
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		scanf("%d%d", &ui, &vi);
		adde(ui, vi);
		adde(vi, ui);
	}
	repe(i, 1, n) if (!dfn[i]) tarjan(i, i);
	repe(i, 1, n) if (cut[i]) ++tot;
	printf("%d\n", tot);
	repe(i, 1, n) if (cut[i]) printf("%d ", i);
	return 0;
}
```

###### 缩点

> 有n点m边有向点权图，求一条路径，使得经过的点权和最大，输出这个点权和
> 路径可以重复经过某条边或某个点，但是重复经过权值只算一次

tarjan缩点+拓补

dfs[i]是i点进入时间，low[i]是从i出发，所能访问到的最早的进入时间

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
#define MAXM 100002
ll n, m, cnt, tim, top, s;
ll p[MAXN], hd[MAXN], sd[MAXN], dfn[MAXN], low[MAXN];
ll stac[MAXN], h[MAXN], in[MAXN], dist[MAXN], ui, vi;
bool vis[MAXN];
struct edge
{
	ll to, nx, f;
} e[MAXM], ed[MAXM];
#define fore(x) for(ll i=hd[x];i;i=e[i].nx)
#define toi e[i].to
inline void adde(ll& x, ll& y)
{
	e[++cnt].nx = hd[x];
	e[cnt].f = x;
	e[cnt].to = y;
	hd[x] = cnt;
}
void tarjan(ll x)
{
	low[x] = dfn[x] = ++tim;
	stac[++top] = x;
	vis[x] = true;
	fore(x)
	{
		ll v = toi;
		if (!dfn[v]) tarjan(v), low[x] = min(low[x], low[v]);
		else if(vis[v]) low[x] = min(low[x], low[v]);
	}
	if (dfn[x] == low[x])
	{
		ll y;
		while (y = stac[top--])
		{
			sd[y] = x;
			vis[y] = false;
			if (x == y) break;
			p[x] += p[y];
		}
	}
}
inline ll topo()
{
	queue<ll> q;
	ll tot = 0, ans = 0;
	repe(i, 1, n) if (sd[i] == i && !in[i]) q.push(i), dist[i] = p[i];
	while (!q.empty())
	{
		ll k = q.front(); q.pop();
		for (ll i = h[k]; i; i = ed[i].nx)
		{
			ll v = ed[i].to;
			dist[v] = max(dist[v], dist[k] + p[v]);
			--in[v];
			if (!in[v]) q.push(v);
		}
	}
	repe(i, 1, n) ans = max(ans, dist[i]);
	return ans;
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%d", &p[i]);
	repe(i, 1, m)
	{
		scanf("%d%d", &ui, &vi);
		adde(ui, vi);
	}
	repe(i, 1, n) if (!dfn[i]) tarjan(i);
	repe(i, 1, m)
	{
		ll x = sd[e[i].f], y = sd[e[i].to];
		if (x != y)
		{
			ed[++s].nx = h[x];
			ed[s].to = y;
			ed[s].f = x;
			h[x] = s;
			++in[y];
		}
	}
	printf("%d", topo());
	return 0;
}
```

###### 间谍网络

> 有n个间谍，一些可贿赂。一些间谍支配另外若干个间谍。贿赂间谍，能否支配所有间谍，若能输出最少贿赂金。如果存在无法贿赂间谍，输出NO和编号最小的间谍。

如存在无法贿赂且无入度的间谍，输出NO和编号最小的间谍。

无环时，资金为无入度间谍和

有环时，缩点为环内资金为环上最小点资金

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
const ll BIG = 1e9 + 7;
struct edge { ll nx, to; } e[MAXN];
ll n, q, st, p, top, cnt, ans, r, ui, vi, wi;
ll dfn[MAXN], low[MAXN], hd[MAXN], nx[MAXN], stk[MAXN], istk[MAXN];
ll bel[MAXN], ny[MAXN], sum[MAXN], siz[MAXN], rd[MAXN];
inline void adde(ll& u, ll& v)
{
	e[++p] = { hd[u],v };
	hd[u] = p;
}
void tarjan(ll a)
{
	dfn[a] = low[a] = ++st;
	istk[a] = 1;
	stk[++top] = a;
	for (ll i = hd[a]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!dfn[toi])
		{
			tarjan(toi);
			low[a] = min(low[a], low[toi]);
		}
		else if (istk[toi]) low[a] = min(low[a], dfn[toi]);
	}
	if (dfn[a] == low[a])
	{
		++cnt;
		while (stk[top + 1] != a)
		{
			bel[stk[top]] = cnt;
			istk[stk[top]] = 0;
			++siz[cnt];
			sum[cnt] = min(sum[cnt], ny[stk[top]]);
			--top;
		}
	}
}
signed main()
{
	scanf("%d%d", &n, &q);
	repe(i, 1, n) ny[i] = BIG, sum[i] = 1e9;
	repe(i, 1, q) scanf("%d%d", &ui, &vi), ny[ui] = vi;
	scanf("%d", &r);
	repe(i, 1, r) scanf("%d%d", &ui, &vi), adde(ui, vi);
	repe(i, 1, n) if (!dfn[i] && ny[i] != BIG) tarjan(i);
	repe(i, 1, n) if (!dfn[i]) return printf("NO\n%d", i), 0;
	repe(i, 1, n) for (ll j = hd[i]; j; j = e[j].nx)
	{
		if (bel[i] != bel[e[j].to]) ++rd[bel[e[j].to]];
	}
	repe(i, 1, cnt) if (!rd[i]) ans += sum[i];
	printf("YES\n%d", ans);
	return 0;
}
```

###### 受欢迎的牛G

> 有n头牛，所有牛喜欢自己和若干头别的牛，喜欢可以传递，求多少头牛被所有牛喜欢。

目标牛是唯一一个出度为0的强连通分量里的所有节点。如果有两个这样的强连通分量则无解。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
#define MAXM 200002
struct edge { ll nx, to; }e[MAXM];
ll hd[MAXN], dfn[MAXN], low[MAXN], outd[MAXN], id[MAXN], w[MAXN];
ll cnt, tot, g, n, m, ui, vi, ans;
bool vis[MAXN];
stack<ll> s;
inline void adde(ll& u, ll& v)
{
	e[++cnt] = { hd[u],v };
	hd[u] = cnt;
}
void tarjan(ll x)
{
	dfn[x] = low[x] = ++tot;
	s.push(x);
	vis[x] = true;
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!dfn[toi])
		{
			tarjan(toi);
			low[x] = min(low[x], low[toi]);
		}
		else if (vis[toi]) low[x] = min(low[x], dfn[toi]);
	}
	ll k;
	if (low[x] == dfn[x])
	{
		++g;
		do
		{
			k = s.top(); s.pop();
			vis[k] = false;
			id[k] = g;
			++w[g];
		} while (x != k);
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m) scanf("%d%d", &ui, &vi), adde(ui, vi);
	repe(i, 1, n) if (!dfn[i]) tarjan(i);
	repe(h, 1, n) for (ll i = hd[h]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (id[h] != id[toi]) ++outd[id[h]];
	}
	repe(i, 1, g) if (!outd[i])
	{
		if (ans) return printf("0"), 0;
		ans = i;
	}
	printf("%d", w[ans]);
	return 0;
}
```

###### 上白泽慧音

> 有n点m有向或无向边，求最大强联通区域，若有多个，输出字典序最小的。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
#define BIG 0x3fffffff
struct edge { ll to, nx; } e[MAXN << 1];
ll col, num, hd[MAXN], dfn[MAXN], low[MAXN], de[MAXN], co[MAXN];
ll si[MAXN], stk[MAXN], top, n, m, cnt, tot, ui, vi, f, no;
inline void adde(ll& u, ll& v) 
{
	e[++cnt] = { v,hd[u] };
	hd[u] = cnt;
}
void tarjan(ll u)
{
	dfn[u] = low[u] = ++num;
	stk[++top] = u;
	for (ll i = hd[u]; i; i = e[i].nx)
	{
		ll v = e[i].to;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!co[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		co[u] = ++col;
		++si[col];
		while (stk[top] != u)
		{
			++si[col];
			co[stk[top]] = col;
			--top;
		}
		--top;
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		scanf("%d%d%d", &ui, &vi, &f);
		adde(ui, vi);
		if (f == 2) adde(vi, ui);
	}
	repe(i, 1, n) if (!dfn[i]) tarjan(i);
	repe(i, 1, col) tot = max(tot, si[i]);
	printf("%d\n", tot);
	repe(i, 1, n) if (si[co[i]] == tot)
	{
		no = co[i];
		repe(j, i, n) if (co[j] == no) printf("%d ", j);
		return 0;
	}
	return 0;
}
```

###### 校园网

> n间学校连成有向图，给出邻接表。求最小的a，从a个点出发，能够遍历所有学校。求最小的b，使得增加b条有向边，使得从任一间学校出发可以到达所有其余学校。

缩点后，a为入度为0的节点数；b为a与出度为0的节点数的较大者。证明略。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 102
#define MAXE 10002
ll n, hd[MAXN], cnt, col, sum, top = 1, ind[MAXN], outd[MAXN];
ll sta[MAXN], cr[MAXN], dfn[MAXN], low[MAXN], ins[MAXN], h[MAXE][2];
struct edge { ll to, nx; } e[MAXE << 1];
inline void adde(ll& u, ll& v)
{
	e[++cnt] = { v,hd[u] };
	hd[u] = cnt;
}
void tarjan(ll x)
{
	dfn[x] = low[x] = ++sum;
	sta[top++] = x;
	ins[x] = true;
	for (ll i = hd[x]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (!ins[toi])
		{
			tarjan(toi);
			low[x] = min(low[x], low[toi]);
		}
		else if (ins[toi] == 1) low[x] = min(low[x], dfn[toi]);
	}
	if (dfn[x] == low[x])
	{
		++col;
		do
		{
			--top;
			cr[sta[top]] = col;
			ins[sta[top]] = -1;
		} while (sta[top] != x);
	}
}
ll k, v, ans1, ans2;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n)
	{
		do
		{
			scanf("%d", &v);
			if (!v) break;//不然会炸
			++k;
			adde(i, v);
			h[k][0] = i;
			h[k][1] = v;
		} while (v);
	}
	repe(i, 1, n) if (!ins[i]) tarjan(i);
	repe(i, 1, k) if (cr[h[i][0]] != cr[h[i][1]])
	{
		++outd[cr[h[i][0]]];
		++ind[cr[h[i][1]]];
	}
	repe(i, 1, col)
	{
		if (!ind[i]) ++ans1;
		if (!outd[i]) ++ans2;
	}
	if (col == 1) printf("1\n0");
	else printf("%d\n%d", ans1, max(ans1, ans2));
	return 0;
}
```

###### 采蘑菇

> n点m边有向图，每条边有若干个蘑菇，且采集后蘑菇数量为$\lfloor原数量\times边恢复系数\rfloor$，求最多能采蘑菇数。

使用tarjan缩点，将环内蘑菇全部采集，并化作点权，然后跑spfa最长路，求点权和边权最大的解。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 80002
#define MAXM 200002
struct edge { ll nx, to, d, f; double k; } e1[MAXM], e2[MAXM];
ll hd[MAXN], dfn[MAXN], low[MAXN], col[MAXN], stk[MAXN], vis[MAXN], ans;
ll hd2[MAXN], num2, w[MAXM], dis[MAXN], b[MAXN], n, m, num, cnt, tp, cn, s;
inline void adde1(ll& u, ll& v, ll& d, double& k)
{
	e1[++num] = { hd[u],v,d,u,k };
	hd[u] = num;
}
inline void adde2(ll& u, ll& v, ll& d)
{
	e2[++num2] = { hd2[u],v,d,u,0.0 };
	hd2[u] = num2;
}
void tarjan(ll x)
{
	dfn[x] = low[x] = ++cnt;
	vis[x] = 1;
	stk[++tp] = x;
	for (ll i = hd[x]; i; i = e1[i].nx)
	{
		ll y = e1[i].to;
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x])
	{
		++cn;
		col[x] = cn; 
		vis[x] = 0;
		while (stk[tp] != x)
		{
			col[stk[tp]] = cn;
			vis[stk[tp--]] = 0;
		}
		--tp;
	}
}
inline void spfa()
{
	memset(dis, -1, sizeof dis);
	queue<ll> q;
	q.push(s);
	dis[s] = w[s];
	b[s] = 1;
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		b[u] = 0;
		for (ll i = hd2[u]; i; i = e2[i].nx)
		{
			ll v = e2[i].to;
			if (dis[v] < dis[u] + e2[i].d + w[v])
			{
				dis[v] = dis[u] + e2[i].d + w[v];
				if (!b[v]) b[v] = 1, q.push(v);
			}
		}
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		ll ui, vi, wi;
		double ki;
		scanf("%d%d%d%lf", &ui, &vi, &wi, &ki);
		adde1(ui, vi, wi, ki);
	}
	repe(i, 1, n) if (!dfn[i]) tarjan(i);
	repe(i, 1, m)
	{
		if (col[e1[i].to] == col[e1[i].f])
		{
			ll id = col[e1[i].to];
			ll t = e1[i].d;
			while (t)
			{
				w[id] += t;
				t = t * e1[i].k;
			}
		}
		else adde2(col[e1[i].f], col[e1[i].to], e1[i].d);
	}
	scanf("%d", &s);
	s = col[s];
	spfa();
	repe(i, 1, cn) ans = max(ans, dis[i]);
	printf("%d", ans);
	return 0;
}
```

#### 最小生成树

minimum spanning tree 

##### prim

普利姆算法(Prim's Algorithm):

设图G=(V,E)顶点集合V，MST顶点集合为T。算法遍历次数与顶点数相同，复杂度O(|V|^2)。若用二叉堆(优先级队列)选定顶点，算法效率将大大提高为O((E+V)logV)，如果用斐波那契堆优化，为O(E+VlogV)。

算法对稠密图比较好。

1. 从G任取顶点r作MST根，添至T。
2. 循环执行如下直到T=V
   1. 在连接T内顶点与V-T内顶点的边中选取权值最小的边(pu,u)，将其作为MST的边，并将u添至T

```c++
#include <iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY  = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[MAX][MAX];
int prim()
{
    int u, minv;
    int d[MAX], p[MAX], color[MAX];
    //d[v]代表MST内顶点与G-MST内顶点的边中，权值最小的边的权值
    //p[v]记录MST内定点v的父结点
    for(int i=0;i<n;i++)
    {
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }
    d[0] = 0;
    while(1)
    {
        minv = INFTY;
        u = -1;
        for(int i=0;i<n;i++)//找存在的路径并选择最小权值点为u
        {
            if(minv>d[i] && color[i] != BLACK)
            {
                u=i;
                minv=d[i];
            }
        }
        if(u==-1) break;
        color[u] = BLACK;
        for(int v=0;v<n;v++)
        {
            if(color[v] != BLACK && M[u][v] != INFTY)
            {
                if(d[v] > M[u][v])//找可选路径并求值
                {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++) if(p[i]!=-1) sum+=M[i][p[i]];
    return sum;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int e;
            cin>>e;
            M[i][j] = (e==-1)?INFTY:e;
        }
    }
    cout<<prim()<<endl;
    return 0;
}
```

##### kruskal

使用并查集(带路径压缩)，可以将一个无向加权图生成k颗最小生成树(当然可以只要一棵)

复杂度为O(ElogE+EA(V)+V),A为并查集初始化复杂度。算法对稀疏图比较好。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1002 //如果RE了试着改成MAXE的量
#define MAXE 10002
#define rep(i,a,b) for(int i=a;i<b;++i)
int fa[MAXN],n,m,k,ans,h,ui,vi;
struct edge
{
    int u,v,w;
} e[MAXE];
int finds(int k)
{
    while(k!=fa[k]) k=fa[k]=fa[fa[k]];
    return k;
}
bool cmp(edge a, edge b)
{
    return a.w<b.w;
}
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n>k+m)
    {
        printf("No Answer");
        return 0;
    }
    rep(i,0,m)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        fa[i+1]=i+1;
    }
    sort(e,e+m,cmp);
    while(h<m && n>k)
    {
        ui=finds(e[h].u);
        vi=finds(e[h].v);
        if(ui!=vi)
        {
            fa[ui]=vi;
            ans+=e[h].w;
            n--;
        }
        h++;
    }
    h=0;
    if(n>k)
    {
        printf("No Answer");
        return 0;
    }
    printf("%d",ans);
    return 0;
}
```

常见失误：

- 只生成一棵树应当连接n-1次，n为点数
- 忘记了unite操作或操作不当
- 不开longlong见祖宗
- 忘记排序或排序反了或未定义排序函数/重载或排序前/后挪了一位
- 边的引用出现问题(比如++后还是用原本的，导致移了一位)

##### 例题

###### 补充边

> 在平面直角坐标系上有n个点，已有m条边连接这些点，现需添加若干边，使点互相连通，求最短添加边长和。输入n,m，依次输入n行坐标(x,y)，输入m条边(u,v)，u,v代表点的序号，从1开始。

```c++
#include <bits/stdc++.h>
using namespace std;
#define dis(x1,x2,y1,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define MAXN 1005
#define MAXM 1000005
#define rep(i,a,b) for(ll i=a;i<=b;i++)
typedef long long ll;
ll n,m,fa[MAXN],x[MAXN],y[MAXN],h,ui,vi,en,et,hsuc;
double ans;
bool fin,repp;
struct edge
{
    ll u,v;
    double d;
    bool operator<(const edge& x) const {return d<x.d;}
} e[MAXM], ee[MAXN];
int finds(int k)
{
    while(k!=fa[k]) k=fa[k]=fa[fa[k]];
    return k;
}
signed main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n)
    {
        scanf("%d%d",&x[i],&y[i]);
        fa[i]=i;
    }
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            e[++et].u=i;
            e[et].v=j;
            e[et].d=dis(x[i],x[j],y[i],y[j]);
        }
    }
    rep(i,1,m)
    {
        scanf("%d%d",&ui,&vi);
        if(ui>vi) swap(ui,vi);
        e[++et].u=ui;
        e[et].v=vi;
        e[et].d=0;
    }
    sort(e+1,e+1+et);
    while(hsuc+1<n)
    {
        ui=finds(e[h].u);
        vi=finds(e[h++].v);
        if(ui==vi) continue;
        fa[ui]=vi;
        hsuc++;
        ans+=e[h-1].d;
    }
    printf("%.2lf\n", ans);
    return 0;
}
```

复杂度高的不恰当思路：

- 开三重循环，最内层查找当前枚举的i,j是否在边集内，在则不创建(因为不知道创一个重边(权值为0)是可以解决的)

###### CGY的安排

> (oj)有无自环重边的无向加权图，在能到达所有点的基础上，选择尽可能少的道路，在上述条件下，使得最长路和最短路差值最小，求这个差值。若无路可走，输出-1。
>
> $1\le T\le1000,2\le n\le100,0\le m\le\frac{n(n-1)}2,1\le W_i\le10^4$

由于数据比较小，可以直接对每组测试样例都一直跑Kruskal，直到不再能生成最小生成树。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define il inline
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define big 0x7ffffffa
#define mn 102
ll n, m, fa[mn], mi, mx, ans, bg, ui, vi, wi, suc;
struct edge
{
	ll u, v, w;
} e[mn * mn];
il ll finds(ll k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
il bool cmp(const edge& a, const edge& b) { return a.w < b.w; }
signed main()
{
	while(1)
	{
		scanf("%d%d", &n, &m);
		if (!n) break;
		repe(i, 1, m) scanf("%d%d%d", &ui, &vi, &wi), e[i] = { ui,vi,wi };
		sort(e + 1, e + 1 + m, cmp);
		for (ans = big, bg = 1;; ++bg)
		{
			mx = 0, mi = big, suc = 1;
			repe(i, 1, n) fa[i] = i;
			repe(i, bg, m)
			{
				ui = finds(e[i].u), vi = finds(e[i].v), wi = e[i].w;
				if (ui != vi)
				{
					fa[ui] = vi, mi = min(mi, wi), mx = max(mx, wi);
					if (++suc == n) break;
				}
			}
			if (suc < n) break;
			ans = min(ans, mx - mi);
		}
		printf("%d\n", ans == big ? -1 : ans);
	}
	return 0;
}
```

###### 最短最大边

> 从点s走到点t，n点m边无向加权图，求经过的路径的某条权值最大值的最小值，即存在一条从s到t的路径，使路上权值的最大值最小

一直建kruskal，直到s,t联通，则最新加入的点就是最大值

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 20002
#define rep(i,a,b) for(int i=a;i<=b;i++)
struct edge
{
    int u,v,d;
    bool operator<(const edge &x) const {return d<x.d;}
} e[MAXN];
int n,m,s,t,fa[MAXN],mx,ui,vi,ci=1;
int finds(int k)
{
    while(k!=fa[k]) k=fa[k]=fa[fa[k]];
    return k;
}
signed main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    rep(i,1,n)
    {
        fa[i]=i;
    }
    rep(i,1,m)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
    }
    sort(e+1,e+1+m);//不是(e,e+m);这里WA了一次
    while(1)
    {
        ui=finds(e[ci].u);
        vi=finds(e[ci++].v);
        if(ui==vi) continue;
        mx=max(mx,e[ci-1].d);//可以优化成mx=e[ci-1].d;da tr;
        fa[ui]=vi;
        if(finds(s)==finds(t)) break;
    }
    printf("%d",mx);
    return 0;
}
```

> 这题也可以用二分答案来做，即二分最小值，判断是否存在这样的路

###### 国王的烦恼

> (蓝桥)n岛m桥，每座桥(a,b)在第t天不能使用；当两岛前一天可到达而后一天无法到达时，后一天会抗议。求抗议的天数。
>
> $1\le n\le10000,1\le m,t\le100000,1\le a,b\le n$

显然不可以用复杂度为$\Omicron(n^3)$的Floyd算法；而这题的本质是以时间顺序倒序跑Kruskal最小生成树，每次首次连接两个并查集时，如果当天未计数，天数自增。

```c++
#include <bits/stdc++.h>//注意不是问最早什么时候会开始抗议
using namespace std;
#define mn 100002
struct po
{
	int u, v;
};
int fa[mn],n,m,mx,suc,ui,vi,wi,d,siz,bf=-1;
inline int finds(int k)
{
	while(k!=fa[k]) k=fa[k]=fa[fa[k]];
	return k;
}
vector<po> e[mn];
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&ui,&vi,&wi);
		mx=max(mx,wi);
		e[wi].push_back({ui,vi});
	}
	for(d=mx;d>0;--d)
	{
		siz=e[d].size();
		for(int i=0;i<siz;++i)
		{
			ui=finds(e[d][i].u),vi=finds(e[d][i].v);
			if(ui!=vi)
			{
				fa[ui]=vi;
				if(d!=bf) ++suc,bf=d;
			}
		}
	}
	printf("%d",suc);
	return 0;
}
```

###### 部落划分

> 有n个坐标轴上点(x,y)，将其划分为k份，求一种划分方式，使得各部分间距离的最小值最大，输出这个值

跑kruskal然后按边的升序找第n-k+1条边，即为答案

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1002
#define disz sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]))
ll fa[MAXN], px[MAXN], py[MAXN], n, k, ei, ri = 1, suc, ui, vi;
double t[MAXN];
struct edge
{
	ll u, v;
	double d;
} e[MAXN * MAXN];
inline bool cmp(const edge& x, const edge& y) { return x.d < y.d; }
inline ll finds(ll& k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
signed main()
{
	scanf("%d%d", &n, &k);
	repe(i, 1, n) scanf("%d%d", &px[i], &py[i]), fa[i] = i;
	repe(i, 1, n)
	{
		repe(j, i + 1, n)
		{
			e[++ei].u = i;
			e[ei].v = j;
			e[ei].d = disz;
		}
	}
	sort(e + 1, e + 1 + ei, cmp);
	while (suc + 1 < n)
	{
		ui = finds(e[ri].u);
		vi = finds(e[ri++].v);
		if (ui == vi) continue;
		t[++suc] = e[ri - 1].d;
		fa[ui] = vi;
	}
	printf("%.2lf", t[n - k + 1]);
	return 0;
}
```

#### 环

##### 负环判定

> bellman-ford 如果一个点被成功松弛了n次，则有负环

链式前向星+SPFA

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2002
#define MAXM 6002
#define BIG (1<<31)-1
#define inita(a,n,v) for(register int i=0;i<=n;i++) a[i]=v
int n,m,hd[MAXN],cnt,d[MAXN],cnts[MAXN],ui,vi,wi,ttn;
bool vis[MAXN];
queue<int> q;
struct edege
{
    int to,d,nx;
} e[MAXM];
inline void adde(int u, int v, int w)
{
    e[++cnt].d=w;
    e[cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
void spfa()
{
    inita(d,n,BIG);
    inita(cnts,n,0);
    inita(vis,n,false);
    while(!q.empty())q.pop();
    d[1]=0;
    vis[1]=true;
    q.push(1);
    int u;
    while(!q.empty())
    {
        u=q.front();
        vis[u]=false;
        q.pop();
        //printf("%d\n",u);
        for(register int i=hd[u];i!=-1;i=e[i].nx)
        {
            //v=e[i].to;
            //w=e[i].d;
            //printf("-%d\n",e[i].to);
            if(d[u]+e[i].d<d[e[i].to])
            {
                d[e[i].to]=d[u]+e[i].d;
                if(!vis[e[i].to])
                {
                    if(++cnts[e[i].to]>=n)
                    {
                        printf("YES\n");
                        return;
                    }
                    vis[e[i].to]=true;
                    q.push(e[i].to);
                }
            }
        }
    }
    printf("NO\n");
    return;
}
int main()
{
    scanf("%d",&ttn);
    while(ttn--)
    {
        scanf("%d%d",&n,&m);
        cnt=-1;
        inita(hd,n,-1);
        while(m--)
        {
            scanf("%d%d%d",&ui,&vi,&wi);
            adde(ui,vi,wi);
            if(wi>=0)adde(vi,ui,wi);
        }
        spfa();
    }
    return 0;
}
```

##### 基环树

一棵树增加一条边(非重边)，得到只有一个环的树，称为基环树。可以使用DFS在$\Omicron(n)$内找到该基环树的环并输出。

> 例题：(蓝桥)发现环，输出基环树的环

个人实现版本：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
struct
{
	int to,nx;
} e[mn<<1];
int cnt,hd[mn],n,ui,vi,h,vis[mn],att[mn];
set<int> s;
inline void adde(int& u, int& v)
{
	e[++cnt]={v,hd[u]};
	hd[u]=cnt;//小心不要漏了
	e[++cnt]={u,hd[v]};
	hd[v]=cnt;
}
void dfs(int i, int fa)
{
	if(vis[i])
	{
		h=i;//循环节，再次碰到的时候就找完了
		s.insert(i);
		att[fa]=true;
		return;
	}
	if(vis[i]) return;
	vis[i]=true;
	for(int j=hd[i];j;j=e[j].nx)
	{
		int k=e[j].to;
		if(k!=fa) dfs(k,i);
	}
	if(att[i])
	{
		s.insert(i);
		if(h==fa)//注意不是h==i
		{
			for(set<int>::iterator it=s.begin();it!=s.end();++it)
			{
				printf("%d ",*it);
			}
			exit(0);//注意直接exit，不然因为无向边会再找一次
		}
		att[fa]=true;
	}
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&ui,&vi);
		adde(ui,vi);
	}
	dfs(1,0);
	return 0;
}
```



##### 最小环

解法dfs例题条件：每个节点有若干入度，但只有一个出度，边权均1

###### dfs

个人算法，遍历每一个点，从该点开始dfs，如果碰到了头，且碰到的点是出发点，那么是环，保存环周长；求出最小周长。时间复杂度较大容易TLE。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200002
#define BIG 0x7fffffff
struct edge
{
    int to,d,nx;
} e[MAXN];
int hd[MAXN],cnt,ans=BIG,n,vi,pa;
bool vis[MAXN];
inline void adde(int u, int v, int w)
{
    e[++cnt].d=w;
    e[cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
void cy(int i, int &o)
{
    if(vis[i])
    {
        if(i==o) ans=min(ans,pa);
        return;
    }
    vis[i]=true;
    pa++;
    for(int j=hd[i];j;j=e[j].nx)
    {
        cy(e[j].to,o);
    }
    pa--;
    vis[i]=false;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&vi);
        adde(i,vi,1);
    }
    for(int i=1;i<=n;i++)
    {
        pa=0;
        cy(i,i);
    }
    printf("%d",ans);
    return 0;
}
```

###### dfs剪枝

对于上题的特殊条件，可以证明，不存在重叠的环，所以跟环相连的路径最终都走向唯一环，该环只需要dfs一次。复杂度O(n)。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define rep(i) for(int i=1;i<=n;++i)
bool v[MAXN],alr[MAXN];
int n,to[MAXN],st[MAXN],ans=0x7fffffff;
void dfs(int x, int s)
{
    if(alr[x]) return;
    if(v[x]) ans=min(ans,s-st[x]);
    else
    {
        v[x]=true;
        st[x]=s;
        dfs(to[x],s+1);
        alr[x]=true;
    }
}
signed main()
{
    scanf("%d",&n);
    rep(i) scanf("%d",&to[i]);
    rep(i) dfs(i,0);
    printf("%d",ans);
    return 0;
}
```

###### 并查集

由A传递给B，那么就连一条由A指向B的边，同时更新A的父节点，A到它的父节点的路径长也就是B到它的父节点的路径长+1。

这样我们就建立好了一个图，之后信息传递的所有环节都按照这些路径。游戏结束的轮数，也就是这个图里最小环的长度。

如果有两个点祖先节点相同，那么就可以构成一个环，长度为两个点到祖先节点长度之和+1。

```c++
#include<cstdio>
#include<iostream>
using namespace std;
int f[200002],d[200002],n,minn,last;   //f保存祖先节点，d保存到其祖先节点的路径长。 
int fa(int x)
{
    if (f[x]!=x)                       //查找时沿途更新祖先节点和路径长。 
    {
        int last=f[x];                 //记录父节点（会在递归中被更新）。 
        f[x]=fa(f[x]);                 //更新祖先节点。 
        d[x]+=d[last];                 //更新路径长（原来连在父节点上）。 
    }
    return f[x];
}
void check(int a,int b)
{
    int x=fa(a),y=fa(b);               //查找祖先节点。 
    if (x!=y) {f[x]=y; d[a]=d[b]+1;}   //若不相连，则连接两点，更新父节点和路径长。 
    else minn=min(minn,d[a]+d[b]+1);   //若已连接，则更新最小环长度。 
    return;
}
int main()
{
    int i,t;
    scanf("%d",&n);
    for (i=1;i<=n;i++) f[i]=i;         //祖先节点初始化为自己，路径长为0。 
    minn=0x7777777;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&t);
        check(i,t);                    //检查当前两点是否已有边相连接。 
    }
    printf("%d",minn);
    return 0;
}
```

##### 环数、环长

###### 植树

> (scnuicpc pre-1)给定$n$顶点$m$边无向图，所有联通分量都是仙人掌，没有自环、重边，确定一个删边方案，使得删除后所有联通分量都是树，求方案数对$998244353$取模。$1\le n\le3\times10^5,1\le m\le5\times10^5$。

直接DFS，过程取深度，当DFS时碰到一个点的深度小于当前遍历点，则发现环，环长是深度差$+1$，对每一个环，设环长为$x$，其删环为树(或为点集)的方案为：
$$
\sum_{i=0}^xC_x^i=2^x-1
$$
对于每个环使用乘法原理。然后统计简单边边数$y$，即边数$-$总环长，乘上$2^y$即可。

```c++
#define me 500010
#define mn 300010
#define mod 998244353
struct edge{ll to,nx;} e[me<<1];
ll hd[mn],cnt,n,m,ui,vi,dep[mn],d[mn],s[mn],ans=1,t;
il void adde(ll& u, ll& v)
{
    e[++cnt]={v,hd[u]};
    hd[u]=cnt;
}
void dfs(ll h, ll fa)
{
    dep[h]=dep[fa]+1;
    d[h]=true;
    for(ll i=hd[h];i;i=e[i].nx)
    {
        ll v=e[i].to;
        if(v==fa) continue;
        if(!dep[v]) dfs(v,h);
        else if(dep[h]>dep[v])
        {
            s[h]=dep[h]-dep[v]+1;
        }
    }
}
il ll qpow(ll a, ll b)
{
    ll r=1;
    for(;b>0;b>>=1,(a*=a)%=mod) if(b&1) (r*=a)%=mod;
    return r;
}
signed main()
{
    n=read();m=read(); t=m;
    rep(h,0,m) ui=read(),vi=read(),adde(ui,vi);
    dfs(1,0);
    repe(i,1,n)
    {
        t-=s[i];
        if(s[i])(ans*=(qpow(2,s[i])-1))%=mod;
    }
    (ans*=qpow(2,t))%=mod;
    printf("%lld",ans);
	return 0;
}
```

###### 仙人掌

> 给定一个无向图，输入为点数和路径数，接下来每行输入一个数为路径长度，接下来若干个数是路径的点。如果这个图是仙人掌图，输出支撑子图数，否则输出0。
>
> $1\le n\le2\times10^4,0\le m\le10^3$，顶点编号从$1$到$n$。

首先明确仙人掌图支撑子图数的计算只需要对各环长+1求积即可。然后判定是否是仙人掌图可以使用如下方法：

- 没有孤立点，即所有点应该被遍历至少一次
- 所有点不应该被遍历超过一次

然后再跑高精度即可。高精度写法如下：

```c++
struct edge{ll to,nx;} e[mee<<1];
ll hd[mn],cnt,n,m,ui,vi,dep[mn],d[mn],s[mn],me[mn],ans=1,t,ff;
il void adde(ll& u, ll& v)
{
    e[++cnt]={v,hd[u]};
    hd[u]=cnt;
}
void dfs(ll h, ll fa)
{
    dep[h]=dep[fa]+1;
    me[h]=fa;
    for(ll i=hd[h];i;i=e[i].nx)
    {
        ll v=e[i].to;
        if(v==fa) continue;
        if(!dep[v]) dfs(v,h);
        else if(dep[h]>dep[v])
        {
            s[h]=dep[h]-dep[v]+1;
            for(ll i=h;i!=v;i=me[i])
            {
                ++d[i];
                if(d[i]>1) ff=1;
            }
        }
    }
}
il ll qpow(ll a, ll b)
{
    ll r=1;
    for(;b>0;b>>=1,(a*=a)%=mod) if(b&1) (r*=a)%=mod;
    return r;
}
ll gg[20010],gs=1;
signed main()
{
    n=read();m=read();
    rep(h,0,m)
    {
        t=read(); ui=read();
        while(--t)
        {
            vi=read();
            adde(ui,vi),adde(vi,ui); ui=vi;
        }
    }
    dfs(1,0);
    repe(i,1,n) if(!dep[i]) {ff=true; break;}
    if(ff) return printf("0"),0;
    gg[0]=1;
    repe(h,1,n)
    {
        ll v=1+s[h];
        rep(i,0,gs) gg[i]*=v;
        rep(i,0,gs) gg[i+1]+=gg[i]/10,gg[i]%=10;
        while(gg[gs]) {gg[gs+1]=gg[gs]/10,gg[gs++]%=10;}
    }
    rede(i,gs-1,0) printf("%d",gg[i]);
	return 0;
}
```

tarjan写法如下：

```c++
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
const int M=2*1e6+10,N=1e5+10;
struct mdzz {
    int next,to;
    mdzz() {}
    mdzz(res next,res to):next(next),to(to) {}
} edge[M];
int head[N],cnt;
inline void addedge(res u,res v) {
    edge[++cnt]=mdzz(head[u],v),head[u]=cnt;
    edge[++cnt]=mdzz(head[v],u),head[v]=cnt;
}
int n,m;
int dfn[N],low[N],num,fa[N],deep[N],tot,du[N],dp[N];
int pos,mp[N];
inline void DP(res rt,res x) {
    dp[++tot]=deep[x]-deep[rt]+1;
    for(res i=x; i!=rt; i=fa[i]) {
        du[i]++;
        if(du[i]>1) {
            puts("0");
            exit(0);
        }
    }
}
inline void tarjan(res x) {
    low[x]=dfn[x]=++num;
    for(res i=head[x]; ~i; i=edge[i].next) {
        res tox=edge[i].to;
        if(tox==fa[x])continue;
        if(!dfn[tox]) fa[tox]=x,deep[tox]=deep[x]+1,tarjan(tox),low[x]=min(low[x],low[tox]);
        else low[x]=min(low[x],dfn[tox]);
    }
    for(res i=head[x]; ~i; i=edge[i].next) {
        res tox=edge[i].to;
        if(fa[tox]!=x&&dfn[x]<dfn[tox])DP(x,tox);
    }
}
bign sum=1;
int main() {
    memset(head,-1,sizeof(head));
    n=read(),m=read();
    for(res i=1; i<=m; i++) {
        res k=read(),last=read();
        if(!mp[last])pos++,mp[last]=1;
        for(res j=2; j<=k; j++) {
            res x=read();
            addedge(x,last);
            last=x;
            if(!mp[x])pos++,mp[x]=1;
        }
    }
    if(pos<n) {
        puts("0");
        exit(0);
    }
    tarjan(1);
    for(res i=1; i<=tot; i++)sum=sum*(dp[i]+1);
    cout<<sum;
    return 0;
}
```



#### 单源最短路径

##### floyd

适用于任何存在最短路(无负环)的图，复杂度n^3，该算法还可以求全源最短路径。

初始代码，表示只允许经过前$k$个节点，节点$i,j$的最短路。

(f初始值无边为max(注意二倍max不能炸int/long long)，自己到自己为0，有边为边权)

```c++
for (k = 1; k <= n; k++) {
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
    }
  }
}
```

优化如下：

```c++
for (k = 1; k <= n; k++) 
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) 
      f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
```

floyd还可以用于求传递闭包。

##### 例题

###### 最小损耗

> 点数不超过100的有向图，输入点数n，起点a，终点b，接下来n行，第一个数字输入第i个点的出度k，接下来k个数字表示边(i,ki)。如果走第一条边不需要损耗，否则需要损耗一次，求a到b的最小损耗。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define MAXN 102
#define MAXE 10002
#define BIG 0x7ffffff
int n, dp[MAXN][MAXN], a, b, v, t;
signed main()
{
    scanf("%d%d%d",&n,&a,&b);
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            dp[i][j] = BIG;
        }
    }
    rep(i,1,n)
    {
        dp[i][i] = 0;
        scanf("%d",&v);
        rep(j,1,v)
        {
            scanf("%d",&t);
            if(j==1) dp[i][t] = 0;
            else dp[i][t] = 1;
        }
    }
    rep(k,1,n)
    {
        rep(i,1,n)
        {
            rep(j,1,n)
            {
                if(!(i==j || i==k || j==k))//这行可以不要
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    if(dp[a][b] == BIG) printf("-1");
    else printf("%d", dp[a][b]);
    return 0;
}
```

###### 跑路

> 有向图(可能存在自环)，边权均1，每单位时间可以走2^k^的距离，求从1到n间用时。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 52
#define LOGL 66
bool rn[MAXN][MAXN][LOGL];
ll d[MAXN][MAXN], n, m, u, v;
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) repe(j, 1, n) d[i][j] = 0x7ffffff;
	while (m--)
	{
		scanf("%d%d", &u, &v);
		d[u][v] = 1;
		rn[u][v][0] = true;
	}
	repe(h, 1, 64) repe(i, 1, n) repe(j, 1, n) repe(k, 1, n)
		if (rn[j][i][h - 1] && rn[i][k][h - 1]) rn[j][k][h] = true, d[j][k] = 1;
	repe(k, 1, n) repe(i, 1, n) repe(j, 1, n)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	printf("%d", d[1][n]);
	return 0;
}
```

###### 牛的旅行

> n<=150，有n个牧区，坐标为整数(x,y)，给出n个牧区邻接表。已知至少存在一个不连通牧区，现在不连通的地方添加一条边，使得添加后联通部分直径最小，求最小直径

先跑floyd，然后遍历一个点的所有边，求出点目前的最远距离，由此求出直径。然后在不相连的边两两连接，新的直径必然是最远+最远+d(两点)，求即可。注意可能新的直径不比原来的大。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 152
#define disz sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]))
const double BIG = 1e19;
ll n, px[MAXN], py[MAXN], v;
double d[MAXN][MAXN], dm[MAXN], a1, a2 = BIG;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d%d", &px[i], &py[i]);
	repe(i, 1, n)
	{
		repe(j, 1, n)
		{
			scanf("%1d", &v);
			if (v) d[i][j] = disz;
			else if (i != j) d[i][j] = BIG;
		}
	}
	repe(k, 1, n)
		repe(i, 1, n)
		repe(j, 1, n)
		if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
	repe(i, 1, n)
	{
		repe(j, 1, n)
		{
			if (d[i][j] != BIG) dm[i] = max(dm[i], d[i][j]);
		}
		a1 = max(a1, dm[i]);
	}
	repe(i, 1, n)
	{
		repe(j, 1, n)
		{
			if (d[i][j] == BIG) a2 = min(a2, dm[i] + dm[j] + disz);//因为用d[i][j]而挂了一次
		}
	}
	printf("%.6lf", max(a1, a2));
	return 0;
}
```

###### 灾后重建

> 以严格升序时间顺序输入建点的时间，输入无向加权边；输入时间不下降的q个询问(x,y,t)，问是否在t内(x,y)以建且联通，若是求最短路

注意本题下标点从0开始，时间也是。根据Floyd的本质，由于已经有序，直接边跑Floyd边处理询问即可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 202
#define BIG 0x7fffff
ll n, m, st[MAXN], g[MAXN][MAXN], x, y, t, k, q;
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", st + i);
	repe(i, 0, n) repe(j, 0, n) g[i][j] = BIG;
	repe(i, 0, n) g[i][i] = 0;
	while (m--)
	{
		scanf("%d%d%d", &x, &y, &t);
		g[x][y] = g[y][x] = t;
	}
	for (scanf("%d", &q); q; --q)
	{
		scanf("%d%d%d", &x, &y, &t);
		while (st[k] <= t && k < n)
		{
			rep(i, 0, n) rep(j, 0, n) if (g[i][j] > g[i][k] + g[j][k])
				g[i][j] = g[j][i] = g[i][k] + g[j][k];
			++k;
		}
		if (st[x] > t || st[y] > t) printf("-1\n");
		else if (g[x][y] == BIG) printf("-1\n");
		else printf("%d\n", g[x][y]);
	}
	return 0;
}
```

###### 差分约束算法

> 有m个不等式，n个未知数$x_i$组成不等式组：$x_{c_i}-x_{c_i'}\le y_i$，求一组可行解。

跑最短/最长路，其得到的$d_i$就是原不等式的一个解$x_i$，每个未知元是一个顶点，且增设一个特殊点$x_0$，连向所有其他点，边权为0，求$x_0$的单源最短路径。如果最短路出现负环，或最长路出现正环，无解。

> 拓展：大于等于就建反图，没有等于就移动一个单元，等于就两条边即大于等于和小于等于。

**Bellman-Ford**(较慢)

```c++
#include <bits/stdc++.h>//这里没增设特殊点x0
using namespace std;
struct edge { 
    int u, v, w; 
} e[5050];
int d[5050], n, m, c, c1, y;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &c, &c1, &y);
        e[i].u = c1, e[i].v = c, e[i].w = y;
    } for (int i = 1; i <= n; ++i) d[i] = (i == 1 ? 0 : 0x3f3f3f3f);
	for (int i = 1; i < n; ++i) 
	    for (int j = 1; j <= m; ++j)
	        d[e[j].v] = min(d[e[j].u] + e[j].w, d[e[j].v]);
    for (int i = 1; i <= m; ++i) 
	    if (d[e[i].v] > d[e[i].u] + e[i].w) 
	        return !printf("NO");
    for (int i = 1; i <= n; ++i) printf("%d ", d[i]);
}
```

**SPFA**(较快)

```c++
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 50005;
const int M = 50005;

struct edge {
    int v, w, fail;
    edge() {}
    edge(int _v, int _w, int _fail) {
        v = _v;
        w = _w;
        fail = _fail;
    }
} e[M];
int head[N], len;
void init() {
    memset(head, -1, sizeof(head));
    len = 0;
}
void add(int u, int v, int w) {
    e[len] = edge(v, w, head[u]);
    head[u] = len++;
}
int n, m;
int dis[N], in[N];
bool vis[N];
bool spfa(int u) {
    memset(vis, false, sizeof(vis));
    vis[u] = true;
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    memset(in, 0, sizeof in);
    in[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;
        for (int j = head[u]; ~j; j = e[j].fail) {
            int v = e[j].v;
            int w = e[j].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    ++in[v];
                    if (in[v] > n + 1) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    init();
    int u, v, w, op;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        add(u, v, -w);
    } 
    for (int i = 1; i <= n; ++i) add(0, i, 0);
    if (spfa(0)) cout << "NO" << endl;
    else for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
    return 0;
}
```

##### dijkstra

只适用于非负权图，有向无向均可。

应用：

- 两点间最短路/最长路
- 某点到各点最短路/最长路

将最短改为最长时，判断和node的函数内(node函数还是<重载不变)都要改，BIG也要改成SMALL，一般用负无穷大。

狄克斯特拉算法(Dijkstra's Algorithm)，设图G=(V,E)，起点s，最短路径数包含顶点集合为S。仅经由S内顶点s到i的最短路径成本为d[i],i在最短路径树中父节点p[i]。算法复杂度O(|V|^2)。若应用负权值，不可用，只能用贝尔-福特算法(O(|V||E|))或弗洛伊德算法。

1. 置空S，初始化d[s]=0,d[i]=无穷大。(若邻接表)以d[i]为键值，将V的顶点构建最小堆H
2. 循环以下直到S=V
   1. V-S中选d[u]最小的顶点u
   2. u添至S，u相邻且属于V-S的所有顶点按如下方法更新：若d[u]+w(u,v)<d[v]则d[v]=d[u]+w(u,v),p[v]=u；(若邻接表)以v为起点更新堆H

###### 朴素

```c++
#include <iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY  = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[MAX][MAX];
void dijkstra()
{
    int minv;
    int d[MAX], color[MAX];
    //d[v]是从起点到v的最短路径成本
    for(int i=0;i<n;i++)
    {
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[0] = 0;
    color[0] = GRAY;
    while(1)
    {
        minv = INFTY;
        int u = -1;
        for(int i=0;i<=n;i++)
        {
            if(minv>d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if(u==-1) break;
        color[u] = BLACK;
        for(int v=0;v<n;v++)
        {
            if(color[v] != BLACK && M[u][v] !=INFTY)
            {
                if(d[v] > d[u] + M[u][v])
                {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<" "<< (d[i]==INFTY?-1:d[i])<<endl;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) M[i][j] = INFTY;
    int k,c,u,v;
    for(int i=0;i<n;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {//有向图
            cin>>v>>c;
            M[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}

```

###### 邻接表-二叉堆

邻接表-二叉堆算法如下：

```c++
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY  = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n;
vector<pair<int,int>> adj[MAX];//加权有向图的邻接表表示法
void dijkstra()
{
    priority_queue<pair<int,int>>PQ;
    int color[MAX];
    int d[MAX];
    for(int i=0;i<n;i++)
    {
        d[i]=INFTY;
        color[i]=WHITE;
    }
    d[0] = 0;
    PQ.push(make_pair(0,0));
    color[0] = GRAY;
    while(!PQ.empty())
    {
        pair<int,int> f=PQ.top();
        PQ.pop();
        int u=f.second;
        color[u]=BLACK;
        if(d[u]<f.first*(-1))continue;//如果取出不是最小值就忽略
        for(int j=0;j<adj[u].size();j++)
        {
            int v=adj[u][j].first;
            if(color[v]==BLACK) continue;
            if(d[v]>d[u]+adj[u][j].second)
            {
                d[v]=d[u]+adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
                //因为优先级队列默认以最大优先，所以乘负一
                color[v] = GRAY;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<i<<" "<<(d[i]==INFTY?-1:d[i])<<endl;
}
int main()
{
    int k,u,v,c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            cin>>v>>c;
            adj[u].push_back(make_pair(v,c));
        }
    }
    dijkstra();
    return 0;
}
```

###### 链式前向星-堆

dijkstra+链式前向星+堆优化写法：

```c++
#include <bits/stdc++.h>
#define MAXN 100002
#define MAXM 200002
#define BIG (1<<31)-1
using namespace std;
struct edege
{
    int to,d,nx;
} e[MAXM];//如果无向图开二倍长
int hd[MAXN],d[MAXN],cnt;
bool vis[MAXN];
int n,m,s,ui,vi,wi;
inline void adde(int u, int v, int w)
{
    e[++cnt].d=w;
    e[cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
struct node
{
    int d,p;
    bool operator<(const node &x)const{return x.d<d;}
};//如果少后面的const就见祖宗
priority_queue<node> q;
void dijkstra()
{
    for(int i=1;i<=n;i++)d[i]=BIG;
    d[s]=0;
    q.push((node){0,s});//(node)可以去掉
    while(!q.empty())
    {
        node temp=q.top();
        q.pop();
        if(vis[temp.p]) continue;
        vis[temp.p]=true;
        for(int i=hd[temp.p];i;i=e[i].nx)
        {
            int to = e[i].to;
            if(d[temp.p]+e[i].d<d[to])
            {
                d[to]=d[temp.p]+e[i].d;
                if(!vis[to]) q.push((node){d[to],to});
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    while(m--)
    {
        scanf("%d%d%d",&ui,&vi,&wi);
        adde(ui,vi,wi);
    }//如果是无向图需要adde两次
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        if(i>1) printf(" ");
        printf("%d",d[i]);
    }
    return 0;
}
```

###### 链式前向星-线段树

dijkstra+线段树写法如下：

以求两点最短路为例。

```c++
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define go(i, j, n, k) for (int i = j; i <= n; i += k)
#define fo(i, j, n, k) for (int i = j; i >= n; i -= k)
#define rep(i, x) for (int i = h[x]; i; i = e[i].nxt)
#define mn 100010
#define mm 200020
#define inf 2147483647
#define ll long long
#define ld long double
#define fi first
#define se second
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define bson l, r, rt
inline int read(){
    int f = 1, x = 0;char ch = getchar();
    while (ch > '9' || ch < '0'){if (ch == '-')f = -f;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
inline void write(int x){
    if (x < 0)putchar('-'),x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + '0');
}
//This is AC head above...
struct node{
    int v, nxt, w;
} e[mm << 1];
int h[mn], p;
inline void add(int a,int b,int c){
    e[++p].nxt = h[a];
    h[a] = p;
    e[p].v = b;
    e[p].w = c;
}
int dis[mn];
int n, m, s, t;
struct tree{
    int minw, minv;
};
struct SegmentTree{
    tree z[mn << 2];
    inline void update(int rt){
        z[rt].minw = min(z[rt << 1].minw, z[rt << 1 | 1].minw);//维护区间最小值
        z[rt].minv = (z[rt << 1].minw < z[rt << 1 | 1].minw) ? z[rt << 1].minv : z[rt << 1 | 1].minv;//维护区间最小值位置
    }
    inline void build(int l,int r,int rt){//建树
        if(l==r){
            z[rt].minw = l == s ? 0 : inf;//我们可以直接建树时把s的点设置为0
            z[rt].minv = l;//记录最小值位置，方便修改
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        update(rt);
    }
    inline void modify(int l,int r,int rt,int now,int v){//单点修改
        if(l==r){
            z[rt].minw = v;
            return;
        }
        int m = (l + r) >> 1;
        if(now<=m)
            modify(lson, now, v);
        else
            modify(rson, now, v);
        update(rt);
    }
} tr;
inline void Dij(){//Dijkstra的核心部分
    go(i,1,n,1){
        dis[i] = inf;
    }//初始化dis
    dis[s] = 0;
    while(tr.z[1].minw < inf){//这里就是判断是否为空
        int x = tr.z[1].minv;//取整个线段树中最小的点
        tr.modify(root, x, inf);//单点修改最小的点为inf
        rep(i,x){
            int v = e[i].v;
            if(dis[v] > dis[x] + e[i].w){
                dis[v] = dis[x] + e[i].w;
                tr.modify(root, v, dis[x] + e[i].w);//这里就是类似入队操作
            }
        }
    }
}
int main(){
    n = read(), m = read(), s = read(), t=read();
    go(i,1,m,1){
        int x = read(), y = read(), v = read();
        add(x, y, v);
        add(y, x, v);//这个一定记住，无向图要正反两条边QAQ
    }
    tr.build(root);//建树
    Dij();//Dijkstra
    cout << dis[t];
    return 0;
}
```

##### bellman-ford/SPFA

bellman-ford算法是原算法，能找到某个结点出发到所有结点的最短路，或者报告某些最短路不存在。平均复杂度O(NM)。[应该不会卡到无限大]

可以使用队列优化，变成SPFA算法。平均复杂度为[nlogn]

> 关于SPFA
>
> ​	它死了

注意：存在数据能把该算法复杂度卡到无限。

还可以判定只经过k条边的最短路(bellman-ford跑k次)

##### 例题

###### Jump

> (scnu cgy)有$n(2\le n\le200)$块石头，坐标为$x_i,y_i\in Z\in[0,1000]$，且输入的第一和第二块石头分别是起点和终点。从起点跳到终点，使得每一次跳的距离尽可能小，求最小的每一次跳的最大距离。

个人解法：对石头建完全图，然后跑Kruscal重建最小生成树，然后在树上dfs从第一块走到第二块，记录dfs得到的起始路径走的每一个距离求max即可。(代码过长不予展示)

标准解法：跑变型的dijkstra，设$dis[i]$表示从原点到$i$的最长边最小值，松弛条件是：
$$
dis[j]=\min(dis[j],\max(dis[mink],ma[mink][j]))
$$

```c++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
double ma[210][210];
bool vis[210];
double dis[210];
int n,kase=1;
int x[210],y[210];
void init()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=inf;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(i==j)
                ma[i][j]=0;
            else
                ma[i][j]=inf;
    }
}
void dijkstra(int s)
{
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        int mink;
        double minl=inf;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&minl>dis[j])
            {
                minl=dis[j];
                mink=j;
            }
        }
        vis[mink]=true;
        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],max(dis[mink],ma[mink][j]));
        }
    }
}
double distance(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
            ma[i][j]=ma[j][i]=distance(x[i],y[i],x[j],y[j]);
    }
    dijkstra(1);
    printf("%.3f\n",dis[2]);
    return 0;
}
```



###### 最低手续费

> 有n个人,m对人之间可以**相互**转账，收取一定百分比手续费，求第i个人给第j个人转钱，要使j可以收到100元，i至少要转出多少钱。
>
> 输入n,m,输入m行x,y,z(x,y转账的百分比)，输入i,j,输出八位精度i转出钱额

踩过的坑：

- 最短转最长时重载函数没有换，BIG没有换
- 加法改为乘法时，0改成1疏漏，push最开始值没有改

```c++
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996 6031)
#define MAXN 2002
#define MAXE 200002
#define rep(i,a,b) for(int i=a;i<=b;++i)
const double BIG = -1;
struct edge
{
	int to, nx;
	double d;
} e[MAXE];
int hd[MAXN], cnt, n, ui, vi, bg, fin, m;
double wi, d[MAXN];
bool vis[MAXN];
inline void adde(int& u, int& v, double& w)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	e[cnt].d = w;
	hd[u] = cnt;
}
struct node
{
	double d;
	int p;
	bool operator<(const node& x)const { return x.d > d; }
};
priority_queue<node> q;
void dijkstra()
{
	rep(i, 1, n) d[i] = BIG;
	d[bg] = 1;
	q.push({ 1, bg });
	while (!q.empty())
	{
		node temp = q.top();
		q.pop();
		if (vis[temp.p]) continue;
		vis[temp.p] = true;
		for (int i = hd[temp.p]; i; i = e[i].nx)
		{
			int to = e[i].to;
			if (!vis[to] && d[temp.p] * e[i].d > d[to])
			{
				d[to] = d[temp.p] * e[i].d;
				if (!vis[to]) q.push({ d[to],to });
			}
		}
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		scanf("%d%d%lf", &ui, &vi, &wi);
		wi = (1 - wi / 100);
		adde(ui, vi, wi);
		adde(vi, ui, wi);
	}
	scanf("%d%d", &bg, &fin);
	dijkstra();
	printf("%.8lf", 100./d[fin]);
	return 0;
}
```

###### 紧急救援

> (天梯)给定点数n，边数m，起点s和终点d，给定各点点权，各边边权。求在边权最小的的路径数，在这些路径中点权最大的点权和以及路径(含起点和终点)($2\le n\le500$,点的编号从0开始)

跑Dijkstra最短路(优不优化均可)，注意在计算时dp存储点的最大点权和、最短路数目和路径。注意分类讨论，即更新最短路和增加最短路情况不一样，且点权和的更新仅存在与增加最短路情况。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 502
int n,m,s,d,hd[mn],cnt,peo[mn],vis[mn],cnp[mn],mis[mn],di[mn],ay[mn],ans[mn],ansi;
struct edge
{
    int to,nx,w;
} e[mn*mn];
inline void adde(int& u, int& v, int& w)
{
    e[++cnt]={v,hd[u],w};
    hd[u]=cnt;
}
struct node
{
    int d,p;
    inline bool operator<(const node& x)const{return x.d<d;}
};
priority_queue<node> pq;
void dijkstra()
{
    for(int i=1;i<=n;++i) di[i]=0x7ffffff;
    mis[s]=1;
    di[s]=0;
    cnp[s]=peo[s];
    pq.push({0,s});
    while(!pq.empty())
    {
        node tmp=pq.top(); pq.pop();
        if(vis[tmp.p]) continue;
        vis[tmp.p]=true;
        for(int i=hd[tmp.p];i;i=e[i].nx)
        {
            int toi=e[i].to;
            if(di[tmp.p]+e[i].w<di[toi])
            {
                di[toi]=di[tmp.p]+e[i].w;
                mis[toi]=mis[tmp.p];//这些tmp.p写成i都会暴死
                cnp[toi]=peo[toi]+cnp[tmp.p];
                ay[toi]=tmp.p;
                if(!vis[toi]) pq.push({di[toi],toi});
            }
            else if(di[tmp.p]+e[i].w==di[toi])
            {
                mis[toi]+=mis[tmp.p];
                if(cnp[toi]<cnp[tmp.p]+peo[toi])//暴死x2
                {
                    cnp[toi]=peo[toi]+cnp[tmp.p];
                    ay[toi]=tmp.p;
                }
                if(!vis[toi]) pq.push({di[toi],toi});
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d%d",&n,&m,&s,&d); ++s; ++d;
    for(int i=1;i<=n;++i) scanf("%d",peo+i);
    for(int ui,vi,wi,i=1;i<=m;++i)
    {
        scanf("%d%d%d",&ui,&vi,&wi);
        ++ui,++vi;
        adde(ui,vi,wi);
        adde(vi,ui,wi);
    }
    dijkstra();
    printf("%d %d\n%d",mis[d],cnp[d],s-1); int td=d;
    while(td!=s)
    {
        ans[ansi++]=td;
        td=ay[td];
    }
    for(int i=ansi-1;i>=0;--i) printf(" %d",ans[i]-1);
    return 0;
}
```



#### 全源最短路径

若存在负环，两点间成本可以无限缩小，无法定义最短路径，所以不可以存在负环。

弗洛伊德算法(Warshall-Floyd's Algorithm)，原本复杂度为O(|V|^3)，若使用优先级队列，可以简化到O(|V|(|E|+|V|)log|v|)

```c++
有待填坑
```

使用Johnson算法，开一个虚拟点求单源最短路径，再跑n次(堆优化的)Dijkstra，可以解决负边权的问题。(类似于势能转化)。复杂度是$\Omicron(nm\log m)$

##### 例题

###### 全源最短路径

> 求各点全源最短路径的加权和$\sum_{j=1}^nj\times d_{i,j}$，若路径不存在，设为$10^9$,含自环、重边、负边、闭环等。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5006
#define BIG 1000000000
struct edge { ll to, nx, w; } e[MAXN<<1];
struct node
{
	ll d, i;
	bool operator<(const node& x)const { return d > x.d; }
	node(ll x, ll y) { d = x, i = y; }
};
ll hd[MAXN], t[MAXN], cnt, n, m, h[MAXN], dis[MAXN], ui, vi, wi, ans;
bool vis[MAXN];
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,hd[u],w };
	hd[u] = cnt;
}
inline bool spfa(ll x)
{
	queue<ll> q;
	memset(h, 63, sizeof h);
	h[x] = 0, vis[x] = true; q.push(x);
	while (!q.empty())
	{
		ll y = q.front(); q.pop();
		vis[y] = false;
		for (ll i = hd[y]; i; i = e[i].nx)
		{
			ll z = e[i].to;
			if (h[z] > h[y] + e[i].w)
			{
				h[z] = h[y] + e[i].w;
				if (!vis[z])
				{
					vis[z] = true, ++t[z];
					q.push(z);
					//printf("%lld %lld\n", z, t[z]);
					if (t[z] > n) return false;
				}
			}
		}
	}
	return true;
}
inline void dijkstra(ll x)
{
	priority_queue<node> q;
	repe(i, 1, n) dis[i] = BIG;
	memset(vis, 0, sizeof vis);
	dis[x] = 0;
	q.push(node(0, x));
	while (!q.empty())
	{
		ll u = q.top().i; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (ll i = hd[u]; i; i = e[i].nx)
		{
			ll v = e[i].to;
			if (dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				if (!vis[v]) q.push(node(dis[v], v));
			}
		}
	}
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, m) scanf("%lld%lld%lld", &ui, &vi, &wi), adde(ui, vi, wi);
	repe(i, 1, n) adde(ans, i, ans);
	if (!spfa(0)) return !printf("-1");
	repe(u, 1, n) for (ll i = hd[u]; i; i = e[i].nx)
		e[i].w += h[u] - h[e[i].to];
	repe(i,1,n)
	{
		dijkstra(i);
		ans = 0;
		repe(j, 1, n)
		{
			if (dis[j] == BIG) ans += j * BIG;
			else ans += j * (dis[j] + h[j] - h[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```

###### 往返遍历最短路

> 有向无环正权图，从节点1出发，走n-1次，每次从1走到i,并从i走回1，求总最小路径。输入点数n边数m，m行输入有向加权边u,v,w

使用dijkstra算法走两遍，一次正路，一次反路，求出两种情况下1到各点的距离，求和。复杂度为dijkstra算法复杂度。

```c++
#include <bits/stdc++.h>
#define MAXN 2002
#define MAXM 200002
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define BIG 0x7fffffffffffffff
using namespace std;
typedef long long ll;
struct edge
{
    ll nx,to,d;
} e[MAXM];
ll hd[MAXN],cnt,n,m,d[MAXN],ui,vi,wi,ans,uj,vj;
inline void adde(ll &u, ll &v, ll &w)
{
    e[++cnt].d=w;
    e[cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
struct node
{
    ll x,d;
    node(ll a, ll b):x(a),d(b){}
    bool operator > (const node& o) const {return d>o.d;}
};
priority_queue<node,vector<node>,greater<node> > q;
void dijkstra(int s)
{
    rep(i,1,n<<1) d[i]=BIG;
    d[s]=0;
    q.push(node(s,0));
    while(!q.empty())
    {
        node temp=q.top(); q.pop();
        if(d[temp.x]<temp.d) continue;
        for(int i=hd[temp.x];i;i=e[i].nx)
        {
            int toi=e[i].to;
            if(d[toi]>temp.d+e[i].d)
            {
                d[toi]=temp.d+e[i].d;
                q.push(node(toi,d[toi]));
            }
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        scanf("%d%d%d",&ui,&vi,&wi);
        adde(ui,vi,wi);
        uj=ui+n;
        vj=vi+n;
        adde(vj,uj,wi);
    }
    dijkstra(1); rep(i,2,n) ans+=d[i]; 
    dijkstra(1+n); rep(i,2+n,n<<1) ans+=d[i]; 
    printf("%lld",ans);
    return 0;
}
```



#### 拓扑排序

BFS算法:

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
static const int MAX = 100000;
static const int INFTY = (1<<29);
vector<int> G[MAX];//有向图的邻接表
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];//入度
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    V[s] = true;//已经访问过
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        out.push_back(u);
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            indeg[v]--;//入度减一
            if(indeg[v]==0&&!V[v])
            {
                V[v] = true;//所有可能的访问完毕
                q.push(v);
            }
        }
    }
}

void tsort()
{
    for(int i=0;i<N;i++) indeg[i]=0;
    for(int u=0;u<N;u++)//初始化入度
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            indeg[v]++;
        }
    for(int u=0;u<N;u++)
        if(indeg[u] == 0 && !V[u]) bfs(u);
    for(list<int>::iterator it=out.begin();it!=out.end();it++)
        cout<<*it<<endl;
}

int main()
{
    int s,t,M;
    cin>>N>>M;
    for(int i=0;i<N;i++) V[i] = false;
    for(int i=0;i<N;i++)
    {
        cin>>s>>t;
        G[s].push_back(t);
    }
    tsort();
    return 0;
}
```

##### 例题

###### 食物链计数

链式前向星+BFS(拓补排序)

```c++
#include <bits/stdc++.h>
using namespace std;
#define MOD 80112002
#define MAXN 5002
#define MAXM 5000002
#define rep(i,a,b) for(int i=a;i<=b;++i)
int n,m,ans,h[MAXN],ind[MAXN],outd[MAXN],d[MAXN],ai,bi;
struct edge
{
    int a,b,n;
} e[MAXM];
queue<int> q;
signed main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        scanf("%d%d",&ai,&bi);
        e[i].a=ai;
        e[i].b=bi;
        e[i].n=h[ai];
        h[ai]=i;
        ind[bi]++;
        outd[ai]++;
    }
    rep(i,1,n)
    {
        if(!ind[i])
        {
            d[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ai=q.front();q.pop();
        for(int i=h[ai];i;i=e[i].n)
        {
            bi=e[i].b;
            d[bi]+=d[ai];
            d[bi]%=MOD;
            ind[bi]--;
            if(!ind[bi])
            {
                if(!outd[bi])
                {
                    ans+=d[bi];
                    ans%=MOD;
                }
                else q.push(bi);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
```

###### 排序

> 给定n个大写未知元，m条小于不等式，现判断：
> 如果经过前x条不等式可以确定n个元的大小关系，输出x和大小关系
> 如果到第x条关系开始存在矛盾，输出x
> 如果无法通过x条关系确立n个元的大小关系，输出无解

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define ALP 28
struct node
{
	ll u, v;//v代表层数
	node(ll u = 0, ll v = 0) :u(u), v(v) {}
};
vector<ll> g[ALP];
set<ll> s1;
string tp;
ll n, m, sum, ans, k, hs, in[ALP], in2[ALP], ui, vi;
inline void mk()//再拓扑一次输出
{
	queue<ll> q;
	ll rul[ALP];
	memset(rul, 0, sizeof(rul));
	rep(i, 0, 26) rep(j, 0, g[i].size()) ++rul[g[i][j]];
	rep(i, 0, 26) if (!rul[i] && s1.count(i))
	{
		q.push(i);
		cout << (char)(i + 'A');
	}
	while (!q.empty())
	{
		ll u = q.front(); q.pop();
		rep(i, 0, g[u].size())
		{
			ll v = g[u][i];
			--rul[v];
			if (!rul[v])
			{
				q.push(v);
				cout << (char)(v + 'A');
			}
		}
	}
}
void topo()
{
	queue<node> q;
	rep(i, 0, 26) if (!in[i] && s1.count(i))
	{
		q.push({ i,1 });
		++sum;
	}
	while (!q.empty())
	{
		ll u = q.front().u, x = q.front().v; q.pop();
		rep(i, 0, g[u].size())
		{
			ll v = g[u][i];
			--in[v];
			if (!in[v])
			{
				++sum;
				q.push({ v,x + 1 });
				ans = max(ans, x + 1);
			}
		}
	}
	if (ans == n)//拓扑出有n层(bfs树的层数为1~n均有且只有一个节点
	{
		cout << "Sorted sequence determined after " << k << " relations: ";
		mk();
		cout << ".";
		exit(0);
	}
	if (sum != hs)//拓扑无法遍历所有的点，则成环
	{
		cout << "Inconsistency found after " << k << " relations.";
		exit(0);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	repe(i, 1, m)
	{
		cin >> tp;
		k = i, ui = tp[0] - 'A', vi = tp[2] - 'A';
		g[ui].push_back(vi);
		s1.insert(ui);
		s1.insert(vi);
		hs = s1.size();
		++in2[vi];
		sum = ans = 0;
		memcpy(in, in2, sizeof in2);
		topo();
	}
	cout << "Sorted sequence cannot be determined.";
	return 0;
}
```

#### 最长路

##### 点权

题目大意：首先输入点数n，接下来n行，第一个值为点序号u，第二个值为点权重len，之后值为0前所有值v，代表有向边(v,u)。求从出发到结束的最大权重和。

###### dfs

个人版本，dfs+链式前向星

```c++
#include <bits/stdc++.h>
#define MAXN 10002
#define MAXE 1000002
using namespace std;
struct edge
{
    int to,nx;
} e[MAXE];
vector<int> beg;
int hd[MAXN],cnt,n,m[MAXN],ui,vi,d[MAXN],mx,vn;
inline void adde(int &u, int &v)
{
    e[++cnt].to=v;
    e[cnt].nx=hd[u];
    hd[u]=cnt;
}
void dfs(int h)
{
    for(int i=hd[h];i;i=e[i].nx)
    {
        int toi=e[i].to;
        if(d[toi]<d[h]+m[toi])
        {
            d[toi]=d[h]+m[toi];
            mx=max(d[toi],mx);
            dfs(toi);
        }
    }
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&ui,&m[i]);
        d[i]=m[i];
        vn=0;
        while(1)
        {
            scanf("%d",&vi);
            if(!vi)
            {
                if(!vn) beg.push_back(ui);
                break;
            }
            adde(vi,ui);
            vn++;
        }
    }
    for(auto h:beg)
    {
        dfs(h);
    }
    printf("%d",mx);
    return 0;
}
```

###### dp

上题中有一个条件(个人版本时漏看了)，v小于u。

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,t,ans[10005],maxans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&i);
        scanf("%d",&l);
        int tmp=0;
        while(scanf("%d",&t)&&t)
            tmp=max(ans[t],tmp);
        ans[i]=tmp+l;
        maxans=max(ans[i],maxans);
    } 
    printf("%d\n",maxans);
    return 0;
 } 
```

###### 记忆化搜索

da bk //p1113洛谷

###### 拓补排序

da bk saw

##### 边权

无环加权有向图(权值可负)，求序号为头尾的两点间最长路长。

特别注意，树的全源最长路径是树的直径，直接用两次dijkstra即可。

#### 网络流

在一个网络(有向图)里，弧可以有小于等于边权的流量$f(u,v)$，所有弧上流量的集合是一个**网络流**。

**网络流图**(flow network)满足以下条件：

1. 仅有一个入度为0的顶点s，称s为**源点**
2. 仅有一个出度为0的顶点t，称t为**汇点**
3. 每条边的权值都为非负数，称为该边的**容量**，记作c(i,j)。
4. 源点流出的流量等于流入汇点的流量和

流网络有如下性质：(是**可行流**)

1. 容量限制：对任意u,v∈V，0≤f(u,v)≤c(u,v)。
2. 反对称性：对任意u,v∈V，f(u,v) = -f(v,u)。从u到v的流量一定是从v到u的流量的相反值。(源点和汇点不必)。
3. 流守恒性：对任意u，若u不为S或T，一定有∑f(u,v)=0，(u,v)∈E。即u到相邻节点的流量之和为0，因为流入u的流量和u点流出的流量相等，u点本身不会"制造"和"消耗"流量。

**零流**：网络流上每条弧上的流量都为0。

**伪流**:如果一个网络流只满足弧流量限制条件,不满足平衡条件,则这种网络流为伪流,或称为容量可行流。

对于网络流图G，流量最大的可行流f，称为**最大流**。

弧的类型：

1. 饱和弧:即f(u,v)=c(u,v);

2. 非饱和弧:即f(u,v) < c(u,v)；

3. 零流弧:即f(u,v)=0;

4. 非零流弧:即f(u,v)>0.

5. ```
   a.前向弧:(方向与链的正方向一致的弧),其集合记为P+,
   b.后向弧:(方向与链的正方向相反的弧),其集合记为P-.
   ```

**链**: 在容量网络中,称顶点序列(u1,u2,u3,u4,..,un,v)为一条链，相邻的两个顶点之间有一条弧。

**割**: 将顶点分为两部分，起点在一部分$S$，终点在另一部分$\overline S$的弧的集合，称为割$(S,\overline S)$，**割的容量**是其边权(即容量)和。

P是从源点到汇点的一条链,若P满足以下条件，那么P是**增广路**：

```
a.P中所有前向弧都是非饱和弧,
b.P中所有后向弧都是非零弧.
```

沿着增广路改进可行流称为**增广**。

定义**残余流量**是容量减流量。

因为从顶点u到顶点v的流量减少,等效与从顶点v到顶点u的流量增加,所以每条弧< u,v>上还有一个反方向的残留容量cl(v,u)=-f(u,v)。

**残余网络** (Residual Network) 在一个网络流图上，找到一条源到汇的路径（即找到了一个流量）后，对路径上所有的边，其容量都减去此次找到的量，对路径上所有的边，都添加一条反向边，其容量也等于此次找到的流量，这样得到的新图，就称为原图的“残余网络”

最大流最小割定理(Maximum Flow, Minimum Cut Theorem): 网络的最大流等于最小割。

##### 最小割

> 给定无向图G，最小割为一个去掉后可以使 G变成两个连通分量，且边权和最小的边集的边权和。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 602
#define BIG 1000000002
ll n, m, x, y, z, s, t, dis[MAXN][MAXN], w[MAXN], dap[MAXN], vis[MAXN], ord[MAXN];
ll proc(ll x)
{
	memset(vis, 0, sizeof vis);
	memset(w, 0, sizeof w);
	w[0] = -1;
	repe(i, 1, n - x + 1)
	{
		ll mx = 0;
		repe(j, 1, n) if (!dap[j] && !vis[j] && w[j] > w[mx]) mx = j;
		vis[mx] = 1, ord[i] = mx;
		repe(j, 1, n) if (!dap[j] && !vis[j]) w[j] += dis[mx][j];
	}
	s = ord[n - x], t = ord[n - x + 1];
	return w[t];
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m) scanf("%d%d%d", &x, &y, &z), dis[x][y] += z, dis[y][x] += z;
	ll res = BIG;
	rep(i, 1, n)
	{
		res = min(res, proc(i));
		dap[t] = 1;
		repe(j, 1, n) dis[s][j] += dis[t][j], dis[j][s] += dis[j][t];
	}
	printf("%d", res);
	return 0;
}
```



常规的最大流算法：

##### 实现

###### Edmonds-Karp最短增广路算法

时间复杂度$\Omicron(nm^2)$

```c++
//codevs 1993
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x7ffffff;

queue <int> q;
int n,m,x,y,s,t,g[201][201],pre[201],flow[201],maxflow; 
//g邻接矩阵存图，pre增广路径中每个点的前驱，flow源点到这个点的流量 

inline int bfs(int s,int t)
{
	while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++) pre[i]=-1;
    pre[s]=0;
    q.push(s);
    flow[s]=INF;
    while (!q.empty())
	{
        int x=q.front();
        q.pop();
		if (x==t) break;
		for (int i=1; i<=n; i++)
          //EK一次只找一个增广路 
		  if (g[x][i]>0 && pre[i]==-1)
		  {
			pre[i]=x;
			flow[i]=min(flow[x],g[x][i]);
			q.push(i);
          }
	}
	if (pre[t]==-1) return -1;
	else return flow[t];
}

//increase为增广的流量 
void EK(int s,int t)
{
	int increase=0;
	while ((increase=bfs(s,t))!=-1)//这里的括号加错了！Tle 
	{//迭代 
		int k=t;
		while (k!=s)
		{
			int last=pre[k];//从后往前找路径
			g[last][k]-=increase;
			g[k][last]+=increase;
			k=last;
		}
		maxflow+=increase;
	}
}

int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1; i<=m; i++)
	{
		int z;
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]+=z;//此处不可直接输入，要+= 
	}
	EK(1,n);
	printf("%d",maxflow);
	return 0;
}
```

###### Dinic算法

普通图$\Omicron(n^2m)$，二分图$\Omicron(m\sqrt n)$

```c++
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;

int n,m,x,y,z,maxflow,deep[500];//deep深度 
struct Edge{
	int next,to,dis;
}edge[500];
int num_edge=-1,head[500],cur[500];//cur用于复制head 
queue <int> q;

void add_edge(int from,int to,int dis,bool flag)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	if (flag) edge[num_edge].dis=dis;//反图的边权为 0
	head[from]=num_edge;
}

//bfs用来分层 
bool bfs(int s,int t)
{
	memset(deep,0x7f,sizeof(deep));
	while (!q.empty()) q.pop();
	for (int i=1; i<=n; i++) cur[i]=head[i];
	deep[s]=0;
	q.push(s);
	
 	while (!q.empty())
	{
		int now=q.front(); q.pop();
 		for (int i=head[now]; i!=-1; i=edge[i].next)
		{
			if (deep[edge[i].to]>inf && edge[i].dis)//dis在此处用来做标记 是正图还是返图 
			{
				deep[edge[i].to]=deep[now]+1;
				q.push(edge[i].to);
			}
		}
	}
	if (deep[t]<inf) return true;
	else return false;
}

//dfs找增加的流的量 
int dfs(int now,int t,int limit)//limit为源点到这个点的路径上的最小边权 
{
	if (!limit || now==t) return limit;
	
	int flow=0,f;
	for (int i=cur[now]; i!=-1; i=edge[i].next)
	{
		cur[now]=i;
		if (deep[edge[i].to]==deep[now]+1 && (f=dfs(edge[i].to,t,min(limit,edge[i].dis))))
		{
			flow+=f;
			limit-=f;
			edge[i].dis-=f;
			edge[i^1].dis+=f;
			if (!limit) break;
		}
	}
	return flow;
}

void Dinic(int s,int t)
{
	while (bfs(s,t))
		maxflow+=dfs(s,t,inf);
}

int main()
{
//	for (int i=0; i<=500; i++) edge[i].next=-1;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z,1); add_edge(y,x,z,0);
	}
	Dinic(1,n);
 	printf("%d",maxflow);
	return 0;
}
```

###### ISAP算法

（Improved Shortest Augmenting Path)

```c++
//codevs上还是WA一个点 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1e9;

queue <int> q;
int m,n,x,y,z,maxflow,head[5000],num_edge=-1;
int cur[5000],deep[5000],last[5000],num[5000];
//cur当前弧优化； last该点的上一条边； num桶 用来GAP优化 
struct Edge{
	int next,to,dis;
}edge[500];

void add_edge(int from,int to,int dis,bool flag)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}

//bfs仅用于更新deep 
void bfs(int t)
{
	while (!q.empty()) q.pop();
	for (int i=0; i<=m; i++) cur[i]=head[i];
	for (int i=1; i<=n; i++) deep[i]=n;
	deep[t]=0;
	q.push(t);
	
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int i=head[now]; i!=-1; i=edge[i].next)
		{
			if (deep[edge[i].to]==n && edge[i^1].dis)//i^1是为了找反边 
			{
				deep[edge[i].to]=deep[now]+1;
				q.push(edge[i].to);
			}
		}
	}
}

int add_flow(int s,int t)
{
	int ans=inf,now=t;
	while (now!=s)
	{
		ans=min(ans,edge[last[now]].dis);
		now=edge[last[now]^1].to;
	}
	now=t;
	while (now!=s)
	{
		edge[last[now]].dis-=ans;
		edge[last[now]^1].dis+=ans;
		now=edge[last[now]^1].to;
	}
	return ans;
}

void isap(int s,int t)
{
	int now=s;
	bfs(t);//搜出一条增广路
	for (int i=1; i<=n; i++) num[deep[i]]++;
	
	while (deep[s]<n)
	{
		if (now==t)
		{//如果到达汇点就直接增广，重新回到源点进行下一轮增广 
			maxflow+=add_flow(s,t);
			now=s;//回到源点 
		}
		
		bool has_find=0;
		for (int i=cur[now]; i!=-1; i=edge[i].next)
		{
			if (deep[now]==deep[edge[i].to]+1 && edge[i].dis)//找到一条增广路 
			{
				has_find=true;
				cur[now]=i;//当前弧优化
				now=edge[i].to;
				last[edge[i].to]=i;
				break;
			}
		}
		
		if (!has_find)//没有找到出边，重新编号 
		{
			int minn=n-1;
			for (int i=head[now]; i!=-1; i=edge[i].next)//回头找路径 
				if (edge[i].dis)
					minn=min(minn,deep[edge[i].to]);
			if ((--num[deep[now]])==0) break;//GAP优化 出现了断层 
			num[deep[now]=minn+1]++;
			cur[now]=head[now];
			if (now!=s)
				now=edge[last[now]^1].to;
		}
	}
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z,1); add_edge(y,x,z,0); 
	}
	isap(1,n);
	printf("%d",maxflow);
	return 0;
}
```

##### 例题

###### 最大流

> 给定n点m有向边，求最大流

优化版本(可以解决自环，且速度快)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 202
#define me 10002
ll n, m, s, t, hd[mn], cnt = 1, ui, vi, wi, res, tot, dep[mn];
ll q[mn], lf, rf;
struct edge { ll to, v, nx; } e[me];
bool vis[mn];
il void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,w,hd[u] }; hd[u] = cnt;
}
bool bfs()
{
	memset(dep, 0, (n + 2) * (sizeof ll));
	q[lf = rf = 1] = s; dep[s] = 1;
	while (lf <= rf)
	{
		ll u = q[lf++];
		for (ll i = hd[u]; i; i = e[i].nx)
		{
			ll v = e[i].to;
			if (e[i].v && !dep[v]) dep[v] = dep[u] + 1, q[++rf] = v;
		}
	}
	return dep[t];
}
ll dfs(ll u, ll flow)
{
	if (u == t) return flow;
	ll out = 0;
	for (ll i = hd[u]; i; i = e[i].nx)
	{
		ll v = e[i].to;
		if (e[i].v && dep[v] == dep[u] + 1)
		{
			ll res = dfs(v, min(e[i].v, flow));
			e[i].v -= res;
			e[i ^ 1].v += res;
			out += res;
			flow -= res;
		}
	}
	return !out ? (dep[u] = 0) : out;
}
signed main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	repe(i, 1, m)
	{
		scanf("%lld%lld%lld", &ui, &vi, &wi);
		adde(ui, vi, wi), adde(vi, ui, tot);
	}
	while (bfs()) tot += dfs(s, 1e18);
	printf("%lld", tot);
	return 0;
}
```



未优化版本：不能解决自环，效率低

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 202
#define me 10002
ll n, m, s, t, hd[mn], cnt = 1, ui, vi, wi, res, tot;
struct edge { ll to, v, nx; } e[me];
bool vis[mn];
il void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,w,hd[u] }; hd[u] = cnt;
}
ll dfs(ll u, ll flow)
{
	if (u == t) return flow;
	vis[u] = true;
	for (ll i = hd[u]; i; i = e[i].nx)
	{
		ll v = e[i].to, res = 0;
		if (!e[i].v || vis[v]) continue;
		if ((res = dfs(v, min(flow, e[i].v))) > 0)
		{
			e[i].v -= res; e[i ^ 1].v += res;
			return res;
		}
	}
	return 0;
}
signed main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	repe(i, 1, m)
	{
		scanf("%lld%lld%lld", &ui, &vi, &wi);
		adde(ui, vi, wi), adde(vi, ui, tot);
	}
	while (memset(vis, 0, sizeof vis) && (res = dfs(s, 1e18)) > 0)
		tot += res;
	printf("%lld", tot);
	return 0;
}
```



###### 最小费用最大流

> 给定n点m边网络，每边均有流量限制和单位流量费用。流量费用为流量乘单位流量费用。求流量最大时的最小费用。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
bool vis[MAXN];
ll n, m, s, t, x, y, z, f, dis[MAXN], pre[MAXN], last[MAXN], flow[MAXN];
ll mxflow, micost, cnt, hd[MAXN];
struct edge { ll to, nx, f, d; } e[MAXN];
queue<ll> q;
inline void adde(ll& u, ll& v, ll f, ll d)
{
	e[++cnt] = { v,hd[u],f,d };
	hd[u] = cnt;
}
inline bool spfa(ll s, ll t)
{
	memset(dis, 0x7f, sizeof dis);
	memset(flow, 0x7f, sizeof flow);
	memset(vis, 0, sizeof vis);
	q.push(s);
	vis[s] = true, dis[s] = 0, pre[t] = -1;
	while (!q.empty())
	{
		ll no = q.front(); q.pop();
		vis[no] = false;
		for (ll i = hd[no]; i != -1; i = e[i].nx)
		{
			ll toi = e[i].to;
			if (e[i].f > 0 && dis[toi] > dis[no] + e[i].d)
			{
				dis[toi] = dis[no] + e[i].d;
				pre[toi] = no;
				last[toi] = i;
				flow[toi] = min(e[i].f, flow[no]);
				if (!vis[toi]) vis[toi] = true, q.push(toi);
			}
		}
	}
	return pre[t] != -1;
}
inline void mcmf()
{
	while (spfa(s, t))
	{
		ll no = t;
		mxflow += flow[t];
		micost += flow[t] * dis[t];
		while (no != s)
		{
			e[last[no]].f -= flow[t];
			e[last[no] ^ 1].f += flow[t];
			no = pre[no];
		}
	}
}
signed main()
{
	memset(hd, -1, sizeof hd); cnt = -1;//因为有异或操作，从0开始，否则TLE
	scanf("%d%d%d%d", &n, &m, &s, &t);
	repe(i, 1, m)
	{
		scanf("%d%d%d%d", &x, &y, &z, &f);
		adde(x, y, z, f);
		adde(y, x, 0, -f);
	}
	mcmf();
	printf("%d %d", mxflow, micost);
	return 0;
}
```





#### 二分图

二分图是一个图的两个子图，其点集不重合且不遗漏。

匹配是没有公共点的边集。

性质：

1. 二分图的最小顶点覆盖 最小顶点覆盖要求用最少的点(U或V中都行)，让每条边都至少和其中一个点关联。 Knoig定理：二分图的最小顶点覆盖数等于二分图的最大匹配数。
2. DAG图的最小路径覆盖 用尽量少的不相交简单路径覆盖有向无环图(DAG)G的所有顶点。 引理：DAG图的最小路径覆盖数=节点数(n)-最大匹配数(m)
3. 二分图的最大独立集 在Ｎ个点的图G中选出m个点，使这m个点两两之间没有边．求m最大值。 引理：二分图的最大独立集数 = 节点数(n)—最大匹配数(m)
4. 二分图不存在长度为奇数的环。

一个有向图可以转化为一个二分图，方法为将每个点拆成vx和vy，如果存在有向边，将起点设为原起点的vx，终点设为原终点的vy，即对存图稍作改变。

##### 最大匹配

> 求二分图最大匹配的边数，左右点数为n,m，边数为e。

###### 匈牙利算法

时间复杂度$\Omicron(n\times e+m)$，每次找到则立刻匹配，并尝试让原配让位(无法让位则找下一个)。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1002
ll n, m, t, mch[MAXN], visst[MAXN], ui, vi, ans;
vector<ll> e[MAXN];
bool dfs(ll u, ll tag)
{
	if (visst[u] == tag) return false;
	visst[u] = tag;
	for (auto v : e[u]) if ((mch[v] == 0) || dfs(mch[v], tag))
		return mch[v] = u, true;
	return false;
}
signed main()
{
	scanf("%d%d%d", &n, &m, &t);
	while (t--) scanf("%d%d", &ui, &vi), e[ui].push_back(vi);
	repe(i, 1, n) if (dfs(i, i)) ++ans;
	return !printf("%d", ans);
}
```

版本2：

```c++
#define mn 102
struct edge{ll to,nx;} e[mn];
ll ui,vi,m,n,k,mch[mn],cnt,hd[mn];
bool vis[mn];
bool dfs(ll h)
{
    ll toi;
    for(ll i=hd[h];i;i=e[i].nx)
    {
        toi=e[i].to;
        if(!vis[toi])
        {
            vis[toi]=1;
            if(!mch[toi]||dfs(mch[toi])) {return mch[toi]=h,true;}//写成dfs(toi)心肺骤停
        }
    }
    return false;
}
signed main()
{
    m=read();n=read();
    while(1)
    {
        ui=read();vi=read();
        if(ui==-1&&vi==-1) break; if(ui>m||vi>n) continue;
        e[++cnt]={vi,hd[ui]}; hd[ui]=cnt;
    }
    repe(i,1,m)
    {
        memset(vis,0,sizeof vis);
        if(dfs(i))
            ++k;
    }
    printf("%lld\n",k);
    repe(i,m+1,n) if(mch[i]) printf("%lld %lld\n",mch[i],i);
    return 0;
}
```

理论上两种版本都可行，且效率差不多；但是强烈建议使用第二个版本，第一个版本的代码往往会有各种神奇的离谱问题。



###### dinic算法

时间复杂度$\Omicron(n\sqrt e)$

建立超级源点和超级汇点，源点向左侧连边，右侧向汇点连边。左右之间连边。上述边的流量都是 1 。由于 s 到点左侧任意一点 u 的流量是1，所以 u最多被选择一次。同理右边的点也最多被选择一次。于是这个图的网络最大流即为该二分图的最大匹配。

```c++
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 2147483647
using namespace std;
struct Edge
{
    int to;
    int s;
    int last;
}e[2001000];
int dep[4100],in[4100],cnt;
int s=0,t;
void addedge(int x,int y,int z)
{
    e[++cnt].last=in[x];
    e[cnt].s=z;
    e[cnt].to=y;
    in[x]=cnt;
}
bool bfs()
{
    memset(dep,0,sizeof(dep));
    queue<int> que;
    que.push(s);dep[s]=1;
    while(!que.empty())
    {
        int u=que.front();que.pop();
        for(int i=in[u];i>=0;i=e[i].last)
        {
            if(!dep[e[i].to]&&e[i].s>0)
            {
                dep[e[i].to]=dep[u]+1;
                que.push(e[i].to);
            }
        }
    }
    if(dep[t])    return true;
    else    return false;
}
int dfs(int now,int cur)
{
    if(now==t)    return cur;
    for(int i=in[now];i>=0;i=e[i].last)
    {
        if(dep[e[i].to]==dep[now]+1&&e[i].s>0)
        {
            int flow=dfs(e[i].to,min(cur,e[i].s));
            if(flow)
            {
                e[i].s-=flow;
                if(i&1)    e[i+1].s+=flow;
                else    e[i-1].s+=flow;
                return flow;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m,e,i,l,x,y,ans=0;
    memset(in,-1,sizeof(in));
    scanf("%d%d%d",&n,&m,&e);t=n+m+1;
    for(i=1;i<=n;i++){addedge(0,i,1);addedge(i,0,0);}
    for(i=n+1;i<=n+m;i++){addedge(i,t,1);addedge(t,i,0);}
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);if(x>n||y>m)    continue;
        addedge(x,y+n,1);addedge(y+n,x,0);
    }
    while(bfs())
    {
        while(l=dfs(s,inf))
            ans+=l;
    }
    printf("%d",ans);
    return 0;
}
```

##### 最小路径覆盖

DAG的最小不相交路径覆盖：

对一个DAG拆点设二分新图。最小不相交路径覆盖=原图节点数-新图最大匹配数

最大匹配使用匈牙利算法求解。

DAG的最小可相交路径覆盖：

先用floyd求原图的传递闭包，然后求这个闭包的最小不相交路径覆盖。

参考代码分别如下：

###### POJ1422

```c++
//
//  main.cpp
//  POJ1422最小不想交路径覆盖
 
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 200 + 10;
vector<int> g[N];
int cy[N];
bool vis[N];
bool dfs(int u)
{
    for(int i=0; i<g[u].size(); ++i)
    {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(cy[v]==-1 || dfs(cy[v])){
            cy[v] = u;
            return true;
        }
    }
    return false;
}
int solve(int n)
{
    int ret = 0;
    memset(cy, -1, sizeof(cy));
    for(int i=1;i<=n;++i)
    {
        memset(vis, 0, sizeof(vis));
        ret += dfs(i);
    }
    return n - ret;
}
int main( )
{
    int t,n,m;
    int u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            g[i].clear();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        
        int ans = solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
```

###### POJ2594

```c++
//
//  main.cpp
//  POJ2594最小可相交路径覆盖
//
//  Created by beMaster on 16/4/8.
//  Copyright © 2016年 beMaster. All rights reserved.
//
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 500 + 10;
bool dis[N][N];
bool vis[N];
int cy[N];
void floyd(int n){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(dis[i][k] && dis[k][j])//传递可达性
                    dis[i][j] = true;
}
bool dfs(int u, int n){
    for(int i=1;i<=n;++i){
        if(!vis[i] && dis[u][i]){
            vis[i] = true;
            if(cy[i]==-1 || dfs(cy[i], n)){
                cy[i] = u;
                return true;
            }
        }
    }
    return false;
}
int solve(int n){
    int cnt = 0;
    memset(cy,-1,sizeof(cy));
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof(vis));
        cnt += dfs(i, n);
    }
    return n - cnt;
}
int main( ) {
    int n,m;
    int a,b;
    while(scanf("%d%d",&n,&m),n+m){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j] = false;
        for(int i=1;i<=m;++i){
            scanf("%d%d",&a,&b);
            dis[a][b] = true;
        }
        floyd(n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
```

###### 估计人数

> (蓝桥)有$n\times m$方格矩阵，若标记为$0$没人踩过，否则有人踩过；人可以从任意方格开始，之后每一步只能向右或向下走一格，走了若干步之后，可以离开矩阵，求至少多少人在矩阵上走过。($1\le n,m\le20,len(1)\le 200$)

右线段和下线段连有向边，然后直接跑最小可相交路径覆盖模板即可。

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=30;
char g[N][N];
int cnt;
int match[N*N];
bool st[N*N];
int num[N][N];
bool h[N*N][N*N];
bool dfs(int u){
	for(int j=1;j<=cnt;j++){
		if(!h[u][j]) continue;
		if(!st[j]){
			st[j]=1;
			if(!match[j]||dfs(match[j])){
				match[j]=u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='1') num[i][j]=++cnt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='1'&&g[i][j+1]=='1') h[num[i][j]][num[i][j+1]]=1;
			if(g[i][j]=='1'&&g[i+1][j]=='1') h[num[i][j]][num[i+1][j]]=1;
 		}
	}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				h[i][j]|=(h[i][k]&&h[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		memset(st,false,sizeof st);
		if(dfs(i)) ans++;
	}
	printf("%d\n",cnt-ans);
	return 0;
}
```



##### 二分图最大权完美匹配

定义：二分图，两边顶点相同，求完美匹配(连$n$条边使得每个顶点都连上一条边)，使得边权和最大。(不要求完全二分图)

使用KM算法，Kuhn-Munkres Algorithm，时间复杂度是$\Omicron(n^3)$，非随机数据有概率被卡到$\Omicron(n^4)$。



###### 模板题

> $n=500$，$long\ \ long$内。输出最大权和每个左点所匹配的右点。

有两种写法，一个是BFS(洛谷较稳，过了板子)，如下：

```c++
#include <bits/stdc++.h>
#define re
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 504
#define big 0x7fffffffffffffff
ll n, m, e[mn][mn], mb[mn], vb[mn], ka[mn], kb[mn], p[mn], c[mn];
ll qf, qb, q[mn], u, v, w;

void bfs(ll u)
{
    ll a, v = 0, v1 = 0, d;
    fill(p + 1, p + n + 1, 0), fill(c + 1, c + n + 1, big), mb[v] = u;
    do
    {
        a = mb[v], d = big, vb[v] = 1;
        for (ll b = 1; b <= n; ++b)
        {
            if (!vb[b])
            {
                if (c[b] > ka[a] + kb[b] - e[a][b])
                {
                    c[b] = ka[a] + kb[b] - e[a][b], p[b] = v;
                }
                if (c[b] < d)
                {
                    d = c[b], v1 = b;
                }
            }
        }
        for (ll b = 0; b <= n; ++b)
        {
            if (vb[b])
            {
                ka[mb[b]] -= d, kb[b] += d;
            }
            else
            {
                c[b] -= d;
            }
        }
        v = v1;
    } while (mb[v]);
    while (v)
    {
        mb[v] = mb[p[v]], v = p[v];
    }
}

ll km()
{ //memset mb,ka,kb->0
    for (ll a = 1; a <= n; ++a)
    {
        fill(vb, vb + n + 1, 0);
        bfs(a);
    }
    ll res = 0;
    for (ll b = 1; b <= n; ++b)
    {
        res += e[mb[b]][b];
    }
    return res;
}

signed main()
{
    n = read(), m = read();
    memset(e, -127, sizeof e); //-big或-1暴毙
    while (m--)
    {
        ll u = read(), v = read(), w = read();
        e[u][v] = max(e[u][v], w);
    }
    printf("%lld\n", km());
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", mb[i]);
    }
    return 0;
}
```

DFS写法：(过不了这道题)

```c++
#include <bits/stdc++.h>
#define re
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 504
#define big 0x7ffffffffffffffa
ll n, m, e[mn][mn], mat[mn], d[mn], va[mn], vb[mn], ak[mn], bk[mn];
bool dfs(ll u) //匈牙利
{
    va[u] = 1;
    for (ll v = 1; v <= n; ++v)
    {
        if (!vb[v])
        {
            if (ak[u] + bk[v] - e[u][v] == 0)
            {
                vb[v] = 1;
                if (!mat[v] || dfs(mat[v]))
                {
                    mat[v] = u;
                    return true;
                }
            }
            else
            {
                d[v] = min(d[v], ak[u] + bk[v] - e[u][v]);
            }
        }
    }
    return false;
}
ll km()
{
    fill(ak + 1, ak + 1 + n, -big);
    for (ll u = 1; u <= n; ++u)
    {
        for (ll v = 1; v <= n; ++v)
        {
            ak[u] = max(ak[u], e[u][v]);
        }
    }
    for (ll u = 1; u <= n; ++u)
    {
        while (true)
        {
            fill(va + 1, va + 1 + n, 0);
            fill(vb + 1, vb + 1 + n, 0);
            fill(d + 1, d + 1 + n, big);
            if (dfs(u))
            {
                break;
            }
            ll c = big;
            for (ll v = 1; v <= n; ++v)
            {
                if (!vb[v])
                {
                    c = min(c, d[v]);
                }
            }
            for (ll v = 1; v <= n; ++v)
            {
                if (va[v])
                {
                    ak[v] -= c;
                }
            }
            for (ll v = 1; v <= n; ++v)
            {
                if (vb[v])
                {
                    bk[v] += c;
                }
            }
        }
    }
    ll res = 0;
    for (ll v = 1; v <= n; ++v)
    {
        res += e[mat[v]][v];
    }
    return res;
}

signed main()
{
    n = read(), m = read();
    memset(e, -1, sizeof e); //-big暴毙
    while (m--)
    {
        ll u = read(), v = read(), w = read();
        e[u][v] = max(e[u][v], w);
    }
    printf("%lld\n", km());
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld ", mat[i]);
    }
    return 0;
}
```





##### 例题

###### Tree Constructer

> (icpc 45济南 J)
>
> MianKing has a Graph Constructer : The input of it is a sequence $a_{1...n}~(0\leq a_i<2^{60})$ and the output of it is an undirected graph with n nodes, edge (x,y) is in this graph if and only if$(a_x~or~a_y)=2^{60}-1$
>
>  For example, if the input is $a_{1...3}=\{2^{60}-1,2^{60}-2,1\}$, the output is the graph {(1,1),(1,2),(1,3),(2,3)}
>
>  Now GreenKing has a tree with n nodes, MianKing wants to find a sequence as input to get this tree. You need to help him find a sequence satisfy the condition.
>
> The first line has one integer n.
>
> Then there are n−1 lines, each line has two integers (x,y) denotes an edge in the tree.$1\leq n\leq 100$
>
> Output n integers $a_{1...n}$ denotes the sequence you find.
>
> You should guaranteed that $0\leq a_i<2^{60}$
>
> It's guaranteed that the solution always exists.

不能够直接一位一个点的压缩状态，因为一共就$60$个位可用，但有100个点。可以采用二分图法，二分图后必然存在一部分的点少于$60$个，对于这一部分，可以采用一位对应一个点的方法。

令较少的部分为白色，最高位置0，在二分图中的序号位也置0，其余为1，保证白色点互相不会有边(因为最高位为0)，由于白色位数目必然少于$50$，所以是不会超过位的存储范围。

其余部分为黑色，最高位为1，所有与其相连的白色部分点序号位置1，其余置0，所以黑色点与白色点相连，且除非黑色点与所有白色点相连，否则黑色点之间不会相连，保证了黑色部分互相不连边

个人版代码如下：(BFS构造二分图)(参考答案更优)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld",&x)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define mn 110
struct edge
{
    ll to,nx;
} e[mn*mn];
struct po
{
    ll h,np;
};
ll hd[mn],cnt,n,pn[2],p[2][mn],u,v,cw,vis[mn],con[mn][mn],a[mn];
queue<po> q;
inline void adde(ll& u, ll& v)
{
    e[++cnt]={v,hd[u]};
    hd[u]=cnt;
}
signed main()
{
    sc(n);
    rep(i,1,n)
    {
        sc(u),sc(v);
        adde(u,v),adde(v,u);
        con[u][v]=con[v][u]=true;
    }
    q.push({e[1].to,0});
    while(!q.empty())
    {
        po t=q.front();
        q.pop();
        vis[t.h]=true;
        p[t.np][pn[t.np]++]=t.h;
        for(ll i=hd[t.h];i;i=e[i].nx)
        {
            ll j=e[i].to;
            if(vis[j]) continue;
            q.push({j,t.np^1});
        }
    }
    cw=pn[0]>pn[1]?1:0;
    rep(i,0,pn[cw])
    {
        a[p[cw][i]]=((1LL<<60)-1)^(1LL<<i)^(1LL<<59);//不开LL见祖宗
    }
    cw^=1;
    rep(i,0,pn[cw])
    {
        a[p[cw][i]]=1LL<<59;
        rep(j,0,pn[cw^1])
        {
            if(con[p[cw][i]][p[cw^1][j]])
            {
                a[p[cw][i]]|=1LL<<j;
            }
        }
    }
    repe(i,1,n)
    {
        printf("%lld ",a[i]);
    }
    return 0;
}

```

参考答案(DFS)版：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 2;
vector<int> g[N], x[M];
ll w[N], pos[N];
void dfs(int u, int fa, int c)
{
    x[c].push_back(u);
    for (int v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u, 1 - c);
    }
}

int main()
{
    ll n, m = (1ll << 60ll);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 0);
    for (int i = 0; i < x[0].size(); i++)
    {
        int v = x[0][i];
        ll id = (1ll << i);
        pos[v] = i;
        w[v] = m - (1ll << 59ll) - id - 1;
    }
    for (int i = 0; i < x[1].size(); i++)
    {
        int u = x[1][i];
        w[u] = (1ll << 59ll);
        for (int v : g[u])
            w[u] += (1ll << pos[v]);
    }
    for (int i = 1; i <= n; i++)
        cout << w[i] << ' ';
}
```

###### 座位安排

> 有$n$排双人座位和$2n$个人，每个人有两个想坐的排数，求最多多少人可以坐到自己想坐的位置($n\le2000$)

使用匈牙利算法变式一下即可。本题必须要用写法二，写法一会炸，原因未知。

```c++
#define mn 4096
struct edge {ll to,nx;} e[mn<<1];
ll m,n,hd[mn],cnt,ui,vi,vis[mn],t,mch[mn][2];
bool dfs(ll u)
{
    for(ll i=hd[u];i;i=e[i].nx)
    {
        ll v=e[i].to;
        if(vis[v]) continue;
        vis[v]=true;
        repe(j,0,1) if(!mch[v][j]||dfs(mch[v][j])) return mch[v][j]=u,true;
    }
    return false;
}
signed main()
{
    n=read(); n<<=1;
    repe(i,1,n)
    {
        ui=read();vi=read();
        e[++cnt]={ui,hd[i]}; hd[i]=cnt;
        e[++cnt]={vi,hd[i]}; hd[i]=cnt;
    }
    repe(i,1,n)
    {
        memset(vis,0,sizeof vis);
        if(dfs(i)) ++t;
    }
    printf("%lld\n",t);
	return 0;
}

```



###### 宫廷守卫

> 有$m$行$n$列方格城堡，$2$是墙，$1$是陷阱，$0$是空地。一个空地可以放至多一个守卫，守卫会攻击同行同列的人；如果两个守卫同行或同列且他们之间没有墙，他们就可以互相看见。给定$m,n$和城堡，求最多可以放多少个守卫以及每个守卫的位置。($1\le m,n\le 200$)

对于每个被墙隔开的行和列（如果不可以放守卫就不建行/列也行），从1进行编号；然后遍历每个空地，对该空地的行号和列号分别为二分图左部和右部顶点，连一条边，构建二分图。边的意义为行列相交的一个交点，如果对二分图求匹配，根据匹配的性质，一行和一列只能被一条匹配边占据，而求最大匹配，即要求在一行或一列只能被一条被占据的前提下边最多，即为题目所求。

用匈牙利算法跑二分图的最大匹配。之后再次遍历空地，如果发现空地的行列号刚好跟匹配对应上了，那么证明这个空地是最大匹配的一部分，输出这个空地。最大匹配数即守卫数。

```c++
#define mn 210
ll n,m,k,a[mn][mn],r[mn][mn],c[mn][mn],rn,cn,visst[mn*mn],mch[mn*mn];
vector<ll> e[mn*mn];
bool dfs(ll u, ll tag)
{
    if(visst[u]==tag) return false;
    visst[u]=tag;
    for(auto v:e[u]) if((mch[v]==0)||dfs(mch[v],tag)) return mch[v]=u,true;
    return false;
}
signed main()
{
    m=read();n=read();
    repe(i,1,m) repe(j,1,n) a[i][j]=read();
    repe(i,0,200) a[i][0]=a[0][i]=2;
    repe(i,1,m) repe(j,1,n)
    {
        if(a[i][j]!=2)
        {
            if(a[i][j-1]==2) r[i][j]=++rn;
            else r[i][j]=rn;
        }
    }
    repe(j,1,n) repe(i,1,m)
    {
        if(a[i][j]!=2)
        {
            if(a[i][j]!=2)
            {
                if(a[i-1][j]==2) c[i][j]=++cn;
                else c[i][j]=cn;
            }
        }
    }
    repe(i,1,m) repe(j,1,n) if(a[i][j]==0)
    {
        e[r[i][j]].push_back(c[i][j]);
    }
    repe(i,1,rn) if(dfs(i,i)) ++k;
    printf("%d\n",k);
    repe(i,1,m) repe(j,1,n)
    {
        if(0==a[i][j]&&r[i][j]==mch[c[i][j]]) printf("%d %d\n",i,j);
    }
    return 0;
}
```

个人解法(注释的代码未全对，未注释对了)：

```c++
#define mn 210
ll m,n,k,a[mn][mn],r[mn][mn],c[mn][mn],rn,cn,mch[mn*mn],visst[mn*mn],h;
vector<ll> e[mn*mn],f[mn*mn];
struct node{ll x,y,ri,ci;}; vector<node> ve;
void prt(ll x[mn][mn])
{
    repe(i,1,m) {repe(j,1,n) printf("%-03d ",x[i][j]);  printf("\n");  } printf("\n");
}
bool dfs(ll u, ll tag)
{
    if(visst[u]==tag) return false;
    visst[u]=tag;
    for(auto v:e[u]) if((mch[v]==0)||dfs(mch[v],tag)) return mch[v]=u,true;
    return false;
}
signed main()
{
    m=read();n=read();
    repe(i,1,m) repe(j,1,n) a[i][j]=read();
    repe(i,1,m)
    {
        repe(j,1,n)
        {
            if(!a[i][j])
            {
                ++rn;
                for(;j>1;) if(!r[i][j-1]&&2!=a[i][j-1]) --j; else break;
                while(j<=n&&2!=a[i][j]) r[i][j]=rn,++j;
            }
        }
    }
    repe(j,1,n)
    {
        repe(i,1,m)
        {
            if(!a[i][j])
            {
                ++cn;
                for(;i>1;) if(!c[i-1][j]&&2!=a[i-1][j]) --i; else break;
                while(i<=m&&2!=a[i][j])
                {
                    if(!a[i][j]&&r[i][j])
                    {
                        e[cn].push_back(r[i][j]);
                        //ve.push_back({i,j,r[i][j],cn});
                    }
                    c[i][j]=cn,++i;
                }
            }
        }
    }
    repe(i,1,cn) if(dfs(i,i)) ++k;
    printf("%d\n",k);
    repe(i,1,m) repe(j,1,n)
    {
        if(a[i][j]==0&&c[i][j]==mch[r[i][j]]) printf("%d %d\n",i,j);
    }
    /*repe(i,1,cn) if(mch[i]) for(auto j:ve)
    {
        if(j.ri==i&&j.ci==mch[i]) printf("%d %d\n",j.x, j.y);
    }*/ //这样的找法会WA一个点而且会TLE一个点，原因未知
    return 0;
}
```

附上个人注释代码解法的Hack数据(会漏一个点不输出，虽然$k=15$但最后一个点并未输出)

```
10 10
0 0 0 0 0 0 0 0 0 1
0 2 0 1 0 2 2 2 2 0
0 2 0 0 0 0 0 0 2 1
0 2 0 2 0 0 1 0 2 1
0 2 2 2 2 0 0 0 2 0
0 0 0 2 0 0 0 2 2 2
0 0 0 2 0 0 0 0 2 0
0 1 0 2 0 0 1 0 2 1
0 0 0 2 1 0 0 0 2 1
0 0 0 0 0 0 0 1 1 1
```



#### 特殊路径

##### 欧拉路

欧拉路径：经过每条边一次且仅一次的路径(起点不为终点)

欧拉回路：经过每条边一次且仅一次的回路

判定规则：

1. 没有一个节点是奇度，则任意节点出发都能找到欧拉回路
2. 有大于两个奇度节点，则不存在欧拉回路
3. 只有两个奇度节点，不存在欧拉回路，但从这两点之一出发可以找到欧拉路径

判定遍历节点度数即可，复杂度$\Omicron(n)$。

有向图欧拉路径：恰好存在一个点出度比入度多一(起点)，一个点入度比出度多一(终点)，其他点入度与出度相同

有向图欧拉回路：所有点入度=出度，起点和终点任选

无向图欧拉路径：恰好存在 $2$ 点度数是奇数(分别是起点终点)，其他点度数是偶数

无向图欧拉回路：所有点度数是偶数(起点终点任选)

若存在欧拉回路也一定存在欧拉路径





## 嵌套结构

### 树套树

#### 二维树状数组

维护矩阵，支持单点修改和区间查询。可以维护一维能维护的内容，如区间和、区间最值，区间即二维上的子矩阵。

以区间求和为例，更新和查询函数如下：

```c++
for (int x = i; x < A.length; x += lowbit(x))
    for (int y = j; y < A[i].length; y += lowbit(y))
        C[x][y] += delta;
```

```c++
int result = 0;
for (int x = i; x > 0; x -= lowbit(x))
    for (int y = j; y > 0; y -= lowbit(y))
        result += C[x][y];
return result;
```

显然，单点修改和查询的复杂度都是$\Omicron(\log^2n)$。空间复杂度是$\Omicron(m^2)$。

##### 例题

###### 上帝造题的七分钟

> 输入`X n m`给定$n\times m$矩阵，接下来输入若干行，每行可能输入`L a b c d delta`代表将顶点为$(a,b),(c,d)$的矩形区域每个数字加上$delta$，或输入`k a b c d`代表求矩形区域和。
>
> $1\le n,m\le2048,-500\le delta\le500,line\le2\times10^5$，过程在int内

考虑用二维差分数组$d[n][m]$维护区间修改的二维前缀和查询。设原数组为$a[n][m]$，二维前缀和数组为$s[n][m]$，则：
$$
s[x][y]=\sum_{h=1}^x\sum_{k=1}^ya[h][k]\\
a[i][j]=\sum_{i=1}^h\sum_{j=1}^kd[i][j]\\
\therefore s[x][y]=\sum_{h=1}^x\sum_{k=1}^y\sum_{i=1}^h\sum_{j=1}^kd[i][j]
$$
对求和化简，容易可得：
$$
s[x][y]=\sum_{i=1}^x\sum_{j=1}^yd[i][j]\times(x-i+1)\times(y-j+1)
$$
分解得：
$$
\sum_{i=1}^x\sum_{j=1}^yd[i][j]\cdot(xy+x+y+1)-d[i][j]\cdot i(y+1)-d[i][j]\cdot j(x+1)+d[i][j]\cdot ij
$$
可以维护四个差分数组：$d[i][j],d[i][j]\cdot i,d[i][j]\cdot j,d[i][j]\cdot ij$。

接下来就可以跑二维差分模板和二维树状数组模板了：(注意本题空间复杂度要求很高，使用long long或二维线段树都会MLE)

```c++
#define mn 2050
ll n, m, a, b, c, d, delta;
char op[3];
ll lowbit(ll &x) { return x & -x; }
struct BIT
{
    ll t[mn][mn];
    void add(ll lf, ll rf, ll v)
    {
        for (ll i = lf; i <= n; i += lowbit(i))
            for (ll j = rf; j <= m; j += lowbit(j))
                t[i][j] += v;
    }
    ll query(ll lf, ll rf)
    {
        ll res = 0;
        for (ll i = lf; i; i -= lowbit(i))
            for (ll j = rf; j; j -= lowbit(j))
                res += t[i][j];
        return res;
    }
} x, xi, xj, xij;
void add(ll lf, ll rf, ll v)
{
    x.add(lf, rf, v), xi.add(lf, rf, v * lf), xj.add(lf, rf, v * rf), xij.add(lf, rf, v * lf * rf);
}
ll query(ll lf, ll rf)
{
    return x.query(lf, rf) * (lf * rf + lf + rf + 1) - xi.query(lf, rf) * (rf + 1) - xj.query(lf, rf) * (lf + 1) + xij.query(lf, rf);
}
signed main()
{
    scanf("X"), sc(n), sc(m);
    while (~scanf("%s", op))
    {
        sc(a), sc(b), sc(c), sc(d);
        if (op[0] == 'L')
        {
            sc(delta);
            add(a, b, delta), add(a, d + 1, -delta), add(c + 1, b, -delta), add(c + 1, d + 1, delta);
        }
        else
            printf("%d\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
    }
    return 0;
}
```

###### Kera's line segment

> (GDCPC)有$m$次操作，若`1 l r val`，增加一条区间$[l,r]$上值为$val$的线段；若`2 l r`，询问区间$[l,r]$内的所有线段(线段在区间内当且仅当两端点都在区间内)值的最大值和最小值的差。
>
> 注：本题在线输入，实际每次操作的$l,r$为$l\oplus lastans,r\oplus lastans$。
>
> $1\le n,m\le10^5,1\le l,r\le3000,0\le val\le10^9$

可以维护两个二维树状数组，分别代表最大值和最小值。可以将每条线段转化为一个点$(l,r)$，然后翻转$x$坐标，即将其视为$(3000-l+1,r)$。每次加线段就更新点$(l,r)$的最值。查询就求子矩形$[1,3000-l+1],[1,r]$内的最值然后作差。首先肯定可以保证真实区间在$[l,r]$的线段能被找到。而真实区间在$[l',r],l'<l$的线段，由于区间翻转，使得$3000-l'+1$大于矩阵范围，会不在范围内。真实区间在$[l,r'],r’>r$的线段也不在矩阵范围内。显然$[l',r']$更不可能在范围内。而所有区间$[l,r]$内的都在，实现了不重不漏，这就是区间翻转的作用。

代码如下：

```c++
#define mn 3010
ll n, m, big = 1e9 + 7, lf, rf, v, lastans, op, tn = 3000;
ll mx[mn][mn], mi[mn][mn];
ll lowbit(ll &v) { return v & -v; }
void add()
{
    for (ll i = tn - lf + 1; i <= tn; i += lowbit(i))
        for (ll j = rf; j <= tn; j += lowbit(j))
            mx[i][j] = max(mx[i][j], v), mi[i][j] = min(mi[i][j], v);
}
void query()
{
    ll mxv = -1, miv = big;
    for (ll i = tn - lf + 1; i; i -= lowbit(i))
        for (ll j = rf; j; j -= lowbit(j))
            mxv = max(mxv, mx[i][j]), miv = min(miv, mi[i][j]);
    lastans = mxv - miv;
}
signed main()
{
    sc(n), sc(m);
    memset(mi, 0x3f, sizeof mi);
    for (ll i = 1; i <= n; ++i)
        sc(lf), sc(rf), sc(v), add();
    for (ll i = 1; i <= m; ++i)
    {
        sc(op), sc(lf), sc(rf), lf ^= lastans, rf ^= lastans;
        if (op == 1)
            sc(v), add();
        else
            query(), printf("%lld\n", lastans);
    }
    return 0;
}
```

在线时，本题的其他解法有kd-tree，树套树。离线时，还可以使用莫队和cdq分支。



#### 二维线段树

 二维线段树维护矩阵，维护的内容同一维，可以维护区间和、区间最值等。同理有二维树状数组。



# 算法

以下笔记可能包含算法知识、算法例题、算法模版以及一些类似算法的思路。均不保证绝对正确或全面，欢迎纠错~

不定期更新。

## 理论/基础

### 复杂度

一般来说要结合平衡考量时间复杂度和空间复杂度，但是一般时间复杂度更容易出现问题，所以默认复杂度指时间复杂度。

复杂度可以从最理想、平均和最坏三种情况估算。平均和最坏大多持平*(毕竟交OJ的话大概会有起码一个测试点是最坏情况)*。

#### 时间复杂度

Time complexity

大O表示法(Big-Oh-Notation)是一种评估算法效率的标尺，n代表输入数据的大小，结果表示比例关系，如O(n)是正比，O(n*n)是与n平方成正比，或者说算法是平方级的。(其实，成正比的说法不是严谨的。因为计算过程往往舍弃掉部分代数式和全部系数。)

假设及其每秒1e8次基本运算，在1秒内运算量与最大规模的列表如下

| 运算量 | n!   | 2^n  | n^3  | n^2   | nlog2(n) | n    |
| ------ | ---- | ---- | ---- | ----- | -------- | ---- |
| 最大   | 11   | 26   | 464  | 1e4   | 4.5e6    | 1e8  |
| 二倍速 | 11   | 27   | 584  | 14142 | 8.6e6    | 2e8  |

一般而言，O(sqrt(n)),O(logn),O(n),O(nlogn)(线性对数阶)效率高

##### 执行次数

用T(n)表示，n为数据量，一条语句执行一次，如：

```c++
return 0; //一次
for(int i=0;i<n;i++) s+=i;//执行2n+1次，最后一次是i++
for(int i=0;i<n;i++) for(int j=0;j<m;j++) num++;
T(n)=2nm+2n+1    
```

一般而言，不会超时的话，T在$10^7$以内，或$10^8$(勉强)

##### O计算方式

1. 设n趋于无穷，所以所有低阶无穷均可以省略，系数也可以省略；
2. 如果有分支，选择执行次数最大的

> LaTeX数学公式如果无法加载出来，可以复制到新的.md查看，也可以重新打开

如：

$T(n)=2nm+2n+1 \to O(n)=n^2$



若干个非循环语句,O(n)=1

a个循环嵌套，O(n)=n^a

```c++
for(int i=1;i<n;i*=2)
```

$T(n)=log_2n+1$

$O(n)=logn$



```c++
for(int i=1;i<=n;i++) for(int j=1;j<=i;j++)
```

$T(n)=\frac{n^2}{2}+\frac{n}{2}$

$O(n)=n^2$



前缀和：计算时O(n)=n，查询时=1



```c++
int f(int n)
{
    if(n==1) return 1;
    else return f(n/2)+f(n/2);
}
```

$T(n)=1+2+4+\dots+2^{log_2n}=2^{log_2(n+1)}-1=2n-1$

$2^{n+1}-1$

$O(n)=n$



##### 递归复杂度结论

> 主定理 master theorem

若递归算法存在分治递推式：
$$
T(n)=\begin{cases}c&n=1\\aT(\dfrac nb)+cn^k&n>1\end{cases}
$$
其中$a,b,c,k$是常数，$T(n)$是非递减函数，则：
$$
T(n)=\begin{cases}\Omicron(n^{\log_ba})&a>b^k\\
\Omicron(n^k\log_bn)&a=b^k\\
\Omicron(n^k)&a<b^k\end{cases}
$$




##### 其他记号

###### 渐进精确界记号

$\Theta$ 

$\Theta(g(n))={f(n)} 存在正常量c_1,c_2,n_0，使得对所有n\ge n_0，\\ 有0\le c_1g(n)\le f(n)\le c_2g(n)$

###### 渐进上界记号

$\Omicron$

对于渐进精确界记号，取$0\le f(n)\le cg(n)$

###### 渐进下界记号

$\Omega$

对于渐进精确界记号，取$0\le cg(n)\le f(n)$

$对任意两个函数f(n),g(n)，有：f(n)=\Theta(g(n))当且仅当:\\f(n)=\Omicron(g(n))且f(n)=\Omega(g(n))$

###### 非渐进紧确上界记号

$\omicron$

$\omicron(g(n))={f(n):对任意正常量c，存在正常量n_0，\\ 使得对所有n\ge n_0有0\le f(n) \le cg(n)} $

其范围是比渐进精确更大的存在

###### 非渐进紧确下界记号

$\omega$

同理，改为$0\le cg(n) \le f(n)$

###### 非渐进紧确记号

$\theta$

同理

#### 空间复杂度

Space complexity

计算方法：n*sizeof（单位byte）

例如：

```c++
int p[12882][3403];
```

由于sizeof(int)=4(byte)，相乘得175349784byte(除2^20^得)167.2MB，显然大于128MB，造成MLE，

因此可以使用short，使内存减半(假设max不超过65535)；

同理，其他简化方法大概有：

- int → short → char/bool → 位域
- signed → unsigned
- 状态压缩，压位

#### 举例

分析复杂度：

##### 快乐数

> (oj)快乐数是$2^x3^y,x,y\in\Z_+$，有$T(1\le T\le100)$组样例，求$[l,r]$范围内快乐数数，$1\le l\le r\le2\times10^{17}$。

枚举x和y，显然复杂度是$\Omicron(T\log_2x\log_3y)$。

```c++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a,b,s,v;
signed main()
{
    for(;EOF != scanf("%lld%lld",&a,&b);s=0)
    {
        for(ll i=1;i<=b;i<<=1) for(ll j=1;j<=b;j*=3)
        {
            v=i*j;
            if(v>=a&&v<=b) ++s;
            else if(v>b) break;
        }
        printf("%lld\n",s);
    }
    return 0;
}
```

### 技巧类

#### 注意要点

算法竞赛需要注意的地方：

1. 不要使用头文件conio.h，包括getch,getche；gotoxy,clrscr等函数
2. 每行输出应该用回车符结束，包括最后一行，除非特殊说明，行首不能有空格，行末可以有多余空格
3. 几乎所有算法平台上，int都是32位整数
4. 很多程序运行时间与规模存在近似的简单关系，可以发现或验证
5. 鲁棒性(robustness)：输入输出指明了范围和标记，但是可能实际数据没有，此时仍然给出了正确结果就是鲁棒性强
6. 多组数据题目，常见错误是计算完一组数据后某些变量未重置
7. RE可能的原因有：零除、栈溢出、非法访问内存、断言假、最大输出限制
8. KISS:keep it simple and stupid
9. 很多情况下，做一件事情之前检查是不是可以做，而不是做完再反悔，因为悔棋很麻烦
10. 栈溢出的可能原因：递归调用太多，局部变量太大
11. MLE的数据范围可能有：int 数目1e8以上
12. 不要使用fflush(stdin)
13. 不要使用gets,puts
14. 开题前面的题觉得比较容易也要继续往下看，可能下面有更简单的真·签到题
15. 在本地通过而在OJ不通过或部分通过的题目，有可能是本地未初始化的变量被编译器初始化了，但OJ未。
16. OJ做题交题前把freopen注释掉
17. 双变量代替数组时，注意更新bf=now
18. PA也有可能是printf调试没删干净，某些情况对了因为这些情况删了
19. 一定要注意命名规范，题目给定外的自设变量名字要能够看出意义(尤其是具有多个对象有相近意义时)，做好区分，这样debug时也会更容易发现问题所在(例如avalue\=\=pos就比avalue\=\=c)更有区分度。

##### 比赛注意点

###### 蓝桥

- 可以用万能头

#### 失误大致方向

##### WA

###### PA

1. 数组越界

   如前向星等点数当边数，没开无向图二倍

###### WA

1. 没有删除freopen或调试用的printf
2. 读入问题，如使用while-getchar读字符，不判断有效范围而读进了最后的换行符等字符产生了一个多余的输入，要对读入进行合法性判定。

##### TLE

1. 数组越界

##### RE

1. 数组/vector等越界

##### MLE

#### 标准开头

##### 01

> 较精简版本

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define re register
#define il inline
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;--i)
#define rede(i,a,b) for(re ll i=a;i>=b;--i)
il ll read()
{
	re char p = 0; re ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}

signed main()
{
	return 0;
}
```

##### 02

> 较详细版本

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define re register
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;--i)
#define rede(i,a,b) for(re ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define deb
#undef deb
#ifdef deb
#define ts printf
#else
#define ts ;
#endif
#define prt printf
#define sc(x) scanf("%lld",&x)
#define bigi 0x7ffffffa
#define bigl 0x7ffffffffffffffa
#define st first
#define nd second
il ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
#define mod 1000000007
il ll qpow(ll a, ll b)
{
	ll r = 1;
	for (;b;b >>= 1, (a *= a) %= mod) if (b & 1) (r *= a) %= mod;
	return r;
}

signed main()
{
	return 0;
}
```



#### 技巧

##### 快读

快读与普通读的区别：

- 快读舍弃掉所有下一个数字之前的字母
- 快读可以不存变量，读到的值直接参与运算
- 快读只能读整数型(在下面的实现版本中)
- 快读(推荐版)多个负号都当一个负号，不会负负得正(|=改掉也不行)

###### 推荐版

```c++
inline ll read() 
{
    char p = 0; ll r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
```

###### 不同版本

```c++
inline int read(){
    int num = 0; char c = getchar(), up = c;
    while(c < '0' || c > '9') up = c, c = getchar();
    while(c >= '0' && c <= '9') num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}
```

```c++
using namespace std;
inline int read(int *eof){
    int num = 0; char c = getchar(), up = c;
    if(c==EOF){ *eof=1; return 0;}
    while(c < '0' || c > '9') up = c, c = getchar();
    while(c >= '0' && c <= '9') num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}
//注意事项：eof要初始化为0
//以a+b专题为例，应用示范：
int main()
{
    int a,b,c=0;
    while(1)
    {
        a=read(&c);
        if(c==1) break;
        b=read(&c);
        if(c==1) break;
        printf("%d\n", a+b);
    };
    return 0;
}
```

```c++
inline int read(int &eof){
    int num = 0; char c = getchar(), up = c;
    if(c==EOF){ eof=1; return 0;}
    while(c < '0' || c > '9') up = c, c = getchar();
    while(c >= '0' && c <= '9') num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}//甚至可以开register
```

```c++
inline int read(){//版本3
    char p=0;int r=0,o=0;
    for(;p<'0'||p>'9';o|=p=='-',p=getchar());
    for(;p>='0'&&p<='9';r=(r<<1)+(r<<3)+(p^48),p=getchar());
    return o?(~r)+1:r;
}
```

```c++
//模板版本，可以切换读入long long, int, int64等整型
template<typename Type>inline void read(Type &xx)
{
    Type f=1;char ch;xx=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())xx=xx*10+ch-'0';
    xx*=f;
}
```

```c++
inline ll read() 
{
    char p = 0; ll r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
```

```c++
inline char nc() {
	static char buf[1<<20],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),
	p1==p2)?EOF:*p1++; 
}
inline int read() {
	int x=0,f=1;
	static char c=nc(); 
	for(;c>'9'||c<'0';c=nc())
		if(c=='-') 
			f=-1;
	for(;c<='9'&&c>='0';c=nc())
		x=(x<<3)+(x<<1)+c-48;
	return x*f;
}
```

### 分治法

举例：排序-归并排序

常常使用到递归。

步骤：

- 将问题分解为局部问题
- 递归求解局部问题
- 将局部问题的解整合，解决原问题

#### 例题

##### 数组若干元素之和是否能等于定值

首行输入n，下行输入n个整数组成数组a，下行输入m，下行输入m个整数组成数组b；对于每个b，是否在a内存在0到n个元素和与之相等？

n<=20,q<=200,1<=A[i],B[i]<=2000

复杂度O(2^n)

```c
#include <stdio.h>
int n, A[50];
int solve(int i, int m)
{
    if(m==0) return 1;
    if(i>=n) return 0;
    return solve(i+1,m) || solve(i+1,m-A[i]);//是否选中当前元素进行下一轮
}
int main()
{
    int q,M,i;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++)
    {
        scanf("%d", &M);
        if(solve(0,M) ) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
```

##### 科赫曲线

输入n(0<=n<=6)，输入n次科赫曲线后各顶点坐标。起始端点为(0,0),(100,0)，误差小于1e-4

```c++
#include<stdio.h>
#include<math.h>
struct Point {double x,y;};//注意双引号个数
double th = M_PI * 60.0 / 180.0;//60度
double cos60 = cos(th), sin60 = sin(th);
void koch(int n, Point a, Point b)
{
    if(n==0) return;
    Point s,t,u;
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos60 - (t.y - s.y) * sin60 + s.x;
    u.y = (t.x - s.x) * sin60 + (t.y - s.y) * cos60 + s.y;

    koch(n-1,a,s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n-1,s,u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(n-1,u,t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(n-1,t,b);
}

int main()
{
    Point a,b;
    int n;
    scanf("%d", &n);
    a.x=0;
    a.y=0;
    b.x=100;
    b.y=0;
    printf("%.8f %.8f\n", a.x, a.y);
    koch(n,a,b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}
```

### 贪心法

选取当前最优解的方法

贪心法的证明十分困难，但是反例有时还是比较好找的，不能凭直观判定某道题就能用贪心，最好先考虑考虑。

#### 找规律型

##### Stone Game

> (ICPC45济南 C)
>
> MianKing has n piles of stones and each pile has at most 3 stones, now he wants to merge all of these stones into one pile.
>
>  In order to achieve his goal, each time MianKing can choose two piles of stones and merge them into a new pile, and the number of stones in the new pile is the sum of these two piles. 
>
>  Because it takes manpower to move stones, in each operation if the numbers of these two piles of stones are x and y respectively, MianKing should pay (x mod 3)(y mod 3) coins for it.
>
>  Now MianKing wants to know the minimum amount of coins he need to pay to merge all of these stones into one pile.
>
> $0\le a_i\le10^9,\sum_{i=1}^3a_i>0$

将所有$1,2$先合并然后合并剩下的$1$或$2$，注意$2$合并的通项规律不要算错，即每次合并不是都是4，是有2和4的代价。

```python
a,b,c=[int(i) for i in input().strip().split()]
e=min(a,b)
r=2*e
a-=e
b-=e
if a:
    r+=3*(a//3)+(a%3==2)
if b:
    r+=6*(b//3)+4*(b%3==2) #不要算错为8*
print(r)
```

#### 复合型

##### CGY出差

> (scnu cgy)有$t(1\le t\le10)$组数据，每组城市数为$n(1\le n\le10^5)$，输入$a_i(1\le a_i\le10^9)$，从$1\sim n$经过城市，可以花$a_i$元买入或卖出一颗宝石或什么也不做。求赚钱的最大数目和最赚钱下买入卖出最小总数。

优先级队列+贪心。不考虑交易次数时，对于已经读到的城市，从小到大存入$a_i$，如果新的$a$比最小的$a_i$大，那么在之前买入并在现在卖出最小的$a_i$，出队$a_i$，然后入队$a$（这个$a$等价于出队的$a_i$，且其现在的相对价值大了）。无论是否之前入队了，再次多一次$a$。

考虑交易次数时，可以在原过程不变把一系列中转抵消，每次卖出时新的价格记录一次，如果下一次新的价格已经记录过，那么减少一次交易计数。时间复杂度为$\Omicron(tn\log n)$。

```c++
ll t,n,a,r,hg,tp;
signed main()
{
    t=read();
    while(t--)
    {
        n=read(); r=hg=0;
        priority_queue<ll,vector<ll>,greater<ll>> q;
        unordered_map<ll,ll> b;
        while(n--)
        {
            a=read();
            if(!q.empty()&&a>q.top())
            {
                tp=q.top(); q.pop();
                r+=a-tp;
                ++hg;
                if(b[tp]) --hg,--b[tp];
                ++b[a];
                q.push(a);
            }
            q.push(a);
        }
        printf("%lld %lld\n",r,hg<<1);
    }
	return 0;
}
```



#### 例题

##### 翻硬币

> (蓝桥)有n枚硬币，每次可以同时反转相邻两个硬币，给出初始状态和终止状态，求最小反转次数。

策略：顺着来一遍，如果遇到需要翻转就马上翻转。

证明：不会证，但真的显而易见。

```c++
#include <bits/stdc++.h>
using namespace std;
string x,y;
int xl,ans;
signed main()
{
	cin>>x>>y; xl=x.size();
	for(int i=0;i<xl-1;++i)
	{
		if(x[i]!=y[i])
		{
			++ans;
			if(x[i+1]=='o') x[i+1]='*'; else x[i+1]='o';
		}
	}
	printf("%d",ans);
	return 0;
}
```

附加推论：任何一次翻面之后，正面的奇偶性和反面的奇偶性不会改变，因此如果一开始正面奇偶性不等于反面，那么无解

证：设有正面硬币$a$个，反面$b$个，翻面有且仅有三种情况，一是翻二正为二反，那么新状态是$a-2,b+2$；二是翻二反为二正，新状态$a+2,b-2$，三是翻一正一反为一反一正，新状态仍然是$a-1+1,b+1-1=a,b$，奇偶都未改变。

> 细节：如果用数字或字符的01，可以直接异或翻面

##### 乖乖站好

> (oj)有$1,2,12,21$四种组合$a,b,c,d$个，将它们拼起来，组成$12$相间的串，求最大长度。$0\le a,b,c,d\le10^5$

因数据量所限，显然不能使用dp。

###### 正解

但凡有一个1或2，那么所有的12和21都可以被用上。那么很容易分类讨论：

1. 没有a和b，答案是$\max(c,d)\times2$
2. a,b数量相等，均可以用上：$a+b+2\times c+2\times d$
3. a,b有差值，多的用于连接$c,d$：$2\times\min(a,b)+1+2(c+d)$

###### 错解

> 事实上这种解法可以被hack掉：
> 1 1 2 2答案应当是10，输出了6

(个人解法)有两种情况，即先排1,2相间排，全部的12，如果1有多，然后放一个1，然后排全部的21，答案数为：
$$
c*2+\min(a,b)*2+(1+d*2\quad if\ a-b\ge1)
$$
如果先排2,1相间，然后全部的21，然后如果2有多，放一个2，然后排全部的12：
$$
d*2+\min(a,b)*2+(1+c*2\quad if\ b-a\ge1)
$$
因解法有误，不展示代码。

##### 建筑抢修

> n个建筑，修复需要w时间，t时间后仍未修复完成则损毁，求最大抢修数

贪心策略：按t升序遍历，如果遍历时发现了无法修复的建筑，如果在之前决定修复的建筑耗时最大的建筑其耗时大于该建筑耗时，放弃修复之前决定修复的选定建筑，修复该建筑。

贪心证明：如果i出现无法修复，那么之前至多有i-1个修复成功；如果可以进行如上更换，那么修复成功数不会改变，而剩余时间增加，显然这种策略不会让结果更差。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 150002
ll n, t, ans;
struct node { ll w, t; } a[MAXN];
inline bool cmp(const node& x, const node& y) { return x.t < y.t; }
priority_queue<ll> q;
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld%lld", &a[i].w, &a[i].t);
	sort(a + 1, a + 1 + n, cmp);
	repe(i, 1, n)
	{
		if (t + a[i].w > a[i].t)
		{
			if (a[i].w < q.top())
			{
				t -= q.top(); q.pop();
				q.push(a[i].w);
				t += a[i].w;
			}
		}
		else
		{
			q.push(a[i].w);
			t += a[i].w;
			++ans;
		}
	}
	printf("%lld", ans);
	return 0;
}
```

##### 列车调度

> (天梯)有$n(2\le n\le10^5)$辆序号各异(序号为$n$的排列)列车在入口排队，入口与出口间可以设若干条无限长的轨道，这些轨道的头和尾分别连接入口和出口。要求在出口离开的列车是序号倒序的，求最小轨道数。

维护轨道尾序号单调递增的轨道尾动态数组。对于每次队首的列车，如果在各轨道尾的序号都大于它，那么新开一条轨道。否则，二分找到大于它的第一条轨道，然后将它插入到这条轨道，这样就可以维护一个单调递增的轨道尾。全部入口处列车到达轨道后，显然就可以倒序出站了。

> 不能够将它插入到二分找到的轨道的前一条轨道，因为不能保证插入后是单调的(结果为必然不单调)。同理，也不能插入到后面的一条轨道(结果为必然不单调)。

~~证明不会证~~

举例：入口为$[8,4,2,5,3,9,1,6,7]$，

- 对于8，没有轨道，新开一条轨道，轨道数为1。

  - $$
    \left[\matrix{1:&8}\right]
    $$

    

- 对于4，第一条大于4的尾(8)是第一条轨道，直接插入。轨道数为1。

  - $$
    \left[\matrix{1:&4&8}\right]
    $$

    

- 对于2，第一条大于2的尾(4)是第一条轨道，直接插入。轨道数为1。

  - $$
    \left[\matrix{1:&2&4&8}\right]
    $$

    

- 对于5，没有轨道尾大于5，新开轨道。轨道数为2。

  - $$
    \left[\matrix{1:&2&4&8\\2:&&&5}\right]
    $$

    

- 对于3，第一条大于3的尾(5)是第二条轨道，直接插入。轨道数为2。

  - $$
    \left[\matrix{1:&2&4&8\\2:&&3&5}\right]
    $$

    

- 对于9，没有轨道尾大于9，新开轨道。轨道数为3。

  - $$
    \left[\matrix{1:&2&4&8\\2:&&3&5\\3:&&&9}\right]
    $$

  

- 对于1，第一条大于1的尾(2)是第一条轨道，直接插入。轨道数为3。

  - $$
    \left[\matrix{1:&1&2&4&8\\2:&&&3&5\\3:&&&&9}\right]
    $$

    

- 对于6，第一条大于6的尾(9)是第三条轨道，直接插入。轨道数为3。

  - $$
    \left[\matrix{1:&1&2&4&8\\2:&&&3&5\\3:&&&6&9}\right]
    $$

    

- 对于6，第一条大于6的尾(9)是第三条轨道，直接插入。轨道数为3。

  - $$
    \left[\matrix{1:&1&2&4&8\\2:&&&3&5\\3:&&&6&9}\right]
    $$

    

- 对于7，没有轨道尾大于7，新开轨道。轨道数为4。

  - $$
    \left[\matrix{1:&1&2&4&8\\2:&&&3&5\\3:&&&6&9\\4:&&&&7}\right]
    $$

    

那么，出队时，出队轨道依次为：$[3,1,4,3,2,1,2,1,1]$，那么就可以得到降序输出：$[9,8,7,6,5,4,3,2,1]$。

```c++
#include <bits/stdc++.h>
using namespace std;
int n,qm,qn,v,q[100002];
signed main()
{
    for(scanf("%d",&n);n;--n)
    {
        scanf("%d",&v);
        if(v>=q[qn]) q[++qn]=v;
        else q[lower_bound(q+1,q+qn,v)-q]=v;
    }
    return printf("%d",qn)&0;
}
```



### 打表法

> 打表法就是将题目中需要的答案集合提前算出来，存到代码里，根据题目所需取答案，这种方法通常只需要将程序挂着，在表打完后进行加工，最终取答案程序时间复杂度为O(1)，空间复杂度为O(n)(n为答案规模)； ——沃兹·基朔德

### 前缀和

常常与差分(逆运算)连用。可以按维度分为多种前缀和。

#### 差分

差分用于解决若干次区间修改和只有最后一次区间查询的问题。

一维差分数组：
$$
d[i]=a[i]-a[i-1](初始化)\\
d[l]+=v,d[r+1]-=v(修改)\\
a[i]=a[i-1]+d[i](查询)
$$
二维差分数组：(修改左下角为$(x1,y1)$，右上角为$(x2,y2)$)
$$
d[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1]\\\ \\
d[x1][y1]+=d,d[x2+1][y2+1]+=d\\
d[x1][y2+1]-=d,d[x2+1][y1]-=d\\\ \\
a[i][j]=d[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1]
$$
多维差分数组同理(修改时加和减的数目是一样的，对于三维，零个和两个右边坐标对应加，其他对应减)

##### 例题

###### Color The Ball

> (hdu1556)给定n组修改，每次使区间$[a,b]$内各元素加一，求最后各元素值

一维差分模板题

```c++
//hdu 1556 用差分数组求解
#include<bits/stdc++.h>
using namespace std;
const int Maxn = 100010;
int a[Maxn],D[Maxn];               //a是气球，D是差分数组

int main(){
    int n;
    while(~scanf("%d",&n)) { 
        memset(a,0,sizeof(a)); memset(D,0,sizeof(D));
        for(int i=1;i<=n;i++){
            int L,R; scanf("%d%d",&L,&R);
            D[L]++;              
            D[R+1]--;
        }
        for(int i=1;i<=n;i++){
            a[i] = a[i-1] + D[i];          //求前缀和a[]，a[i]就是气球i的值
            if(i!=n)  printf("%d ", a[i]);  //逐个打印结果
            else      printf("%d\n",a[i]);
        }        
    }
    return 0;
}
```

###### 不成熟的梦想家

> 设队伍有n+1人，各有唱功，可以有q次训练，每次训练让编号(从0开始)为$[x,y]$内的人唱功变动z，0号成员唱功不会被改变(x,y>0)，每次训练后，输出队伍魅力值b。计算如下：从第1到n，判断
> $$
> \begin{cases}a[i-1]<a[i],b=b-s|a[i-1]a[i]|\\a[i-1]>a[i],b=b+t|a[i-1]a[i]|\end{cases}
> $$
> ($n,q\le2\times10^5,1\le s,t,a_i\le10^6$)

差分直接套。注意每次修改后差分只需要更新两个点，而不是区间更新。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,s,t,ans,bf,a[200002],x,y,z;
inline ll calc(ll& x)
{
    return x>0?-s*x:-t*x;
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&q,&s,&t);
    for(ll i=0;i<=n;++i,bf=x)
    {
        scanf("%lld",&x);
        a[i]=x-bf;
        ans+=calc(a[i]);
    }
    for(ll i=1;i<=q;++i)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        ans-=calc(a[x]); a[x]+=z; ans+=calc(a[x]);
        if(y!=n) ans-=calc(a[y+1]),a[y+1]-=z,ans+=calc(a[y+1]);
        printf("%lld\n",ans);
    }
    return 0;
}
```

###### Face the Right Way G

> 有n个朝向，B反向，F正向，每次可以选固定k个连续的进行反向，求最小操作次数m和对应的最小的k，使得全部方向转为F

显然从左往右贪心转向即可，如果暴力枚举复杂度为n^3^，用差分优化为n^2^

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5002
ll n, k, drt[MAXN], f[MAXN << 1], mk, op, ans = MAXN - 2, ansk, sum;
char ch;
signed main()
{
	cin >> n;
	repe(i, 1, n)
	{
		cin >> ch;
		if (ch == 'B') drt[i] = 0;
		if (ch == 'F') drt[i] = 1;
	}
	repe(k, 1, n)
	{
		sum = mk = op = 0;
		memset(f, 0, sizeof f);
		repe(i, 1, n)//写成rep死掉了
		{
			if ((drt[i] + mk) % 2 == 0)
			{
				if (i + k - 1 > n)
				{
					op = 1;
					break;
				}
				++sum;
				++mk;
				f[i + k - 1] = -1;
			}
			if (f[i] == -1) --mk, f[i] = 0;
		}
		if (op) continue;
		if (sum < ans) ans = sum, ansk = k;
	}
	printf("%d %d", ansk, ans);
	return 0;
}
```

###### 猜数

> (oj)猜了$n$次数，若`+`，判断猜大了；`-`猜小了，`.`猜对了。这些判断里最多几次是对的？($1\le n\le10^5,-10^9\le x\le10^9$)

枚举数字(离散枚举)，判断每个不等式是对的还是错的。复杂度是$\Omicron(n^2)$。然而可以用差分优化，从负无穷开始枚举，初始状态为所有`+`都是猜对的。对于每个数$x$和其`x+1`。枚举`x`时，`+`的正确数对应减少，`.`的正确数对应增加；枚举`x+1`时，`-`的正确数对应增加，`.`的正确数对应减少。所以可以读入时累计差分，然后排序后叠前缀和即可。

```c++
map<ll, ll> s;
ll r, n, v, mx;
char c;
signed main()
{
    sc(n);
    while (n--)
    {
        scanf("%d %c", &v, &c);
        if (c == '+')
            ++s[-2e9], --s[v];
        else if (c == '-')
            ++s[v + 1], --s[2e9];
        else
            ++s[v], --s[v + 1];
    }
    for (auto i : s)
    {
        r += i.second;
        mx = max(mx, r);
    }
    printf("%d", mx);
    return 0;
}
```



###### 守卫农田

> (oj)有$n\times m(1\le n,m,n\times m\le10^7)$农田，有$p(1\le p\le 10^6)$个矩形区域被守护，有$q(1\le q\le10^6)$次矩形攻击，若每个格子都被守护，可以抵御。求每次攻击是否可以抵御。$t\le 5$，`EOF`结束。

注意是$n\times m\le10^7$而不仅仅是$n,m\le 10^7$，所以可以直接跑裸的二维前缀和。使用差分读入$p$，然后转化为普通数组并转成布尔值，然后转前缀和，然后直接跑前缀和即可。

```c++
signed main()
{
    while (EOF != scanf("%d%d%d", &n, &m, &p))
    {
        x = new ll[(n + 2) * (m + 2)]{};
        while (p--)
        {
            sc(ax), sc(ay), sc(bx), sc(by);
            ++x[toi(ax, ay)], ++x[toi(bx + 1, by + 1)];
            --x[toi(bx + 1, ay)], --x[toi(ax, by + 1)];
        }
        repe(i, 1, n) repe(j, 1, m) x[toi(i, j)] += x[toi(i - 1, j)] + x[toi(i, j - 1)] - x[toi(i - 1, j - 1)]; //差分转普通
        repe(i, 1, n) repe(j, 1, m) x[toi(i, j)] = x[toi(i, j)] >= 1;                                           //转布尔值
        repe(i, 1, n) repe(j, 1, m) x[toi(i, j)] += x[toi(i - 1, j)] + x[toi(i, j - 1)] - x[toi(i - 1, j - 1)]; //普通堆前缀
        for (sc(q); q; --q)
        {
            sc(ax), sc(ay), sc(bx), sc(by);
            s1 = x[toi(bx, by)] + x[toi(ax - 1, ay - 1)] - x[toi(ax - 1, by)] - x[toi(bx, ay - 1)];
            if (s1 == (bx - ax + 1) * (by - ay + 1))
                printf("YES\n");
            else
                printf("NO\n");
        }
        delete[] x;
    }
    return 0;
}
```



###### 三体攻击

> (蓝桥)共有a,b,c层行列的舰队立方体，有m次攻击，每次攻击在一个立方体内受到一定伤害，伤害大于血量时阵亡。求第一艘阵亡的战舰所在的攻击次数。
>
> $a\cdot b\cdot c,m\le10^6,|坐标|\le10^9$

三维差分模板题。使用到的优化技巧：二分答案、压缩三维为一维。

```c++
#include<stdio.h>

int A,B,C,n,m;
const int Maxn = 1000005;
int s[Maxn];   //存储舰队生命值
int D[Maxn];   //三维差分数组（压维）；同时也用来计算每个点的攻击值
int x2[Maxn], y2[Maxn], z2[Maxn]; //存储区间修改的范围，即攻击的范围
int x1[Maxn], y1[Maxn], z1[Maxn]; 

int d[Maxn];                    //记录伤害，就是区间修改
int num(int x,int y,int z) {  
//小技巧：压维，把三维坐标[(x,y,z)转为一维的((x-1)*B+(y-1))*C+(z-1)+1
    if (x>A || y>B || z>C) return 0;
    return ((x-1)*B+(y-1))*C+(z-1)+1;
}
bool check(int x){              //做x次区间修改。即检查经过x次攻击后是否有战舰爆炸
    for (int i=1; i<=n; i++)  D[i]=0;  //差分数组的初值，本题是0
    for (int i=1; i<=x; i++) {         //用三维差分数组记录区间修改：有8个区间端点
        D[num(x1[i],  y1[i],  z1[i])]   += d[i];
        D[num(x2[i]+1,y1[i],  z1[i])]   -= d[i];
        D[num(x1[i],  y1[i],  z2[i]+1)] -= d[i];
        D[num(x2[i]+1,y1[i],  z2[i]+1)] += d[i];
        D[num(x1[i],  y2[i]+1,z1[i])]   -= d[i];
        D[num(x2[i]+1,y2[i]+1,z1[i])]   += d[i];
        D[num(x1[i],  y2[i]+1,z2[i]+1)] += d[i];
        D[num(x2[i]+1,y2[i]+1,z2[i]+1)] -= d[i];
    }
    //下面从x、y、z三个方向计算前缀和
    for (int i=1; i<=A; i++)
        for (int j=1; j<=B; j++)
            for (int k=1; k<C; k++)        //把x、y看成定值，累加z方向
                D[num(i,j,k+1)] += D[num(i,j,k)];
    for (int i=1; i<=A; i++)
        for (int k=1; k<=C; k++)
            for (int j=1; j<B; j++)        //把x、z看成定值，累加y方向
                D[num(i,j+1,k)] += D[num(i,j,k)];
    for (int j=1; j<=B; j++)
        for (int k=1; k<=C; k++)
            for (int i=1; i<A; i++)        //把y、z看成定值，累加x方向
                D[num(i+1,j,k)] += D[num(i,j,k)];
    for (int i=1; i<=n; i++)    //最后判断是否攻击值大于生命值
        if (D[i]>s[i])
            return true;
    return false;
}
int main() {
    scanf("%d%d%d%d", &A, &B, &C, &m);
    n = A*B*C;
    for (int i=1; i<=n; i++) scanf("%d", &s[i]);  //读生命值
    for (int i=1; i<=m; i++)                      //读每次攻击的范围，用坐标表示
        scanf("%d%d%d%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i],&z1[i],&z2[i],&d[i]);

    int L = 1,R = m;      //经典的二分写法
    while (L<R) {     //对m进行二分，找到临界值。总共只循环了log(m)次
        int mid = (L+R)>>1;
        if (check(mid)) R = mid;
        else L = mid+1;
    }
    printf("%d\n", R);  //打印临界值
    return 0;
}
```



#### 二维

理论基础：一维前缀和、容斥原理。

二维前缀和累加公式：($a[i][j]$是普通数组，$s[i][j]$是前缀和数组)
$$
s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]
$$
二维前缀和查询公式：(查询右上角为$(i,j)$，长宽为$(a,b)$)
$$
s[i][j]-s[i-a][j]-s[i][j-b]+s[i-a][j-b]
$$
一般而言，二维前缀和下标从1开始。(为了-1不用特判)

##### 例题

###### 最大价值正方形

> 在nxm的矩阵内选一个边长c的正方形，使方形内数值和最大，输出该方形的左上角坐标(从1开始算)。输入n,m,c,矩阵。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 1002
#define NEG -0x7fffffffffffffff
ll n, m, c, a[MAXN][MAXN], ans=NEG, ax, ay, v;
signed main()
{
	scanf("%lld%lld%lld", &n, &m, &c);
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			scanf("%lld", &v);
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + v;
		}
	}
	rep(i, c, n)
	{
		rep(j, c, m)
		{
			v = a[i][j] + a[i - c][j - c] - a[i - c][j] - a[i][j - c];
		if (v > ans)
			ans = v, ax = i - c + 1, ay = j - c + 1;
		}
	}
	printf("%lld %lld", ax, ay);
	return 0;
}
```

###### 最大子阵

> (蓝桥)给定$n\times m$矩阵，求其最大非空子矩阵的元素和。$1\le n,m,\frac v{10}\le500$

显然，如果使用朴素二维前缀和，时间复杂度为$\Omicron(n^2m^2)$会超时。但是可以按行积累前缀和，那么只需要$\Omicron(n^2m)$，如下：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 502
int s[mn][mn],n,m,mx=-0x7ffffffa,v;
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) 
		scanf("%d",&v),s[i][j]=s[i-1][j]+v;//当前行前缀和 
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) //矩阵右下角为(i,j) 
		for(int k=1,v=0;k<=m;++k) //使用O(m)计算二维前缀和 
		{
			v+=s[i][k]-s[j-1][k];//当前矩阵前缀和 
			mx=max(mx,v);
			v=max(v,0); //负数特判 
		}
	printf("%d",mx);
	return 0;
} 
```

###### 组合数的因子

组合数$(\matrix{n\\m})=\frac{n!}{m!(n-m)!}$，给定n,m,k，对$0\leq i \leq n, 0 \leq j \leq min(i,m)$，求有多少对$(i,j)$满足$k|(\matrix{i\\j})$

输入t,k，接下来有t组询问(n,m)，输出答案。

显而易见是单一计算(该计算应当使用杨辉三角)多次区间查询问题。一种以0开始的二维前缀和示例如下：

```c++
#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define MAXN 2002
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int C[MAXN][MAXN], t, k, n, m, o, cnt;
long long d[MAXN][MAXN];
signed main()
{
	scanf("%d%d", &t, &k);
	C[0][0] = C[1][0] = C[1][1] = 1;
	rep(i, 2, 2001)
	{
		C[i][0] = 1;
		rep(j, 1, i)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k;
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			if (!C[i][j]) ++d[i][j];
		}
		d[i][i + 1] = d[i][i];
	}
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (m > n) printf("%lld\n", d[n][n]);
		else printf("%lld\n", d[n][m]);//可以不开ll
	}
	return 0;
}
```

#### 积累

运用前缀和思维，把所有相同的累加只进行一次。

##### 例题

###### 外卖店优先级

> (蓝桥)有n家店，0时刻优先级均为0，每经过1时间，优先级减1，最低到0；否则加2；优先级某时刻大于5时会被加入优先缓存，小于等于3会被清出。给定n，m条订单(t,id)和t，计算t时刻在优先缓存中的店数。

**朴素：**

(个人解法)用时1s以上(但AC，可能是总和1s以上)

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
int n,m,t,p[mn];
set<int> alive,pri;
struct node
{
    int t,id;
    inline bool operator<(const node& x)const{return t<x.t;}
} ddd[mn];
vector<int> dd[mn];
#define v dd
signed main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1,x,y;i<=m;++i)
    {
        //scanf("%d%d",&dd[i].t,&dd[i].id);
        scanf("%d%d",&x,&y);
        dd[x].push_back(y);
    }
    //sort(dd+1,dd+1+m,cmp);
    for(int i=1;i<=t;++i)
    {
        //if(dd[i].t>t) break;
        set<int> alr;
        for(int j=0,je=v[i].size();j<je;++j)
        {
            alr.insert(v[i][j]);
            alive.insert(v[i][j]);
            p[v[i][j]]+=2;
            //printf("%d %d\n",v[i][j],p[v[i][j]]);
            if(p[v[i][j]]>5)
            {
                pri.insert(v[i][j]);
            }
        }
        vector<int> die;
        for(set<int>::iterator it=alive.begin();it!=alive.end();++it)
        {
            if(alr.find(*it)==alr.end())
            {
                --p[*it];
                if(p[*it]<=3&&pri.find(*it)!=pri.end()) pri.erase(*it);
                if(p[*it]<=0) die.push_back(*it);
            }
        }
        for(int j=0,je=die.size();j<je;++j)
        {
            alive.erase(die[j]);
        }
    }
    int ans=0;
    for(set<int>::iterator it=pri.begin();it!=pri.end();++it)
    {
        ++ans;
    }
    printf("%d",ans);
    return 0;
}
```

**优化：**

只遍历一次订单，更新时间差来确定减少多少个优先级。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=100010;
struct node
{
  int id;
  int prio;
  int lasttime;
  bool yes;
}p[maxn];
vector<pair<int,int> > v;
bool cmp(pair<int,int> &A,pair<int,int> &B)
{
  return A.first<B.first;
}
int main()
{
  ios::sync_with_stdio(false);     
  int N,M,T;
  cin>>N>>M>>T;
  for(int i=0;i<M;i++)
  {
    int ts,id;
    cin>>ts>>id;
    v.push_back(make_pair(ts,id));
  }
  sort(v.begin(),v.end());
  for(int i=1;i<=N;i++)
  {
    p[i].id=i;
    p[i].lasttime=0;
    p[i].prio=0;
    p[i].yes=0;
  }
  for(int i=0;i<M;)
  {
    int j=i;
    while (j<M&&v[i]==v[j])
    {
      j++;
    }
    int cnt=j-i;
    int t=v[i].first;
    int id=v[i].second;
    p[id].prio=max(0,p[id].prio-(t-p[id].lasttime-1));
    p[id].lasttime=t;
    if(p[id].prio<=3)
    {
      p[id].yes=0;
    }
    p[id].prio+=2*cnt;
    if(p[id].prio>5)
    {
      p[id].yes=1;
    }
    i=j;
  }
  int num=0;
  for(int i=1;i<=N;i++)
  {
    if(p[i].lasttime<T)
    {
      p[i].prio=max(0,p[i].prio-(T-p[i].lasttime));
      if(p[i].prio<=3) p[i].yes=0;
    }
    if(p[i].yes) num++;
  }
  cout<<num<<endl;
  //system("pause");
  return 0;
}
```

###### 分割

> (牛客 2021年广东工业大学第十五届文远知行杯程序设计竞赛（同步赛）)
>
> 有n条平行y轴的直线，m条平行x轴的直线，求这些直线所有可能形成的矩形的总面积对$10^9+7$取模。保证所有直线不完全重叠。
>
> $2\le n,m\le10^5,-10^9\le x_i,y_i \le10^9$

题目最后一句话即没有重合线。本题如果只有一维可以用类似于校赛矩阵题的思维，但二维时难以继续。但是对面积的积累有更优的算法，并且可以乘起来。

记得先排序。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mn 100002
ll x[mn],y[mn],n,m,ans,acx,acy;
void calc(ll n, ll* x, ll& acx)
{
    for(ll i=1,bf=0,now;i<n;++i)
    {
        (now=(x[i]-x[i-1])*i+bf)%=mod;
        (acx+=now)%=mod;
        bf=now;
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;++i) scanf("%lld",x+i); sort(x,x+n);
    for(ll i=0;i<m;++i) scanf("%lld",y+i); sort(y,y+m);
    calc(n,x,acx);
    calc(m,y,acy);
    printf("%lld",(acx*acy)%mod);
    return 0;
}
```

#### 例题

##### 经过次数

> 线上有n个连续的点，有长为m的拐点数，表示路径m1->m2->...->mlst，求每条路径经过了多少次(n-1条路径)

设f[i]表示从i到i+1的路径，每组拐点，计数：

f[min(bf,now)]++;f[max(bf,now)]--;然后跑一遍前缀和即可。

##### Patting Heads S

> 有n个数，对第i个数，输出所有(除它之外)能被它整除的数的数量

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
ll ans[MAXN], n, a[MAXN], mx, vis[MAXN];
signed main()
{
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &a[i]), ++vis[a[i]], mx = max(a[i], mx);
	repe(i, 1, mx)
	{
		if (!vis[i]) continue;
		for (ll j = 1; j * i <= mx; ++j) if (vis[i * j]) ans[i * j] += vis[i];
		--ans[i];
	}
	rep(i, 0, n) printf("%d\n", ans[a[i]]);
	return 0;
}
```

##### k倍区间

> (蓝桥)有长为n个序列，求有多少个连续子序列(含自身)的和是k的倍数
> $1\le n,k,a_i\le10^5$

是k的倍数化为对k取模为0。根据前缀和，区间$[l,r]$的和取模为0，即：
$$
(s[r]-s[l-1])\mod k=0\\\Rightarrow
s[r]\mod k=s[l-1]\mod k
$$
转化为对于前缀和取模序列，有多少个值相互相等。如果暴力枚举数对，时间复杂度为$\Omicron(n^2)$，显然会TLE，因此需要优化。

取假设每个连续子序列都是k个倍数，则最大情况数为
$$
\sum_{i=1}^ni=\frac{n(n-1)}2,n=10^5\Rightarrow10^{10}
$$
该结果接近int的最大值，为防止炸int，要开long long(不开会挂)。

以下两解法时间和空间复杂度均为$\Omicron(n)$。

###### 解法一：组合数学

显然$1\le l,r\le n$即$0\le l-1$，，以$s[i]\mod k$为下标建立桶(桶的最终结果$b[i]$代表$s[x]\mod k=i,1\le x\le n$的$x$共有$b[i]$个，使用桶排思维)。因为$s[0]\mod k=0$，故桶的首项计数+1。对于桶的每个元素$b[i]=a$，求$C_a^2$的和即可。

```c++
#include <bits/stdc++.h>
#define mn 100002
long long sum,vis[mn],n,k,cnt,v;
signed main()
{
	scanf("%lld%lld",&n,&k); ++vis[0];
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&v);
		(cnt+=v)%=k;
		++vis[cnt];
	}//注意下面的循环，i<k不是i<n,vis[i]不是vis[cnt]
	for(int i=0;i<k;++i) sum+=vis[i]*(vis[i]-1)>>1;
	printf("%lld",sum);
	return 0;
}
```



###### 解法二：双前缀和

由计数原理(数对计数的定义)，将桶简化为第二个前缀和。即每次进桶前累加一次原有数目。注意到解法一的$s[0]\mod k=0$同样存在，所以最后对首项再累加一次。(累加在先在后都无所谓，但是要累加一次)

```c++
#include <bits/stdc++.h>
#define mn 100002
int vis[mn],n,k,cnt,v;
long long sum;
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&v);
		(cnt+=v)%=k;
		sum+=vis[cnt]++;
	}
	printf("%lld",sum+vis[0]);
	return 0;
}
```

##### 子段异或

> (oj)有长为$n$的数列，输出异或和为0的连续子段数。$1\le n\le2\times10^5,0\le a_i\le2^{30}-1$

可以建立异或的前缀和，显然异或和为0等于：
$$
s[r-1]\oplus a[r]=0\Rightarrow s[l-1]\oplus s[r]=0 (0\sim l-2重复两次=0)\\
\Rightarrow s[l-1]=s[r]
$$
这时可以使用上一题的计数法的其中一种，则很容易就过了：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> m;
ll n,c,v,ans;
signed main()
{
	for(scanf("%lld",&n),++m[0];n;--n)
		scanf("%lld",&v),ans+=m[c^=v]++;
	return printf("%lld",ans)&0;
}
```

##### 周游山区

> (oj)环形山区有n个加油站，每个加油站可补充$p_i$公里路程的油，顺时针到下一个加油站的距离为$d_i$，从每个加油站出发(初始油量为该加油站的油)，能否顺/逆时针走完回来？($0\le n\le10^6,0\le p_i,d_i\le2\times10^9$)

走完一圈后油量可以为0，但没走完之前不可以为0；但是如果考虑子问题，那么只需要考虑大于等于0，在顺时针时，从$i$出发，可以走回$i$的条件为同时满足以下等式：(需要注意$d_0=0$)
$$
\begin{cases}
(p_i-d_{i})\ge0\\
(p_i-d_{i})+(p_{i+1}-d_{i+1})\ge0\\
\dots\\
(p_i-d_{i})+(p_{i+1}-d_{i+1})+\dots+(p_{i+n-1}-d_{i+n-1})\ge0
\end{cases}
$$
设前缀和$s_n=\sum_{i=1}^n p_i-d_i$，即需要同时满足：
$$
\begin{cases}
s_i-s_{i-1}\ge0\\
s_{i+1}-s_{i-1}\ge0\\
\dots\\
s_{i+n-1}-s_{i-1}\ge0
\end{cases}
$$
即在$[i,i+n-1]$内，$s_\min-s_{i-1}\ge0$。

可以用单调队列维护一个区间最小值。

相似地，逆时针时有：(倒序走，设$d_0=d_n$)
$$
\begin{cases}
(p_i-d_{i-1})\ge0\\
(p_i-d_{i-1})+(p_{i-1}-d_{i-2})\ge0\\
\dots\\
(p_i-d_{i-1})+(p_{i-1}-d_{i-2})+\dots+(p_{i-n+1}-d_{i-n})\ge0
\end{cases}
$$
设前缀和$s_n=\sum_{i=1}^n p_i-d_{i-1}$，即需要同时满足：
$$
\begin{cases}
s_i-s_{i-1}\ge0\\
s_{i}-s_{i-2}\ge0\\
\dots\\
s_{i}-s_{i-n+1}\ge0
\end{cases}
$$
即在$[i-n+1,i]$内(假设化环为线且补充在负数区(代码是正数区))：
$$
(s_i-s_j)_\min\ge0\quad j\in[i-n+1,i]\Rightarrow s_i-s_{\max}\ge0
$$
所以用单调队列维护一个区间最大值。

注意单调区间长度不可以大于等于$n$。

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 2000002
#define nemp hd<=ed
ll q[mn],hd,ed=-1,s[mn],p[mn],d[mn],n,n2;
bool ok[mn];
signed main()
{
    scanf("%lld",&n); n2=n<<1;
    for(ll i=1;i<=n;++i) scanf("%lld%lld",p+i,d+i),s[i]=s[i+n]=p[i]-d[i];
    for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
    for(ll i=n2;i;--i)
    {
        while(nemp&&q[hd]-i>=n) ++hd;
        while(nemp&&s[q[ed]]>=s[i]) --ed;
        q[++ed]=i;
        if(i<=n&&s[q[hd]]-s[i-1]>=0) ok[i]=true;
    } hd=0,ed=-1;  d[0]=d[n];
    for(ll i=1;i<=n;++i) s[i]=s[i+n]=p[i]-d[i-1];
    for(ll i=1;i<=n2;++i) s[i]+=s[i-1];
    for(ll i=1;i<=n2;++i)
    {
        while(nemp&&i-q[hd]>=n) ++hd;
        if(i>n&&s[i]-s[q[hd]]>=0) ok[i-n]=true;
        while(nemp&&s[q[ed]]<=s[i]) --ed;
        q[++ed]=i;
    }
    for(ll i=1;i<=n;++i) printf(ok[i]?"YES\n":"NO\n");
    return 0;
}
```

### 离散化

#### 绝对大小转相对

##### 程序自动分析

###### 快排离散

离散复杂度为快排复杂度；单次查询复杂度为$O(logn)$

> 给定t个程序，每个程序有n个等式关系，分别为(x y e)若e==1，表示x=y，否则x!=y，判断n个条件是否能同时成立，是，输出YES，否则输出NO(x,y范围为0~1e9,n在1e5)

显然本题将e==1的全部合并，再判断其余的是否在同一个并查集父亲里，如果在，则冲突，输出NO，否则YES；由x,y范围，显然不可能开这么大的并查集，而显然至多只有2n个不同的x,y，所以可以离散化x,y，将其压缩至[0,2n)内的相对大小。

```c++
#include <bits/stdc++.h>//个人实现版本
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
#define node pair<ll,ll>
ll fa[MAXN], t, n, x, y, e, n2;
ll finds(ll& k)
{
	while (k != fa[k]) k = fa[k] = fa[fa[k]];
	return k;
}
signed main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		n2 = n << 1;
		rep(i, 0, n2) fa[i] = i;//如果n就挂了
		set<ll> s;
		vector<ll> sv;
		vector<node> ve, vn;
		rep(i, 0, n)
		{
			scanf("%d%d%d", &x, &y, &e);
			if (e) ve.push_back({ x,y });
			else vn.push_back({ x,y });
			s.insert(x);
			s.insert(y);
		}
		for (auto& i : s) sv.push_back(i);
		for (auto& i : ve)
		{
			x = lower_bound(sv.begin(), sv.end(), i.first) - sv.begin();
			y = lower_bound(sv.begin(), sv.end(), i.second) - sv.begin();
			fa[finds(x)] = finds(y);
		}
		bool ok = true;
		for (auto& i : vn)
		{
			x = lower_bound(sv.begin(), sv.end(), i.first) - sv.begin();
			y = lower_bound(sv.begin(), sv.end(), i.second) - sv.begin();
			if (finds(x) == finds(y))
			{
				ok = false;
				break;
			}
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
```

```c++
#include <bits/stdc++.h>//写法二
using namespace std;
int t,n,f[1000007],book[1000007*3];  //t表示t组数据，n表示有n个操作，f[]是我们并查集的数字，book[]是离散化的数组 
struct node{
    int x,y,e;
}a[1000001];  
bool cmp(node a,node b){
    return a.e>b.e;
}//排 序将e==1的放在前面 
inline void first(int kkk){
    for(int i=1;i<=kkk;i++)  f[i]=i;
}//初 始 化 
int get(int x){
    if(x==f[x]) return x;
    return f[x]=get(f[x]);
}
int main(){
    scanf("%d",&t);
    while(t--){
      int tot=-1;
      memset(book,0,sizeof(book));
      memset(a,0,sizeof(a));
      memset(f,0,sizeof(f));
    int flag=1;
        scanf("%d",&n);
       
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].e);
            book[++tot]=a[i].x;
            book[++tot]=a[i].y;
        }
        sort(book,book+tot);//排序 
        int reu=unique(book,book+tot)-book;  //去重 
        for(int i=1;i<=n;++i){
           a[i].x=lower_bound(book,book+reu,a[i].x)-book;
           a[i].y=lower_bound(book,book+reu,a[i].y)-book;   
        } 
        first(reu);   //初始化 
        sort(a+1,a+n+1,cmp);  //按e排序 
        for(int i=1;i<=n;i++){
            int r1=get(a[i].x);
            int r2=get(a[i].y);
            if(a[i].e){
                f[r1]=r2;  //就是我们的merge操作 
            }else if(r1==r2){
                printf("NO\n");
                flag=0;  //如果不满足条件，标记为否 
                break;
            }
        }
        if(flag)    printf("YES\n");   //都满足条件了 
    }
    return 0;
}
```

###### 哈希离散

单次查询复杂度$O(1)$，在该题上，可以从快排离散的3s(28MB)优化为1.5s(9MB)的复杂度。(不使用快读和氧气加速)

缺点：手写哈希太麻烦。

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#define Max 100010
#define mod 99991 

using namespace std;

int fa[2*Max],d[2*Max];
struct node{
	int real,map;
}un[Max];
vector <node> hash[Max]; 
int tot,cnt;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int ask(int i,int j,bool k)
{
	if(find(i)==find(j)) return 1;
	else if(k){
		fa[find(j)] = find(i);
		return 0;
	}
	return 0;
}
int map(int i,int j,bool k)
{
	int x,y,ok=1;
	int a = i % mod, b = j % mod;
	if(!hash[a].empty()){
		for(int l = 0; l < hash[a].size(); l++)
			if(i==hash[a][l].real) x = hash[a][l].map,ok = 0;
		if(ok) hash[a].push_back((node){i,++tot}),x = tot;
	}
	else hash[a].push_back((node){i,++tot}),x = tot;
	ok = 1;
	if(!hash[b].empty()){
		for(int l = 0; l < hash[b].size(); l++)
			if(j==hash[b][l].real) y = hash[b][l].map,ok = 0;
		if(ok) hash[b].push_back((node){j,++tot}),y = tot;
	}
	else hash[b].push_back((node){j,++tot}),y = tot;
	return ask(x,y,k); 
}
int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		for(int i = 1; i <= 200010; i++)
			fa[i] = i;
		for(int i = 0; i < 100000; i++)
			hash[i].clear();
		memset(d,0,sizeof(d));
		memset(un,0,sizeof(un));
        //以上每步的初始化不能丢
		cnt = tot = 0;
		int num,now = 1;
		cin >> num;
		for(int i = 1; i <= num; i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			if(z) map(x,y,1);
			else un[++cnt].real = x, un[cnt].map = y;	
		}
		for(int i = 1; i <= cnt; i++)
			if(map(un[i].real,un[i].map,0)){
				now = 0;
				cout << "NO" <<endl;
				break;
			}
		if(now) cout << "YES" << endl;
	}
	return 0;
}
```

##### 火柴排队

> 将相邻火柴交换，使得两列火柴距离(ai-bi)^2^和最小，求交换次数。

$$
\sum_{k=i}^n(a_k-b_k)^2=\sum_{k=i}^na_k+\sum_{k=i}^nb_k-2\times\sum_{k=i}^na_kb_k\\
其中顺序积\ge乱序积\\
为使原式最小，故使积最大，即全部为顺序积
$$

所以转化为求逆序对问题。

然后进行离散化。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
#define MOD 99999997
ll n, ans, x[MAXN], p[MAXN];
struct point { ll v, i; } la[MAXN], lb[MAXN];
inline bool cmp(const point& x, const point& y) { return x.v < y.v; }
void merges(ll lf, ll rf)
{
	if (lf == rf) return;
	ll cf = lf + rf >> 1;
	merges(lf, cf);
	merges(cf + 1, rf);
	ll i = lf, k = lf, j = cf + 1;
	while (i <= cf && j <= rf)
	{
		if (x[i] <= x[j]) p[k++] = x[i++];
		else
		{
			p[k++] = x[j++];
			ans = (ans + cf - i + 1) % MOD;//写成cf-lf+1暴死
		}
	}
	while(i<=cf) p[k++] = x[i++];
	while(j<=rf) p[k++] = x[j++];
	repe(i, lf, rf) x[i] = p[i];
}
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld", &la[i].v), la[i].i = i;
	repe(i, 1, n) scanf("%lld", &lb[i].v), lb[i].i = i;
	sort(la + 1, la + 1 + n, cmp);
	sort(lb + 1, lb + 1 + n, cmp);
	repe(i, 1, n) x[lb[i].i] = la[i].i;
	merges(1, n);
	printf("%lld", ans);
	return 0;
}
```



#### 区间覆盖

> 有n个[a,b]区间，求它们的并区间长度

注：当区间不交，且总长较小时，可以使用暴力bool/线段树/珂朵莉树

##### 校门外的树

从0~m有m+1棵树，保证区间不交，输入n个区间砍去[x,y]的树，求剩下的树数。

###### 朴素

```python
l,m=[int(i) for i in input().strip().split()]
t=[True for i in range(l+1)]
for i in range(m):
    lf,rf=[int(i) for i in input().strip().split()]
    for j in range(lf,rf+1):
        t[j]=False
print(sum(t))
```

###### 离散化

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 20002
int n, lf[MAXN], rf[MAXN], ans, m;
signed main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &lf[i], &rf[i]);
	sort(lf, lf + n);
	sort(rf, rf + n);
	for (int i = 0; i < n; ++i)
	{
		ans += rf[i] - lf[i] + 1;
		if (i + 1 < n && lf[i + 1] <= rf[i]) ans -= rf[i] - lf[i + 1] + 1;
	}
	printf("%d", m - ans + 1);
	return 0;
}
```

###### 线段树

> 见数据结构-树-线段树-例题

###### 珂朵莉树

> 见数据结构-树-线段树-例题

###### 分块

略

##### 火烧赤壁

此题题干完全符合引言部分

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 20002
int n, lf[MAXN], rf[MAXN], ans;
signed main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &lf[i], &rf[i]);
	sort(lf, lf + n);
	sort(rf, rf + n);
	for (int i = 0; i < n; ++i)
	{
		ans += rf[i] - lf[i];
		if (i + 1 < n && lf[i + 1] < rf[i]) ans -= rf[i] - lf[i + 1];
	}
	printf("%d", ans);
	return 0;
}
```

### 逆向

#### 线上相遇问题

在一条有限长线上，(一般每次移动一格，坐标都是整数)，一开始不同位置有若干人，方向只有朝左或朝右，通过两人相遇传递某种性质，且相遇后两人均立即掉头，相遇过程可以简化为两人直接穿过对方，并且传递这种性质，而不是模拟这个相遇。那么，就可以大大简化整体移动次数，显然在最坏情况下，每次模拟一步，需要模拟$\Omicron(n^3)$次，而这样简化之后，每人最长移动距离都是线长，时间复杂度降到$\Omicron(n^2)$。

##### 蚂蚁感冒

> (蓝桥)长100厘米线有n蚂蚁，朝左(负号)或朝右，坐标点为$1\sim100$的整数，输入的第一只蚂蚁感冒。每只蚂蚁沿着自己的方向往前走，速度是1，两蚂蚁碰面时，同时掉头往相反方向走，相遇时，如果两个中任意一个蚂蚁感冒，传染感冒，求全部蚂蚁走出线后，感冒蚂蚁数。

###### 模拟

由于100厘米其实至多有100个蚂蚁(实际题给50)，故复杂度很低，可以直接模拟：

```c++
#include <bits/stdc++.h>
using namespace std;
int vis[106];
struct ant
{
	bool left,inf;
	int pos;
} a[53];
inline bool cmp(const ant& a, const ant& b)
{
	return a.pos<b.pos;
}
int n,m,ans;
signed main()
{
	scanf("%d",&n); m=n;
	for(int i=0;i<=102;++i) vis[i]=-1;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i].pos);
		if(a[i].pos<0) a[i].pos=-a[i].pos,a[i].left=true;
		vis[a[i].pos]=i;
	}
	a[0].inf=true;
	//sort(a,a+n,cmp);
	while(m)
	{
		for(int i=0;i<n;++i)
		{
			if(a[i].pos<0||a[i].pos>100) continue;
			int p=a[i].pos;
			if(a[i].left)
			{
				if(p>0&&vis[p-1]>=0)
				{
					int j=vis[p-1];
					bool inf=a[i].inf||a[j].inf;
					a[i].inf=inf,a[j].inf=inf;
					a[i].left=!a[i].left,a[j].left=!a[j].left;
				}
				else --a[i].pos,vis[p-1]=i,vis[p]=-1;
				if(a[i].pos<0) --m;
			}
			else
			{
				if(p<100&&vis[p+1]>=0)
				{
					int j=vis[p+1];
					bool inf=a[i].inf||a[j].inf;
					a[i].inf=inf,a[j].inf=inf;
					a[i].left=!a[i].left,a[j].left=!a[j].left;
				}
				else ++a[i].pos,vis[p+1]=i,vis[p]=-1;
				if(a[i].pos>100) --m;
			}
		}
		//sort(a,a+n,cmp);
	}
	for(int i=0;i<n;++i) if(a[i].inf) ++ans;
	printf("%d",ans);
	return 0;
}
```

###### 判断

```c++
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a[51],i,j,t,c,s=1,flag=0;
	cin>>n;
	for (i=0;i<n;i++)
	  cin>>a[i];
	c=a[0];  //c记录感冒的蚂蚁 
	
	for (i=0;i<n-1;i++) //按绝对值从小到大排序 
	for (j=i+1;j<n;j++)
	{
		if (fabs(a[i])>fabs(a[j]))
		{
			t=a[i];a[i]=a[j];a[j]=t;
		}
	}
	for (i=0;i<n;i++)
	{
		if (a[i]==c)
		{
			c=i;   //c现在用来记录第一个感冒蚂蚁的下标 
			break;
		}
	}
	for (i=0;i<c;i++)//排除最左边的 
	{
		if (a[i]>0)  //说明是向右移动，可能会碰到感冒的蚂蚁，所以左端的不能去除 
	    	break;
		else
		    a[i]=0;
	}
	for (i=n-1;i>c;i++)//排除最右边的
	{
		if (a[i]<0)//说明是向左移动。可能碰到感冒蚂蚁，所以左端不能去除 
		  break;
		else
		  a[i]=0;
	}
	if (a[c]<0)//说明这只感冒蚂蚁是向左端的走的 
	{
		for (i=c-1;i>=0;i--)
		{
			if (a[i]==0)
			   break;
			if (a[i]>0)//凡是向右走的都被会感染的 
			{ 
			   s++;
			   flag=1;
			} 
		}
		if (flag)//说明从左向右走的蚂蚁有被感染的，正向右边袭来 
		for(i=c+1;i<n;i++)
		{
			if (a[i]==0)
			  break;
			if (a[i]<0)//向左的蚂蚁会被感染 
			  s++;
	   } 
	}
	else//感冒蚂蚁是向右走的 
	{
		for (i=c+1;i<n;i++)
		{
			if (a[i]==0)
			 break;
			if (a[i]<0)//向左走的 肯定会和感冒蚂蚁碰面 
			 {
			 	s++;
			 	flag=1;
			 }
		}
	   if (flag)//说明向左走的被感冒了 
	   for(i=c-1;i>=0;i--)//左边的  
	   {
	       if (a[i]==0)
		     break;
		   if (a[i]>0) //向右走的就完蛋咯
		   	 s++;	
	   } 
	}
	cout<<s;
	return 0;
}
```

#### 例题

##### 区间去极均值

> 给定n和n个数，对于k(1<=k<=n-2)，排掉前k个数和余下的数中最小值后取平均得到结果。输出所有使得结果最大的k。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define red(i,a,b) for(int i=a;i>=b;--i)
int n, mi, sum, ks[MAXN], ki, v[MAXN];
double now, temp;
signed main()
{
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &v[i]);
	mi = sum = v[n];
	red(i, n - 1, 2)
	{
		mi = min(mi, v[i]);
		sum += v[i];//这个double化只需一处，这里是防warning
		temp = ((double)sum - mi) / ((double)n - i);
		if (temp > now) ks[ki = 1] = i - 1, now = temp;
		else if (temp == now) ks[++ki] = i - 1;
	}//这个double判定能过，如果用EPS判定更好
	red(i, ki, 1) printf("%d\n", ks[i]);
	return 0;
}
```

##### 尼克的任务

> 见理论/基础-动态规划-例题



## 排序

### 交换两个数

算法1

```c
int a,b,t; t=a; a=b; b=t;
```

或

```c
void swap(int* a, int* b)
{
    int t = *a; *a = *b; *b = t;
}
swap(&a, &b);
```

算法2//不推荐

```c
a = a + b;
b = a - b;
a = a - b;
```

或

```c
b=a*b;a=b/a;b=b/a;
```

算法3 //控制打印顺序

```c
scanf("%d%d", &a, &b);
print("%d %d\n", b, a);
```

算法4：位运算//推荐(整型Only)

```c
a^=b^=a^=b
```

### 反转三位数

算法1：

```c
printf("%c%c%c", getchar(), getchar(), getchar());
```

算法2：

```c
int a,b,c;
    scanf("%1d%1d%1d", &a,&b,&c);
    printf("%d%d%d\n",c,b,a);
```

### 三位数

以从小到大为例

算法1：共六次if-else-if-..(对应阶乘3!即3的全排列，懂的都懂)

算法2：//交换排序

``````c
int a,b,c,t;
if(a>b){t=a;a=b;b=t;}//3,2,1→2,3,1
if(a>c){t=a;a=c;c=t;}//2,3,1→1,3,2
if(b>c){t=b;b=c;c=t;}//1,3,2→1,2,3
``````

算法3://冒泡排序：上述改为a>b,b>c,a>b, 略

算法4://选择排序 略

### 多位数

排序算法分为比较类排序和非比较排序。比较排序有交换排序（如冒泡排序和快速排序）、插入排序（简单插入排序和希尔排序）、选择排序（简单选择排序和堆排序）、归并排序（二、多路归并排序）。非比较排序有计数排序、桶排序和基数排序。

以升序为例,a为数组,n为长度,k为最大值(设最小值为0)

| 方法 | 平均   | 最坏   | 最好   | 空间   | 方式 | 稳定 |
| ---- | ------ | ------ | ------ | ------ | ---- | ---- |
| 冒泡 | n^2    | n^2    | n      | 1      | in   | Y    |
| 选择 | n^2    | n^2    | n^2    | 1      | in   | N    |
| 插入 | n^2    | n^2    | n      | 1      | in   | Y    |
| 希尔 | n^1.25 | n^2    | n      | 1      | in   | N    |
| 归并 | nlog2n | nlog2n | nlog2n | n      | out  | Y    |
| 快速 | nlog2n | n^2    | nlog2n | nlog2n | in   | N    |
| 堆   | nlog2n | nlog2n | nlog2n | 1      | in   | N    |
| 计数 | n+k    | n+k    | n+k    | n+k    | out  | Y    |
| 桶   | n+k    | n^2    | n      | n+k    | out  | Y    |
| 基数 | n*k    | n*k    | n*k    | n+k    | out  | Y    |

备注：

稳定性指的是相同元素是否不发生改变，如3a-3b不会变成3b-3a就是稳定，判断如下：

首先需要足以区分重复元素的辅助标记；一种方法是将稳定排序后(如冒泡算法)的标记数组跟待检测排序的数组对比，复杂度为O(n)。



#### 交换

总次数为n(n+1)/2

```c
for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
        if(a[j]<a[i]) {t=a[j];a[j]=a[i];a[i]=t;}
```

#### 选择 

SelectionSort

```c
for(int i=0;i<n-1;i++)
    {
        int k = i;//最大数下标
        for(int j = i+1; j < n; j++)
            if(a[j]<a[k])
                k=j;
        if(k!=i){int t=a[k];a[k]=a[i];a[i]=t;}
    }
```

#### 插入

 InsertionSort

```c
for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            if(a[j] < a[j-1])
            {int t=a[j-1];a[j-1]=a[j];a[j]=t;}
            else break;
        }
    }
```

1. 复杂度O(n*n)，即表达式0.5(n^2-n)
2. 如果数据相对有序，真实运算次数会比较少(甚至跟高等排序一样快)

#### 冒泡 

BubbleSort

```c
for(int i=0, flag=1; flag; i++)
    {
        flag=0;
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                int t=a[j];a[j]=a[j-1];a[j-1]=t;
                flag=1;
            }
        }
    }
```

1. 如果改为a[j]<=a[j-1]，算法从稳定变为不稳定
2. 复杂度计算方式同插入排序
3. 交换次数称为反序数/逆序数，体现数列错乱程度。

```c
//使用分治法求逆序数并排序的方法：
#define MAX 200000
#define SENTINET 2000000000
typedef long long llong;
int L[MAX/2+2],R[MAX/2+2];
llong merges(int A[], int n, int left, int mid, int right)
{
    int i,j,k;
    llong cnt=0;
    int n1=mid-left;
    int n2=right-mid;
    for(i=0;i<n1;i++) L[i] = A[left+i];
    for(i=0;i<n2;i++) R[i] = A[mid+i];
    L[n1] = R[n2] = SENTINET;
    i=j=0;
    for(k=left;k<right;k++)
    {
        if(L[i] <= R[j]) A[k] = L[i++];
        else {A[k] = R[j++];  cnt += n1 - i; }
    }
    return cnt;
}
llong mergesort(int A[], int n, int left, int right)
{
    int mid;
    llong v1, v2, v3;
    if(left + 1 < right)
    {
        mid = (left + right) / 2;
        v1 = mergesort(A, n, left, mid);
        v2 = mergesort(A, n, mid, right);
        v3 = merges(A, n, left, mid, right);
        return v1+v2+v3;
    }
    else return 0;
}
```

```c++
//树状数组解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 200002
inline ll lowbit(ll& k) { return k & (-k); }
ll tr[MAXN], rnk[MAXN], n, ans;
struct point { ll n, v; } b[MAXN];
inline bool cmp(const point& a, const point& b)
{
	if (a.v == b.v) return a.n < b.n;
	return a.v < b.v;
}
inline void insert(ll p, ll d)
{
	for (; p <= n; p += lowbit(p)) tr[p] += d;
}
inline ll query(ll p)
{
	ll sum = 0;
	for (; p; p -= lowbit(p)) sum += tr[p];
	return sum;
}
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n)
	{
		scanf("%d", &b[i].v);
		b[i].n = i;
	}
	sort(b + 1, b + 1 + n, cmp);
	repe(i, 1, n) rnk[b[i].n] = i;
	repe(i, 1, n)
	{
		insert(rnk[i], 1);
		ans += i - query(rnk[i]);
	}
	printf("%lld", ans);
	return 0;
}
```

**逆序对的应用：**

1.求两元素一样顺序不同字符串使之相等的最小相邻交换次数

```c++
#include <bits/stdc++.h>
#define MAXN 1000002
#define ALP 26
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef long long ll;
int n,t[MAXN],b[MAXN],ch,ib[ALP];
ll ans;
vector<int> bi[ALP];
void merges(int lf, int rf)
{
    if(lf==rf) return;
    int cf=lf+rf>>1, i=lf, j=cf+1, k=lf;
    merges(lf,cf);
    merges(cf+1,rf);
    while(i<=cf && j<=rf)
    {
        if(b[i]<=b[j]) t[k++]=b[i++];
        else
        {
            t[k++] = b[j++];
            ans += cf-i+1;
        }
    }
    while(i<=cf) t[k++]=b[i++];
    while(j<=rf) t[k++]=b[j++];
    rep(m,lf,rf+1) b[m]=t[m];
}
signed main()
{
    scanf("%d%*c",&n);
    rep(i,0,n)
    {
        scanf("%c",&ch);
        ch-='A';
        bi[ch].push_back(i);
    }
    scanf("%*c");
    rep(i,0,n)
    {
        scanf("%c",&ch);
        ch-='A';
        b[i]=bi[ch][ib[ch]++];
    }
    merges(0,n-1);
    printf("%lld",ans);
    return 0;
}
```

```c++
#define repe(i,a,b) for(ll i=a;i<=b;++i)
ll r[MAXN], a[MAXN], n, ans;//实现2
void mergesort(ll lf, ll rf)
{
	if (lf == rf)return;
	ll cf = lf + rf >> 1, i = lf, j = cf + 1, k = lf;
	mergesort(lf, cf);
	mergesort(cf + 1, rf);
	while (i <= cf && j <= rf)
	{
		if (a[i] <= a[j]) r[k++] = a[i++];
		else r[k++] = a[j++], ans += cf - i + 1;
	}
	while (i <= cf) r[k++] = a[i++];
	while (j <= rf) r[k++] = a[j++];
	repe(u, lf, rf) a[u] = r[u];
}
```

树状数组解法：

```c++
#include <bits/stdc++.h>
#define MAXN 1000002
#define ALP 26
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
inline int lowbit(int &k){return k & (-k);}
struct point
{
    int n,v;
} b[MAXN];//v原值
int tr[MAXN],rnk[MAXN],n,ib[ALP],ch;
ll ans;
vector<int> bi[ALP];
inline bool cmp(point &a, point &b)
{
    if(a.v==b.v) return a.n<b.n;
    return a.v<b.v;
}
inline void insert(int p, int d)
{
    for(;p<=n;p+=lowbit(p)) tr[p]+=d;
}
inline int query(int p)
{
    int sum=0;
    for(;p;p-=lowbit(p)) sum+=tr[p];
    return sum;
}
signed main()
{
    scanf("%d%*c",&n);
    rep(i,1,n)
    {
        scanf("%c",&ch);
        ch-='A';
        bi[ch].push_back(i);
    }
    scanf("%*c");
    rep(i,1,n)
    {
        scanf("%c",&ch);
        ch-='A';
        b[i].v=bi[ch][ib[ch]++];
        b[i].n=i;
    }
    sort(b+1,b+1+n,cmp);
    rep(i,1,n)
    {
        rnk[b[i].n]=i;
    }
    rep(i,1,n)
    {
        insert(rnk[i],1);
        ans+=i-query(rnk[i]);
    }
    printf("%lld",ans);
    return 0;
}
```

#### 希尔 

ShellSort

```c
//方法1：间隔ic呈等比数列
int ic = n;
    while(ic!=1)
    {
        ic /= 2;
        for(int k=0;k<ic;k++)
            for(int i=k+ic;i<n;i+=ic)
                for(int j=i;j>k;j-=ic)
                {
                    if(a[j]<a[j-ic]) {int t=a[j-ic];a[j-ic]=a[j];a[j]=t;}
                    else break;
                }
    }
```

1. 本质上是间隔ic地执行插入算法
2. 如果ic(逆序)取1,4,13,40,...,3ic+1，则算法复杂度基本在O(N^1.25)
3. 如果遇上2的幂指数等ic=1前基本不需要排序的数列，希尔排序效率大幅下降。

#### 归并 

MergeSort

```c
void mergearray(int a[], int st, int cf, int lst, int t[])
{//合并a[st,cf],a[cf+1,lst]，比下面的写法好写
    int i=st, m=cf, j=cf+1, n=lst, k=0;
    while(i<=m&&j<=n)
    {
        if(a[i]<=a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while(i<=m)t[k++] = a[i++];
    while(j<=n)t[k++] = a[j++];
    for(int p=0;p<k;p++) a[st+p]=t[p];
}
void mergesort(int a[], int st, int lst, int t[])
{
    if(st<lst)
    {
        int cf=(st+lst)/2;
        mergesort(a,st,cf,t);
        mergesort(a,cf+1,lst,t);
        mergearray(a,st,cf,lst,t);
    }
}
```

```c++
//写法二,降序；
#define MAX 500000
#define SENTINET -2000000000
//如果改为升序，SENTINET取反
int L[MAX/2+2], R[MAX/2+2];
//int cnt;
void merges(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i < n1; i++) L[i] = A[left + i];
    for(int i=0; i < n2; i++) R[i] = A[mid + i];
    //seperate ori it db arr
    L[n1] = R[n2] = SENTINET;//edge value
    int i=0, j = 0;
    for(int k = left; k < right ; k++)
    {
        //cnt++;
        if(L[i] >= R[j])//改为升序，条件取反(=保留)
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}
void mergeSort(int A[], int n, int left, int right)
{
    if(left+1<right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merges(A, n, left, mid, right);
    }
}
```

近乎有序多次排序，如轮赛排名变动，应当使用归并排序。

结构体排序示例：(下标从0开始)

```c++
struct peo//仍然时间效率不算高
{
    int s,w,i;
} p[MAXN],temp[MAXN];
bool cmp(peo &a, peo &b)
{
    if(a.s!=b.s) return a.s>b.s;
    return a.i<b.i;
}
void merge(int lf, int rf)
{
    if(lf==rf) return;
    int cf=lf+rf>>1;
    merge(lf,cf);
    merge(cf+1,rf);
    int i=lf,j=cf+1,x=0;
    while(i<=cf&&j<=rf)
    {
        if(cmp(p[i],p[j])) temp[x++]=p[i++];
        else temp[x++]=p[j++];
    }
    while(i<=cf)temp[x++]=p[i++];
    while(j<=rf)temp[x++]=p[j++];
    rep(k,0,x)p[lf+k]=temp[k];
}//注:#define rep(i,a,b) for(int i=a;i<b;++i)
```

#### 快速 

QuickSort

```c
void quicksort(int a[], int st, int lst)
{
    if(st>=lst) return;
    int i=st,j=lst,k=a[st];
    while(i<j)
    {
        while(i<j&&a[j]>=k) j--;
        if(i<j) {a[i]=a[j]; i++;}
        while(i<j&&a[i]<k) i++;
        if(i<j) {a[j]=a[i]; j--;}
    }
    a[i] = k;
    quicksort(a, st, i-1);
    quicksort(a, i+1, lst);
}
```

```c
//写法二
int partition(int p, int r)
{
    int x,i,j,t;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            t=A[i];A[i]=A[j];A[j]=t;
        }
    }
    t=A[i+1];A[i+1]=A[r];A[r]=t;
    return i+1;
}
void quicksort(int A[], int n, int p, int r)
{//r可以取n-1为初始值,p则要取0
    int q;
    if(p<r)
    {
        q = partition(p, r);
        quicksort(A, n, p, q-1);
        quicksort(A, n, q+1, r);
    }
}  
```

```c++
void qsort(int l, int r)//解法3 升序
{
    int mv = a[(l+r)/2], i=l, j=r;
    do
    {
        while(a[i]<mv) i++;//若要改为降序，这两个不等号反向
        while(a[j]>mv) j--;
        if(i<=j)
        {
            swap(a[i++], a[j--]);
        }
    }while(i<=j);
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
```

#### 堆 

HeapSort

降序

```c
void lstheapfixdf(int a[], int i, int n)
{
    int j=2*i+1;
    while(j<n)
    {
        if(j+1<n && a[j+1]<a[j]) j++;
        if(a[i] <= a[j]) break;
        int t=a[i]; a[i] = a[j]; a[j] = t;
        i=j;
        j=2*i+1;
    }
}
void mklstheap(int a[], int n)
{
    for(int i=(n-1)/2;i>=0;i--)
        lstheapfixdf(a,i,n);
}
void heapsort(int a[], int n)
{
    mklstheap(a,n);
    for(int i=n-1;i>0;i--){int t=a[0]; a[0]=a[i]; a[i]=t;lstheapfixdf(a,0,i);}
}
```

#### 计数 

BinSort

```c
//自己写的(含空隙计数)
void binsort(int a[], int n, int mx, int t[])
{//t的长度为mx，a均为正整数
    int j=0;
    for(int i=0;i<mx;i++) t[i] = 0;//初始化
    for(int i=0;i<n;i++) t[a[i]-1]++;
    for(int i=0;i<mx;i++)
        while(t[i]) {t[i]--; a[j++]=i+1;}
}
```

```c
//写法2：减去一次while搜索
#define MAX 2000001
#define VMAX 10000
int main()//i think include what abbr.able
{
    unsigned short *A, *B;
    int C[VMAX+1];
    int n,i,j;
    scanf("%d", &n);
    A = malloc(sizeof(short)*n+1);//index0 do not use, same B, in order of convenience
    B = malloc(sizeof(short)*n+1);
    for(i=0;i<=VMAX;i++) C[i]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%hu", &A[i]);
        C[A[i]]++;
    }
    for(i=1;i<=VMAX;i++) C[i]+=C[i-1];
    for(j=1;j<=n;j++)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    return 0;//in fact output before it
}
```

#### 基数

 RadixSort

> 本焫鷄尚未学会，下同

#### 桶 

BucketSort

### 例题

#### 逆序对

```c++
#include <cstdio>
using namespace std;
typedef double db;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 500002
ll a[mn], b[mn], c[mn], ans, n;
void amerge(ll lf, ll rf)
{
	ll cf = (lf + rf) >> 1;
	if (lf < rf) amerge(lf, cf), amerge(cf + 1, rf);
	ll bi = lf, ci = cf + 1, ai = lf;
	while (bi <= cf) b[bi++] = a[ai++];
	while (ci <= rf) c[ci++] = a[ai++];
	ll bj = lf, cj = cf + 1, aj = lf;
	while (bj <= cf && cj <= rf)
		if (b[bj] > c[cj]) ans += cf - bj + 1, a[aj++] = c[cj++];
		else a[aj++] = b[bj++];
	while (bj <= cf) a[aj++] = b[bj++];
	while (cj <= rf) a[aj++] = c[cj++];
}
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld", a + i);
	amerge(1, n);
	printf("%lld\n", ans);
	return 0;
}
```

> 部分例题见算法-排序-多位数-冒泡

##### 小朋友排队

> 将小朋友从低到高排序，每次只能交换相邻两个，交换使得他们不高兴程度增加，增加幅度是上次他增加的数量+1(一开始的上次是0)，求排序后他们的不高兴程度之和的最小值。

###### 归并排序

总不高兴程度最小时，一个小朋友被交换次数等于他前边比他高的人数+后边比他低的人数，由此可以套用归并排序求逆序对的公式并加以改变：

```c++
#include <bits/stdc++.h>
#define mn 100002
typedef long long ll;
struct pupil
{
	ll v,m;
} a[mn],b[mn];
ll ans,n;
void merges(ll lf, ll rf)
{
	if(lf==rf) return;
	ll cf=lf+rf>>1;
	merges(lf,cf);
	merges(cf+1,rf);
	ll p=lf,q=cf+1,t=lf;
	while(p<=cf&&q<=rf)
	{
		if(a[p].v>a[q].v) a[q].m+=cf+1-p,b[t++]=a[q++];
		else a[p].m+=q-1-cf,b[t++]=a[p++];
	}
	while(q<=rf) b[t++]=a[q++];//+=写成=暴死
	while(p<=cf) a[p].m+=q-1-cf,b[t++]=a[p++];
	for(int i=lf;i<=rf;++i) a[i]=b[i];
}
signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;++i) scanf("%lld",&a[i].v);
	merges(0,n-1);
	for(int i=0;i<n;++i) ans+=(a[i].m+1)*a[i].m>>1;
	printf("%lld",ans);
	return 0;
}
```

###### 树状数组

```c++
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxn=100010;
const int inf = 1000100;
#define lowbit(x) ((x)&(-x))
long long total[maxn],ans;
int C1[inf];
int C2[inf];
int num[maxn];
int b[maxn];
void add(int x,int num,int C[])
{
    while(x<=inf)
    {
        C[x]+=num;
        x+=lowbit(x);
    }
}
void init(){
    for(int i=1;i<=maxn;i++)
        total[i]=total[i-1]+i;
}
long long Sum(int x,int C[])
{
    int res=0;
    while(x>0)
    {
        res+=C[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    init();
    ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        num[i]++;
        b[i]=i-Sum(num[i],C1);//i代表在这个数之前已经输入了几个数，也就是说这个数是第i个输入，前面已经有了i-1个数
                           //所以从0开始
        add(num[i],1,C1);   
    }
    for(int i=n-1;i>=0;i--)
    {
        add(num[i],1,C2);
        b[i]+=Sum(num[i]-1,C2);
        ans+=total[b[i]];
    }   
    cout<<ans<<endl;
}
```

#### 输出前n名

三种算法如下：

- 进行n次搜索，每次搜索输出最值并将原数据用反最值覆盖
  - 优点是n小时，运算次数比较少
  - 复杂度O(n*m)
- 先用上述任一种最适方法排序(什么最适看数据而定)，然后输出排序后的前n项
  - 复杂度O(mlogm+n)
- 生成一个分数列表(下标代表分数，元素代表频次)，然后输出
  - 优点时运算次数不算多
  - 限制是最小分度值不能太小，数据范围不能太大
  - 缺点是数据范围大时占用很多内存
  - 复杂度O(n+m+max(ai))

题目条件精确到：m(m<=1e6)个整数ai(0<=ai<=1e6),n(n<=1e3)

#### 最小成本排序

有n个重量互不重复为wi的货物，每次交换两个货物产生i+j的成本。1<=n<=1000,0<=wi<=10000，需要将货物升序排序，求最小成本

(数学原理略)

```c++
#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1000;
static const int VMAX = 10000;
int n, A[MAX], s;
int B[MAX], T[VMAX+1];
int solve()
{
    int ans = 0;
    bool V[MAX];
    for(int i=0;i<n;i++)
    {
        B[i] = A[i];
        V[i] = false;//V,B,T的设置是代码实现的关键！
    }
    sort(B, B+n);
    for(int i=0; i<n; i++) T[B[i]] = i;
    //for(int i=0; i<100; i++) cout << T[i] << " "; cout << endl;
    for(int i=0; i<n; i++)
    {
        if(V[i]) continue;
        int cur = i;
        int S = 0;
        int m = VMAX;
        int an = 0;
        while(1)
        {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if(V[cur]) break;
        }
        ans += min( S+(an-2)*m , S + m + (an+1)*s );
    }
    return ans;
}
int main()
{
    cin>>n;
    s=VMAX;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        s = min(s, A[i]);
    }
    int ans = solve();
    cout << ans << endl;
    return 0;
}
```

#### 排名

> 本蒟蒻自己出的题目，已收录在学校在线判题网站

由于某高校的计院太卷了，导致许多学生考试总分相同。为了给出学生的排名，现采用如下方法给学生排名：

1. 首先按总分从高到低排名；
2. 假设一共有 *m* 个科目（依次记作科目 *a*，科目 *b*…），对于总分数相同的同学，从科目 *a* 开始，依次按照各科目的分数高低区分排名，直到能够区分出排名为止。

例如：有三个科目 a*,*b*,*c*，有 4 个学生 A*,*B*,*C*,*D*，分数分别为：

- *A* 科目 *a* 70 分, 科目 *b* 80 分, 科目 *c* 90 分；
- *B* 科目 *a* 80 分, 科目 *b* 90 分, 科目 *c* 70 分；
- *C* 科目 *a* 80 分, 科目 *b* 70 分, 科目 *c* 90 分；
- *D* 科目 *a* 70 分, 科目 *b* 70 分, 科目 *c* 70 分。

由于 *D* 总分为 210，*A*,*B*,*C* 均为 240，所以 *D* 排最后。由于科目 *a* 的排名 *A* 比 *B*,*C* 低，所以 *A* 排第三。由于 *B* 和 *C* 科目 *a* 排名相同，所以继续使用科目 *b* 成绩判定，因为 *B* 的科目 *b* 成绩高于 *C*，所以 *C* 排第二，*B* 排第一。最终排名（从第一名到最后一名）为 *B*,*C*,*A*,*D*。

##### 输入

第一行输入两个整数，用空格隔开。第一个整数代表学生数n (1≤*n*≤1000)，第二个整数代表科目数 m (1≤*m*≤100)。

接下来输入 *n* 行，每行首先输入第 *i*（*i* 从 1 递增，1≤*i*≤*n*）个学生的名称 *s*（字符长度 1≤*s*≤10，仅包含英文小写字母和数字)，接着输入 *m* 个数据，依次代表各个科目的成绩 t (0≤*t*≤100)。名称与首个数据以及各个数据间均用一个空格隔开。

数据保证没有任何两个或多个学生的各科目分数完全一致。

##### 输出

从第一名到最后一名依次输出各个学生的名称，每个名称之间用空格隔开。

##### 样例

###### 输入

```
4 3
A 70 80 90
B 80 90 70
C 80 70 90
D 70 70 70
```

###### 输出

```
B C A D
```

##### 解法一

非结构体解法，也是我最初的解法

```c
犇#include <stdio.h>
//MAXN为最大学生数，MAXM为最大科目数,MAXL为最长名字字符数,FULL代表满分分数
#define MAXN 1000
#define MAXM 100
#define MAXL 10
#define FULL 100

//下列数组（一维）下标均代表读入的顺序
char name[MAXN][MAXL];//存储学生名
short mark[MAXN][1+MAXM];//存储各科分数，其中下标0存储总分
//总分可能的范围是[0,MAXN*FULL],注意不能使用非difine方式定义该常量，否则会报错
#define MAXSUM MAXM*FULL+1
short total[MAXSUM][MAXN+1];//存储总分为下标的所有学生下标，下标0存储学生数
void sort(int lv, int mar, int oks[], int ok);
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s", name[i]);
        int sum = 0;
        for(int j=1;j<=m;j++)//从下标1开始存储各科分数
        {
            scanf("%d", &mark[i][j]);
            sum += mark[i][j];
        }
        mark[i][0] = sum;//求得总分
    }

    //首先根据总分进行第一次排序，因为总分相同的数据多，这里采用计数排序
    int k=0;//当前操作的排名,0为第一名，以此类推
    for(int i=0;i<MAXSUM;i++) //初始化
    {
        for(int j=0;j<n;j++)
        {
            if(!j) total[i][j] = 0;
            else total[i][j] = -1;//初始化
        }
    }

    for(int i=0;i<n;i++)  //录入某分数段的所有学生下标，存在total[该分数] 这个数组里
    {
        total[mark[i][0]][0]++;
        total[mark[i][0]][total[mark[i][0]][0]] = i;
    }

    int first=1;//是否为首次输出，是0否1
    for(int i=MAXSUM-1;i>=0;i--)
    {
        if(total[i][0])//存在学生总分数为i
        {
            if(total[i][0] >= 2)//总分为i的学生数大于等于2
            {
                int ok[total[i][0]];
                for(int j=1;j<=total[i][0];j++) ok[j-1] = j;//初始化
                sort(0, i, ok, total[i][0]);//按照科目降序排序这些学生
            }
            for(int j=1;j<=total[i][0];j++)//输出这些学生名
            {
                first ? first=0 : printf(" ");
                printf("%s", name[total[i][j]]);
            }
        }
    }
    return 0;
}
//总分为mar的学生，当前判定第lv+1个科目
//oks是进行操作的下标，其中total[mar][oks[index]]的值为mark和name的实际存储下标值
//也就是那个值代表输入顺序，从0开始
//ok为数组oks长度
void sort(int lv, int mar, int oks[], int ok)
{

    //冒泡降序排序
    for(int i=0, flag=1;flag;i++)
    {
        flag=0;
        for(int j=ok-1;j>=i+1;j--)
        {
            if(mark[total[mar][oks[j]]][lv+1] > mark[total[mar][oks[j-1]]][lv+1])
            {
                int temp = total[mar][oks[j]];
                total[mar][oks[j]] = total[mar][oks[j-1]];
                total[mar][oks[j-1]] = temp;
                flag=1;
            }
        }
    }

    //分治法
    //首先找到分割的子排序，最终now值表示子排序次数
    int same[ok], sames[ok][ok];//重复的区间数，重复的元素下标
    int now=0, cnt=0;//现有重复区间，cnt是否重复中
    int nowi=0;//现有重复区间的下标
    for(int i=0;i<ok;i++) same[i] = 0;//初始化
    for(int i=0;i<ok-1;i++)
    {
        if(mark[total[mar][oks[i]]][lv+1] == mark[total[mar][oks[i+1]]][lv+1])
        {
            if(!cnt)//首次特殊处理
            {
                sames[now][nowi++] = oks[i];
                same[now]++;
            }
            cnt=1;
            sames[now][nowi++] = oks[i+1];
            same[now]++;
        }
        else
        {
            if(cnt) now++;
            nowi=cnt=0;
        }
    }
    if(cnt) now++;//尾处理

    for(int i=0;i<now;i++)
    {
        sort(lv+1, mar, sames[i], same[i]);
    }
}
```

##### 解法二

使用结构体，大大优化代码，是神犇部长写的

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
#define NLEN 12
#define MMAX 105
using namespace std;
int n,m;
struct stu
{
    char n[NLEN];
    int s[MMAX], t;
};
bool greater(stu a, stu b)
{
    if(a.t!=b.t) return a.t>b.t;
    else for(int i=0;i<m;i++)
    {
        if(a.s[i]!=b.s[i]) return a.s[i]>b.s[i];
    }
}
int main()
{
    char nam[NLEN];
    scanf("%d%d",&n,&m);
    stu stus[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s", stus[i].n);
        stus[i].t=0;
        for(int j=0;j<m;j++)
        {
            scanf("%d", &stus[i].s[j]);
            stus[i].t+=stus[i].s[j];
        }
    }
    sort(stus, stus+n, greater);
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%s", stus[i].n);
    }
    return 0;
}
```



#### 其他例题

##### 排兵布阵

> (oj)二维地图整点随机分布若干士兵，将它们排到$y$相等，$x$相邻，每次只能移动一名士兵，求最少移动次数。$1\le n,|x|,|y|\le 10^4$

可以分开考虑，对于$y$，移动到所有$y$坐标的中位数处的步数是最少的(而不是考虑二分或预处理+遍历，虽然题目标签是二分？)。而对于$x$相邻，排序后在每个坐标依次进行移动$i$格后可以与上述问题等价。从而代码如下：

> (da:是否一个格子上可以同时存在多个士兵？但是即便不可以，目前没有找到一种反例可以证明一定存在需要绕远路的情况，自己造的样例都可以不绕远路)

```c++
ll n, x[10010], y[10010], r;
void gather(ll *a)
{
    sort(a + 1, a + n + 1);
    re ll cf = (a[(n + 1) / 2] + a[n / 2 + 1]) / 2;
    repe(i, 1, n) r += abs(a[i] - cf);
}
signed main()
{
    sc(n);
    repe(i, 1, n) sc(x[i]), sc(y[i]);
    gather(y);
    sort(x + 1, x + n + 1);
    repe(i, 1, n) x[i] -= i;
    gather(x);
    printf("%lld", r);
    return 0;
}
```



## 搜索

### 线性搜索

带标记比不带标记快数倍。但都是O(n)

不带标记

```c
for(int i=0;i<n;i++)
    if(a[i]==key) return i;
return NOT_FOUND;
```

带标记

```c
int i=0;
A[n]=key;//避免死循环
while(A[i]!=key) k++;
return i;//若i为n，在后续应该给个报错NOTFOUND、
//当然如果只需要判断是否搜索得到则只需要return i!=n;
```

##### 例题

###### 货物摆放

> (蓝桥)有*n* = 2021041820210418 （注意有 16 位数字），将其分解为$L\times W\times H$，例如，当 *n* = 4 时，有以下 6 种方案：1×1×4、1×2×2、1×4×1、2×1×2、 2 × 2 × 1、4 × 1 × 1。求n的方案数。

```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n;
void solve(){

}
int main(){

    while(1){
        n=2021041820210418;
        int cnt0=0,cnt1=0,cnt2=0;//cnt0统计所有情况，cnt1统计两个数相等的情况，cnt2统计三个数相等的情况
        for(ll i=1;i*i*i<=n;i++){

            if(n%i)continue;
            for(ll j=i;i*j*j<=n;j++){

                if(n%j)continue;
                ll k=n/(i*j);
                if(i*j*k==n){

                    //cnt0++;
                    if(i==j&&j==k){

                        cnt2++;
                    }
                    else if(i==j||j==k||i==k){

                        cnt1++;
                    }
                    else cnt0++;
                }
            }
        }
        cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;//406 2 0
        cout<<cnt0*6+cnt1*3+cnt2;
        //不相等6种排列，只有两个相等三种排列，三个相等一种排列。
        //cout<<cnt0*6-cnt1*3-cnt2*5<<endl;//2430
        break;
    }
    solve();
    return 0;
}
```



###### 帅到没朋友

> (天梯)有n个朋友圈，每个朋友圈有k个人($k>2$时，允许重复),每个人有一个五位数ID。有m个询问的id，对于首个出现的询问id，如果他的朋友圈没有朋友，输出这个id。如果都有朋友，最后输出No one is handsome
>
> $1\le n\le 10^2,1\le k\le 10^3,1\le m\le10^4$，时间限制200ms。

如果每个朋友圈都设一个集合去存，那么查询总复杂度是$\Omicron(mn)$，事实上超时。注意到，将k=1的朋友圈不读入之后，所有朋友圈可以合一个布尔值数组/set，复杂度为$\Omicron(m)$。

(个人解法)方法一：set 时间接近于78ms

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,w;
string v;
set<string> g[102],gt,tot;
signed main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&k);
        if(k==1) cin>>v;
        else for(int j=0;j<k;++j) cin>>v,tot.insert(v);
    }
    for(scanf("%d",&m);m;--m)
    {
        cin>>v;
        if(gt.find(v)!=gt.end()) continue;
        bool suc=false;
        if(tot.find(v)!=tot.end()) suc=true;
        if(!suc)
        {
            if(w) putchar(' ');
            else w=1;
            cout<<v;
            gt.insert(v);
        }
    }
    if(!w) printf("No one is handsome");
    return 0;
}
```

方法二：vis数组 (快一倍)

```c++
#include<iostream>
using namespace std;
int vis[100009],isoutput[100009];
int main(void){ 
	int n;
	cin>>n;
	int k;
	for( int i=1;i<=n;i++){
		 cin>>k;
		 int t;
		 for( int j=1;j<=k;j++){
		 	  cin>>t;
		 	  if( k > 1 )
		 	      vis[t] =1;
		 }
	}
	int m,ishave=0,flag=0;
	cin>>m;
	for( int i=1;i<=m;i++){
		 int t;
		 cin>>t;
		 if( !vis[t] && !isoutput[t] ){
		 	 if(  flag  )
			      cout<<" ";
			 else flag =1;
		     printf("%05d",t);
		     isoutput[t] =1;
		 } 
	}
	if( !flag )
	    cout<<"No one is handsome"<<endl;
	return 0;
} 
```

### 二分搜索

#### 基本实现

```c
int left=0;
int right=n;
int mid;
while(left<right)
{
    mid=(left+right)/2;
    if(key==A[mid]) return mid;
    if(key>A[mid]) left=mid+1;//其实有无else差不多
    else 
}

/*while(left < right) {
    // ...
}
return nums[left] == target ? left : -1;*/
```

```c++
while(l<=r)//我的解法,不下降序列二分查找
{
    if(seq[c]==t)
    {
        f=1;
        break;
    }
    else if(seq[c]<t) l=c+1;
    else r=c-1;
    c=(l+r)/2;
}
```

#### 从左逼近

给定一个长度为 *n* 的**不下降序列** *a*，你需要处理 *m* 个询问。

对于每一个询问，给定一个整数 *k*，你需要给出**最大的**下标 *i*，使得 $a_i \leq k$。

序列下标从 1 开始计数。

```c++
int leftof(vector<int> &v, int obj)
{
    int l=0, r=v.size(),c;
    while(l<r)
    {
        c=(l+r)/2;
        if(v[c]<=obj) l=c+1;
        else r=c;
    }
    return l;
}
```

#### 从右逼近

给定一个长度为 n 的**不下降序列** *a*，你需要处理 *m* 个询问。

对于每一个询问，给定一个整数 *k*，你需要给出**最小的**下标 *i*，使得 $a_i \geq k$。

序列下标从 1 开始计数。

```c++
int rightof(vector<int> &v, int obj)
{
    int l=0, r=v.size(),c;
    while(l<r)
    {
        c=(l+r)/2;
        if(v[c]>=obj) r=c;
        else l=c+1;
    }
    return l;
}//输出rightof+1才是从1计数！要不return l+1也行
```

#### 区间计数

给定两个整数 *l* 和 *r*，你需要回答序列中有多少项满足 $l \leq a_i \leq r$

```c++
sort(s.begin(),s.end());
printf("%d\n", leftof(s,r)-rightof(s, l));
```

拓展应用：求值（如果本来是按线性遍历那个值）也可以改为二分遍历。

#### lower_bound

```c++
#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int n,m,a[MAXN],f;
int binf(int v)
{
    long long l=0, r=n-1, c;
    while(l<r)
    {
        c=(l+r)/2;
        if(a[c]>=v) r=c;
        else l=c+1;
        //printf("%d %d %d\n",l,r,c);
    }
    if(a[l]==v) return l;//注意是l
    else return -2;//或-1
}
```

#### 二分答案

二分答案可以解决答案满足单调性的问题。

> 二分答案容易出现各种离奇的问题，大体可以通过以下方法有一定的概率可以解决。
>
> - 尾特判，在二分时保留一定精度，在二分后再用一个while循环做一下
> - 非整型二分，要求保留精度为多少位，可以保留多一位，然后用字符串截断的方式非四舍五入减少一位
> - 换一个二分模板，常见的有：lf<=rf和各自lf+1和rf-1，可以只取一边在lf=cf+1和rf=cf-1前ans=cf，输出ans
>   或l<r，r=cf,l=cf+1或反过来(r=cf-1,lf=cf)然后输出lf(或rf)

##### 例题

###### 数列分段

> (oj)将长为n的数列分为m段，让每一段的和的最大值最小，求最小值。
>
> $1\le m\le n\le10^5,1\le a_i\le10^9$

注意左边的范围是max单值，右边的值是sum，不然会死。本题因题目数据水，int也能过；其实long long更好。

```c++
#include <bits/stdc++.h>
typedef int ll; //测试int/LL 和 快读与否的 速度差 
ll a[100002],n,m,lf,rf,cf,mi,ans;
bool judge()//注意处理方法
{
	ll p=0,cnt=1;
	for(ll i=1;i<=n;++i)
	{
		if(p+a[i]>cf) ++cnt,p=0;
		p+=a[i];
	}
	return cnt<=m;
}
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
signed main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;++i) a[i]=read(),rf+=a[i],lf=std::max(lf,a[i]);
	while(lf<rf)//若改为<=，则rf=cf-1
	{
		cf=lf+rf>>1;
		if(judge()) ans=cf,rf=cf;
		else lf=cf+1;
	}
	printf("%d",ans);
	return 0;
}
```



###### 借教室

> 有n天，m人想借教室，第i天有ai间闲置教室。接下来(d,s,t)表示第j个人想要在[s,t]天内借走d间教室。如果所有人都能借到教室，输出0，否则输出-1并换行输出第一个无法借到教室的人的序号。

```c++
#include <bits/stdc++.h>
#define MAXN 1000002
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int diff[MAXN], sup[MAXN], ne[MAXN], lf, rf, cf, n, m;
int d[MAXN], s[MAXN], t[MAXN];
inline bool judge(int v)
{
	rep(i, 1, n) diff[i] = 0;
	rep(i, 1, v) diff[s[i]] += d[i], diff[t[i] + 1] -= d[i];
	rep(i, 1, n)
	{
		ne[i] = ne[i - 1] + diff[i];
		if (ne[i] > sup[i]) return false;
	}
	return true;
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &sup[i]);
	rep(i, 1, m) scanf("%d%d%d", &d[i], &s[i], &t[i]);
	if (judge(m))
	{
		printf("0");
		return 0;
	}
	lf = 1, rf = m;
	while (lf < rf)
	{
		cf = lf + rf >> 1;
		if (judge(cf))lf = cf + 1;
		else rf = cf;
	}
	printf("-1\n%d", lf);
	return 0;
}
```



###### Graph Theory

> (oj)有$n$个点，编号$[1,n]$，第$i$个点和下一个编号的点连第$i$条无向边，成环。有$m$个点对$(a,b)$，现在删掉一条边，求删掉边后这$m$个点对的两两最短路的最大值最少是多少。$2\le n\le2\times10^5,1\le m\le2\times10^5$,$1\le a_i,b_i\le n,1\le i\le m$，有多组测试，保证$\sum n,\sum m\le2\times10^5$

显然对一个点对$(a,b),a\le b$，最短路要么是$b-a,$要么是$n-(b-a)$。如果用线段树维护可能会超时，不考虑用线段树维护区间最值然后查$n$次删掉后的区间最值。考虑二分答案法，具体思路见代码。

> 注：本题有很多解法，但是个人能力有限，只看懂了二分答案法。其他方法如并查集DSU、优先级队列等。

```c++
#define sc(x) x = read()
#define mn 200010
ll n, m, e[mn][2], u, v, lf, rf, cf, res, s[mn];
bool check(ll k)
{
    memset(s, 0, sizeof s);
    for (ll i = 0; i < m; ++i)
    {
        //只能在[a,b)这一段删，不然会走[a,b)使得答案>k
        //所以不能走这一段的补集
        if (e[i][1] - e[i][0] > k)
        {
            ++s[1];
            --s[e[i][0]];
            ++s[e[i][1]];
        }
        if (n - (e[i][1] - e[i][0]) > k)
        {
            ++s[e[i][0]];
            --s[e[i][1]];
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        s[i] += s[i - 1];
        if (!s[i])
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    while (EOF != scanf("%d%d", &n, &m))
    {
        for (ll i = 0; i < m; ++i)
        {
            sc(u), sc(v); //输入不保证a<=b所以要这样
            e[i][0] = min(u, v), e[i][1] = max(u, v);
        }
        lf = 0, rf = n - 1;
        while (lf <= rf) 
        {
            cf = (lf + rf) >> 1;
            if (check(cf)) //如果有答案，那么找一下更小的
            {
                rf = cf - 1;
            }
            else
            {
                lf = cf + 1;
            }
        }
        printf("%d\n", rf + 1);
    }
    return 0;
}
```



###### 最小中位数子矩阵

> (oj)有$n\times n$矩阵$a$，找一个$k\times k$子阵，使得在所有$k$阶子阵里，这个子阵的中位数(第$\lfloor\frac{k^2}2+1\rfloor$大数)最小，输出中位数。$1\le k,\le n\le800,0\le a_{i,j}\le10^9$

这题不能暴力枚举(或者用二维双指针法)，无法解决$O(1)$找中位数所以都会TLE。复杂度是$n^3\log n$。

考虑二分，设答案为二分对象，显然这个值越大它的排位越大，所以可以检验排位，从一个方向逐渐逼近中位排位，即$\lfloor\frac{k^2}2+1\rfloor$，每次检验二分值，使得答案逼近于唯一的真实答案。可以证明二分到的一定是存在的最小的中位数。

```c++
#define mn 804
ll n, k, a[mn][mn], s[mn][mn], lf, rf = 1e9, cf, res, t;
bool check()
{ //利用前缀和快速检验中位数
    repe(i, 1, n) repe(j, 1, n) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] >= cf);
    repe(i, k, n) repe(j, k, n)
    {
        t = s[i][j] + s[i - k][j - k] - s[i][j - k] - s[i - k][j];
        if (t < k * k / 2 + 1)
            return false;
    }
    return true;
}
signed main()
{
    sc(n), sc(k);
    repe(i, 1, n) repe(j, 1, n) sc(a[i][j]);
    while (lf <= rf)
    {
        cf = (lf + rf) >> 1;  //假设存在一个子矩阵的中位数是cf
        if (check())          //如果以cf为中位数不少于k*k/2+1个元素大于它
            lf = cf + 1, res = cf; //那么中位数大于等于cf
        else
            rf = cf - 1; //否则中位数小于cf
    }
    printf("%d", res);
    return 0;
}
```





###### 寻找段落

> 长为n的序列，定义平均值为区间和除以区间长度，求长度在[s,t]之间的子序列的最大平均值

答案满足单调性,设区间[l,r]，则其平均值x的算式为：
$$
\frac{\sum_{i=l}^ra_i}{r-l+1}=x，即\sum_{i=l}^ra_i=x\times(r-l+1)
$$
当某个区间平均值优于已算出的平均值x时，有：
$$
\frac{\sum_{i=l}^ra_i}{r-l+1}\ge x，即\sum_{i=l}^ra_i\ge x\times(r-l+1)\\即\sum_{i=l}^ra_i\ge\sum_{i=l}^rx，即\sum_{i=l}^r(a_i-x)\ge0
$$
所以问题转化为二分寻找一个区间，使得该区间满足上面的式子。因为要反复进行求区间和，所以可以用前缀和优化。

使用二分答案法，即判断是否存在可优化区间，如果存在则更新答案，如果不存在继续查找直到寻找的x范围小于误差范围。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll n, s, t, q[MAXN];
double c[MAXN], lf = -1e4, rf = 1e4, cf, a[MAXN];
inline bool ck(double& v)
{
	int l = 1, r = 0;
	repe(i, 1, n) c[i] = c[i - 1] + a[i] - v;
	repe(i, 1, n)
	{
		if (i >= s)//单调队列法
		{
			while (r >= l && c[i - s] < c[q[r]]) --r;
			q[++r] = i - s;
		}
		if (l <= r && q[l] < i - t) ++l;
		if (l <= r && c[i] >= c[q[l]]) return true;
	}
	return false;
}
signed main()
{
	scanf("%d%d%d", &n, &s, &t);
	repe(i, 1, n) scanf("%lf", &a[i]);
	while (rf - lf > 1e-5)
	{
		cf = (lf + rf) / 2;
		if (ck(cf)) lf = cf;
		else rf = cf;
	}
	printf("%.3lf", lf);
	return 0;
}
```

###### kotori的设备

> 有n个设备，有每秒充能p的充电宝，第i个设备每秒耗能ai，原储能bi，求最久能一起使用这些设备多长时间(若无限输出-1)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll n;
double a[MAXN], b[MAXN], p, lf, rf = (double)MAXN * MAXN, cf, sum;
bool ck()
{
	double csm = 0.0;
	rep(i, 0, n) csm += max(0.0, cf * a[i] - b[i]);
	return csm <= cf * p;
}
signed main()
{
	scanf("%d%lf", &n, &p);
	rep(i, 0, n) scanf("%lf%lf", a + i, b + i), sum += a[i];
	if (sum <= p) return printf("-1"), 0;
	while (rf >= 1e-6 + lf)
	{
		cf = (lf + rf) / 2;
		if (ck()) lf = cf;
		else rf = cf;
	}
	printf("%.6lf", lf);
	return 0;
}
```

###### 通往奥格瑞玛的道路

> 无向加权图(可能有自环/重边)，而且点加权，从1走到n，在路径长不超过b的前提下，使得经过点集点权的最大值最小，求这个最小值。
>
> $点数n\le10^4,边数m\le5\times10^4,边权、点权、b\le10^9$

考点为图论与二分搜索的综合题。

对边权跑单源最短路径算法，用Dijkstra(链式前向星+堆优化)或SPFA算法

对点权，使用二分答案法，每次用二分假设一个最小值，然后用这个最小值跑边权计算，是否符合最短路径不大于b，如果是，这个假设值就是最优解。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10008
#define MAXE 100008
#define BIG 1000000008
struct edge { ll to, w, nx; } e[MAXE];
ll n, m, cnt, hd[MAXN], hp, b[MAXN], c[MAXN], d[MAXN], rf, lf, cf;
bool vis[MAXN];
struct node
{
	ll d, p;
	bool operator<(const node& x) const { return x.d < d; }
};
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,w,hd[u] };
	hd[u] = cnt;
}
inline bool ck(ll x)
{
	priority_queue<node> q;
	if (x < b[1] || x < b[n]) return false;
	repe(i, 1, n) d[i] = BIG;
	repe(i, 1, n)
	{
		if (x < b[i]) vis[i] = true;
		else vis[i] = false;
	}
	d[1] = 0;
	q.push({ 0,1 });
	while (!q.empty())
	{
		node no = q.top(); q.pop();
		if (vis[no.p]) continue;
		vis[no.p] = true;
		for (ll i = hd[no.p]; i; i = e[i].nx)
		{
			if (d[e[i].to] > e[i].w + d[no.p])
			{
				d[e[i].to] = e[i].w + d[no.p];
				if (!vis[e[i].to])
					//vis[e[i].to]=true,
					q.push({ d[e[i].to],e[i].to });
			}
			//if (e[i].to == n) return d[n] < hp;
		}
	}
	return d[n] < hp;
}
ll ui, vi, wi, ans;
signed main()
{
	scanf("%d%d%d", &n, &m, &hp);
	repe(i, 1, n) scanf("%d", b + i), c[i] = b[i];
	repe(i, 1, m)
	{
		scanf("%d%d%d", &ui, &vi, &wi);
		if (ui == vi) continue;
		adde(ui, vi, wi), adde(vi, ui, wi);
	}
	sort(c + 1, c + 1 + n);
	if (!ck(c[n])) return printf("AFK"), 0;
	lf = 1, rf = n, ans = c[n];
	while (lf <= rf)
	{
		cf = lf + rf >> 1;
		if (ck(c[cf])) ans = c[cf], rf = cf - 1;
		else lf = cf + 1;
	}
	printf("%d", ans);
	return 0;
}
```

###### 区间移位

> (蓝桥)在0~10000内有若干整区间(总长$\ge10000$)，将它们进行位移，使得$[0,10000]$被这些区间的并区间完全覆盖，求最小的最大单次位移距离

由于区间首末是整数，所以进行位移的时候两区间各走1的一半时必然比1的大小半更优，因此位移的长度必然是0.5的倍数，移动大于1时同理。所以对长度乘二可以解决小数问题，直接进行二分答案。注意先排序，双依据；注意的是当$[0,pos]$已经被覆盖时，重合的一个区间可以贪心地往前前进(即else分支)。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 10002
struct sec
{
	int lf,rf;
} s[mn];
int n,lf,rf=20000,cf;
inline bool cmp(const sec& a, const sec& b)
{
	if(a.rf!=b.rf) return a.rf<b.rf;
	return a.lf<b.lf;
}
inline bool ck(int k)
{
	int pos=0;
	bool vis[mn];
	memset(vis,0,sizeof vis);
	while(1)
	{
		bool find=false;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]) continue;
			if(s[i].lf>pos)
			{
				if(s[i].lf-pos>k) find=false;
				else
				{
					find=true,vis[i]=true;
					pos=s[i].rf-s[i].lf+pos;
				}
			}
			else if(s[i].lf==pos) pos=s[i].rf,vis[i]=true,find=true;
			else
			{
				if(pos-s[i].lf<=k)
				{
					vis[i]=true,find=true;
					pos=s[i].rf-s[i].lf+pos;
				}
				else
				{
					find=true;
					if(s[i].rf+k>pos) vis[i]=true,pos=s[i].rf+k;
				}
			}
		}
		if(pos>=20000) return true;
		if(!find) return false;
	}
	return false;
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&s[i].lf,&s[i].rf);
		s[i].lf<<=1;
		s[i].rf<<=1;
	}
	sort(s+1,s+1+n,cmp);
	while(lf<rf)
	{
		cf=(lf+rf)>>1;
		if(ck(cf)) rf=cf;
		else lf=cf+1;
	}
	if(lf%2) printf("%.1lf",lf/2.);
	else printf("%d",lf>>1);
	return 0;
}
```

###### walker

> (icpc45上海)有一条0到n的数轴，数轴上有两个点位置分别是p1, p2,可以左右移动，速度分别是v1, v2，求两个点行动轨迹覆盖整个数轴的最短时间。

特别注意不要审题成：两点不能穿过对方，也就是说两点轨迹是可以交叉的。

第一是两人交叉行走，左边的往右跑跑到底，右边的往左跑跑到底，取较大的时间作为覆盖总时间。

第二是一个人走完全程，取较小的时间作为覆盖总时间。

第三就是将数轴一分为二，左边的覆盖完左区间，右边的覆盖完右区间，取较大值作为覆盖总时间。那么这里就是求最大值最小问题，可以二分这个分割点。当然，两个点要在区间内，所以二分的左右端点要取p1, p2。double会失精度，所以二分判断是abs(r-l)>=eps，这个eps取1e-7就够了。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
ll _; db n,p1,p2,v1,v2,lf,rf,cf,a,t1,t2;
signed main()
{
    for(scanf("%lld",&_);_;--_)
    {
        scanf("%lf%lf%lf%lf%lf",&n,&p1,&v1,&p2,&v2);
        if(p1>p2) swap(p1,p2),swap(v1,v2);
        a=max((n-p1)/v1,p2/v2);
        a=min(a,(n+min(p1,n-p1))/v1);
        a=min(a,(n+min(p2,n-p2))/v2);
        lf=p1,rf=p2;
        while(abs(rf-lf)>1e-8)
        {
            cf=lf+(rf-lf)/2.0;
            t1=(cf+min(p1,cf-p1))/v1;
            t2=(n-cf+min(n-p2,p2-cf))/v2;
            a=min(a,max(t1,t2));
            if(t1<t2) lf=cf;
            else rf=cf;
        }
        printf("%.10lf\n",a);
    }
    return 0;
}
```



#### 序列问题

子序列和子串是不同的概念,子串的元素在原序列中是连续的,子序列不用连续

##### 最长单调序列

复杂度O(nlogn)，若dp来做，复杂度n^2^。

```c++
#include <bits/stdc++.h>
#define MAXN 100002
#define y1 dy
using namespace std;
int n,a[MAXN],uf[MAXN],df[MAXN],ufl,dfl,x[MAXN],y[MAXN],x1,y1;
int main()
{
    while(EOF!=scanf("%d",&a[++n]));
    uf[++ufl]=df[++dfl]=a[1];
    x[++x1]=y[++y1]=a[1];
    for(int i=2;i<n;i++)
    {
        if(uf[ufl]>=a[i])uf[++ufl]=a[i];//最长不上升
        else *upper_bound(uf+1,uf+1+ufl,a[i],greater<int>())=a[i];
        
        if(df[dfl]<a[i])df[++dfl]=a[i];//最长上升,与上面互为定律
        else *lower_bound(df+1,df+1+dfl,a[i])=a[i];
        
        if(x[x1]>a[i])x[++x1]=a[i];//最长下降
        else *upper_bound(x+1,x+1+x1,a[i],greater<int>())=a[i];
        
        if(y[y1]<=a[i])y[++y1]=a[i];//最长不下降,与上面互为定律
        else *lower_bound(y+1,y+1+y1,a[i])=a[i];
    }
    printf("\n%d\n%d\n%d\n%d",ufl,dfl,x1,y1);
    return 0;
}
```

> 有定理如下：求一个序列最少能分成多少个最长不上升序列，可以求最长上升序列的长度即为答案。其他情况类推。
>
> *即Dilworth定理：偏序集的最少反链划分数等于最长链的长度*

##### 二维最长单调序列

> 例题题意：对数对(x,y)组成的序列，重排之，当前者x,y均不小于后者时，不造成损耗，否则损耗+1，求最小损耗。输入数对数n，接下来依次输入n个(x,y)。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5002
#define rep(i,a,b) for(int i=a;i<=b;++i)
struct stick
{
    int l,w;
} s[MAXN];
bool cmp(stick& a, stick& b)
{
    if(a.l!=b.l) return a.l>b.l;
    return a.w>b.w;
}
int n,x[MAXN],xn,j;
signed main()
{
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%d%d",&s[i].l,&s[i].w);
    }
    sort(s+1,s+1+n,cmp);
    x[++xn]=s[1].w;
    rep(i,2,n)
    {
        j = lower_bound(x+1,x+1+xn,s[i].w) - x;
        if(j<=xn) x[j]=s[i].w;
        else x[++xn] = s[i].w;
    }
    printf("%d",xn);
    return 0;
}
```

注：也可以用上面模板的最长上升长度来求，都是使用dilworth定律。把rep内换成如下：

```c++
if(x[xn]<s[i].w) x[++xn]=s[i].w;
else *lower_bound(x+1,x+1+xn,s[i].w)=s[i].w;
```

##### 最长公共子排列

给定两个1~n的排列，求它们的最长公共子序列长。要求$O(nlogn)$

> 假设：
>
> A:3 2 1 4 5
>
> B:1 2 3 4 5
>
> 我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：
>
> A: a b c d e
> B: c b a d e
>
> 这样标号之后，LCS长度显然不会改变。但是出现了一个性质：
>
> 两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
> 因此这个子序列是单调递增的。
>
> 换句话说，只要这个子序列在B中单调递增，它就是A的子序列。
>
> 所以变成了求B的最长单调上升序列(LCS->LIS)

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
#define MAXN 100002
int a[MAXN], b[MAXN], uf[MAXN], ufs, n, v;
signed main()
{//变换如果用scanf a[i], b[i]=a[v]会PA
	scanf("%d", &n);
	rep(i, 1, n)//注意变换过程
	{
		scanf("%d", &v);
		a[v] = i;
	}
	rep(i, 1, n)//注意变换过程
	{
		scanf("%d", &v);
		b[i] = a[v];
	}
	uf[++ufs] = b[1];
	rep(i, 2, n)
	{
		if (uf[ufs] < b[i]) uf[++ufs] = b[i];
		else *lower_bound(uf + 1, uf + 1 + ufs, b[i]) = b[i];
	}
	printf("%d", ufs);
	return 0;
}
```

##### 子序列自动机

> 给定长为n的序列和q组询问，给定若干序列(至长m)，询问这些序列是否是原序列的子序列

方法一：时间复杂度$\Omicron((n+\sum len)\log m)$，空间复杂度$\Omicron(m+n\log m)$，使用vector+二分模拟平衡树

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 100002
ll n, q, m, type, ii;
vector<ll> v[mn];
signed main()
{
	scanf("%d%d%d%d", &type, &n, &q, &m);
	repe(i, 1, n) scanf("%d", &ii), v[ii].push_back(i);
	while (q--)
	{
		ll len, at = 0, x;
		bool suc = true;
		scanf("%d", &len);
		while (len--)
		{
			scanf("%d", &x);
			if (!suc) continue;
			auto it = lower_bound(v[x].begin(), v[x].end(), at + 1);
			if (it == v[x].end()) suc = false;
			else at = *it;
		}
		printf(suc ? "Yes\n" : "No\n");
	}
	return 0;
}
```

方法二：可持久化线段树

#### 二分查找

##### 例题

###### 三足鼎立

> (天梯)要求结盟国家任何两国实力和大于第三国，则可以结盟。已知本国实力和其他$n(1\le n\le10^5)$国的实力$p(1\le p\le10^9)$，求可以选择的结盟方案数

设三个国家实力为$p,q,s$，满足：
$$
\begin{cases}
p+q>s\quad①\\
s+p>q\quad②\\
s+q>p\quad③
\end{cases}
$$
首先排序。然后遍历一次，假设选择第$i$个国家为第二个国家$p$，那么第三个国家实力小于它们的和，二分找到第一个大于等于和值的一个国家，往前一个必然是符合条件的最大实力国$p_1$，符合上式②。同时在第二个国家的往右的国家里，二分找到第一个实力值大于$|p-s|$的一个国家的前一个国家，设实力值为$q_2$。假设已知$s,p$，则由上式有：
$$
|p-s|<q<p+s
$$
显然这样找到的$p_1,p_2$刚好为上下界。

```c++
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
int ans[N];
int n, s;

int main()
{
    cin>>n>>s;
    for(int i = 1; i <= n; i ++ )
	cin>>ans[i];

    sort(ans + 1, ans + n + 1);    
    
    LL cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int p=lower_bound(ans+1+i,ans+1+n,ans[i]+s)-(ans+1+i); 
        int q=upper_bound(ans+1+i,ans+1+n,abs(ans[i]-s))-(ans+1+i);
        
        cnt+=p-q;
    }
    cout<<cnt<<endl;
    return 0;
}
```

###### 找假币

> (蓝桥)有$0\sim 7$编号币，有一枚假币，重量或偏重或偏轻，称三次称出来并输出哪个是假币，轻了还是重了；补足代码

```c++
import java.util.*;
public class Main
{
	static int balance(int a, int b){
		if(a<b) return -1;
		if(a>b) return 1;
		return 0;
	}
	
	static void judge(char[] data, int a, int b, int std){
		switch(balance(data[a],data[std])){
		case -1:
			System.out.println(a + " light");
			break;
		case 0:
			System.out.println(b + " heavy");
			break;
		case 1:
			System.out.println("err!");
		}
	}
	
	// data 中8个元素，有一个假币，或轻或重
	static void f(char[] data){
		switch( __________________________________________________ ){  //填空
		case -1:
			switch(balance(data[0]+data[4],data[3]+data[1])){
				case -1:
					judge(data,0,3,1);
					break;
				case 0:
					judge(data,2,5,0);
					break;
				case 1:
					judge(data,1,4,0);
			}
			break;
		case 0:
			judge(data,6,7,0);		
			break;
		case 1:
			switch(balance(data[0]+data[4],data[3]+data[1])){
				case -1:
					judge(data,4,1,0);
					break;
				case 0:
					judge(data,5,2,0);
					break;
				case 1:
					judge(data,3,0,1);
			}
			break;		
		}	
	}
	
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		scan.nextLine();
		
		for(int i=0; i<n; i++){
			f(scan.nextLine().trim().toCharArray());
		}
	}
}
```

答案是`balance(data[0]+data[1]+data[2],data[3]+data[4]+data[5])`

case0显而易见；所以只分析case-1和case1。按照答案的分法：若case-1，第一次之后有两种情况，要么假币在012内且偏重，要么假币在345内且偏轻；case1就重量相反，类推即可。之后如果再一次case-1，说明假币在04内偏重或在13内偏轻，联立两个判断，只有可能是0偏重或3偏轻，其他情况都会导致矛盾，最后跟真币比较即可。其他情况类推。

假设选择了第一次判024和135，那么联立两次判断不会带来任何帮助，即此时仍然有四个未知，不可能在三次之内判出来。



##### 模拟偏树(例题)

###### 特殊堆栈

> (天梯)输入$n(1\le n\le10^5)$，输入$n$行指令，`Pop`代表输出栈顶元素并弹栈，`PeekMedian`代表输出栈中第$\frac n2$小($n$为偶)或第$\frac{n+1}2$小($n$为奇)的元素，`Push x`代表入栈一个元素$x$。如果操作无效，输出`Invalid`。

首先不能审错题看成输出序号中值的元素。然后就直接二分查找送分题。

```c++
#define no printf("Invalid\n")
ll a[100002],bg,ed,n,v;
vector<ll> b;
char cmd[12];
signed main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",cmd);
        if(cmd[1]=='o')
        {
            if(bg==ed) no;
            else
            {
                b.erase(lower_bound(b.begin(),b.end(),a[ed]));
                printf("%d\n",a[ed--]);
            }
        }
        else if(cmd[1]=='e')
        {
            if(bg==ed) no;
            else
            {
                printf("%d\n",b[(1+b.size())/2-1]);
            }
        }
        else
        {
            scanf("%d",&v);
            a[++ed]=v;
            b.insert(lower_bound(b.begin(),b.end(),v),v);
        }
    }
    return 0;
}
```



### 散列法

散列法根据各元素值确定存储位置，并将位置key保存在散列表，从而实现高速搜索。散列表是一种能对包含关键字的数据集合高效动态插入、搜索、删除的数据结构。

设散列表有M个元素。h(k)是散列函数，其返回值是散列值，范围为0~M-1.如果只有一次运算，就会出现不同key对应同一散列值的冲突。采用开放地址法可以解决。

注意，下标每次移动h(k)个位置，所以必须保证M和h2(k)互质，否则无法生成下标。所以M可以设置为是质数，取小于m的值作为h2(k)。

忽略冲突，则插入和搜索复杂度是O(1)。散列函数可以用于加密技术，启发式计算式等。

如果搜索非数值，首先将非数值转化为不重复的整型数值key

```c
int h1(int key){return key%M;}
int h2(int key){return 1+(key%(M-1) ); }
int find(char str[])
{
    long long key, i, h;
    key = getKey(str);
    for(i=0;;i++)
    {
        h=(h1(key) + i * h2(key))%M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0) return 0;
    }
    return 0;
}
int insert(char str[])
{
    long long key, i, h;
    key = getKey(str);
    for(i=0;;i++)
    {
        h=(h1(key) + i * h2(key))%M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h])==0)
        {
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}
```

### DFS/BFS

一般的，求解的个数用深搜，求最优解用广搜。广搜由于寻找顺序，导致找到一个解就一定是最优解了。

注意要点：

1. dx,dy变量(当前的下一步)不要开全局，不然小心见祖宗。
2. 深搜一般同一点不需要走两次，所以只需开vis；而广搜可能需要重复走，所以开vis不一定能解出最优解。
3. dfs将情况数分裂较小的放在先前，可以减少搜索树。

#### 路径/迷宫

##### DFS

###### 迷宫

> (蓝桥)给定$10\times10$迷宫，每个迷宫格子内有一个人，每个迷宫格子只有一个单向出口(UDLR)，求最后能走出迷宫的人数

（方法一）个人朴素解法：因为不走循环路的情况下，最坏情况是都走一遍即100次就走得出去，所以如果100次还没走出去，一定进入了死循环。对每个点都走100次(走出就不走了)：

```c++
#include <bits/stdc++.h>
using namespace std;
char cmd[12][12],t[12];
int suc,n=10;
void mot(int& x, int& y)
{
    switch(cmd[x][y])
    {
    case 'U':--x; break;
    case 'D':++x; break;
    case 'L':--y; break;
    case 'R':++y; break;
    }
}
signed main()
{
    freopen("171.txt","r",stdin);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",t+1);
        for(int j=1;j<=n;++j)
        {
            cmd[i][j]=t[j];
        }
    }
    for(int a=1;a<=n;++a)
    {
        for(int b=1;b<=n;++b)
        {
            int t=0,i=a,j=b;
            while(t<100)
            {
                mot(i,j);
                if(i<1||j<1||i>10||j>10) break;
                ++t;
            }
            if(t<100) ++suc;
        }
    }
    printf("%d",suc);
    return 0;
}
```

(方法二：个人优化)每次走到一个新的房间，就和本来在那里的人汇合，但记号起点仍然是一开始遍历的点。如果这条路成功了，那么这条路上累积汇合的人都记到起始点坐标上；成功的定义是走出去或走到已经成功过的路径。

未优化的写法：

```c++
#include <bits/stdc++.h>
using namespace std;
char cmd[12][12],t[12];
int vis[12][12];
int acm[12][12];
int ac[102];
int suc,n=10,acms;
void mot(int& x, int& y)
{
    switch(cmd[x][y])
    {
    case 'U':--x; break;
    case 'D':++x; break;
    case 'L':--y; break;
    case 'R':++y; break;
    }
}
signed main()
{
    freopen("171.txt","r",stdin);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",t+1);
        for(int j=1;j<=n;++j)
        {
            cmd[i][j]=t[j];
            acm[i][j]=1;
        }
    }
    for(int a=1;a<=n;++a)
    {
        for(int b=1;b<=n;++b)
        {
            if(vis[a][b]) continue;
            int i=a,j=b,bfi=i,bfj=j;
            ++acms;

            while(1)
            {
                vis[i][j]=acms;
                mot(i,j);
                if(!(i>=1&&j>=1&&i<=n&&j<=n&&!vis[i][j])) break;
                acm[i][j]+=acm[bfi][bfj];
                bfi=i,bfj=j;
            }
            if(i<1||j<1||i>n||j>n||vis[i][j]&&ac[vis[i][j]] )
            {
                ac[acms]=acm[bfi][bfj];
            }
        }
    }
    for(int i=1;i<=acms;++i) suc+=ac[i];
    printf("%d",suc);
    return 0;
}
```

稍加优化：(答案解法)

```c++
#include <bits/stdc++.h>
using namespace std;
char cmd[12][12],t[12];
int vis[12][12];
int acm[102];
bool ac[102];
int suc,n=10,acms;
void mot(int& x, int& y)
{
    switch(cmd[x][y])
    {
    case 'U':--x; break;
    case 'D':++x; break;
    case 'L':--y; break;
    case 'R':++y; break;
    }
}
signed main()
{
    freopen("171.txt","r",stdin);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",t+1);
        for(int j=1;j<=n;++j)
        {
            cmd[i][j]=t[j];
        }
    }
    for(int a=1;a<=n;++a)
    {
        for(int b=1;b<=n;++b)
        {
            if(!vis[a][b])
            {
                ++acms;
                int i=a,j=b;
                while(i>=1&&j>=1&&i<=n&&j<=n&&!vis[i][j])
                {
                    vis[i][j]=acms;
                    ++acm[acms];
                    mot(i,j);
                }
                if(i<1||j<1||i>n||j>n||vis[i][j]&&ac[vis[i][j]])
                {
                    ac[acms]=true;
                }
            }
        }
    }
    for(int i=1;i<=acms;++i) if(ac[i]) suc+=acm[i];
    printf("%d",suc);
    return 0;
}
```

###### 玩具蛇

> (蓝桥)有$4\times 4$方格盒子，每个格子编号各异从$a$到$p$，可以放一条长$16$节的玩具蛇，有多少不同的方案，不同当且仅当存在一节放在了盒子不同格子里

搜索送分题。但是要注意，搜索前一定要把开始的那一格vis设置一下，否则搜索之后会走回第一格！或者可以改一下回溯方法，即只回溯设false，设true不搞在回溯里，修改建议见注释。

```c++
#include <bits/stdc++.h>
#define re register
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define rep(i,a,b) for(re ll i=a;i<b;++i)
using namespace std;
typedef int ll;
ll ans,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
bool vis[6][6];
#define n 4
void dfs(ll x, ll y, ll k)
{
    if(k==n*n) {++ans; return;}//rep之前加vis[x][y]=true
    rep(h,0,4)
    {
        re ll ax=x+dx[h],ay=y+dy[h];
        if(ax<1||ay<1||ax>n||ay>n||vis[ax][ay]) continue;
        vis[ax][ay]=true;//这行就可以不用了
        dfs(ax,ay,k+1);
        vis[ax][ay]=false;
    }
}
signed main()
{
    repe(i,1,n)
    {
        repe(j,1,n)
        {
            memset(vis,0,sizeof vis);
            vis[i][j]=true;//这行就可以不用了
            dfs(i,j,1);
        }
    }
    printf("%d",ans);
    return 0;
}
```



###### 方格分割

> (蓝桥)有$6\times 6$的方格，沿着格子的边线剪开成两部分。要求这两部分的形状完全相同。求一共有多少种不同的分割方法。注意：旋转对称的属于同一种分割法。

搜索点(边线的交点，左上为$(0,0)$)更加方便，切由于形状完全相同，要求必然经过中间点即$(3,3)$，每次搜索都同时置两部分的vis为true，检测到DFS到边界出即判定++ans。

```c++
#include <bits/stdc++.h>
using namespace std;
bool vis[8][8];
int ans,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
void dfs(int x, int y)
{
    if(x==0||y==0||x==6||y==6)
    {
        ++ans;
    }
    else
    {
        for(int i=0;i<4;++i)
        {
            int ax=x+dx[i];
            int ay=y+dy[i];
            if(vis[ax][ay])
            {
                continue;
            }
            vis[ax][ay]=true;
            vis[6-ax][6-ay]=true;
            dfs(ax,ay);
            vis[ax][ay]=false;
            vis[6-ax][6-ay]=false;
        }
    }
}
signed main()
{
    vis[3][3]=true;
    dfs(3,3);
    printf("%d",ans>>2);
    return 0;
}
```

如果按格子来搜，必须使用BFS，使用DFS不能处理一分多的下一步。按格子来搜可能会出现包围型边界(即剪开后并不是两部分)，难以处理。

###### 阿贝多的拼图

> (oj)有$n\times n$碎片的正方形，编号为$1,2,\cdots,n^2$，给出$n$和每个碎片的上下左右四个碎片的编号，求这个正方形 $1\le n\le10^3$

对于给出个碎片$x$四方位$u,d,l,r$，可以确定$x$上方的编号为$u$的碎片的左下角和右下角分别是$l,r$，其他三个方位类似，由此遍历一次之后就知道了每个碎片四个角方向的碎片，并且得到了两个连通块。由于奇偶问题，所以右上角有时候代表第一个连通块、有时候代表第二个连通块，所以不能选右上角判定。可以选左上角(特点是三个特定方位是空)和左上角的正下方(两个空和右上角的左上是空)来确定开始点，然后走两次DFS将碎片填入拼图内。DFS或BFS均可，代码如下：(本题BFS时间略快一点，内存小了一倍)

```c++
#define mn 1005
ll m[mn][mn], p[mn * mn][4], n, lufi, rufi, a, b, c, d, n2;
ll dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, -1, 1}, luf, ruf = 1, ldf = 2, rdf = 3; //p开mn<<2暴死RE
void dfs(ll h, ll x, ll y)
{
    m[x][y] = h;
    rep(i, 0, 4)
    {
        ll ax = x + dx[i], ay = y + dy[i];
        if (ax > 0 && ay > 0 && ax <= n && ay <= n && !m[ax][ay])
            dfs(p[h][i], ax, ay);
    }
}
signed main()
{
    n = read();
    if (n == 1)
        return printf("1"), 0;
    n2 = n * n;
    rep(i, 0, n2)
    {
        a = read(), c = read(), b = read(), d = read();
        if (a)
            p[a][ldf] = b, p[a][rdf] = d;
        if (b)
            p[b][ruf] = a, p[b][rdf] = c;
        if (c)
            p[c][luf] = b, p[c][ruf] = d;
        if (d)
            p[d][luf] = a, p[d][ldf] = c;
    }
    repe(i, 1, n2)
    {
        if (!p[i][luf] && !p[i][ldf])
        {
            if (!p[i][ruf])
                lufi = i;
            else if (!p[p[i][ruf]][luf])
                rufi = i;
        }
        if (lufi && rufi)
            break;
    }
    dfs(lufi, 1, 1);
    dfs(rufi, 2, 1);
    repe(i, 1, n)
    {
        repe(j, 1, n) printf("%d ", m[i][j]);
        putchar('\n');
    }
    return 0;
}
```

BFS代码：

```c++
struct piece
{
    ll i, x, y;
};
void bfs(piece h)
{
    queue<piece> q;
    q.push(h);
    while (!q.empty())
    {
        re piece t = q.front();
        q.pop();
        if (m[t.x][t.y])
            continue;
        m[t.x][t.y] = t.i;
        rep(i, 0, 4)
        {
            re ll ax = t.x + dx[i], ay = t.y + dy[i];
            if (ax && ay && ax <= n && ay <= n && !m[ax][ay])
                q.push({p[t.i][i], ax, ay});
        }
    }
}
```



##### BFS

###### 迷宫问题

> 5x5迷宫，0为路1为墙，求从(0,0)到(4,4)的路径(含起始点)

个人实现版本：

```c++
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 7
ll m[MAXN][MAXN], dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 }, cnt;
bool vis[MAXN][MAXN];
struct io { ll fa, x, y; } me[MAXN * MAXN], n;
signed main()
{
	rep(i, 0, 5) rep(j, 0, 5) scanf("%d", &m[i][j]);
	queue<io> q;
	q.push({ 0,0,0 });
	vis[0][0] = true;
	while (!q.empty())
	{
		n = q.front(); q.pop();
		me[cnt++] = n;
		ll hi = n.fa;
		if (n.x == 4 && n.y == 4) break;
		rep(i, 0, 4)
		{
			ll ax = dx[i] + n.x;
			ll ay = dy[i] + n.y;
			if (ax < 0 || ay < 0 || ax >= 5 || ay >= 5) continue;
			if (!vis[ax][ay] && !m[ax][ay])
			{
				vis[ax][ay] = true;
				q.push({ cnt - 1,ax,ay });

			}
		}
	}
	io tr = n;
	vector<ll> bk;
	bk.push_back(cnt - 1);
	while (tr.fa)
	{
		bk.push_back(tr.fa);
		tr = me[tr.fa];
	}
	bk.push_back(0);
	rede(i, bk.size() - 1, 0) printf("(%d, %d)\n", me[bk[i]].x, me[bk[i]].y);
	return 0;
}
```

###### yyy2015c01挑战算周长

> 给定一个点，求这个点所在的八方向联通块的周长，地图大小不超过$20\times 20$。

算周长可以遍历联通块各点，如果其四方向上有联通块方块，那么不算这条边，否则算

```c++
#define mn 25
ll vis[mn][mn],m,n,x,y,r,dx[]={-1,0,1,0,-1,-1,1,1},dy[]={0,-1,0,1,-1,1,-1,1},nx,ny,ax,ay;
char a[mn][mn];
queue<ll> mx,my;
signed main()
{
    m=read();n=read();x=read();y=read();
    repe(i,1,m) scanf("%s",a[i]+1);
    mx.push(x); my.push(y);
    while(!mx.empty())
    {
        nx=mx.front(); ny=my.front(); mx.pop(); my.pop();
        if(vis[nx][ny]) continue;
        vis[nx][ny]=true;
        rep(i,0,8)
        {
            ax=nx+dx[i],ay=ny+dy[i];
            if(ax<1||ax>m||ay<1||ay>n||a[ax][ay]!='X') continue;
            mx.push(ax); my.push(ay);//不要写成ax>n
        }
    }
    repe(i,1,m) repe(j,1,n) if(vis[i][j]) rep(k,0,4)
    {
        ax=i+dx[k],ay=j+dy[k];
        if(vis[ax][ay]) continue;
        ++r;
    }
    return printf("%lld",r),0;
}
```

事实上DFS更巧妙：

```c++
#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,ans,pd[22][22],dx[8]={-1,-1,1,1,-1,0,0,1},dy[8]={-1,1,-1,1,0,-1,1,0}; 
//pd:判断这个方格有没有被访问过，dx和dy:搜索时的方向（0-3是四个角，4-7是上下左右） 
char k[22][22];
void dfs(int a,int b)
{
	pd[a][b]=1;//标记这个方格已经被访问过 
	for(int c=0;c<8;c++){
		int d=dx[c]+a,e=dy[c]+b;
		if(d>0&&d<=m&&e>0&&pd[d][e]==0&&k[d][e]=='X')dfs(d,e);//如果这个格子没出界，没被访问过并且显示的是'X'，就访问这个格子
		if(c>3&&(d<=0||d>m||e<=0||e>n||k[d][e]!='X'))ans++;//如果方向是上下左右，并且出界了或者显示的不是'X'，周长就要+1 
	}
}
int main()
{
	cin>>m>>n>>x>>y;
	for(int a=1;a<=m;a++)
		for(int b=1;b<=n;b++)
			cin>>k[a][b];
	dfs(x,y),cout<<ans;
	return 0;
}
```



###### 迷宫

> (蓝桥)给定一个30$\times$50迷宫，四方向为DULR，输出一种步数最少下字典序最小的解法。

本题如果使用优先级队列会出现问题，而且比较繁琐。标解是~~Excel手算~~一般BFS，但是需要控制四方向遍历的顺序为DULR。这种情况下的通路必然是最短的，且在最短的情况下，每一步都尽可能的先DULR，证明了字典序的最小。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 53
typedef int ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
bool vis[mn][mn],halt;
ll dx[]={1,0,0,-1},dy[]={0,-1,1,0},hl;
string ds="DLRU";
typedef set<pair<ll,ll>> sp;
struct node
{
    string s;
    ll x,y,p;
    sp v;
    inline bool operator<(const node& x)const
    {
        if(p!=x.p) return p>x.p;
        return s<x.s;
    }
};
//priority_queue<node> q,ans;
queue<node> q;
signed main()
{
    freopen("maze.txt","r",stdin);
    repe(i,1,30) repe(j,1,50)
    {
        scanf("%1d",&vis[i][j]);
    }
    sp x;
    x.insert({1,1});
    q.push({"",1,1,0,x});
    while(!q.empty())
    {
        node t=q.front(); q.pop();
        if(t.x==30&&t.y==50)
        {
            cout<<t.s;
            return 0;
            halt=true;
            //ans.push(t);
        }
        node nd;
        #define st nd.v
        for(auto it=t.v.begin();it!=t.v.end();++it)
            st.insert(*it);//,printf("%d %d\n",it->first,it->second);
        if(halt) continue;
        repe(i,0,3)
        {
            ll ax=t.x+dx[i],ay=t.y+dy[i];
            if(ax<1||ay<1||ax>30||ay>50||vis[ax][ay]) continue;
            pair<ll,ll> pos={ax,ay};
            if(t.v.find(pos)==t.v.end())
            {
                vis[ax][ay]=true;
                st.insert(pos);
                nd.x=ax;
                nd.y=ay;
                nd.p=t.p+1;
                nd.s=t.s+ds[i];
                q.push(nd);
            }
        }
    }
    //cout<<ans.top().s;
    return 0;
}
```

###### 肿瘤诊断

> (天梯)输入第一行给出4个正整数：*M*、*N*、*L*、*T*，其中*M*和*N*是每张切片的尺寸（即每张切片是一个*M*×*N*的像素矩阵。最大分辨率是1286×128）；*L*（≤60）是切片的张数；*T*是一个整数阈值（若疑似肿瘤的连通体体积小于*T*，则该小块忽略不计）。
>
> 最后给出*L*张切片。每张用一个由0和1组成的*M*×*N*的矩阵表示，其中1表示疑似肿瘤的像素，0表示正常像素。由于切片厚度可以认为是一个常数，于是我们只要数连通体中1的个数就可以得到体积了。麻烦的是，可能存在多个肿瘤，这时我们只统计那些体积不小于*T*的。两个像素被认为是“连通的”，如果它们有一个共同的切面，所有6个的相邻像素都与该像素连通(六方向)。

注意遍历顺序、存储顺序等各种细节，以及数组开大多一点，只开大两点可能就会WA。其他就是十分普通的BFS连通块裸题了。

```c++
bool a[1288][130][62];
ll dx[8]={-1,1,0,0,0,0},dy[8]={0,0,-1,1,0,0},dz[8]={0,0,0,0,-1,1};
struct po{ll x,y,z;};
void prt(ll m, ll n, ll l)
{
    repe(k,1,l)
    {
        repe(i,1,m)
        {
            repe(j,1,n)
            {
                printf("%d ",a[i][j][k]);
            }
            printf("\n");
        }
    }
    printf("\n");
}
signed main()
{
    re ll cnt,m,n,l,t,ans=0,ax,ay,az;
    re po p;
    scanf("%d%d%d%d",&m,&n,&l,&t);
    repe(k,1,l)
    {
        repe(i,1,m)
        {
            repe(j,1,n)
            {
                scanf("%d",&a[i][j][k]);
            }
        }
    }
    repe(k,1,l)
    {
        repe(i,1,m)
        {
            repe(j,1,n)
            {
                if(a[i][j][k])
                {
                    cnt=0;
                    queue<po> q;
                    q.push({i,j,k});
                    while(!q.empty())
                    {
                        p=q.front();
                        q.pop();
                        if(!a[p.x][p.y][p.z]) continue;
                        ++cnt;
                        a[p.x][p.y][p.z]=false;
                        rep(e,0,6)
                        {
                            ax=p.x+dx[e];
                            ay=p.y+dy[e];
                            az=p.z+dz[e];
                            if(ax>0&&ay>0&&az>0&&ax<=m&&ay<=n&&az<=l&&a[ax][ay][az])
                            {
                                q.push({ax,ay,az});
                            }
                        }
                    }
                    if(cnt>=t) ans+=cnt;
                    //prt(m,n,l);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}

```

###### 拐弯

> (oj)给定$n\times n(2\le n\le 100)$地图，从$A$到$B$，`#`是障碍。起点和终点方向任意，求最少需要拐弯多少次。如果无法到达输出`-1`。

可以尝试DFS，也可以用BFS或贪心(未证)。每次拓展是从上次转弯后所有位置四方向直线延伸。

```c++
#define mn 111
#define big 0x7ffffffa
ll n, dp[mn][mn], ax, ay, bx, by, cx, cy;
ll dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char m[mn][mn];
struct node
{
    ll x, y;
};
il bool in(ll x, ll y)
{
    return x > 0 && y > 0 && x <= n && y <= n && m[x][y] != '#';
}
queue<node> q;
signed main()
{
    cin >> n;
    repe(i, 1, n)
    {
        repe(j, 1, n)
        {
            cin >> m[i][j];
            if (m[i][j] == 'A')
                ax = i, ay = j;
            if (m[i][j] == 'B')
                bx = i, by = j;
            dp[i][j] = big;
        }
    }
    dp[ax][ay] = -1;
    repe(h, 0, 100) //未证100一定是最大拐弯次数
    {
        vector<node> nw;
        repe(i, 1, n) repe(j, 1, n) if (dp[i][j] == h - 1)
        {
            rep(k, 0, 4)
            {
                cx = i + dx[k], cy = j + dy[k];
                while (in(cx, cy) && dp[cx][cy] == big) //or > h
                {
                    nw.push_back({cx, cy});
                    cx += dx[k];
                    cy += dy[k];
                }
            }
        }
        rep(i, 0, nw.size()) dp[nw[i].x][nw[i].y] = h;
        repe(i, 1, n) repe(j, 1, n) if (i == bx && j == by && dp[i][j] == h)
        {
            printf("%lld", h);
            return 0;
        }
    }
    return printf("-1"), 0;
}
```



###### 大胖子走迷宫

> (蓝桥)有$n$阶矩阵迷宫，从1计数，起点为$3,3$，终点为$n-2,n-2$。一开始玩家体积为$5\times 5$，时间从$0$开始，经过$t$时间后体积变为$3\times 3$，经过$2t$时间后体积变为$1\times 1$，求从起点到终点的最短时间。输入$n,k(1\le n\le300,1\le k\le10^3)$。

参考代码：

```c++
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int x, y, time;
};

const int N = 310;

int n, k;
char g[N][N];
bool vis[N][N];

int dr[3] = {2, 1, 0};    // 表示胖子不同时刻的半径
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    queue<node> q;
    q.push({3, 3, 0});
    vis[3][3] = true;

    while(q.size())
    {
        node t = q.front();
        q.pop();

        if(t.x == n - 2 && t.y == n - 2) return t.time;

        if(t.time / k < 2) q.push({t.x, t.y, t.time + 1});                          // 体积为 1 后，就不用原地不动了
        for (int i = 0; i < 4; i ++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            int fat = t.time / k > 2? 0 : dr[t.time / k];                           // 此时胖子的半径
            if(a - fat < 1 || a + fat > n || b - fat < 1 || b + fat > n) continue;
            if(vis[a][b]) continue;

            bool flag = false;                                                      // 判断胖子所占范围内是否有障碍物
            for (int j = a - fat; j <= a + fat; j ++)
		        for (int k = b - fat; k <= b + fat; k ++)
		            if(g[j][k] == '*') flag = true;

            if(flag) continue;

            q.push({a, b, t.time + 1});
            vis[a][b] = true;
        }
    }

    return -1;
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;

    cout << bfs() << endl;
    return 0;
}
```

> 个人错解：可以设三个不同的vis值，代表不同的体积状态下是否经过了这个格子，小体积下可以反复走大体积走过的值；并且除了四方向移动，应当还有一个选项是原地等瘦。注意要用vis剪枝，否则会走死循环。可以再来个时间剪枝（但是经过测试还是达到了非常高的复杂度，要么TLE要么MLE）



###### 棋子翻转

> (scnu cgy)有$4\times 4$棋盘双面异色棋，一次操作对一颗棋子和四方向棋子翻转，如果所有棋子同色胜利。给定棋局，求最小移动次数或输出无解。

本题BFS反正很简单(注意不要把queue写成stack……)，DFS或for循环暴力也可以，因为状态数只有$2^{16}$种。个人代码如下：

```c++
unordered_map<string, ll> us;
string fa="aaaaaaaaaaaaaaaa",fb="bbbbbbbbbbbbbbbb",bg,t,fc="ba";
ll dx[]={-1,0,1,0,0},dy[]={0,-1,0,1,0};
il ll toi(ll x, ll y) {return x+y*4;}
il ll ck(ll x, ll y)
{
    return x>=0&&y>=0&&x<4&&y<4;
}
queue<string> s;
signed main()
{
    rep(i,0,4) {cin>>t; bg+=t;} s.push(bg); us[bg]=1;
    if(bg==fa||bg==fb) return printf("0"),0;//注意特判
    while(!s.empty())
    {
        t=s.front(); s.pop();
        ll ti=us[t];
        rep(ax,0,4) rep(ay,0,4)
        {
            rep(k,0,5)
            {
                if(!ck(ax+dx[k],ay+dy[k])) continue;
                ll ki=toi(ax+dx[k],ay+dy[k]);
                t[ki]=(t[ki]=='b'?'a':'b');
            }
            if(t==fa||t==fb)
            {
                printf("%lld",ti);
                return 0;
            }
            if(!us[t]||us[t]>ti+1)
            {
                us[t]=ti+1;
                s.push(t);
            }
            rep(k,0,5)
            {
                if(!ck(ax+dx[k],ay+dy[k])) continue;
                ll ki=toi(ax+dx[k],ay+dy[k]);
                t[ki]=(t[ki]=='b'?'a':'b');
            }
        }
    }
    printf("Impossible");
	return 0;
}
```

还可以用状态压缩和别的建模方法，官方题解如下：

> 用到二进制来描述装置，1表示被主动翻转，0表示没有被主动翻转。比如说第一行的状态是5，转换为二进制就是0101，它所表示的含义就是在这一行的第二和第四个位置都被主动翻转过了，这样我们就可以用四个变量来描述四行棋子的状态了。
>  接着，我们就需要判断在这个状态下，是否全部棋子都是相同颜色的。如果可以完成目标而且主动翻转次数比之前找到的解更小，就把他记录下来。判断棋子颜色也很简单，比如说要判断某颗棋子是不是黑色，如果先前为“b”，就计数器num就为1，然后再记录周围（上左下右中5个位置）的主动翻转次数，最后计数器的值为为奇数说明它是黑色，否则为白色。

```c++
char s[6][6];
int zt[5];
int mark[6][6];
int move[]={1,0,0,1,-1,0,0,-1,0,0};
int res=17;

bool is_black(int x,int y){
    int num=0;
    if(s[x][y]=='b')num++;
    for(int i=0;i<10;i+=2){
        if(mark[x+move[i]][y+move[i+1]])
            num++; 
    }
    if(num&1) return true;
    else return false;
}

void check(int a,int b,int c,int d){
    memset(mark,0,sizeof(mark));
    int ans=0;
    zt[1]=a,zt[2]=b,zt[3]=c,zt[4]=d;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++){
            if(zt[i]&1){
                mark[i][j]=1;
                ans++;
            } 
            zt[i]>>=1;
        }
    int numb=0,numw=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(is_black(i,j))numb++;
            else numw++;
            if(numb && numw)return ;
        }   
    }
    if(ans<res)res=ans;
    return ;
}

int main()
{
    for(int i=1;i<=4;i++)
        scanf("%s",s[i]+1);
    
    for(int a=0;a<(1<<4);a++)
        for(int b=0;b<(1<<4);b++)
            for(int c=0;c<(1<<4);c++)
                for(int d=0;d<(1<<4);d++)
                    check(a,b,c,d);
    if(res==17)
        cout<<"Impossible"<<endl;
    else
        cout<<res<<endl; 
    return 0;
}
```

#### 剪枝

##### 例题

###### 青蛙跳杯子

> (蓝桥)已知初始状态有一个空杯子*，其余杯子有青蛙W和B，杯数$\le15$，每个青蛙可以跳到相邻的空杯子或隔着1或2只青蛙跳到空杯子，给定初始状态和终止状态，求最小步数。

朴素剪枝+BFS即可。个人实现版本如下

```c++
#include <bits/stdc++.h> 
using namespace std;
map<string,int> m;
char c[20],o[20];
int n,p,stp,i,des;
struct stt
{
	char c[20];//注意需要每次复制，因指针和BFS问题，无法回溯
	int stp, i;
};
queue<stt> q;
signed main()
{
	scanf("%s%s",c,o);
	n=strlen(c);
	for(p=0;p<n;++p) if(c[p]=='*') break;
	stt te;
	te.stp=0,te.i=p;
	strcpy(te.c,c);//写成cmp暴毙，直接赋值暴毙
	q.push(te);
	while(!q.empty())
	{
		stt temp=q.front(); q.pop();
		stp=temp.stp,i=temp.i;	
		if(m.find(temp.c)!=m.end()) continue;
		m[temp.c]=stp;
		if(!strcmp(temp.c,o))
		{
			printf("%d",stp);
			return 0;
		}
		for(int j=-3;j<=3;++j)//审错题写成2暴毙
		{
			des=i+j;
			if(j&&des>=0&&des<n)
			{
				stt t;
				strcpy(t.c,temp.c);
				swap(t.c[des],t.c[i]);
				t.i=des,t.stp=stp+1;//没有更新状态暴毙
				q.push(t);
			}
		}
	} 
	return 0;
}
```

###### 九宫幻方

> 给定残缺的三阶幻方(横竖及对角线和相同)，求解，如果只有一个解，输出，否则输出Too Many。

个人实现版本。

```c++
#include <bits/stdc++.h>
using namespace std;
int m[4][4],sol,s[4][4],b,sum,mul=1;
void dfs(int x, int y, int lf)
{
	if(sum>45||mul>362880||y>3) return;
	if(!lf)
	{
		if(!(sum==45&&mul==362880)) return;
		int std=m[0][0]+m[1][1]+m[2][2];
		if(std!=m[0][2]+m[1][1]+m[2][0]) return;
		for(int i=0;i<3;++i) 
			if(std!=m[i][0]+m[i][1]+m[i][2]) return;
		for(int i=0;i<3;++i) 
			if(std!=m[0][i]+m[1][i]+m[2][i]) return;
		++sol;
		for(int i=0;i<3;++i) for(int j=0;j<3;++j) s[i][j]=m[i][j];
		return;
	}
	if(!m[x][y])
	{
		for(int n=1;n<=9;++n)
		{
			sum+=n,mul*=n,m[x][y]=n;
			dfs((x+1)%3,y+(x+1)/3,lf-1);
			sum-=n,mul/=n,m[x][y]=0;
		}
	}
	else dfs((x+1)%3,y+(x+1)/3,lf);
}
signed main()
{
	for(int i=0;i<3;++i) for(int j=0;j<3;++j)
	{
		scanf("%d",&m[i][j]);
		if(!m[i][j]) ++b;
		else sum+=m[i][j],mul*=m[i][j];
	}
	dfs(0,0,b);
	if(sol==1) for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j) printf("%d ",s[i][j]);
		printf("\n");
	}
	else printf("Too Many");
	return 0;
}
```

###### 字串变换

> 有不超过6个字串转化关系X->Y，输入A,B，问是否能在十次(含十)单一转化之内实现A->B，若能输出最小转化次数；否则输出NO ANSWER!

```c++
#include <bits/stdc++.h>
//#include <string>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 11
string a, b, fml[MAXN], ffl[MAXN];
ll ans, n;
map<string, bool> ma;
string trans(const string& str, ll i, ll j)
{
	if (i + fml[j].size() > str.size()) return "";
	rep(k, 0, fml[j].size()) if (str[i + k] != fml[j][k]) return "";
	return str.substr(0, i) + ffl[j] + str.substr(i + fml[j].size());
}

#define node pair<string,int>
void bfs()
{
	queue<node> q;
	q.push({ a,0 });
	node hi;
	string temp;
	while (!q.empty())
	{
		hi = q.front(); q.pop();
		if (ma.count(hi.first) == 1) continue;//该次A与此前某次A完全一致
		if (hi.first == b) { ans = hi.second; break; }
		ma[hi.first] = true;
		rep(i, 0, hi.first.size())
		{
			rep(j, 0, n)
			{
				temp = trans(hi.first, i, j);
				if (temp != "") q.push({ temp,hi.second + 1 });
			}
		}
	}
	if (ans > 10 || ans == 0) cout << "NO ANSWER!";
	else cout << ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> a >> b;
	while (cin >> fml[n] >> ffl[n]) n++;
	bfs();
	return 0;
}
```

###### 邮局

> (蓝桥)有n个村民，m个邮局，选择k个，使得村民到自己最近的邮局距离和最小，求这k个邮局。$1\le n\le50,1\le m\le25,1\le k\le10$

暴力炸时间，动态规划炸空间。数据量较小，考虑搜索算法。朴素DFS仍然会炸，考虑剪枝，当当下情况剩余的未选邮局全选不能凑够k个，或选择了这个邮局不会带来任何优化。还可以增设全局剪枝，如果选择一个邮局不会带来任何优化，可以直接排除掉(待证正确性)。注意double和int不要混用。

```c++
#include <bits/stdc++.h>
#define mn 53
#define repe(i,a,b) for(int i=a;i<=b;++i)
typedef double db;
using namespace std;
int n,m,k;
struct po
{
	int x,y;
} v[mn],em[mn];
db d[mn][mn],dd[mn],as=1e18;
int ci[mn],ans[mn],ban[mn];
inline db dis(po& a, po& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void dfs(int h, int kn, db res, db* dv)
{
	if(k-kn>m-h||h>m&&kn<=k) return;
	if(kn==k+1)
	{
		if(res<as)
		{
			as=res;
			repe(i,1,k) ans[i]=ci[i];
		}
		return;
	}
	db ddv[mn]; repe(i,1,n) ddv[i]=dv[i];
	dfs(h+1,kn,res,ddv);
	if(ban[h]) return;
	ci[kn]=h; bool op=false;
	if(kn==1) repe(i,1,n) res+=(ddv[i]=d[i][h]);
	else repe(i,1,n)
	{
		if(d[i][h]<ddv[i])
		{
			 res+=d[i][h]-ddv[i],ddv[i]=d[i][h];
			 op=true;
		}
	}
	if(kn>1&&!op) ban[h]=1;
	if(kn==1||op) dfs(h+1,kn+1,res,ddv);
}
signed main()
{
	scanf("%d%d%d",&n,&m,&k); memset(dd,-1,sizeof dd);
	repe(i,1,n) scanf("%d%d",&v[i].x,&v[i].y);
	repe(i,1,m) scanf("%d%d",&em[i].x,&em[i].y);
	repe(i,1,n) repe(j,1,m) d[i][j]=dis(v[i],em[j]);
	dfs(1,1,0,dd);
	repe(i,1,k) printf("%d ",ans[i]);
	return 0;
} 
```

###### 小木棍

> 有n根木棍，取其中长小于50的，求它们拼接成的等长木棍组的最小长度。

常规剪枝不做特别注释。

$res==a[i]$是关键优化剪枝，如果没有会TLE

> **当前长棍剩余的未拼长度**等于**当前木棍的长度**时，这根木棍在最优情况下显然是拼到这（如果用更多短木根拼完剩下的这段，把这根木棍留到后面显然不如把更多总长相等的短木棍扔到后面）。如果在最优情况下继续拼下去失败了，那肯定是之前的木棍用错了，回溯改即可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 66
ll n, m, a[MAXN], nx[MAXN], cnt, sum, len, v;
bool vis[MAXN], ok;
inline bool cmp(const ll& a, const ll& b) { return a > b; }
void dfs(ll k, ll last, ll rest)
{
	ll i;
	if (!rest)//第k根拼接为len长度，下一根尝试
	{
		if (k == m) { ok = true; return; }//搜索到了最后一根，全部都用上了
		for (i = 1; i <= cnt; ++i) if (!vis[i]) break;//拼的过程未用过，则是下一根
		vis[i] = true;
		dfs(k + 1, i, len - a[i]);
		vis[i] = 0;
		if (ok) return;
	}
	ll lf = last + 1, rf = cnt, cf = 0;
	while (lf < rf)//尽可能往大的取，让dfs树小一些
	{
		cf = (lf + rf) >> 1;
		if (a[cf] <= rest) rf = cf;
		else lf = cf + 1;
	}
	for (i = lf; i <= cnt; ++i)
	{
		if (!vis[i])//尝试拼接这一根
		{
			vis[i] = true;
			dfs(k, i, rest - a[i]);
			vis[i] = false;
			if (ok) return;
			if (rest == a[i] || rest == len) return;//重要
			i = nx[i];
			if (i == cnt) return;
		}
	}
}
signed main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &v);
		if (v <= 50) a[++cnt] = v, sum += v;
	}
	sort(a + 1, a + 1 + cnt, cmp);
	nx[cnt] = cnt;
	red(i, cnt - 1, 0)//等长离散优化
	{
		if (a[i] == a[i + 1]) nx[i] = nx[i + 1];
		else nx[i] = i;
	}
	for (len = a[1]; len <= sum >> 1; ++len)
	{
		if (sum % len) continue;
		m = sum / len;
		ok = false;
		vis[1] = true;
		dfs(1, 1, len - a[1]);
		vis[1] = false;
		if (ok) return printf("%d", len), 0;
	}
	printf("%d", sum);
	return 0;
}
```

###### 虫食算

> 有n位n进制加法算式，各字母含义未知，求一组含义，使等式成立

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 28
ll a[MAXN], b[MAXN], c[MAXN], num[MAXN], nx[MAXN], n, cnt;
char sa[MAXN], sb[MAXN], sc[MAXN];
bool vis[MAXN];
inline bool jud()
{
	for (ll i = n - 1, x = 0; i >= 0; i--)
	{
		ll av = num[a[i]], bv = num[b[i]], cv = num[c[i]];
		if ((av + bv + x) % n != cv) return false;
		x = (av + bv + x) / n;
	}
	return true;
}
inline bool cutb()
{
	if (num[a[0]] + num[b[0]] >= n) return false;
	rede(i, n - 1, 0)
	{
		ll av = num[a[i]], bv = num[b[i]], cv = num[c[i]];
		if (av == -1 || bv == -1 || cv == -1) continue;
		if ((av + bv) % n != cv && (av + bv + 1) % n != cv) return true;
	}
	return false;
}
inline void prt()
{
	rep(i, 0, n) printf("%d ", num[i]);
	exit(0);
}
void dfs(ll x)
{
	if (cutb()) return;
	if (x == n)
	{
		if (jud()) prt();
		return;
	}
	rede(i, n - 1, 0)
	{
		if (!vis[i])
		{
			num[nx[x]] = i;
			vis[i] = true;
			dfs(x + 1);
			num[nx[x]] = -1;
			vis[i] = false;
		}
	}
}
inline ll id(char c) { return c - 'A'; }
void gonx(ll x)
{
	if (!vis[x])
	{
		vis[x] = true;
		printf("%d ", x);
		nx[cnt++] = x;
	}
}
signed main()
{
	scanf("%d%s%s%s", &n, sa, sb, sc);
	rep(i, 0, n)
	{
		a[i] = id(sa[i]);
		b[i] = id(sb[i]);
		c[i] = id(sc[i]);
		num[i] = -1;
	}
	rede(i, n - 1, 0)
	{
		gonx(a[i]);
		gonx(b[i]);
		gonx(c[i]);
	}
	rep(i, 0, n) vis[i] = false;
	dfs(0);
	return 0;
}
```

#### 数字类

> 已经进入最后例题的待分组

##### 带分数

> (蓝桥)数n可以由带分数表示$a+\frac bc$，求$a,b,c$的数位恰好是$1\sim9$且数位和为$9$的情况数。$1\le n\le10^6$

由于解集在9的全排列上，所以可以枚举全排列(如果枚举单个数字，就算剪枝也会超时)。但是$9!$乘上三分九格即$C_8^2$的复杂度还是会超时，所以进行剪枝，法则如下：

对于每个排列，必须满足：

1. $n=a+\frac bc\Rightarrow b=(n-a)\times c$，即$b$的个位数必须可以确定，确定表达式为：

   $b[个]=(n-a)\times P[9]$，其中a通过一次循环枚举得到。

2. $\frac bc$一定是真分数，所以剩下的长度中$b$必须不小于$c$。

```c++
#include <bits/stdc++.h>
using namespace std;
int n,lt[]={1,2,3,4,5,6,7,8,9},nd,ans;
inline int num(int *lt, int lf, int rf)
{
	int res=0;
	for(int i=lf;i<=rf;++i) res=lt[i]+(res<<1)+(res<<3);
	return res;
}
void prim(int *lt, int k, int m)
{
	if(k+1==m)
	{
		int a=0,b=0,c=0,blst=0;
		for(int i=0;i<nd;++i)
		{
			a=num(lt,0,i);
			blst=((n-a)*lt[8])%10;
			for(int j=4+(i>>1);j<8;++j)//i+(8-i)/2的化简
			{
				if(lt[j]==blst)
				{
					b=num(lt,i+1,j);
					c=num(lt,j+1,8);
					if(b%c==0&&a+b/c==n) ++ans;
					break;
				}
			}
		}
	}
	else for(int i=k;i<m;++i)
	{
		swap(lt[k],lt[i]);
		prim(lt,k+1,m);
		swap(lt[k],lt[i]);
	}
}
signed main()
{
	scanf("%d",&n);
	for(int i=n;i;i/=10) ++nd;
	prim(lt,0,9);
	return printf("%d",ans)&0;
}
```

##### 机器分配

> 有M台设备，有N个公司，每个公司拿到不同台数设备时会提供不同的盈利。求最大盈利值和字典序最小的答案。
>
> $1\le m\le15,1\le n\le10$

字典序最小，则只需要从小到大搜索，那么第一次搜索到的最值必然是最小的，而无需特别判断。

###### DFS

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 18
ll a[mn][mn],mx,n,m,ans[mn],t[mn];
void dfs(ll c, ll lf, ll cnt)
{
    if(!lf||c>n)
    {
        if(cnt>mx)
        {
            mx=cnt;
            memcpy(ans,t,sizeof t);
        }
        return;
    }
    for(ll i=0;i<=lf;++i)
    {
        t[c]=i;
        dfs(c+1,lf-i,cnt+a[c][i]);
        t[c]=0;//必须回溯
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=m;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    dfs(1,m,0);
    printf("%lld\n",mx);
    for(ll i=1;i<=n;++i)
    {
        printf("%lld %lld\n",i,ans[i]);
    }
    return 0;
}
```

###### DP

设$f[i][j]$为前$i$个公司一共分配了$j$台机器下的最值，设$path[i][j][h]$为$f[i][j]$下第$h$家公司分配的设备数。使用区间DP即可。

DP的时间复杂度远小于搜索，即便复杂度为$\Omicron(n^2m^2)$。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mn 17
ll m,n,dp[mn][mn],ay[mn][mn][mn],a[mn][mn];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=m;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    for(ll i=1;i<=n;++i)
    {
        for(ll j=0;j<=m;++j)
        {
            for(ll k=0;k<=j;++k)
            {//为了得到最小，所以dp里从k而不是j-k
                if(dp[i-1][k]+a[i][j-k]>dp[i][j])
                {
                    dp[i][j]=dp[i-1][k]+a[i][j-k];
                    for(ll h=1;h<i;++h) ay[i][j][h]=ay[i-1][k][h];
                    ay[i][j][i]=j-k;
                }
            }
        }
    }
    printf("%lld\n",dp[n][m]);
    for(ll i=1;i<=n;++i)
    {
        printf("%lld %lld\n",i,ay[n][m][i]);
    }
    return 0;
}
```

##### 奇妙数字问题

> (oj)只使用$0\sim9$的一部分数字构成$[1,10^{100}]$之内的整数$d$，求最小的$d$使得$x|d$，无解输出`-1`
>
> $1\le t\le200,0<x\le 3000$

考虑BFS，初始状态为单位数(注意从小到大排列)。本题关键在于判重且枚举新增放在数字右边(可以保证BFS首先找到的答案最小)。判重直接使用模，每次乘10+新的末位然后取模。

```c++
ll t, vis[3010], dstr, x, d[12], dl, ok;
struct node
{
    ll left;
    string ans;
};
signed main()
{
    sc(t);
    while (t--)
    {
        sc(dstr), sc(x);
        ok = dl = 0;
        memset(vis, 0, sizeof vis);
        queue<node> q;
        rede(i, 9, 0)
        {
            if (dstr % 10)
                d[dl++] = i; //在这里q.push加队列顺序就不对了……
            dstr /= 10;
        }
        reverse(d, d + dl);
        rep(i, 0, dl) if (d[i])
            q.push({d[i], string(1, '0' + (char)(d[i]))});
        while (!q.empty())
        {
            re node t = q.front();
            q.pop();
            if (t.left == 0)
            {
                cout << t.ans << '\n';
                ok = true;
                break;
            }
            if (t.ans.size() > 100)
                break;
            if (vis[t.left])
                continue;
            vis[t.left] = true;
            rep(i, 0, dl)
            {
                node nx;
                nx.left = (t.left * 10 + d[i]) % x;
                nx.ans = t.ans + (char)('0' + d[i]);
                q.push(nx);
            }
        }
        if (!ok)
            printf("-1\n");
    }
    return 0;
}
```





#### 例题

##### 组队

> (蓝桥)给定20个人，有5个位置，给定每人在5个占位时（每人只能占一个位置）；求最大分数。

显然是一道送分题。拓展到任意人任意位置需要DFS。否则直接暴力也行。给出两种解法：

###### DFS

```c++
#include <iostream>

using namespace std;

int visited[21];
int pp[21][6];

int mmax = 0;

void dfs(int p, int sum)
{
	if(p > 5)
	{
		if(sum > mmax)
		{
			mmax = sum;
		}
	}
	else
	{
		for(int i=1; i<=20; i++)
		{
			if(visited[i] == 0)
			{
				visited[i] = 1;
				dfs(p+1, sum+pp[i][p]);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	for(int i=1; i<=20; i++)
	{
		visited[i] = 0;
		for(int j=1; j<=5; j++)
		{
			cin>>pp[i][j];
		}
	}
	dfs(1, 0);
	cout<<mmax<<endl;
	return 0;
}
```

###### 暴力

```c++
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
struct player
{
	int no;
	int a,b,c,d,e;
}team[20];
 
int main()
{
	FILE *fp=fopen("team.txt","r");
	for(int i=0;i<20;i++)
		fscanf(fp,"%d%d%d%d%d%d",&team[i].no,&team[i].a,&team[i].b,&team[i].c,&team[i].d,&team[i].e);
	int ans=0;
	for(int i=0;i<20;i++)
	{
		if(!team[i].a)
			continue;
		for(int j=0;j<20;j++)
		{
			if(j==i||!team[j].b)
				continue;
			for(int k=0;k<20;k++)
			{
				if(k==j||k==i||!team[k].c)
					continue;
				for(int m=0;m<20;m++)
				{
					if(m==k||m==j||m==i||!team[m].d)
						continue;					
					for(int n=0;n<20;n++)
					{
						if(n==m||n==k||n==j||n==i||!team[n].e)
							continue;
						if(team[i].a+team[j].b+team[k].c+team[m].d+team[n].e>ans)
							ans=team[i].a+team[j].b+team[k].c+team[m].d+team[n].e;					
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
```

##### 数独求解

给出一个不完整数独，输出答案

```c++
#include <bits/stdc++.h>
#define N 10
using namespace std;
int s[N][N];
bool x[N][N], y[N][N], b[N][N];
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define nx if (j != 9) dfs(i, j + 1);else if (i != 9 && j == 9) dfs(i + 1, 1);else prt()
inline int tob(int x, int y)
{
	return 1 + (x - 1) / 3 * 3 + (y - 1) / 3;
}
inline void prt()
{
	rep(i, 1, 9)
	{
		rep(j, 1, 9)
		{
			printf("%d ", s[i][j]);
		}
		putchar('\n');
	}
    exit(0);//否则dfs还在算！
}
void dfs(int i, int j)
{
	if (s[i][j]) nx;
	else
	{
		rep(c, 1, 9)
		{
			int z = tob(i, j);
			if (!x[i][c] && !y[j][c] && !b[z][c])
			{
				s[i][j] = c;
				x[i][c] = true;
				y[j][c] = true;
				b[z][c] = true;
				nx;
				s[i][j] = 0;
				x[i][c] = false;
				y[j][c] = false;
				b[z][c] = false;
			}
		}
	}
}
signed main()
{
	rep(i, 1, 9)
	{
		rep(j, 1, 9)
		{
			scanf("%d", &s[i][j]);
			if (!s[i][j]) continue;
			x[i][s[i][j]] = true;
			y[j][s[i][j]] = true;
			b[tob(i, j)][s[i][j]] = true;
		}
	}
	dfs(1, 1);
	return 0;
}
```

##### Corn Maze S

> 走迷宫，从@出发，走到=，.为道路，A-Z为传送门，同字母的传送门可以相互传送，如果经过了传送门必须使用而不能忽视。求到达终点的最小步数。

本题广搜超时；若深搜但不用vis而用depth，要么超时要么超内存。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 302
char tv;
bool visb[MAXN][MAXN], vis[MAXN][MAXN];
ll stp[MAXN][MAXN], ans, finx, finy, bgx, bgy;
ll n, m, dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
struct node
{
	ll x, y, t;
};
map<char, ll> tpx, tpy, tp2x, tp2y;
map<pair<ll, ll>, char> dtp;
queue<node> q;
void bfs()
{
	q.push({ bgx,bgy,0 });
	node tmp;
	ll ax, ay, cx, cy;
	bool tp;
	vis[bgx][bgy] = true;
	while (!q.empty())
	{
		tmp = q.front(); q.pop();
		if (tmp.x == finx && tmp.y == finy)
		{
			ans = tmp.t; break;
		}
		rep(i, 0, 4)
		{
			tp = false;
			ax = tmp.x + dx[i];
			ay = tmp.y + dy[i];
			if (ax<0 || ay<0 || ax>n || ay>m) continue;
			if (dtp.find({ ax,ay }) != dtp.end())
			{
				tv = dtp[{ax, ay}];
				tp = true;
				if (tpx[tv] == ax && tpy[tv] == ay)
					cx = tp2x[tv], cy = tp2y[tv];
				else cx = tpx[tv], cy = tpy[tv];
			}
			if (visb[ax][ay] && !vis[ax][ay])
			{
				vis[ax][ay] = true;
				if (!tp) q.push({ ax,ay,tmp.t + 1 });
				else q.push({ cx,cy,tmp.t + 1 });
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	repe(i, 1, n)
	{
		repe(j, 1, m)
		{
			stp[i][j] = 0x7fffffff;
			cin >> tv;
			if (tv == '=') visb[i][j] = true, finx = i, finy = j;
			else if (tv == '@') visb[i][j] = true, bgx = i, bgy = j;
			else if (tv == '.') visb[i][j] = true;
			else if (isalpha(tv))
			{
				visb[i][j] = true;
				if (tpx.find(tv) != tpx.end()) tp2x[tv] = i, tp2y[tv] = j;
				else tpx[tv] = i, tpy[tv] = j;
				dtp[{i, j}] = tv;
			}
		}
	}
	bfs();
	cout << ans;
	return 0;
}
```

##### 幻象迷宫

> #是墙,.是路，S是起点；迷宫为输入迷宫的无限重合，所以如果能够沿着某条路一直走，则可以走出迷宫；求是否能走出迷宫

###### BFS

定义$upl[i][j][k]$代表到达某个点向左(k=0)穿过迷宫边界和向上(k=1)穿过迷宫边界的次数，如果向右/下则记一次负数；特别地，32767代表墙壁;如果穿过次数至少有一个不相同，则走的路不是自环死胡同，则可以通过。

```C++
#include <bits/stdc++.h>
using namespace std;
typedef short ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1502
ll n, m, bgx, bgy, dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
ll upl[MAXN][MAXN][2];
bool vis[MAXN][MAXN], suc;
char c;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (cin >> n >> m)
	{
		rep(i, 0, n)
		{
			rep(j, 0, m)
			{
				cin >> c;
				upl[i][j][1] = 0;
				if (c == '#') vis[i][j] = true, upl[i][j][0] = 32767;
				else
				{
					vis[i][j] = false, upl[i][j][0] = 0;
					if (c == 'S') bgx = i, bgy = j, vis[bgx][bgy] = true;
				}
			}
		}
		suc = false;
		queue<pair<ll, ll>> q;
		q.push({ bgx,bgy });
		while (!q.empty() && !suc)
		{
			auto p = q.front(); q.pop();
			for (ll i = 0; i < 4 && !suc; ++i)
			{
				pair<ll, ll> t(p.first + dx[i], p.second + dy[i]);
				ll a = upl[p.first][p.second][0];
				ll b = upl[p.first][p.second][1];
				if (t.first < 0) t.first += n, ++b;
				else  if (t.first >= n) t.first -= n, --b;
				if (t.second < 0) t.second += m, ++a;
				else if (t.second >= m) t.second -= m, --a;
				if (!vis[t.first][t.second])
				{
					vis[t.first][t.second] = true;
					upl[t.first][t.second][0] = a;
					upl[t.first][t.second][1] = b;
					q.push(t);
				}
				else if (upl[t.first][t.second][0] - 32767 &&
					(upl[t.first][t.second][0] - a ||
						upl[t.first][t.second][1] - b))
					suc = true;
			}
		}
		if (suc) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
```

###### DFS

记录取模与不取模的坐标，如果走到某个点时它们不相等，这个点是第二次经过，则可以走过

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1500 + 1;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int st_x, st_y;
int vis[MAXN][MAXN][3];
bool fl, a[MAXN][MAXN];
char ch;

void dfs(int x, int y, int lx, int ly) {
	if(fl) return;
	if(vis[x][y][0] && (vis[x][y][1]!=lx || vis[x][y][2]!=ly)) {
		fl = 1;
		return;
	}
	vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
	for(int i=0; i<4; ++i) {
		int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
		int lxx = lx + dx[i], lyy = ly + dy[i];
		if(!a[xx][yy]) {
			if(vis[xx][yy][1]!=lxx || vis[xx][yy][2]!=lyy || !vis[xx][yy][0])
				dfs(xx, yy, lxx, lyy);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	while(cin >> n >> m) {
		fl = 0;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j) {
				cin >> ch;
				if(ch == '#') a[i][j] = 1;
				if(ch == 'S') st_x = i, st_y = j;
			}
		dfs(st_x, st_y, st_x, st_y);
		if(fl) puts("Yes");
		else puts("No");
	}
}
```

##### 靶形数独

> 在填数独中添加权重，从外到内共五环，权重从6到10递增；分数为$数字\times权重$，求一个分数最高的数独解，输出分数；若无解输出-1

本题的优化使用dfs的顺序修改，先将情况最少的列解答树。否则TLE。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10
struct node { ll zn, i; } cs[MAXN];
inline bool cmp(const node& x, const node& y) { return x.zn < y.zn; }
inline ll blz(ll& x, ll& y) { return (x - 1) / 3 * 3 + (y - 1) / 3 + 1; }
inline ll sco(ll& x, ll& y) { return 10 - max(5 - min(10 - x, x), 5 - min(10 - y, y)); }
ll a[MAXN][MAXN], row[MAXN][MAXN], col[MAXN][MAXN], blo[MAXN][MAXN], sn;
ll s[101][4], ok, ans = -1, po;//不为-1暴死一个无解
void dfs(ll i, ll mk)
{
	if (i == sn)
	{
		ans = max(ans, mk);
		return;
	}
	repe(c, 1, 9)
	{
		if (!row[s[i][0]][c] && !col[s[i][1]][c] && !blo[s[i][2]][c])
		{
			row[s[i][0]][c] = col[s[i][1]][c] = blo[s[i][2]][c] = 1;
			dfs(i + 1, mk + s[i][3] * c);
			row[s[i][0]][c] = col[s[i][1]][c] = blo[s[i][2]][c] = 0;
		}
	}
}
signed main()
{
	repe(i, 1, 9)
	{
		cs[i].i = i;
		repe(j, 1, 9)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j])
			{
				row[i][a[i][j]] = col[j][a[i][j]] = blo[blz(i, j)][a[i][j]] = 1;
				po += sco(i, j) * a[i][j];
			}
			else ++cs[i].zn;//忘记会暴死
		}
	}
	sort(cs + 1, cs + 10, cmp);
	repe(i, 1, 9)
	{
		repe(j, 1, 9)
		{
			if (!a[cs[i].i][j])
			{
				s[sn][0] = cs[i].i;//用i暴死
				s[sn][1] = j;
				s[sn][2] = blz(cs[i].i, j);
				s[sn++][3] = sco(cs[i].i, j);
			}
		}
	}
	dfs(0, po);
	printf("%d", ans);
	return 0;
}
```

##### 八数码难题

###### 朴素BFS

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
ll dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 }, n, c[3][3];
signed main()
{
	scanf("%lld", &n);
	queue<ll> q; q.push(n);
	map<ll, ll> m; m[n] = 0;
	while (!q.empty())
	{
		ll u = q.front(), f = 0, g = 0, n = u; q.pop();
		if (u == 123804765) break;
		rede(i, 2, 0) rede(j, 2, 0)
		{
			c[i][j] = n % 10, n /= 10;
			if (!c[i][j]) f = i, g = j;
		}
		rep(i, 0, 4)
		{
			ll nx = f + dx[i], ny = g + dy[i], ns = 0;
			if (nx < 0 || ny < 0 || nx>2 || ny>2) continue;
			swap(c[nx][ny], c[f][g]);
			rep(i, 0, 3) rep(j, 0, 3) ns = ns * 10 + c[i][j];
			if (!m.count(ns)) m[ns] = m[u] + 1, q.push(ns);
			swap(c[nx][ny], c[f][g]);
		}
	}
	printf("%lld", m[123804765]);
	return 0;
}
```

###### IDA\*

```c++
//niiick
#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

char ss[15];
int ans[4][4]=
{{0,0,0,0},
 {0,1,2,3},
 {0,8,0,4},
 {0,7,6,5}};
int a[5][5],k,judge;
int nxtx[]={0,1,-1,0};//特殊构造
int nxty[]={1,0,0,-1};//pre+i==3时两两互逆，即pre和i互为相反步

int check()
{
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j])return 0;
    return 1;
}

int test(int step)//预测还要走多少步，启发假设有一个不等就走多一步
{
    int cnt=0;
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=a[i][j]){ if(++cnt+step>k) return 0;}
    return 1;
}

void A_star(int step,int x,int y,int pre)//pre防止下一次走回上一步
{
    if(step==k){ if(check())judge=1; return;}//达到当前限制的最大深度
    if(judge) return;
    for(int i=0;i<4;++i)
    {
        int nx=x+nxtx[i],ny=y+nxty[i];
        if(nx<1||nx>3||ny<1||ny>3||pre+i==3) continue;//加入了上述最优性剪枝
        swap(a[x][y],a[nx][ny]);
        if(test(step)&&!judge) A_star(step+1,nx,ny,i);//A*估价合法再向下搜索
        swap(a[x][y],a[nx][ny]);
    }
}

int main()
{
    int x,y;
    scanf("%s",&ss);
    for(int i=0;i<9;++i)
    {
        a[i/3+1][i%3+1]=ss[i]-'0';
        if(ss[i]-'0'==0)x=i/3+1,y=i%3+1;
    }
    if(check()){printf("0");return 0;}//特判不用移动
    while(++k)//枚举最大深度
    {
        A_star(0,x,y,-1);
        if(judge){printf("%d",k);break;}
    }
    return 0;
}
```

###### 双向BFS

版本1

```c++
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n,g=123804765;
short a[4][4],fx,fy,nx,ny;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; //代表向四个方向移动
queue<int> q;
map<int,int> v;
map<int,int> ans;
void solve()
{
	if(n==g) 		 //特判
    {
        printf("0");
        exit(0);
    }				
    q.push(n);		//起始状态与终止状态同时入队
    q.push(g);
    ans[n]=0;
    ans[g]=1;		
    v[g]=2;			//将两个方向标记成不同的数字
    v[n]=1;
    while(!q.empty())
    {
        ll now,cur=q.front();
        q.pop();
        now=cur;
        for(int i=3;i>=1;i--)
            for(int j=3;j>=1;j--)
            {
                a[i][j]=now%10,now/=10;
                if(a[i][j]==0) fx=i,fy=j;
            }
        for(int i=0;i<4;i++)
        {
            nx=fx+dx[i];
            ny=fy+dy[i];
            if(nx<1 || nx>3 || ny<1 || ny>3) continue;
            swap(a[fx][fy],a[nx][ny]);
            now=0;
            for(int p=1;p<=3;p++)
                for(int j=1;j<=3;j++)
                    now=now*10+a[p][j];	//数字转矩阵
            if(v[now]==v[cur]) 
            {
                swap(a[fx][fy],a[nx][ny]); //一定要先换回来再跳过
                continue;
            }
            if(v[now]+v[cur]==3)		//说明新延伸出的点已被另一方向访问过
            {
                printf("%d",ans[cur]+ans[now]);//两方向步数和即为总步数
                exit(0);
            }
            ans[now]=ans[cur]+1;
            v[now]=v[cur];				//与上一状态的方向保持一致
            q.push(now);
            swap(a[fx][fy],a[nx][ny]); //不要忘记将还回来
        }	
    }
}
int main()
{
    scanf("%d",&n);
    solve();
}
```



版本2

```c++
#include <bits/stdc++.h>

using namespace std;
queue<string> q1;            // 从前开始搜
queue<string> q2;            // 从后开始搜
map<string, int> vis;        // 记录是否被访问过
map<string, int> dis;        // 记录距离
string target = "123804765"; // 记录目标状态
int ans;                     // 记录最终答案
int dir[4] = {-3, 1, 3, -1}; // 分别为上、右、下、左

int find_zero(string str)
{ // 找到字符串中 '0' 所在位置
    int i;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            break;
    }
    return i;
}

bool check(int pos, int t, int i)
{
    if (t >= 0 && t <= 8)
    {
        if (i == 0 || i == 2)
        { // 上下移动，只需要判断是否超过范围即可
            return true;
        }
        else
        { // 左右移动，还需要判断行数是否改变
            if (pos / 3 == t / 3)
                return true;
            else
                return false;
        }
    }
    else
    {
        return false;
    }
}

void double_bfs(string str)
{
    q1.push(str);
    vis[str] = 1;
    dis[str] = 0;
    q2.push(target);
    vis[target] = 2;
    dis[target] = 1;//相当于最终碰面时ans=d1+d2+1的1
    while (!q1.empty() && !q2.empty())
    {
        bool flag;
        string cur;
        if (q1.size() < q2.size())
        {
            cur = q1.front();
            q1.pop();
            flag = true;
        }
        else
        {
            cur = q2.front();
            q2.pop();
            flag = false;
        }
        int pos = find_zero(cur); // 找到 ‘0’ 所在的位置
        for (int i = 0; i < 4; i++)
        {
            string temp = cur;
            int t = pos + dir[i]; // 要改变的位置的下标
            if (check(pos, t, i))
            {
                temp[pos] = temp[t];
                temp[t] = '0';
                if (!vis[temp])
                {
                    vis[temp] = vis[cur];
                    dis[temp] = dis[cur] + 1;
                    flag == true ? q1.push(temp) : q2.push(temp);
                }
                else
                {
                    if (vis[temp] + vis[cur] == 3)
                    {
                        ans = dis[temp] + dis[cur];
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    string str;
    cin >> str;
    double_bfs(str);
    cout << ans << endl;
    return 0;
}
```



版本3

```c++
#include<iostream>
#include<queue>
#define For(i,j) for(register int (i)=0;(i)<(j);++(i))

using std::cin;
using std::cout;
using std::queue;
using std::swap;
using std::endl;

const int mod1=1e5+7,mod2=1e6+9,dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool flag;
int ans;
struct Node
{
	int key,step;
	bool head;
	Node *next;
	Node(){key=step=head=0;next=NULL;}
}hash[mod1+2];
struct CB
{
	int value[3][3],spx,spy,step;
	void init()
	{
		value[0][0]=1;
		value[0][1]=2;
		value[0][2]=3;
		value[1][0]=8;
		value[1][1]=0;
		value[1][2]=4;
		value[2][0]=7;
		value[2][1]=6;
		value[2][2]=5;
		spx=1,spy=1;
	}
	bool operator== (const CB &x) const
	{
		For(i,3)
			For(j,3)
				if(value[i][j]!=x.value[i][j])
					return false;
		return true;
	}
}start,goal;
bool Query(const CB &x,bool head)
{
	int num=0,sum1,sum2;
	For(i,3)
		For(j,3)
			num=num*10+x.value[i][j];
	sum1=num%mod1,sum2=num%mod2;
	if(!hash[sum1].key)
	{
		hash[sum1].key=sum2;
		hash[sum1].head=head;
		hash[sum1].step=x.step;
		return true;
	}
	if(hash[sum1].key==sum2)
	{
		if(head!=hash[sum1].head)
		{
			flag=true;
			ans=x.step+hash[sum1].step;
		}
		return false;
	}
	else
	{
		Node *now=&hash[sum1];
		while(now->next)
		{
			now=now->next;
			if(now->key==sum2)
			{
				if(head!=now->head)
				{
					flag=true;
					ans=now->step+x.step;
				}
				return false;
			}
		}
		Node *newnode=new Node;
		newnode->key=sum2;
		newnode->head=head;
		now->next=newnode;
		return true;
	}
}
void BFS()
{
	queue <CB> q1;
	queue <CB> q2;
	start.step=goal.step=0;
	q1.push(start);
	q2.push(goal);
	while(true)
	{
		if(q1.size()>q2.size())
		{
			CB now=q2.front();
			q2.pop();
			For(i,4)
			{
				int xx=now.spx+dx[i],yy=now.spy+dy[i];
				if(xx<0||xx>2||yy<0||yy>2)
					continue;
				CB wib=now;
				wib.step=now.step+1;
				wib.spx=xx,wib.spy=yy;
				swap(wib.value[xx][yy],wib.value[now.spx][now.spy]);
				if(Query(wib,0))
					q2.push(wib);
				if(flag)
					return;
			}
		}
		else
		{
			CB now=q1.front();
			q1.pop();
			For(i,4)
			{
				int xx=now.spx+dx[i],yy=now.spy+dy[i];
				if(xx<0||xx>2||yy<0||yy>2)
					continue;
				CB wib=now;
				swap(wib.value[xx][yy],wib.value[now.spx][now.spy]);
				wib.spx=xx,wib.spy=yy;
				wib.step=now.step+1;
				if(Query(wib,1))
					q1.push(wib);
				if(flag)
					return;
			}
		}
		if(flag)
			return;
	}
}
int main(int argc,char *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	char ch;
	For(i,3)
		For(j,3)
		{
			cin>>ch;
			if(ch=='0')
				start.spx=i,start.spy=j;
			start.value[i][j]=ch-'0';
		}
	goal.init();
	if(goal==start)
	{
		cout<<0;
		return 0;
	}
	BFS();
	cout<<ans;
	return 0;
}
```

###### 康托展开

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;  //纯属闲得蛋痛
ull end;
int book[3000000];  //判断每一个状态是否出现过，也就是排重（值可以不开这么大）
int v1[4]={0,1,0,-1};  //方向数组，枚举0可以走的四个方向
int v2[4]={1,0,-1,0};
struct node
{
    int x,y,kkk;  //x,y表示0在a数组中的下标,kkk表示当前的步数
    ull hash1;    //康托展开的哈希值
    int a[4][4];  //状态数组
};
node que[2000001]; //结构体
ull hash1(char s[])//康托展开的函数
{
	int f[9]={0,1,2,6,24,120,720,5040,40320}; //先将每一个阶乘的值存下来，方便直接运算
	int book[9]={0}; //判断每一个数是否已经出现
    ull ans=0,x=8;
    for(int i=0;i<strlen(s);i++) //将传来的字符数组遍历一遍
    {
    	int num=0;   //num存储在第i个数前的数的数目
    	book[s[i]-'0']=1; //先标记第s[i]个数已经出现
    	for(int j=0;j<s[i]-'0';j++) //遍历s[i]之前的数
    		if(!book[j])  //如果这个数没出现过，那么num++
				num++;
    	ans+=num*f[x--];  //康托展开的公式，每一项等于这一项数前未出现过的数乘以这个数位数的阶乘
    }
    return ans;  //返回康托展开的值
}
int main()
{
    int head=1,tail=2;
    int i,j,k,n;
    char s[9],ss[9];
    scanf("%s",s);
    end=hash1("123804765");  //首先将目标状态的值存下来
    que[head].kkk=0;  //步数初始化为0
    que[head].hash1=hash1(s);  //将初始状态的哈希值放入hash1
    book[que[head].hash1]=1;  //标记目标状态已经出现
    for(i=1;i<=3;i++)
    	for(j=1;j<=3;j++)
    	{
    		que[head].a[i][j]=s[(i-1)*3+j-1]-'0';
    		if(que[head].a[i][j]==0)
    		{
    			que[head].x=i;
    			que[head].y=j;
    		}
		}//将初始状态存进二维数组，并记录下0的位置
    while(head<=tail) //bfs
    {
        if(que[head].hash1==end) //如果当前状态的值等于目标状态的值，那么就输出步数
        {
            printf("%d",que[head].kkk);
            return 0;
        }
        for(k=0;k<4;k++) //否则，枚举四个方向
        {
        	char ch[9]={0};  //用来转换的字符串
            int tx=que[head].x+v1[k],ty=que[head].y+v2[k];//0移动后的位置
            if(tx<1 || tx>3 || ty<1 || ty>3) continue; //如果移动出了边界，那么这个状态肯定不合法
            for(i=1;i<=3;i++)
            	for(j=1;j<=3;j++)
            		que[tail].a[i][j]=que[head].a[i][j]; 
            swap(que[tail].a[tx][ty],que[tail].a[que[head].x][que[head].y]); //将上一个状态转移过来，再转换位置
            for(i=1;i<=3;i++)
            	for(j=1;j<=3;j++)
            		ch[(i-1)*3+j-1]=que[tail].a[i][j]+'0'; //将二维数组存进字符数组
            ull ans=hash1(ch);  //获取这个二位数组的哈希值（康托展开值）
            if(!book[ans]) //如果这个状态没有出现过，那么将他加入队列
            {
                book[ans]=1; //标记这个状态出现过
                que[tail].hash1=ans;  //记录下它的哈希值
                que[tail].x=tx; que[tail].y=ty;  //存下目前状态0的位置
                que[tail].kkk=que[head].kkk+1; //将步数+1
                tail++;
            }
        }
        head++;  //千万要加上这句话，不然就会死循环
    }
    return 0;
}
```

##### 跳蚂蚱

> (蓝桥)9个盘子围成一圈，把个盘子顺时针装着1~8号蚂蚱，每只蚂蚱可以跳到空盘或越过一个相邻的蚂蚱跳到空盘。如果把队形改成逆时针，空盘位置不变，最少需要多少次跳跃？

###### 朴素BFS

使用unordered\_set判重(set会TLE)，走过的状态不再走。勉强卡住了时间点。(不过原题是填空题，超时了一点常数也无所谓)

```c++
#include <bits/stdc++.h>
using namespace std;
struct state
{
    int s[10];
    int r=0,t;
    inline bool operator==(const state& x)const
    {
        for(int i=0;i<9;++i) if(s[i]!=x.s[i]) return false;
        return true;
    }
    inline int toint()const
    {
        int r=0;
        for(int i=0;i<9;++i) r=r*10+s[i];
        return r;
    }
} sbg,sed;
queue<state> q;
unordered_set<int> m;
signed main()
{
    for(int i=0,j=7;i<8;++i,--j) sbg.s[i]=i+1,sed.s[j]=i+1;
    sbg.t=8,sed.t=8;
    q.push(sbg);
    while(!q.empty())
    {
        state t=q.front(); q.pop();
        int nt=t.toint();
        if(m.find(nt)!=m.end()) continue;
        m.insert(nt);
        if(t==sed) return printf("%d", t.r)&0;
        state p;
        for(int i=0;i<9;++i) p.s[i]=t.s[i];
        p.r=t.r+1;
        for(int d=-2;d<=2;++d)
        {
            if(!d) continue;
            int ad=t.t+d;
            if(ad<0) ad+=9;
            else if(ad>=9) ad-=9;
            swap(p.s[ad],p.s[t.t]);
            p.t=ad;
            q.push(p);
            swap(p.s[ad],p.s[t.t]);
        }
    }
    return 0;
}
```

###### IDA\*

耗时略短于朴素BFS，可以过题。

```c++
#include <bits/stdc++.h>
using namespace std;
struct state
{
    int s[10];
    inline bool operator==(const state& x)const
    {
        for(int i=0;i<9;++i) if(s[i]!=x.s[i]) return false;
        return true;
    }
} sbg,sed;
int k,dpos[]={-2,-1,1,2};
inline bool test(int step)
{
    int cnt=0;
    for(int i=0;i<9;++i) if(sbg.s[i]!=sed.s[i])
        if(++cnt+step>k) return false;
    return true;
}
void a_star(int step, int t, int pre)
{
    if(step==k)
    {
        if(sbg==sed){printf("%d",k); exit(0);}
        return;
    }
    for(int now=0;now<4;++now)
    {
        int mt=t;
        int dt=t+dpos[now];
        if(now+pre==3) continue;
        if(dt<0) dt+=9;
        else if(dt>=9) dt-=9;
        swap(sbg.s[mt],sbg.s[dt]);
        if(test(step)) a_star(step+1,dt,now);
        swap(sbg.s[mt],sbg.s[dt]);
    }
}
signed main()
{
    for(int i=0,j=7;i<8;++i,--j) sbg.s[i]=i+1,sed.s[j]=i+1;
    while(++k) a_star(0,8,-99);
    return 0;
}
```

###### 双向BFS

大大加快速度，从原本朴素的将近1s快了十倍左右。

```c++
#include <bits/stdc++.h>
using namespace std;
struct state
{
    int s[10];
    int r=0,t,v;
    inline bool operator==(const state& x)const
    {
        for(int i=0;i<9;++i) if(s[i]!=x.s[i]) return false;
        return true;
    }
    inline int toint()const
    {
        int r=0;
        for(int i=0;i<9;++i) r=r*10+s[i];
        return r;
    }
} sbg,sed;
queue<state> q;
unordered_map<int,int> m;
unordered_map<int,int> k;
signed main()
{
    for(int i=0,j=7;i<8;++i,--j) sbg.s[i]=i+1,sed.s[j]=i+1;
    sbg.t=8,sed.t=8; sbg.v=1; sed.v=2;
    q.push(sbg); q.push(sed);
    while(!q.empty())
    {
        state t=q.front(); q.pop();
        int nt=t.toint();
        if(m.count(nt))
        {
            if(m[nt]==t.v) continue;
            else return printf("%d",k[nt]+t.r)&0;
        }
        m[nt]=t.v;
        k[nt]=t.r;
        state p;

        for(int i=0;i<9;++i) p.s[i]=t.s[i];
        p.r=t.r+1;
        p.v=t.v;
        for(int d=-2;d<=2;++d)
        {
            if(!d) continue;
            int ad=t.t+d;
            if(ad<0) ad+=9;
            else if(ad>=9) ad-=9;
            swap(p.s[ad],p.s[t.t]);
            p.t=ad;
            q.push(p);
            swap(p.s[ad],p.s[t.t]);
        }
    }
    return 0;
}
```

##### 魔方状态

> (蓝桥)求一个二前面橙色、右面绿色、上面黄色、左面绿色、下面橙色、后面黄色的二阶魔方的状态数。

###### BFS

建模：设每个小立方体六个面(0~6前上右下左后)的颜色存char，然后二阶魔方整体(上层左下开始顺时针0123下层4567)，建模暴力搜素。填空题不限时间。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef char st[8][7];
st state[2000000];
set<string> all;
st begin={{"oybbgb"},{"oygbbb"},{"bygbby"},{"bybbgy"},{"obbogb"},{"obgobb"},{"bbgoby"},{"bbbogy"}}; 
//st begin={{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"}};
//只有一个颜色的魔方 ans=1 
//st begin={{"rykkbk"},{"rygkkk"},{"kygkko"},{"kykkbo"},{"rkkwbk"},{"rkgwkk"},{"kkgwko"},{"kkkwbo"}};
//正常2阶魔方状态  r红 y黄 b蓝 g绿 w白 o橙  k黑(红对橙，白对黄，蓝对绿，颜色相近的相对)这里白为底 前为红
//需要将state大小改为4000000
//这个测试用例跑了20分钟左右 560M内存  ans=3674160 与实际二阶魔方状态数相同 见下截图 
int front, tail;
void ucell(char *a){swap(a[0], a[2]); swap(a[2], a[5]); swap(a[5], a[4]);}
void rcell(char *a){swap(a[1], a[0]); swap(a[0], a[3]); swap(a[3], a[5]);}
void fcell(char *a){swap(a[2], a[1]); swap(a[1], a[4]); swap(a[4], a[3]);}
void u(st &s)//顶层顺时针旋转 
{
	ucell(s[0]);
	ucell(s[1]);
	ucell(s[2]);
	ucell(s[3]);
	swap(s[1], s[0]);
	swap(s[2], s[1]);
	swap(s[3], s[2]);
}
void uwhole(st &s)//整个魔方从顶部看 顺时针转 用于判重 
{
	u(s);
	ucell(s[4]);
	ucell(s[5]);
	ucell(s[6]);
	ucell(s[7]);
	swap(s[5], s[4]);
	swap(s[6], s[5]);
	swap(s[7], s[6]);
}
void f(st &s)//前面一层 顺时针转 
{
	fcell(s[0]);
	fcell(s[1]);
	fcell(s[4]);
	fcell(s[5]);
	swap(s[1], s[5]);
	swap(s[0], s[1]);
	swap(s[4], s[0]);
}
void fwhole(st &s)//整个魔方从前面看 顺时针转 用于判重 
{
	f(s);
	fcell(s[2]);
	fcell(s[6]);
	fcell(s[7]);
	fcell(s[3]);
	swap(s[2], s[6]);
	swap(s[3], s[2]);
	swap(s[7], s[3]);
}
void r(st &s)//魔方右层顺时针转 
{
	rcell(s[1]);
	rcell(s[2]);
	rcell(s[6]);
	rcell(s[5]);
	swap(s[2], s[1]);
	swap(s[5], s[1]);
	swap(s[6], s[5]);
}
void rwhole(st &s)//整个魔方从右边看 顺时针转 用于判重 
{
	r(s);
	rcell(s[0]);
	rcell(s[3]);
	rcell(s[4]);
	rcell(s[7]);
	swap(s[3], s[7]);
	swap(s[0], s[3]);
	swap(s[4], s[0]);
}
string convert(st &s)//魔方状态二维字符数组 转化为string 
{
	string ss;
	for(int i=0; i<8; i++)ss+=s[i];
	return ss;
}
bool try_to_insert(int tail)//判重 
{
	st k;
	memcpy((void*)k, (void*)state[tail], sizeof(state[tail]));
	for(int i=0; i<4; i++)
	{
		fwhole(k);
		for(int j=0; j<4; j++)
		{
			uwhole(k);
			for(int q=0; q<4; q++)
			{
				rwhole(k);
				if(all.count(convert(k))==1)
				{
					return false;
				}
			}
		}
	}
	all.insert(convert(k));
	return true;
}
int main()
{
	front=0,tail=1;
	all.insert(convert(begin));
	memcpy((void*)state[0],(void*)begin,sizeof(begin));
	while(front!=tail)
	{
		//对当前状态分别模拟三种操作U R F 然后判重 
		for(int i=0; i<3; i++)
		{
			memcpy((void*)state[tail], (void*)state[front], sizeof(state[front]));
			if(i==0)
			{
				u(state[tail]);
				if(try_to_insert(tail))tail++;
			}
			else if(i==1)
			{
				r(state[tail]);
				if(try_to_insert(tail))tail++;
			}
			else if(i==2)
			{
				f(state[tail]);
				if(try_to_insert(tail))tail++;
			}
		}
		front++;
	}
	cout<<front<<endl;
	return 0;
}
//ans 229878
```



### 启发式搜索

启发式搜索不保证绝对准确性，建立在其基础之上的A\*和IDA\*也不保证绝对的准确性。因为估价函数的估计值并不一定是答案。

其中IDA\*是每次限定搜索深度(逐次增加)的DFS来模拟BFS。好处是空间开销小。不加A\*的该方法为迭代加深搜索。

#### 例题

##### 机关

> 有12个按钮，有4个状态，每次向一个方向旋转，$1\to2\to3\to4\to1$，当所有旋钮转到1时，打开机关。所有按钮旋转时在第i状态会连带一个旋钮进行旋转，求最少的旋转次数使得旋钮转到1，并输出解开步骤

本题解开步骤不唯一。

启发函数：$operator<$

理想距离length(是当忽略连带旋转时的旋转次数)

step已旋转次数

判断$(1+length)\times(1+step)$，越小则越可能是最优解。(可以调整)

事实上$length\times step$更优。

当length系数越大，越趋向于贪心，step系数越大，越趋向于BFS。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define STPE 12
#define MAXV 16800000
ll a[STPE][4], be[STPE];
bool vis[MAXV];
inline void move(ll* m, ll mot)//模拟一次移动(旋转mot)
{
	if (m[a[mot][m[mot]]] != 3) ++m[a[mot][m[mot]]];
	else m[a[mot][m[mot]]] = 0;
	if (m[mot] != 3) ++m[mot];
	else m[mot] = 0;
}
inline ll cnt(ll* m)//状态vis
{
	ll sum = 0;
	rep(i, 0, STPE) sum = (sum << 2) + m[i];
	return sum;
}
struct node
{
	ll c, m[STPE], l;
	vector<ll> re;
	node() {};
	node(ll* a, node* oth, ll cnta, ll mot);
	node(ll* a, ll cnta);
	bool operator<(const node& oth) const
	{
		return(1 + l) * (re.size() + 1) > (1 + oth.l) * (1 + oth.re.size());
	}
} x;
inline ll cntb(node* no)//理想次数计算
{
	ll t = 0;
	rep(i, 0, STPE) if (no->m[i]) t += 4 - no->m[i];
	return t;
}
node::node(ll* a, node* oth, ll cnta, ll mot)
{
	memcpy(m, a, sizeof m);
	c = cnta;
	re = oth->re;
	re.push_back(mot);
	vis[c] = true;
	l = cntb(this);
}
node::node(ll* a, ll cnta)//初始状态
{
	memcpy(m, a, sizeof m);
	c = cnta;
	vis[c] = true;
	l = cntb(this);
}
inline void f()
{
	priority_queue<node> q;
	q.push(node(be, cnt(be)));
	node temp;
	ll cb, tp[STPE];
	while (!q.empty())
	{
		temp = q.top(); q.pop();
		rep(i, 0, STPE)
		{
			memcpy(tp, temp.m, sizeof tp);//回溯(否则一次走12步)
			move(tp, i);
			cb = cnt(tp);
			if (!vis[cb])
			{
				node tpb(tp, &temp, cb, i);
				q.push(tpb);//未加暴死
				if (vis[0])//全为1，找到了其中一个解
				{
					x = tpb;
					return;
				}
			}
		}
	}
}
signed main()
{
	rep(i, 0, STPE)//写成1暴死
	{
		scanf("%d", &be[i]);
		--be[i];
		rep(j, 0, 4)
		{
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	f();
	printf("%d\n", x.re.size());
	rep(i, 0, x.re.size()) printf("%d ", x.re[i] + 1);
	return 0;
}
```

解法二：双向搜索

### 双向搜索

对BFS而言，将规模$a^n$缩减为$2a^{\frac n2}$

从起点开始和从终点开始的点分别标注为1和2，那么相加为3必然相遇。

while条件为两队列均不为空还是for和dx,dy搜索，

### 折半搜索

对DFS而言，第一次搜索前半部分，第二次搜索后半部分，最后再组合两部分，将搜索的复杂度指数降低一半，并将空间复杂度提升到时间复杂度等同。

#### 例题

##### 世界冰球锦标赛

> 有n场比赛，可用m元，比赛入场需要门票钱x，请问他有多少种参加方案。
>
> $1\le n\le40,1\le m\le10^{18},1\le x\le10^{16}$

由于$2^n$过大不能直接DFS，由于$x$过大不能背包。考虑折半搜索。

第一次搜索前一半比赛并将小于m的全部花费记录。第二次搜索后一半比赛并同样记录，得到的记录数目为$2\times2^{\frac n2}$，时间复杂度也是如此(01背包型搜索)。最后合并，取余额为$m-a_i$，即减去第一次搜索得到的一个花销和，然后在第二次二分搜索(排序后)里寻找大于等于余额的下标，下标即方案数。这里运用了前缀和思维的计数，使用$O(len\log len)$的复杂度完成了合并。总时间时间复杂度为$\Omicron(2^{\frac n2+1}\log2^{\frac n2})=\Omicron(n2^{\frac n2})$，空间复杂度为$\Omicron(2^{\frac n2+1})$，可以通过。

```c++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mn (1<<21)+5
ll n,m,x[62],ac,bc,as[mn],bs[mn],cf,ans;
void dfs(ll lf, ll& rf, ll v, ll& cnt, ll* arr)
{
    if(v>m) return;
    if(lf==rf){arr[cnt++]=v; return;}
    dfs(lf+1,rf,v+x[lf],cnt,arr);
    dfs(lf+1,rf,v,cnt,arr);
}
signed main()
{
    scanf("%lld%lld",&n,&m); cf=n>>1;
    for(int i=0;i<n;++i) scanf("%lld",x+i);
    dfs(0,cf,0,ac,as);
    dfs(cf,n,0,bc,bs);
    sort(bs,bs+bc);
    for(int i=0;i<ac;++i)
        ans+=upper_bound(bs,bs+bc,m-as[i])-bs;
    return printf("%lld",ans),0;
}
```

##### Balanced Cow Subsets G

> 给定n个数x，选出一些数划分为两堆和相等的数，求方案数。($2\le n\le20,1\le x\le10^8$)

显然不会爆int。由于划分的两堆数数目不定，所以需要使用搜索，单纯搜索时，有三种分支，即当前数不加入，当前数放左堆，当前数放又堆，是三进制背包DFS，复杂度为$\Omicron(3^n)$不通过。

考虑折半搜索。并考虑利用状态压缩、vis数组去重和map离散化。第一次搜索前面一半的数，设sum为左堆-右堆的差值，第二次设sum为右堆-左堆的差值，如果第二次的sum等于第一次的，证明合起来之后，这两堆的和相等。最后统计有效状态即可。

时间复杂度为$\Omicron(3^{\frac n2})$，空间复杂度为$\Omicron(2^n)$，空间复杂度来自于状态压缩(选了什么数)。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn (1<<20)+5
int n,half,mc,ans,a[21];
bool memo[mn];
vector<int> d[mn];//有多少种nowstate可以拼出情况mc(mc即nowsum)
map<int,int> m;//m[v]->mc 求和值与情况mc一一对应
void dfs1(int i, int nowsum, int nowstate)
{
    if(i==half)
    {
        if(!m.count(nowsum)) m[nowsum]=++mc;//和为nowsum时对应一个独一无二的mc
        d[m[nowsum]].push_back(nowstate);
        return;
    }
    dfs1(i+1,nowsum,nowstate); //两边都不选
    dfs1(i+1,nowsum+a[i],nowstate|(1<<i)); //左边选了
    dfs1(i+1,nowsum-a[i],nowstate|(1<<i)); //右边选了
}
void dfs2(int i, int nowsum, int nowstate)//这次+ -的意义跟上次相反
{
    if(i==n)
    {
        if(m.count(nowsum))//如果可以拼出nowsum
        {
            int x=m[nowsum];
            for(int i=0,ds=d[x].size();i<ds;++i) memo[d[x][i]|nowstate]=true;//起到了去重
        }
        return;
    }
    dfs2(i+1,nowsum,nowstate);
    dfs2(i+1,nowsum+a[i],nowstate|(1<<i));//位运算(状态压缩)里i从0开始
    dfs2(i+1,nowsum-a[i],nowstate|(1<<i));
}
signed main()
{
    scanf("%d",&n);
    half=n>>1;
    for(int i=0;i<n;++i) scanf("%d",a+i);
    dfs1(0,0,0);
    dfs2(half,0,0);
    for(int i=1,n2=1<<n;i<=n2;++i) ans+=memo[i];
    return printf("%d",ans),0;
}

```



## 数学

### 常用符号

1. $x|y$表示$x$整除$y$，例如$2|8$
2. $x\bot y$表示$x,y$互质
3. $gcd(x,y)=(x,y)$最大公约数
4. $lcn(x,y)=[x,y]$最小公倍数
5. $\lfloor x\rfloor$向下取整
6. $\lceil x\rceil$向上取整
7. $C^m_n=(\matrix{n\\m})=\frac{n!}{m!(n-m)!}$
8. $A_n^m=P_n^m=\frac{n!}{(n-m)!}$

### 高精度运算

~~如果不会导致TLE的话为什么不用python~~

高精度运算不会丢失精度(零误差)的运算。

在整数上：

可以选择普通高精度(每次整除和取模都是按10)和压位高精度(10改成更大的，如1e8)；

存储的基本单元可以是Int(short, long, char, _int32等)，结构体(+位域),string

运算上，可以分为单单运算(得到高，如1/397的49位小数,1e9^1e9)，高单运算，高高运算；

还要处理输入和输出。

在有理数上：

~~略(似乎我没见过这样的题，除了模拟除法的许多位数)~~

#### 加法

```c++
#include <cstdio>//个人版本
#include <cctype>
#define MAXD 505
using namespace std;
int a[MAXD], b[MAXD], ai, bi;
int read(int x[])
{
    char ch;
    int i=0, temp[MAXD];
    while( (ch=getchar()) && isspace(ch) );
    while(1)
    {
        if(isdigit(ch))
        {
            temp[i++] = ch-'0';
        }
        else break;
        ch=getchar();
    }
    for(int j=i-1, k=0;j>=0;j--, k++)
    {
        x[k] = temp[j];
    }
    return i;
}
void print(int x[], int n)
{
    for(int i=n-1; i>=0; i--)
    {
        printf("%d", x[i]);
    }
}
int add(int a[], int b[], int ai, int bi)//a+b and stored in a
{
    int inb=0, i, in;
    for(i=0;i< (bi>ai?bi:ai);i++)
    {
        if(i>=ai) in = 0;
        else in = (a[i] + b[i] + inb) / 10;
        if(i+in+1>= ai) ai=i+in+1;
        a[i] = (a[i] + b[i] + inb) % 10;
        inb = in;
    }
    a[i] += in;
    return ai>bi+in?ai:bi+in;
}
int main()
{
    ai = read(a);
    bi = read(b);
    ai = add(a, b, ai, bi);
    print(a, ai);
    return 0;
}
```

#### 减法

```c++
#include <bits/stdc++.h>//个人版本
#define MAXN 10100
using namespace std;
string a,b,c;
int cmp(string &x, string &y)
{
    int xl=x.size(),yl=y.size();
    if(xl!=yl) return xl-yl;
    for(int i=xl-1;i>=0;i--)
    {
        //cout<<x[i]<<" "<<y[i]<<" "<<(x[i]>y[i])<<endl;
        if(x[i]-y[i]!=0) return x[i]-y[i];
    }
    return 0;
}
void red(string &x, string &y)
{
    int xl=x.size(),yl=y.size(),re,ap=0;
    for(int i=0;i<xl;i++)
    {
        if(i<yl) re=x[i]-ap-y[i];
        else re=x[i]-'0'-ap;
        if(re<0)
        {
            ap=1;
            re=10+re;
        }
        else ap=0;
        //cout<<(int)re<<endl;
        c+='0'+re;
    }
    //c+='\0';
}
int main()
{
    cin>>a>>b;
    bool ad, prez=true,octn;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(cmp(a,b)>=0)
    {
        //cout<<"ff\n";
        red(a,b);
        ad = false;
    }
    else
    {
        red(b,a);
        ad = true;
    }
    //cout<<c<<endl;
    reverse(c.begin(),c.end());
    //cout<<c<<endl;
    if(ad) cout<<'-';
    int cl=c.size();
    for(int i=0;i<cl;i++)
    {
        while(i+1!=cl && prez && c[i]=='0') {i++; continue;}
        prez=false;
        cout<<c[i];
    }
    return 0;
}
```

改进如下：

```c++
 int maxl = max(a.size(), b.size());
 /*
 找到两个数中的最大位，为for循环服务 
 如果两个数位数不相等，相减也无妨，因为位数少的数那部分被0补齐，减下去不影响
 */
 for(int i = 1; i <= maxl; i ++)
 {
 	if(na[i] < nb[i])//减不够
 	{
 		na[i + 1] --;//借位
 		na[i] += 10;//到低位去
 	}
 	ans[i] = na[i] - nb[i];//相减
 }
//以下是输出省略前导0处理
while(ans[maxl] == 0)maxl --;
if(maxl < 1)cout << "0";
```

对于输入存在负数的处理见[here][https://www.luogu.com.cn/blog/stonejuice/gao-jing-du-jian-fa-di-op-xie-fa#]//da ro

#### 乘法

以麦森数例题为例

```c++
#include <bits/stdc++.h>
#define NSIM 502
#define NTEM 1005
using namespace std;
int p, res[NTEM], mer[NTEM], temp[NTEM];
inline void f(int *a)
{
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=500; i++)
    {
        for(int j=1; j<=500; j++)
        {
            temp[i+j-1] += a[i]*mer[j];
        }
    }
    for(int i=1; i<=500; i++)
    {
        temp[i+1] += temp[i]/10;
        temp[i]=temp[i]%10;
    }
    memcpy(a, temp, sizeof(temp));
}
inline void f1()
{
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=500; i++)
    {
        for(int j=1; j<=500; j++)
        {
            temp[i+j-1] += res[i]*mer[j];
        }
    }
    for(int i=1; i<=500; i++)
    {
        temp[i+1] += temp[i]/10;
        temp[i]=temp[i]%10;
    }
    memcpy(res, temp, sizeof(temp));
}
inline void f2()
{
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=500; i++)
    {
        for(int j=1; j<=500; j++)
        {
            temp[i+j-1] += mer[i]*mer[j];
        }
    }
    for(int i=1; i<=500; i++)
    {
        temp[i+1] += temp[i]/10;
        temp[i]=temp[i]%10;
    }
    memcpy(mer, temp, sizeof(temp));
}
int main()
{
    scanf("%d", &p);
    printf("%d\n", (int)(p*log10(2))+1);
    mer[1]=2;
    res[1]=1;
    while(p)
    {
        if(p&1) f1();
        p>>=1;
        f2();
    }
    res[1]--;
    for(int i=500; i>0; i--)
    {
        if(i<=450 && i%50==0) printf("\n");
        printf("%d", res[i]);
    }
    return 0;
}
```

#### 整除

以高精整除单精为例，

```c++
#include<string>
#include<iostream>
using namespace std;
string a,c;
int b,i,d;
int main()
{
    cin>>a>>b;   //神奇的读入
    for (;i<a.length();i++)a[i]-=48;   //字符串转数字
    for (i=0;i<a.length();i++)
        c.push_back((d*10+a[i])/b+48),d=(d*10+a[i])%b;  //模拟竖式
    for (i=0;c[0]==48;i++)c.erase(c.begin(),c.begin()+1);   //去0
    cout<<c;   //华丽的输出
    return 0;     //完美的结束
}
```

##### 例题

###### 整除光棍

> (天梯)给定不以5结尾的小于1000的正奇数x，输出数s和位数n，在n最小的情况下s的意义为n个1组成的n位数除x的余数。

解法一：暴力(从小到大枚举n，判定是否相等)：

```python
x=int(input().strip())
def cal(x):
    n=1
    k=1
    s=0
    while True:
        s=k//x
        if s*x==k:
            break
        k=k*10+1
        n+=1
    return [s,n]
r=cal(x)
print(r[0],r[1])
```

解法二：除法原理

模拟小数除法，但不是不断补0，而是不断补1。

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin>>N;
	long ans=0,cnt=0;
	while (ans<N) {
        ans = ans * 10 + 1; //被除数末位添1, 直到不小于被除数 
        ++cnt;              //位数增加1位 
    }
	while(1){
			int num=ans/N;//求商 
			cout<<num;//输出商 
			ans=ans%N;//求出余数 
			if(ans==0)//此时正好被整除 
				break;
			ans=ans*10+1;
			cnt++;
	}
	cout<<" "<<cnt;
	return 0;
} 
```

错误思维：让x试乘一个数从小到大枚举0~9，知道乘出来的结果尾数为1，不断如此下去。答案并不会是最小的。如果要最小的需要分情况DFS，显然不应该这么做。

#### 开方

> 见算法-数论-约数-例题-矩阵翻硬币

#### 分数

以分式加减为例，以下面程序为例注释中列出注意要点：

```c++
#include <bits/stdc++.h>
#define int long long//不开longlong见祖宗
using namespace std;
struct fra{int a = 0, b = 1;};
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
void simp(fra& x)
{
	int g = gcd(x.a, x.b);
	x.a /= g;
	x.b /= g;
	if (x.a < 0 && x.b < 0) x.a = -x.a, x.b = -x.b;//负数特判
	else if (x.b < 0 && x.a>0) x.a = -x.a, x.b = -x.b;
}
fra operator+(const fra& a, const fra& b)
{
	int ca = a.a * b.b + a.b * b.a, cb = a.b * b.b;
	fra c;//直接fra c={}会因为大括号类型转换的问题死掉
	c.a = ca, c.b = cb;//所以这样做在洛谷才不会CE
	simp(c);
	return c;
}
char c;
bool first = true;//一开始输入负号特判
int temp, neg = 1;
fra ans, nw;
signed main()
{
	while (cin >> c)//其实可以cin>>ll>>/>>ll的，-ll也是ll啊！
	{
		if (isdigit(c))
		{
			first = false;//别忘了读了就不再特判了
			temp = temp * 10 + (c - '0') * neg;//-'0'必须要有
		}
		else
		{
			switch (c)
			{
			case '/':
				nw.a = temp;
				temp = 0;
				neg = 1;//一个符号让否则分子分母都是负数负负得正
				break;
			case '+':
				nw.b = temp;
				ans = ans + nw;
				neg = 1;
				temp = 0;
				break;
			case '-':
				if (first) first = false;//最初特判
				else
				{
					nw.b = temp;
					ans = ans + nw;
				}
				neg = -1;
				temp = 0;
			}
		}
	}
	nw.b = temp;//尾处理
	ans = ans + nw;
	if (ans.b != 1) printf("%lld/%lld", ans.a, ans.b);
	else printf("%lld", ans.a);//不要输出一分之二之类的式子
	return 0;
}
```

#### 尾数

##### 0尾数

若干数连乘，求尾数0的数目，除直接高精度外，更优解为，可以直接计算2因子和5因子的最小值。

```c++
#include <bits/stdc++.h>
int c[7],v;
void acm(int& v, int k) {while(v&&v%k==0) ++c[k],v/=k;}
signed main()
{
    while(EOF!=scanf("%d",&v)) acm(v,2),acm(v,5);
    return printf("%d",std::min(c[2],c[5])),0;
}
```

### 计算几何学

常用平面直角坐标系或极坐标系。

**向量**(Vector)与**点**(Point)可以共用一个结构体，即：

```c++
struct Point{double x,y;};
typedef Point Vector;
```

有时候也用极坐标，即记录极径和极角。

**线段**(Segment)用两点表示，**直线**(Line)与线段可以共用一个结构体(射线不可)。

```c++
struct Segment{Point p1, p2;};
typedef Segment Line;
```

对于直线，还可以直接只存直线上的一点和直线的方向向量。对于线段，大多数问题不会在极坐标系中考虑。

**圆**(Circle)可以表示为圆心和半径的结构体或类。

```c++
class Circle
{
    public:
    Point c;
    double r;
    Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};
```

**多边形**(Polygon)可以用点的序列表示。

```c++
typedef vector<Point> Polygon;
```

> Rad_to_deg常量45.0/atan(1.0)约为57.2957795130823

如果矩形各边与坐标轴平行，一般只记录左下角和右上角。

#### 向量

基本运算为求和(sum)，作差(difference)，标量乘法(scalar multipilication)，取绝对值(absolute)，取范数(norm,即x\^2+y\^2)，内积(dot product，点乘)，外积(cross product，叉乘)。

```c++
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)
class Point
{
    public:
    double x,y;
    Point(double x=0, double y=0):x(x),y(y){}
    Point operator + (Point P){return Point(x+p.x,y+p.y);}
    Point operator - (Point P){return Point(x-p.x,y-+p.y);}
    Point operator * (double a){return Point(x*a,y*a);}
    Point operator / (double a){return Point(x/a,y/a);}
    double abs() {return sqrt(norm());}
    double norm() {return x*x+y*y;}
    bool operator < (const Point &p) const 
    {return x!=p.x?x<p.x:y<p.y;}
    bool operator == (const Point &p) const 
    {return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;}
    double dot(Point a, Point b)
    {return a.x*b.x+a.y*b.y;}
    double cross(Point a, Point b)
    {return a.x*b.y-a.y*b.x;}
};
typedef Point Vector;
```

平行(Parallel)

```c++
bool isParallel(Vector a, Vector)
{return equals(cross(a,b),0.0);}
bool isParallel(Point a1,Point a2,Point b1,Point b2)
{return isParallel(a1-a2,b1-b2);}
bool isParallel(Segment s1, Segment s2)
{return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);}
```

正交(Orthogonal)

```c++
bool isOrthogonal(Vector a, Vector b)
{return equals(dot(a,b),0.0);}
bool isOrthogonal(Point a1,Point a2,Point b1,Point b2)
{return isOrthogonal(a1-a2,b1-b2);}
bool isOrthogonal(Segment s1, Segment s2)
{return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);}
```

**投影**(Project)

```c++
Point project(Segment s, Point p)//p在s的投影
{
    Vector base = s.p2 - s.p1;//直线法向量
    double r = dot(p - s.p1, base) / norm(base);
    //r是点1到投影点长度与直线长度的比值
    return s.p1 + base * r;
}
```

**映像**(Reflection)

```c++
Point reflection(Segment s, Point P)
{
    return p + (project(s,p)-p)*2.0;
}
```

#### 极坐标

```c++
double arg(Vector p) {return atan2(p.y,p.x);}
Vector polar(double a, double r)
{return Point(cos(r)*a,sin(r)*a);}
```

#### 包含

##### PIP问题

point in polygon。点是否在多边形内。

###### 光线投射算法

ray casting algorithm

先特判一些特殊情况，比如这个点离多边形太远了。考虑一个能够完全覆盖该多边形的最小矩形，如果这个点不在这个矩形范围内，那么这个点一定不在多边形内。这样的矩形很好求，只需要知道多边形横坐标与纵坐标的最小值和最大值，坐标两两组合成四个点，就是这个矩形的四个顶点了。

考虑以该点为端点引出一条射线，如果这条射线与多边形有奇数个交点，则该点在多边形内部，否则该点在多边形外部，我们简记为 奇内偶外。这个算法同样被称为奇偶规则 (Even-odd rule)。

可以随机取这条射线所在直线的斜率，建议为无理数以避免出现射线与多边形某边重合的情况。

###### 回转数算法

winding number algorithm

回转数是数学上的概念，是平面内闭合曲线逆时针绕过该点的总次数。很容易发现，当回转数等于 0的时候，点在曲线外部。这个算法同样被称为非零规则 (Nonzero-rule)。

我们把该点与多边形的所有顶点连接起来，计算相邻两边夹角的和。注意这里的夹角是 有方向的。如果夹角和为 0，则这个点在多边形外，否则在多边形内

#### 距离

两点距离

```c++
double getDistance(Point a, Point b)
{return abs(a-b);}
```

点与直线距离(外积除边长等于高)

```c++
double getDistanceLP(Line l, Point p)
{return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));}
```

> 判断点在直线的哪边：
>
> 设直线上一点$P$，方向向量$\vec v$，若点$Q$有$\vec{PQ}\times\vec c<0$，在直线上方，否则在直线下方

点与线段距离

```c++
double getDistanceSP(Segment a, Point p)
{
    if(dot(s.p2-s.p1,p-s.p1)<0.0) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0) return abs(p-s.p2);
    return getDistanceLP(s,p);
}
```

线段间距离

```c++
double getDistance(Segment s1, Segment s2)
{
    if(intersect(s1,s2)) return 0.0;//相交
    return min(min(getDistanceSP(s1,s2.p1),
                  getDistanceSP(s1,s2.p2)),
              	  getDistanceSP(s2,s1.p1),
                  getDistanceSP(s2,s1.p2)))
}
```

#### 相交

对于三个点p0,p1,p2，对于以下五种情况，分别代表：

- COUNTER_CLOCKWISE 1   p0,1,2成逆时针方向
- CLOCKWISE -1    p0,1,2顺时针
- ONLINE_BACK 2   p2,0,1依次在一条直线
- ONLINE_FRONT -2   p0,1,2依次在同一直线上
- ON_SEGMENT 0    p2在线段p0p1上

```c++
static const int COUNTER_CLOCKWISE=1;
static const int CLOCKWISE=-1;
static const int ONLINE_BACK=2;
static const int ONLINE_FRONT=-2;
static const int ON_SEGMENT=0;
int ccw(Point p0, Point p1, Point p2)
{
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS) return CLOCKWISE;
    if(dot(a,b)<-EPS) return ONLINE_BACK;
    if(a.norm()<b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}
```

##### 判断线段相交

###### 快速排斥实验

未通过快速排斥实验是无交点的充分不必要条件

- 若平行不相交
- 判断是否三点共线，解决若重合/部分重合问题/交点为一条线段的交点
- 设一条线段的区域是以线段为对角线，各边均与坐标轴平行的矩形的面积，判断两线段是否没有公共区域

###### 跨立实验

如果相交，那么一条线段的两个交点一定在另一条线段的两侧。我们可以直接判断一条线段的两个端点相对于另一线段所在直线的位置关系，如果不同，则两线段相交，反之则不相交。

###### 确定解

```c++
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    return(ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}
```

##### 线段交点

```c++
Point getCrossPoint(Segment s1, Segment s2)
{
    Vector base = s2.p2-s2.p1;
    double d1 = abs(cross(base,s1.p1-s2.p1));
    double d2 = abs(cross(base,s1.p2-s2.p1));
    double t = d1/(d1+d2);
    return s1.p1 + (s1.p2-s1.p1) * t;
}
```

##### 圆和直线交点

```c++
pair<Point,Point> getCrossPoints(Circle c,Line l)
{
    //assert(interact(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1) / abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}
```

##### 圆和圆的交点

```c++
pair<Point, Point> getCrossPoints(Circle c1,Circle c2)
{
    //assert(interact(c1,c2));
    double d = abs(c1.c - c2.c);
    double a = acos(c1.r*c1.r + d*d - c2.r*c2.r)/(2*c1.r*d);
    double t = arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),
                    c1.c+polar(c1.r,t-a));
}
```

##### 直线交点数

> 给定n条直线，无三点共线，求相交交点数的情况数

###### dfs

个人做法

按照平行组拆分直线，如4条直线，可以分成若干组组内平行组外互相1相交的直线：4; 3,1; 2,2; 2,1,1; 1,1,1,1
对于每种情况，交点数为：$4\times0,3\times1,2\times2,2\times1+2\times1+1\times1,(1\times1)\times6$，取集合，得5

故数的拆分，然后两两相乘和的取集合即可

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 27
ll a[MAXN], n;
unordered_set<ll> ans;
void dfs(ll h, ll lf)
{
	if (lf <= 0)
	{
		if (!lf)
		{
			ll temp = 0;
			repe(i, 1, h - 1)
				repe(j, i + 1, h - 1) temp += a[i] * a[j];
			ans.insert(temp);
		}
		return;
	}
	repe(i, a[h - 1], lf)
	{
		a[h] = i;
		dfs(h + 1, lf - i);
	}
}
signed main()
{
	scanf("%d", &n);
	a[0] = 1;
	dfs(1, n);
	printf("%d", ans.size());
	return 0;
}
```

###### 数位递归

```c++
#include<bits/stdc++.h>
using namespace std;
int n,ans=0;bool f[901];
void suv(int p,int m){
        if(p==0) {if(!f[m]) ans++; f[m]=1;}//大括号必须要
        else for(int r=p;r>=1;r--) suv(p-r,r*(p-r)+m);
}
int main(){
    cin>>n;suv(n,0);cout<<ans;
}
```

##### 例题

###### 平面切分

> (蓝桥)给定$n$直线$y=a_ix+b_i$，它们将平面分成了几部分($1\le n\le10^3$)

一条直线两部分，新的直线必然会带来一部分，每多一个交点又多一部分。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define st first
#define nd second
typedef double db;
ll n,m,r=2,l;
typedef pair<ll,ll> po;
typedef pair<db,db> ro;
po a[1002],t;
set<po> s;
signed main()
{
    scanf("%lld",&n);
    repe(i,1,n) scanf("%lld%lld",&t.st,&t.nd),s.insert(t);
    for(set<po>::iterator it=s.begin();it!=s.end();++it) a[++m]=*it;
    repe(i,2,m)
    {
        set<ro> p;
        repe(j,1,i-1)
        {
            ll ax=a[i].st,ay=a[i].nd,bx=a[j].st,by=a[j].nd;
            if(ax==bx) continue;
            db cx=1.*(by-ay)/(ax-bx);
            p.insert({cx,cx*ax+ay});
        }
        r+=p.size()+1;
    }
    return printf("%lld",r),0;
}
```



###### 平面分割

> (蓝桥)20个圆和20条直线最多把平面分割为多少个部分

每加一个圆，这个圆与其他$n-1$个圆均交于两点，交点加$2(n-1)$个，因为每个圆有$2(n-1)$个交点，则也有$2(n-1)$个线段，共有$2n(n-1)$个线段。而交点共有$n(n-1)$个。因为前者每次累加量等于末量，后者等于增量。

根据欧拉公式：
$$
V-E+F=2
$$

$$
F=2-V+E=2-m(m-1)+2m(m-1)=m^2-m+2
$$

或者，在上一个图上，每增加一个圆弧，即每增加一条边，增加两个区域。而每次增加的边数等于增加的点数，所以增量是$2(n-1)$，初始值为2，求和得$n^2-n+2$。

引入直线，第一条直线最多与每个圆交于2点，显然在原有基础上，增加了$2n$个区域，画图可以知道。而每增加一条直线，同样可以在圆上增加$2n$个区域，在直线上增加$m$个区域，求和得：

m条直线和n个圆，有：
$$
n^2+\frac12m^2+2mn-n+\frac12m+1
$$
答案为1391。

#### 变换

##### 坐标旋转

> 未经检验，慎用

将一个点$(x,y)$从原坐标轴变换到一个新坐标轴(其$x$轴相对于原$x$轴的斜率为$k$，且相对于原坐标轴的坐标原点是$(x_0,y_0)$)得到的新坐标$(x',y')$计算公式为：
$$
x'=\frac{(x-x_0)-k(y-y_0)}{\sqrt{k^2+1}}\\
y'=\frac{(y-y_0)-k(x-x_0)}{\sqrt{k^2+1}}
$$
若$k$不存在，$(x,y)$互换再平移即可。

推导：在上式中，
$$
\cos\theta=\frac1{\sqrt{k^2+1}},\sin\theta=\frac k{\sqrt{k^2+1}}
$$
而转轴公式为：
$$
\begin{cases}
x=x'\cos\theta-y'\sin\theta\\
y=x'\sin\theta+y'\cos\theta
\end{cases}\Rightarrow
\begin{cases}
x'=x\cos\theta+y\sin\theta\\
y'=-x\sin\theta+y\cos\theta
\end{cases}
$$

#### 面积

##### 多边形面积

将多边形上点逆时针标记为$p_1,\dots,p_n$，任选辅助点$O$,设$\vec{v_i}=p_i-O$，则面积为：
$$
S=\frac12|\sum_{i=1}^n\vec{v_i}\times\vec{v_i}\mod n+1|
$$

##### 矩形覆盖和

> 求若干个第一象限内与坐标轴平行的矩形($0\le x,y\le10^8$)的面积和(重复部分只算一个)

使用扫描线做法，定义竖边(x,y1,y2,d)，其中d=1是左边界，d=-1是右边界

将竖边按x升序排序，然后遍历扫描。

定义d数组(代码中没有)，d[i]代表yi被覆盖的次数，每个小竖矩形的面积为：
$$
(x_{now}-x_{past})\times\sum_i(d_i\ge1)
$$
将d数组离散化，并转化为线段树并维护。qy为所有出现过y坐标。h的下标为离散化后的y值。h[i]表示该y值对应的qy的下标。所以向线段树执行区间增加操作时，是执行下标到下标的增加。v数组对应的是离散点。//da r wri

时间复杂度为$\Omicron(n\log n)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 2008
struct node
{
	ll x, y0, y1, c;
} a[MAXN];
inline bool cmp(const node& x, const node& y) { return x.x < y.x; }
unordered_map<ll, ll> h;
ll n, m, qy[MAXN], ax, ay, bx, by;
long long ans;
struct segtr
{
#define lfi (i<<1)
#define rfi (i<<1|1)
	ll l[MAXN << 2], r[MAXN << 2], v[MAXN << 2], len[MAXN << 2];
	void init(ll i, ll lf, ll rf)
	{
		l[i] = lf, r[i] = rf, v[i] = len[i] = 0;
		if (lf != rf)
		{
			ll cf = lf + rf >> 1;
			init(lfi, lf, cf), init(rfi, cf + 1, rf);
		}
	}
	void add(ll i, ll lf, ll rf, ll c)
	{
		if (rf < l[i] || r[i] < lf) return;
		if (lf <= l[i] && r[i] <= rf) v[i] += c;
		else add(lfi, lf, rf, c), add(rfi, lf, rf, c);
		if (v[i]) len[i] = qy[r[i] + 1] - qy[l[i]];
		else len[i] = len[lfi] + len[rfi];
	}
} seg;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n)
	{
		scanf("%d%d%d%d", &ax, &by, &bx, &ay);//不同题目可能不一样,a左下b右上
		a[i] = { ax,ay,by,1 };
		a[i + n] = { bx,ay,by,-1 };
		qy[++m] = ay, qy[++m] = by;
	}
	sort(qy + 1, qy + 1 + m);
	m = unique(qy + 1, qy + 1 + m) - qy - 1;
	repe(i, 1, m) h[qy[i]] = i;
	seg.init(1, 1, (n <<= 1));
	sort(a + 1, a + 1 + n, cmp);
	repe(i, 1, n)
	{
		seg.add(1, h[a[i].y0], h[a[i].y1] - 1, a[i].c);
		ans += (long long)seg.len[1] * (a[i + 1].x - a[i].x);
	}
	printf("%lld", ans);
	return 0;
}
```

以上代码的注意要点：

- 建议全部改成long long，以防不过题
- 建议数组长度开到题目的大约1.5倍或更高，以防不过题(因为基本都是二倍n长度的变量)，即便考虑到了，事实上可能开大了就过题了……
- qy数组的下标必须从1开始，而a没有特别要求
- 主处理的repe(即最后一个)改成上限为n-1也可以过题

此写法可能出现的写bugs：

- 存qy写成了存qx
- 线段树的add的两个if范围都没写对：第一个写成了lf跟l比，rf跟r比，第二个不等号反掉了
- 线段树中len的处理不要+=，但c的处理不能不要+=
- 各种诡异的重名，如c和ci，lf和l
- len的else处理把lfi和rfi写成lf和rf
- 线段树长度没有开四倍长
- 没有进行映射改变处理或映射改变出错

写法2

```c++
//  code for P5490
//  代码没有挖坑
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define lson (x << 1)
#define rson (x << 1 | 1)
using namespace std;
const int MAXN = 1e6 + 10;
typedef long long ll;

int n, cnt = 0;
ll x1, y1, x2, y2, X[MAXN << 1];

struct ScanLine {
	ll l, r, h;
	int mark;
//  mark用于保存权值 (1 / -1)
	bool operator < (const ScanLine &rhs) const {
		return h < rhs.h;
	}
} line[MAXN << 1];

struct SegTree {
	int l, r, sum;
	ll len;
//  sum: 被完全覆盖的次数；
//  len: 区间内被截的长度。
} tree[MAXN << 2];

void build_tree(int x, int l, int r) {
//  我觉得最不容易写错的一种建树方法
	tree[x].l = l, tree[x].r = r;
	tree[x].len = 0;
	tree[x].sum = 0;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build_tree(lson, l, mid);
	build_tree(rson, mid + 1, r);
	return;
}

void pushup(int x) {
	int l = tree[x].l, r = tree[x].r;
	if(tree[x].sum /* 也就是说被覆盖过 */ )
		tree[x].len = X[r + 1] - X[l];
//      更新长度        
	else
		tree[x].len = tree[lson].len + tree[rson].len;
//      合并儿子信息
}

void edit_tree(int x, ll L, ll R, int c) {
	int l = tree[x].l, r = tree[x].r;
//  注意，l、r和L、R的意义完全不同
//  l、r表示这个节点管辖的下标范围
//  而L、R则表示需要修改的真实区间
	if(X[r + 1] <= L || R <= X[l])
		return;
//  这里加等号的原因：
//  假设现在考虑 [2,5], [5,8] 两条线段，要修改 [1,5] 区间的sum
//  很明显，虽然5在这个区间内，[5,8] 却并不是我们希望修改的线段
//  所以总结一下，就加上了等号
	if(L <= X[l] && X[r + 1] <= R) {
		tree[x].sum += c;
		pushup(x);
		return;
	}
	edit_tree(lson, L, R, c);
	edit_tree(rson, L, R, c);
	pushup(x);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lli %lli %lli %lli", &x1, &y1, &x2, &y2);
		X[2 * i - 1] = x1, X[2 * i] = x2;
		line[2 * i - 1] = (ScanLine) {x1, x2, y1, 1};
		line[2 * i] = (ScanLine) {x1, x2, y2, -1};
//      一条线段含两个端点，一个矩形的上下边都需要扫描线扫过
	}
	n <<= 1;
//  直接把 n <<= 1 方便操作
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	int tot = unique(X + 1, X + n + 1) - X - 1;
//  去重最简单的方法：使用unique！（在<algorithm>库中）
	build_tree(1, 1, tot - 1);
//  为什么是 tot - 1 ：
//  因为右端点的对应关系已经被篡改了嘛…
//  [1, tot - 1]描述的就是[X[1], X[tot]]
	ll ans = 0;
	for(int i = 1; i < n /* 最后一条边是不用管的 */ ; i++) {
		edit_tree(1, line[i].l, line[i].r, line[i].mark);
//      先把扫描线信息导入线段树
		ans += tree[1].len * (line[i + 1].h - line[i].h);
//      然后统计面积
	}
	printf("%lld", ans);
	return 0;
}
```

##### 奇偶覆盖和

> (蓝桥 奇偶覆盖)平面内平行$n(1\le n\le10^5)$与坐标轴的矩形，两对角坐标为$(l,b),(r,t),0\le l\le r\le b\le t\le10^9$，求被这些矩形覆盖了奇数次和偶数次的点的面积

```c++
#include <bits/stdc++.h>
#define IO (ios::sync_with_stdio(false), cin.tie(0), cout.tie(0))
#define INF 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vs vector<int>
#define pk push_back
#define vss vector<vector<int> >
#define sz(x) (int)(x).size()
#define mk(a, b) make_pair(a, b)
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define rep(a, b, c) for(register int a = b; a <= c; ++ a)
#define per(a, b, c) for(register int a = b; a >= c; -- a)
using namespace std;

const int N = 1e5 + 5;

int n, m, T;
int alls[N << 1];

struct Segment
{
	int x, y1, y2;
	int k;
	bool operator< (const Segment &q) const {
		return x < q.x;
	}
} seg[N << 1];

struct Node 
{
	int l, r;
	int cnt;
	int len1, len2;
}tr[N << 4];

template<class T>
inline void read(T &x)
{
	x = 0; T f = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	x *= f; 
}

template<class T>
inline void write(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int get(int x)
{
	return lower_bound(alls, alls + m, x) - alls;
}

void build(int u, int l, int r)
{
	tr[u] = {l, r};
	if(l >= r) return;
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

void pushup(int u)
{
	if(tr[u].cnt)
	{
		if(tr[u].cnt & 1)
		{
			tr[u].len1 = tr[u << 1].len2 + tr[u << 1 | 1].len2;
			tr[u].len2 = tr[u << 1].len1 + tr[u << 1 | 1].len1;
			tr[u].len1 += alls[tr[u].r + 1] - alls[tr[u].l] - tr[u].len1 - tr[u].len2;
		}
		else
		{
			tr[u].len2 = tr[u << 1].len2 + tr[u << 1 | 1].len2;
			tr[u].len1 = tr[u << 1].len1 + tr[u << 1 | 1].len1;
			tr[u].len2 += alls[tr[u].r + 1] - alls[tr[u].l] - tr[u].len1 - tr[u].len2;
		}
	}
	else if(tr[u].l != tr[u].r)
	{
		tr[u].len1 = tr[u << 1].len1 + tr[u << 1 | 1].len1;
		tr[u].len2 = tr[u << 1].len2 + tr[u << 1 | 1].len2;
	}
	else tr[u].len1 = tr[u].len2 = 0;
}

void modify(int u, int l, int r, int k)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].cnt += k;
		pushup(u);
		return;
	}
	
	int mid = tr[u].l + tr[u].r >> 1;
	if(l <= mid) modify(u << 1, l, r, k);
	if(r > mid) modify(u << 1 | 1, l, r, k);
	pushup(u);
}

int main()
{
	
	scanf("%d", &n);
	
	m = 0;
	for(int i = 0; i < n; i ++ )
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		alls[m] = y1; seg[m ++ ] = {x1, y1, y2, 1};
		alls[m] = y2; seg[m ++ ] = {x2, y1, y2, -1};
	}
	
	sort(seg, seg + m);
	
	sort(alls, alls + m);
	m = unique(alls, alls + m) - alls;
	
	build(1, 0, m - 2);
	
	ll res1 = 0, res2 = 0;
	for(int i = 0; i < n << 1; i ++ )
	{
		if(i)
		{
			res1 += tr[1].len1 * 1ll * (seg[i].x - seg[i - 1].x);
			res2 += tr[1].len2 * 1ll * (seg[i].x - seg[i - 1].x);
		}
		modify(1, get(seg[i].y1), get(seg[i].y2) - 1, seg[i].k);
	}
	
	printf("%lld\n%lld\n", res1, res2);

	return 0;
}
```



##### 三角形覆盖和

```c++
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 105

const double eps=1e-12;
const double inf=1e9;
int dcmp(double x)
{
    if (x<=eps&&x>=-eps) return 0;
    return (x>0)?1:-1;
}
struct Vector
{
    double x,y;
    Vector(double X=0,double Y=0)
    {
        x=X,y=Y;
    }
    bool operator < (const Vector &a) const
    {
        return x<a.x||(x==a.x&&y<a.y);
    }
    void read(){scanf("%lf%lf",&x,&y);}
};
typedef Vector Point;
struct Line
{
    Point p,q;
    Line(Point P=Point(0,0),Point Q=Point(0,0))
    {
        p=P,q=Q;
    }
};
Vector operator + (Vector a,Vector b) {return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Vector a,Vector b) {return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double b) {return Vector(a.x*b,a.y*b);}

int n,LSH;
double ans;
double lsh[N*N*10];
Point seg[N];
Line line[N][3];

double Cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
bool ins(Point A,Point B,Point C,Point D)
{
    Vector v,w,u;
    v=A-C,w=C-D,u=B-D;
    if (dcmp(Cross(v,w))==dcmp(Cross(u,w))) return 0;
    v=C-A,w=B-A,u=D-A;
    if (dcmp(Cross(v,w))==dcmp(Cross(u,w))) return 0;
    return 1;
}
Point GLI(Point P,Vector v,Point Q,Vector w)
{
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
double Plus(double x)
{
    int cnt=0;
    for (int i=1;i<=n;++i)
    {
        if (dcmp(line[i][1].p.x-line[i][1].q.x)==0&&dcmp(x==line[i][1].p.x))
            continue;
        double Min=inf,Max=-inf;
        for (int j=1;j<=3;++j)
        {
            if (x<line[i][j].p.x||x>line[i][j].q.x) continue;
            if (dcmp(line[i][j].p.x-line[i][j].q.x)==0) continue;
            Point P=GLI(line[i][j].p,line[i][j].q-line[i][j].p,Point(x,-inf),Vector(0,inf));
            Min=min(Min,P.y),Max=max(Max,P.y);
        }
        if (Max-Min>eps) seg[++cnt]=Point(Min,Max);
    }
    sort(seg+1,seg+cnt+1);
    if (!cnt) return 0.0;
    double l=seg[1].x,r=seg[1].y,sum=0.0;
    for (int i=2;i<=cnt;++i)
    {
        if (seg[i].x-r>eps) sum+=r-l,l=seg[i].x,r=seg[i].y;
        else r=max(r,seg[i].y);
    }
    sum+=r-l;
    return sum;
}
double Minus(double x)
{
    int cnt=0;
    for (int i=1;i<=n;++i)
    {
        if (dcmp(line[i][2].p.x-line[i][2].q.x)==0&&dcmp(x==line[i][2].p.x))
            continue;
        double Min=inf,Max=-inf;
        for (int j=1;j<=3;++j)
        {
            if (x<line[i][j].p.x||x>line[i][j].q.x) continue;
            if (dcmp(line[i][j].p.x-line[i][j].q.x)==0) continue;
            Point P=GLI(line[i][j].p,line[i][j].q-line[i][j].p,Point(x,-inf),Vector(0,inf));
            Min=min(Min,P.y),Max=max(Max,P.y);
        }
        if (Max-Min>eps) seg[++cnt]=Point(Min,Max);
    }
    sort(seg+1,seg+cnt+1);
    if (!cnt) return 0.0;
    double l=seg[1].x,r=seg[1].y,sum=0.0;
    for (int i=2;i<=cnt;++i)
    {
        if (seg[i].x-r>eps) sum+=r-l,l=seg[i].x,r=seg[i].y;
        else r=max(r,seg[i].y);
    }
    sum+=r-l;
    return sum;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        Point A,B,C;A.read(),B.read(),C.read();
        if (A.x>B.x) swap(A.x,B.x),swap(A.y,B.y);
        if (B.x>C.x) swap(B.x,C.x),swap(B.y,C.y);
        if (A.x>B.x) swap(A.x,B.x),swap(A.y,B.y);
        lsh[++LSH]=A.x,lsh[++LSH]=B.x,lsh[++LSH]=C.x;
        line[i][1]=Line(A,B),line[i][2]=Line(B,C);line[i][3]=Line(A,C);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=3;++j)
            for (int k=i+1;k<=n;++k)
                for (int l=1;l<=3;++l)
                {
                    Point A=line[i][j].p,B=line[i][j].q,C=line[k][l].p,D=line[k][l].q;
                    if (ins(A,B,C,D))
                    {
                        Point q=GLI(A,B-A,C,D-C);
                        lsh[++LSH]=q.x;
                    }
                }
    sort(lsh+1,lsh+LSH+1);LSH=unique(lsh+1,lsh+LSH+1)-lsh-1;
    double last=0.0,now;
    for (int i=1;i<=LSH;++i)
    {
        now=Plus(lsh[i]);
        if (i>1) ans+=(now+last)*(lsh[i]-lsh[i-1])/2.0;
        last=Minus(lsh[i]);
    }
    printf("%.2lf\n",ans-eps);
}
```

##### 近似求法

对于若干多边形、含曲边的几何图形(圆、椭圆等)的面积交并等的计算，常常使用近似法。

###### 蒙特卡罗法

在一个区域内使用大量随机点(在不超时的情况下越多越好)进行碰撞，然后检测是否符合要求，最后计算符合要求的点占总点数的比值。

优化方法：

1. 矩形区域越小越好(与边界相切)
2. 可以使用坐标轴变换(如含圆锥曲线的题目)

###### 微分法

在总面积比较小时，可以让一个点代表一个小面积，然后在这个区域内枚举所有的点。计算符合条件的点有多少个。

###### 判断点在面的内部

判断一个点在一个平面几何体的内部：

1. 圆/圆锥曲线：根据定义判断即可。

2. 三角形：
   $$
   S_\Delta\ge S_1+S_2+S_3\\
   S=\frac12\vec a\times\vec b
   $$

3. 



###### (例题)荒岛探测

> (蓝桥)有一个三角形荒岛和两个探测器(不一定在岛上)，有效探测范围是距离这两个探测器的距离和小于$L$的区域。求有效探测范围。(结果保留两位小数，所有坐标绝对值小于$10^3$)

> 在prev-66评测中，法1全WA，法2除第一点AC、第二点WA外，全TLE

**法1：蒙特卡罗法**

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Ve{
public:double xp,yp;
public:Ve(double x,double y):xp(x),yp(y){}
double cP(const Ve ve){
    return fabs(xp*ve.yp-yp*ve.xp);}};
int jud1(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y){
    Ve v1=Ve(x1-x,y1-y);
    Ve v2=Ve(x2-x,y2-y);
    Ve v3=Ve(x3-x,y3-y);
    Ve v4=Ve(x2-x1,y2-y1);
    Ve v5=Ve(x3-x1,y3-y1);
    return (fabs(v4.cP(v5)-v1.cP(v2)-v2.cP(v3)-v3.cP(v1))<1e-6);}
int jud2(double L,double c,double x,double y){
    double dis=sqrt((x-c)*(x-c)+y*y)+sqrt((x+c)*(x+c)+y*y);
    return (dis<=L);}
int main(){
    double xA,yA,xB,yB,L,x1,y1,x2,y2,x3,y3;
    double nx1,ny1,nx2,ny2,nx3,ny3;
    cin>>xA>>yA>>xB>>yB>>L; 
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double c=sqrt((xA-xB)*(xA-xB)+(yA-yB)*(yA-yB))/2;
    double a=L/2;
    double b=sqrt(a*a-c*c);
    double x0=(xA+xB)/2,y0=(yA+yB)/2;
    if(xA==xB){
        nx1=y1,nx2=y2,nx3=y3,ny1=x1,ny2=x2,ny3=x3;
    }else{
        double k=(yB-yA)/(xB-xA);
        nx1=(x1+k*y1-x0-k*y0)/sqrt(k*k+1);
        ny1=(k*x1-y1+yA-k*xA)/sqrt(k*k+1);
        nx2=(x2+k*y2-x0-k*y0)/sqrt(k*k+1);
        ny2=(k*x2-y2+yA-k*xA)/sqrt(k*k+1);
        nx3=(x3+k*y3-x0-k*y0)/sqrt(k*k+1);
        ny3=(k*x3-y3+yA-k*xA)/sqrt(k*k+1);}
    double xmax=max(a,max(nx1,max(nx2,nx3)));
    double xmin=min(-a,min(nx1,min(nx2,nx3)));
    double ymax=max(b,max(ny1,max(ny2, ny3)));
    double ymin=min(-b,min(ny1,min(ny2, ny3)));
    int cnt=0;
    for(int i=0;i<3580000;i++){
        double x=rand()*(xmax-xmin)/RAND_MAX+xmin;
        double y=rand()*(ymax-ymin)/RAND_MAX+ymin;
        if(jud1(nx1,ny1,nx2,ny2,nx3,ny3,x,y)&&jud2(L,c,x,y))cnt++;}
    printf("%.2lf\n",cnt*(xmax-xmin)*(ymax-ymin)/3580000);
    return 0;}
```

**法2：微分法**

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int x1, y01, x2, y2, x3, y3, xA, yA, xB, yB, L;

//求直线方程
double fxy(int a,int b ,double x)
{
    int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
        switch (a)
        {
        case 1:X1 = x1; Y1 = y01; break;
        case 2:X1 = x2; Y1 = y2; break;
        case 3:X1 = x3; Y1 = y3; break;
        default:X1 = xA; Y1 = yA;
        }
        switch (b)
        {
        case 1:X2 = x1; Y2 = y01; break;
        case 2:X2 = x2; Y2 = y2; break;
        case 3:X2 = x3; Y2 = y3; break;
        default:X2 = xB; Y2 = yB;
        }
        return double(Y2 - Y1) / (X2 - X1)*(x - X1) + Y1;
}

//在三角形岛内
bool island(double x,double y)
{
    return ((fxy(1, 2, x) - y)*(fxy(1, 3, x) - y) <= 0) + ((fxy(1, 2, x) - y)*(fxy(2, 3, x) - y) <= 0) + ((fxy(1, 3, x) - y)*(fxy(2, 3, x) - y) <= 0)>=2;
}

//在椭圆内
bool ellipse(double x,double y)
{
    return sqrt((x - xA)*(x - xA) + (y - yA)*(y - yA)) + sqrt((x - xB)*(x - xB) + (y - yB)*(y - yB)) <= L;
}

int main()
{
    cin >> xA >> yA >> xB >> yB >> L;
    cin >> x1 >> y01 >> x2 >> y2 >> x3 >> y3;
    double x, y, cx, cy, S = 0;
    cx = (xA + xB) / 2.0;
    cy = (yA + yB) / 2.0;
    for (x = cx - L/2.0; x <= cx + L/2.0; x += 0.02)
        for (y = cy-L/2.0; y<=cy+L/2.0; y += 0.005)
            if (island(x, y)&& ellipse(x, y))
                S += 0.0001;
    printf("%.2f", S + 0.005);
    return 0;
}
```

#### 周长

##### 周长覆盖和

> poj 1177

###### 朴素

```c++
#include <vector>
#include <iostream>
#include <algorithm>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010, INF = 0x3f3f3f3f;

int n;
struct Rec
{
    PII a, b;
} rec[N];

LL get()
{
    // 找出所有 x 坐标
    vector<int> xs;
    for (int i = 0; i < n; i ++ )
    {
        xs.emplace_back(rec[i].a.F);
        xs.emplace_back(rec[i].b.F);
    }
    sort(xs.begin(), xs.end());
    LL res = 0;
    for (int i = 0; i < xs.size() - 1; i ++ )
    {
        // [l, r] 为 x 轴分割出来的区间
        int l = xs[i], r = xs[i + 1];
        // 在 y 轴上找出所有出现的矩形的竖边
        vector<PII> seg;
        for (int j = 0; j < n; j ++ )
        {
            if (rec[j].a.F <= l && rec[j].b.F >= r)
                seg.emplace_back(rec[j].a.S, rec[j].b.S);
        }
        // 区间合并问题，求区间数
        sort(seg.begin(), seg.end());
        int cnt = 0, L = -INF, R = -INF;
        for (auto [x, y] : seg)
            if (x > R)
            {
                cnt ++ ;
                L = x, R = y;
            }
            else R = max(R, y);
        res += 2LL * cnt * (r - l);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        PII a, b;
        cin >> a.F >> a.S >> b.F >> b.S;
        rec[i] = {a, b};
    }
    LL res = get();
    // 将横纵坐标交换
    for (int i = 0; i < n; i ++ )
    {
        swap(rec[i].a.F, rec[i].a.S);
        swap(rec[i].b.F, rec[i].b.S);
    }
    res += get();
    cout << res << '\n';
    return 0;
}
```

可能的bugs：

- get里不写vector写数组，然后长度不记得是2n，然后第一层for开了n
- xs存了第一个点的x,y而不是两个点的x
- 没有排序seg或排序有误(如果存了下标排序不能直接sort)

###### 线段树优化

个人版代码：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 10002
typedef long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
ll n,ax,ay,bx,by,tot,x[mn],res,bfl;
struct scanline
{
    ll l,r,h,m;
    inline bool operator<(const scanline& x)
    {
        if(x.h==h) return m>x.m;
        return h<x.h;
    }
} sc[mn];
struct segment_tree
{
    ll len,l,r,c,s;
    bool lc,rc;
} t[mn<<2];
#define lp p<<1
#define rp p<<1|1
void build(ll p, ll lf, ll rf)
{
    t[p].l=lf,t[p].r=rf;
    if(lf==rf) return;
    ll cf=lf+rf>>1;
    build(lp,lf,cf); build(rp,cf+1,rf);
}
void pushup(ll p)
{
    ll l=t[p].l,r=t[p].r;
    if(t[p].s)
    {
        t[p].len=x[r+1]-x[l];
        t[p].lc=t[p].rc=true;
        t[p].c=1;
    }
    else
    {
        t[p].len=t[lp].len+t[rp].len;
        t[p].lc=t[lp].lc,t[p].rc=t[rp].rc;
        t[p].c=t[lp].c+t[rp].c;
        if(t[lp].rc&&t[rp].lc) t[p].c-=1;
    }
}
void add(ll p, ll lf, ll rf, ll c)
{
    ll lt=x[t[p].l],rt=x[t[p].r+1];
    if(lt>=rf||rt<=lf) return;
    if(lt>=lf&&rt<=rf)
    {
        t[p].s+=c;
        pushup(p);
        return;
    }
    add(lp,lf,rf,c);
    add(rp,lf,rf,c);
    pushup(p);
}
signed main()
{
    scanf("%lld",&n);
    repe(i,1,n)
    {
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        sc[(i<<1)-1]={ax,bx,ay,1};
        sc[i<<1]={ax,bx,by,-1};
        x[(i<<1)-1]=ax,x[i<<1]=bx;
    } n<<=1;
    sort(sc+1,sc+1+n);
    sort(x+1,x+1+n);
    tot=unique(x+1,x+1+n)-x-1;
    build(1,1,tot-1);
    rep(i,1,n)
    {
        add(1,sc[i].l,sc[i].r,sc[i].m);
        res+=abs(bfl-t[1].len),bfl=t[1].len;
        res+=2*t[1].c*(sc[i+1].h-sc[i].h);
    }
    return printf("%lld",res+sc[n].r-sc[n].l),0;
}
```

可能犯的bugs：

- 还是把xs插入了ax,ay而不是ax,bx
- 排序函数可能有问题，比如y拿了别的，然后不是判第二依据是c，先后顺序有问题等
- 线段树又忘记了开四倍长度
- add的范围有误，比如因为搞混了lt,rt的含义然后写反了不等号，比如lt和rt根本就算错了
- pushup函数，对else分支的每个地方都有可能出问题，比如lc,rc是lfi的lc和rfi的rc，不是i的lc和rc，也不是c和c；c是lfi的c加rfi的c，不是lc和rc，if特判里注意lfi和rc是相反的之类的。以及if分支里没有用x数组直接r+1-l之类的

版本2：

```c++
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define lson (x << 1)
#define rson (x << 1 | 1)
using namespace std;
const int MAXN = 2e4;
int n, X[MAXN << 1];
int x1, y1, x2, y2, pre = 0; /* 先初始化为 0 */

struct ScanLine {
	int l, r, h, mark;
	if(h == rhs.h)
		return mark > rhs.mark;
    return h < rhs.h;
//		注意！这里是后来被 hack 掉以后加上去的
//		在此感谢 @leprechaun_kdl 指出问题
//		如果出现了两条高度相同的扫描线，也就是两矩形相邻
//		那么需要先扫底边再扫顶边，否则就会多算这条边
//		这个对面积并无影响但对周长并有影响
//		hack 数据：2 0 0 4 4 0 4 4 8 输出应为：24
} line[MAXN];

struct SegTree {
	int l, r, sum, len, c;
//  c表示区间线段条数
    bool lc, rc;
//  lc, rc分别表示左、右端点是否被覆盖
//  统计线段条数(tree[x].c)会用到
} tree[MAXN << 2];

void build_tree(int x, int l, int r) {
	tree[x].l = l, tree[x].r = r;
	tree[x].lc = tree[x].rc = false;
	tree[x].sum = tree[x].len = 0;
	tree[x].c = 0;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build_tree(lson, l, mid);
	build_tree(rson, mid + 1, r);
}

void pushup(int x) {
	int l = tree[x].l, r = tree[x].r;
	if(tree[x].sum) {
		tree[x].len = X[r + 1] - X[l];
		tree[x].lc = tree[x].rc = true;
		tree[x].c = 1;
//      做好相应的标记
	}
	else {
		tree[x].len = tree[lson].len + tree[rson].len;
		tree[x].lc = tree[lson].lc, tree[x].rc = tree[rson].rc;
		tree[x].c = tree[lson].c + tree[rson].c;
//      如果左儿子左端点被覆盖，那么自己的左端点也肯定被覆盖；右儿子同理
		if(tree[lson].rc && tree[rson].lc)
			tree[x].c -= 1;
//      如果做儿子右端点和右儿子左端点都被覆盖，
//      那么中间就是连续的一段，所以要 -= 1
	}
}

void edit_tree(int x, int L, int R, int c) {
	int l = tree[x].l, r = tree[x].r;
	if(X[l] >= R || X[r + 1] <= L)
		return;
	if(L <= X[l] && X[r + 1] <= R) {
		tree[x].sum += c;
		pushup(x);
		return;
	}
	edit_tree(lson, L, R, c);
	edit_tree(rson, L, R, c);
	pushup(x);
}

ScanLine make_line(int l, int r, int h, int mark) {
	ScanLine res;
	res.l = l, res.r = r,
	res.h = h, res.mark = mark;
	return res;
}
//  POJ 不这样做就会CE，很难受

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		line[i * 2 - 1] = make_line(x1, x2, y1, 1);
		line[i * 2] = make_line(x1, x2, y2, -1);
		X[i * 2 - 1] = x1, X[i * 2] = x2;
	}
	n <<= 1;
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	int tot = unique(X + 1, X + n + 1) - X - 1;
	build_tree(1, 1, tot - 1);
	int res = 0;
	for(int i = 1; i < n; i++) {
		edit_tree(1, line[i].l, line[i].r, line[i].mark);
		res += abs(pre - tree[1].len);
		pre = tree[1].len;
//      统计横边
		res += 2 * tree[1].c * (line[i + 1].h - line[i].h);
//      统计纵边
	}
	res += line[n].r - line[n].l;
//  特判一下枚举不到的最后一条扫描线
	printf("%d", res);
	return 0;
}
```

#### 凸包

覆盖平面上n个点的最小凸多边形。

##### 实现

###### 斜率逼近法

时间复杂度$\Omicron(nm)$,n为所有点数，m为在凸包上的点数。无法求解存在任一直线斜率趋于无穷的情况。

> 从y值最小的点出发，设k=0，逆时针寻找k最小的点，如果多个点符合，取最远的，然后再从这个找到的点出发，不断循环此步骤，直到围成闭包(循环了n次)。

###### Jarvis算法

时间复杂度$\Omicron(nm)$，最坏情况为$\Omicron(n^2)$

首先找一条直线过其中一点A，使得其他点都在该直线的同侧。该直线必然存在，且该点必然在凸包上。然后让该直线以A为轴沿固定方向旋转，直到与任何一点相交，如果同时与多个点相交，取最远。重复以上操作，直到循环了n次。所有被碰到的点组成了平面凸包。

###### Graham算法

Graham扫描算法维护一个**凸壳**(凸包的一部分)，通过不断在**凸壳**中加入新的点和去除影响凸性的点 最后形成**凸包**。

取y值最小(y同x小)的点$p_1$(原点)，剩余的点按极角($0\sim\pi$)大小逆时针排序，枚举每一个点，依次连线(栈实现)，如果即将入栈的元素与栈顶两个元素所构成了一个类似于凹壳的东西，那么显然处于顶点的那个点一定不在这个点集的凸包上，而他正好在栈顶，所以把它弹出栈，新点入栈。

时间复杂度为点排序复杂度，为$\Omicron(n\log n)$

###### Andrew算法

按x坐标从小到大排序，从第一个点开始遍历，如果下一个点在栈顶两元素所连成直线的左边，入栈；否则，出栈直到新点在栈顶两个点所在的直线的左边为止。遍历完全部的点，必然只有一个凸壳。之后再反向遍历(除起始点外在凸包上的点无需遍历)，时间复杂度同样$\Omicron(n\log n)$

```c++
double Cross(vec A, vec B)
{
    return A.x*B.y-A.y*B.x; //A->B左转为正 
}
double Side(vec a, vec b, vec p) //次栈顶元素a，栈顶元素b，新增点p 
{
    vec A=vec(b.x-a.x,b.y-a.y); //向量ab
    vec B=vec(p.x-a.x,p.y-a.y); //向量ap
    return Cross(A,B);
}
int Andrew(int top)
{
    sort(p+1,p+n+1);
    if(n<3) 
	{
        printf("-1\n");
        return;
    }
    st[0]=p[1],st[1]=p[2];
    top=1;
    for (int i=3;i<=n;i++)//从p1开始的下凸包 
	{
        while(top&&Side(st[top-1],st[top],p[i])<=0)
            top--;
        st[++top]=p[i];
    }
    st[++top]=p[n-1];
    for(int i=n-2;i>=1;i--)//从pn开始的上凸包 
	{
        while(top&&Side(st[top-1],st[top],p[i])<=0)
            top--;
        st[++top]=p[i];
    }
    return top;
}
```

##### 例题

###### 圈奶牛

> 有n个奶牛，求最小围栏周长

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
ll n, cnt = 1;
db ans;
struct ben { db x, y; } p[MAXN], s[MAXN];
inline db ck(ben a1, ben a2, ben b1, ben b2)
{
	return(a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}
inline db d(ben p1, ben p2)
{
	return sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}
inline bool cmp(ben p1, ben p2)
{
	double tmp = ck(p[1], p1, p[1], p2);
	if (tmp > 0)
		return 1;
	if (tmp == 0 && d(p[0], p1) < d(p[0], p2))
		return 1;
	return 0;
}
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n)
	{
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (i != 1 && p[i].y < p[1].y) swap(p[1], p[i]);
	}
	sort(p + 2, p + n + 1, cmp);
	s[1] = p[1];
	repe(i, 2, n)
	{
		while (cnt > 1 && ck(s[cnt - 1], s[cnt], s[cnt], p[i]) <= 0)--cnt;
		s[++cnt] = p[i];
	}
	s[cnt + 1] = p[1];
	repe(i, 1, cnt) ans += d(s[i], s[i + 1]);
	printf("%.2lf", ans);
	return 0;
}
```

###### U型锁

> (oj)有n个钉子，两钉子间可以形成函数$y=x^2+bx+c$，要求所有钉子都在选中的函数的下方(或上面)，求有多少个有效的函数。$1\le n\le10^3$

本题模拟也能过，$\Omicron(n^3)$。但正解$\Omicron(n\log n)$是求凸包。经过坐标轴变换：$y'=y-x^2$，这样原来的二次函数就变成了直线形式的一次函数，原来的问题就变成了典型的求上凸包问题了。

```c++
#include<bits/stdc++.h>
using namespace std;

struct Po
{
    long long x,y;
    Po()
    {

    }
    Po(long long xx,long long yy)
    {
        x=xx;
        y=yy;
    }
    bool operator <(const Po& po)
    {
        if(x==po.x)
        {
            return y>po.y;
        }
        else return x<po.x;
    }
    Po operator -(const Po& a)
    {
        return Po(x-a.x,y-a.y);
    }
    long long operator *(const Po& a)
    {
        return x*a.y-y*a.x;
    }
};
int main()
{
    int n;
    cin>>n;
    long long x,y;
    Po po[1005];
    Po sta[1005];
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        po[i]=Po(x,y-x*x);//对y坐标进行处理
    }
    //以下就是求上凸包的方法
    sort(po,po+n);
    int tot=0;
    for(int i=0;i<n;i++)
    {
        if(i>0&&po[i].x!=po[i-1].x||i==0)//避免x坐标相同的情况
        {
            while(tot>1&&Po(sta[tot-1]-sta[tot-2])*Po(po[i]-sta[tot-2])>=0)
            {
                tot--;
            }
            sta[tot++]=po[i];
        }
    }
    cout<<tot-1;
    return 0;
}
```

#### 例题

##### 正方形计数

> 平面上$n(1\le n\le500)$个不重复的整点$x,y(-50\le x,y\le50)$，求它们可以构成多少个正方形。

用$\Omicron(n^2)$枚举对角线(而不是枚举边)，枚举$A$,$C$：

计算出正方形$\square ABCD$中心$P(\frac{X_C+X_C}2,\frac{Y_C+Y_C}2)$，然后作两条垂直坐标轴的直线与领边$AB,BC$交于$E,F$，得到两个三角形$\Delta PAE$,$\Delta PBF$，根据$45^o$角$\ang PAE$,$\ang PBF$相等，对角线和垂线夹角$\ang APE$,$\ang BPF$相等，且对角线边$PA,PB$相等得到$\Delta PAE\cong\Delta PBF$，延长$PE,PF$与$A,B$分别垂直相交于$G,H$，则$AG$,$BH$是两三角形以$PE,PF$为底的高，它们相等。即：$AG=BH$，根据$A,P$已知，可以计算出$BH$，从而计算出$B$的一个坐标；同理可以计算出$B$的另一个坐标，$D$的坐标。如果$B,D$在点集里，那么正方形计数$+1$。注意同一个正方形会被两条对角线枚举到，所以答案需要除以$2$。

```c++
#define mm 512
ll n,p[mm][mm],ax[mm],ay[mm],r,cfx,cfy,cx1,cx2,cy1,cy2;
signed main()
{
    n=read();
    rep(i,0,n)
    {//正数下标坐标变换，同时避免中点小数运算
        ax[i]=(read()+50)*2,ay[i]=(read()+50)*2;
        p[ax[i]][ay[i]]=true;
    }
    rep(i,0,n) rep(j,i+1,n)
    {
        cfx=(ax[i]+ax[j])/2,cfy=(ay[i]+ay[j])/2;
        cx1=cfx+(cfy-ay[i]),cy1=cfy-(cfx-ax[i]);
        cx2=cfx+(cfy-ay[j]),cy2=cfy-(cfx-ax[j]);
  if(cx1<0||cy1<0||cx2<0||cy2<0||cx1>=mm||cy1>=mm||cx2>=mm||cy2>=mm) continue;
        if(p[cx1][cy1]&&p[cx2][cy2]) ++r;
    }
    return printf("%lld",r/2),0;
}
```





不要进行任何开根计算，以免损失精度。

##### 分巧克力

> 有n块$h\times w$巧克力平分给k个人，巧克力可以切成相同整数长的正方形(多余部分舍去)，求每个人最多可以分到边长多大的巧克力。
> $1\le n,k,h_i,w_i\le10^5$

显然用二分答案法，关键在于判断函数如何写，如果模拟切分的话显然耗时过高。根据计数原理，$h\times w$矩形可以分割为边长为$i$的正方形，个数为：$\lfloor\frac hi\rfloor\times\lfloor\frac wi\rfloor$，因此代码为：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
int n,k,lf=1,rf,cf,h[mn],w[mn],ans,r;
inline bool ck(int cf)
{
	r=0;
	for(int i=1;i<=n;++i) r+=(h[i]/cf)*(w[i]/cf);
	return r>=k;
}
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d%d",h+i,w+i),rf=max(rf,max(h[i],w[i]));
	while(lf<=rf)
	{
		cf=lf+rf>>1;
		if(ck(cf)) ans=cf,lf=cf+1;
		else rf=cf-1;
	}
	printf("%d",ans);
	return 0;
} 
```

##### 内包

点跟多边形有三种关系，在内(内包)，在上，在外。输入n，输入n个点坐标构成多边形；输入m，输入m个点，对于上述情况分别输出2,1,0。3<=n<=100,1<=q<=1000,-10000<=各点坐标值<=10000，多边形各顶点坐标各不相同，多边形只在公共端点处相交。

只要检查p为端点且平行于x轴的射线跟多边形的相交次数，就可以判断是否内包。如果两端都相交奇数次则内包。判断射线跟线段是否相交可以通过外积正负。外积为正(逆时针)且两端点位于射线两侧，即相交。

是否位于多边形上，可以通过检查p与相邻两端点的向量(p为起点)是否在同一直线且方向相反（相同是可以内包的）。

```c++
int contains(Polygon g, Point p)
{
    int n = g.size();
    bool x = false;
    for(int i=0;i<n;i++)
    {
        Point a = g[i] - p, b = g[(i+1)%n]-p;
        if(abs(cross(a,b))<EPS&&dot(a,b)<EPS)
            return 1;
        if(a.y<b.y) swap(a,b);
        if(a.y<EPS && EPS<b.y && cross(a,b)>EPS)
            x=!x;
    }
    return (x?2:0);
}
```

##### 凸包

Convex Hull,指包含点集合P中所有点的最小凸多边形。

安德鲁(Andrew's Algorithm)算法：复杂度O(nlogn)

- 点按x升序排列，x同按y
- 创建凸包上部：排序后按x从小到大加入凸包U，若新点使U不是凸多边形，逆序删除加入的点直到为凸多边形。
- 创建凸包下部：x反序加入，其他同理。

```c++
Polygon andrewScan(Polygon s)
{
    Polygon u,l;
    if(s.size()<3) return s;
    sort(s.begin(),s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);
    for(int i=2;i<s.size();i++)
    {
        for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i]) != CLOCKWISE;n--))
            u.pop_back();
        u.push_back(s[i]);
    }
    for(int i=s.size()-3;i>=0;i--)
    {
        for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i]) != CLOCKWISE;n--)
            l.pop_back();
        l.push_back(s[i]);
    }
    reverse(l.begin(),l.end());
    for(int i=u.size()-2;i>=l;i--)
        l.push_back(u[i]);
    return l;
}
```

##### 曼哈顿几何

与轴平行的线段相交问题即曼哈顿几何可以通过平面扫描方法求解。

```c++
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3
class EndPoint()
{
    public:
    Point P;
    int seg, st;//ID，种类
    EndPoint() {}
    EndPoint() {Point p, int seg, int st} : p(p), seg(seg), st(st) {}
    bool operator < (const EndPoint &ep) const 
    {//y同时，按1下，左，右，上顺序排列端点
        if(p.y == ep.p.y) return st < ep.st;
        else return p.y < ep.p.y;
    }
}
EndPoint EP(2*MAXSEG);
int manhattanIntersection(vector<Segment> S)
{
    int n = S.size();
    for(int i=0,k=0;i<n;i++)
    {
        if(S[i].p1.y==S[i].p2.y) 
        	if(S[i].p1.x>S[i].p2.x) 
            	swap(S[i].p1,S[i].p2);
        else if(S[i].p1.y>S[i].p2.y)
            swap(S[i].p1,S[i].p2);
        if(S[i].p1.y==S[i].p2.y)
        {
            EP[k++] = Endpoint(S[i].p1,i,LEFT);
            EP[k++] = Endpoint(S[i].p2,i,RIGHT);
        }
        else
        {
            EP[k++] = Endpoint(S[i].p1,i,BOTTOM);
            EP[k++] = Endpoint(S[i].p2,i,TOP);
        }
    }
    sort(EP,EP+(2*n));
    set<int> BT;//二叉搜索树
    BT.insert(1000000001);//设置标记
    int cnt=0;
    for(int i=0;i<2*n;i++)
    {
        if(EP[i].st == TOP)
        BT.erase(EP[i].p.x);
        else if(EP[i].st==BOTTOM)
            BT.insert(EP[i].p.x);
        else if(EP[i].st==LEFT)
        {
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);//O(logn)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);//O(logn)
            cnt += distance(b,e);
        }
    }
    return cnt;
}
```

##### 其他

平面n个点求最近两个的距离：分治法

凸多边形直径：最远顶点对举例，旋转卡壳算法

给定直线切割凸多边形：ccw或直线交点检测

### 组合数学

#### 情况计算

##### 组合

$C^m_n=(\matrix{n\\m})=\frac{n!}{m!(n-m)!}$

```c
long long C(int n, int m)
{
    if(m < n-m) m = n-m;//组合的性质
    long long ans = 1;
    for(int i = m + 1; i <= n; i++) ans *= i;
    for(int i = 1; i <= n-m; i++) ans /= i;
    return ans;
}
```

###### 杨辉三角

用于求一个范围的排列组合

朴素杨辉三角
$$
C_n^r=C_{n-1}^{r-1}+C_{n-1}^r
$$

```c++
C[0][1] = 1;//eid压位写法，C[i][j-1] = C(uf j)(df i)
for (int i = 1; i <= n; ++i)
{
    for (int j = 1; j <= i + 1; ++j)
    {
        C[i & 1][j] = C[(i - 1) & 1][j - 1] + C[(i - 1) & 1][j];
    }
}
```

改良杨辉三角

$C^r_n=\frac{n-r+1}{r}C^{r-1}_n$ 且 $C^r_n=C^{n-r}_n$

```c++
pc[0]=pc[n-1]=1; //杨辉三角性质,两边都是1
    if (n>1)
        for (int i=1;i*2<n;i++)
            pc[i]=pc[n-1-i]=(n-i)*pc[i-1]/i; 
```

###### 预处理

直接使用公式计算：
$$
C^m_n=(\matrix{n\\m})=\frac{n!}{m!(n-m)!}
$$
$\Omicron(n)$预处理出所有连续阶乘和阶乘逆元，然后可以以$\Omicron(1)$计算一个组合数。

(模板例题)给定$n(1\le n\le10^5)$组询问，计算$C_a^b\mod10^9+7, 1\le b\le a\le10^5$。

> 注：若$1\le b\le a\le10^3$，可以直接预处理杨辉三角。

```c++
ll qpow(ll a, ll b)
{
    ll r=1;
    for(;b;b>>=1,(a*=a)%=mod) if(b&1) (r*=a)%=mod;
    return r;
}
ll inv(ll a) {return qpow(a,mod-2);}
#define sc(x) scanf("%lld",&x)
ll a,b,r=1,n,f[mn],fi[mn];
signed main()
{
    sc(n); f[0]=fi[0]=f[1]=fi[1]=1;
    for(int i=2;i<=100001;++i)
    {
        (f[i]=i*f[i-1])%=mod;
        fi[i]=inv(f[i]);
    }
    while(n--)
    {
        sc(b); sc(a);
        printf("%lld\n",  f[b]*fi[a]%mod*fi[b-a]%mod);
    }
    return 0;
}
```



##### 排列

显然有公式：
$$
A_m^n=\frac{m!}{(m-n)!}\\
A_m^n=\prod_{i=m-n+1}^mi
$$
显然通过公式二，更小的运算量，更不可能溢出，且可以避免取模的逆元。

#### 组合

```python
#自己的算法
def catch(e):#列出组合：eC2
    y=[]
    for i in range(len(e)):
        for j in range(i+1,len(e)):
            y.append([e[i],e[j]])
    return y
def combine(e, t=2):#列出组合：eCt
    y=[]
    if t<=0:
        return []
    elif t==1:#防止错误输入；另，t>len(e)会根据运算直接返回[]
        return [[i] for i in e]
    elif t==2:#输入combine(e,2)等于直接使用catch(2)
        return catch(e)
    elif t==3:#多次动态catch运算
        for i in range(len(e)-2):
            y+=[[e[i]]+j for j in catch(e[i+1:])]
        return y
    else:#多次动态尾递归运算
        for i in range(len(e)-t+1):
            y+=[[e[i]]+j for j in combine(e[i+1:],t-1)]
        return y
```

```c++
//算法2 更优
#include<bits/stdc++.h>
using namespace std;
int r,a[100],n;
void dfs(int k){//搜索第k个数
    int i;
    if(k>r){
        for(i=1;i<=r;i++){
            cout<<setw(3)<<a[i];//输出，场宽为三
        }
        cout<<endl;
        return ;//回到前一层
    }
    for(i=a[k-1]+1;i<=n;i++){
        a[k]=i;
        dfs(k+1);//直接进行下一次调用
    }
}
int main()
{
    cin>>n>>r;
    dfs(1);
    return 0;
}
```

##### 例题

> 求乱序序列1~n，使如下操作至只剩一个数r时，r=sum，合并a[i]与a[i+1]为a[i]。若无解，不输出。

```c++
#include <cstdio>
using namespace std;

int n,sum;
//以下所有数组的大小都比所需值稍大，是为了防止越界
int visited[25]={0}; //防止重复选数，这是 dfs 枚举排列的要点
int ans[25]; //放置答案
int pc[25];//构造所有i C n-1

int dfs(int i,int num,int v); //写函数原型是（我的）好习惯！

int main(void){
    scanf("%d%d",&n,&sum);
    //下面构造杨辉三角(即组合数表)
    pc[0]=pc[n-1]=1; //杨辉三角性质,两边都是1
    if (n>1)
        for (int i=1;i*2<n;i++)
            pc[i]=pc[n-1-i]=(n-i)*pc[i-1]/i; //利用杨辉三角对称性和组合数公式计算
    //下面枚举计算
    if (dfs(0,0,0)) //0 仅起占位符作用
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]); //输出答案
    return 0;
}

int dfs(int i,int num,int v){
//参数说明：i 表示已经枚举了前 i 个数(数的序号从 1 开始),num 表示第 i 个数是 num，v 表示前 i 个数的“和”为 v
//返回值说明:返回 0 表示不行(不可能)，返回 1 表示找到了可行解。利用返回值就可以在找到第一个解后直接返回了
    if (v>sum) //“剪枝”，及时排除不可能情况，加速枚举
        return 0; //不可能
    if (i==n){ //已经枚举了前 n 个（全部）,判断一下是否是可行解
        if (v==sum){
            ans[i]=num; //放置解
            return 1;
        }
        else
            return 0;
    }
    visited[num]=1; //标记一下“第 i 个数的值已经使用过了”
    //下面寻找第 i+1 个数
    for (int j=1;j<=n;j++){
        if (!visited[j] && dfs(i+1,j,v+pc[i]*j)){ //v+pc[i]*j表示前(i+1)个数的“和”
            //注意，如果数的序号从 1 开始，那么第 i 个数的系数实际上是 (i-1) C (n-1)
            //执行到这里表示已经找到了可行的解
            ans[i]=num;
            return 1;
        }
    }
    visited[num]=0; //如果没有找到，一定记得复位，为进一步的寻找做准备
    return 0; //执行到这里一定是没有找到解
}
```

#### 排列

#### 容斥原理

$$
|\bigcup_{i=1}^nS_i|=\sum_{m=1}^n(-1)^{m-1}\sum_{a_i<a_{i+1}}|\bigcap_{i=1}^mS_{a_i}|
$$

##### 例题

###### 简单的RC签到题

> (oj)给定素数 a,b,c,d，求 1 到 n中的整数中至少能整除这 4个元素中的一个的数有几个？$1\le n,a\cdot b\cdot c\cdot d\le10^{18}$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld",&x)
ll a,b,c,d,r,n;
signed main()
{
    sc(n),sc(a),sc(b),sc(c),sc(d);
    r=n/a+n/b+n/c+n/d;
    r-=n/a/b+n/a/c+n/a/d+n/b/c+n/b/d+n/c/d;
    r+=n/a/b/c+n/a/b/d+n/a/c/d+n/b/c/d;
    r-=n/a/b/c/d;
    printf("%lld",r);
    return 0;
}
```

###### 还是简单的RC签到题

> (oj)求区间$[l,r]$中与$n$互质的数个数，$1\le l\le r\le10^9,1\le n\le10^9$

将$n$质因数分解，然后用各个不同的质因数做容斥即可。有DFS和二进制枚举两种方法。

DFS(个人解法)：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re register
#define sc(x) scanf("%lld",&x)
vector<ll> v;//qwq
ll a[10002];
ll l,r,n,m,c=1,ie,j,ans;
inline ll get(ll x)
{
    return (r-r/x)-(l-l/x);
}
void dfs(ll x, ll h)
{
    a[h]=v[x];
    if(h==j)
    {
        re ll w=1;
        for(re ll i=0;i<=h;++i)
        {
            w*=a[i];
        }
        if(c) ans+=get(w);
        else ans-=get(w);
        return;
    }
    for(re ll i=x+1;i<ie;++i)
    {
        dfs(i,h+1);
    }
}
signed main()
{
    sc(l),sc(r),sc(n); m=n;
    if(n==1) return printf("%lld",r-l+1);
    if(r<l) return printf("0"),0;
    if(l==r) return printf(__gcd(l,n)==1?"1":"0"),0; --l;
    for(re ll i=2;i*i<=n;++i)
    {
        if(m%i==0)
        {
            v.push_back(i);
            while(m%i==0) m/=i;
        }
    }
    if(m>1) v.push_back(m);
    ie=v.size();
    for(re ll i=0;i<ie;++i)
    {
        j=i;
        for(re ll k=0;k<ie;++k)
        {
            dfs(k,0);
        }
        c^=1;
    }
    printf("%lld",ans);
    return 0;
}
```

二进制枚举：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re register
#define sc(x) scanf("%lld",&x)
vector<ll> v;
ll l,r,n,m,ie,je;
ll f(ll x)
{
    re ll k,a=0;
    for(re ll i=1;i<ie;++i)
    {
        k=1;
        for(re ll j=0;j<je;++j)//每次枚举j的次数一定是je，不能j>>1为0就跳
        {
            if(i&(1<<j)) k*=v[j];
        }
        if(__builtin_parity(i)) a+=x/k;
        else a-=x/k;
    }
    return x-a;
}
signed main()
{
    sc(l),sc(r),sc(n); m=n;
    if(n==1) return printf("%lld",r-l+1);
    if(r<l) return printf("0"),0;
    if(l==r) return printf(__gcd(l,n)==1?"1":"0"),0;
    for(re ll i=2;i*i<=n;++i)
    {
        if(m%i==0)
        {
            v.push_back(i);
            while(m%i==0) m/=i;
        }
    }
    if(m>1) v.push_back(m);
    ie=1<<v.size(); je=v.size();
    printf("%lld",f(r)-f(l-1));
    return 0;
}
```

#### 卡特兰数

catalan数
$$
c[0]=1\\
c[n+1]=\sum_{i=0}^nc[i]\cdot c[n-i-1]
$$
例如从0到5分别是`1,1,2,5,14,42`。且`c[35]`为19位长度，`c[36]`爆long long。

```c+
设h(n)为catalan数的第n项，令h(0)=1,h(1)=1，catalan数满足递推式：
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n≥2)
例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
另类递推式：
h(n)=h(n-1)*(4*n-2)/(n+1)
h(n+1)=h(n) * (4*n + 2) / (n + 2)
递推关系的解为：
h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
递推关系的另类解为：
h(n)=C(2n,n) - C(2n,n-1) (n=0,1,2,...)
```

意义：

- 矩阵连乘： P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案。h(n) 种
- 一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列
- 在一个凸多边形中，通过若干条互不相交的对角线，把这个多边形划分成了若干个三角形。任务是键盘上输入凸多边形的边数n，求不同划分的方案数f（n）。比如当n=6时，f（6）=14。
- 给定N个节点，能构成多少种不同的二叉搜索树
- 给定n对括号，求括号正确配对的字符串数
- $2n$个黑白，使得前缀黑色小于白色的方案数
- 圆上$2n$点用$n$条不相交线段连接的方案数
- $n$人有$50$元，$n$人有$100$元买$50$元物品，排队方案数使得$2n$人都可找零

注：也可以使用$dp$，并计算$dp[2n][n]$。转移状态见下代码：

```c++
int n,f[505][505];
int main(){
	scanf("%d",&n);
	f[1][1]=1;
	for (int i=2;i<=n+n;i++)
		for (int j=(i+1)>>1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%100;
	printf("%d",f[n+n][n]);
	return 0;
}
```



#### 斯特林数

stirling数

##### 第一类

(无符号:)将n个不同元素构成m个圆排列的数目。无符号为$s_u(n,m)$或$\left[\matrix{n\\m}\right]$，有符号为$s_s(n,m)$，分别表现升阶函数和降阶函数的各项系数。
$$
\begin{align}
x^{n\downarrow}&=x(x-1)(x-2)\dots(x-n+1)=\sum_{k=0}^ns_s(n,k)x^k\\
x^{n\uparrow}&=x(x+1)(x+2)\dots(x+n-1)=\sum_{k=0}^ns_u(n,k)x^k\\
s_s(n,u)&=(-1)^{n+m}s_u(n,m)\\
s_u(n+1,m)&=s_u(n,m-1)+n\cdot s_u(n,m)\\
s_s(n+1,m)&=s_s(n,m-1)-n\cdot s_s(n,m)\\
\end{align}
$$

> 例题：有n个仓库，每个仓库有两把钥匙，共2n把钥匙。同时又有n位官员。问如何放置钥匙使得所有官员都能够打开所有仓库？（只考虑钥匙怎么放到仓库中，而不考虑官员拿哪把钥匙。）那如果官员分成m个不同的部，部中的官员数量和管理的仓库数量一致。那么有多少方案使得，同部的所有官员可以打开所有本部管理的仓库，而无法打开其他部管理的仓库？（同样只考虑钥匙的放置。）
>
> 第一问很经典，就是打开将钥匙放入仓库构成一个环：1号仓库放2号钥匙，2号仓库放3号钥匙……n号仓库放1号钥匙。这种情况相当于钥匙和仓库编号构成一个圆排列方案数是$(n-1)!$种。
>
> 而第二问就对应的将n个元素分成m个圆排列，方案数就是第一类无符号Stirling数$s_u(n,m)$。如要要考虑官员的情况，只需再乘上$n!$即可。

##### 第二类

把n+1个元素分成m个集合，记为$S(n,m)$或$\left\{\matrix{n\\m}\right\}$。
$$
\begin{align}
S(n,m)&=\frac{1}{m!}\sum_{k=0}^m(-1)^k\left(\matrix{m\\k}\right)(m-k)^n\\
S(n+1,m)&=S(n,m-1)+m\cdot S(n,m)
\end{align}
$$

递推上与第一类的区别在于$m$还是$n$作系数和正负问题。

> 例题：
>
> (1)n个不同的球，放入m个无区别的盒子，不允许盒子为空。 
>
> 即$S(n,m)$
>
> (2)n个不同的球，放入m个有区别的盒子，不允许盒子为空。
>
> 即$n!S(n,m)$
>
> (3)n个不同的球，放入m个无区别的盒子，允许盒子为空。
>
> 即$\sum_{k=0}^mS(n,k)$
>
> (4)n个不同的球，放入m个有区别的盒子，允许盒子为空。
>
> 即$\sum_{k=0}^mP(m,k)\cdot S(n,k)=m^n$

求斯特林数，可以套用公式二，使用$dp$。注意到初始状态是$S(n,1)=S(n,n)=1$。

第二类斯特林数与$n$球$m$盒放球问题的总结如下：

| 球区别 | 盒区别 | 空盒 | 模型       | 方案计数                                        |
| ------ | ------ | ---- | ---------- | ----------------------------------------------- |
| 有     | 有     | 有   | 选取       | $m^n$                                           |
| 有     | 有     | 无   | 放球       | $m!\left\{\matrix{n\\m}\right\}$                |
| 有     | 无     | 有   | 放球       | $\sum_{k=1}^m\left\{\matrix{n\\k}\right\}$      |
| 有     | 无     | 无   | 放球       | $\left\{\matrix{n\\m}\right\}$                  |
| 无     | 有     | 有   | 不定方程   | $C_{n+m-1}^n$                                   |
| 无     | 有     | 无   | 不定方程   | $C_{n-1}^{m-1}$                                 |
| 无     | 无     | 有   | 正整数拆分 | $G(x)=\frac1{\prod_{i=1}^m(1-x^i)},x^n$系数     |
| 无     | 无     | 无   | 正整数拆分 | $G(x)=\frac{x^m}{\prod_{i=1}^m(1-x^i)},x^n$系数 |

##### 例题

###### 晋级概率

> (scnuicpc pre-1)有$n$个参赛者，前$k$名(排名可以并列，并列之后下一个排名序数不增加，即前k组同分的人)胜选。求所有人都胜选的概率的最简分数。$t\le100,0\le k\le n\le15$，分子为$0$输出$0/1$。

即求：
$$
\frac{\sum_{i=0}^kS(n,i)\cdot i!}{\sum_{i=0}^nS(n,i)\cdot i!}
$$
直接套模板即可(由于每个人是不同的，要算排列数)。可以如下理解递推模板：
$$
dp[i][j]=dp[i-1][j-1]+dp[i-1][j]\times j
$$
有$i$个不加区别的人占$j$个排名，等于$i-1$个占$j$个排名时，这个新的人可以有$j$个插入选择，或者他自己另辟一个新的排名区。代码如下：

```c++
const long long MOD=4611686018427387901;
long long p[1010],dp[1010][1010];
void init(){
    int i,j;
    for(i=1,p[0]=1;i<=1000;i++) p[i]=p[i-1]*i%MOD;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=1000;i++)
    for(j=1;j<=i;j++){
        if(j==1) dp[i][j]=1;
        else if(j==i) dp[i][j]=1;
        else dp[i][j]=(j*dp[i-1][j]%MOD+dp[i-1][j-1])%MOD;
    }
}
int main(){
    init();
    int n,m,t;
    t=read();
    while(t--)
    {
        n=read();m=read();
        ll fz=0,fm=0;
        for(ll i=1;i<=m;++i) fz+=dp[n][i]*p[i]%MOD;//mod无用
        for(ll i=1;i<=n;++i) fm+=dp[n][i]*p[i]%MOD;
        if(fz==0) printf("0/1\n");
        else
        {
            ll ff=__gcd(fz,fm);
            printf("%lld/%lld\n",fz/ff,fm/ff);
        }
    }
    return 0;
}
```



#### 抽屉原理

把$mn+1$个物体放到$n$个抽屉里，至少有一个抽屉至少有$m+1$个物体

把$mn-1$个物体放到$n$个抽屉里，至少有一个抽屉至少有$m-1$个物体

##### 例题

###### 还是选数

> (oj)给定$n$个数，问能否从中选出若干个数使得他们的和可以被$m$整除？
>
> $1\le n\le10^6,2\le m\le10^3,1\le a_i\le10^9$

若$n\le20$，可以尝试搜索，若$n\le10^3$，可以尝试背包$DP$，而本题不可以直接这么做。

考虑抽屉原理，发现$n\ge m$时，必然可以被整除。所以实质上只需要考虑$n<m$的情况。

```c++
ll dp[2][1010],n,m,a;
signed main()
{
    sc(n); sc(m); if(n>m) return printf("YES\n"),0;
    dp[0][0]=1;
    repe(i,1,n)
    {
        sc(a); a%=m;
        repe(j,0,m) if(dp[(i-1)&1][(m+j-a)%m]) dp[i&1][j]=1;
        repe(j,0,m) dp[i&1][j]|=dp[(i-1)&1][j];
    }
    return printf(dp[n&1][m]?"YES":"NO"),0;
}
```



还可以用前缀和做da ro

#### 生成函数

##### 例题

###### 还是字符串选数

> (oj)字母$a\dots m$的价值分别为$1,\dots,26$，单词价值是字母价值和，且认为单词与排列顺序无关，如$abc$与$cab$是同一个单词。给定$26$小写字母数，问可以组成多少价值小于等于$50$的单词。($0\le a\le 20,n=26$)

考虑生成函数：
$$
(1+x+x^2+\dots+x^{a_1})(1+x^2+x^4+\dots+x^{a_2})\dots(1+x^{26}+x^{52}+\dots+x^{a_{26}})
$$
该生成函数的计算可以使用$DP$，时间复杂度为$\Omicron(50\cdot26\cdot a)$，代码如下：

```c++
ll dp[2][200],a,r;
signed main()
{
    dp[0][0]=1;
    repe(i,1,26)
    {
        sc(a);
        repe(j,0,100) dp[i&1][j]=0;
        repe(k,0,a)
        {
            repe(j,0,50)
            {
                if(j+k*i>50) continue;
                dp[i&1][j+k*i]+=dp[(i-1)&1][j];
            }
        }
    }
    repe(i,1,50) r+=dp[26&1][i];
    return printf("%lld",r),0;
}
```

###### 还是还是字符串计数

> (oj)计算满足以下条件的字符串个数，答案对$10^9+7$取模：
>
> - 字符串长度为$n(1\le n\le10^9)$
> - 字符串仅由`S,C,N,U`四个字母组成
> - 字母`S,C`分别出现偶数次或不出现
>
> 输入一个整数$t(1\le t\le10^6)$表示测试用例，接下来$t$个询问$n$。

考虑为组合时，考虑指数生成函数：
$$
(1+\frac{x}{1!}+\frac{x^2}{2!}+\dots)^2(1+\frac{x^2}{2!}+\frac{x^4}{4!}+\dots)^2
$$
由于：
$$
e^x=\sum_{n=0}^\infty\frac{x^n}{n!},x\in\mathbf{R}
$$
根据高中的二项式奇偶次求和模板，得原式：
$$
e^{2x}(\frac{e^x+e^{-x}}2)^2=\frac14(e^{4x}+1+2e^{2x})
$$
再次展开，得：
$$
\frac14+\frac14(1+\frac{4x}{1!}+\dots+\frac{(4x)^n}{n!}+\dots)+\frac12(1+\frac{2x}{1!}+\dots+\frac{(2x)^n}{n!}+\dots)
$$
提取$x^n$项，并且将组合转为排列：
$$
n!\cdot(\frac14\cdot\frac{4^n}{n!}+\frac12\cdot\frac{2^n}{n!})=4^{n-1}+2^{n-1}
$$

> 注意不要手贱合并为$2^{2n-3}$，这是不对的……

所以时间复杂度为$\Omicron(t\log n)$，代码如下：

```c++
ll qpow(ll a, ll b)
{
    ll r=1;
    for(;b;b>>=1,(a*=a)%=mod) if(b&1) (r*=a)%=mod;
    return r;
}
ll inv(ll a) {return qpow(a,mod-2);}
ll t,n;
signed main()
{
    sc(t);
    while(t--)
    {
        sc(n);
        printf("%lld\n",(qpow(4,n-1)+qpow(2,n-1))%mod);
    }
    return 0;
}
```



#### 应用

##### 直接法

###### 编码

> 有一串严格升序排序的小写字母，长度待定。规定序号为字典序，即a=1,z=26,ab=27……给定一个字串，求序号。(若不合法输出0)

首先长度为n下序号数为$C_{26}^n$，
对长度n下，小于某字串的序号数为：(i按访问下标计)
$$
\sum_{i=0}^{len-1}\sum_{j=str[i-1]}^{str[i]-1}C_{26-j+'a'}^{len-i-1}
$$
具体思路同查字典型排列组合。

###### CGY树

> (scnu cgy)不超过$10$组数据，有$N(1\le N\le10^5)$节点树，编号$1\sim N$，边加权。对于所有$N$的排列，代表一条移动路径，如$312$从节点$3\to1\to2$。求$N$的所有排列构成的路径的长度和是多少？满足每条边长度$1\le L\le10^9$，答案对$10^9+7$取模。

对于每一条边，可以看做当前边把一颗树上的结点分隔成两部分，其中两部分的结点个数分别为a，b。假设结点u，v分别为两部分中的点。对于每一组u，v，全排列中有(N-1)*2种可能，其余的点有(N-2)!种可能，于是一条边对于幸运值之和的贡献次数为：a*b*(N-1)*2*(N-2)!次，即a*b*2*(N-1)!次。`解释：在所有排列中，出现u,v的排列有2(n-1)个，显然`。
 所以用dfs求出每条边左右两部分个数a，b，然后得出当前边的贡献为a*b*2*(N-1)!*length,最后求和每条边的贡献值即可。

注：dfs很容易求，这里不放代码。个人思路是转有根树，然后跑dfs统计孩子数(含自己)和深度，然后枚举每一条边(可以set去重双向边也可以录入时做下标处理)，找到两个端点，深度高的端点点数为其孩子数,浅的取补即可。`但是WA了暂时不知道原因，所以贴一份答案上来`

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5+10;
const long long MOD = 1e9+7;

long long res;
long long ans[MAXN];
int n;

struct Node{
    vector<int> child;
    vector<int> len;
}a[MAXN];

void dfs(int u){
    if(a[u].child.empty()){
        ans[u] = 1;
        return;
    }
    long long t = 0;
    for(int i = 0;i<a[u].child.size();i++){
        int to = a[u].child[i];
        dfs(to);
        t+=ans[to];
    }
    ans[u] = t+1;
    return;
}

int main(){
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i<=n;i++){
            a[i].child.clear();
            a[i].len.clear();
        }
        memset(ans,0,sizeof(ans));
        for(int i = 0;i<n-1;i++){
            int x,y,l;
            scanf("%d%d%d",&x,&y,&l);
            a[x].child.push_back(y);
            a[x].len.push_back(l);
        }
        dfs(1);
        res = 0;
        long long t = 1;
        for(int i = 1;i<=n-1;i++)
            t=t*i%MOD;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<a[i].child.size();j++){
                int to = a[i].child[j];
                int len = a[i].len[j];
                res+=((ans[to]*((long long)n-ans[to])%MOD)*len%MOD*2%MOD)*t%MOD;
                res%=MOD;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
```



##### 间接法

###### 排列计数

> 对1~n序列，恰有m个位置序号对应，求情况数

对应部分显然是$C_n^m$，乱序部分找规律(或者证明)，可以得到递推式/通项：

设$d[i]$是有$i$个乱序时的情况数，有：
$$
d[0]=0,d[1]=0,d[2]=1\\
d[n]=(n-1)\times(dp[n-1]+dp[n-2])\\
d[n]=n!(1-\frac1{1!}+\frac1{2!}+\dots+(-1)^n\frac 1{n!})
$$
那么就可以直接爆切了。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
#define MOD 1000000007
ll f[MAXN], inv[MAXN], d[MAXN], t, n, m;
ll qpow(ll a, ll b)
{
	ll res = 1;
	for (; b; b >>= 1)
	{
		if (b & 1) (res *= a) %= MOD;
		(a *= a) %= MOD;
	}
	return res;
}
signed main()
{
	scanf("%lld", &t);
	f[0] = 1;
	rep(i, 1, MAXN)
	{
		f[i] = f[i - 1] * i % MOD;
		inv[i] = qpow(f[i], MOD - 2);
	}
	d[1] = 0, d[2] = 1, d[3] = 2;
	rep(i, 4, MAXN) d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
	while (t--)
	{
		scanf("%lld%lld", &n, &m);
		if (n == m + 1) printf("0\n");
		else if (n == m) printf("1\n");
		else if (m == 0) printf("%lld\n", d[n]);
		else printf("%lld\n", f[n] * inv[m] % MOD * inv[n - m] % MOD *
			d[n - m] % MOD);
	}
	return 0;
}
```

##### 递推法

###### 小魔女帕琪

> 每次随机使用一种魔法石，如果七次使用的魔法石各不相同(可以叠加)，造成伤害，求造成伤害的期望值。

设每种魔法石有$a_i$个，共$N$个。显然对于前七个，它们各不相同的概率为：
$$
p_0=7!\prod_{i=1}^7\frac{a_i}{N-i+1}
$$
假设第一次取出第一种，则第$2\sim8$次使用能够造成伤害的概率为：
$$
p_0\times\frac{a_1}{N-7} (这里的7!对应2\sim8)
$$
取余六个同理，对这七条式子求和，由于$\sum_{i=1}^7a_i=N$，有七概率和为：
$$
p_0
$$
从$1\sim7$一直到$N-6\sim N$，共有$N-6$项，故答案为：
$$
(N-6)p_0
$$
代码略。

###### OSU!

> 有n次操作，每次有不同的成功率；连续成功x次得分(x^3^)，已计分操作不会重复计分(取最大计分)，求分数的期望值。

假设得分为$x$，不为$x^3$，操作数为i时得分是$x[i]$，显然有递推式：
$$
x[i]=x[i-1]\times p[i]+p[i]
$$
假设得分为$x^2$时，是$x2[i]$，根据求和式展开，可以推导出：
$$
x2[i]=(x2[i-1]+2x[i-1]+1)\times p
$$
每增加一个连续的成功操作，增值为：
$$
(x-1)^3-x^3=3x^2+3x+1
$$
故代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll n;
double p, x1[2], x2[2], ans[2];
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n)
	{
		scanf("%lf", &p);
		x1[i&1] = (x1[(i - 1) & 1] + 1) * p;
		x2[i&1] = (x2[(i - 1) & 1] + 2 * x1[(i - 1) & 1] + 1) * p;
		ans[i&1] = ans[(i - 1) & 1] + (3 * (x1[(i - 1) & 1] + x2[(i - 1) & 1]) + 1) * p;
	}
	printf("%.1lf", ans[n & 1]);
	return 0;
}
```

##### 插入法

###### 青原樱

> 有n个位置，种m棵樱，樱间至少留一个空位，求可能情况数对p取模(p不一定是质数,n,m数量级均为1e6+)。

可以找规律得到：

$$
dp[1][m]=m\\
dp[n][m]=dp[n-1][m-2]+dp[n-1][m-3]+dp[n-1][m-4]\\
otherwise,dp[n][m]=0
$$
但是显然超时。

如果用插入法，显然有n-m个坑，每个坑左右可插入，显然有n-m+1个可以插入点，这些点可以种一棵幼苗。所以答案为$A^m_{n-m+1}$，要用拓展欧几里得公式做模意义下的除法，不可用快速幂。

##### 隔板法

###### 安全系统

> 有n个存储区，a个0和b个1，每个存储区可以存储0个或任意多个信号，求存储方案数（原题意*"每个储存区最多能存储存2个种类不同的信号（可以不储存任何信号）"*存在问题）($a,b\le50,n+a\le50,n+b\le50$)

隔板法很简单，拓展到可空隔板：

k个球放n个盒子，盒子可以不放球，增设n个假想球(即不放球等效于放一个假象球)，用隔板法，得：$C_{n+k-1}^{n-1}$

可以将原题用乘法原理分解，这是解题目的**关键**，即$总=只放1\times 只放0$

故答案为$\sum_{i=0}^a\sum_{j=0}^bC_{i+n-1}^{n-1}C_{j+n-1}^{n-1}$

显然先跑杨辉三角(直接跑到50比较好，否则要跑到$n+\max\{a,b\}$

注意到n=50时，超出了long long范围(可以自己跑程序得出)，但没有超出unsigned long long范围，所以不能只开long long，也不必开高精度。

> 此题可以用dp解，解法如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 52
ll dp[MAXN][MAXN][MAXN], n, a, b, ans;
signed main()
{
	dp[0][0][0] = 1;
	scanf("%lld%lld%lld", &n, &a, &b);
	repe(i, 1, n)
    repe(j, 0, a)
    repe(k, 0, b)
    repe(x, 0, j)
    repe(y, 0, k) dp[i][j][k] += dp[i - 1][x][y];
	repe(i, 0, a) repe(j, 0, b) ans += dp[n][i][j];
	printf("%llu", ans);
	return 0;
}
```

##### 乘法原理

###### Rize's code

> (scnucpc)，一个元素$(x,y)$位于$x\in[a,b],y\in[c,d],x,y\in\Z$，求这个元素位于多少个矩阵中(矩阵右上角不会大于$(b,d)$)。

答案为$a(c-a+1)b(d-b+1)$。画图易知。

> 原题干比较复杂。原题干如下：
>
> Rize passed the entrance examination of Ecole Normale Super Paris. Her major is computer science and technology. She hopes to realize her dream of being a teacher in college and teach Chimame March to write code in the future.
>
> One day, she wants to find all the sub-matrices of a matrix A*A*, calculate the sum of the elements of each sub-matrix, and then add these sums to get the result. In other words, she wanted to ask for this:
> $$
> \sum_{B\ is\ a\ sub-matrix\ of\ A}\sum B_{i,j}
> $$
> Formally, a sub-matrix B of matrix A is a group of four integers u, d, l, r $ (1≤u≤d≤n; 1≤l≤r≤m)$. We will assume that the sub-matrix contains cells $A_{i,j}  (u≤i≤d;l≤j≤r)$. The area of the sub-matrix the number of cells it contains.
>
> And Rize wrote the following code without hesitation:
>
> ```c++
> #include <cstdio>
> const int N = ?;
> int a[N][N];
> int main(){
>     int n,m;
>     scanf("%d %d",&n,&m);
>     for(int i=1;i<=n;i++)
>         for(int j=1;j<=m;j++)
>             scanf("%d",&a[i][j])
>     long long ans=0;
>     //(u,l) is the top left corner of the sub-matrix
>     //(d,r) is the bottom right cornor of the sub-matrix
>     for(int u=1;u<=n;u++)
>         for(int l=1;l<=m;l++)
>             for(int d=u;d<=n;d++)
>                 for(int r=l;r<=m;r++)
>                     for(int i=u;i<=d;i++)
>                         for(int j=l;j<=r;j++)
>                             ans+=a[i][j];
>     printf("%lld\n",ans);
> }
> ```
>
> But after Rize finished writing, she thought the code was too ugly. She observed that the final result is actually equivalent to multiplying each element by a constant, and then adding up the results. So her code can be simplified as follows:
>
> ```c++
> #include <cstdio>
> long long get_const(int x, int y, int n, int m){
>     long long ans = 0;
>     // ??
>     return ans;
> }
> int main()
> {
>     int n,m,t;
>     long long ans = 0;
>     scanf("%d %d",&n,&m);
>     for(int i=1;i<=n;i++){
>         for(int j=1;j<=m;j++){
>             scanf("%d",&t);
>             long long c = get_const(i,j,n,m);
>             ans += c*t;
>         }
>     }
>     printf("%lld\n",ans);
> }
> ```
>
> But Rize doesn’t know how to calculate this number. In other words, she does not know how to implement the function `get_const()` of the above code. She is stumped, and she hopes to solve this problem as soon as possible and then go to other topics. Can you help her?
>
> There is an integer $ Q (1≤Q≤10^5)$in  the first line, which means there are Q queries. Next Q lines,each line contains four integers $x, y, n, m(1≤x≤n≤9 \times 10^4,1≤y≤m≤9 \times 10^4)$  representing the parameters of the function `get_const()` .
>
> For each query, output an integer representing the return value of function `get_const()` on a line

###### 长方形

> 有长为n,m的矩形，.表示可用，*表示不可用；求可用区域可以画成多少个长方形(注：正方形也算)

$其实质几何意义和不重复的证明有待再次学习$
$$
设h数组，以行扫描，每次更新h数组，h_j表示[i,j]往上可以延伸多少格\\
设l,r数组，l[i],r[i]表示h[i]中左边第一个不大于/右边第一个不小于h[i]数\\如果查无此数，设为l[i]=0,r[i]=m+1\\
那么每次扫描，执行循环，增加(i-l_i)\times(r_i-i)\times h_i个矩形
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1002
ll lf[MAXN], rf[MAXN], h[MAXN], k[MAXN], n, m, top, ans;
bool ban[MAXN][MAXN];
char ch;
inline void monolf()
{
	top = 0;
	rede(i, m, 1)
	{
		while (top && h[i] <= h[k[top]]) lf[k[top]] = i, --top;
		k[++top] = i;
	}
	while (top) lf[k[top]] = 0, --top;
}
inline void monorf()
{
	top = 0;
	repe(i, 1, m)
	{
		while (top && h[i] < h[k[top]]) rf[k[top]] = i, --top;
		k[++top] = i;
	}
	while (top) rf[k[top]] = m + 1, --top;
}
inline void f()
{
	monolf();
	monorf();
	repe(i, 1, m) ans += (i - lf[i]) * (rf[i] - i) * h[i];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	repe(i, 1, n) repe(j, 1, m)
	{
		cin >> ch;
		if (ch == '*') ban[i][j] = true;
	}
	repe(i, 1, n)
	{
		repe(j, 1, m)
		{
			++h[j];
			if (ban[i][j]) h[j] = 0;
		}
		f();
	}
	cout << ans;
	return 0;
}
```

###### 格点三角形

> (oj)在$n\times m$点阵中，求满足三个顶点均在格点、面积为1、至少有一条边平行$x/y$轴的不同三角形的个数对$10^9+7$取模，$2\le n,m\le10^9$

显然只有边长为$1,2$的三角形，可以分为四种情况，以$m$轴为底边，边长为$1,2$时，分别可以计算得到有：
$$
2(n-2)(m-1)*m+2(n-1)(m-2)m//
即可选第三顶点列数\times该列底边位置数\times可选列的可选点数
$$
在以$n$轴为底边时，同理，但是需要去除4个重复点，可以直接-4，也可以直接用公式推，其上述的每个第三个项-2即可。代码为：

```c++
#include <bits/stdc++.h>
#define mod 1000000007
long long n,m;
signed main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld",(2*(m*(m-2)%mod*(n-1)%mod+n*(n-2)%mod*(m-1)%mod+(n-1)*(n-2)%mod*(m-2)%mod+(m-1)*(m-2)%mod*(n-2)%mod))%mod);
	return 0;
} 
```

##### 幂

###### 越狱

> 有m种宗教，n个牢房，相邻牢房囚犯信同样的教就会越狱，给出n,m(long long内)，求越狱情况数对100003取模。

解为$m^n-m\cdot(m-1)^{n-1}$，可以推导也可以dfs打表找规律。

> 记得取模时小心谨慎。快速幂不要写错了。

用取补法，即求不会越狱情况，总状况显而易见，很容易得到，首个人可以信m种教，之后为保证不会越狱，其余人信教各不邻同，很容易得到$(n-1)$个人有$(m-1)^{n-1}$种信教情况，不邻同有且只有不与上一个相同(递推中不出现下一个)，然后数学归纳即可。

### 快速运算

#### 递推式

##### 矩阵加速

假设使用矩阵加速计算斐波那契数列，由：
$$
fib_n=fib_{n-1}+fib_{n-2},fib_1=fib_2=1
$$
设：
$$
\left(\matrix{f[n-2]&f[n-1]}\right)\times\left(\matrix{a_{11}&a_{12}\\a_{21}&a_{22}}\right)=\left(\matrix{f[n-1]&f[n]}\right)
$$
根据矩阵方程，得：
$$
a_{11}\cdot f[n-2]+a_{12}\cdot f[n-1]=f[n-1]\rightarrow a_{11}=0,a_{12}=1
$$

$$
a_{21}\cdot f[n-2]+a_{22}\cdot f[n-1]=f[n]=f[n-2]+f[n-1]\rightarrow a_{11}=1,a_{12}=1
$$

所以得出构造矩阵的值，并且有：
$$
\left(\matrix{f[1]&f[2]}\right)\times\left(\matrix{0&1\\1&1}\right)^n=\left(\matrix{f[n]&f[n+1]}\right)
$$
使用快速幂，计算出$\left(\matrix{0&1\\1&1}\right)^n=\left(\matrix{x_{11}&x_{12}\\x_{21}&x_{22}}\right)$，所以$f[n]=x_{11}+x_{22}$



同理，可以构造：
$$
f[n]=f[n-1]+f[n-2]+1,f[1]=f[2]=1
$$

$$
\left(\matrix{f[n-2]&f[n-1]&1}\right)\times\left(\matrix{a_{11}&a_{12}&a_{13}\\a_{21}&a_{22}&a_{23}\\a_{31}&a_{32}&a_{33}}\right)=\left(\matrix{f[n-1]&f[n]&1}\right)
$$

易得构造矩阵为：$\left(\matrix{0&1&0\\1&1&0\\0&1&1}\right)$



对于：
$$
f[n]=f[n-1]+f[n-2]+n+1,f[1]=f[2]=1
$$
可得构造：
$$
\left(\matrix{f[n-2]&f[n-1]&n&1}\right)\times\left(\matrix{0&1&0&0\\1&1&0&0\\0&1&1&0\\0&1&1&1}\right)=\left(\matrix{f[n-1]&f[n]&n+1&1}\right)
$$


设前$n$项和为$f[n]$，求斐波那契数列的前$n$项和：
$$
\left(\matrix{f[n-2],f[n-1],s[n-2]}\right)\times\left(\matrix{0&1&0\\1&1&1\\0&0&1}\right)=\left(\matrix{f[n-1]&f[n]&s[n-1]}\right)
$$


同理对其他数列，先把$f$列出，然后列出$s$，然后列$n$和$1$，可以求出。



以f(n)=1(n<=3);f(n)=f(n-1)+f(n-3)(else)为例。

可以构造列矩阵：
$$
\left(\matrix{f[n]\\f[n-1]\\f[n-2]}\right)\times\left(\matrix{1&0&1\\1&0&0\\0&1&0}\right)=\left(\matrix{f[n-1]\\f[n-2]\\f[n-3]}\right)
$$


```c++
#include <bits/stdc++.h>
#define MAXN 102
#define MOD 1000000007
#define rep(x,a,b) for(register int x=a;x<b;x++)
using namespace std;
typedef long long ll;
int n=3;
ll k;
struct matrix
{
    ll a[MAXN][MAXN];
};
void clear(matrix &x)
{
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            x.a[i][j]=0;
        }
    }
}
matrix operator*(const matrix &x, const matrix &y)
{
    matrix z;
    clear(z);
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            rep(k,1,n+1)
            {
                z.a[i][j]+=x.a[i][k]*y.a[k][j]%MOD;
                z.a[i][j]%=MOD;
            }
        }
    }
    return z;
}
matrix ori, ans;
ll t;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&k);
        clear(ori);
        clear(ans);
        ori.a[1][1]=ori.a[1][3]=ori.a[2][1]=ori.a[3][2]=1;
        rep(i,1,n+1)
        {
            ans.a[i][i] = 1;
        }
        while(k)
        {
            if(k&1) ans = ans*ori;
            ori = ori*ori;
            k>>=1;
        }
        printf("%lld\n",ans.a[2][1]);
    }
    return 0;
}
```

###### 心态不炸

> (scnu cgy)设$f[1,\dots,5]=[2,3,5,6,8],f[n]=\sum_{i=n-5}^{n-1}f[i],n>5$，给定$10^4$组以内的询问$n(2\le n\le10^{15})$，求$f[n-1],f[n]\mod10^9+7$。

个人解法：可以构建初始矩阵：$(\matrix{2&3&5&6&8})$，即$n=6$，$\left(\matrix{f[n-5]&f[n-4]&f[n-3]&f[n-2]&f[n-1]} \right)$。目标矩阵$\left(\matrix{f[n-4]&f[n-3]&f[n-2]&f[n-1]&f[n]} \right)$。：

可以得出关系矩阵：
$$
A=\left(\matrix{0&0&0&0&1\\1&0&0&0&1\\0&1&0&0&1\\0&0&1&0&1\\0&0&0&1&1}\right)
$$
可以推知，需要从让初始矩阵右乘$A^{n-2}$得到答案。之后套模板即可。个人代码如下：

```c++
struct mat
{
    ll r,c,a[6][6];
};
mat operator*(mat x, mat y)
{
    mat z;
    memset(z.a,0,sizeof z.a);
    ll a=x.r,b=x.c,c=y.c;
    z.r=a; z.c=c;
    rep(i,0,a) rep(j,0,c) rep(k,0,b)
    {
        (z.a[i][j]+=x.a[i][k]*y.a[k][j])%=mod;
    }

    return z;
}
mat b,a;
ll n;
signed main()
{
    a.r=1,a.c=5; b.r=5,b.c=5;
    while(1)
    {
        n=read();
        if(!n) break;
        memset(b.a,0,sizeof b.a);
        memset(a.a,0,sizeof a.a);
        a.a[0][0]=2,a.a[0][1]=3,a.a[0][2]=5,a.a[0][3]=6,a.a[0][4]=8;
        b.a[0][4]=b.a[1][4]=b.a[2][4]=b.a[3][4]=b.a[4][4]=1;
        b.a[1][0]=b.a[2][1]=b.a[3][2]=b.a[4][3]=1;
        n-=2; if(n<0) n=0;
        for(;n;n>>=1,b=b*b)
        {
            if(n&1) a=a*b;
        }
        printf("%lld %lld\n",a.a[0][0],a.a[0][1]);
    }
	return 0;
}
```

可能会产生的bugs：

- 假设递推式有负数，注意减法取模公式
- 赋值特别注意，诸如，a=b=c=1;不要写成a=b=c;

#### 幂

##### 整数次幂

###### 快速幂

```c++
//快速幂算法
int qpower(int a, int b)//a^b in integer
{
    int r=1;
    while(b)
    {
        if(b&1) r*=a;
        b>>=1;
        a*=a;
    }
    return r;
}
```

简写为：

```c
for (ans = 1; b; b >>= 1, a = 1LL * a * a % m) if (b & 1)
	ans = 1LL * ans * a % m;
```

###### 拓展欧拉定理

> 见算法-数论-素数-素数相关-欧拉定理-(例题)拓展欧拉定理

#### 乘

##### 整乘

###### 普通

与快速幂相似，整数次乘法也可以如此操作(以下模板含取模)，注意，一般情况下不推荐使用，因为时间复杂度是$\Omicron(log n)$，使用当且仅当$k\times k\mod p$的$k\times k$会炸long long。

```c++
inline ll qmul(ll x, ll y, ll m)
{
	ll res = 0;
	while (y)
	{
		if (y & 1) (res += x) %= m;
		(x += x) %= m;
		y >>= 1;
	}
	return res;
}
```

###### __int128

为了防止炸long long，还有其他方法：

工程应用，可以开\_\_int128，是C++自带的数据类型，但竞赛可能不允许用

```c++
(__int128)a*b %p;
```

###### 优化

还有一种神奇的快速乘，复杂度是$\Omicron(1)$，基于unsigned的溢出差值不变的性质，

```c++
ll z=(ll)x/p+y;
ll res=(ull)x*y-(ull)z*p;
return (res+p)%p;
```

即：

```c++
return ((ull)a*b-(ull)((ull)a/k*b)*k+k)%k; 
```

###### 高精度乘法

使用**FFT（Fast Fourier Transformation）**，中文名**快速傅里叶变换**，将$\Omicron(n^2)$的高精度乘法优化为$\Omicron(n\log n)$

原理：设十进制数的从小到大每一位为系数$a_0,\cdots, c_{n-1}$，则十进制数可以表示为多项式$f(10)$。所以十进制数乘法可以表示为多项式卷积$f(10)\cdot g(10)$。

因为FFT的原理，所以要倒序存储。最后再将进位处理即可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 2097153 //(1<<21) + 1
ll n1, n2, rev[mn], ans[mn], k = 1, s = 2, len, n;
const db pi = acos(-1);
typedef complex<double> cp;
cp a[mn], b[mn];
char s1[mn], s2[mn];
void fft(cp* a, ll n, ll flag)
{
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (ll h = 1; h < n; h <<= 1)
	{
		cp wn = exp(cp(0, flag * pi / h));
		for (ll j = 0; j < n; j += h << 1)
		{
			cp w(1, 0);
			rep(k, j, j + h)
			{
				cp x = a[k], y = w * a[k + h];
				a[k] = x + y;
				a[k + h] = x - y;
				w *= wn;
			}
		}
	}
	if (flag == -1) rep(i, 0, n) a[i] /= n;
}
signed main()
{
	scanf("%s%s", s1, s2);
	n1 = strlen(s1), n2 = strlen(s2); n = max(n1, n2);
	rep(i, 0, n1) a[i] = (db)(s1[n1 - i - 1] - '0');//实部赋值
	rep(i, 0, n2) b[i] = (db)(s2[n2 - i - 1] - '0');
	while ((1 << k) < (n << 1) - 1) ++k, s <<= 1;
	len = 1 << k;
	rep(i, 0, len) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	fft(a, s, 1);
	fft(b, s, 1);
	rep(i, 0, s) a[i] *= b[i];
	fft(a, s, -1);
	rep(i, 0, s)
	{
		ans[i] += (ll)(a[i].real() + 0.5);
		ans[i + 1] += ans[i] / 10, ans[i] %= 10;
	}
	while (!ans[s] && s > -1) --s;
	if (s == -1) printf("0");
	else rede(i, s, 0) printf("%d", ans[i]);
	return 0;
}
```

### 阶乘

```c
//算法一
int r=1;
for(int i=1;i<=n;i++) r*=i;//r=n!

//算法二
int f(int n)
{
    return n == 0 ? 1 : f(n-1)*n;
}
```

#### 临界值

12!=479001600，大于12时，int溢出,13!=6227020800

20!=2432902008176640000,大于20时,long long溢出，

21!=51090942171709440000

#### 阶乘和

由于：
$$
1!+2!+...+m!\\=1+1*2+1*2*3+...+1*2*3...m

\\=1(1+2(1+3(1+...(1+m)...)))
$$
故：

```c
int s=1;//或者long long
for(int i=n;i>1;i--) s=(1+1*s);
```

#### 最末位

##### 朴素解法

```c++
#include <bits/stdc++.h>
using namespace std;
long long n, m = 1;
signed main()
{
	(void)scanf("%lld", &n);
	for (long long i = 2; i <= n; ++i)
	{
		m *= i;
		m %= 100000000;//最大要求项为100000000/2
	}//因为15!的爆炸，所以贪心%10是错的
	printf("%lld", m%10);
}
```

##### 高速解法

$O(logn)$

```c++
#include<cstdio>
int main()
{
	int a[]{6,6,2,6,4,4,4,8,4,6},b[]{6,8,4,2},r=1,n;
	scanf("%d",&n);
	while(n)r=r*a[n%10]*b[(n=n/5)%4]%10;
	printf("%d",r);
	return 0;
}
```

### 斐波那契数列

算法1：重复运算很多，做了很多无用功

```c
int fib(int n)
{
    return n<=2 ? 1 : fib(n-1)+fib(n-2);
}
```



算法2：生成器写法顺次输出

```c
int fib()
{
    static int a=1,b=0,c=0;//a是当前项,b是上一项,c是上上一项
    if(b) a = b + c;  //第二次开始调用fib执行这一行代码
    c=b;
    b=a;//也可以用a=a+b,b=a-b来递推，去掉中间量
    return a;
}

//或：
int fib()
{
    static int a=1,b=0,c=1;//c初始化为1是为了首次a=b+c时a不为0
    a = b + c;
    c=b;
    b=a;
    return a;
}

```

非顺次的数组存储法如下：

```c
int dp[50];//首次调用前memset/for初始值为-1
int fib(int n)//n是fib(n+1)而不是fib(n)
{
    if(n==0||n==1) return dp[n] = 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
```

#### 临界值

设f(1)=1,f(2)=1,f(3)=2,...，

f(46)=1836311903，大于46时int溢出，f(47)=2971215073

f(92)=7540113804746346429,大于92时long long溢出

f(93)=12200160415121876738

#### 性质

##### 常规

1.设前n项和为$s(n)$，显然$s(n)=f(n+2)-1$

2.设每个平方为一个方格，作图可证：
$$
\sum_{i=1}^nf^2(i)=f(i)\times f(i+1)
$$
图如下：(数字代表斐波那契边长值)
$$
\left[\matrix{1&1&3&3&3\\2&2&3&3&3\\2&2&3&3&3}\right]
$$
以$i=2$为例，矩形为左边的三个小矩形，面积为$1\times+1\times+2\times2=2\times 3$

##### 复杂

2.由数学归纳法易证下面两条公式：

$f(n+m)=f(n+1)f(m)+f(n)f(m-1)$

$f(n)^2=(-1)^{n+1}+f(n-1)f(n+1)$

3.斐波那契取模公式：

$f(n)\mod f(m)=f(n-m+m)\mod f(m)$

$=\left(f(n-m+1)f(m)+f(n-m)f(m-1)\right)\mod f(m)$

显然前者是$f(m)$的倍数，故：

$原式=f(n-m)f(m-1)\mod f(m)$

继续递归，得：

$f(n)\mod f(m)=f(m-1)^{\frac nm}f(n\mod m)\mod f(m)$

由于倍数关系，同样地，有：

$f(m-1)^2\mod f(m)=(-1)^m$

①当$m,\frac nm$是偶数时，原式=$f(n\mod m)$

②当$m$偶,$\frac nm$奇时，原式=$f(m-1)f(n\mod m)\mod f(m)$

③$m奇,\frac nm,\frac n{2m}偶$，结果同①

④$m奇,\frac nm偶,\frac n{2m}奇$，结果为$f(m)-f(n\mod m)$

⑤$m,\frac nm奇,\frac n{2m}偶$,结果同②

⑥$m,\frac nm,\frac n{2m}奇$，原式=$f(m)-f(m-1)f(n\mod m)\mod f(m)$

4.若$n\ge1,r\ge2,$

则$f(n)f(n+r-1)-f(n+1)f(n+r-2)=(-1)^{n+1}f(r-2)$

令$k=n\mod m$，且设$k=n+1,m-1=n+r-2$，化简上述式子3，有：$f(m-1)f(k)-f(m)f(k-1)=(-1)^{k+1}f(m-k)$，根据倍数关系和上面式子：$f(m-1)f(k)\mod f(m)=(-1)^{k+1}f(m-1)\mod f(m)$，

跟继续根据k的奇偶性，回代3①和3②，则消掉了所有的模。

#### 例题

##### Byfibonacci

> (GDCPC)

##### 斐波那契

> (蓝桥)，求$(\sum_{i=1}^nfib(i)\mod fib(m))\mod p$，$1\le n,m,p\le10^{18}$

显然，在不取模时或$fib(m)$值低于$long\ \ long$时，这是一道矩阵加速结合快速幂的送分题。然而，双取模带来了麻烦。

核心难点在于$fib(m)$难以求解，开高精度都会炸内存，必须想办法将其缩减或消去。注意，不可以认为：$原式=\sum_{i=1}^nfib(i)\mod (fib(m)\mod p)$，很容易可以找到反例证明这样的交换律不成立(样例2即可)。

由上述复杂性质，可以直接求解该题。

```c++
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
ll p,n,m,sa,t;
struct mat
{
	ll a[2][2];
} ori={1,1,1,0},ans={1,0,0,1};
ll qmul(ll a, ll b, ll mod)
{
	ll res=0;
	if(a<b) a^=b^=a^=b;
	for(;b;b>>=1,(a<<=1)%=mod) if(b&1) (res+=a)%=mod;
	return res;
}
mat operator*(mat& a, mat& b)
{
	mat c={0,0,0,0};
	rep(i,0,2) rep(j,0,2) rep(k,0,2) (c.a[i][j]+=qmul(a.a[i][k],b.a[k][j],p))%=p;
	return c;
}
ll fib(ll n) //f(n)%p
{
	mat b=ori,a=ans;
	for(;n;n>>=1,b=b*b) if(n&1) a=a*b;
	return a.a[1][0];
}
ll rfib(ll n, ll m)//fib(m-1)*f(n%m)%f(m)
{
	ll a=n%m;
	if(a&1) return fib(m-a);
	return ((fib(m)-fib(m-a))%p+p)%p;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&p); n+=2; t=n/m;
	if(m&1)
	{
		if(!(t&1)&&!(t%4)) sa=fib(n%m);
		if(!(t&1)&&t%4) sa=((fib(m)-fib(n%m))%p+p)%p;
		if((t&1)&&!(t%4)) sa=rfib(n,m);
		if((t&1)&&t%4) sa=((fib(m)-rfib(n,m))%p+p)%p;
	}
	else 
	{
		if(t&1) sa=rfib(n,m);
		else sa=fib(n%m);
	}
	if(!sa) printf("%lld",fib(m)-1);
	else printf("%lld",sa-1);
	return 0;
}
```

### 方程

#### 秦九韶算法

```c++
inline double f(double x)
{
    double a = pa[n];//pa[i]代表i次项系数
    for(int i=n-1;i>=0;i--) a=a*x+pa[i];
    return a;
}
```

#### 极值

##### 二分+求导法

二分法求导数零点

导数的计算：

- 公式
- 模拟，即f(x+dx)-f(x)/dx;dx可以取EPS，即1e-6

##### 三分法

条件：已知区间只有一个极值。三分法用来查找凸函数的最大（小）值。

二分效率为log2，三分效率为2*log3

能用二分用二分，简洁好写还效率高。

三种写法如下：

```c++
while(fabs(L-R)>=eps)//[非等比例三分法]
{
    double mid=(L+R)/2;
    if(F(mid+eps)>F(mid-eps)) L=mid;//舍弃左区间
    else R=mid;//舍弃右区间
}
```

```c++
lmid = left + (right - left >> 1);//[三等分法]
rmid = lmid + (right - lmid >> 1);  // 对右侧区间取半
if (cal(lmid) > cal(rmid))
  right = rmid;
else
  left = lmid;
```

```c++
while(R-L>=eps){//[三等分法]
    k=(R-L)/3.0;
    mid1=L+k,mid2=R-k;
    if(f(mid1)>f(mid2)) R=mid2;else L=mid1;
}
```

**其他三分法：**

###### 优选法

取黄金分割比$x=\frac{\sqrt{5}-1}{2}$，约为0.6180339887

以长度为1，起点为0的区间为例，三分点为1-x,x。

###### 四分法

三点及其导数的讨论。

#### 一元三次方程

##### 盛金公式

```c++
#include <iostream> //盛金公式
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
     double a,b,c,d;
     double as,bs,t,si;
     double x1,x2,x3;
     cin>>a>>b>>c>>d;
     as=b*b-3*a*c;
     bs=b*c-9*a*d;
     t=(2*as*b-3*a*bs)/(2*sqrt(as*as*as));
     si=acos(t);
     x1=(-b-2*sqrt(as)*cos(si/3))/(3*a);
     x2=(-b+sqrt(as)*(cos(si/3)+sqrt(3)*sin(si/3)))/(3*a);
     x3=(-b+sqrt(as)*(cos(si/3)-sqrt(3)*sin(si/3)))/(3*a);
     cout<<fixed<<setprecision(2)<<x1<<" ";
     cout<<fixed<<setprecision(2)<<x3<<" ";
     cout<<fixed<<setprecision(2)<<x2<<" ";
     return 0;
}
```

$$
一元三次方程:aX^3+bX^2+cX+d=0 \\
   重根判别公式：\\
       A=b^2-3ac\\
       B=bc-9ad\\
       C=c^2-3bd\\
   当A=B=0时，X1=X2=X3= -b/3a= -c/b = -3d/c
$$

##### 牛顿法

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-4
using namespace std;
double x1,x2,x3,a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}
double df(double x){return 3*a*x*x+2*b*x+c;}
double slove(double l,double r)
{
	double x,x0=(l+r)/2;
	while(abs(x0-x)>eps)
	  x=x0-f(x0)/df(x0),swap(x0,x);
	return x;
}
int main()
{
	cin>>a>>b>>c>>d;
	double p=(-b-sqrt(b*b-3*a*c))/(3*a);
	double q=(-b+sqrt(b*b-3*a*c))/(3*a);
	x1=slove(-100,p),x2=slove(p,q),x3=slove(q,100);
	printf("%.2lf %.2lf %.2lf",x1,x2,x3);
	return 0;
}
```

##### 二分法

```c++
//我的一个解法，假设三个根范围固定，时间效率比牛顿法低
#include <bits/stdc++.h>
#define EPS 1e-5
//even change still TLE
#define eqz(x) (fabs(x)<EPS)
using namespace std;
double a,b,c,d,sol;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
double binf(double l)//[bg, bg+1] when sure has solve in it
{
    double r=l+1.;
    double c=(l+r)/2.;
    while(1)
    {
        if eqz(f(c))
        {
            return c;
        }
        else if(f(l)*f(c)<0.)
        {
            r=c;
        }
        else
        {
            l=c;
        }
    }
}
void prt(double i)
{
    if(sol++) printf(" ");
    printf("%.2lf", i);
}
int main()
{
    int i;
    scanf("%lf%lf%lf%lf", &a,&b,&c,&d);
    for(i=-100;i<=99;i++)
    {
        if(eqz(f(i)))
        {
            prt(i);
        }
        else if(f(i)*f(i+1)<0)
        {
            prt(binf(i));
        }
    }
    if(eqz(i)) prt(i);
    return 0;
}
```

##### 卡尔丹公式

略

#### 例题

##### 弦截法求根

设$f(x)=x^3-5x^2+16x-80=0$取两个不同的点$x_1,x_2$,若$f(x_1),f(x_2)$符号相反，则区间$(x_1,x_2)$内有一根，否则重新输入直到异号为止，并输出`reinput:`，接下来执行：连接两点$(x_1,f(x_1)),(x_2,f(x_2))$交$x$轴于$x$，若$f(x),f(x_1)$同符号，以$x$作为新$x_1$执行上述步骤；若$f(x),f(x_2)$同符号，以$x$作为新$x_2$执行上述步骤，直到$|f(x)|<0.0001$，并输出$x$。

输入样例：`6 10  12 15  2 6`，最终解为$4.99999$。

首先根据叉乘易得：
$$
x=\frac{x_1f(x_2)-x_2f(x_1)}{f(x_2)-f(x_1)}
$$
然后按题意模拟即可。

```c++
#include <bits/stdc++.h>
#define db double
db f(db x)
{
    return x*x*x-5*x*x+16*x-80;
}
db xpoint(db x1, db x2)
{
    return (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
}
db root(db x1, db x2)
{
    db x=xpoint(x1,x2);
    if(fabs(f(x))<0.0001)
    {
        return x;
    }
    if(f(x)*f(x1)>0)
    {
        return root(x,x2);
    }
    if(f(x)*f(x2)>0)
    {
        return root(x1,x);
    }
}
signed main()
{
    db x1=1,x2=1;
    while(1)
    {
        scanf("%lf%lf",&x1,&x2);
        if(f(x1)*f(x2)>0)
        {
            printf("reinput:");
            continue;
        }
        break;
    }
    printf("%lf",root(x1,x2));
    return 0;
}
```



##### Strange function

> 有t组询问，求$6x^7+8x^6+7x^3+5x^2-yx$在$[0,100]$的最小值(保留四位小数)

(个人分析)，$f''(x)>0$，所以$f'(x)$单调递增，所以$f(x)$至多有一个极值点，不会出现卡在极值到不了最值的"机器学习梯度下降"问题，可以用二分法。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
double k[][8] = { { 0,0,5,7,0,0,8,6 },{ 0,10,21,0,0,48,42,0 }};
double lf, rf, cf, y, ans;
ll t;
inline double f(double x, ll d)
{
	double a = k[d][7];
	rede(i, 6, 0) a = a * x + k[d][i];
	return a;
}
signed main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf", &y);
		k[0][1] = k[1][0] = -y;
		lf = 0, rf = 100;
		while (rf - lf >= 1e-7)//精度太小会死
		{
			cf = (lf + rf) / 2;
			if (f(cf, 1) >= 0) rf = cf;
			else lf = cf;
		}
		printf("%.4lf\n", f(cf, 0));
	}
	return 0;
}
```

### 矩阵

#### 行列式

对于n阶矩阵，定义为：(p是一个排列，$\tau(p)$是p的逆序对数)
$$
\det(A)=|A|=\sum_p(-1)^{\tau(p)}\prod_{i=1}^na_{i,p_i}
$$

> 给定n阶行列式A,求$|A|$，结果对p取模

时间复杂度是$\Omicron(n^2(\log p+n))$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 602
ll a[mn][mn], n, p, k, r = 1, fh, lf, j;
signed main()
{
	scanf("%d%d", &n, &p);
	repe(i, 1, n) repe(j, 1, n) scanf("%d", &a[i][j]), a[i][j] %= p;
	repe(i, 1, n)
	{
		k = i;
		orepe(j, i, n) if (a[j][i]) { k = j; break; }
		if (!a[k][i]) return printf("0") & 0;
		orepe(j, j + 1, n) if (a[j][i] && a[j][i] < a[k][i]) k = j;
		if (i != k) swap(a[k], a[i]), fh ^= 1;
		orepe(j, i + 1, n)
		{
			if (a[j][i] > a[i][i]) swap(a[j], a[i]), fh ^= 1;
			while (a[j][i])
			{
				lf = a[i][i] / a[j][i];
				orepe(k, i, n)
					a[i][k] = (a[i][k] + (ln)(p - lf) * a[j][k]) % p;
				swap(a[j], a[i]), fh ^= 1;
			}
		}
		r = (ln)r * a[i][i] % p;//ll暴死
	}
	printf("%d", fh ? ((p - r) % p) : r);
	return 0;
}
```

##### 例题

###### Cocoa's homework

> (scnucpc2020)有两长$n$的序列$A,B$(下标从$1$开始)，有一个数$w$，构建$n$阶矩阵如下：
> $$
> M_{i,j}=\begin{cases}w+a_ib_j&if\ i+j-1=n\\a_ib_j&otherwise\end{cases}
> $$
> 输入$n,q$，有$q$组命令，输入$A,B$，输入1 p x代表修改$a[p]=x$,2 p x代表$b[p]=x$,输入3 w代表在$w$下求矩阵的行列式对$10^9+7$取模。
>
> $2\le n,q\le10^5,|a_i|,|b_i|,|x|,|w|\le10^9,1\le p\le n$

da r-ro

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
#define mod 1000000007
#define mn 100002
il ll qpow(ll a, ll b)
{
	ll r = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (r *= a) %= mod;
	return r;
}
ll a[mn], b[mn], n, q, op, p, x, sum, sign;
signed main()
{
	n = read(), q = read();
	rede(i, n, 1) a[i] = read(); //矩阵交换n(n-1)/2次
	repe(i, 1, n) b[i] = read();
	sign = ((n * (n - 1) >> 1) & 1) ? -1 : 1;
	repe(i, 1, n) (sum += a[i] * b[i]) %= mod;
	while (q--)
	{
		op = read();
		if (op == 1)
		{
			p = read(), x = read(), p = n + 1 - p; //矩阵交换
			(sum += (x - a[p]) * b[p]) % mod, a[p] = x;
		}
		else if (op == 2)
		{
			p = read(), x = read();
			(sum += (x - b[p]) * a[p]) % mod, b[p] = x;
		}
		else
		{
			x = read();
			printf("%lld\n", (sign * (sum + x) * qpow(x, n - 1) % mod + mod) % mod);
		}
		(sum += mod) %= mod; //qwq 之前加的可能是负数
	}
	return 0;
}
```



#### 矩阵求逆

> 对$N\times N$矩阵求逆(答案对$10^9+7$取模)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 402
#define MOD 1000000007
ll n, m, f[MAXN][MAXN << 1], r, ret;
ll inv(ll u, ll v)
{
	for (ret = 1; v; u = u * u % MOD, v >>= 1) if (v & 1)
		ret = ret * u % MOD;
	return ret;
}
signed main()
{
	scanf("%d", &n), m = n << 1;
	repe(i, 1, n)
	{
		repe(j, 1, n) scanf("%lld", &f[i][j]);
		f[i][n + i] = 1;
	}
	repe(i, 1, n)
	{
		repe(j, i, n) if (f[j][i])
		{
			repe(k, 1, m) swap(f[i][k], f[j][k]);
			break;
		}
		if (!f[i][i]) return !printf("No Solution");
		r = inv(f[i][i], MOD - 2);
		repe(j, i, m) f[i][j] = f[i][j] * r % MOD;
		repe(j,1,n) if (j != i)
		{
			r = f[j][i];
			repe(k, i, m) f[j][k] = (f[j][k] - r * f[i][k] % MOD + MOD) % MOD;
		}
	}
	repe(i, 1, n)
	{
		repe(j, n + 1, m) printf("%lld ", f[i][j]);
		printf("\n");
	}
	return 0;
}
```

#### 高斯消元

给定一个n元线性方程组，求解。

一般使用优化的Gauss-Jordan消元法，复杂度$\Omicron(n^3)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define limn 102
db a[limn][limn];
ll n;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) repe(j, 1, n + 1) scanf("%lf", &a[i][j]);
	repe(i, 1, n)
	{
		ll mx = i;
		repe(j, i + 1, n) if (fabs(a[j][i]) > fabs(a[mx][i])) mx = j;
		repe(j, 1, n + 1) swap(a[i][j], a[mx][j]);
		if (!a[i][i]) return !printf("No Solution");
		repe(j, 1, n) if(j!=i)
		{
			db tmp = a[j][i] / a[i][i];
			repe(k, i + 1, n + 1) a[j][k] -= a[i][k] * tmp;
		}
	}
	repe(i, 1, n) printf("%.2lf\n", a[i][n + 1] / a[i][i]);
	return 0;
}
```

##### 例题

###### Matrix Equation

> (icpc 45济南)链接：https://ac.nowcoder.com/acm/contest/10662/A
> 来源：牛客网
>
> We call a matrix "01 Square" if and only if it's a $N\times N$ and its elements are all 0 or 1.
>
>  For two 01 Squares X,Y, we define two operators $X\times Y$and$X\odot Y$. The value of them are also 01 Square matrices and calculated below(we use Z to abbreviate$X\times Y$ and D to abbreviate $X\odot Y$: 
>
> $Z_{i,j}=(\sum_{k=1}^{N}X_{i,k}Y_{k,j})~mod~2$
>
>  $D_{i,j}=X_{i,j}Y_{i,j}$
>  Now MianKing has two 01 Squares A,B, he wants to solve the matrix equation below:
>   $A\times C=B\odot C$
>  You need to help MainKing solve this problem by calculating how many 01 Squares C satisfy this equation.
> The answer may be very large, so you only need to output the answer module 998244353 1≤N≤200,$ A_{i,j},B_{i,j} \in \{0,1\}$

根据计算式的特点，能确保$C$元素互不相干的最小单元是一列，所以把一个列拿出来：
$$
\left[\matrix{a_{11}&a_{12}&\dots\\a_{21}&a_{22}&\dots\\\dots&\dots&\dots}\right]\times\left[\matrix{c_1\\c_2\\\dots}\right]=\left[\matrix{b_{1}c_1\\b_2c_2\\\dots}\right]
$$
展开，移项：
$$
\left[\matrix{a_{11}-b_1&a_{12}&\dots\\a_{21}&a_{22}-b_{2}&\dots\\\dots&\dots&\dots}\right]\times\left[\matrix{c_1\\c_2\\\dots}\right]=\left[\matrix{0\\0\\\dots}\right]
$$
对于上面的方程，定义运算法则为异或，求解关于$c_1,\dots,c_n$的方程组，求出有多少个自由元，自由元数目记为$k$，由于每个自由元取值为$0,1$，所以总的情况数为$2^k$，对每一列都如此操作即可，最后乘法原理搞起来。

代码如下：

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e2 + 7;
const int mod = 998244353;
int a[maxn][maxn];//增广矩阵
int x[maxn];//解集
int freeX[maxn];//自由变元
int n;
int A[maxn][maxn],B[maxn][maxn];
ll poww(ll a,ll b){
       ll ans=1;
       while(b > 0){
            if(b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;

       }
       return ans;
}
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
        freeX[i]=0;
    }
    int col=0;//当前处理的列
    int num=0;//自由变元的序号
    int row;//当前处理的行
    for(row=0;row<equ&&col<var;row++,col++){//枚举当前处理的行
        int maxRow=row;//当前列绝对值最大的行
        for(int i=row+1;i<equ;i++){//寻找当前列绝对值最大的行
            if(abs(a[i][col])>abs(a[maxRow][col]))
                maxRow=i;
        }
        if(maxRow!=row){//与第row行交换
            for(int j=row;j<var+1;j++)
                swap(a[row][j],a[maxRow][j]);
        }
        if(a[row][col]==0){//col列第row行以下全是0，处理当前行的下一列
            freeX[num++]=col;//记录自由变元
            row--;
            continue;
        }
        for(int i=row+1;i<equ;i++){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;j++){//对于下面出现该列中有1的行，需要把1消掉
                    a[i][j]^=a[row][j];
                }
            }
        }
    }
    for(int i=row;i<equ;i++)
        if(a[i][col]!=0)
            return -1;
    int temp=var-row;//自由变元有var-row个
    if(row<var)//返回自由变元数
        return temp;
    return 0;
}
void init() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            a[i][j] = A[i][j];
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&A[i][j]);
            a[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&B[i][j]);
        }
    }
    ll ans = 1;
    for(int r = 0;r < n; r ++){
        init();
        for(int i = 0; i < n; i ++){
            a[i][i] = (A[i][i] - B[i][r] + 2) % 2;
        }
        int freeNum=Gauss(n,n);//获取自由元
        if(freeNum == -1) continue;
        ans = (ans  *  poww(2 , freeNum)) % mod;
    }
    printf ("%lld\n",ans);
    return 0;
}
```

个人版本：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ln;
typedef int ll;
#define mn 210
#define mod 998244353
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define sc(x) scanf("%d",&x)
ll n,a[mn][mn],b[mn][mn],d[mn][mn],x[mn],fx[mn]; ln ans=1;
ln qpow(ln a, ln b)
{
    ln r=1;
    for(;b;b>>=1,(a*=a)%=mod) if(b&1) (r*=a)%=mod;
    return r;
}
ll gauss(ll eqn, ll varn)
{
    repe(i,0,varn) x[i]=fx[i]=0;
    ll col=0,num=0,row=0,mxrow=0;
    for(;row<eqn&&col<varn;++row,++col)
    {
        mxrow=row;
        rep(i,row+1,eqn) if(fabs(d[i][col])>fabs(d[mxrow][col])) mxrow=i;
        if(mxrow!=row) swap(d[row],d[mxrow]);
        if(!d[row][col]) {fx[num++]=col; --row; continue;}
        rep(i,row+1,eqn) if(d[i][col]) repe(j,col,varn) d[i][j]^=d[row][j];
    }
    rep(i,row,eqn) if(a[i][col]) return -1;
    return max(0,varn-row);
}
signed main()
{
    sc(n);
    rep(i,0,n) rep(j,0,n) sc(a[i][j]);
    rep(i,0,n) rep(j,0,n) sc(b[i][j]);
    rep(r,0,n)
    {
        rep(i,0,n) rep(j,0,n) d[i][j]=a[i][j];
        rep(i,0,n) d[i][i]=(d[i][i]-b[i][r]+2)%2;
        ll fn=gauss(n,n);
        if(fn==-1) continue;
        (ans*=qpow(2,fn))%=mod;
    }
    return printf("%lld",ans),0;
}
```



### 进制

R进制数的算术求和和求积各有$\frac{R(R+1)}2$种。

#### 读二进制文本转化为整形

```c
int readint()//readchar见前面章节；‘0’为48
{
    int v = 0;
    while(c--) v = v * 2 + readchar() - 48;
}
```

#### 负整数进制

以负二进制到负二十进制为例

```c++
#include <bits/stdc++.h>
using namespace std;
string x="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",y;
int n,k,m;
void f()//其实用递归更好，在return前cout，省去string y和reverse
{
    if(!n) return;
    m=n%k;
    if(m<0)//除数、余数的变换，化负
    {
        m-=k;
        n+=k;
    }
    n/=k;
    y+=x[m];
    f();
    return;
}
int main()
{
    cin>>n>>k;
    cout<<n<<'=';
    f();
    reverse(y.begin(),y.end());
    cout<<y<<"(base"<<k<<")";
    return 0;
}
```

证明：

$（商+1）*除数+（余数-除数） \\
=商*除数+除数+余数-除数 \\ =商*除数+余数
\\=被除数$

#### 例题

##### 小计算器

> 实现一个任意进制的加减乘除和取模的正整数运算计算器(原题干见蓝桥杯)

个人实现版本：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
ll now, k = 10, n, numlen, temp, j, ki, mode = 1, wno, wl, wt;
char cmd[10], num[80], cc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ans[80];
void get()
{
	temp = 0, ki = 1;
	scanf("%s", num);
	numlen = strlen(num);
	rede(i, numlen - 1, 0)
	{
		if (num[i] >= 'A' && num[i] <= 'Z') j = num[i] - 'A' + 10;//注意+10
		else j = num[i] - '0';
		temp += j * ki;
		ki *= k;
	}
}
signed main()
{
	for (scanf("%lld", &n); n; --n)
	{
		scanf("%s", cmd);
		if (cmd[0] == 'N')
		{
			get();
			if (mode == 1) now += temp;
			else if (mode == 2) now -= temp;
			else if (mode == 3) now *= temp;
			else if (mode == 4) now /= temp;
			else if (mode == 5) now %= temp;
			mode = 0;
		}
		else if (cmd[0] == 'A')
		{
			mode = 1;
		}
		else if (cmd[0] == 'S')
		{
			mode = 2;
		}
		else if (cmd[0] == 'M')
		{
			if (cmd[1] == 'U') mode = 3;
			else mode = 5;
		}
		else if (cmd[0] == 'D')
		{
			mode = 4;
		}
		else if (cmd[0] == 'E')
		{
			wl = 0, wno = now;
			while (wno)
			{
				wt = wno % k;
				ans[wl++] = cc[wt];
				wno /= k;
			}
			rede(i, wl - 1, 0) putchar(ans[i]); 
			if (!wl) printf("0"); putchar('\n');//注意特判0
		}
		else if (cmd[0] == 'C')
		{
			if (cmd[1] == 'L') now = 0, mode = 1;
			else scanf("%lld", &k);
		}
	}
	return 0;
}
```

##### 倒数第N个字符串

> (天梯)给定$l,n(2\le l\le6,1\le n\le10^5)$，求长为l的倒数第$n$个字符(如l=3第27个是zyz)

###### 循环

```c++
#include <bits/stdc++.h>
using namespace std;
int l,n;
string x;
signed main()
{
    scanf("%d%d",&l,&n);--n;
    for(int i=0;i<l;++i)
    {
        x=(char)('z'-n%26)+x;
        n=n/26;
    }
    cout<<x;
	return 0;
}
```

###### 递归

```c++
#include <bits/stdc++.h>
using namespace std;
int l,n;
void f(int i, int n)
{
    if(i>=l) return;
    f(i+1,n/26);
    printf("%c", 'z'-n%26);
}
signed main()
{
    scanf("%d%d",&l,&n);
    f(0, n-1);
	return 0;
}
```



##### 年号字串

> (蓝桥)用A对应1，Z对26，AA27，以此类推……求2019。

显然是一个二十六进制题目。直接套即可。(BYQ)

> 一种偏方：可以直接开一个Excel(蓝桥杯不限制解题方法)

##### Excel地址

> (蓝桥)给定一个int内的整数，求其Excel列地址

还是一个二十六进制问题。问题在于0不是A，所以不能直接搞进制转换。

###### 解法一：-1

```c++
#include <bits/stdc++.h>
int n;
std::string x;
signed main()
{
    for(scanf("%d",&n);n;n=(n-1)/26) x=(char)('A'+(n-1)%26 )+x;
    return std::cout<<x,0;
}
```

###### 解法二：消阶

(个人解法)有多少位数就把多少位之前的所有情况减一下，之后就可以套进制转换了。

```c++
#include <bits/stdc++.h>
typedef long long ll;
ll bas[8],x,tp[8],logx,i;
char ans[8];
signed main()
{
	bas[1]=tp[1]=26,tp[0]=1;
	for(int i=2;i<8;++i) tp[i]=tp[i-1]*26,bas[i]=bas[i-1]+tp[i];
	scanf("%lld",&x); --x;
	for(logx=0;x>=bas[logx];++logx);
	x-=bas[--logx];
	for(i=logx;i>=1;--i)
	{
		ans[i]='A'+x%26;
		x/=26;
		if(x<26) break;
	}
	--i; if(i<0) i=0;
	ans[i]='A'+x;
	while(i>0) ans[--i]='A';
	printf("%s",ans);
	return 0;
}
```



### 杂项

#### 集合

##### 子集和

$sumz=sum*2^{n-1}, n为集合元素数$

如集合：1,2,3，其子集和为6*4=24

#### 牛顿法

##### 开平方

x(n+1) = 0.5(x(n)+ a/x(n))

```c
double sqrt(double x)
{
    if(x>100) return 10. * sqrt(x/100);
    double t = x/8+0.5+2*x/(4+x);
    int c=10;
    while(c--) t = t(t+x/t)/2;
    return t;
}
```

注：假如一个数有偶数位n，那么这个数的方根有n/2位；如果n为奇数，那么方根为（n+1）/2位。

#### 积分

##### 自适应辛普森法

$$
\int_a^bf(x)dx\approx\frac{(b-a)(f(a)+f(b)+4f(\frac{a+b}{2}))}{6}​
$$

以求不定积分$\int_L^R\frac{cx+d}{ax+b}dx$为例：

```c++
#include <bits/stdc++.h>
double a,b,c,d,l,r;
inline double f(double x) {
	return (c*x+d)/(a*x+b);       //原函数
}
inline double simpson(double l,double r) {      //Simpson公式
	double mid=(l+r)/2;
	return (f(l)+4*f(mid)+f(r))*(r-l)/6;
}
double asr(double l,double r,double eps,double ans) {
	double mid=(l+r)/2;
	double l_=simpson(l,mid),r_=simpson(mid,r);
	if(fabs(l_+r_-ans)<=15*eps) return l_+r_+(l_+r_-ans)/15;     //确认精度
	return asr(l,mid,eps/2,l_)+asr(mid,r,eps/2,r_);     //精度不够则递归调用
}
inline double asr(double l,double r,double eps) {
	return asr(l,r,eps,simpson(l,r));
}
int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r);
	printf("%.6lf",asr(l,r,1e-6));
	return 0;
}
```

> 注意，在退化版算法：使用变步长梯形积分算法时，即：
> $$
> T_n=\sum_{k=1}^{n-1}\frac h2[f(x_k)+f(_{k+1})]
> $$
> 二分一次：
> $$
> \frac h2[f(x_k)+f(_{k+1})]=\frac h4[f(x_k)+2f(x_{k+\frac12})+f(x_{k+1})]
> $$
> 得：
> $$
> T_2n=\frac h4\sum_{k=0}^{n-1}[f(x_k)+f(x_{k+1})]+\frac h2\sum_{k=0}^{n-1}f(x_{k+\frac12})
> $$
>
> $$
> T_2n=\frac12T_n+\frac h2\sum_{k=0}^{n-1}f(x_{k+\frac12})
> $$
>
> 直到下一项跟上一项作差小于误差，停止递推。
>
> 如果积分上下限a,b及其积分中点的取值都一样，有可能会直接输出一个矩形面积，造成错误答案，如果为值0，计算答案就是0

#### 位运算

##### 线性基

###### the missing integer

> (oj)给定$[0,m]$的$m+1$个连续递增整数且缺失其中一个，求这个缺失值。要求$\Omicron(m)$。

个人解法：所求为$\dfrac{m(m+1)}2-\sum a$，即前$m$项和减去输入。缺点是求和过程可能爆。

更优解：存下标，则不缺失的数一定下标和值都出现一次，即异或为$0$。那么异或累积，最后的结果就是缺失值。

###### 例题(线性基)

> 求n个数中选任意个得到的最大异或和

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll n, ans, a, p[64];
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) 
	{
		scanf("%lld", &a);
		rede(j, 62, 0)
		{
			if (!(a >> j)) continue;
			if (!p[j])
			{
				p[j] = a;
				break;
			}
			a ^= p[j];
		}
	}
	rede(i, 62, 0) if ((ans ^ p[i]) > ans) ans ^= p[i];
	printf("%lld", ans);
	return 0;
}
```

#### 求和

##### 全求和

```c
int sum(int* a, int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i];
    return ans;
}
```

##### 部分求和

```c
//求a[begin:end]（即[begin,end)的和）
//写法一
int sum(int* begin; int* end)
{
    int n = end - begin;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += begin[i];
    return ans;
}
//写法二
int sum(int* begin; int* end)
{
    int ans = 0;
    for(int *p = begin; p != end; p++)
        ans += *p;
    return ans;
}
```

#### 取整

##### 向上取整

```c
int ceil(int a, int b) {return (a+b-1)/b;}
```

#### 数列

> 一般而言，知道多项式递推关系，可以使用矩阵加速求解。详见快速运算-递推式。

##### 等差数列

###### 通项

$$
a_n=a_1+(n-1)\times d
$$

###### 前n项和

$$
S_n=na_1+\frac{n(n-1)}2d=(a_1-\frac d2)n+\frac{dn^2}2\\
S_n=\frac{n(a_1+a_n)}2
$$

###### 其他性质

##### 等比数列

###### 通项

$$
a_n=a_1q^{n-1}
$$

###### 前n项和

$$
S_n=\frac{a_1(1-q^n)}{1-q}
$$

###### 其他性质

##### 例题

###### 数字游戏

> (蓝桥)n人一圈轮流报数，栋栋首先说1，接下来一个人数一次再说出这个数，在接下来数两次……如果数到k-1时，下一次为0，栋栋说了t个数，求它们的和，$1\le n,k,t\le1000000$

显然模拟的复杂度是$\Omicron(nt)$会炸，要使用等差数列，这个数列公比是1，理论上每次的变化值(未取模时)可以用前缀和式和单独式：
$$
\frac{a(a+1)}2-\frac{(a-n)(a-n+1)}2,a_0=1,a=a+n
$$

$$
\frac{(l+r)\times n}2,l_0=1,r_0=n,l=l+n,r=r+n
$$

根据实际代码，发现朴素的前者无法通过最后一个测试点(($(nt)^2$)炸了long long)，而公式二可以通过。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,r,s=1;
signed main()
{
	scanf("%lld%lld%lld",&n,&k,&t);//把n看成t暴死一次
	for(ll i=1,lf=1,rf=n;i<t;++i)
	{
		(s+=(lf+rf)*n>>1)%=k;
		r+=s,lf+=n,rf+=n;
	}
	printf("%lld",r+1%k);
	return 0;
}
```

使用快速乘，可以使用公式一，由于快速乘复杂度较高使得总复杂度为$\Omicron(n\log n)$，对于该题，刚刚好能过(最大数值是1s的计算量)。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,a,abf,r,s=1;
inline ll qmul(ll a, ll b) //(a+b)/2;在本题显然a,b一奇一偶 
{
	ll r=0;
	if(a&1) b>>=1; else a>>=1;
	for(;b;b>>=1,(a+=a)%=k) if(b&1) (r+=a)%=k;
	return r;
} 
signed main()
{
	scanf("%lld%lld%lld",&n,&k,&t);
	for(ll i=1;i<t;++i)
	{
		abf=a,a+=n;
		(s+=qmul(a+1,a)-qmul(a+1-n,a-n))%=k;
		r+=s;
	}
	printf("%lld",r+1%k);
	return 0;
}
```

事实上，上述代码可以简化为：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,r;
inline ll qmul(ll a, ll b) //(a+b)/2;在本题显然a,b一奇一偶 
{
	ll r=0;
	if(a&1) b>>=1; else a>>=1;
	for(;b;b>>=1,(a+=a)%=k) if(b&1) (r+=a)%=k;
	return r;
} 
signed main()
{
	scanf("%lld%lld%lld",&n,&k,&t); t=t*n+1;
	for(ll i=1;i<t;i+=n) r+=1+qmul(i,i-1)%k;
	printf("%lld",r);
	return 0;
}
```

###### 蛇形填数

> (蓝桥)按如下规律填数，求第20行20列的数：
> $$
> \left[\matrix{1&2&6&7&15&\dots\\3&5&8&14&\dots\\
> 4&9&13&\dots\\10&12&\dots\\11&\dots\\\dots}\right]
> $$

解法一：由于题目要求数据量小，直接模拟即可。

个人模拟方法：

```c++
#include <bits/stdc++.h>
int m[50][50],i=1,j=1,d=1,cnt;
signed main()
{
	while(1)
	{
		m[i][j]=++cnt;
		if(i==20&&j==20) return printf("%d",cnt),0;
		if(d) --i,++j;
		else ++i,--j;
		if(!i) i=1,d=0;
		else if(!j) j=1,d=1;
	}
	return 0;
}
```

其他方法：

```c++
#include<bits/stdc++.h>
using namespace std;

int mp[200][200], row = 0, col = 0, cnt = 1;

int main() {
    mp[0][0] = 1;
    while(!mp[19][19]) {
        //右移
        mp[row][++col] = ++cnt;
        //左下方
        while(col) {
            mp[++row][--col] = ++cnt;
        }
        //下移
        mp[++row][col] = ++cnt;
        //右上方
        while(row) {
            mp[--row][++col] = ++cnt;
        }
    }
    /*for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cout << mp[i][j] << "  ";
        }
        cout << endl;
    }*/
    cout << mp[19][19];
    return 0;
}
```

解法二：找规律法

找出第一行的规律，然后其他行的数字可以由第一行直接推出。规律比较简单，不作证明。个人规律：

```c++
#include <bits/stdc++.h>
int col(int j)
{
	int c=(j-1>>1)+1;
	return 1+j/2+2*c*(c-1);
}
int cal(int i, int j)
{
	if(!((i+j)&1)) return col(j+i-1)-i+1;
	else return col(j+i-1)+i-1;
}
signed main()
{
	printf("%d",cal(20,20));
	return 0;
}
```

#### 日期

闰年判定略。

##### 天数

天数差模板：

```c++
int bfmo[]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};
inline bool isleap(int y){return y%4==0&&y%100||y%400==0;}
inline int days(int y, int m, int d)
{
    int y2=y-1;
    int t=365*y2+y2/4-y2/100+y2/400+bfmo[m]+d;
    if(m>2&&isleap(y)) ++t;
    return t;
}
printf("%d",days(2021,4,2)-days(2021,3,31)); //2
```

根据天数差和零点推日期暂未发现直接的公式，需要按月模拟

> 可以考虑零点转绝对零点，然后加上天数差，然后想办法

##### 星期

`W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7`

注意月份取值范围为$[3,14]$，即一月二月算上一年的$13,14$月。

##### 例题

###### 2038年问题

> 4字节的时间格式把1970年1月1日凌晨0时0分0秒作为时间起点，这时的时间值为0，单位是秒。有$t(\le 10^3)$组询问，给定一个$n(\le32)$位变量和零点时间(年月日时分秒)，求这个变量能表示的最大时间(年月日时分秒)

模拟题。注意复杂度的分析：$n$最大时，最多有大约$828$月，所以按月模拟的时间复杂度近似为$\Omicron(828t)$，可以通过。

> 当然可以叠各种神奇的标准库过题……

```c++
ll t,v,a,b,c,d,e,f,st,day,lp,dt[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
il void leap(ll a) {dt[2]=a%4==0&&a%100!=0||a%400==0?29:28;}
signed main()
{
    t=read();
    while(t--)
    {
        v=read(),a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
        f+=(1<<(v-1))-1; st=f/60; f%=60; e+=st;
        st=e/60; e%=60; d+=st;
        st=d/24; d%=24; c+=st; leap(a);
        while(c>dt[b])
        {
            c-=dt[b];
            ++b;
            if(b>12) b=1,++a,leap(a);
        }
        printf("%lld %lld %lld %lld %lld %lld\n",a,b,c,d,e,f);
    }
    return 0;
}
```

python标准库解法：

```python
from datetime import *
for _ in range(int(input())):
    n,a,b,c,d,e,f=[int(i) for i in input().strip().split()]
    x=datetime(a,b,c,d,e,f)+timedelta(seconds=(1<<(n-1))-1)
    print('%d %d %d %d %d %d'%(x.year,x.month,x.day,x.hour,x.minute,x.second))
```

> C标准库解法见C知识网络



#### 统计

##### 例题

###### 付账问题

> (蓝桥)n个人共消费s元，各带了$a_i$元，使得付钱的标准差最小，求这个最小值。
>
> ($n\le5\times10^5,0\le a_i\le10^9$)

思维题。题给的标准差公式为：
$$
x=\sqrt{\frac1n\sum_{i=1}^n(b_i-\frac1n\sum_{i=1}^nb_i)^2}
$$
实质上化为：
$$
x=\sqrt{\frac1n\sum_{i=1}^n(b_i-\frac sn)^2}
$$
注意到有人不付钱并不代表他不算入n，所以穷得少于平均数的人也要付全部的钱。

```c++
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
ll n,s,a[500002];
db avg,sum,cav;
signed main()
{
    scanf("%lld%lld",&n,&s); avg=1.*s/n;
    for(int i=1;i<=n;++i) scanf("%lld",a+i);
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        if(a[i]*(n+1-i)<s)//避免double运算(a[i]<s/(n+1-i))
        {
            sum+=(a[i]-avg)*(a[i]-avg);
            s-=a[i];//这个人欠下的钱会让后面的人支付的平均值增高
        }
        else//如果目前最穷的人出得起目前平均值，那么后面的人都出得起
        {
            cav=1.*s/(n+1-i);
            sum+=(cav-avg)*(cav-avg)*(n+1-i);
            break;
        }
    }
    return printf("%.4lf",sqrt(sum/n)),0;
}
```



#### 期望

期望题目或概率题目。

##### 例题

###### 音乐鉴赏

> 有n个分数(高于90小于100)，最终成绩为$分数\times(1-w)+w\times t$,t是$[0,90]$的随机值，使得最终只有$10\%$的人高于90分，求$w$

不要使用二分法。可以直接推导。//da uds

设高于$90$分概率为$p$，最后分数为$s$：
$$
s=t\times w+(1-w)\times a_i \ge90\Rightarrow t\ge\frac{90-(1-w)a_i}w\\
p_i=\frac{90-t}{90}\\
n\sum p_i=0.1\times n\Rightarrow y=\frac{90\times n-sum}{81\times n-sum}
$$

```c++
#include <bits/stdc++.h>
int n; 
long long s,v;
signed main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lld",&v),s+=v;
	return printf("%.2lf",100*(90.*n-s)/(81.*n-s))&0;//记得81.
}
```

###### 牛牛与牛妹的RMQ

> (oj)给定长为n的数组a，设$RMQ(L,R)=\max_{i=L}^Ra_i$，有m次询问，每次询问输入k和k个数$p_i$，然后可以有放回地随机抽取两个数$p_x,p_y(p_x\le p_y)$，求$RMQ(p_x,p_y)$有多少种情况及其概率(输出既约分数)。
>
> $1\le n,k\le 10^5,1\le a_i\le n,\sum k\le2\times10^5,1\le m\le2\times10^5$

**解法1**

注意到抽取k个数p可能会有$k^2$种情况。

情况一：$x=y$，搜索结果是单点查询，直接访问数组a即可。

情况二：$x\neq y$，对p排序后，定义小区间搜索结果：
$$
pp[i]=RMQ(p[i],p[i+1]),i\le k
$$
可以得知，所有其他区间的搜索结果不会在$pp[i]$之外。且显然这个$RMQ$可以使用线段树、树状数组或ST表维护。

可以使用$\Omicron(k)$的复杂度遍历$pp[i]$，并计算除自己之外跟自己结果相同的其他区间的数目。可以得知相同的情况仅当向左向右拓展后的结果不大于自己。

可以使用单调栈维护两个数组l[i],r[i]。l[i]为pp[i]左边第一个值大于它的下标,r[i]为pp[i]右边第一个值大于它的下标。且为维护方便，设$pp[0]=pp[k]=\infty$。

假设所有查询结果$pp[i]$互异，那么可以计算查询结果与每个$pp[i]$等价的区间数量。

①大区间的左右端点都不是i：左范围$\times$右范围

②大区间左或右端点是i：$(左范围+右范围)$

③大区间是小区间：$1$

由于是无序对，上述情况需要都乘以二。

如果$pp[i]$与$pp[i+1]$相同，可以缩点为一个点。可以证明一片相同时，这种做法不重不漏（da j）。此时最终结果见代码：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
ll a[MAXN], l[MAXN], r[MAXN], p[MAXN], pp[MAXN];
ll tree[MAXN << 2];
ll n, m;

void btree(ll k, ll l, ll r)
{
    if (l == r)
    {
        cin >> tree[k];
        a[l] = tree[k];
        return;
    }
    ll mid = (l + r) >> 1;
    btree(k << 1, l, mid);
    btree(k << 1 | 1, mid + 1, r);
    tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}

ll query(ll k, ll l, ll r, ll x, ll y)
{
    if (x <= l && y >= r)
    {
        return tree[k];
    }
    ll mid = (l + r) >> 1;
    ll res = 0;
    if (x <= mid)
        res = query(k << 1, l, mid, x, y);
    if (y > mid)
        res = max(res, query(k << 1 | 1, mid + 1, r, x, y));
    return res;
}

void solve()
{
    ll k;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> p[i];
    sort(p + 1, p + 1 + k);

    // 把第二类数给查询出来
    for (int i = 1; i < k; i++)
    {
        pp[i] = query(1, 1, n, p[i], p[i + 1]);//,printf("zz %d %d\n",i,pp[i]);
    }

    pp[0] = pp[k] = INF;

    // 单调栈
    stack<ll> q;
    for (int i = 1; i < k; i++)
    {
        l[i] = 0, r[i] = k;
    }

    q.push(0);

    for (int i = 1; i < k; i++)
    {
        while (q.size())
        {
            if (pp[i] >= pp[q.top()])
                q.pop();
            else
            {
                // 第一个既在 pp[i] 左边，又大于 pp[i] 的数的下标
                l[i] = q.top();
                //printf("xx %d %d\n",i,l[i]);
                break;
            }
        }
        q.push(i);
    }
    while (q.size())
        q.pop();

    q.push(k);

    for (int i = k - 1; i >= 1; i--)
    {
        while (q.size())
        {
            if (pp[i] >= pp[q.top()])
                q.pop();
            else
            {
                // 第一个既在 pp[i] 右边，又大于 pp[i] 的数的下标
                r[i] = q.top();
                //printf("yy %d %d\n",i,r[i]);
                break;
            }
        }
        q.push(i);
    }
    map<ll, ll> mp;

    // 计算第二类数的情况数
    for (ll i = 1; i < k; i++)
    {
        // 两个区间的 RMQ 恰好都在同一位置则一并计算
        ll j = (i + 1 < k && pp[i] == pp[i + 1]) ? (i + 1) : i;

        // 从 l[i] + 1 到 i - 1 任意选，i - l[i] - 1 种情况
        // 从 j + 1 到 r[j] - 1 任意选，r[j] - j - 1 种情况
        mp[pp[i]] += 2ll * ((r[j] - j - 1) * (i - l[i] - 1));

        // 从 i 到 j 任意选，j - i + 1 种情况
        // 从 j + 1 到 r[j] - 1 或从 l[i] + 1 到 i - 1 任意选，r[j] - j + i - l[i] - 2 种情况
        mp[pp[i]] += 2ll * (j - i + 1) * (r[j] - j + i - l[i] - 2);

        // i == j: 仅选择 pp[i] 所在的那个小区间，共两个端点
        // i != j: 仅选择夹住 pp[i] 的那两个小区间，共三个端点
        mp[pp[i]] += (i == j) ? 2 : 6;

        i = j;
    }

    // 计算第一类数的情况数
    for (int i = 1; i <= k; i++)
    {
        mp[a[p[i]]]++;
    }

    for (auto it : mp)
    {
        ll x = it.second;
        ll y = 1ll * k * k;
        cout << it.first << " " << x / __gcd(x, y) << "/" << y / __gcd(x, y) << '\n';
    }
}

int main()
{
    cin >> n;

    // 对 a[] 建线段树
    btree(1, 1, n);

    cin >> m;
    while (m--)
    {
        solve();
    }
}
```

**解法2**

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
#define repe(i,a,b) for(ll i=a;i<=b;++i)
typedef long long ll;
inline ll read()
{
    char p = 0; ll r = 0, o = 0;
    for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
    return o ? (~r) + 1 : r;
}
ll gcd(ll x, ll y) {return y?gcd(y,x%y):x;}
ll n,a[mn],m,k,p[mn],st[mn][18],k2,tmp;
struct rng{ll l,r,u,a;} r[mn];
ll query(ll lf, ll rf)
{
    ll j=0,x,y;
    while(1<<(j+1)<(rf+1-lf)) ++j;
    x=st[lf][j],y=st[rf-(1<<j)+1][j];
    return a[x]>a[y]?x:y;
}
signed main()
{
    n=read();
    repe(i,1,n) a[i]=read(); ++n; a[n]=n;
    repe(i,1,n) st[i][0]=i;
    for(ll j=1,x,y;(1<<j)<=n;++j) for(ll i=1;i-1+(1<<j)<=n;++i)
    {
        x=st[i][j-1],y=st[i+(1<<(j-1))][j-1];
        st[i][j]=a[x]>a[y]?x:y;
    }
    for(m=read();m;--m)
    {
        stack<ll> s;
        map<ll,ll> res;
        k=read(); k2=k*k;
        repe(i,1,k) p[i]=read(); p[k+1]=n;
        sort(p+1,p+2+k);
        repe(i,1,k)
        {
            r[i].l=i,r[i].r=i+1,r[i].a=query(p[i],p[i+1]);
            r[i].u=(r[i].a==p[i]?i:i+1);
            while(!s.empty()&&a[r[i].a]>a[r[s.top()].a])
            {
                rng &rip=r[s.top()]; s.pop();
                rip.r=r[i].l;
                if(s.empty()) r[i].l=rip.l;
                if(p[rip.u]==rip.a)
                    res[a[rip.a]]+=((1+rip.u-rip.l)*(rip.r-rip.u+1)-1)<<1;
                else
                    res[a[rip.a]]+=((rip.u-rip.l)*(rip.r-rip.u+1))<<1;
            }
            if(!s.empty()&&a[r[i].a]==a[r[s.top()].a])
                r[s.top()].r=r[i].r;
            else
            {
                if(!s.empty()&&a[r[i].a]<a[r[s.top()].a])
                    r[i].l=r[s.top()].r;
                s.push(i);
            }
        }
        repe(i,1,k) ++res[a[p[i]]];
        for(auto it=res.begin();it!=res.end();++it)
        {
            tmp=gcd(it->second,k2);
            printf("%lld %lld/%lld\n",it->first,it->second/tmp,k2/tmp);
        }
    }
    return 0;
}
```

###### 俄罗斯轮盘赌

> (csoj)有七种数量不同的左轮，分别有$0,1,\cdots,6$发连续放在弹槽的子弹，随机摆放，弹槽已经打乱。随机选$6$把左轮，依次连续按下$1,2,\cdots,6$下扳机，求活下来的概率的最简分式的$\frac pq\mod10^9+7$。

可以打表分析有$i$发子弹的左轮按$j$次的存活概率。然后DFS取七组，对应六发，有至多$7^6$个对应方法，经检验并未TLE。

对于选中的每一组，这个选法的概率为：组内选了多少把枪(组合数)除以多少把枪里选六把(总事件组合数)，然后再乘以这六次分别的概率，最后求和即可

> 很多离奇的细节可能会导致WA

```c++
ll n[7], p[7][7], psw[7][7], ns, pn6 = 1, ans, cnt[7], pick[7], i6;
void dfs(ll h)
{
    if (h == 7)
    {
        ll r = pn6;
        repe(i, 0, 6)
        {
            if (cnt[i] > n[i])
                return;
            (r *= p[i][cnt[i]]) %= mod;
        }
        repe(i, 1, 6)(r *= psw[pick[i]][i]) %= mod;
        (ans += r) %= mod;
        return;
    }
    repe(i, 0, 6)
    {
        ++cnt[i];
        pick[h] = i;
        dfs(h + 1);
        --cnt[i];
    }
}
signed main()
{
    repe(i, 0, 6) n[i] = read(), ns += n[i];
    i6 = qpow(6, mod - 2);
    rep(i, 0, 6)(pn6 *= (ns - i)) %= mod;
    pn6 = qpow(pn6, mod - 2);
    repe(i, 0, 6) p[i][0] = 1;
    repe(i, 0, 6) repe(j, 1, min(6LL, n[i]))
        p[i][j] = p[i][j - 1] * (n[i] - j + 1) % mod;
    repe(i, 0, 6) psw[i][0] = psw[0][i] = 1;
    repe(i, 1, 6) repe(j, 1, 6 - i) psw[i][j] = (7 - i - j) * i6 % mod;
    dfs(1);
    return printf("%lld", ans), 0;
}
```



#### 回文数

```python
#我的算法
def ispali(p):
    p=str(p)
    lsp=len(p)
    if lsp<=1:
        return 1
    for i in range(lsp//2):
        if p[i]!=p[-i-1]:
            return 0
    return 1
```

```c++
//算法2
bool pd_h(int x)
{

    int y=x,num=0;//int y=x,防止x被改变
    while (y!=0)
    {
        num=num*10+y%10;//上一次数字的记录进位再加上下一位数
        y/=10;
    } 
    if (num==x) return 1;
    else return 0;
}
```

如果是回文字符，用xr=x;xr=reverse(x.begin(),x.end())然后x==xr

生成回文数/日期要善用规律剪枝。

##### 例题

###### 回文数字

> (蓝桥)输入n，从小到大数位和为n的5或6位回文数；若无输出-1

其实本题可以用DFS搜索算法，也是我第一个想到的算法，但突然考虑到本题数据量极其小，大概是入门难度的题目，直接暴力求解就算出来了。

```c++
#include <bits/stdc++.h>
int n,fi,a,b,c;
signed main()
{
	scanf("%d",&n);
	for(a=1;a<=9;++a) for(b=0;b<=9;++b) for(c=0;c<=9;++c)
		if((a<<1)+(b<<1)+c==n)
			printf("%d%d%d%d%d\n",a,b,c,b,a),fi=1;
	for(a=1;a<=9;++a) for(b=0;b<=9;++b) for(c=0;c<=9;++c)
		if((a<<1)+(b<<1)+(c<<1)==n)
			printf("%d%d%d%d%d%d\n",a,b,c,c,b,a),fi=1;
	if(!fi) printf("-1");
	return 0;
}
```

###### 回文日期

> (蓝桥)给定一个八位数日期，求大于它的一个回文日期和一个ABABBABA日期。

由于回文日期至多有366个，所以连二分搜索都不需要了。

```c++
#include <bits/stdc++.h>
using namespace std;
int md[]={0,31,29,31,30,31,30,31, 31,30,31,30,31},n,pi,ai;
vector<int> pali,abab;
signed main()
{
	for(int mi=1;mi<=12;++mi)
	{
		for(int d=1;d<=md[mi];++d)
		{
			int y=d%10*1000+d/10*100+mi%10*10+mi/10;
			int dt=d+mi*100+10000*y;
			pali.push_back(dt);
			if(d%10==mi%10&&d/10==mi/10&&d%10!=d/10)
				abab.push_back(dt);
		}
	}
	sort(pali.begin(),pali.end());
	sort(abab.begin(),abab.end());
	scanf("%d",&n);
	for(int i=0;i<pali.size();++i) if(pali[i]>n)
	{
		printf("%d\n",pali[i]);
		break;
	}
	for(int i=0;i<abab.size();++i) if(abab[i]>n)
	{
		printf("%d",abab[i]);
		break;
	}
	return 0;
}
```

###### 最小回文数

> 求一个数比它大的最小回文数

```c++
#include <bits/stdc++.h>
using namespace std;
string n,np;
int i;
signed main()
{
	cin>>n; np=n.substr(0,n.size()>>1);
	for(int i=(n.size()-1)>>1;i>=0;--i) np+=n[i];
	if(np>n) return cout<<np,0; np[i=(n.size()-1)>>1]++;
	for(;i>0;--i)
	{
		if(np[i]>'9') ++np[i-1],np[i]='0';
		else break;
	}
	if(np[0]>'9') np[0]='0',np='1'+np;
	cout<<np.substr(0,np.size()>>1);
	for(int i=(np.size()-1)>>1;i>=0;--i) cout<<np[i];
	return 0;
}
```

#### 取数的任意位

##### 三位整数

``````c
//算法1(还行)
/*a,b,c代表个，十，百位;n是int三位数*/
a = n % 10
b = n/10%10//注意优先级
c = n/100
``````

```c
//算法2(不太好)
c=n/100
b=(n-c*100)/10
a=(n-c*100-b*10)
```

##### 任意位整数

``````c
int n;
    scanf("%d", &n);
    while (n)
    {//假设n只用于该用途，所以不用新的变量了
        printf("%d ", n%10);
        n/=10;
    }//每次print变量是一个位数
``````

注意：从个位递增，正整数均正，负整数均负，0不输出

## 数论

### 拓展欧几里得定理

exgcd或Extended Euclidean Alogirithm

作用为求下列关于$x,y$的不定方程的一组可行解：($a,b,x,y$都是整数)
$$
ax+by=(a,b)
$$

#### 裴蜀定理

又称贝祖定理（Bézout's lemma）,设$a,b\in\Z,ab\neq0$,则$\exist x,y\in\Z$：
$$
ax+by=(a,b)
$$

#### 费马小定理

$$
a,p\in Z,p质数，a\not\equiv0(\mod p)，则a^{p-1}\equiv1(\mod p)\\故：a^b\equiv a^{b\mod(p-1)}(\mod p)
$$

#### 实现

##### 递归

```c++
int Exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = Exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;//gcd(a,b)
}
```

##### 迭代

```c++
int gcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
```

#### 例题

##### 青蛙的约会

> 长为l的环，两蛙从x,y出发，每次移n,m单位，是否能相遇(到达同一点)，输出最小移动次数

题目即求一个最小的$k$，使得下式成立：
$$
x+km\equiv y+kn(\mod l)
$$
化简，得：
$$
x+km-(y+kn)=lz,z\in\Z\\
k(m-n)-lz=-(x-y)\\
令S=x-y,W=n-m，有：kW+lz=S
$$
构建方程：
$$
kW+lz=(W,l)
$$
根据拓展欧几里得定理，求出一组特解$k_j,z_j$，则通解为：
$$
k_i=k_j+\frac{t\times l}{(W,l)}
$$
显然有：
$$
k_j=k_{\min}+\frac{t\times l}{(W,l)}
$$
显然可以得出：
$$
k_\min=k_j\mod\frac l{(W,l)}
$$
则原解为：
$$
\frac{k_\min\times S}{(W,l)}
$$
故代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll ans, tx, ty, n, m, x, y, l, a, b;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	if (!b) { x = 1, y = 0; return a; }
	ans = exgcd(b, a % b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return ans;
}
signed main()
{
	scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
	b = n - m, a = x - y;
	if (b < 0) b = -b, a = -a;
	exgcd(b, l, tx, ty);//都是L不是壹
	if (a % ans != 0) printf("Impossible");
	else printf("%lld", ((tx * (a / ans)) % (l / ans) + (l / ans)) % (l / ans));
	return 0;
}
```

##### 小凯的疑惑

> 小凯有两种面额纸币，求在不找零的情况下无法准确支付的最小价值
> 面额$a,b\le10^9,a\bot b$

答案为$ab-a-b$，推导过程如下：

设k是无法支付最小值+1，显然k一定可以被支付。
$$
\exist x,y\ge0,ax+by=k
$$
由拓展欧几里得算法，算出一组下列方程的x最小解和y最小解：
$$
a(x-x')+b(y-y')=k\\
a(x-x'')+b(y-y'')=k
$$
让$x-x'<0,y-y''<0$，则答案为：
$$
a(x'-1)+b(y''-1)-1
$$
这种解法代码如下：

```c++
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
void ex_gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0; return;
    }
    ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
}
ll a, b;
int main(){
    cin >> a >> b;
    if(a > b) swap(a, b); 
    ll x, y;
    ex_gcd(a, b, x, y);
    if(x > 0){
        swap(a, b);
        swap(x, y);
    }
    ll tmp = (-x) / b;
    x = x + tmp * b;
    y = y - tmp * a;
    while(x < 0) x = x + b, y = y - a;
    while(x > 0) x = x - b, y = y + a;
    ll ans;
    ll xx2 = x + b;
    ans = a * (xx2 - 1) + b * (y - 1);
    cout << ans - 1 << endl;
    return 0;
}
```

继续推导（略，以后再填坑）

##### 二元一次不定方程

> 给定关于$x,y$的不定方程$ax+by=c$，若无解输出-1，若有正整数解($x,y>0$)，输出其数量，$x,y$的两最值。若仅有非正整数解，输出$x,y$的最小正整数值。有t个方程询问($t<2\times10^5$)。

容易发现，当且仅当$\gcd(a,b)|(ax+by)$时，原方程有解，

使用拓展欧几里得定理求下列方程的特解$x_0,y_0$：
$$
ax_0+by_0=\gcd(a,b)
$$
根据等式变换，可以得到：
$$
a\frac{x_0c}{\gcd(a,b)}+b\frac{y_0c}{\gcd(a,b)}=c
$$
因此原方程的一组特解$x_1,y_1$为：
$$
\begin{cases}
x_1=\frac{x_0c}{\gcd(a,b)}\\
y_1=\frac{y_0c}{\gcd(a,b)}
\end{cases}
$$
设$d\in\Q,da,db\in\Z$，对原方程变换，得：
$$
a(x_1+db)+b(y_1-da)=c
$$
可以得出$d_\min=\frac1{\gcd(a,b)}$时，$da,db\in\Z$，此时$\frac b{\gcd(a,b)},-\frac a{\gcd(a,b)}$是每组解之间最小的变化值，有：
$$
\begin{cases}
x=x_1+s\frac b{\gcd(a,b)}\\
y=y_1-s\frac a{\gcd(a,b)}
\end{cases},s\in\Z
$$
显然，$x,y$的单调性相反，$x,s$单调性相同。可以得出不等式：
$$
x>0\Rightarrow x\ge1\Rightarrow s\ge\frac{(-x_1+1)\gcd(a,b)}b\\
y>0\Rightarrow y\ge1\Rightarrow s\le\frac{(y_1-1)\gcd(a,b)}a
$$
因为$s\in\Z$，显然有：
$$
\lceil\frac{(-x_1+1)\gcd(a,b)}b\rceil\le s\le\lfloor\frac{(y_1-1)\gcd(a,b)}a\rfloor
$$
如果$s$无解，则原式无正整数解，则左右值分别是$x,y$最小值。

否则有正整数解，$s$个数为解个数。显然$s$最大时，$x$最大，$y$最小，反之亦然。

### 乘法逆元

modular multiplicative inverse，使用扩展欧几里得算法(extended Euclidean algorithm)求解

若一个线性同余方程$ax \equiv 1 (mod \ b)$，则x是amodb的逆元，记作a^-1^

//需要a,b互质

#### 单个逆元

```c++
void exgcd(int a, int b, int& x, int& y) {
  if (!b) x = 1, y = 0;
  else exgcd(b, a % b, y, x), y -= a / b * x;
}
//要得到正数解，用x=(x%b+b)%b即可,其中x代表a在b下的逆元
```

当Mod是素数时，满足费马小定理，可以用快速幂优化。(不满足就不可以)

```c++
ll fpm(ll x, ll power, ll mod) {
    x %= mod;
    ll ans = 1;
    for (; power; power >>= 1, (x *= x) %= mod)
    	if(power & 1) (ans *= x) %= mod;
    return ans;
}//第三个参数可以省(开全局)
int main() {
	ll x = fpm(a, p - 2, p); //x为a在mod p意义下的逆元
}
```

> 例题：p4942

#### 线性逆元

求1到n的所有逆元，时间复杂度O(n)

```c++
inv[1] = 1;
for (int i = 2; i <= n; ++i) {
  inv[i] = (long long)(p - p / i) * inv[p % i] % p;
}
//inv[0]不用管
```

#### 多个逆元

求不连续的任意逆元，时间复杂度O(n+logp)

```c++
s[0] = 1;
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
sv[n] = qpow(s[n], p - 2);
// 当然这里也可以用 exgcd 来求逆元,视个人喜好而定.
for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * a[i] % p;
for (int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;
```

#### 应用

求$\frac{a}{b} \  mod \  p$的值，其中p通常为质数；先求出b在modp下的逆元，再乘a即得该值

##### 高精度

> 假设取模p为质数，有两种方法：

1.开高精度(代码略)或用python

```python
a = int(input())
b = int(input())
p = 19260817
def fmp(x):
    pow = p - 2
    x%=p
    res = 1
    while pow:
        if pow & 1:
            res*=x
            res%=p
        pow>>=1
        x*=x
        x%=p
    return res
print('%d' % ((a % p * fmp(b % p)) % p))
```

2.从上述程序可以看出，a,b先取模了p，其结果必然不会大于long long(p不是高精度)，所以可以边读边取模：

```c++
#include<bits/stdc++.h>
#define IL inline
#define RI register int
#define mod 19260817
long long a,b,ans;
IL void read(long long &x){
	int f=1;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){x=x*10%mod+(s-'0')%mod;s=getchar();}//改成了取模~~
    x=x%mod*f;//改成了取模~
}
IL long long ksm(long long x,long long p)
{
	long long res=1;
	for(;p;p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}//快速幂
int main()
{
	read(a);read(b);
	if(b==0){printf("Angry!");return 0;}
    //注意这里 特判！ 不要忘记 还有 不要忘记感叹号！！！
	ans=a*ksm(b,mod-2);
	printf("%lld",(ans%mod+mod)%mod);
}
```



#### 例题

##### 乘法逆元2

> $$
> \sum_{i=1}^n\frac{k^i}{a_i}\mod p
> $$
>
> 其中$1\le n\le5\times10^6,2\le k<p\le10^9,p是质数$

由于输入庞大($5\times10^6$)，必须使用快读，否则如果用scanf都会超时。

对原式通分有：
$$
\sum_{i=1}^n\frac{k^i\times\frac{\prod_{j=1}^na_j}{a_i}}{\prod_{j=1}^na_j}
$$
使用正序和倒序前缀积，可以在$\Omicron(n)$内计算上述式子，其中，分子优化为：
$$
\frac{\prod_{j=1}^na_j}{a_i}=\prod_{j=1}^{i-1}a_j\times\prod_{j=i+1}^na_j
$$
代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5000002
ll n, k, p, pre[MAXN], suf[MAXN], a[MAXN], ans;
inline ll read() {//版本3
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
ll inv(ll k)
{
	if (k == 1) return 1;
	return (p - p / k) * inv(p % k) % p;
}
/*ll inv(ll x)
{
	ll pow = p - 2;
	ll res = 1;
	for (; pow; pow >>= 1, (x *= x) %= p)
		if (pow & 1) (res *= x) %= p;
	return res;
}*/ //快速幂不如它快
signed main()
{
	n = read(); p = read(); k = read();
	pre[0] = suf[n + 1] = 1;
	repe(i, 1, n)
	{
		a[i] = read();
		pre[i] = pre[i - 1] * a[i] %p;
	}
	rede(i, n, 1) suf[i] = suf[i + 1] * a[i] % p;
	for (ll i = 1, j = k; i <= n; ++i, j = j * k % p)
		(ans += j * pre[i - 1] % p * suf[i + 1]) %= p;
	printf("%lld", ans * inv(pre[n]) % p);
	return 0;
}
```

### 余数

#### 取模

加法和乘法直接每次取模

注意：

- 禁止a+=x%=y 不然小心见祖宗，建议分两行，但(a+=x)%=y也行

##### 减法

```c++
(a-b + d-e + ... )%c 
= (a-b+c)%c+(d-e+c)%c+...
```

##### 除法

```c++
(a/b * d/e * ...)%c//或连加
=（a*inb%MOD) *（d*ine%MOD) * ...//inb是b的逆元
```

##### 特定取模

一个数对9取模等于数位和对9取模

#### 性质

要计算只包含加减乘的整数表达式除以正整数n的余数，可以在每步计算之后对n取余，结果不变。

#### 应用

1.将序号和值混存于同一变量(而避免用pair或struct)

已知最大序号为N,则存储为id乘v，

当对该值取模时，得到序号id，对该值整除时，得到值v

##### 卢卡斯定理

$$
n=sp+q,m=tp+r,0\le q,r\le p-1,p是质数，则\\
\begin{pmatrix}n\\m\end{pmatrix}\mod p=
\begin{pmatrix}\lfloor\frac np\rfloor\\\lfloor\frac mp\rfloor\end{pmatrix}
\cdot\begin{pmatrix}n\mod p\\m\mod p\end{pmatrix}\mod p
$$

时间复杂度为$\Omicron(f+g\log n)$,f是预处理组合数复杂度，g是单次求组合数复杂度

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 100002
ll a[mn], p, t, n, m;//i!=a[i]
il ll qpow(ll a, ll b)
{
	ll res = 1;
	for (; b; b >>= 1, a = a * a % p) if (b & 1)
		res = res * a % p;
	return res;
}
il ll C(ll n, ll m)
{
	if (m > n) return 0;
	return ((a[n] * qpow(a[m], p - 2)) % p * qpow(a[n - m], p - 2) % p);
}
ll lucas(ll n, ll m)
{
	if (!m) return 1;
	return C(n % p, m % p) * lucas(n / p, m / p) % p;
}
signed main()
{
	a[0] = 1;
	for (scanf("%lld", &t); t; --t)
	{
		scanf("%lld%lld%lld", &n, &m, &p);
		repe(i, 1, p) a[i] = a[i - 1] * i % p;
		printf("%lld\n", lucas(n + m, n));//原题算C(n,m+n)
	}
	return 0;
}
```

###### (例题)公式求值

> (蓝桥)求$\sum_{i=0}^n\left(C_n^iC_n^mi^k\right)\mod999101$
>
> 其中$1\le n\le10^{1000},1\le k\le1000,0\le m\le n,k\le n$

暂时未搞懂，挂一份AC代码(原题数据4有误，故特判)：

```java
import java.math.BigInteger;
import java.util.Scanner;
class Number {
	long x,y,dd;
	/**
	 * @param x
	 * @param y
	 * @param dd
	 */
	public Number(long x, long y, long dd) {
		super();
		this.x = x;
		this.y = y;
		this.dd = dd;
	}
	public Number() {
		super();
	}
}
public class Main {
	static BigInteger n, m;
	static int k;
	static long monum = 999101;
	static BigInteger mobig = new BigInteger("999101");
	static BigInteger big2 = new BigInteger("2");
	static long ansnum1,ans;
	static long dp[][], bignum[], subnum[];
	static long fact[];
    private static Number gcd(long a,long b) {
	  if (b==0) return new Number(1,0,a);
	  Number number=gcd(b, a%b);
	  long x=number.y;
	  long y=number.x-(a/b)*number.y;
	  long dd=number.dd;
	  return new Number(x,y,dd);
    }
    private static long mod_inverse(long num) {
    	if (num==0) return 0;
    	Number number=gcd(num, monum);
    	long x=(number.x+monum)%monum;
    	return x;
    }
	private static long cal(BigInteger num) {
		if (num.equals(BigInteger.ZERO)) return 1;
		if (num.equals(BigInteger.ONE)) return 2;
		long mnum = cal(num.divide(big2));
		mnum = mnum*mnum%monum;
		BigInteger mo = num.mod(big2);
		if (mo.equals(BigInteger.ONE))
			mnum=mnum*2%monum;
		return mnum;
	}
	private static void init() {
		fact = new long[(int) (monum + 1)];
		fact[0] = 1;
		for (int i = 1; i <= monum; i++) 
			fact[i]=(fact[i-1]*(long)i)%monum;
	}
	private static long calc(int n,int m) {
		if (n<m) return 0;
		long mo=fact[m]*fact[n-m]%monum;
		long divnum=mod_inverse(mo);
		long res=fact[n]*divnum%monum;
		return res;
	}
    private static long lucas(BigInteger n,BigInteger m){
    	if (m.equals(BigInteger.ZERO)) return 1;
    	int nmo=n.mod(mobig).intValue();
    	int mmo=m.mod(mobig).intValue();
    	return calc(nmo, mmo)*lucas(n.divide(mobig),m.divide(mobig))%monum;
    }
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		n = reader.nextBigInteger();
		m = reader.nextBigInteger();
		k = reader.nextInt();
		if(n.equals(new BigInteger("7349813")) && m.equals(new BigInteger("3590741")) && k == 9)
        {
            System.out.println(591101);
            return;
        }
		BigInteger kbig=new BigInteger(String.valueOf(k));
		dp = new long[k + 1][k + 1];
		dp[0][0]=1;
		long mon=n.mod(mobig).longValue();
		for (int i = 0; i <= k - 1; i++)
			for (int j = 0; j <= i; j++) {
				dp[i + 1][j] = (dp[i+1][j]+(long)j*dp[i][j])%monum;
				dp[i + 1][j + 1] =(dp[i+1][j+1]+(long)(mon-j+monum)*dp[i][j])%monum;
			}
		long mulnum =cal(n.subtract(kbig));
		for (int i = k; i >= 0; i--) {
			ansnum1 =(ansnum1+dp[k][i]*mulnum)%monum;
			mulnum = (mulnum*2)%monum;
		}
		init();
		ans=ansnum1*lucas(n, m)%monum;
		System.out.println(ans);
	}
}
```

##### 例题

###### 丘丘人的数学题

> (oj)对于正整数$a,b,c,n$有等式:$a\cdot 2^b+c=n(1\le n\le10^{18})$，输入$n$，求$a+b+c$的最小值

显然直接枚举$b$，然后求最大$a$，然后用等式$c$即可。证明如下：

对确定的$b$，$a$的最大值是$\lfloor\frac n{2^b}\rfloor$，令$a=\lfloor\frac n{2^b}\rfloor-k(k\in\Z^+)$，根据不等式，得$c=n+2^b(k-\lfloor\frac n{2^b}\rfloor)$，代入$a+b+c$，整理，得：
$$
a+b+c=(2^b-1)\cdot k+n+(1-2^b)\lfloor\frac n{2^b}\rfloor+b
$$
对于确定的$b,n$，唯一的变量是$k$，为了让$a+b+c$最小，则取$k=0$，即证毕



### 因数

约数/倍数/因数专题。

#### 唯一分解定理

对任意正整数$n$，有：
$$
n=\prod p_i^{a_i}
$$
$p$是质数，$a$是自然数。且这样的分解是唯一的。

即任意正整数可以表示为任意质数的乘积。

且有$n$的因子个数$c$，因子和$k$分别为：
$$
c=\prod a_i+1
$$

$$
k=\prod\sum_{j=0}^{a_i}p_i^{j}
$$



#### 约数数求法

将$x$质因数分解，因数数为：$\prod(1+p_i)$,$p_i$为每个质因数出现次数。

模板如下：

```c++
ll cal(ll n)
{
	ll r=1,sn=sqrt(n);
	map<ll,ll> m;
	for(ll i=2;i<=sn;++i) while(n%i==0) n/=i,++m[i];
	if(n>1) ++m[n];
	for(map<ll,ll>::iterator it=m.begin();it!=m.end();++it) r*=(1+it->second);
	return r;
}
```

#### 约数和

设约数和函数为$f(n)$，举例：$f(6)=1+2+3+6=12$

1. $f(x)$是积性函数

2. 若$x=p^k$是素数的整数次幂，则：
   $$
   f(x)=1+p+p^2+\dots+p^k=\frac{p^k-1}{p-1}
   $$

3. 若$x$不满足第二条性质，可以使用积性函数性质求$x$：
   $$
   f(x)=f(\frac x{p_x})\times f(p_x)
   $$

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
#define mn  10000002
#define mod 1000000007
ll n, k, p[mn], pri[mn], e[mn], pe[mn], g[mn], cnt; ln ans = 1;
void euler(ll n)
{
	repe(i, 2, n)
	{
		if (!p[i]) p[i] = i, pri[++cnt] = i, pe[i] = i, e[i] = 1;
		for (ll j = 1; i * pri[j] <= n; ++j)
		{
			p[i * pri[j]] = pri[j];
			if (pri[j] == p[i])
			{
				e[i * pri[j]] = e[i] + 1;
				pe[i * pri[j]] = pe[i] * pri[j];
				break;
			}
			e[i * pri[j]] = 1;
			pe[i * pri[j]] = pri[j];
		}
	}
}
il ln qpow(ln a, ln b)
{
	ln res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}
signed main()
{
	n = read(), k = read();
	euler(1e7); g[1] = 1;
	repe(i, 2, n)
	{
		if (pe[i] == i) g[i] = (qpow(p[i], 1LL * e[i] * k + 1) - 1 + mod) % mod * qpow(p[i] - 1, mod - 2) % mod;
		else g[i] = 1LL * g[i / pe[i]] * g[pe[i]] % mod;
		(ans += g[i]) %= mod;
	}
	return printf("%lld", ans) & 0;
}
```



#### 性质

1. 完全平方数(14,9,...)有奇数个约数，其他数有偶数个约数
2. 

#### 例题

##### 连续因子

> (天梯)一个正整数$n(1<n<2^{31})$，求其最长连续因子个数，并输出最小的连续因子序列

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;//不开long long见祖宗
bool isprime(ll p)
{
    if(p==2||p==3) return true;
    if(p<2||(p%6!=1&&p%6!=5)) return false;
    for(ll i=5;i*i<=p;i+=6) if(p%i==0||p%(i+2)==0) return false;
    return true;
}
ll n,bg,len,sqrtn;
signed main()
{
    scanf("%lld",&n);
    if(isprime(n)) return printf("1\n%lld",n)&0; //注意这里不要漏n
    //sqrtn=sqrt(n);这样还会更慢？
    for(ll i=2;i<sqrt(n)+1;++i) if(n%i==0)
    {
        ll acm=i,j=i+1;
        for(;j<sqrt(n)+1;++j)
        {
            acm*=j;
            if(n%acm!=0) break;//乘积必定也是因子
        }
        if(j-i>len) len=j-i,bg=i;
    }
    printf("%lld\n",len);
    for(ll i=bg;i<=bg+len-1;++i)
    {
        if(i!=bg) putchar('*');
        printf("%lld",i);
    }
    return 0;
}
```

##### 倍数问题

> (蓝桥)输入n,k,和n个数a，选三个数加起来的和是k的倍数，求最大的和。
>
> ($1\le k\le10^3,1\le n\le10^5,1\le a_i\le10^8$)

直接枚举的复杂度是$\Omicron(n^2)$，会TLE，但是可以发现，原题即：
$$
(a+b+c)\mod k=0\Rightarrow(a\%k+b\%k+c\%k)\mod k=0
$$
所以可以枚举余数即可。注意可以从两/三个同余中合成k，所以不能只存同余最值。在这种情况下，为了能够取到最值以外的值，可以取一个数先暂时让其弹栈，后来再入栈。时间复杂度优化为$\Omicron(k^2)$

```c++
#include <bits/stdc++.h>
using namespace std;
stack<int> st[1005];
int n,k,a[100002],ans;
signed main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) st[a[i]%k].push(a[i]);
    for(int i=0;i<k;++i) if(st[i].size())
        for(int j=i;j<k;++j) if(st[j].size())
        {
            int h=(k-i-j+k)%k,v=0;
            if(h<j) continue;
            if(st[i].size())
            {
                int ai=st[i].top(); v+=ai; st[i].pop();
                if(st[j].size())
                {
                    int aj=st[j].top(); v+=aj; st[j].pop();
                    if(st[h].size())
                    {
                        int ak=st[h].top(); v+=ak; st[h].pop();
                        ans=max(v,ans);
                        st[h].push(ak);
                    }
                    st[j].push(aj);
                }
                st[i].push(ai);
            }
        }
    return printf("%d",ans),0;
}
```

##### 序列求和

> (蓝桥)定义对正整数$t$，含$t$个约数的最小数为$S_t$，如$S_3=4$，求$\sum_{i=1}^{60}S_i$。

由唯一分解定理和因子数性质：
$$
n=\prod p_i^{a_i}
$$

$$
t=\prod a_i+1
$$

可以DFS，将$t$拆分为若干个整数$a_i+1$，然后将拆分的$a_i$贪心地通过唯一分解定理构造尽可能小的$n$。显然拆分到的越大的$a_i$给越小的质数越好，并且如果$t$是质数，质数不可拆，直接唯一构造$n=2^{t-1}$，因为$2$是最小的质数。可以用反证法证明该贪心算法的正确性。

由于DFS时下一层跟上一层是倍数关系，所以DFS并不会出现指数级的复杂度。

个人代码如下：

```c++
#define mn 100100
#define big 0x7ffffffffffffffa
ll res=3,vis[mn],pr[mn],cnt,mi,dfn[mn];
il ll qpow(ll a, ll b)
{
    ll r=1;
    for(;b;b>>=1,a*=a) if(b&1) r*=a;
    return r;
}
il void euler(ll k=100000)
{
    vis[0]=vis[1]=true;
    repe(i,2,k)
    {
        if(!vis[i]) pr[++cnt]=i;
        repe(j,1,cnt)
        {
            if(i*pr[j]>k) break;
            vis[i*pr[j]]=true;
            if(i%pr[j]==0) break;
        }
    }
}
il void cal(ll ds)
{
    ll r=1;
    sort(dfn+1,dfn+1+ds,greater<ll>());
    ts("%lld\n",ds);
    repe(i,1,ds)
    {
        ts("%lld %lld\n",pr[i],dfn[i]);
        r*=qpow(pr[i],dfn[i]);
    }
    mi=min(mi,r);
    ts("%lld\n\n",r);
}
void dfs(ll h, ll ds)
{
    if(!vis[h])
    {
        dfn[ds]=h-1;
        cal(ds);
        return;
    }
    for(re ll i=2;i<=h;++i)//i*i会暴死S(8)，但参考代码不会……有待思索参考答案tmp的作用
    {
        if(h%i==0)
        {
            dfn[ds]=i-1;
            dfs(h/i,ds+1);
        }
    }
}
signed main()
{
    euler();
    repe(h,3,60)
    {
        mi=big;
        dfs(h,1);
        res+=mi;
        ts("----%lld %lld\n",h,mi);
    }
    printf("%lld",res);
    return 0;
}
```

参考代码如下：

```c++

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=1e5,inf=1e18;
bool vis[N+10];
ll prime[N+10],tot=0,mi;
void get_prime() // 素数筛
{
	memset(vis,1,sizeof(vis));
	vis[0]=vis[1]=0;
	for(int i=2;i<=N;i++)
	{
		if(vis[i])prime[tot++]=i;
		for(int j=0;j<tot&&i*prime[j]<=N;j++)
		{
			vis[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}
ll qpow(ll a,ll b) // 快速幂
{
	ll s=1;
	while(b)
	{
		if(b&1)s=s*a;
		b/=2;
		a*=a;
	}
	return s;
}
ll dfs(ll x,vector<ll>g) // 将x分解成若干个数的乘积
{
	if(vis[x]||x==1)return qpow(2,x-1); // 特判质数和1
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ll t=x/i; // 大的那个数
			g.push_back(i);

			// 更新mi
			vector<ll>tmp=g;
			tmp.push_back(t);
			sort(tmp.begin(),tmp.end(),greater<ll>());
			ll s=1;
			for(int j=0;j<tmp.size();j++)
				s*=qpow(prime[j],tmp[j]-1);
			mi=min(mi,s);

			dfs(t,g);
			g.pop_back();
		}
	}
	return mi;
}
int main()
{
	ios::sync_with_stdio(false);
	get_prime();
	ll ans=0;
	vector<ll>g;
	for(int i=1;i<=60;i++)
	{
		mi=inf;
		g.clear();
		ll ts=dfs(i,g);
		ans+=ts;
	}
	printf("%lld\n",ans);
	return 0;
}
```



##### 矩阵翻硬币

> 有n行m列个硬币，对每个硬币执行Q操作，即对硬币元$(x,y)$，将所有$(ix,jy)$的硬币进行翻转，$i,j$任意可行的正整数，计数从1开始。执行后，所有硬币正面朝上，求一开始有多少反面朝上的硬币。
>
> $n,m\le10^{1000}$

在第一行和第一列，即求约数数是奇数的数目，显然是$\lfloor\sqrt n\rfloor$和$\lfloor\sqrt m\rfloor$，注意去重$(1,1)$。对于其他，反转次数是行序号约数数乘列序号约数数（注意不是加！），因此，答案为：
$$
\lfloor\sqrt n\rfloor\times\lfloor\sqrt m\rfloor
$$
由于数据巨大，使用高精度：

```c++
#include <bits/stdc++.h>
using namespace std;
string mul(string a, string b)
{
	string res="";
	int lena=a.length(),lenb=b.length(),num[502]={0},lenc=lena+lenb,i;
	for(int i=0;i<lena;++i) for(int j=0;j<lenb;++j)
		num[lena-2+lenb-i-j]+=(a[i]-'0')*(b[j]-'0');
	for(int i=0;i<lenc;++i)
		num[i+1]+=num[i]/10,num[i]%=10;
	for(i=lenc-1;i>=0;--i) if(num[i]!=0) break;
	for(;i>=0;--i) res+=(char)(num[i]+'0');
	return res;
}
int cmp(string a, string b, int pos)
{
	int lena=a.length(),lenb=b.length();
	if(a.length()+pos>b.length()) return true;
	if(a.length()+pos<b.length()) return false;
	for(int i=0;i<a.length();++i)
	{
		if(a[i]<b[i]) return false;
		if(a[i]>b[i]) return true;
	}
}
string ssqrt(string a)
{
	string res="";
	int len=a.length();
	len=(len&1)?((len>>1)+1):(len>>1);
	for(int i=0;i<len;++i)
	{
		res+='0';
		while(true!=cmp(mul(res,res),a,(len-1-i)<<1))
		{//用!表达式暴死；用1和true不相等暴死
			if(res[i]==':') break;
			++res[i];
		}
		--res[i];
	}
	return res;
}
string n,m;
signed main()
{
	cin>>n>>m;
	cout<<mul(ssqrt(n),ssqrt(m))<<endl;
	return 0;
}
```



### gcd/lcm

最大公因数/最小公倍数

#### 求法

> 可以认为一个数的gcd就是他自己

##### 两位数

###### 递归式

```python
def gcd(n1,n2):#greatest common divisor function
    return gcd(n2,n1%n2) if n2>0 else n1#或if n2
def lcm(n1,n2):#lowest common multiple function
	return n1*n2//gcd(n1,n2)
```

> long long时，C注意n1/gcd(n1,n2)*n2才不会爆long long
>
> Python注意，/gcd(n1,n2)会因为double丢失精度，不能这么做

C++有编译器函数__gcd(a,b)可以做上面的操作。特别注意若一方为0，直接输出另一方。均0为0。

###### 循环式

```python
def gcd(x,y):
    while(y) x,y=y,x%y
    return x
```

##### 多位数

gcd(a,gcd(b,c)),lcm同理

#### 推论/定理

1.
$$
若a,b\in Z_+，(a,b)=k，则(\frac ak,\frac bk)=1
$$

$$
若p\bot q，则(p^n,q^m)=1
$$

$$
若x\times(a,b)=a,y\times(a,b)=b,则a\bot b
$$



> 对lcm，由计算式$[a,b]=\lfloor\frac{a\times b}{(a,b)}\rfloor$化为gcd即可

2.gcd(a,b)递归n次变成gcd(1,0),这样的最小a+b为：

(2,1),(3,2),(5,3),(8,5)...，显然构成斐波那契数列，递归n次的最小a+b是fib(n+1)+fib(n+2)，n=0特判

3.
$$
\gcd(x^i,y^j)=\prod_{k=0}^nfac[k]^{\min(i\cdot cnt_x[k],j\cdot cnt_y[k])}
$$
其中$fac$是$x,y$的公因子集合，长度为$n$，$cnt$是$x/y$的质因数分解的次数集合，即：
$$
\begin{cases}
x^i=\prod_{k=0}^nfac[k]^{i\cot cnt_x[k]}\\
y^j=\prod_{k=0}^nfac[k]^{j\cot cnt_y[k]}
\end{cases}
$$

#### 作用

##### 定长移动周期

n位队列，第x(从0算)个人每次移动m格(超过则回到首位)，移动了k次。

这个人所在的位置的周期长度为：n/gcd(n,m)，k次之后，该人所在的位置为：(x+km)%n。

gcd(n,m)=1是当k趋于无穷时使得队列所有位置都能被走到的条件。

#### 例题

##### 公因数计数

> 给定$a,b$，求有多少个整数$d$满足$d|a,d|b$。$1\le t\le1000,1\le a,b\le10^9$

标程：如果$a=b$直接$\log a$复杂度求因子，很容易求(按理而言是不需要开set的)；如果不然，在$\gcd(a,b)$之内遍历求。

暴力解法：不仅两个都$\log a$求因子，还要开set判重然后合并，也勉强能过。

##### Game

> (icpc45 上海热身)有$[1,n](1\le n\le5000)$的整数，从里面等概率取走两个，如果取出的两数互质，分数加一，求分数期望值。

对于每一个互质对，其最终贡献分数数目为$\lfloor\frac n2\rfloor$，即抽取次数。//da y

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,q,c;
signed main()
{
    scanf("%lld",&n); q=n*(n-1)/2;
    if(n==1) return printf("0/1"),0;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) if(__gcd(i,j)==1) p+=n/2;
    c=__gcd(p,q); printf("%lld/%lld",p/c,q/c);
    return 0;
}
```



##### Co-prime Permutation

> (icpc45 南京)长度为$n$的$k$互质排列$A$是排列中有且仅有$k$个数与其序数(从$1$开始)互质的排列，给定$n,k(1\le n\le10^6,0\le n\le n)$，输出一个这样的数列，不存在输出$-1$。

对于下列公式，没有找到反例：
$$
(n-1,n)=1
$$
所以可以构造一个排列：$n,1,2,3,\dots,n-1$，必然是$n$互质排列，如果从第二个数开始两两交换一次，那么互质数减少1，最后末项首项交换，变成正排列$a_i=i$，只有首项满足$(1,1)=1$，其余都为$(n,n)=n$，所以$k\ne 0$时必然存在。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,k,a[1000010];
signed main()
{
    scanf("%d%d",&n,&k);
    if(k<1) return printf("-1"),0;
    a[1]=n;
    for(int i=1;i<n;++i) a[i+1]=i;
    for(int i=1;i<=n-k;++i) swap(a[i+1],a[i+2]);
    if(k==1) a[1]=1,a[n]=n;
    printf("%d", a[1]);
    for(int i=2;i<=n;++i) printf(" %d",a[i]);
    return 0;
}
```



##### 共同gcd

找出n个数中1,2,...n个数的最大gcd并输出。

注意：转化为求n个数中1,2,...n个数的共有最大因子并输出。

个人版本：

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10002
unordered_map<int, int> x, freq;
int n, a, ans[MAXN];
signed main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		for (int j = 1; j * j <= a; ++j)
		{//若改为其他如j<=a/2TLE
			if (a % j == 0)
			{
				x[j]++;
				if (a / j != j) x[a / j]++;//特别注意
			}//注意这两个if的关系
		}
	}
	for (auto i : x) freq[i.second] = max(freq[i.second], i.first);
	for (auto i : freq)
		for (int j = 1; j <= i.first; ++j) 
			ans[j] = max(ans[j], i.second);
	for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	return 0;
}
```

优化版如下：

```c++
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,t=0,c[1000010];
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++)
	{
        int x; cin>>x;
		t=max(t,x);
        int m=sqrt(x);
        for(int i=1;i<=m;i++)
            if(x%i==0)
			{
                c[i]++;
                if(x!=i*i) c[x/i]++;
            }
    }
    int x=t;
    for(int i=1;i<=n;i++)
	{
        while(c[x]<i) x--;
        cout<<x<<endl;
    }
    return 0;
}
```

##### Hankson的趣味题

> n组$a_0,a_1,b_0,b_1$，求有多少个正整数$x$，满足$(x,a_0)=a_1,[x,b_0]=b_1$

由推论可知，即满足
$$
\begin{cases}
(\frac{x}{a_1},\frac{a_0}{a_1})=1\\
(\frac{b_1}{b_0},\frac{b_1}{x})=1
\end{cases}
$$
可知$x|a_1且b_1|x$，所以枚举$b_1$的因子

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll a0, a1, b0, b1, n, ans, a, b, j;
ll gcd(ll x, ll y)
{
	return y ? gcd(y, x % y) : x;
}
signed main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
		a = a0 / a1, b = b1 / b0, ans = 0;
		for (ll i = 1; i * i <= b1; ++i)
		{//枚举因子的模板
			if (b1 % i == 0)
			{
				if (i % a1 == 0 && gcd(i / a1, a) == 1 && gcd(b, b1 / i) == 1) ++ans;
				j = b1 / i; if (i == j) continue;
				if (j % a1 == 0 && gcd(j / a1, a) == 1 && gcd(b, b1 / j) == 1)++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
```

##### 这是非常难的中等简单题

> (oj,2021寒假多校牛客) 计算：
> $$
> \gcd(x_1^{p_1},x_2^{p_2},\dots,x_n^{p_n})\mod10^9+7
> $$
> $(1\le n,x_i,p_i\le10^4)$

首先不可以暴力，会超时。根据公式，有：
$$
\gcd(x^i,y^j)=\prod_{k=0}^nfac[k]^{\min(i\cdot cnt_x[k],j\cdot cnt_y[k])}
$$
可以考虑将所有数质因数分解，总时间复杂度是$\Omicron(n\log n)$。使用上式计算全部时，显然时间复杂度是$\Omicron(n\log n)$，因为$fac$的长度约为$\log n$。

特别注意不可以把两两计算的结果直接取模得到中间量，然后重复调用公式：
$$
\gcd(a,b,c,\dots)=\gcd(\gcd(a,b),c\dots)
$$
因为计算过程中会超过$10^9+7$，需要取模，取模后得到的数继续往下计算不成立，即：
$$
\gcd(\gcd(a,b),c)\ne \gcd(\gcd(a,b)\mod 10^9+7,c),其中\gcd(a,b)\ge10^9+7
$$
所以计算后的结果不要直接使用公式算值，而是继续保留质因数分解形式，用这个形式一直往下计算，直到最后全部计算完毕，再对质因数分解用快速幂求答案，求答案的时间复杂度是$\Omicron(\log^2n)$，即对$\log n$个数执行$\Omicron(\log n)$的快速幂算法。

总时间复杂度是$\Omicron(n\log n+log^2n)=\Omicron(nlog n)$，总空间复杂度是$\Omicron(n\log n)$。

特别注意，在处理合并因子过程中，任意一方次数为$0$，那么将不予合并，否则时空复杂度都会降化到$\Omicron(nlog^nn)=\Omicron(n^2\log n)$。这是因为不加筛选地合并因子的最坏情况是得到了最大的广义质因数分解，即把所有$p^0,1\le p\le10^4$都算在了集合里，即无用的因子数目扩大了$n,n\to10^4$倍。

个人代码如下：

```c++
#define mn 10009
#define mod 1000000007
ll n,x[mn],p[mn],r=1,g;
typedef unordered_map<ll,ll> um;
typedef unordered_set<ll> us;
void fct(ll a, ll ap, um& ta)
{
    ll b=2;
    while(b*b<=a)
    {
        while(a%b==0) {ta[b]+=ap;a/=b;}
        ++b;
    }
    if(a>1) ta[a]+=ap;
}
ll qpow(ll x, ll n)
{
    ll r=1;
    for(;n;n>>=1,(x*=x)%=mod) if(n&1) (r*=x)%=mod;
    return r;
}
void gcd(um& fa, um& fb, um& fr)
{
    us fac;
    for(auto i=fa.begin();i!=fa.end();++i) fac.insert(i->first);
    for(auto i=fb.begin();i!=fb.end();++i) fac.insert(i->first);
    for(auto i=fac.begin();i!=fac.end();++i) if(min(fa[*i],fb[*i])) fr[*i]=min(fa[*i],fb[*i]);
}
um xf[mn],rf[mn];
signed main()
{
    n=read();
    repe(i,1,n) x[i]=read();
    repe(i,1,n) p[i]=read();
    if(n==1) return printf("%lld\n",qpow(x[1],p[1])),0;
    repe(i,1,n) fct(x[i],p[i],xf[i]);
    gcd(xf[1],xf[2],rf[2]);
    repe(i,3,n) gcd(rf[i-1],xf[i],rf[i]);
    for(auto i=rf[n].begin();i!=rf[n].end();++i) (r*=qpow(i->first,i->second))%=mod;
    printf("%lld",r);
    return 0;
}
```

##### 这是简单难度的中等难题

> (oj, 2020牛客多校 Groundhog Chasing Death) 计算：
> $$
> \prod_{i=a}^b\prod_{j=c}^d\gcd(x^i,y^j)\mod998244353
> $$
> $0\le a,b,c,d\le3\times10^6,a\le b,c\le d,0<x,y\le10^9$

首先注意取模的不是$10^9+7$……将上式展开，得：
$$
\prod_{i=a}^b\prod_{j=c}^d\prod_{k=0}^nfac[k]^{\min(i\cdot cnt_x[k],j\cdot cnt_y[k])}\mod998244353
$$
使用乘法交换律：
$$
\prod_{k=0}^n\prod_{i=a}^b\prod_{j=c}^dfac[k]^{\min(i\cdot cnt_x[k],j\cdot cnt_y[k])}\mod998244353
$$
由于同底数幂相乘，底数不变指数相加，得：
$$
\prod_{k=0}^nfac[k]^{\sum_{i=a}^b\sum_{j=c}^d\min(i\cdot cnt_x[k],j\cdot cnt_y[k])}\mod998244353
$$
当前时间复杂度为$\Omicron(cd\log\gcd(x,y))=\Omicron(c^2\log\log x)$，因为实质上对于两数的质因数分解合并，等效于直接对$(a,b)$质因数分解。仍不可行，尝试降低一个复杂度，使用二分优化，当枚举$k,i$时，只有$j$是变量，考虑对$j$的分段数列：
$$
f(j)=\min(i\cdot cnt_x[k],j\cdot cnt_y[k])=\begin{cases}
i\cdot cnt_x[k],j>\frac{cnt_x[k]}{cnt_y[k]}i\\
j\cdot cnt_y[k],j\ge\frac{cnt_x[k]}{cnt_y[k]}i
\end{cases}
$$
显然有一部分是常数列$i\cdot cnt_x[k]$，另一部分是等差数列$j\cdot cnt_y[k]$，后者首项为：
$$
\lfloor\frac{cnt_x[k]}{cnt_y[k]}i\rfloor
$$
可以尝试求出这个首项(我失败了)，也可以直接二分查找这个首项。然后很快可以得出答案，注意本题有可能会爆long long，需要开\_\_int128。

使用等差数列+二分优化后，时间复杂度为：$\Omicron(c\log c\log\log x)$。代码如下：

```c++
typedef __int128 ln;
typedef long long ll;
#define mod 998244353
ll a,b,c,d,x,y,r=1,xy,c1,c2;
ll sc()
{
    ll x;
    scanf("%lld",&x);
    return x;
}
ln qpow(ln x, ln n)
{
    ln r=1;
    for(;n;n>>=1,(x*=x)%=mod) if(n&1) (r*=x)%=mod;
    return r;
}
ln bin(ll lf, ll rf, ll v, ll n)
{
    ll cf;
    while(lf<rf)
    {
        cf=lf+rf>>1;
        if(cf*n>v) rf=cf;
        else lf=cf+1;
    }
    return lf;
}
vector<ll> fc;
signed main()
{
    a=sc(),b=sc(),c=sc(),d=sc(),x=sc(),y=sc();
    xy=__gcd(x,y);
    for(ll i=2;i*i<=xy;++i) if(xy%i==0) {fc.push_back(i); while(xy%i==0) xy/=i;}
    if(xy>1) fc.push_back(xy);
    for(auto k=fc.begin();k!=fc.end();++k)
    {
        c1=c2=0;
        while(x%*k==0) x/=*k,++c1;
        while(y%*k==0) y/=*k,++c2;
        ln p=0;
        repe(i,a,b)
        {
            ln q=0;
            if(c1*i>=c2*d) q=c2*(c+d)*(d-c+1)/2;
            else if(c1*i<=c2*c) q=(d-c+1)*c1*i;
            else
            {
                ln r=bin(c,d,c1*i,c2);//(ln)(1.0*i*c1/c2);
                q=c2*(c+r-1)*(r-c)/2+(d-r+1)*c1*i;
            }
            p+=q;
        }
        (r*=qpow(*k,p))%=mod;
    }
    printf("%lld",r);
    return 0;
}
```



### 素数

#### 判断

##### int

###### 朴素

```c
//算法1(差)
int is_prime(int n)//n!=1,n不能过大(i*i溢出当i=46341)
{
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}

//相似写法
int is_prime(int n)
{
    if(n <= 1) return 0;
    int m = floor(sqrt(n) + 0.5);//见判断相等 - 浮点运算后整数
    for(int i = 2； i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}
```

###### 单个判断模板

```伪代码
//模版伪代码 - 较优 - 算法2
bool isprime(ll p)
{
    if (p == 2 || p == 3)
        return 1;
    if (p < 2 || (p % 6 != 1 && p % 6 != 5))
        return 0;
    for (T i = 5; i * i <= p; i = i + 6)
        if (p % i == 0 || p % (i + 2) == 0)
            return 0;
    return 1;
}
```

###### 埃式筛法

```c
//Eratosthenes筛法 - 算法3
#include <stdio.h>
#include <string.h>
#include <math.h>
#define RANGE 100001
int prime[RANGE];
int main()//Eratosthenes筛法
{
    memset(prime, 0, sizeof(prime));//其实可以不memset
    int m=sqrt(0.5+RANGE);
    for(int i=2;i<=m;i++)
        if(!prime[i])
            for(int j=i*i;j<=RANGE;j+=i) prime[j] = 1;
    prime[1] = !prime[1];
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d", &n);
        !prime[n] ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}

//生成不大于 n 的所有质数 - 写法2
bool numlist[100000001];
int prime[20000001], cnt;
void work(int n){
	for(int i=2; i<=n; i++){
		if(numlist[i]==false){
			prime[++cnt] = i ;
			for(int j=i; i*j<=n; j++)
				numlist[i*j] = true;
		}
	}
	return;
}
```

一个可以勉强卡常通过$10^8$的数目的求素数数目的板子：

```c++
#include <bits/stdc++.h>
using namespace std;
bool p[100000002];
typedef int ll;
ll n,i,j,s;
signed main()
{
    scanf("%d",&n); p[1]=true; s=n-1;
    for(ll i=2;i*i<=n;++i) if(p[i]==0) for(ll j=i*i;j<=n;j+=i) if(p[j]==0) p[j]=1,--s; //写j=i*2也行，会慢一些
    return printf("%d",s),0;
}
```



###### 欧拉筛法

```c++
//欧拉筛法，更优于埃式筛法 - 算法4
bool vis[MAXN] = {1,1};//0,1 neither；其实可以不写
int Prime[MAXN], k;
void prime(long long n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) Prime[++k]=i;//++k is prime
        for(int j=1;j<=k;j++)
        {
            if(Prime[j]*i>n) break;//这个可以代替j<=k
            vis[Prime[j]*i]=true;//not prime
            if(i%Prime[j]==0) break;
        }
    }
}
//在这之后,i>=2,vis[i]=true代表i是合数，否则质数
//而prime从下标1开始是素数表(直至后边有一串的0)
```

###### MEISSEL-LEHMER算法

原理：我们预处理出N^(2/3)以内的素数

然后对于询问，我们可以计算出1-N之内，不能被2-N^(1/3)的质数整除的数字个数。

这个东西我们用`f[i][j]`表示,则有`f[i][j]=f[i][j-1]-f[i/pri[j]][j-1]`且`f[i][0]=i;`

同时有f[i][j]=max(0,(1-i)质数个数-j+1)

然后我们预处理出i<=100000,j<=70的f数组，剩下直接递归

然后我们+2-N^(1/3)的质数个数-1，称之为伪素数。

可以发现此时仍有合数，但一定是两个大于N^(1/3)次的素数相乘。

我们枚举较小的素数，可以计算出较大素数范围。

然后剩下的就是真·素数了。

时间,空间复杂度O（N^（2/3））

```c++
#include<bits/stdc++.h>
#define N 216000
#define ll long long
using namespace std;
int mn[N],pri[N/10],fl[N];
int tot,cnt,num,n;
int f[20005][55];
int inf=2e9;
int dp(int x,int y){
    if (x<=20000&&y<=50) return f[x][y];
    if (x==0||y==0) return x;
    if (1ll*pri[y]*pri[y]>=x&&x<N) return max(0,mn[x]-y);
    return dp(x,y-1)-dp(x/pri[y],y-1);
}
void pre(){
    for (int i=2;i<N;i++){
        if (!fl[i]) pri[++tot]=i;
        for (int j=1;i*pri[j]<N&&j<=tot;j++){
            fl[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
    for (int i=1;i<N;i++)
        mn[i]=(cnt+=1-fl[i]);
    for (int i=1;i<=20000;i++) f[i][0]=i;
    for (int i=1;i<=20000;i++)
        for (int j=1;j<=50;j++)
            f[i][j]=f[i][j-1]-f[i/pri[j]][j-1];
}
int power(int x,int y){
    int s=1;
    while (y!=0){
        if (y&1){
            if (s>=inf/x) s=inf;
            else s=s*x;
        }
        y/=2;
        if (x>=inf/x) x=inf;
        else x=x*x;
    }
    return s;
}
int yroot(ll x,int y){
    int l=2,r=6666,ans=1;
    while (l<=r){
        int mid=(l+r)/2;
        if (power(mid,y)<=x) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int work(int m){
    if (m<N) return mn[m]-1;
    int y=yroot(m,3),n=mn[y];
    int ans=dp(m,n)+n-1;
    for (n++;pri[n]*pri[n]<=m;n++)
        ans-=mn[m/pri[n]]-mn[pri[n]]+1;
    return ans;
}
int main(){
    pre();
    scanf("%d",&n);
    printf("%d\n",work(n));
}
```

###### 区间素数

> 区间边界在Int内，区间长度在1e6内，求区间[lf,rf]内素数数

**方法1：**

先筛出$1\sim\sqrt{int}$内的素数，然后从大于L的最小的能被p整除的数开始(防筛掉自己要特判)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
#define SQRTR 50000
ll prime[MAXN], k, ans, lf, rf, p, bg;
bool vis[MAXN];
inline void euler()
{
	rep(i, 2, SQRTR)
	{
		if (!vis[i]) prime[++k] = i;
		for (ll j = 1; i * prime[j] <= SQRTR; ++j)
		{
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
signed main()
{
	scanf("%lld%lld", &lf, &rf);
	lf = (lf == 1) ? 2 : lf;
	euler();
	repe(i, 0, 1000001) vis[i] = false;
	repe(i, 1, k)
	{
		p = prime[i];
		bg = (lf + p - 1) / p * p > 2 * p ? (lf + p - 1) / p * p : 2 * p;
		for (ll j = bg; j <= rf; j += p) vis[j - lf + 1] = true;
	}
	repe(i, 1, rf - lf + 1) if (!vis[i]) ++ans;
	printf("%lld", ans);
	return 0;
}
```

稍微优化：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
#define SQRTR 50000
ll prime[MAXN], k, ans, lf, rf, p, bg;
bool vis[MAXN];
inline void euler()
{
	repe(i, 2, ceil(sqrt(rf)))
	{
		if (!vis[i]) prime[++k] = i;
		for (ll j = 1; i * prime[j] <= ceil(sqrt(rf)); ++j)
		{
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
signed main()
{
	scanf("%lld%lld", &lf, &rf); lf = (lf == 1) ? 2 : lf;
	euler();
	repe(i, 0, 1000001) vis[i] = false;
	repe(i, 1, k)
	{
		p = prime[i];
		bg = (lf + p) / p * p; if (bg - p >= lf) bg -= p;
		for (ll j = bg; j <= rf; j += p) vis[j - lf + 1] = true;
	}
	repe(i, 1, rf - lf + 1) if (!vis[i]) ++ans;
	printf("%lld", ans);
	return 0;
}
```

**方法2：the Meissel, Lehmer, Lagarias, Miller, Odlyzko method**

p[i]表示第i个素数，pi[i]表示i以内素数个数,f[n,m]表示n以内不等于第i至m个素数及其倍数的数的个数，p2[n,m]表示n以内只有两个素因数且最小的素因数大于p[m]的数的个数，p3[n,m]表示n以内只有三个素因数且最小的素因数大于p[m]的数的个数。
注意，接下来提到的除法都是指向下取整。
f明显可以递归计算，转移方程：f[n,m] = f[n,m-1] + f[n/p[m],m-1]。证明留作练习
根据大佬的PPT，计算f的时间复杂度是O(mn^(1/2))。但是蒟蒻我根本不会证明。。
然后是p2的计算方法。p2[n,m] = Σpi[n/k] - pi[k] + 1，其中k是所有大于p[m]且小于n^(1/2)的素数。
接着是p3的计算方法。p3[n,m] = Σp2[n/k,pi[k]-1],其中k是所有大于p[m]且小于n^(1/3)的素数。
先介绍第一种计算pi[n]的方法。线性筛预处理前n^(1/2)的p和pi。pi[n] = pi[n^(1/3)] + f[n,pi[n^(1/3)]] - 1 - p2[n,pi[n^(1/3)]]。减一是为了排除掉1。
这种方法的时间复杂度是O(n^(5/6) / log(n))。时间复杂度的瓶颈在f的计算上，其中pi[n^(1/3)] ≈ n^(1/3) / log n。
为了进一步改善时间复杂度，我们要尽量减少f的计算。以下是经过改进的第二种方法。
还是线性筛预处理前n^(1/2)的p和pi。pi[n] = pi[n^(1/4)] + f[n,pi[n^(1/4)]] - 1 - p2[n,pi[n^(1/4)]] - p3[n,pi[n^(1/4)]]。 计算p3的时间复杂度还不到O(n^(2/3))， 所以瓶颈还在f上，总时间复杂度为O(n^(3/4) / log n)。
如果想要避免递归计算pi，欧拉筛需要预处理前n^(3/4)。

```c++
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <time.h>
#pragma warning(disable:4996)
#define INF 2000000005//2 * 10^9
#define lowbit(a) ((a)&-(a))
inline long long max(long long a, long long b)
{return a > b ? a : b;}
inline long long min(long long a, long long b)
{return a < b ? a : b;}
#define FAIL -INF
const long long MAXN = 6893911;//10000000;
long long p[MAXN], cnt;
bool mark[MAXN];
int pi[MAXN];
void init()
{
    long long i, j;
    for (i = 2; i < MAXN; i++)
    {
        if (!mark[i])
            p[cnt++] = i;
        pi[i] = pi[i - 1] + !mark[i];
        for (j = 0; p[j] * i < MAXN&&j < cnt; j++)
        {
            mark[p[j] * i] = true;
            if (i%p[j] == 0)
                break;
        }
    }
}
int f(long long n, int m)
{
    if (n == 0) return 0;
    if (m == 0) return n - n / 2;
    return f(n, m - 1) - f(n / p[m], m - 1);
}
int Pi(long long N);
int p2(long long n, int m)
{
    int ans = 0;
    for (int i = m + 1; (long long)p[i] * p[i] <= n; i++)
        ans += Pi(n / p[i]) - Pi(p[i]) + 1;
    return ans;
}
int p3(long long n, int m)
{
    int ans = 0;
    for (int i = m + 1; (long long)p[i] * p[i] * p[i] <= n; i++)
        ans += p2(n / p[i], i - 1);
    return ans;
}
int Pi(long long N)
{
    if (N < MAXN) return pi[N];
    int lim = pow(N, 0.25) + 1;
    int i;
    for (i = 0; p[i] <= lim; i++);
    int ans = i + f(N, i - 1) - 1 - p2(N, i - 1) - p3(N, i - 1);
    return ans;
}

int main()
{
    long long L, R;
    scanf("%lld %lld", &L, &R);
    init();
    printf("%d", Pi(R) - Pi(L-1));
    return 0;
}
//1 2000000000
//2147483647以内素数个数：105097565
```

**方法3：部分打表**

打出一些小质数（在这份代码里面取得是前5144个，太多会过长，太小会WA），然后直接用埃氏筛就可以了

```c++
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool isPrime[1000005];
long long primes[]=表
int main(){
	long long l,r;
	scanf("%lld %lld",&l,&r);
	int tot=0;
	for(long long i=0;primes[i]*primes[i]<r+1;++i)
	{
		long long p=primes[i];//先取出一个小质数，然后直接埃氏筛判素数
		for(long long j=max(2*p,((long long)ceil(double(l)/double(p)))*p);j<r+1;j+=p)
		{
			isPrime[j-l]=true;//埃氏筛。因为区间很小所以我们开数组判素数，注意要减去l 不然就没了
		}
	}
	for(long long i=l;i<=r;++i)	if(!isPrime[i-l])	++tot;//统计
	printf("%d",tot);
	return 0;
}
```

##### double

对于double类型变量x（不是整型）不能执行求余运算，即不能用x%i == 0来判断x是否能被i整除，可以使用x/i == (long long)(x/i)来判断x是否能被i整除。

```c
int IsPrime(double x)
{
    int i;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x/i==(long long)(x/i)) return 0;
    }
    return 1;
}
```

#### 素数相关

##### 质因数分解

```c++
//方法一：直接枚举
map<int,int> x;//map[i]=j表示 i^j; da ck
ll a=2,m=i,temp=1;
while(a*a<=m)
{
    while(m%a==0)
    {
        x[a]++;
        m/=a;
    }
    a++;
}
if(m>1) x[m]++;
```

```c++
//方法二：枚举素数
j = 1;
while (j <= prs)
{
    while (c % prime[j] == 0) ++cpr[j], c /= prime[j];
    ++j;
}
```

推论：对$m_1^{m_2}$的质因数分解的结果，等于$m_1$每个结果的$m_2$倍，即：

```c++
i = 1;
while (m1 != 1)
{
    while (m1 % prime[i] == 0) mpr[i] += m2, m1 /= prime[i];
    ++i;
}
```

##### 欧拉函数

$\varphi(n)$，表示$\le n$的正整数中与n互质的数目，如：

$\varphi(0)=0\quad\varphi(1)=1\quad\varphi(8)=len\{1,3,5,7\}=4$

计算式为：
$$
\varphi(x)=x\cdot\prod_{i=1}^n(1-\frac 1{p_i}),p_i为x的所有质因数,x\in\N_+
$$

###### 性质

1. 若$p$是素数，$\varphi(p)=p-1$

2. 若$p$是素数,$k\in\Z_+,k>1$，$\varphi(p^k)=p^k-p^{k-1}$,$\varphi(p^{k+1})=p\cdot\varphi(p^k)$

3. 若$p_1,p_2$是素数，$k_1,k_2\in\Z_+且>1$,根据容斥原理和因式分解，有：
   $\varphi(p^{k_1}_1p^{k_2}_2)=(p_1^{k_1}-p_1^{k_1-1})(p_2^{k_2}-p_2^{k_2-1})=\varphi(p^{k_1}_1)\varphi(p^{k_2}_2)$

4. 有计算式可知，若$p$是素数,$k\in\Z_+,k>1$，$\varphi(n)=\prod_{i=1}^m\varphi(p_i^{k_i})$

5. $\forall a,b\in\Z,(A,B)=1$，有$\varphi(ab)=\varphi(a)\varphi(b)$，即**积性函数**的定义

   > 完全积性函数：$\forall a,b\in\R,f(ab)=f(a)f(b)$

6. 若$p$是素数，$\varphi(i\cdot p)=\begin{cases}\varphi(i)\cdot(p-1)&,p\nmid i\\\varphi(i)\cdot p&,p\mid i\end{cases}$

###### 实现

求一个数$m$的欧拉函数$phi$

```c++
ll t = phi = m;
for (ll i = 2; i * i <= m; ++i) if (t % i == 0)
{
    phi = phi - phi / i;
    while (t % i == 0) t /= i;
}
if (t > 1) phi = phi - phi / t; //此后phi为所求
```

求一个区间内所有数的欧拉函数：(见例题)

###### (例题)签到题

> 求$\sum_{i=l}^rlen\{x|x\le i\wedge!(x\bot i)\},1\le l\le r\le10^{12},r-l\le10^6$

显然不能用杜教筛(时间复杂度$O(n^\frac 23)$超时)或min\_25，发现原题即求
$$
v(x)=\sum_{i=1}^x(i-\varphi(i)),v(r)-v(l)​
$$
即求区间欧拉函数，时间复杂度$\sum_{p\in prime}{\frac {r-l}p+1}$，对其定积分：
$$
\int_1^\sqrt{r}\frac{r-l}x+1dx=\sqrt{r}+(r-l)\ln r
$$
将最坏情况下的l,r代入得$10^6+10^6\times12\ln10\approx2.4\times10^7$，知可以通过

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
#define MOD 666623333
#define bs l
ll l, r, ans, cnt, prime[MAXN], a[MAXN], b[MAXN];
bool vis[MAXN];
signed main()
{
	repe(i, 2, MAXN)
	{
		if (!vis[i]) prime[++cnt] = i;
		for (ll j = i << 1; j <= MAXN; j += i) vis[j] = true;
	}
	scanf("%lld%lld", &l, &r);
	repe(i, l, r) a[i - bs] = b[i - bs] = i;
	ll i = 1;
	while (prime[i] * prime[i] <= r)
	{
		ll p = prime[i];
		for (ll x = (p - l % p) % p; x + l <= r; x += p)
		{
			(a[x] /= p) *= p - 1;
			while (b[x] % p == 0) b[x] /= p;
		}
		++i;
	}
	repe(i, 0, r - l)
	{
		if (b[i] != 1) (a[i] /= b[i]) *= b[i] - 1;
		(ans += bs + i - a[i]) %= MOD;
	}
	printf("%lld", ans);
	return 0;
}
```

###### (例题)仪仗队

> 有$n\times n$的整齐方阵，在其左后方一个单位的位置能够看见多少个人(例：$4\times 4$，$9$人)

> 本题不能枚举斜率，$\Omicron(n^2)$会超时。

某个人能被看见，当且仅当它所在坐标$\gcd(x,y)=1$，即求：
$$
\sum_{x=0}^{n-1}\sum_{y=0}^{n-1}[(x,y)=1]
$$
**解法一：**将第二重求和三切分展开，根据对称性，可以化简为：
$$
1+2\sum_{x=0}^{n-1}\sum_{y=0}^{x-1}[(x,y)=1]
$$
根据欧拉函数的定义，即求：
$$
1+2\sum_{x=0}^{n-1}\varphi(x)
$$
单次欧拉函数的算法仍然会超时，可以利用欧拉函数的<u>性质8</u>：
$$
若p是素数，\varphi(i\cdot p)=\begin{cases}\varphi(i)\cdot(p-1)&,p\nmid i\\\varphi(i)\cdot p&,p\mid i\end{cases}
$$
跟欧拉素数筛法结合使用，并使用前缀和，达到线性时间复杂度，代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 40002
ll n, prime[MAXN], cnt, fc[MAXN], phi[MAXN];
signed main()
{
	scanf("%d", &n);
	if (n == 1) return printf("0"), 0;
	phi[1] = 1;
	repe(i, 2, n - 1)
	{
		if (!fc[i])
		{
			prime[++cnt] = i;
			fc[i] = i;
			phi[i] = i - 1;
		}
		repe(j, 1, cnt)
		{
			if (prime[j] * i > n || prime[j] > fc[i]) break;
			fc[prime[j] * i] = prime[j];
			if (prime[j] < fc[i]) phi[prime[j] * i] = (prime[j] - 1) * phi[i];
			else phi[prime[j] * i] = prime[j] * phi[i];
		}
		phi[i] += phi[i - 1];
	}
	printf("%d", phi[n - 1] << 1 | 1);
	return 0;
}
```

**解法二：**(该解法可拓展到$n\times m$)：坐标公约数为i的个数是：
$$
f(i)=\lfloor\frac ni\rfloor\times\lfloor\frac mi\rfloor
$$
去重后所求为：
$$
\sum_{k=2}^{k\times i\le n}f(k\times i)
$$
朴素时间复杂度为$\Omicron(n\log n)$，反演时间复杂度为$\Omicron(n)$

```c++
#include<bits/stdc++.h>
using namespace std;
int n , ans ;
int f[50000] ;
int main()
{
    scanf("%d",&n);
    if( n == 1 ){
        printf("0\n");
        return 0;
    }
    ans = ( n -1 ) * ( n - 1 ) ;
    n-- ;
    for(int i = n ; i >= 2 ; i--){
        f[i] = ( n /i ) * ( n / i ) ;
        for(int j = 2 * i ; j <= n ;j += i ) f[i] -= f[j] ;
        ans -= f[i] ;
    }
    printf("%d",ans + 2 );
    return 0;
}
```

##### 欧拉定理

$$
a\bot m,则a^{\varphi(m)}\equiv1\mod m\quad a,m\in\Z,m是素数
$$

拓展欧拉定理：
$$
b\ge\varphi(m)，则a^b\equiv a^{(b\mod\varphi(m))+\varphi(m)}\mod m\\ a,b,m\in\Z,m是素数
$$

###### (例题)拓展欧拉定理

> 求解$a^b\mod m$，其中$b\le10^{2^8}$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll a, b, m, t, phi, ans = 1;
char c;
bool flag;
signed main()
{
	scanf("%d%d", &a, &m);
	t = phi = m;
	for (ll i = 2; i * i <= m; ++i) if (t % i == 0)
	{
		phi = phi - phi / i;
		while (t % i == 0) t /= i;
	}
	if (t > 1) phi = phi - phi / t;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar())
	{
		b = (b << 1) + (b << 3) + (c ^ '0');
		if (b >= phi) flag = true, b %= phi;
	}
	if (flag) b += phi;
	for (ans = 1; b; b >>= 1, a = 1LL * a * a % m) if (b & 1)
		ans = 1LL * ans * a % m;
	printf("%d", ans);
	return 0;
}
```

#### 性质

##### 唯一分解定理

任何一个大于1的自然数 N,如果N不为质数，那么N可以唯一分解成有限个质数()可以重复的乘积。

##### 定理

$$
若p\bot q，一定存在p^n\%q^m\ne0
$$

$$
若x\times(a,b)=a,y\times(a,b)=b,则a\bot b
$$

$$
若a\cdot b\bot c\cdot d则a\bot b,a\bot c,b\bot c,b\bot d
$$

> 应用举例：
> $$
> ((m+1)^2-1)\bot((n+1)^2-1)\\由辗转相除法得：
> ((m+1)^2-1)\bot((n+1)^2-(m+1)^2)\\即：
> (m(m+2))\bot(n+m-2)(n-m)\\故：
> \begin{cases}
> n\bot m\\
> n\bot(m+2)\\
> (n+1)\bot m\\
> (n+2)\bot(m+2)
> \end{cases}
> $$

##### 因数相关

> 因数包含自己，如8的因数有1,2,4,8(存疑)

$$
若S|M，则M的质因数multiset是S的质因数multiset的子集
$$

$$
a的因子和=将a质因数分解为\sum_ia_i^j后，\prod_i\sum_{h=0}^ja_i^h\\上式的内层求和可以用等比数列公式化简；然后用快速幂/exgcd可以应对取模
$$

#### 例题

##### RSA解密

> (蓝桥)RSA算法首先生成两个质数$p,q$，令$n=p\cdot q,d\bot(p-1)(q-1),$$d\cdot e\mod(p-1)(q-1)=1$,则$n,d,e$为私钥，$n,d$为公钥。使用公钥加密一个整数$x(x<n)$，则密文$c=x^d\mod n$，解密：$x=c^e\mod n$，给出公钥$n,d$和密文$c$，求原文(结果填空题)
>
> n=1001733993063167141,d=212353,c=20190324

发现n恰好小于long long，则$\sqrt n$数量级为$10^{9.5}$，考虑到python运行较慢(实测两分钟多)，使用C++遍历求$p,q$：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=1001733993063167141,nsqrt,p,q;
signed main()
{
    nsqrt=sqrt(n);
    for(p=2;p<=nsqrt;++p) if(n%p==0)
    {
        q=n/p;
        break;
    }
    printf("%lld %lld\n",p,q);
    return 0;
}
```

得到p,q，直接枚举e显然时间复杂度为$\Omicron(n)$或更高，且也存在高精度问题，建议使用python，令$w=(p-1)(q-1)$，推导公式如下：
$$
d\cdot e\mod w=1\Rightarrow d\cdot e=i\cdot w+1\Rightarrow d|(i\cdot w+1)
$$
可以使用while：

```python
p=891234941
q=1123984201
pq=(p-1)*(q-1)
d=212353
i=1
while True:
    t=i*pq+1
    if t%d==0:
        print(t//d) #e=823816093931522017
        break
    i+=1
```

之后直接套快速幂即可，这里不做展示。答案为579706994112328949

##### 因子和

> 求a^b^的因子和对9901取模

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MOD 9901
ll to1, to2, ans = 1, x, y, t, sx;
inline ll qpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) (res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}
signed main()
{
	scanf("%lld%lld", &x, &y);
	sx = sqrt(x);
	repe(i, 2, sx)
	{
		if (!(x % i))
		{
			t = 0;
			while (!(x % i)) x /= i, ++t;
			to2 = t * y + 1;
			if (i % MOD == 1) (ans *= t + 1) %= MOD;
			else
			{
				to1 = i % MOD;
				ans *= (qpow(to1, to2) - 1) * qpow(to1 - 1, MOD - 2);
				ans %= MOD;
			}
		}
	}
	if (x != 1)
	{
		to2 = y + 1;
		if (x % MOD == 1) (ans *= y + 1) %= MOD;
		else
		{
			to1 = x % MOD;
			ans *= (qpow(to1, to2) - 1) * qpow(to1 - 1, MOD - 2);
			ans %= MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}
```

### 同余方程

求$ax \equiv 1 (\mod b)$，如果要求最小正整数解，可以套用如下模板：

```c++
#include <bits/stdc++.h>//模板1
using namespace std;
#define int long long
typedef long long ll;
int ex_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = ex_gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
bool liEu(int a, int b, int c, int& x, int& y) {
  int d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return 1;
}
ll a,b,x,y;
signed main()
{
    scanf("%lld%lld",&a,&b);
    liEu(a,b,1,x,y);
    printf("%lld",(b+x)%b);
    return 0;
}
```

```c++
#include<bits/stdc++.h>//模板2
using namespace std;

long long x, y;//目前方程真正的解 

void exgcd(long long a, long long b)
{
	//当前目的：求解 ax + by = gcd(a, b) 这么一个方程
	
	if(b == 0) //a, b不断改变的过程中，b最终必然会成为0
	{
		//在 b = 0 时方程还要成立？ 使 x = 1, y = 0 ，必然成立 
		x = 1;
		y = 7; //建议返回0。不过y = 7能AC，证明了最后一个等式不受最后一个y影响
		return;
	} 
	
	exgcd(b, a % b);//把下一层系数传进去（先求下一个方程的解 ）
	
	//现在我们已经拿到了下一个方程的解x, y
	long long tx = x;//暂时存一下x，别丢了
	x = y;
	y = tx - a / b * y; 
}

int main()
{
	long long a, b;
	cin >> a >> b;
	exgcd(a, b);
    
	x = (x % b + b) % b;//我们求出来的x必然满足方程，但不一定是最小正整数解，所以要进行答案处理
	printf("%lld\n", x);
	return 0;
}
```

### 中国剩余定理

CRT(Chinese Remainder Theorem)

求解如下一元线性同余方程的元$x$：($n_i$两两互质)
$$
\begin{cases}
x\equiv a_1(\mod n_1)\\
x\equiv a_2(\mod n_2)\\
\quad\quad\quad\ \ \ \vdots\\
x\equiv a_k(\mod n_k)\\
\end{cases}
$$
算法流程：(代码实现见例题)

1. 计算$n=\prod_{i=1}^k n_i$
2. 对于第$i$个方程：
   1. $m_i=\frac n{n_i}$
   2. 计算$m_i$在模$n_i$下的逆元$m_i^{-1}$
   3. $c_i=m_i\times m_i^{-1}$
3. $x=\sum_{i=1}^ka_ic_i(\mod n)$

#### 拓展中国剩余定理

EXCRT，求解$n_i$不两两互质的情况。

如下程序求$x\equiv b_i(\mod a_i)$的最小非负整数解。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
#define mn 100002
ll n, ai[mn], bi[mn], x, y, k, m, ans, a, b, c, gcc, bg;
ll qmul(ll a, ll b, ll mod) //防止爆炸，更稳定(虽然慢一点)
{
	ll res = 0;
	for (; b; b >>= 1, a = (a + a) % mod) if (b & 1)
		res = (res + a) % mod;
	return res;
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	if (!b) { x = 1, y = 0; return a; }
	ll gcd = exgcd(b, a % b, x, y);
	ll t = x; x = y, y = t - a / b * x;
	return gcd;
}
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld%lld", ai + i, bi + i);
	m = ai[1], ans = bi[1];
	repe(i, 2, n)
	{
		a = m, b = ai[i], c = (bi[i] - ans % b + b) % b;
		gcc = exgcd(a, b, x, y), bg = b / gcc;
		if (c % gcc != 0) return printf("-1") & 0;
		x = qmul(x, c / gcc, bg);
		ans += x * m, m *= bg, ans = (ans % m + m) % m;
	}
	printf("%lld", (ans% m + m) % m);
	return 0;
}
```

#### 例题

##### 曹冲养猪

> 有n个建圈，建a圈余b猪，$a\bot b$，求最小猪数。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define ln 12
ll n, a[ln], m[ln], mi, mul = 1, x, y, ans;
void exgcd(ll a, ll b, ll& x, ll& y)
{
	if (!b) { x = 1, y = 0; return; }
	exgcd(b, a % b, x, y);
	ll z = x; x = y, y = z - y * (a / b);//不加括号暴毙
}
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n)
	{
		scanf("%lld%lld", m + i, a + i);
		mul *= m[i];
	}
	repe(i, 1, n)
	{
		mi = mul / m[i], x = 0, y = 0;
		exgcd(mi, m[i], x, y);
		ans += a[i] * mi * (x < 0 ? x + m[i] : x);
	}
	printf("%lld", ans % mul);
	return 0;
}
```

##### 猜数字

> 有两个长为k的序列，b序列两两互素，求最小的$n\in\N$，满足$\forall i\in[1,k]$，有$b_i|(n-a_i)$

对其中一条式子，显然可转化为$n-a_k\equiv0(\mod b_k)$，

根据同余变换法则，若$a\equiv b(\mod m)$则$a+c\equiv b+c(\mod m)$

故化为同余方程$n\equiv a_k(\mod b_k)$，套中国剩余定理即可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 12
ll k, a[MAXN], b[MAXN];
inline ll qmul(ll x, ll y, ll m)
{
	ll res = 0;
	while (y)
	{
		if (y & 1) (res += x) %= m;
		(x += x) %= m;
		y >>= 1;
	}
	return res;
}

void exgcd(ll u, ll v, ll& x, ll& y)
{
	if (v == 0) { x = 1, y = 0; return; }
	exgcd(v, u % v, x, y);
	ll w = x; x = y; y = w - u / v * y;
}

inline ll cn()
{
	ll res = 0, lcm = 1, x, y, t;
	repe(i, 1, k) lcm *= b[i];
	repe(i, 1, k)
	{
		t = lcm / b[i];
		exgcd(t, b[i], x, y);
		x = (x % b[i] + b[i]) % b[i];
		(res += qmul(qmul(t, x, lcm), a[i], lcm)) %= lcm;
	}
	return (res + lcm) % lcm;
}

signed main()
{
	scanf("%lld", &k);
	repe(i, 1, k) scanf("%lld", &a[i]);
	repe(i, 1, k) scanf("%lld", &b[i]);
	repe(i, 1, k) a[i] = (a[i] % b[i] + b[i]) % b[i];
	printf("%lld", cn());
	return 0;
}
```

### 多项式

#### 基本概念

**系数表示法**：$F(x)=y=\sum_{i=0}^na_ix^i$，其中$\{a_i\}$是每一项的系数。

**点值表示法**：$F(x)$可以被n个点$(x_i,f(x_i))$唯一确定。

朴素**系数转点值**的算法叫**DFT（离散傅里叶变换）**,优化后为**FFT（快速傅里叶变换）**，**点值转系数**的算法叫**IDFT（离散傅里叶逆变换）**，优化后为**IFFT(快速傅里叶逆变换**)。

两个多项式相乘即求**卷积**：
$$
f(x)\times g(x)={(x_i,f(x_i)\times g(x_i))}
$$
显然，点值表示法下的卷积运算时间复杂度为$\Omicron(n)$

#### 傅里叶变换

复数w有$w^n=1$,则w是n次单位根。将单位圆n等分，获得n个复数，即找到了n次单位根。设第k个n次单位根是$w_n^k$，则：$(w_n^1)^k=w_n^k$(即复数相乘时模长相乘幅角相加的原则)，且：
$$
w_n^k=\cos\frac kn2\pi+i\sin\frac kn2\pi
$$
单位根具有如下性质：

1. $w_n^k=w_{2n}^{2k}$
2. $w_n^k=-w_n^{k+\frac n2}$
3. $w_n^0=w_n^n=1$

将$w_n^i(i=0\to n-1)$代入多项式，得到的点值表示称为DFT。将多项式$A(x)$($0\to n-1$次)**系数**分解为奇次$A_1(x)(1\to n-1)$和偶次$A_0(x)(0\to n-1)$，根据等式的性质，有：
$$
A(x)=A_0(x^2)+x\times A_1(x^2)
$$
由单位根性质，代入单位根$w_n^k$和$w_n^{k+\frac n2}$，则可以得到递推式：(**蝴蝶变换**)
$$
\begin{cases}
A(w_n^k)&=A_0(w_{\frac n2}^k)+w_n^k\times A_1(w_{\frac n2}^k)\\
A(w_n^{k+\frac n2})&=A_0(w_{\frac n2}^k)-w_n^k\times A_1(w_{\frac n2}^k)
\end{cases}
$$
可以将求$A(x)$的$w_n^i(i=1\to n-1)$分治为求两个子多项式在$w_{\frac n2}^i(i=1\to\frac n2-1)$的值。

分治的处理长度只能是$2^m,m\in N^*$，所以DFT之前需要向上补长度，系数为$0$。

使用循环优化递归分治。一次分治后的新位置等于原位置(下标从$0$开始)二进制翻转，翻转长度为这次二分的范围(从$2^m$开始每次减半)。即逆序置换(bit-reversal permutation，蝴蝶变换)

逆序置换可以$O(n)$递推实现。设$r(x)$表示长为$k$的二进制数$x$翻转后(高位补$0$)后的数。设$len=2^k$。则$r(0)=0$，递推方法为将$x$右移，然后取反，再右移，即得到除个位外其他位的反转结果。对个位，若为$1$，移动到到数的最高位。否则等效删去个位。这个过程等效于上述逆序置换，其中取反为$r(x>>1)=r(\lfloor\dfrac x2\rfloor)$。故：
$$
r[i]=(r[i>>1]>>1)|((i\&1)<<(k-1))
$$
算法实现上，FFT的大致流程如下：

- 将原系数序列排序变化为$k$次分支后的系数序列
- 求$w_n^k$，然后根据递推式同时求$A(w_n^k),A(w_n^{k+\frac n2})$

时间复杂度为$\Omicron(n\log n)$

由于DFT的本质为对这个线性变换的优化：
$$
\begin{bmatrix}y_0\\y_1\\y_2\\\vdots\\y_{n-1}\end{bmatrix}=\begin{bmatrix}1&1&1&\cdots&1\\1&w_n^1&w_n^2&\cdots&w_n^{n-1}\\1&w_n^2&w_n^4&\cdots&w_n^{2(n-1)}\\\vdots&\vdots&\vdots&\ddots&\vdots\\1&w_n^{n-1}&w_n^{2(n-1)}&\cdots&w_n^{(n-1)^2}\end{bmatrix}\begin{bmatrix}a_0\\a_1\\a_2\\\vdots\\a_{n-1}\end{bmatrix}
$$
而左边矩阵$\mathbf C$的逆矩阵有特殊性质，即$\mathbf C^{-1}$的$x=\dfrac1{nx}$。可以根据数学知识得到，计算单位负根的公式只需要将$\exp$表达式的虚部乘以$-1$。即把：
$$
w=e^{\frac\pi h i}\Rightarrow w=e^{-\frac\pi h i}
$$
所以，把多项式A(x)的离散傅里叶变换结果作为另一个多项式B(x)的系数，取单位根的倒数作为x代入B(x)，得到的每个数再除以n，得到的是A(x)的各项系数，这就实现了傅里叶变换的逆变换了。

如果需要解决浮点数精度问题，参见快速数论变换。

#### 常规运算

##### 除法

即大除法。朴素解法：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
typedef double db;
typedef int ll;
ll an,bn,x,am,bm,qt,rt;
db a[mn],b[mn],q[mn],r[mn],y;//q是商,r是余
void get(ll& len, db* arr, ll& m)//读入len项，最大项指数为m
{
    scanf("%d",&len);
    for(ll i=0;i<len;++i)
    {
        scanf("%d%lf",&x,&y);
        arr[x]=y;
        m=max(m,x);
        if(!x) break;
    }
}
void prt(ll bg, db* arr)
{
    vector<ll> pe;
    vector<db> pv;
    ll tl=0;
    for(ll i=bg;i>=0;--i) //题目要求四舍五入后为0.0的不要输出
    {
        int v=round(abs(arr[i])*10);
        if(v!=0)
        {
            ++tl;
            pe.push_back(i);
            pv.push_back(arr[i]);
        }
    }
    if(tl==0){printf("0 0 0.0\n");return;}//空多项式
    printf("%d",tl);//项数
    for(ll i=0;i<tl;++i) printf(" %d %.1lf",pe[i],pv[i]);
    putchar('\n');
}
signed main()
{
    get(an,a,am);
    get(bn,b,bm);
    for(ll ai=am,bi=bm,qi=am-bm;ai>=0&&qi>=0;--ai,--bi,--qi)
    {
        db k=a[ai]/b[bm]; q[qi]=k;
        for(ll j=ai,h=bm;h>=0&&j>=0;--h,--j) a[j]-=k*b[h];
    } //边界条件>=0基本上少一个错一个测试点，多一个多余的也是
    prt(am-bm,q);
    prt(bm,a);
    return 0;
}
```



#### 卷积

多项式乘法(FFT)

> 计算n次多项式F(x)和m次多项式G(x)的卷积，从低到高输出系数。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 2097153 //(1<<21) + 1
ll n1, n2, rev[mn], ans[mn], k, s = 1, len, n;
db pi = acos(-1), v;
typedef complex<double> cp;
cp a[mn], b[mn];
void fft(cp* a, ll n, ll flag)
{ //i<rev[i]是确保每对只置换一次
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (ll h = 1; h < n; h <<= 1)
	{
		cp wn = exp(cp(0, flag * pi / h));
		for (ll j = 0; j < n; j += h << 1)
		{
			cp w(1, 0);
			rep(k, j, j + h)
			{
				cp x = a[k], y = w * a[k + h];
				a[k] = x + y;
				a[k + h] = x - y;
				w *= wn;
			}
		}
	}
	if (flag == -1) rep(i, 0, n) a[i] /= n;
}
signed main()
{
	scanf("%d%d", &n1, &n2); n = n1 + n2;
	repe(i, 0, n1) scanf("%lf", a + i);
	repe(i, 0, n2) scanf("%lf", b + i);
	while (s <= n) s <<= 1, ++k;
	rep(i, 0, s) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	fft(a, s, 1);
	fft(b, s, 1);
	repe(i, 0, s) a[i] *= b[i];
	fft(a, s, -1);
	repe(i, 0, n) printf("%d ", (ll)(a[i].real() + 0.5));
	return 0;
}
```

#### 拉格朗日插值

> 给定由n个点确定的多项式$f(x)$，求$f(k)$

公式：
$$
f(k)=\sum_{i=0}^ny_i\prod_{i\neq j}\frac{k-x[j]}{x[i]-x[j]}
$$
时间复杂度：$\Omicron(n^2)$

##### 代码实现

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 2002
#define MOD 998244353
ll n, k, x[MAXN], y[MAXN], ans, s1, s2;
inline ll qpow(ll a, ll x)
{
	ll res = 1, t = a;
	for (; x; t = t * t % MOD, x >>= 1) if (x & 1)
		res = res * t % MOD;
	return res;
}
inline ll inv(ll x) { return qpow(x, MOD - 2); }
signed main()
{
	scanf("%lld%lld", &n, &k);
	repe(i, 1, n) scanf("%lld%lld", x + i, y + i);
	repe(i, 1, n)
	{
		s1 = y[i] % MOD, s2 = 1;
		repe(j, 1, n) if (i != j)
			s1 = s1 * (k - x[j]) % MOD,
			s2 = s2 * ((x[i] - x[j] % MOD) % MOD) % MOD;
		ans += s1 * inv(s2) % MOD;
		ans = (ans + MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}
```

### 原根

若$(a,m)=1$，使得$a^l\equiv 1(\mod m)$成立最小的$l$称为$a$关于模$m$的**阶**，记作$ord_ma$

若$(g,m)=1,ord_mg=\varphi(m)$，则g是m个一个原根

> $g$为$m$的一个原根当且仅当$\{g,g^2,\dots,g^{\varphi(m)}\}$构成$m$的一个既约剩余系。

判断：$m$有原根则m是$2,4,p^a,2p^a$,$p$是奇素数，$a\in\Z_+$

求一个原根：$(g,m)=1,p_1,\dots,p_k$是$\varphi(m)$的所有不同素因数，$g$是$m$的原根，当且即当对任意$1\le i\le k$，有$g^{\frac{\varphi(m)}{p_i}}\not\equiv1(\mod m)$。

求所有原根：有$\varphi(\varphi(m))$个关于m两两不互余的原根$S=\{g^s|1\le s\le\varphi(m),(s,\varphi(m)=1)\}$

最小原根在$\Omicron(m^{0.25})$级别。

#### 求所有原根

> t组询问，输入n,d，输出n的原根数c，从小到大输出$\lfloor\frac cd\rfloor$个原根，分别为第$d,2d\dots$个。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1000002
ll t, p, cnt, tot, ctans, fc[MAXN], ans[MAXN], pri[MAXN], rt[MAXN];
ll q[MAXN], phi[MAXN], v, mn;
inline ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
inline ll qpow(ll a, ll b, ll p)
{
	ll res = 1;
	for (; b; a = (1LL * a * a) % p, b >>= 1) if (b & 1)
		res = (1LL * res * a) % p;
	return res;
}
inline void proc(ll p)
{
	for (ll i = 2; i * i <= p; ++i) if (p % i == 0)
	{
		fc[++cnt] = i;
		while (p % i == 0) p /= i;
	}
	if (p > 1) fc[++cnt] = p;
}
inline bool ck(ll x, ll p)
{
	if (qpow(x, phi[p], p) != 1) return false;
	repe(i, 1, cnt) if (qpow(x, phi[p] / fc[i], p) == 1) return false;
	return true;
}
inline ll findrt(ll p)
{
	rep(i, 1, p) if (ck(i, p)) return i;
	return 0;
}
inline void getrt(ll p, ll x)
{
	ll prod = 1;
	repe(i, 1, phi[p])
	{
		prod = (1LL * prod * x) % p;
		if (gcd(i, phi[p]) == 1) ans[++ctans] = prod;
	}
}
signed main()
{
	phi[1] = 1;
	repe(i, 2, MAXN - 2)
	{
		if (!q[i]) pri[++tot] = i, phi[i] = i - 1;
		for (ll j = 1; j <= tot && pri[j] * i <= MAXN - 2; ++j)
		{
			q[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
	rt[2] = rt[4] = 1;
	repe(i, 2, tot)
	{
		for (ll j = 1; 1LL * j * pri[i] <= MAXN - 2; j *= pri[i])
			rt[j * pri[i]] = 1;
		for (ll j = 2; 1LL * j * pri[i] <= MAXN - 2; j *= pri[i])
			rt[j * pri[i]] = 1;
	}
	for (scanf("%d", &t); t; --t)
	{
		scanf("%d%d", &p, &v);
		if (rt[p])
		{
			ctans = cnt = 0;
			proc(phi[p]);
			mn = findrt(p);
			getrt(p, mn);
			sort(ans + 1, ans + ctans + 1);
			printf("%d\n", ctans);
			repe(i, 1, ctans / v) printf("%d ", ans[i * v]);
			printf("\n");
		}
		else printf("0\n\n");
	}
	return 0;
}
```

### BSGS

求解关于$x$的方程$a^x\equiv b(\mod p),p$是素数。

时间复杂度是$\Omicron(\sqrt p)$，p在int都能过

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 1000700
#define mod 1000007
struct hasht {
	ll mp[mn], hsh[mn];
	inline ll find(ll x)
	{
		ll t = x % mod;
		while (mp[t] != x && mp[t] != -1)
		{
			t += 107;
			if (t >= mod) t -= mod;
		}
		return t;
	}
	inline void insert(ll x, ll i)
	{
		ll f = find(x);
		mp[f] = x, hsh[f] = i;
	}
	inline bool isin(ll x)
	{
		return mp[find(x)] == x;
	}
	inline ll gohsh(ll x)
	{
		return hsh[find(x)];
	}
	inline void cls()
	{
		memset(hsh, -1, sizeof hsh);
		memset(mp, -1, sizeof mp);
	}
} ht;
ll b, p, n, m, s;
signed main()
{
	scanf("%d%d%d", &p, &b, &n);
	ht.cls();
	if (n == 1) return !printf("0");
	m = ceil(sqrt((db)p)) + 1;
	s = 1;
	for (ll i = 1; i <= m; ++i, s = (1LL * s * b) % p, n = (1LL * n * b) % p)
		ht.insert(n, i);
	b = s;
	for (ll i = 1; i <= m; ++i, b = (1LL * b * s) % p)
		if (ht.isin(b))
			return !printf("%d", i * m - ht.gohsh(b) + 1);
	return !printf("no solution");
}
```

#### exBSGS

约束条件：$p$不再是素数，但$\sum\sqrt p\le5\times10^6,1\le p\le10^9$

用哈希实现：

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()

#define mn 100000
#define mod 1000007
#define big 0xfffffffffffffa
ll a, b, p, baby[mn + 3], giant[mn + 3], key[mod], comment[2][mod];
ll stk[mod << 1 | 1];
ll mhash(ll v)
{
    ll w = v * v % mod;
    while (key[w] && key[w] != v)
    {
        (w += 1) %= mod;
    }
    if (!key[w])
    {
        stk[++stk[0]] = w;
    }
    return w;
}
ll phi(ll x)
{
    ll r = x;
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            r = r / i * (i - 1);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
    {
        r = r / x * (x - 1);
    }
    return r;
}
ll exbsgs()
{
    ll res = big, block = ceil(sqrt(2 * phi(p)));
    baby[0] = 1;
    for (ll i = 1; i <= block; ++i)
    {
        baby[i] = baby[i - 1] * a % p;
    }
    comment[0][mhash(1)] = 0;
    giant[0] = 1;
    for (ll i = 1; i <= block; ++i)
    {
        giant[i] = giant[i - 1] * baby[block] % p;
        ll now = mhash(giant[i]);
        if (!comment[0][now])
        {
            comment[0][now] = i;
        }
        else if (!comment[1][now])
        {
            comment[1][now] = i;
        }
    }
    for (ll i = 0; i <= block; ++i)
    {
        ll now = mhash(b * baby[i] % p);
        ll t0 = comment[0][now], t1 = comment[1][now];
        if (t0 && giant[t0 - 1] * baby[block - i] % p == b)
        {
            res = min(res, t0 * block - i);
        }
        else if (t1 && giant[t1 - 1] * baby[block - i] % p == b)
        {
            res = min(res, t1 * block - i);
        }
    }
    return res;
}

signed main()
{
    while (scanf("%lld%lld%lld", &a, &p, &b) != EOF)
    {
        if (!p && !a && !b)
        {
            break;
        }
        b %= p, a %= p;
        while (stk[0])
        {
            key[stk[stk[0]]] = 0;
            comment[0][stk[stk[0]]] = 0;
            comment[1][stk[stk[0]]] = 0;
            --stk[0];
        }
        ll res = exbsgs();
        if (res == big)
        {
            printf("No Solution\n");
        }
        else
        {
            printf("%lld\n", res);
        }
    }
    return 0;
}
```

用map实现(会TLE)：

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
ll a, b, p;
unordered_map<ll, ll> f;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
    }
    else
    {
        exgcd(b, a % b, x, y);
        ll t = x;
        x = y, y = t - a / b * y;
    }
}
ll inv(ll a, ll b)
{
    ll x, y;
    exgcd(a, b, x, y);
    return (x % b + b) % b;
}
ll qpow(ll a, ll b, ll p)
{
    ll r = 1;
    for (; b; b >>= 1, (a *= a) %= p)
    {
        if (b & 1)
        {
            (r *= a) %= p;
        }
    }
    return r; //无return会bugs
}
ll bsgs(ll a, ll b, ll p)
{
    f.clear();
    ll m = ceil(sqrt(p));
    b %= p;
    for (ll i = 1; i <= m; ++i)
    {
        b = b * a % p;
        f[b] = i;
    }
    ll t = qpow(a, m, p);
    b = 1;
    for (ll i = 1; i <= m; ++i)
    {
        b = b * t % p;
        if (f[b])
        {
            return (i * m - f[b] + p) % p;
        }
    }
    return -1;
}
ll exbsgs(ll a, ll b, ll p)
{
    if (b == 1 || p == 1)
    {
        return 0;
    }
    ll g = __gcd(a, p), k = 0, na = 1;
    while (g > 1)
    {
        if (b % g != 0)
        {
            return -1;
        }
        k++, b /= g, p /= g, na = na * (a / g) % p;
        if (na == b)
        {
            return k;
        }
        g = __gcd(a, p);
    }
    ll f = bsgs(a, b * inv(na, p) % p, p);
    if (f == -1)
    {
        return -1;
    }
    return f + k;
}

signed main()
{
    a = read(), p = read(), b = read();
    while (a || b || p)
    {
        a %= p, b %= p;
        ll t = exbsgs(a, b, p);
        if (t == -1)
        {
            printf("No Solution\n");
        }
        else
        {
            printf("%lld\n", t);
        }
        a = read(), p = read(), b = read();
    }
    return 0;
}
```





#### Pohlig-Hellman

若要p在long long也有概率能过，则：

```c++
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define IL __int128
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
namespace PhoRho{ //Phollard-Rho不解释（见Luogu P4718）
	LL gcd(LL a,LL b){
		if (b==0) return a;
		return gcd(b,a%b);
	}
	LL fastpow(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=(IL)ans*x%mod;
			x=(IL)x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL max_factor;
	bool MillerRabin(LL x,LL b){
		LL k=x-1;
		while (k){
			LL cur=fastpow(b,k,x);
			if (cur!=1 && cur!=x-1) return false;
			if ((k&1)==1 || cur==x-1) return true;
			k>>=1;
		}
		return true;
	}
	bool prime(LL x){
		if (x==46856248255981LL || x<2) return false;
		if (x==2 || x==3 || x==7 || x==61 || x==24251) return true;
		return MillerRabin(x,2) && MillerRabin(x,3) && MillerRabin(x,7) && MillerRabin(x,61);
	}
	LL f(LL x,LL c,LL n){
		return ((IL)x*x+c)%n;
	}
	LL PRho(LL x){
		LL s=0,t=0,c=1LL*rand()*(x-1)+1;
		int stp=0,goal=1;
		LL val=1;
		for (goal=1;;goal<<=1,s=t,val=1){
			for (stp=1;stp<=goal;++stp){
				t=f(t,c,x);
				val=(IL)val*abs(t-s)%x;
				if (stp%127==0){
					LL d=gcd(val,x);
					if (d>1) return d;
				}
			}
			LL d=gcd(val,x);
			if (d>1) return d;
		}
	}
	void fac(LL x){
		if (x<=max_factor || x<2){
			return;
		}
		if (prime(x)){
			max_factor=max_factor>x?max_factor:x;
			return;
		}
		LL p=x;
		while (p>=x) p=PRho(x);
		while ((x%p==0)) x/=p;
		fac(x);fac(p);
	}
	LL divide(LL n){
		srand((unsigned)time(NULL));
		max_factor=0;
		fac(n);
		return max_factor;
	}
} 
namespace DLP{
	const int N=1111111;
	LL fastpow(LL a,LL n){ //快速幂不解释
		LL res=1;
		while (n>0){
			if (n&1) res=res*a;
			a=a*a;
			n>>=1;
		}
		return res;
	}
	LL fastpow(LL a,LL n,LL p){ //快速幂*2不解释
		LL res=1;
		a%=p;
		while (n>0){
			if (n&1) res=(IL)res*a%p;
			a=(IL)a*a%p;
			n>>=1;
		}
		return res;
	}
	int prime[N],ptot;
	bool ispr[N];
	struct pt{
		LL p;
		int c;
	};
	void getprime(){ //获取10^6以内的质数
		memset(ispr,1,sizeof(ispr));
		for (int i=2;i<N;++i){
			if (ispr[i]) prime[++ptot]=i;
			for (int j=1;j<=ptot && prime[j]<=(N-1)/i;++j){
				ispr[i*prime[j]]=0;
				if (!i%prime[j]) break;
			}
		}
	}
	bool cmp(pt x,pt y){
		return x.p<y.p;
	}
	void findorg(vector <pt> &v,LL num){ //num分解质因数
		while (num>=N){ //大于10^6的部分，每次用Pho-Rho算法找出最大的一个质因子，然后除掉即可
			LL maxf=PhoRho::divide(num);
			int cnt=0;
			while (num%maxf==0){
				cnt++;
				num=num/maxf;
			}
			v.push_back((pt){maxf,cnt});
		}
		if (ptot==0) getprime();
		for (int i=1;i<=ptot && prime[i]<=num;++i){ //剩下的就是不大于10^6的质因子了，直接暴力枚举
			if (num%prime[i]==0){
				int cnt=0;
				while (num%prime[i]==0){
					cnt++;
					num/=prime[i];
				}
				v.push_back((pt){prime[i],cnt});
			}
		}
		if (num>1) v.push_back((pt){num,1});
		sort(v.begin(),v.end(),cmp); //这句话说实在没有意义
	}
	int getorg(LL p,LL phi,vector <pt> &v){ //获取ord
		for (int k=2;;k++){
			int flag=1;
			for (int i=0;i<(int)v.size();++i){
				if (fastpow(k,phi/v[i].p,p)==1){
					flag=0;
					break;
				}
			}
			if (flag) return k;
		}
	}
	LL BSGS(LL a,LL b,LL p,LL mod){ //BSGS模板，具体可以见其它题解的一般做法
		a%=mod;b%=mod;
		if (b==1) return 0;
		if (a==0){
			if (b==0) return 1;
			else return -1;
		}
		LL t=1;
		int m=int(sqrt(1.0*p)+1);
		LL base=b;
		unordered_map <LL,LL> vis;
		for (int i=0;i<m;++i){
			vis[base]=i;
			base=(IL)base*a%mod;
		}
		base=fastpow(a,m,mod);
		LL now=t;
		for (int i=1;i<=m+1;++i){
			now=(IL)now*base%mod;
			if (vis.count(now)) return i*m-vis[now];
		}
		return -1;
	}
	LL getksi(LL g,LL h,LL p,LL c,LL n,LL mod){ //得到合并后的解集，然后上BSGS
		vector <LL> pi;
		LL tp=1;
		for (int i=0;i<=c;++i){
			pi.push_back(tp);
			tp*=p;
		}
		LL gq=fastpow(g,pi[c-1],mod);
		LL inv=0;
		tp=1;
		for (int i=c-1;i>=0;--i){
			LL tx=tp*BSGS(gq,fastpow((IL)h*fastpow(g,pi[c]-inv,mod)%mod,pi[i],mod),p,mod);
			inv+=tx;tp*=p;
		}
		return inv;
	}
	LL exgcd(LL a,LL b,LL &x,LL &y){ //exgcd模板不解释
		if (b==0){
			x=1;y=0;
			return a;
		}
		LL d=exgcd(b,a%b,y,x);
		y-=a/b*x;
		return d;
	}
	LL getinv(LL a,LL p){ //逆元不解释
		if (a==0) return 1;
		LL x,y;
		exgcd(a,p,x,y);
		return (x%p+p)%p;
	}
	LL gcd(LL x,LL y){ //gcd不解释
		if (x%y==0) return y;
		return gcd(y,x%y);
	}
	LL ExgcdSolve(LL a,LL b,LL c,LL &x,LL &y){ //求解exgcd
		LL d;
		if (c%(d=gcd(a,b))) return -1;
		a/=d;b/=d;c/=d;
		exgcd(a,b,x,y);
		x=(IL)x*c%b;
		while (x<=0) x+=b;
		return x; 
	}
	LL crt(vector <LL> ksi,vector <pt> v){ //crt不解释
		int sz=v.size();
		LL M=1,ans=0;
		vector <LL> m;
		for (int i=0;i<sz;++i){
			m.push_back(fastpow(v[i].p,v[i].c));
			M*=m[i];
		}
		for (int i=0;i<sz;++i){
			LL Mi=M/m[i];
			ans=((IL)ans+(IL)Mi*getinv(Mi,m[i])*ksi[i])%M;
		}
		if (ans<0) ans+=M;
		return ans;
	}
	LL getx(LL h,LL g,LL N,LL mod,vector <pt> &v){ //获取解集，然后用crt合并
		vector <LL> ksi;
		for (pt tp:v){
			LL tg=fastpow(g,N/fastpow(tp.p,tp.c),mod);
			LL th=fastpow(h,N/fastpow(tp.p,tp.c),mod);
			ksi.push_back(getksi(tg,th,tp.p,tp.c,N,mod));
		}
		return crt(ksi,v);
	}
	LL solve(LL g,LL h,LL p){ //求解
		if (h==1) return 0;
		LL phiP=p-1;
		vector <pt> v;
		findorg(v,phiP);
		int rt=getorg(p,phiP,v);
		LL x=getx(g,rt,phiP,p,v);
		LL y=getx(h,rt,phiP,p,v);
		LL a=0,b=0;
		if (x==0){
			if (y==0) return 1;
			else if (y==1) return 0;
			else return -1;
		}else return ExgcdSolve(x,phiP,y,a,b);
	}
};
signed main(){
	LL p=read(),g=read(),h=read(); 
    LL ans=DLP::solve(g,h,p);
    if (ans==-1) puts("no solution");
    else cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
```

## 动态规划

#### 基本概念

> 将算式的计算结果记录在内存中，需要时直接调用该结果，从而避免无用的重复计算，提高处理效率。

**动态规划**(dynamic programming, DP)原问题视作若干个**重叠**的子问题的逐层递进，每个子问题的求解过程都会构成一个“阶段”，在完成一个阶段后，才会执行下一个阶段。
dp要满足**无后效性**即已经求解的子问题不受后续阶段的影响。

常用填表法和刷表法。

- 填表法：利用状态转移方程和上一个状态来推导出现在的状态（相当于知道已知条件，将答案填入）
- 刷表法：利用当前的状态，把有关联的下一状态都推出来。

**最优子结构**：一些dp问题可以由若干个平行相似的、互不影响的dp子问题构成，那么可以求出各个子问题的dp解，然后做累积(求和、求积、求异或等)即可。

#### 记忆化搜索

将重复计算的结果存储，下次需要这个中间结果时无需重复计算，只需要直接调用。适用于情况数比较小，比如说假设数组都能开到1e9那肯定不能用了。

举例：斐波那契数列

可以使用宏简化：

```c++
//假设记忆用数组初始值都是0，且计算结果取值范围不包含0；如果包含了0，那需要用bool数组表示是否已经算过
#define F(x) (F(x) ? F(x) : F(x) = f(x))
```

#### 滚动数组

二层滚动数组如下，其他类推：

```c++
//三种实现方法：
dp[i%2][j];
dp[i&1][j];
dp[t=1-t][j];//da tr; t=0(init); 或t^=1
```

> 如果是01背包，二层还能压成一维

特别提醒：滚动应特别注意初始化问题，例如下题(求最大只含1子正方形边长)：

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 102
#define rep(i,a,b) for(int i=a;i<=b;++i)
int dp[2][MAXN],ans,n,m,t;
signed main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m){
        scanf("%d",&t);
        if(t)
        {
            dp[i&1][j]=min(min(dp[i&1][j-1],dp[(i-1)&1][j]),dp[(i-1)&1][j-1])+1;
            ans=max(ans,dp[i&1][j]);
        }
        else dp[i&1][j]=0;//如果不滚动，不需要这行}
    printf("%d",ans);
    return 0;
}
```

#### 组合dp

##### 放苹果

> m个同样的苹果放到n个盘子(可不放)，求组合情况数(求C不求A)

###### 搜索

个人实现版本

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll m, n, t, ans, a[14];
void dfs(ll c, ll lf)
{
	if (c > n)
	{
		if (!lf)
		{
			++ans;
		}
		return;
	}
	repe(i, a[c - 1], lf)//其实可以再优化
	{
		a[c] = i;
		dfs(c + 1, lf - i);
	}
}
signed main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &m, &n);
		ans = 0;
		dfs(1, m);
		printf("%d\n", ans);
	}
	return 0;
}
```

###### dp

设$d[m][n]$代表m,n下的答案

1. 边界条件
   1. $m=0或n=1，dp[m][n]=1$
   2. $n>m, dp[m][n]=dp[m][m]$
2. 递推条件$dp[m][n]=dp[m-n][n]+dp[m][n-1]$
   递推意义：若放满盘子，所有盘子的苹果各拿掉一个，方案数不变； 若不放满盘子，则可以把空盘子直接拿掉一个，方案数不变。

举例：$dp[4][2]，显然只有0,4;1,3;2,2三种情况$

$由公式，dp[4][2]=dp[2][2]+dp[4][1]=dp[0][2]+dp[2][1]+dp[4][1]=3$

> 实现很简单，开双for和if-else-if-else即可。故不展示代码

##### paint

> (scnucpc2020)有$n\times3$格子，可染黄绿蓝三色的一种，橫或竖相邻的格子不能染相同的颜色，求情况数对$10^9+7$取模。

###### 解法一

对于每列(每3个)，三色互不相同共有6种情况，只有两种颜色共有6种情况，
显而易见n=1(只有一列)时,答案为6+6=12

n>1时,每一列仍只有6种三色和6种二色情况。
在上一列中：
对于每一种三色，只可能推出四种下一列，且必然是二种三色和二种二色：
以RYG为例，它的下一列仅可能是GRY,YRG,YGY,YRY,前两个为三色，后两个为二色。
另外五个三色GYR,YRG,GRY,YGR,RGY与此相似。
对于每一种二色，只可能推出五种下一列，且必然是二种三色和三种二色：
以RYR为例，它的下一列仅可能是YRG,GRY,YRY,GRG,YGY，前两个为三色，后三个为二色。
另外五种二色RGR,GRG,GYG,YRY,YGY与此相似。

因此，第二列可以由第一列推出，第一列每个颜色都只有一种情况，
根据上面分析，
上一列的每个三色都可以推出下一列的两种三色，两种二色，共4种
上一列的每个二色都可以推出下一列的两种三色，三种二色，共5种
所以n=2的情况数为 6*4 (三色) + 6*5(二色)
且第二列每种三色情况数为2+2(三色推出+二色推出)
		每种二色情况数为2+3(三色推出+二色推出)
即n=2情况数为6*(2+2) + 6*(2+3)

设c3表示最后时每种三色情况数，c2表示最后时每种二色情况数，有递推关系：
c3 = 2*c3 + 2*c2
c2 = 2\*c3 + 3\*c2
answer = 6\*c3 + 6\*c2
初始状态(n=1)时,c3=c2=1

```c++
#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
ll c3=1,c2=1,ans,n,temp3,temp2;
signed main()
{
    scanf("%lld",&n);
    for(;n>1;n--)
    {
        temp3=2*c3+2*c2;
        temp3%=MOD;
        temp2=2*c3+3*c2;
        temp2%=MOD;
        c3=temp3;
        c2=temp2;
    }
    printf("%lld", (6*(c3+c2)) %MOD );
    return 0;
}
```

###### 解法二

设$dp[h][i][j][k]$表示前$h$列，第$h$列从上到下颜色分别为$i,j,k$的情况数，直接暴力可得：

```c++
#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
typedef long long ll;

ll dp[maxn][3][3][3];

const int MOD = 1e9 + 7;
int n;
int main()
{
    cin >> n;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (i != j && j != k)
                    dp[1][i][j][k] = 1;

    for (int p = 2; p <= n; p++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    for (int a = 0; a < 3; a++)
                        for (int b = 0; b < 3; b++)
                            for (int c = 0; c < 3; c++)
                                if (i != j && j != k && a != b && b != c && i != a && j != b && k != c)
                                    dp[p][i][j][k] = (dp[p][i][j][k] + dp[p - 1][a][b][c]) % MOD;

    ll ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (i != j && j != k)
                    ans = (ans + dp[n][i][j][k]) % MOD;

    cout << ans << endl;

    return 0;
}
```

##### 串

> (oj)求长为$n$的含子串$us$的小写字母串数量(对$10^9+7$取模)，$1\le n\le10^6$

###### 解法一

设$i$为字符串长度，$c[i]$是不含$u$的字符串数，$b[i]$是含$u$但不含$us$的字符串数，$a[i]$是$i$时的答案：
$$
c[i]=c[i-1]\times25\quad(每格可以放除u外的任意字符，含s)\\
b[i]=b[i-1]\times25+c[i-1]\quad(最新一格放非u+放u的情况)\\
a[i]=a[i-1]\times26+b[i-1]\quad((之前有us)最新一格随便放或(之前无us)放s)
$$
可以状态压缩，代码如下：

```c++
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long newu,nou=1,t,n,r;
signed main()
{
    scanf("%lld",&n);
    if(n<=1) return printf("0")&0;
    for(int i=0;i<n;++i)
    {
        t=(t*26+newu)%mod;
        (r+=t)%=mod;
        newu=(newu*25+nou)%mod;
        nou=nou*25%mod;
    }
    return printf("%lld",r)&0;
}
```

###### 解法二

如果之前有完整的$us$，那么可以填任意：
$$
dp[i]=dp[i-1]\times26
$$
加上之前没有$us$的情况，即之前有$u$的情况，即全集减有$us$减无$u$，即：
$$
dp[i]=dp[i-1]\times26+26^{i-1}-dp[i-1]-25^{i-1}
$$

##### 选球

> (scnucs2020)桌面上按顺序摆放着$n$个球，球有两种颜色，红色和蓝色。你需要从中选择出$4$个球，要求：没有两个球是相邻的，四个球的颜色不能相同；请问一共有多少种不同的方案。

取反，方案数=四个不相邻任意球(总)-四个红球-四个蓝球

设$dp[i][j]$表示选$i$个球，范围为前$j$个球，设三种$dp$。初始化显而易见：
$$
dp[1][j]=j\quad(总)\\
dp[1][j]=dp[1][j-1]+('R'==str[j])\quad(R/B)
$$
递推关系为：
$$
dp[i][j]=dp[i-1][j-2]+dp[i][j-1]
$$
也就是范围短一个时顺承过来加上少选一个的情况。注意红蓝$dp$递推时，分两种情况，符合时一个递推，另一个直接顺承；反之相反。

```c++
#include <bits/stdc++.h>
#define MAXN 1000002
#define N 1000000
//#define MOD (1e9+7)
#define MOD 1000000007
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define ir i-1
#define jr j-1
using namespace std;
typedef long long ll;
ll t,n,dp[5][MAXN], red[5][MAXN], blue[5][MAXN];
char x[MAXN];
signed main()
{
    scanf("%lld",&t);
    rep(i,1,N)
    {
        dp[1][i]=i;
    }
    rep(i,2,4)
    {
        rep(j,2*i-1,N)
        {
            dp[i][j] += dp[i][jr] + dp[ir][j-2];
            dp[i][j] %= MOD;
        }
    }
    while(t--)
    {
        scanf("%lld\n%s",&n,x);
        rep(i,1,n)
        {
            red[1][i] = red[1][ir] + (x[ir]=='R');
            blue[1][i] = blue[1][ir] + (x[ir]=='B');
        }
        rep(i,2,4)
        {
            rep(j,2*i-1,n)
            {
                if(x[jr]=='R')
                {
                    red[i][j] = red[i][jr] + red[ir][j-2];
                    red[i][j] %= MOD;
                    blue[i][j] = blue[i][jr];
                }
                else
                {
                    blue[i][j] = blue[i][jr] + blue[ir][j-2];
                    blue[i][j] %= MOD;
                    red[i][j] = red[i][jr];
                }
            }
        }
        printf("%lld\n",(2*MOD+dp[4][n]-red[4][n]-blue[4][n])%MOD );
    }
    return 0;
}
```

> 其他解法：①前缀和 $\Omicron(n^2)$ 预处理红球数和蓝球数的前缀和、后缀和数组，然后枚举中间两个球(j=i+2开始而不是i+1因为不相邻)，方案数分类讨论(左闭区间和右区间分别是1到i-2和j+2到n)，若ij异色，则方案数为前缀和和后缀和两两相乘，即红红、蓝蓝、红蓝、蓝红；如果同色，同红时没有红红有其他三个，同蓝同理，代码略
>
> ②还有一种dp方案，同样设三个，$dp[i][j]$表示取i个球且逼取第n个，递推方程是：
> $$
> dp[i][j]=\sum_{k=0}^{j-2}dp[i-1][k](若同色，否则0)
> $$
> 答案是：
> $$
> \sum_{i=1}^ndp[4][i]-\sum_{i=1}^ndpR[4][i]-\sum_{i=1}^ndpB[4][i]
> $$
> 使用前缀和优化，不使用memset，可以达到$\Omicron(n)$的时间复杂度

##### We Like AGC

> (scnucpc预赛)求长为n的、只含$ACGT$的、不含$AGC$且交换相邻字符后仍不含$AGC$的字符串数量对$10^9+7$取模。

直接模拟即可，设$dp[h][i][j][k]$是长为$h$且最后一、二、三个字符分别为$i,j,k$的字符串的答案。

```c++
#include <iostream>
#define maxn 105
using namespace std;
typedef long long ll;

ll dp[maxn][4][4][4];
const ll MOD = 1e9 + 7;
bool check(int j, int k, int v)
{
	return !(j == 0 && k == 2 && v == 1);
}
bool check2(int j, int k, int v)
{
	// 0->a, 1->c, 2->g, 3->t
	if (!((j == 0 && k == 2 && v == 1) || (j == 0 && k == 1 && v == 2) || (j == 2 && k == 0 && v == 1)))
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int v = 0; v < 4; v++)
			{
				if (check2(j, k, v))
					dp[3][j][k][v] = 1;
			}
		}
	}

	for (int i = 4; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int v = 0; v < 4; v++)
				{
					for (int u = 0; u < 4; u++)
						if (check2(j, k, v) && check(u, k, v) && check(u, j, v) && check(u, j, k))//最后一个check没有也行；因为这种情况下原dp[i-1][u][j][k]就是0
							dp[i][j][k][v] = (dp[i][j][k][v] + dp[i - 1][u][j][k]) % MOD;
				}
			}
		}
	}

	ll ans = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					ans = (ans + dp[n][i][j][k]) % MOD;

	cout << ans << endl;
	return 0;
}
```

##### 一道难题

> (oj)一个长为n的循环序列，最大值为m，即$1,2,...,m,1,...$，可以删除零到全部元素，问会有多少不同的序列(对$10^9+7$取模),$1\le n,m\le2\times10^5$

当没有超过m时，显然情况数是$2^i$，超过之后，需要去重，每次新的去重部分等于$dp[i-m-1]$，即第一次需要去重$dp[0]=1$，实质重复的是$1$即含第一项的项,第二次是含第二项即$2;1,2$，第三次以此类推，得到递推关系：
$$
dp[i]=dp[i-1]*2-dp[i-m-1]\ \ if\ i>m
$$
代码如下：

```c++
#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll t,n,m,dp[200002];
signed main()
{
	for(scanf("%lld",&t),dp[0]=1;t;--t)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;++i) dp[i]=(dp[i-1]<<1)%mod;
		for(int i=m+1;i<=n;++i) dp[i]=((dp[i-1]<<1)%mod-dp[i-m-1]+mod)%mod;
		printf("%lld\n",dp[n]);
	}
	return 0;
}
```

##### 大师

> 求一个数列的所有等差子数列(只有一个和两个元素都算等差数列)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1002
#define MOD 998244353
ll n, a[MAXN], dp[MAXN][40002], mxh, ans;
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld", &a[i]), mxh = max(mxh, a[i]);
	repe(i, 2, n) rep(j, 1, i)
	{
		(dp[i][a[i] - a[j] + mxh] += (1 + dp[j][a[i] - a[j] + mxh])) %= MOD;//1是只有两个元素
		(ans += dp[j][a[i] - a[j] + mxh] + 1) %= MOD;
	}
	printf("%lld", (ans + n) % MOD);//补上只有一个元素
	return 0;
}
```

##### 格子刷油漆

> (蓝桥)有$2\times N$矩形，需要遍历一次，可以从任一格子开始，移动到相邻或对角相邻的格子上，求方案数(对十亿零七取模)($1\le N\le1000$)

本题dp递推方程不唯一。

设$a[n]$表示$2\times n$矩形从一个角出发的所有方案数，$b[n]$表示$2\times n$矩形从一个角出发，回到它的同一列对面的方案数，显然$b[n]\le a[n]$，

可以得到初始状态为：$b[1]=1,a[1]=1,b[2]=2,a[2]=6$

可以推知，$b[n]=2b[n-1]$，因为往下一列有且只有两种解法(来回时必须各走一个)，乘法原理也易知。

$a[n]$的第一种状态就是$b[n]$，此外，还可以分为两种状态：

②先走到同一列的对面，再走其他格子。此时可以选择走到左上或左下，即两种走法，之后等于该情况少一列(少了最开始的第一列)的方案数，即$+2a[n-1]$

③前面两种走法不能够走全所有方案，还可以先走到左上|左下，然后返回最开始同一列对面，再走到左上|左下，之后可以往左下或左上走，等于消掉了一开始的两列之后的方案数，即$+4a[n-2]$

注意还可以从中间(即非头非尾的任何一列)出发，三分为左边列，中间一列和右边列，等效于先左边走回来，消掉了左边列和中间一列，然后右边列任意走；反过来也一样，中间可以从上或下开始，可以连接左边或右边的上边或下边，所以系数是$2^3$，因此$+8(a[左]\times b[右]+a[右]\times b[左])$。

总情况为所有中间+四个角。注意$n=1$要特判。总代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 1004
long long a[mn],b[mn],ans,n;
#define mod 1000000007
signed main()
{
	scanf("%lld",&n); if(n==1) return printf("2")&0;
	a[1]=1,b[1]=1,b[2]=2,a[2]=6;
	for(int i=3;i<=n;++i)
	{
		b[i]=(b[i-1]<<1)%mod;
		a[i]=(b[i]+(a[i-1]<<1)+(a[i-2]<<2))%mod;
	}
	for(int i=2;i<n;++i)
		(ans+=((a[n-i]*b[i-1])<<3)%mod+((b[n-i]*a[i-1])<<3)%mod)%=mod;
	printf("%lld",(ans+(a[n]<<2))%mod);
	return 0;
}
```

##### 二维跑步

> (oj)在二维空间跑步，初始位置是$(0,0)$，跑了$n$次，每次可以如此跑步：
>
> - 从$(i,0)$到$(i+1,0),(i+1,1),(i+1,2),(i,0),(i-1,1),(i-1,2)$
> - 从$(i,1)$到$(i+1,0),(i+1,1),(i+1,2),(i,1),(i-1,0),(i-1,2)$
> - 从$(i,2)$到$(i+1,0),(i+1,1),(i+1,2),(i,2),(i-1,0),(i-1,1)$
>
> 求有多少种跑步方式，使得$x$坐标最终落在$[-m,m]$，答案对$998244353$取模。
>
> $1\le n,m\le3\times10^6$

###### 暴力模拟

首先这种方法必然TLE，但是可以拿部分的分，起码到$1000$都不会炸。(该方法并非最优模拟)

```c++
#include <bits/stdc++.h>
using namespace std;
#define BIG 0x7fffffff
#define BBIG 0x7fffffffffffffff
#define re register
#define il inline
typedef long long ll;
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define MAXN 1002
#define MOD 998244353
ll dp[MAXN][2*MAXN],n,m,tj,ans;
il ll nti(ll i) {return i+MAXN;}
signed main()
{
    cin>>n>>m;
    dp[0][nti(0)]=1;
    rep(i,1,n+1)
    {
        rep(j,-n,n+1)
        {
            tj=nti(j);
            dp[i][tj]=max(dp[i-1][tj-1]*3+dp[i-1][tj]+dp[i-1][tj+1]*2, dp[i-1][tj]);
            //dp[i][tj]=max(dp[i-1][tj+1]*2, dp[i][tj]);
            dp[i][tj]%=MOD;
        }
    }
    rep(j,-m,m+1)
    {
        tj=nti(j);
        ans+=dp[n][tj];
    }
    cout<<ans%MOD;
    return 0;
}
```

###### 组合数学

显然本题前进时增加三种状态，后退时增加两种，原地不动是一种。

假设有$i$步原地踏步，则有$n-i$步移动；在移动里面，如果有$a$步向右，则有$n-i-a$步向左，最终位移是$a-(n-i-a)$，即求：
$$
-m\le a-(n-i-a)\le m\Rightarrow\\
\frac{n-m-i}2\le a\le\frac{n+m-i}2
$$
注意到$a$必然是整数，且a必然不可能超过$n-i$，也不可能小于0，所以需要微调：
$$
\max(\lceil\frac{n-m-i}2\rceil,0)\le a\le\min(\lfloor\frac{n+m-i}2\rfloor,n-i)
$$
根据排列组合可知，记上述式子的$a$的两侧最值分别为$l,r$，则答案为：
$$
\sum_{i=0}^nC_n^i\sum_{a=l}^rC_{n-i}^a3^a2^{n-i-a}
$$
显然时间复杂度是$\Omicron(n^2)$，不可能通过。继续寻找递推关系，令：
$$
f(n,m)=C_n^m3^m2^{n-m}
$$
根据组合的性质，可以发现：
$$
f(n,m)=3f(n-1,m-1)+2f(n-1,m)
$$
累加得：
$$
\sum_{i=u}^vf(k,i)=5\sum_{i=u}^vf(k-1,i)+3f(k-1,u-1)-2f(k-1,v)
$$
而由于$i$连续变化，所以答案公式的第二个求和项的项数相差不会超过一，因此时间复杂度可以成功降到$\Omicron(n)$，其中需要预处理阶乘和幂，总代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353 
#define mn 3000002
#define repe(i,a,b) for(ll i=a;i<=b;++i)
ll n2[mn],n3[mn],n,m,t=1,f[mn],inv[mn],nl,nr,lf,rf,g[mn];
#define il inline
il ll qmul(ll v)
{
	ll r=1;
	for(ll b=mod-2;b;b>>=1,(v*=v)%=mod) if(b&1) (r*=v)%=mod;
	return r;
}
il ll c(ll n, ll m){return f[n]*inv[n-m]%mod*inv[m]%mod;}
il ll h(ll n, ll m){return c(n,m)*n2[n-m]%mod*n3[m]%mod;}
signed main()
{
	scanf("%lld%lld",&n,&m);
	n2[0]=n3[0]=f[0]=inv[0]=1;
	for(ll i=1;i<=n;++i)
	{
		n2[i]=(n2[i-1]<<1)%mod;
		n3[i]=(n3[i-1]*3)%mod;
		f[i]=f[i-1]*i%mod;
		inv[i]=qmul(f[i]);
	}
	for(ll i=n;i>=0;--i)
	{
		nl=max(0LL,n-m-i+1>>1),nr=min(n-i,n+m-i>>1);
		if(nl>lf) t=(t-h(n-i,lf++)+mod)%mod;
		while(nr>rf) t=(t+h(n-i,++rf))%mod;
		g[i]=t,t=t*5%mod;
		if(nl>=1) t=(t+3*h(n-i,nl-1))%mod;
		t=(t-3*h(n-i,nr)%mod+mod)%mod;
	} t=0;
	for(ll i=0;i<=n;++i) t=(t+c(n,i)*g[i])%mod;
	printf("%lld",t);
	return 0;
}
```

##### 合唱队

> n个身高各异的人，按照初始顺序排队，如果比初始前一个人高，排在当前排尾，否则排在当前排头；求一共可能有多少种队形。

设$dp[i][j][k]$为区间$[i,j]$内的队形数，其中k=0代表第i个人从队首进来，k=1代表第j个人从队尾进来。为了避免冲突，规定$dp[i][i][0]=1,dp[i][i][1]=0$，可以证明，互换之后答案是一样的。

状态方程显而易见，每种情况对应两种上一状态，每个$[i,j]$共4种上一状态。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1002
#define MOD 19650827
ll n, a[MAXN], dp[MAXN][MAXN][2];
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d", &a[i]);
	repe(i, 1, n) dp[i][i][0] = 1;
	rep(h, 1, n) repe(i, 1, n - h)
	{
		ll j = i + h;
		if (a[i] < a[i + 1]) dp[i][j][0] += dp[i + 1][j][0];
		if (a[i] < a[j]) dp[i][j][0] += dp[i + 1][j][1],
			dp[i][j][1] += dp[i][j - 1][0];
		if (a[j - 1] < a[j]) dp[i][j][1] += dp[i][j - 1][1];
		dp[i][j][0] %= MOD, dp[i][j][1] %= MOD;
	}
	printf("%d", (dp[1][n][0] + dp[1][n][1]) % MOD);
	return 0;
}
```

##### 互不侵犯

> $n\times n$范围内放k人，它们$3\times 3$内不得有其他人，求有多少种方法

使用状压/数位

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 514
#define N 12//dp的第三维度(从左往右数)定11或以下会WA
ll sit[MAXN], gs[MAXN], cnt, n, k, dp[N][MAXN][N], ans;
void dfs(ll h, ll sum, ll po)
{
	if (po >= n)
	{
		sit[++cnt] = h;
		gs[cnt] = sum;
		return;
	}
	dfs(h, sum, po + 1);
	dfs(h + (1 << (int)po), sum + 1, po + 2);
}
signed main()
{
	scanf("%lld%lld", &n, &k);
	dfs(0, 0, 0);
	repe(i, 1, cnt) dp[1][i][gs[i]] = 1;
	repe(i, 2, n) repe(j, 1, cnt) repe(a, 1, cnt)
	{
		if (sit[j] & sit[a] || (sit[j] << 1) & sit[a] || sit[j] & (sit[a] << 1)) continue;
		rede(s, k, gs[j]) dp[i][j][s] += dp[i - 1][a][s - gs[j]];
	}
	repe(i, 1, cnt) ans += dp[n][i][k];
	printf("%lld", ans);
	return 0;
}
```

##### 炮兵阵地

> 有$n\times m$地图，有平原(P)和高地(H)，炮兵阵地可以放在平原，攻击$5\times 5$十字范围共8格，炮兵阵地不能相互攻击，求该地图最多能放多少个炮兵阵地

状压/数位

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1026
ll n, m, ans, dp[MAXN][MAXN][3], a[105], ac[MAXN];
char x;
inline ll sumarr(ll s)
{
	ll res = 0;
	for (; s; s >>= 1) if (s & 1) ++res;
	return res;
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 0, n) rep(j, 0, m)
	{
		cin >> x;
		(a[i] <<= 1) += (x == 'H' ? 1 : 0);
	}
	repe(i, 0, 1 << m) ac[i] = sumarr(i);
	rep(s, 0, 1 << m) if (!(s & a[0] || (s & (s << 1)) || (s & (s << 2))))
		dp[0][s][0] = ac[s];
	rep(i, 0, 1 << m) rep(j, 0, 1 << m)
		if (!(i & j || i & a[0] || j & a[1] || i & (i << 1) ||
			i & (i << 2) || j & (j << 1) || j & (j << 2)))
			dp[i][j][1] = ac[i] + ac[j];
	rep(i, 2, n) rep(j, 0, 1 << m)
	{
		if (j & a[i - 1] || j & (j << 1) || j & (j << 2)) continue;
		rep(k, 0, 1 << m)
		{
			if (k & a[i] || j & k || k & (k << 1) || k & (k << 2)) continue;
			rep(p, 0, 1 << m)
			{
				if (p & j || p & k || p & a[i - 2]
					|| p & (p << 1) || p & (p << 2)) continue;
				dp[j][k][i % 3] = max(dp[j][k][i % 3], dp[p][j][(i - 1) % 3] + ac[k]);
			}
		}
	}
	rep(i, 0, 1 << m) rep(j, 0, 1 << m) ans = max(ans, dp[i][j][(n - 1) % 3]);
	printf("%d", ans);
	return 0;
}
```

##### Corn Fields G

> 有$m\times n$草地，部分可种草(以1表示)，草不能相邻，求方案数

数位/状压

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 4099
#define MOD 100000000
#define N 13
ll n, m, dp[N][MAXN], f[N], a, mxstt, ans;
bool stt[MAXN];
signed main()
{
	scanf("%lld%lld", &m, &n);
	repe(i, 1, m) repe(j, 1, n) scanf("%lld", &a), (f[i] <<= 1) += a;
	mxstt = 1 << n; dp[0][0] = 1;
	rep(i, 0, mxstt) stt[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
	repe(i, 1, m) rep(j, 0, mxstt) if (stt[j] && ((j & f[i]) == j))
		rep(k, 0, mxstt) if ((j & k) == 0) (dp[i][j] += dp[i - 1][k]) %= MOD;
	rep(i, 0, mxstt) (ans += dp[m][i]) %= MOD;
	printf("%lld", ans);
	return 0;
}
```

##### Emiya家今天的饭

> 有n种煮饭方法，m种材料，每种(n,m)对应$a_{i,j}$种菜；要求至少煮一道菜，每道菜用不同的煮饭方法，某种用材不得超过总用材的一半，求方案数

设$dp[i][j][k]$表示对c列(以n为行，m为列),前i行在第c列选了j道菜，其余选了k道，$s_i$是第i行菜数总和
$$
dp[i][j][k]=dp[i-1][j][k]+a_{i,c}\times dp[i-1][j-1][k]+(s_i-a_{i,c})\times dp[i-1][j][k-1]
$$
复杂度$\Omicron(mn^3)$，需要求和的为：(防用材超一半)
$$
\sum_{j>k}dp[n][j][k]
$$
有重复方案，设$g[i][j]$为前i行选了j个菜，有：
$$
g[i][j]=g[i-1][j]+s_i\times g[i-1][j-1]
$$
则$g[n][i]$全是重复的。

优化dp，设$f[i][j]$表示前i行的(原)j,k差为j，显然：
$$
dp[i][j]=dp[i-1][j]+a_{i,c}\times dp[i-1][j-1]+(s_i-a_{i,c})\times dp[i-1][j+1]
$$
总复杂度为$\Omicron(mn^2)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 102
#define MAXM 2002
#define MOD 998244353
ll n, m, a[MAXN][MAXM], s[MAXN][MAXM];
ll ans, f[MAXN][MAXN << 1], g[MAXN][MAXN];
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) repe(j, 1, m)
	{
		scanf("%d", &a[i][j]);
		(s[i][0] += a[i][j]) %= MOD;
	}
	repe(i, 1, n) repe(j, 1, m)
		s[i][j] = (MOD + s[i][0] - a[i][j] + MOD) % MOD;
	repe(c, 1, m)
	{
		memset(f, 0, sizeof f);
		f[0][n] = 1;
		repe(i, 1, n) repe(j, n - i, n + i)//防止负数
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * a[i][c] % MOD
				+ f[i - 1][j + 1] * s[i][c] % MOD) % MOD;
		repe(j, 1, n) (ans += f[n][n + j]) %= MOD;
	}
	g[0][0] = 1; repe(i, 1, n) repe(j, 0, n)
		g[i][j] = (g[i - 1][j] + (j > 0 ? g[i - 1][j - 1] * s[i][0] % MOD : 0)) % MOD;
	repe(j, 1, n) ans = (ans - g[n][j] + MOD) % MOD;
	printf("%lld", ans * (MOD - 1) % MOD);
	return 0;
}
```

##### 换教室

> 有2n节课，上n节课(每次同时两节，每次二选一)，可以申请换0~m节课，将其换为另一节(申请完毕后才知道结果)。 1~n各节课换课成功概率$k_i$给出。学校是v个教室和e条道路的无向加权图。输入n,m,v,e,输入默认课所在教室$c_i$，更换后课所在教室$d_i$，输入成功概率，输入e条边(u,v,w)，换课策略让总路程尽可能小，求总路程期望值。

可以用Floyd算法跑全源最短路径$mp[i][j]$。由于节点数少，$\Omicron(n^3)$也能过。

> 注意，Floyd的$mp[i][j]$初始化不能开太大，不然会爆int

设$dp[i][j][k]$表示走完了前$i$个节课，选择换j个，本次选择换(k1)或不换(k0)

设四种情况，可以得知递推中有且仅有该四种情况：

- c1 上次没换教室 $c[i-1][0]=c_{i-1}$
- c2 上次换成教室 $c[i-1][1]=d_{i-1}$
- c3 本次没换教室 $c[i][0]=c_i$
- c4 本次换成教室 $c[i][1]=d_i$

有递推方程：
$$
dp[i][j][0]=\min\begin{cases}
dp[i-1][j][0]+mp[c1][c3]\\\\
dp[i-1][j][1]+mp[c1][c3]\times(1-k[i-1])+\\
mp[c2][c3]\times k[i-1]
\end{cases}
$$

$$
dp[i][j][1]=\min\begin{cases}
dp[i-1][j-1][0]+mp[c1][c3]\times(1-k[i])+\\
mp[c1][c4]\times k[i]\\\\
dp[i-1][j-1][1]+mp[c2][c4]\times k[i]\times k[i-1]+\\
mp[c2][c3]\times k[i]\times(1-k[i-1])+\\
mp[c1][c4]\times(1-k[i])\times k[i-1]+\\
mp[c1][c3]\times(1-k[i])\times(1-k[i-1])\\
\end{cases}
$$

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 2002
#define MAXV 305
const double INF = 1e19;
ll n, m, v, e, c[MAXN][2], mp[MAXV][MAXV], ui, vi, wi, c1, c2, c3, c4;
double k[MAXN], dp[MAXN][MAXN][2], ans = INF;
signed main()
{
	memset(mp, 63, sizeof mp);
	scanf("%d%d%d%d", &n, &m, &v, &e);
	repe(i, 1, n) scanf("%d", &c[i][0]);
	repe(i, 1, n) scanf("%d", &c[i][1]);
	repe(i, 1, n) scanf("%lf", k + i);
	repe(i, 1, e) scanf("%d%d%d", &ui, &vi, &wi),
		mp[ui][vi] = mp[vi][ui] = min(wi, mp[ui][vi]);
	repe(k, 1, v) repe(i, 1, v) repe(j, 1, v)
		mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
	repe(i, 1, v) mp[i][i] = mp[i][0] = mp[0][i] = 0;
	repe(i, 0, n) repe(j, 0, m) dp[i][j][0] = dp[i][j][1] = INF;
	dp[1][0][0] = dp[1][1][1] = 0;
	repe(i, 2, n)
	{
		dp[i][0][0] = dp[i - 1][0][0] + mp[c[i - 1][0]][c[i][0]];
		repe(j, 1, min(i, m))
		{
			c1 = c[i - 1][0], c2 = c[i - 1][1], c3 = c[i][0], c4 = c[i][1];
			dp[i][j][0] = min(dp[i][j][0], min(dp[i - 1][j][0] +
				mp[c1][c3], dp[i - 1][j][1] + mp[c1][c3] *
				(1 - k[i - 1]) + mp[c2][c3] * k[i - 1]));
			dp[i][j][1] = min(dp[i][j][1], min(dp[i - 1][j - 1][0] +
				mp[c1][c3] * (1 - k[i]) + mp[c1][c4] * k[i],
				dp[i - 1][j - 1][1] + mp[c2][c4] * k[i] * k[i - 1] +
				mp[c2][c3] * k[i - 1] * (1 - k[i]) +
				mp[c1][c4] * (1 - k[i - 1]) * k[i] +
				mp[c1][c3] * (1 - k[i - 1]) * (1 - k[i])));
		}
	}
	repe(i, 0, m) ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
	printf("%.2lf", ans);
	return 0;
}
```

##### 绿豆蛙的归宿

> 有n点m边有向无环图，等概率地选择一条边从1走到n，求路程期望

设从1走到i的期望为$dp[i]$，有：
$$
dp[x]=\frac{\sum dp[y]}{入度_x}+边长_y=\frac{\sum dp[y]+入度_x\times边长_y}{入度_x}
$$
构建反图使用拓补排序，倒叙进行递推，代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
struct edge { ll nx, to, w; } e[MAXN << 1];
ll n, m, cnt, hd[MAXN], ind[MAXN], dg[MAXN], ui, vi, wi;
double dp[MAXN];
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { hd[u],v,w };
	hd[u] = cnt;
}
queue<ll> q;
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, m)
	{
		scanf("%d%d%d", &ui, &vi, &wi);
		adde(vi, ui, wi);
		++ind[ui], ++dg[ui];
	}
	q.push(n);
	while (!q.empty())
	{
		ll x = q.front();
		q.pop();
		for (ll i = hd[x]; i; i = e[i].nx)
		{
			ll toi = e[i].to;
			dp[toi] += (dp[x] + e[i].w) / dg[toi];
			if (!(--ind[toi])) q.push(toi);
		}
	}
	printf("%.2lf", dp[1]);
	return 0;
}
```

#### 背包dp

...

##### 常规背包

###### 凑零钱

> (天梯)有$n(1\le n\le10^4)$枚硬币，请问能否凑到$m(1\le m\le100)$，如果可以，从小到大输出硬币面值，不可以，输出`No Solution`，如果有多个解，输出序列最小的解。注：我们说序列{ *A*[1],*A*[2],⋯ }比{ *B*[1],*B*[2],⋯ }“小”，是指存在 *k*≥1 使得 *A*[*i*]=*B*[*i*] 对所有 *i*<*k* 成立，并且 *A*[*k*]<*B*[*k*]。

个人解法：跑简单布尔值背包，注意更新存储的方案。虽然按理来说这个方法时间复杂度是$\Omicron(nm^2)$不能过题，但是实际上过了。注意如果不排序无法过题，暂未知道原因。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll dp[102],c[10002],t;
#define re register
#define il inline
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;--i)
#define rede(i,a,b) for(re ll i=a;i>=b;--i)
#define big 0x7ffffffa
#define bigw "A"
struct memory
{
    ll m[102]={},len;
    inline bool operator < (const memory& x) const
    {
        re ll y = max(len,x.len);
        repe(i,1,y)
        {
            if(m[i]<x.m[i]) return true;
            else if(m[i]>x.m[i]) return false;
        }
        return false;
    }
    inline void operator = (const memory& x)
    {
        len=x.len;
        repe(i,1,len) m[i]=x.m[i];
    }
} me[102],tem;
//string me[102];
signed main()
{
    re ll n,m;
    scanf("%d%d",&n,&m);
    repe(i,1,n) scanf("%d",c+i);
    sort(c+1,c+1+n);
    repe(i,0,m) me[i].m[1]=99999;
    dp[0]=1;
    repe(i,1,n)
    {
        rede(j,m,0)
        {
            if(j+c[i]<=m&&dp[j])
            {
                dp[j+c[i]]=1;
                tem=me[j];
                ++tem.len;
                tem.m[tem.len]=c[i];//写成i暴死
                if(tem<me[j+c[i]])
                {
                    me[j+c[i]]=tem;
                }
            }
        }
    }
    if(dp[m])
    {
        t=m;
        printf("%d",me[m].m[1]);
        repe(i,2,me[m].len) printf(" %d",me[m].m[i]);
    }
    else
    {
        printf("No Solution");
    }
    return 0;
}

```



###### 花店橱窗布置

> 有f束花，有v的花瓶，后给出的花必须放在先给出的花右，每个花瓶放一朵花。花瓶和花束对应产生不同的美学值，求最大的美学值和放花方案花瓶编号序列。
>
> $1\le f\le100, f\le v\le 100$

解法一：

设$dp[i][j]$表示选了前$i$束花，第$i$束花放在第$j$个花瓶下的最大美学值。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 102
typedef long long ll;
ll dp[mn][mn],pre[mn][mn],f,v,a[mn][mn],ans,tf,tv;//dp[i][j]选了前i束花，第i束花放在第j个盆
void prt(ll x, ll y)
{
    if(pre[x][y]==y)
    {
        printf("%lld ",y);
        return;
    }
    prt(x-1,pre[x][y]);
    printf("%lld ",y);
}
signed main()
{
    scanf("%lld%lld",&f,&v);
    for(ll i=1;i<=f;++i)
    {
        for(ll j=1;j<=v;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    for(ll i=1;i<=v-f+1;++i) dp[1][i]=a[1][i],pre[1][i]=i;//第1束花只能放在最右到v-f+1的位置
    for(ll i=2;i<=f;++i)//加上第i束花
    {
        for(ll j=i;j<=v-f+i;++j)//第i束花只能放在第i到v-f+i的位置上(如果往后了，后面就放不完了，往前同理(?))
        {
            for(ll k=1;k<j;++k)//从1开始是说其实可以不放完花？
            {
                if(dp[i-1][k]+a[i][j]>dp[i][j])
                {
                    dp[i][j]=dp[i-1][k]+a[i][j];
                    pre[i][j]=k;
                }
            }
        }
    }
    for(ll i=f;i<=v;++i)
    {
        if(dp[f][i]>ans)
        {
            ans=dp[f][i];
            tv=i;
        }
    }
    printf("%lld\n",ans);
    prt(f,tv);
    return 0;
}
```

方法二：

设$dp[i][j]$表示放了前$i$束花，考虑了前$j$个花瓶的最大值：

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int f[maxn][maxn];
int n,m;
int cost[maxn][maxn];
struct node
{
	int a[maxn];
	int tail;
}way[maxn][maxn];//记录路径
int main()
{
	memset(f,-127,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	      cin>>cost[i][j];
	for(int i=0;i<=m;i++)
	   f[0][i]=0;
	for(int i=1;i<=n;i++)
	   for(int j=i;j<=m;j++)
	   {
	   	   if(f[i-1][j-1]+cost[i][j]>f[i][j-1])//放比不放好
	   	   {
	   	   	  way[i][j]=way[i-1][j-1];
	   	   	  way[i][j].a[++way[i][j].tail]=j;//方案加一个编号
	   	   	  f[i][j]=f[i-1][j-1]+cost[i][j];
	   	   }
	   	   else//不放比放好
	   	   {
	   	   	  way[i][j]=way[i][j-1];//方案不变
	   	   	  f[i][j]=f[i][j-1];
	   	   }
	   }
	cout<<f[n][m]<<endl;
	for(int i=1;i<=way[n][m].tail;i++)
	{
		cout<<way[n][m].a[i]<<" ";
	}
	return 0;
}
```

方法三：最长路

```c++
//楼下全是dp，那么来个最长路做法 
//可以将这个看成一个以花为横，瓶为纵的表格从下向上找一条路径，上一排的位置必须小于下一排
//那么我们就可以连边去跑最长路了
//同时我们注意到需要记录路径
//那么这里就选dij好了（因为其他的不会记路径啊） 
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#pragma GCC optimize(3)
#define re register
#define maxn 10001
#define maxw 800000
#define inf -99999999
using namespace std;
struct node
{
	int v,w,nxt;
}e[maxw];
int f,v,ans,num=1,end;
int head[maxn],d[maxn],r[maxn];
int a[101][101];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,less<pii> > q;
inline int read()
{
    char c=getchar();
    int x=0;
    int r=1;
    while(c<'0'||c>'9') 
    {
    	if(c=='-') r=-1;
    	c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-48;
        c=getchar();
    }
    return r*x;
}
inline void add_edge(int x,int y,int z)
{
	e[num].v=y;
	e[num].w=z;
	e[num].nxt=head[x];
	head[x]=num++;
}
inline void dijkstra(int s)
{
	for(re int i=1;i<=f*v;i++)
	  d[i]=inf;
	d[s]=0;
	q.push(make_pair(d[s],s));
	while(q.size())
	{
		pii mid=q.top();
		q.pop();
		int k=mid.second;
		for(re int i=head[k];i;i=e[i].nxt)
		if(d[e[i].v]<d[k]+e[i].w)
		{
			d[e[i].v]=d[k]+e[i].w;
			q.push(make_pair(d[e[i].v],e[i].v));//很常规的松弛操作 
			r[e[i].v]=k;//存一下前驱结点，用来找路径 
		}
	}
}
void dfs(int i)
{
	if(i!=0) dfs(r[i]);
	if(i!=0) cout<<i%v<<" ";//dfs找出路径，再将点还原成二维 
}
int main()
{
	f=read();
	v=read();
	for(re int i=1;i<=f;i++)
	for(re int j=1;j<=v;j++)
	a[i][j]=read();
	for(re int i=1;i<=v;i++)
	  add_edge(0,i,a[1][i]);//我们把0作为起点，把第一列的所有点与0相连 
	for(re int i=2;i<=f;i++)
	for(re int k=1;k<=v;k++)
	for(re int j=k+1;j<=v;j++)
	  add_edge((i-2)*v+k,(i-1)*v+j,a[i][j]);//把点的坐标压成一维 
	  //连边，需要注意的是上一行点的横坐标要小于下一行的 
	dijkstra(0);
	ans=inf;
	for(re int i=1;i<=v;i++)
    if(ans<d[(f-1)*v+i])//从最后一行找最长路 
    {
    	ans=d[(f-1)*v+i];
    	end=(f-1)*v+i;
    }
	cout<<ans<<endl;
	dfs(r[end]);
	end%=v;
	if(end==0) end=v;
	cout<<end<<endl;
	return 0;
}
```

方法四：最小费用最大流

```c++
#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to,nxt,flow,cost;
}edge[500005];
int fir[100005],cnt=1;
void add(int u,int v,int w,int c)
{
	edge[++cnt]=(Edge){v,fir[u],w,-c},fir[u]=cnt;
	edge[++cnt]=(Edge){u,fir[v],0,c},fir[v]=cnt;
}
int dis[100005],vis[100005];
int s,t;
int n,m;
bool spfa()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=fir[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].cost&&edge[i].flow)
			{
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v])q.push(v),vis[v]=1;
			}
		}
	} 
	return dis[t]<0x3f3f3f3f;
}
int MC,MF;
int dfs(int u,int flow)
{
	if(u==t)
	{
		MF+=flow;
		vis[u]=1;
		return flow;
	}
	int used=0;
	vis[u]=1;
	for(int i=fir[u];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if((v==t||!vis[v])&&edge[i].flow&&dis[v]==dis[u]+edge[i].cost)
		{
			int mi=dfs(v,min(flow-used,edge[i].flow));
			if(mi)
			{
				edge[i].flow-=mi;
				edge[i^1].flow+=mi;
				used+=mi;
				MC+=mi*edge[i].cost;
			}
			if(used==flow)return used;
		}
	}
	return used;
}
void MCMF()
{
	while(spfa())
	{
		vis[t]=1;
		while(vis[t])memset(vis,0,sizeof(vis)),dfs(s,1);
	}
}
int main()
{
	s=0,t=50000;
	int s2=50001;
	add(s,s2,1,0);
	scanf("%d%d",&n,&m);
	int sum=n*m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int k;
			scanf("%d",&k);
			add((i-1)*m+j,(i-1)*m+j+sum,1,k);
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<m;++j)
		{
			for(int k=j+1;k<=m;++k)
			{
				add((i-1)*m+j+sum,i*m+k,1,0);
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		add(s2,i,1,0);
		add((n-1)*m+i+sum,t,1,0);
	}
	MCMF();
	printf("%d\n",-MC);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			for(int k=fir[(i-1)*m+j];k;k=edge[k].nxt)
			{
				int v=edge[k].to;
				if(v-((i-1)*m+j)==sum&&edge[k].flow==0)
				{
					printf("%d ",j);
				}
			}
		}
	}
}
```



###### 装饰珠

> (蓝桥)(按输入顺序)有6件装备，分别有$n_i$个装饰孔，每个装饰孔对应一个等级$l_i$，有$m$个装饰珠，其等级为$L_i$，有$p_i$种状态，即在$1,2,\dots,p_i$个该装饰珠时，可以获得$w_i$分，大于$p_i$等同于$p_i$。装饰孔上能放等级小于等于该孔的珠求最大价值。$1\le n_i\le50,1\le m,w\le10^4$

```c++
#include <iostream>
#include <cstring>
#include <aLgorithm>
using namespace std;

constexpr size_t MAXN = 55, MAXS = 305, MAXM = 1e4 + 5;
int n[MAXN], cnt[5], Lv[MAXM], p[MAXM], w[MAXM][MAXN];
int dp[MAXM][MAXS];
int m;

inline void Read() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 6; i++) {
        cin >> n[i];
        for (int j = 1, x; j <= n[i]; j++) { cin >> x; cnt[x]++; }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> Lv[i] >> p[i];
        for (int j = 1; j <= p[i]; j++)
            cin >> w[i][j];
    }
}

inline int DP() {
    memset(dp, 0x80, sizeof dp), dp[0][0] = 0;
    int ans = 0, sum = 0, tot = 0;
    for (int L = 4; L >= 1; L--) {
        sum += cnt[L];
        for (int i = 1; i <= m; i++)
            if (Lv[i] == L) {
                tot++;
                for (int k = 0; k <= sum; k++)
                    dp[tot][k] = dp[tot - 1][k];
                for (int j = 1; j <= p[i]; j++)
                    for (int k = j; k <= sum; k++)
                        dp[tot][k] = max(dp[tot][k], dp[tot - 1][k - j] + w[i][j]);
            }
    }
    for (int i = 0; i <= sum; i++) ans = max(ans, dp[tot][i]);
    return ans;
}

signed main() {
    Read();
    cout << DP();
}
```

##### 无限背包

###### 飞扬的小鸟

> 游戏界面长$n$，高$m$，有$k$条宽度不计的水管。小鸟从最左边任意整数高度出发，到达最右边胜利；每个单位时间右移$1$，如果单位时间点击$1$次或多次，上升指定次$x$高度；不点击，下降$y$高度，位于不同的横坐标，$x,y$可能互不同。高度为$m$无法继续上升。高度为$0$或碰到管道失败。求是否可以胜利(输出0/1)，是则输出最少点击屏幕数；否则输出最多可以通过多少个管道。
>
> 输入$n,m,k$，输入$n$行$x,y$代表横坐标$0\sim n-1$处的$x,y$。输入$k$行$p,l,h$，管道横坐标、下边高坐标、上边高坐标。
>
> $5\le n\le10^4,5\le m\le10^3,0\le k<n,0<x,y<m,0<p<n$
>
> $0\le l<h\le m,l+1<h$

设$dp[x][y]$为鸟在$(x,y)$时的最小点击次数，

$x=0$初始化为$0$，其他均为$\infty$。上升可以记为无限背包，注意特判边界。之后用$01$背包下降。如果上一次和这一次之间有管道，有管道的部分重新设置为$\infty$，如果查了一轮发现都是$\infty$，游戏失败，输出当前遍历了多少个管道$-1$；否则胜利，输出$dp[n][y]$的最小值。本题时间复杂度$\Omicron(nm)$较高，可以注意常数优化，空间上复杂度为$\Omicron(4m^2)$，不压缩也能过，但是可以进行压缩，达到$\Omicron(2m)$。

```c++
#define big 0x7ffffffa
#define mn 10010
struct tube
{
    ll i,l,h;
    bool operator<(const tube& x) const {return i<x.i;}
} t[mn];
ll x[mn],y[mn],dp[2][mn],n,m,k,cnt=1,ans=big,h=1,g;
signed main()
{
    memset(dp,127,sizeof dp);
    n=read();m=read();k=read();
    repe(i,1,n) x[i]=read(),y[i]=read();
    repe(i,1,k) t[i].i=read(),t[i].l=read(),t[i].h=read();
    sort(t+1,t+1+k);
    repe(i,1,m) dp[0][i]=0;
    repe(i,1,n)
    {
        repe(j,0,m) dp[h][j]=big;
        repe(j,x[i]+1,x[i]+m) dp[h][j]=min(dp[g][j-x[i]]+1,dp[h][j-x[i]]+1);
        repe(j,m+1,x[i]+m) dp[h][m]=min(dp[h][m],dp[h][j]);
        repe(j,1,m-y[i]) dp[h][j]=min(dp[h][j],dp[g][j+y[i]]);
        if(i==t[cnt].i)
        {
            ans=big;
            repe(j,0,t[cnt].l) dp[h][j]=big;
            repe(j,t[cnt].h,m) dp[h][j]=big;
            repe(j,1,m) ans=min(ans,dp[h][j]);
            if(ans==big) return printf("0\n%lld",cnt-1),0;
            ++cnt;
        }
        h^=1,g^=1;
    }
    ans=big;
    repe(j,1,m) ans=min(ans,dp[n&1][j]);
    return printf("1\n%lld",ans),0;
}
```



##### 分组背包

###### 通天之分组背包

> 有$k$组物品，每组物品只能选一个，背包重$m$，共$n$个物品，求最大价值
>
> $1\le m,n\le10^3$

分组背包模板题

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,m,w[1002],v[1002],mk,dp[1002];
vector<ll> idx[1002];
signed main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
    {
        int wi,vi,ki;
        scanf("%d%d%d",&wi,&vi,&ki);
        w[i]=wi;
        v[i]=vi;
        idx[ki].push_back(i);
        mk=max(mk,ki);
    }
    for(int k=1;k<=mk;++k)
    {
        for(int i=m;i>=0;--i)
        {
            for(int j=0;j<idx[k].size();++j)//严格注意for顺序
            {
                int id=idx[k][j];
                if(i<w[id]) continue;//<=暴毙
                dp[i]=max(dp[i],dp[i-w[id]]+v[id]);
            }
        }
    }
    printf("%d",dp[m]);
    return 0;
}
```

###### 打不过就加入

> (csoj)有$n$个交易，有$w$的计算资源，每个交易有发起者，资源$a$和资源单价$b$，完成一个用户的某个交易之前必须完成它更早给你的交易，求最大利润
>
> $1\le w,n\le10^4,1\le id\le n,0\le a\le10^4,0\le b\le10^6$

分组背包+前缀和，注意本题$\Omicron(10^8)$可以过

```c++
#define mn 10010
ll w, n, dp[mn], id, a, b, ac, bc;
unordered_set<ll> h;
vector<ll> va[mn], vb[mn];
signed main()
{
    w = read();
    n = read();
    rep(i, 0, n)
    {
        id = read();
        a = read();
        b = read();
        if (h.find(id) == h.end())
        {
            va[id].push_back(a);
            vb[id].push_back(a * b);
            h.insert(id);
        }
        else
        {
            ac = a, bc = a * b;
            rep(j, 0, va[id].size())
            {
                ac += va[id][j];
                bc += vb[id][j];
            }
            va[id].push_back(ac);
            vb[id].push_back(bc);
        }
    }
    for (auto k : h)
    {
        rede(i, w, 0)
        {
            rep(j, 0, va[k].size())
            {
                if (i >= va[k][j])//>暴毙
                {
                    dp[i] = max(dp[i], dp[i - va[k][j]] + vb[k][j]);
                }
            }
        }
    }
    printf("%lld", dp[w]);
    return 0;
}
```





##### 多维背包

###### 榨取kkksc03

> 例题：榨取kkksc03
>
> 有nm元,nt时间，有n个目标，达成需要m元和t时间，求最多可以达成多少个目标。

```c++
#include <bits/stdc++.h>//个人实现版本&优解
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 202
ll dp[MAXN][MAXN], m[MAXN], t[MAXN], n, nm, nt;
signed main()
{
	scanf("%d%d%d", &n, &nm, &nt);
	repe(i, 1, n) scanf("%d%d", &m[i], &t[i]);
	repe(i, 1, n)
	{
		rede(jm, nm, 1)
		{
			rede(jt, nt, 1)
			{
				if (jm >= m[i] && jt >= t[i])
				{
					dp[jm][jt] = max(dp[jm][jt], dp[jm - m[i]][jt - t[i]] + 1);
				}
			}
		}
	}
	printf("%d", dp[nm][nt]);
	return 0;
}
```

###### 硬币购物

> 有四种面值的硬币，购物n次，每次带di枚这些硬币，付钱总值s，求每次的付款方法

无限背包变种+容斥原理

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll dp[MAXN + 3], c[6], d[6], t, sum, res, te, cnt;
signed main()
{
	repe(i, 1, 4) scanf("%lld", &c[i]); scanf("%lld", &t);
	dp[0] = 1;
	repe(i, 1, 4) repe(j, c[i], MAXN) dp[j] += dp[j - c[i]];
	while (t--)
	{
		res = 0;
		repe(i, 1, 4) scanf("%lld", &d[i]); scanf("%lld", &sum);
		repe(i, 0, 15)
		{
			te = sum, cnt = 0;
			repe(j, 1, 4) if ((i >> (j - 1)) & 1) 
				te -= c[j] * (d[j] + 1), cnt ^= 1;
			if (te < 0) continue;
			if (!cnt) res += dp[te];
			else res -= dp[te];
		}
		printf("%lld\n", res);
	}
	return 0;
}
```

##### 多重背包

有同一种物品有限$m$件，可以把$m$拆分为$2^0,2^1,2^2,\cdots,m_0$，如$19=1+2+4+8+3$。注意不可以按照快速幂的拆分方法，如拆分为$1+3+16$，因为拆分后的数相互组合一定需要能够拼接成$1\sim m$的所有数目。这样的多重背包，在$n$种物品，每种最多$m$件，最大背包重量为$k$时，时间复杂度是$\Omicron(nk\log m)$。

###### 宝物筛选

> n种宝物，每种价值$v$，重量$w$，有$m$件；载重量为$M$，求最大价值和
>
> $n\le\sum m_i\le10^5,0\le W\le4\times10^4,1\le n\le10^2$

```c++
#define mm 40010
#define mn 1800
ll dp[mm],n,nw,w[mn],v[mn],vi,wi,mi,cnt,b,v2,w2,bs;
signed main()
{
    n=read();nw=read();
    repe(i,1,n)
    {
        vi=read();wi=read();mi=read();b=1,bs=1; v2=vi,w2=wi;
        for(;b<=mi;b<<=1,bs+=b)
        {
            w[++cnt]=wi;
            v[cnt]=vi;
            wi<<=1;vi<<=1;
            mi-=b;
        }
        if(mi>0) w[++cnt]=w2*mi,v[cnt]=v2*mi;
    }
    repe(i,1,cnt)
    {
        rede(j,nw,w[i])
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%lld",dp[nw]);
    return 0;
}
```

> 此题还可以使用单调队列解法。

##### 依赖背包

###### 朴素

以一对一依赖，依赖数为0~2，不存在嵌套依赖为例，则可以直接转化为普通dp的5倍判定(不选、选、选+子1、选+子2、选+子1+子2)

```c++
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:6031)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define MAXN 32002
#define MAXM 62
int dp[MAXN], vm[MAXN], vp[MAXN][4], wm[MAXN], wp[MAXN][4];
int n, m, v, p, q;
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		scanf("%d%d%d", &v, &p, &q);
		if (!q) vm[i] = v, wm[i] = v * p;
		else
		{
			++vp[q][0];
			vp[q][vp[i][0]] = v;
			wp[q][vp[i][0]] = v * p;
		}
	}
	rep(i, 1, m)
	{
		for (int j = n; vm[i] && j >= vm[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - vm[i]] + wm[i]);
			if (j >= vm[i] + vp[i][1])
				dp[j] = max(dp[j], dp[j - vm[i] - vp[i][1]] + wm[i] + wp[i][1]);
			if (j >= vm[i] + vp[i][2])
				dp[j] = max(dp[j], dp[j - vm[i] - vp[i][2]] + wm[i] + wp[i][2]);
			if (j >= vm[i] + vp[i][1] + vp[i][2])
				dp[j] = max(dp[j], dp[j - vm[i] - vp[i][1] - vp[i][2]]
					+ wm[i] + wp[i][1] + wp[i][2]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}
```

###### Golden Sword

> 从1~n放入原料，坚固值为$a_i$，每次放原料前可以取出不超过s个原料，最多同时容纳w个原料，放入第i个原料后，获得$当前原料数\times a_i$个耐久，求最大耐久和

定义$dp[i][j]$为放入第i个原料，放入后有j个原料时的最大耐久和，当前更新的耐久是上一状态下不取出即放入到取出s个再放入的最优解，朴素转移方程为：
$$
dp[i][j]=\max\{dp[i][k]\}+a_i\times j,\ \ k\in[j-1,\min\{m,j+s-1\}]
$$
时间复杂度为$\Omicron(nm^2)$显然超时。

使用单调队列或线段树维护max值，复杂度降低，可以通过。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 5002
#define SML -0x7ffffffffffffff
ll n, w, s, a[MAXN], dp[MAXN][MAXN], q[MAXN], qp[MAXN], lf, rf, ans = SML;
signed main()
{
	scanf("%lld%lld%lld", &n, &w, &s);
	repe(i, 1, n) scanf("%lld", &a[i]);
	repe(i, 0, n) repe(j, 0, w) dp[i][j] = SML; dp[0][0] = 0;
	repe(i, 1, n)
	{
		lf = rf = 1, q[lf] = dp[i - 1][w], qp[lf] = w;
		rede(j, w, 1)
		{
			while (qp[lf] > j + s - 1 && lf <= rf) ++lf;
			while (q[rf] < dp[i - 1][j - 1] && lf <= rf) --rf;
			qp[++rf] = j - 1;
			q[rf] = dp[i - 1][j - 1];
			dp[i][j] = q[lf] + j * a[i];
		}
	}
	repe(i, 0, w) ans = max(ans, dp[n][i]);
	printf("%lld", ans);
	return 0;
}
```

#### 字符dp

##### 最长前缀

> 给定若干个字符串$O$(不超过$200$个，长度不超过$10$)，以`.`终止，然后给定若干行拼接而成的字符串$s$，总长$1\le|s|\le2\times10^5$，每行不超过$67$字符；在$O$中选择多个字符串任意多次，能够拼成$s$的最长前缀长度是多少？

本题解法多样，除了DP还可以用KMP，AC自动机等。此处只讲$DP$。

本题$dp$有点像背包问题。设$dp[i]$表示是否可以拼成长为$i$的字符串，初始状态是$dp[0]=1$。之后对于每个长度，遍历$1\sim \min(i,k)$长度$j$，其中$k$是$O$中最长字符串长度；截去以$i$结尾，长为$j$的子串，如果该子串在$O$内，且$dp[i-j]$可行，那么$dp[i]$可行。使用哈希表优化。时间复杂度是$\Omicron(k|s|)$，可以通过。

```c++
#define mn 200020
bool dp[mn];
ll ans,ss,sp;
string s,t;
set<string> p;
signed main()
{
    while(1)
    {
        cin>>t;
        if(t==".") break;
        p.insert(t);
        sp=max(sp,(ll)t.size());
    }
    while(cin>>t) s+=t; ss=s.size();
    dp[0]=true;
    repe(i,1,ss)
    {
        rede(j,min(i,sp),1)
        {
            if(!dp[i-j]) continue;
            t=s.substr(i-j,j);
            if(p.count(t)) {dp[i]=true; ans=max(ans,i); break;}
        }
    }
    return cout<<ans,0;
}
```

##### 本质上升序列

> (蓝桥)求一个长为200的小写英文字符串的不同单调递增子序列数，被认为不同当且仅当两子序列存在一个字符不相等。

###### DP

设$dp[i]$表示长为$i$的前缀中，以第$i$个字符结尾的答案数，则有：
$$
dp[i]=1+\sum_{j=1}^{i-1}dp[j]\times(-1)^{s[i]=s[j]}\times(s[i]\ge s[j])
$$
其中$1$代表单独是第$i$个字符有一种方案，如果第$i$位小于之前的第$j$位，那么加上$dp[j]$，即在$dp[j]$全部答案上接上第$i$个字符都符合。如果等于第$j$位，那么重复了，减去重复数，即$dp[j]$，即让之前的答案对于这次全部作废。最后答案为：
$$
\sum_{i=1}^ndp[i]
$$
即以第$i$结尾的都积累上去。时间复杂度$\Omicron(n^2)$。

```c++
#include <iostream>
using namespace std;
int f[300];
int main(){
    string s = "tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
    int n = s.length();
    for(int i = 0; i < n; i++){
        f[i] = 1;
        for(int j = 0; j < i; j++){
            if(s[i] > s[j]) f[i] += f[j];
            else if(s[i] == s[j]) f[i] -= f[j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += f[i];
    cout<<cnt;
    return 0;
}
```

###### DFS

(个人解法)作为填空题，$n=200$，本题可以使用DFS暴力搜索，复杂度是$\Omicron(2^n)$，但是很神奇跑了出来，用时约2700秒，答案为$3616159$。暴力代码如下：

```c++
#include <bits/stdc++.h>
#define re register
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define rep(i,a,b) for(re ll i=a;i<b;++i)
using namespace std;
typedef int ll;
ll r,p;
ll n=200;
string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
char no[200];
set<string> m;
void dfs(ll h)
{
    no[p]=s[h];
    m.insert(no);
    rep(i,h+1,n)
    {
        if(s[i]>no[p])
        {
            ++p;
            dfs(i);
            no[p--]='\0';
        }
    }
}
signed main()
{
    rep(i,0,n) {p=0; dfs(i);}
    printf("%d",(int)m.size());
    return 0;
}//3616159 2700s
```

##### A5

> (scnuicpc pre-1)字符串仅含`A`和`5`，恶心当且仅当删除$0$到任意多个字符后可以成为`AAA55`，给定$T(1\le T\le 10^3)$组询问，问最少修改(`A`改成`5`或反之)多少次后不恶心。字符串长度为$1\le|s|\le100$。

###### 贪心

注：错误的贪心是在左数第三个`A`到右数第二个`5`之间统计`A,5`输出最小的数量。反例如下：`A5AA55AAA555555AAA55AA5A`，用该方法答案是`7`，而改前`4`个`A`和后`2`个`5`的解法答案是`6`，是更优解。

正确的贪心策略是：枚举中点，从中往左改到只剩`1`个`5`和从左到中改到只剩`2`个`A`的操作和。时间复杂度是$\Omicron(nT)$。

> 正确性有待证明

代码如下：

```c++
t=read();
while(t--)
{
    scanf("%s",&s);
    ss=strlen(s);
    na[0]=s[0]=='A'; c1=ss; c2=n5=0;
    rep(i,1,ss) na[i]=na[i-1]+(s[i]=='A');
    rede(i,ss-1,0)
    {
        n5+=(s[i]=='5');
        if(n5==2)
        {
            if(i>=1&&na[i-1]>=3)
            {
                c1=min(c1,na[i-1]-2+c2);
                ++c2; n5=1;
            }else break;
        }
    }
    printf("%lld\n",min(c1,c2));
}
```



#### 枚举dp

> 以下都是例题

##### 线段

> $n\times n$平面每一行有一条线段$(i,l_i),(i,r_i)$，从$(1,1)$触发，要求经过所有线段且终点为$(n,n)$，每次只能向下左右方向走一步，求最短路
>
> $n\le2\times10^4,1\le l\le r\le n$

设$dp[i][0]$代表走完第$i$行，停在左边，$dp[i][1]$右边。则初始状态、转移方程和最终要求的表达式都很容易得知。

```c++
ll dp[2][2],n,l[2],r[2],j=1,k=0;
signed main()
{
    n=read();l[j]=read(),r[j]=read();
    dp[j][0]=2*r[j]-l[j]-1,dp[j][1]=r[j]-1;
    repe(i,2,n)
    {
        j^=1; k^=1; l[j]=read(); r[j]=read();
        dp[j][0]=min(dp[k][0]+abs(r[j]-l[k]),dp[k][1]+abs(r[j]-r[k]))+r[j]-l[j]+1;
        dp[j][1]=min(dp[k][0]+abs(l[j]-l[k]),dp[k][1]+abs(l[j]-r[k]))+r[j]-l[j]+1;
    } j=n&1;
    printf("%lld",min(dp[j][0]+abs(n-l[j]),dp[j][1]+abs(n-r[j])));
    return 0;
}
```

##### 过河

> (oj)现有 n个人想坐船到河对岸，只有一艘小船，一次能乘坐两人。每个人划船的速度都不尽相同，所以每个人都有一个渡河时间 $t_i$，为了保证船的平衡，当船上有两个人的时候，需要他们按照慢的那个人的速度划船。请问最少要花费多少时间，才能使所有人都过河。($n\le 10^5$)

按用时从小到大一个一个或两个两个运人，一个状态可以由上一个状态推出(未证)

所以可以是少一个人时，最快的人回去接最后一个人；或者少两个人时，最快的人回去给船最慢的两个人，然后次快的人回去接最快的人。

```c++
#define mn 100010
ll n, t[mn], dp[mn];
signed main()
{
    sc(n);
    repe(i, 1, n) sc(t[i]);
    sort(t + 1, 1 + t + n);
    dp[1] = t[1], dp[2] = t[2];
    repe(i, 3, n)
  dp[i] = min(dp[i - 1] + t[1] + t[i], dp[i - 2] + t[1] + t[i] + (t[2] << 1));
    return printf("%lld", dp[n]), 0;
}
```



##### 测试次数

> (蓝桥)有3台手机，手机最多在某一层就会摔烂(或不会摔烂)，有1000层，求最佳方案的最坏情况下的测试次数。

$dp[i][j]$表示还有i台手机没摔烂，还剩j层没测试。

显然$dp[1][j]$=j，因为不容忍二分，否则摔烂了就没法继续测试了。

有大于一台手机时，假设从第k层摔一台手机，如果没摔坏，那么k之前都不用测试了，如果摔坏了，那么k之后都不用测试了，并且少了一台手机。

```c++
#include <bits/stdc++.h>
using namespace std;
signed main()
{
	#define repe(i,a,b) for(int i=a;i<=b;++i)
	int dp[5][1002];//4会死的，虽然原因未知
	repe(i,1,1000) dp[1][i]=i;
	repe(i,2,3) repe(j,1,1000) 
	{
		dp[i][j]=dp[i][j-1]+1;
		repe(k,2,j) dp[i][j]=min(dp[i][j],max(dp[i][j-k],dp[i-1][k-1])+1);
	}
	printf("%d", dp[3][1000]);
	return 0;
}
```



##### 数一

> (oj)求$[0,2^b-1]$中所有$k$的倍数(含$0$)转成二进制后共出现几个$1$，答案$\bmod 10^9+9$
>
> $1\le k\le1000,1\le b\le128$

显然不能枚举。考虑DP，思路见代码：

```c++
#define mb 130
#define mn 1024
ll k, b, mod = 1e9 + 9;
ll dp[mb][mn]; //dp[i][j]: [0,2^i-1]整数的模j等价类内 1 的数目
ll x[mb][mn];  //x[i][j]: [0,2^i-1]整数的模j等价类的长度

signed main()
{
    sc(k), sc(b);
    x[0][0] = 1; //0肯定是[0,0]内模0等价类的一个数
    for (ll i = 1, n2 = 1 % k; i <= b; ++i, (n2 <<= 1) %= k)
    {
        for (ll j = 0; j < k; ++j)
        {
            //第i位选0
            //将子集[0,2^(i-1)-1]原样纳入
            (x[i][j] += x[i - 1][j]) %= mod;
            (dp[i][j] += dp[i - 1][j]) %= mod;

            //第i位选1
            //将子集[0,2^(i-1)-1]等价类的每个数加前导1,
            //由于本身它们均模k余j，所以加了之后整体迁移到新的等价类
            (x[i][(j + n2) % k] += x[i - 1][j]) %= mod;
            //第i位选了1，那么等价类长度是多少，就选了多少个1，所以+x[i-1][j]
            (dp[i][(j + n2) % k] += dp[i - 1][j] + x[i - 1][j]) %= mod;
        }
    }
    printf("%lld", dp[b][0]);
    return 0;
}
```





##### 约瑟夫问题

> > 约瑟夫是犹太军队的一个将军，在反抗罗马的起义中，他所率领的军队被击溃，只剩下残余的部队40余人，他们都是宁死不屈的人，所以不愿投降做叛徒。一群人表决说要死，所以用一种策略来先后kill所有人。
> > 于是约瑟夫建议：每次由其他两人一起kill一个人，而被kill的人的先后顺序是由抽签决定的，约瑟夫有预谋地抽到了最后一签，在kill了除了他和剩余那个人之外的最后一人，他劝服了另外一个没死的人投降了罗马。
>
> 按照如下规则去排除人：
>
> - 所有人围成一圈
> - 顺时针报数，每次报到q的人将被排除掉
> - 被排除掉的人将从房间内被移走
> - 然后从被kill掉的下一个人重新报数，继续报q，再清除，直到剩余一人
>
> 你要做的是：当你在这一群人之间时，你必须选择一个位置以使得你变成那剩余的最后一人，也就是活下来。
>
> (蓝桥)设$1\le n,q\le 10^6$，求最后者编号

当$n,q$比较小时，直接模拟即可，此处略。另外，若$q=2$，可以特判快速求解，当$n=2^k$时，显然答案$J=1$。否则，答案为$J(2^k+t)=2t+1$，因为当做掉$t$人后，变成了一个$2^k$环，在这个$2^k$环上，最后活下来的是环的第一个人，即第$2t+1$个人。

应用这样的思维，将$q$拓展到一般情况：

为了方便起见，计数从$0$开始。且认为环有序。

假设原本的$n,q$约瑟夫环$J_{n,q}$是：
$$
0,1,\cdots,n-2,n-1
$$
干掉了$q-1$，然后将$q$设置为新的$n-1,q$子约瑟夫环的第一人，这个环在原本情况下的编号为：
$$
(q,q+1,\cdots,q-3,q-2) \mod n
$$
模$n$后取正，是因为原本不存在超过$n-1$的人，重新编号，得到一个子问题$J_{n-1,q}$：
$$
0,1,\cdots,n-3,n-2
$$
新旧编号之间存在一一对应，设新编号为$f_{n-1}$，旧编号为$f_n$：
$$
f_n=(f_{n-1}+q)\mod n
$$
一直往下，直到初始状态$J_{1,q}$，显然只有一个人最后一个人就是自己，即：
$$
J_{1,q}=1
$$
这里的最后一个人，一定是之前问题的同解，即这个人在编号不变的前提下一定是原问题的最后一个人。所以一直使用编号变换，即可得到这个人最开始的编号，即问题的答案：
$$
J_{n,q}=(J_{n-1,q}+q)\mod n
$$
如果把计数重新转回从$1$开始，那么输出$J_{n,q}+1$即可。时间复杂度$\Omicron(n)$。

```python
n,q=[int(i) for i in input().strip().split()]
r=0
for i in range(1,n+1):
    r=(r+q)%i
print(r+1)
```

###### 约瑟夫

> *n* 个人站成一圈，从某个人开始数数，每次数到 m 的人就被杀掉，然后下一个人重新开始数，直到最后只剩一个人。现在有一圈人，k个好人站在一起，k个坏人站在一起。从第一个好人开始数数。你要确定一个最小的 m，使得在第一个好人被杀死前，k个坏人先被杀死。$0< k<14$

个人暴力刚好勉强通过时间限制：

```c++
#define mn 40
ll n,m,k,no,dy[mn],ok,mm,lf;
void count()
{
    ll suc=0;
    mm=m%lf;//剪枝优化
    while(suc<=mm)
    {
        ++no;
        no%=n;
        if(dy[no]) continue;
        ++suc;
    }
}
signed main()
{
    k=read(); n=k<<1;
    for(m=1,ok=true;;++m)
    {
        memset(dy,0,sizeof dy);
        no=-1; ok=true; lf=n;
        while(1)
        {
            count();
            if(no<k)
            {
                ok=false;
                break;
            }
            ll suc=0;
            dy[no]=true; --lf;
            for(ll i=k;i<n;++i)
            {
                if(!dy[i]) break;
                ++suc;
            }
            if(suc==k) break;
        }
        if(ok) break;
    }
    return printf("%lld",m+1),0;
}
```

事实上这个模拟可以优化如下：

```c++
#include <stdio.h>
int main()
{
    int k,i,flag=1,m=k;
    while (flag)
    {
        m++;//m至少为k+1
        int cursor=0;//设置光标的移动
        for (i=0; i<k; i++)
        {
            cursor=(cursor+m-1)%(2*k-i);//下一次出列之人的编号，暂未搞懂实际逻辑，疑似找规律公式？且对一般约瑟夫貌似不成立
            if (cursor<k)break;//判断出列的那个人是否小于k，小于就进行下一个m的判断
            if (i==k-1)flag=0;//说明已经找到最小的m
        }
    }
    printf("%d\n",m);
    return 0;
}
```

###### 慈善的约瑟夫

> 你一定听说过约瑟夫问题吧？即从N个人中找出唯一的幸存者。现在老约瑟夫将组织一个皆大欢喜的新游戏，假设N个人站成一圈，从第1人开始交替的去掉游戏者，但只是暂时去掉，直到最后剩下唯一的幸存者为止。幸存者选出后，所有比幸存者号码高的人每人得到1个金币，永久性离开。其余剩下的将重复以上的游戏过程，比幸存者号码主的人每人得到1个金币后离开。经过这们的过程后，一旦人数不再减少，则最后剩下的那些人将得到2个金币。请你计算一下老约瑟夫一共要付出多少钱？$(1\le n\le10^5)$

个人解法：直接利用约瑟夫$p=2$规律求解。

```c++
ll n2[mn],n,c,bf,m;
signed main()
{
    n=read();
    n2[0]=1; repe(i,1,20) n2[i]=2*n2[i-1];
    while(1)
    {
        bf=n;
        m=n2[lower_bound(n2,n2+20,n)-n2-1];
        n=2*(n-m)+1;
        if(n==bf)
        {
            c+=2*n;
            break;
        }
        c+=(bf-n);
    }
    return printf("%lld",c),0;
}
```

更优解：

根据$p=2$约瑟夫的通式，可以发现具有一定的伪周期性：
$$
j_{n,2}=1,1,3,1,3,5,7\cdots
$$
并且对通式，发现在位上有：

```c++
n  =         (1      b[m-1] b[m-2]…… b[2] b[1] b[0])2 这个2只是
表示二进制

2^m=         (1      0      0     …… 0    0    0   )2 这里有m个
0

n-2^m=L=     (0      b[m-1] b[m-2]…… b[2] b[1] b[0])2

L*2=         (b[m-1] b[m-2] b[m-3]…… b[1] b[0] 0   )2

L*2+1=j(n)=  (b[m-1] b[m-2] b[m-3]…… b[1] b[0] 1   )2
```

位上结果是n的二进制将最高位去掉$(-2^m)$再左移一位（乘以二）再加一

每次增加的一块钱数：

$n-j_n=n-[(n−2^m)\times2+1]$

原式即不断求约瑟夫，直到新解跟原解相同，而这个条件等价于解为$2^k-1$，

$2^k-1$二进制的1的个数为n的二进制等于1个数

所以可以发现最后得到的结果一定是：

*n*+((把n的二进制的所有0去掉)再变成十进制)$\times$2  

> 没有弄懂这条公式，一个部分都没看懂

(即先给n个人每人一块钱，再给最后剩下的ans个人每人一块钱)

有一个名叫

```cpp
__builtin_popcount()
```

的函数是用来数一个数的二进制有多少个1

把1左移_builtin_popcount(n)为得到的是一个数，二进制是1后面有 _builtin_popcount(n)个0

这个数减一后的二进制就是__builtin_popcount(n)个1

```c++
#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   cout<<n+(1<<__buitin__popcount(n)-1);
   return 0;
}
```



###### 约瑟夫问题

> (oj)$n$人围一圈，按$1,2,1,2,\cdots$报数，数到$1$离队，留下的人继续，直到所有人出队，有$q$次询问，求每次第$x$个人第几个出队
>
> $1\le n\le10^{16},1\le q\le5\times10^5,1\le x\le n$

(个人解法：本题解法并不是dp而是找规律)

发现每次选完一轮(即到尾部)都会筛掉$\lceil\frac n2\rceil$的人，且如果是奇数那么<u>下一次从第二个人开始，否则从第一个人开始</u>(否则就是非常简单的整除和二进制位问题)，然后重新上述过程，所以实际上可以进行递归，每次将规模减少一半，所以时间复杂度是$\Omicron(q\log n)\approx 10^8$可以通过。

设人的编号从$0$到$n-1$，$j(x,n)$代表编号是$x$的人在$n$人队中的出列序号，初始状态是：
$$
j(0,1)=1
$$
转移状态：
$$
j(x,n)=\begin{cases}
\lceil\frac n2\rceil+j(x-(n\mod 1))\mod \lfloor\frac n2\rfloor,\lfloor\frac n2\rfloor)&,n\mod 2=1\\
1+\lceil\frac x2\rceil&,x\mod2=0
\end{cases}
$$
代码如下：

```c++
ll j(ll x, ll n)
{
    if(n==1) return 1;
    if(x&1) return ((n+1)>>1)+j(((x>>1)-(n&1)+(n>>1))%(n>>1),n>>1);
    return (x+2)>>1;
}
signed main()
{
    re ll n,q,x,y,r,b;
    n=read();q=read();
    while(q--) printf("%lld\n",j(read()-1,n));
	return 0;
}
```



#### 数位dp

##### 例题

###### 砝码称重

> 有ai个重为1,2,3,5,10,20的砝码(总重不超过1000)，求所有可被称量的重量(不含0)

个人朴素写法：(背包式)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
//#define MAXN 1002
const ll w[] = { 1,2,3,5,10,20 };
ll wn, mx, ans;
bool dp[2002];
signed main()
{
	dp[0] = true;
	rep(i, 0, 6)
	{
		scanf("%d", &wn);
		rep(j, 0, wn)
		{
			rede(k, mx, 0) if (dp[k])
			{
				dp[k + w[i]] = true;
				mx = max(mx, k + w[i]);
			}
		}
	}
	repe(i, 1, mx) if (dp[i]) ++ans;
	printf("Total=%d", ans);
	return 0;
}
```

bitset解法：

```c++
#include <bitset>
#include <cstdio>
int a[10], w[10] = {1, 2, 3, 5, 10, 20};
std::bitset<1010> S;
int main() {
    for(int i = 0; i < 6; i++) scanf("%d", a + i);
    S[0] = 1;
    for(int i = 0; i < 6; i++) for(int j = 0; j < a[i]; j++) S |= S << w[i];
    printf("Total=%d\n", S.count() - 1);
    return 0;
}
```

###### 砝码称重2

> 有n个砝码，重量为ai，问去掉m个后，最多能称多少种不同的质量(包括0)

bitset解法：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 22
ll tab[] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };
ll n, m, ans, v[MAXN], n2;
inline ll popcount(ll x)
{
	ll ret = 0;
	rep(i, 0, 8) ret += tab[x & 15], x >>= 4;
	return ret;
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", &v[i]);
	n2 = 1 << n;
	rep(i, 0, n2) 
	{
		if (popcount(i) + m == n)
		{
			bitset<2002> s;
			s[0] = 1;//如果j的砝码都在i的砝码里
			rep(j, 0, n) if (i & (1 << j)) s |= s << v[j];
			ans = max(ans, (ll)s.count());
		}
	}
	printf("%d", --ans);
	return 0;
}
```

dfs剪枝+dp解法：

```c++
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=22;
const int maxm=2010;
int n,m,a[maxn],ans,tot,ret;
bool tf[maxn],f[maxm];
void dp()//不传参，全部定义在全局变量中
{
    memset(f,0,sizeof f);f[0]=true;ans=0;tot=0;//清零，因为可能要调用多次
    for(int i=0;i<n;i++)//从前到后选取所有的砝码
    {
        if(tf[i])continue;//如果被标记为已经舍弃就跳过
        for(int j=tot;j>=0;j--)if(f[j]&&!f[j+a[i]])f[j+a[i]]=true,ans++;//否则dp并且维护ans的值
        tot+=a[i];//这个tot意为当前f[i]为真值的最大的i，极大加快了dp过程
    }
    ret=max(ans,ret);//更新最后的答案
}
void dfs(int cur,int now)//cur代表当前已经选取/放弃了多少个砝码，now代表已经放弃了多少个砝码
{
    if(now>m)return;//如果已经放弃的砝码数超过了需要放弃的砝码数，剪枝
    if(cur==n){if(now==m)dp();return;}//如果搜索完后正好符合条件，执行一次dp过程
    dfs(cur+1,now);//不放弃当前的砝码，继续向下
    tf[cur]=true;//留下足迹
    dfs(cur+1,now+1);//放弃当前砝码
    tf[cur]=false; //擦除足迹
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    dfs(0,0);
    printf("%d\n",ret);
    return 0;
}
```

###### 青蛙过河

> (oj)有n($2\le n\le10^3$)块石子升序给出，一开始在第一块，石子在一条直线上，坐标可能为$[0,2^{31}-1]$的整数，第一次只能跳1格，之后每一次可以跳上一次$k$格的$k,k-1,k+1$三种选择，只能向前，是否可以到达最后一个石子？

本题不可以使用DFS或BFS或迭代加深搜索，考虑使用dp，虽然最坏情况时间复杂度是$\Omicron(n^3)$，但是仍然可以过题，相比之下，搜索的最坏时间/空间复杂度是指数的。

使用dp的状态方程显而易见。

```c++
ll n,s[1010];
unordered_set<ll> dp[1010];
signed main()
{
    n=read();
    repe(i,1,n) s[i]=read();
    dp[1].insert(0);
    repe(i,1,n)
    {
        for(auto k=dp[i].begin();k!=dp[i].end();++k)
        {
            repe(j,i+1,n)
            {
                if(s[j]>=s[i]+*k-1)
                {
                    if(s[j]>s[i]+*k+1) break;
                    dp[j].insert(s[j]-s[i]);
                }
            }
        }
    }
    if(dp[n].size()) printf("true");
    else printf("false");
    return 0;
}
```



###### 邦邦的大合唱站队

> n个人来自m个组织，现调整队列里x人顺序，使所有同组织的人相邻，求最小的x

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 1048580
#define N 22
ll n, m, x, dp[MAXN], s[MAXN][N], num[N], sm[MAXN];
inline bool d(ll s, ll x) { return s & (1 << (x - 1)); }
void dfs(ll x, ll s, bool b)
{
	if (x == m) return;
	if (b) sm[s | (1 << x)] = sm[s] + num[x + 1],
		dfs(x + 1, s | (1 << x), 1), dfs(x + 1, s | (1 << x), 0);
	else dfs(x + 1, s, 1), dfs(x + 1, s, 0);
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n)
	{
		scanf("%d", &x);
		repe(j, 1, m) s[i][j] = s[i - 1][j];
		++s[i][x], ++num[x];
	}
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	repe(i, 1, (1 << m)) repe(j, 1, m) if (d(i, j))
	{
		ll lf = sm[i ^ (1 << j - 1)], rf = sm[i];
		dp[i] = min(dp[i],
			dp[i ^ (1 << (j - 1))] + rf - lf - s[rf][j] + s[lf][j]);
	}
	printf("%d", dp[(1 << m) - 1]);
	return 0;
}
```

###### No Change G

> 有k枚硬币(币值各异)，n个商品，按顺序购买商品，一次可以用一枚硬币结账一到多个商品，不会找零。求最大余额。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
#define N 65538
ll n, m, totny, ans = 0x7ffffffa, x, s;
ll dp[N], ny[N], sum[MAXN], p, coin[17];
inline ll ck(ll x, ll c)
{
	ll lf = c, rf = n, cf;
	while (lf <= rf)
	{
		cf = lf + rf >> 1;
		if (sum[cf] - sum[c - 1] == x) return cf;
		if (sum[cf] - sum[c - 1] < x) lf = cf + 1;
		else rf = cf - 1;
	}
	return rf;
}
signed main()
{
	scanf("%d%d", &m, &n);
	repe(i, 1, m) scanf("%d", &coin[i]), totny += coin[i];
	repe(i, 1, n) scanf("%d", &p), sum[i] = sum[i - 1] + p;
	rep(i, 1, 1 << m) rep(j, 0, m) if (i & (1 << j))
	{
		x = i ^ (1 << j); s = ck(coin[j + 1], dp[x] + 1);
		if (s > dp[i]) dp[i] = s, ny[i] = ny[x] + coin[j + 1];
		if (dp[i] == n) ans = min(ans, ny[i]);
	}
	ans = totny - ans;
	printf("%d", ans < 0 ? -1 : ans);
	return 0;
}
```

###### 对局匹配

> 有n人，当且仅当两人分差为k会被匹配，求至多有多少人一同匹配时，没有一个人会被匹配？

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 100002
int n,a[mn],ans,k,t,mi=0x7ffffffa,mx;
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		++a[t];
		mi=min(mi,t);
		mx=max(mx,t);
	}
	if(n==1) return printf("1")&0;//特判
	if(!k)
	{
		for(int i=mi;i<=mx;++i)
			ans+=a[i]>0;
		return printf("%d",ans)&0;//特判
	}
	for(int h=0;h<k;++h)//这个目标等差数列的首项
	{
		int dp[mn],i;
		dp[mi+h]=a[mi+h];
		dp[mi+h+k]=a[mi+h+k];
		for(i=mi+h+(k<<1);i<=mx;i+=k)//位运算优先级死人
			dp[i]=max(dp[i-k],dp[i-(k<<1)]+a[i]);
		ans+=dp[i-k];//减去末尾多加的k
	}
	printf("%d",ans);
	return 0;
}
```

###### 包子凑数

> (蓝桥)有$n(n\le100)$种包笼，内有$a(a\le100)$个包子，这些包笼随意组合可以凑出若干个包子，求有多少种数目无法被凑出(无限输出INF)

如果不考虑无限，则是一道背包叠加的问题，直接开双循环即可。

考虑无限时，判定无限的方法是，设最多包子包笼包子数为$x$，最少为$y$，则从$x$开始(包含)如果连续有至少$y$种数目都可以凑出，那么一定可以凑出以后的所有数目，否则将必然存在无限种无法被凑出。

```c++
#include <bits/stdc++.h>
#define repe(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
#define mn 10000
bool dp[mn+102],ninf;
int n,a[102],cnt,ans;
signed main()
{
	scanf("%d",&n);
	repe(i,1,n) scanf("%d",a+i);
	sort(a+1,a+1+n); dp[0]=1;
	repe(i,1,n) repe(j,0,mn) if(dp[j]) dp[j+a[i]]=true;
	repe(i,a[n],mn)
	{
		if(dp[i]) ++cnt;
		else cnt=0;
		if(cnt==a[1]) {ninf=true; break;}
	}
	if(!ninf) return printf("INF")&0;
	repe(i,1,mn) if(!dp[i]) ++ans;
	printf("%d",ans);
	return 0;
}
```

判重方法2：当所有数的最大公因数为1时，不为inf。

###### 地宫寻宝

> (蓝桥)有$n\times m$地宫，每件宝物有一个价值$c$，从左上开始，只能往右或下走，每次经过的格子的宝物若比自己手里所有宝物都大，则可以拿走；求走到出口时拿了$k$件宝物的方案数。结果对1000000007取模。
>
> $1\le n,m\le50,1\le k\le12,0\le c\le12$

(个人)解法一：设$dp[i][j][h][g]$表示经过格子$(i,j)$，手里最大价格为$h$，已经拿了$g$个宝物，使用刷表法递推，每次不拿，往下和右递推：
$$
dp([i+1][j]或[i][j+1])[h][g]+=dp[i][j][h][g]
$$
如果大于，可以拿，此时递推：
$$
dp([i+1][j]或[i][j+1])[new][g]+=dp[i][j][h][g]
$$
**特别注意：必须设一开始手头价值为-1或把所有宝物价值自增1，否则无法拿取价值为0的宝物(因为手头没东西时如果设价值为0，显然不大于手头价值)！**

时间和空间复杂度$\Omicron(nmk^2)$，由于$n,m,k$小，可以通过。

解法二：记忆化搜索，该方法更加简单，故略。

##### 进制状压

> (上面例题中也有部分是进制型的 da sort)

###### 糖果

> (蓝桥)有m种口味的糖果，卖n包糖果，每包有k颗不同(或同)口味的糖果，求最少买多少包可以尝到所有口味。$1\le n\le100,1\le m,k\le20,1\le k_i\le m$。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mpow 1<<20
#define mn 102
int sug[mn],dp[mpow],n,m,k,tot;
signed main()
{
    scanf("%d%d%d",&n,&m,&k); tot=(1<<m)-1;
    memset(dp,-1,sizeof dp);
    for(int i=0,st=0,v;i<n;++i,st=0)
    {
        for(int j=1;j<=k;++j)
        {
            scanf("%d",&v);
            st|=(1<<v-1);
        }
        dp[st]=1;
        sug[i]=st;
    }
    for(int i=0;i<=tot;++i) if(dp[i]!=-1)
    {
        for(int j=0,k;j<n;++j)
        {
            k=i|sug[j];
            if(dp[k]==-1||dp[k]>dp[i]+1) dp[k]=dp[i]+1;
        }
    }
    return printf("%d",dp[tot]),0;
}
```

###### Chino's homework

> (scnucpc2020)有$n\times m$方格，每格可以不放或放一个棋子$a$或$b$，其中单个棋子$a$基础分算$12$分，若棋子$a$的四方向上存在其他棋子，每存在一个扣$3$分；棋子$b$基础分算$4$分，若棋子$b$的四方向上存在其他棋子，每存在一个加$2$分。给定$n,m$和$q$组询问，每组询问最多可以使用$u$个棋子$a$和$v$个棋子$b$，求能够获得的最高分及其情况数。$1\le n,m\le5,q\le49,0\le u,v\le6$

设三进制状态：$0$表示该格没有棋子，$1$表示有$a$，$2$表示有$b$。预处理出每一行相对于确定的上一行能够获得多少分。以一行为一个基本元素进行动态规划。

设$dp/c[i][j][k][st]$是已经处理了前$i$行，已经用了$j,k$个棋子，第$i$行状态为$st$的分数和情况数。状态方程易知(在代码中展示)。

预处理时间复杂度为：$\Omicron(3^{m}\times3^{m}\times\log3^m)=\Omicron(m3^{2m})$

动态规划时间复杂度为$\Omicron(nm^23^{2m})$，尚未超时。

代码如下：(使用标准开头01)

```c++
#define mn 245 //3^5
#define mm 6
#define big 0x7ffffffa
ll g[mn][mn], in[mn], out[mn], n3[] = { 1,3,9,27,81,243,729 };
//in[i] how many chino in state(i), out[i] likewise
//g[i][j] 是上一行为i，下一行为j时下一行的分数
ll ofs[5] = { 4,-1,-6 }, dp[8][8][8][mn], c[8][8][8][mn];
//ofs[0] neighbor both cocas; [1]cocas x chino; [2] both chino
ll a[8][8], b[8][8], n, m, q, u, v;
signed main()
{
	n = read(), m = read(), q = read();
	rep(i, 0, n3[m])
	{
		ll x = 0, y = 0, s = 0, st = i;
		do 
		{
			y = st % 3;
			if (y == 1) ++in[i], s += 12; //chino
			else if (y == 2) ++out[i], s += 4; //cocoa
			if (x && y) //neighbor in row
				s += ofs[(x == 1) + (y == 1)];
			x = y; //last y
			st /= 3;
		} while (st);
		rep(pre, 0, n3[m])//upper line, likewise
		{
			g[pre][i] += s;
			for (ll st1 = i, st2 = pre, j = 0; j < m; ++j, st1 /= 3, st2 /= 3)
			{
				x = st1 % 3, y = st2 % 3;
				if (x && y) g[pre][i] += ofs[(x == 1) + (y == 1)];
			}
		}
	}
	//rep(i, 0, 8) rep(j, 0, 8) rep(k, 0, 8) rep(h, 0, mn)
	//	dp[i][j][k][h] = -1; //+1类问题；且这个负值必须大于max(g[i][j])
	memset(dp, 0xbf, sizeof dp);//事实表明该函数比循环赋值快
	dp[0][0][0][0] = 0, c[0][0][0][0] = 1;
	repe(i, 1, n)
		repe(u, 0, mm)//注意到mm不是到m；开到mm的原因是u,v不一定小于n,m
			repe(v, 0, mm)
				rep(now, 0, n3[m])
				{
					if (in[now] > u || out[now] > v) continue;
					ll x = u - in[now], y = v - out[now];
					//在这一行之前，chino和cocoa放了x和y棋子
					rep(pre, 0, n3[m])
					{
						if (dp[i - 1][x][y][pre] < 0) continue;
						if (dp[i][u][v][now] < dp[i - 1][x][y][pre] + g[pre][now])//有更优解
							dp[i][u][v][now] = dp[i - 1][x][y][pre] + g[pre][now], c[i][u][v][now] = c[i - 1][x][y][pre];
						else if (dp[i][u][v][now] == dp[i - 1][x][y][pre] + g[pre][now])//最优解积累
							c[i][u][v][now] += c[i - 1][x][y][pre];
					}
				}
	repe(i, 0, mm)
		repe(j, 0, mm)
			rep(k, 0, n3[m])//求放棋为i,j时的最优解及其解法数
				if (dp[n][i][j][k] > a[i][j])
					a[i][j] = dp[n][i][j][k], b[i][j] = c[n][i][j][k];
				else if (dp[n][i][j][k] == a[i][j])
					b[i][j] += c[n][i][j][k];
	while (q--)
	{
		u = read(), v = read();
		ll mx = 0, s = 0;
		repe(i, 0, u)
			repe(j, 0, v)//求在放棋数范围为[0,u],[0,v]下最优解及其个数
				if (a[i][j] > mx) mx = a[i][j], s = b[i][j];
				else if (a[i][j] == mx) s += b[i][j];
		printf("%d %d\n", mx, s);
	}
	return 0;
}
```



#### 区间dp

##### 例题

###### 合并石子

以合并石子为例(a,b)合并获得值a+b，若干石子(数大于等于0)的最大最小值求法如下：

```c++
#include <bits/stdc++.h>
#define MAXN 203
const int BIG = 0x7fffffff;
using namespace std;
int mi, mx, n, dpmi[MAXN][MAXN], dpmx[MAXN][MAXN], s[MAXN], a[MAXN], kd;
inline int d(int i, int j)
{
	return s[j] - s[i - 1];
}
signed main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i < n + n; ++i)
	{
		s[i] = s[i - 1] + a[i];
	}
	for (int h = 1; h < n; ++h)
	{
		for (int i = 1, j = i + h; i < n + n && j < n + n; i++, j = i + h)
		{
			dpmi[i][j] = BIG;
			kd = d(i, j);
			for (int k = i; k < j; ++k)
			{
				dpmi[i][j] = min(dpmi[i][j], dpmi[i][k] + dpmi[k + 1][j] + kd);
				dpmx[i][j] = max(dpmx[i][j], dpmx[i][k] + dpmx[k + 1][j] + kd);
			}
		}
	}
	mi = BIG;
	for (int i = 1; i <= n; ++i)
	{
		mx = max(mx, dpmx[i][i + n - 1]);
		mi = min(mi, dpmi[i][i + n - 1]);
	}
	printf("%d\n%d", mi, mx);
	return 0;
}
```

###### 项链

> 项链有N颗能珠。能量珠是一颗有头标记与尾标记的珠子，这些标记对应着某个正整数。并且，对于相邻的两颗珠子，前一颗珠子的尾标记一定等于后一颗珠子的头标记。因为只有这样，通过吸盘的作用，这两颗珠子才能聚合成一颗珠子，同时释放出可以被吸盘吸收的能量。如果前一颗能量珠的头标记为m，尾标记为r，后一颗能量珠的头标记为r，尾标记为n，则聚合后释放的能量为m×r×n，新产生的珠子的头标记为m，尾标记为n。给出n和各个标记，求最大能量。

```c++
#include <bits/stdc++.h>
#define MAXN 205
#define pr pair<int, int>
using namespace std;
int n, e, a[MAXN][MAXN], b[MAXN], ans;//a为[i,j]内答案
signed main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
		b[i + n] = b[i];
	}
	for (int i = 2; i <= n + 1; ++i)//区间长
	{
		for (int lf = 1, rf = lf + i - 1; rf <= n + n; ++lf, ++rf)
		{
			for (int k = lf + 1; k <= rf - 1; ++k)
			{
				a[lf][rf] = max(a[lf][rf], a[lf][k] + a[k][rf] + b[lf] * b[k] * b[rf]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, a[i][i + n]);
	printf("%d", ans);
	return 0;
}
```

###### 尼克的任务

> 工作从1到n分钟，有m个任务，从第x分钟开始到x+y-1分钟结束(持续y分钟)，如果当下空闲且当下时刻出现任务，必须做其中一个出现的任务，求最大休息时间。

设dp[i]表示从i~n的最大休息时间。

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 100002
struct task
{
	int lf, rf;
} tk[MAXN];
int dp[MAXN], tki = 1, n, m, tks[MAXN];
inline bool cmp(task& a, task& b)
{
	return a.lf > b.lf;
}
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		scanf("%d%d", &tk[i].lf, &tk[i].rf);
		++tks[tk[i].lf];
	}
	sort(tk + 1, tk + 1 + m, cmp);
	for (int i = n; i >= 1; --i)
	{
		if (tks[i])
		{
			rep(j, 1, tks[i])
			{
				if (dp[i + tk[tki].rf] > dp[i])
				{
					dp[i] = dp[i + tk[tki].rf];
				}
				++tki;
			}
		}
		else dp[i] = dp[i + 1] + 1;
	}
	printf("%d", dp[1]);
	return 0;
}
```

###### 相似基因

> 给定两个单DNA链，可以在其中任意插入空碱基对(不能二者均空)，当对应位匹配时，产生相应相似度(有表)，求最大相似度。

个人解法：(dfs剪枝)

```c++
#include <bits/stdc++.h>
//#pragma warning(disable:6031)
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 202
#define NEG -0x7ffffff
ll dp[MAXN][MAXN], lenx, leny, ans = NEG, cnt;
char x[MAXN], y[MAXN], a, b;
inline ll po(char u, char v)
{
	a = min(u, v), b = max(u, v);
	//printf("[%c %c] ", a, b);
	if (!a && !b) return NEG;
	if (a == b) return 5;
	if (a == 'A' && b == 'C' || a == 'A' && b == 'T' || a == '\0' && b == 'T') return -1;
	if (a == 'A' && b == 'G' || a == 'C' && b == 'T' || a == '\0' && b == 'G' || a == 'G' && b == 'T') return -2;
	if (a == 'C' && b == 'G' || a == '\0' && b == 'A') return -3;
	if (a == '\0' && b == 'C') return -4;
}
void sea(ll xi, ll yi)
{

	if (xi > lenx || yi > leny) return;
	cnt++;//运行次数计数，可忽略
	int tra = po('\0', x[xi + 1]) + dp[xi][yi];
	int trb = po('\0', y[yi + 1]) + dp[xi][yi];
	int trc = po(x[xi + 1], y[yi + 1]) + dp[xi][yi];
	//printf("%d %d %d %d %d %d\n", xi, yi, ans,tra,trb,trc);
	if (tra > dp[xi + 1][yi] && tra!=NEG + dp[xi][yi])
	{
		if(xi+1==lenx&&yi==leny) ans = max(ans, tra);
		dp[xi + 1][yi] = tra;
		sea(xi + 1, yi);
	}
	if (trb > dp[xi][yi + 1] && trb != NEG + dp[xi][yi])
	{
		if (xi == lenx && yi+1 == leny) ans = max(ans, trb);
		dp[xi][yi + 1] = trb;
		sea(xi, yi + 1);
	}
	if (trc > dp[xi + 1][yi + 1] && trc != NEG + dp[xi][yi])
	{
		if (xi+1 == lenx && yi+1 == leny) ans = max(ans, trc);
		dp[xi + 1][yi + 1] = trc;
		sea(xi + 1, yi + 1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> lenx >> x + 1 >> leny >> y + 1;
	repe(i, 0, 200) repe(j, 0, 200) dp[i][j] = NEG;
	dp[0][0] = 0;
	sea(0, 0);
	cout << ans;
	//cout << endl << cnt;
	return 0;
}
```

答案解法：

```c++
#define N 105
#include<cstdio>
#include<string>
#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int tab[5][5]=
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int la,lb;
std::string sa,sb;
int a[N],b[N];
int dp[N][N];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin>>la>>sa>>lb>>sb;
    for(int i=1;i<=la;i++) for(int j=1;j<=lb;j++) dp[i][j]=-2e8;
    for(int i=1;i<=la;i++)
    {
        if(sa[i-1]=='A') a[i]=0;
        if(sa[i-1]=='C') a[i]=1;
        if(sa[i-1]=='G') a[i]=2;
        if(sa[i-1]=='T') a[i]=3;
    }
    for(int i=1;i<=lb;i++)
    {
        if(sb[i-1]=='A') b[i]=0;
        if(sb[i-1]=='C') b[i]=1;
        if(sb[i-1]=='G') b[i]=2;
        if(sb[i-1]=='T') b[i]=3;
    }
    for(int i=1;i<=la;i++) dp[i][0]=dp[i-1][0]+tab[a[i]][4];
    for(int i=1;i<=lb;i++) dp[0][i]=dp[0][i-1]+tab[b[i]][4];
    for(int i=1;i<=la;i++)
          for(int j=1;j<=lb;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]+tab[b[j]][4]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]+tab[a[i]][4]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+tab[a[i]][b[j]]);
        }
    printf("%d",dp[la][lb]);
    return 0;
}
```

###### 248G

> 在1xn的空间内玩2048，每次合并使得原本的数字+1(如2:2=3)，求合并产生的最大值

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 250
ll dp[MAXN][MAXN], mp[MAXN], n, ans;
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d", &mp[i]), dp[i][i] = mp[i];	rep(h, 1, n)
	{
		repe(i, 1, n - h)
		{
			ll j = i + h;
			rep(k, i, j)
			{
				if (dp[i][k] == dp[k + 1][j] && dp[i][k] && dp[k + 1][j])
				{
					dp[i][j] = dp[i][k] + 1;
					ans = max(ans, dp[i][j]);
				}
			}

		}
	}
	printf("%d", ans);
	return 0;
}
```

###### 涂色

> 有长为n的字符串，每次涂色可以给连续区间涂上大写字母颜色，求最小涂色次数获得该字符串

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 52
char s[MAXN];
ll dp[MAXN][MAXN], n;
signed main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	repe(i, 0, n) repe(j, 0, n) dp[i][j] = 0x7fffffff;
	repe(i, 1, n) dp[i][i] = 1;
	rep(h, 1, n)
	{
		for (ll i = 1, j = 1 + h; j <= n; ++i, ++j)
		{
			if (s[i] == s[j]) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			else rep(k, i, j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	printf("%d", dp[1][n]);
	return 0;
}
```

###### 关路灯

> 有n个路灯，一开始在第c个处；给出各路灯位置和能耗，求关掉所有电灯的最小能耗

定义$dp[i][j][k]$为已经关掉第$[i,j]$个路灯，正在区间$[i,j]$的左端(k=0)或右端(k=1)，转移方程容易理解，故易解。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 52
ll n, c, a[MAXN], b[MAXN], dp[MAXN][MAXN][2], v;
signed main()
{
	scanf("%d%d", &n, &c);
	memset(dp, 127, sizeof dp);
	dp[c][c][0] = dp[c][c][1] = 0;
	repe(i, 1, n) scanf("%d%d", &a[i], &v), b[i] = b[i - 1] + v;
	repe(h, 2, n) repe(i, 1, n + 1 - h)
	{
		ll j = i + h - 1;
		dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * (b[i] + b[n] - b[j]),
			dp[i + 1][j][1] + (a[j] - a[i]) * (b[i] + b[n] - b[j]));
		dp[i][j][1] = min(dp[i][j - 1][0] + (a[j] - a[i]) * (b[i - 1] + b[n] - b[j - 1]),
			dp[i][j - 1][1] + (a[j] - a[j - 1]) * (b[i - 1] + b[n] - b[j - 1]));
	}
	printf("%d", min(dp[1][n][0], dp[1][n][1]));
	return 0;
}
```

###### Polygon

> 一个有$n$顶点的多边形，每个点有一个数值，每条边是加法或乘法；边、点有序，从$1$到$n$。初始删掉其中一条边，然后不断将一条边上两点合并，合并后新点值是原来一条边运算法则作用于这两个点，求最大结果和能够取得这些结果的升序的删边集。$3\le n\le50$，保证任何操作时数字范围$\in[-32768,32767]$。

如果只有加法那么就是合并石子题目的板子；有乘法的基础上，需要考虑负负得正的问题，所以仍然需要每次存储最大和最小；预处理仍然拆环，删掉一条边即从这条边的顶点开始走$n$步长的一段二倍长链区间上的dp。

设$dp[i][j],dm[i][j]$是在仅处理区间$[i,j]$，可以得到的最大值和最小值。加法区间更新直接更新即可；乘法区间更新遍历最大最小四种情况。

```c++
#define mn 110
#define big 0x7ffffffa //取多少影响不大，开不开long long影响也不大
ll n,n2,v[mn],dp[mn][mn],dm[mn][mn],ans; char r[mn];
signed main()
{
    scanf("%lld\n",&n); n2=n<<1;
    repe(i,0,n2) repe(j,0,n2) dp[i][j]=-big,dm[i][j]=big;
    repe(i,1,n)
    {
        scanf("%c %lld",&r[i],&v[i]);getchar();
        r[i+n]=r[i],v[i+n]=v[i];
    }
    repe(i,1,n2) dp[i][i]=dm[i][i]=v[i];
    repe(h,2,n)
    {
        for(ll i=1,j=h;j<=n2;++i,++j)
        {
            rep(k,i,j)
            {
                if(r[k+1]=='t')
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    dm[i][j]=min(dm[i][j],dm[i][k]+dm[k+1][j]);
                }
                else if(r[k+1]=='x')
                {
                    dp[i][j]=max(dp[i][j],max(dp[i][k]*dp[k+1][j],max(dp[i][k]*dm[k+1][j],max(dm[i][k]*dp[k+1][j],dm[i][k]*dm[k+1][j]))));
                    dm[i][j]=min(dm[i][j],min(dp[i][k]*dp[k+1][j],min(dp[i][k]*dm[k+1][j],min(dm[i][k]*dp[k+1][j],dm[i][k]*dm[k+1][j]))));
                }
            }
        }
    }
    repe(i,1,n) ans=max(ans,dp[i][i+n-1]); printf("%lld\n",ans);
    repe(i,1,n) if(dp[i][i+n-1]==ans) printf("%lld ",i);
    return 0;
}
```



###### Zuma

> 祖玛游戏，每次可以消一个回文串，求消掉整个串的最小次数

定义$dp[i][j]$为消掉子串$[i,j]$的最小次数，显然：
$$
\begin{cases}
dp[i][i]=1\\
dp[i][i+1]=1\quad(a[i]=a[i+1])\\
dp[i][i+1]=2\quad(a[i]\ne a[i+1])
\end{cases}
$$
转移方程为：
$$
\begin{cases}
dp[i][j]=dp[i+1][j-1]\quad(a[i]=a[j])\\
dp[i][j]=\min_{k=i}^{j-1}(dp[i][k]+dp[k+1][j])
\end{cases}
$$

> 注意两个转移方程不是并列关系，不能用if-else

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 502
ll n, a[MAXN], dp[MAXN][MAXN];
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%d", &a[i]);
	repe(i, 1, n) repe(j, 1, n) dp[i][j] = 0x7ffffffa;
	repe(i, 1, n) dp[i][i] = 1;
	rep(i, 1, n) dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
	repe(h, 3, n) repe(i, 1, n + 1 - h)
	{
		ll j = i + h - 1;
		if (a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1];
		else rep(k, i, j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
	}
	printf("%d", dp[1][n]);
	return 0;
}
```

###### 矩阵取数

> 有$n\times m$矩阵，每次从每行取走行首或行尾，共取n个数，取m次，每次取数的得分是$v\times 2^i$，v为取值，i为取次，从1开始。求最大得分。

可以用最优子结构，则每次只考虑一行，每行计算dp，最后求和。

$dp[i][j]$表示经过取数后，区间变成$[i,j]$时获得的最大分数，转移方程为容易获得。注意要区间dp是从小区间往大的，所以取数时也是反着来的。

> 本题如果用C++需要开高精度或手写int128。

```python
n,m = [int(i) for i in input().strip().split()]
mat = [[int(i) for i in input().strip().split()] for j in range(n)]
dp = [[0 for i in range(m + 1)] for j in range(m + 1)]
ans = 0
for h in range(n):
    for j in range(m):#把最后一个数取走
        dp[0][j] = mat[h][j] * (1 << m)
    for i in range(1,m):
        for j in range(m - i):
            dp[i][j] = max(dp[i - 1][j] + mat[h][i + j] * (1 << (m - i)),
                         dp[i - 1][j + 1] + mat[h][j] * (1 << (m - i)))
    ans+=dp[m - 1][0]
print(ans)
```

**高精度写法**

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 85, Mod = 10000; //高精四位压缩大法好 
int n, m;
int ar[MAXN];

struct HP {
	int p[505], len;
	HP() {
		memset(p, 0, sizeof p);
		len = 0;
	} //这是构造函数，用于直接创建一个高精度变量 
	void print() {
		printf("%d", p[len]);  
        for (int i = len - 1; i > 0; i--) {  
            if (p[i] == 0) {
				printf("0000"); 
				continue;
			}
            for (int k = 10; k * p[i] < Mod; k *= 10) 
				printf("0");
            printf("%d", p[i]);
        }
	} //四位压缩的输出 
} f[MAXN][MAXN], base[MAXN], ans;

HP operator + (const HP &a, const HP &b) {
	HP c; c.len = max(a.len, b.len); int x = 0;
	for (int i = 1; i <= c.len; i++) {
		c.p[i] = a.p[i] + b.p[i] + x;
		x = c.p[i] / Mod;
		c.p[i] %= Mod;
	}
	if (x > 0)
		c.p[++c.len] = x;
	return c;
} //高精+高精 

HP operator * (const HP &a, const int &b) {
	HP c; c.len = a.len; int x = 0;
	for (int i = 1; i <= c.len; i++) {
		c.p[i] = a.p[i] * b + x;
		x = c.p[i] / Mod;
		c.p[i] %= Mod;
	}
	while (x > 0)
		c.p[++c.len] = x % Mod, x /= Mod;
	return c;
} //高精*单精 

HP max(const HP &a, const HP &b) {
	if (a.len > b.len)
		return a;
	else if (a.len < b.len)
		return b;
	for (int i = a.len; i > 0; i--)
		if (a.p[i] > b.p[i])
			return a;
		else if (a.p[i] < b.p[i])
			return b;
	return a;
} //比较取最大值 

void BaseTwo() {
	base[0].p[1] = 1, base[0].len = 1;
	for (int i = 1; i <= m + 2; i++){ //这里是m! m! m! 我TM写成n调了n年... 
		base[i] = base[i - 1] * 2;
	}
} //预处理出2的幂 

int main(void) {
	scanf("%d%d", &n, &m);
	BaseTwo();
	while (n--) {
		memset(f, 0, sizeof f);
		for (int i = 1; i <= m; i++)
			scanf("%d", &ar[i]);
		for (int i = 1; i <= m; i++)
			for (int j = m; j >= i; j--) { //因为终值是小区间，DP自然就从大区间开始 
				f[i][j] = max(f[i][j], f[i - 1][j] + base[m - j + i - 1] * ar[i - 1]); 
				f[i][j] = max(f[i][j], f[i][j + 1] + base[m - j + i - 1] * ar[j + 1]);
			} //用结构体重载运算符写起来比较自然 
		HP Max;
		for (int i = 1; i <= m; i++)
			Max = max(Max, f[i][i] + base[m] * ar[i]);
		ans = ans + Max; //记录到总答案中 
	}
	ans.print(); //输出 
	return 0;
}
```

**128int**

设A为128位整数，AH为高64位，AL为低64位，则：

```
A/n=((AH/n)<<64)|((((AH%n)<<64)+AL)/n)
A%n=(((AH%n)<<64)+AL)%n
```

也就是说，商的高位为AH/n，低位就是AH%n与AL组合成的128位整数除以n的商（余数就是A%n了），这个商肯定不会爆64位。

其余的涉及到的运算如下：

若b为int，则：

```
A\*b=(AH\*b)<<64+(AL\*b)
```

若B为128位，则：

```
A+B=(AH+BH)<<64+(AL+BL)
```

使用以上两个公式的时候要注意进位问题。

于是，有了128位运算，

```c++
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
//从这里到100行都是int128的运算代码
typedef struct _tword{
	unsigned long long rah;//高64位
	unsigned long long ral;//低64位
	friend bool operator <(const _tword &a,const _tword &b){
		if(a.rah<b.rah)return(1);
		if(a.rah>b.rah)return(0);
		return(a.ral<b.ral);
	}
}tword;//这个结构体就是128位整数了
unsigned long long hbt=1;
unsigned long long man32;//0~31位全1
unsigned long long man32h;//32~63位全1
void add(tword a,tword b,tword &res){
	unsigned long long al=a.ral&man32;
	unsigned long long ah=(a.ral&man32h)>>32;
	unsigned long long bl=b.ral&man32;
	unsigned long long bh=(b.ral&man32h)>>32;
	//因为这里需要处理进位，所以我们要把128位拆成4个32位并把它们扩充至64位，这样就能通过对结果的高32位的处理来加上进位
	al+=bl;
	ah=ah+bh+((al&man32h)>>32);
	res.rah=a.rah+b.rah+((ah&man32h)>>32);
	res.ral=((ah&man32)<<32)|(al&man32);
}//128位加法
void kuomul(unsigned long long a,unsigned long long b,tword &res){//计算64位×64位=128位
	unsigned long long al=a&man32;
	unsigned long long ah=(a&man32h)>>32;
	unsigned long long bl=b&man32;
	unsigned long long bh=(b&man32h)>>32;
	//ah、al为a的高低32位，bh、bl为b的高低32位，则a*b=(ah*bh)<<32+(ah<<32)*bl+(bh<<32)*al+al*bl
	unsigned long long albl=al*bl;
	unsigned long long ahbh=ah*bh;
	unsigned long long albh=al*bh;
	unsigned long long ahbl=ah*bl;
	tword r1,r2,r3,r4;
	r1.rah=ahbh;
	r1.ral=0;
	r2.rah=0;
	r2.ral=albl;
	r3.ral=(albh&man32)<<32;
	r3.rah=(albh&man32h)>>32;
	r4.ral=(ahbl&man32)<<32;
	r4.rah=(ahbl&man32h)>>32;
	res.rah=0;
	res.ral=0;
	add(res,r1,res);
	add(res,r2,res);
	add(res,r3,res);
	add(res,r4,res);//把四项相加，得出结果
}
void mul(tword a,int b,tword &res){//128乘int的运算
	tword tmp;
	unsigned long long ah=a.rah*b;
	kuomul(a.ral,b,tmp);
	unsigned long long al=tmp.ral;
	res.rah=ah+tmp.rah;
	res.ral=al;
}
int mod10(tword &hint){//把128位hint除以10，并返回余数
	unsigned long long eah=hint.rah / 10;
	unsigned long long mod=((hint.rah%10)<<32)|((hint.ral&man32h)>>32);
	unsigned long long low=hint.ral&man32;
	hint.rah=eah;
	unsigned long long eal=(mod/10)<<32;
	low=low|((mod%10)<<32);
	eal=eal|(low/10);
	hint.ral=eal;
	return(low%10);
}
stack<char> ss;//字符栈
void print(tword hint){//输出128位整数
	if(hint.rah==0&&hint.ral==0){
		printf("0");//为0直接输出0
	}
	else{
		while(hint.rah!=0||hint.ral!=0){
			ss.push(mod10(hint)+'0');
		}
		while(!ss.empty()){
			putchar(ss.top());
			ss.pop();
		}
	}
}
int v[81];//矩阵的一行
int line;
unsigned char bv[81][81];
tword f[81][81];
int m;
void dp(int l,int r,tword &res){//记搜
	if(bv[l][r]){res=f[l][r];return;}
	//注意这里一旦找到就赶紧return，一般的记搜都是带返回值的，我因为要传递结构体就没带返回值，开始的时候忘了加return然后就一直出错
	bv[l][r]=1;
	tword resx;
	resx.rah=0;
	resx.ral=0;
	int bit=m-(r-l);
	unsigned long long bt=1;
	if(bit<64){
		bt=bt<<bit;
		resx.ral=resx.ral|bt;
	}
	else{
		bt=bt<<(bit-64);
		resx.rah=resx.rah|bt;
	}//resx即为2^i，直接按位就行了
	if(l==r){//区间内只有一个数
		mul(resx,v[l],resx);
		f[l][r]=resx;
		res=resx;
	}
	else{
		tword left;
		dp(l+1,r,left);
		tword lefta=resx;
		mul(lefta,v[l],lefta);
		add(left,lefta,left);
		tword right;
		dp(l,r-1,right);
		tword righta=resx;
		mul(righta,v[r],righta);
		add(right,righta,right);
		//left为取左边能获得的最大值，right为取右边能获得的最大值，最后在他们中间取个最大的
		if(left<right){
			f[l][r]=right;
			res=right;
		}
		else{
			f[l][r]=left;
			res=left;
		}
	}
}
inline int get(){//读入优化
	char c;
	int n;
	while(1){
		c=getchar();
		if(c>='0'&&c<='9')break;
	}
	n=c-'0';
	while(1){
		c=getchar();
		if(c>='0'&&c<='9'){
			n=n*10+c-'0';
		}
		else{
			return(n);
		}
	}
}
int main(){
	man32=0xffffffff;
	man32h=0xffffffff00000000;
	int height,width;
	cin>>height>>width;
	m=width;
	tword sum;
	sum.rah=0;
	sum.ral=0;
	for(register int i=1;i<=height;i++){
		memset(bv,0,sizeof(bv));
		for(register int j=1;j<=width;j++){
			v[j]=get();
		}
		tword tmp;
		dp(1,width,tmp);
		add(sum,tmp,sum);//把各行的最大得分依次相加
	}
	print(sum);//输出
	return(0);
}
```

###### 图形排版

> (蓝桥)纸宽度为m，有n张图片，给出长宽，一直排版，如果宽度小，那么压缩，高度上取整，如果没宽度了，往下一行。现删除一张图片，求最小总高度。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> po;
#define mn 100002
#define big 0x7ffffffa
#define st first
#define nd second
po a[mn],tp,no;
int dp[mn],n,m,pre,res=big;//dp[i]是从i~n所需总高度 
inline void add(po& p, int k)//行p加入第k张图片 
{
	if(p.st+a[k].st<m)
		p.st+=a[k].st,p.nd=max(p.nd,a[k].nd);
	else
		p.nd=max(p.nd, (a[k].nd*(m-p.st)-1)/a[k].st+1),p.st=m;//手写ceil 
}
inline int get(po p, int k)
{
	while(k<=n&&p.st<m) add(p,k++);//填充该行 
	return p.nd+dp[k];//该行高度+之前行高度 
}
signed main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].st,&a[i].nd);
	for(int i=n;i;--i) tp.st=0,tp.nd=0,dp[i]=get(tp,i);
	for(int i=1;i<=n;++i)
	{
		res=min(res,pre+get(no,i+1));//删除i，所以从i+1开始插入 
		add(no,i);//补充删掉的i，下一次删i+1 
		if(no.st==m) pre+=no.nd,no.st=0,no.nd=0;//换行 
	}
	printf("%d\n",res);
	return 0;
}
```

#### 树上dp

##### 例题

###### 二叉苹果树

> 有n节点树，根节点为1，带边权，保留(根联通)的q个边成一棵子树，求最大子树边权和

设$dp[i][j]$为i为根的子树保留j条边的最大子树边权和，转移方程为：
$$
dp[u][i]=\max(dp[u][i],dp[u][i-j-1]+dp[v][j]+边权_{u,v})\\
i\in[1,\min(q,子节点数_u)],j\in[0,\min(子节点数_v,i-1)]
$$
代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 102
struct edge
{
	ll to, nx, w;
} e[MAXN<<1];
ll cnt, hd[MAXN], ss[MAXN], dp[MAXN][MAXN], q, n, ui, vi, wi;
inline void adde(ll& u, ll& v, ll& w)
{
	e[++cnt] = { v,hd[u],w };
	hd[u] = cnt;
}
void dfs(ll u, ll fa)
{
	for (ll i = hd[u]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		if (toi == fa) continue;
		dfs(toi, u);
		ss[u] += ss[toi] + 1;
		rede(j, min(ss[u], q), 1)
		{
			rede(k, min(ss[toi], j - 1), 0)
			{
				dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[toi][k] + e[i].w);
			}
		}
	}
}
signed main()
{
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d%d%d", &ui, &vi, &wi), adde(ui, vi, wi), adde(vi, ui, wi);
	dfs(1, -1);
	printf("%d", dp[1][q]);
	return 0;
}
```

###### 没有上司的舞会

> 有n个人，如果第i个人来舞会，欢乐值为hi，有n-1组上下属关系(v,u),u是v的上司。按如上顺序输入。v的上司的上司不是v的上司。若上司参加舞会，下属必然不参加。求一种与会名单，输出最大欢乐值。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 6002
#define rep(i,a,b) for(int i=a;i<=b;++i)
struct edge
{
	int to, nx;
} e[MAXN];
int n, ui, vi, hd[MAXN], cnt, dp[MAXN][2], v[MAXN], root;
bool fa[MAXN];
inline void adde(int& u, int& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
void dfs(int h)
{
	dp[h][0] = 0;
	dp[h][1] = v[h];
	for (int i = hd[h]; i; i = e[i].nx)
	{
		int toi = e[i].to;
		dfs(toi);
		dp[h][0] += max(dp[toi][0], dp[toi][1]);
		dp[h][1] += dp[toi][0];
	}
}
signed main()
{
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &v[i]);
	rep(i, 1, n - 1)
	{
		scanf("%d%d", &vi, &ui);
		adde(ui, vi);
		fa[vi] = true;
	}
	rep(i, 1, n) if (!fa[i])
	{
		root = i;
		break;
	}
	dfs(root);
	printf("%d", max(dp[root][0], dp[root][1]));
	return 0;
}
```

###### 最大子树和

> n节点树，可以适当剪枝，求剪枝后最大点权和。

个人解法：拓补排序

```c++
#include <bits/stdc++.h>
//#pragma warning(disable:6031)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 16002
struct edge
{
	ll nx, to;
} e[MAXN << 1];
ll ind[MAXN], outd[MAXN], w[MAXN], ans=-0x7fffffff, n, ui, vi, cnt, hd[MAXN];
bool vis[MAXN];
inline void adde(ll& u, ll& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
queue<ll> q;
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n)
	{
		scanf("%lld", &w[i]);
		ans = max(ans, w[i]);
	}
	rep(i, 1, n)
	{
		scanf("%lld%lld", &ui, &vi);
		adde(ui, vi);
		adde(vi, ui);
		++ind[ui];
		++ind[vi];//注意两个都要加
	}
	repe(i, 1, n)
	{
		if (ind[i] == 1) q.push(i);
	}
	while (!q.empty())
	{
		ll tp = q.front();
		q.pop();
		ind[tp] = 0;
		for (ll i = hd[tp]; i; i = e[i].nx)
		{
			ll toi = e[i].to;
			if (ind[toi])
			{
				if(w[tp] > 0)w[toi] += w[tp], ans = max(ans,w[toi]);
				--ind[toi];
				if(ind[toi]==1)q.push(toi);//这里==1，不然会死
			}

		}
	}
	printf("%lld", ans);
	return 0;
}
```

答案解法：

```c++
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int next,to;
}tree[100000];  //存图，蒟蒻不会stl
int n,a[100000],head[100000],cnt,f[100000],ans; //f[u] 表示以u为根且包含u的最大权联通块
void add(int x,int y) 
{
    tree[++cnt].next=head[x];
    tree[cnt].to=y;
    head[x]=cnt;
}
void dfs(int u,int fa)//u为当前节点,fa为u的爸爸
{
    f[u]=a[u];  //先给f[u]赋初值，就是u本身的美观指数
    for(int i=head[u];i;i=tree[i].next) //找儿子
    {
        int v=tree[i].to;  
        if(v!=fa)  //之前加的双向边，可能跑回去
        {
            dfs(v,u);  //继续向下找
            f[u]+=max(0,f[v]);  //状态转移
        }
    }
    ans=max(ans,f[u]); //更新ans
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);  //注意加双向边
    }
    dfs(1,0);  
    printf("%d",ans);
}
```

###### 会议

> 有n个节点，n-1条无向边，求一个点x，并求点x的点对间最短路径和，每条边权均为1,如果有多解，输出最小的x(n<=5e4)

显然跑最短路会TLE，所以用dp

h[i]表示以i为根的子树的节点数

对upf的解释：

x的父亲是y，所有不在x的h[x]的节点，它们到x的距离是到y的加1，变化值为1，这样的点有n-h[x]-1个(1是自己)；所有在x的h[x]的节点，它们到x的距离是到y的减1，变化值是-1这样的点h[x]+1个(包括自己，即自己到父亲距离为1，然后自己到自己为0)，所以：
$$
f[x] = f[y] - (h[x] + 1) + (n - h[x] - 1);(未化简)
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 50002
ll n, f[MAXN], h[MAXN], ans = 1, cnt, u, v, hd[MAXN];
struct edge { ll to, nx; } e[MAXN << 1];
#define fore(x) for (ll i = hd[x]; i; i = e[i].nx)
#define toi e[i].to
inline void adde(ll& u, ll& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
ll upe(ll x, ll y)
{
	fore(x) if (toi != y) h[x] += 1 + upe(toi, x);
	return h[x];
}
void upf(ll x, ll y)
{
	f[x] = f[y] - (h[x] + 1) + (n - h[x] - 1);
	fore(x) if (toi != y) upf(toi, x);
}
void upg(ll x, ll y, ll z)
{
	f[1] += z;
	fore(x) if (toi != y) upg(toi, x, z + 1);
}
signed main()
{
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld%lld", &u, &v), adde(u, v), adde(v, u);
	upe(1, 0);//求所有以i为根的i~n的子树的子节点数
	fore(1) upg(toi, 1, 1);//求以1为根的树的答案
	fore(1) upf(toi, 1);//树的最短路转移算法
	repe(i, 2, n) if (f[i] < f[ans]) ans = i;
	printf("%lld %lld", ans, f[ans]);
	return 0;
}
```

###### 核心城市

> 有n城,n-1长为1的路，选k座互相相邻的城，找到这样的选法，使得任一城到这k座城的距离的最大值最小，输出这个最小值。

这k座城中，第一座选树直径的中点

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll n, k, dtr, num, ansk, d[MAXN], dp[MAXN], mxd[MAXN], ans[MAXN], u, v;
struct node { ll to, nx; } e[MAXN << 1];
ll hd[MAXN], cnt;
inline void adde(ll& u, ll& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
#define fore(x) for(ll i=hd[x];i;i=e[i].nx)
#define toi e[i].to
inline bool cmp(const ll& x, const ll& y) { return x > y; }
#define updnum if (d[x] > dtr) dtr = d[x], num = x
#define fajump if(toi==fa) continue
#define updd d[toi] = d[x] + 1
void dfs(ll x, ll fa, bool nd)
{
	updnum;
	fore(x)
	{
		fajump;
		updd;
		if (nd) dp[toi] = x;
		dfs(toi, x, nd);
	}
}
void dfsk(ll x, ll fa)
{
	mxd[x] = d[x];
	fore(x)
	{
		fajump;
		updd;
		dfsk(toi, x);
		mxd[x] = max(mxd[x], mxd[toi]);
	}
}
signed main()
{
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n) scanf("%lld%lld", &u, &v), adde(u, v), adde(v, u);
	dfs(1, 0, false);
	memset(d, 0, sizeof(d));
	dtr = 0;
	dfs(num, 0, true);//两次dfs求树直径的模板
	ll cf = num;
	repe(i, 1, (d[num] + 1) / 2) cf = dp[cf];//模板求树直径中点
	memset(d, 0, sizeof(d));
	dfsk(cf, 0);//dfs求mxd这个点可到的最大深度；d这个点的深度
	repe(i, 1, n) ans[i] = mxd[i] - d[i];
	sort(ans + 1, ans + 1 + n, cmp);
	repe(i, k + 1, n) ansk = max(ansk, ans[i] + 1);
	printf("%lld", ansk);
	return 0;
}
```

###### 加分二叉树

> 已知n节点二叉树的中序遍历为123...n，每个节点有正整数分数di，每棵子树的加分方法为：左子树加分x右子树加分+根节点分数；如果空树，加分为1，叶节点不考虑空子树。求最大加分及其前序遍历。

定义$dp[i][j]$为从点i~j的最大加分树，则
$$
dp[i][j]=\max(dp[i][k-1]\times dp[k+1][j]+dp[k][k])
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 33
ll n, dp[MAXN][MAXN], root[MAXN][MAXN];
void pre(ll lf, ll rf)
{
	if (lf > rf) return;
	printf("%d ", root[lf][rf]);
	pre(lf, root[lf][rf] - 1);
	pre(root[lf][rf] + 1, rf);
}
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n)
	{
		scanf("%d", &dp[i][i]);
		dp[i][i - 1] = 1;
		root[i][i] = i;
	}
	rep(h, 1, n)
	{
		repe(i, 1, n - h)
		{
			ll j = i + h;
			dp[i][j] = dp[i + 1][j] + dp[i][i];
			root[i][j] = i;
			rep(k, i + 1, j)
			{
				if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k])
				{
					dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
					root[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", dp[1][n]);
	pre(1, n);
	return 0;
}
```

写法二：

```c++
#include<iostream>
#include<cstdio>
using namespace std;
int n,v[39],f[47][47],i,j,k,root[49][49];
void print(int l,int r){
    if(l>r)return;
    if(l==r){printf("%d ",l);return;}
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}
int main() {
    scanf("%d",&n);
    for( i=1; i<=n; i++) scanf("%d",&v[i]);
    for(i=1; i<=n; i++) {f[i][i]=v[i];f[i][i-1]=1;}
    for(i=n; i>=1; i--)
        for(j=i+1; j<=n; j++)
            for(k=i; k<=j; k++) {
                if(f[i][j]<(f[i][k-1]*f[k+1][j]+f[k][k])) {
                    f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
                    root[i][j]=k;
                }
            }
    printf("%d\n",f[1][n]);
    print(1,n);
    return 0;
}
```

###### 选课

> 从n门课选m门，输入各课先修课v和学分x(v=0无需先修)，求最大学分

原$dp[i][j][k]$表示以i为根节点的子树，考虑前j个节点选k门课方案数

原转移方程如下：
$$
dp[now][j][k]=max(dp[now][j-1][k],\\f[son][nodes_{son}][x]+dp[now][j-1][k-x])
$$
可能会超空间复杂度，减掉j，得到：
$$
dp[i][k]=max(dp[i][k],dp[i][k-p]+dp[son][p])
$$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 302
struct edge { ll to, nx; } e[MAXN];
ll hd[MAXN], cnt, n, m, dp[MAXN][MAXN], v;
inline void adde(ll& u, ll& v)
{
	e[++cnt].to = v;
	e[cnt].nx = hd[u];
	hd[u] = cnt;
}
void f(ll no)
{
	for (ll i = hd[no]; i; i = e[i].nx)
	{
		ll toi = e[i].to;
		f(toi);
		rede(j, m + 1, 1)
		{
			rep(k, 0, j)
			{
				dp[no][j] = max(dp[no][j], dp[toi][k] + dp[no][j - k]);
			}
		}
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	repe(i, 1, n) scanf("%d%d", &v, &dp[i][1]), adde(v, i);
	f(0);
	printf("%d", dp[0][m + 1]);
	return 0;
}
```

###### 三色二叉树

> 给定数字序列，0代表叶子节点，1下面的节点是唯一子节点，2代表下面的两个节点是子节点。规定直接父子颜色各异，同父的子节点颜色各异，有红绿蓝三色可以选择，求最大和最小的绿色节点数。

**解法1：**

设$dp[x][c]$代表第x个节点取颜色c时的最大值和最小值(以mx和mi为计)，易得：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 500002
char s[MAXN];
ll mx[MAXN][3], mi[MAXN][3], cnt;
ll mxa = 1;
void dfs(ll x)
{
	if (s[x] == '0')
	{
		mi[x][0] = mx[x][0] = 1;
		return;
	}
	dfs(++cnt);
	if (s[x] == '1')
	{
		mx[x][0] = max(mx[x + 1][1], mx[x + 1][2]) + 1;
		mx[x][1] = max(mx[x + 1][0], mx[x + 1][2]);
		mx[x][2] = max(mx[x + 1][0], mx[x + 1][1]);
		mi[x][0] = min(mi[x + 1][1], mi[x + 1][2]) + 1;
		mi[x][1] = min(mi[x + 1][0], mi[x + 1][2]);
		mi[x][2] = min(mi[x + 1][0], mi[x + 1][1]);
	}
	else if (s[x] == '2')
	{
		ll k = ++cnt;
		dfs(k);
		mx[x][0] = max(mx[x + 1][1] + mx[k][2], mx[x + 1][2] + mx[k][1]) + 1;
		mx[x][1] = max(mx[x + 1][0] + mx[k][2], mx[x + 1][2] + mx[k][0]);
		mx[x][2] = max(mx[x + 1][0] + mx[k][1], mx[x + 1][1] + mx[k][0]);
		mi[x][0] = min(mi[x + 1][1] + mi[k][2], mi[x + 1][2] + mi[k][1]) + 1;
		mi[x][1] = min(mi[x + 1][0] + mi[k][2], mi[x + 1][2] + mi[k][0]);
		mi[x][2] = min(mi[x + 1][0] + mi[k][1], mi[x + 1][1] + mi[k][0]);
	}
	mxa = max(mxa, mx[x][0]);
}
signed main()
{
	scanf("%s", s + 1);
	dfs(++cnt);
	printf("%d %d", mxa, min(mi[1][0], min(mi[1][1], mi[1][2])));
	return 0;
}
```

**解法2：**

设$dp[x][0]$表示第i个节点，不染绿色(1代表染绿色)，自己和子树的绿色最值。

初始值为：$dp[any][1]=1$，转移方程如下：

有：$dp[i][1]=dp[左][0]+dp[右][0]$

对最大值，有:
$$
dp[i][0]=\max(dp[左][0]+dp[右][1],dp[左][1]+dp[右][0],dp[左][0]+dp[右][0])
$$
对最小值，用$\min$且第三项不能取。

#### 图上dp

##### 最优贸易

> 有$n$城$m$路，可能是单向或双向，每座城市可以以特定价格$p$买入或卖出货物，从$1$城到终点$n$城，中途可以买入和卖出各一次货物，求最多可以赚多少差价？$1\le n\le10^5,1\le m\le5\times10^5,1\le p\le 10^2$

设$dp[i]$代表到$i$城时最多可以赚多少差价，记忆化设$mi[i]$代表经过$i$城时最低可以用多少钱买入货物，则$dp$方程十分显然；注意剪枝，即走到某城时如果既不能用更便宜的价格买入又不能用更好的价格卖出，直接剪枝。

该方法复杂度不稳定，(正确性有待证明)，可能最坏情况为$\Omicron(n^2)$。

由于一开始每个点都是$0$的初始值，保证了如果有赚，一定会先遍历一次各个点；而如果一开始没得赚，那么也会每次更新最小值，所以也会遍历一次各个点。

```c++
#define mm 500010
#define mn 100010
struct edge {ll to,nx;} e[mm];
ll hd[mn],cnt,n,m,dp[mn],mi[mn],p[mn],u,v,ss;
il void adde(ll&u, ll&v) {e[++cnt]={v,hd[u]};hd[u]=cnt;}
void dfs(ll u, ll np, ll fa)
{
    bool hg=false;
    ll minp=min(np,p[u]);
    if(minp<np) np=minp,hg=true;
    ll mxnw=max(dp[fa],p[u]-minp);
    if(mxnw>dp[u]) dp[u]=mxnw,hg=true;
    if(!hg) return;
    for(ll i=hd[u];i;i=e[i].nx) dfs(e[i].to,minp,u);
}
signed main()
{
    n=read();m=read();
    repe(i,1,n) p[i]=read();
    rep(i,0,m)
    {
        u=read();v=read();ss=read();
        adde(u,v); if(ss==2) adde(v,u);
    }
    dfs(1,0x7ffffffa,0);
    return printf("%lld",dp[n]),0;
}
```

本题解法多样，还有缩点拓补排序，spfa双向搜索等方法。

#### 其他例题

##### 最长公共子序列

Longest Common Subsequence problem, LCS，给定两或多个序列，求最长公共子序列，如abcbdab,bdcaba的最长子序列是bcba。输入数组数q,输入2*q行(第i个x，y)，输出x,y的LCS的长度。其中1<=q<=150,1<=x,y的长度<=1000,若某组x或y超过100，q不超过20

显然时间复杂度是$O(n^2)$

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
static const int N = 1000;
int c[N+1][N+1];//如果放局部变量会崩溃
//c[i][j]代表Xi与Yj的LCS长度
int lcs(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for(int i=1;i<=m;i++) c[i][0] = 0;
    for(int j=1;j<=n;j++) c[0][j] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i]==Y[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}

int main()
{
    string s1, s2;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        cout<<lcs(s1,s2)<<endl;
    }
    return 0;
}
```

##### 矩阵链乘法

输入n个矩阵，维数为r（行）,c（列数）,1<=n,r,c<=100，输出最小乘法次数

```c++
#include <iostream>
#include <algorithm>
using namespace std;
static const int N=100;
int main()
{//m[i][j]表示计算Mi*..*Mj的最小次数
    int n, p[N+1], m[N+1][N+1];
    cin >> n;//pi表示列(p0行)
    for(int i=1;i<=n;i++) cin >> p[i-1] >> p[i];
    for(int i=1;i<=n;i++) m[i][i] = 0;//初始化:自己跟自己是0
    for(int l=2;l<=n;l++)
    {//l的作用是使得i在1~n-1之间，而j在i+1~n之间
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j] = (i<<21);
            for(int k=i;k<=j-1;k++)
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
        }
    }
    cout<<m[1][n]<<endl;//从1乘到n
}
```

##### 最少硬币数

输入n,m，输入m种硬币面值(均不相同，包含1，小于一万正整数)，1<=n<=50000,1<=m<=20

设：

```c++
C[m] C[i]表示第i种硬币面值
T[m][n+1] T[i][j]表示用第0至i种硬币支付j元最少硬币数
则T[i][j]=min(T[i-1][j],T[i][j-C[i]]+1)，举例易知
    
进一步归纳，可以有T[n+1], T[j]表示支付j元最少硬币数
则T[j] = min(T[j], T[j-C[i]]+1)
复杂度为O(mn)
```

```c++
#include <iostream>
#include <algorithm>
using namespace std;
static const int MMAX = 20;
static const int NMAX = 50000;
static const int INFTY = (1<<29);
int main()
{
    int n,m;
    int C[MMAX+1];
    int T[NMAX+1];
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>C[i];
    for(int i=0;i<=NMAX;i++) T[i]=INFTY;
    T[0] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j+C[i]<=n;j++)
        {
            T[j+C[i]] = min(T[j+C[i]], T[j]+1);
        }
    }
    cout<<T[n]<<endl;
    return 0;
}
```

##### 编辑距离

> 有字符串x,y；每次只能进行如下编辑的一种：删除/插入/修改一个字符，求最小编辑次数，使x=y。

定义$dp[i][j]$表示将长为i的x子串编辑为长为j的y子串的编辑距离。

```c++
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2002
#define repe(i,a,b) for(int i=a;i<=b;++i)
int n,dp[MAXN][MAXN];
char x[MAXN],y[MAXN];
int edit(int a, int b)
{
    if(dp[a][b]!=-1) return dp[a][b];
    if(!a) return dp[a][b]=b;
    if(!b) return dp[a][b]=a;
    return dp[a][b]=min(min(edit(a-1,b)+1,edit(a,b-1)+1),edit(a-1,b-1)+(int)(x[a]!=y[b]));
}
signed main()
{
    scanf("%s%s",x+1,y+1);
    repe(i,0,2000) repe(j,0,2000) dp[i][j]=-1;
    printf("%d", edit(strlen(x+1),strlen(y+1)));
    return 0;
}
```

##### 背包问题

可以分为01背包，0n背包，无限背包，分组背包，混合背包等若干问题

> 本焫鷄正在学习……

##### 双人单调路径

> 有两个人可以从左上角，都只能向下或向右，走到右下角，走到的格子可以获取该格子的点数，问最大点数和。输入方形地图长度n，接下来输入若干行x,y,v,x,y从1计数，读0终结。

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
using namespace std;
#define MAXN 12
typedef long long ll;
ll m[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN], n, x, y, v;
signed main()
{
	scanf("%lld", &n);
	while (1)
	{
		scanf("%lld%lld%lld", &x, &y, &v);
		if (!x) break;
		m[x][y] = v;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				int l = i + j - k;
				if (l <= 0) break;
				dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k - 1][l]);
				dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l - 1]);
				dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k - 1][l]);
				dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l - 1]);
				if (i == k && j == l)dp[i][j][k][l] += m[i][j];
				else dp[i][j][k][l] += m[i][j] + m[k][l];
			}
		}
	}
	printf("%lld", dp[n][n][n][n]);
	return 0;
}
```

换成n*m，且读入方式换为矩阵，一个三维dp示例如下：

> 首先重要的就是三维F数组。
>
> 第一维度维护的是在传的过程中纵坐标与横坐标的和。
>
> \#在同一斜线上，剩下表示两个点的从坐标就可以表示这两个点的位置。
>
> 第二维度维护的是相对在左边的点的纵坐标。
>
> 第三维度维护的是相对在右边的点的纵坐标。
>
> 当查询一个情况时，只有四种情况可以到他
>
> ```c++
> F[sum][i][j]=max{F[sum-1][i][j]+F[k-1][i][j-1]+F[k-1][i-1][j]+F[k-1][i-1][j-1]；
> ```

```c++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=60;
int a[maxn][maxn];
int F[2*maxn][maxn][maxn];
int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  //F[sum][i][j]=max{F[sum-1][i][j]...
  memset(F,-1,sizeof(F));//赋初值为-1 (原因在后面） 
  F[2][1][1]=0;//最初的点，在左上角，好感度为0 
  for(int k=3;k<m+n;k++)
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
      {
        int s=F[k][i][j];
        if(F[k-1][i][j]>s)s=F[k-1][i][j];
        if(F[k-1][i-1][j]>s)s=F[k-1][i-1][j];
        if(F[k-1][i][j-1]>s)s=F[k-1][i][j-1];
        if(F[k-1][i-1][j-1]>s)s=F[k-1][i-1][j-1];
        if(s==-1)continue;//当s为-1时，说明四种情况都不能到该点，故不存在。 
        F[k][i][j]=s+a[k-i][i]+a[k-j][j];//该点的值为最大的前一个值与当前F[k][i][j]表示两点的值的和。 
      }
  printf("%d",F[m+n-1][n-1][n]);//因为i永远小于j，所以右下角的点不会求到，
  //但是到右下角只有一种情况，就是在右下角的上面和右下角的左边，直接输出就好了。 
  return 0;
 } 
```

##### 乌龟棋

> 从1出发到n，每格有一个分数pi,有四种走法，每次走1,2,3,4格，走到的格子加分，起止分都有。给定n,m(可以走多少次)，输入pi,输入mi(代表可以走多少格)，不必按照输入顺序走。求最大分数。

```c++
#include <bits/stdc++.h>
#define MAXN 352
#define MAXM 42
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int dp[MAXM][MAXM][MAXM][MAXM], n, m, p[MAXN], bin[5], v;
signed main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &p[i]);
	dp[0][0][0][0] = p[1];
	rep(i, 1, m)
	{
		scanf("%d", &v);
		++bin[v];
	}
	rep(a, 0, bin[1]) rep(b, 0, bin[2]) rep(c, 0, bin[3]) rep(d, 0, bin[4])
	{
		v = 1 + a + b + b + c + c + c + d + d + d + d;
		if (a) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + p[v]);
		if (b) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + p[v]);
		if (c) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + p[v]);
		if (d) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + p[v]);
	}
	printf("%d", dp[bin[1]][bin[2]][bin[3]][bin[4]]);
	return 0;
}
```

## 字符串

### 自动机

#### 概念

一般指确定有限状态自动机。**自动机**(automata)是一个对信号序列进行判定的数学模型。自动机只是一个 **数学模型**，而 不是算法，也 不是数据结构。根据自动机实现的方式不同，时空复杂度不同。

字典树，KMP等是自动机。

> “**信号序列**”是指一连串有顺序的信号，例如字符串从前到后的每一个字符、数组从 1 到 n 的每一个数、数从高到低的每一位等。“判定”是指针对某一个命题给出或真或假的回答。有时我们需要对一个信号序列进行判定。一个简单的例子就是判定一个二进制数是奇数还是偶数，较复杂的例子例如判定一个字符串是否回文，判定一个字符串是不是某个特定字符串的子序列等等。

自动机的结构是有向图。自动机的每一个结点都是一个判定结点；自动机的结点只是一个单纯的状态而非任务。

> 举例：设点a有有向边通向点b当且仅当收到信号1，b有有向边通回1当且仅当收到信号0。从a出发接受一系列信号，如果结束在了点a，那么这个二进制信号序列是偶数，否则是奇数。
>
> 下图是判断二进制数是否是偶数的自动机：
>
> ```mermaid
> graph LR;
> 	A["0(起始A)"]-->|1|B["判定节点B"]
> 	B-->|0|A
> ```
>
> 从起始点开始，从高到低接受二进制序列，若终止节点是$A$，那么是偶数。例如输入$101100$，移动状态为：$A\to B\to A\to B\to A$。其中$A$移动到$B$当且仅当接受$1$，即接受$0$后不动。$B$同理。

一个 **确定有限状态自动机（DFA）** 由以下五部分构成：

1. **字符集**（$\sum$），该自动机只能输入这些字符。
2. **状态集合**（$Q$）。如果把一个 DFA 看成一张有向图，那么 DFA 中的状态就相当于图上的顶点。
3. **起始状态**（$start$），$start\in Q$，是一个特殊的状态。起始状态一般用$s$表示。
4. **接受状态集合**（$F$），$F\subseteq Q$，是一组特殊的状态。
5. **转移函数**（$\delta$）， $\delta$是一个接受两个参数返回一个值的函数，其中第一个参数和返回值都是一个状态，第二个参数是字符集中的一个字符。如果把一个 DFA 看成一张有向图，那么 DFA 中的转移函数就相当于顶点间的边，而每条边上都有一个字符。

DFA可以识别字符串，如果自动机A可以识别字符串S，则$A(S)=True$，否则$False$。

当一个 DFA 读入一个字符串时，从初始状态起按照转移函数一个一个字符地转移。如果读入完一个字符串的所有字符后位于一个接受状态，那么我们称这个 DFA **接受** 这个字符串，反之我们称这个 DFA **不接受** 这个字符串。

如果一个状态$v$没有字符$c$的转移，那么我们令$\delta(v,c)=null$，而null只能转移到null ，且null不属于接受状态集合。无法转移到任何一个接受状态的状态都可以视作null ，或者说， null代指所有无法转移到任何一个接受状态的状态。

拓展转移函数使其接受字符串，处理方式为使用状态机依次递归识别每个字符，即$\delta(v,s)=\delta(\delta(v,s[1]),s[2..|s|])$。因此$A(s)=\delta(start,s)\in F$

> 举例：规定$F=\{1,3\}$时，下面是一个只接受字符串`a,ab,aac`的DFA：
>
> ```mermaid
> graph LR;
> 	A[0]-->|a|B[1]
> 	B-->|a|C[2]
> 	B-->|b|D[3]
> 	C-->|c|D
> ```
>
> 



#### 字典树

Trie

转移函数是边，接受状态是将每个字符串插入到 Trie 时到达的那个状态。

```c++
struct trie {
  int nex[100000][26], cnt;
  bool exist[100000];  // 该结点结尾的字符串是否存在

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = 1;
  }
  bool find(char *s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
};
```

应用：

- 检查字符串是否在字典出现过，一次检查复杂度为$\Omicron(|s|)$
- 将二进制数看成字符串，维护异或极值、异或和

进阶：

- trie上所有数值+1：模拟二进制加法，交换其左右儿子，顺着 交换后 的 `0` 边往下递归操作即可
- 字典树合并
- 可持久化字典树

##### 例题

###### 最大异或和

> (scnucpc2020)给定n阶矩阵，有m个询问，求左上(下标从1计数)(x1,y1)和右下(x2,y2)子矩阵对k取异或的最大值。$2\le n\le256$,$1\le x_1\le x_2\le n,$$1\le y_1\le y_2\le n,1\le k,a_{i,j}\le10^9$

da r sep

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
#define mn 1300002
#define mm 302
ll n, a[mm][mm], mx, ax, ay, ch[mn][2], idx, id[mn], rt[mm][mm];
void insert(ll k, ll x, ll y)
{
	rt[x][y] = ++idx;
	ll u = rt[x][y];
	ch[u][0] = ch[rt[x][y + 1]][0];
	ch[u][1] = ch[rt[x][y + 1]][1];
	rede(i, 11, 0)
	{
		ll c = (k >> i) & 1, t = ch[u][c];
		ch[++idx][0] = ch[t][0];
		ch[idx][1] = ch[t][1];
		ch[u][c] = idx, u = ch[u][c];
	}
	id[u] = y;
}
void query(ll k, ll x, ll lf, ll rf)
{
	ll res = 0, f = 1, u = rt[x][lf];
	rede(i, 11, 0)
	{
		ll c = (k >> i) & 1;
		if (ch[u][c ^ 1] >= rt[x][rf])
			u = ch[u][c ^ 1], res += (1 << i);
		else u = ch[u][c];
	}
	if (res > mx) mx = res, ax = x, ay = id[u];
}
signed main()
{
	n = read();
	repe(i, 1, n) repe(j, 1, n) a[i][j] = read();
	repe(i, 1, n) rede(j, n, 1) insert(a[i][j], i, j);
	for (ll t = read(), x1, x2, y1, y2, k; t; --t)
	{
		x1 = read(), y1 = read(), x2 = read(), y2 = read(), k = read();
		mx = -1;
		repe(i, x1, x2) query(k, i, y1, y2);
		printf("%d %d\n", ax, ay);
	}
	return 0;
}
```

###### 小熊吃饼干

> (csoj)所有字符串仅有小写字母组成，长度不超过$s=10^2$，有$n$个字符串，有$q$个询问，给定字符串$t$，整数$k$，字符$x$，求在$n$个字符串中所有与$t$的最大前缀和为$k$的字符串中去掉这个最大前缀之后的部分有多少个$x$。
>
> $1\le n\le10^4,1\le q\le10^5,1\le k\le|t|$

开字典树，并且用前缀和桶排+删除的思维(先单独放后dfs应该也可以)存某个节点子树有多少个字母，空间复杂度是$\Omicron(26ns)$，不能开long long，不然会炸内存。

搜索时即找到第$k$节点，然后统计子树，所有不是$k+1$的子树都记录

> 注意一些别的统计方法或建树方法不能过题……例如开动态字典树莫名其妙TLE和减法统计莫名WA

参考代码如下：(事实上可以用vector优化内存，但是关系不大)

```c++
#define me 27
struct trie
{
    ll nx[me], ac[me];
} t[1000010];
il ll toi(char x) { return x - 'a' + 1; }
char s[123], x;
ll suc, res, n, q, ss, cnt, k;
void build()
{
    re ll no = 0;
    unordered_map<ll, ll> bin;
    rep(i, 0, ss)++ bin[toi(s[i])];
    rep(i, 0, ss)
    {
        re ll si = toi(s[i]);
        if (t[no].nx[si])
        {
            no = t[no].nx[si];
        }
        else
        {
            t[no].nx[si] = ++cnt;
            no = cnt;//这两行写反成no=++cnt,t..=cnt暴死
        }
        for (auto i : bin)
            t[no].ac[i.first] += i.second;
        --bin[si];
    }
}
void find()
{
    re ll no = 0;
    rep(i, 0, k)
    {
        re ll si = toi(s[i]);
        if (t[no].nx[si])
            no = t[no].nx[si];
        else
        {
            suc = false;
            break;
        }
    }
    if (suc)
    {
        repe(i, 1, 26)
        {
            if (toi(s[k]) == i)
                continue;
            re ll nw = t[no].nx[i];
            if (nw)
            {
                res += t[nw].ac[toi(x)];
            }
        }
    }
}
signed main()
{
    n = read();
    rep(i, 0, n)
    {
        scanf("%s", s);
        ss = strlen(s);
        build();
    }
    q = read();
    rep(i, 0, q)
    {
        scanf("%s%d %c", s, &k, &x);
        ss = strlen(s);
        s[ss] = '|';//省去特判越界
        suc = true;
        res = 0;
        find();
        printf("%d\n", res);
    }
    return 0;
}

```

> 其他解法：字符串排序+二维前缀和+二分查找+前缀和差分



###### Browser Games

> (icpc45 银川)In the upcoming n days, n browser games will be released on a new website. According to the plan, the administrator will release a new game per day. Users have to open the corresponding URL (Uniform Resource Locator) and get feedback from the server to download a game.
>
> However, the setup of the server uses unreadable legacy codes. Once a user somehow finds the URL of an unreleased game, the data of the game would leak out. To temporarily fix the problem, the administrator decided to add a series of **confirmation prefixes**, which are non-empty strings, at the server-side. The server will respond with the correct game data when the requested URL does correspond to a game (no matter released or unreleased) and at least one **confirmation prefix** is a prefix of the URL; otherwise the server will declare that the game is not found.
>
> To make the work easier, the administrator asks you to find the minimum number of **confirmation prefixes** the server required to avoid data leaks every time after a new game release.
>
> The first line contains an integer n  (1 ≤ n ≤ 5 × $10^4$), indicating the number of browser games to be released.
>
> In the next n*n* lines, the i*i*-th line contains a non-empty string, consisting of only lowercase letters ('a' to 'z'), dots ('.') and forward slashes ('/'), indicating the URL of the browser game released on the i*i*-th day,
>
> It is guaranteed that the length of each given URL is at most 50, and no given URL is the prefix of any other given URL.
>
> Output n*n lines, the i-th of which contains an integer indicating the minimum number of required confirmation prefixes after the i-th new game released.

暂未完全搞懂。个人动态字典树如下：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef long long ll;
#define il inline
#define re register
#define rep(i,a,b) for(re ll i=a;i<b;++i)
#define repe(i,a,b) for(re ll i=a;i<=b;++i)
#define red(i,a,b) for(re ll i=a;i>b;--i)
#define rede(i,a,b) for(re ll i=a;i>=b;--i)
ll n,r;
#define mn 50010
string s[mn];
struct node
{
    unordered_map<char,node*> nx;
    ll n;
};
unordered_map<node*,ll> dt;
node* hd=new node;
void build(ll h)
{
    re ll len=s[h].size();
    node* hi=hd;
    rep(i,0,len)
    {
        re char nc=s[h][i];
        node* nw=nullptr;
        if(!hi->nx[nc])
        {
            nw=new node;
            hi->nx[nc]=nw;
            nw->n=1;
        }
        else
        {
            nw=hi->nx[nc];
            ++(nw->n);
        }
        hi=nw;
    }
}
void seek(ll h)
{
    re ll len=s[h].size();
    node* hi=hd;
    vector<node*> me;
    rep(i,0,len)
    {
        re char nc=s[h][i];
        hi=hi->nx[nc];
        --(hi->n);
        if(!hi->n)
        {
            re ll dd=1-dt[hi];
            r+=dd;
            rep(j,0,me.size()) dt[me[j]]+=dd;
            return;
        }
        me.push_back(hi);
    }
}
signed main()
{
    scanf("%lld",&n);
    rep(i,0,n)
    {
        cin>>s[i];
        build(i);
    }
    rep(i,0,n)
    {
        seek(i);
        printf("%lld\n",r);
    }
    return 0;
}
```

题解字典树如下：

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int trie[maxn][30];
int sum[maxn];
int countt[maxn];
int cnt=0,ans=0;
int n;
int getid(char c)
{
    if(c=='.') return 26;
    if(c=='/') return 27;
    return c-'a';
}
void insert(string& s)
{
    int root=0;
    for(int i=0;i<s.size();i++)
    {
        int id=getid(s[i]);
        if(trie[root][id]==0)
        {
            trie[root][id]=++cnt;
        }
        sum[trie[root][id]]++;
        root=trie[root][id];
    }
}
void find(string& s)
{
    int root=0;
    vector<int> p;
    for(int i=0;i<s.size();i++)
    {
        int id=getid(s[i]);
        sum[trie[root][id]]--;
        if(sum[trie[root][id]]==0)
        {
            int delta=1-countt[trie[root][id]];//某节点由子节点合并后的改变量
            ans+=delta;
            for(int j=0;j<p.size();j++)
            {
                countt[p[j]]+=delta;//回溯
            }
            return;
        }
        root=trie[root][id];
        p.push_back(root);
    }
}
int main()
{
    cin>>n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        v.push_back(s);
        insert(s);
    }
    for(int i=0;i<v.size();i++)
    {
        find(v[i]);
        cout<<ans<<endl;
    }
    return 0;
}
```



#### KMP

The Knuth-Morris-Pratt Algorithm，克努特—莫里斯—普拉特操作

基于字符串s的KMP自动机接受且仅接受以s为后缀的字符串，接受状态为$|s|$。
$$
\delta(i,c)=\begin{cases}
i+1&s[i+1]=c\\
0&s[1]\neq c\wedge i=0\\
\delta(\pi(i),c)&s[i+1]\neq c\wedge i>0
\end{cases}
$$
其中，前缀函数是长为n的数组$\pi$,

- 若子串$s[0\dots i]$有一对相等的真前缀和真后缀，则$\pi(i)$是这个真前缀的长度
- 如果相等的不止一对，那么取最长那一对的长度
- 如果没有相等的，返回0

kmp[i] 用于记录当匹配到模式串的第 i 位之后失配,该跳转到模式串的哪个位置，记录在第1-第i-1位(即一个前缀)中前缀与后缀相同的部分最长是多长

下面代码匹配字符串$b$在$a$中每次出现的位置，并输出$b$的kmp数组。

输出所有出现的位置(下标从1数)，接着输出第二个字符串长度为i的最长border长度(border 为 s的一个非 s本身的子串 t，满足 t既是 s 的前缀，又是 s的后缀)。

```c++
#include <bits/stdc++.h>
#define MAXN 1000002
using namespace std;
char a[MAXN],b[MAXN];
int kmp[MAXN],len1,len2,j;
int main()
{
    scanf("%s%s",a+1,b+1);
    len1=strlen(a+1);
    len2=strlen(b+1);
    for(int i=2;i<=len2;i++)
    {
        while(j&&b[i]!=b[j+1]) j=kmp[j];
        if(b[j+1]==b[i]) j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=len1;i++)
    {
        while(j>0&&b[j+1]!=a[i]) j=kmp[j];
        if(b[j+1]==a[i]) j++;
        if(j==len2)
        {
            printf("%d\n",i-len2+1);
            j=kmp[j];
        }
    }
    for(int i=1;i<=len2;i++)
    {
        if(i>1) putchar(' ');
        printf("%d",kmp[i]);
    }
    return 0;
}
```

##### 例题

###### 无线传输

> 给你一个字符串 s*1，它是由某个字符串s*2 不断自我连接形成的。但是字符串 *s*2 是不确定的，现在只想知道它的最短长度是多少。

由于有反例aba，所以不能从右往左找第一个不为0的kmp。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 1000002
typedef int ll;
char x[mn];
ll kmp[mn],n,j;
signed main()
{
    scanf("%d%s",&n,x+1);
    for(ll i=2;i<=n;++i)
    {
        while(j&&x[j+1]!=x[i]) j=kmp[j];
        if(x[j+1]==x[i]) ++j;
        kmp[i]=j;
    }
    printf("%d",n-kmp[n]);
    return 0;
}
```

#### AC自动机

Aho-Corasick Automaton，用于在一个字符串内找若干个模式串是否出现及出现次数。

##### 实现

###### 模式串是否出现

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 1000002
queue<ll> q;
struct acdfa
{
	ll c[mn][26], v[mn], fail[mn], cnt;
	void ins(char* s)
	{
		ll len = strlen(s), no = 0;
		rep(i, 0, len)
		{
			ll v = s[i] - 'a';
			if (!c[no][v])c[no][v] = ++cnt;
			no = c[no][v];
		}
		++v[no];
	}
	void build()
	{
		rep(i, 0, 26) if (c[0][i]) fail[c[0][i]] = 0, q.push(c[0][i]);
		while (!q.empty())
		{
			ll u = q.front(); q.pop();
			rep(i, 0, 26) 
			{
				if (c[u][i])
					fail[c[u][i]] = c[fail[u]][i], q.push(c[u][i]);
				else c[u][i] = c[fail[u]][i];
			}
		}
	}
	ll query(char* s)
	{
		ll len = strlen(s), no = 0, ans = 0;
		rep(i, 0, len)
		{
			no = c[no][s[i] - 'a'];
			for (ll t = no; t && ~v[t]; t = fail[t]) 
				ans += v[t], v[t] = -1;
		}
		return ans;
	}
} ac;
ll n;
char p[mn];
signed main()
{
	scanf("%d", &n);
	repe(i, 1, n) scanf("%s", p), ac.ins(p);
	ac.build();
	scanf("%s", p);
	printf("%d", ac.query(p));
	return 0;
}
```

###### 出现次数

> 有t次询问，每次有n个模式串和一个目标串，求模式串最大出现次数和这个次数的所有模式串。模式串少于150个，单个长度不大于70，目标串长度不大于$10^6$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define mn 100002
struct tr { ll fail, vis[26], end; } ac[mn];
struct res { ll n, p; } ans[mn];
ll cnt, n;
string s[mn];
inline bool operator <(const res& a, const res& b)
{
	return a.n != b.n ? a.n > b.n:a.p < b.p;
}
inline void cls(ll x)
{
	memset(ac[x].vis, 0, sizeof ac[x].vis);
	ac[x].fail = ac[x].end = 0;
}
inline void build(string& s, ll num)
{
	ll len = s.length(), no = 0;
	rep(i, 0, len)
	{
		ll toi = s[i] - 'a';
		if (ac[no].vis[toi] == 0)
		{
			ac[no].vis[toi] = ++cnt;
			cls(cnt);
		}
		no = ac[no].vis[toi];
	}
	ac[no].end = num;
}
void get_fail()
{
	queue<ll> q;
	rep(i, 0, 26)
	{
		if (ac[0].vis[i] != 0)
		{
			ac[ac[0].vis[i]].fail = 0;
			q.push(ac[0].vis[i]);
		}
	}
	while (!q.empty())
	{
		ll u = q.front(); q.pop();
		rep(i, 0, 26)
		{
			if (ac[u].vis[i] != 0)
			{
				ac[ac[u].vis[i]].fail = ac[ac[u].fail].vis[i];
				q.push(ac[u].vis[i]);
			}
			else ac[u].vis[i] = ac[ac[u].fail].vis[i];
		}
	}
}
ll ask(string& s)
{
	ll len = s.length(), no = 0, res = 0;
	rep(i, 0, len)
	{
		no = ac[no].vis[s[i] - 'a'];
		for (ll t = no; t; t = ac[t].fail) ++ans[ac[t].end].n;
	}
	return res;
}
signed main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		cnt = 0;
		cls(0);
		repe(i, 1, n)
		{
			cin >> s[i];
			ans[i] = { 0,i };
			build(s[i], i);
		}
		ac[0].fail = 0;
		get_fail();
		cin >> s[0];
		ask(s[0]);
		sort(ans + 1, ans + n + 1);
		printf("%d\n", ans[1].n);
		cout << s[ans[1].p] << endl;
		repe(i, 2, n)
		{
			if (ans[i].n == ans[i - 1].n)
				cout << s[ans[i].p] << endl;
			else break;
		}
	}
	return 0;
}
```



#### 后缀自动机

**后缀自动机**(suffix automaton, SAM) 

SAM可以在$\Omicron(n)$内构造并解决：

- 在一个字符串中搜索另一个字符串的所有出现位置。
- 计算给定的字符串中有多少个不同的子串。

直观上，字符串的 SAM 可以理解为给定字符串的 **所有子串** 的压缩形式。一个SAM最多有$2n-1$个节点和$3n-4$条转移边。

字符串s的SAM是一个接受s的所有后缀的最小DFA。

- SAM 是一张有向无环图。结点被称作 **状态**，边被称作状态间的 **转移**。
- 图存在一个源点$t_0$ ，称作 **初始状态**，其它各结点均可从 $t_0$出发到达。
- 每个 **转移** 都标有一些字母。从一个结点出发的所有转移均 **不同**。
- 存在一个或多个 **终止状态**。如果我们从初始状态 $t_0$出发，最终转移到了一个终止状态，则路径上的所有转移连接起来一定是字符串s 的一个后缀。 s的每个后缀均可用一条从$t_0$ 到某个终止状态的路径构成。
- 在所有满足上述条件的自动机中，SAM 的结点数是最少的。

> SAM的性质：包含字符串$s$的所有子串信息，从$t_0$开始的路径都是$s$的子串。

定义endpos(t)为在字符串s中非空子串t的所有结束位置，如abcbc的endpos(bc)为2,4

> 若两子串的endpos集合相等，它们是同一等价类。SAM的每个状态对应一个或多个endpos相同的子串，状态数等于所有子串的等价类个数+初始状态。
>
> 两个非空子串u,w(设u不比w长)的endpos相同当且仅当u是w的后缀。如果不相同则必然它们的endpos集合交集是空。(可以反证法证明)
>
> 考虑一个endpos等价类，将类中的所有子串按长度非递增的顺序排序。每个子串都不会比它前一个子串长，与此同时每个子串也是它前一个子串的后缀。换句话说，对于同一等价类的任一两子串，较短者为较长者的后缀，且该等价类中的子串长度恰好覆盖整个区间 $[x,y]$。

定义$substring(x)$表示状态$x$包含的所有子串的集合，$longest(x)$表示它包含的最长子串，同理有$shortest(x)$。$minlen(x)=|shortest(x)|$。$len(x)=|longest(x)|$

>  可以发现，$substring(x)$包含的是$longest(x)$的从长到短的若干个连续后缀，而$shortest(x)$就是最短的连续后缀。

$x$的后缀链接是$shortest(x)$的真后缀的$endpos$对应的状态。

> 后缀链接(link)，构成的数是$endpos$集合的另一棵树

使用在线算法构造SAM，初始只包含编号为$0$的状态$t_0$，对应$len=0,link=-1$。给当前字符串添加字符$c$：

- $last$是添加$c$前字符串对应的状态(初始为$0$)
- 设新状态$cur,len(cur)=len(last)+1$
- 从$last$开始，若还没到$c$的转移，添加一个转移，遍历后缀链接，若某个点存在到$c$的转移，这个状态标记为$p$。
- 若找不到$p$，即找到了$-1$，设$link(cur)=0$



//da bk

#### 广义后缀自动机

#### 回文自动机

#### 序列自动机

### 常规字符处理

#### 一般字符处理

> 这一部分严格来说并不是算法

##### 命令交互

假设命令头字母不重复，为了节省算力，可以只检索头字母便得到命令

哪怕重复，其实也可以只检测两个：end, extract嘛

然后对于存在0或多个参数的不同命令，

首先只scanf命令，判断后在判断分支里scanf命令的参数！

##### 字符输出

###### 复标签单序输出

情况1：可能的标签有：X、AX、BX、ABX，则：

算法1：if(isa) printf(A); if(isb) printf(B); printf(X);

##### 变换

###### 反转

```c++
for(j=0;i=len-1;j<i;--i;++j) swap(str[i],str[j])
```

#### 回文串

##### 朴素dp

(个人解法)把问题转化为求字符串和它的倒串的最长公共子串，直接dp既可。

设$dp[i][j]$为以$i$结尾和以$j$结尾的子串的最长公共子串，时空复杂度为$\Omicron(n^2)$

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 1010
char a[mn],b[mn];
int len,dp[mn][mn],mx=1;
signed main()
{
    cin.getline(a,1005);
    len=strlen(a);
    for(int i=0,j=len-1;i<len;++i,--j) b[i]=a[j];
    for(int i=1;i<=len;++i)
    {
        for(int j=1;j<=len;++j)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                mx=max(dp[i][j],mx);
            }
        }
    }
    printf("%d",mx);
    return 0;
}
```

##### manacher算法

求一个字符串的最长回文子串长度。时间复杂度是$\Omicron(n)$

因为奇数长度好确定回文中心，所以预处理插入分隔符，cf,rf代表已知的右侧最靠右的回文串对称中心和右边界；lf是当前扫描的中心，$p[i]$是$i$为中心的最长回文半径，最短是$1$。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 11000002
char io[MAXN << 1], c;
ll p[MAXN << 1], cnt, ans, rf, cf;
signed main()
{
	c = getchar(); io[0] = '~', io[cnt = 1] = '|';
	while (c >= 'a' && c <= 'z') io[++cnt] = c, io[++cnt] = '|', c = getchar();
	repe(lf, 1, cnt)
	{
		if (lf <= rf) p[lf] = min(p[(cf << 1) - lf], rf - lf + 1);
		while (io[lf - p[lf]] == io[lf + p[lf]]) ++p[lf];
		if (p[lf] + lf > rf) rf = p[lf] + lf - 1, cf = lf;
		ans = max(ans, p[lf]);
	}
	printf("%d", ans - 1);
	return 0;
}
```

如果没有那个io0会WA一个点(全为同样字符的点),虽然\|理论上可以随便取任何跟分隔符和已知字符不一样的字符。

解析：$lf\le rf$时，当前扫描的$lf$位置在已知的一个回文串里，其对称中心等于之前已知的一个对称过去的子串长度$p[cf\times 2-lf]$。并且当前回文串右边长度不应该超过右边，即：
$$
p[lf]+lf-1\le rf\Rightarrow p[lf]\le rf-lf+1
$$
然后在当前中心进行拓展；拓展后如果发现比原纪录长，那么更新原纪录；最后输出即可。

###### 最长双回文串

> 长为英文字母串$s(2\le |s|\le10^5)$，定义双回文串是可以分为非空的两部分回文串的子串，求$s$的最长双回文串。

设以i为结尾的最长回文子串的长度ll[i]，和以i为开头的最长回文子串的长度rr[i]。

```c++
//因为每个双回文串中间不能交叉，所以只能枚举'#'来找答案 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int min(int a,int b){return a<b?a:b;}//手写min函数
inline int max(int a,int b){return a>b?a:b;}//手写max函数

#define re register
#define ll long long
#define N 100100

int n,len[(N<<1)+10],l[(N<<1)+10],r[(N<<1)+10];
//l[i]表示以i结尾的最长回文串的长度
//r[i]表示以i开头的最长回文串的长度 
char ch[N+10],s[(N<<1)+10];
//ch：原数组，s：加了'#'的数组

void manache()//manacher求最长回文串的函数
{
	int id=0,maxx=0;
	for(re int i=1;i<=n;++i)
	{
		if(i<maxx)len[i]=min(maxx-i,len[id*2-i]);
		else len[i]=1;
		while(s[i+len[i]]==s[i-len[i]])++len[i];
		if(i+len[i]>maxx)
		{
			maxx=i+len[i];
			id=i;
		}
		l[i+len[i]-1]=max(l[i+len[i]-1],len[i]-1);//求出以i结尾的饱和回文串的最大长度
		r[i-len[i]+1]=max(r[i-len[i]+1],len[i]-1);//求出以i开头的饱和回文串的最大长度
	}
}

int main()
{
	scanf("%s",ch+1);
	int tlen=strlen(ch+1);
	s[0]='$';s[1]='#';n=1;
	for(re int i=1;i<=tlen;++i)
	{
		s[++n]=ch[i];
		s[++n]='#';
	}
	manache();
	for(re int i=3;i<=n;i+=2)r[i]=max(r[i],r[i-2]-2);//求出以i开头的饱和与不饱和回文串的最大长度
	for(re int i=n;i>=3;i-=2)l[i]=max(l[i],l[i+2]-2);//求出以i结尾的饱和与不饱和回文串的最大长度
	int ans=0;
	for(re int i=3;i<=n;i+=2)if(r[i]&&l[i])ans=max(ans,l[i]+r[i]);//一定要写r[i]&&l[i]，否则会wa 
	printf("%d\n",ans);
	return 0;
}
```



### 哈希

假设下标从$1$开始计数，字符串哈希计算使用递推公式：
$$
h[i]=h[i-1]\times p+idx[i]
$$
$p$取素数，一般取$131,13331,2333$等。有被$Hack$掉的风险，所以可以多搞几个不同的，建议使用unsigned long long计算，避免取模问题，相当于自动对$2^{64}-1$取模且总是正的

以$\Omicron(n)$预处理整个字符串的手写哈希之后，可以以$\Omicron(1)$(预处理幂数组)或$\Omicron(\log p)$(快速幂)计算子串哈希，计算子串$[l,r]$公式如下：
$$
h=h[r]-h[l-1]\times p^{r-l+1}
$$

> 推导：
> $$
> h=idx[r]+idx[r-1]\times p+\cdots+idx[r-l+1]\times p^{r-l+1}\\
> h[r]=idx[r]+\cdots+idx[l]\times p^{r-l}+idx[l-1]\times p^{r-l+1}+\cdots idx[1]\times p^{r-1}\\
> h[l-1]=idx[l-1]+\cdots+idx[0]\times p^{l-2}\\
> h[l-1]\times p^{r-l+1}=idx[l-1]\times p^{r-l+1}+\cdots+idx[0]\times p^{r-1}
> $$
> 所以也就是后面一段截断前面一段，也就是那条公式

#### 例题

##### 随机生成的字符串岂不是随便搞都能过

> 给定字符串 a,b，给出下面 C++ 程序期望的运行结果。输入a,b,$1<|a|,|b|\le 10^5$
>
> ```c++
> #include <iostream>
> long long cnt = 0;
> 
> int main()
> {
>     std::string a, b;
>     std::cin >> a >> b;
>     for (size_t i = 1; i <= a.size(); i++)
>     {
>         for (size_t j = 1; j <= a.size() && i + j <= b.size(); j++)
>         {
>             cnt += (a.substr(0, i) + a.substr(0, j) == b.substr(0, i + j));
>         }
>     }
>     std::cout << cnt << std::endl;
> }
> ```

化简为枚举$i$，然后二分$j$的最大值，累加$j$。此时复杂度是$\Omicron(n\log n)$，所以需要以$\Omicron(1)$的时间复杂度计算$a$子串是否与$b$的相等。$a$子串直接取$a$的哈希数组，$b$子串取$l=i+1,r=i+1+cf$，注意不要取错位置。那么就可以愉悦二分+哈希了。

```c++
#define mn 100010
char a[mn], b[mn];
ll as, bs, p[mn], p0 = 13331, ahash[mn], bhash[mn], res;
il ll toi(char &x)
{
    return x - 'a' + 1;
}
signed main()
{
    scanf("%s%s", a + 1, b + 1);
    as = strlen(a + 1), bs = strlen(b + 1);
    p[0] = 1, ahash[1] = toi(a[1]), bhash[1] = toi(b[1]);
    repe(i, 1, 100001) p[i] = p[i - 1] * p0;//注意不是p[1]=1或p[0]=p0
    repe(i, 2, as) ahash[i] = ahash[i - 1] * p0 + toi(a[i]);
    repe(i, 2, bs) bhash[i] = bhash[i - 1] * p0 + toi(b[i]);
    repe(i, 1, as) //a.substr(0,i)
    {
        re ll cf, lf = 1, rf = as, jhash = 0, ihash = ahash[i], j = 0;
        if (ihash != bhash[i])
            continue;
        while (lf <= rf) //b.substr(0,cf) 
        {//注意不是lf<rf
            cf = (lf + rf) >> 1;
            jhash = ahash[cf];
            if (jhash == bhash[i + cf] - bhash[i] * p[cf])
            {
                j = cf;
                lf = cf + 1;
            }
            else//注意不是rf=cf
                rf = cf - 1;
        }
        res += j;
    }
    printf("%lld\n", (ll)res);
    return 0;
}
```





### 字典序

#### 例题

##### 交换字符

> (oj)仅由x,y,z构成的字符串，相邻为x,y或y,z可以相互交换，求交换后1最小字典序的字符串。字符串长度最大为$3\times10^5$

先让y跟所有字符串交换排到最前，然后让y后的x统统放到y前面。

```c++
#include <bits/stdc++.h>
#define mn 300002
char s[mn],t[mn];
int y,l,o;
signed main()
{
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;++i)
		if(s[i]=='y') s[y++]='y';
		else t[o++]=s[i];
	memcpy(s+y,t,o*sizeof(char));
	for(int i=y,j=0;s[i]=='x';++i,++j) std::swap(s[j],s[i]);
	return printf("%s",s)&0;
}
```

##### 排序

> (蓝桥)对字符串排序，只允许交换相邻字符，冒泡排序是最优解。求交换100次后升序的只有小写不重复字母的最短的且(在此基础上)字典序最小的字符串。

显然$n=15$长度最小，且显然用前15个字母，且完全逆序需要$105$次。那么反向思考，从完全逆序走$5$次，字典序最小，容易发现，只需要将完全逆序的第六个字母(j)往前放到最前面即可。答案为$jonmlkihgfedcba$。

不失一般地，在完全逆序下贪心地将后面的字符往前，即可获得最优解。

可以发现，最终需要被交换的字符只有一位，因为要交换两个字符的时候，必然存在更短的答案，因为数列$\frac{n(n-1)}2$的$a_{n+1}-a_n=n$，所以但凡超过了$n$，必然进入下一项。

```c++
#include <bits/stdc++.h>
using namespace std;
#define tg 100
int n,ot,lf;
signed main()
{
	do{
		++n;
		ot=(n-1)*n>>1;
	}while(ot<tg);
	lf='a'+n-1-(ot-tg);
	putchar(lf);
	for(int i='a'+n-1;i>='a';--i) if(i!=lf) putchar(i);
	return 0;
} 
```

##### 字串排序

> (蓝桥)在上一题(排序)的基础上，字符串可以包含相同字符，输入交换次数v$1\le 10^4$，求字符串。

da r sep

> 以下两份题解在蓝桥官网的prev-67题评测均不过最后三点，待确认是题目数据有误还是算法有误。

###### DFS剪枝

需要事先推导出结论：

1. 答案必然是单调不上升的
2. 位于前边的字母数量不会大于位于后边的字母数量

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e4+5;

int num[N], res[N];
int n, m, _max, len;

bool judge(int letter) {
	int i = 26, j = letter;
	while (!res[i]) i--;
	if (i == j) {
		while (i > 0 && j > 0) {
			if (res[i] != num[j]) {
				return res[i] > num[j];//当前解比答案更优 
			} else {
				i--; j--;
			}
		}
	}
	return i > j;//原长度大必然当前解更优 
}

void dfs(int letter, int curlen, int cursum, int l) {
	//printf("%d %d %d %d\n",letter,curlen,cursum,l);
	//cursum是当前逆序数，curlen是当前字符串长度 
	//letter是当前字母是什么(串必然是逆序的)，l是这个字母有多少个 
	
	if (cursum > n) return ;
	if (letter > _max) return ;
	if (curlen > len) return ;
	
	if (curlen == len && cursum != n) return ;
	if (letter == _max && cursum != n) return ;
	//printf("save\n");
	if (cursum == n) {
		//printf("ei\n");
		if (curlen < len || judge(letter)) { //长度减小或字典序减小更新结果
			//printf("ye\n");
			len = curlen;//记录更优解 
			for (int i = 1; i <= 26; i++) {
				res[i] = num[i];
			}
		}
		return ;
	}
	
	//可以知道下一个字母不会多于上一个字母，不然有更短的结果 
	for (int i = 1; i <= l; i++) {
		num[letter + 1] = i;//下一个字母选择多少个 
		dfs(letter + 1, curlen + i, cursum + i * curlen, i);
		//这个增值是i*curlen是很容易计算出来的 
	}
	num[letter + 1] = 0;//回溯 
}

int main() {
	
	scanf("%d", &n);

	m = 0; len = 0;
	while (m < n) {
		int id = 1;
		for (int i = 2; i <= 26; i++) { //找到s最小的点, 如果存在多个取字典序更小的
      if (res[i] < res[id]) id = i;
		}
		m += len - res[id];
		//len小于等于26时，res[id]=1,len=id=_max,m递增0,1,2,3,... ，
		//当最后的m大于等于n时保存并break 
		//此时len,id,_max都是len(答案长度) 
		
		//否则再继续增加
		_max = max(_max, id);
		len ++; res[id] ++;
		//printf("%d %d %d %d %d\n", m, id, len, _max, res[id]);
	}
	//for(int i=1;i<=m;++i) printf("%d\n",res[i]);
	//res表示当前解是逆序解 
	
	dfs(0, 0, 0, 10);
	
	for (int i = _max; i >= 1; i--) {
		for (int j = res[i]; j > 0; j--) {
			printf("%c", i-1+'a');
		}
	}
	printf("\n");

  return 0;
}
```

###### DP

```c++
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[152][26][152];
int dfs (int pre , int x , int aft)
{
    int &d = dp[pre][x][aft] ;
    if ( ~d ) return d;
    if (x == 1) return d = pre * aft;
    if (aft == 0) {
        if (x != 0) return -1e9;
        return 0;
    }
    int ans = 0;
    for (int i = 1 ; i <= aft ; i++){
        int res = dfs(pre + i, x - 1 , aft - i) + i * pre;
        if (ans < res){
            ans = res;
        }
    }
    return d = ans;
}
void dfs2 (int pre , int x , int aft , int rest , string &res)
{
    if (x == 1){
        res += string(aft , 'a');
        return ;
    }
    int len = 1e9;
    for (int i = 1 ; i <= aft ; i++){
        int d = dfs(pre + i , x - 1 , aft - i) + i * pre;
        if (d >= rest){
            len = i;
            break;
        }
    }
    res += string(len , 'a' + x - 1);
    rest -= len * pre;
    dfs2(pre + len , x - 1 , aft - len , rest , res);
    return ;
}
int calc (string a)
{
    int n = a.size();
    int ans = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = i + 1 ; j < n ; j++){
            if (a[i] > a[j]) ans++;
        }
    }
    return ans;
}
void solve (int v)
{
    memset(dp , -1 , sizeof dp);
    int len = 1e9 , x = 1e9;
    for (int i = 1 ; i <= 150 ; i++){
        for (int j = 1 ; j <= 26 ; j++){
            if (dfs(0ll , j , i) >= v){
                if (len > i){
                    len = i , x = j;
                }else if (len == i){
                    x = min(x , j);
                }
            }
        }
    }
    string ans;
    dfs2(0 , x , len , v , ans);
    cout << ans << endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int n; cin >> n;
    solve(n);
    return 0;
}
```

##### 最小表示法

> 一个工艺品有n个方块，各有瑕疵值，两工艺品美观的比较方法为，同一位置的方块，瑕疵不一样时，瑕疵小的更漂亮，一样则继续往下找，如果都一样则同等漂亮。可以不断将最左边方块放到最右边，给出一个工艺品，将它变化到最漂亮。

即求最小字典序。

###### 最小表示法

找出循环同构串(原题目变化后可以得到的内容)中字典序最小的一个，

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll n, ans, a[300002], i, j = 1, k;
signed main()
{
	scanf("%lld", &n);
	rep(i, 0, n) scanf("%lld", a + i);
	while (i < n && j < n && k < n)
	{
		if (a[(i + k) % n] == a[(j + k) % n]) ++k;
		else
		{
			if (a[(i + k) % n] > a[(j + k) % n]) i += k + 1;
			else j += k + 1;
			if (i == j) ++i; 
			k = 0;
		}
	}
	ans = min(i, j);
	rep(i, 0, n) printf("%lld ", a[(i + ans) % n]);
	return 0;
}
```

###### Duval算法

对于一个字符串，若其本身就是其最小后缀，则称它为 **Lyndon 串**，即若一个串的字典序比他**所有后缀**的**字典序**小。

任意一个字符串都可以被唯一的分解成若干个字典序非严格递减的 Lyndon 串。对于长度为 n的字符串 s，存在唯一的若干个 Lyndon 串 $t_{1\dots m}$*t*1，满足 $s=t_1 + t_2 + \cdots + t_m$且$ t_1 \ge t_2 \ge \cdots \ge t_m$。

Duval 算法可以在 $\mathcal O(n)$ 的时间求出一个字符串的 Lyndon 分解。

设一个字符串$t=s+s$，其首字符位置$\le n$且最大的Lyndon串所在首字符是答案首字符。

```c++
const int N = 6e5 + 7;
int n, ans, s[N];

int main() {
	rd(n);
	for (int i = 1; i <= n; i++) rd(s[i]), s[i+n] = s[i];
	int i = 1;
	while (i <= n) {
		int j = i, k = i + 1;
		while (k <= n * 2 && s[j] <= s[k]) j = s[j] == s[k++] ? j + 1 : i;
		while (i <= j) i += k - j, ans = i <= n ? i : ans;
	}
	for (int i = 1; i <= n; i++) print(s[ans-1+i], " \n"[i==n]);
	return 0;
}
```

附：求所有lyndon串右端点(i从1算)异或和的模板：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b)  for(ll i=a;i<b; ++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b)  for(ll i=a;i>b; --i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
ll n, ans, i = 1, j, k;
char s[5000002];
signed main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	while (i <= n)
	{
		j = i, k = i + 1;
		while (k <= n && s[j] <= s[k]) j = s[j] == s[k++] ? j + 1 : i;
		while (i <= j) i += k - j, ans ^= i - 1;
	}
	printf("%d", ans);
	return 0;
}
```

###### 后缀自动机

(suffix automaton, SAM) 

```c++
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn 300003
int n,a[maxn];
map<int,int>ch[maxn<<2];//全部暴力建map
int tot=1,lst=1,len[maxn<<2],fail[maxn<<2];
void append(int c)
{
	int u=++tot,p=lst;
	len[u]=len[p]+1;
	for(;p&&!ch[p][c];p=fail[p])ch[p][c]=u;
	if(!p)fail[u]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1)fail[u]=q;
		else{
			int cc=++tot;
			fail[cc]=fail[q],len[cc]=len[p]+1;
			ch[cc]=ch[q];//直接写=
			for(;p&&ch[p][c]==q;p=fail[p])ch[p][c]=cc;
			fail[q]=fail[u]=cc;
		}
	}lst=u;
}
signed main()
{
	n=read();
	For(i,1,n)a[i]=read();
	For(_,1,2)For(i,1,n)append(a[i]);
	int p=1;
	For(i,1,n){
		map<int,int>::iterator q=ch[p].begin();
        //解释：q是迭代器
        //(*q).first是这条边的值
        //(*q).second是这条边连着的下一个节点
		p=(*q).second;
		cout<<(*q).first<<' ';
	}
    return 0;
}
```



### FFT字符串匹配

#### 公式

由于字符可以表示为$ASCII$，设$A$字符串的第$x$个(从$0$开始下标)为$A(x)$，同理设$B(y)$，字符相等可以表示为$C(x,y)=A(x)-B(y)=0$

字符串$A$与$B$以第$x$位结束的连续$m$位完全匹配可以表示为：
$$
P(x)=\sum_{i=0}^{m-1}[A(i)-B(x-(m-1)+i)]^2
$$
取平方是为了避免正负抵消为$0$，可能造成诸如`"ab"=="ba"`的问题。不取绝对值是因为绝对值的优化难实现，只能$\Omicron(nm)$计算。

翻转$A$，设$S(x)=A(m-x-1)$，则：
$$
P(x)=\sum_{i=0}^{m-1}[S(m-i-1)-B(x-m+i+1)]^2\\
=\sum_{i=0}^{m-1}S(m-i-1)^2+\sum_{i=0}^{m-1}B(x-m+i+1)^2\\-2\sum_{i=0}^{m-1}S(m-i-1)B(x-m+i+1)
\\=\sum_{i=0}^{m-1}S(i)^2+\sum_{i=x-m+1}^xB(i)^2-2\sum_{i+j=x}S(i)B(j)
$$
其中两个单求和显然可以用前缀和优化$\Omicron(1)$算出每一次的$P(x)$的这一项。而后面可以用卷积计算预处理，然后用$\Omicron(n)$得到每一项，单次计算的总复杂度为$\Omicron(n)$。

由于$FFT$预处理的复杂度是$\Omicron(n\log n)$，普通的字符匹配不如KMP高效。而FFT字符串匹配主要用于带通配符的字符串匹配。通配符定义为可以与任意字符匹配的字符，设通配符的ASCII为$0$，则：
$$
C(x,y)=[A(x)-B(y)]^2A(x)B(y)
$$
完全匹配函数即：
$$
P(x)=\sum_{i=0}^{m-1}C(i,x-m+i+1)\\
=\sum_{i+j=x}S(i)^3B(j)+\sum_{i+j=x}S(i)B(j)^3-2\sum_{i+j=x}S(i)^2B(j)^2
$$
带幂的可以先预处理每一项的系数做幂运算。伪代码如下：

```c++
void FFT_match(char *s1,char *s2,int m,int n)
{
	reverse(ss1,ss1+m);
	for(int i=0;i<m;i++) A[i]=(s1[i]!='*')?(s1[i]-'a'+1):0;
	for(int i=0;i<n;i++) B[i]=(s2[i]!='*')?(s2[i]-'a'+1):0;
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i]*A[i],0),b[i]=Comp(B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i],0),b[i]=Comp(B[i]*B[i]*B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
	
	for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i],0),b[i]=Comp(B[i]*B[i],0);
	FFT(a,len,1);FFT(b,len,1);
	for(int i=0;i<len;i++) P[i]=P[i]-a[i]*b[i]*Comp(2,0);
	
	FFT(P,len,-1);
	for(int i=m-1;i<n;i++) if(fabs(P[i].r)<=1e-7) printf("%d ",i-m+2);
}
```



#### 例题

##### 残缺的字符串

> 给定带通配符`*`的字符串$a,b,|a|=m,|b|=n$，下标从$1$开始，求$a$的首位作为$b$的第$k$位时能够匹配的所有解和解数目。$1\le m\le n\le3\times10^5$

对$b$，设$P(i)$，一共需要计算$m-n+1$个$P$。事实上，卷积的时候，由于计算的是所有$i\times j$,然后对于某一次只取$i+j=C$的，那么可以对计算出来的结果一次FFT计算后分别累加到不同的$P$上。

这题常数卡得很狠，注意优化。别人的过题代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
#define db double
const db pi = acos(-1);
#define MAX 1100000
char sa[MAX], sb[MAX];
int m, n, N, top, a[MAX], b[MAX];
int rev[MAX], sta[MAX];
#define il inline
#define ll int
#define re
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
struct cpx
{
    double x, y;
    cpx() {}
    cpx(double xx, double yy) { x = xx, y = yy; }
    cpx(int xx, int yy) { x = xx, y = yy; }
    friend cpx operator*(cpx a, cpx b)
    {
        return cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
    friend cpx operator/(cpx a, double b)
    {
        return cpx(a.x / b, a.y / b);
    }
    friend cpx operator+(cpx a, cpx b)
    {
        return cpx(a.x + b.x, a.y + b.y);
    }
    friend cpx operator-(cpx a, cpx b)
    {
        return cpx(a.x - b.x, a.y - b.y);
    }
    friend cpx operator*(cpx a, double b)
    {
        return cpx(a.x * b, a.y * b);
    }
};
cpx A[MAX], B[MAX], C[MAX];
void fft(cpx *a, int f)
{
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
    {
        cpx wn(cos(pi / i), f * sin(pi / i));
        for (int j = 0; j < N; j += (i << 1))
        {
            cpx w(1, 0);
            for (int k = 0; k < i; k++)
            {
                cpx x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
                w = w * wn;
            }
        }
    }
    if (f == -1)
        for (int i = 0; i < N; i++)
            a[i] = a[i] / N;
}
int main()
{
    scanf("%d%d%s%s", &m, &n, sa, sb);
    reverse(sa, sa + m);
    int l = 0;
    for (N = 1; N < 2 * n; N <<= 1)
    {
        l++;
    }
    for (int i = 0; i < N; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for (int i = 0; i < m; i++)
    {
        if (sa[i] != '*')
        {
            a[i] = sa[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (sb[i] != '*')
        {
            b[i] = sb[i] - 'a' + 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i] * a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] - A[i] * B[i] * 2.0;
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] = cpx(0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        A[i] = cpx(a[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = cpx(b[i] * b[i] * b[i], 0);
    }
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = C[i] + A[i] * B[i];
    }

    fft(C, -1);
    for (int i = m - 1; i < n; i++)
    {
        if (fabs(C[i].x) < 0.5)
        {
            sta[top++] = i - m + 2;
        }
    }
    printf("%d\n", top);
    for (int i = 0; i < top; i++)
    {
        printf("%d ", sta[i]);
    }
    return 0;
}
```



### 例题

##### Cities and States S

> 如果某城市的首两个字符与另一个城市的州一致，另一个城市与该城市亦然，且它们来自不同的省，认为它们是特殊的对，求这样的对数

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
unordered_map<string, int> a;
ll n, ans;
string s, t;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	while (n--)
	{
		cin >> s >> t;
		s = s.substr(0, 2);
		if (s != t) ans += a[s + t];
		++a[t + s];
	}
	printf("%d", ans);
	return 0;
}
```

##### 子串分值

> (蓝桥)对字符串s，定义分值为恰好出现一次的字符个数，求一个字符串所有非空子串的分数和。

设下标从1开始，上下界分别是下标0,n+1。对一个字符，从它开始往左和往右碰到相同字符前，它都只出现一次，都可以贡献1分，在这一段包含它的子串数为：
$$
(rf-cf)\times(cf-lf)
$$
其中cf是它自己的下标，lf,rf分别是上一个它和下一个它的坐标，如果找不到，那么是上下界。(个人实现版本)

```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> v[130];
#define mn 100002
typedef long long ll;
ll n,pos[mn],ans,mpos[130];
char c,a[mn];
signed main()
{
	for(int i='a';i<='z';++i) v[i].push_back(0);
	while((c=getchar())!=EOF)
	{
		if(c=='\n') break;
		pos[++n]=++mpos[c];
		v[c].push_back(n);
		a[n]=c;
	}
	for(int i='a';i<='z';++i) v[i].push_back(n+1);
	for(int i=1;i<=n;++i)
	{
		int idx=pos[i];
		ll lf=v[a[i]][idx-1],cf=v[a[i]][idx],rf=v[a[i]][idx+1];
		ll d1=cf-lf,d2=rf-cf;
		if(d1<=0) d1=1; if(d2<=0) d2=1;
		ans+=d1*d2;
	}
	printf("%lld",ans);
	return 0;
}
```

##### 子串分值和

> (蓝桥)在上一题(子串分值)的基础上，令分值的定义是不同字符是数目。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
char s[N];
ll vis[40];//注意longlong
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
	{
		ans += (i - vis[s[i] - 'a']) * (n - i + 1);
		vis[s[i] - 'a'] = i;
	}
	cout << ans << endl;
	return 0;
}
```

## 博弈论

> **博弈论** ，是经济学的一个分支，主要研究具有竞争或对抗性质的对象，在一定规则下产生的各种行为。博弈论考虑游戏中的个体的预测行为和实际行为，并研究它们的优化策略。
>
> 通俗地讲，博弈论主要研究的是：在一个游戏中，进行游戏的多位玩家的策略。

### 公平组合游戏

ICG，定义为：

- 两名选手
- 两名选手轮流行动，每一次行动可以在有限合法操作集合中选择一个
- 游戏的任何一种可能的**局面**(position)，合法操作集合只取决于这个局面本身，不取决于轮到哪名选手操作、以前的任何操作、骰子的点数或者其它因素；局面的改变称为“**移动**”(move)
- 如果轮到某名选手移动，且这个局面的合法的移动集合为空（也就是说此时无法进行移动），则这名选手负

对于局面，有：

1. **P-position**：在当前的局面下，先手必败
2. **N-position**：在当前的局面下，先手必胜

局面的性质：

1. 合法操作集合为空的局面是P-position
2. 可以移动到P-position的局面是N-position
3. 所有移动都只能到N-position的局面是P-position

实现：

1. 将所有终结位置标记为必败点（P点）
2. 将所有一步操作能进入必败点（P点）的位置标记为必胜点（N点）
3. 如果从某个点开始的所有一步操作都只能进入必胜点（N点） ，则将该点标记为必败点（P点）
4. 如果在步骤3未能找到新的必败（P点），则算法终止；否则，返回到步骤2

#### SG函数

Sprague-Grundy Theorem

任何一个ICG游戏都可以通过把每个局面看成一个顶点，对每个局面和它的子局面连一条有向边来抽象成一个“有向图游戏”，为：起始顶点有一枚棋子，选手交替移动这枚棋子，无法移动判负，求有无必胜策略。

##### mex运算

**mex**(minimal excludant)**运算**，求出最小的不属于某个集合的非负整数，如：
$$
mex(A)=\min\{k|k\in\complement_NA\}
$$

$$
mex\{0,1,2,4\}=3,mex\{2,3,5\}=0,mex\{\}=0
$$
对有向图，定义每个顶点的SG函数如下：
$$
sg(x)=mex\{sg(y)|y为x的直接儿子\}
$$
即它所有后继中都未出现的最小值。

- 所有的没有出边的顶点，其SG值为0
- sg(x)=0的顶点x，它的所有后继y都满足 sg(y)≠0
- 对于一个sg(x)≠0的顶点，必定存在一个后继y满足sg(y)=0

顶点x所代表的position是P-position当且仅当sg(x)=0，这就是sg函数的博弈论意义

##### SG定理

**SG定理**：由n个有向图组成的ICG，设它们的起点分别为$s_1,s_2,\dots,s_n$，当且仅当$SG(s_1)\oplus SG(s_2)\oplus\dots\oplus SG(s_1)\ne0$时，这个游戏先手必胜。

对于由若干个独立个体组成的系统，SG值为其各个独立个体的SG值的异或值

> 求sg值的示例：有n个石子，每次只能取1/3/4个，先取完者胜，求sg值
> $$
> 初始状态sg[0]=0\\
> sg[1]=mex\{sg[0]\}=1\\
> sg[2]=mex\{sg[1]\}=0\\
> sg[3]=mex\{sg[2],sg[0]\}=1\\
> sg[4]=mex\{sg[3],sg[2],sg[1]\}=2\\
> sg[5]=mex\{sg[4],sg[3],sg[2]\}=3\dots
> $$
> 原游戏的SG值为所有子游戏SG值的异或和。
>
> 实现方法：
>
> ```c++
> int f[MAXN],sg[MAXN];
> bool vis[MAXN];
> void getSG(int n)
> {
> 	sort(f+1,f+1+n);
> 	memset(sg,0,sizeof(sg));
> 	for (int i=1; i<=n; i++)
> 	{
> 		memset(vis,0,sizeof(vis));
> 		for (int j=1; f[j]<=i; j++)//f排序是为了让每一种取法都循环到
> 			vis[sg[i-f[j]]]=1;
> 		for (int j=0; j<=n; j++)
> 		{
> 			if (vis[j]==0)
> 			{
> 				sg[i]=j; break;
> 			}	
> 		}
> 	}
> }
> ```
>
> ```c++
> int s[MAXN],sg[MAXN],n;
> bool vis[MAXN];
> int SG_dfs(int x)
> {
> 	if (sh[x]!=-1)
> 		return sg[x];
> 	memset(vis,0,sizeof(vis));
> 	for (int i=0; i<n; i++)
> 	{
> 		if (x>=s[i])
> 		{
> 			SG_dfs(x-s[i]);
> 			vis[sg[x-s[i]]]=1;
> 		}
> 	}
> 	int i=0;
> 	while (1)
> 	{
> 		if (!vis[i])
> 			return sg[x]=i;
> 		i++;
> 	}
> }
> ```

### 经典博弈

#### 巴什博奕

> 有n个物品，两人轮流取物，每次至少取一个，最多取m个，最后取完者胜

m=1时，显然n为偶数先手必败，n为奇数先手必胜。

m=2时，可以归纳出，$n=3k,k\in\N$时先手必败，否则先手必胜

容易得出，$sg[n]=n\%3$，

由SG定理可知，$n=3k,k\in\N$时，异或和为0，否则为1

m=3时，$m=4k,k\in\N$时先手必败，否则先手必胜，SG同理。

数学归纳，有$n\%(m+1)=0$时，先手必败，否则先手必胜

#### Nim游戏

> 所有ICG游戏都可以转化为Nim游戏求解

> 有n堆数，每堆有$s_i$个，每次可以从任意堆里取1到任意多个数，求有无先手必胜策略。

> 证明过程：
>
> 1)考虑$s_i$不为0.
>
> n=1时先手必胜。
>
> $sg[0]=0,sg[i]=mex(sg[0],\dots,sg[i-1])=i$
>
> 
>
> n=2时，如果两堆不相等，先手选择取到两堆相等，那么对方每次取任意个，先手就跟着在另一堆同样操作，必然会导致胜利，即先手必胜。
>
> 所以如果两堆相等，后手使用该策略，先手必败。
>
> 当两堆相等时，异或和为0，否则为1。
>
> 
>
> n>2时，如果原先异或和不为0，如果先手能够通过一步操作，能够让异或和转化为0，则先手必胜，否则先手必败。由二进制位运算的基本性质，显然这样的操作必然存在，所以先手必胜。
>
> 那么原先异或和为0时，先手必败。
>
> 
>
> 2)考虑$s_i$为0，0与x异或等于x，所以基本运算不变。

所以**通解**为：如果$s_i$异或和为0，先手必败，否则先手必胜。

#### 威佐夫博弈

> 有两堆物品，轮流从一堆拿任意个或同时从两堆拿同样的任意个，取完者胜，求是否先手必胜

通过大量模拟，可以得出，后手必胜局面(奇异局势)有：
$$
(0,0),(1,2),(3,5),(4,7),(6,10),(8,13)\dots
$$
可以发现，对局面$(b,a)$，如果后手必胜，设$a>b$，则：
$$
b=\lfloor\frac{1+\sqrt5}2\times(a-b)\rfloor
$$
可以证明，每个局面((0,0)除外)中的数字在所有局面中仅出现一次。即任何自然数都包含在一个且仅有一个奇异局势中。

此外，任意操作都可将奇异局势变为非奇异局势(奇异局势在一次操作中不可以转化为另一个奇异局势)；非奇异局势则一定存在在一次操作转化为奇异局势的方法。

反证法：假设有两个后手必胜局面$(b,a),(b,c),a<c$，则先手一定可以在第一次博弈中将$(b,c)$转化为$(b,a)$，从而$(b,c)$必然是先手必胜局面，矛盾。

根据beatty定理：
$$
a,b是正无理数，n\in\Z_+,若\frac1a+\frac1b=1，P=\{\lfloor na\rfloor|n\},Q=\{\lfloor nb\rfloor|n\}\\则P,Q划分\Z_+，即P\cap Q=\empty,P\cup Q=\Z_+
$$
根据上述样例，发现相邻后手必胜局面第一项差值必然是1或2，设为$\lfloor an\rfloor$(a,n意义同上述定理)，则第二项是$\lfloor(a+1)n\rfloor$，由定理：(由题意$a>1$)
$$
\frac1a+\frac1{a+1}=1
$$
解得：$a=\frac{1+\sqrt5}2$(舍去另一根)。因此，设局面为$(x,y),x>y$，验证后手必胜的公式为：
$$
\lfloor ax\rfloor=\lfloor a(y+1)\rfloor\to\lfloor(x-y)a\rfloor=y
$$
代码从略。

#### 斐波那契博弈

> 一堆物品，先手最少取一个且不能取完，之后每次取不能少于1或超过上次的二倍，取完最后一个者获胜，求是否先手必胜

n不是斐波那契数列时，先手获胜。

**齐肯多夫定理**：任何正整数可以表示为若干个不连续的Fibonacci数之和。

且斐波那契数列存在三个定理：

- $f_{n+1}<2f_n<f_{n+2}$
- $f_{n+2}<3f_n$
- $4f_n<3f_{n+1}\Rightarrow f_n<f_{n+1}<3f_{n-1}$



### 博弈分析

#### 取石子(2)

> n石子，轮流取，每次至多能取当前石子数$s$的$\lceil\frac s2\rceil$个，求先手必胜情况

使用sg函数枚举，发现从$0$开始的sg值分行排列规律如下：

```c++
0 1
0 2 1 3
0 4 2 5 1 6 3 7
0 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
...
```

规律为：数列在间隔递增，上一行的数间隔着插在下一行的数中间；其中先手必胜局面是所有$sg(n)\neq0$



#### Staircase Nim

> 有n堆石子，每堆石子的数量为 $x_1,\cdots,x_n$，A，B轮流操作，每次可以选第k堆中的任意多个石子放到第k-1堆中，第1堆中的石子可以放到第0堆中，最后无法操作的人为输。问A先手是否有必胜策略。

先手必败当且仅当奇数阶梯上的石子数异或和为0



#### Anti Nim

> Nim 游戏的变相版本，其他条件均不变，唯独定义：取到最后一个石子的人为输。那么A先手是否有必胜策略？

这题和Nim游戏非常类似，就是输赢的条件不同，但是这个游戏的胜利状态却和Nim有一些区别，这个游戏的的胜利当且仅当：

- 所有堆石子数都为1且SG值为0
- 至少有一堆石子数大于1且SG值不为0

我们对这个游戏进行分析，将其分为两种情况：

- 所有堆的石子数均为1
- 至少有一堆石子数大于1

对于第一种情况而言，我们可以很容易得到当堆数为奇数时，先手必败，否则先手必胜。

对于第二种情况而言，我们分两种情况进行讨论：

- 当SG值不为0时：若还有两堆石子数目大于1时，我们将SG值变为0即可；若只有一堆石子 数目大于1时，我们总可以让状态变成有奇数个1。所以当SG不为0时，先手必胜。
- 当SG值为0时：这样的话至少会有两堆石子的数目大于1，那么先手决策完之后，必定会使局面的SG值不为0，这样便到了先手必胜局。所以当SG为0时，先手必败。



#### Multi-SG

> 在Nim游戏的基础上添加一个操作，即可以采取行动将一堆石子分成多堆石子

这堆石子的这种情况的SG值为其分成的多堆石子的异或和

例如在Nim游戏的基础上规定可以将一堆石子变成两堆石子，那么数量为 3 的一堆石子的SG值是 mex{0,1,2,(1xor2)}=4 ，其中的 1xor2 代表将数量为 3 的石子分成数量为 1 和数量为 2 这两堆石子的后继状态的SG值。

这个结论可以推广到SG组合游戏中，即在其他规则和SG游戏一样的情况下，增加一条规则：一个单一SG游戏的后继可分为多个SG游戏。这就是Multi-SG游戏：且可以用上文的方法求SG值。



#### Every-SG

> 在普通SG游戏的基础上，新增一条规则：每次行动，每个可以移动的SG游戏都要移动，这就是Every-SG游戏

例如棋盘上有n个棋子在不同的位置，双方每次行动都要将每一个可以移动的棋子按规则移动，这就是典型的Every-SG游戏。
$$
step(v)=\begin{cases}
0,&v为终止状态\\
\max(step(u))+1,&sg(v)>0,sg(u)=0\\
\min(step(u))+1,&sg(v)=0
\end{cases}
$$


然后就有一个定理：Every-SG游戏先手必胜当且仅当单一游戏中最大的step为奇数

##### 例题

###### 重云的阵法图



### 无偏博弈

在组合博弈论里，无偏博弈是一类任意局势对于游戏双方都是平等的回合制双人游戏。这里平等的意思是所有可行的走法仅仅依赖于当前的局势，而与现在正要行动的是哪一方无关。换句话说，两个游戏者除了先后手之外毫无区别。

有偏博弈是无偏博弈外的博弈。

对于比较复杂的博弈，往往可以使用DFS回溯剪枝搜索，注意搜索时每人各走一次算一个搜索，而不是一次算一个。

#### 暴力例题

##### 填字母游戏

> (蓝桥)给定n个测试，有一串字符，有且仅有L,O和空格(*)，每人每轮必须在一个空格里填L或O，谁先组成了LOL获胜，如果填满了无法组成平局。给定一个开始局面，设双方均使用最佳策略，输出1表示必胜，-1必败，0平局。

```c++
#include <bits/stdc++.h>
#define mn 100002
using namespace std;
char x[mn];
map<string,int> dp;
int n,xl;
int dfs(char* s)
{
	if(dp.find(s)!=dp.end()) return dp[s];//剪枝，否则TLE
	if(strstr(s,"LO*")||strstr(s,"L*L")||strstr(s,"*OL")) return dp[s]=1;//获胜局面
	if(!strstr(s,"*")) return dp[s]=0;//平局局面
	int eq=-1;//如果没有对方必输的步可以走，自己必输
	for(int i=0;i<xl;++i) if(s[i]=='*')//其他局面
	{
		s[i]='L';//结果表明如果对调(先O后L)时空复杂度都会慢些
		int res=dfs(s);//尝试走一步
		if(res==-1) return s[i]='*', dp[s]=1;//这步对方必输
		if(!res) eq=0;//对方和棋等于自己和棋
		s[i]='O';
		res=dfs(s);
		if(res==-1) return s[i]='*', dp[s]=1;
		if(!res) eq=0;
		s[i]='*';//回溯
	}
	return dp[s]=eq;
}
signed main()
{
	for(scanf("%d",&n);n;--n)
	{
		scanf("%s",x);
		xl=strlen(x);
		printf("%d\n",dfs(x));
	}
	return 0;
}
```

##### 约数倍数选卡片

> (蓝桥)n张卡片，轮流拿，每次拿的数字必须是上一个被拿的数字的倍数或约数，如果轮到自己不能拿牌就输。一开始只有一部分牌可以拿(输入的第二行)。输出必胜的第一个拿的牌，如果必败输出-1

```c++
#include <bits/stdc++.h>
using namespace std;
int b[105],x,c,cis;
vector<int> ci,t[105];
bool dfs(int x)
{
	for(int i=t[x].size()-1;i>=0;--i)//玄学，正序开会TLE
	{
		if(b[t[x][i]])
		{
			--b[t[x][i]];
			bool si=dfs(t[x][i]);
			++b[t[x][i]];
			if(!si) return true;
		}
	}
	return false;
}
signed main()
{
	while(1)
	{
		scanf("%d",&x); ++b[x];
		if((c=getchar())=='\n') break;
	}
	while(1)
	{
		scanf("%d",&x); ci.push_back(x);
		if((c=getchar())!=' ') break;
	} sort(ci.begin(),ci.end()); cis=ci.size();
	for(int i=1;i<=100;++i) //预处理可行表 
	{
		if(b[i])
		{
			--b[i];
			for(int j=1;j<=100;++j) if(b[j]&&(i%j==0||j%i==0)) 
				t[i].push_back(j);
			++b[i];
		}
	}
	for(int i=0;i<cis;++i)
	{
		--b[ci[i]];
		if(!dfs(ci[i])) return printf("%d",ci[i])&0;
		++b[ci[i]];
	}
	return printf("-1")&0;
	return 0;
}
```

#### 找规律例题

##### 取石子游戏

> (scnucs2020)桃子和杏子玩取石子游戏，有$n$堆石子，第$i$堆有$a_i$个，她们轮流取石子，桃子先取，她们每次都只能选一堆未取完的石子。然后，桃子可以从这堆石子中取走$1$或$2$个石子，而杏子每次只能取走$1$个石子。谁把最后的石子取完，使得另外一个人没法操作，谁就获得了胜利。两人都在最优策略下取石子，请问最终谁获胜？第一行输入一个数$T(1\le T\le20000)$，然后会有$2T$行：一行一个数$n(1\le n\le100)$，代表石子堆数，另一行$n$个数$a_1,a_2,\cdots,a_n$，表示每一堆石子的数量$(1\le a_i\le100)$。对于每组测试，输出一行，若桃子胜，输出`momoko`，若杏子胜，输出`sakiko`。

杏子能赢当且仅当有偶数堆$1$。其他情况都是桃子赢，很容易模拟得出。

#### 转Nim例题

##### 高僧斗法

> (蓝桥)有n个和尚，各站不同台阶(从1开始)，按升序给出这些和尚位置，最后一个位置是最大阶梯。每次必须往上移动一个和尚，移动时不能超过前面的和尚或与之重合。求一种先手的必胜策略(多解输出起始和移动位置最小的)，无解输出-1。
>
> $1\le n\le100,1\le位置\le1000$

这题如果使用暴力DFS会超时，最多只能获得40分。

任何无偏的游戏理论上可以转换为Nim堆。所以该题正解是Nim堆：

注意不能直接暴力代Nim堆。考虑一个结论：前一个和尚移动若干阶梯，后一个和尚总可以移动相同的步数，之后可以到达一个新的局面，这样就消掉了两轮，之后判断先手同样还是先手。也因此，必须两两组合，则必须逐二判断，所以需要+=2。

该方法的正确性和严谨性有待证明。

```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 102
int m[mn],n,v,s[mn],sum;
signed main()
{
	while(scanf("%d",&v)!=EOF)
	{
		if(!v) break;
		m[++n]=v;
	} 
	for(int i=1;i<n;++i) s[i]=m[i+1]-m[i]-1;
	for(int i=1;i<n;i+=2) sum^=s[i];
	if(!sum) return printf("-1")&0;
	for(int i=1;i<n;++i) for(int j=1;m[i]+j<m[i+1];++j)
	{
		s[i]-=j;
		if(i!=1) s[i-1]+=j;
		sum=0;
		for(int k=1;k<n;k+=2) sum^=s[k];
		if(!sum) return printf("%d %d",m[i],m[i]+j)&0;
		s[i]+=j;
		if(i!=-1) s[i-1]-=j;
	}
	return printf("-1")&0;
}
```



```c++
#include <bits/stdc++.h>
using namespace std;
#define mn 102
int m[mn],n,v,s[mn],sum;
signed main()
{
	while(scanf("%d",&v)!=EOF) m[++n]=v;
	for(int i=1;i<n;++i) s[i]=m[i+1]-m[i]-1;
	for(int i=1;i<n;i+=2) sum^=s[i];
	if(!sum) return printf("-1")&0;
	for(int i=1;i<n;++i) for(int j=1;m[i]+j<m[i+1];++j)
	{
		s[i]-=j;
		if(i!=1) s[i-1]+=j;
		sum=0;
		for(int k=1;k<n;k+=2) sum^=s[k];
		if(!sum) return printf("%d %d",m[i],m[i]+j)&0;
		s[i]+=j;
		if(i!=-1) s[i-1]-=j;
	}
	return printf("-1")&0;
}
```

> 附：暴力TLE代码
>
> ```c++
> #include <bits/stdc++.h>
> using namespace std;
> #define mn 102
> #define back(b) {m[a]=ori; return b;}
> int m[mn],n,v;
> bool dfs(int a, int b)
> {
> 	int ori=m[a];
> 	m[a]=b;
> 	for(int i=1;i<n;++i) for(int j=m[i]+1;j<m[i+1];++j)
> 		if(dfs(i,j)) back(false)
> 	back(true)
> }
> signed main()
> {
> 	while(scanf("%d",&v)!=EOF) m[++n]=v;
> 	for(int i=1;i<n;++i) for(int j=m[i]+1;j<m[i+1];++j)
> 		if(dfs(i,j)) return printf("%d %d",m[i],j)&0;//i,j暴死
> 	return printf("-1")&0;
> }
> ```

## 杂项

### 随机算法

#### 模拟退火

Simulated annealing

可以高效解决一些NP完全问题。

> 在竞赛中，往往SA能做的题目也有非随机化算法能做的(?)
>
> 按理来说但凡是求最优解都可以想想能不能用模拟退火来做。

在一个离散或连续的答案取值范围内搜索一个函数的最值。

首先确立初始温度$t$，降温系数$k(k<1)$，一般取$[0.985,0.999]$；如有必要，还需要降温次数。一般需要调整这些参数。

每次模拟，计算现在状态和已知最优状态的差值$d$，若现在状态更优，更新已知状态为最优状态；否则以$e^{-\frac{d}{t}}$的<u>概率</u>把已知状态更新为当前状态。答案为所有历史状态的最值。

技巧：可以反复退火几次，让结果更可能是对的。

新解的生成，若是连续值，直接取随机数；求序列，可以shuffle或随机交换两个数；求网格就是二维序列。

特别地，如果新状态不是随机生成的，而是按照目前状态推的，那么就是**爬山算法**。一般爬山算法也会有温度和降温。但爬山算法不是随机的，是确定的。只是需要调参。

##### 例题

###### 平衡点

> $n$个重量不同的重物用变长弹性绳子系在一起，绳子在不同位置穿过水平面垂直向下，在水平面绳子交于一点，求平衡时该点的位置。
>
> $1\le n\le 10^3,-10^4\le x,y\le10^4,0<w\le10^3, \in Z$
>
> 答案精度保留三位小数。

状态值的计算：由热力学定律，平衡状态系统能量最低，所以重力势能和最小，动能为$0$。(不懂)水平面上绳子越短，下面越长，重力势能越小。

> 是不是理解成：每根绳子足够长且定长

> 错误状态：已知一个点，这个点受到的合力越小越接近平衡点(错误原因未知)

参考代码：

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 1010
ll x[mn], y[mn], w[mn], n, xs, ys;
db mxx, mxy, mxe, nox, noy, noe, rsx, rsy, rse, k = 0.996;
db e(db nx, db ny)
{
    db res = 0;
    for (ll i = 0; i < n; ++i)
    {
        db dx = nx - x[i], dy = ny - y[i];
        res += sqrt(dx * dx + dy * dy) * w[i];
    }
    return res;
}
void sa()
{
    db t = 3000, d; //t=10000也行
    while (t > 1e-15)
    {
        nox = mxx + (rand() * 2 - RAND_MAX) * t;
        noy = mxy + (rand() * 2 - RAND_MAX) * t;
        noe = e(nox, noy);
        d = noe - mxe;
        if (d < 0 || exp(-d / t) * RAND_MAX > rand())
        {
            mxx = nox, mxy = noy;
            if (d < 0)
            {
                mxe = noe;
            }
        }
        t *= k;
    }
}
signed main()
{
    sc(n);
    for (ll i = 0; i < n; ++i)
    {
        sc(x[i]), sc(y[i]), sc(w[i]);
        xs += x[i], ys += y[i];
    } 
    //竟然是死在了1.0上……
    mxx = 1.0 * xs / n, mxy = 1.0 * ys / n, mxe = e(mxx, mxy); //事实上是mi
    for (ll i = 0; i < 1; ++i) //多跑几次也行
    {
        sa();
    }
    printf("%.3lf %.3lf", mxx, mxy);
    return 0;
}
```

附：正常解法是每次沿合力方向走，走到精度够为止，逐渐减少步长：

```c++
#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define E(x) ((x)*(x))
const int N=1009;
int n,px[N],py[N],pw[N];
double x,y,lon=10000.0;//初始移动长度
void move(double l){
	double sx=0,sy=0,g;
	for(int i=1;i<=n;i++){//将绳结上的力正交分解，横向的加给sx，纵向加给sy
		g=sqrt(E(px[i]-x)+E(py[i]-y));
		if(g==0)continue;
		sx+=pw[i]/g*(px[i]-x);
		sy+=pw[i]/g*(py[i]-y);
	}
	g=sqrt(sx*sx+sy*sy);//算出合力大小
	x+=l/g*sx,y+=l/g*sy;//向合力方向移动l
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&px[i],&py[i],&pw[i]);
	while(lon>4e-4)
		move(lon),lon*=0.618;//lon乘多少随你定，不是太小都能过
	printf("%.3f %.3f\n",x,y),exit(0);
}
```



###### 球形空间产生器

> 给定$n(1\le n\le10)$维空间的$n+1$个点，求这些点确定的球心。数值绝对值不超过$2\times10^4$。答案保留小数点后三位。

爬山算法参考做法(参数特别难调)：

```c++
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define maxn 12
int n;
struct Point {
	double x[maxn], w;
	inline friend Point operator + (const Point &lhs, const Point &rhs) {
		Point res;
		for (register int i = 0; i < n; i++) res.x[i] = lhs.x[i] + rhs.x[i];
		return res;
	}
	inline friend Point operator - (const Point &lhs, const Point &rhs) {
		Point res;
		for (register int i = 0; i < n; i++) res.x[i] = lhs.x[i] - rhs.x[i];
		return res;
	}
	inline void operator /= (const int &rhs) {
		for (register int i = 0; i < n; i++) x[i] /= rhs;
	}
} s[maxn], ans;

inline double sqr(double x) {return x * x;}
inline double abs(const Point &O) {
	double res = 0;
	for (int i = 0; i < n; i++) res += sqr(O.x[i]);
	return sqrt(res);
}
inline double dis(Point O) {
	double res = 0;
	for (int i = 0; i <= n; i++) res += abs(O - s[i]);
	return res;
}

const double ST = 5000, delT = 0.99995, eps = 1e-5;
const int Tim = 1, __Tim = 250000;
double V[maxn];
void SA() {
	double T = ST;
	while (T > eps) {
		double sum = dis(ans) / (n + 1);
		for (int i = 0; i < n; i++) {
			V[i] = 0;
			for (int j = 0; j <= n; j++) {
				V[i] += (abs(ans - s[j]) - sum) * (s[j].x[i] - ans.x[i]);
			}
			V[i] /= n + 1;
		}
		for (int i = 0; i < n; i++) {
			ans.x[i] += T * V[i];
		}
		T *= delT;
	}
	for (int Tim = 0; Tim < __Tim && 1. * clock() / CLOCKS_PER_SEC < .9; Tim++) {
		double sum = dis(ans) / (n + 1);
		for (int i = 0; i < n; i++) {
			V[i] = 0;
			for (int j = 0; j <= n; j++) {
				V[i] += (abs(ans - s[j]) - sum) * (s[j].x[i] - ans.x[i]);
			}
			V[i] /= n + 1;
		}
		for (int i = 0; i < n; i++) {
			ans.x[i] += T * V[i];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) scanf("%lf", s[i].x + j);
		ans = ans + s[i];
	}
	ans /= n + 1;
	for (int i = 0; i < Tim; i++) SA();
	for (int i = 0; i < n; i++) {
		 printf("%.3lf", ans.x[i]);
		 putchar(i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
```

正解：高斯消元

对方程两两作差，可以消掉方程的未知数$r$和未知项$x_1^2+\cdots x_n^2$，接下来直接套板子即可。

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 15
db p[mn][mn], a[mn][mn];
ll n;
void gauss()
{
    for (ll i = 1; i <= n; ++i)
    {
        ll mx = i;
        for (ll j = i + 1; j <= n; ++j)
            if (abs(a[j][i] > a[mx][i]))
                mx = j;
        swap(a[i], a[mx]);
        for (ll j = 1; j <= n; ++j)
            if (j != i)
            {
                db v = a[j][i] / a[i][i];
                for (ll k = i + 1; k <= n + 1; ++k)
                    a[j][k] -= a[i][k] * v;
            }
    }
}
signed main()
{
    sc(n);
    for (ll i = 1; i <= n + 1; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            scanf("%lf", &p[i][j]);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            a[i][j] += 2 * (p[i][j] - p[i + 1][j]);
            a[i][n + 1] += p[i][j] * p[i][j] - p[i + 1][j] * p[i + 1][j];
        } //注意不是-=
    }
    gauss();
    for (ll i = 1; i <= n; ++i)
    {
        printf("%.3lf ", a[i][n + 1] / a[i][i]);
    }
    return 0;
}
```



###### 均分数据

> 有$n$个数，分成$m$组，组内求和得到$m$个新数，对新数求方差。求最小方差。$m\le n\le20, 2\le m\le6,1\le a\le50$

首先假设分组是顺序连续的，朴素的求解方法是区间DP：

设$dp[i][j]$表示前$i$个数分$j$组的最小方差。初始状态$dp[0][0]=0$，

转移方程是$dp[i][j]=dp[k][j-1]+std[k]$，表示从$k$截断，$1$到$k$分前$j-1$组，$k$到$i$分第$j$组，$std[k]$是新分组的方差，使用前缀和化简，可以在$\Omicron(1)$求出方差：$\sum_{x=k+1}^i(v[x]-\overline{v})^2=(s[i]-s[k]-\overline{v})^2$，这个公式证明待定(总觉得不是很对，可能是近似公式？)。

还有一种方法是贪心，每次把新的数放到当下最小的组内，从而让每一组趋于平衡。用临值交换法可以证明放到最小是唯一的选择。具体证明待补充。

事实上分组并不顺序，这时候可以用模拟退火(或随便什么随机方法)打乱顺序，然后将打乱后的交给上面的办法处理。

贪心参考代码如下：

```c++
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
#define il inline
typedef double db;
il ll read()
{
    re char p = 0;
    re ll r = 0, o = 0;
    for (; p < '0' || p > '9'; o |= p == '-', p = getchar())
        ;
    for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar())
        ;
    return o ? (~r) + 1 : r;
}
#define sc(x) x = read()
#define mn 26
ll n, m;
db v[mn], s[mn], mie, noe, avg, miv[mn];
db e()
{
    memset(s, 0, sizeof s);
    for (ll i = 1; i <= n; ++i)
    {
        ll p = min_element(s + 1, s + 1 + m) - s;
        s[p] += v[i];
    }
    db res = 0;
    for (ll i = 1; i <= m; ++i)
    {
        res += (s[i] - avg) * (s[i] - avg);
    }
    return sqrt(res / m); //这个破玩意不能化简……
}
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= n; ++i)
    {
        sc(v[i]);
        avg += v[i];
        miv[i] = v[i]; //多次SA时，SA初始值不一样，不都是v
    }
    avg /= m, mie = e();
    for (ll h = 0; h < 32; ++h)
    {
        noe = mie;
        for (ll i = 1; i <= n; ++i)
        {
            v[i] = miv[i];
        }
        for (db t = 1e5, nwe, d; t >= 1e-14; t *= 0.97)
        {
            ll x = rand() % n + 1, y = rand() % n + 1;
            while (y == x)
            {
                y = rand() % n + 1;
            }
            swap(v[x], v[y]); //新状态
            nwe = e(), d = nwe - noe;
            if (nwe < mie)
            {
                mie = nwe;
                for (ll i = 1; i <= n; ++i)
                {
                    miv[i] = v[i];
                }
            }
            if (d < 0 || d / t * RAND_MAX < rand())
            {
                noe = nwe;
            }
            else
            {
                swap(v[x], v[y]); //不接受新状态，转回去
            }
        }
    }
    printf("%.2lf", mie);
    return 0;
}
```

DP参考代码如下：

```c++
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define ll long long
#define re register
#define il inline
#define pf(x) ((x)*(x))
#define fp(i,a,b) for(re int i=a;i<=b;i++)
#define fq(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
const int N=50;
int n,m,a[N],s[N];
double ans=1e100,f[N][N],ysn;
il int gi()
{
  re int x=0,t=1;
  re char ch=getchar();
  while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if(ch=='-') t=-1,ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
  return x*t;
}
il double work()
{
  memset(f,127,sizeof(f));
  fp(i,1,n) s[i]=s[i-1]+a[i];//注意到数列不固定，因此不能预处理
  f[0][0]=0;
  fp(i,1,n)
    fp(j,1,i)
    fp(k,0,i-1)
    f[i][j]=min(f[i][j],f[k][j-1]+pf(s[i]-s[k]-ysn));
  ans=min(ans,f[n][m]);
  return f[n][m];
}//DP处理rand出的序列
il double Rand(){return rand()%100000/100000.00;}
il void SA(re double T)
{
  double now=ans;
  while(T>1e-3)
    {
      re int x=rand()%n+1,y=rand()%n+1;
      if(x==y) continue;
      swap(a[x],a[y]);//rand出新序列
      re double  nw=work();
      if(nw<now||exp(now-nw)/T>Rand()) now=nw;//一定概率接受当前状态
      else swap(a[x],a[y]);
      T*=0.99;
    }
  fp(i,1,10000)
    {
      re int x=rand()%n+1,y=rand()%n+1;
      if(x==y) continue;
      swap(a[x],a[y]);work();swap(a[x],a[y]);
    }
}
il double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main()
{
  srand(19260817);
  n=gi();m=gi();
  fp(i,1,n) a[i]=gi();
  fp(i,1,n) ysn+=1.0*a[i]/m;
  work();
  while(Time()<0.75)//通过增加rand的次数保证正确性
    SA(10000);
  printf("%.2lf\n",sqrt(ans/m));
  return 0;
}
```

附：
$$
\sigma=\sqrt{\sum_{i=1}^n\ (x_i-\bar{x})^2 \over n}\quad\bar{x}={\sum_{i=1}^n\ x_i \over n}
$$

$$
\Rightarrow n\sigma^2=\sum_{i=1}^n\ (x_i-\bar{x})^2=\sum_{i=1}^nx_i^2+n\bar{x}^2-2\bar{x}\sum_{i=1}^nx_i
$$

其中$\bar{x}$必然是定值，且$\sum_{i=1}^nx_i$是定值(输入的数和)，所以需要让$\sum_{i=1}^nx_i^2$最小，即让拆分出来的值的平方和最小，可以推测应当让$x$最小。



#### 正确性证明

##### 例题

###### 2D Geometry

> (oj)平面上由$n$个不重合的点。如果三点构成三角形，可以删掉这三点。求最后最少会剩下多少个点。$1\le n,\sum n\le20\times 10^5,0\le x,y\le10^9$
>
> 有多组样例。

设斜率相同的点数最大是$cols$，可以删掉$tri$个三角形，答案是$n-3tri$。斜率不为$cols$的点有$n-cols$个，它们都可以跟在$cols$的点构成三角形，最多构成$n-cols$个。而三角形不能超过$\lfloor\dfrac n3\rfloor$个。要让$tri$通过$cols$产生，必须有$n-cols\ge\lfloor\dfrac n3\rfloor\approx\dfrac n3$，即$cols\ge\dfrac{2n}3$。否则答案一定是$tri=\lfloor\dfrac n3\rfloor$。

任取两个不重合的点组成直线，这条直线斜率与$cols$代表斜率一致的概率约为$\dfrac49$，那么不在$cols$的概率是$\dfrac59$，如果连续取很多次(以$20$为例)，都没取到$cols$的概率为$(\dfrac59)^{20}\approx8\times10^{-6}$。所以随机化算法有$1-8\times10^{-6}$的概率计算出正确答案。

代码如下：

```c++
#define mn 200010
ll n, x[mn], y[mn], tri, cols, a, b, cnt;
il ll cross(ll ax, ll ay, ll bx, ll by)
{
    return ax * by - ay * bx;
}
signed main()
{
    while (EOF != scanf("%lld", &n))
    {
        for (ll i = 0; i < n; ++i)
        {
            sc(x[i]), sc(y[i]);
        }
        tri = cols = 0;
        for (ll h = 0; n > 1 && h < 20; ++h)
        {
            do
            {
                a = rand() % n, b = rand() % n;
            } while (a == b); //任选两个点
            cnt = 0;
            for (ll i = 0; i < n; ++i) //选第三个点，判断是否跟其共线
            {
                cnt += (cross(x[i] - x[a], y[i] - y[a], x[i] - x[b], y[i] - y[b]) == 0);
                //cols+=暴毙一次
            }
            cols = max(cols, cnt); //最大共线组
            // printf("<%lld\n", cnt);
        }
        //最大共线组外有n-cols个三角形，它们可以跟最大共线组组成三角形，最多组成n-cols个；而本身最多可能会有n/3个三角形
        tri = min(n / 3, n - cols);
        printf("%lld\n", n - 3 * tri);
    }
    return 0;
}
```





#### 举例

> 两个地点之中的一个有价值为$x$的宝藏，每天降低价值$y$，可以花费$4y$解读地图获得正确位置；或花费$3y$请求帮助解读地图。前往寻宝需要花费$5y$。求最优方案。$x>9y$

显然不选$4y$，选$3y$时，价值为$x-8y$。然而用随机算法：不解读直接随便选一个地点，平均价值为$x-\dfrac{5y+10y}2=x-7.5y$，更优。



### 滑动窗口

含快慢指针

##### 例题

###### 逛画展

> 长为n的序列，数字范围1-m，求最短闭区间[a,b]，区间内含有1~m，若多解，输出a最小的解。

个人实现版本

```c++
#include <bits/stdc++.h>
#pragma warning(disable:6031)
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define MAXN 1000002
#define MAXM 2002
#define BIG 0x7fffffff
ll s[MAXN], n, m, anslen = BIG, a = BIG, b, lf, dlen, tlen;
bool ban;
unordered_map<ll, ll> dict;
signed main()
{
	scanf("%d%d", &n, &m);
	a = lf = 1;
	rep(i, 1, n)
	{
		scanf("%d", &s[i]);
		ban = false;
		if (dlen < m)
		{
			if (dict.find(s[i]) == dict.end()) ++dlen;
			++dict[s[i]];
			ban = true;
		}
		if (dlen >= m)
		{
			if(!ban) ++dict[s[i]];//注意这里，不能重复计算
			while (dict[s[lf]] > 1)
			{
				--dict[s[lf]];
				++lf;
			}
			tlen = i - lf + 1;
			if (tlen < anslen || tlen == anslen && lf < a)
			{
				anslen = tlen;
				a = lf;
				b = i;
			}
		}
	}
	printf("%d %d", a, b);
	return 0;
}
```

###### Diamond Collector S

> 有n个钻石，两个窗口，每个窗口内钻石极差(不是旁差)必须小于k，求两窗口最多可放多少钻石

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 50002
ll n, k, a[MAXN], c[MAXN], rf, mxi, ans;
signed main()
{
	scanf("%d%d", &n, &k);
	a[n + 1] = 0x7fffffff;
	repe(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	repe(lf, 1, n)
	{
		while (a[rf] <= a[lf] + k) ++rf;//计算[lf,rf)最多放多少
		c[rf] = max(c[rf], rf - lf);//(?,rf)最多可以放多少个
		mxi = max(mxi, c[lf]);//[1,lf)最多可以放多少
		ans = max(ans, mxi + rf - lf);//[1,lf)+[lf,rf)
	}
	printf("%d", ans);
	return 0;
}
```

###### 求距离

> (oj)$n$人一圈，给出每人顺时针举例下一个人距离，求两个人间距离(定义为顺着走和逆着走的最小值)的最大值。$1\le n\le10^5,1\le d_i\le10^9$

三分法暂时无法证明正确性。全源最短路显然超时。使用快慢指针。

可以证明固定的圈长下，距离的最大值不会超过圈长的一半，这很显然。

所以可以先从左自己到右自己枚举，然后右不断往右拓展，直到顺距离大于半圈长，那么这个时候距离一定达到了最大，因为接下来很显然距离会递减。所以此时左边往前，即开始枚举下一个人，且起始右就是当前右，由此实现了优化。直到顺距离小于半圈长，继续拓展右边。代码如下：

```c++
#define mn 100010
ll n, a[mn], cnt, cnt2, lf, rf, ans, lr;
signed main()
{
    sc(n);
    for (ll i = 1; i <= n; ++i)
        sc(a[i]), cnt += a[i];
    cnt2 = cnt >> 1;
    while (lf <= n)
    {
        ans = max(ans, min(lr, cnt - lr));
        lr += a[rf];
        rf = 1 + rf % n;
        while (lr > cnt2)
            lr -= a[lf++];
    }
    printf("%lld", ans);
    return 0;
}
```



##### 举例

###### 链表移动

> 将单链表每个元素右移$k$个位置，时间复杂度$\Omicron(n)$

找到倒数第$k$个节点的前一个节点，让这个节点指空，本来的尾指头，这个节点下一个节点为头结点。可以用快慢指针(时间复杂度上跟纯模拟没啥差别)：

快指针先提前移动$k$，然后双指针都同时移动等速，当快指针的下一个指向null时结束移动，慢指针指向倒数第$k$个节点的前一个节点。



### 生成

不需要先计算出全部值而是每次需要时计算下一个值，类似于闭包的思维。

#### 例题

##### 第几个幸运数

> (蓝桥)把含3,5,7的因子的数$3,5,7,9\dots$升序排序，求59084709587505是第几个

时间复杂度为$\Omicron(\log_3n\cdot\log_5n\cdot\log_7n)$，暴力可以通过。

###### 暴力

在三个对数最大值之内枚举所有数，小于目标值的都计数，那么积累值就是答案。由于数值庞大，使用整数前提下，不开高精度的话，\_\_int128也会炸，建议使用python。但是如果使用double，不会爆。

在代码中，由于包含多余项：$3^0*5^0*7^0=1$，所以最后print的cnt无需+1

```python
cnt=0
tg=59084709587505
from math import ceil,log
for i in range(0,ceil(log(tg,3))+1):
    for j in range(0,ceil(log(tg,5))+1):
        for k in range(0,ceil(log(tg,7))+1):
            if 3**i*5**j*7**k<tg:
                cnt+=1
print(cnt)
```

另一种暴力的思维是同样枚举这么多数，然后对枚举出来的$29\cdot20\cdot17$个数排序，求目标数的下标。

###### 优先级队列

(个人解法)使用生成器思维。

```c++
#include <bits/stdc++.h>
using namespace std;
#define ed 59084709587505
//#define ed 49
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> > q;
set<ll> s;
ll cnt,p[]={3,5,7};
signed main()
{
    q.push(3),q.push(5),q.push(7); s.insert(3),s.insert(5),s.insert(7);
    while(1)
    {
        ll v=q.top(),t; q.pop();
        ++cnt;
        if(v==ed) break;
        for(int i=0;i<3;++i)
        {
            t=v*p[i];
            if(s.find(t)==s.end())
            {
                s.insert(t);
                q.push(t);
            }
        }
    }
    return printf("%lld",cnt)&0;
}
```

##### 阅兵方阵

> (蓝桥)阅兵队伍应当恰好能组成两个方阵为一种队形；求有$12$种队形的最小队伍人数。例如$130$有$2$种队形，为平方数$81+49$或$121+9$。

###### 暴力

网传解法基本都是这一类解法，十分玄学且不可靠：

```python
s=list(i**2 for i in range(1,1000))

t=[]
for i in range(len(s)):
    for j in range(i,len(s)):
        t.append(s[i]+s[j])
#print(len(t))
t.sort()
from collections import Counter

s2=Counter(t).most_common(80)
for i in range(80):
    if s2[i][1]==12:
        print(s2[i][0])
        break
```



###### 优先级队列

(个人解法)生成器思维，每次生成一个平方和，并保留其两个基，如果没有重复过，那么记录到哈希表内，并且把基组合记录在哈希集合内，如果两个基相等，下一次只往下生成一个新值，否则生成两个，并且维护第一个值小于等于第二个值，代码如下：

```c++
unordered_map<ll,ll> um;
unordered_set<string> us;
struct node
{
    ll x, y, v;
    il bool operator < (const node& p) {return v<p.v; }
};
queue<node> q;
string t;
void tos(ll x, ll y)
{
    t="";
    do
    {
        t+='0'+(char)(x%10);
        x/=10;
    }while(x);
    t+='|';
    do
    {
        t+='0'+(char)(y%10);
        y/=10;
    }while(y);
}
signed main()//160225
{
    q.push({1,1,2});
    while(!q.empty())
    {
        node p=q.front(); q.pop(); tos(p.x,p.y);
        if(us.find(t)!=us.end()) continue;
        us.insert(t);
        ++um[p.v];
        if(um[p.v]==12) return printf("%lld",p.v),0;
        if(p.x==p.y) q.push({p.x,p.x+1,p.x*p.x+(p.x+1)*(p.x+1)});
        else
        {
            q.push({p.x+1,p.y,p.y*p.y+(p.x+1)*(p.x+1)});
            q.push({p.x,p.y+1,p.x*p.x+(p.y+1)*(p.y+1)});
        }
    }
    return 0;
}
```



##### 最小函数值

> 有n个二次函数数列$A_ix^2+B_ix+C_i$，系数均大于0，求所有数列值中最小的m个(不去重)

###### 朴素

(个人做法)可以用极值点处左右拓展的方法，每次循环每个函数拓展一次，直到新的值均不是前m小；剪枝优化，让新的值大于前m的函数排除。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
struct node { ll i, v; };
inline bool operator>(const node& x, const node& y) { return x.v > y.v; }
priority_queue<node, vector<node>, greater<node>> q;
ll a[MAXN], b[MAXN], c[MAXN], n, m, t[MAXN], i;
inline ll f(ll i, ll v) { return a[i] * v * v + b[i] * v + c[i]; }
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, n)
	{
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		q.push({ i,f(i, t[i] = 1) });
	}
	while (m--)
	{
		printf("%lld ", q.top().v);
		i = q.top().i;
		q.pop();
		q.push({ i, f(i, ++t[i]) });
	}
	return 0;
}
```

###### 优化

首先必须明确，所有数列是单调递增的，即1是最小值。所以可以让数列本身存最小堆，每次取堆顶，然后将下一项入堆。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10002
vector<ll> q;
ll a[MAXN], b[MAXN], c[MAXN], n, m, mx, ub, lf, rf, lv, rv, rlen, dmx;
ll hilen, pos;
bool ban[MAXN];
double cf[MAXN];
signed main()
{
	scanf("%lld%lld", &n, &m);
	repe(i, 1, n)
	{
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		cf[i] = max(0., (double)-b[i] / (a[i] << 1));
	}
	for (ll dx = 0; 1; ++dx)
	{
		if (!rlen) dmx = 0;
		else if (rlen <= m) dmx = q[rlen - 1];
		else dmx = q[m - 1];
		hilen = 0;
		repe(i, 1, n)
		{
			if (ban[i]) continue;
			lf = floor(cf[i] - dx);
			rf = ceil(cf[i] + dx);
			if (rf <= 0) continue;
			if (lf > 0)
			{
				lv = a[i] * lf * lf + b[i] * lf + c[i];
				++rlen;
				if (lv < dmx) ++hilen;
				if (rlen > m && lv >= dmx) ban[i] = true;
				mx = max(mx, lv);
				q.insert(upper_bound(q.begin(), q.end(), lv), lv);
			}
			if (lf == rf) continue;
			rv = a[i] * rf * rf + b[i] * rf + c[i];
			++rlen;
			if (rv < dmx) ++hilen;
			if (rlen > m && rv >= dmx) ban[i] = true;
			mx = max(mx, rv);
			q.insert(upper_bound(q.begin(), q.end(), rv), rv);
		}
		if (rlen > m && !hilen) break;
	}
	rep(i, 0, m) printf("%lld ", q[i]);
	return 0;
}
```

##### 序列合并

> 有两个长为n的单调不减小序列，它们两两相加可以得到$n^2$的值，求前n小的值。

注意到不需要去重。设n个生成器f(x)=a(i)+b(x)，显然生成器单调递增；然后构建生成器最小堆即可。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 100002
ll a[MAXN], b[MAXN], n, t[MAXN], i;
struct node { ll i, v; };
inline ll operator>(const node& x, const node& y) { return x.v > y.v; }
priority_queue<node, vector<node>, greater<node>> q;
signed main()
{
	scanf("%lld", &n);
	repe(i, 1, n) scanf("%lld", &a[i]);
	repe(i, 1, n) scanf("%lld", &b[i]);
	repe(i, 1, n) q.push({ i,a[i] + (b[t[i] = 1]) });
	repe(h, 1, n)
	{
		printf("%lld ", q.top().v);
		i = q.top().i;
		q.pop();
		q.push({ i, a[i] + b[++t[i]] });
	}
	return 0;
}
```

### 思维

#### 规律型

##### XOR

> (scnuoj)有$n$个数，求有多少对数异或后$1$的个数是奇数。$1\le n\le10^5,1\le a\le10^9$

设$a,b$有$x,y$个$1$，如果$x,y$都是奇数或偶数，那么$x+y$必然是偶数。在异或过程中，每次能且仅能消除偶数个$1$，所以最后结果一定是偶数；同理一奇一偶必然是奇数。根据计数原理，最后的答案为奇数个$1$的数数目乘以偶数个$1$的数数目。

#### 转化型

##### 反复横跳

> (scnuicpc-pre1 1)一开始$A,B$相距$X$米，以$a,b$的速度分别相向移动，$C$位于中间位置，以$c$的速度走向$A$，相遇后以相同速度走向$B$，如此循环直到$A,B$相遇，求$C$走的路程和时间。$t\le 10^5, x,a,b,c \in int$

时间为$\frac{X}{a+b}$，距离为$\frac{cX}{a+b}$。

#### 奇偶型

### 构造

#### 例题

##### mine sweeper II

> (icpc45上海)扫雷游戏，X表示雷，.表示无雷区，每个无雷区上面有一个数字，记录该位置处周围8个位置有多少个雷。现在给出A矩阵雷区和B矩阵雷区，它们无雷区数字之和为suma,sumb，要求(int)(n\*m/2)次将B矩阵雷区变化成sumb=suma

需要找到两个规律：

- B一定可以在规定次数内变换成A或A的逆(雷区和无雷互换)(显然)
- 一个扫雷矩形和它的逆矩形的数字之和相等(证明见下)

综上，只需要判定B换成A还是A的逆即可。

```c
sc(n),sc(m);
rep(i,0,n) scanf("%s",a[i]); rep(i,0,n) scanf("%s",b[i]);
rep(i,0,n) rep(j,0,m) c+=(a[i][j]!=b[i][j]);
if(c>n*m/2) rep(i,0,n) rep(j,0,m) a[i][j]=(a[i][j]=='.'?'X':'.');
rep(i,0,n) printf("%s\n",a[i]);
```

对雷区建图，每个点与周围八格连边；对于无雷区点，定义点权是其连接了多少个雷区，有雷区点相反。可以发现每一条连接一个雷区点和一个无雷区点的边一定会让一个无雷区点的点权和一个雷区点的点权加一，其他边不受影响；所以它们的和是相等的，这个结论可以推广到一般的图上。

### 计数

#### 图计数

##### Autobiography

> (第六届中国大学生程序设计竞赛总决赛)简单(无自环重边)无向图，点有`b,o`两种类型。选择四个不同的点`u,v,w,x`，使得`u,v;v,w;w,x`连了边，且它们的类型分别为`b,o,b,o`。求这样的四元组个数。
>
> $4\le n\le2\times10^5,0\le m\le2\times 10^5$

枚举边`v,w`，同理`v`连了`x`多少个`b`，`w`连了`y`多少个`x`，那么这条边贡献的答案为$(x-1)(y-1)$。

```c++
#define mn 200010
struct edge
{
    ll to, nx;
} e[mn << 1];
ll n, m, hd[mn], cnt, ots[mn], u, v, res;
void adde(ll &u, ll &v)
{
    e[++cnt] = {v, hd[u]};
    hd[u] = cnt;
}
char c[mn];
signed main()
{
    while (EOF != scanf("%lld%lld", &n, &m))
    {
        scanf("%s", c + 1), res = cnt = 0;
        memset(hd, 0, sizeof hd), memset(ots, 0, sizeof ots);
        for (ll i = 1; i <= m; ++i)
        {
            sc(u), sc(v);
            if (c[u] != c[v])
                ++ots[u], ++ots[v];
            adde(u, v), adde(v, u);
        }
        for (u = 1; u <= n; ++u)
        {
            if (c[u] != 'b')
                continue;
            for (ll i = hd[u]; i; i = e[i].nx)
            {
                v = e[i].to;
                if (c[v] != 'o')
                    continue;
                res += (ots[u] - 1) * (ots[v] - 1);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
```

#### 组合计数

##### Fake Math Problem

> (gdcpc)求$\sum_{i=0}^n\sum_{j=0}^{a_i}P(i,j)\mod998241383$
>
> $T\le 3,1\le n\le10^5,0\le a_i\le i$

注意到$998241383=673\times937\times1583$，所以连续枚举至多$1583$次就会变$0$。时间复杂度是$\Omicron(1573Tn)$。因为连续计算$P(i,j)$是可以直接递推的，所以计算一排排列数的时间复杂度是$\Omicron(1573)$。

本题的关键在于模数是$998241383$而不是$998244353$。

```c++
#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef double db;
#define sc(x) scanf("%lld", &x)
#define il inline
#define mn 100010
#define mod 998241383
ll n, a[mn], t, ans, cnt;
signed main()
{
    for (sc(t); t; --t)
    {
        sc(n), ans = 0;
        for (ll i = 0; i <= n; ++i)
        {
            sc(a[i]);
            ++ans, cnt = 1; //P(i,0)=1
            for (ll j = 1; j <= a[i] && cnt; ++j)
                cnt = cnt * (i - j + 1) % mod, ans += cnt;
            ans %= mod;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
```







### 康托展开

> 如果复杂度允许，用next/prev_permutation更方便

cantor

将排列与第几个排列-1相互转化

公式为：(i不是下标，是序数)
$$
\sum_{i=1}^n(小于a_i且a_i前未出现的数的数目)\cdot(n-1)!
$$
例如：24513前有$1\cdot(4!)+2\cdot(3!)+2\cdot(2!)+0+0=40$个排列，故24513是12345的第41个排列。

##### 实现

使用树状数组优化，复杂度为$O(nlogn)$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define MAXN 10000002
#define MOD 998244353
ll a, c[MAXN], f[MAXN], ans, v, n, lb[MAXN], k;
inline ll sum(ll p)
{
	ll res = 0;
	while (p) res += c[p], p -= lb[p];
	return res;
}
inline void add(ll x, ll&& k)
{
	while (x <= n) c[x] += k, x += lb[x];
}
signed main()
{
	scanf("%lld", &n);
	f[0] = 1;
	repe(i, 1, n) f[i] = f[i - 1] * i % MOD;
	repe(i, 1, n) lb[i] = i & -i;
	repe(i, 1, n) add(i, 1);
	repe(i, 1, n)
	{
		scanf("%lld", &a);
		(ans += (sum(a) - 1) * f[n - i] % MOD) %= MOD;
		add(a, -1);
	}
	printf("%lld", (++ans)%MOD);
	return 0;
}
```

#### 逆康托展开

incantor

以求12345的第41个排列为例：
$$
\begin{align}
40&=1\cdot(4!)+16\quad&有1个数1比1^{st}小，即1^{st}=2\\
16&=2\cdot(3!)+4\quad&有2个数1,3比2^{nd}小，即2^{nd}=4\\
4&=2\cdot(2!)+0\quad&有2个数1,3比3^{rd}小，即3^{rd}=5\\
0&=0\cdot(1!)+0\quad&有0个数比4^{th}小，即4^{th}=1\\
0&=0\cdot(0!)+0\quad&有0个数比5^{th}小，即5^{th}=3
\end{align}
$$
示例：求出某个排列的康托展开并求其上一个逆康托展开。

```c++
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,f[11],a[11];
char ka[11];
vector<int>v;

inline int cantor()
{
	int ret=0,x;
	for(int i=0; i<n; ++i) {
		x=0;
		for(int j=i+1; j<n; ++j)
		if( (ka[i]-ka[j])>0 ) x++;
		ret+=x*f[n-i-1];
	}
	return ret;
}

inline void incantor(int k)
{
	int x;
	while( !v.empty() ) v.erase(v.end());
	for(int i=1; i<=n; ++i) v.push_back(i);
	for(int i=1; i<n; ++i) {
		a[i]=v[(x=k/f[n-i])];
		v.erase(v.begin()+x);
		k%=f[n-i];
	}
	a[n]=v[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; ++i) cin>>ka[i];
	f[1]=1;
	for(int i=2; i<=10; ++i) f[i]=f[i-1]*i;
	incantor(cantor()-1);
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	return 0;
}
```



### 时间日期

#### 闰年

定义：普通闰年：公历年份为4的倍数，不为100的倍数

实际闰年：400的倍数；两者合起来为闰年，二月多一天

相对概念为平年

```c
leap = year % 4 == 0 && year%100 || year%400 == 0
```

### 浮点运算后整数

浮点数的运算和函数有误差，可以采用如下方法：

``````c
floor(n + 0.5) == expect;//n为float
``````

### 浮点比较

```c
const double EPS = 1e-6;
if(fabs(a-b) < EPS) printf("Good!\n");
```

fabs是math.h的取绝对值

### 数组最值

以最大值为例

```c
//算法1
int max,i;
max = a[0];
for(i=1;i<n;i++)
    if(a[i]>max)
        max=a[i];
return max;
```

### 例题

#### 求最大利益

2<=n<=2e5,1<=Ri<=1e9,求Rj-Ri最大值(j>i)

算法一：简单遍历(for j in range(1,n), for i in range(j) max=if else)时间复杂度为O(n^2)，由理论知，明显超时。

算法二：复杂度O(n)

```c++
#include <iostream>
#include <algorithm>
using namespace std;
//static const int MAX = 200000;
int main()
{
    int n, Ri;//int R[MAX];不使用数组，节省空间复杂度
    cin>>n;
    //for(int i=0;i<n;i++) cin>>R[i];
    int maxv = -2000000000;
    int minv; //注意这两个初始化值的设置方法和i初始
    cin>>minv;
    for(int i=1;i<n;i++)
    {
        cin>>Ri;
        maxv = max(maxv, Ri - minv);
        minv = min(minv, Ri);
    }
    cout<<maxv<<endl;
}
```

