---
title: RMQ问题
date: 2016-08-11 21:37:00
categories: 算法
tags: 
- RMQ问题
- ST算法
- 线段树
- 二分
---
{% blockquote 百度百科 http://baike.baidu.com/view/1536346.htm RMQ 问题 %}
RMQ ( Range Minimum / Maximum Query )问题是指：
> 对于长度为 `n` 的数列 A ，回答若干询问 `RMQ(A,i,j)` ( `i,j<=n` )，返回数列 A 中下标在 `i` , `j` 里的最小(大)值  
> 也就是说，RMQ 问题是指求区间最值的问题  
{% endblockquote %}

<!--more-->

显然,最直观的算法是用 O(n) 的时间找到查询范围内的最值,然后输出  
当查询的次数 `m` 非常大时,时间复杂度是 `O(n*m)`  
很可能是一个非常大的数字  

于是有了一些其他的查询方法:  

1. 预处理区间  
  用 <code>O(n<sup>2</sup>)</code> 的时间进行预处理  
  分别用 `Max[i][j]` 、 `Min[i][j]` 表示 `[i,j]` 的最值  
  预处理时间 <code>O(n<sup>2</sup>)</code>  
  单次查询时间 `O(1)`
  总时间 <code>O(n<sup>2</sup>) + m * O(1)</code>
  显然,当 `n` 比较大时,这种方法并不好  

2. [**>线段树<**](/post/Algorithm/Segment_tree.html)  
  通过二分法,用 `O(logn)` 的时间建树,再用 `O(logn)` 的时间查询  
  总时间 `O(logn) + m * O(logn)`  
  综合来看时间复杂度能够接受,但是由于需要构建二叉树,因此对内存的占用较大  

3. [**>ST算法<**](/post/Algorithm/ST.html)  
  将线段分成一个个 <code>[i,i+2<sup>k</sup>-1]</code> 的区间  
  采用动态规划的方法在 `O(nlogn)` 的时间内预处理  
  采用数学方法,在 `O(1)` 的时间内完成一次查询  
  总时间 `O(nlogn) + m * O(1)`  
  综合时间复杂度较低,并且对内存占用也比较小  
  是解决RMQ问题的最好方法  

