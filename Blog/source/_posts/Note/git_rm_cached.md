---
title: Git取消文件追踪
date: 2017-08-10 16:45:00
categories: 笔记
tags: Git
---
不知道为什么Git同时追踪了 `Blog` 和 `blog`  
虽然没有什么影响,但是看上去很难受  
想要解决也很简单,因为我的文件夹明明为 `Blog`  
因此应该取消对 `blog`  的追踪
```
git rm --cached blog
```