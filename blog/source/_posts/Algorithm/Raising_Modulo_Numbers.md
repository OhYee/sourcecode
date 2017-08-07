---
title: 快速幂取模
date: 2015-07-29 20:59:00
tags: 
- 快速幂取模
- 二分
- 递归与分治
categories: 
- 算法
---
取余数有%，即
> 10%3

可以得到1

但是当数比较大时(比如2999999)，计算机可能就无法计算

然而，根据数论的结论，我们可以简化一下。
<!--more-->
根据`a*b mod c = ( (a mod c) * (b mod c) ) mod c`

可以得出 `an mod b = (a mod b)n mod b`

所以，有 `an mod b = (a mod b)n mod b = (a mod b)n/22 mod b = (an/2 mod b)2 mod b = (an/2 mod b)2 mod b`

如果用`exp_mod(a,n,b)`表示**an mod b**那么就是`exp_mod(a,n,b) = exp_mod(a,n/2,b)*exp_mod(a,n/2,b) mod b`

那么我们可以不断二分幂，从而减小运算

有几种特殊情况需要考虑

1. n=0，也即a^n=1，此时模为1%b
2. n=1，这时二分已经到了终点，可以直接用a%b得到答案
3. n为奇数，此时n/2会被舍去小数部分，会少乘一个a mod b，可以在补上a mod b

代码如下：
``` cpp
typedef long long LL;
LL exp_mod(LL a,LL n,LL b){
    LL t;
    if(n==0) return 1%b;
    if(n==1) return a%b;
    t=exp_mod(a,n/2,b);
    t=t*t%b;
    if((n&1)==1) t=t*a%b;
    return t;
}
```