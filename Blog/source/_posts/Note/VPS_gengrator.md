---
title: VPS gengrator 命令导致 hexo 被 killed 解决方案
date: 2017-04-07 21:31:50
categories: 笔记
tags:
 - Hexo
 - VPS
 - Linux
keywords:
 - Hexo killed
---
问题在 Segmentfault 上提问 [Linux(CentOs)下hexo生成文章被killed](https://segmentfault.com/q/1010000007869915)  

有解决方案:
> 内存不足，创建交互空间即可。  
> 见：https://www.qcloud.com/document/product/362/3597  

<!--more-->

该网页给出如下方案  
```bash
free -m 
dd if=/dev/zero of=/swap bs=4096 count=1572864
mkswap /swap
swapon /swap
echo "LABEL=SWAP-sda /swap swap swap defaults 0 0" >> /etc/fstab
```

这样会在根目录建立一个 swap 文件,用于虚拟内存  
**使用 `dd if=/dev/zero of=/swap bs=4096 count=1572864` 命令时,会卡一会,等待即可**  

然后就可以正常使用 `hexo g` 命令了  