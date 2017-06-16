//document.write("<script language=javascript src='http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js'></script>");
document.write("<script language=javascript src='/js/jquery.js'></script>");
document.write("<script language=javascript src='/js/after_jquery.js'></script>");
document.write("<script language=javascript src='/js/spfk.js'></script>");


//网站重定向
host = window.location.host
if(host=="ohyee.coding.me")
    window.location.href = window.location.href.replace(/ohyee.coding.me/,"www.oyohyee.com")


//alert("加载完成");