---
title: 域名跳转
date: 2016-06-26 18:25:17
categories: 笔记
tags: 
 - javascript
---

博客是搭建在[Github](https://github.com/ohyee)和[Coding](https://coding.net/u/OhYee)上的  
Github的默认域名是`ohyee.github.io`,CNAME后会将强制跳转到绑定的域名上  
而Coding的默认域名是`ohyee.coding.me`,这个域名和绑定的域名都可以独立访问  

也即：网站有两套独立的域名  
显然,这样会很“别扭”,搜索引擎会对两个域名分别收录一遍网站  
因此萌生了将`ohyee.coding.me`强制跳转到`www.oyohyee.com`的想法  

由于在Git Pages和Coding Pages不能设置301重定向,因此使用**javascript**来实现跳转  

<!--more-->

首先是获取当前域名
```javascript
host = window.location.host;
host2 = document.domain;
url = window.location.href;
```
前两种方法获取根域名,帮助我们判断现在访问的是哪个域名  
最后一个是获取完整域名,用于接下来的跳转  

在这里分别输出下三种方法调用出来的结果   

> <script language="javascript">
> host = window.location.host;
> host2 = document.domain; 
> url = window.location.href;
> 
> document.write("host="+host+"<br>")
> document.write("host2="+host2+"<br>")
> document.write("url="+url+"<br>")
> </script>

<br>

前两种方法在使用时是一样的,不过第一种在本地调试(localhost:4000)会返回`localhost:4000`,而第二种是`localhost`   

如果获取到的host为`ohyee.coding.me`,则替换根域名部分
```javascript
window.location.href= url.replace(/ohyee.coding.me/,"www.oyohyee.com")
```

完整的代码
```javascript 域名跳转
<script language="javascript">
    host = window.location.host
    if(host == "ohyee.coding.me")
        window.location.href = window.location.href.replace(/ohyee.coding.me/,"www.oyohyee.com")
</script>
```

效果展示[>**http://ohyee.coding.me/**<](http://ohyee.coding.me/)