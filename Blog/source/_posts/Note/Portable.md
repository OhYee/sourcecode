---
title: Hexo + C++ 便携套装
date: 2016-11-07 14:54:41
categories: 笔记
tags:
- portable
- hexo
- git
- nodejs
- vscode
---
Hexo 相比于其他博客系统,最大的问题就是发布博客需要大量的前置工作:安装 Nodejs,安装 Git,安装一个靠谱的 Markdown 编辑器……  
因此,将 **环境装到U盘** 里是一个非常好的解决方案  
<!--more-->

# 后台环境
首先确定大致思路,U盘的组件必然是无法加入到环境变量的,只能采用批处理的形式临时加入到环境变量里,然后在这个控制台中调用相应的功能  

OK,先准备好 Nodejs 和 Git 将他们放到同一个文件夹里,然后在博客的源文件目录写上批处理即可  

```bash
@echo off

cls

cd Blog

set path=%path%;%cd%\..\..\Support\git\bin\;%cd%\..\..\Support\npm\bin\;%cd%\..\..\Support\nodejs\;%cd%\..\..\Support\npm\;%cd%\..\..\Support\git\

hexo %1 %2 %3

cd ..\
```

# 编辑器 
后台实现之后,还需要一个编辑器来写 Markdown  
能选择的有 Vim,Atom,VS Code  
毫无疑问选择了 VS Code 颜值过关,并且还自带 Markdown  

解压 portable 版本的 VS Code  
然后同样使用批处理来解决文件配置的问题(键盘映射必须要在系统目录里,因此要写一个批处理一键复制过去)  

# 顺便编译下 cpp  
有了上面的经验,再搞编译器就简单了,同样把 MinGW 复制到U盘里,然后在 VS Code 里使用 tasks 来调用批处理  
编译运行即可  
(没法逐步调试,不过应该可以使用控制台的逐步调试来解决这个问题,但是意义不大)  

