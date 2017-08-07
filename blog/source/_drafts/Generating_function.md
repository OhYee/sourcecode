---
title: 母函数
date: 2016-08-16 11:38:52
categories: 算法
tags: 
- 母函数
- 数学
---
{% blockquote 百度百科 http://baike.baidu.com/view/2415279.htm 母函数 %}
生成函数即母函数,是组合数学中尤其是计数方面的一个重要理论和工具  
生成函数有普通型生成函数和指数型生成函数两种,其中普通型用的比较多  
形式上说,普通型生成函数用于解决多重集的组合问题,而指数型母函数用于解决多重集的排列问题  
母函数还可以解决递归数列的通项问题(例如使用母函数解决斐波那契数列的通项公式)  
{% endblockquote %}
<!--more-->

------
# 多项式的展开
对于多项式  
<code>(1+x) \* (1+x<sup>2</sup>) \* (1+x<sup>3</sup>) \* (1+x<sup>4</sup>)</code>  
可以将其展开成  
<code>1 + x + x<sup>2</sup> + 2\*x<sup>3</sup> + 2\*x<sup>4</sup> + 2\*x<sup>5</sup> + 2\*x<sup>6</sup> + 2*x<sup>7</sup> + x<sup>8</sup> + x<sup>9</sup> + x<sup>10</sup> </code>  

展开后的每一项的系数和次数都和原式有着对应的关系  

一个 `(1+x)` 只能到 `(1+x)`  
而 <code>(1+x) \* (1+x<sup>2</sup>)</code> 则可以得到 <code> 1 + x + x<sup>2</sup> + x<sup>3</sup> </code>  
<code> (1+x) \* (1+x<sup>2</sup>) \* (1+x<sup>3</sup>) </code> 可以得到 <code> 1 + x + x<sup>2</sup> + 2 \* x<sup>3</sup> + x<sup>4</sup> + x<sup>5</sup> + x<sup>6</sup> </code> 

仔细在拆分的过程就可以发现: **每一项都是由次数不比它大的项 "贡献" 来的**  

`x` 来自于 `(1+x)`  
<code>x<sup>2</sup></code> 来自于 <code>(1+x<sup>2</sup>)</code>  
<code>x<sup>3</sup></code> 来自于 <code>(1+x) \* (1+x<sup>2</sup>)</code>  
<code>x<sup>3</sup></code> 来自于 <code>(1+x) \* (1+x<sup>2</sup>)</code> 
……  


-------

当给式子中的数字赋予实际含义时,就可以用它来解决许多问题  

# 例一 (01背包问题)  
<br>
> 有1克、2克、3克、4克的砝码各一枚,能称出哪几种重量?每种重量各有几种可能方案?  

先考虑简单点的情况:
- 如果只有 `1` 克的砝码
  显然只能称出 `1` 克  
  共有 `1` 种方案  
- 如果有 `1` 克和 `2` 克  
  能够称量出 `1` 克, `2` 克,和 `3` 克  
  并且每种方案数都是 `1`  
- 如果有 `1` 克、 `2` 克和 `3` 克  
  能够称量出 `1` 克、 `2` 克、 `3` 克、`4` 克、 `5` 克和 `6` 克  
  除了 `3` 克是 `2` 种方案,其他都是 `1` 种方案  

到这里应该已经看出来一些规律了,这正好和上面的式子产生了对应关系  

有 `1` 个 `k` 克的砝码,就相当有有一个 <code>1 + x<sup>k</sup></code>  
而答案中的 <code>a * x<sup>k</sup></code> 表示有 `a` 种方案组成 `k` 克  

那么按照最前面的式子,就可以轻松得到答案  
> 共能称出 1、2、3、4、5、6、7、8、9、10 这 10 种重量  
> 每种重量对应的方案数分别为 1、1、2、2、2、2、2、1、1、1

用母函数的思路来解答,就是:
**<span style="color:#66ccff">G(x) = (1+x) \* (1+x<sup>2</sup>) \* (1+x<sup>3</sup>) \* (1+x<sup>4</sup>)</span>**  

<span style="color:red">
很容易将这种问题联系到 **背包问题** 上  
而 **背包问题** 最重要的在于 "选" 和 "不选" 两种状态  
拿 1 + x<sup>2</sup> 来说  
可以将其看成 1 \* x<sup>0</sup> + 1 \* x<sup>2</sup>  
也即 **选择重量为 0 的砝码(不选)** 和 **选择重量为 2 的砝码(选)**  
</span>

再结合展开时的具体操作,应该很容易就能明白具体的原理  


再看一道题  
# 例二 (完全背包问题)  
<br>
> 求用1分、2分、3分的邮票贴出不同数值的方案数  

与例一不同的地方在于,每种邮票的个数是无限的(完全背包问题)  
但是无论如何,解法都相同  
**<span style="color:#66ccff">G(x) = (1+x+x<sup>2</sup>+....) (1+x<sup>2</sup>+x<sup>4</sup>+....) (1+x<sup>3</sup>+x<sup>6</sup>+...)</span>**  

当然,如果非要写成上米俺的形式也可以写成这样  
**<span style="color:#66ccff">G(x) = (1+x)(1+x)…… (1+x<sup>2</sup>)(1+x<sup>2</sup>)…… (1+x<sup>3</sup>)(1+x<sup>3</sup>)……</span>**  

# 例三 (斐波那契数列)
<br>
> 使用母函数求出斐波那契数列的通项公式
> Fib(n)=Fib(n-1)+Fib(n-2),这里假设Fib(1)=1,Fib(2)=1

知网的东西貌似不能随便上传到网上,有兴趣的用学校校园网登知网自己去看下吧  

**资料来源**:
> 【作者】 李文捷；
> 【Author】 LI Wen-jie
> 【机构】 安徽师范大学；
> 【摘要】 递推数列的通项公式的求解近年来吸引了许多数学工作者的注意,目前已经出现了诸如数学归纳法、特征方程法、待定系数法等求解方法。受齐次线性微分方程的母函数解法的启发,研究人员利用母函数,力图寻找出著名的斐波那契数列通项公式的一种新的求解方法. 
> 【关键词】 递推数列； 母函数； 通项公式； 
> 【所属期刊栏目】 工程 科技研究 （2012年01期）


 ![](/post/img/Generating_function.png)

# 例四 (德.梅其里亚克称重问题)
<br>
> 重为a1,a2,a3.....ak的砝码,如何放在天平的两端

记可称重量为n的物体的不同方式为Cn,则Cn的母函数为:
**<span style="color:#66ccff">G(x) = (x - a<sub>1</sub> + 1 + x \* a<sub>1</sub>)(x - a<sub>2</sub> + 1 + x \* a<sub>2</sub>).........(x-a<sub>k</sub>+1+x \* a<sub>k</sub>)</span>**
<code>x - a<sub>1</sub></code> 表示砝码 <code>a<sub>1</sub></code> 和物体放在同一个托盘内  
<code>x * a<sub>1</sub></code> 表示砝码和物体放在不同的托盘内  
`1` 则为不用这个砝码  

> 重为a1,a2,a3....ak的砝码,如只可以放在天平的一端

记可称重量为n的物体的不同方式为Cn,则Cn的母函数为：
**<span style="color:#66ccff">G(x) = (1 + x \* a<sub>1</sub>)(1 + x \* a<sub>2</sub>).........(1 + x \* a<sub>k</sub>)</span>**

# 例五 (数的划分)
<br>
> 将整数分解为若干个整数(相当于将n个苹果放在n个无区别的盘子里,每个盘子可以放多个,也可以不放)  

假设 `1` 出现的次数为记为 <code>a<sub>1</sub></code>, `2` 出现的次数记为 <code>a<sub>2</sub></code>......... `k` 出现的次数记为 <code>a<sub>k</sub></code>  
那么生成函数为:
**<span style="color:#66ccff">G(x) = (1+x+x<sup>2</sup>+x<sup>3</sup>+x<sup>4</sup>+.....)(1+x<sup>2</sup>+x<sup>4</sup>+x<sup>6</sup>+x<sup>8</sup>+......)(1+x<sup>3</sup>+x<sup>6</sup>+x<sup>9</sup>+....)........(1+x<sup>n</sup>)</span>**
前面的 <code>1+x<sup>2</sup>+x<sup>4</sup>+x<sup>6</sup>+x<sup>8</sup>+......</code> 意思是当出现一个 `2` 时为 <code>x<sup>2</sup></code>,当出现两个 `2` 时为 <code>x<sup>4</sup></code>.....  
为什么当出现 `n` 时,只有两项 <code>(1+x<sup>n</sup>)</code> ,因为是将数 `n` 划分为若干项,所以不能超过该数,且由数 `1` 到 `n` 项数依次要 `<=n/k (k=1.2,3,4...n)`  



# 参考资料:
1. [**母函数（Generating function）详解 — TankyWoo** *http://www.wutianqi.com/?p=596*](http://www.wutianqi.com/?p=596)
2. [**母函数 - 许增强的CSDN博客** *http://blog.csdn.net/xuzengqiang/article/details/7464337*](http://blog.csdn.net/xuzengqiang/article/details/7464337)