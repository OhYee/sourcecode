---
title: 如何写好Makefile
date: 2017-06-26 00:18:21
categories: 
- 笔记
- UNIX网络编程
tags:  
  - Linux
keywords: 
  - makefile
  - make
---

对于一个项目而言,整体源码必然是分布在众多文件夹中的  
那么就出现了我们写简单的单个 `cpp` 文件不会遇到的问题: 哪些文件需要先编译?哪些文件需要后编译?哪些文件需要重新编译?  

Makefile就是一个帮你处理这些功能的文件,在 *nix 环境下,有 `make` 命令来读取 `Makefile` 文件并进行相应的操作   

<!--more-->
# 编译和链接
首先,需要知道的是把源码编程我们能执行的二进制文件,有两步重要的操作: **编译(compile)**和**链接(link)**  

## 编译
编译是针对每一个文件,把他们转换成二进制文件. 这是单纯的翻译过程,只要源码语法正确,就可以正常编译出中间文件(目标文件)  
对于每一个源码文件,编译后都会产生一个中间文件(`.o`或是`.obj`)  

该部分对应了 `g++` 的 `g++ -c <SourceCodeFilename>`

## 链接
编译过后我们有了能够被执行的二进制文件,那么问题来了: 一个条例清晰的文件,可能其函数声明和定义并不在一个文件里,如何找到各个部分之间的关系就是链接部分要解决的问题了  

该部分对应了 `g++` 的 `g++ <ObjectFilename> -o <OutputFilename>`

## 库
项目比较大的时候,自然不可能改一下就重新整体编译一次,那么就有了库(library)  
将一些目标文件(Object)打包成库文件,然后链接的时候直接链接库文件和改动部分的目标文件即可  
库文件在 Windows 下为 `.lib` 在UNIX下是 `.a`

# Makefile的使用
首先我们要明白Makefile需要做什么: 
1. 如果这个工程没有编译过,那么所有C文件都要编译并被链接
2. 如果这个工程的某几个C文件被修改,那么我们只编译被修改的C文件,并链接目标程序
3. 如果这个工程的头文件被改变了,那么我们需要编译引用了这几个头文件的C文件,并链接目标程序

举例一个makefile的例子如下:
```
test:   a.o b.o c.o d.o /
    A.o B.o C.o D.o
    cc -o test a.o b.o c.o d.o /
    A.o B.o C.o D.o

a.o:     a.c F.h
    cc -c a.c
b.o:     b.c F.h c.h
    cc -c b.c
c.o:     c.c F.h c.h
    cc -c c.c
d.o:     d.c F.h E.h
    cc -c d.c
A.o:     A.c F.h E.h
    cc -c A.c
B.o:     B.c F.h E.h
    cc -c B.c
C.o:     C.c F.h E.h c.h
    cc -c C.c
D.o:     D.c F.h
    cc -c D.c

clean:  
    rm edit a.o b.o c.o d.o /
    A.o B.o C.o D.o
```

很容易可以看出来大概的含义: 
```
[要生成的文件]:   [生成该文件所依赖的文件列表]
    [生成该文件的命令行]
```
其中,如果需要换行,就在末尾加 `\` 

再正式一下,就是
```
<target>:   <prerequisites>
    <command>
```

target是一个目标文件,可以是Object File,也可以是执行文件
还可以是一个标签（Label）

prerequisites就是,要生成那个target所需要的文件或是目标

command也就是make需要执行的命令（任意的Shell命令）
需要注意的是,如同缩进一样,command部分必须由<kbd>tab</kbd>开头

当没有依赖文件的时候,这一条就会被识别为标签,例如上面的 `clean`  
当运行 `make clean` 时,就会清空所有生成的中间文件和最终输出文件  

这样,对于上面的文件,`make` 命令会以第一个目标文件为最终输出,按照修改时间检查所有目标文件和依赖文件,如果依赖文件更新或者目标文件不存在就会运行相应的命令生成目标文件,最终得到一个输出文件  

当文件大量重复时,就可以使用变量了  
`v = a.o b.o`
使用时用 `$(v)` 就可以代替 `a.o b.o` 了  

而根据习惯,我们生成的中间文件一般是与源文件同名的,也就是说 `a.o` 时通过 `a.c` 生成的  
并且对应的编译指令也是可以推测出的  

那么完全可以简化成
```
[中间文件]: [对应的头文件]
```
这样只要对应的头文件或者源文件有改动,中间文件就会自动通过相应的编译指令生成  
这叫做make的**隐晦规则**  

对于清理命令,也有更为严谨的写法
```
.PHONY : clean
clean :
-rm edit $(objects)
```
`.PHONY` 说明 `clean` 是一个伪目标  
而 `rm` 前面的 `-` 则告诉系统,当 `rm` 无视可能会出错的情况继续执行后面的(比如删除一个不存在的文件)  

这时,clean即使是伪目标,也可以写依赖项了  
比如我的默认操作是生成许多文件,就可以写成
```
all: a b c d
.PHONY all

a: ……
……
```


如果项目中存在多个makefile时,可以使用`include`来引用其它的makefile文件  
如果需要忽略报错,可以使用`-include`或`sinclude`  


当文件夹比较多时,就需要让makefile自己去找你要编译的文件到底在哪个文件夹里了  

```
VPATH = src:../headers

vpath %.c src
vpath %.h ../headers
```
前者是搜索目录先从当前目录开始,然后是`src`,最后是`../headers`(使用`:`分割)  
后者则是针对不同的文件,进行不同的搜索目录(`vpath`用小写)


# 参考目录
[Linux makefile 教程 非常详细，且易懂](http://blog.csdn.net/liang13664759/article/details/1771246)