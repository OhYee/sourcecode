---
title: 把svg图片转换为图标
date: 2017-09-03 13:58:23
categories: 笔记
tags:
 - Hexo
 - CSS
---

图标可以用于页面的很多地方,通常来说,我们使用的是通过字体来实现小图标  
但是当我们需要使用自己的图片时,也可以将svg图片转换为字体,实现图标   
<!--more-->

在[icoMoon](https://icomoon.io/app/)网站,可以将svg转换为字体  
(这里需要注意**不要给svg填充颜色**,不然会按照颜色分成多块)  

然后我们可以在css里写入  
```css
@font-face {
    font-family: 'icon-OhYee';
    src:  url('/fonts/icon-OhYee.eot?nz90s1');
    src:  url('/fonts/icon-OhYee.eot?nz90s1#iefix') format('embedded-opentype'),
      url('/fonts/icon-OhYee.ttf?nz90s1') format('truetype'),
      url('/fonts/icon-OhYee.woff?nz90s1') format('woff'),
      url('/fonts/icon-OhYee.svg?nz90s1#icon-OhYee') format('svg');
    font-weight: normal;
    font-style: normal;
}
  
.icon-OhYee {
    /* use !important to prevent issues with browser extensions that change fonts */
    font-family: 'icon-OhYee' !important;
    speak: none;
    font-style: normal;
    font-weight: normal;
    font-variant: normal;
    text-transform: none;
    line-height: 1;

    /* Better Font Rendering =========== */
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
}

/* 这里按照具体生成的字符编码写 */
.icon-OhYee::before{
    content: "\e904";
}
```

在使用时可以按照通常的字符图标一样使用,只需要把图标名改为OhYee就会显示我们自己的图标  

|效果|描述|源码|
|:---|:---:|:---|
|<i class="icon-OhYee"></i>|单独使用|`<i class="icon-OhYee"></i>`|
|<span style="color:pink"><i class="icon-OhYee"></i></span>|加上颜色|`<span style="color:pink"><i class="icon-OhYee"></i></span>`|
|<i class="icon icon-OhYee"></i>|按照正常的font icon格式使用|`<i class="icon icon-OhYee"></i>`|
|<i class="icon icon-OhYee icon-lg"></i>|indigo主题的1.5倍大小|`<i class="icon icon-OhYee icon-lg"></i>`|
|<i class="icon icon-OhYee icon-2x"></i>|indigo主题的2倍大小|`<i class="icon icon-OhYee icon-2x"></i>`|
|<i class="icon icon-OhYee icon-3x"></i>|indigo主题的3倍大小|`<i class="icon icon-OhYee icon-3x"></i>`|
|<i class="icon icon-OhYee icon-4x"></i>|indigo主题的4倍大小|`<i class="icon icon-OhYee icon-4x"></i>`|
|<i class="icon icon-OhYee icon-5x"></i>|indigo主题的5倍大小|`<i class="icon icon-OhYee icon-5x"></i>`|
|<i class="icon icon-OhYee icon-pr"></i>|indigo主题的5px右边距|`<i class="icon icon-OhYee icon-pr"></i>`|
|<i class="icon icon-OhYee icon-pl"></i>|indigo主题的5px左边距|`<i class="icon icon-OhYee icon-pl"></i>`|