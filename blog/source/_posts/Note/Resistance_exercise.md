---
title: 电阻色环练习工具
date: 2016-06-27 19:45:09
categories: 笔记
tags: 
 - javascript
---

突发奇想就像做一个电阻色环练习工具(不务正业系列)  

使用HTML(Div+Css)+Javascript实现  

采用**Jquery**的功能实现修改颜色的部分  

没脸传Github ╮(╯-╰)╭  

遵守[GPL协议](http://baike.baidu.com/view/130692.htm)  

<!--more-->
[**>Demo<**](/post/Note/El.html#色环练习)

使用到的功能如下：

取0~1的随机数
```javascript
Math.random()
```

转换到整数
```javascript
parseInt()
```

检测点击事件
```javascript
$(document).ready(function(){
    $("#").click(function (){

    });
};
```

修改控件内容
```javascript
    $("#").text();
```

修改控件属性
```javascript
    $("#").attr();
```

**完整代码**

HTML部分
```html
<div style="background:#66ccff; width:100px; text-align:center;font-weight:bold"><font id="a1" size=5px color="BLACK">|</font> <font id="a2" size=5px color="BLACK">|</font> <font id="a3" size=5px color="BLACK">|</font> <font id="a4" size=5px color="BLACK">|</font> <font id="a5" size=5px color="BLACK">|</font></div>
<p id="answer"></p>
<button id="do">新数据</button> <button id="do2">显示答案</button>
```

Javascript部分
```javascript
<script src="https://code.jquery.com/jquery-3.0.0.min.js"></script>
<script language="javascript">
var sum = 0;
var bit = 0;
var delta = 0;
var ColorIndex = new Array("BLACK","BROWN","RED","ORANGE","YELLOW","GREEN","BLUE","PURPLE","GREY","WHITE");
var OIndex = new Array(0,1,2,3,4,5,6,7,8,9);
var DeltaColorIndex = new Array("BROWN","RED","GREEN","BLUE","PURPLE","GREY","GOLD","SILVER","66CCFF");
var DeltaOIndex = new Array(1,2,0.5,0.25,0.1,0.05,5,10,20);

Do();

function rand(n){
    return parseInt(Math.random()*1000000)%(n+1);
}
$(document).ready(function(){
    $("#do").click(Do);
    $("#do2").click(function(){
        $("#answer").text(sum+" × 10^"+bit+" Ω ± "+delta+"%");
    });
});

function Do(){
    sum=0;
    bit=0;

    for(var i=0;i<4;i++){
        index = rand(ColorIndex.length-1);
        var color = ColorIndex[index];
        $("#a"+(i+1)).attr("color",color);

        if(i==0)
            sum+=OIndex[index]*100;
        if(i==1)
            sum+=OIndex[index]*10;
        if(i==2)
            sum+=OIndex[index];
        if(i==3)
            bit=OIndex[index];
    }

    index = rand(DeltaColorIndex.length-1);
    var color = DeltaColorIndex[index];
    $("#a5").attr("color",color);
    delta = DeltaOIndex[index];

    $("#answer").text("刮开查看答案");
}
</script>
```