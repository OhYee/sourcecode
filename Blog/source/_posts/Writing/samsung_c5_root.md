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
刷机有风险,会失去保修、失去 Knox 、失去 SANSUNG PAY 、失去指纹支付(支付宝、微信)

刷机前备份 **efs** !!!  
刷机前备份 **efs** !!!  
刷机前备份 **efs** !!!  

<!--more-->

# 需要的程序
  


[百度云链接](http://pan.baidu.com/s/1pLgyALX)

1. CROM (`CROM Service.7z`)
2. Odin3 (`Odin3.7z`)
3. 港版官方固件 (`SM-C5000ZHU1API2四件套（含一体包）.zip`)
4. TWRP Recovery (`C5000ZCU1API2版本可用recovery.zip`)
5. SuperSu 二进制包 (`BETA-SuperSU-v2.74-2-20160519174328.zip`)
6. xposed 下载器 (`xposed.apk`)
7. xposed 框架 (`xposed-v86.0-sdk23-arm-custom-build-by-wanam-20160709.zip`)

# 解除手机锁
进入三星商店,下载 CROM  
解除手机锁

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
4. 当显示绿色的 pass 时,同时按下 **下音量键 + HOME 键 + 电源键** 强制关机
5. 正常启动,进入系统,检查是否成功(wifi、蓝牙、信号是否正常)  

# 刷入 Recovery(TWRP)  
1. 同上手机连接电脑,在 Odin 中,将 `C5000-recovery.tar` 选在 AP 里,同样取消 `自动启动`  
2. 同上刷入 Recovery , 关机后同时按下 **上音量键 + HOME 键 + 电源键**    
3. 进入 TWRP 替换官方 Recovery  

# Root (SuperSu)   
1. 将 `BETA-SuperSU-v2.74-2-20160519174328.zip` 传输到手机里  
2. 进入 TWRP 安装该 zip 文件  
3. 重启手机 

# 安装 xposed 
1. 同 Root 部分,将 `xposed-v86.0-sdk23-arm-custom-build-by-wanam-20160709.zip` 卡刷入系统  
2. 打开 xposed 安装器安装文件  

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