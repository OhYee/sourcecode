---
title: 评论
date: 2017-06-24 12:52:55
---
<div id="gitments"></div>
<script src="<%- config.root %>js/gitment.browser.js"></script>
<script>
    var gitment = new Gitment({
      id: "Gitment",//window.location.pathname,
      owner: '<%= owner%>',
      repo: '<%= repo%>',
      oauth: {
        client_id: '<%= client_id%>',
        client_secret: '<%= client_secret%>',
      },
    })
    gitment.render('gitments')
</script>