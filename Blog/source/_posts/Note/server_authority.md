---
title: 服务器权限设置出错及维护
date: 2017-03-28 23:46:53
categories: 笔记
tags: 
 - 服务器
keywords:
 - 服务器权限
 - 服务器维护
---
服务器上的网站除了首页，其他所有页面都打不开  
看了下数据库没问题，网站的 aspx 文件也没问题  
估计是权限的问题  

<!--more-->

看了下报错的信息  
<!-- Web.Config Configuration File -->
<configuration>
    <system.web>
        <customErrors mode="Off"/>
    </system.web>
</configuration>

网站关了提示报错  
先去根目录的 `web.config` 修改下配置，打开报错  
改成 `Off` 后就可以看到报错信息了（注意大小写）


然后再看网页  
`BC30138: 无法在路径“C:\WINDOWS\TEMP\”中创建临时文件: 拒绝访问。`

问题定位完毕 `temp` 目录权限问题  
进到 windosws 目录右键把 `network service` 的写入权限打开  
解决~