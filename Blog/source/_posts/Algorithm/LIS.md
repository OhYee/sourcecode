---
title: 最长上升子序列
categories: 算法
tags:
  - 最长上升子序列
  - 动态规划
  - 二分
date: 2016-04-30 22:37:00
---

> 对于一个数列a1,a2,a3,a4……求取其最长的子序列s1,s2,s3……使其满足单调递增的算法，叫做最长上升子序列

 

对于该问题有两种思路：

* 动态规划方法求解 O(n2)
* 贪心+二分 O(nlogn)
 

# 动态规划

* A[i]表示序列中的第i个数  
* dp[i]表示从1到i这一段中以i结尾的最长上升子序列的长度  

初始时设`dp[i] = 0(i = 1, 2, ...)`。

则有动态规划方程：`dp[i] = max{dp[j] + 1} (j = 1, 2, ..., i - 1, 且A[j] < A[i])`

 

# 贪心+二分

构造一个有顺序的栈s

每次取栈顶元素top和读取到的元素a

```
if top < a

　　s.push(a)

else

　　用a替换栈中第一个比a大的数
```
 

最后栈中的元素的数量就是所求的数量(但是栈中元素可能并不是最长上升子序列)


举例：原序列为1，5，8，3，6，7 
 
栈为1，5，8，此时读到3，则用3替换5，得到栈中元素为1，3，8，  再读6，用6替换8，得到1，3，6，再读7，得到最终栈为1，3，6，7  ，最长递增子序列为长度4。 

 ```cpp 模板
 class LIS_stack {
private:
    static const int SIZE = maxn;//最大长度
    int len;//长度
    int Stack[SIZE];
public:
    LIS_stack() {
        len = 0;
        memset(Stack,0,sizeof(Stack));
    }
    void push(int num) {
        if(len == 0 || Stack[len - 1] < num) {
            Stack[len++] = num;
        } else {
            for(int i = 0;i < len;i++) {
                if(Stack[i] > num) {
                    Stack[i] = num;
                    break;
                }
            }
        }
    }
    int lenth() {
        return len;
    }

};

int LIS(int *a,int len) {
    LIS_stack s;
    for(int i = 0;i < len;i++) 
        s.push(a[i]);
    return s.lenth();
}
```