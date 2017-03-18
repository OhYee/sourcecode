---
title: 学习安卓开发
date: 2017-03-11 23:22:21
categories: 笔记
tags:
  - Android
---
安卓又是一个大坑  
<!--more-->  

# IDE的选择
安卓开发有两个 IDE 可供选择  
- eclipse
- Android Studio

虽然 eclipse 是 Java 的王者,但是自然是专为 Android 开发准备的 Android Studio 更适合我们  

首先,Android的开发需要安装 Android SDK ,因此需要在安装 IDE 的同时顺便勾选上 Android SDK  

# 运行第一个项目

安装完成后,就可以开始自己的第一个项目了  
正常的新建等步骤  
然后可以什么都不管直接跑(Hello World)  
就会发现并不能直接编译  

因为 Android 的软件自然是要在 Android 设备上跑的,直接在 Windows 显然跑不起来  
因此还需要 Android 虚拟机  
在 `SDK Manage` 里确保已经有个基础的 SDK (记得看下另一个选项卡的 SDK tool)  
然后在 `AVD Manage` 里新建一个设备  
这里就是管理你的安卓模拟器的地方,配置好(选择不同版本的系统需要下载对应版本的包)  
最后 `Sync Project with Gradle Files` 即可
这时再点击运行就会启动安卓模拟器并且自动装上你的软件了  

# Grable  
通俗来说,Grable 就是一个帮你完成写完整体架构后的编译工作的工具  
不管你要针对不同的幸好编译多少的版本,也不管你需要依赖多少文件,全部交给它搞定即可  

Gradle的配置包含以下方面
> - 构建变量
>   构建系统可以根据不同的配置为同一个项目生成多个APK。当你想建立不同版本的应用程序，而不必为每个人单独的项目，这是很有用的
> - 依赖关系
>   构建系统管理项目的依赖，并从本地文件系统和远程存储库支持的依赖。这可以防止你不必搜索，下载和复制二进制包为你的依赖到你的项目目录。
> - 清单条目
>   构建系统使您可以指定的值在生成配置清单文件中的某些元素。这些新的值将覆盖在manifest文件中的现有值。如果你想生成多个的
>   APK为您的项目中，他们每个人都有不同的包名，最小的SDK版本，或目标SDK版本，这是很有用的。
> - 签名
>   构建系统使您可以指定生成配置签名设置，它可以在生成过程中签署您的APK。


# Andriod Studio 的 Android 目录解释

参考文章：
[1.Android Studio目录结构浅析](https://segmentfault.com/a/1190000002963895)

首先看一下一个简单的程序包含哪些文件  

<div><div class="fold_hider"><div class="close hider_title">点击显隐内容</div></div><div class="fold">```

│  build.gradle
│  gradle.properties
│  gradlew
│  gradlew.bat
│  local.properties
│  SchoolNavigation.iml
│  settings.gradle
├─.gradle             
├─.idea 
├─app
│  │  .gitignore
│  │  app.iml
│  │  build.gradle
│  │  CMakeLists.txt
│  │  proguard-rules.pro
│  ├─libs    
│  └─src
│      ├─androidTest                         
│      ├─main
│      │  │  AndroidManifest.xml
│      │  ├─cpp   
│      │  ├─java                     
│      │  └─res
│      │      ├─anim    
│      │      ├─drawable   
│      │      ├─drawable-hdpi   
│      │      ├─drawable-mdpi   
│      │      ├─drawable-xhdpi   
│      │      ├─drawable-xxhdpi   
│      │      ├─layout   
│      │      ├─menu   
│      │      └─values
│      │              
│      └─test                               
├─build       
└─gradle
            

```
</div></div>  

<br>

首先最显眼的就是 Gradle  
所有名字带有这个的自然就是 Gradle 需要的  

`.gradle` 就是 Gradle 的编译系统  
`gradlew`	和 `graldew.bat`	分别是 *nix 和 windows下的 gradle wrapper 可执行文件  
`build.gradle` `settings.gradle` 和 `gradle.properties`	都是相关的设置  
`gradle` 	wrapper的jar和配置文件所在的位置  

`local.properties` 则是记录了该项目的一些信息(key、sdk位置等)  
`.idea` 是 Android Studio 需要的一些文件  
`build`	代码编译后生成的文件存放的位置

这些都是 ide 自己可以生成的,不是我们应该关系的内容  


`app` 文件夹内才是我们需要特别关注的,我们写的代码、调用的资源全部都在这里  
`bulid` 同样是编译后生成的文件目录  
`libs` 则是项目依赖的库的目录,使用的外部的库都放在这个目录里  
`src` 就是我们接触最多的源码目录了  

里面的 `test` 显然是测试代码  
`main` 就是主代码了  
进去后会有最关键的 `AndroidManifest.xml` 这个就是项目清单文件,这个文件列出了应用程序所提供的功能,所有开发好的各种组件需要在该文件中进行配置,如果应用使用到了系统内置的应用(如电话服务、互联网服务、短信服务、GPS服务等等),还需在该文件中声明使用权限.  
而其他的几个 `java` `cpp` 则是通过不同语言写的代码部分,也就是后端部分  
`res` 则是资源目录,每个页面的布局、使用的动画图片等前端部分放在这里  