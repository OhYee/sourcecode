---
title: 2017安徽省程序设计竞赛培训笔记
date: 2017-01-16 13:39:20
categories: 笔记
tags:
---
2017-1-16 ~ 2017-1-19  
内容:
* [数学(数论 & 组合数学)](/post/Note/2017_Winter_Coding_Training.html#数学-数论-amp-组合数学)
* [数据结构](/post/Note/2017_Winter_Coding_Training.html#数据结构)
* [图论](/post/Note/2017_Winter_Coding_Training.html#图论)
* [动态规划](/post/Note/2017_Winter_Coding_Training.html#动态规划)

<!--more-->
# 数学(数论 & 组合数学)
## 唯一分解定理
每个正整数都可以唯一地表示成素数的乘积.  
即有唯一的分解质因数的方案:  
{% raw %}$x=a_1^{p_1}a_2^{p_2}...a_n^{p_n}${% endraw %}  
根据上面的式子,可以推知 x 共有 $(p_1+1)(p_2+1)...(p_n+1)$ 个约数

## 最大公因数和最小公倍数  
若有  
$x=a_1^{p_1}a_2^{p_2}...a_n^{p_n}$  
$y=a_1^{q_1}a_2^{q_2}...a_n^{q_n}$

则
$gcd(x,y) = a_1^{min(p_1,q_1)}a_2^{min(p_2,q_2)}...a_n^{min(p_n,q_n)}$  
$lcm(x,y) = a_1^{max(p_1,q_1)}a_2^{max(p_2,q_2)}...a_n^{max(p_n,q_n)}$

同时可以很容易得到  
$x \times y = gcd(x,y) \times lcm(x,y)$  

若 
$x = p \times gcd(x,y)$  
$y = q \times gcd(x,y)$  

那么 $x + y = (p+q) \times gcd(x,y)$
可以得到 $gcd(x,y) = gcd(x,x+y)$  

## 欧几里得算法  
`gcd(a,b) = gcd(b,a mod b)`  

证明如下:  
若

$a = p \times c$  
$b = q \times c$  
$a \;  mod \;  b =  a - \left \lfloor \frac{a}{b} \right \rfloor \times b$  
$a \; mod \; b = p \times c - k \times q \times c$   
$a \; mod \; b = (p-kq)c$  
$\therefore gcd(a,b) = gcd(b,a \; mod \; b)$  


之所以要不断交换 `a` `b` 的位置,是为了保证两边都要逐渐减小  


根据这个算法,就可以写出求最小公倍数的算法
```cpp 欧几里得算法
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
```


## 拓展欧几里得算法

对于方程 `ax + by = c`  
有两种情况  
* `gcd(a,b)` 是 `c` 的因子  
  这种情况下,有 $ \frac{a}{gcd(a,b)}x + \frac{b}{gcd(a.b)}= \frac{c}{gcd(a,b)}$  
  有可能存在整数解
* `gcd(a,b)` 不是 `c` 的因子  
  这种情况下,两边同时除以 `gcd(a,b)` 左侧为整数,右侧为小数,不可能存在整数解  

先考虑 `ax+by=gcd(a,b)` 的情况  
当 $b=0$ 时,有 `gcd(a,b)=a` 即  `x=1,y=0`  
当 $b \neq 0$,有 `ax+by=gcd(a,b)`   
根据欧几里得算法 $gcd(a,b) = gcd(b,a \; mod \; b)$  
有 $ax+by = gcd(a,b) = gcd(b,a \; mod \; b)$  
$bx′+(a−b∗\left \lfloor \frac{a}{b} \right \rfloor)y′ = gcd(b,a \; mod \; b)$  
可化得 $ax+by = bx' + (a \; mod \; b)y' = ay'+b(x'- \lfloor \frac{a}{b} \rfloor y')$  
因此 $\begin{cases}
x=y'\\
y=x'-  \lfloor \frac{a}{b} \rfloor  y'
\end{cases}$  

由于已经知道递归到 `b=0` 时的解,因此可以一步一步得出 `ax+by=gcd(a,b)` 的解  
而对于 `ax+by=kgcd(a,b)` 只需要将 `x` , `y` 同乘 `k` 即可  

下面是对于 `ax+by=gcd(a,b)` 的解   
```cpp 拓展gcd
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
```

## 同余方程

## 中国剩余定理  
对于一元线性同余方程组  
{% raw %}$
\begin{cases}
x \equiv a_1 (mod \; m_1)\\
x \equiv a_2 (mod \; m_2)\\
...\\
x \equiv a_n (mod \; m_n)\\
\end{cases}
${% endraw %}  

其中 $m_1$ 、$m_1$ .... $m_n$ 两两互质  
则对任意整数 $a_1$ 、$a_1$ .... $a_n$ 方程组有解

求解方法如下   
令 
$M=m_1m_2m_3...m_n$  
$M_i=\frac{M}{m_i}$  
$t_i$为$M_i$模$m_i$下的逆元,也即$M_it_i \equiv 1(mod \; m_i)$  

则有  
$x = a_1t_1M_1 + a_2t_2M_2 +  ...  + a_nt_nM_n + kM  \; \; k \in Z$


## Lucas定理

若 `p` 为素数  
$n = n_kp^k + n_{k-1}p^{k-1} + ...+n_1p + n_0$  
$m = m_kp^k + m_{k-1}p^{k-1} + ...+m_1p + m_0$  

则有$C(n,m) = \prod_{i=0}^{k} C(n_i,m_i)(mod \; p)$ 

## 数论的函数 
* $\phi (n)$ : 不大于 n 且与 n 互素的数的个数  
* $\mu (n)$ : 如果 $n=kd^2$, $\mu (n)= 0$, 否则 $\mu(n) = (-1)^k $,其中 k 是 n 的素因子数  

特别地  
{% raw %}
$\sum_{d|n} \phi(d) = n$   
<br/>
$\sum_{d|n} \mu(d) = [n=1]$  
{% endraw %}
 
## 积性函数
$\forall x,y$ 若 $gcd(x,y)=1$ ,则$f(xy)=f(x)f(y)$  
$\phi (x)$和$\mu (x)$都是积性函数  

## 完全积性函数
$\forall x,y$ ,则$f(xy)=f(x)f(y)$  

## Euler筛法
对于积性函数 `f(x)` 可以用 Euler 筛法在 `O(n)` 的时间复杂度内预处理 `f(1)` `f(2)` ... `f(n)` 的值  
若 t 是  x 的最小质因子,那么 `f(x)` 将在枚举到 `x/t` 时用 `f(x/t)` 与 `f(t)` 求出  


## Mobius反演
Dirichlet卷积 
$(f \times g)(n) = \sum_{d|n}f(d)g(\frac{n}{d})$  

如果 `f` , `g` 是积性函数,那么 `f × g` 也是积性函数  
且当 {% raw %}$g(n)  = \sum_{d|n}f(d)${% endraw %} 时  
有 {% raw %}$f(n) = \sum_{d|n} \mu (d) g(\frac{n}{d})${% endraw %}  


## 最大公约数和
{% raw %}$
\begin{align*}
&\sum_{i=1}^{n}gcd(n,i) \\
= &\sum_{i=1}^{n} \sum_{d|i\&d|n}\phi(d) \\
= &\sum_{d|n}\left \lfloor \frac{n}{d} \right \rfloor\phi(d)
\end{align*}
${% endraw %}

<br\>

{% raw %}$
\begin{align*}
&\sum_{i=1}^{n}\sum_{j=1}^{m}gcd(i,j) \\
= &\sum_{i=1}^{n}\sum_{j=1}^{m} \sum_{d|i\&d|n}\phi(d) \\
= &\sum_{d=1}^{min(n,m)}\left \lfloor \frac{n}{d} \right \rfloor \left \lfloor \frac{m}{d} \right \rfloor\phi(d)
\end{align*}
${% endraw %}

## 组合数 
从 n 个数中选 m 个数,每个数最多选一次  
$C(n,m) = \frac{n!}{m!(n-m)!}$  

特别地,  
* `C(n,0) = C(n,n) = 1`
* `C(n,m) = C(n,n-m)`
* `C(n,m) = C(n-1,m-1) + C(n-1,m)`

## 二项式展开

$(x + y)^n = \sum_{i=0}^{n} C(n,i)x^iy^{n-i}$

## 置换

## 置换群
置换作为元素的群  
可以用来描述等价关系  


## Burnside引理
对于一个置换 f ,若方案 s 变回它自己,称它为 f 的不动点  
f 的不动点数目记为 `C(f)`  
等价类数目为所有 `C(f)` 的平均值  

## Polya定理
给 n 种颜色着 k 种颜色,设置换 f 的循环节为 `m(f)` ,则它的不动点数目为 $C(f) = k^{m(f)}$  

----------

# 数据结构

## RMQ问题 
[RMQ问题](/post/Algorithm/RMQ.html) 是范围最小值查询问题  

### 稀疏表(ST算法)
[ST算法](/post/Algorithm/ST.html)  
ST算法是一种解决 RMQ 问题的效率较高的方法  
在不需要更改节点的情况下,可以优先使用ST算法  

### 线段树
[线段树](/post/Algorithm/Segment_tree.html)  
当需要更新节点的时候,就需要使用线段树这种数据结构  
在修改节点时,只需要改变其所在分支上的节点  
在修改区间时,给区间加上tag,在以后用到该区间时,将tag传递给其子节点(`O(log n)`)  

如果线段树上的修改为 **取模** 操作,可以将其化为 **最大值查询+单点修改**  

## 左式堆  
又称左偏树、左倾堆  

* 外部节点（external node）：左子树或右子树为空的节点
* 左偏树节点距离（dis）属性：该节点到最它的后代中最近的外部节点经过的距离
  特别地，外部节点dist = 0
* 左偏树key值满足堆性，左儿子dist>=右儿子dist  

整个树呈现一种左倾的形态,根据这种特性,可以将插入、修改、删除全部以合并不同的左式堆代替  
合并时,优先合并到右支  
```cpp merge
int merge(int u, int v){
    if (!u) return v;
    if (!v) return u;
    if (key[u] < key[v]) swap(u,v);
    r[u] = merge(r[u],v);
    if (dist[r[u]] > dist[l[u]]) swap(r[u], l[u]);
    dist[u] = r[u] > 0 ? dist[r[u]] + 1 : 0;
    return u;
}
```

## 并查集
[并查集](/post/Algorithm/Union_Find.html)  
在一些有N个元素的集合应用问题中,我们通常是在开始时让每个元素构成一个单元素的集合  
然后按一定顺序将属于同一组的元素所在的集合合并,其间要反复查找一个元素在哪个集合中  
这一类问题数据量极大,若用正常的数据结构来描述的话,计算机无法承受  
只能采用一种全新的抽象的特殊数据结构——并查集来描述  

## 带权并查集
顾名思义，就是在维护元素所属集合的同时记录集合的一些信息：  
* 维护集合的最大最小值
* 维护集合的和
* 维护其它的信息
  

## KMP算法
[KMP算法](/post/Algorithm/KMP.html)  
KMP算法是一种字符串匹配算法  
可以快速地找出一个字符串在另一个字符串中第一次出现的位置  

## 字典树(Trie)
字典树是一个26叉树，每次插入一个单词的话就是按照树的插入操作进行  
将每个字母看作一个节点  

## AC自动机
AC 自动机是一种多模匹配算法  
可以简单地将其看作 字典树+KMP算法   

失败指针：AC自动机即在字典树上添加失败指针,这个失败指针与 KMP 的 next 数组类似  

对应关系:   

|KMP|AC自动机|
|:----:|:----:|
|单串|多串|
|原字符串|字典树|
|Next数组|失败指针|

 

  
## 可持久化数据结构
所谓的可持久化数据结构,就是保存这个数据结构的历史版本,同时他们之间公用数据减少时间和空间的消耗  
可用持久化的数据结构：线段树(常见),平衡树,块状链表,块状数组(较少见)等  

**对于线段树的可持久化**  

可持久化线段树常见应用：有修改的区间第k大  

* 单点修改：
  * 修改一个叶子节点
    我们只需要新建一个新的叶子节点就能得到一个当前版本
  * 修改一个非叶子节点.
    两个孩子中最多有一个会被修改,于是递归调用.然后将当前版本复制一遍,另外一个孩子不变,当前孩子为修改后的版本.
* 查询.与线段树一样
* tag标记.遇到一个打了标记的节点,直接下传标记即可,下传的时候新建两个打了标记的节点.

----------
# 图论



----------

# 动态规划