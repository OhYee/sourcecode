---
title: 倍增最近公共祖先(LCA)
date: 2017-08-29 23:14:00
categories: 算法
tags:
 - 最近公共祖先
 - 树
---
> 对于有根树T的两个结点u、v，最近公共祖先LCA(T,u,v)表示一个结点x，满足x是u、v的祖先且x的深度尽可能大。

在树上,两点之间的最短路就是公共祖先分别到两个节点的路径,因此最近公共祖先非常重要  
<!--more-->

常规而言,求两个节点的公共祖先的思路是两个节点如果不在同一深度,首先将更深的往上调整到另一个节点的深度,然后两个节点在同步往上走,直到走到同一个节点  

但是这样就有一个问题就是:一步一步走,最坏情况下时间复杂度是`O(n)`  
那么就有了另一个思路:**倍增**  

用 `f[i][j]` 表示节点`i`的<code>2<sup>j</sup></code>辈祖先(比如`f[5][0]`即使节点`5`的父节点)  
![](/post/img/lca.png)
很容易得到递推式 `f[i][j] = f[f[i][j-1][j-1]`  

需要特别注意的是,根据递推式,可以发现应该先循环`j`,再循环`i`  
```cpp
for (int j = 1; j < maxlog; ++j) 
        for (int i = 1; i <= n; ++i) 
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
```
这样可以在`O(nlog(n))`的时间预处理好  

对于`a`和`b`,有`b=a+2^(log(b-a))`  
那么在将两个节点调成深度一致的时候,就可以直接使用`log`倍增  
而之后两个节点同步上升的时候,则可以让他们直接倍增到最后一个两者祖先不相同的幂数  
按照这样查询的时间复杂度是`O(log(n))`  

而对于任意两点之间的距离、路径上最小边之类的内容,只需要在更新节点的时候计算下即可  

模板如下,其中`function(a,b)`是需要维护的值的函数,可以是`max()`,`min()`,`add()`等内容  
```cpp
// function() 是需要维护的值的函数,可以是 max() , min() , add() 等内容  
void dfs(int t, int deep) {
    depth[t] = deep;
    for (auto edge : edges[t]) {
        int child = edge.c;
        if (parent[t][0] != child) {
            parent[child][0] = t;
            weight[child][0] = edge.w;
            dfs(child, deep + 1);
        }
    }
}

void lca() {
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            weight[i][j] = function(weight[i][j - 1], weight[parent[i][j - 1]][j - 1]);
        }
    }
}

int query(int a, int b) {
    int ans = 0;
    if (depth[a] < depth[b])
        swap(a, b);
    while (depth[a] != depth[b]) {
        int dis = depth[a] - depth[b];
        int step = (int)(log(dis) / log(2));
        // 由于这里还要用到a,因此a要在后面再赋值
        ans = function(ans, weight[a][step]); 
        a = parent[a][step];
    }

    while (a != b) {
        int step = 0;
        for (int i = 0; i < maxlog; ++i) {
            if (parent[a][i] == parent[b][i]) {
                step = i - (i ? 1 : 0);
                break;
            }
        }

        ans = function(ans, function(weight[a][step], weight[b][step]));
        a = parent[a][step];
        b = parent[b][step];
    }
    return ans;
}
```