---
title: Photoshop 安装错误解决
date: 2017-03-31 09:43:02
categories: 笔记
tags: 
  - Photoshop
keywords:
  - Photoshop安装错误
  - Camera Profiles Installer 8.0.0.15
  - 34
---
安装 photoshop 时遇到错误  
应该是因为老版本没有卸载干净  

{% note danger %}
Exit Code: 34
Please see specific errors below for troubleshooting. For example,  ERROR: 
\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\- Summary \-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-
 \- 1 fatal error(s), 0 error(s) 

FATAL: Payload 'Camera Profiles Installer 8.0.0.15 {3F023875\-4A52\-4605\-9DB6\-A88D4A813E8D}' information not found in Media_db.
\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-

System Requirements
{% endnote %}
<!--more-->
解决方案: 删掉 `C:\Program Files (x86)\Common Files\Adobe\caps` 目录下的3个 `.db` 文件