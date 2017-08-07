---
title: 丑数
date: 2016-07-25 00:31:59
categories: 算法
tags: 丑数
---
{% blockquote 百度百科 http://baike.baidu.com/link?url=4FAuh-kn25Reiy0i9QVOLqvTl7AAmLZ4SMAiR1RLwKXy7uzb47qqvVln8Nkfk57LSjarzLqhpYDREBGt47x8USGtpbNsLLxvevXHcqfu6jO 丑数 %}
所谓丑数，就是不能被2，3，5，7以外的其他素数整除的数。1，2，3，4，5，6，7，8，9，10，12，14，15，16，18是最前面的15个丑数。
{% endblockquote %}

<!--more-->
根据**唯一素数分解定理**,类似于**筛法求素数**的方法,即可求出所有素数  

如果采用筛法求素数的思路,需要开两个数组,而实际由于我们并不需要这些  

由于由每个丑数分别乘上 `2` , `3` , `5` , `7` 可以得到所有丑数,可以分别对每个丑数乘上这四个数,在找到新丑数的同时找到新的因子  
重点在于判重,由于 `2*3` 和 `3*2` 这种情况会被重复计算,因此可以采取用 `4` 个“指针”,来分别记录对 `4` 个数的下标,每次将新的丑数取最小的那个,而后将结果中与新的丑数相同的下标全部后移  
这样在排序的同时做到了判重  

```丑数
const int maxn = 5842 + 1;
int dp[maxn];
int i1 = 1,i2 = 1,i3 = 1,i4 = 1;
    int n = 1;
    dp[1] = 1;
    while(n < maxn) {
        dp[++n] = min(min(2 * dp[i1],3 * dp[i2]),min(5 * dp[i3],7 * dp[i4]));
        if(dp[n] == 2 * dp[i1]) i1++;
        if(dp[n] == 3 * dp[i2]) i2++;
        if(dp[n] == 5 * dp[i3]) i3++;
        if(dp[n] == 7 * dp[i4]) i4++;
    }
```