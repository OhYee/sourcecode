---
title: double的读入与输出
categories: 笔记
date: 2016-06-06 23:49:55
tags:
 - 读入输出
---

{% blockquote Taku https://segmentfault.com/q/1010000005590782 SegmentFault上的回答 %}  
scanf函数是通过指针指向变量的。%f告诉scanf函数在所传地址位置上存储一个float型值，
而%lf告诉scanf函数在所传地址位置上存储一个double型值。这里float和double的区别是非常重要的。
如果给出了错误的转换说明，那么scanf函数将可能存储错误的字节数量
（没有提到的是，float型的为模式可能不同于double型的位模式）。  
{% endblockquote %}  


因此，当输入时必须使用`%lf`来确保数据被正确存储

为了方便使用者，很多编译器默许了常见的错误，当使用`printf("%lf",a)`时，若a为`double`变量，编译器会自动把其修改为`%f`

而LLVM会警告并推荐修改为%f。

**`scanf()`函数中不存在`%lf`，输入`double`用`%lf`输出用`%f`**