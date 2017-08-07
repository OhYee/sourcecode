---
title: 第一个 Qt 程序
date: 2016-10-31 18:25:35
categories: 笔记
tags: Qt
---
帮忙写数据结构的课程设计,要用到界面,就顺便入门了下 Qt (算不上入门,只是能跑起来而已)   
<!--more-->
# 安装 Qt
![](/post/img/Qt_1.gif)

安装目录里 `\Qt\Tools\QtCreator\bin\qtcreator.exe` 就是 Qt 的编辑器  
打开后新建项目就可以像 VS 里一样写代码  
![](/post/img/Qt_2.gif)  

如图, `编辑` 是代码界面  
 `设计` 就是 UI 界面  

# 编译

编译项目需要有调试器(不然会提示 `qt 调试器未设置` ),可以下载 Microsoft 的调试器 `dbg`  
![](/post/img/Qt_3.gif)  

在 `工具->选项->构建和运行->构建套件(Kit)` 设置好 `dbg.exe` 即可  
然后就能点左下角的绿色箭头编译并运行了  

# 项目结构
一个标准的项目包括  
```
头文件
    mainwindow.h
源文件
    main.cpp
    mainwindow.cpp
界面文件
    mainwindow.ui
```

其中 `mainwindow` 就是默认的窗口名称  
ui 就是其界面布局
h 是其布局结构的定义(有哪些控件)
cpp 则是页面对应的各种功能的实现(按下按钮等)

每一个窗口都是一个类,因此如果想要写一个函数对一个窗口操作,就要在头文件里添加声明  

# 最后
并没有在界面上卡很久,和 VB 易语言的界面类似,还是比较容易入手的  
然而最后在 C++ 上卡了好久……  

