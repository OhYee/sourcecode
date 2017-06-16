---
title: 搜索
date: 2016-06-28 16:03:51
comments: false
---
{% raw %}
<!--搜索结果-->
<style>
.main-inner {
    margin-top: 0px;
}
.footer{
    margin-top: 0px;
}
</style>
<script src="/js/jquery.js"></script>
<script type="text/javascript">
    var ua = navigator.userAgent;
    var ipad = ua.match(/(iPad).*OS\s([\d_]+)/),
    isIphone = !ipad && ua.match(/(iPhone\sOS)\s([\d_]+)/),
    isAndroid = ua.match(/(Android)\s+([\d.]+)/),
    isMobile = isIphone || isAndroid;
    if(isMobile) {
        //Mobile
        document.write("检测到您正在使用手机访问该页面，为了更好的体验，建议跳转到<strong><a href=\"http://zhannei.baidu.com/cse/search?s=14190290798740403696\">外部页面<\/a><\/strong>进行搜索功能")
        document.write("<iframe id='MobileSearch' frameBorder=0  width='100%' height='500px' src=\"http://zhannei.baidu.com/cse/search?s=14190290798740403696\"><\/iframe>");
        //$("#MobileSearch").attr("height",parseInt($(window).height())-270 +"px");
    }else{
        //PC
        document.write("<div id='bdcs-frame-box' style='align:center;'><\/div>");
        var bdcsFrameSid="14190290798740403696";
        var bdcsFrameWidth = 1500;
        var bdcsFrameWt = 1;
        var bdcsFrameHt = 2;
        var bdcsFrameResultNum = 10;
        var bdcsFrameBgColor = "#3F3F3F";
        document.write("<script type='text/javascript' src='http://zhannei.baidu.com/static/js/iframe.js'><\/script>");
        $(document).ready(function(){
            $('#bdcs-frame-box').css({"width":"100%"});
        });
    }


</script>
{% endraw %}
