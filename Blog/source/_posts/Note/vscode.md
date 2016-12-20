---
title: VS Code 便携环境配置
date: 2016-12-10 15:08:26
categories: 笔记
tags:
  - Hexo
  - MinGW
  - Python
  - vscode
keywords:
  - portable
  - Hexo
  - U盘
  - U盘写Hexo博客
  - U盘编译C/C++
  - U盘编译Python
---
关键词: U盘写Hexo博客 | U盘编译C/C++ | U盘编译Python
支持 <span class="label label-green">node.js</span><span class="label label-sky">Hexo</span><span class="label label-red">Git</span><span class="label label-blue">Python</span><span class="label label-orange">MinGW</span>


在 [Hexo + C++ 便携套装](/post/Note/Portable.html) 里,介绍了将 VS Code portable 化的基础思路  
经过改进,将该功能改的更加完美  

<!--more-->

# 准备工作
由于需要的文件过大,不提供直接下载,请根据思路自行配置自己需要的部分  

## 获取需要的文件
首先,可以得知,类似 Git、MinGW 安装后,都是通过加入到环境变量里后,通过命令行调用的,因此我们完全可以通过将U盘路径加入到命令行里来实现在U盘配置自己的环境
从各个官网获取需要的程序,正常安装,然后将安装文件夹整个拷贝到U盘里,卸载电脑上的程序,我们就获得了文件的主体  
(当然,如果能够直接下载 `zip` 更好,不过有个功能不太全)  

## 目录结构
取得需要的文件后,目录如下:  
> - Portable //主目录
>   - Code //代码文件夹,一般可以将该文件夹整个备份到git上
>     - Blog //博客文件夹
>       - node_modules //hexo 主文件
>   - Support //需要加到环境变量里的文件
>     - Git //用来给VS Code提供git 同时Hexo也用得到
>     - nodejs //Hexo需要
>     - MinGW //编译C/C++需要
>     - Python //写Python需要
>   - ssh //备份的ssh,用来在其他电脑上连接git
>   - VS Code //编辑器
>     - resources
>       - app
>         - extensions //VS Code 插件文件夹


# 具体操作
<span class="label label-sky">Hexo</span>的配置需要<span class="label label-green">node.js</span>和<span class="label label-red">Git</span>  
编译C/C++需要<span class="label label-orange">MinGW</span>

关于配置环境方面,各个部分是一样的,只举一种例子.  
以 Hexo 为例,按照上面的部分下载完成后,放到该放的地方上.  

## Hexo

在 `Portable\Code\Blog` 文件夹里初始化 Hexo (如果没有安装 Hexo 组件,安装到这个文件夹里)  
或者将自己已经有的博客文件拷贝进来也行  

在博客主目录下写文件 `portable\run.bat`  
```bat run.bat
set path=%path%;%cd%\Support\git\
set path=%path%;%cd%\Support\git\bin\

set path=%path%;%cd%\Support\nodejs\
set path=%path%;%cd%\Support\node_modules\npm\
set path=%path%;%cd%\Support\node_modules\npm\bin\

set path=%path%;%cd%\Support\MinGW\bin\
set path=%path%;%cd%\Support\MinGW\lib\
set path=%path%;%cd%\Support\MinGW\include\

set path=%path%;%cd%\Support\Python\

set path=%path%;%cd%\Support\cmder\

cd VS Code
start Code.exe ../Code
exit
```

这样u盘里的文件对于 VS Code 就被加到环境变量里了(仅对于VSCode和从VSCode启动的程序)  
那么,理论上而言,剩下的就和正常的一样了  
<kbd>Ctrl + `</kbd>调用VS Code里的控制台,通过这个控制台来写hexo的那些命令,或者通过这个控制台启动外部的控制台也行  


## 编译  
编译需要安装相应的插件,先在VS Code里下好插件,到`{USER}\.vscode\extensions`里将插件移动到 `\portable\VS Code\resources\app\extensions`即可(插件列表里会消失,不过不影响使用)  

Python的不需要配置  
C/C++需要配置下  

我这里用了两个不同的C/C++编译方式,使用VS Code的Debug和自己写的bat  
在 `tasks.json` 里写了多个不同指令的任务,目测没有bug  
以下给出配置   

```json launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Launch (GDB)",                 // 配置名称，将会在启动配置的下拉菜单中显示
            "type": "cppdbg",                           // 配置类型，这里只能为cppdbg
            "request": "launch",                        // 请求配置类型，可以为launch（启动）或attach（附加）
            "launchOptionType": "Local",                // 调试器启动类型，这里只能为Local
            "targetArchitecture": "x86",                // 生成目标架构，一般为x86或x64，可以为x86, arm, arm64, mips, x64, amd64, x86_64
            "program": "${file}.exe",                   // 将要进行调试的程序的路径
            "miDebuggerPath":"${cwd}\\..\\support\\MinGW\\bin\\gdb.exe", // miDebugger的路径，注意这里要与MinGw的路径对应
            "args": [],                                 // 程序调试时传递给程序的命令行参数，一般设为空即可
            "stopAtEntry": false,                       // 设为true时程序将暂停在程序入口处，一般设置为false
            "cwd": "${workspaceRoot}",                  // 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录
            "externalConsole": true,                    // 调试时是否显示控制台窗口，一般设置为true显示控制台
            "preLaunchTask": "g++"　　                  // 调试会话开始前执行的任务，一般为编译程序，c++为g++, c为gcc
        },
        {
            "name": "Python",
            "type": "python",
            "request": "launch",
            "stopOnEntry": true,
            "program": "${file}",
            "debugOptions": [
                "WaitOnAbnormalExit",
                "WaitOnNormalExit",
                "RedirectOutput"
            ]
        },
        {
            "name": "Python Console App",
            "type": "python",
            "request": "launch",
            "stopOnEntry": true,
            "program": "${file}",
            "externalConsole": true,
            "debugOptions": [
                "WaitOnAbnormalExit",
                "WaitOnNormalExit"
            ]
        },
        {
            "name": "Django",
            "type": "python",
            "request": "launch",
            "stopOnEntry": true,
            "program": "${workspaceRoot}/manage.py",
            "args": [
                "runserver",
                "--noreload"
            ],
            "debugOptions": [
                "WaitOnAbnormalExit",
                "WaitOnNormalExit",
                "RedirectOutput",
                "DjangoDebugging"
            ]
        },
        {
            "name": "Watson",
            "type": "python",
            "request": "launch",
            "stopOnEntry": true,
            "program": "${workspaceRoot}/console.py",
            "args": [
                "dev",
                "runserver",
                "--noreload=True"
            ],
            "debugOptions": [
                "WaitOnAbnormalExit",
                "WaitOnNormalExit",
                "RedirectOutput"
            ]
        }
    ]
}
```

```json tasks.json
{
    "version": "0.1.0",
    "command": " ",//需要多个指令 因此留空 以下面的参数为指令
    "isShellCommand": true,
    "showOutput": "always",
    "echoCommand": false,
    "suppressTaskName": true,
    "tasks": [
        {
            "taskName": "g++",
            //"command": "g++",
            "args": ["g++","-g","${file}","-o","${file}.exe"],    // 编译命令参数
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": ["relative", "${workspaceRoot}"],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
         },
         {
            "taskName": "compile",
            //"command": "compile.bat",
            "args": ["compile.bat","${file}"],    // 编译命令参数
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": ["relative", "${workspaceRoot}"],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        {
            "taskName": "echo",
            "args": ["echo","${workspaceRoot}/.vscode/.clang-format"]    // 编译命令参数
        }
    ]
}
```

下面两个是我自己写的通过bat编译,运行完会自己暂停,并且会自动删除生成的exe  
放在 `code` 文件夹里

```bat compile.bat
@Echo off

echo Begin

set path=%path%;%cd%\..\Support\MinGW\bin\;%cd%\..\Support\MinGW\lib\;%cd%\..\Support\MinGW\include\

if exist %1.exe del %1.exe 

g++ -g -Wall -std=c++11 %1 -o %1.exe 

::if exist %1.exe %1.exe

if exist %1.exe  start run.bat %1 /B /c

echo Finished
```

```bat run.bat
@Echo off
%1.exe
pause
del %1.exe 
exit
```


另外 `.vscode` 里的 `setting.json` 是对该工作区有效的,因此相当于我们直接把配置文件放到了U盘里  
不过键盘映射必须要在 `{USER}\.vscode` 目录   
可以自己写一个bat自动拷贝键盘映射文件  
另外ssh文件也可以这样实现  

放在`portable`文件夹里

如下  
```bat keybindings_copy.bat
copy /D /Y %cd%\Code\.vscode\keybindings.json %USERPROFILE%\AppData\Roaming\Code\User\keybindings.json
exit
```

``` bat keybindings_delete.bat
copy /D /Y %USERPROFILE%\AppData\Roaming\Code\User\keybindings.json %cd%\Code\.vscode\keybindings.json
del %USERPROFILE%\AppData\Roaming\Code\User\keybindings.json
exit
```

```bat ssh_backup.bat
copy /D /Y %USERPROFILE%\.ssh\id_rsa  %USERPROFILE%\.ssh\id_rsa.backup
copy /D /Y %USERPROFILE%\.ssh\id_rsa.pub  %USERPROFILE%\.ssh\id_rsa.pub.backup

copy /D /Y %cd%\ssh\id_rsa %USERPROFILE%\.ssh\id_rsa
copy /D /Y %cd%\ssh\id_rsa.pub %USERPROFILE%\.ssh\id_rsa.pub
```

```bat ssh_del.bat
copy /D /Y %USERPROFILE%\.ssh\id_rsa.backup %USERPROFILE%\.ssh\id_rsa
copy /D /Y %USERPROFILE%\.ssh\id_rsa.pub.backup %USERPROFILE%\.ssh\id_rsa.pub 

del %USERPROFILE%\.ssh\id_rsa.backup
del %USERPROFILE%\.ssh\id_rsa.pub.backup
```

# Git
在有些电脑上,Git可能会由于ssh证书的问题无法连接    

提示 `error setting certificate verify locations` 

可以使用 `git config --system http.sslverify false` 解决  