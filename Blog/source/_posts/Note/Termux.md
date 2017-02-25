---
title: 使用 Termux 在手机上运行 linux 黑科技
date: 2017-02-09 16:42:58
categories: 笔记
tags: 
  - Termux
Keywords:
  - 手机运行Linux
  - nodejs
  - python
  - hexo
  - git
  - 手机运行hexo
---
非常棒的神器  
不同于其他终端,这个终端是一个寄居在安卓系统中的阉割版 <span class="label label-orange">Linux</span>  
手机里的 `/data/data/com.termux/files/` 目录对应的就是 <span class="label label-orange">Linux</span>   的根目录 `/`  

在自己的这一块地方里, <span class="label label-sky">Termux</span> 拥有绝对权限,但是出去后需要 root 权限才能进行操作  

这篇博客介绍<span class="label label-sky">Termux</span>的基础配置及在手机上写<span class="label label-blue">Hexo</span>博客(是不是很激动[滑稽])
<!-- more -->

---

# 基础环境的配置  

**建议翻墙操作,部分内容在墙外面下载比较慢**
<span class="label label-sky">Termux</span>第一次启动会下载系统,需要等待安装,如果太慢可以试试翻墙  

安装好后,执行
```bash
apt update
```
先更新下 `apt`  
(一开始不能下载的话有可能更新下就好了,不行可以换用清华的源 [Termux 镜像使用帮助](https://mirrors.tuna.tsinghua.edu.cn/help/termux/))  

然后执行你需要的命令即可,如  
```bash
apt install screenfetch
```

然后使用 `screenfetch` 查看设备信息  
<img src='/post/img/termux_1.png' width=30% height=30% />  

# 美化termux
有人做了一键美化,可以试下  
[termux-ohmyzsh](https://github.com/Cabbagec/termux-ohmyzsh)

# hexo博客  
首先,<span class="label label-blue">Hexo</span>需要的环境要配置好  

```bash
apt install nodejs
apt install git 
npm install -g hexo
```
然后就是正常的博客生成  
<span class="label label-sky">Termux</span> root 账户(root权限),而 root 账户无法使用 <span class="label label-sky">Termux</span> 的命令,这就造成一个很尴尬的问题  

下面的方法可以一定程度上解决这个问题  

[tsu命令](https://github.com/cswl/tsu)  
使用 `tsu` 代替 `su` 获取 root 权限,在 root 的情况下使用 <span class="label label-sky">Termux</span> 命令  

经过测试, `hexo g` `hexo s` 都能正常使用  
其中 `hexo g` 可能会稍慢,不过还是能生成的,比用最便宜的 VPS 好多了(最便宜的vps跑不起来 generate)  

如图  
<img src='/post/img/termux_2.jpg' width=30% height=30% align='left'/><img src='/post/img/termux_3.jpg' width=30% height=30% />  

剩下的 deploy 和正常的一样就行  


---

- PS: 应群主要求
  点击链接加入群【Termux】：https://jq.qq.com/?_wv=1027&k=44mL4Xt
- PS2: 有个 `linux deploy` 能安装发行版的 linux 可以有空试下