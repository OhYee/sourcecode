---
title: 自定义 li 前面的图标
date: 2017-06-18 16:17:22
categories: 笔记
tags: 
  - CSS
  - spfk
---
新主题的 `li` 前的图标挺好看的,但是存在缩进错误的小问题
采用 `::before` 的方式增加前面的图标,同时注意到了多行时缩进的问题(使用首行负值缩进整体缩进的方法)
<!--more-->
```css
ul{
    list-style: none
}
ul li{
    margin-left: 40px;
    text-indent: -20px;
}
ul li::before{
    content: "\f05d";
    font: normal normal normal 14px/1 FontAwesome;
    display: inline-block;
    margin: 0 10px;
    line-height: 28px;
}
```