---
title: 拓扑排序
date: 2016-06-07 17:13:18
categories: 算法
tags:
 - 拓扑排序
 - 排序
---

{% blockquote 百度百科 http://baike.baidu.com/view/288212.htm 拓扑排序 %}  
对一个有向无环图(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，使得图中任意一对顶点u和v，若边(u,v)∈E(G)，则u在线性序列中出现在v之前。  
通常，这样的线性序列称为满足拓扑次序(Topological Order)的序列，简称拓扑序列。  
简单的说，由某个集合上的一个偏序得到该集合上的一个全序，这个操作称之为拓扑排序。  
{% endblockquote %}  

<!--more-->
<br>
举一个例子就是
> 学习《数据结构》前我们需要学习《C语言》  
> 学习《高数2》前我们需要学习《高数1》  
> 如何安排学习顺序？  

我们有以下学习顺序：
* 《高数1》 -> 《高数2》 -> 《C语言》 -> 《数据结构》
* 《高数1》 -> 《C语言》 -> 《数据结构》 -> 《高数2》
* 《高数1》 -> 《C语言》 -> 《高数2》 -> 《数据结构》 
* ……

这种有着先行条件的排序就是拓扑排序。  
只有满足了先行条件，我们才能进行任务(到达结点)  
因此可以看作有向图  
同时，可以简单证明，如果存在环(`1->2`、`2->1`)  
显然是无解的。  

对于拓扑排序，我们可以看成有向无环图(DAG)  

# 普通的拓扑排序

算法如下:  
1. 找出所有我们可以选择的结点(没有先行条件的结点(源))  
2. 选择一个源，开始拓展。对于每一个访问到的结点，从图中删除这个结点和这个结点指向的边(使以它为先行条件的结点变成源)  
3. 重复以上过程

如果**所有源都访问过后，还有未访问的结点，那么存在环**(因为环中的结点永远无法访问)  


# 带字典序的拓扑排序 

题目:[>吃在工大<](/post/HFUT/1359.html)  

当输出要求输出字典序最大解时，我们可以维护一个优先队列，队首是字典序最大的元素。  

将所有的源放在优先队列里，每次拓展结点从优先队列取出  

代码如下
```cpp
bool G[maxn][maxn];
bool vis[maxn];
int n;

bool HasLoop() {
	//判断是否存在环
	for(int i = 1;i <= n;i++)
		if(!vis[i])
			return false;
	return true;
}

bool IsStart(int k) {
	//判断是否入度为0
	for(int i = 1;i <= n;i++)
		if(G[i][k])
			return false;
	return true;
}


bool TopoSort(int _n,int *ans) {
	//拓扑排序
	/*
	参数:
	邻接矩阵G[][]
	顶点数目n
	用于保存拓扑排序结果的数组 ans[]
	*/
	//输出结果下标初始化
	int pos = 0;

	//已访问数组初始化
	memset(vis,false,sizeof(vis));

	//可被选择的数
	priority_queue<int> Q;

	//判断i是否为源
	for(int i = 1;i <= n;i++) {
		if(IsStart(i))
			Q.push(i);
	}

	while(!Q.empty()) {
		int k = Q.top();
		Q.pop();

		if(vis[k])
			continue;
		else
			vis[k] = true;

		//记录到结果中
		ans[pos++] = k;

		for(int i = 1;i <= n;i++) {
			if(G[k][i]) {
				//路径k~i存在
				//删除路径
				G[k][i] = false;
				//如果成为入度为0的点
				if(IsStart(i))
					Q.push(i);
			}
		}
	}

	//判断是否有环
	return HasLoop();
}
```