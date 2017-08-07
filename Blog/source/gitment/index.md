---
title: 评论
date: 2017-06-24 12:52:55
---
@card{

评论需要Chrome浏览器支持
其他浏览器请通过该[issue](https://github.com/OhYee/OhYee.github.io/issues/5)提交评论内容

}

@card{

<div id="gitments"></div>

<link rel="stylesheet" href="/css/gitment.css">
<script src="/js/gitment.js"></script>
<script>
    var gitment = new Gitment({
      id: "Gitment",//window.location.pathname,
      owner: 'OhYee',
      repo: 'OhYee.github.io',
      oauth: {
        client_id: '300bdf519730fd67e69c',
        client_secret: '9a496df1c4da10cec1ec233379b9b3ef6a448c2e',
      },
    })
    gitment.render('gitments')
</script>

}