---
title: 强连通分量缩点 — kosaraju | tarjan | gabow
date: 2016-11-06 01:01:07
categories: 算法
tags:
- 强连通分量
- 图论
- kosaraju
- tarjan
- gabow
---
# 强连通分量
如果两个点能够互相到达,那么说明两个点在一个 **强连通分量** (成 **环** )里  
其概念与 [**并查集**](/post/Algorithm/Union_Find.html) 相似  

不同点在于并查集为无向图,直接遍历,只要能访问到就在一个并查集里  
而强连通分量操作的是无向图,需要考虑边的方向  

如图,最左侧的分支不是一个强连通分量,而右两个是  

![Strongly_connected_components](/post/img/strongly_connected_components_1.png)

在许多图的题目里,需要对节点进行 **强连通分量缩点** 从而简化后续操作的复杂度  
缩点后,新的图是一个 **有向无环图(DAG)** ,因此可以使用其他算法进行其他的操作  

强连通分量的算法有 kosaraju tarjan gabow  

找了模板题 [**HDU 1269.迷宫城堡**](/post/HDU/1269.html) 测试写的模板有没有问题

<!--more-->

# Kosaraju
Kosaraju 采用两次 DFS 及一次对逆图的操作从而求解的   

首先 DFS 遍历所有节点,当到头后,将节点入栈,返回 DFS  
遍历完后在逆图(所有边反向)里按照栈的顺序进行 DFS ,将所有能访问到的点删除,加入到当前连通分量里  
直到所有点都被删除  

由于强连通是环,无论图的边如何反向,应该都是能够互相访问的,而不在环里的点是无法访问到的.  
要考虑的额外情况就是逆图里是否会有一个点能访问到和它不是强连通的点  
假设存在这种情况,那么有以下条件:
1. 这两个点单向连通(不连通逆图无法访问)
2. 单向连通的子节点后入栈(这样能在父节点被删除前访问到父节点)

如果两个节点单向连通,有两种情况: 
 1. 先访问到父节点
  父节点能遍历到子节点,父节点会后入栈
 2. 先访问子节点
  子节点在第一次遍历时,无法遍历到父节点,子节点先入栈,同上 

因此,该算法可以实现强连通分量缩点的功能  

步骤如下:
1. DFS 遍历所有节点,当到达终点后入栈
2. 在逆图里按照栈的顺序 DFS 所有节点,将所有能够访问到的点连为一个强连通分量并从图里删除
3. 重复 2 直到所有点被删除  

代码如下:

```cpp Kosaraju
//Kosaraju
const int maxm = 100005;

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];
list<int> L2[maxn];

stack<int> s;
bool vis[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    L2[v].push_back(pos);//逆图

    pos++;
}

void DFS1(int t) {
    if(!vis[t]) {
        vis[t] = true;
        for(list<int>::iterator i = L[t].begin();i != L[t].end();i++)
            DFS1(edge[*i].v);
        s.push(t);
    }
    return;
}

void DFS2(int p,int t) {
    if(vis[t]) {
        vis[t] = false;
        SCC[p].push_back(t);
        for(list<int>::iterator i = L2[t].begin();i != L2[t].end();i++)
            DFS2(p,edge[*i].u);
    }
    return;
}

int Kosaraju(int n) {
    //第一次DFS
    for(int i = 0;i < n;i++)
        DFS1(i);

    //第二次DFS
    int p = 0;
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        list< list<int> >::iterator it;
        if(vis[t])
            DFS2(p++,t);
    }
    return p;
}
```