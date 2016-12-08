---
title: 三星 C5 Google(港版) + root + Xposed + 其他设置
date: 2016-11-17 12:47:01
categories: 随笔
tags: 
- 三星(SANSUNG)
- Android
- C5he
- root
---

# == 刷机前注意！！ ==
刷机有风险,会失去保修、失去 <span class="label label-blue">Knox</span> 、失去 <span class="label label-blue">SAMSUNG PAY</span> 、失去<span class="label label-blue">指纹支付(支付宝、微信)</span>

<!--more-->
> ============ update 2016-11-30 ================
> 从贴吧和群里有挺多人都挺想刷机,许多人都加好友问了一些具体的操作.  
> 本来只是提供下刷机思路,帮助有刷机经验的人少踩些不必要的坑  
> 既然问的人比较多,就把步骤再完善下.

# 概述
该刷机思路为先线刷官方包到<span class="label label-orange">港版固件</span>,再刷入<span class="label label-orange">港版</span>对应的 <span class="label label-sky">recovery</span> ,而后通过 <span class="label label-sky">recovery</span> 卡刷完成设备 root  

<b><p style="color:red">变砖等各种刷机造成的问题,不予负责</p></b>    

# 再次警告
Root 会失去 **保修、指纹支付、固件升级** 等功能  
且有一定几率刷机出现问题,导致(不限于)以下问题: 信号网络无法连接, wifi 功能无法使用, 手机话筒失灵, 无法发送短信    
尽管以上内容基本都能够通过重新刷机解决,但是对于没有刷机经验的人来说,不建议以目前状态(没有第三方 ROM ,没有大神帮助解决问题)下的 C5 为入门  

刷机前请 <b><p style="color:red">完整看完所有步骤</p></b> ,有整体思路后再开始刷机  
如果有地方看不懂,建议**停止刷机**行为  
即使刷成功,获取 Root 权限后使用某些软件造成各种奇怪的后果仍然会 **极大影响你正常使用手机**  

由于没有人整合 ROM 和 Root 包,导致能找到的 <span class="label label-blue">Samsung C5</span> root 包 和<span class="label label-sky">recovery</span>包 比较少  
因此,想要 root <span class="label label-blue">C5</span> 不能像别的机型那样直接线刷或者卡刷root包解决.  
因此,刷机后,手机会比 恢复出厂设置 更干净  

<b><p style="color:red">自行备份 联系人、短信、相册 ！！！</p></b> 
可以使用百度云、XXX手机助手等任意软件备份  

<b><p style="color:red">当某一步手机发现不正常行为,从头开始重新刷机理论可以解决大部分问题,如果还不行,基本上就只能换新手机了</p></b> 

<b><p style="color:red">无论卡到哪一个界面,同时按下 <kbd>下音量键 + Home键 + 电源键</kbd> 可以强制重启</p></b> 

自行学习以下内容,里面有详细的图文解释: 
 1. [三星C5解锁教程_三星C5000解锁bootloader教程](http://www.muzisoft.com/root/240801.html) 
 2. [三星C5(C5000)刷入recovery教程](http://www.muzisoft.com/shuaji/241211.html)
 3. [三星C5(C5000)root权限获取教程](http://www.muzisoft.com/root/241215.html)

由于固件版本问题,上面教程里的给的部分文件会造成奇怪的问题,但是**其他操作一模一样**！  
跟着走就行  

有问题可以 QQ 看有没有时间回答,苦逼大二狗要忙着上课、考试、陪女票、写代码  
当然,如果发个几百的红包,说不定我就不管其他事先来帮忙回答问题了 (✿◡‿◡)  

# 需要的程序

先下载好以下软件,做好准备工作  

[百度云链接](http://pan.baidu.com/s/1pLgyALX)

1. CROM (`CROM Service.7z`)
2. Odin3 (`Odin3.7z`)
3. <span class="label label-orange">港版官方固件</span> (`SM-C5000ZHU1API2四件套（含一体包）.zip`)
4. <span class="label label-sky">TWRP Recovery</span>  (`C5000ZCU1API2版本可用recovery.zip`)
5. SuperSu 二进制包 (`BETA-SuperSU-v2.74-2-20160519174328.zip`)
6. <span class="label label-green">xposed 下载器</span> (`xposed.apk`)
7. <span class="label label-green">xposed 框架</span> (`xposed-v86.0-sdk23-arm-custom-build-by-wanam-20160709.zip`)

# 解除手机锁
进入<span class="label label-blue">三星商店</span>,下载 CROM  (上面链接里也有,建议在三星商店下)  

安装完成后, **认真阅读警告** ,如果仍然确定要刷,点击 **确定** 解锁完成  

# 刷入港版包( SM-C5000ZCU1API2 )  

关机,同时按下 **下音量键 + HOME 键 + 电源键** 进入 DOWNLOAD 模式(挖煤模式)  

1. 手机连接电脑,进入 Odin ,显示设备插入(蓝色)  
2. 选择刷机包内的文件,对应名字选择(选择时会略卡)  
 其中 csc 有两个文件,建议用不带 HOME 的刷入(清除设备刷入)
 - BL 
     - `BL_C5000ZHU1API2_CL8450604_QB11041581_REV00_user_low_ship_MULTI_CERT.tar.md5`
 - AP 
     - `AP_C5000ZHU1API2_CL8450604_QB11041581_REV00_user_low_ship_MULTI_CERT.tar.md5`
 - CP 
     - `CP_C5000ZHU1API2_CL8450604_QB11041581_REV00_user_low_ship_MULTI_CERT.tar.md5`
 - CSC 
     - `CSC_ZZH_C5000ZZH1API2_CL8450604_QB11041581_REV00_user_low_ship_MULTI_CERT.tar.md5` (会清除所有数据)
     - `HOME_CSC_ZZH_C5000ZZH1API2_CL8450604_QB11041581_REV00_user_low_ship_MULTI_CERT.tar` (可能不会清除所有数据) 

3. **取消选择 `自动重启`** ,开始刷机  
 ![](/post/img/root_1.png)
4. 当显示绿色的 pass 时,同时按下 <kbd>下音量键 + HOME 键 + 电源键</kbd> 强制关机
5. 正常启动,进入系统,检查是否成功(wifi、蓝牙、信号是否正常)  

# 刷入 Recovery(TWRP)  
1. 解压 `C5000ZCU1API2版本可用recovery.zip` 找到里面的 `C5000-recovery.tar` 
2. 同上,手机连接电脑,在 Odin 中,将 `C5000-recovery.tar` 选在 AP 里,同样取消 `自动启动`  
3. 同上,刷入 Recovery , 关机后同时按下 <kbd>上音量键 + HOME 键 + 电源键</kbd> ,进入 Recovery 模式      
4. 进入<span class="label label-sky">TWRP</span>替换官方 Recovery (中文操作,按提示就行)  

<b><p style="color:red">此时,你可以选择备份,进入后备份 EFS 分区,该分区至关重要 ！！！</p></b> 

# Root (SuperSu)   
1. 将 `BETA-SuperSU-v2.74-2-20160519174328.zip` 传输到手机里(最好放在根目录里,好找)  
2. 进入 <span class="label label-sky">TWRP</span> 选择安装,找到 `BETA-SuperSU-v2.74-2-20160519174328.zip`
3. 重启手机 
4. 此时你的手机已经 Root 完成,开机检查是否有问题,如果没有 SuperSU 权限管理工具,自己上网找一个下载安装  

# 安装 xposed 
1. 同 Root 部分,将 `xposed-v86.0-sdk23-arm-custom-build-by-wanam-20160709.zip` 卡刷入系统  
2. 刷入后重启会 **非常慢** ,如果无限卡三星logo,强制重启即可  
3. 进入系统后,打开 <span class="label label-green">xposed</span> 已经可以看到框架安装成功,无视他的不兼容警告  
4. 安装模块  

# 关闭相机快门音 

原帖 http://www.linuxidc.com/Linux/2013-07/87304.htm

> 三星i9100怎么才能取消拍照声音呢，在默认情况下即使静音状态下拍照还是有声音的。
> 
> 手机需 root，且需要 TC、RE、ES 等文件管理器，自己下载吧。
> 
> 当然，也可以修改 SamsungCamera.apk 内 res-raw 来达到完全达到完全无声的效果，但是，万一需要拍照有声音，还是要替换 SamsungCamera.apk，很是麻烦。
> 
> 其实，拍照软件本来就有个“快门音”的选项菜单的，只是系统默认是隐藏的。
> 
> 而我的方法，就是让你的i9308手机系统拍照软件显示该菜单，见图，只需修改一次，以后无需替换文件，直接在照相时候选择是否需要拍照音（包括单拍、连拍、聚焦等）
> 
> 1. 文本形式打开 `/system/csc/feature.xml`
>  
>  若有 `<!--Camera-->` 
>  这段，就在下面新增
>  `<CscFeature_Camera_ShutterSoundMenu>true</CscFeature_Camera_ShutterSoundMenu>` 
>  若已有该行则把 `false` 改为 `true`
>  
>  没有 `<!--Camera-->` 
>  这段，把这段也新增，`<!--Camera-->` 只是用来解释说明的行，说明下面的命令是关于 Camera 的，本身不是命令  
>  注意 xml 的嵌套关系,不要放错嵌套  
>  ```xml
 <!--Camera-->
 <CscFeature_Camera_ShutterSoundMenu>true</CscFeature_Camera_ShutterSoundMenu>
 ```
>  保存退出
>    
>  这个命令就是让系统拍照软件显示“快门音”菜单，但此时菜单有了，但是关闭选项仍然是无效的，因为系统强制拍照有声音
>   
> 2. 文本形式打开 `/system/build.prop`
>  
>  在中间的位置可以看到 `ro.camera.sound.forced=1` ，把 `1` 改成 `0` 
>  若没有这行就新增
>  保存退出
>  
>  这个命令就是系统强制拍照声音的根源，改成 `0` 
>  关闭后，系统就不强制拍照带声音了，让“快门音”菜单“关”生效  
>   
> 3. 进入相机关闭快门音