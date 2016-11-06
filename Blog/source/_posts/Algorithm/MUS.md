---
title: 最大不连续子序列
categories: 算法
tags:
  - 最大不连续子序列
  - 动态规划
date: 2016-07-23 01:55:00
---
按照 `最大连续子序列` 的命名,来命名 `最大不连续子序列` ( `Maximum Uncontinuous Subsequence` )  

> 其意思是,在一串数中,在所有数都不相邻的子序列里,找出和最大的子序列  

<!--more-->

根据动态规划的思想,用 `dp[i]` 表示前 `i` 个数中,最大不连续子序列  
那么对于第 `i` 个数,有选择和不选择两种情况  
如果选择,那么就不能选择第 `i-1` 个数,此时有 `dp[i] = dp[i-2] + num`  
如果不选择,那么它应该等于上一个最大不连续子序列,有 `dp[i] = dp[i-1]`  

也即 `dp[i] = max(dp[i-1],dp[i-2]+num)`  

由于通常 `i>=1` 因此需要特殊考虑 `i==1` 和 `i==2` 的情况  

```cpp
void MUS(int *dp,int *num,int n){
    dp[1] = num[1];
    dp[2] = max(num[1],num[2]);
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+num[i]);
    }
}
```
