---
title: jQuery 实现内容折叠功能
date: 2017-04-07 17:33:08
categories: 笔记
tags:
  - Hexo
  - javascript
  - jquery
keywords:
 - iPad jQuery 兼容问题
 - 折叠
---

代码折叠功能如下

> {% fold 点击折叠/展开 %}  
我是内容
{% endfold %}
  

<!--more-->

其使用的是 jQuery 的基础功能 `slideToggle`  

给所有的指定标签都绑定一个时间,点击后会 `slideToggle` 这些标签的父 `div`  

为了保证能够绑定成功,要在页面全部加载后绑定  

代码如下  
```js
$(document).ready(function(){
    $(document).on('click', '.fold_hider', function(){
        $('>.fold', this.parentNode).slideToggle();
        $('>:first', this).toggleClass('open');
    });
    //默认情况下折叠
    $("div.fold").css("display","none");
});
```

当然,该部分要在 **读入 jquery 文件后**  

同时为了让文字更好看,加上一些符号  
另外由于**在 iOS 上,要响应 click ,需要鼠标放上去显示手的符号**  
因此还要改一下 css  

```css
.hider_title{
    font-family: "Microsoft Yahei";
    cursor: pointer;
}
.close:after{
    content: "▼";
}
.open:after{
    content: "▲";
}
```

使用时这样即可
```HTML
<div>
    <div class="fold_hider">
        <div class="close hider_title">' + text + '</div>
    </div>
    <div class="fold">
        ...内容...
    </div>
</div>
```

当然,在 Hexo 里可以使用 **内建标签**  
具体可以参考[官方的文档](https://hexo.io/zh-cn/api/tag.html)  

在博客根目录里的 `scripts` 的文件夹里,新建 `fold.js`  
```js fold.js https://github.com/OhYee/sourcecode.io/blob/master/Blog/scripts/fold.js
/* global hexo */
// Usage: {% fold ???? %} Something {% endfold %}

function fold (args, content) {
    var text = args[0];
    if(!text) text = "点击显/隐";
    return '<div><div class="fold_hider"><div class="close hider_title">' + text + '</div></div><div class="fold">\n' + hexo.render.renderSync({text: content, engine: 'markdown'}) + '\n</div></div>';
}

hexo.extend.tag.register('fold', fold, {ends: true});
```

这样就可以通过以下方式使用  
```ejs
{% note 点击显/隐内容 %}
内容
{% endnote %}
```

如果你想**折叠代码块**,那么需要额外加一个 js 文件,实现对代码块的渲染  
详情参考 [Hexo 自建标签渲染代码段的 Bug 解决方案](/post/Note/hexo_tag.html)   

```js tags.js https://github.com/OhYee/sourcecode.io/blob/master/Blog/scripts/tags.js
/*
  @haohuawu
  修复 Nunjucks 的 tag 里写 ```代码块```，最终都会渲染成 undefined 的问题
  https://github.com/hexojs/hexo/issues/2400
*/

const rEscapeContent = /<escape(?:[^>]*)>([\s\S]*?)<\/escape>/g;
const placeholder = '\uFFFD';
const rPlaceholder = /(?:<|&lt;)\!--\uFFFD(\d+)--(?:>|&gt;)/g;
const cache = [];
function escapeContent(str) {
  return '<!--' + placeholder + (cache.push(str) - 1) + '-->';
}
hexo.extend.filter.register('before_post_render', function(data) {
  data.content = data.content.replace(rEscapeContent, function(match, content) {
    return escapeContent(content);
  });
  return data;
});

hexo.extend.filter.register('after_post_render', function(data) {
  data.content = data.content.replace(rPlaceholder, function() {
    return cache[arguments[1]];
  });
  return data;
});
```