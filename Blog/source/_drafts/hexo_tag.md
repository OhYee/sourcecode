---
title: Hexo 自建标签渲染代码段的 Bug 解决方案
date: 2017-03-24 23:56:07
categories: 笔记
tags:
 - Hexo
---
Hexo 有一个非常方便的功能 - 自建标签  

其使用如下   
`{% raw %}{% raw %} 123 {% endraw %}{% endraw %}`  
这样 `123` 会以 HTML 的形式插入到网页里,而非 Markdown  

许多主题也都加入了许多有用的 tag   
比如 `{% raw %}{% cq %} blah blah blah {% endcq %}{% endraw %}`  

{% cq %} blah blah blah {% endcq %}  

而这个功能存在一个问题,由于渲染顺序的问题,导致如果你在自建的标签里使用

`{% raw %}``` ```{% endraw %}` 的代码段,就会发现代码段部分被渲染成了 `undefined`  

提了 Issue 后,有了如下解决方案  
[{% raw %}{% raw %}{% endraw %} 无法渲染 ``` 代码段 #2400](https://github.com/hexojs/hexo/issues/2400)


也即只需在 `scripts` 目录里新建一个 js 文件,贴入以下内容即可  

