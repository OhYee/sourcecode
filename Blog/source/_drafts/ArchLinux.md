---
title: 安装 Arch Linux
date: 2017-05-17 20:21:16
categories: 笔记
tags: 
  - Linux
---
想折腾Linux玩玩,选了一下决定研究下 Arch Linux  

虽然很多人都推荐用 Ubuntu (比较省事)  
但是怎么要的不就是钻研精神么?

下面开始尝试安装 Arch Linux  

**本博客纯实验笔记性质,可能部分步骤是错误的(发现后会标记出来)**

----------

{% note info %}
# 任务1:下载镜像
**描述**:前往**[官网](https://www.archlinux.org/download/)**下载镜像
{% endnote %} 

下载等待的同时设置好虚拟机(第一次装还是虚拟机练下手靠谱一点)  

Vmware 没检测到镜像,选其它Linux吧~  

![开始界面]()

显然,应该选择第一个安装64位的系统  

根据正常的装机顺序,第一步应该是分区  
所以,我们的下一个任务就是给 sda 分区  

{% note info %}
# 任务2:给硬盘分区
**描述**:将硬盘*(<span style='color:red'>sda</span>)*分为两个分区,分别用于挂载swap和根目录
**命令**:`fdisk` `mount`
{% endnote %}

执行 `fdisk -l` 查看系统的硬盘  

![查看硬盘]()

可以看到有
`Disk /dev/sda: 20GB` 和 `Disk /dev/loop0:369.5MB`  
显然第一个是硬盘,第二个是加载的 ISO 镜像  


使用 
```bash
fdisk /dev/sda
```
对硬盘进行分区  
这时,会进入分区命令里  

需要用到的操作有:
> m 查看帮助
> n 新建分区
> d 删除分区  
> w 写入分区表

我们需要新建分区  
首先要选择新建主分区(p)和逻辑分区(e)  
其中主分区最多4个(这也是我们电脑通常是C、D、E、F四个盘的原因)  

选好p之后再选择分区编号,默认即可  
然后是分区起始位置和分区结束位置  


由于Linux直接扔到一个分区就行,我们就不必刻意去分  
不过可以单独把swap分区分出来,swap分区就相当于虚拟内存  
我们这里分给它1G  

一个扇区为512B
1G=1024*1024*1024/512=2097152个扇区
由于分区是从2048开始的,故结束点是2097152+2048=2099200
所以分区起始位置默认,结束位置2099200  
这样我们就分了一个1G分区  

然后把剩下的全部分到一个分区,全部默认即可  

最后w写入分区表即可  

![分区]()

运行 
```bash
cat /proc/partitions
```

其中sda1,sda2就是我们分的两个分区  
![查看分区表]()

然后运行  
```bash
mkswap /dev/sda1
swapon /dev/sda1
```
格式化并启用swap分区  

运行
```bash
mkfs.ext4 /dev/sda2
```
格式化主分区

![格式化分区]()


最后挂载主分区  
```bash
mount /dev/sda2 /mnt
```
![挂载分区]()





{% note info %}
# 任务3:安装系统
**描述**:将 Arch Linux 装入硬盘
**命令**:`pacstrap`
{% endnote %}

首先检查镜像文件是否正常  
`/etc/pacman.d/mirrorlist`
查看China源是否被注释,如果正常就不用管了  


运行命令安装系统  
```bash
pacstrap /mnt base base-devel
```

因为要联网下载好多东西,所以可能需要等待一段时间  


剩下的就是根据需要进行设置即可  
