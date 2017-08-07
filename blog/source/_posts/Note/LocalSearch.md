---
title: Hexo本地搜索及部分SEO优化
date: 2017-02-08 21:01:42
categories: 笔记
tags:
  - Hexo
  - SEO
keywords:
  - 本地搜索
  - SEO优化
---
解决本地搜索问题,并且修改了 Next 主题的部分SEO内容,写了一个小插件用于生成 `urls.txt` 用来给百度主动推送
<!--more-->

百度的站内搜索好久没有收录新的页面,站内搜索这个功能还是掌控在自己手里好一点  
Next主题本身自带的有 Local Search 功能  
当安装 `search.xml` 生成插件后,可以自动开启搜索功能  

试了下发现点搜索后没有用,找了以下发现生成的xml有错误,有的页面内存在 `&` 等字符,导致 xml 无法正常解析  
想了下还是自己修改下吧  
有 `hexo-generator-searchdb` 是一个比较完善的插件  
可以做到提取摘要部分  
不过我还想把 tags 部分和 keywords 部分也提取出来用来增强搜索功能  

同时这个插件生成的链接存在一些小bug,不知道是不是我哪里设置有问题  

自己修改了下  
```js search.ejs
<?xml version="1.0" encoding="utf-8"?>
<search>
  <% if(posts){ %>
    <% posts.slice(0,limit).each(function(post){ %>
    <entry>
      <%
            var dd = "";
            if(post.keywords){
                post.keywords.forEach(function(keyword){
                    dd +=  keyword.name + '|';
                });
            }
            if(post.categories){
                post.categories.forEach(function(category){
                    dd +=  category.name + '|';
                });
            }
            if(post.tags){
                post.tags.forEach(function(tag){
                    dd +=  tag.name + '|';
                });
            }
      %>
      <title><%-: post.title | cdata %></title>
      <url><%- encodeURIComponent(post.path) %></url>
      <content type="text"><%-: dd + (raw ? post[raw] : post.content) | cdata %></content>
    </entry>

    <% }) %>
  <% } %>
  <% if(pages){ %>
    <% pages.each(function(page){ %>
    <entry>
      <title><%-: page.title | cdata %></title>
      <url><%- encodeURIComponent(post.path) %></url>
      <content type="text"><%-: raw ? page[raw] : page.content | cdata %></content>
    </entry>
    <% }) %>
  <% } %>
</search>
```


本地优化主要在于 `<title></title>` 和 `<meta name="keywords" />`

```html _layout.swig
<title>{% block title %}{% endblock %} - {{ config.description }} |{% if page.keywords %}{% for keyword in page.keywords %}{{ keyword }}|{% endfor %}{% endif %}{% if page.tags and page.tags.length %}{% for tag in page.tags %}{{ tag.name }}|{% endfor %}{% endif %}</title>
```

```html head.swig
<meta name="keywords" content="{% if page.keywords %}{{ page.keywords }},{% endif %}{% if page.tags and page.tags.length %}{% for tag in page.tags %}{{ tag.name }},{% endfor %}{% endif %}{% if theme.keywords %}{{ theme.keywords }}{% endif %}{% if config.keywords %}{{ config.keywords }}{% endif %}" />
```
