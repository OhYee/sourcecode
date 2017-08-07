---
title: VPS搭建Git服务器及git pages
date: 2016-06-26 18:25:17
categories: 笔记
tags: 
 - Hexo
 - VPS
 - Git
 - Linux
keywords:
 - 搭建Hexo
 - 搭建Git服务器
 - 腾讯云
 - 服务器
 - VPS
---
对比了以下腾讯云和阿里云,觉得个人更喜欢腾讯云一点  
腾讯云每天中午12点能够在官网上抢学生优惠  
一个月1元钱拿到 VPS 服务器    
练手专用  

<!--more-->

抢到后选择 65 的服务器(一个月),然后用抢到的 64 优惠券购买  
以后每个月记得去领一次优惠券即可(不用抢)  

弄好后,选择了 Linux 系统的服务器  
既然是学习,再用 Windows 就没有意思了嘛~~~   

使用了 `CentOS 7.2 64位`   
初始化完成后,只需要 `yum install git`  
就可以在服务器上安装上 git  
同理可以安装 `python` `nodejs` 等内容  
安装好 `nodejs` 后,直接 `npm install hexo -g`  
就可以安装 hexo  
不过这个其实没必要,如果文章比较多,其实在服务器上跑生成会被系统强行杀死的  

不过我们可以模仿 github 那样搭建自己的 gitpages  

首先解决权限问题, git的操作最好给一个特定的用户  
我们新建一个 git 用户  
```bash
adduser git
passwd 
```

进入用户目录 `/home/git`  
这里有一个隐藏的文件夹 `.ssh`  
在这个文件夹里就是我们 `ssh` 相关的配置文件  
新建一个 `authorized_keys` 文件  
把我们本地的 `id_rsa.pub` 的内容放进去,这样服务器就会同意我们的电脑通过 ssh 连接进来  
**所有文件的所有者和用户组都应该是 git ,并且权限也要设置好**  


然后在他的用户目录里新建一个文件夹作为我们的git库  
```bash
mkdir git
cd git
git init --bare
```

这样我们的 git 服务器就搭建好了  
把本机的远程仓库地址填成 `git@[vps地址]:[目录地址(以/home/git为根目录)]`  
push 上去就行了  

那么怎么显示出来呢  
我们可以再搭建一个 nginx   
每次推送上去后把文件复制到 nginx 的目录里  

这就需要 `git hooks` 来实现了  
进入 git 服务器的目录里  
有一个 `hooks` 目录  
新建一个 `post-receive` 文件  
```bash
touch post-receive
```

然后内容改为
```bash
#!/bin/bash
echo BEGIN

rm -rf /home/git/hexo
git clone /home/git/hexo.git /home/git/hexo
rm /home/git/task/urls.txt
cp /home/git/hexo/urls.txt /home/git/task/urls.txt
rm -rf /usr/share/nginx/hexo/*
mv /home/git/hexo/* /usr/share/nginx/hexo

echo BLOG FINISH

git push -u origin master -f

echo FINISH
```

自己改为自己对应的目录  

解释下内容 `#!/bin/bash` 告诉系统这个以 bash 形式运行文件   
`rm -rf /home/git/hexo`  
`git clone /home/git/hexo.git /home/git/hexo`  
删除并重新 clone 出博客(必须clone在git有权限操作的目录里)  

`rm /home/git/task/urls.txt`  
`cp /home/git/hexo/urls.txt /home/git/task/urls.txt`  
复制一份生成的所有文章的链接的文件(用于提交到百度站长,可以不要这两行)  

`rm -rf /usr/share/nginx/hexo/*`  
`mv /home/git/hexo/* /usr/share/nginx/hexo`  
删除 nginx 的网站目录下的文件,并将新的内容移动过去(git需要该目录的权限)  

这样就完成了我们自己的 git pages 的搭建    

`git push -u origin master -f`  
这个可以顺便把我们的博客推送到 `github` 和 `Coding`  
在 git 目录里设置下 remote 即可  
