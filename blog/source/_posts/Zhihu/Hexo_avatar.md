---
title: hexo next主题如何更改css使头像在手机端显示？
date: 2017-04-01 23:19:41
categories: 知乎
tags: 
 - Hexo
---
https://www.zhihu.com/question/57821305/answer/154688341
<!--more-->
这要看你想加到哪，想怎么加了(知乎不支持markdown真恶心,排版好难受)


以 NexT 主题为例(毕竟我也不知道你用的什么主题,就选用的人最多的吧)

官方文档如下
{% note %}
**如何更改内容区域的宽度？**

NexT 对于内容的宽度的设定如下：

- 700px，当屏幕宽度 < 1600px
- 900px，当屏幕宽度 >= 1600px
- 移动设备下，宽度自适应  

如果你需要修改内容的宽度，同样需要编辑样式文件。 编辑主题的 `source/css/_variables/custom.styl` 文件，新增变量：
```css
// 修改成你期望的宽度
$content-desktop = 700px

// 当视窗超过 1600px 后的宽度
$content-desktop-large = 900px
```
{% note warning%}
此方法不适用于 Pisces Scheme，关于如何修改 Pisces Scheme 的宽度请参看 这个 [Issue](https://github.com/iissnan/hexo-theme-next/issues/759#issuecomment-202242848)  

{% endnote %}

{% endnote %}

也即,如果你想让手机端和电脑端一样也显示边栏就修改这个值(很显然会很难看)


如果想在手机端比较好看地显示头像,显然不能指望 sidebar 了  

那么就自己把头像加进去就行

`<img src="XXX"  class = "touxiang">`

然后把 `touxiang` 的 css 设置一下放到你想放的位置

(比如标题栏下面放个比较小的头像应该是相对较美观的)

(再或者放到标题前面或者后面也行)


**关于如何加 html**  

到你相应的主题文件夹的 `layout` 目录,找到对应的部分的文件修改即可


在评论回下主题什么什么的如果有空可以给你写一下(可能要很久,拖延症晚期)