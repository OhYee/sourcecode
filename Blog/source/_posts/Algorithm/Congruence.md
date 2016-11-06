---
title: 同余
date: 2015-07-28 20:17:00
tags:
- 同余
- 数学
categories:
- 算法
---

> 同余指两个整数除以同一正数，余数相同。  
> 同余指两个整数相减能够被一个整数整除。
<!--more-->

1. 反身性 a≡a(mod m)
2. 对称性 若a≡b(mod m)，则b≡a (mod m)
3. 传递性 若a≡b (mod m)，b≡c (mod m)，则a≡c (mod m)
4. 同余式相加 若a≡b (mod m)，c≡d(mod m)，则a+-c≡b+-d (mod m)
5. 同余式相乘 若a≡b (mod m)，c≡d(mod m)，则ac≡bd (mod m)
6. 线性运算如果a ≡ b (mod m)，c ≡ d (mod m),那么(1)a ± c ≡ b ± d (mod m)，(2)a * c ≡ b * d (mod m)
7. 除法若ac ≡ bc (mod m) c≠0 则 a≡ b (mod m/gcd(c,m)) 其中gcd(c,m)表示c,m的最大公约数.特殊地 ,gcd(c,m)=1 则a ≡ b (mod m)
8. 幂运算如果a ≡ b (mod m)，那么a^n ≡ b^n (mod m)
9. a ≡ b (mod m)，n|m,则 a ≡ b (mod n)
10. 若a ≡ b (mod mi) (i=1,2...n) 则 a ≡ b (mod [m1,m2,...mn]) 其中[m1,m2,...mn]表示m1,m2,...mn的最小公倍数

## 欧拉定理
设a,m∈N,(a,m)=1,则a^(φ(m))≡1(mod m)
(注:φ(m)指模m的简系个数， φ(m)=m-1, 如果m是素数；φ(m=q1^r1 * q2^r2 * ...*qi^ri)=m (1-1/q1)(1-1/q2)...(1-1/qi))
推论: 费马小定理: 若p为质数，则a^p ≡ a (mod p) 即a^(p-1) ≡ 1 (mod p)
 （但是当p|a时不等价）  
   
   
 
## 中国剩余定理
设整数m1,m2,m3,......,mn 两两互素，令m=m1m2m3m4m5...mn（mi的连乘）。则对于任意的J在（1,n)整数，下列联立的同余式有解：
{xj≡1(mod mj)
{xj≡0(mod mi) i不等于j
令x为从1到najxj的和，则x适合下列联立同余式
x≡aj（mod mj）, j=1,2,3,.....,n