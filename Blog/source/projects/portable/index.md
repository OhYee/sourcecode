---
layout: page
title: Portable Development Environment
description: U盘版集成开发环境
comments: false     # 禁用评论，可选，默认开启
reward: true       # 禁用打赏，可选，默认开启
---

@card{

使用VSCode以及一些配置文件实现在U盘完成开发工作  

已确认支持语言: <span class="label label-sky">C/C++</span>、<span class="label label-red">Java</span>、<span class="label label-blue">Python</span>、<span class="label label-green">Node.js</span>  
另外也可配置<span class="label label-orange">Git</span>环境,因此也可以用来写Hexo博客  

编程学习者可以用该环境更方便地进行代码编写工作(比如在网吧)  
非编程开发人员也可以用来随时随地更新自己的Hexo博客   

设备要求:
 - U盘一个,空间大于2G
 - **Windows 7 以上(不包括)电脑**(更低版本无法运行VS Code)
(如果希望在所有系统下保证开发环境,可以使用Deepin来实现)  

实现思路:
 - 通过在运行VS Code前使用命令行语句设置临时环境变量,实现开发环境的构建
 - 通过VS Code的参数来指定插件目录和数据目录到U盘内  

因此按照该思路,理论上可以实现绝大多数编程环境的U盘化  

}

@card{

# 具体步骤
1. 下载[VS Code ZIP版](https://code.visualstudio.com/docs/?dv=winzip)  
2. 使用cmd来配置临时环境变量,并且设定VS Code启动目录
```cmd
set VSCodePath=%cd%\VSCode
set default_path=%path%
set PortableENV=%VSCodePath%\environment

set path=%PortableENV%\git\
set path=%path%;%PortableENV%\git\bin\
set path=%path%;%PortableENV%\git\usr\bin\

set path=%path%;%PortableENV%\nodejs\
set path=%path%;%PortableENV%\nodejs\node_modules\npm\
set path=%path%;%PortableENV%\nodejs\node_modules\npm\bin\

set path=%path%;%cd%\Code\Blog\node_modules\
set path=%path%;%cd%\Code\Blog\node_modules\.bin\

set path=%path%;%PortableENV%\MinGW\bin\
set path=%path%;%PortableENV%\MinGW\lib\
set path=%path%;%PortableENV%\MinGW\include\

set path=%path%;%PortableENV%\Python\
set path=%path%;%PortableENV%\Python\Scripts\

set path=%path%;%PortableENV%\cmder\

set JAVA_HOME=%PortableENV%\Java\jdk1.8.0_131
set path=%path%;%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;
set CLASSPATH=%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;

set path=%path%;%default_path%

start %VSCodePath%\VSCode\Code.exe -n --user-data-dir %VSCodePath%\data --extensions-dir %VSCodePath%\extension  ./Code
exit  
```
  前三行是需要用到的参数
  - `VSCodePath` 是VSCode的路径  
  - `default_path`是默认的环境变量(如果电脑的环境里和U盘里配置了同样的环境,优先使用U盘环境)  
  - `PortableENV`是U盘环境目录,开发环境在该目录里

  下面需要用到那些环境就保留哪一部分即可  
  最后是默认打开`Code`文件夹  
3. 下载对应的环境安装到电脑,安装完成后把文件复制到`PortableENV`文件夹内,然后电脑内的可以视需要卸载掉  
  - [git](https://github.com/git-for-windows/git/releases)
  - [Python](https://www.python.org/downloads/)
  - [nodejs](https://nodejs.org/en/download/current/)
  - [MinGW](https://sourceforge.net/projects/mingw/files/)
  - [cmder](https://github.com/cmderdev/cmder/releases/)

4. 使用`run.bat`运行VS Code即可

}