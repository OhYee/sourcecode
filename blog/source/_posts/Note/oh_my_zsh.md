---
title: oh_my_zsh 安装
date: 2017-05-20 23:44:45
categories: 笔记
tags:
 - Linux
---

`oh_my_zsh` 是 Linux 上一款非常漂亮的终端界面  
![](/post/img/oh_my_zsh.png)

<!--more-->

1. 更新软件源
  ```bash
sudo apt-get update
```

2. 安装zsh
  ```bash
sudo apt-get install zsh
```

3. 获取并安装 oh my zsh
  ```bash
wget --no-check-certificate https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh
```
4. 替换bash为zsh
  ```bash
chsh -s /bin/zsh
```
5. 重启电脑
  ```bash
sudo reboot
```
6. 安装分屏软件
  ```bash
sudo apt-get install terminator
```