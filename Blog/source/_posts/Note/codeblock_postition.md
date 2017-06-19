---
title: 代码框位置错误
date: 2017-06-17 12:55:14
categories: 笔记
tags:
  - Hexo
  - CSS
  - spfk
---
spfk的代码框在代码长度较长的时候,会发生错位问题  
<!--more-->
![](/post/img/codeblock_position.png)  

看了下实现部分,使用 `::before` 来自动生成上面的title,由于向右滑动时,整个元素会一起右移就导致了错位问题  

而恰好 `position: sticky` 就是用来解决这个问题的, 设置好这个再加上 `left: 0` 就可以保证定位的正确  
不过由于本身代码框是通过 `padding` 导致旁边有一圈虽然有颜色,但是并不算元素内,所以这样做会使左侧有一点小问题  
修改 `margin-left` 和 `margin-right` 保证两边有同样的空隙,然后用`border-radius` 设置下面的两个角为圆角,这样看上去就好看了许多~  

--------
好吧,我直接把上面去掉了,代码框多了上面真难看……