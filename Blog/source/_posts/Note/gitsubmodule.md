---
title: git submodule导致git无法追踪文件
date: 2017-06-18 00:50:56
categories: 笔记
tags:
  - Git
keyword:
  - git无法追踪特定文件
---

Hexo里clone了别人的主题发现在博客的源码备份git里无法记录主题文件夹
<!--more-->

查了下发现是子模块的问题

```
fatal: no submodule mapping found in .gitmodules for path 'Blog/themes/spfk'
```

采用下面的代码删除子模块记录

```
git ls-files --stage | grep 160000
git rm --cached Blog/themes/spfk
```