---
title: Sublime编译c++
date: 2016-06-10 18:41:23
categories: 
 - 笔记
tags:
 - Sublime
 - C++
---
**Sublime Text 2/3** 是一款非常优秀的编辑器(虽然我推VS Code)  

作为一款可以自由搭配的编辑器，我们可以用它一键编译cpp文件  
在网络上，我们可以找到许多的配置项，来帮助我们实现我们的目的。  

针对编译后会生成难看的exe文件(如果目录都是cpp多么美妙)  
我们有一下解决方案：  

根据观察，我们可以看出编译配置文件
<!--more-->
``` json
{
	"encoding": "utf-8",
	"working_dir": "${file_path}",
	"shell_cmd": "g++ -Wall -std=c++0x $file_name -o $file_base_name",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	"selector": "source.c++,source.c",
	"encoding":"cp936",

 
	"variants": 
	[
		{	
		"name": "Run",
        	"shell_cmd": "g++ -Wall -std=c++0x $file -o $file_base_name.exe && start cmd /c \"${file_path}/${file_base_name}.exe & pause\" "
		}
	]
}
```

编译并运行exe使用的是cmd
``` json
"shell_cmd": "g++ -Wall -std=c++0x $file -o $file_base_name.exe && start cmd /c \"${file_path}/${file_base_name}.exe & pause" "
```

根据我们的知识，可以稍加修改，即可达到我们的目的  

仿照前面的`pause` 我们在后面加上`& del /Q ${file_base_name}.exe`  

这样，我们运行后，程序会自己删除掉难看的exe文件

```json 完整的Sublime-build文件
{
	"encoding": "utf-8",
	"working_dir": "${file_path}",
	"shell_cmd": "g++ -Wall -std=c++0x $file_name -o $file_base_name",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	"selector": "source.c++,source.c",
	"encoding":"cp936",

 
	"variants": 
	[
		{	
		"name": "Run",
        	"shell_cmd": "g++ -Wall -std=c++0x $file -o $file_base_name.exe && start cmd /c \"${file_path}/${file_base_name}.exe & pause & del /Q ${file_base_name}.exe\" "
		}
	]
}
```