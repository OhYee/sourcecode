//标签云生成
$(document).ready(function(){
    //手机端按钮隐藏
    $(".slider-trigger").css("display","none");

    var tags = $(".tagcloud a");
        tags.css({"font-size": "12px"});
        for(var i=0,len=tags.length; i<len; i++){
            var num = tags.eq(i).html().length % 5 +1;
            tags[i].className = "";
            tags.eq(i).addClass("color"+num);
    }
});