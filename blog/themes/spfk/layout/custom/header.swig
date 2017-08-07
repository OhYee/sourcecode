<!-- Keywords -->
<meta name="keywords" content="{% if page.keywords %}{{ page.keywords }},{% endif %}{% if page.tags and page.tags.length %}{% for tag in page.tags %}{{ tag.name }},{% endfor %}{% endif %}{% if theme.keywords %}{{ theme.keywords }}{% endif %}{% if config.keywords %}{{ config.keywords }}{% endif %}" />


<!--状态栏颜色-->
<meta name="theme-color" content="#3F3F3F">


<link href="/css/My.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="/js/My.js"></script>