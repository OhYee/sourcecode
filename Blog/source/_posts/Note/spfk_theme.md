---
title: Hexo博客主题更换
date: 2017-06-16 21:15:24
categories: 笔记
tags:
 - Hexo
Keywords: 
 - spfk
 - Next
---

spfk是一个在电脑端和移动端都有着不错效果的网站  
由于之前Next已经修改了好多地方,所以迁移还是一个比较大的工程  

修改部分如下：
1. Keywords信息添加
  ```HTML
<!-- Keywords -->
<meta name="keywords" content="{% if page.keywords %}{{ page.keywords }},{% endif %}{% if page.tags and page.tags.length %}{% for tag in page.tags %}{{ tag.name }},{% endfor %}{% endif %}{% if theme.keywords %}{{ theme.keywords }}{% endif %}{% if config.keywords %}{{ config.keywords }}{% endif %}" />
```
2. 代码折叠等功能抑制
3. 增加备案信息
4. 修改了个别页面的显示问题
5. 修改了在手机端标题和日期重叠的问题
6. 将标签页的标签云的形式改成了符合主题风格的形式
7. 删掉了许多不需要的东西
8. 增加了手机端chrome的状态栏颜色