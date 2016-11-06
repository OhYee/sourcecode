---
title: 线段树
date: 2016-08-11 21:49:23
categories: 算法
tags: 
 - 线段树
 - 树
 - 递归与分治
---
{% blockquote 百度百科 http://baike.baidu.com/view/670683.htm 线段树%}
线段树是一种二叉搜索树，与区间树相似，它将一个区间划分成一些单元区间，每个单元区间对应线段树中的一个叶结点。  
使用线段树可以快速的查找某一个节点在若干条线段中出现的次数，时间复杂度为O(logN）。而未优化的空间复杂度为2N，因此有时需要离散化让空间压缩。  
{% endblockquote %}
<!--more-->
<br> 
对于一棵线段树，其叶节点是长度为1的线段  
如图，是一棵(0,10)的线段树  
![线段树](../img/Segment_tree.png)

<br>
可以看出，叶节点是区间内长度为1的线段的集合  

二叉树的优势在于访问的快速，我们可以在O(logN)的时间内找到我们需要的节点  
因此，借助线段树，我们可以进行高效的线段操作。 



# 最简单的线段树
简单的线段树只需要实现快速获取一个区间的最大值或者最小值等数据即可  

**代码根据 [AOJ 351.求最值之差](/post/AOJ/351.html) 编写**   

## 结构定义
首先线段树是一棵二叉树,他应该有二叉树基本的数据
```cpp
struct Tree{
	int l,r;
	int n;
};
```

`l` 和 `r` 是线段树的两个端点  
`n` 是线段树的这个结点存储的数值,可以根据具体需要更改  

## 建树
首先需要根据数据建立线段树  
采用 **递归与分治** 的思想递归建树  
`compare` 是函数指针,可以是 `max` 或者 `min` 用于确定是要最大值还是最小值  
这样就构建好了一棵线段树  
```cpp 建树  
int BuildTree(int a,int b,int (*compare)(int,int),int* num,Tree *T,int pos = 1) {
    T[pos].l = a;
    T[pos].r = b;
    if(b - a == 1)
        return T[pos].n = compare(num[a],num[b]);
 
    int mid = (a + b) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;
 
    T[pos].n = compare(
        BuildTree(a,mid,compare,num,T,leftchild),
        BuildTree(mid,b,compare,num,T,rightchild)
    );
}
```

## 查询
线段树的查询只需要判断区间关系即可  
如果正好是当前访问的区间,那么直接返回结果即可  
如果完全在当前区间的一侧,则递归返回  
如果跨越区间中点,则分别取两侧的最值然后比较返回即可  

```cpp 查询
int GetNum(int a,int b,int(*compare)(int,int),int* num,Tree *T,int pos = 1) {
    if(a == b)
        return num[a];
 
    int &l = T[pos].l;
    int &r = T[pos].r;
 
    if(a == l && b == r)
        return T[pos].n;
 
    int mid = (l + r) / 2;
    int leftchild = 2 * pos;
    int rightchild = 2 * pos + 1;
 
    if(b <= mid)
        return GetNum(a,b,compare,num,T,leftchild);
    if(a >= mid)
        return GetNum(a,b,compare,num,T,rightchild);
 
    return T[pos].n = compare(
        GetNum(a,mid,compare,num,T,leftchild),
        GetNum(mid + 1,b,compare,num,T,rightchild)
    );
}
```