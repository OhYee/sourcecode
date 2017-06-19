---
title: 给 Hexo 加上 bootstrap 的一些特效 &amp;&amp; jquery 实现隐藏功能
date: 2016-12-09 00:57:29
categories: 笔记
tags: 
  - javascript
  - jquery
  - CSS
  - Hexo
  - bootstrap
---

查东西的时候看到了 [Bootstrap](http://www.bootcss.com/) 的特效,觉得非常好看,就像把里面的一些功能加到 Hexo 的 Next 主题里  
(有别的主题是自带 <span class="label label-sky">Bootstrap</span> 的,不过 Next 已经被修改了好多,不想在折腾了【虽然有折腾了一晚上】)  

加了一些好看的标签,同时修改了 Next 自带的 `code` 标签  

<!--more-->

# 效果展示

效果如下：

- 各种颜色的标签: 
 - <span class="label label-red">red</span>
 - <span class="label label-sky">sky</span>
 - <span class="label label-orange">orange</span>
 - <span class="label label-blue">blue</span>
 - <span class="label label-green">green</span>
- 单行代码框: 
 - <code>int num;</code>
- 按键框
 - <kbd>Ctrl + A</kbd>
- 并且新版的 Next 主题内建标签有了这种 note  
 - {% note defult %}deafult{% endnote %}  
 - {% note primary %}primary{% endnote %}  
 - {% note success %}success{% endnote %}  
 - {% note info %}info{% endnote %}  
 - {% note warning %}warning{% endnote %}  
 - {% note danger %}danger{% endnote %}  

----

然后又顺手重新弄了下 OJ 题目的 CSS (稍微好看了那么一点)  
美化完又增加了按键隐藏功能(毕竟题目和代码真长……)  

效果如下：

<!-- OJ题目 -->
{% raw %}
<div><div class="fold_hider"><div class="close hider_title">点击显/隐</div></div><div class="fold">
<div class="oj">   
    <div class="part" title="Description">
{% endraw %}

There is a kindom of obsession, so people in this kingdom do things very strictly.

They name themselves in integer, and there are n people with their id continuous (s+1,s+2, ,s+n) standing in a line in arbitrary order, be more obsessively, people with id x wants to stand at yth position which satisfy

`x mod y=0`

Is there any way to satisfy everyone’s requirement

{% raw %}
    </div>
    <div class="part" title="Input">
{% endraw %}
First line contains an integer T, which indicates the number of test cases.

Every test case contains one line with two integers n, s.

Limits
1≤T≤100.
1≤n≤109.
0≤s≤109.
{% raw %}
    </div>
    <div class="part" title="Output">
{% endraw %}
For every test case, you should output ‘Case #x: y’, where x indicates the case number and counts from 1 and y is the result string.

If there is any way to satisfy everyone’s requirement, y equals ‘Yes’, otherwise y equals ‘No’.
{% raw %}
    </div>
    <div class="samp">
        <div class="clear"></div>
        <div class="input part" title="Sample Input">
{% endraw %}
2
5 14
4 11
{% raw %}
        </div>
        <div class="output part" title="Sample Output">
{% endraw %}
Case #1: No
Case #2: Yes
{% raw %}
        </div>
        <div class="clear"></div>
    </div>
</div>
</div></div>
{% endraw %}


<!-- OJ题目 -->
{% raw %}
<div><div class="fold_hider"><div class="close hider_title">点击显/隐</div></div><div class="fold">
<div class="oj">   
    <div class="part" title="Description">
{% endraw %}

There is a kindom of obsession, so people in this kingdom do things very strictly.

They name themselves in integer, and there are n people with their id continuous (s+1,s+2, ,s+n) standing in a line in arbitrary order, be more obsessively, people with id x wants to stand at yth position which satisfy

`x mod y=0`

Is there any way to satisfy everyone’s requirement

{% raw %}
    </div>
    <div class="part" title="Input">
{% endraw %}
First line contains an integer T, which indicates the number of test cases.

Every test case contains one line with two integers n, s.

Limits
1≤T≤100.
1≤n≤109.
0≤s≤109.
{% raw %}
    </div>
    <div class="part" title="Output">
{% endraw %}
For every test case, you should output ‘Case #x: y’, where x indicates the case number and counts from 1 and y is the result string.

If there is any way to satisfy everyone’s requirement, y equals ‘Yes’, otherwise y equals ‘No’.
{% raw %}
    </div>
    <div class="samp">
        <div class="clear"></div>
        <div class="input part" title="Sample Input">
{% endraw %}
2
5 14
4 11
{% raw %}
        </div>
        <div class="output part" title="Sample Output">
{% endraw %}
Case #1: No
Case #2: Yes
{% raw %}
        </div>
        <div class="clear"></div>
    </div>
</div>
</div></div>
{% endraw %}

<div><div class="fold_hider"><div class="close hider_title">点击显/隐</div></div><div class="fold">```cpp 123 http://www.baidu.com 123
#include <cstdio>
#include <cstdio>
#include <cstdio>
#include <cstdio>
#include <cstdio>
```
</div></div>

<div><div class="fold_hider"><div class="close hider_title">点击显/隐</div></div><div class="fold">```cpp 123 http://www.baidu.com 123
#include <cstdio>
#include <cstdio>
#include <cstdio>
#include <cstdio>
#include <cstdio>
```
</div></div>

# 思路
CSS 部分就是简单的 CSS 代码  
只不过是想练下 `:after` 和 `:before`  
(觉得每次写浮动,都要蛋疼好久)
隐藏和显示则是使用了<span class="label label-green">jquery</span>的一些功能  
仔细想一下,其实好久之前就写过这些功能,只不过好久没有碰过,忘完了……  

其实就是一个非常简单的选择器的一些操作而已  
不过又踩了关于 `js` 文件加载顺序的坑  
如果写`jquery`函数的话,一定要确保加载完毕(可以在新的文件里写`jquery`部分)  

# 具体代码
具体代码见文件
[`/js/My.js`](/js/My.js)
[`/js/after_jquery.js`](/js/after_jquery.js)
[`/css/My.css`](/css/My.css)

OJ 题目格式使用如下:  
```HTML OJ题目
{% raw %}
<div>
    <div class="oj">   
        <div class="part" title="Description">
{% endraw %}
            <!--题面-->
{% raw %}
        </div>
        <div class="part" title="Input">
{% endraw %}
            <!--输入解释-->
{% raw %}
        </div>
        <div class="part" title="Output">
{% endraw %}
            <!--输出解释-->
{% raw %}
        </div>
        <div class="samp">
            <div class="clear"></div>
            <div class="input part" title="Sample Input">
{% endraw %}
                <!--样例输入部分-->
{% raw %}
            </div>
            <div class="output part" title="Sample Output">
{% endraw %}
                <!--样例输出-->
{% raw %}
            </div>
            <div class="clear"></div>
        </div>
    </div>
</div>
{% endraw %}
```