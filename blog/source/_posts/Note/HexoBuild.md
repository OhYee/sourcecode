---
title: Hexo博客搭建及迁移完成
date: 2016-06-07 00:39:53
categories: 笔记
tags:
 - Hexo
---
从0开始安装Hexo用了两天，迁移博客用了三天。  
纪念一下。

# 迁移至Hexo的原因  
之前使用的是[博客园](http://www.cnblogs.com/ohyee)的博客。  
作为国内两大IT技术博客(另一个是CSDN，之前也用过，不过审核实在太烦人)的集中地，不得不说博客园有很多不错的地方。  
不过，与几乎所有博客一样，过多的限制了用户的自由。
许多本来可以轻易更改的东西需要费很大功夫才能达到自己的目的。  
(真的觉得博客园的代码高亮真难看╮(╯-╰)╭)  
一直都挺向往GitHub的GitHub Pages搭建的博客的，于是终于下决心搞了下。  

# 搭建GitHub Pages
由于GitHub使用了挺长一段时间了，因此，注册什么的就不详细说了。
## 安装环境  
Hexo的安装需要Git和Node.js支持  
这些都可以在他们的官网上获取最新的安装包。  
链接：[Git](https://git-scm.com/)、[Node.js](https://nodejs.org/en/)  
下载并安装好后，可以尝试在控制台运行
```bash
node -v
npm -v
```
指令来检查node.js和npm是否安装成功  

## 安装Hexo
安装完成后，就可以运行下面的命令开始安装Hexo了。
```bash
npm install hexo -g
```
其中，`-g`指全局安装  
根据网速可能需要等待不同的时间  
安装完成后，进入我们要搭建博客的目录
```bash
npm install hexo --save
```
将Hexo安装到目录中。  
而后运行
```basg
npm install
```
安装可能需要的插件  

安装完毕后，我们就搭建好了Hexo  
可以使用
```bash
hexo s
```
而后访问[localhost:4000](localhost:4000)测试  
如果能够看到页面，就证明安装完成  

## 配置和上传
Hexo有以下目录与文件
* node_modules (Hexo的程序，用于生成页面)
* public (生成的页面文件，上传到git的就是这个文件夹内的内容)
* scaffolds (模板文件，使用`hexo new`命令时，会按照这个模板生成文件)
* source (资源文件，里面的_post存放文章，其他东西生成时会照搬到public)
* theme (主题文件，里面每一个文件夹都是一个主题。定义页面生成的样式)
* _config.yml (Hexo配置文件，我们主要操作的文件，里面定义各种变量，在生成页面会程序会根据不同变量生成不同形式的页面)
* db.json (数据库文件)
* package.json (插件数据库，只要有这个文件，运行`npm install`就会按照里面的内容安装插件)

Hexo常用的命令如下
* hexo clean 清楚public文件夹
* hexo g 生成文件
* hexo d 上传网站到git
* hexo s 运行本地服务器测试网站
* hexo new 建立一个md文件(页面)

其中，可以`hexo d -g`在生成后发布  

## 使用GitCafe(Coding)搭建双博客系统
由于GitHub屏蔽了百度爬虫，同时访问速度稍微有点慢，我们可以搭建双系统来实现我们心目中的完美网站。  
按照正常的方式申请项目  
在`_config.yml`的`deploy`中，同时写入GitHub和GitCafe即可  
这样每次`hexo d`会同时上传到两边  
在域名dns解析里，再根据线路进行解析即可。  


