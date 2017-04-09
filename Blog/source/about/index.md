---
title: about
date: 2016-06-07 01:14:40
comments: false
---
{% cq %}
<p style="font-size:30px">欢迎来到OhYee的博客</p>
{% endcq %}

{% raw %}
<style>
    .about_left{ 
        float:left;
        width:45%;
        height:100%;
    }
    .about_right{
        float:right;
        width:45%;
        height:100%;
    }
    .clear {
        clear: both;
    }
    .about_block{
        width:24%;
        height: 100%;
        float: left;
        font-size: 10px;
    }
    .about_block ul{
        margin-left: 0 px;
    }
    .about_block li{
        margin-left: -20px;
    }
    
</style>
<script src="/js/jquery.js"></script>
<div class="about">
    <div class="clear">
    </div>
    <div class="about_left">
        <h1 id="About-me">
            <a href="#About-me" class="headerlink" title="About me"></a>
            About me
        </h1>
        <p>
            <em>
                一个想要进ACM World Final的渣渣
            </em>
        </p>
        <p>
            Contact me
            <ul>
                <li>
                    Mail：<a href="mailto:oyohyee@oyohyee.com" target="_blank" rel="external">oyohyee@oyohyee.com</a>
                </li>
                <li>
                    QQ: 896817156
                </li>
                <li>
                    twitter: <a href="https://twitter.com/OYOhYee" target="_blank" rel="external">@oyohyee</a>
                </li>
                <li>
                    知乎账号: <a href="https://www.zhihu.com/people/kong-chen-hao" target="_blank" rel="external">孔晨皓</a>
                </li>
                <li>
                    Page: <a href="http://www.oyohyee.com">www.oyohyee.com</a>
                </li>
            </ul>
        </p>
    </div>
    <div class="about_right">
        <h1 id="About-the-blog">
            <a href="#About-the-blog" class="headerlink" title="About the blog"></a>
            About the blog
        </h1>
        <p>
            这是OhYee记录自己学习与生活的地方。
            <br>
            善用<strong>搜索</strong>和<strong>标签</strong>找到你想要的东西
            <br>
            你在这里或许能收获：
            <ul>
                <li>
                    基础的<strong><a href="../categories/Algorithm/">算法</a></strong>知识
                </li>
                <li>
                    一些题目的<strong><a href="../categories/Answer/">题解</a></strong>及<strong><a href="https://github.com/OhYee/ACM.github.io" target="_blank" rel="external">OhYee的代码备份</a></strong>
                </li>
                <li>
                    <strong><a href="/templates.html" target="_blank" rel="external">常见模板</a></strong>
                </li>
            </ul>
        </p>
        <p>
            当然，如果你不知道自己为什么会来到这里，也可以参照<strong><a href="/404.html">404页面</a></strong>的问题，来找到自己需要的东西哦！
            <br>
        </p>
    </div>
    <div class="clear">
    </div>
    <div class="about_bottom">
        <div class="about_block">
            <ul>
                <li>
                    我做过什么
                    <ul>
                        <li>
                            <a href="http://www.oyohyee.com/">这个博客</a>
                        </li>
                        <li>
                            <a href="/categories/Answer/">ACM题解</a>
                        </li>
                        <li>
                            <a href="https://github.com/OhYee/ACM.github.io" target="_blank" rel="external">写过的大部分C/C++</a>
                        </li>
                        <li>
                            娱乐性大于实用性的项目
                            <ul>
                                <li>
                                    <a href="https://github.com/ohyee" target="_blank" rel="external">Github</a>
                                </li>
                                <li>
                                    <a href="https://coding.net/u/OhYee" target="_blank" rel="external">Coding</a>
                                </li>
                            </ul>
                        </li>
                    </ul>
                </li>
            </ul>
        </div>
        <div class="about_block">
            <ul>
                <li>
                    我曾经得到过
                    <ul>
                        <li>
                            NOIP复赛二等奖
                        </li>
                    </ul>
                </li>
            </ul>
        </div>
        <div class="about_block">
            <ul>
                <li>
                    我正在学
                    <ul>
                        <li>
                            C++
                        </li>
                        <li>
                            HTML(Div+Css)
                        </li>
                        <li>
                            Javascript
                        </li>
                        <li>
                            Java
                        </li>
                        <li>
                            PHP+Mysql
                        </li>
                    </ul>
                </li>
                <li>
                    我准备学
                    <ul>
                        <li>
                            汇编
                        </li>
                        <li>
                            Python
                        </li>
                    </ul>
                </li>
            </ul>
        </div>
        <div class="about_block">
            <ul>
                <li>
                    My tag
                    <ul>
                        <li>
                            LOVELIVE!
                        </li>
                        <li>
                            C++
                        </li>
                        <li>
                            安徽大学
                        </li>
                        <li>
                            宅
                        </li>
                        <li>
                            ACM
                        </li>
                    </ul>
                </li>
            </ul>
        </div>
        <div class="clear">
        </div>
    </div>
    <div class="clear">
    </div>
    <script>
    $(document).ready(function(){
        $(".friends2").html($(".friends").html());
    });
    </script>
    <h3 id="friends">
            <a href="#friends" class="headerlink" title="friends"></a>
            # 友情链接
    </h3>
    <div class="friends2">
    </div>
</div>
{% endraw %}