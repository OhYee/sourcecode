---
title: 最大上升子序列(最大递增子段和)
date: 2016-07-12 03:07:41
categories: 算法
tags:
- 最大上升子序列
- 动态规划
---
没有找到相似的叫法,网上能搜到的有:
- 最大递增子段和
- 最大上升子段和

不过我更倾向于**最大递增子段和**  
<!--more-->
因为其算法与[**>动态规划版的最大上升子序列<**](/post/Algorithm/LIS.html#动态规划)如出一辙  

根据名字可以看出,最大上升子序列的意义为:
> 找出一个数列的递增子列中,和最大的那个子列  

采用动态规划的解法:  
用 `a[i]` 来存储数列的第 `i` 个数  
用 `dp[i]` 来记录到数列的第 `i` 个数(选取它的情况下)  

对于数列中的第 `i` 个数,显然有 `i` 种可能:  

{% raw %}
<p>
1.    子序列上一个是 <code>1</code> <br>
2.    子序列上一个是 <code>2</code> <br>
3.    子序列上一个是 <code>3</code> <br>
4.    子序列上一个是 <code>4</code> <br>
……<br>
i.    从 <code>i</code> 开始<br>
</p>
{% endraw %}

而显然,由于子序列要上升,因此如果 `a[j] <= a[i]` 这种情况可以直接跳过的  

也即 `dp[i] = max{ dp[j]+a[i] } (j<i && a[j]<a[i])`

由于最后可以从任意地方结束,因此答案不是 `dp[n]` 而是 `dp[]` 中最大的值  
可以维护一个 `Max` 变量  

数据为 `1~n`  
`a[0]` 表示起点,初始化为 `0`  

```cpp MIS
int Max = 0;
a[0] = 0;
for(int i = 0;i <= n;i++) {
    dp[i] = 0;
    for(int j = 0;j < i;j++) 
        if(a[i] > a[j])
            dp[i] = max(dp[i],dp[j] + a[i]);
    Max = max(Max,dp[i]);
}
```