---
title: 最大矩形
categories: 算法
tags:
  - 最大矩形
  - 动态规划
date: 2016-07-24 01:04:00
---
**最大矩形**是动态规划问题的一部分

对于一个二维的图,可以将其看成由许多宽度为 `1` 的小矩形组成的  
每次可以以一行为基底,求出最低到这一行的矩形的最大面积  
先求出从这一行开始的矩形的往上能达到的最远距离(高),将其称为一个小矩形    
再分别对每个小矩形求取其左侧和右侧没有高于它的最远距离(宽)  
根据宽和高即可求出这个小矩形往外拓展能达到的最大矩形,最后求出所有小矩形中最大的那个值即可  

[**>参考<**](/post/HDU/1506.html)
<!--more-->

```cpp 最大矩形 https://github.com/OhYee/sourcecode/tree/master/ACM 代码备份
int H[maxn][maxn];

int Left[maxn];
int Right[maxn];

int MaxMatrix(bool Matrix[maxn][maxn],int n,int m,bool target) {
    memset(H,0,sizeof(H));
    memset(Left,0,sizeof(Left));
    memset(Right,0,sizeof(Right));

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                if(Matrix[i - 1][j])
                    H[i][j] = H[i - 1][j] + 1;
                else
                    H[i][j] = 1;
            }
        }

    int Max = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                int t = j;
                while(t > 1 && H[i][j] <= H[i][t - 1])
                    t = Left[t - 1];
                Left[j] = t;
            }
        }
        for(int j = m;j >= 1;j--) {
            if(Matrix[i][j] == target) {
                int t = j;
                while(t < m && H[i][j] <= H[i][t + 1])
                    t = Right[t + 1];
                Right[j] = t;
            }
        }

        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                int S = H[i][j] * (Right[j] - Left[j] + 1);
                Max = max(Max,S);
            }
        }

    }

    return Max;
} 
```