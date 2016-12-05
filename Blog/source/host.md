# 根据github对vendor的屏蔽实现判断访问的站点
> 
{% raw %}
<script type="text/javascript">
    coding=false;
    function Coding(){}
</script>

<script src="./vendors/host.js"></script>

<script type="text/javascript">
Coding();
if (coding === true)
    document.write("Coding.net");
else
    document.write("Github.com");
</script>
{% endraw %}
