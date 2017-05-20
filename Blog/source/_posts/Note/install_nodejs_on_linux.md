---
title: 在 Linux 上安装 Node.js
date: 2017-05-20 23:44:45
categories: 笔记
tags:
 - Linux
 - nodejs
---

原则上,直接从[官网](https://nodejs.org/en/download/)下载是没有问题的  
不过我这里一直安装不上  
`apt-get` 和 source 都安装失败  

于是下载了编译好的 64 位包  

下载后  
```bash
tar xvf <filename>
```
解压文件  

然后放到了 `/usr/share/node` 目录

然后编辑 `/etc/profile` 

把下面内容加到最后面(环境变量) 
```
export NODE_HOME=/alidata/node-v0.10.19-linux-x64
export PATH=$PATH:$NODE_HOME/bin
export NODE_PATH=$NODE_HOME/lib/node_modules
```

最后重载下  
```bash
source /etc/profile
```
