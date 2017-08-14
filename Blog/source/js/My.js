//document.write("<script language=javascript src='http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js'></script>");
document.write("<script language=javascript src='/js/jquery.js'></script>");
document.write("<script language=javascript src='/js/after_jquery.js'></script>");
document.write("<script language=javascript src='/js/spfk.js'></script>");


//网站重定向
host = window.location.host
if(host=="ohyee.coding.me")
    window.location.href = window.location.href.replace(/ohyee.coding.me/,"www.oyohyee.com")

//to https
protocol = window.location.protocol
if(protocol == "http:" && host!="localhost:4000")
  window.location.href = window.location.href.replace("http://","https://")

//百度站长统计
var _hmt = _hmt || [];
(function() {
  var hm = document.createElement("script");
  hm.src = "https://hm.baidu.com/hm.js?c3c4a93be88257973d97af02f735ed4e";
  var s = document.getElementsByTagName("script")[0]; 
  s.parentNode.insertBefore(hm, s);
})();

//alert("加载完成");