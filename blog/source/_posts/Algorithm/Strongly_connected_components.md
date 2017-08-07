---
title: 强连通分量缩点 — Kosaraju | Tarjan | Gabow
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

# Tarjan

Tarjan 是求强连通分量的一种非常常用的方法,其依据是 DFS 的遍历的顺序  

不难得出,一个含环有向图,从一个节点开始遍历,环必然存在在第一个被遍历的环的子树上  
如最前面的图里,每一个环都存在于一个子树中  
而环的这棵树的最大的不同就是他能够回到已经访问过的节点上  

首先看一颗有向的树,首先对树进行遍历,并且记录下访问该节点(u)的时间(次序)  
将节点(u)压入栈内,然后开始遍历它的子节点(v)  
找到该节点(u)到树根上尽可能上的节点(更早遍历)  
(下面所有重新标记节点的行为都是为了这一步)  

有以下情况:
- 子节点(v)已访问过,并且在栈里
 非常显然,该节点(u)可以回到他的某一祖宗(v)处,从祖宗节点(v)到该节点(u)中间的所有节点可以连成环  
 将该节点(u)的访问时间标记为 **重新标记为该环最小的时间(缩点)**
- 子节点(v)已访问过,不在栈里
 无法连成环,一个节点的两棵子树间的单向边(图中 3 和 4 的关系)
- 子节点(v)未访问过
 继续 DFS 遍历该子节点(v)  
 遍历完该子节点(v)的所有子节点后,尝试**缩点**
 将该节点(u)的时间标记 **重新标记为该节点(u)与子节点(v)时间标记的最小值**
 (如果需要修改就证明它的 **某个后代节点和它的祖宗节点有连接** )

遍历完该节点(u)的子节点,就可以判断该节点是否在环里了  
如果该节点的标记被修改过,那么显然这个节点不可能是含环子树最顶部的节点  
而如果没有被修改过,那么就说明这个节点是环顶部的节点(有可能只有它一个,单独的强连通分量)  
由于 DFS 在树上有着天然的顺序,因此栈顶一直到该节点中间所有的节点都在这个环里  
直接记录即可  

其中需要考虑的特殊情况有如图的两种情况  
<img width=30% height=30% src='/post/img/strongly_connected_components_2.png' align='right' />

- 2,3之间是双向箭头(互相指向)  
 根据上面的思路,这时两个点已经缩成一个点, **3 不会出栈(时间标记改变)**  
- 2,3之间是单向箭头
 不存在环的关系,因此不会改变时间节点,**3 访问后出栈**  

这样,无论如何,都不会影响后面的结果,不过 4 和 1,2 等祖宗节点是否成环,都不会影响结果  
因此,该算法成立  

最后要考虑的就是所有节点分成了多棵树的情况,遍历下所有点全部进行 DFS 即可(已经访问过自然不用再管了)  


```cpp Tarjan
//Tarjan 返回强连通分量个数
//节点从0开始,记得初始化变量

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];

stack<int> s;
bool inStack[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表
int cnt,Index;
int DFN[maxn],Low[maxn];

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    pos++;
}

void tarjan(int u) {
    if(DFN[u] != -1)
        return;

    DFN[u] = Low[u] = ++Index;
    s.push(u);
    inStack[u] = true;

    for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
        int v = edge[*it].v;

        if(DFN[v] == -1) {
            tarjan(v);
            Low[u] = min(Low[u],Low[v]);
        } else if(inStack[v]) {
            Low[u] = min(Low[u],DFN[v]);
        }

    }
    if(DFN[u] == Low[u]) {
        int v = s.top();
        s.pop();
        inStack[v] = false;

        SCC[cnt++].push_back(v);

        while(u != v) {
            v = s.top();
            s.pop();
            inStack[v] = false;

            SCC[cnt - 1].push_back(v);
        }
    }
}

int Tarjan(int n) {
    cnt = 0;
    Index = 0;
    while(!s.empty())s.pop();
    memset(inStack,false,sizeof(inStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));

    for(int i = 0;i < n;i++)
        tarjan(i);
    return cnt;
}
```

# Gabow  
Gabow 算法可以理解成是 Tarjan 算法的改良,将 stack 改成数组,其他思路一样  
只错了常量的时间,不再看了