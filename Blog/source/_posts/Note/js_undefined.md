---
title: 主题bug修复及Javascript中判定undefined
date: 2017-06-17 01:32:34
categories: 笔记
tags: 
  - javascript
  - spfk
---
在新换的 spfk 主题里的 main.js 中有这样一段代码  
{% fold 点击显/隐代码%}```javascript main.js
//是否使用fancybox
if(yiliaConfig.fancybox === true){
    require([yiliaConfig.rootUrl + 'fancybox/jquery.fancybox.js'], function(pc){
        var isFancy = $(".isFancy");
        if(isFancy.length != 0){
            var imgArr = $(".article-inner img");
            for(var i=0,len=imgArr.length;i<len;i++){
                var src = imgArr.eq(i).attr("src");
                var title = imgArr.eq(i).attr("alt");
                imgArr.eq(i).replaceWith("<a href='"+src+"' title='"+title+"' rel='fancy-group' class='fancy-ctn fancybox'><img src='"+src+"' title='"+title+"'></a>");
            }
            $(".article-inner .fancy-ctn").fancybox();
        }
    });
}
```
{% endfold %}

很容易明白,这是处理fancybox中,点击放大图片功能的代码  
检测到图片后会自动修改 `img` 为 `<a ...><img ...></a>`  
<!--more-->

而 spfk 对 a 有单独的 css 样式  
因此当插入图片时,就会套用 a 的样式（有背景色）  

显然,只需要将fancybox对应的a元素修改回默认值即可  
{% fold 点击显/隐代码%}```css
a.fancy-ctn.fancybox {
    background-color: transparent ;
    border: 0;
}
```
{% endfold %}

然后,对于上面转换的js,可以发现有比较大的bug  
假如我给img指定了`width`和`height`  
那么,这个转换程序并不会自动转换  

因此需要增加对 `id` `class` `width` `height` 的识别  
而假如img不存在某个元素,相应的变量为 `undefined`  
可以使用下面的方法判断一个变量是否为 `undefined`  
`typeof(a)=="unfined"`

修改后代码如下  
{% fold 点击显/隐代码%}```javascript
//是否使用fancybox
if(yiliaConfig.fancybox === true){
    require([yiliaConfig.rootUrl + 'fancybox/jquery.fancybox.js'], function(pc){
        var isFancy = $(".isFancy");
        if(isFancy.length != 0){
            var imgArr = $(".article-inner img");
            for(var i=0,len=imgArr.length;i<len;i++){
                var flag = imgArr.eq(i).attr("no-fancybox");
                if(flag=="true")
                    continue;
                
                var src = imgArr.eq(i).attr("src");
                var title = imgArr.eq(i).attr("alt");
                var width = imgArr.eq(i).attr("width");
                var height = imgArr.eq(i).attr("height");
                var id = imgArr.eq(i).attr("id");
                var clas = imgArr.eq(i).attr("class");

                var temp = "<a";
                if(typeof(src)!="undefined")
                    temp+=" href='"+src+"'";
                if(typeof(title)!="undefined")
                    temp+=" title='"+title+"'";
                temp+=" rel='fancy-group' class='fancy-ctn fancybox'><img"
                if(typeof(id)!="undefined")
                    temp+=" id='"+id+"'";
                if(typeof(clas)!="undefined")
                    temp+=" class='"+clas+"'";
                if(typeof(src)!="undefined")
                    temp+=" src='"+src+"'";
                if(typeof(alt)!="undefined")
                    temp+=" alt='"+title+"' title='"+title+"'";
                if(typeof(width)!="undefined")
                    temp+=" width='"+width+"'";
                if(typeof(height)!="undefined")
                    temp+=" height='"+height+"'";
                temp+=" /></a>"

                imgArr.eq(i).replaceWith(temp);
                
            }
            $(".article-inner .fancy-ctn").fancybox();
        }
    });
}
```
{% endfold %}