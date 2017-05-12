---
title: Hexo的原理是什么？
date: 2017-05-12 23:20:42
categories: 知乎
tags:
- Hexo
---
[https://www.zhihu.com/question/51588481/answer/126547622](https://www.zhihu.com/question/51588481/answer/126547622)
<!--more-->

---------------

{% note %}
**Hexo的原理是什么？**
Hexo的原理是什么？为啥就能通过GitHub Pages弄一个博客了？
{% endnote %}

---------------

github pages支持静态页面的解析
完全可以自己写 html push 到 gitpages 

简单来说就是不支持动态页面，没办法就在本地写好网站，然后用程序生成静态页面

可以改名叫 **markdown - 博客 一键转换器**

---------------

下面是大概原理
（不会 node.js ，主攻方向不是网络，非计算机专业的学生表示根据已有信息认为是以下解释，欢迎大神指正问题。不保证严谨，但是理解应该没问题）
（其实自己实验下就能理解吧(ง •̀_•́)ง）

---------------

如果要做博客 wordpress 的思路是 php + MySql 而 gitpages 不支持动态语言，因此只能使用 html 拼合成博客

首先自己本地文件夹的 source 就是数据库，以 .md(markdown) 格式存储文章，
theme 文件夹是主题文件，以 .yml 等类型，决定了页面如何“组装”

每次运行 hexo g 命令，hexo(node.js程序)会遍历你的 source 目录，建立索引，根据你 theme 文件夹的主题生成页面到 public 文件夹。这时 public 文件夹就是一个纯由 html javascript css 等内容制作的博客，而这些恰好能在 git pages 识别

最后 hexo d 将 public 文件夹的内容复制到临时目录，以 git 方式 push 到 github 的指定项目的指定分支，由 github 进行显示
