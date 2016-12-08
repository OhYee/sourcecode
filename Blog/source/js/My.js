//document.write("<script language=javascript src='http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js'></script>");
document.write("<script language=javascript src='/js/jquery.js'></script>");
document.write("<script language=javascript src='/js/after_jquery.js'></script>");



//网站重定向
host = window.location.host
if(host=="ohyee.coding.me")
    window.location.href = window.location.href.replace(/ohyee.coding.me/,"www.oyohyee.com")

//百度推送
var bp = document.createElement('script');
var curProtocol = window.location.protocol.split(':')[0];
if (curProtocol === 'https') {
    bp.src = 'https://zz.bdstatic.com/linksubmit/push.js';        
}
else {
    bp.src = 'http://push.zhanzhang.baidu.com/push.js';
}
var s = document.getElementsByTagName("script")[0];
s.parentNode.insertBefore(bp, s);



//alert("加载完成");