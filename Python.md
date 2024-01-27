> 此为第二版python3学习笔记，在第一版的基础上删减了大部分过于基础的内容，删除了大量图片实例，取之以代码。
>
> <p align="right">——蒟蒻lr580</p>
>
> 2021/2/27 开始编写第二版python笔记

# 语法

## 初始

### 安装/使用python

python3.4是最后支持window XP的版本。不要安装最新的版本，往往会出现bugs，安装一个小版本号，如3.9是最新，安装3.8的稳定版。

必须勾选add python.exe to Path，否则重装，如下图：

<img src="img/image-20210227194041109.png" alt="image-20210227194041109" />

使用略。

### 测试

查看版本：

```python
python --version
```

代码查看：

```python
import platform
print(platform.python_version()) #'3.10.6'
```

查看安装路径

```shell
py -0p
```

```python
import sys
sys.executable # '...\\Python310\\pythonw.exe' 绝对路径
```



### 第三方库

> linux 无 pip：(gpt)
>
> ```sh
> yum update
> yum install epel-release
> yum install python-pip
> pip --version
> ```

打开cmd，输入如下指令：

```bash
pip install 第三方库名
```

如：

```bash
pip install requests-html
pip install plotly pandas # 一次装两个
```

> 注意到 debian 如果报错 `error: externally-managed-environment`，考虑 apt 装包，如装 `pymysql`：
>
> ```sh
> apt-get install python3-pymysql
> ```

可以加上调用国内镜像的选项，加快下载速度：

```bash
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pyspider
```

其他镜像：

> 清华：https://pypi.tuna.tsinghua.edu.cn/simple
>
> 阿里云：http://mirrors.aliyun.com/pypi/simple/
>
> 中国科技大学 https://pypi.mirrors.ustc.edu.cn/simple/
>
> 华中理工大学：http://pypi.hustunique.com/
>
> 山东理工大学：http://pypi.sdutlinux.org/ 
>
> 豆瓣：http://pypi.douban.com/simple/
>
> 如果http不行换https

可以在用户目录下创建pip目录，创新文件pip.ini，输入如下内容：

```ini
[global]
index-url = https://pypi.tuna.tsinghua.edu.cn/simple
[install]
trusted-host=mirrors.aliyun.com
```

> 或者可以：
>
> ```bash
> pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
> ```
>
> 需要取消时，可以：
>
> ```bash
> pip config unset global.index-url
> ```



将 python 安装的包移出 C盘：

输入 `python -m site` 查看当前安装目录

输入 `python -m site -help` 查看当前该程序目录，点进去，修改两个变量 `USER_SITE, USER_BASE` 为所想要的路径，如：

```python
USER_SITE = 'D:\\Program Files\\Python37\\lib\\site-packages'
USER_BASE = 'D:\\Program Files\\Python37\\Scripts'
```

> 已有的包直接强行剪切出去貌似不是一个好主意



卸载库指令：

```bash
pip uninstall 库名
```

更新指令：

```bash
pip install 库名 --upgrade
```

> 注意，安装失败的原因非常多，根据库的不同详情百度

可以安装下载好的库文件而不是在线下载，文件后缀名是whl，命令同上



可以使用下面指令获取当前机子装了的全部包：

```bash
pip freeze > requirements.txt
```

先用 `pip` 安装 `pipreqs` ，然后使用：(可以直接 `pipreqs ./`)

```bash
pipreqs ./ --encoding utf8
```

或

```bash
pipreqs ./ --encoding=utf8
```

那么导出的 `requirements.txt` 可以用下面指令批量安装：

```bash
pip install -r requirement.txt
```

> 如果里面任意一项输入不正确，如版本找不到，全部都不会安装，不会弹 error 直接结束。





### 编译

python是解释性语言，但是也可以编译成exe

首先使用cmd打开python安装路径，打开scripts文件夹

#### 初始化

输入指令，安装PyInstaller.exe

```cmd
pip.exe install PyInstaller
```

如果要卸载

```cmd
pip.exe remove PyInstaller
```

#### 常规使用

将要编译的文件(单一.py文件)放在上述文件夹(scripts)内，则可以写相对路径，否则要写绝对路径

```cmd
pyinstaller.exe 路径
```

通常加-F，将其编译为单独的exe文件，缺陷是运行速度更慢

```cmd
pyinstaller.exe 路径 -F
```

若要增加一个程序图标，用-i 图标路径

若有额外的引用模块路径，用-p 模块文件夹路径。

> 凡是编译的程序最后都应该添加一行input()，以免运行结束立刻闪退。窗口化程序除外。

如果编译出错，再重复操作一次试试；若依旧出错，百度一下。

1. Pyinstaller对中文目录存在一定的兼容问题。故使用过程中，一般最好不要将exe文件放在带有中文的目录下。
2. 使用python编译程序本身存在着局限。因此运行程序的速度是比较慢的。
3. 要编译的程序尽可能减少应用的模块，否则此程序会过于庞大。

### 使用提示

1. 请不要在中文(全角)下输入单词后回车或使用快捷键，不要在大写状态使用快捷键，否则可能不成功。

### 规范

#### 标准头

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''第一行告诉非windows操作系统，这是python可执行程序
第二行告诉python解释器，本程序使用utf-8编码，防止中文乱码'''
```

第一行可能会导致 windows 编译出错

#### 帮助

##### help

加一个函数/数据类型，输出参数，成员函数(方法)，成员属性

加一个变量，等同于加它的数据类型

```python
help(print)
x=3
help(x) #同help(int)
```

可以查阅特定方法或成员属性：

```python
help(list.extend)
```

#### 标准化编程

更多请参见C学习笔记

> 编写程序的六个步骤
>
> （1）定义程序目标
>
> 用一般的概念来考虑你需要用程序解决的问题，应该涉及到的计算和操作。
>
> （2）设计程序
>
> 明确编写程序的用户界面、目标用户（客户）、编写大致所需时间，明确如何表示、处理、存储数据等等。
>
> （3）编写代码和调试程序
>
> 写出完整的python代码。
>
> 一般地，编写代码的时候，每写完一个小功能（或子函数、或一段比较长的代码），都应该先调试一下这一部分是否有bug，如果有的话，立刻修复，然后再继续编写。如果全部代码都写完再一起调试，往往查找bug是非常困难的。
>
> 在编写代码时，建议养成每写完一部分重要代码（或隔一段时间）后立刻备份的习惯，即复制并保留一份一模一样的源码，以免断电、误删等失误带来不必要的损失。
>
> （4）编译程序
>
> 当调试无误后，就可以编译程序了，记得写上程序的基本信息（程序名、版本号等），建议在32位和64位环境下都编译一份，否则64位的用户打开不了32位的.exe程序，32位的用户也打开不了64位的.exe程序。
>
> （5）维护和修改程序
>
> 程序总是要时常更新、维护、升级的。当你发现程序有可以改进、修复的时候，记得及时维护你的程序（除非你弃坑了）。如果程序功能比较复杂，最好给用户写好说明书，配有图文解说。
>
> （6）发布程序
>
> 将.exe文件（或安装包）发布。

#### 其他

##### 缩进

默认缩进代表代码块。

在没有冒号的地方不允许强行缩进创造代码块实现变量生存周期。

可以用分号或逗号强行缩行，但逗号表示的是tuple

```python
print(2);print(3),print(4)
```

冒号后面可以强行不缩进：

```python
if 0:print(2)
elif 1:print(3)
else:print(4)
```



##### dir

dir()内置函数可以查看一个对象/数据类型拥有的所有属性名和方法名。

```python
dir() #未import时只有双下划线的东西，import后有别的东西
```

```python
dir(int) #查看int的所有内置方法和属性
```

查看所有内置函数：

```python
dir(__builtins__)
```



### 编辑器

#### jupyter

##### ipynb

一种支持python的笔记本格式，可以使用vscode打开，需要安装插件(其中pip的pywin32安装较慢，特别是清华镜像源，建议官网或别的地方找正确的版本自己下载whl安装，看正确的版本只需要在pip install pywin32自动安装失败时看看它用的文件名叫啥就好了)

ipynb使用十分简单，事实上就是一堆代码框，然后可以分块运行(注意没有文本框，只有代码框)，左上角的数字代表是否执行过(是则有数字)，和执行的先后顺序

这个工具的使用本身十分简单……本处不赘述

这个工具跟自带IDLE相比，可以有vscode插件加成，有输入提示，可以用 vscode 整

##### 安装

```shell
pip install jupyter
```

##### 格式转换

[参考](https://blog.csdn.net/u014297502/article/details/125997504)

新版本下，path 有 python 的 scripts 时，直接输入：

```shell
jupyter-nbconvert.exe --to markdown .\homework1.ipynb
```

也可以转其他格式。会将内容及其运行结果导出。

不要输出运行结果：

```shell
jupyter-nbconvert.exe --to markdown --TemplateExporter.exclude_output=True .\homework1.ipynb
```

##### 魔法命令

`%matplotlib inline` 是 Jupyter Notebook 的魔法命令，它可以在 Jupyter Notebook 中直接显示 Matplotlib 绘图，而不需要在代码中使用 `plt.show()` 来显示图像。具体来说，这个命令会启用 Matplotlib 的交互式后端，将图形嵌入到 Notebook 中的输出单元格中

如：

```python
%matplotlib inline
import random
```



对 `import` 本地文件，当其更新时，不必重新运行 `ipynb`：

```python
%load_ext autoreload
%autoreload 2
```

> 如果没有这个，因为每次会在 `__pycache__` 里读取第一次编译好的字节码，所以不会实时更新。
>

##### 查阅帮助

在Jupyter Notebook中，你可以在一个对象、方法、函数或变量后面加上一个问号（?），以调用内置的帮助系统。这将显示该对象的文档字符串（docstring），其中通常包含了关于该对象的描述、使用方法和参数信息等。

```python
from scipy.stats import ks_2samp
ks_2samp?
```

##### 导出

以 vscode 预览 jupyter 为例，`...` 里找到导出直接导出即可。

#### vscode

常见问题：

report missing import 警告：[可以直接忽略警告](https://blog.csdn.net/qq_39287793/article/details/121263322)，也可以手动设置路径。

ctrl+shift+p 打开 `settings.json` (一般可能在用户文件夹的 `AppData\Roaming\Code\User\settings.json`)，追加： 

```json
"python.analysis.diagnosticSeverityOverrides": {
    "reportMissingImports": "none"
},
```

格式化：pylint, autopep8 等插件

### conda

#### 安装

anaconda 安装可以去官方，或者 miniconda [here](https://anaconda.org.cn/anaconda/)

作用：隔离环境，一个项目一个 py 版本及其对应的包。避免项目间污染。

环境变量放 PATH，找到自己的安装路径加入：[参考](https://blog.csdn.net/m0_57383947/article/details/127823940)

```sh
D:\APP\Anaconda
D:\APP\Anaconda\Scripts
D:\APP\Anaconda\Library\bin
```

> 如果 PATH 太长，可以参考这个解决方案 [here](https://www.cnblogs.com/yigiuwoligiao/p/12910690.html)，把原 PATH 末尾不带分号写成 `Path1`，然后 `PATH` 添加 `%Path1%;其他路径`。
>
> update: 疑似不行，后面再说。

检查安装完毕：

```sh
conda -V # 或 conda --version
```

镜像：

```sh
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes
conda install numpy # 测试镜像
```



#### 使用

新建环境：

```sh
conda create -n 环境名如lr5801 python=3.8
```

- `-n` 指定环境的名字

> 预装包：
>
> ```sh
> conda create -n myenv python=3.8 numpy pandas
> ```

列出全部环境：

```sh
conda env list # or conda info --envs
```

删除环境：

```sh
conda env remove --name 环境名称
```

激活环境：(后续操作不会影响其他环境；每次使用前激活)

```sh
conda activate 环境名
```

> 对 windows，要在命令提示符，不能在 powershell。

之后可以装包。(如 `pip install -r requirements.txt`)

激活后 sh 会有前缀，如 `dsc80` 环境：

> ```sh
> (dsc80) D:\_lr580\program\practice\szq\dsc80\2\dsc80-2023-fa>
> ```

取消激活：

```sh
conda deactivate
```

vscode 调用 conda 环境：ctrl+shift+p 输入 python，选择：选择编译器，选刚刚的环境，对 jupyter ipynb 同理。



### 其他

`.pyc` 文件可以删除。



## 输入和输出

### 标准I/O

#### print

```python
print(可变参数)
print(False,1,'32')'''多行注释的本质是一个不输出的字符串'''
print()#空行
```

会输出一个对象的\_\_str\_\_属性，如果要输出\_\_repr\_\_，在IDLE里直接不用print的输出达到repr，print取str,repr函数也可以获得repr(返回str，但不打印)，在非IDLE下：

```python
print(repr('3'))#用双引号也一样
```

可以调节默认参数，sep和end是参数间隔和末尾处理，默认为空格和换行。

```python
print(3,4,5,sep='_',end='#')
```

可以使用重定义进行写入，使用flush默认参数：

```python
with open('1.txt', 'w') as f:
    print(123,file=f)
```

> 还有flush参数，默认关闭。

返回值是None

#### input

```python
input('请输入内容：')#自然是可以不填的
```

读取**一行内容**，如果要模拟C的scanf，需要用循环，分割字符或正则表达式(假设要模糊化空格为空白字符)。

实现一直读(条件break)的模型：

```python
while True:
    try:
        x=int(input())
        if not x:#没有!x的表达
            break
    except:
        pass # ... 也行；对变量也可以 ... 如 x=...
```

> 注意在python2有raw_input而python3没有。

#### 转义符

单引号和双引号的意义相同。

单引号内需要转义双引号，反之亦然，三单/双引号内无需转义引号

三单/双引号也可以用于代替注释，但严格意义上并不是注释，只有#才是单行注释。

```python
print(''''w"\nc''')
```

r开头的文本内部所有内容均不转义，常用于正则表达式：

```python
print(r'\n')
```

可以使用一个转移跨行输入，但是注意tab缩进会算入，所以下一行不要缩进：

```python
print('123\
456')
```

> 其他转义符同C语言，参见C学习笔记。



#### 占位符

##### 通常法

规则是：

```python
单个占位： '%?'%内容
多个占位： '%?a %?b'%(?a,?b)
```

常用占位符：

```python
%s 跟字符串，但数字也可以。数组类输出同直接print。
%d 占位时自动显示成整数(float则四舍五入)
%f 占位默认为小数点后六位，如果整了也会补齐
	例如 print('%f'%(1/8))
%o 以八进制数字输出(%O、小数报错)，不带前导
	oct(x) 输出的八进制带前导0o，而%o不带(小数报错)
%x(%X) 以十六进制数字输出，不带前导
	hex(x) 输出带前导0x
    bin(x) 输出二进制(含前导0b)，不存在二进制的占位符
%e(%E) 输出科学计数法(含四舍五入，指数带正号)
%g(%G) 灵活输出
```

显然，同C语言，加正数居右占位，加负数居左，加小数点加正数四舍五入处理小数点后若干位(.0四舍五入取整，同round(x)，否则同round(x,dight))

> round放大不会增设0，而占位符会，如round(2.99,3)不是2.990

显然前导0+数字是整数的零占位符。

##### 格式法

使用 format 占位

f 格式：(3.6+)

```python
i=1
r=f'i={i}' #1
i,j=5,2
f'i2={i*i},j={j}' #'i2=25,j=2'
```

format 方法/函数：

```python
"{} {}".format(value1, value2)  # 同上理
"{1}, {0}".format('世界', '你好') # "你好, 世界" 位置参数
"{year}年{month}月".format(year=2023, month=4) # "2023年4月" 关键字参数
"{:%Y-%m-%d}".format(datetime(2023, 4, 1)) # "2023-04-01"
"{data[year]}年".format(data={'year': 2023}) # "2023年"
"{0[0]}和{0[1]}".format(['苹果', '香蕉']) # "苹果和香蕉"
```

更多格式：

```python
f'{6:02d},{1/3:+.6f}' #前导零，带符号小数；指数就e，同理
"{:>10}".format("测试") # 右对齐，总宽度为10
"{:->10}".format("测试") #空格使用字符 - 补全
"{:<10}".format("测试") # 左对齐
"{{{}年}}".format(2023) # "{2023年}"#双大括号转义
```



### 文件I/O

#### 打开文件

##### 常规

```python
open(文件路径, 打开方式(='r'))
```

> 路径可以是相对路径或绝对路径，参见语法-模块-引用方法-路径

```python
fp = open('a.txt', 'r')
```

常用的打开方式标识符有：

- r 只读，没有则FileNotFoundError
- w 只写，覆盖原文本，没有则新建
- a 追加，会在已有文本末尾写内容(不会换行)
- rb 二进制读(一般是图片、音频等)，同理有wb
- r+ 可读可从头覆盖写(没写到的地方不会处理，末尾不加\0)，一般不使用a+或w+(读不出东西)

注意：

1. w/a模式不可以读内容，r模式不可以写内容，没有rw、ra模式

还有两个默认参数，encoding=None,errors=None

encoding是编码方式(不区分大小写，如UTf-8也能过)，常见的有：

- utf-8
- gbk
- gb2312
- ascii
- euc-jp (日语)

如果含中文的文件，默认使用gbk读入，但是一般中文文件可能使用utf-8编码的，所以要注意。(大部分时候还可能会报错UnicodeDecodeError)

如果以b读写，不填encoding。

如下方式自动忽略错误：

```python
errors='ignore'
```



以非with方法打开文件，**需要关闭文件**：

> 虽然很多时候不关闭也没什么问题

```python
fp.close()
```

##### with

```python
with open(...) as f:
    操作
```

例如：

```python
with open('a.txt', 'r+', encoding='utf-8') as f:
    print(f.readlines())
```

文件相关操作在代码块内执行，代码块外无此文件，with结束后自动关闭文件。(文件指针仍然存在，但是被关闭，所以如果在with外操作文件，会报错ValueError)

#### 读文件

##### read

返回str，得到的最后一位不是EOF，而是文件的最后一个有效字符；但是仍然是读到第一个\0就停止。

```python
print(fp.read())
```

可以加一个参数(默认为-1，即无限行0)，表示最多读取多少长度(如果文件长度不足，则到此为止)，不会超越第一个\0。

读取是一次性的，即便\0后面还有其他字符，也不会被读到，第一次之后每次读取都返回空字符，readlines同。

##### readlines

返回一个列表，每个元素是一行(除最后一行，每行都有换行符)

如果有若干个空行，那么最后一个空行不会被读取。显然这种情况下每个非空行都有\n

同理，可以加一个参数表示读多少行。

#### 写文件

```python
fp.write(str)
```

写内容到文件

#### 编码

##### 检查编码

使用模板

```python
import chardet
def check(d):#d是路径，返回编码方式(str)
    with open(d,'rb') as f:
        dt=f.read() #可以加读取多少长度的常量
    return chardet.detect(dt)['encoding']
```

示例：

```python
import chardet
d='a.txt'
def check(d):#d是路径，返回编码方式(str)
    with open(d,'rb') as f:
        dt=f.read() #可以加读取多少长度的常量
    return chardet.detect(dt)['encoding']
e=check(d)
print(e)
with open(d,encoding=e) as f:
    print(f.read())
```

### 文档I/O

首次运行需要安装第三方库：

```cmd
pip install python-docx
```

#### doc/docx

##### docx

加载：

```python
import docx
```

打开文件：

```python
f = docx.Document(路径)
```

读取所有段落的纯文本：

```python
for i in f.paragraphs:
    print(i.text)
```

> 更多内容请查看官方文档等内容

##### doc

先转化为docx，然后再读取。

> 特别提醒：需要使用绝对路径。
>
> 执行这个函数时，不要正在打开/使用word应用，否则可能会被强行退出。
>
> 当转换结束后，再打开转换后的文件，就可以同docx一样的处理了。
>
> 使用该转换需要电脑有word

```python
import os, sys, pickle, re, codecs, string, shutil, docx
from win32com import client
def toAbsPath(p):
    return os.path.dirname(os.path.abspath(__file__))+'\\'+p
def change(addr):
    word = client.Dispatch('Word.Application')
    doc = word.Documents.Open(addr)
    doc.SaveAs(addr+'x', 12, False, '', True, '',False, False, False, False)
    doc.Close()
    word.Quit()
```

使用示例：

```python
change(toAbsPath('ab.doc'))
```

#### xlsx

##### openpyxl

###### 基础操作

安装：(window cmd命令)

```cmd
pip install openpyxl
```

加载：(方法不唯一)

```python
from openpyxl import *
```

打开文件：(路径相对绝对都可)

```python
wb = load_workbook(路径)
```

新建文件：(自带名为`sheet`的初始sheet表单)

```python
wb = Workbook()
```

保存文件：

```python
wb.save(路径)
```



读取sheet表格，可以用`worksheets`按数字从左到右顺序或用`wb`实例的key名(sheet名字符串)：

```python
sheet0 = wb.worksheets[0]
sheet1 = wb['Sheet1']
```

创建sheet表格：

```python
wb.create_sheet(index=0,title='sheet名字')
```

获取某个单元格cell的数据、坐标(字符串)：

```python
sheet0['A1'].value
sheet0['A1'].coordinate
```

> value有就是字符串，没有就是None

按行或列遍历：

```python
sheet.iter_rows() #用于for，元素是行，再for之得每个单元格
sheet.iter_cols() #同理
```

举例：

1: 批量读取

```python
from openpyxl import *
# 使用vscode自带代码补全，很好用
# 打开与本程序同目录下的一个excel表格文件
wb = load_workbook('中文路径测试.xlsx') 
sheet = wb.worksheets[0]
for col in sheet.iter_cols(): #按列遍历
    for cell in col:
        print(cell.coordinate, cell.value)
```

2: 创建一个九九乘法表并保存

```c++
from openpyxl import *
wb = Workbook()
wb.create_sheet(index=0, title='九九乘法表')
sheet = wb.worksheets[0]
for i in range(1, 10):
    for j in range(1, 10):
        cor = '%c%d' % (chr(64+i), j)  # chr是int转ascii char
        sheet[cor].value = i*j
wb.save('99mul.xlsx')
```

> 附：大的数字转EXCEL行，可以用进制的方法，递推公式是$c=(x-1)\mod26,\quad x=(x-1)/26$，新生成的$c$位于最开头，即unshift操作
>
> 参考C++代码如下：(原题：`蓝桥杯真题EXCEL地址`)
>
> ```c++
> #include <bits/stdc++.h>
> int n; std::string x;
> signed main()
> {
>     for(scanf("%d",&n);n;n=(n-1)/26) x=(char)('A'+(n-1)%26 )+x;
>     return std::cout<<x,0;
> }
> ```

> 更多内容：如字体、边框填充、超链接、excel公式、合并单元格，暂时用不上，这里不做笔记，需要用时见[这里](https://blog.csdn.net/liyuanjinglyj/article/details/87895700)



##### xlrd

> 下面内容暂时发现有误。

> 一般而言安装docx的同时已经安装了xlsx的相应模块，不需要再次安装。但如果发现无法加载，可以首次使用时安装：
>
> ```cmd
> pip install xlrd
> ```

加载：

```python
import xlrd
```

打开表格：

```python
f = xlrd.open_workbook(路径)
```

①获取表头名：f.sheet_names() 返回一个list

②打开一个Sheet(记作sht) sht = f.sheet_by_name(表头名str)

③获取sht的有效行列数：调用属性sht.nrows以及sht.ncols

nrows是行，就是打横的；ncols是列，就是打竖的

④读取表格信息，调用属性： sht.cell(行a, 列b).value

注意，行a和列b为int，从0开始数，即0代表序号第一，1代表序号第二…

另，如果该表格的内容为excel函数表达式，会直接返回计算结果。

## 数据类型

### 相关函数

#### 类型查看

##### type

查看数据、函数、实例的数据类型，返回值数据类型为type。

```python
type(print)
type(False)
type(type(1))
```

##### isinstance

判断参数是否在类型内，如果多个类型，用元组括起来

```python
isinstance(x,type)
```

例如：

```python
isinstance(7,int) #true
a='8'
isinstance(a,(str,list))
```



#### 强转

##### int

第二个参数表示原始进制，默认是10，最大是36，最小是2，只能是整数

```python
int('30')
int(30.9)
int(30)
int('10000',2)
int('ff00',16)
int('zzz',36)#注意不是26
```

##### 其他

float主要用于将str转float

bool仅对于None,空字符，空数组，空数字(虚数实部虚部均0)返回False

显然其他各种类型强转都是类似的道理，如str,bool,list,tuple

一个类型可以强转它自己，如 `str('1')`

#### len

对字符串统计长度，注意中文等特殊符号算一个字符，也可以被下标索引。

对数组统计元素个数。

#### in

> 是标识符，不是函数

判断是否在一个数组内，返回布尔值，对dict，in是代表.keys()

```python
True in [1] #返回True，会转类型后判定
```



#### getattr

`getattr(x,'y')` 等效于 `x.y` 



#### 数组类

##### range

生成数列，用在for之外需要强转

```python
range(n) #生成首项为0，公差为1，末项为n-1的序列
list(range(3)) #[0,1,2]

range(a,b) #生成首项为a，公差为1，末项为b-1的序列
range(a,b,c) #生成首项为a，公差为c，末项为b-1的序列
list(range(21,11,-2)) #[21, 19, 17, 15, 13]
```



##### enumerate

生成下标-元素tuple对的list，下标从0开始，如果是dict，元素是key。需要强转。

```python
list(enumerate([1,3,5,7]))
#[(0, 1), (1, 3), (2, 5), (3, 7)]
```

##### zip

合并多个数组型，生成tuple，每个元素依次是参数的每个元素，需要强转(如list化)，zip的每个参数是一个数组，如果每个参数长度不一，最终生成取最小的

```python
list(zip([(1,1),(2,2),(1,3)],(False,True,False),'def'))
#[((1, 1), False, 'd'), ((2, 2), True, 'e'), ((1, 3), False, 'f')]
```

可以逆向操作，使用*，如：（同样会tuple化）

```python
list(zip(*[((1, 1), False, 'd'), ((2, 2), True, 'e'), ((1, 3), False, 'f')]))
#[((1, 1), (2, 2), (1, 3)), (False, True, False), ('d', 'e', 'f')]
```



### 基本

#### int

整型，正负数和0

> 最大值
> 在32位系统中 2147483647
> 在64位系统中 9223372036854775807
>
> 但事实上可以超过这个值，python自带对高精度大数的支持。如：
>
> ```python
> 2**100
> ```

可以用前导0x,0o和0b表示整数

可以用下划线在中间，如 `10_000_000` 表示 `10000000`。

> int 最大长度受及其限制，如果不确定限制为多少，可以手动设置：(疑似 windows 不适用)
>
> ```python
> import sys
> sys.set_int_max_str_digits(10010)
> str(int(num1)+int(num2)) # 高精度加法
> ```

位运算方法(变量可用)：

```python
x=15
x.bit_count() #数1; 15.bit_count() 报错
x.bit_length() #二进制串长度
```



#### float

最大值是inf，即float('inf')可以这样获取到这个值。负也可以float('-inf')；可以参与比较

```python
print(-float('-inf')/9-9) #是inf
```

非无穷的最小值/最大值：`sys.float_info.min`, `.max`，最小正差异 `.epsilon`。



#### bool

布尔值，True和False，注意大写

#### str

字符串。

不可以取下标修改如 `s[i]='x'`

字符串有加法连接和乘法重复。

`r''` 代表里面的转义符一律当普通字符。

`b''` 二进制字符串(只能有ASACII)，type 为 bytes 

`f''` 格式化(占位符用, 3.6+)

> `u''` unicode 字符串 (python2 里 type 不一样)， py3 里与一般字符串等价

##### 函数

ord()将长度为1的str转化为ASCII码(中文等则拓展的码),chr()将其逆向

```python
ord('x')
ord('我')
chr(65)
chr(20320)
```

##### 方法

upper()将所有小写转大写，其他字符不变

lower()将所有大写转小写，其他字符不变

strip()取消首尾的全部空白字符，如空格、换行符、制表符

如果中间也去掉，可以使用reduce,filter办法：

```python
from functools import reduce
reduce(lambda x,y:x+y,list(filter(str.strip,'\n _1\n\t 1\n  \n')))
```

如果只去除左边或右边，使用lstrip或rstrip方法。

split(str)分割文本，返回list，如果分割失败，返回只有自身为元素的一元list。分割后结果不含分割符，如果分割符在头尾或连续出现，分割结果含空字符。不填参数用连续空白字符分割

find(str)查找从左到右出现的第一个str，并返回该str首元素的下标，如果没找到返回-1

rfind(str)查找从右到左第一次出现的。

replace(a,b)将str中所有的子字符串a替换为子字符串b，如果没有返回原str。

replace(a,b,c)将上述操作至多替换c次

center(总长) 返回居中显示的str，左右补足空白；同理有 ljust 左对齐, rjust

```python
'1'.center(4,'-') # 第二个参数默认空格，结果 '-1--'
```

join(字符串为元素的iterable) 以原字符串为分割符，穿插插入得到结果，如

```python
'a'.join(('bc','','d','e')) == 'bcaadae'
```

> 逐个字符追加到字符串尾部(`+=`)没有先搞一个list然后join更快

isalpha() 等方法判断该字符串是否每个字符都是特定范围的

```python
'αBc'.isalpha() == True
```

同理，注意到 isdigit() 会判断特殊字符是不是数字，如：

```python
'²'.isdigit() == True
```

- 还有 isnumeric() 方法，区别在于该方法会把简繁中文、罗马数字也算数字

translate：单字符替换

```python
trans = str.maketrans('abc', '123') #或任意str对象如''.maketrans
result = "abcde".translate(trans) # 结果: "123de"
```

title: 每个单词首字母大写；capitalize 只第一个单词首字母大写

```python
'123 abc def'.capitalize() # 不变;若 title 则 a->A, d->D
```

expandtabs 将 \t 转化 7 个空格，可以调为 n-1 个

zfill(n) 补充前导零直到长度为n

#### None

表示空，不等同于0，也不等同于零元素集合(数学空集)，类型也不一样：

```python
type(None)
```

> `x=...` 会导致得到单例对象 `Ellipsis` 省略，可用于 np 多维切片缺省维度。

#### complex

自带，如1+3j,1+1j,1j,0j,1+0j

real属性取实部，imag取虚部，都是float

#### Decimal

高精度小数，使用decimal模块

```python
from decimal import *
```

修改精度(默认28位)：

```python
getcontext().prec =50
```

修改精度不会影响修改前的任何结果，含变量。

```python
getcontext().prec=10
x=Decimal(1)/Decimal(9)
getcontext().prec=50
y=Decimal(1)/Decimal(9)
print(x,y,sep='\n')#输出不一样
```



必须要高精与高精运算才得到高精：

```python
Decimal(1/9)#错误示范
Decimal(1)/Decimal(9) #正解
```

### 数组型

下标均从0开始算

#### list

同数据结构的双向列表。

```python
a=[]#空列表
b=[1,False,[3,4,5],'996']
```

##### 方法

append在尾部添加一个元素

pop(i)删除下标i的元素并返回，其余元素往前顶来补充，不填i代表最后元素，越界报错IndexError

remove(p)删除元素p，从头到尾，每次只删除一个，找不到报错ValueError；原地修改，返回 None

insert(i,p)在i处插入元素p，原i的元素往后推

extend(数组)在尾部添加若干元素

sort()按升序整理，返回值None

- 如果有参数key=函数)，以函数为标准整理：

  ```python
  x=[1,3,-1,-2]
  x.sort(key=abs)#得[1,-1,-2,3],-1在后因本来就在后，稳定排序
  ```

- 如果有参数reverse=True，逆序

- `sorted` 内置函数不改变传入的参数，返回排序后的新 list

copy()返回x的一个副本(直接赋值是指针操作)，set同理。

> 对二维数组，无论是 `.copy` 还是切片还是乘法都不能复制；使用 copy 标准库的 deepcopy 函数
>
> 切忌诸如：`vis = [[False] * m] * n`，这样会导致浅拷贝

index(x)返回从左到右第一个出现的x元素的下标，如果找不到返回ValueError

count(x)统计有多少个x元素，找不到返回0

`*`一个整数复制重复这么多次，空集乘是自身；乘 0 得空集

> 判断某元素不在 list: `x not in arr` 或 `not x in arr`

直接使用 del 可以删除一个下标/切片区间，并让后面元素顶上，如 `del s[1:]`

#### tuple

元组，是定义之后不可以修改的列表：

```python
x=(1,2)
x=1,2 #也是tuple
x=()#空tuple
x=(1,) #或1,
```

tuple内list可变，实例同理(dack)。切片取tuple复制后赋值，二者都变。

> 没有copy方法，可以切片

#### dict

字典，即C语言的map。3.7 之后保证元素枚举顺序是插入顺序。(之前要 `collections.OrderedDict`)

```python
x={1:20,'1':30}#初始化 key:value
x[2]=50 #新增元素
y={}#空字典
```

调用错误的值返回 `KeyError`

`in .keys()` 是时空 O1 的

`[]` 与 `get()` 的区别，前者查无 `KeyError`，后者返回 None。`get(key, default)` 可以规定查无返回什么。

##### 方法

添加多项：

```python
x.update({3:50,4:False}) 
```

删除一项用pop(key)，用法同list，也可以用 `del x[key]`，这两种用法不存在都会报错

查找key用in 或in .keys()

查找value用in .values()

get(key,p=None)如果存在key返回key对应的value，否则返回p

copy()副本

#### set

同C/数学的集合。确定性、互异性、无序性(不能取下标)

```python
s={1,2,3,1,2,4}#初始化
s=set([1,2,3,4,5,2])
s=set()#空字典
s=set("aab") #逐个字符
```

- `discard(u)` 删除值为 u 的元素，如无忽略；返回 None

  `remove(u)` 如无报错，返回 None

- `pop()` 任意删除元素并返回；空集报错

- `add(u)` 插入元素，已有忽略；返回 None

##### 运算

交集 & 并集 | 取异^ 减法 - 包含关系(不等号)

```python
x,y={1,2,3},{3,4,5}
x&y #{1}
x|y #{1,2,3,4,5}
x&y|y #左结合
x^y #异或嘛，当然是{1,2,4,5}了
x-y #顾名思义，去掉x中的y部分，即{1,2}
y-x #{4,5}
x!=y #True
x>y #False
x|y>y #True
```

##### 方法

add(x) 插入

remove(x) 删除，找不到返回KeyError

discard 删除，找不到忽略

update(set) 批量插入

copy() 副本

##### frozenset

一旦创建，集合中的元素就不能被更改。

由于其不可变性，`frozenset` 可以被用作字典的键或者另一个集合的元素。

```python
fs = frozenset([1, 2, 3, 4])
```



#### 切片

> 以a=list(range(101))为例

```python
a[:] #取全部元素(等效于copy方法)
a[:y] #取下标整序列区间[0,y)内元素
a[x:] #取下标整序列区间[x,len(a))内元素
a[x:y] #取下标整序列区间[x,y)内元素
a[::d] #取首项0，区间[0,len(a))，公差d的下标序列内元素
a[x:y:d] #同样缺省x,y有变种；区间[x,y)，首项x，公差d
```

可以用-1代表最后一个元素，-2倒数第二个，以此类推

```python
a[-3:-2] #[98]
a[0:0],a[1000:10000],a[5:4] #[]
a[-7:] #[94,95,96,97,98,99,100] 
a[::50] #[50,100]
a[:21:5] #[0,5,10,15,20]
```

有 slice 函数，`slice(start, stop[, step])`

```python
"abcde"[slice(1,None)] #bcde
"abcde"[slice(1,None,2)] #bd
"abcde"[slice(2)] #'ab'
```

可以随便越界，如：`"123"[-12:15]=="123"`

#### bytes

##### 基本

`b'字符串'` 创建如 `b'abc'`。只能包含 ASCII 码(取值 0-255)，如 `b'你好'` 报错。

字符串的 `.encode()` 获得 bytes；其 `.decode()` 获得 str。默认参数是 `'utf8'`。

>  如可以 `'你好'.encode()` 和 `b'\xe4\xbd\xa0\xe5\xa5\xbd'.decode()` 和 `'你好'.encode('gbk').decode('gbk')` 编码解码不一致格式可能会报错。

支持取下标，输出每个的 ASCII 码；支持 len，切片

##### bytearray

```python
bytearray([65,66]) # 也可以 bytearray(b'AB')
bytearray("你好", "utf-8") #第二个参数必填
```

可以 append, pop 等常用 list 的操作。通过 `bytes` 函数转 bytes。

### 对象

#### 基本概念

自定义数据类型，即类。其变量是实例，有成员属性和成员函数(方法)。

定义：

```python
class 类名(父类名):#父类可以不写，或写Object，父类可以有多个
    def __init__(self,参数): #构造函数,self是自己，即this
        self.成员属性=... #定义成员属性 
    def func(self): #成员函数
        pass
    def __add__(self,v):#重载运算符+
        pass
```

使用：

```python
a=类名(参数) #创造一个实例
a.func() #使用成员函数
```

大同C++，从略。

主要介绍特殊方法和特殊属性，即带双下划线的内容：

```python
__str__ print时输出的东西，是无参数(除self)方法
__repr__ repr函数取的内容，一般用于调试，是无参数方法
```

如果他们相同，可以：

```python
class ...(...):
    ...
    def __str__(self):
        return ...
    __repr__=__str__
```

继承单一父类时，可以用super方法调用父类的初始化函数等内容。同名函数可覆盖

```python
class person(object):
    def __init__(self,n,a):
        self.name=n
        self.age=a
    def __str__(self):
        return '<'+self.name+','+str(self.age)+'>'
    __repr__=__str__
a=person('张三',120)
class chum(person):
    def __init__(self,a,b,c):
        super().__init__(a,b)
        self.hobby=c
    def __str__(self):
        return super().__str__()+'(%s)'%self.hobby
b=chum('李四',9,'鲨人') 
print(a,b) #注意由于chum的repr未赋值，故与person同
```

可以考虑动态添加成员属性和方法：

```python
class x:
    ...
y = x()
y.a=1 # 只有 y 实例有 a
print(y.a)
```

```python
def add_to_class(Class):  #这是一个装饰器
    def wrapper(obj):
        setattr(Class, obj.__name__, obj)
    return wrapper
class A:
    def __init__(self):
        self.b = 1
a = A()
@add_to_class(A)
def do(self):
    print('Class attribute "b" is', self.b)
a.do()
```

#### 静态

静态属性：

```python
class Number:
    version = "v1.0"
    def __init__(self, v):
        self.v = v
a = Number(1)
b = Number(2)
print(a.v, b.v, a.version, b.version, Number.version)
```

静态方法：

```python
class American(object):
    @staticmethod
    def printNationality():
        print('USA')
American.printNationality()
```



#### __属性

##### len

`__len__` 方法如果定义了，可以用内置函数 `len()`。通常都是 O(1) 的。

##### call

`()` 方法调用

##### doc

`__doc__` 属性，可以输出函数文档，也可以对库函数等使用，且 help 函数会用到，如：

```python
def square(num):
    '''Return the square value of the input number.
    The input number must be integer.'''
    return num ** 2
print(square.__doc__)
'''
Return the square value of the input number.
    The input number must be integer.
''' #注意会有顶格indent
```

##### slot

不要为类使用字典来存储实例属性的特殊属性，好处是减少内存占用

```python
class Point:
    __slots__ = ['x', 'y'] #中括号可以不要(tuple)
    def __init__(self, x, y):
        self.x = x
        self.y = y
p = Point(1, 2)
p.z = 3  # 抛出 AttributeError，因为 'z' 不在 __slots__ 中
```

注意：

1. **继承**：如果一个类继承了使用了 `__slots__` 的类，子类也需要定义 `__slots__`。如果不这样做，子类会自动创建字典来存储属性，这可能会抵消使用 `__slots__` 带来的好处。
2. **实例字典**：使用 `__slots__` 后，实例不再有 `__dict__` 属性（存储一个对象的所有属性，键值对）。这意味着不能再使用 `getattr()`、`setattr()` 和 `delattr()` 函数以动态的方式操作属性。
3. **弱引用**：如果你的类需要支持弱引用（通过 `weakref` 模块），那么你需要在 `__slots__` 中包含 `'__weakref__'`。

对比 dict: 虽然可以直接操作 `__dict__`，但这并不是访问或修改属性的推荐方式。通常，直接使用点操作符（`.`）是更好的选择，因为这样可以触发相关的属性访问方法（如 `__get__`、`__set__` 和 `__delete__`）。

#### 装饰器

##### property

内置装饰器，用于将一个类方法转换为属性。这样，可以像访问属性那样访问这个方法，而不需要在方法名后面加括号。

```python
class Circle:
    def __init__(self, radius):
        self.radius = radius
    @property
    def area(self):
        return 3.14159 * self.radius ** 2
circle = Circle(5)
print(circle.area)  # 输出: 78.53975
```

##### dataclass

3.7 开始。自动生成特定方法，如`__init__()`、`__repr__()`和`__eq__()`，从而简化数据类的创建

```python
from dataclasses import dataclass
@dataclass
class Point:
    x: int
    y: int
p = Point(1, 2)
print(p)  # 输出: Point(x=1, y=2)
```

- 默认值和类型提示：你可以为数据类的字段提供默认值。
- 不可变数据类：通过设置`frozen`参数为`True`，你可以使得数据类的实例不可变。
- 排序支持：通过设置`order`参数，可以让数据类支持比较操作（如`<`, `<=`, `>`, `>=`）。

```python
@dataclass(order=True, frozen=True)
class Point: # 比较依据类似 pair
    x: int = 0
    y: int = 0
# p1.x+=1 炸因为 frozen 禁止这样
p1 = Point(1, 2)
p2 = Point(1, 2)
p3 = Point(0, 1)
print(p1 == p2)  # True
print(p1 < p3)   # False
```

按照关键字顺序排序，没找到如何修改顺序。

可以套 default dict，但是需要工厂，如：

```python
@dataclass(order=True)
    class SubmitCode:
        submit_time: datetime
        code: str
        language: str
        result: str
        student_number: str
        submit_id: str
        contest_problem_id: str
        
    def create_default_code():
        return SubmitCode(datetime.min, "", "", "", "", "", "")
    last_submits = defaultdict(create_default_code) # 键是 (student_number, contest_problem_id) 二元 tuple
    
    # for ... :
    submitCode = SubmitCode(submit_time, code, language, result, student_number, submit_id, contest_problem_id)
    key = (student_number, contest_problem_id)
    if last_submits[key] < submitCode:
        last_submits[key] = submitCode
```



## 运算

### 常规运算

#### 算术运算

(以下运算类型不同才提升类型)

四则运算同理，除法是数学除法，不是C语言除法

取模，如果是负数，得到正数；甚至可以负数取模一个负数，意义同定义。

乘方是双乘号，可以实现开方等操作：

```python
3**7
-1**0 #0**0也是1,0**其他是0
4**0.5 #开根号，必然是float的2.0
8**(1/3) #开立方
(-5)**0.5 #返回虚数(0+2.23i)，注意括号优先级
```

双除号是取商，如：

```python
27//7
5.9//1.2 #4.0
2.1//2 #1.0
```

赋值语句可以连等号，也可以分步连等：

```python
a=b=c=d=40
a,b,c=1,3,5 #注意没有先后顺序，不同于C，所以不可以a,b,c=1,a,b
```

支持位运算且优先级、符号与C相同

海象运算符(3.8 Walrus Operator)，允许类似 C 语言的 `if((c=getchar)!=EOF)`

```python
if (z:=5) > 6: #注意括号
    print('666')
print(z) # if不成立z也赋值
```



#### 逻辑运算

用标识符表示与或非，如果用符号其实代表位运算

```python
and or not
```

优先级同C语言：

```python
0 and 1 or 0 #输出0
```

同C，同样有短路现象：

```python
0 and print(3) #均不执行 若0&len(str(print(3)))则执行
1 or print(4)
```

逻辑判断不遵循C语言的左结合，如：

```python
9>7>5 #True,若C语言则表示(9>7)>5=1>5=0
```

返回值or是最前者，and是最后者：

```python
(1 or 2 or 3)==1
(1 and 2 and 3)==3
(1 and 2 and 3 or 4 and 8 or 5 and 6 and 7)==3
```

### 变量

命名规范同C语言

## 流程控制

### 条件判断

> 没有switch

#### if

##### 常规式

```python
if 0:
    print(2)
elif 1:
    print(3) #3
else:
    print(4)
```

##### 简化式

没有三目运算符，但是可以if else连续(无elif)

```python
print(3) if 0 else print(4) if 0 else print(5) #5
```

多层不用括号：

```python
return 0 if s1 == s2 else 1 if s1 > s2 else 2
```



### 循环

> 没有do……while，不允许在判别式里赋值(不同C语言)
>
> continue和break同C语言理

==在删除元素等情况下尤其注意循环的代码是否正确==

#### while

循环

```python
i=1 #显然输出1,2,3,4
while i<5: 
    print(i)
    i+=1
```

> ctrl+c退出强行结束死循环程序



#### for

##### 常规式

迭代

```python
for 元素 in 数组:
    操作
```

如：

```python
for i in range(0,21,5):
    print(i)
for i,j in (('苹果',5),('香蕉',7),('西瓜',10)):
    print('%s, %d元'%(i,j))
for i,j in zip(('苹果','香蕉','西瓜'),(5,7,10)):
    print('%s, %d元'%(i,j))
for i in ((1,2),(3,4)):#此时i是tuple
    print(i[0]*i[1])
```

range 传非正整数返回空的。

可以 for-else，触发条件是 for 里没执行过 break：(continue 不管)

```python
for x in range(n + 1):
    y = m - x
    if 2 * x + 4 * y == n and x >= 0 and y >= 0:
        print(f'Chicken={x} Rabbit={y}')
        break
else:
    print("No solution!")
```



##### 列表生成表达式

外括号决定生成的是列表、元组还是集合。以列表为例：

```python
[表达式 for i in x] #基本表达式，生成列表
[表达式 for i in x if 表达式] #判定型表达式
```

例如：

```python
[False for i in range(3)]#[False,False,False]
[x for x in range(5)] #[0, 1, 2, 3, 4]
[print(i*i) for i in range(9)] #None列表，但输出了值
[float(input('输入第%d个数：'%i)) for i in range(1,6)]
[x for x in range(13) if x%4==0] #[0,4,8,12]
```

可以使用多个迭代(左边是外层，右边是内层)：

```python
[x*y for x in range(1,4) for y in range(10,31,10)]
#[10, 20, 30, 20, 40, 60, 30, 60, 90]
[x+y+z for x in 'AB' for y in 'ab' for z in '12']
['Aa1', 'Aa2', 'Ab1', 'Ab2', 'Ba1', 'Ba2', 'Bb1', 'Bb2']
```

可以嵌套：

```python
[i+1 for i in [j*(j+1) for j in range(11)]]#右嵌
#[1, 3, 7, 13, 21, 31, 43, 57, 73, 91, 111]
[[j**2 for j in range(i*3,i*3+3)] for i in range(3)]#左
#[[0, 1, 4], [9, 16, 25], [36, 49, 64]]
```

dict:

```python
{i:i**i for i in range(5)}
```

对 tuple 要显式：

```python
tuple(i for i in range(5))
(i for i in range(5)) #返回生成器，可以 next
```



#### else

`for: ... else:` 或 `while: ... else:`

循环在正常执行时会进入 else 分支，被 break 了就不会进入，如：

```python
x = int(input())
for i in range(5):
    if x == i:
        break
else:
    print('x not in [0,4]')
```

```python
for i in range(5):
    for j in range(5):
        if i == 2 and j == 2:
            break
        print(i, j)
    else:  #上面break掉了，这里就不continue
        continue
    break  #不continue就break从而跳出多重循环
```

但是被 continue 了不会触发 else ；所以跳出多重循环可以这么做



### 错误判定

#### try

##### 基本格式

```python
try:
    代码块
except:
    pass #或代码块；不能什么也不写，什么也不写就写pass
```

例如：

```python
try:
    f=open(input('输入文件名：')+'.txt','r')
    print(f.read())
    f.close()
except:
    print('文件不存在。')
```

##### 完整格式

```python
try:
    代码块A
except 错误类型a:
    代码块B
except 错误类型b:
    代码块C
else: #可以省略
    代码块D
...
finally: #可以省略
    代码块E
```

先执行代码块A，如果A报错，从报错处停止，如果符合错误类型a，执行代码块B，否则继续判断，如果符合错误类型b，执行代码块C，如果没有报错执行代码块D，无论是否报错，均执行代码块E。例如：

```python
try:
    x=int(input())
    print('4/%d=%f'%(x,4/x))
except ValueError:
    print('转换数字失败')
except ZeroDivisionError:
    print('除以0')
else:
    print('成功计算')
finally:
    print('qwq')
```

可以except内拥有多个错误类型：

```python
try:
    x=int(input())
    print('4/%d=%f'%(x,4/x))
except (ValueError,ZeroDivisionError):
    print('有误。')
```

> 获取错误类型非常简单，自己搞一次报错出来就知道是什么报错了。

可以打印给出的错误信息：

```python
try:
    x=int(input())
    print('4/%d=%f'%(x,4/x))
except (ValueError,ZeroDivisionError) as e: #单一错误也行
    print(e)
```

#### assert

判定一个逻辑运算表达式是否为真，不为真报出错误AssertionError，为真什么也不发生

```python
assert 表达式
assert 表达式, 不成立时输出什么
```

例如：

```python
a=3
assert a!=3 #报错
assert 1==2, "FCKK"
```

#### raise

在调试过程中，有时候需要在结果不符合自己意愿时，主动报错，引起程序终止，以避免大幅度修改程序。可以使用raise语句。

```python
raise 错误类型(错误信息str)
```

例如：

```python
a=0
if not a:
    raise ValueError('a为0')
```

```python
try:
    raise RuntimeError('something went wrong')
except RuntimeError as e:
    print(e) # something went wrong
```

#### 类

##### 常用方法

Python中的每个异常都是一个类，这些类都继承自内置的 `BaseException` 类。下面是一些常用的属性和方法，以及它们的简要说明：

1. **属性**:
   - `args`: 异常类的构造函数接收的参数元组。通常包含错误消息或其他详细信息。
   - `__cause__`: 表示异常链中的直接原因。在使用 `raise ... from ...` 语法时设置。
   - `__context__`: 自动设置，用于存储异常链中的上下文。
   - `__traceback__`: 包含一个 traceback 对象，记录了异常发生时的调用堆栈信息。
2. **方法**:
   - `with_traceback(traceback)`: 这个方法可以用于设置异常的 `__traceback__` 属性，并返回修改后的异常对象。这通常用于异常处理和重新引发异常。

##### 自定义类

```python
class MyError(Exception):
    def __init__(self, msg):
        self.msg = msg
try:
    raise MyError('test my error')
except MyError as e:
    print(e)
```



### 文件读写

with ... as ... 可以在读写错误时自动关闭文件。



扩展：自定义 with

```python
#@save
class Benchmark:
    """用于测量运行时间"""
    def __init__(self, description='Done'):
        self.description = description

    def __enter__(self):
        self.timer = d2l.Timer()
        return self

    def __exit__(self, *args):
        print(f'{self.description}: {self.timer.stop():.4f} sec')
net = get_net()
with Benchmark('无torchscript'):
    for i in range(1000): net(x)

net = torch.jit.script(net)
with Benchmark('有torchscript'):
    for i in range(1000): net(x)
```





## 函数

又称子程序。支持递归。

```python
def 函数名(参数): #参数无需写类型，可以有0到多个
    代码块
    return 值 #可以返回数组等东西，也是传值
```



函数允许重定义，如：

```python
def f():
    print('f')
def f():
    print('g')
f() #输出g
```



在函数内写一个字符串，表示函数注释，以后调用函数时悬停能看到该字符串：

```python
def toGrey(img):
    'fuck'
    pass
```

函数内的空行或两个`\n`算换行：

```python
def toGrey(img):
    """这是第一行
    789
    
    这是第二行\n\n第三行"""
    pass
```





### 参数

**位置参数**就是一般的参数，与C等语言一样，从略。

可以 `*` 传参，如：

```python
def f(a,b):
    print(a,b)
f(*map(int,input().split()))
```



#### 执行顺序

从左到右，Java 也是；C/C++ 未定义

```python
def f():
    print('call f')
    return 1
def g():
    print('call g')
    return 2
print(f(),g())
def h(x,y):
    return x+y
print(h(f(),g()))
'''call f
call g
1 2
call f
call g
3'''
```



#### 全局变量

使用无需声明，修改必须声明

```python
global 变量名
global a,b,c
```

使用示例：

```python
x=1
def f()
	global x
    x+=1
    print(x)
f()
f()
```

同理有 `nonlocal`

#### 传址/传值

数组类和对象均传址，等效于C++的传引用，会修改值。普通数据均传值。

数据传值示例：

```python
x=3
def f(k):
    k+=3
    print(k) #6
f(x)
print(x) #3
```

数组传址示例：

```python
y=[1,2]
def f(x):
    x.append(3)
    print(x) #[1,2,3]
f(y)
print(y) #[1,2,3]
```

对象传址示例：

```python
class ab():
    def __init__(self):
        self.x=1
k=ab()
def f(x):
    x.x+=2
    print(x.x) 
f(k) #3
f(k) #5
```

#### 默认参数

当不传入的时候，使用默认值的参数。就加一个赋值即可，同C++。

```python
def prt(nr='sth'):
    print(nr)
prt()
prt('123')
```

默认参数一般是不可变数据类型，如Number,str,tuple，如果是可变类，如数组，会形成记忆：

```python
def f(g=[]):
    g.append(1)
    print(g)
f() #[1]
f() #[1,1]
k=[2]
f(k) #[2,1]
f() #[1,1,1]
```

对象同理：

```python
class ab():
    def __init__(self):
        self.x=1
def f(x=ab()):
    x.x+=1
    print(x.x)
f() #2
f() #3
f(ab()) #2
f() #4
```

有位置参数时，默认参数必须位于后方，填参数如果一一对应，可以不声明是哪个，否则必须声明：

```python
def f(a,b,c=3,d=4):
    print(a+b+c+d)
f(0,0)
f(0,0,0) #c=0
f(0,0,d=-3) #c=3,d=-3
f(0,0,0,0) #c=0,d=0
f(0,0,d=1,c=2)
```

注意默认参数的初始化问题，如：

```python
def f(x, lt=[]):
    lt.append(x)
    print(lt)
f(114) #[114]
f(514) #[114,514]
```

建议：

```python
def f(x, lt=None):
    if lt is None:
        lt = []
    lt.append(x)
    print(lt)
```

只能通过 `=` 形式传参：

```python
def f(*, a, b): # 必须两个都传，顺序任意，必须以 a= 的形式传入
    ...
def f1(*, a=1, b):
    ...
def f2(x, *, a=1, b):
    ...
def f3(a, b=2, *, c, d=3):
    ...
```

可以拆 dict 传入：

```python
f(**{'b':2,'a':None})
```



#### 可变参数

与其他参数一起用时，可变参数放在最后面。可变参数可以传入0到多个参数，用*表示。传入的参数记作tuple。

```python
def f(*e):
    r=0
    print(e)
    for i in e:
        r+=i**2
    return r
print(f())
print(f(5))
print(f(1,2,3))
print(f(*[1,2,3])) # 含义同上
```

#### 关键字参数

```python
```





#### main参数

使用 `sys` 库的 `argv` 属性，第一个元素是运行输入的程序名，后面依次是输入的参数。即 python 后面的逐个记入 `argv`，如 `python a.py add 1 2` 有四个元素。



### 匿名函数

```python
lambda 参数:运算
```

等效于：

```python
def f(参数):
    return 运算
```

例如：

```python
x=lambda a,b:a+2*b
x(2,5) #12
```

```python
max(2+1j,1+2j,key=lambda x:x.real) #默认无法比较虚数
```

无参数匿名函数不输入参数即可，如：

```python
lambda :print('123')
```



### 高阶函数

使用一个或多个函数作为参数的函数是高阶函数。



### 内建函数

无需import即可直接使用的函数，如print。

> 使用 del 可以清理被命名覆盖的变量
>
> ```python
> sum=1
> del sum
> sum([1,2]) #之后再del报错
> ```



#### 算术函数

##### sum

可以传入一个数组型数据和附加一个数字型数据

```python
sum([1,2,3,4,5]) #15
sum([1,2,3,4,5],10) #25
```

##### abs

取绝对值，复数的绝对值同定义。

```python
abs(1+1j)
```

##### round

四舍五入函数，默认取整。

```python
round(0.9) #1
round(1.256,2) #1.25
round(150,-2) #200
round(1,-3) #0
```

注意，对0.5，存在同matlab一样的问题，即偶下奇上规律：

```python
[(i+0.5,round(i)) for i in range(-4,5)]
#[(-3.5, -4), (-2.5, -3), (-1.5, -2), (-0.5, -1), (0.5, 0), (1.5, 1), (2.5, 2), (3.5, 3), (4.5, 4)]
```

##### min,max

可以传入可变参数或一个可迭代数据类型，都返回其最值；如果传入多个可迭代类型，评判依据是整体的最值的最值，如果都有最值，返回出现最多，如果出现次数同样，返回杂质偏离最少的。

```python
min([1,2,3,4,5])
max(2,4,6,8,10)
min([1,2,3,4,5],[6]) #[1,2,3,4,5]
min([1,1],[1,9,6]) #[1,1]
min([1,1],[1,1,2]) #[1,1]
min([1,1,3],[1,1,2]) #[1,1,2]
```

可以修改可变参数，作为评判依据，是一个函数

```python
max(-7,2,4,key=abs) #-7
max([1,2,3,4,5,1,2,3,4,5],[6,10],key=sum) #前者
```

如果返回列表等，是传址

```python
x,y=[1,2],[3]
z=max(x,y) #y
z.append(9)
print(y) #[3,9]
```

同大时，在先的更具备优先级。

```python
min(-1,1,key=abs) #-1
min(1,-1,key=abs) #1
```

default 参数：防止空数组异常

```python
max([-1,-2],default=0) # -1
max([],default=0) #0
```

##### pow

基本：`pow(a,b)`

还有 `pow(a,b,p)`，可以求模意义整数快速幂。

##### hash

返回 object 的十进制数字散列值。

```python
hash('hello') #5943034673097449129
hash(1) #1
hash(-0.0) #0
hash('A') #8832457150969917233
hash(True) #1
```



#### 判断函数

##### isinstance

子类也算，想不算的话用 type，如：

```python
from collections import namedtuple
lt = namedtuple('lt', ['a', 'b'])
l = lt(1, 5)
print(type(l) == tuple)  #子类不算
print(isinstance(l, tuple))  #子类算
```

##### all

是否全为 true

注意到多维不能直接用：

```python
all([[True,True],[True,False,True]]) # True
```

##### any

是否有 true



#### 数组函数

> len、强转、range等详见数据类型-相关函数，本处主要介绍高阶函数。

##### map

```python
map(func, iterable)
```

对iterable所有元素执行一元函数func，返回操作后的结果(需要强转)，如：

```python
list(map(abs,[-3,3,6,8,-6.7]))
```

iterable自身不会被该函数改变。

可以直接赋值，如：

```python
a,b=map(int,input().split())
def f(a,b):
    print(a,b)
f(*map(int,input().split()))
```



##### reduce

该函数不是内建函数(但常用性堪比内建函数)，载入：

```python
from functools import reduce
```

格式：

```python
reduce(func, Iterable)
```

对iterable内元素从左到右两两执行一次二元函数func，共执行len(iterable)-1次，所以iterable至少有一个元素(只有一个原样返回)，其返回值类型取决于func类型。

作用举例：reduce(f, [x1,x2,x3,x4]) = f(f(f(x1,x2),x3),x4)，

```python
reduce(lambda a,b:a*10+b,[3,6,0,1])
```

iterable自身不会被该函数改变。

##### filter

不要拼错了。功能是过滤，func返回值为真的元素被保留。

```python
filter(func, Iterable)
```

例如：

```python
list(filter(lambda x:x%2==0,x)) #[-2,0,2]
```

iterable自身不会被该函数改变。

##### sorted

```python
sorted(Iterable,key=func,reverse=False)
```

顺序默认升序，除非改变reverse=True

如果不输入key=func，默认按从小到大的顺序排列。如果是str，返回按ASCII码排序的list(中文不按拼音排序)

```python
sorted('ac12我是什么')
sorted([0,5,5.1,-9]) #[-9,0,5,5.1]
```

iterable自身不会被该函数改变。

##### reversed

返回的不是原类型，需要转：

```python
list(reversed([1, 2, 3]))
```

#### 控制函数

##### eval/exec

###### eval

eval(代码str)执行单行代码并返回代码的返回值，执行的必须是运算代码，不可以是这些代码：

- 控制代码，如break
- 赋值语句，如y=3

举例：

```python
x=0
while True:
    s=input('计算器(当前值:%f)，输入公式(q退出)：'%x)
    if s.upper()=='Q': break
    x=eval(s)
```

可以使用global参数（为dict）临时给一个代码str里可能会出现的变量赋值(否则会在其他代码内找)，如果有local参数，则优先级高于global的。

###### exec

执行一行到多行代码，可以是任意代码。同样有上述参数。没有返回值。

##### compile

```python
def add_():
    return '''
def add(a, b):
    return a + b
'''

def fancy_func_():
    return '''
def fancy_func(a, b, c, d):
    e = add(a, b)
    f = add(c, d)
    g = add(e, f)
    return g
'''

def evoke_():
    return add_() + fancy_func_() + 'print(fancy_func(1, 2, 3, 4))'

prog = evoke_()
print(prog)
y = compile(prog, '', 'exec')
exec(y)
```



#### 元/反射

##### dir

查看某个包的所有属性：

```python
import random
print(dir(random))
import torch
print(dir(torch.distributions))
```

带单下划线的一般是内部属性，双下划线的是特殊属性如重载运算符。

##### vars

查看当前已定义的所有变量名(key)及其取值，以 dict 形式输出。变量包括函数变量和常规变量，即 def 的东西也会在。如：`print(vars())`。如果传入的参数是一个 object，返回该参数的所有属性及其取值。如：

```python
class obj:
    a = 1
print(vars(obj))
```

##### locals

与不传参数的 `vars` 功能一致。返回当前位置局部变量。

##### globals

返回全局变量。与 `vars` 格式类似。

##### help

输出 `__doc__`(带点装饰)，如：

```python
def square(num):
    '''Return the square value of the input number.'''
    return num ** 2
help(square)
```

#### 对象函数

`setattr, hasattr, delattr` 等。

##### getattr

返回一个对象指定的属性，第一个参数是对象变量，第二个参数 str 是属性名

##### hasattr

```python
x=1
hasattr(x,'__lt__')
hasattr([],'append')
```



### 其他函数

#### 函数指针

变量指向函数。

```python
a=print
a('1','2')
```

#### 偏函数

固定函数的默认参数，需要大批量使用固定默认参数的函数时比较有用。

```python
from functions import partial
```

举例：

```python
int2=partial(int,base=2)
int2('100000')
```

### 装饰器

装饰器装饰的对象是函数或者方法 [参考](https://blog.csdn.net/weixin_44992737/article/details/125868592)

#### 无参装饰器

```python
from time import time


def timeCount(func):

    def inner(*args, **kwargs):
        t_start = time()
        ret = func(*args, **kwargs)
        t_end = time()
        print('%s用时:%fs' % (func.__name__, t_end - t_start))
        return ret

    return inner


@timeCount
def add(x, y):  #故意延时
    for i in range(1000000):
        x += 1
    for i in range(1000000):
        x -= 1
    return x + y


print(add(1, 3))
```

多个装饰器的先后顺序：

```python
def log(func):

    def inner(*args, **kwargs):
        print(func.__name__, '执行开始')
        ret = func(*args, **kwargs)
        print(func.__name__, '执行结束')
        return ret

    return inner


#先后顺序:log头-count头-add-count尾-log尾
@log
@timeCount
def add(x, y):  #故意延时
    for i in range(1000000):
        x += 1
    for i in range(1000000):
        x -= 1
    return x + y
```

#### 有参装饰器

```python
def log2(type, dest):

    def decorator(func):

        def infunc(*args, **kwargs):
            print('%s %s %s start' % (type, dest, func.__name__))
            res = func(*args, **kwargs)
            print('%s %s %s end' % (type, dest, func.__name__))
            return res

        return infunc

    return decorator
```

```python
def add_to_class(Class):  #@save
    """Register functions as methods in created class."""
    def wrapper(obj):
        setattr(Class, obj.__name__, obj)
    return wrapper
class A:
    def __init__(self):
        self.b = 1
a = A()
@add_to_class(A)
def do(self):
    print('Class attribute "b" is', self.b)
a.do()
```



#### @wraps

因为装饰器实质是就是一个函数，是一个被修饰过函数，他与原来未被修饰的函数是两个不同的函数对象。

所以，这个装饰器丢失了原来函数对象的一些属性，比如：`__name__`，`__doc__`等属性。使用wraps语法糖可以保留这些属性

```python
from functools import wraps


def log3(func):

    @wraps(func)
    def infunc(*args, **kwargs):
        print(func.__doc__)  #加不加@wraps这个都能输出
        return func(*args, **kwargs)

    return infunc


@log3
def mul(x, y):
    '''mul文档:这是一个函数'''
    return x * y


print(mul(2, 3))
print(mul.__doc__)  #不加@wraps这个输出不了
```



#### 类装饰器

把装饰器写成类

```python
from time import sleep


class delay1:

    def __init__(self, func):
        self.func = func

    def __call__(self, *args, **kwargs):
        print('延时开始')
        sleep(1)
        ret = self.func(*args, **kwargs)
        print('延时结束')
        return ret


@delay1
def div(x, y):
    return x / y


print(div(1, 3))
```

可以给被装饰函数加参数实现装饰器的参数：

```python
class delay:

    def __init__(self, func):
        self.func = func

    def __call__(self, sec, *args, **kwargs):
        print('延时%ds开始' % sec)
        sleep(sec)
        ret = self.func(*args, **kwargs)
        print('延时结束')
        return ret


@delay
def div(x, y):
    return x / y


print(div(2, 1, 3))
```



### 生成器

#### 迭代器

iter 和 next 方法：[参考](https://www.baidu.com/link?url=_QbVBt50dVz8x9whAMlJYQNvkMcY7_NC2R98CNiXv3dnyu6jc5-_MmTySbhqg-8rEcuuS7LBx6LjW1r3KCfEhpCgFiVvoDmnjLPfG7jbyUa&wd=&eqid=ad0b782e0003bf5900000006641d9c52)

```python
lt = [1,4,3,7,5,8,1]
it = iter(lt)
print(next(it)) #1
print(next(it)) #2
```

可迭代对象：[参考](https://blog.csdn.net/m0_63007797/article/details/125690290)

```python
class myIter(object):
    def __init__(self, lt):
        self.lt = lt
        self.cnt = 0
    def __iter__(self):  # then isinstance(class1,Iterable)
        return self
    def __next__(self):  # then isinstance(class1,Iterator))
        if self.cnt < len(self.lt):
            self.cnt += 1
            return self.lt[self.cnt - 1]
        raise StopIteration #否则死循环得到None
it = myIter([6,1])
for x in it:
    print(x) #6, 1
```

#### yield

yield 相当于手动 return，下次从 return 处继续执行，返回4，res是None [参考](https://blog.csdn.net/qq_41554005/article/details/119940983)

```python
def f():
    yield 1
f1 = f()
print(next(f1)) #1
try:
    print(next(f1))
except StopIteration:
    print('stop') #走这里
for v in f():
    print(v) #1
```

```python
def fun_yield():
    print("starting fun yield")
    while True:
        res = yield 4
        print("判断yield之后是否继续执行",res) #None

g = fun_yield() # 调用这个函数只是会得到一个生成器
print("函数结果是一个生成器：",g)
print("对此生成器还是进行调用：")
print("第一次调用")
print("生成器的返回值",next(g)) 
print("第二次调用")
print("生成器的返回值",next(g))
print("第三次调用")
print("生成器的返回值",next(g))
```

```python
def yy():
    yield 1
    yield 2
    yield 4
    yield 8
for i in iter(yy()):
    print(i)
xx = iter(yy())
for i in range(4):
    print(next(xx))
```



#### send

使得 res 有值：

```python
def fun_yield():
    print("starting fun yield")
    while True:
        res = yield 4
        
        print("判断yield之后是否继续执行",res)

g = fun_yield() # 调用这个函数只是会得到一个生成器
print("函数结果是一个生成器：",g)

print("对此生成器还是进行调用：")
print("第一次调用")
print(next(g))
print("生成器的返回值",g.send(1))
print("第二次调用")
print("生成器的返回值",g.send(2))
print("第三次调用")
print("生成器的返回值",g.send(3))
```





## 模块

### 引用方法

#### 基本

无论如何引用的过程会原样执行被引用代码文件(.py)的全部内容，含print等。

引用格式：

格式A

```python
import mod
import mod1,mod2,...
import mod as abbr #引用并缩写
import mod1,mod2,... as abbr #共用一个缩写
```

格式B

```python
from mod import x
from mod import * #引用全部内容
from mod import x as c #如果x,y as c那么c代表最后者即y
```

格式A引用的内容，调用为mod.nr，但是有缩写时只能用abbr.nr

格式B引用的内容，调用为x，有缩写时也只能用缩写



引用后，其变量也可以被调用，作为全部变量，如：

```python
#impa.py  不能以数字开头，在当前文件夹
x=3
print(x) #3

#ano.py
from impa import * #无.py
x+=4
print(x) #7
def f():
    global x
    x+=3
    print(x) #10
f()
```



#### 注意

1. 反复多次执行一个 import 时，只有第一次会生效
2. 引用了一个模块，会引用该模块所引用的其他模块

如：`testimport.py`

```python
from tii import *
g()
f()
from tii import *
f()
```

`tii.py`

```python
from tib import *
a = []
print('hey tii')
def f():
    a.append(1)
    print(a)
```

`tib.py`

```python
print('hey tib')
def g():
    print('G')
```

输出：

```text
hey tib
hey tii
G
[1]
[1, 1]
```



上述 `testimport.py` 也可以改成：

```python
import tii
tii.g()
tii.f()
import tii
tii.f()
```

如果把 `tii.py` 修改为：

```python
import tib
```

则需要 `testimport.py` 修改为：

```python
tii.tib.g();
```



根据单次引用规则，若有 `ta.py`：

```python
import tb
print('ta')
```

和 `tb.py`：

```python
import ta
print('tb')
```

调用 `ta.py`，会输出：

```python
ta
tb
ta
```

如果 `ta.py` 添加一些定义语句，如定义函数，不会爆重定义错误



#### 路径

同文件夹下直接写文件名，如上例(impa.py)

##### 异文件夹

模块在文件夹里，只有单级文件夹，然后直接引用即可：

> 原笔记为首先在被引用模块下新建空的\_\_init\_\_.py文件，实测发现无需如此

```python
from 文件夹名.模块名 import * #格式B
from imp import test #格式A
```

有多个文件夹，嵌套即可。

例如：

```python
from abc.bcd.ef import * #跨了两个文件夹
#假设该代码文件在C:\a.py，则ef1在C:\abc\bcd\ef.py
from abc.bcd import ef #同理，但不可abc->bcd.ef
```

对于上级文件夹下的另一文件夹：

```python
import sys
sys.path.append('..') #导入上级路径
from lr580.abc import * #上级下某一下级内的.py
```

对于上级文件夹下的某个文件：

```python
import sys
sys.path.append('..')
from abcc import * #abc可能会跟标准库重名
```

上两级路径或其他路径，建议使用绝对路径，如：

```python
sys.path.append('D:\_lr580\program')
sys.path.append('../../') #等价的相对路径
```

常用/来表示相对路径，\来表示绝对路径



#### \_\_all\_\_

表示该模块里允许被 `from xx import *` 的 `*` 所包含的内容。是字符串或列表，表示变量名/函数名。

 如：`ima.py`

```python
__all__ = ['a', 'f']
a = 1
b = 2
c = 3
def f():
    print(b)
def g():
    print(c)
class h(object):
    def __init__(self, x):
        self.x = x
```

`imh.py`

```python
from ima import *
print(a)
f()
from ima import h
v=h('g')
print(v.x)
import ima
print(ima.b)
ima.g()
```



#### \_\_init\_\_.py

有该 `.py` 的文件夹被视为一个模块，文件夹名可以当做模块名被 `import`。当引入该模块时，首先会执行 `__init__.py`。模块的 `__all__` 可以包含一系列该模块下文件名(不含后缀的相对名字)。

那么当执行时 `from import *`，其 `__all__` 下所有包含的会被一并 `import`。且这些文件被视作一个对象般去使用。

如：有 `\impall` 文件夹，下有 `__init__.py`：

```python
print('impall')
from os.path import dirname, basename, isfile
import glob
modules = glob.glob(dirname(__file__)+"/*.py")
__all__ = [basename(f)[:-3] for f in modules if isfile(f)]
```

下有 `fia.py`：

```python
print('fia')
def ffa():
    print("ffa")
```

下有 `fib.py`：

```python
print('fib')
def ffb():
    print("ffb")
def ffc():
    print("ffc")
```

有 `\imim.py`，可以执行：

```python
import impall.fia #import impall不能调用impall.fia.ffa()
impall.fia.ffa()
# import impall #如无上两行，只触发impall
from impall import fia
fia.ffa()
from impall import *
fib.ffc() #warning
```



#### \_\_import\_\_()

内置函数。动态加载类和函数。

```python
__import__('a')
```

导入 `a.py`。

有待深入研究。



### 常用标准库

#### collection

集合类

> 栈用 list 即可；没有 TreeSet 要考虑第三方库

##### defaultdict

提供了一个默认值，用于在尝试访问字典中不存在的键时自动创建条目。这样，就不需要检查键是否存在于字典中。

```python
d = defaultdict(int) # 默认值 0
d = defaultdict(list) # 空列表
```

##### queue

有 `get` 出队并取队首，`put` 插入

##### deque

构造函数 `deque()` 或传入一个 list 等可迭代代表初始元素

> 传一个 tuple 可能会当各个元素插入，建议 `append` 来

`if` 该 deque 变量本身返回它是否为空

`pop, popleft` 方法删除右端和左端并返回，`append, appendleft` 插入。

##### priorityqueue

`queue.PriorityQueue`类是一个线程安全的优先级队列实现。它提供了以下几个常用方法：

1. **构造函数** - `PriorityQueue(maxsize=0)`：创建一个优先级队列。`maxsize`指定队列可以容纳的最大元素数目。如果`maxsize`小于或等于0，队列大小是无限的。
2. **`put(item, block=True, timeout=None)`**：将`item`放入队列中。如果队列已满，则阻塞，直到有空间可用，除非指定了`timeout`。
3. **`get(block=True, timeout=None)`**：从队列中移除并返回一个元素。如果队列为空，则阻塞，直到有元素可用，除非指定了`timeout`。
4. **`qsize()`**：返回队列中大约的元素数量。
5. **`empty()`**：如果队列为空，则返回`True`。
6. **`full()`**：如果队列已满，则返回`True`。

```python
from queue import PriorityQueue
pq = PriorityQueue()
pq.put((2, '任务2'))
pq.put((1, '任务1'))
pq.put((3, '任务3'))
while not pq.empty(): #while pq 不行，这样会死循环
    print(pq.get())
'''(1, '任务1')
(2, '任务2')
(3, '任务3')'''
```

或者用另一个标准库：(输出同上；不线程安全，轻量)

```python
import heapq
heap = []
heapq.heappush(heap, (2, '任务2'))
heapq.heappush(heap, (1, '任务1'))
heapq.heappush(heap, (3, '任务3'))
while heap:
    print(heapq.heappop(heap)) #1,2,3
a=[1,1,4,5,1,4]
heapq.heapify(a) #成最小堆,无返回值
```



##### counter

记录数的频次可以用 Counter ，传入一个列表，输出元组列表，依次表示数字和频次，用 `.most_common()` 方法转元素列表，输入参数表示取多少个。如果想要按大小取，可以先对传入的列表排序。可以减法作差。

```python
data = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']
counter = Counter(data)
print(counter)  # 输出: Counter({'apple': 3, 'banana': 2, 'orange': 1})

more_data = ['apple', 'banana']
counter.update(more_data)
print(counter)  # 输出: Counter({'apple': 4, 'banana': 3, 'orange': 1})

print(counter['apple'])  # 输出: 4

for item, count in counter.most_common(2):
    print(item, count)  # 输出: apple 4, banana 3

print(list(counter.elements()))  # 输出: ['apple', 'apple', 'apple', 'apple', 'banana', 'banana', 'banana', 'orange']
# 同 dict 理有 items(key,val), keys

counter1 = Counter(a=3, b=1)
counter2 = Counter(a=1, b=2)

print(counter1 + counter2)  # 相加: Counter({'a': 4, 'b': 3})
print(counter1 - counter2)  # 相减: Counter({'a': 2})
```



#### math

常数pi和e，意义同数学

sqrt 开根号，不能是负数

ceil,floor 上，下取整

log(x,base=e) 取对数

三角函数sin cos tan 使用弧度

反三角函数 atan acos atan 

弧度转角度degrees(x)，

角度转弧度radians(th)

```python
round(tan(radians(45)))
int(degrees(asin(0.5)))
```

最大公因数：(也有最小公倍数 lcm)

```python
gcd(-3,-6) #3
```



#### random

无需置随机数种子，也可置，可非 int 如 `random.seed(time.time())`

##### random

```python
random() #[0,1] 随机实数
uniform(a,b) #[a,b] 随机浮点数
```

##### randint

```python
randint(a,b) #返回区间[a,b]内随机整数
```

##### choice

```python
choice(数组) #返回数组内随机一个元素,dict要key是整数,返回value
```

加权，多次：(权和可以不为 1)

```python
choices(list(self.mdl.index), weights=self.mdl.values, k=M)
```

##### sample

取不重复元素

```python
sample(["never","gonna","give","you","up"],4)
```

##### randrange

```python
# 从 0 到 9 中随机选择一个数字
num = random.randrange(10)
# 从 5 到 50 中随机选择一个数字
num = random.randrange(5, 51)
# 从 0 到 100 中以 5 为步长随机选择一个数字（例如 0, 5, 10, ..., 95, 100）
num = random.randrange(0, 101, 5)
```



#### sys

递归栈深度：`sys.setrecursionlimit(10000)`

main参数

`sys.argv` 得到数组，第一个元素是输入的执行本程序名，后面是输入的参数

安装路径：

```python
sys.executable # '...\\Python310\\pythonw.exe' 绝对路径
```



#### os

##### 操作系统

查看操作系统类型：

```python
os.name
```

查看操作系统详细信息(windows不支持)

```python
os.uname()
```

查看操作系统环境变量：

```python
os.environ
```

获取操作系统环境变量用get方法，例如：

```python
os.environ.get('PATH')
os.environ.get('x','def') #如果没找到返回def
```

##### 目录

查看当前运行目录绝对路径：(二选一)

```python
os.getcwd()
os.path.abspath('.')
```

获取当前运行程序的文件夹路径和程序相对路径：

```python
import sys
dn,fn=os.path.split(os.path.abspath(sys.argv[0])) 
dn,fn=os.path.split(__file__) 
```

> \_\_file\_\_与sys.argv[0]的区别：前者是存储路径，后者是运行路径，举个例子：
>
>  a.py载入了b.py，在a import b，那么b内的\_\_file\_\_指向b，其他都指向a

拼接路径：

```python
os.path.join(路径， ...)
```

如：

```python
os.path.join('/Users/michael', 'testdir') #'/Users/michael/testdir'
```

返回不带目录的带后缀的文件名：

```python
os.path.basename(路径)
```

拆分路径：(将最后一部分(最后级别的目录或文件名(含后缀))分开)

```python
os.path.split(路径)
```

拆分文件名：(其余部分+`.后缀`(注意结果里有 `.`))

```python
os.path.splitext(路径)
```

从相对路径返回绝对路径：

```python
os.path.realpath(相对路径)
```

是否是目录：

```python
os.path.isdir(路径)
```

创建目录：如果原目录存在，会报错

```python
os.mkdir(路径)
```

> 创建多层嵌套目录 `makedirs`。该函数可以加默认参数 `exist_ok=True`。

删除目录： 如果失败，可以先把里面文件一一删除

```python
os.rmdir(路径)
```

强删带内容的文件夹：

```python
shutil.rmtree(路径)
```

路径是否存在

```python
os.path.exists(路径)
```

##### 文件

重命名：

```python
os.rename(旧完整文件名, 新完整文件名) #完整文件名=前缀+后缀，不一定是绝对路径
```

如：

```python
os.rename('test.txt','test.py')
```

删除文件：

```python
os.remove(完整文件名)
```

复制文件：

```python
import shutil
shutil.copyfile(原完整文件名,新完整文件名) #返回新完整文件名
```

> 复制文件夹：
>
> ```python
> shutil.copytree(src_dir, dst_dir)
> ```

列出当前文件或目录：

> isdir,isfile需要绝对路径；下例中dirx为os.getcwd()

```python
[x for x in os.listdir(dirx) if os.path.isdir(os.path.join(dirx,x))]
```

```python
[x for x in os.listdir(dirx) if os.path.isfile(x) and os.path.splitext(x)[1]=='.txt']
```

列出文件夹内所有文件(含子文件夹内的文件)：

```python
for root, dirs, files in os.walk(dirx):
```

当前根目录，当前下的子目录列表(相对)，当前的文件列表(相对)

文件比较：

```python
import filecmp
filecmp.cmp(路径1,路径2) #返回True如果相同
```



#### re

即regex(regular expression),正则表达式库

> 事实上python的re库是残缺的，并未支持完全的re功能
>
> [cheat-table](https://dsc80.com/resources/other/berkeley-regex-reference.pdf) [re官方文档](https://docs.python.org/3/library/re.html) [官方2](https://docs.python.org/3/howto/regex.html) [在线测试网站](https://regex101.com/)

##### 正则表达式语法

> 更多内容参见web笔记

简略版：(完全版见后面)

```python
. 匹配单字符
* 前面字符出现任意次数或0次
? 前面字符出现0次或1次
+ 前面字符出现1次或以上
^ 行开头
$ 行结尾
[] 含内部字符的字符组
[x-y] ascii码范围的[x,y]
[^] 不含内部字符
| 选择符(前后内容不只是单个字符)
{n} 重复次数为n
{n,} 重复次数至少n
{n,m} 重复次数在[n,m]内
() 分组
```

```python
\d [0-9]
\D [^0-9]
\w [0-9a-zA-Z_]
\W [^0-9a-zA-Z_]
\s [\t\n\r\f]
\S [^\t\n\r\f]
\t 制表符
\f 换页符
\b 单词边界
[^\x20-\x7f] 汉字
[\u0800-\u4e00] 日文(不含汉字字符)
[\u0800-\u4e00]{1,}|[^\x20-\x7f]{1,} 日文(含汉字字符)
```

匹配术语：

贪婪匹配：在所有可能的情况下，取到匹配文本最长的匹配结果。

常用的贪婪匹配表达式有：`.* .+ .{n,} […]*  […]{n,}`

懒惰匹配：在所有可能的情况下，取到匹配文本最短的匹配结果。

常用的懒惰匹配表达式有：`[…|…]? .{n,m}? .{n,}? […|…]{n,m}?`

应用举例：

```python
(0|[1-9][0-9]*) 匹配零和非零开头的数字
[\[|\<|\{|\(|（|【](.{1,}?)[\]|\>|\}|\)|）|】] 匹配括号里的内容
```



使用举例：

无分组：

```python
from re import *
def f(reg,tx):
    return findall(reg,tx,I|S)

f('f.ck','f*ck huck fack fuck') 
#['f*ck', 'fack', 'fuck']

f('\..*','www.?.cn')
#['.?.cn'] 贪婪匹配以.开始的任意内容，如果传入'c.'返回['.']

f('f*k','ffufuckffk')
#['k', 'ffk'] 特别注意零次这个条件，所以k也在内

f('f+k','ffufuckffk')
#['ffk']

f('k?','ksks')
#['k', '', 'k', '', ''] //分别是k,s,k,s,\0

f('k?','ss')
#['', '', ''] 

f('\(.*?\)','(12)+(34)')
#['(12)', '(34)'] 最简单的懒惰匹配

#事实上有+? ??等组合，但意义不大，不做叙述

f('^w.*w$','www')
#['www']

f('w.*w$','www\n')
#['www']

f('^w.*w$','\nwww')
#[]

f('w.*w$','www\nwk\n')
#[]

f('tac|cde|xyz','cdetaxycxyz')
#['cde', 'xyz'] 注意不能放到[]，也不能放到()里……不然都会歪曲意义

f('[145]','12344')
#['1', '4', '4']

f('[0-9_\.\-\+]','-3.e')
['-', '3', '.'] #注意转移……包括-号

f('[\u0800-\u4e00]{1,}|[^\x20-\x7f]{1,}','何を言おう;分かってるのそれでも')
#['何を言おう', '分かってるのそれでも']

f(r'\([^\(\)]{1,}?\)','(())+(3k)-()*(1+2(3)+4(5(6)7))')
#['(3k)', '(3)', '(6)'] 不含嵌套括号的非空括号，含嵌套建议DFS

#r"^(NY-\d{2}-[A-Z]{3}-\d{4}|[A-Z]{2}-\d{2}-(SAN|LAX)-\d{4})$"
#NY开头；或中间为SAN或LAN

#网址匹配
re.findall(r'http[s]?://\S+', tweet)
```

分组：

```python
f(r'\(([^\(\)]{1,}?)\)','(())+(3k)-()*(1+2(3)+4(5(6)7))')
#['3k', '3', '6'] 不含嵌套括号的非空括号，不含括号本身
f('([CHNO])(\d*)','CH3')
#[('C', ''), ('H', '3')] 匹配化学式并分离字母和数字
#一共有两组匹配，每组匹配有两个分组
f('(([CHNO])(\d*))','CH3')
#[('C', 'C', ''), ('H3', 'H', '3')] 两组匹配，各三个分组
```

##### compile



##### search

位置参数是正则表达式字符串和待匹配文本字符串，可以加可变参数，表示匹配方式，有：

- re.I 开启大小写不敏感
- re.S .会匹配换行符
- re.L 特殊字符集
  如`\w, \W, \b, \B, \s, \S`依赖于当前环境
- re.M 多行模式
- re.U 特殊字符集 
  ` \w, \W, \b, \B, \d, \D, \s, \S` 依赖于 Unicode 字符属性数据库
- re.X 为了增加可读性，忽略空格和 `#` 后面的注释

可以复合使用，如`re.I|re.S`

> split,findall的参数同理

如果匹配成功，返回的结果为match对象，无匹配结果返回None

match对象的常用属性/方法如下：

- group()或group(0)返回结果文本
- groups()返回所有分组文本组成的tuple(有先后顺序)
- group(n)返回第n个分组文本
- pos属性，表示结果文本在待匹配文本的起始位置

> 有re.match，re.match只匹配字符串的开始，如果字符串开始不符合正则表达式，则匹配失败，函数返回None；而re.search匹配整个字符串，直到找到一个匹配

**search只匹配一次！ **~~狗都不用~~

```python
x=search('\((.*?)\)','(2)+(1)*(2)')
x.groups()#('2',)
x.group(0) #'(2)'
x.group(1) #'2'
```



##### findall

进行所有可以的正则表达式匹配，并以list形式返回结果

如果无法匹配，返回空list；如果没有分组，返回列表，`[所有匹配结果]`,如果有分组，返回`[所有分组匹配结果]`,注意：每个匹配结果如果只有一个，是str；如果有多个结果是一个元组，每个元素是一个分组结果。

> 一般而言最常用

举例见上



##### split

以正则表达式参数为分割符，对待匹配文本分割，返回list表示所有分割子文本，如果分割失败，返回单元素列表，元素为待匹配文本

使用举例：

```python
split('\s+','q\n \nww tttk\tt') #['q', 'ww', 'tttk', 't']
```



##### sub

语法：

```
re.sub(pattern, repl, string, count=0, flags=0)
```

参数：

- pattern : 正则中的模式字符串。
- repl : 替换的字符串，也可为一个函数。
- string : 要被查找替换的原始字符串。
- count : 模式匹配后替换的最大次数，默认 0 表示替换所有的匹配。

返回match对象

```python
sub('\d+',lambda x:str(int(x.group(0))*2),'g6h99')
#'g12h198'
```

也可以返回字符串，如将 `ji` 替换为 `zhi yin`，反之相反的代码：

```python
s = re.sub(r'\bji\b', '#', s)
s = re.sub(r'\bzhi yin\b', 'ji', s)
s = re.sub('#', 'zhi yin', s)
```

##### match

match 是从开始位置匹配。

匹配并获取分组：下标从 1 开始算。匹配失败返回 None。组下标越界会报错。

```python
import re
emailAddress = input()
pat2 = r'(\w+)@(\w+)\.(\w+)'
r2 = re.match(pat2,emailAddress)
print(r2.group(1) if r2 else '-1')
```



##### 完全语法

| 模式        | 描述                                                         |
| :---------- | :----------------------------------------------------------- |
| ^           | 匹配字符串的开头                                             |
| $           | 匹配字符串的末尾。                                           |
| .           | 匹配任意字符，除了换行符，当re.DOTALL标记被指定时，则可以匹配包括换行符的任意字符。 |
| [...]       | 用来表示一组字符,单独列出：[amk] 匹配 'a'，'m'或'k'          |
| [^...]      | 不在[]中的字符：[^abc] 匹配除了a,b,c之外的字符。             |
| re*         | 匹配0个或多个的表达式。                                      |
| re+         | 匹配1个或多个的表达式。                                      |
| re?         | 匹配0个或1个由前面的正则表达式定义的片段，非贪婪方式         |
| re{ n}      | 精确匹配 n 个前面表达式。例如， **o{2}** 不能匹配 "Bob" 中的 "o"，但是能匹配 "food" 中的两个 o。 |
| re{ n,}     | 匹配 n 个前面表达式。例如， o{2,} 不能匹配"Bob"中的"o"，但能匹配 "foooood"中的所有 o。"o{1,}" 等价于 "o+"。"o{0,}" 则等价于 "o*"。 |
| re{ n, m}   | 匹配 n 到 m 次由前面的正则表达式定义的片段，贪婪方式         |
| a\| b       | 匹配a或b                                                     |
| (re)        | 对正则表达式分组并记住匹配的文本                             |
| (?imx)      | 正则表达式包含三种可选标志：i, m, 或 x 。只影响括号中的区域。 |
| (?-imx)     | 正则表达式关闭 i, m, 或 x 可选标志。只影响括号中的区域。     |
| (?: re)     | 类似 (...), 但是不表示一个组                                 |
| (?imx: re)  | 在括号中使用i, m, 或 x 可选标志                              |
| (?-imx: re) | 在括号中不使用i, m, 或 x 可选标志                            |
| (?#...)     | 注释.                                                        |
| (?= re)     | 前向肯定界定符。如果所含正则表达式，以 ... 表示，在当前位置成功匹配时成功，否则失败。但一旦所含表达式已经尝试，匹配引擎根本没有提高；模式的剩余部分还要尝试界定符的右边。 |
| (?! re)     | 前向否定界定符。与肯定界定符相反；当所含表达式不能在字符串当前位置匹配时成功 |
| (?> re)     | 匹配的独立模式，省去回溯。                                   |
| \w          | 匹配字母数字及下划线                                         |
| \W          | 匹配非字母数字及下划线                                       |
| \s          | 匹配任意空白字符，等价于 **[ \t\n\r\f]**。                   |
| \S          | 匹配任意非空字符                                             |
| \d          | 匹配任意数字，等价于 [0-9].                                  |
| \D          | 匹配任意非数字                                               |
| \A          | 匹配字符串开始                                               |
| \Z          | 匹配字符串结束，如果是存在换行，只匹配到换行前的结束字符串。 |
| \z          | 匹配字符串结束                                               |
| \G          | 匹配最后匹配完成的位置。                                     |
| \b          | 匹配一个单词边界，也就是指单词和空格间的位置。例如， 'er\b' 可以匹配"never" 中的 'er'，但不能匹配 "verb" 中的 'er'。 |
| \B          | 匹配非单词边界。'er\B' 能匹配 "verb" 中的 'er'，但不能匹配 "never" 中的 'er'。 |
| \n, \t, 等. | 匹配一个换行符。匹配一个制表符。等                           |
| \1...\9     | 匹配第n个分组的内容。                                        |
| \10         | 匹配第n个分组的内容，如果它经匹配。否则指的是八进制字符码的表达式 |

*\`(?P...)` 分组匹配

例：身份证 1102231990xxxxxxxx

```
import re
s = '1102231990xxxxxxxx'
res = re.search('(?P<province>\d{3})(?P<city>\d{3})(?P<born_year>\d{4})',s)
print(res.groupdict())
```

此分组取出结果为：

```
{'province': '110', 'city': '223', 'born_year': '1990'}
```

直接将匹配结果直接转为字典模式，方便使用。

#### pathlib

打开某个路径的文件：

```python
from pathlib import Path
data_dir = Path('.vscode') # data_dir = Path('.') 当前路径
file_path = data_dir / 'launch.json'
with open(file_path, 'r', encoding='utf8') as f:
    print(f.readlines())
```

没有就下载：

```python
# Download Israeli COVID vaccinations data from the ☁️
if not pathlib.Path(data_dir / 'israel.csv').exists():
    urllib.request.urlretrieve(
        'https://f000.backblazeb2.com/file/dsc-data/covid-israel/israel.csv',
        data_dir / 'israel.csv'
    )
```



#### datetime

日期操作

```python
from datetime import datetime, timedelta
```

##### 创建

获取当前时间：

```python
dt = datetime.today()
```

获得指定日期

```python
dt = datetime(年,月 ,日 ,时 ,分 ,秒)
```

取最值时间：

```python
datetime.min # 0001-01-01 00:00:00; 或 .max 9999-12-31 23:59:59.999999
```



##### datetime对象

返回datetime对象：

*second* *属性，当前时间的秒数*

*microsecond* *属性，毫秒*

*month* *属性，月份数字*

*year* *属性，年份*

*day* *属性，日*

*hour* *属性，小时*

*minute* *属性，分钟*

*ctime()* *方法，输出str的星期、月份、日期、时分秒、年份*

*isoweekday()* *方法，输出星期数(1-Mon. 2-Tue …)*

如果使用weekday()方法，则0-Mon, 1-Tue…

timestamp() 方法，输出与该时间对应的一个长float – timestamp型数字

datetime对象本身可以比较大小



##### str互转

与str互转：

（1）str转datetime

dt = datetime.strptime(str数据, 数据格式声明)

数据格式与str数据格式保持一致，其中常用格式占位符有：

> 不能加数字等一般意义的占位修饰符

*%a* *英文或德文(下同，支持双语)的星期单词简称，可匹配对象如Sun/So (注意大小写)*

*%A* *星期单词全称 如Sunday/Sonntag*

*%w* *星期序号，与weekday()方法对应*

*%d* *日期序号，如01,1,31*

*%b* *月份单词简称，如Dec/Dez %m月份数字(默认%02，日期同)*

*%B* *月份单词全称 如December/Dezember*

*%y* *年份序号末两位，如17,19*

*%Y* *年份序号全部，如2017,1919*

*%H 24小时制的小时（%I为十二小时制的，与%p一起用，%p匹配大小写AM,PM）*

*%M* *分钟序号，如04,4,58*

*%S* *秒数序号*

*%f* *微秒序号，六位数字，如110000表示0.11秒*

如：

```python
dt = datetime.strptime('2019-1-28 9:00:05','%Y-%m-%d %H:%M:%S') //2019-01-28 09:00:05 是datetime对象
```

（2）datetime转str

方法一：dt.strftime(数据格式声明) 返回按照格式声明的一串字符串。

方法二：手写……



##### timestamp互转

在计算机中，时间实际上是用数字表示的，这个数字称为timestamp(时间戳)，以中时区（世界协调时）的1970年第一天0时0秒为timestamp的0，往前负数，往后正数。在python中，小数部分表示毫秒，整数部分代表秒。

（1）顺转换

使用dt.timestamp()方法，返回float timestamp

```python
print(datetime.today().timestamp())
```

（2）逆转换

dt = datetime.fromtimestamp(timestamp数据 即float)

```python
print(datetime.fromtimestamp(1623241613.023852))
#2021-06-09 20:26:53.023852
```



##### timedelta

构造函数第一个参数是天，(可选)第二个是秒，后面是毫秒等可选。

时间 datetime 可以相减，得到 `timedelta` ，支持不等号比较。

有属性 days 等。可以与日期进行加法运算。

```python
a=datetime(2002,3,8)
b=datetime(2002,3,9)
c=datetime(2002,3,8,23,59,59)
(b-a).days #1
(b-c).days #0
```





##### 日历

calendar库

```python
import calendar
print(calendar.month(2021,6))
```



#### time

import time

当前时间戳 `time.time()` (float,小数点后六位，整数部分是秒)

（2）创造延迟

time.sleep(秒数a)

使程序（当前线程）停止任何代码执行a秒

（3）计算运行时间

> time.clock() 返回一个浮点数 旧版本(3.3) (3.8被移除)

从第一次执行该函数开始计时，第一次运行时返回一个接近于0的数字；以后每次运行都返回运行时的时间与第一次运行时时间的差距（float）。通过作差可以用于计算程序运行用时

新版本使用下面二者之一：

```python
time.process_time() #没那么精准
time.pref_counter() #更为精准
```

如：

```python
import time
x=time.perf_counter()
y=time.perf_counter()
print(y-x)
```

更准确的计时：

```python
import time
t1 = time.perf_counter()
time.sleep(0.5)
t2 = time.perf_counter()
print(t2 - t1)
```

其他计时库：

```python
import timeit
t = timeit.Timer("[x**2 for x in range(500000)]")
result = t.timeit(number=10) #测试10次，返回总用时
print(result) #1.8840052999985346
```





#### winsound

仅支持wav的播放

（1）加载模块

import winsound

（2）播放音频

winsound.PlaySound(文件路径, winsound.SND_LOOP) 代表单次播放

当然可以加一个循环让它重复播放。注意：当正在执行上面一行代码的时候，即正在播放音频的时候，程序下面的代码均不会执行，直到声音播放完毕。所以，一般会把播放声音单独创建一个线程来处理。

> 示例：
>
> ```python
> import winsound,threading,time
> #winsound.PlaySound('test.wav',winsound.SND_LOOP)
> stop=False
> def f():
>     global stop
>     winsound.PlaySound('test.wav',winsound.SND_LOOP)
>     stop=True
>     print('done?')
> def g():
>     i=0
>     while not stop:
>         time.sleep(0.1)
>         i+=0.1
>         print('%.1f'%i)
>     print('done.')
> thr1 = threading.Thread(target=f)
> thr2 = threading.Thread(target=g)
> thr1.start()
> thr2.start()
> thr1.join()
> thr2.join()
> ```



#### threading

> **进程**(process)：正在运行的程序的实例。例如：运行着的QQ、浏览器以及Word文档等等。
>
> **线程**(thread)：程序中一个单一的顺序控制流程。在之前所有的学习的python程序，都是单进程、单线程程序。单线程就是只能像一条线一样顺次执行任务，如果中途出错或运算量巨大，就容易卡机或崩溃。

```python
import threading
```

创建线程：

```python
thr = threading.Thread(target=线程目标函数, args=线程拥有的参数tuple)
```

如果使用全局变量，可以不传入参数`args`，但是需要申明global

启动线程：

```python
thr.start()
```

可以在start后加一句这个，如果不能正常启动：

```python
thr.join()
```



#### json

```python
import json
```

常规字符串与其转换使用 `str.encode(编码方式)` , `bstr.decode(编码方式)` 

数据与 JSON 转换：`json.dumps(数据)` 得到 JSON 格式的字符串

逆转换： `json.loads(JSON格式字符串)` 得到原数据

集成函数：

```python
def Encode(Message): # 加密
    return json.dumps(Message).encode('utf-8')
def Decode(Binary): # 解密
	return json.loads(Binary.decode('utf-8'))
```



#### functools

##### 缓存

1. 版本要求：
   - `@cache` 是在 Python 3.9 中引入的。
   - `@lru_cache` 在较早的版本中就已经存在（Python 3.2 及以上版本）。
2. 缓存策略：
   - `@cache` 本质上是 `@lru_cache(maxsize=None)` 的简化版本。它不限制缓存大小，所以会缓存所有调用的结果。
   - `@lru_cache` 允许你指定一个 `maxsize` 参数，用于限制缓存的大小。如果设置了 `maxsize`，它将采用“最近最少使用”（LRU）策略来淘汰旧的缓存项。

```python
from functools import lru_cache, cache
@lru_cache(maxsize=None) # 或 @cache ,都不加就 TLE
def fibonacci_mod(n):
    MOD = 10**9 + 7
    if n < 2:
        return n
    return (fibonacci_mod(n - 1) + fibonacci_mod(n - 2)) % MOD
print(fibonacci_mod(400))
```



#### itertools

```python
from itertools import *
```

可以枚举排列组合等

如：

- 笛卡尔积

  `product(iterable, repeat=1)` ，输出 $len^{repeat}$ 个元素

  `product(iterable1, iterable2, ...)` 多个集合笛卡尔积

  对 dict 使用，等价于对 keys 使用

- 排列 `permutaions(iterable, m = len)`

  按照给定参数的顺序而不是字典序返回排列，每个排列是 tuple；组合、笛卡尔积同理

  ```python
  list(permutations([1,5,3]))
  #[(1, 5, 3), (1, 3, 5), (5, 1, 3), (5, 3, 1), (3, 1, 5), (3, 5, 1)]
  ```

- 组合 `combinations(iterable, m)` 

- 带自身重复的组合(每个元素可以选无限次) `combinations_with_replacement()`

- 前缀和 `list(accumulate(nums, initial=0))`  (增加首元素0,即对 [0]+nums 叠，长度加一；不加该参数长度不变原地叠)

例：

```python
list1 = [1, 2]
list2 = [3, 4]
cartesian_product = list(itertools.product(list1, list2))
# 输出: [(1, 3), (1, 4), (2, 3), (2, 4)]
cartesian_product = list(itertools.product(list1, repeat=3))
# 输出: [(1, 1, 1), (1, 1, 2), (1, 2, 1), (1, 2, 2), (2, 1, 1), (2, 1, 2), (2, 2, 1), (2, 2, 2)]
```

```python
for i in product('1234', repeat=2):
    print(''.join(i), end=' ')
for i in product('1234', 'abc', 'AB'):
    print(''.join(i), end=' ')
for i in permutations(("abc", "def", "ghi")):
    print(i)
for i in combinations_with_replacement("abcd", 3):
    print(''.join(i), end=' ')
```

排列数组合数建议用算法知识计算，也可以调第三方库：(可以对 `numpy` 数组两两算组合)

```python
from scipy.special import comb, perm
print(perm(5, 2)) # A(n, m) 返回 double
print(comb(5, [i for i in range(6)])) # C(n, m)
```

连接多个迭代器：

```python
from itertools import chain
list1 = [1, 2, 3]
list2 = [4, 5, 6]
list3 = [7, 8, 9]
for item in chain.from_iterable([list1, list2, list3]):
    print(item)
```

```python
# 层序遍历模板
q = list(chain.from_iterable((node.left, node.right) for node in q))
```







#### decimal

以例子说明：

```python
from decimal import *
getcontext().prec = 20
x = Decimal('1')
y = Decimal('7.0')
print((x / y * y * y).quantize(Decimal('0.00'), ROUND_HALF_DOWN))
#第二个参数可以不填
```

> 精度：(官方文档)
>
> ROUND_CEILING (towards Infinity),
> ROUND_DOWN (towards zero),
> ROUND_FLOOR (towards -Infinity),
> ROUND_HALF_DOWN (to nearest with ties going towards zero),
> ROUND_HALF_EVEN (to nearest with ties going to nearest even integer),
> ROUND_HALF_UP (to nearest with ties going away from zero), or
> ROUND_UP (away from zero).
> ROUND_05UP (away from zero if last digit after rounding towards zero would have been 0 or 5; otherwise towards zero)



#### glob

文件通配符。提供了函数用于从目录通配符搜索中生成文件列表。

语法：(类比 Linux)

-  `*` 表示零到任意多个字符。所有本层文件和子目录
- `**` 表示所有文件、目录、子目录和子目录的文件(与上面相比多了子目录下的)
- `?` 单个字符
- `[]` 范围内字符，如 `[0-9]`

函数：`glob` 列出当前目录下符合条件的文件名：

```python
import glob
print(glob.glob('*.py'))  # 当前目录下所有.py
```

```PYTHON
print(glob.glob('**', recursive=True))  # 所有目录下
print(glob.glob('**/*.py', recursive=True))  # 所有目录下的.py
```

glob函数默认不搜索以· 点号开头的文件和路径，如果要求的话需要单独特判

```python
print(glob.glob('.gitignore'))
print(glob.glob('.vscode/*'))
```



`iglob` 每次返回可迭代对象，如：

```python
f = glob.iglob('*.py')
print(f)
for py in f:
    print(py)
```



`escape` 将特殊符号一般化处理(转义化)：

```python
print(glob.escape('?[]*.py'))
```

#### typing

类型检查，提出警告但不报错。3.5+

常见的：

- `List, Tuple, Set, Dict`，如 `Dict[str, int]`

- `Any`

- 函数返回值 `def add(x: int, y: int) -> int`

- `Union` 是可以取里面几种的一种作输入如 `Union[int, str]`

  类比 rust，`Optional` 是 `Union` 特况，表示还可以是 `None`

- `Callable` 可调用对象如函数

例如：

```python
from typing import List
def f(a: List[int]) -> int:
    print(sum(a))
```

> 具体使用：安装第三方库
>
> ```
> pip install mypy
> ```
>
> 执行：
>
> ```sh
> mypy code.py
> ```

自定义类：

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        ...
```

#### bisect

二分库

- `bisect_left(arr, v)` 第一个 $\ge v$ 的最小下标，对应 lower bound

  ```python
  a=[2,3,3,6,6,6]
  bisect_left(a,0) #0
  bisect_left(a,2) #0
  bisect_left(a,3) #1
  bisect_left(a,4) #1
  bisect_left(a,6) #3
  bisect_left(a,7) #6
  bisect_left([],0) #0
  ```

- `bisect_right(arr, v)` 第一个 $> v$ 的最小下标，对应 upper bound

  ```python
  a=[2,3,3,6,6,6]
  bisect_right(a,0) #0
  bisect_right(a,2) #1
  ```

  支持 `lo,hi` 参数，代表区间 [lo,hi)。返回的下标仍然相对 arr 首元素。

  ```python
  a=[2,3,3,6,6,6]
  bisect_left(a,0,3,5) #3
  bisect_left(a,100,3,5) #5
  ```

  3.10 之前，不支持自定义比较依据。之后可以 `key=`:

  ```python
  a = [6, 6, 6, 3, 3, 2]
  bisect_left(a,-6,key=lambda x:-x) #找6, 返回0
  bisect_left(a,-5,key=lambda x:-x) #找5, 返回3
  bisect_left(a,-1,key=lambda x:-x) #找1, 返回6
  bisect_right(a,-7,key=lambda x:-x) #0
  bisect_right(a,-6,key=lambda x:-x) #3
  ```

- `insort_left(arr, v)` 将 `v` 插入到 `arr`，返回 None，保持有序，插入到相同元素的左

- `insort_right(arr, v)` 将 `v` 插入到 `arr`，返回 None，保持有序，插入到相同元素的右

二分答案：[例题](https://leetcode.cn/problems/maximum-number-of-alloys/solutions/2446024/er-fen-da-an-fu-ti-dan-by-endlesscheng-3jdr/)

```python
class Solution:
    def maxNumberOfAlloys(self, n: int, k: int, budget: int, composition: List[List[int]], stock: List[int], cost: List[int]) -> int:
        ans = 0
        mx = min(stock) + budget
        for comp in composition:
            def f(num: int) -> int:
                money = 0
                for s, base, c in zip(stock, comp, cost):
                    if s < base * num:
                        money += (base * num - s) * c
                        if money > budget:
                            break
                return money
            ans += bisect_right(range(ans + 1, mx + 1), budget, key=f)
        return ans
```



#### argparse

处理 CLI 参数：

```python
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--experiment', type=str, default='test_momentum', help='Specify the experiment that you want to run')
parser.add_argument('-p', type=int, default=80, help='Some port')
args = parser.parse_args()
print(args.experiment) #上面那个experiment;或args.p
```

- `help` 参数提供了这个选项的简短描述。当用户在命令行中运行程序并带上 `-h` 或 `--help` 时，这些帮助信息会显示出来。

#### hashlib

md5 加密一个文件或二进制文本，返回32字符的十六进制字符串：

```python
hashlib.md5(b'aba').hexdigest()
def md5(path):
    with open(path,'rb') as f:
        return hashlib.md5(f.read()).hexdigest()
```

#### operator

可以用作排序依据：

```python
from operator import itemgetter
people = [('张三', 30), ('李四', 25), ('王五', 40)]
# 使用 itemgetter(1) 来获取每个元组的第二个元素，即年龄
sorted_people = sorted(people, key=itemgetter(1))
print(sorted_people)
#多关键字：itemgetter(1,0)
```

```python
from operator import attrgetter
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
people = [Person('张三', 30), Person('李四', 25), Person('王五', 40)]
sorted_people = sorted(people, key=attrgetter('age'))
for person in sorted_people:
    print(person.name, person.age)
```

#### zlib

压缩解压缩

```python
import zlib
print(zlib.compress(b'hello!'*20)) #b'x\x9c\xcbH\xcd\xc9\xc9W\xcc\xa0;\t\x00|B,%'
print(zlib.decompress(b'x\x9cKLLJJ\x1c\x06\x18\x00\xe9]L-')) #b'aabb'*50
```



# 库

在这里列出部分常用的标准库或第三方库的一些学习笔记

## 窗口化

### tkinter

> 尚未完工，还有许多实例类笔记未记录，只收录了总结笔记的主要部分

#### 窗口设置

##### 初始化

加载 

```python
from tkinter import *
```

更多加载：

```python
from tkinter.messagebox import *
from tkinter.filedialog import *
from tkinter.colorchooser import *
from tkinter import ttk
```

创建窗口

```python
root = Tk()
```

生成窗口(一般放在程序的最后)

```python
root.mainloop()
```

##### 基本属性

###### 宽高

```python
root.geometry('宽x高') 
```

完整为：width x height + x_offset + y_offset

x_offset和y_offset同样为数字，分别代表举例距离电脑屏幕左上角的水平距离和竖直距离

例如：

```python
root.geometry('250x250+500+200')
```

如果使用负数，可隐藏窗口

```python
root.geomeyry('+-1000+-1000')
```

如果禁止用户调节宽和高：

```python
root,resizable(FALSE,FALSE)#注意大写 
```

如果允许调节，可以设置宽高：

```python
root.minsize(宽,高)
root.maxsize(宽,高)
```

###### 标题

```python
root.title(str)
```

###### 图标

```python
root.iconbitmap(路径) #一般用.ico文件，支持透明
```

> 一个提供ico文件的网址：http://www.easyicon.net/

##### 基本事件

###### 最大/小化

```python
root.state('zoomed') #最大化
root.iconify() #最小化
```

###### 销毁

销毁方法是：

```python
root.destroy()
```

即将关闭窗口可以执行以下函数，如果没定义，自动执行root.destroy()

```python
root.protocol("WM_DELETE_WINDOW", ev)
```

ev是事件函数，一定要在最后有root.destroy()，否则无法关闭窗口。

#### 页面布局

同一个框架(root或Frame)内，只能使用一种方法，不能混用。

以下三种方法都可以在放置后使用对应的隐藏方法。

```python
实例.pack_forget() #或place_forget(),grid_forget()
```

显然可以通过不断地forget和布局实现动画。

##### pack

包装

> 优点：适用于单行/列，控件少时是最佳选择。可以动态变化。一般不与geometry连用。
>
> 缺点：运作方式并不是特别易于理解。 已经由 Pack 布局完成的设计也很难做出改变，控制细节方面有些力不从心

使用方法：

```python
控件实例.pack(属性)
```

属性有：

1. side=LEFT/RIGHT/TOP/BOTTOM，默认为TOP
   按照代码顺序依次（left从左到右，right从右到左，top从上到下，bottom从下到上）放置控件。
2. 外边距调节：padx, pady=… 两边的水平x/竖直y外边距，单位：像素，默认为0
   调节控件间的距离
3. 内边距调节，ipadx, ipady=…单位：像素，默认为0
   调节控件内字符与控件边框的距离
4. expand=1 //dabk
5. fill='both'  //dabk

例如：如下代码生成如图窗口：

```python
Label(root,text='The first one',bg='chocolate').pack(side=RIGHT,padx=5,pady=20)
Label(root,text='The second one',bg='cyan').pack(side=RIGHT)
Label(root,text='The third one',bg='palegreen').pack(side=RIGHT,ipadx=5,ipady=5)
```

![image-20210308134709633](img/image-20210308134709633.png)

##### place

位置

> 优点：使用绝对位置，位置严谨，复杂窗口的常用方法。是普适性最高的方法。
>
> 缺点：很麻烦。要自己计算、调试合适的x和y。

属性：x,y,width,height,单位均为像素

##### grid

网格

> 优点：实用。把控件放置在二维表格，按照行列排序。
>
> 缺点：控件的大小差距太大时，显得不美观。

使用：控件实例.grid(row=行数，column=列数),若列数为0可以省略，行列从0开始算

同样可以使用padx,pady,ipadx,ipady。

新属性排列：sticky = N ,W ,E, S, NW, NE, SE, SW 分别八个方向的英文简写，表示在格子里居什么排列。如sticky=W表示当组件大小不一时，靠格子的西边(west)排列。

例如，如下代码生成如图窗口：

```python
Label(root,text='The first one',bg='chocolate').grid(row=0)
Label(root,text='The second one',bg='cyan').grid(row=0,column=1,padx=10,ipadx=5)
Label(root,text='The third one',bg='palegreen').grid(row=1,column=1,pady=10)
```

![image-20210308134932284](img/image-20210308134932284.png)

#### 事件

##### bind

```python
实例.bind(event,func)
```

event为触发条件，使用str形式表达，比较常见的有：

> *<Button-1>* *左键单击，如果有双击，第一次也会触发*
>
> *<Double-1>* *左键双击*
>
> *<Button-3>* *右键单击*
>
> *<Button-2>* *鼠标中键*
>
> *<Motion>* *鼠标在按钮内，且移动了(也就是扫过按钮会触发很多次，但在按钮里不动不会触发)*
> *<B1-Motion>来让左键不放触发事件*
>
> *<key>* *按键触发，如<a>代表点击a触发，特殊键位有space，shift，F1等等，对于字母，区分大小写*
>
> *<KeyPress>* *按下任意键*
>
> *<键名>* *按下该键* //dack

func为触发后执行的函数，必须有一个参数(也可以设为可变参数)，

该参数有属性x和y，都是int类型；，代表坐标

属性keysym

如果是点击触发，x和y分别代表在控件内鼠标所处的x坐标和y坐标

当func比较简单时，可以使用匿名函数更为方便。

以下例子获取点击坐标(当且仅当点击了Label test内)：

```python
test=Label(root,text='please click',bg='chocolate')
def ev(a):
    test.config(text=str(a.x)+','+str(a.y))
test.bind('<Button-1>',ev)
test.pack()
```

##### bind_all

与bind的区别为：

支持按键触发，此时参数a的x和y以窗口左上角为原点；

若点击触发，当点击控件内部时，参数a以控件左上角为原点；当点击空间外部时，参数a以窗口左上角为原点。

以下例子获取按键的名字：

```python
test=Label(root,text='please input',bg='chocolate')
test.bind_all('<KeyPress>',lambda a:test.config(text=a.keysym))
test.pack()
```

##### after

```python
实例.after(毫秒数int, 函数名)
```

在延期多少毫秒后执行函数。

如果要循环执行，可以在函数里用after调用函数自身。

拓展：

- 多重after

  每次在after方法指定的函数的外部调用一次after，就会调用一个新的循环，与原有循环互不干扰，时间上没有相关联

- return

  如果after方法指定的函数内部有return（一般用if触发），每次执行return，将会结束一个循环。

给出两个例子：

①计时器

```python
butt=Label(root,bg='chocolate')
j=0
def cycles():
    global j
    butt.config(text=str(j))
    j+=1
    butt.after(1000,cycles)
butt.after(0,cycles)
butt.pack()
```

②复杂的例子

分析：

> *a.若先按kill使其return，那么无论kill了多少次，只需要再press两次，就可以正常执行一次after*
>
> *第一次看作抵消return，第二次看作正常启动*
>
> *b.若按了press一次，相当于启动了一个新的循环；按了多少次就有多少个各自进行的循环，不同时进行*
>
> *c.按一次kill可以抵消一次之前的after循环*

#### 通用属性

##### 方法

###### config()

```python
config(属性)
```

调节一个或多个属性，也可以通过实例['属性名']来赋值或调用(if)

##### 属性

1. fg 文字颜色str，支持RGB或颜色单词，如red, light green, dark blue

2. bg 背景颜色，同理

3. font 字体str，格式为字体 字号 (bold) (italic)，如黑体 25 italic

4. justify 多行文本对齐方式，有LEFT,RIGHT,CENTER三种，默认为LEFT

5. width 宽度

6. height 高度

7. text 名称(按钮、标签等)str

   高度和宽度在place中的度量单位是像素，在创建控件中一般是行字数（列数）

#### 控件

创建控件：

```python
实例名 = 控件名(窗口/框架名, 属性)
```

一次性修改的标签可以不设实例名，直接创建并生成，如：

```python
Label(root,text='A label.').place(x=0,y=0)
```

##### 标签Label

适合justify属性

有compound属性，如果一个标签既有图片又有文字，使用其限定图片的位置

有BOTTOM,TOP,LEFT,RIGHT,CENTER。用CENTER的话图片作为背景。

插入图片：

```python
图片 = PhotoImage(file=路径) #只支持gif
实例.config(image=图片)
```

> 动态改变图片，如：[参考](http://www.qb5200.com/article/374718.html) [参考](https://blog.csdn.net/m0_50000839/article/details/120078530)
>
> ```python
> from PIL import ImageTk
> imgShow = PhotoImage(file=path)
> imgLabel.config(image=imgShow) 
> imgLabel.image = imgShow # 防止临时变量消亡
> ```
>
> 要缩放的话，构造函数直接传 Image 对象，对 Image 对象缩放



##### 按钮Button

command=点击事件(一个函数名) 

禁用/可用 state="disabled" / "normal"

##### 提示框

加载：

```python
from tkinter.messagebox import *
```

样式：

(1)信息框： 有一个蓝色倒感叹号图标，为“i”，按钮为确认，

  showinfo(标题, 内容)

(2)警告框，有一个黄三角图标，按钮同为确定

  showwarning(标题, 内容)

(3)错误框：有一个红叉图标，按钮同

  showerror(标题, 内容)

(4)是否框：有一个蓝色问号图标，按钮为 是(Y)和 否(N)，不能点右上的“叉”

  布尔值变量 = askyesno(标题, 内容)

  当点击了是按钮，布尔值返回真，点击否返回假。

注意：执行提示框时，直到用户操作前，下面的代码不会执行。如：

```python
if askyesno('确认删除吗？','删除的文件无法复原'):
    print('删除')
else:
    print('撤销')
print('点击后才能看到这个')
```

##### 输入框Entry

1.获得内容：str变量 = Entry名.get()

2.删除内容：delete(起始位置, 结束位置)

一般使用：Entry名.delete(0, END) 注意END大写

3.插入内容：insert(起始位置, str内容)

4.掩码 show属性

用法：show=掩码内容str,如果是单个字符或汉字，则用此为掩码；如果为字符串，使用第一个字符或汉字作掩码。可以用于设计输入密码 ,使用举例：

```python
e1=Entry(root,show='*')
e1.pack()
Button(root,text='Get',command=lambda :showinfo('Get:',e1.get())).pack()
```

##### 文本框Text

文本框即多行编辑框，常用于文本的输出或输入

1.获得内容：Text名.get(行列a, 行列b)

行列是一个格式，**用float表示**，格式为：行号.列号， 如2.1为2行1字符末

行号从1开始，列号从0开始，省略行列b默认为输入行列b为END

2.删除，得到和插入跟输入框Entry一样，但是要注意位置改用成行列

3.更多属性：

state=DISABLED /NORMAL不可操作(代码也不行)或常规

4.插入文本：Text名.insert(位置标记, 文本str)

5.字体

创建字体：Text实例.tag_configure(字体名字, font=字体格式str, foreground=颜色单词str) 其中，foreground不能简写为fg，可以不设置，则默认为黑色

字体格式为：字体 字号 (bold) (italic)，字体名字任意

使用字体：Text实例.insert(位置, 文本内容, 字体名字)

> *（注：width和height的长度单位是默认字体时的，不会随字体变化而变化）*

```python
t1=Text(root,height=7,width=16,bg='cyan')
t1.tag_configure('f1',font='楷体 18 bold',foreground='green')
t1.insert(END,'测试字体\n123abcABC','f1')
t1.pack()
```

##### 滚动条Scrollbar

以与Text配合为例：

```python
t1=Text(root,height=4,width=20)
s1=Scrollbar(root,command=t1.yview)#竖直
t1.config(yscrollcommand=s1.set)
t1.pack(side=LEFT)
s1.pack(side=LEFT)
```

##### 单选框Radiobutton

常用属性：text 显示内容

variable 选择变量，如果多个单选框使用同一个variable，则它们是同一组单选框

value 选择值，选中时选择变量的值

command 点击事件

indicatoron 样式，默认为1，另一种样式为0

2.选择变量(设为v)

创建一个选择变量v = IntVar()

设置选择变量的值value: v.set(值)

得到选择变量的值value: v.get() 

举例：

```python
v1,v2=IntVar(),IntVar()
v1.set(1)
v2.set(2)
Label(root,text='选择水果和饮料：').grid(row=0)
for a,b in [('苹果',1),('香蕉',2),('梨子',3),('西瓜',4)]:
    Radiobutton(root,text=a,variable=v1,value=b).grid(row=b,column=1)
for a,b in [('可乐',1),('橙汁',2),('牛奶',3)]:
Radiobutton(root,text=a,variable=v2,value=b,indicatoron=0).grid(row=b)
Button(root,text='下单',command=lambda :showinfo('提示：','购买编号为%s,%s'%(str(v1.get()),str(v2.get())))).grid(row=0,column=1)
```

##### 复选框Checkbutton

一个复选对应一个选择变量，其他大同单选框。习惯上会开数组。

##### 列表框Listbox

1.常用属性：

selectmode = SINGLE/MULTIPLE/EXTENDED/BROWSE,单选，多选，支持ctrl和alt的多选及按住时滑动单选，默认为SINGLE，推荐BROWSE或EXTENDED

selectforeground = 颜色str， 选中项字体颜色，默认为white

selectbackground = 颜色str， 选中项背景色，默认为系统蓝色

2.常用方法：

insert(a, b) 在列表a处插入一项，内容为b。a的0为头项，1为第二项，END为最后一项……

delete(a,b) 删除从第a到第b之间的所有项，从0开始算为头项。不填b，则删除a单独一项

size() 获得当前项目总数，类型为int

curselection() 获得选中项序号tuple

get(序号) 获得序号指向的内容，一般与上一个方法连用。若不填，获取所有项目

*序号的填法：填入一项或一个tuple int，获取该项(该tuple的所有)内容*

*填入两个参数a，b，获取序号区间[a,b]内所有项目的内容*

select_set(a,b) 选中项目。可以不填b，则单选。填入，则选中区间[a,b)内所有项目。

3.注意，若使用bind单击事件，则curselection方法获得的是上一次点击的项目；使用双击事件才能获得本次点击的项目。

##### 通用对话框

通用对话框，即让用于选择打开文件，保存文件，打开文件夹或选择颜色等操作的对话框

1.加载：from tkinter.filedialog import *

from tkinter.colorchooser import *

2.打开文件框 askopenfilename

可选属性：(1)title 对话框的名字

(2)initialdir = 初始绝对路径str ，默认为运行目录

(3)filetypes = [类tuple, 类tuple, ……] 筛选可以看到的文件种类，默认所有(即 *)

举例：filetypes=[('程序','py'),('所有文件','*')])

需要用一个变量来接受返回值，若打开成功，返回文件的绝对路径(完整路径+文件全名)，若打开失败，返回空str

3.保存文件框 asksaveasfilename

与打开文件框不同的是标题，按钮名称，以及要覆盖时提示是否选择覆盖文件(当然实际不会覆盖，要实现覆盖可以用os库的命令)

用户要自己在对话框中输入文件名，如果不输入后缀，不会自动添加后缀，但是可以通过其他代码实现。

返回值是文件绝对路径str

4.打开文件夹框 askdirectory

5.第二种打开文件框 askopenfile

与askopenfilename不同之处在于，返回值是file类或None，而不是str

可选属性：mode=打开方式，打开方式见open函数的说明(c5.docx)

6.颜色选择对话框 askcolor

返回值是一个tuple((R, G, B), 十六进制值str)或(None, None)

RGB是电脑储存颜色的常规方法，在这里是float形式。如果用于tkinter，一般使用后面的十六进制值，可以用于其他组件的颜色属性color=十六进制值str

可选属性：color=(R,G,B)，默认选择的颜色



from tkinter.messagebox import *

对话框：showwarning, showinfo, askyesno, 第一个参数标题，第二个文本。问是否的返回值为真是点是。

##### 菜单Menu

1.创建父菜单

父菜单名 = Menu(root/上一级菜单)  *记父菜单名为a*

2.创建一个子菜单栏目

a.add_cascade(label=栏目名,menu=菜单名) *记菜单名为b*

在b中添加b的子菜单也是同样的操作，b.add_cascade(label=…,menu=…)

3.创建一个菜单项目

b.add_command(label=…,command=func)

4.添加分割线 b.add_separator()

5.修改子菜单项目： b.entryconfig(序号, 待修改属性) 序号从0开始

6.tearoff属性，用于菜单b,若为1，菜单头有一条虚线；为0没有，默认为1

7.右击菜单模版

root(或Frame实例等控件).bind(‘<Button-3>’,popup)

def popup(event):

  a/b.post(event.x_root, event.y_root)

右击后在鼠标处召唤出菜单

8.显示菜单：root/Frame.config(menu=父菜单名)

```python
menu0=Menu(root)
menuA=Menu(menu0,tearoff=0)
menuB=Menu(menu0)
menu0.add_cascade(label='Handle',menu=menuA)
menu0.add_cascade(label='Set',menu=menuB)
menuB.add_command(label='Exit',command=root.destroy)
menuA.add_command(label='About',command=lambda :showinfo('x:','A program.'))
menuA.add_separator()
menuC=Menu(menuA)
menuA.add_cascade(label='Edit',menu=menuC)
menuC.add_command(label='Move',command=lambda :showerror('404','Not Found!'))
root.config(menu=menu0)
```

> *上面例子的包含关系为：menu0包含menuA（显示名Handle）和menuB(显示名Set)。menuB包含exit一个项目；menuA包含项目about,子菜单menuC(显示名为edit)。子菜单menuC包含项目Move，要用到menu=xxx时，指向的必须是实在的Menu实例*

##### 框架Frame

Frame是用来装控件的空间，常用于复杂的窗口设计。每个Frame相当于一块装载控件的板。每个Frame内的页面布局方式要相同，但不同Frame之间可以不同。在Frame内的控件布局坐标以Frame左上角为原点。用于复杂情况下代替root装载控件。

如：

```python
fra=Frame(root,bg='cadetblue')
fra.grid(row=0)
frb=Frame(root,width=120,height=40,bg='aqua')
frb.grid(row=0,column=1,padx=5)
Label(fra,text='123').pack()
Label(fra,text='4566666').pack(padx=15,pady=15)
Label(frb,text='789').place(x=20,y=10)
```

> 在上述例子，fra,frb代替了root来装载控件，归属关系为：root包含fra,frb；fra包含前两个标签,frb包含第三个标签。

##### 画板Canvas

作用：绘制简单图形和文字等。

1.常用基本方法：

画直线：create_line(x1, y1, x2, y2,fill=颜色str, width=宽度) 宽度单位为像素

*以一定宽度和颜色过点(x1, y1),(x2, y2)作一条直线，width默认1，默认颜色黑，下同*

画矩形：create_retangle(x1, y1, x2, y2, fill=…, width=…, outline=…)

*以(x1,y1),(x2, y2)为左上和右下端点画矩形，outline为边框颜色，若设置了width的话可以显示出，像fill，width等属性大多是通用的，下面不重复*

画文字：create_text(x1, y1, text=文字str)

*以(x1,y1)为文字中心绘制文字*

画类椭圆曲线：create_oval(x1, y1, x2, y2, ……)

*以(x1,y1),(x2, y2)为外切椭圆的矩形的左上和右下端点，绘制椭圆(或圆)*

画图片： create_image(x, y, image=Image类, anchor=NW)

*以(x,y)为图片左上角，绘制图片，图片用PhotoImage(file=地址)加载，使用anchor=NW就是把x,y锁定在左上角的意思，如果不用，则在中心。*

画多边形：create_polygon(点组list/tuple……)

*至少要三个点，即六个参数*

2.可以使用bind方法进行点击事件，event为<B1-Motion>来让左键不放触发事件

##### 分组框Notebook

1.加载：from tkinter import ttk  一定要单独写一行，因为ttk是一个子模块

2.创建：分组框名 = ttk.Notebook(root)  *记分组框名为tabs*

3.添加分组框架：

3-1.创建分组框架：框架名 = ttk.Frame(tabs)  *要用专用框架ttk.Frame*

3-2.加载框架：tabs.add(框架名, text=表头名)

每个分组框栏目内空间实际上可以看做一个Frame

如：

```python
tabf=ttk.Notebook(root)
tab1=ttk.Frame(tabf)
tab2=ttk.Frame(tabf)
tabf.pack(expand=1,fill='both')
tabf.add(tab1,text='fx1')
tabf.add(tab2,text='fx2')
Label(tab2,text='xyz').grid(column=0,row=0,padx=8,pady=4)
```

##### 拖动条Scale

常用于用户自定义设置的功能中。

1.基本属性：

from_ 起始数值，注意有一个下划线，*是因为避免与from … import 的关键字重复*

to 终止数值

orient 有HORIZONTAL或VERTICAL两种，即水平或竖直，默认为后者

length 条形长度 注意，不使用height

width 条形宽度

tickinterval显示的分度值

2.基本方法:

set 设置一个显示的值

get 得到所显示的值



#### 杂项

##### 剪切板

复制内容到剪贴板，使用 root 的方法：`clipboard_append(str)` [参考](https://vimsky.com/examples/detail/python-ex-Tkinter-Tk-clipboard_append-method.html)

记得先 `clipboard_clear()`



## 远程处理

### pymysql

连接到数据库：`connect(host=url字符串, user=数据库用户名字符串, password=数据库用户密码字符串, database=数据库名字符串, charset=字符集)` ，返回一个对象，该对象可以使用 `.cursor()` 方法得到用于操作的对象，得到的对象有方法：

`execute(sql语句字符串)` 执行一条数据库指令

`fetchall()` 得到输出(tuple的tuple，第一个维度是行，第二个是列)

> 如：
>
> ```python
> import pymysql as sql
> oj = sql.connect(host=hosturl, user=username, password=password,
>          database='scnuoj', charset='UTF8')
> cur = oj.cursor()
> cid = input('输入比赛ID:')
> cmd_getProblem = 'select problem_id,title from problem, contest_problem where problem_id=problem.id and contest_id='+cid
> #如果是修改，记得commit。参考github官方例子 oj.commit()
> lens = cur.execute(cmd_getProblem)
> print(lens, cur.fetchall())
> ```

注：

- 读入的日期会以 `datetime` 格式保存。

建议用 `with oj.cursor() as cur` 写法，会自动关闭。

写一定要 commit，不然不成功，如：

```python
import pymysql as sql
from random import randint
oj = sql.connect(host='192.168.126.128', port=8066, user='root', password='root', database='mstest', charset='UTF8')
with oj.cursor() as cur:
    sql = "INSERT INTO t_user VALUES (%s, %s)"
    values = (randint(1, 65535), '白茶')
    cur.execute(sql, values)
    oj.commit()
with oj.cursor() as cur:
    cmd = 'SELECT * FROM t_user'
    cur.execute(cmd)
    print(cur.fetchall())
```



### paramiko

[参考](https://www.cnblogs.com/erlou96/p/16878288.html) [参考2](https://zhuanlan.zhihu.com/p/456447145)

#### 远程命令

```python
# import os
# os.system('ssh root@174.136.237.70')
# os.system('ls')
import paramiko
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(
    hostname='174.136.237.70',
    username='root'
) #假设已经免密登录了
stdin,stdout,stderr = ssh.exec_command('ls')
result = stdout.read().decode()
print(result)
```

多条指令分号隔开，如 `ls;cd py;ls`。输出会合并。

#### 文件传输

```python
#文件上传
#从ssh.connect之后继续:
sftp = paramiko.SFTPClient.from_transport(ssh.get_transport())
localpath = 'combs.cpp'
remotepath = '/root/c.cpp' #路径不能写~等,而且要完整有c.cpp不可缺省
sftp.put(localpath,remotepath)
```

```python
#文件下载:
localpath = 'dest.py'
remotepath = '/root/py/crawl.py'
sftp.get(remotepath,localpath)
```





## 数据处理

### numpy

惯用加载法

```python
import numpy as np
```

#### 数组操作

##### 创建

建立Numpy的数组

```python
arr=np.array(数组, dtype=数据类型)
```

> 如用 `asarray`，非必要不 copy。而 array 必须 copy
>
> 逆运算：`tolist` 方法

查看维度：(一个tuple)

```python
arr.shape
```

重建维度：

```python
arr.reshape(tuple 维度)
```

建立零数组：

```python
np.zeros(维度)#单一维度可以用int，否则用tuple，类型默认float
```

> ```python
> bins = np.zeros(256, np.float32)
> np.zeros(a.shape)
> self.prev_dw = np.zeros_like(self.w) 
> ```

建立未初始化的数组：

```python
np.empty(img1.shape, img1.dtype)
```

```python
np.empty_like(img, dtype=float) #复制形状
```



建立一数组同理，用ones

建立python range：

```python
np.arange(n) #同np.array(range(n))
```

建立n阶或$n\times m$$(0,1)$对角矩阵

```python
np.eye(3)
np.eye(4,5) #第五列无1
```

建立值域在$[10^a,10^b]$的k个数，它们的图像类似于$e^{-a},a>0$，实质上它们成等比数列：

```python
np.logspace(a,b,k)
```

建立值域为$[a,b]$的k个成等差数列的数：

```python
np.linspace(a,b,k)
```

##### 类型

查看：`.dtype`

##### 大小

`.size` 元素数

`.shape` tuple 维度(一维也是 tuple)

##### 变换

插入：

```python
np.insert(原数组, 插入位置, values=插入值, axis=轴) #轴0是插入行，1插入列
```

例如：

```python
h=np.insert(np.eye(5),1,values=np.ones(5),axis=0)  #values形状会随axis不同而变化
```

扁平化，即降维：

- rival 返回值是原数组的引用(原数组不被扁平化，修改返回值数组也会修改原数组)
- flatten 返回值是原数组的副本，互不干扰

##### 形变

形状重组 `reshape(h,w)`，如：

```python
np.linspace(1,25,25).reshape(5,5)
```

类型转换方法 `astype`：

```python
np.linspace(1,25,25).reshape(5,5).astype(np.int8)
```

也可以用 `np.数据类型()`，如：

```python
output = np.uint8(output * 255)
```

维度增加：`np.newaxis`，如：

```python
np.array([1, 2, 3, 4])[:,np.newaxis]
```

变成一维并返回：`.flatten()`

##### 运算

`.shape` 属性看各维度大小，`.size` 看元素数

运算：*是直接的，@是外积(`np.dot`)，如：

```python
x=np.array([1,2,3,4,5])
y=np.ones([5,1])
x@y
```

数组一对一乘法：

```python
np.multiply(arr1,arr2)
```

数组连接：

```python
np.concatenate((np.array([4,3,2]),np.array([0,-1])))
```

数组排序(升序)：

```python
np.sort(arr)
```

逻辑运算，对每个元素操作，返回真值矩阵，如：

```python
arr>0 # 返回 bool 数组
arr[arr>0] #用该布尔值数组筛选
arr[~(arr>0)] # 取补
arr[(arr >= l) & (arr <= r)] # 同时满足两个条件
np.random.uniform(low=0.0, high=1.0, size=(5,5))>0.5
```



转置：

```python
arr.transpose()
```

随机选择 10 次：

```python
np.random.choice([1,2,3,4,5],size=10,p=[0.05,0.05,0.2,0.3,0.4])
```

随机打乱：

```python
np.random.permutation(x) # np.random.shuffle(x) # 有细节差别
```



##### 下标

`[第一维度,第二维度, ...]` 的方法。每个维度可以用列表生成表达式，可以表示子阵，支持修改。如 `x[1,2]`, `x[1,:,3]=3`，也可以 `x[1][2]`，对二维用 `x[1]` 得到一维数组(第二行)

可以用不等式表示范围内的下标，如：

```python
mu0 = np.sum(img[img < i])/n0
img2[img2 < x] = 0
```

范围下标：如取 `(1,1),(2,2),(3,3)`：

```python
a = np.zeros((5,6))
a[[1,2,3],[1,2,3]]=1
```

应用例子：one hot (更快的实现见下文)

```python
oneHot = np.zeros((labels.size, num_classes))
oneHot[np.arange(labels.size), labels] = 1
return oneHot # labels : N dimensional 1D array 
```

其中 arange 是 0,1,2, ... ,size-1 的整型 np 数组

##### 遍历

以二维为例

```python
rows, cols = img0.shape[:2]
for x0 in range(rows):
    for y0 in range(cols):
        img[x0, y0] = 255
```

```python
rows, cols = img1.shape
    img = np.empty((rows, cols*2), img1.dtype)
    for i, v in np.ndenumerate(img1):
        img[i] = img1[i]
        img[(i[0], i[1]+cols)] = img2[i]
```





#### 常规运算

##### 初等

$e^k$

```python
np.exp(k)
# 如 np.exp([-1,0,1]), 即可以传 list，返回 ndarray
```

$\lg(k)$

```python
np.log(k)
```

`np.square` 逐个元素求平方

##### 浮点相等

两数是否在某个阈值内相近：(绝对误差)

```
np.isclose(a,b,atol=k)
```

##### 求和

对二维，逐行和逐列分别是参数 `axis=1`, `axis=0` 且结果会降维，不填就降成常数，如果保持二维：

```python
arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
np.sum(arr) # 78
np.sum(arr, axis=1)  # 输出: array([10, 26, 42])
np.sum(arr, axis=1, keepdims=True)  # 输出: array([[10], [26], [42]])
```

##### 求最值

min, max 或取得最值的地方：argmin, argmax (第一个最值)

```python
np.argmax(np.array([[1,5,2,5],[3,2,1,3]]),axis=1) # array([1, 0])
```

缩减到某个范围内 `x = np.clip(x, -500, 500)`

##### 随机

种子：(设置了之后，pandas 的一些方法也会固定下来)

```python
np.random.seed(23)
```

随机整数：获取$[a,b)$内的随机整数。

```python
np.random.randint(a,b)
```

在一个数组$a$内随机选取$k$个(会重复)的元素：

```python
np.random.choice(a,k)
```

长为 n 的随机全排列：

```
np.random.permutation(n)
```

高斯分布，如：

```python
np.random.normal(mean, sigma, image.shape).astype(dtype=np.float32)
```

均匀分布：

```python
np.random.uniform(low=0.0, high=1.0, size=(5,5))
np.random.uniform(-1, 1, (1000, d))
np.random.uniform(0,1) #取一个
```

随机数组，每个数概率不同：(下例数组长为 100)

```python
np.random.choice([0, 1], 100, p=[0.98, 0.02])
np.random.choice(a=range(10), p=bin_probs) #取一个[0,10),概率各不用
```

二项分布：size是多少个同样的次数实验，返回每个元素是进行这么多次试验成功了几次的整形数组形状是size，每个元素表示一次平行的次数次试验

```python
np.random.binomial(实验次数,成功率, size)
```

##### 组合数学

阶乘：

```python
permutation = np.math.factorial(n) / np.math.factorial(n - k)
print("排列:", permutation) # n 个选 k 个

# 计算组合
combination = np.math.factorial(n) / (np.math.factorial(k) * np.math.factorial(n - k))
print("组合:", combination)
```

二项分布：

```python
import numpy as np

# 模拟二项分布
n = 10  # 试验的次数
p = 0.5  # 每次试验成功的概率
k = 4  # 成功的次数
simulated_probability = np.random.binomial(n, p, size=10000).tolist().count(k) / 10000
print("模拟概率:", simulated_probability)

# 计算二项分布概率
from scipy.special import comb

probability = comb(n, k) * (p ** k) * ((1 - p) ** (n - k))
print("计算概率:", probability)
```



##### 数组

均值：

```python
np.mean(arr)
```

标准差

```python
np.std(arr)
```

逆矩阵： //dack

```python
np.linalg.inv(arr)
```

限定范围(将高于低于边界的设为边界值)：

```python
np.clip(arr, minv, maxv)
```

按行/列运算，方法：[参考](https://zhuanlan.zhihu.com/p/447785621)，`.sum(axis=0/1/...)`, `.mean`，如：

```python
sumVert = ((255-img)//255).sum(axis=0)
sumHori = ((255-img)//255).sum(axis=1)
```

排序：`np.sort`，不会改变传入的参数。除非使用对象的 `.sort` 方法

求差分：

```python
a = np.array([1, 2, 4, 7, 11])
diff_a = np.diff(a)
print(diff_a)  # 输出: [1 2 3 4]
diff_a_2 = np.diff(a, n=2) #二阶差分
print(diff_a_2)  # 输出: [1 1 1]
```

求百分位数，如 97th 百分位数表示一个数，在一组数据中有 97% 的数据小于或等于该值，而有 3% 的数据大于该值，即分位数。

```python
data = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
percentile_97 = np.percentile(data, 97) # 9.73
```

##### 统计

###### 方差

```python
import numpy as np
# 创建一个简单的数据集
data = np.array([1, 2])
# 使用 NumPy 计算标准差，默认 ddof=0（总体标准差）
numpy_std_population = np.std(data) # 即分母 N
# 使用 NumPy 计算标准差，设置 ddof=1（样本标准差）
numpy_std_sample = np.std(data, ddof=1) # 即分母 N-1
```

对每列分别计算：`np.std(inp, axis=0)`



##### 拼接

如样本特征增广：

```python
X = np.column_stack((np.ones(x_squared.shape), x_squared))#x_squared是一维数组np.array([-1, 0, 1, 2, 3])平方
```

```python
x = np.array([1, 2, 3, 4, 5])
y = np.array([2, 4, 5, 4, 5])
A = np.vstack([x, np.ones(len(x))]).T
#array([[1., 1.],
#       [2., 1.],
```

```python
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
c = np.c_[a, b] # 打竖拼接
'''[[1 4]
 [2 5]
 [3 6]]'''
X = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])
X_b = np.c_[np.ones((len(X), 1)), X]
'''[[1. 1. 2. 3.]
 [1. 4. 5. 6.]
 [1. 7. 8. 9.]]'''
```



#### 线性代数

##### 乘法

点乘：`a*b` 或 `np.multiply(a,b)` 矩阵或向量

- multiply 可以标量对矩阵/向量，会广播

矩阵乘法：`np.dot(a,b)` 或 `a.dot(b)`

- a,b 都是一维，做向量内积
- a,b 都是二维，做矩阵乘法(叉乘而不是点乘)，等效于 `a@b`
- 高维，根据数组的最后两个维度来执行矩阵乘法，并按照广播规则处理其他维度

如果对一维向量做 `a@b`，等效于内积元素和，即 `np.sum(a*b)`

##### 逆元

求矩阵的转置、逆元、矩阵乘法以求和正规方程：

```python
coefficients = np.linalg.inv(X.T @ X) @ X.T @ y
```

##### 线性回归

其他解法和更多例子参见 `应用举例-线性回归`

`np.linalg.lstsq(A,B,rcond)` 求解过定方程组(方程数多于未知数)

- `A` 是设计矩阵。
- `B` 是观测值向量。
- `rcond` 是一个用于判断奇异值的阈值。

函数返回四个值：

1. 模型系数。
2. 残差平方和。
3. `A` 的秩。
4. `A` 的奇异值

```python
A = np.array([[1, 1], [1, 2], [1, 3]])
B = np.array([6, 5, 7])
x, residuals, rank, s = np.linalg.lstsq(A, B, rcond=None)
```



##### 多项式回归

如拟合 $ax^2+bx+c$，返回 `[a,b,c]`。

```python
x = np.array([1, 2, 3, 4, 5])
y = np.array([5, 7, 9, 11, 13])
coefficients = np.polyfit(x, y, 2)
```

高级选项，比如权重和误差估计，允许更复杂的拟合分析。

#### 其他运算

##### where/zscore

```
np.where(condition, [x, y])
```

- `condition`：一个布尔数组，其中的每个元素都对应一个条件判断。
- `x`：当条件为 `True` 时选择的值。
- `y`：当条件为 `False` 时选择的值。
- 返回值：一个与 `condition` 形状相同的数组，其中包含来自 `x` 或 `y` 的元素，取决于对应位置的条件是 `True` 还是 `False`。

如 z-scoring (一般不用特判，即分母为零直接 nan)

```python
def normalize_data(inp):
    mean = np.mean(inp, axis=0)
    std = np.std(inp, axis=0)
    import warnings
    with warnings.catch_warnings():
        warnings.simplefilter("ignore", category=RuntimeWarning)
        normalized_inp = np.where(std == 0, 0, (inp - mean) / std)
    return normalized_inp
```

> 无需手写：
>
> ```python
> from scipy import stats
> stats.zscore(a,axis=0)
> ```



##### histogram

`np.histogram` 是 NumPy 库中的一个函数，用于计算一维数据的直方图。直方图是一种展示数据分布的图表，其中数据被分组成不同的“桶”或“箱”，每个桶包含了一定范围内的数据点数量。

`np.histogram` 函数接受以下参数：

- `a`：输入的数据，一维数组。

- ```
  bins
  ```

  ：可以是以下几种：

  - 整数：表示要使用的箱子的数量。
  - 序列：指定每个箱子边界的数组。
  - 字符串：一种用于计算最佳箱子数量的方法（例如，'auto', 'fd', 'doane', 'scott', 'stone', 'rice', 'sturges' 或 'sqrt'）。

- `range`：形式为 `(min, max)`，用来指定要包括在直方图中的数据范围。如果没有提供，就使用所有数据的最小值和最大值。

- `normed` 或 `density`：这个参数在不同版本的 NumPy 中可能有所不同。在旧版本中可能是 `normed`，在新版本中是 `density`。如果设置为 `True`，直方图会被归一化，使得箱子下的面积（或箱子的总高度）等于1。

- `weights`：每个数据点的权重数组，这允许每个数据点对直方图的贡献进行加权。

- `cumulative`：如果为 `True`，则计算直方图的累积分布，这意味着每个箱子中的计数是该箱子和所有较小箱子中的计数的总和。

函数返回两个数组：

- `hist`：每个箱子中的计数或者权重总和。
- `bin_edges`：一个数组，其长度比 `hist` 多1，表示箱子的边界。

下面是一个简单的例子：

```
data = np.random.randn(1000)
hist, bin_edges = np.histogram(data, bins=10, range=(-3, 3), density=False)
```

在这个例子中，我们生成了1000个标准正态分布的随机数，然后计算了这些数据的直方图，将数据分成了10个箱子，范围从-3到3。`density=False` 意味着我们在每个箱子中得到的是计数，而不是概率密度。

```python
hist, bin_edges = np.histogram(observed_values, bins=10)
bin_probs = hist / hist.sum()# 计算每个bin的概率（面积）
```



如果你想要绘制直方图，可以使用 Matplotlib 库的 `plt.hist` 函数，它会自动计算直方图并且还会绘制出来。

##### 错误处理

如 $\dfrac{2z}{x+y}$

```python
def depth_percentage(arr):
    x, y, z = arr[:, 0], arr[:, 1], arr[:, 2]
    with np.errstate(divide='ignore', invalid='ignore'):
        depth_pct = 100 * (2 * z) / (x + y)
        depth_pct[np.isinf(depth_pct)] = np.nan  # 将无限值替换为nan
    return depth_pct
```



#### 输出配置

小数不需要以科学计数法的形式输出：

```python
np.set_printoptions(suppress=True)
```

- precision：控制输出的小数点个数，默认是8
- threshold：控制输出的值的个数，其余以…代替；
  当设置打印显示方式`threshold=np.nan`，意思是输出数组的时候`完全输出，不需要省略号将中间数据省略`

零除警报消除：[参考](https://blog.csdn.net/baidu_41836513/article/details/118417019)

```python
np.seterr(divide='ignore',invalid='ignore')
```





#### 应用举例

##### 独热

高效：(单一特征的话 flatten)

```python
def one_hot_encoding(labels, num_classes=10):
    return np.eye(num_classes)[labels]
one_hot_encoding(np.array([3,4,1]))
def one_hot_encoding(labels, num_classes=10):
    return np.eye(num_classes)[labels.flatten()]
one_hot_encoding(np.array([[3],[4],[1]]))
```



##### 图片加噪手写

```python
def gaussian_noise(img, mean=0.1, sigma=0.1):
    image = np.array(img / 255, dtype=np.float32)
    noise = np.random.normal(mean, sigma, img.shape).astype(dtype=np.float32)
    output = image + noise
    output = np.clip(output, 0, 1)
    output = np.uint8(output * 255)
    return output


def salt_pepper_noise(img, prob=0.02):

    def add_uniform_noise(img, prob, val):
        h, w = img.shape[:2]
        noise = np.random.uniform(low=0.0, high=1.0, size=(h, w))
        noise = noise.astype(dtype=np.float32)
        mask = np.zeros(shape=(h, w), dtype=np.uint8) + val
        idx = noise > prob
        mask = mask * (~idx)
        output = img * idx[:, :] + mask[:, :]
        output = np.clip(output, 0, 255)
        output = np.uint8(output)
        return output

    img = add_uniform_noise(img, prob, 255)
    img = add_uniform_noise(img, prob, 0)
    return img
```



##### 图片FFT

```python
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np

img = mpimg.imread(r'res\Fig0804(a).tif')
f = np.fft.fft2(img)
f = np.fft.fftshift(f)
fimg = np.log(np.abs(f))
f2 = np.fft.ifftshift(f)
f2 = np.fft.ifft2(f2)
f2img = np.abs(f2)

plt.subplot(131)
plt.imshow(img, 'gray')
plt.subplot(132)
plt.imshow(fimg, 'gray')
plt.subplot(133)
plt.imshow(f2img, 'gray')
plt.show()
```

低通滤波：

```python
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np

img = mpimg.imread(r'res\Fig0804(a).tif')
f = np.fft.fft2(img)
f = np.fft.fftshift(f)


def ILPF(img, d0, N=1):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            if dis <= d0:
                h[y, x] = 1**N
            else:
                h[y, x] = 0**N
    return h


def BLPF(img, d0, N=2):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            h[y, x] = 1 / (1 + (dis / d0)**N)
    return h


def GLPF(img, d0, N=2):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            h[y, x] = np.exp(-dis**N / (2 * d0**N))
    return h


def ifft(f):
    f2 = np.fft.ifftshift(f)
    f2 = np.fft.ifft2(f2)
    return np.abs(f2)


img2 = ifft(ILPF(f, 15) * f)
img3 = ifft(BLPF(f, 15) * f)
img4 = ifft(GLPF(f, 15) * f)
plt.subplot(221)
plt.imshow(img, 'gray')
plt.subplot(222)
plt.imshow(img2, 'gray')
plt.subplot(223)
plt.imshow(img3, 'gray')
plt.subplot(224)
plt.imshow(img4, 'gray')
plt.show()
```

高通滤波：

```python
def ILPF(img, d0, N=1):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            if dis <= d0:
                h[y, x] = 0**N
            else:
                h[y, x] = 1**N
    return h


def BLPF(img, d0, N=2):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            if dis == 0:
                h[y, x] = 0
            else:
                h[y, x] = 1 / (1 + (d0 / dis)**N)
    return h


def GLPF(img, d0, N=2):
    h = np.empty_like(img, dtype=float)
    m, n = img.shape
    midx, midy = n // 2, m // 2
    for x in range(n):
        for y in range(m):
            dis = ((x - midx)**2 + (y - midy)**2)**0.5
            h[y, x] = 1 - np.exp(-dis**N / (2 * d0**N))
    return h
```



##### 熵权TOPSIS

[TOPSIS理论](https://blog.csdn.net/m0_58585940/article/details/127700230) [熵权法理论](https://zhuanlan.zhihu.com/p/161372016) [熵权TOPSIS公式](https://blog.csdn.net/qq_42374697/article/details/105901229) [参考实现](https://blog.csdn.net/NIH2221/article/details/119893572)

```python
import numpy as np
import openpyxl as xls


def read(path):
    '''path is .xlsx file, the first line is column name, other lines are data'''
    wb = xls.load_workbook(path)
    sh = wb.worksheets[0]
    rows = sh.max_row-1
    cols = sh.max_column
    # one line np.array one table.col(var)
    # each line contains all table.row data
    res = np.zeros((cols, rows), np.float64)
    for i in range(cols):
        for j in range(rows):  # skip header
            cor = '%c%d' % (chr(65+i), j+2)
            val = sh[cor].value
            res[i, j] = val
    # print('read:\n', res)
    return res


def modify(data, desc):
    '''desc is file descripting column type that:
    1 denotes that the bigger the better
    2 denotes that the smaller the better
    3 denotes that the nearer one specific the better
    4 denotes that the nearer one specific interval the better
    (3, 4 is not needed in this problem)
    where better means a bigger value of light pollution
    desc is python list type file content like [1,2,1]'''
    with open(desc) as f:
        typ = eval(f.read())
    col = data.shape[0]
    for i in range(col):
        # bigger -> better need not predeal
        if typ[i] == 2:  # smaller -> better
            data[i] = np.max(data[i])-data[i]

    # standardize matrix
    k = np.power(np.sum(pow(data, 2), axis=1), 0.5)
    for i in range(k.size):
        for j in range(data[i].size):
            data[i, j] = data[i, j]/k[i]
    # print('modify:\n', data)
    return data


def entropy(data):
    '''return each w of data var'''
    # num of var, num of table row data
    n, m = data.shape
    mx = np.max(data, axis=1)  # max of each var
    mi = np.min(data, axis=1)  # min of each var
    for i in range(n):
        data[i] = (data[i]-mi[i])/(mx[i]-mi[i])
    s = np.sum(data, axis=1)
    for i in range(n):
        data[i] = data[i]/s[i]
    a = data * 1.0
    a[np.where(data == 0)] = 0.0001  # avoid ln0
    e = (-1.0 / np.log(m)) * np.sum(data*np.log(a), axis=1)
    w = (1-e)/np.sum(1-e)
    return w


def topsis(data, w):
    n, m = np.shape(data)
    mx = np.max(data, axis=1)
    mi = np.min(data, axis=1)
    ans = np.zeros(m, data.dtype)
    for i in range(m):  # each table row data
        mxsum = misum = 0
        for j in range(n):
            mxsum += w[j]*np.power(data[j,i]-mx[j], 2)
            misum += w[j]*np.power(data[j,i]-mi[j], 2)
        mxsum = pow(mxsum, 0.5)
        misum = pow(misum, 0.5)
        ans[i] = misum / (misum + mxsum)
    ans = ans / np.sum(ans)
    # print('topsis:\n', ans)
    return ans


data = read('topsis_data.xlsx')
data = modify(data, 'topsis_desc.txt')
w = entropy(data)
data = topsis(data, w)
print(data)
```

数据：

```
good	great	awful
1	1	5
1	9	0
4	1	3
5	9	1
1	8	1
4	1	2
```

```python
[1,1,2]
```



##### 遗传算法

[题目](https://blog.csdn.net/a_hui_tai_lang/article/details/119900038)

要最求最小值的二元函数：

```python
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

def fitness_func(X):
    # 目标函数，即适应度值，X是种群的表现型
    a = 10
    pi = np.pi
    x = X[:, 0]
    y = X[:, 1]
    return 2 * a + x ** 2 - a * np.cos(2 * pi * x) + y ** 2 - a * np.cos(2 * 3.14 * y)

def decode(x, a, b):
    """解码，即基因型到表现型"""
    xt = 0
    for i in range(len(x)):
        xt = xt + x[i] * np.power(2, i)
    return a + xt * (b - a) / (np.power(2, len(x)) - 1)

def decode_X(X: np.array):
    """对整个种群的基因解码，上面的decode是对某个染色体的某个变量进行解码"""
    X2 = np.zeros((X.shape[0], 2))
    for i in range(X.shape[0]):
        xi = decode(X[i, :20], -5, 5)
        yi = decode(X[i, 20:], -5, 5)
        X2[i, :] = np.array([xi, yi])
    return X2

def select(X, fitness):
    """根据轮盘赌法选择优秀个体"""
    fitness = 1 / fitness  # fitness越小表示越优秀，被选中的概率越大，做 1/fitness 处理
    fitness = fitness / fitness.sum()  # 归一化
    idx = np.array(list(range(X.shape[0])))
    X2_idx = np.random.choice(idx, size=X.shape[0], p=fitness)  # 根据概率选择
    X2 = X[X2_idx, :]
    return X2

def crossover(X, c):
    """按顺序选择2个个体以概率c进行交叉操作"""
    for i in range(0, X.shape[0], 2):
        xa = X[i, :]
        xb = X[i + 1, :]
        for j in range(X.shape[1]):
            # 产生0-1区间的均匀分布随机数，判断是否需要进行交叉替换
            if np.random.rand() <= c:
                xa[j], xb[j] = xb[j], xa[j]
        X[i, :] = xa
        X[i + 1, :] = xb
    return X

def mutation(X, m):
    """变异操作"""
    for i in range(X.shape[0]):
        for j in range(X.shape[1]):
            if np.random.rand() <= m:
                X[i, j] = (X[i, j] + 1) % 2
    return X



def ga():
    """遗传算法主函数"""
    c = 0.3  # 交叉概率
    m = 0.05  # 变异概率
    best_fitness = []  # 记录每次迭代的效果
    best_xy = []
    iter_num = 100  # 最大迭代次数
    X0 = np.random.randint(0, 2, (50, 40))  # 随机初始化种群，为50*40的0-1矩阵
    for i in range(iter_num):
        X1 = decode_X(X0)  # 染色体解码
        fitness = fitness_func(X1)  # 计算个体适应度
        X2 = select(X0, fitness)  # 选择操作
        X3 = crossover(X2, c)  # 交叉操作
        X4 = mutation(X3, m)  # 变异操作
        # 计算一轮迭代的效果
        X5 = decode_X(X4)
        fitness = fitness_func(X5)
        best_fitness.append(fitness.min())
        x, y = X5[fitness.argmin()]
        best_xy.append((x, y))
        X0 = X4
    # 多次迭代后的最终效果
    print("最优值是：%.5f" % best_fitness[-1])

    print("最优解是：x=%.5f, y=%.5f" % best_xy[-1])
    # 最优值是：0.00000
    # 最优解是：x=0.00000, y=-0.00000
    # 打印效果
    plt.plot(best_fitness, color='r')
    plt.show()

ga()

```



##### 层次分析

[参考0](https://blog.csdn.net/bb_sy_w/article/details/107577856) [参考](https://blog.csdn.net/Trisyp/article/details/106017533?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-106017533-blog-80405807.pc_relevant_recovery_v2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-106017533-blog-80405807.pc_relevant_recovery_v2&utm_relevant_index=3)

```python
import numpy as np
import pandas as pd
import warnings

class AHP:
    def __init__(self, criteria, samples):
        self.RI = (0, 0, 0.58, 0.9, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49)
        self.criteria = criteria
        self.samples = samples
        self.num_criteria = criteria.shape[0]
        self.num_project = samples[0].shape[0]

    def calculate_weights(self, input_matrix): #废弃
        input_matrix = np.array(input_matrix)
        n, n1 = input_matrix.shape
        assert n==n1, "the matrix is not orthogonal"
        for i in range(n):
            for j in range(n):
                if np.abs(input_matrix[i,j]*input_matrix[j,i]-1) > 1e-7:
                    raise ValueError("the matrix is not symmetric")
        eigen_values, eigen_vectors = np.linalg.eig(input_matrix)
        max_eigen = np.max(eigen_values)
        max_index = np.argmax(eigen_values)
        eigen = eigen_vectors[:, max_index]
        eigen = eigen/eigen.sum()
        if n > 9:
            CR = None #其实就是报错，而不是警告
            warnings.warn("can not judge the uniformity")
        else:
            CI = (max_eigen - n)/(n-1)
            CR = CI / self.RI[n-1]
        return max_eigen, CR, eigen

    def calculate_mean_weights(self,input_matrix):
        input_matrix = np.array(input_matrix)
        n, n1 = input_matrix.shape
        assert n == n1, "the matrix is not orthogonal"
        A_mean = []
        for i in range(n):
            mean_value = input_matrix[:, i]/np.sum(input_matrix[:, i])
            A_mean.append(mean_value)
        eigen = []
        A_mean = np.array(A_mean)
        for i in range(n):
            eigen.append(np.sum(A_mean[:, i])/n)
        eigen = np.array(eigen)
        matrix_sum = np.dot(input_matrix, eigen)
        max_eigen = np.mean(matrix_sum/eigen)
        if n > 9:
            CR = None
            warnings.warn("can not judge the uniformity")
        else:
            CI = (max_eigen - n) / (n - 1)
            CR = CI / self.RI[n - 1]
        return max_eigen, CR, eigen

    def run(self, method="calculate_weights"):
        weight_func = eval(f"self.{method}")
        max_eigen, CR, criteria_eigen = weight_func(self.criteria)
        print('准则层：最大特征值{:<5f},CR={:<5f},检验{}通过'.format(max_eigen, CR, '' if CR < 0.1 else '不'))
        print('准则层权重={}\n'.format(criteria_eigen))

        max_eigen_list, CR_list, eigen_list = [], [], []
        for sample in self.samples:
            max_eigen, CR, eigen = weight_func(sample)
            max_eigen_list.append(max_eigen)
            CR_list.append(CR)
            eigen_list.append(eigen)

        pd_print = pd.DataFrame(eigen_list, index=['准则' + str(i+1) for i in range(self.num_criteria)],
                                columns=['方案' + str(i+1) for i in range(self.num_project)],
                                )
        pd_print.loc[:, '最大特征值'] = max_eigen_list
        pd_print.loc[:, 'CR'] = CR_list
        pd_print.loc[:, '一致性检验'] = pd_print.loc[:, 'CR'] < 0.1
        print('方案层')
        print(pd_print)

        # 目标层
        obj = np.dot(criteria_eigen.reshape(1, -1), np.array(eigen_list))
        print('\n目标层', obj)
        print('最优选择是方案{}'.format(np.argmax(obj)+1))
        return obj


if __name__ == '__main__':
    # 准则重要性矩阵
    criteria = np.array([[1, 2, 7, 5],
                         [1 / 2, 1, 4, 3],
                         [1 / 7, 1 / 4, 1, 1 / 2],
                         [1 / 5, 1 / 3, 2, 1]])

    # 对每个准则，方案优劣排序
    sample1 = np.array([[1, 2, 8], [1/2, 1, 6], [1/8, 1/6, 1]])
    sample2 = np.array([[1, 2, 5], [1 / 2, 1, 2], [1 / 5, 1 / 2, 1]])
    sample3 = np.array([[1, 1, 3], [1, 1, 3], [1 / 3, 1 / 3, 1]])
    sample4 = np.array([[1, 3, 4], [1 / 3, 1, 1], [1 / 4, 1, 1]])

    samples = [sample1, sample2, sample3, sample4]
    a = AHP(criteria, samples).run("calculate_mean_weights")
```

> 已知权重转矩阵：
>

##### 线性回归

###### 梯度下降

以 MSE 误差，求 $h=w_0+w_1 x^2$ 为例，梯度下降：

```python
import numpy as np
x = np.array([-1, 0, 1, 2, 3])
y = np.array([1, 2, 2, 5, 10])

def compute_gradients(w0, w1, x, y):
    m = len(x)
    error = (w0 + w1 * x**2) - y
    grad_w0 = (1/m) * np.sum(error)
    grad_w1 = (1/m) * np.sum(error * x**2)
    return grad_w0, grad_w1

def gradient_descent(x, y, learning_rate, iterations):
    w0 = 0
    w1 = 0
    m = len(x)
    for _ in range(iterations):
        grad_w0, grad_w1 = compute_gradients(w0, w1, x, y)

        w0 = w0 - learning_rate * grad_w0
        w1 = w1 - learning_rate * grad_w1
    return w0, w1

learning_rate = 0.01
iterations = 10000

w0_gd, w1_gd = gradient_descent(x, y, learning_rate, iterations)
print(w0_gd, w1_gd)
```



###### 最小二乘法

(手写)

```python
x = np.array([-1,0,1,2,3])**2
y = np.array([1,2,2,5,10])
mean_x = np.mean(x)
mean_y = np.mean(y)
n = len(x)
numerator = np.sum((x - mean_x) * (y - mean_y))
denominator = np.sum((x - mean_x) ** 2)
a = numerator / denominator
b = mean_y - (a * mean_x)
print(f"线性回归方程为: y = {a}x + {b}")
```



调库：(或多项式拟合：`np.polyfit`)

```python
x = np.array([1, 2, 3, 4, 5])
y = np.array([2, 4, 5, 4, 5])
A = np.vstack([x, np.ones(len(x))]).T #[[1,1],[2,1],[3,1],[4,1],[5,1]]
a, b = np.linalg.lstsq(A, y, rcond=None)[0]
```

多个变量：

```python
X = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [10, 11, 12]
])
Y = np.array([2, 3, 4, 5])
X_b = np.c_[np.ones((len(X), 1)), X]
coefficients = np.linalg.lstsq(X_b, Y, rcond=None)[0]
```



###### 正规方程

令 $z=x^2$，则要求拟合 $h=w_0+w_1z$。做增广，令 $X=(1,z)=(1,x^2)$。所求为：$h=wX$。令 $h=y$，正规方程为：
$$
w=(X^TX)^{-1}X^Ty
$$
编写代码：

```python
import numpy as np
x = np.array([-1, 0, 1, 2, 3])
y = np.array([1, 2, 2, 5, 10])
x_squared = x**2
X = np.column_stack((np.ones(x_squared.shape), x_squared))
coefficients = np.linalg.inv(X.T @ X) @ X.T @ y
w_0, w_1 = coefficients
print(w_0, w_1) #1.0555555555555551 0.9814814814814814
```



### matplotlib

是第三方库，需要手动安装。[官方文档](https://matplotlib.org/3.6.0/gallery/index.html)

通常如此加载：

```python
import matplotlib.pyplot as plt
```

#### 绘图

##### 基础

分为绘制和展示两部分：

```python
plt.plot(数据) #折线图
plt.show() #如果plot多次，自动赋予不同颜色
```

如：

```python
plt.plot([1,4,9,16,25])#点(0,1),(1,4),...，下类同;也可以nparray
plt.plot([-1,-1,-1,-1])
plt.show()
```

保存到文件：(重名覆盖)

```python
plt.savefig(输出文件名含后缀)
```



##### 散点

绘制二维散点点图：[具体参考](https://www.runoob.com/matplotlib/matplotlib-scatter.html)

```python
plt.scatter([1,5,10],[-3,-2,-1],s=10)
#s是点的面积，画三个点(1,-3),(5,-2),...
```

```python
plt.scatter([1,5,10],[-3,-2,-1],s=100,edgecolor='none')
#点比较连续的时候增设一个默认参数显示效果更佳
```

可以绘制单个点：

```python
plt.scatter(1,2,s=50)
```

可以用marker属性描述点型：(每个点实心) [参考](https://www.runoob.com/matplotlib/matplotlib-marker.html)

```python
marker='x'; marker='o'
```

> - markersize，简写为 ms：定义标记的大小。
> - markerfacecolor，简写为 mfc：定义标记内部的颜色。
> - markeredgecolor，简写为 mec：定义标记边框的颜色。
>
> ```python
> plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r')
> plt.plot(ypoints, marker = 'o', ms = 20, mec = '#4CAF50', mfc = '#4CAF50')
> ```



##### 其他

[柱状图参考](https://www.runoob.com/matplotlib/matplotlib-bar.html)

[饼图参考](https://www.runoob.com/matplotlib/matplotlib-pie.html)

横纵坐标旋转：`plot(ylt,xlt)`

```python
lt = list(range(img.shape[0]-1, -1, -1))
plt.plot(sumHori, lt) #x坐标点集, y坐标点集
```

> ```python
> # 画多条线, fmt 是颜色等, [表示可选]
> plot([x], y, [fmt], [x2], y2, [fmt2], ..., **kwargs)
> plot(x, y, 'bo')  # 创建 y 中数据与 x 中对应值的二维线图，使用蓝色实心圈绘制(o是空心散点而不是无点折线)
> plot(y, 'r+')     # 使用红色 + 号
> # fmt = '[marker][line][color]'
> # 例如 o:r，o 表示实心圆标记，: 表示虚线，r 表示颜色为红色。
> ```
>
> [具体参考](https://www.runoob.com/matplotlib/matplotlib-marker.html)



##### 举例

###### 横纵坐标转置

```python
img = cv2.imread('../../imgs/02.png')
img = toGrey(img)
img = toBinary(img, getThrestHold(img)) #二值图像
sumVert = ((255-img)//255).sum(axis=0)
sumHori = ((255-img)//255).sum(axis=1)

plt.subplot(221)
plt.imshow(img, 'gray')
plt.subplot(222)
# lt = list(range(img.shape[0]-1, -1, -1))
lt = list(range(img.shape[0]))
plt.ylim(img.shape[0], 0)  # 这个倒了lt自己也会倒
plt.plot(sumHori, lt)
plt.subplot(223)
plt.plot(sumVert)
plt.show()
```

###### 半平面和点涂色

```python
w = [1, -1, -1] # 1-x_1-x_2
def g2(): # 分界线所在也是红色的
    c, a, b = w
    
    x = np.linspace(-1, 2, 400)
    y = np.linspace(-1, 2, 400)
    X, Y = np.meshgrid(x, y)

    Z = a*X + b*Y + c

    plt.figure(figsize=(6,6))
    plt.contourf(X, Y, Z, levels=[0, Z.max()], colors='red', alpha=0.3)

    points = {'(0,0)': (0, 0), '(0,1)': (0, 1), '(1,0)': (1, 0), '(1,1)': (1, 1)}
    for label, (x, y) in points.items():
        color = 'blue' if label == '(1,1)' else 'red'
        plt.scatter(x, y, color=color)
        plt.text(x, y, label, fontsize=12, horizontalalignment='right')

    plt.xlim(-1, 2)
    plt.ylim(-1, 2)
    plt.axhline(0, color='black',linewidth=0.5)
    plt.axvline(0, color='black',linewidth=0.5)
    plt.grid(color = 'gray', linestyle = '--', linewidth = 0.5)
    plt.title('Graph of ax + by + c >= 0 with specific points marked')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()
```





#### 属性

##### 基本

图表预设定：(必须放在绘图，如scatter之前)

```python
plt.figure(figsize=(10,5))
plt.figure(figsize=(10,5),dpi=128) #改单位
```

属性：[参考](https://www.runoob.com/matplotlib/matplotlib-marker.html)

> **颜色字符：**'b' 蓝色，'m' 洋红色，'g' 绿色，'y' 黄色，'r' 红色，'k' 黑色，'w' 白色，'c' 青绿色，'#008000' RGB 颜色符串。多条曲线不指定颜色时，会自动选择不同颜色。
>
> **线型参数：**'‐' 实线，'‐‐' 破折线，'‐.' 点划线，':' 虚线。
>
> **标记字符：**'.' 点标记，',' 像素标记(极小点)，'o' 实心圈标记，'v' 倒三角标记，'^' 上三角标记，'>' 右三角标记，'<' 左三角标记., 'H' 六边形, 'D'菱形..等等。(marker)
>
> ```python
> plot(y, 'r+')     # 使用红色 + 号
> ```

- 线宽 linewidth / lw

  ```python
  plt.plot(ypoints, linewidth = '12.5')
  ```

- 线形状linestyle [参考](https://www.runoob.com/matplotlib/matplotlib-line.html)

  ```python
  plt.plot(ypoints, linestyle = 'dotted')
  ```

- 线色 c / color，使用单词或范围为$[0,1]$的RGB三元tuple（1浅0深），一般使用单词即可，使用tuple可能会出问题 [参考](https://www.runoob.com/html/html-colorvalues.html)

  颜色可以映射，如：

  ```python
  xv=list(range(1,1001))
  yv=[x**2 for x in xv] #蓝色由浅到深
  plt.scatter(xv,yv,s=40,edgecolor='none',c=yv,cmap=plt.cm.Blues)
  ```

- 图例名字label [带中文参考](https://www.runoob.com/matplotlib/matplotlib-label.htmls)

图表基本设定：

```python
plt.title('A title',fontsize=24) #标题设置
plt.xlabel('xv',fontsize=14) #x轴名字
plt.ylabel('saw',fontsize=14) 
plt.tick_params(axis='both',labelsize=14) #或x或y，坐标上数字大小
```

> ```python
> import numpy as np
> from matplotlib import pyplot as plt
> import matplotlib
>  
> # fname 为 你下载的字体库路径，注意 SourceHanSansSC-Bold.otf 字体的路径，size 参数设置字体大小
> zhfont1 = matplotlib.font_manager.FontProperties(fname="SourceHanSansSC-Bold.otf", size=18)
> font1 = {'color':'blue','size':20}
> font2 = {'color':'darkred','size':15}
> x = np.arange(1,11)
> y =  2  * x +  5
> 
> # fontdict 可以使用 css 来设置字体样式
> plt.title("菜鸟教程 - 测试", fontproperties=zhfont1, fontdict = font1)
>  
> # fontproperties 设置中文显示，fontsize 设置字体大小
> plt.xlabel("x 轴", fontproperties=zhfont1)
> plt.ylabel("y 轴", fontproperties=zhfont1)
> plt.plot(x,y)
> plt.show()
> ```
>
> title() 方法提供了 loc 参数来设置标题显示的位置，可以设置为: 'left', 'right', 和 'center'， 默认值为 'center'。
>
> xlabel() 方法提供了 loc 参数来设置 x 轴显示的位置，可以设置为: 'left', 'right', 和 'center'， 默认值为 'center'。
>
> ylabel() 方法提供了 loc 参数来设置 y 轴显示的位置，可以设置为: 'bottom', 'top', 和 'center'， 默认值为 'center'。

##### 点样式

```python
plt.plot(dimensions, min_distances, marker='o')
```

- `'o'`: 圆圈
- `'.'`: 点
- `'^'`: 上三角
- `'v'`: 下三角
- `'<'`: 左三角
- `'>'`: 右三角
- `'s'`: 正方形
- `'p'`: 五边形
- `'*'`: 星号
- `'+'`: 加号
- `'x'`: 叉号
- `'D'`: 菱形
- `'H'`: 六边形

##### 坐标轴

锁定坐标轴范围为$x\in[-12,12],y\in[-5,5]$。也可以用 `xlim(a,b)`, `ylim`。可以 $a\ge b$ 则画图序列也跟着倒序。

```python
plt.axis([-12,12,-5,5]) 
```

设置坐标轴坐标尺(每隔多少显示一次数字)：(y同理)

```python
plt.gca().xaxis.set_major_locator(plt.MultipleLocator(1))
```

隐藏坐标轴：(与上面不会冲突)(该命令会引发warning)

```python
plt.axes().get_xaxis().set_visible(False)
plt.axes().get_yaxis().set_visible(False)
```

不显示坐标轴：

```python
plt.axis('off')
```

对数坐标轴：

```python
plt.xscale('log')
```



##### 图例

图例使用：

```python
plt.scatter([0,2,3,4],[3,3,2,3],label='pic1',c='chocolate')
plt.plot([0,1,2,3,4],label='pic2')
plt.legend(loc=2)
plt.show()
```

loc控制图例的方位，具体为：$\left[\matrix{2&3\\1&4}\right]$

##### 网格

添加网格：[参考](https://www.runoob.com/matplotlib/matplotlib-grid.html)

```python
plt.grid()
```

> - b：可选，默认为 None，可以设置布尔值，true 为显示网格线，false 为不显示，如果设置 `**kwargs` 参数，则值为 true。
> - which：可选，可选值有 'major'、'minor' 和 'both'，默认为 'major'，表示应用更改的网格线。
> - axis：可选，设置显示哪个方向的网格线，可以是取 'both'（默认），'x' 或 'y'，分别表示两个方向，x 轴方向或 y 轴方向。
> - `**kwargs`：可选，设置网格样式，可以是 color='r', linestyle='-' 和 linewidth=2，分别表示网格线的颜色，样式和宽度。

##### 保存

保存图表：

```python
plt.savefig('pic.png',bbox_inches='tight') #必须在show之前
```



举例：

```python
import matplotlib.pyplot as plt

xv = list(range(1, 27))
yv = [1, 2, 4, 8, 16, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 21, 22, 23, 24, 25, 26, 1, 2, 3, 4]
plt.figure(figsize=(13, 8))
plt.grid()
plt.plot(xv, yv, 'o-') #点线形状
plt.xlabel('n')
plt.ylabel('cwnd')
for i in zip(xv, yv): #写文本
    plt.annotate('%s' % i[1], xy=(i[0], i[1] + 1))
plt.show()
```



#### 子图

```python
subplot(nrows, ncols, index, **kwargs)
subplot(pos, **kwargs)
subplot(**kwargs)
subplot(ax)
```

以上函数将整个绘图区域分成 nrows 行和 ncols 列，然后从左到右，从上到下的顺序对每个子区域进行编号 `1...N` ，左上的子区域的编号为 1、右下的区域编号为 N，编号可以通过参数 index 来设置。

##### 例子

> ```python
> import matplotlib.pyplot as plt
> import numpy as np
> 
> #plot 1:
> x = np.array([0, 6])
> y = np.array([0, 100])
> 
> plt.subplot(2, 2, 1)
> plt.plot(x,y)
> plt.title("plot 1") #子图标题
> 
> #plot 2:
> x = np.array([1, 2, 3, 4])
> y = np.array([1, 4, 9, 16])
> 
> plt.subplot(2, 2, 2)
> plt.plot(x,y)
> plt.title("plot 2")
> 
> #plot 3:
> x = np.array([1, 2, 3, 4])
> y = np.array([3, 1, 4, 2])
> 
> plt.subplot(2, 2, 3)
> plt.plot(x,y)
> plt.title("plot 3")
> 
> #plot 4:
> x = np.array([1, 2, 3, 4])
> y = np.array([4, 3, 2, 1])
> 
> plt.subplot(224) #这样也行
> plt.plot(x,y)
> plt.title("plot 4")
> 
> plt.suptitle("RUNOOB subplot Test") #大标题
> plt.show()
> ```

> ```python
> import numpy as np
> import matplotlib.pyplot as plt
> 
> def generate_data(d):
>     """生成 d 维的数据集，每个维度包含 1000 个点，每个点的坐标在 [-1, 1] 之间随机生成。"""
>     return np.random.uniform(-1, 1, (1000, d))
> 
> def calculate_distances(data):
>     """计算数据集中的点到原点的欧氏距离，并返回最近和最远的距离。"""
>     distances = np.sqrt(np.sum(data**2, axis=1))
>     return np.min(distances), np.max(distances)
> 
> # 设定一系列维度 d
> dimensions = [2, 4, 8, 16, 32, 64, 128, 256, 512]
> min_distances = []
> max_distances = []
> 
> # 对于每个维度，生成数据并计算距离
> for d in dimensions:
>     data = generate_data(d)
>     min_dist, max_dist = calculate_distances(data)
>     min_distances.append(min_dist)
>     max_distances.append(max_dist)
> 
> # 绘制图表
> plt.figure(figsize=(14, 6))
> 
> # △0(d) 随 d 变化的图表
> plt.subplot(1, 2, 1)
> plt.plot(dimensions, min_distances, marker='o')
> plt.xlabel('Dimension d')
> plt.ylabel('Minimum Distance to Origin (△0(d))')
> plt.title('Minimum Distance to Origin vs Dimension')
> plt.xscale('log')
> 
> # △1(d)/△0(d) 随 d 变化的图表
> plt.subplot(1, 2, 2)
> plt.plot(dimensions, np.array(max_distances) / np.array(min_distances), marker='o')
> plt.xlabel('Dimension d')
> plt.ylabel('Ratio of Max to Min Distance (△1(d)/△0(d))')
> plt.title('Ratio of Max to Min Distance vs Dimension')
> plt.xscale('log')
> 
> plt.tight_layout()
> plt.show()
> ```

#### 图片

##### 常规

本质是对 numpy 二维数组(np.uint8) 绘制，或者对三维数组(第三维RGB等)绘制

```python
import matplotlib.image as mpimg
```

```python
img = mpimg.imread('img/keepOut.jpg') #类型是numpy.ndarray
#读JPG类型是uint8,读PNG类型是float32且有透明通道
plt.imshow(img)
plt.show()
plt.savefig() #与上一行不兼容，建议加 bbox_inches='tight' 去白边框
mpimg.imsave(des, img2) #同理保存
#mpimg.imsave(dest, imgs[i], cmap='gray') 黑白保存
```

> 如：
>
> ```python
> import matplotlib.pyplot as plt
> import matplotlib.image as mpimg
> def keepOut(src, desc):
>     img = mpimg.imread('img/keepOut.jpg')
>     # img2 = mpimg.imread(src)
>     plt.figure(figsize=(10, 10), dpi=60)  # 600*600
>     plt.axis('off')
>     plt.imshow(img)
> 
>     # img2 = mpimg.imread(src)
> 
>     # w, h = [int(i) for i in img2.shape[:2]]
>     # plt.imshow(img2)
>     # plt.show()
>     plt.savefig(desc, bbox_inches='tight')
> keepOut('cf.png', 'out.jpg')
> ```



##### 缩放叠加

手写即可，记得 copy 解除只读，如：

```python
import matplotlib.pyplot as plt
import matplotlib.image as mpimg


def keepOut(src, desc, limx=150, limy=150):
    img = mpimg.imread('img/keepOut.jpg')
    plt.figure(figsize=(10, 10), dpi=60)  # 600*600
    plt.axis('off')

    img1 = img.copy()
    img2 = mpimg.imread(src)
    ox, oy = 225, 40
    rows, cols = img2.shape[:2]
    rx = min(rows, limx)
    ry = min(cols, limy)
    for i in range(rx):
        for j in range(ry):
            x, y = int(i/rx*rows), int(j/ry*cols)
            img1[i+ox][j+oy] = img2[x][y][:3]

    plt.imshow(img1)
    plt.savefig(desc, bbox_inches='tight')
```



##### 灰度拉伸

手写实现 matlab 的 `imshow(,[])`，如：

```python
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

img = mpimg.imread('img2.tif')
rows, cols = img.shape[:2]
plt.figure(figsize=(rows // 10, cols // 10), dpi=10)
plt.axis('off')
img2 = img.copy()
img2 = ( (img - np.min(img) ) / (np.max(img) - np.min(img)))*255
img2 = img2.astype(int)
plt.imshow(img2,cmap="Greys_r") #不加参数是彩色图
#第二个参数建议为'gray'与上者不同
plt.savefig('img20.tif', bbox_inches='tight')
```



##### 任意位置插入

[figimage](https://matplotlib.org/3.6.0/api/_as_gen/matplotlib.pyplot.figimage.html#matplotlib.pyplot.figimage)

注意坐标轴以左下角为原点，x 从左到右，y 从上到下



#### 文字

先搞一张画布：

```python
plt.figure(figsize=(620//20, 700//20), dpi=20, facecolor='grey')
```

> 大概是y中心上角原点，x最左原点

```python
# 设置显示中文字体
plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
```

重新设置坐标范围(不然范围是 $[0,1]$)，并关闭坐标轴显示

```python
plt.axis('off')
plt.xlim([0, 620])
plt.ylim([0, 700])
```

绘制文字：

```python
plt.text(20, 30, text4, fontsize=100)
```

dpi 越高，字体辨认越好，建议 100



#### 形状

矩形示例：

```python
rect = mpatches.Rectangle(
    (10, 80), 650, 200, fill=True, color="silver", alpha=0.5, zorder=1)
plt.gca().add_patch(rect)
```

[颜色参考](https://matplotlib.org/3.6.0/gallery/color/named_colors.html#sphx-glr-gallery-color-named-colors-py)

#### 举例

##### 绘图集成

```python
import numpy as np
from matplotlib_inline import backend_inline
#from d2l import torch as d2l
def use_svg_display():  #@save
    backend_inline.set_matplotlib_formats('svg')
def set_figsize(figsize=(3.5, 2.5)):  #@save
    use_svg_display()
    d2l.plt.rcParams['figure.figsize'] = figsize
#@save
def set_axes(axes, xlabel, ylabel, xlim, ylim, xscale, yscale, legend):
    axes.set_xlabel(xlabel)
    axes.set_ylabel(ylabel)
    axes.set_xscale(xscale)
    axes.set_yscale(yscale)
    axes.set_xlim(xlim)
    axes.set_ylim(ylim)
    if legend:
        axes.legend(legend)
    axes.grid()
#@save
def plot(X, Y=None, xlabel=None, ylabel=None, legend=[], xlim=None,
         ylim=None, xscale='linear', yscale='linear',
         fmts=('-', 'm--', 'g-.', 'r:'), figsize=(3.5, 2.5), axes=None):
    """Plot data points."""

    def has_one_axis(X):  # True if X (tensor or list) has 1 axis
        return (hasattr(X, "ndim") and X.ndim == 1 or isinstance(X, list)
                and not hasattr(X[0], "__len__"))

    if has_one_axis(X): 
        X = [X]
    if Y is None:
        X, Y = [[]] * len(X), X
    elif has_one_axis(Y):
        Y = [Y]
    if len(X) != len(Y):
        X = X * len(Y)

    set_figsize(figsize)
    if axes is None:
        axes = d2l.plt.gca()
    axes.cla()
    for x, y, fmt in zip(X, Y, fmts):
        axes.plot(x,y,fmt) if len(x) else axes.plot(y,fmt)
    set_axes(axes, xlabel, ylabel, xlim, ylim, xscale, yscale, legend)
x = np.arange(0, 3, 0.1)
plot(x, [f(x), 2 * x - 3], 'x', 'f(x)', legend=['f(x)', 'Tangent line (x=1)'])
```



### pandas

[文档](https://pandas.pydata.org/docs/index.html)

#### 基本

##### 读入

支持 `read_csv`, `read_excel`, `read_html`, `read_json`。

###### csv

读 csv: (二维表，行间空行隔开，列间单半角逗号隔开，第一行是表头不算作实际数据)

> [数据集出处](https://faculty.sdu.edu.cn/qiang2chen2/zh_CN/jxzy/545776/content/1793.htm#jxzy)

```python
import pandas as pd
audiometric = pd.read_csv('audiometric.csv')
# 可以试图直接 print 或交互下直接写变量名输出，等于 head5+tail5
# 会输出有几行、几列；返回值是 DataFrame
```

> 可以读 `.tsv`，加参数 `sep='\t'`
>
> 可以读 `.txt`
>
> 增加参数，指定某一列的读入类型：
>
> ```python
> dtype={"fips": str}
> ```

不含表头：`header=None`

不含表头，已知有若干列，分配列名：

```python
pd.read_csv(fp, names=['id', 'name', 'date', 'text'])
```

其 `.shape` 依次是行数(不含表头)、列数。是独有的类型。

若数据里写着 NA (不带引号)而不是数值，读进去是 not a number。

打印前五行数据：(后三行 `tail(3)`)

```python
print(audiometric.head())
```

查看行号 `.index`，列 `.columns`，各列信息 `.info()`

求列的相关系数：

```python
audiometric = pd.read_csv('audiometric.csv')
print(round(audiometric.corr(), 2))
```

绘图展示：

```python
import seaborn as sns
import matplotlib.pyplot as plt
sns.heatmap(round(audiometric.corr(), 2),annot=True)
plt.show()
```

###### excel

需要：

```
pip install openpyxl
```

也可以读 excel，默认第一行是表头，没有列头。如果要列头加默认参数如：[参考](https://blog.csdn.net/qq_18351157/article/details/124865696)

```python
data = pd.read_excel('pca_data.xlsx',index_col=0)
```

`header=n` 跳过前 n 行，第 n+1 行作为表名。(疑似不能和 `skiprows=n` 混用)



###### 构造

使用 dict (key: string, value: list of int / string) 构造。

```python
data = {
    'City': ['London', 'London', 'Paris', 'Paris', 'Berlin', 'Berlin'],
    'Date': ['2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02'],
    'Temperature': [8.0, 7.1, 5.5, 6.2, 0.0, 2.3]
}
df = pd.DataFrame(data)
```

或反过来：

```python
pd.DataFrame([{'name':'lr580','value':580},{'name':'lr581','value':581}])
```

复制：`df_copy = pd.DataFrame(df)`

只有列名的空表：

```python
columns = ['id', 'by', 'text', 'parent', 'time']
pd.DataFrame(columns=columns)
```

只有行号的：

```python
pd.DataFrame(index=diamonds.index)
```

全为 NaN 的：(各列类型 object)

```python
pd.DataFrame(columns=['train_err', 'test_err'], index=range(1, 21))
```

各列 assign 传入：

```python
x = np.arange(1, 101) + np.random.normal(0, 0.5, 100)
y = 2 * ((x + np.random.normal(0, 1, 100)) ** 2) + np.abs(x) * np.random.normal(0, 30, 100)
df_1 = pd.DataFrame().assign(x=x, y=y)
```

从 numpy: (行列名都是 0 开始的数字) (同理传 (1,n) 的给 `df[]=` 可以赋整列)

```python
pd.DataFrame(np.array([[1,2],[3,4],[5,6]]))
```

##### 写入

[参考](https://blog.csdn.net/m0_46419189/article/details/123111493)

###### csv

```python
with pd.ExcelWriter("pca_result.xlsx") as writer:
    data.to_excel(writer, index=True) #单个表单
```

> excel 转 csv:
>
> ```python
> #指定空值的显示方式，否则会在保存时以字符“.”代替，影响后续的数据分析
> data_xls = pd.read_excel(data_file, index_col=0, na_values='')
> data_xls.to_csv(data_name + '.csv', encoding='utf-8')
> ```



> 多 csv 数据合并：
>
> ```python
> merge_list = []
> for i in matches:
>        # 读取风机这部分数据
>        data_df = pd.read_csv(os.path.join(data_dir, i), index_col=False, keep_default_na=False)
>        merge_list.append(data_df)
>     if len(merge_list) > 0:
>            all_data = pd.concat(merge_list,axis=0,ignore_index=True).fillna(".")
>            all_data.to_csv(os.path.join(data_dir, data_basename.split('-')[0]+ '.csv'),index=False) 
> ```

###### md

`.to_markdown(index=False)`。

> 可能需要：
>
> ```
> pip install tabulate
> ```

不加 `index=False` 的话会有第一列是没表头的代表索引。

返回值 str，如：`'|    |   A |   C |\n|---:|----:|----:|\n|  0 |   1 |   4 |\n|  1 |   2 |   3 |\n|  2 |   3 |   5 |'`

同理有 `.to_latex`

##### 基本操作

列名字符串区分大小写。默认每列同一个数据类型。

创建两行数据：

```python
x=pd.DataFrame({'A': [1, 2, 3], 'C': [4, 3, 5]})
print(x)
```

从 numpy 转回来：

```python
pd.DataFrame(nparr, column=x.columns,index=list(range(...)))
```

取一列：`[列名str]`。取行区间`[起:止]` (切片语法同 python)。用下标取就 `iloc[]`

> 如，取前两列外的每一列：`df.iloc[:, 2:]`；取定值 `.iloc[0]['A']`
>
> 取特定若干列：`df[['text', 'num_hashtags']]`；取一列是 series，这样取多列还是 df 类型。
>
> 若干行+若干列举例：`print(df.iloc[:5][['DURATION', 'AFFECTED']])`
>
> 取特定类型的类：
>
> ```python
> df.select_dtypes(include=[np.number])
> df.select_dtypes(include=[np.number]).columns.tolist()
> ```

取单独元素 `.at[行号, 列str]` 或 `.loc[]`，可以取和赋值

> loc 和 iloc 的区别在于，对行 loc 是下标值作索引，iloc 是第几个下标

转 numpy(丢失表头)：`.to_numpy()`，转列表 `.tolist()`，转 set 直接 `set(df[])`，

转字典 `to_dict()`，key 是列(str 或多索引就 tuple，见聚合索引), value 是 dict(行index: 值)

简要统计 `.describe()` 形状 `.shape`

取所有列(含下表列) `df.columns`，取指定列，可以 for 和取下标，得 str，可以 `.tolist()`

取行下标范围 `df.index` 有属性 `start,step,stop`，其中 stop 是第一个越界

> 如果是聚合下标，见下文。

取每列数据类型 `df.dtypes`，取指定列的 `df[col].dtype`。

用列值进行 01 分类：`get_dummies`

取 `.values` 可以转化为 np array。然后可以丢进 tensor。

> `df[col].values.shape` 是一维；`df[[col]].values.shape` 是二维(前者算 series 转；后者算一列 df 转，故第二维为 1)

列赋值，可以直接把 numpy (1,n) shape 的赋值

##### nan/null

常量：`pd.NA`。

判断当前元素是否是 null(如 `datetime` 的 coerce)：`pd.notnull(x)`。

或对立含义 `isnull`。

去掉 nan 行：`dropna()`。(返回去掉的 df，不修改原有的)

```python
df.dropna(subset=['Column1']) # 不加就任意一行 NA 就删
```

`isna()`：(反义 `notna`)

```python
israel['Age'].isna() # isna() 返回布尔列
```

可以拿来筛选 NaN：

```python
df1 = df[df['credit_card_number'].notnull()]
df2 = df[~df['credit_card_number'].notnull()]
```

两个 series：

```python
A = pd.Series([1, np.nan, 3, np.nan, 5])
B = pd.Series([10, 20, 30, 40, 50])
B[A.dropna().index]
B[A[A.isna()].index]
```

将 nan 用一个值/一些值替换，如：`x.fillna(x.mean())`，如：

- fill 了会把 object 转成 fill 的数据类型
- 可对一个列使用如 `df['MW'] = df['MW'].fillna(0)`

> ```python
> heights_mcar.fillna(heights_mcar['child'].mean())
> child_imputed.loc[child.isnull()] = imputed_values # 等长度的 serial / numpy 数组
> ```
>
> 数据：
>
> ```csv
> NumRooms,RoofType,Price
> NA,NA,127500
> 2,NA,106000
> 4,Slate,178100
> NA,NA,140000
> ```
>
> ```python
> row2 = data.iloc[:,:2]
> row2 = pd.get_dummies(row2, dummy_na=True)
> row2 = row2.fillna(row2.mean())
> print(row2)
> ```

`combine_first` 可以在有缺失时转为别的值，如：

```python
df['OUTAGE.START.TIME'] = pd.to_timedelta(df['OUTAGE.START.TIME'], errors='coerce')
df['OUTAGE.START.DATE'] = df['OUTAGE.START.DATE'].combine_first(pd.Timestamp(0))
```



##### series

直接构造：

```python
tweets = pd.Series(["This is a tweet #example", "Another tweet #test #example", "No hashtag here"])
```

取某一列：

```python
data = {'A': [1, 2, 3],
        'B': [4, 5, 6]}
df = pd.DataFrame(data)
series = df['A'].squeeze()
series.loc[1]
df.loc[1, 'A'] #等价
```

应用：使用 boolean series 筛选元素：

```python
w=df.apply(lambda x:x[0]>3, axis=1)
df[w]
```

> 对 dataframe 只在 只有一列时转换，否则不转换：`.squeeze('columns')`
>

转回 data frame：`.to_frame()`

取某个值：`get(index, default=None)`



遍历某个 list，将每个元素(str 如 `20-30`)作为上下界作用于某列进行筛选，然后筛选完了求平均值或其他返回一元值的操作

```python
def effectiveness(df):
    vaccinated_data = df[df['Vaccinated'] == True]
    unvaccinated_data = df[df['Vaccinated'] == False]
    p_V = vaccinated_data['Severe Sickness'].mean()
    p_U = unvaccinated_data['Severe Sickness'].mean()
    return 1 - (p_V / p_U)

AGE_GROUPS = [
    '12-15',
// ...
    '80-89',
    '90-'
]

def stratified_effectiveness(df):    
    def get_effectiveness(age_range):
        age_range = age_range.split('-')
        if age_range[-1] == '':
            age_range[-1] = '999'
        age_range = [int(i) for i in age_range]
        left, right = age_range
        rows = df[(df['Age'] >= left) & (df['Age'] <= right)]
        return effectiveness(rows)
    
    result = pd.Series(AGE_GROUPS).map(get_effectiveness)
    # 如果不加 index，默认 index 为 0 开始的整数，加了就指定为该字符串
    result.index = AGE_GROUPS
    return result
```



##### 数据处理

可以直接两列运算：`df[new_col_name] = df[col1] * df[col2]`

```python
df['COLUMN'] = df['DURATION'] * np.log(df['AFFECTED'] + 1)
```

取某列等于特定值的数据：

```python
country_only = vacs[vacs['Country_Region'] == country]
```

> 单点修改：
>
> ```python
> # 使用条件索引来找到第一列('A')为'abc'的值，并将其替换为'def'
> df.loc[df['A'] == 'abc', 'A'] = 'def'
> ```

清理冗余数据：

```python
#时间戳重复的脏数据,保留第一个,假设有Column为DATATIME
df.drop_duplicates(subset = ['DATATIME'],keep='first',inplace=True)
```

取列去重，返回 `np.ndarray`

```python
vacs['Country_Region'].unique()
```

> 去重数目 `nunique()`



插入一个二分类列，表示某一列是否为 `np.nan`。

```python
israel.assign(null_age=israel['Age'].isna()) # isna() 返回布尔列
```

删掉有 nan 的行，或指定列有 nan 的行：

```python
df.dropna()
df.dropna(axis=1) #的列，而不是的行
df.dropna(subset=['B'])
```

取取值范围在区间内的列：

```python
rows = df[(df['Age'] >= left) & (df['Age'] <= right)]
```

##### apply

对该列每个元素应用某函数，返回值就地赋值 `df[col].apply(函数)`，例子见下文字符串处理。

每行处理：`apply(f, axis=1)`，更多例子见字符串处理。f 参数是列，不是标量。

> 如：对固定三个取值(或 NA)的字符串转化为整型：
>
> ```python
> def convert_climate(s):
>     if 'normal' == s:
>         return 1
>     if 'cold' == s:
>         return 2
>     if 'warm' == s:
>         return 3
>     return 0
> df['OUTAGE.CLIMATE.CATEGORY'] = df['CLIMATE.CATEGORY'].apply(convert_climate)
> ```

> `name=`，对两列操作，固定第二列，则 `f` 传多一个列，且参数名为 `name`(关键字参数)

> 将每个分类值按顺序转化为整数：(ordinal encoding)
>
> ```python
> def ordinal_encode(column, order):
>     return column.apply(lambda x: order.index(x))
> def create_ordinal(df):
>     cut_order = ['Fair', 'Good', 'Very Good', 'Premium', 'Ideal']
>     color_order = ['J', 'I', 'H', 'G', 'F', 'E', 'D']
>     df['ordinal_cut'] = ordinal_encode(df['cut'], cut_order)
>     df['ordinal_color'] = ordinal_encode(df['color'], color_order)
>     return df[['ordinal_cut', 'ordinal_color']]
> ```



如，每列与第二列进行运算，返回结果 series(原列名，且只有一行返回值)：

```python
def verify_child(heights):
    def calc(child, father):
        return stats.ks_2samp(father[child.dropna().index],father[child[child.isna()].index])[1]
    father = heights.iloc[:,1]
    p_values = heights.iloc[:,2:].apply(calc, father=father)
    print(p_values)
    return p_values
```

`stats` 是 scipy 的。



逐行+传多几个参数，考虑例子：以第一列为分组变量，对其他列进行标准化(减方差除均值)



##### groupby

```python
import pandas as pd

data = {
    'City': ['London', 'London', 'Paris', 'Paris', 'Berlin', 'Berlin'],
    'Date': ['2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02'],
    'Temperature': [8.0, 7.1, 5.5, 6.2, 0.0, 2.3],
    'Rainfall': [5.0, 6.7, 15.3, 10.1, 0.0, 13.1]
}

df = pd.DataFrame(data)
print(df)
```

聚合函数：(数值函数会忽略字符串列，把 `groupby` 列当成下标列)

```python
grouped_df = df.groupby('City').mean()
```

同一列两个运算：

```python
stat_df = df.groupby('U.S._STATE')['OUTAGE.DURATION'].agg(['mean', 'count'])
```

其他聚合函数，如 min, max, sum, size(计数),count, var(方差), median(中位数), nunique(不同值的数目)。这些聚合函数也可以直接对原表或子表使用，如 `df.min()`

分位数：

```python
q1 = df2.groupby('U.S._STATE')['OUTAGE.DURATION'].quantile(0.25)
```

> 双聚合因子和双聚合函数：
>
> ```python
> grouped_df = df.groupby(['City', 'Date']).agg({'Temperature': 'max', 'Rainfall': 'sum'})
> print(grouped_df)
> ```
>
> 怎么用这个结果看聚合索引。
>

自定义聚合函数：

```python
def coefficient_of_variation(series):
    return series.std() / series.mean()
result = df.groupby('City')['Temperature'].agg(coefficient_of_variation)
print(result)
```

多列：

```python
result = df.groupby('City').agg({
    'Temperature': coefficient_of_variation,
    'Rainfall': 'max'
})
```

聚合后自定义列名：

```python
df.groupby('City').agg(
    Temp_Coef_Var=('Temperature', coefficient_of_variation),
    Max_Rainfall=('Rainfall', 'max')
)
```

##### filter

对 df 使用，如取特定几列：

```python
data = {
    'A': [1, 2, 3],
    'B': [4, 5, 6],
    'C': [7, 8, 9],
    'D': [10, 11, 12]
}
df = pd.DataFrame(data)
df.filter(items=['B', 'C'])
```

对 groupby 后的 `DataFrameGroupBy` 使用，返回原 df 格式(不分组)：传入一个函数，对每个 group 的子 dataframe 返回一个布尔值代表保留不保留该组

- 如果确定每个 group 只有一个元素：

```python
df.groupby('A').filter(lambda df:df['B']>4) # 删一列
```

- 否则，必须再将多个元素转化为标量：

```python
df.loc[2,'A']=2
df.groupby('A').filter(lambda df:df['B'].min()>=5) #如果>5则返回空
```

- 联合条件记得两边都加括号，不然会寄：

```python
df.groupby('A').filter(lambda df:(df['B'].min()>=5) & (df.shape[0] > 1))
```



##### 聚合索引

多列多聚合函数导致的：

```python
data2 = {
    'group': ['A', 'B', 'A', 'B', 'A'],
    'x': [1, 2, 3, 4, 5],
    'y': [2, 1, 4, 3, 5]
}
df=pd.DataFrame(data2)
df.groupby('group').agg(['mean','std']).to_dict()
'''      x                   y          
      mean       std      mean       std
group                                   
A      3.0  2.000000  3.666667  1.527525
B      3.0  1.414214  2.000000  1.414214'''
# {('x', 'mean'): {'A': 3.0, 'B': 3.0}, ('x', 'std'): {'A': 2.0, 'B': 1.4142135623730951}, ('y', 'mean'): {'A': 3.6666666666666665, 'B': 2.0}, ('y', 'std'): {'A': 1.5275252316519468, 'B': 1.4142135623730951}}
```



生成跟上面 group by 双索引一样的数据：

```python
# 创建示例数据
data = {
    'Temperature': [0.0, 2.3, 8.0, 7.1, 5.5, 6.2],
    'Rainfall': [0.0, 13.1, 5.0, 6.7, 15.3, 10.1]
}

# 创建多层索引
arrays = [
    ['Berlin', 'Berlin', 'London', 'London', 'Paris', 'Paris'],
    ['2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02', '2021-01-01', '2021-01-02']
]
index = pd.MultiIndex.from_arrays(arrays, names=('City', 'Date'))

# 创建DataFrame
df = pd.DataFrame(data, index=index)

```

聚合索引，输出一行：

```python
print(grouped_df.loc[('Berlin', '2021-01-01')])
```

指定行的指定列：(`numpy.float64` 可以强转 float)

```python
print(grouped_df.loc[('Berlin', '2021-01-01'), 'Temperature'])
```

此时 `df.index`：

- `df.index.nlevels` int 有几个聚合

- `df.index.get_level_values(-1)` 取全体特定一列的行下标值

  再取最后一行的最后一列下标 `df.index.get_level_values(-1)[-1]`

  可以用 for 遍历，把两个 -1 变成 i,j 即可



##### transform

通过 groupby 算得某个值，然后按未 groupby 地将这个值返回给组内每个行：

```python
df = pd.DataFrame({
    'City': ['New York', 'New York', 'New York', 'San Francisco', 'San Francisco', 'Los Angeles', 'Los Angeles'],
    'Store': ['A', 'B', 'C', 'A', 'B', 'A', 'B'],
    'Sales': [100, 200, 300, 400, 500, 600, 700]
})
def calculate_mean(sales):
    return sales.mean()
df['City_Average'] = df.groupby('City')['Sales'].transform(calculate_mean)
```



##### 排序

```python
data = {'Name': ['Alice', 'Bob', 'Charlie', 'David'],
        'Age': [24, 42, 35, 29]}
df = pd.DataFrame(data)
sorted_df = df.sort_values(by='Age')
print(sorted_df)
avg_df.sort_values() # series 排序，升序
avg_df.sort_values(ascending = False) # 降序
```



##### concat

```python
pd.concat(objs, axis=0, join='outer', ignore_index=False)
```

- `objs`: 要连接的 Pandas 数据结构的序列，可以是 DataFrame 或 Series 的列表。
- `axis`: 指定连接的轴，0 表示按行连接，1 表示按列连接。
- `join`: 指定连接的方式，可以是 `'inner'`（交集）、`'outer'`（并集）或其他选项。
- `ignore_index`: 如果为 True，将重新生成索引，如果为 False，则保留原始索引。(即如 0,1,2, ..., 0,1,2)

如：

```python
df1 = pd.DataFrame({'A': ['A0', 'A1'], 'B': ['B0', 'B1']})
df2 = pd.DataFrame({'A': ['A2', 'A3'], 'B': ['B2', 'B3']})
result = pd.concat([df1, df2], axis=0, ignore_index=True)
print(result) # df1+df2
```

```python
df1 = pd.DataFrame({'A': ['A0', 'A1'], 'B': ['B0', 'B1']})
df2 = pd.DataFrame({'C': ['C0', 'C1'], 'D': ['D0', 'D1']})
result = pd.concat([df1, df2], axis=1)
print(result) # A0,B0,C0,D0 为一行，另一个为一行
''' A   B   C   D
0  A0  B0  C0  D0
1  A1  B1  C1  D1'''
```

##### merge

```python
pd.merge(left, right, how='inner', on=None, left_on=None, right_on=None)
```

- `left` 和 `right`: 要连接的两个 DataFrame。

- `how`: 连接方式，可以是 `'inner'`（内连接，交集）、`'outer'`（外连接，并集）、`'left'`（左连接）、`'right'`（右连接）等。

  outer 会把不存在的数字值设为 `NaN`

- `on`: 指定用于连接的列名，如果 `left` 和 `right` 都具有相同的列名，可以简单地使用 `on`。

- `left_on` 和 `right_on`: 如果要连接的列在左右两个 DataFrame 中具有不同的列名，可以使用这两个参数来分别指定左右的列名。

如：

```python
df1 = pd.DataFrame({'key': ['A', 'B', 'C', 'D'], 'value': [1, 2, 3, 4]})
df2 = pd.DataFrame({'key': ['B', 'D', 'E', 'F'], 'value': [5, 6, 7, 8]})
print(pd.merge(df1, df2, on='key', how='inner'))
print(pd.merge(df1, df2, on='key', how='outer'))

df1 = pd.DataFrame({'key1': ['A', 'B', 'C', 'D'], 'value': [1, 2, 3, 4]})
df2 = pd.DataFrame({'key2': ['B', 'D', 'E', 'F'], 'value': [5, 6, 7, 8]})
print(pd.merge(df1, df2, left_on='key1', right_on='key2', how='inner'))
```

##### 行列重构

将默认列名重命名为其他列名：

```python
.rename(columns={0: 'p-value'})
```

也可以考虑诸如 `df.columns = df.iloc[4]`

```python
count_df.columns = ['U.S._STATE', 'count'] # 重命名各列
```

将普通列设为索引或将索引退回成普通列：

```python
data = {'Name': ['Alice', 'Bob', 'Charlie'],
        'Age': [25, 30, 35]} #初始0-2索引，2个普通列
df = pd.DataFrame(data)
# 设置索引为 'Name' 列，删掉初始索引
df.set_index('Name', inplace=True)
# 使用 reset_index 重置索引，归还初始状态
df_reset = df.reset_index()
print(df_reset)
```

可以设置 `reset_index(drop=1)`，顺手把原本的索引列即上例 name 删了

增加一些没有的列 id 对应的值，填补缺省值：

```python
rainfall = pd.Series([45, 32, 64, 28], index=[2019, 2020, 2021, 2022], name='Rainfall')
new_years = [2018, 2019, 2020, 2021, 2022, 2023]
# 插入不存在的列，其值设为 NaN, 数据类型转 float
rainfall_reindexed = rainfall.reindex(new_years)
# 不转类型，设 0
rainfall_reindexed = rainfall.reindex(new_years, fill_value=0)
```

删列：

```python
df = pd.DataFrame({
    'A': [1, 2, 3],
    'B': [4, 5, 6],
    'C': [7, 8, 9],
})
df2 = df.drop(columns=['A', 'B']) # 不改变 df
df.drop(columns=['A', 'B'], inplace=True) # 改变
df3 = df[['C']] # 只要 C 列
df = df.drop(0) # 删第一行
df = df.drop(df.columns[0], axis=1) # 删第一列
```

##### 透视表

对数据：

```python
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'Diana', 'Eva', 'Frank'],
    'Gender': ['Female', 'Male', 'Male', 'Female', 'Female', 'Male'],
    'Test_Score': [88, 90, 85, 95, 78, 75],
    'Study_Group': ['A', 'B', 'A', 'B', 'A', 'B']
}
df=pd.DataFrame(data)
```

```python
pivot_table = df.pivot_table(index='Gender', columns='Study_Group', values='Test_Score', aggfunc='mean')
```

以 `Gender` 为索引，以 `Study_Group` 所有不同的取值为列，对 `Test_Score` 列，使用 group by，聚合函数是 `mean`。得到新的数据表。并且，删掉 `Name` 列。可以用 `.apply` 代替 `aggfunc`。

##### 查询

满足某个字符串 eval 表达式的所有行：(返回 DataFrame)

```python
w=pd.DataFrame([{'name':'lr580','value':580},{'name':'lr581','value':581}])
w.query('value >= 581') #相等就 ==
```



#### 其他运算

##### 随机

打乱某列，其他列不变：

```python
df['B'] = np.random.permutation(df['B'])
```

固定随机数种子：以 permutation test 为例：

```python
def permutation_test(model, df, col, val, rounds=500):
    observed = diff_of_R2(model, df, col, val)
    simulated = np.zeros(rounds)
    df2 = df.copy()
    for _ in range(rounds):
        df2[col] = df[col].sample(frac=1,random_state=SEED+_).reset_index(drop=True)
        simulated[_] = diff_of_R2(model, df2, col, val)
    p_value = np.mean(simulated >= observed)
    return observed, p_value
```



##### diff

对列差分：

```python
diffs = pivot_table.diff(axis=1)
```

则第一列变成 NaN，第二列变成第二列减第一列……

##### qcut

根据样本分位数对数据进行分箱。这意味着 `qcut` 会尽量按照数据的分布将数据分成几个具有相同数量的数据点的桶（bins）

```python
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
result = pd.qcut(data, 4)
```

将分类新建一个列存储：

```python
df = pd.DataFrame({
    'Income': [55000, 48000, 90000, 120000, 29000, 32000, 76000, 40000, 54000, 150000],
    'Age': [25, 30, 35, 40, 45, 50, 55, 60, 65, 70]
})
df['Income Quartile'] = pd.qcut(df['Income'], 4, labels=['Q1', 'Q2', 'Q3', 'Q4'])
grouped = df.groupby('Income Quartile')
age_summary = grouped['Age'].agg(['mean', 'min', 'max'])
```

分类，求各类平均值，然后求加权平均值：

```python
def cond_single_imputation(new_heights):
    df = new_heights.copy()
    df['father_cat'] = pd.qcut(df['father'], q=4)
    child_mean = df.groupby('father_cat')['child'].transform('mean')
    df['child'] = df['child'].fillna(child_mean)
    return df['child']
```

##### one-hot

独热编码；nominal encoding 的一种。

```python
tags = quotes['tags'].str.split(',') #每行的某列转list
def encode(tag_list):
    return pd.Series({k: 1 for k in tag_list})
tags.apply(encode)

#原地某个字符串列转多个one hot
quotes_full = pd.concat([quotes, tags.apply(encode)], axis=1).drop(columns='tags')
quotes_full.head()
```

写法二(多个列 one hot)：

```python
def one_hot_encode(df, column):
    """辅助函数，用于为单个列生成独热编码"""
    unique_values = df[column].unique()
    for value in unique_values:
        # 创建新列，名称符合 'one_hot_<col>_<val>' 格式
        df[f'one_hot_{column}_{value}'] = df[column].apply(lambda x: 1 if x == value else 0)
    return df[[col for col in df.columns if col.startswith(f'one_hot_{column}_')]]
def create_one_hot(diamonds):
    one_hot_df = pd.DataFrame(index=diamonds.index)  # 初始化一个空的 DataFrame
    # 对每个需要编码的列生成独热编码
    for column in ['cut', 'color', 'clarity']:
        one_hot_encoded_cols = one_hot_encode(diamonds, column)
        one_hot_df = pd.concat([one_hot_df, one_hot_encoded_cols], axis=1)
    return one_hot_df
```

写法三：scipy (创建多个新的列)

```python
from sklearn.preprocessing import OneHotEncoder
import pandas as pd
data = {
    'group': ['A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A']
}
df = pd.DataFrame(data)
encoder = OneHotEncoder(sparse=False)
encoded_data = encoder.fit_transform(df[['group']]) #numpy.ndarray(float)
columns = encoder.get_feature_names_out(['group']) #list(str)
encoded_df = pd.DataFrame(encoded_data, columns=columns)
result_df = pd.concat([df, encoded_df], axis=1)
result_df.head()  # 展示前几行以检查结果
```

> 如果要获得 pipeline 里的列名：
>
> ```python
> column_transformer = ColumnTransformer(
>     transformers=[
>         ('climate_category', ClimateCategoryTransformer(), ['CLIMATE.CATEGORY']),
>         ('state_one_hot', OneHotEncoder(), ['U.S._STATE']),
>     ],
>     remainder='passthrough'  # 保留 OUTAGE.START.DATE 和 OUTAGE.START.TIME
> )
> pipeline = Pipeline(steps=[('transform', column_transformer)])
> 
> transformed_data = pipeline.fit_transform(df)
> 
> # 获取 ColumnTransformer 中的 transformers
> column_transformers = pipeline.named_steps['transform'].named_transformers_
> 
> # 获取 OneHotEncoder 生成的列名
> one_hot_column_names = column_transformers['state_one_hot'].get_feature_names_out()
> 
> # 将 OneHotEncoder 的列名与 ClimateCategoryTransformer 和其他保留列的列名结合
> dynamic_column_names = ['Climate_Category'] + list(one_hot_column_names) + ['Outage_Start_Date', 'Outage_Start_Time', 'Other_Column']
> 
> # 创建带有动态列名的 DataFrame
> dynamic_transformed_df = pd.DataFrame(transformed_data, columns=dynamic_column_names)
> print(dynamic_transformed_df)
> ```
>
> 

##### value_counts

对某列操作，返回一个 series，索引是每个值，数值是该值出现频次。并且按照降序排列。

```python
data = {'fruit': ['apple', 'banana', 'orange', 'apple', 'banana', 'apple']}
df = pd.DataFrame(data)
print(df['fruit'].value_counts()) # 'pandas.core.series.Series'
print(df.value_counts(normalize=True)) # float64, 出现百分比
df.value_counts(normalize=True)['apple'] # 当 dict 用
```

##### crosstable

可以生成 2x2 表，分别表示某行是否为何值，某列是否为何值四种情况的取值：

```python
df = pd.DataFrame({
    'col1': [np.nan, 2, 3, np.nan, 5, 6,np.nan],
    'col2': [1, np.nan, 3, 4, 5, np.nan,np.nan]
})
table = pd.crosstab(df[col1].isna(), df[col2].isna()) #2,2,2,1
```

##### idxmax

```python
df = pd.DataFrame({'A': [1, 2, 3], 'B': [3, 2, 1]})

# 找到每列的最大值的索引
max_index = df.idxmax()
print(max_index) #A:2, B:0

# 找到每行的最大值的索引
max_index_row = df.idxmax(axis=1) #0:B,1:A,2:A
print(max_index_row)
```

##### 去重

`.nunique()` 返回每列有几个不同的值的数目

`.unique()` 返回 `numpy.ndarray` 代表不同取值

##### 方差

1. **NumPy**: 当使用 NumPy 的 `std` 函数时，默认情况下，它使用的是分母 N（这是总体标准差的计算方式）。但是，你可以通过设置 `ddof`（Delta Degrees of Freedom）参数为 1 来改用 N−1 作为分母，这样计算的是样本标准差。例如，`numpy.std(a, ddof=1)`。
2. **Pandas**: 在 Pandas 中，`DataFrame.std()` 或 `Series.std()` 函数默认使用的是分母 N−1（样本标准差的计算方式）。这是因为 Pandas 通常用于处理样本数据，而不是整个总体。如果你想计算总体标准差，需要设置 `ddof=0`。

```python
import numpy as np
import pandas as pd

# 创建一个简单的数据集
data = np.array([1, 2, 3, 4, 5])

# 使用 NumPy 计算标准差，默认 ddof=0（总体标准差）
numpy_std_population = np.std(data)

# 使用 NumPy 计算标准差，设置 ddof=1（样本标准差）
numpy_std_sample = np.std(data, ddof=1)

# 将相同的数据集转换为 Pandas Series
data_series = pd.Series(data)

# 使用 Pandas 计算标准差，默认 ddof=1（样本标准差）
pandas_std_sample = data_series.std()

# 使用 Pandas 计算标准差，设置 ddof=0（总体标准差）
pandas_std_population = data_series.std(ddof=0)

# 打印结果
print("NumPy Population Std:", numpy_std_population)
print("NumPy Sample Std:", numpy_std_sample)
print("Pandas Sample Std:", pandas_std_sample)
print("Pandas Population Std:", pandas_std_population)
```



#### 字符串

##### .str

对某一列，`.str` 是 Pandas 中用于对字符串列进行操作的属性

1. 提取子字符串：使用 `.str` 属性的 `extract()` 方法可以提取满足正则表达式模式的子字符串。例如，`df['Column'].str.extract('(\d+)')` 可以提取列 "Column" 中的数字部分。
2. 字符串查找和匹配：`.str` 属性提供了许多方法，如 `contains()`（检查字符串是否包含某个子字符串）、`startswith()`（检查字符串是否以某个子字符串开头）和 `endswith()`（检查字符串是否以某个子字符串结尾）等，用于查找和匹配字符串。
3. 字符串替换：使用 `replace()` 方法可以将字符串中的指定子字符串替换为另一个字符串。
4. 字符串分割和连接：`.str` 属性还提供了用于字符串分割和连接的方法，例如 `split()`（将字符串拆分为列表）和 `join()`（将列表中的字符串连接成一个字符串）。
5. 大小写转换：使用 `lower()` 和 `upper()` 方法可以将字符串转换为小写或大写。
6. 字符串长度：使用 `len()` 方法可以获取字符串的长度。

如，检查是否两列不区分大小写包含某串：

```python
def bhbe_col(heroes):
    def check(row):
        return 'blue' in row['Eye color'].lower() and 'blond' in row['Hair color'].lower()
    return heroes.apply(check, axis=1)
```

> 或：
>
> ```python
> is_blond = heroes['Hair color'].str.contains('blond', case=False, na=False)
> is_blue_eyed = heroes['Eye color'].str.contains('blue', case=False, na=False)
>  return is_blond & is_blue_eyed
> ```

取所有数字并连接，原地保存：

```python
data = {'ColumnName': ['abc123', 'def456', 'ghi789']}
df = pd.DataFrame(data)
df['ColumnName'] = df['ColumnName'].str.extract('(\d+)').astype(int)
print(df)
```

第一列 `-` 设为 `NaN`，其他列转 bool：

```python
res['Age'] = res['Age'].replace('-', np.nan).astype(float)
res['Vaccinated'] = res['Vaccinated'].astype(bool)
```

逐列综合处理：百分号转整数，其他情况去掉 `, _` 等划分长整数的字符，根据是否有小数点转换为整数或浮点数，去掉单位，对字符串。如果无数字。不操作。

```python
# 创建一个示例DataFrame
data = {
    'col1': ['10%', '20%', '30%'],
    'col2': ['123abc', '456def', '789ghi'],
    'col3': ['1.23', '4.56', '7.89xyz'],
    'col4': [10, 20, 30]  # 这列是整数，不会被修改
}

df = pd.DataFrame(data)

# 定义一个函数，对单个字符串进行处理
def process_string(s):
    if '%' in s:
        return float(s.strip('%')) * 0.01
    elif '.' in s:
        return float(''.join(filter(lambda x: x.isdigit() or x == '.', s)))
    else:
        return int(''.join(filter(str.isdigit, s)))

# 对DataFrame的每一列应用这个函数
for col in df.columns:
    if df[col].dtype == 'O':  # 'O'表示对象，通常是字符串
        if df[col].str.contains('\d').all():
        	df[col] = df[col].apply(process_string)

print(df)
# 注意 ² 会 isdight，如果单位有奇怪的特殊字符建议重写isdight
```

正则表达式：

```python
def hashtag_list(tweet_text):
    regex_pattern = r"#([a-zA-Z0-9]+)"
    hashtag_series = tweet_text.apply(lambda tweet: re.findall(regex_pattern, tweet))
    return hashtag_series
tweets = pd.Series(["This is a tweet #example", "Another tweet #test #example", "No hashtag here"])
hashtag_series = hashtag_list(tweets)
'''
0          [example]
1    [test, example]
2                 []'''
all_hashtags = [hashtag for sublist in tweet_lists for hashtag in sublist]
```

```python
import pandas as pd

# 定义函数
def extract_title(df):
    titles = df['Name'].str.extract(r'([A-Za-z]+)\.', expand=False)
    print(titles)
    return pd.DataFrame(titles)

# 创建一个包含一些示例姓名的DataFrame
data = {'Name': ['Mr. John Smith', 'Dr. Alice Jones', 'Miss Emily Brown']}
df = pd.DataFrame(data)

# 使用函数提取标题
titles_df = extract_title(df)

# 显示结果
print(titles_df)
```





#### 时间

##### 类型

转换成对应数据类型：

```python
pd.to_datetime(df[列]) #比如本来是字符串2022-01-29 18:24:07
```

检测转换：

```python
df['date_column'].dtype == 'datetime64[ns]'
```

默认参数：

- `errors='raise'`（默认）：如果遇到无法解析为日期的字符串，会引发一个`ValueError`。
- `errors='ignore'`：如果遇到无法解析为日期的字符串，原始数据将不会被修改，也不会引发错误。
- `errors='coerce'`：如果遇到无法解析为日期的字符串，那些无法解析的字符串将会被设置为`NaT`（Not a Time），这是Pandas中用于表示缺失日期数据的特殊类型。

##### dt属性

一些常用的 `.dt` 方法和属性：

1. `.dt.year`：返回日期时间中的年份。
2. `.dt.month`：返回日期时间中的月份（1 到 12）。
3. `.dt.day`：返回日期时间中的日（1 到 31）。
4. `.dt.hour`：返回日期时间中的小时（0 到 23）。
5. `.dt.minute`：返回日期时间中的分钟（0 到 59）。
6. `.dt.second`：返回日期时间中的秒（0 到 59）。
7. `.dt.microsecond`：返回日期时间中的微秒（0 到 999999）。
8. `.dt.weekday`：返回日期时间对应的星期几，星期一为 0，星期日为 6。
9. `.dt.week`：返回日期时间所在年份的周数。
10. `.dt.strftime(format)`：将日期时间对象格式化为字符串，可以自定义日期时间的输出格式，例如 `'%Y-%m-%d %H:%M:%S'`。
11. `.dt.date`：返回日期时间中的日期部分。
12. `.dt.time`：返回日期时间中的时间部分。
13. `.dt.to_period(freq)`：将日期时间对象转换为指定频率（如天、月、年等）的 Period 对象。

例子，对同 id 的每组计数 $[4PM,8PM)$ 的时间

```python
def prime_time_logins(login):
    df = login # login.copy()
    df['hour'] = pd.to_datetime(df['Time']).dt.hour
    res = df[(df['hour'] >= 16) & (df['hour'] < 20)]
    res = res.groupby('Login Id').agg({"Time":'size'}) #.size()
    # 当前: Login Id 为索引, 无名列为 count
    res = res.reindex(df['Login Id'].unique(), fill_value=0)
    #在上面的基础上补全了为0的缺省(<16 | >=20的login id)

    # .size() 的话重命名
    # res = res.reset_index(name="Time").set_index('Login Id')
    return res
```

##### 日期

返回某个月的最后一天(字符串)：

```python
year=2020
month=2
start_date = f"{year}-{month:02d}-01"
pd.date_range(start_date, periods=1, freq='M').strftime('%Y-%m-%d').tolist()[0] #'2020-02-29'
```

##### 时间戳

默认按毫秒算，如果按秒的时间戳，要加默认参数：

```python
pd.Timestamp(1541014179, unit='s')
pd.Timestamp(1541014179000)
```

##### 时间运算

时间相差：

```python
# pd.Timestamp('2023-01-31') 置一个时间
timestamp1 = pd.Timestamp('2023-01-01 22:00:00')
timestamp2 = pd.Timestamp('2023-01-02 03:00:00')
(timestamp2 - timestamp1).days #0
```

时间下取整(时分秒归零)：

```python
timestamp1.normalize()
```

取天的跨度(而不是简单的小时差)：

```python
(timestamp2.normalize() - timestamp1.normalize()).days
```

岁数：(粗略计算)

```python
df[rowname] = pd.to_datetime(df[rowname], errors='coerce')
# 25-Sep-1982 -> 正常； NaN -> NaT
```

##### 日期时间组合

合并日期列和时间列：

```python
df['OUTAGE.START.DATE'] = pd.to_datetime(df['OUTAGE.START.DATE'], errors='coerce')
from datetime import datetime, timedelta
def time_to_timedelta(time_obj):
    if pd.isnull(time_obj):
        return pd.NaT
    return timedelta(hours=time_obj.hour, minutes=time_obj.minute, seconds=time_obj.second)
df['OUTAGE.START.TIME'] = df['OUTAGE.START.TIME'].apply(lambda x: time_to_timedelta(datetime.strptime(str(x), '%H:%M:%S').time()) if pd.notnull(x) else pd.NaT)

df['OUTAGE.START'] = pd.NaT
for index, row in df.iterrows():
    if pd.notnull(row['OUTAGE.START.DATE']) and pd.notnull(row['OUTAGE.START.TIME']):
        df.at[index, 'OUTAGE.START'] = row['OUTAGE.START.DATE'] + row['OUTAGE.START.TIME']
```

简短：

```python
df['OUTAGE.START.DATE'] = pd.to_datetime(df['OUTAGE.START.DATE'])
df['OUTAGE.START.TIME'] = pd.to_timedelta(df['OUTAGE.START.TIME'].astype(str))
df['OUTAGE.START'] = df['OUTAGE.START.DATE'] + df['OUTAGE.START.TIME']
```



#### 绘图

##### 直方图

直接选一列然后 `.hist()` 即可。

```python
df1['age'].hist()
```

##### 柱状图

以 series(带列名)为例：

```python
to_frame().rename(columns={0: 'p-value'}).plot(kind='barh', width=800, height=400)
```

`kind='barh'`指定了图表的类型为水平条形图（horizontal bar chart）。





### openpyxl

#### 基础操作

安装：(window cmd命令)

```cmd
pip install openpyxl
```

加载：(方法不唯一)

```python
from openpyxl import *
```

打开文件：(路径相对绝对都可)

```python
wb = load_workbook(路径)
```

新建文件：(自带名为`sheet`的初始sheet表单)

```python
wb = Workbook()
```

保存文件：

```python
wb.save(路径)
```



读取sheet表格，可以用`worksheets`按数字从左到右顺序或用`wb`实例的key名(sheet名字符串)：

```python
sheet0 = wb.worksheets[0]
sheet1 = wb['Sheet1']
```

创建sheet表格：

```python
wb.create_sheet(index=0,title='sheet名字')
```

获取某个单元格cell的数据、坐标(字符串)：

```python
sheet0['A1'].value
sheet0['A1'].coordinate
```

> value有就是字符串，没有就是None

按行或列遍历：

```python
sheet.iter_rows() #用于for，元素是行，再for之得每个单元格
sheet.iter_cols() #同理
```

行数，列数即 `sheet.max_row` , `.max_column`。

自适应某列列宽：(如第一列)

```python
sh2.column_dimensions['A'].auto_size = True
```



举例：

1: 批量读取

```python
from openpyxl import *
# 使用vscode自带代码补全，很好用
# 打开与本程序同目录下的一个excel表格文件
wb = load_workbook('中文路径测试.xlsx') 
sheet = wb.worksheets[0]
for col in sheet.iter_cols(): #按列遍历
    for cell in col:
        print(cell.coordinate, cell.value)
```

2: 创建一个九九乘法表并保存

```c++
from openpyxl import *
wb = Workbook()
wb.create_sheet(index=0, title='九九乘法表')
sheet = wb.worksheets[0]
for i in range(1, 10):
    for j in range(1, 10):
        cor = '%c%d' % (chr(64+i), j)  # chr是int转ascii char
        sheet[cor].value = i*j
wb.save('99mul.xlsx')
```

> 附：大的数字转EXCEL行，可以用进制的方法，递推公式是$c=(x-1)\mod26,\quad x=(x-1)/26$，新生成的$c$位于最开头，即unshift操作
>
> 参考C++代码如下：(原题：`蓝桥杯真题EXCEL地址`)
>
> ```c++
> #include <bits/stdc++.h>
> int n; std::string x;
> signed main()
> {
>  for(scanf("%d",&n);n;n=(n-1)/26) x=(char)('A'+(n-1)%26 )+x;
>  return std::cout<<x,0;
> }
> ```

> 更多内容：如字体、边框填充、超链接、excel公式、合并单元格，暂时用不上，这里不做笔记，需要用时见[这里](https://blog.csdn.net/liyuanjinglyj/article/details/87895700)

### plotly

交互良好的数据图。

#### 常用图

##### 直方图

对某列绘制分布图：

```python
fig = px.histogram(df, x='OUTAGE.DURATION', title = 'abc')
```

##### 柱状图

频次统计：(打横的一条条，即横坐标是频次，纵坐标是值)

```python
# 不改变，直接输出原编号
count_df = df['U.S._STATE'].value_counts()
fig = px.bar(count_df, x='U.S._STATE', title = 'Distribution of Outage\'s U.S. State')
# 改变编号为排名
count_df = df['your_column'].value_counts().reset_index()
count_df.columns = ['your_column', 'count']
fig = px.bar(count_df, x='your_column', y='count', 
             title='Your Column Value Counts')
fig.show()
```

打竖的：

```python
fig = px.bar(count_df, y='U.S._STATE', title = 'Distribution of Outage\'s U.S. State')
fig.update_layout(xaxis_title='Outage U.S. State', yaxis_title='counts')
```

一行三列的条形图，即每行对三个条(列是 cold, warm, normal)：

```python
fig = px.bar(pivot_table, title = 'Average Outage Duration of Different Climate Category of Different States')
fig.update_layout(xaxis_title='U.S. State', yaxis_title='Average Outage Duration')
fig.show()
```



##### 折线图

要求用到 pandas 的 `DataFrame`，以 `vacs` 为例，绘制以某列为横坐标，另一列为纵坐标(不只是起标题作用，而是真的用来选择数据)：

```python
import plotly.express as px
def plot_cases(country):
    country_only = vacs[vacs['Country_Region'] == country]
    fig = px.line(country_only, x='Date', y='Doses_admin', title=f"'Doses_admin' column for {country}")
    fig.show()
```

双折线：

```python
stat_df = df.groupby('U.S._STATE')['OUTAGE.DURATION'].agg(['mean', 'count'])
stat_df = stat_df.sort_values(by='mean')
fig = px.line(stat_df, title = 'Average Outage Duration of Different States')
fig.update_layout(xaxis_title='U.S. State')
fig.show()
```

```python
df2 = df.copy()
df2.dropna(subset=['OUTAGE.DURATION'])
df2['OUTAGE.DURATION'] = df2['OUTAGE.DURATION'].astype(float)
stat_df = df2.groupby('U.S._STATE')['OUTAGE.DURATION'].agg(['mean', 'median'])
stat_df = stat_df.sort_values(by='mean')
q1 = df2.groupby('U.S._STATE')['OUTAGE.DURATION'].quantile(0.25)
q3 = df2.groupby('U.S._STATE')['OUTAGE.DURATION'].quantile(0.75)
stat_df = pd.merge(stat_df, q1, on='U.S._STATE')
stat_df = pd.merge(stat_df, q3, on='U.S._STATE')
stat_df.columns = ['mean', 'median', 'Q1', 'Q3']
fig = px.line(stat_df, title = 'Average Outage Duration of Different States')
fig.update_layout(xaxis_title='U.S. State')
fig.show()
```



##### 散点图

```python
data2 = {
    'x': [1, 2, 3, 4, 5],
    'y': [2, 1, 4, 3, 5],
    'group': ['A', 'B', 'A', 'B', 'A']
}
df2 = pd.DataFrame(data2)

# 使用 Plotly Express 创建散点图
fig = px.scatter(df2, x='x', y='y', color='group',
                 size=[10, 20, 30, 40, 50], 
                 hover_data=['x', 'y'])
fig.show()
```

最小二乘法拟合一个散点图，绘制拟合直线：

```python
np.random.seed(23)
x = np.arange(1, 101) + np.random.normal(0, 0.5, 100)
y = 2 * ((x + np.random.normal(0, 1, 100)) ** 2) + np.abs(x) * np.random.normal(0, 30, 100)
df_1 = pd.DataFrame().assign(x=x, y=y)

px.scatter(df_1, x='x', y='y', trendline="ols", trendline_color_override="red")
# ols Ordinary Least Squares 普通最小二乘法
```



##### 箱形图

box plot

1. **箱体**：箱体的上下边界分别表示数据的第三四分位数 (Q3) 和第一四分位数 (Q1)。箱体的长度，即四分位距 (IQR)，是数据分布的主要部分。
2. **中位数**：箱体内的一条线表示数据的中位数（第二四分位数）。
3. **触须（Whiskers）**：箱体外的两条线（触须）延伸到数据点的范围内。通常，它们延伸到 Q1 - 1.5 * IQR 和 Q3 + 1.5 * IQR。超出这个范围的点通常被视为异常值。
4. **异常值**：通常用不同的标记（如点）表示，这些是远离其他数据的值。

```python
data2 = {'Group': ['A', 'B', 'C', 'A', 'B', 'C'],
        'Value': [1, 2, 3, 4, 2, 5]}
df2 = pd.DataFrame(data2)
fig = px.box(df2, x='Group', y='Value')
fig.show()
```



##### 等值线图

[文档](https://plotly.com/python/choropleth-maps/)

画一张世界地图：

```python
def draw_choropleth(tots, pops_fixed):
    df = pd.merge(tots, pops_fixed, left_on = 'Country_Region', right_on= 'Country (or dependency)', how = 'inner')
    df['Doses Per Person'] = df['Doses_admin'] / df['Population in 2023'] / 1000

    # df['Country (or dependency)'] = df['Country (or dependency)'].apply(lambda x: f"<b>{x}</b>") # no need, already bold
    fig = px.choropleth(
        df,
        locations = 'ISO',
        color = 'Doses Per Person',
        labels = {'unemp':'Doses Per Person'},
        hover_name = 'Country (or dependency)',
        color_continuous_scale = ["lightgreen", "darkgreen"], 
        # locationmode = 'ISO-3', # default
    )
    fig.update_layout(
        margin={"r":0,"t":0,"l":0,"b":0},
        title="COVID Vaccine Doses Per Person"
    )
    # fig.update_geos(projection_type="mercator")
    return fig
```

`ISO` 是三个字母的国家编号。再补充。

#### 图表属性

行列标题，表名(左上角)：

```python
fig.update_layout(
   xaxis_title='X轴标签',
   yaxis_title='Y轴标签',
   title='图表标题'
)
```



#### 子图

训练集与测试集的误差，两张子图，每张图两个折线：

```python
from plotly.subplots import make_subplots
import plotly.graph_objects as go
titles = (('Prediction on Train Data', 'Prediction on Test Data'))
fig = make_subplots(rows=1, cols=2, subplot_titles=titles)
fig.add_trace(
    go.Scatter(x=list(range(len(y_train))),
               y=y_train.to_numpy(), name='train_real',mode='markers'),row=1,col=1
)
fig.add_trace(
    go.Scatter(x=list(range(len(y_train_pred))),
               y=y_train_pred, name='train_pred',mode='markers'),row=1,col=1
)
fig.add_trace(
    go.Scatter(x=list(range(len(y_test))),
               y=y_test.to_numpy(), name='test_real',mode='markers'),row=1,col=2
)
fig.add_trace(
    go.Scatter(x=list(range(len(y_test_pred))),
               y=y_test_pred, name='test_pred',mode='markers'),row=1,col=2
)
fig.show()
```

- mode='markers' 是散点，不然折线

> 例子：

> ```python
> from plotly.subplots import make_subplots
> import plotly.graph_objects as go
> np.random.seed(9) # For reproducibility
> 
> tree = tree_reg_perf(galton)
> knn = knn_reg_perf(galton)
> hyp = np.arange(1, 21)
> 
> fig = make_subplots(rows=1, cols=2, subplot_titles=('Error vs. Tree Depth<br>for Decision Tree Regressor',
>                                                     'Error vs. k (# Neighbors)<br>for k-NN Regressor'))
> 
> fig.add_trace(
>     go.Scatter(x=hyp, y=tree.iloc[:, 0], line=dict(color='blue'), name='Training Error'),
>     row=1, col=1).add_trace(go.Scatter(x=hyp, y=tree.iloc[:, 1], line=dict(color='red'), name='Testing Error'), 
>                             row=1, col=1)
> 
> fig.add_trace(
>     go.Scatter(x=hyp, y=knn.iloc[:, 0], line=dict(color='blue'), name='Training Error', showlegend=False),
>     row=1, col=2).add_trace(go.Scatter(x=hyp, y=knn.iloc[:, 1], line=dict(color='red'),  name='Testing Error',
>                                        showlegend=False), row=1, col=2)
> 
> fig.update_layout(height=450, width=975)
> fig.update_xaxes(title_text='Tree Depth', row=1, col=1, tickvals=np.arange(1,21,2))
> fig.update_xaxes(title_text='k (# Neighbors)', row=1, col=2, tickvals=np.arange(1,21,2))
> 
> fig.show()
> ```



#### 导出

##### HTML

设 `fig` 是 plotly Figure 对象，或 `.plot`(`pd.options.plotting.backend = "plotly"`)，则支持方法 `write.html`，如：

```python
fig.write_html('file-name.html', include_plotlyjs='cdn')
```

- 如果不 include，那么会把整个库源码搞到 HTML 里

接下来可以使用内嵌的办法，将其加载，例如：

```html
<iframe src="assets/file-name.html" width=800 height=600 frameBorder=0></iframe>
<!-- 建议可以更改长宽，不要更改frameBorder -->
```

##### 图片

```sh
pip install -U kaleido # --upgrade
```

```python
fig.write_image("residual_plot.png")
```

支持 `.png, .jpg, .svg, .pdf` 等。其中 SVG 是矢量图。

### pygal

```python
import pygal
from random import randint,choice
dice=list(range(1,7))
res,fr=[],[]
for i in range(1000):
    res.append(choice(dice))
for i in range(1,7):
    fr.append(res.count(i))
grap=pygal.Bar()
grap.title='Dice'
grap.x_labels=[str(i) for i in dice]
grap.x_title='Result'
grap.y_title='Frequency'
grap.add('D6',fr) #图例
grap.render_to_file('dice.svg') #生成可用浏览器打开的图表文件
```



## 图像处理

### cv2

```shell
pip install opencv-python
```

#### 读写显示

可能读彩色图有点问题，这样的话建议用 mpimg 读

对于读 PNG，用 `mpimg` 会有 alpha 通道从而第三维度长为 4，而 `cv2` 只有三维。用 `mpimg` 读的范围是 $[0,1]$ 实数，而 `cv2` 是 uint8。

```python
import cv2
src = cv2.imread('img/keepOut.jpg') #<class 'numpy.ndarray'>
cv2.imshow('src', src)  # 窗口名
cv2.waitKey(0)
```

中文路径的读取：

```python
img = cv2.imdecode(np.fromfile(path, dtype=np.uint8), cv2.IMREAD_COLOR)
```

不能读 GIF，需要的话用 `imageio` 库

#### 图像增强

##### 直方图均衡化

[原理](https://blog.csdn.net/qq_15971883/article/details/88699218)

```python
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
import cv2 as cv
img = mpimg.imread(r'res\Fig0203(a).tif')
plt.subplot(1, 2, 1)
plt.imshow(img, cmap="Greys_r")
plt.subplot(1, 2, 2)
img2 = cv.equalizeHist(img)
plt.imshow(img2, cmap="Greys_r")
plt.show()
```



##### 单阈值分割

人工指定阈值：

```python
import cv2
import matplotlib.pyplot as plt

img = cv2.imread("res/Fig0517(a).tif")
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#<120 -> 0 otherwise -> 1
th, img2 = cv2.threshold(img, 120, 255, cv2.THRESH_BINARY)
plt.subplot(121)
plt.imshow(img, 'gray')
plt.subplot(122)
plt.imshow(img2, 'gray')
plt.show()
```

自适应：

```python
import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread("res/Fig0517(a).tif")
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
th, img2 = cv2.threshold(img, 0, 256, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

plt.subplot(121)
plt.imshow(img, 'gray')
plt.subplot(122)
plt.imshow(img2, 'gray')
plt.show()
```

#### 其他例子

##### 字符画转换

基本理论：灰度低的映射到看着更密的字符。

```python
import cv2
import numpy as np
def convert_image_to_ascii(image_path, output_file, chars="@$%#*+=-:. "):
    img = cv2.imread(image_path)
    # 将图片转换为灰度
    gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # 使用 NumPy 重新调整灰度值 将灰度值映射到字符集上
    char_indices = (gray_image / (256.0 / len(chars))).astype(np.int32)
    ascii_image = "\n".join("".join(chars[idx] for idx in row) for row in char_indices)
    with open(output_file, "w") as f:
        f.write(ascii_image)
convert_image_to_ascii("a.jpg", "output.txt")
```



### pillow

PIL python image library [文档](https://pillow.readthedocs.io/en/stable/)

#### 基本

```python
from PIL import Image
```

其读入结果不为 `numpy.ndarray`

```python
img = Image.open(src) #支持中文路径
rows, cols = img.size
```

可以用 `matplotlib` 显示和绘图。

大小缩放：

```python
img = img.resize((rows, cols), Image.Resampling.BICUBIC)
```

保存：

```python
img.save(文件名)
```



#### 转黑白

直接取平均值：

```python
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from PIL import Image

img = Image.open('b.jpg')
img = img.convert('L')
plt.imshow(img, 'gray')
plt.show()
```

可以手写：

```python
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

img = mpimg.imread('b.jpg')
arr = [[0.299, 0.587, 0.114] for i in range(3)]
trans = np.array(arr).transpose()  #矩阵转置
img2 = np.dot(img, trans).astype(np.uint8)
plt.subplot(121)
plt.imshow(img)
plt.subplot(122)
plt.imshow(img2, 'gray')
plt.show()
```



#### 图片旋转

```python
from PIL import Image
import matplotlib.pyplot as plt
path = input("请输入图片相对或绝对路径:")
img = Image.open(path)
ang = float(input("请输入逆时针旋转角(任意角度):"))
img1 = img.rotate(ang, expand=True)
plt.imshow(img1)
plt.show()
```

#### 直方图均衡化

```python
from PIL import Image, ImageOps
image = Image.open("path_to_your_image.jpg")
equalized_image = ImageOps.equalize(image)
equalized_image.save("equalized_image.jpg")
```



> ### scikit-image
>



## 数学处理

### scipy

[官网](https://scipy.org/)

#### 统计

##### KS测试

 Kolmogorov-Smirnov (KS) 测试。KS 测试是一种非参数检验，用于确定两个样本是否可能来自同一分布。它衡量两个累积分布函数（CDF）之间的最大差异，并提供一个统计量来表征这一差异的显著性。

输入两个序列数据如列表、numpy 数组。

返回两个值：

- `statistic` 是 KS 统计量，即两个 CDF 之间的最大差异。
- `p_value` 是与观察到的统计量相对应的 p 值。如果 p 值很小（通常小于显著性水平，如 0.05），我们可以拒绝原假设，即两个样本来自同一分布。

```python
from scipy.stats import ks_2samp
statistic, p_value = ks_2samp(data1, data2)
ks_2samp(data1, data2).statistic # 只要一个结果
```

如对 dataframe：

```python
observed_ks = ks_2samp(data.loc[data['group'] == 'A', 'data'], data.loc[data['group'] == 'B', 'data']).statistic
```



#### 优化

##### 线性规划

例求解：
$$
\min z=2x_1+3x_2+x_3\\
s.t.\begin{cases}
x_1+4x_2+2x_3&\ge 8\\
3x_1+4x_2&\ge6\\
x_1,x_2,x_3&\ge0
\end{cases}
$$

```python
import numpy as np
from scipy.optimize import linprog

f = np.array([2, 3, 1])
a = np.array([[-1, -4, -2], [-3, -2, 0]])  #等式左边系数矩阵取反
b = np.array([-8, -6])  #右边系数
r = linprog(f, A_ub=a, b_ub=b, bounds=((0, None), (0, None), (0, None)))
print(r.x)
```

取负是因为，这些等式约束都是大于等于的，而参数要的是小于等于的



##### 非线性规划

例求解：[文档](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.minimize.html#scipy.optimize.minimize)
$$
\min f(x)=x^2_1+x^2_2+x^3_3+8\\
s.t.\begin{cases}
x^2_1-x_2+x^2_3&\ge0\\
x_1+x^2_2+x^2_3&\le20\\
-x_1-x_2^2+2&=0\\
x_2+2x^2_3&=3\\
x_1,x_2,x_3&\ge0
\end{cases}
$$

```python
from scipy import optimize as opt
import numpy as np

b = (0, None)
bnds = (b, b, b)  #边界约束三变量 >=0
con1 = {'type': 'ineq', 'fun': lambda x: x[0]**2 - x[1] + x[2]**2}  #不等式默认>=0
con2 = {'type': 'ineq', 'fun': lambda x: -(x[0] + x[1]**2 + x[2]**2 - 20)}
con3 = {'type': 'eq', 'fun': lambda x: -x[0] - x[1]**2 + 2}  #等式右边=0
con4 = {'type': 'eq', 'fun': lambda x: x[1] + 2 * x[2]**2 - 3}
cons = ([con1, con2, con3, con4])
f = lambda x: x[0]**2 + x[1]**2 + x[2]**2 + 8
x0 = np.array([0, 0, 0])
sol = opt.minimize(f, x0, method='SLSQP', bounds=bnds, constraints=cons)#不懂算法就不选method
x = sol.x
print('min f=%f' % f(x))
print('x=', x)
```

其中：

- `bound` 是 `min, max` 二元组。
- [返回值](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.OptimizeResult.html#scipy.optimize.OptimizeResult)的 x 是取得最值的参数(np array)，还有布尔值 success 和对应字符串 message

### sklearn

安装：

```shell
pip install scikit-learn -i https://pypi.tuna.tsinghua.edu.cn/simple/
```

#### 线性回归

##### 回归

```python
import pandas as pd
import numpy as np
import plotly.express as px
from sklearn.linear_model import LinearRegression

# 示例数据
np.random.seed(23)
x = np.random.rand(100) * 10
y = 2.5 * x + np.random.randn(100) * 2

# 线性回归模型拟合
model = LinearRegression()
model.fit(x.reshape(-1, 1), y)

# 计算残差
y_pred = model.predict(x.reshape(-1, 1)) # <class 'numpy.ndarray'>
residuals = y - y_pred

# 创建DataFrame
df = pd.DataFrame({'x': x, 'Residuals': residuals})

# 绘制残差图
fig = px.scatter(df, x='x', y='Residuals', title='Residual Plot')
fig.show()
```

写法二：

```python
def create_residual_plot(df, x, y):
    df = df.copy()
    model = LinearRegression()
    model.fit(df[[x]], df[y])
    df['pred'] = model.predict(df[[x]]) 
    df[f'{y} residuals'] = df[y] - model.predict(df[[x]])
    return px.scatter(df, x='pred', y=f'{y} residuals', trendline='ols', trendline_color_override='red')
```

##### 统计量

评估依据：RMSE(root mean squared error，均方根误差) $\sqrt{\dfrac{\sum_{i=1}^n(y_i-\hat y_i)^2}n}$，在 least squares regression 使用该 argmin。值越小表示预测的准确性越高。

$R^2$ coefficient of determination，测定系数，取值 0\~1。取 `model.score`；值越高表示模型的解释能力越强。

```python
from sklearn.metrics import r2_score, mean_squared_error
def get_R2_and_RMSE(df1, col1, df2, col2):
    X = df1[[col1]]
    y = df2[col2]
    lr = LinearRegression()
    lr.fit(X, y)  # X is a DataFrame of training data; y is a Series of prices
    r2 = lr.score(X, y)  # R-squared
    yh = lr.predict(X) # predicted prices, yh is numpyarray
    '''rmse = 0 # check by hand writing
    n = y.shape[0]
    for i in range(n):
        rmse += (yh[i]-y[i])**2
    rmse = (rmse/n) ** 0.5
    print('check rmse: ', rmse)'''
    return (r2_score(y, yh), # the same as lr.score; (yh, h) not same
        mean_squared_error(yh, y, squared=False))
```

##### 多元回归

```python
col1 = diamonds.select_dtypes(include=[np.number]).columns.tolist()
df1 = diamonds[col1]
X = pd.concat([df1, out_q4], axis=1) #多个 pd 列
y = diamonds['price']
lr = LinearRegression()
lr.fit(X,y)
y_pred = lr.predict(X)
print(mean_squared_error(y, y_pred, squared=False))
```

##### 非线性

先转线性。

```python
def simple_pipeline(data): # data: pandas DataFrame
    # 定义对 'c2' 进行对数变换的处理
    log_transformer = FunctionTransformer(np.log, validate=True)

    # 创建管道，首先对 'c2' 进行对数变换，然后应用线性回归
    pipeline = Pipeline([
        ('log_scale', log_transformer),
        ('linear_regression', LinearRegression())
    ])

    # 在数据的 'c2' 列和目标变量 'y' 上拟合管道
    X = data[['c2']]
    y = data['y']
    pipeline.fit(X, y)

    # 使用管道对数据进行预测
    predictions = pipeline.predict(X)
    return pipeline, predictions
```

> 综合例子：
>
> - c1 列对 group 列分类，各列分别求标准放缩，然后 c2 求对数放缩，且 group 求 one hot 后，对这些列做回归
>
> 管道写法：
>
> ```python
> from sklearn.metrics import mean_squared_error, r2_score
> from sklearn.pipeline import make_pipeline
> from math import sqrt
> pipeline = make_pipeline(
>     ColumnTransformer([
>         ('group_scale', StdScalerByGroup(), ['group', 'c1']),
>         ('log_scale', FunctionTransformer(np.log, validate=True), ['c2']),
>         ('one_hot', OneHotEncoder(), ['group'])
>     ]),
>     LinearRegression()
> ) #StdScalerByGroup() 在下文数据转化定义的自定义类
> data = q1_data.copy()
> # 拟合管道并对数据进行预测
> X = data[['group', 'c1', 'c2']]  # 包含所有需要的列
> y = data['y']  # 使用 'c1' 作为目标变量进行测试
> pipeline.fit(X, y)
> predictions = pipeline.predict(X)
> 
> # 计算RMSE和R2
> rmse = sqrt(mean_squared_error(y, predictions))
> r2 = r2_score(y, predictions)
> ```
>
> 非管道：
>
> ```python
> from sklearn.metrics import r2_score, mean_squared_error
> def get_R2_and_RMSE(y, yh):#y_real, y_predict
>     return (r2_score(y,yh), mean_squared_error(y, yh, squared=False))
> scalar = StdScalerByGroup().fit(q1_data.iloc[:,:2])
> c1group = scalar.transform(q1_data.iloc[:,:2])
> df = q1_data.copy()
> df['c1'] = c1group
> df['c2'] = FunctionTransformer(np.log, validate=True).transform(df[['c2']].values)
> 
> encoder = OneHotEncoder(sparse=False)
> cols = encoder.fit_transform(df[['group']])
> col_names = encoder.get_feature_names_out(['group'])
> df = pd.concat([df, pd.DataFrame(cols, columns=col_names)], axis=1)
> X = df[['c1','c2','group_A','group_B','group_C']]
> y = df['y']
> lr = LinearRegression()
> lr.fit(X,y)
> yh = lr.predict(X)
> print(get_R2_and_RMSE(y, yh))
> ```

#### 数据转换

##### bool值

`>1` 为 1.0, 否则 0.0：

```python
from sklearn.preprocessing import Binarizer
def transform_carat(self, data):
    binarizer = Binarizer(threshold=1)  # 创建Binarizer对象，阈值设置为1
    return binarizer.transform(data[['carat']].values)  # 转换并返回结果
```

##### 分位数

下面例子，数据将被映射到100个等分的区间中

```python
from sklearn.preprocessing import QuantileTransformer
import pandas as pd
import numpy as np

# 示例数据
data = {
    'carat': [0.5, 0.7, 0.9, 1.1, 1.3],
    'price': [1500, 2500, 3500, 4500, 5500]
}
diamonds = pd.DataFrame(data)

# 创建 TransformDiamonds 类
class TransformDiamonds(object):
    def __init__(self, diamonds):
        self.data = diamonds

    def transform_to_quantiles(self, data):
        transformer = QuantileTransformer(n_quantiles=100)
        transformer.fit(self.data[['carat']])
        return transformer.transform(data[['carat']]).flatten()

# 实例化 TransformDiamonds 类
transformer = TransformDiamonds(diamonds)

# 新数据进行转换
new_data = pd.DataFrame({'carat': [0.6, 0.8, 1.0]})
transformed_carats = transformer.transform_to_quantiles(new_data)

# 打印结果
transformed_carats # array([0.125, 0.375, 0.625])
# 如果丢原数据，返回：[0.   0.25 0.5  0.75 1.  ]
```

##### 自定义

求 $100\%\cdot\dfrac{2z}{x+y}$

```python
def transform_to_depth_pct(self, data):
        def depth_percentage(arr):
            x, y, z = arr[:, 0], arr[:, 1], arr[:, 2]
            with np.errstate(divide='ignore', invalid='ignore'):
                depth_pct = 100 * (2 * z) / (x + y)
                depth_pct[np.isinf(depth_pct)] = np.nan  # 将无限值替换为nan
            return depth_pct
        transformer = FunctionTransformer(depth_percentage)
        return transformer.transform(data[['x', 'y', 'z']].values)
```

> ```python
> log_transformer = FunctionTransformer(np.log, validate=True)
> ```
>
> 当 `validate=True` 时：
>
> 1. **输入验证**：`FunctionTransformer` 将检查输入数据是否是二维数组（或类似数组的结构）。这是因为 Scikit-Learn 的大多数模型和转换器都期望输入数据是二维的。
> 2. **数据转换**：如果输入数据不是浮点数类型的数组，它将被转换为浮点数。这种转换是必要的，因为 Scikit-Learn 的模型通常需要浮点数输入。
> 3. **处理稀疏矩阵**：如果输入数据是稀疏矩阵，`FunctionTransformer` 也会适当地处理它。在某些情况下，这可能涉及将稀疏矩阵转换为密集矩阵，尤其是如果转换函数不支持稀疏矩阵的话。

pandas:

```python
def extract_title(df):
    titles = df['Name'].str.extract(r'([A-Za-z]+)\.', expand=False)
    return pd.DataFrame(titles)
```

如果要用管道，自定义一个类：如三个字符串常量分别转数值

```python
from sklearn.base import BaseEstimator, TransformerMixin
class ClimateCategoryTransformer(BaseEstimator, TransformerMixin):
    def fit(self, X, y=None):
        return self

    '''def transform(self, X):
        mapping = {'cold': 0, 'normal': 1, 'warm': 2}
        return np.array([mapping[item] for item in X]).reshape(-1, 1)'''

    def transform(self, X): 
        mapping = {'cold': 0, 'normal': 1, 'warm': 2}
        # 由于 X 是 DataFrame 列，我们需要用 .iloc[:, 0] 获取实际的 Series 数据
        return np.array([mapping[item] for item in X.iloc[:, 0]]).reshape(-1, 1)


# 列转换
column_transformer = ColumnTransformer(
    transformers=[
        ('climate_category', ClimateCategoryTransformer(), ['CLIMATE.CATEGORY']),
        ('state_one_hot', OneHotEncoder(), ['U.S._STATE']),
    ],
    remainder='passthrough'
)
```



##### 管道

一个 Pipeline 由一系列步骤组成，每个步骤都是一个元组，包含两个元素：

1. 步骤名称：一个字符串，用于标识步骤。
2. 转换器或估计器：可以是任何 Scikit-Learn 转换器（如 `StandardScaler`, `PCA`）或估计器（如 `LinearRegression`, `RandomForestClassifier`）。

```python
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.linear_model import LogisticRegression
# 创建一个 Pipeline
pipe = Pipeline([
    ('scaler', StandardScaler()),   # 第一步：标准化
    ('pca', PCA(n_components=2)),   # 第二步：PCA 降维
    ('classifier', LogisticRegression())  # 第三步：逻辑回归分类器
])
# 使用 Pipeline
# 假设 X_train 和 y_train 是我们的训练数据
pipe.fit(X_train, y_train)
# 对新数据进行预测
y_pred = pipe.predict(X_test)
```

取管道步骤：`pipe.steps[-1][1]` (取最后一步)；取步骤名 `[-1][0]`。(steps 本身是 list-二元tuple)

对管道 fit 会修改，如果不想污染，可以管道拷贝：

```python
from sklearn.base import clone
copied_pipeline = clone(original_pipeline)
```



##### 独热

单独例子参见 pandas - 其他运算 - ont-hot

```python
import pandas as pd
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder

# 示例数据
data = {
    'age': [25, 32, 47, 51],
    'gender': ['male', 'female', 'female', 'male'],
    'income': [40000, 50000, 30000, 45000]
}
df = pd.DataFrame(data)

# 定义 ColumnTransformer
column_transformer = ColumnTransformer(
    transformers=[
        ('cat', OneHotEncoder(), ['gender'])  # 对分类列进行独热编码
    ],
    remainder='passthrough'  # 其他列不变
)

# 应用 ColumnTransformer
transformed_data = column_transformer.fit_transform(df) #numpy.ndarray

# 将转换后的数据转换为 DataFrame 并打印
transformed_df = pd.DataFrame(transformed_data, columns=column_transformer.get_feature_names_out()) #第二个参数是list(str)
print(transformed_df)
'''
   cat__gender_female  cat__gender_male  remainder__age  remainder__income      
0                 0.0               1.0            25.0            40000.0'''
```

可以设置 categories 如 `[['1', '2', '3']]`，避免训练集测试集维度不一样。

```python
from sklearn.preprocessing import OneHotEncoder
categories = [['类别1', '类别2', '类别3']]
encoder = OneHotEncoder(categories=categories)

train_data = [['类别1'], ['类别2']]
encoder.fit(train_data)
train_encoded = encoder.transform(train_data).toarray()

test_data = [['类别3']]
test_encoded = encoder.transform(test_data).toarray()
print("训练数据编码:", train_encoded)
print("测试数据编码:", test_encoded)
```

pandas 多列：categories 传二维数组

```python
import pandas as pd
from sklearn.preprocessing import OneHotEncoder
data = {
    'Feature1': ['A', 'B', 'C', 'A'],
    'Feature2': ['X', 'Y', 'X', 'Z']
}
df = pd.DataFrame(data)
encoder = OneHotEncoder(categories=[['A', 'B', 'C'], ['X', 'Y', 'Z']])
encoded_data = encoder.fit_transform(df[['Feature1', 'Feature2']]).toarray()
encoded_df = pd.DataFrame(encoded_data, columns=encoder.get_feature_names(['Feature1', 'Feature2']))
final_df = df.join(encoded_df)
print(final_df)
```

删除一些列：drop 参数

1. `None`（默认）：不丢弃任何列。这意味着每个类别将会被转换成一个新的列。
2. `'first'`：对于每个特征，丢弃每个类别中的第一个。这样可以减少一个特征的维度，帮助避免多重共线性。
3. `'if_binary'`：只有当特征是二元的（即只有两个类别）时，才会丢弃第一个。这是处理二元特征的一种有效方法。
4. 数组：可以指定一个数组来选择性地丢弃每个特征的某个类别。数组的长度必须与特征的数量相匹配。

```python
from sklearn.preprocessing import OneHotEncoder
data = [['B', 'Y'], ['C', 'X'],['A', 'X']]
encoder = OneHotEncoder(drop='first') # 删除每个特征字典序最小的列
encoded_data = encoder.fit_transform(data).toarray()
print(encoded_data)
'''[[1. 0. 1.] 
 [0. 1. 0.] 
 [0. 0. 0.]]'''
print(encoder.get_feature_names())#['x0_B' 'x0_C' 'x1_Y']
```



##### 多列变换

按照参数顺序生成结果列的顺序。

```python
import pandas as pd
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder, StandardScaler
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LogisticRegression

# 示例数据
data = {
    'age': [25, 32, 47, 51],
    'gender': ['male', 'female', 'female', 'male'],
    'income': [40000, 50000, 30000, 45000]
}
df = pd.DataFrame(data)

# 定义 ColumnTransformer
column_transformer = ColumnTransformer(
    transformers=[
        ('num', StandardScaler(), ['age', 'income']),  # 对数值列进行标准化
        ('cat', OneHotEncoder(), ['gender'])           # 对分类列进行独热编码
    ]
    #如果有别的列，相对顺序保留：
    #,remainder='passthrough'
    #否则，不填，默认remainder='drop'
)

# 创建一个 Pipeline
pipeline = Pipeline([
    ('transformer', column_transformer),
    ('classifier', LogisticRegression())
])

# 假设 X 和 y 是我们的特征和标签
X = df.drop('income', axis=1)
y = df['income']

# 使用 Pipeline
pipeline.fit(X, y)
# 拟合前：
'''cat__gender_female  cat__gender_male  num__age  num__income
0                 0.0               1.0 -1.292419    -0.169031'''
```



对 dataframe，取某一步的列名，参见 `pandas-其他运算-ont hot`。

转换部分，保留部分，其他丢弃，使用 passthrough 转换器。

```python
column_transformer = ColumnTransformer(
    transformers=[
        ('scale', StandardScaler(), ['A', 'B']),  # 应用 StandardScaler 到列 A 和 B
        ('passthrough', 'passthrough', ['C'])     # 保留列 C
    ],
    remainder='drop'  # 抛弃所有未被明确指定的列，即列 D
)
```



##### 标准缩放

StandardScaler $Z=\dfrac{X-\mu}\sigma$；显然 $\sigma=\sqrt{\dfrac{\sum(X_i-\mu)^2}{n}} $

这意味着转换后的数据将围绕 0 居中，具有单位标准差。例子见上。

参数：`with_mean=False`，因此它不会对数据进行均值中心化，但会除以标准差进行缩放。

分列标准缩放：

```python
from sklearn.base import BaseEstimator, TransformerMixin

class StdScalerByGroup(BaseEstimator, TransformerMixin):

    def __init__(self):
        pass

    def fit(self, X, y=None):
        # X might not be a pandas DataFrame (e.g. a np.array)
        df = pd.DataFrame(X)

        # Compute and store the means/standard-deviations for each column (e.g. 'c1' and 'c2'), 
        # for each group (e.g. 'A', 'B', 'C').  
        # (Our solution uses a dictionary)
        self.grps_ = df.groupby(df.columns[0]).agg(['mean', 'std']).to_dict()
        
        return self

    def transform(self, X, y=None):
        try:
            getattr(self, "grps_")
        except AttributeError:
            raise RuntimeError("You must fit the transformer before tranforming the data!")
        
        df = pd.DataFrame(X)
        # Hint: Define a helper function here!
        def standardize(row, column, group):
            mean = self.grps_[(column, 'mean')][group]
            std = self.grps_[(column, 'std')][group]
            if std == 0:
                return row
            return (row - mean) / std

        for col in df.columns[1:]:
            df[col] = df.apply(lambda row: standardize(row[col], col, row[df.columns[0]]), axis=1)

        return df.iloc[:, 1:]
```

##### 缺失值填充

pipeline:

```python
('impute', SimpleImputer(strategy='most_frequent')),
```

##### 非线性变换

工作原理是将每个特征的分布映射到均匀分布或正态分布，这是通过排序和赋予相应的分位数值来实现的。

```python
from sklearn.preprocessing import QuantileTransformer
import numpy as np
data = np.array([[1], [2], [3], [4], [1000]])  # 极端的偏斜数据
scaler = QuantileTransformer(output_distribution='normal')#设为正态分布
transformed_data = scaler.fit_transform(data)
print(transformed_data)
'''[[-5.19933758]
 [-0.67448975]
 [ 0.        ]
 [ 0.67448975]
 [ 5.19933758]]'''
#如果第四行不设参数：均匀分布
'''[[0.  ]
 [0.25]
 [0.5 ]
 [0.75]
 [1.  ]]'''
```



#### 数据处理

##### 训练集划分

```python
from sklearn.model_selection import train_test_split
import numpy as np

# 示例数据
X = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])  # 特征
y = np.array([1, 2, 3, 4])                      # 标签

# 使用 train_test_split 分割数据
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)
'''[[1 2]
 [7 8]
 [3 4]] [[5 6]] [1 4 2] [3] # 每次随机'''
```

也可以传 data frame

随机数生成器的种子，默认参数 `random_state`，如设置为某个整数

##### 时间

pandas 的 datetime 和 timedelta 分别转实数：

```python
class DateToOrdinalTransformer(BaseEstimator, TransformerMixin):
    def fit(self, X, y=None):
        self.base_date = pd.to_datetime('1900-01-01')
        return self

    def transform(self, X):
        return ((pd.to_datetime(X.iloc[:, 0]) - self.base_date).dt.days).values.reshape(-1, 1)

class TimeToMinutesTransformer(BaseEstimator, TransformerMixin):
    def fit(self, X, y=None):
        return self

    def transform(self, X):
        return (X.iloc[:, 0].dt.total_seconds() / 60).values.reshape(-1, 1)
```



##### 数据类型

pipeline 处理结果如果 0 多，可能会转换为 `<class 'scipy.sparse._csr.csr_matrix'>`，需要转化为 numpy 数组才能传 pandas。可以使用 `.toarray()` 方法传。

#### 机器学习

##### 决策树回归

decision tree regressor

原理：基于同叶的均值。

```python
from sklearn.tree import DecisionTreeRegressor
from sklearn.model_selection import train_test_split
import numpy as np

# 示例数据
X = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])  # 特征
y = np.array([1.5, 3.5, 5.5, 7.5])             # 连续型目标变量

# 分割数据为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)

# 创建 DecisionTreeRegressor 模型
regressor = DecisionTreeRegressor()

# 拟合模型
regressor.fit(X_train, y_train)

# 进行预测
y_pred = regressor.predict(X_test)

# y_pred 现在包含了对 X_test 的预测值
print(y_train, y_pred)
#如：[3.5 5.5 1.5] [5.5]
```

可以设置决策树模型的最大树高：`DecisionTreeRegressor(max_depth=20)`

随机数种子：`random_state=580`

误差衡量：

```python
def tree_reg_perf(galton):
    from sklearn.model_selection import train_test_split
    from sklearn.tree import DecisionTreeRegressor
    def rmse(y_true, y_pred):
        return np.sqrt(np.mean((y_true - y_pred) ** 2))
    X_train, X_test, y_train, y_test = train_test_split(galton.drop('childHeight', axis=1), galton['childHeight'], test_size=0.25)
    results = pd.DataFrame(columns=['train_err', 'test_err'], index=range(1, 21))
    for depth in range(1, 21):
        tree = DecisionTreeRegressor(max_depth=depth)
        tree.fit(X_train, y_train)

        train_pred = tree.predict(X_train)
        test_pred = tree.predict(X_test)
        results.loc[depth, 'train_err'] = rmse(y_train, train_pred)
        results.loc[depth, 'test_err'] = rmse(y_test, test_pred)
    return results
```

1. **`criterion`**：用于测量分割质量的函数。对于分类树（`DecisionTreeClassifier`），常见的选择有 `"gini"`（基尼不纯度）和 `"entropy"`（信息增益）。对于回归树（`DecisionTreeRegressor`），常用的是 `"mse"`（均方误差）和 `"friedman_mse"`。
2. **`splitter`**：选择分割节点的策略。可以是 `"best"`（选择最佳分割）或 `"random"`（随机分割）。
3. **`max_depth`**：树的最大深度。这个参数可以用来控制过拟合，因为更深的树会学习到数据中的细节和噪声。
4. **`min_samples_split`**：分割内部节点所需的最小样本数。这可以是整数（最小样本量）或浮点数（代表百分比）。
5. **`min_samples_leaf`**：在叶节点上所需的最小样本数。这同样可以是整数或浮点数。
6. **`min_weight_fraction_leaf`**：叶节点所需的样本权重总和的最小加权分数。
7. **`max_features`**：寻找最佳分割时要考虑的特征数量。可以是整数、浮点数、字符串（如 `"auto"`、`"sqrt"` 或 `"log2"`）或 `None`。
8. **`random_state`**：控制随机性的种子。它在参数为 `"random"` 时选择分割器，或者在选择特征进行分割时。
9. **`max_leaf_nodes`**：最大叶节点数。
10. **`min_impurity_decrease`**：如果分割导致不纯度的减少大于或等于这个值，则该分割将会发生。
11. **`class_weight`**：类别权重，用于处理不平衡的分类问题。

##### K近邻回归

k-nearest neighbors regressor。基于最近 k 个观测点的最公共欧氏距离

```python
from sklearn.neighbors import KNeighborsRegressor
```

对决策树回归的误差衡量例子，把 `tree=` 行换成：`knn = KNeighborsRegressor(n_neighbors=k)`。

##### 随机森林

以经典泰坦尼克号存活预测数据为例 [kaggle](https://www.kaggle.com/c/titanic)

参数代表树的数量，这里是 100。

回归器：

```python
from sklearn.ensemble import RandomForestRegressor
```

分类器：

```python
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import StandardScaler, OneHotEncoder, FunctionTransformer
from sklearn.impute import SimpleImputer

# 特征工程函数
def extract_title(df):
    titles = df['Name'].str.extract('([A-Za-z]+)\.', expand=False)
    return pd.DataFrame(titles)

def standardize_age(df):
    df['Age'] = df.groupby('Pclass')['Age'].transform(lambda x: (x - x.mean()) / x.std())
    return df

# 构建模型的函数
def titanic_model(titanic):
    # 特征提取
    feature_engineering = ColumnTransformer(
        transformers=[
            ('title', FunctionTransformer(extract_title, validate=False), ['Name']),
            ('age', StdScalerByGroup(), ['Pclass','Age'])
            # 该自定义类见上文 数据转换-标准缩放
            #('age', FunctionTransformer(standardize_age, validate=False), ['Age', 'Pclass'])
        ],
        remainder='passthrough')

    # 定义模型
    model = RandomForestClassifier(n_estimators=100, random_state=42)

    # 构建管道
    pipeline = Pipeline(steps=[
        ('feature_engineering', feature_engineering),
        ('one_hot', OneHotEncoder(handle_unknown='ignore')),
        ('impute', SimpleImputer(strategy='most_frequent')),
        ('scale', StandardScaler(with_mean=False)),
        ('model', model)
    ])

    # 训练模型
    pipeline.fit(titanic.drop('Survived', axis=1), titanic['Survived'])

    return pipeline
```

跑准确率：

```python
from sklearn.model_selection import train_test_split
X = titanic.drop(columns = 'Survived')
y = titanic['Survived']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.35)
pre = titanic_model(titanic)
(pre.predict(X_test)==y_test).mean()
```

1. **`n_estimators`**：森林中树的数量。更多的树可以增加模型的稳定性和性能，但同时也会增加计算成本。
2. **`criterion`**：衡量分割质量的函数。对于分类问题，常见的选择包括 `"gini"` 和 `"entropy"`；对于回归问题，通常使用 `"mse"`（均方误差）或 `"mae"`（平均绝对误差）。
3. **`max_depth`**：树的最大深度。深度较大的树可以捕获更复杂的模式，但可能会导致过拟合。
4. **`min_samples_split`**：分割内部节点所需的最小样本数。
5. **`min_samples_leaf`**：叶节点上所需的最小样本数。
6. **`min_weight_fraction_leaf`**：叶节点所需的样本权重总和的最小加权分数。
7. **`max_features`**：寻找最佳分割时要考虑的特征数量。这个参数控制在每个分割点时要随机选择多少特征进行考虑。常见选项包括 `"auto"`、`"sqrt"`、`"log2"` 或自定义数值。
8. **`max_leaf_nodes`**：最大叶节点数。
9. **`min_impurity_decrease`**：如果分割导致不纯度的减少大于或等于这个值，则该分割将会发生。
10. **`bootstrap`**：是否在构建树时使用引导样本（即抽样替换）。默认是 `True`。
11. **`oob_score`**：是否使用袋外样本来估计泛化精度。
12. **`n_jobs`**：拟合和预测时并行运行的作业数。例如，`-1` 表示使用所有处理器。
13. **`random_state`**：控制随机性的种子。
14. **`verbose`**：在拟合和预测时控制详细程度。
15. **`warm_start`**：设置为 `True` 时，将在现有模型上添加更多的树，而不是从头开始建立一个新模型。
16. **`class_weight`**：用于分类的类别权重。

##### SVM

支持向量机 Support Vector Machine 监督学习进行二元分类。一个例子参见 `辅助功能-超参选择`。

参数：

- `C` 是一个正则化参数，用于控制误差和模型复杂度之间的权衡。它决定了模型对于分类错误的容忍度。

  - 高值：赋予高值意味着模型将尝试最大限度地减少训练误差，这可能导致模型过拟合，即在训练数据上表现良好，但在未见数据上表现不佳。
  - 低值：较低的 `C` 值会增加对误分类的容忍度，可能导致欠拟合，即模型在训练数据和未见数据上都表现不佳。

- `gamma` 参数仅适用于 'rbf'（径向基函数）、'poly'（多项式）和 'sigmoid' 核。

  作用：`gamma` 定义了单个训练样本的影响力，即影响范围。它与决策边界的平滑程度密切相关。

  高值与低值

  - 高值：较高的 `gamma` 值会导致更紧密的决策边界，可能导致过拟合。
  - 低值：较低的 `gamma` 值会导致更宽松的决策边界，可能导致欠拟合。

- kernel 核函数。作用：核函数用于在高维空间中寻找最优分隔平面。基本思想是将原始数据映射到一个高维空间，在这个空间中数据可能更容易被线性分割。

  - `linear`：线性核函数，适用于线性可分数据。
  - `rbf`：径向基函数（高斯核），适用于非线性数据，是SVM中最常用的核。
  - `poly`：多项式核函数，可以表示数据之间的更复杂的关系。
  - `sigmoid`：Sigmoid核，类似于神经网络。

二元回归使用 SVR：

```python
from sklearn.svm import SVR
```



#### 辅助功能

##### 超参选择

`GridSearchCV` 用于执行超参数的穷举搜索。它的目的是通过自动化的方式找到最优的参数组合，从而改进机器学习模型的性能。

```python
from sklearn import datasets
from sklearn.model_selection import GridSearchCV
from sklearn.svm import SVC
iris = datasets.load_iris() # 经典数据集
X = iris.data
y = iris.target
param_grid = {
    'C': [0.1, 1, 10, 100],  # SVM正则化参数的候选值
    'gamma': [1, 0.1, 0.01, 0.001],  # 核函数的参数
    'kernel': ['rbf', 'linear']  # 核函数的类型
}
svc = SVC()
grid_search = GridSearchCV(svc, param_grid, refit=True, verbose=2, cv=5)
grid_search.fit(X, y) # 本来的 svc 不会被 refit, 但这个会
print("最佳参数组合: ", grid_search.best_params_)
print("最佳模型得分: ", grid_search.best_score_)
```

`refit`: 当设置为 `True` 时，一旦找到最佳参数组合，它会用这些参数重新拟合整个数据集。

`verbose`: 这个参数控制函数运行时的详细程度。而 `0` 会使得模型在静默模式下运行，不打印任何信息。3 时会输出每个的 score。

`cv`: 这代表交叉验证（Cross-Validation）的折数。在这个例子中，它被设置为 `5`，意味着用于评估不同参数组合性能的数据将被分成 5 份。在每一轮网格搜索中，其中的 4 份用于训练模型，剩下的 1 份用于测试模型。

使用训练集、测试集代替交叉验证：

```python
from sklearn.model_selection import train_test_split, GridSearchCV, PredefinedSplit
from sklearn.svm import SVC
from sklearn.datasets import load_iris
import numpy as np

# 加载数据并分割成训练集和测试集
iris = load_iris()
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.3, random_state=42)

# 合并训练集和测试集，以便于在 GridSearchCV 中使用
X = np.concatenate((X_train, X_test))
y = np.concatenate((y_train, y_test))

# 创建一个指示数据是属于训练集还是测试集的数组
# 训练集标记为 -1，测试集标记为 0
test_fold = np.concatenate((
    -np.ones(X_train.shape[0]), # 训练集
    np.zeros(X_test.shape[0])   # 测试集
))
X = pd.concat([X_train, X_test])
y = pd.concat([y_train, y_test]) # 不然因为打乱了 told 对不上 Xy

# 使用 PredefinedSplit 来使用训练集进行交叉验证
ps = PredefinedSplit(test_fold)

# 设置参数网格
param_grid = {
    'C': [0.1, 1, 10, 100],
    'gamma': [1, 0.1, 0.01, 0.001],
    'kernel': ['rbf', 'linear']
}

# 创建SVC模型并进行网格搜索
svc = SVC()
grid_search = GridSearchCV(svc, param_grid, cv=ps, refit=True, verbose=2)
grid_search.fit(X, y)

# 输出最佳参数和在训练集上的得分
print("最佳参数组合: ", grid_search.best_params_)
print("最佳模型在训练集的得分: ", grid_search.best_score_)

# 使用最佳参数在测试集上评估模型
best_model = grid_search.best_estimator_
test_score = best_model.score(X_test, y_test)
print("模型在测试集的得分: ", test_score)
```

对管道：

```python
test_pipeline = Pipeline(steps=[
    # 其他步骤...
    ('a', DecisionTreeRegressor(random_state=SEED)) 
])

# 定义要测试的 max_depth 值
param_grid = {
    'a__max_depth': [5, 10, 15, 20, 25, 30]
}
```



#### 主成分分析

[参考](https://blog.csdn.net/weixin_46277779/article/details/125533173)

数据标准化：

```python
import pandas as pd
from sklearn.preprocessing import StandardScaler
data = pd.read_csv('audiometric.csv')
scalar = StandardScaler()
scalar.fit(data)
X = scalar.transform(data) #numpy.ndarray
```

> 标准化即 $x=\dfrac{x-\mu}{s}$，其中分母是标准差即 $s=\sqrt{\dfrac{1}{n}\sum(x_i-u)^2}$。[参考](https://zhuanlan.zhihu.com/p/50751333)

主成分拟合：

```python
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
model = PCA()
model.fit(X)
# 每个主成分能解释的方差
print(model.explained_variance_)
# 每个主成分能解释的方差的百分比
print(model.explained_variance_ratio_)
# 可视化
plt.plot(model.explained_variance_ratio_, 'o-')
plt.xlabel('Principal Component')
plt.ylabel('Proportion of Variance Explained')
plt.title('PVE')
plt.show()
# 查看出每个主成分占的贡献百分比
```

```python
# 百分比前缀和
plt.plot(model.explained_variance_ratio_.cumsum(), 'o-')
plt.xlabel('Principal Component')
plt.ylabel('Cumulative Proportion of Variance Explained')
plt.axhline(0.9, color='k', linestyle='--', linewidth=1) # 虚线横线
plt.title('Cumulative PVE')
plt.show()
```

```python
#主成分核载矩阵
print(model.components_)
columns = ['PC' + str(i) for i in range(1, 9)]
pca_loadings = pd.DataFrame(model.components_, columns=data.columns, index=columns)
print(pca_loadings) #与上面一样，只是转成了 pd
```

绘图展示主成分的成分：

```python
fig, ax = plt.subplots(2, 2)
plt.subplots_adjust(hspace=1, wspace=0.5)   
for i in range(1, 5): #只要前四个
    ax = plt.subplot(2, 2, i)
    ax.plot(pca_loadings.T['PC' + str(i)], 'o-')
    ax.axhline(0, color='k', linestyle='--', linewidth=1)
    ax.set_xticks(range(8))
    ax.set_xticklabels(audiometric.columns, rotation=30)
    ax.set_title('PCA Loadings for PC' + str(i))
plt.show()
```

对样本求主成分得分

### sympy

#### 符号运算

##### 求导

```python
import sympy as sp
x = sp.symbols('x')
function = sp.log(x) / x
derivative = sp.diff(function, x)
print(derivative)
```

##### 积分

```python
from sympy import symbols, integrate, sin
x = symbols('x')
integral = integrate(sin(x)**3, x)
print(integral)
```

##### 求和

```python
from sympy import symbols, summation
n, i, j = symbols('n i j')
print(summation(i,1,n))
print(summation(summation(j,(j,1,i)),(i,1,n))) #n**3/6 + n**2/2 + n/3
print(summation(summation(j,(j,1,i)),(i,1,n)).simplify()) # n*(n**2 + 3*n + 2)/6
```

##### 化简

提取公因式等。

```python
(i**2*j-i*j*j).simplify() # i*j*(i - j)
```

##### 极限

```python
from sympy import *
x=symbols('x')
limit(cot(x)-1/x,x,0)
```

单侧极限：

```python
f = 1/x
left_limit = limit(f, x, 0, '-') '-oo'
right_limit = limit(f, x, 0, '+')
```

> ##### 解方程



#### 数值运算

##### 解方程

```python
from sympy import symbols, Eq, solve
alpha = symbols('alpha')
equation = Eq(alpha**2 + (1 - alpha)**2, 0.65) #a^2+(1-a^2)=0.65
alpha_values = solve(equation, alpha) # list of float
```

不等式：

```python
solve(x**2+x-3>0,x)
```



### cvxpy

#### 整数规划

例：求整数线性规划
$$
\min z=40x_1+90x_2\\
s.t.\begin{cases}
9x_1+7x_2\le56\\
7x_1+20x_2\ge70\\
x_1,x_2\in N
\end{cases}
$$

```python
import cvxpy as cp
import numpy as np

c = np.array([40, 90])
a = np.array([[9, 7], [-7, -20]])  #默认<=
b = np.array([56, -70])
x = cp.Variable(2, integer=True)
obj = cp.Minimize(c * x)
cons = [a * x <= b, x >= 0]
prob = cp.Problem(obj, cons)
prob.solve(solver='GLPK_MI')  #, verbose=True (详细输出)
print(prob.value)  #最小值
print(x.value)  #取得最小值的解
# print(x.value[0])#取数组元素
```

例：01整数规划-指派问题(建房子，每栋楼由不重的一个建筑商建，给定报价数组，求方案)
$$
\min z=\sum_{i=1}^n\sum_{j=1}^mc_{ij}x_{ij}\\
s.t.\begin{cases}
\sum_{j=1}^mx_{ij}=1&,1\le i\le n\\
\sum_{i=1}^nx_{ij}=1&,1\le j\le m\\
x_{ij}=0\ 或\ 1&,1\le i\le n,1\le j\le m
\end{cases}
$$

```python
import cvxpy as cp
import numpy as np
c=np.array([[4, 8, 7, 15, 12],
         	[7, 9, 17, 14, 10],
	        [6, 9, 12, 8, 7],
   	     	[6, 7, 14, 6, 10],
        	[6, 9, 12, 10, 6]])
x = cp.Variable((5,5),integer=True)
obj = cp.Minimize(cp.sum(cp.multiply(c,x)))
con= [0 <= x, x <= 1, cp.sum(x, axis=0, keepdims=True)==1,
             cp.sum(x, axis=1, keepdims=True)==1]
prob = cp.Problem(obj, con)
prob.solve(solver='GLPK_MI')
print("最优值为:",prob.value)
print("最优解为：\n",x.value)
```

[更多例题参考](https://blog.csdn.net/abc1234564546/article/details/126263264)

## 文件处理

### yaml

返回 dict：

```python
import yaml
path = 'configs/config_4.yaml'
res = yaml.load(open(path, 'r'), Loader=yaml.SafeLoader)
print(res)
#{'layer_specs': [784, 10], 'activation': 'None', 'learning_rate': 0.01, 'batch_size': 128, 'epochs': 100, 'early_stop': True, 'early_stop_epoch': 3, 'L2_penalty': 0, 'momentum': False, 'momentum_gamma': 0.9}
```

### pickle

序列化，反序列化

```python
import pickle

# 对象序列化
my_dict = {'a': 1, 'b': 2}
with open('example.pkl', 'wb') as f:
    pickle.dump(my_dict, f)

# 对象反序列化
with open('example.pkl', 'rb') as f:
    loaded_dict = pickle.load(f)
    print(loaded_dict)
```



## 文本处理

### chardet

常用编码：utf-8,gbk,gb2312,ascii; euc-jp (日文)

##### detect

检查编码，传入二进制数据，返回一个字典，其中key为encoding的元素是编码方式。

据此可以设计一个返回文件编码的函数：

```python
import chardet
def check(d):#d是文件路径，返回编码方式(str)
    with open(d,'rb') as df:
        dt=df.read()
    return chardet.detect(dt)['encoding']
```

随后再正式打开文件：

```python
with open(d,'r',encoding=check(d)) as f:
    f.read()
```



## 机器学习

### torch

官网按需下载 pytorch

导库：


```python
import torch
print(torch.__version__)
```

#### 创建张量

任意创建一个张量(多维数组)，下以一维数组 $[0,1,\cdots,11]$ 为例：


```python
x = torch.arange(12)
print(x)
```

查看张量的形状和元素数：


```python
print(x.shape, x.numel()) #多维里len是第一维长度,numel才是元素数目
print(list(x.shape)) #一维列表
# print(x.type()) #数据类型
```

> 复制：用于创建一个新的张量，该张量与原始张量共享相同的数据，但是与计算图不再有关系 `.detach()`

类比 numpy，修改张量形状(可以自动计算，用 `-1` 填充)，下面几个张量完全一样：


```python
x1 = x.reshape(3,4)
x2 = x.reshape(-1,4)
x3 = x.reshape(3,-1)
print(x1)
print(x1.shape, x2.shape, x3.shape)
```

全 0 或 全 1 初始的张量，以三维为例：


```python
print(torch.zeros((2,3,4)))
print(torch.ones((2,3,4)))
```

服从标准正态分布 $\mu=0,\sigma=1$ 的张量(注意不等价值域是 $[0,1]$)：


```python
print(torch.randn(2,8))
# torch.normal(mu, sigma, shape_tuple, requires_grad=False)
```

`[0,1)` 均匀分布： `torch.rand(n_train)`

将列表转化为张量或反过来：


```python
x = torch.tensor([[1,1,4,5,1,4],[1,9,1,9,8,1]])
print(x)
print(x.tolist())
```

numpy 与 tensor 互转： 


```python
x = torch.tensor([[1,1,4,5,1,4],[1,9,1,9,8,1]]) #也可以传np array
print(x.numpy())
import numpy as np
na = np.array([1,1,4,5,1,4])
print(torch.tensor(na))
```

numpy 与标量转化：


```python
x = torch.arange(12)
print(x[2].item(),type(x[2].item()))
```

#### 运算

##### 常规

比 for 更快地取出下标，如 $(0,0)$ 和 $(1,2)$：

```python
y = torch.tensor([0, 2])
y_hat = torch.tensor([[0.1, 0.3, 0.6], [0.3, 0.2, 0.5]])
y_hat[[0, 1], y]
```

> 直接运算：
>
> ```python
> x = torch.arange(6,dtype=torch.float32).reshape(2,3)
> y = x
> print(id(x),id(y))
> y[0,1]+=100
> print(x,y,sep='\n')
> z = x.clone()
> z[1,0]-=100
> print(x,z,sep='\n')
> ```

每个对应位置元素运算：


```python
x = torch.tensor([1., 2, 4, 8])
y = torch.tensor([2, -1, 4, 3.1])
print(x+y,x-y,x*y,x/y,x**y,sep='\n')
```

逻辑运算得到 01 张量：


```python
x = torch.tensor([1,1,4,5,1,4,0])
y = torch.tensor([1,9,1,9,8,1,0])
z = x==y
print(z, z.type())
```

张量拼接操作：


```python
x = torch.arange(12).reshape((2,6))
y = torch.arange(12).reshape((2,6)) * -1
print(torch.cat((x,y),dim=0)) #上下拼接
print(torch.cat((x,y),dim=1)) #左右
```

> ```python
> x=torch.normal(0,1,(1,3,4))
> y=torch.normal(0,1,(1,3,4))
> print(x)
> print(torch.cat((x,y)).size()) #2,3,4
> print(torch.cat((x,y))) 
> print(torch.cat((x,y),dim=1).size()) #1,6,4
> print(torch.cat((x,y),dim=1))
> ```

广播机制，行向量各列复制第一列，列向量复制第一行：


```python
x = torch.tensor([0, 1, 2]).reshape((3, 1))  # 列
y = torch.tensor([0, 10]).reshape((1, 2))  # 变二维
print(x+y)
```

类比 numpy，索引和切片机制：


```python
x = torch.arange(25).reshape((5,5))
print(x)
x[2,3]=114 #修改
print(int(x[2,3])) #取元素
x[1]=1 #整行修改
print(x)
x[:,1]=6 #整列
print(x)
print(x[2:4,-1])
```

id 内置函数可以鉴别两个变量是否同一个地址：


```python
x = [1,1,4,5,1,4]
y, z = x, x[:]
print(id(x),id(y),id(z))
```


```python
x = torch.arange(12).reshape((2,-1))
y = torch.arange(12).reshape((2,-1))
print(id(x))
x = x + y 
print(id(x)) #发现进行运算后，原本的x地址位置被丢掉了
x[:] = x + y #不要丢，原地操作
print(id(x))
```

##### 变形

去掉为 1 的维度，使用 squeeze。

```python
x = torch.randn(1, 3, 1, 2, 1)
y = torch.squeeze(x, 2) #第三个维度，即下标为2的维度
print(y.shape)  # torch.Size([1, 3, 2, 1])
y = torch.squeeze(x)
print(y.shape)  # torch.Size([3, 2])
```

> 维度增加：
>
> ```python
> x = torch.tensor([1, 2, 3])  # 一维张量
> print(x.shape)  # 输出: (3,)
> y = torch.unsqueeze(x, 0)  # 在维度0插入新维度
> print(y.shape)  # 输出: (1, 3)
> z = torch.unsqueeze(x, 1)  # 在维度1插入新维度
> print(z.shape)  # 输出: (3, 1)
> ```

将除了第一个维度的其他维度全压到第二维：(GPT)

```python
flatten = torch.nn.Flatten()
x = torch.randn(10, 3, 32, 32)
y = flatten(x)
print(y.shape)  # torch.Size([10, 3072])
```

维度重排序：

```python
x = torch.randn(2, 3, 4)

# 使用permute函数重新排列维度
y = x.permute(1, 0, 2)  # 将维度1和0交换顺序

print(x.shape)  # 输出: torch.Size([2, 3, 4])
print(y.shape)  # 输出: torch.Size([3, 2, 4])
```

##### 线代

转置： `.T` 或 `.t()`

```python
x = torch.arange(12).reshape(3,4)
print(x, x.T)
```

求和：(后两个得到的 sum 都是一行的向量)

```python
x = torch.arange(6,dtype=torch.float32).reshape(2,3)
print(x.sum(), x.sum(axis=0), x.sum(axis=1)) #按列(3,5,7);按行(3,12)
print(x.sum(axis=[0,1])) #等效于 x.sum()
print(x.sum(axis=1,keepdims=True)) #也就是(2,3) size 变成了 (2,1)
```

同理，求均值操作也能这么干。

```python
print(x.mean(), x.mean(axis=0), x.mean(axis=1))
#axis=多少,就是把多少这个维度给干掉
```

求前缀和(按行一维、按列一维、二维前缀和)

```python
x = torch.arange(25).reshape(5,5)
print(x)
print(x.cumsum(axis=1))
print(x.cumsum(axis=0))
print(x.cumsum(axis=0).cumsum(axis=1))
```

只能用于一维向量的内积：

```python
x = torch.tensor([1, 2, 3])
y = torch.tensor([1, 10, 100])
print(torch.dot(x, y), x.dot(y))
```

对矩阵每行都内积一下：(`mv:matrix vector`)

```python
x = torch.tensor([1, 2, 3], dtype=torch.float32)
y = torch.tensor([[1, 10, 1e2], [1e3, 1e4, 1e5]])
print(torch.mv(y, x))  # 类型必须一致
print(torch.mv(y, x))  # 反过来是可以的,结果一致
print(y@x)  # 反过来是不行的
```

矩阵乘法：

```python
x = torch.tensor([[1, 2, 3], [4, 5, 6]])
y = torch.tensor([[-1, -2], [-3, -4], [-5, -6]])
print(x@y) #第一个元素为例,1*-1+2*-3+3*-5=-22
print(y@x) #第一个元素-1*1+-2*4=-9
#分别size:(2,3)*(3,2)=(2,2); (3,2)*(2,3)=(3,3)
print(torch.mm(x,y),torch.mm(y,x), x.mm(y))
# torch.matmul(x,y)
```

> 区别：`x*y` 是逐个元素对应位置乘，即类似标量运算。

范数：

```python
x = torch.tensor([3, -4],dtype=torch.float32)
print(x.norm(), torch.norm(x)) #必须要float, l_2 范数
print(x.abs().sum(), torch.abs(x).sum()) #l_1 范数
```

##### 求导

反向传播的基本原理是链式求导法则。

函数的梯度：

$$\triangledown_{\mathbf x}f(\mathbf x)=\left[
    \partial_{x_1}f(\mathbf x), \partial_{x_2}f(\mathbf x), \ldots, \partial_{x_n}f(\mathbf x)\right]$$

对线代，有性质如下：

1. $\triangledown_{\mathbf x} \mathbf{Ax}=\mathbf{A}^T$,
   $\triangledown_{\mathbf x} \mathbf x^T\mathbf{A}=\mathbf{A}$
2. 对方阵 $\mathbf A$，有 $\triangledown_{\mathbf x}\mathbf x^T\mathbf{Ax}=(\mathbf A+\mathbf A^T)\mathbf x$，且 $\triangledown_{\mathbf x}||\mathbf x||^2=\triangledown_{\mathbf x}\mathbf x^T\mathbf x=2\mathbf x$
3. 对矩阵 $\mathbf X$ 有 $\triangledown_{\mathbf X}||\mathbf X||^2_F=2\mathbf X$

为了优化时空，对要求导的张量，可以这么设：

```python
import torch
x = torch.arange(4.0)
x.requires_grad_(True)
# x = torch.arange(4.0, requires_grad=True)
print(x.grad) #None
y = 2 * x.dot(x) #y=2 x^T * x, y'= 4x
print(y) #tensor(28., grad_fn=<MulBackward0>)
y.backward() #反向传播
print(x.grad) #tensor([ 0.,  4.,  8., 12.])
print(x.grad == 4*x) #tensor([True, True, True, True])
```

```python
x.grad.zero_()
print(x.grad)#tensor([0., 0., 0., 0.])
y = x.sum()
print(y)#tensor(6., grad_fn=<SumBackward0>)
y.backward()
print(x.grad)#tensor([1., 1., 1., 1.])
```

```python
x.grad.zero_()
y = x * x
y.backward(gradient=torch.ones(len(y)))  # Faster: y.sum().backward()
print(x.grad) 
```

```python
x.grad.zero_()
y = x * x
u = y.detach() #u=y的话,x.grad=3*x*x
z = u * x #将u看成与x无关的常量，故z'=u=x*x
z.sum().backward()
print(x.grad)
print(x.grad == u)
```

```python
x.grad.zero_()
y.sum().backward() #不能反复运行
print(x.grad == 2 * x)
```

可以对动态定义的函数进行梯度计算：

```python
def f(a):
    b = a * 2
    while b.norm() < 1000:
        b = b * 2
    if b.sum() > 0:
        c = b
    else:
        c = 100 * b
    return c
a = torch.randn(size=(), requires_grad=True)
print(a) # 标准正态分布的随机实数
d = f(a)
d.backward()
print(a.grad == d / a)
```

##### 概率

模拟随机抛硬币：

```python
import random
import torch
from torch.distributions.multinomial import Multinomial
from d2l import torch as d2l
num_tosses = 10000
heads = sum([random.random() > 0.5 for _ in range(num_tosses)])
tails = num_tosses - heads
print("heads, tails: ", [heads, tails])
```

等效于：

```python
fair_probs = torch.tensor([0.5, 0.5])
#迁移：fair_probs = torch.tensor([0.1, 0.2, 0.7])
print(Multinomial(num_tosses, fair_probs).sample())#浮点xx.0
```

绘图展示：

```python
counts = Multinomial(1, fair_probs).sample((10000,))
print(counts) #上述结果不累加，是 (0,1) / (1,0) 组成的torch
cum_counts = counts.cumsum(dim=0)
estimates = cum_counts / cum_counts.sum(dim=1, keepdims=True)
estimates = estimates.numpy()

d2l.set_figsize((4.5, 3.5))
d2l.plt.plot(estimates[:, 0], label=("P(coin=heads)"))
d2l.plt.plot(estimates[:, 1], label=("P(coin=tails)"))
d2l.plt.axhline(y=0.5, color='black', linestyle='dashed')
d2l.plt.gca().set_xlabel('Samples')
d2l.plt.gca().set_ylabel('Estimated probability')
d2l.plt.legend()
```



#### 设置

```python
torch.set_printoptions(2)  # 精简输出精度
```



## 网络

### requests

#### 基本

get 请求：

```python
import requests
response=requests.get('http://127.0.0.1:8080/')
print(response.status_code) #200
print(response.text) #'Hello world!'
```

```python
params = {
    'key1': 'value1',
    'key2': 'value2'
}
response = requests.get('http://example.com', params=params)
```

```python
data = {
    'key1': 'value1',
    'key2': 'value2'
}
response = requests.post('http://example.com', data=data) #也可以传str
```

```python
import requests
pam = {"username":"name1"}
print(requests.get('http://127.0.0.1:8080/',params=pam).text)
print(requests.post('http://127.0.0.1:8080/submit',json=pam).text)
```

如果返回值是长得像 json 的(如 `{ ... }` 的纯字符串，即完全 json 格式，无 html 格式的)，可以考虑转化为数据结构(如 dict)如：

 ```python
 response.json() #dict
 ```



#### session提速

多个请求，可以创建会话。原理是复用 TCP。可以至少快几倍。

```python
session = requests.Session()
session.get(url) # 多个url
```

#### 代理

```python
proxies = {
    'http': 'http://10.10.1.10:3128',
    'https': 'http://10.10.1.10:1080',
}
response = requests.get(url, proxies=proxies)
```

`socks5h` 与 `socks5` 的区别在于，`socks5h` 会让代理服务器来处理域名解析，而 `socks5` 则是在本地解析。需要：`pip install pysocks`。

### bs

beautiful soup 版本 4 和 3 区别很大。这里按 4 版本来。

```python
import bs4
```

#### 基本

##### 构造

传入一个网页 HTML 字符串，返回解析

```python
html_string = '''
<html>
    <body>
      <div id="content">
        <h1>Heading here</h1>
        <p>My First paragraph</p>
        <p>My <em>second</em> paragraph</p>
        <hr>
      </div>
      <div id="nav">
        <ul>
          <li>item 1</li>
          <li>item 2</li>
          <li>item 3</li>
        </ul>
      </div>
    </body>
</html>
'''.strip()
soup = bs4.BeautifulSoup(html_string)
# 类型为bs4.BeautifulSoup
print(soup.text) #str,标签全部退散，含\n代替
# '\n\n\nHeading here\nMy First paragraph\nMy second paragraph\n\n\n\n\nitem 1\nitem 2\nitem 3\n\n\n\n'
```

第 20 行，可以固定解析器：`features='lxml'`

##### 遍历

DFS 遍历 soup：

```python
for child in soup.descendants:
    if isinstance(child, str):
        continue
    print(child.name)
'''html
body
div...'''
```

##### 查询

找到第一个满足条件的标签实例：(`bs4.element.Tag`)

```python
soup.find(tag)
soup.find(name=None, attrs={}, recursive=True, text=None)
```

找所有：(list)

```python
soup.find_all(tag)
```

print 输出 tag 返回 HTML 格式显示(不含多余空白)

```python
soup.find('div')
soup.find('div', attrs={'id': 'nav'})
soup.find_all('div', attrs={'class': 'quote'})
# 包含该 class
divs = soup.find_all('div', class_='quote') #与上面等价
#同时包含两个class(不区分大小写，不区分顺序)
soup.find('p',class_=['Four','star-rating'])
#有序，区分大小写，与原文完全一致
soup.find('p',class_='star-rating Four')

#找直接儿子加：recursive=False
```

找到并输出文本：

```python
[x.text for x in soup.find_all('li')]
```

##### 基本属性

```python
p = soup.find('div')
print(p.text) #str
print(p.attrs) #dict(str: str), 如{'id': 'content'}
```

取 attrs 的某个属性 value：(查无则 None)

```python
p.get('id') #'content'
```

多个 class 返回 str 列表：

```python
soup.find('p').get('class') #['star-rating', 'Four']
```



#### 例子

##### div列表

考虑：[quote](https://quotes.toscrape.com/)

先下载网页：

```python
def download_page(i):
    url = f'https://quotes.toscrape.com/page/{i}'
    request = requests.get(url)
    return bs4.BeautifulSoup(request.text)
```

然后观察 F12 得到要求的东西的格式编写一个获取每个列表：

```python
def process_quote(div):
    quote = div.find('span', class_='text').text
    author = div.find('small', class_='author').text
    author_url = 'https://quotes.toscrape.com' + div.find('a').get('href')
    tags = div.find('meta', class_='keywords').get('content')
    
    return {'quote': quote, 'author': author, 'author_url': author_url, 'tags': tags}
```

组装成 data frame：

```python
def process_page(divs):
    return pd.DataFrame([process_quote(div) for div in divs])
```

连在一起：

```python
def make_quote_df(n):
    '''Returns a DataFrame containing the quotes on the first n pages of https://quotes.toscrape.com/.'''
    dfs = []
    for i in range(1, n + 1):
        # Download page n and create a BeautifulSoup object.
        soup = download_page(i)
        
        # Create DataFrame using the information in that page.
        divs = soup.find_all('div', class_='quote')
        df = process_page(divs)
        
        # Append DataFrame to dfs.
        dfs.append(df)
        
    # Stitch all DataFrames together.
    return pd.concat(dfs).reset_index(drop=True)
```

使用：

```python
quotes = make_quote_df(3)
quotes.head()
```



### socket

#### 服务端

```python
import socket
```

创建 TCP, IPv4 服务端：

```python
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

设置服务端属性：

```python
s.bind((str-IP, int-端口)) #注意有两个括号！绑定自己的IP和端口号
s.listen(x) #最多同时建立x个端(包括自己)，部分系统不允许超过5个
```

基本指令：

```python
s.recv(x) #服务端一秒可接受数次信息，设置每次接受的数据的量x（bit）。一般设置为1024
s.accept() #尝试一次接收，如果此时有客户端请求连接，则返回该客户端对象sock和addr。使用：sock, addr = s.accept()
sock.send(tmp) #向连接到的客户端发送JSON二进制数据tmp
sock.close() #结束与客户端sock的连接。
```



常见的错误类型有：

ConnectionResetError 当send或recv失败时，会报这个错误。

OSError 因为服务端挂了，send不出去时，会挂这个错误

ConnectionRefusedError 连接失败时会挂这个错误

一般对于这样的错误，使用try…except…，向用户/后台简要地在except处输出一些信息，或干脆pass掉。



#### 客户端

创建同。连接：

```python
s.connect((IP, PORT))
```



#### 示例

##### 聊天

###### 服务端

```python
#server -ver2;注：如果希望记录服务端运行日志，那么就在每次print的时候顺便把这条消息写到文件
import json,socket,threading
def Encode(Message):#加密
    return json.dumps(Message).encode('utf-8')
def Decode(Binary):#解密
    return json.loads(Binary.decode('utf-8'))

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 1303))
s.listen(5)
print('成功创建服务器。等待客户端连接。')

new = []#还未广播给客户端的消息;信息格式：(信息, IP)
rwp = []#所有正在连接着的客户端的sock和addr

def listen(soc, add):#对应了wp[0]和wp[1]
    global new, rwp
    soc.send(Encode('#%s:%s'%(add[0],add[1])))
    print('成功发送标识码。')
    while True:
        try:
            m = soc.recv(1024)
        except ConnectionResetError:#客户端通过非正常途径强行被关闭
            break#那就不管这个客户端了，直接关闭线程，停止接收信息；总不能把服务器关了吧。
        if m == Encode('#exit'):
            break#正常途径的取消连接。
        new.append((m, add))
    for i in range(len(rwp)):
        if rwp[i][1] == add:
            rwp.pop(i)
            break #找到了就不用继续搜索了，注意这个break很重要！
    soc.close()
    print('%s:%s退出了服务器。'%(add[0],add[1]))
def send():
    global new,rwp
    while True:
        if len(new):
            for i in new:#万一同时收到了不止一条信息，也可以很好处理
                for j in rwp:
                    tx='[%s:%s]%s'%(i[1][0],i[1][1],Decode(i[0]))
                    j[0].send(Encode(tx))
                print('[%s:%s]%s'%(i[1][0],i[1][1],Decode(i[0])))
            new.clear()#清空待发送消息列表
T0 = threading.Thread(target=send)
T0.start()
while True:
    sock, addr = s.accept()
    rwp.append((sock,addr))#添加一个元素：sock-addr元组
    print('连接到客户端%s:%s。当前客户端数：%d'%(addr[0],addr[1],len(rwp)))
    T = threading.Thread(target=listen, args=(rwp[-1]))#同时处理多个客户端要用多线程
    T.start()#每次创建的线程都是独立的，虽然都是T变量

```

###### 客户端

```python
#cilent -ver2
import json,socket,threading
from tkinter import *
def Encode(Message):#加密
    return json.dumps(Message).encode('utf-8')
def Decode(Binary):#解密
    return json.loads(Binary.decode('utf-8'))

run, s, T=True, None, None#s,T是定义了变量名，但没有实体化
def send():
    if but['text'] == '发送':
        nr = Encode(ent.get())
        try:
            s.send(nr)
        except ConnectionResetError:#服务器挂了
            tex.insert(0.0,'发送失败，与服务器中断了连接，请点击按钮重新连接。\n')
            but['text']='连接'
    elif but['text'] == '连接':
        conn()
def ex():
    try:
        s.send(Encode('#exit'))
    except OSError:#服务器关闭，发送失败
        pass#那就不发送了呗
    global run
    run=False#结束线程
    root.destroy()#结束窗口
def recv():
    while run:
        try:
            a = s.recv(1024)
        except ConnectionResetError:#服务器挂了
            tex.insert(0.0,'与服务器中断了连接，请点击按钮重新连接。\n')
            but['text']='连接'
            break
        if a:
            b=Decode(a)
            print(b)
            if b[0] == '#':#特殊代码
                root.title('调试客户端'+b[1:])
                continue#不加入到文本框
            tex.insert(0.0,b+'\n')
def conn():
    global s,T#实体化s,T变量;所有要修改的变量都要global声明
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(('127.0.0.1', 1303))
        tex.insert(0.0,'成功连接到服务器。\n')
        T = threading.Thread(target=recv)
        T.start()
        but['text']='发送'
    except ConnectionRefusedError:
        tex.insert(0.0,'连接失败，请点击按钮重新连接。\n')
        but['text']='连接'

root = Tk()
root.title('调试客户端')
ent = Entry(root, width=60)
ent.grid(row=0,padx=6)
but = Button(root, text='发送',command=send)
but.grid(row=0,column=1,padx=6,pady=3)
tex = Text(root, width=60,height=12)
tex.grid(row=1,padx=6,pady=5)
conn()

root.protocol("WM_DELETE_WINDOW", ex)
root.mainloop()
```





### 爬虫

#### 基本准备

加载模块

```python
from urllib import request
```

> 通常还需要引入的库：
>
> ```python
> import random, chardet, re, os
> ```

报头准备：

```python
user_agent_list = [
 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
  'Chrome/45.0.2454.85 Safari/537.36 115Browser/6.0.3',
 'Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50',
 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50',
 'Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0)',
 'Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)',
 'Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1',
 'Opera/9.80 (Windows NT 6.1; U; en) Presto/2.8.131 Version/11.11',
 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11',
 'Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Trident/4.0; SE 2.X MetaSr 1.0; SE 2.X MetaSr 1.0; .NET CLR 2.0.50727; SE 2.X MetaSr 1.0)',
 'Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0',
 'Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1',
]
```

> 移动端：
>
> ```python
> 'Mozilla/6.0 (iPhone; CPU iPhone OS 8_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/8.0 Mobile/10A5376e Safari/8536.25'
> ```

获取一个结果：

```python
def getres(url):
    try:
        ua = random.choice(user_agent_list)
        req = request.Request(url)
        req.add_header('User-Agent', ua)
        res = request.urlopen(req)
        return res
    except ConnectionError:
        print('连接出错，无法连接: %s'%url)
        return None
```

> 位置参数url：网址参数
>
> 默认参数data：None， 或POST/GET   打开网页要用的方法；提交/获取，HTTP协议之一
>
> 默认参数proxies=None  代理
>
> 创建一个类文件对象file-like，返回网页代码

> 查看网页信息：
>
> ```python
> response = urllib.request.urlopen('http://python.org/')
> print("查看 response 的返回类型：",type(response))
> print("查看反应地址信息: ",response)
> print("查看头部信息1(http header)：\n",response.info())
> print("查看头部信息2(http header)：\n",response.getheaders())
> print("输出头部属性信息：",response.getheader("Server"))
> print("查看响应状态信息1(http status)：\n",response.status)
> print("查看响应状态信息2(http status)：\n",response.getcode())
> print("查看响应 url 地址：\n",response.geturl())
> page = response.read()
> print("输出网页源码:",page.decode('utf-8'))
> ```

抓取并写入一个网页的HTML及其编码方式：

```python
def gethtml(url):
    res = getres(url)
    q = res.read()
    ic = chardet.detect(q).get('encoding', 'utf-8') # dict的get方法，如果得不到，默认采用utf-8
    return [str(q.decode(ic, 'ignore')), ic]
```

获取并写入一张图片：

```python
res = getres(url)
if not res == None:
    with open(objcwd, 'wb') as f:
        f.write(res.read())
```



如若遇到报错：

```shell
urllib.error.URLError: <urlopen error [SSL: CERTIFICATE_VERIFY_FAILED] certificate verify failed: certificate has expired (_ssl.c:1091)>
```

那么需要添加代码，设置全局取消证书验证：

```python
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
```

#### robots.txt

##### 基本概念

[解释文档](https://moz.com/learn/seo/robotstxt)

在网站根目录下的 `robots.txt`(大小写敏感，不可 `Robots.TXT` 等)，全员可看。子域名可以独立。

遵循 robots exclusion protocol (REP) 协议，指示爬虫怎么爬。(建议性规约)

- 空行：隔开不同的爬虫主体
- `#` 注释
- `Disallow: 路径` 可以含通配符如 `*?$`(以什么结尾)
- `Allow: 路径`
- `Crawl-delay: 数字毫秒`

> 参考样例：
>
> ```plain
> # See http://www.linkedin.com/legal/crawling-terms.
> 
> User-agent: Googlebot
> Disallow: /addContacts*
> Allow: /settings/loid-email-unsubscribe*
> Allow: /help/
> 
> User-agent: Applebot
> Disallow: /addContacts*
> Allow: /help/
> 
> User-agent: *
> Disallow: /
> ```
>
> ```
> User-agent: *
> Allow: /
> ```

爬虫程序爬取前首先读 `robots.txt`。

#### 示例

##### 爬取HTML

```python
res = gethtml('https://oj.socoding.cn/')
with open('a.html', 'w', encoding=res[1]) as f:
    f.write(res[0])
```



##### 爬取特定关键字

```python
htmls = gethtml('https://oj.socoding.cn/p/1557')
res = re.findall('>([^>]{0,}?鞘翅[^<]{0,}?)<', htmls[0])
for i in res:
    print(i + '\n')
```



##### 爬取图片

```python
res = gethtml('https://oj.socoding.cn/user/view?id=29')
addrs = re.findall(
    r"<img class='img-thumbnail img-fluid' src=\"(.{1,}?)\"", res[0])
cnt=0
for i in addrs:
    p = 'https://oj.socoding.cn/'+i
    d = p[p.rfind('/')+1:]
    res = getres(p)
    if not None == res:N
        with open(d,'wb') as f:
            f.write(res.read())
```



##### 爬取多个网页的标题

```python
enc = ''
ans = ''
for i in range(1, 8):
    idx = str(i)
    url = 'https://oj.socoding.cn/problem/index?page=' + idx
    htmls = gethtml(url)
    enc = htmls[1]
    # r"<a class=\"text-dark\" href=\"(.{1,}?)\">(.{1,}?)</a>", htmls[0])
    result = re.findall(
        r"<a class=\"badge badge-secondary\"(.{1,}?)</a></td><td><a class=\"text-dark\" href=\"(.{1,}?)\">(.{1,}?)</a>", htmls[0])
    for j in result:
        ans += j[-1] + ' https://oj.socoding.cn' + j[-2] + '\n'
    print('Done ' + idx + ', find ' + str(len(result)))
with open('titles.txt', 'w', encoding=enc) as f:
    f.write(ans)
```



### 远程操作

> 图源华为HCIA,HCIP课件，权侵删

#### telnetlib

标准库，实现了 `Telnet` 功能

![image-20220426151213502](img/image-20220426151213502.png)

![image-20220426151225095](img/image-20220426151225095.png)

> 推荐使用SSH，而不是telnet；此时可以用 `paramiko` 或 `netmiko` 库操作 SSH



#### paramiko

是第三方库，需要先pip安装。用于SSH操作。

![image-20220426201159100](img/image-20220426201159100.png)

![image-20220426201229365](img/image-20220426201229365.png)

![image-20220426202930813](img/image-20220426202930813.png)

![image-20220426204605383](img/image-20220426204605383.png)

![image-20220426204642191](img/image-20220426204642191.png)

![image-20220426204651443](img/image-20220426204651443.png)

![image-20220426204932184](img/image-20220426204932184.png)

![image-20220426205007379](img/image-20220426205007379.png)

![image-20220426205303126](img/image-20220426205303126.png)

![image-20220426205320302](img/image-20220426205320302.png)

![image-20220426205334175](img/image-20220426205334175.png)

![image-20220426205500774](img/image-20220426205500774.png)

### Flask

#### 简单post

几乎都是 GPT 生成。

```python
#你的核心业务代码,也可以单独写一个.py然后import过来
def mainFunc(name):
    #返回的是你业务代码处理得到的结果
    return {'data': name + "爱lr580", 'type': 3}


from flask import Flask, request

# print(__name__) '__main__'
app = Flask(__name__)


@app.route('/', methods=['POST'])
def call_mainFunc():
    name = request.form.get('name')
    res = mainFunc(name)
    return res

app.run(port=52580)  #[1024,65535]任意int
```

测试：

```python
import requests
requests.post('http://127.0.0.1:52580/',data={'name':'yym'}).text
```

网页测试：

```html
<!DOCTYPE html>
<html>
    <head>
        <title>lr580是米娜桑的主人</title>
    </head>
    <body>
        <form>
            <label for="name">你的名字：</label>
            <input type="text" id="name" name="name">
            <button type="button" onclick="callPythonServer()">提交</button>
        </form>
        <div id="result"></div>
        <script>
        //你用jquery也行，我懒，就不用了
		function callPythonServer() {
			// 获取输入框中的名称
			var name = document.getElementById("name").value;

			// 创建一个XMLHttpRequest对象
			var xhr = new XMLHttpRequest();

			// 设置POST请求的URL和参数
			var url = "http://localhost:52580/";
			var params = "name=" + name;

			// 发送POST请求
			xhr.open("POST", url, true);
			xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
			xhr.onreadystatechange = function() {
				if (xhr.readyState == 4 && xhr.status == 200) {
					// 显示结果
                    var res = JSON.parse(xhr.responseText);
					document.getElementById("result").innerHTML = "data: " + res.data + ", type: " + res.type;
				
				}
			};
			xhr.send(params);
		}
        </script>
    </body>
</html>
```



> ### 其他
>

> `PySNMP` 模块可以实现 SNMP 功能

## 数据结构

### sortedcontainers

#### SortedSet

与 set 差不多用法

```python
from sortedcontainers import SortedSet
s = SortedSet([3, 1, 1, 5, 4, 2]) # 会去重掉多余的 1
s.add(6) # 返回 None
s.discard(3) # 返回 None
assert 6 in s # in 操作
print(s[2])  # 输出排序后的第三个元素
for element in s:
    print(element) # 1,2,4,5,6
s2 = SortedSet([5, 6, 7])
print(s | s2)  # 并集
print(s & s2)  # 交集
```



## 算法

### networkX

图论库。[官方文档](https://networkx.org/documentation/stable/tutorial.html), github 有项目

```python
import networkx as nx
```

#### 建图

##### 常规

```python
g = nx.Graph() #无向图，有向是DiGraph
```

点可以是任何 hashable，使用 `add_node` 方法添加单点，用 `add_nodes_from` 从 iterable 或 已知图添加点。用 `.nodes` 取所有点，可强转 list，下同

边用 `add_edge` 填两参，同理可以 `add_edges_from`。会自动去重边，要重边的话要用 `MultiGraph`。可以用 `.edges` 取所有边

如，构造一个圈：

```python
import networkx as nx

g = nx.Graph()
g.add_nodes_from([i for i in range(1, 11)])
for i in range(1, 11):
    j = i % 10 + 1
    g.add_edge(i, j)

print(g.nodes, g.edges)
```

`adj` 属性返回一个 dict 邻接表，key 是点，val 是 dict, 其 key 是点

`degree` 属性返回各点的度。都可以用 `[]` 运算符询问单独一个点

多个询问，用 `edges` 方法+iterable 和 `degree` 同理。结果会去重，如：

```python
print(g.adj[1], g.degree[1]) #前者可简写为g[1]
print(g.edges([1, 2]), g.degree(1, 2)) #简写为g.edges[1,2]或g[1][2]
```

删用 `remove_node`, `remove_edge`

点/边的属性(点权可用 dict 表示，key 是属性名，也可以不)，可以直接赋值，如 `g[][key]=val`，边就 `g[][][key]=val`

加权边：`add_weighted_edges_from`

> 遍历边：
>
> ```python
> for i,j in g.edges(): #可以取len(.edges())
> 	print(i,j) #int, int
> ```



##### 预制

[更多](https://networkx.org/documentation/stable/reference/generators.html)

生成随机 DAG，且点值从 $[0,n)$ 偏移到 $[1,n]$：

```python
from networkx.generators.random_graphs import gnm_random_graph
import networkx as nx
dag = gnm_random_graph(n, m)
dag = nx.relabel_nodes(dag, {i: i + 1 for i in range(n)})
print(dag.edges())
```

随机树：`nx.random_tree(n)`

n点的链：`nx.path_graph(n)`

完全图：`nx.complete_graph(n)`

0为中心的n边菊花图：`nx.star_graph(n)`

n点完全k叉树：`nx.full_rary_tree(k,n)`



#### 绘制

```python
import matplotlib.pyplot as plt
```

```python
nx.draw(g, with_labels=True, font_weight='bold')
# nx.draw_shell(g, with_labels=True, font_weight='bold')
# plt.show() 窗口化输出
plt.savefig("path.png")
```



#### 举例

##### 判断富勒烯图

```python
#(4,5,6)-富勒烯图是3正则3连通且只有4,5,6圈的平面图
import networkx as nx

g = nx.Graph()
n, m = [int(i) for i in input().strip().split()]
for i in range(m):
    u, v = [int(i) for i in input().strip().split()]
    g.add_edge(u, v)

is3Regular = nx.is_k_regular(g, 3)
#print('3-正则:', is3Regular)

is3Connected = nx.is_k_edge_connected(g, 3)
#print('3-连通:', is3Connected)

isPlanar = nx.is_planar(g)
#print('平面图:', isPlanar)

#只有4,5,6圈->不存在<=3或>=7的基圈(基圈通过边异或能组成图上所有圈)
cycles = nx.minimum_cycle_basis(g)
minLen = len(min(cycles, key=lambda x: len(x)))
maxLen = len(max(cycles, key=lambda x: len(x)))
isOnly456 = minLen >= 4 and maxLen <= 6
#print('只有4,5,6圈:', isOnly456)

isFullerene = is3Regular and is3Connected and isPlanar and isOnly456
print(isFullerene)
```

## 其他

### ipywidgets

##### 交互

在 jupyter 创建交互的工具

```python
from ipywidgets import widgets, interact, FloatSlider
```

创建一个交互下拉选择框，以某列的值作为下拉选项，每次只筛选出数据里列值为它的行，然后对这些行另两列做绘图，使用：

```python
import plotly.express as px
def plot_cases(country):
    country_only = vacs[vacs['Country_Region'] == country]
    fig = px.line(country_only, x='Date', y='Doses_admin', title=f"'Doses_admin' column for {country}")
    fig.show()
    

dropdown_cases = widgets.Dropdown(options=np.sort(vacs['Country_Region'].unique()), value=DEFAULT)

def dropdown_cases_handler(change):
    if change['name'] == 'value' and (change['new'] != change['old']):
        clear_output()
        display(dropdown_cases)
        plot_cases(change['new'])
        
display(dropdown_cases)
plot_cases(DEFAULT)
dropdown_cases.observe(dropdown_cases_handler)
```

其中：清除 Jupyter 笔记本的单元格输出区域

```python
from IPython.display import clear_output
clear_output()
```

##### HTML渲染

```python
from IPython.display import HTML
HTML('<h1>Hell word！</h1>')
```

##### 图片渲染

```python
from IPython.display import Image, display
display(Image('https://datascience.ucsd.edu/wp-content/uploads/2022/09/Ery-Arias-Castro-Web.jpg'))
```





# 应用举例

#### 网络

##### 局域网共享文件

cd 到要贡献的目录下，输入：

```sh
python -m http.server 8888
```

之后本机，和局域网内的其他机子，可以下载该目录下的文件。

ctrl+c 关闭。

#### 文件

##### 统计 java 项目代码总行数

```python
import os
cnt = 0
for root, dirs, files in os.walk('.'):
    for i in files:
        p = os.path.join(root, i)
        if os.path.splitext(p)[1] == '.java':
            with open(p, 'r', encoding='utf-8') as f:
                t = len(f.readlines())
                cnt += t
print(cnt)
```



##### 将 markdown 标题全部降一级

```python
with open('LaTeX.md', 'r', encoding='utf8') as f:
    r = f.readlines()
t = ''
for i in r:
    if len(i) and i[0] == '#' and i.count('#') <= 6:
        i = '#' + i
    t += i #不要再加'\n'了
with open('LaTeX2.md', 'w', encoding='utf8') as f:
    f.write(t)
```



##### 批量修改后缀名

GPT4：

```python
import os
from pathlib import Path

def change_file_extension(path, old_extension, new_extension):
    for filepath in path.glob(f"*.{old_extension}"):
        # 用新的扩展名替换旧的扩展名
        new_filepath = filepath.with_suffix(f".{new_extension}")
        # 对文件进行重命名
        filepath.rename(new_filepath)

# 设置路径为当前工作目录
path = Path(os.getcwd())
change_file_extension(path, 'jpg', 'gif')
```



