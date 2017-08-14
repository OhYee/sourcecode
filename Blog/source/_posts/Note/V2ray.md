---
title: 使用V2ray科学上网
date: 2017-08-11 21:41:36
categories: 笔记
tags: 
- 科学上网
- v2ray
keywords:
- v2ray
- 科学上网
- ss
- ssr
- shadowsocks
- shadowsocksR
- VPN
---

近来一段时间访问谷歌变得越来越难,SSR的作者因为人肉原因停止维护SSR  
国家开始严打各种VPN服务  
而近一段写安卓又需要大量使用墙外的资源(有时候github的网速也像是被墙了)  

因此需要搞一个VPN来科学上网  

<!--more-->

近一段国家监控的就是之前号称防止个人信息泄露的VPN,通过算法"识别"是否访问了不应该访问的东西  
虽然国家不可能去管我们搜一些技术性的东西,但是还是需要一个加密的算法来对抗破解  

一般个人搭VPN随便找一个国外的VPS就行了,反正自己用的也不过,自然是选便宜的了  

# 购买VPN
经过挑选选择了搬瓦工的[中国直连服务器](https://bwh1.net/cart.php?a=confproduct&i=0)

> SPECIAL 10G KVM PROMO V3 - LOS ANGELES - CHINA DIRECT ROUTE 
> SSD: 10 GB RAID-10
> RAM: 512 MB
> CPU: 1x Intel Xeon
> Transfer: 1000 GB/mo
> Link speed: 1 Gigabit  
>  <br>
> Location: Los Angeles (no other locations available on this plan)
> Direct route via China Telecom and China Unicom  
>  <br>
> VPS technology: KVM/KiwiVM
> OS: 32 or 64 bit Centos, Debian, Ubuntu
> Instant OS reload
> IPv4: 1 dedicated address
> IPv6 support: **No**
> Full root access
> Instant RDNS update from control panel
> No contract, anytime cancellation
> Strictly self-managed, no support
> 99.5% uptime guarantee  
>  <br>
>  
> \$2.99 USD Monthly
> \$6.99 USD Quarterly
> \$11.99 USD Semi-Annually
> \$19.99 USD Annually

总体来说刚刚好,价格非常便宜,只搭VPN也足够了  

直接使用支付宝购买即可  
买完之后进入后台即可  

在后台最下面三项就是一键安装VPN、一键安装SS、一键安装SSR  
支付宝支付+一键科学上网可见搬瓦工这是有着预谋啊  

# 安装V2ray

不过这些现在已经没有人维护了,还是换一个更有前途的吧  
这里推荐使用[V2ray](https://github.com/v2ray)  

它支持SS和SSR的协议  
而且有人在持续维护  
这就足够了  

跟着[官方文档](https://www.v2ray.com/)安装即可  
当然,也有更为[容易理解的版本](https://toutyrater.github.io)  

首先要先重装系统到 Ubuntu ,搬瓦工默认的 CentOS 6 刚好不支持V2ray  

```bash
bash <(curl -L -s https://install.direct/go.sh)
```

管理员权限下运行上面的指令即可  

然后就可以正常使用了,下面是开启的指令
```bash
service v2ray start
```

# 配置

然后用桌面的客户端 [V2rayN](https://github.com/v2ray/v2rayN)  
连接填好自己的服务器,填好地址即可  
端口按照自己喜欢的来,其他的都可以不管  

确定后右键选择<span class="label label-sky">导出所选服务器为服务端配置</span>

然后用任意方式把到处的文件替换掉服务器的`/etc/v2ray/config.json`  
```bash
service v2ray restart
```


# 连接
如果没问题的话,现在右键服务器测试延迟应该可以看到一个延迟的值了  
然后进入系统设置开全局代理就行了  
- ip: `127.0.0.1`  
- 端口: `1080`  

这个可以在V2rayN的参数设置那里更改(或者更改运行目录下的`config.json`)  

如果只想对浏览器翻墙的话,可以不使用全局代理  
使用类似**SwitchyOmega**这样的插件,设置`proxy`模式,填好ip和端口即可   

手机端的话推荐[V2rayNG](https://github.com/vav88/v2rayNG)  
可以直接在电脑上选择分享配置,手机扫二维码导入  


# 问题
虽然能正常访问谷歌,但是速度有点慢,可以用一些黑科技来解决这个问题,有空去搞一下