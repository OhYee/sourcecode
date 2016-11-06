---
title: 代码优化方案
date: 2015-08-22 18:57:00
tags:
categories: 笔记
---
<blockquote>
<h3><strong>转载自：<a href="http://www.uml.org.cn/c++/200811103.asp#_Toc110958704" target="_blank">http://www.uml.org.cn/c++/200811103.asp#_Toc110958704</a></strong></h3>
</blockquote>
<h3><strong>1、选择合适的算法和数据结构</strong></h3>
<p>选择一种合适的数据结构很重要，如果在一堆随机存放的数中使用了大量的插入和删除指令，那使用链表要快得多。数组与指针语句具有十分密切的关系，一般来说，指针比较灵活简洁，而数组则比较直观，容易理解。对于大部分的编译器，使用指针比使用数组生成的代码更短，执行效率更高。</p>
<p>在许多种情况下，可以用指针运算代替数组索引，这样做常常能产生又快又短的代码。与数组索引相比，指针一般能使代码速度更快，占用空间更少。使用多维数组时差异更明显。下面的代码作用是相同的，但是效率不一样�</p>
<table style="height: 44px; width: 612px;" border="0">
<tbody>
<tr>
<td style="border: 1px solid #000000;">数组索引</td>
<td style="border: 1px solid #000000;">指针运算</td>
</tr>
<tr>
<td style="border: 1px solid #000000;">
<p>&nbsp;For(;;){</p>
<p>&nbsp;&nbsp;&nbsp; A=array[t++];</p>
<p>&nbsp;&nbsp;</p>
<p>&nbsp;&nbsp; &nbsp;。。。。。。。。。</p>
<p>&nbsp;&nbsp;&nbsp; }</p>
<p>&nbsp;</p>
</td>
<td style="border: 1px solid #000000;">
<p>p=array</p>
<p>&nbsp; for(;;){</p>
<p>&nbsp; &nbsp; a=*(p++);</p>
<p>&nbsp;&nbsp; &nbsp;。。。。。。。。。</p>
<p>&nbsp;&nbsp;&nbsp; }</p>
</td>
</tr>
</tbody>
</table>
<p>&nbsp;</p>
<p>指针方法的优点是，array的地址每次装入地址p后，在每次循环中只需对p增量操作。在数组索引方法中，每次循环中都必须根据t值求数组下标的复杂运算。</p>
<h3><strong>2、使用尽量小的数据类型</strong></h3>
<p>能够使用字符型(char)定义的变量，就不要使用整型(int)变量来定义；能够使用整型变量定义的变量就不要用长整型(long int)，能不使用浮点型(float)变量就不要使用浮点型变量。当然，在定义变量后不要超过变量的作用范围，如果超过变量的范围赋值，C编译器并不报错，但程序运行结果却错了，而且这样的错误很难发现。</p>
<p>在ICCAVR中，可以在Options中设定使用printf参数，尽量使用基本型参数(%c、%d、%x、%X、%u和%s格式说明符)，少用长整型参数(%ld、%lu、%lx和%lX格式说明符)，至于浮点型的参数(%f)则尽量不要使用，其它C编译器也一样。在其它条件不变的情况下，使用%f参数，会使生成的代码的数量增加很多，执行速度降低。</p>
<h3><strong>3、减少运算的强度</strong></h3>
<p><strong>（1）、查表(游戏程序员必修课)</strong></p>
<p>一个聪明的游戏大虾，基本上不会在自己的主循环里搞什么运算工作，绝对是先计算好了，再到循环里查表。看下面的例子：</p>
<p>旧代码：</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">long</span> factorial(<span style="color: #0000ff;">int</span><span style="color: #000000;"> i)

    {

        </span><span style="color: #0000ff;">if</span> (i == <span style="color: #800080;">0</span><span style="color: #000000;">)

            </span><span style="color: #0000ff;">return</span> <span style="color: #800080;">1</span><span style="color: #000000;">;

        </span><span style="color: #0000ff;">else</span>

            <span style="color: #0000ff;">return</span> i * factorial(i - <span style="color: #800080;">1</span><span style="color: #000000;">);

    }</span></pre>
</div>
<p>&nbsp;</p>
<p>新代码：</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">static</span> <span style="color: #0000ff;">long</span> factorial_table[] =<span style="color: #000000;">

        {</span><span style="color: #800080;">1</span>， <span style="color: #800080;">1</span>， <span style="color: #800080;">2</span>， <span style="color: #800080;">6</span>， <span style="color: #800080;">24</span>， <span style="color: #800080;">120</span>， <span style="color: #800080;">720</span>  <span style="color: #008000;">/*</span><span style="color: #008000;"> etc </span><span style="color: #008000;">*/</span><span style="color: #000000;"> };

    </span><span style="color: #0000ff;">long</span> factorial(<span style="color: #0000ff;">int</span><span style="color: #000000;"> i)

    {

        </span><span style="color: #0000ff;">return</span><span style="color: #000000;"> factorial_table[i];

    }</span></pre>
</div>
<p>&nbsp;</p>
<p>如果表很大，不好写，就写一个init函数，在循环外临时生成表格。</p>
<p><strong>（2）、求余运算</strong></p>
<p>&nbsp;<span class="cnblogs_code"> a=a%<span style="color: #800080;">8</span>;</span>&nbsp;</p>
<p>可以改为：</p>
<p>&nbsp;<span class="cnblogs_code"> a=a&amp;<span style="color: #800080;">7</span>;</span>&nbsp;</p>
<p>说明：位操作只需一个指令周期即可完成，而大部分的C编译器的&ldquo;%&rdquo;运算均是调用子程序来完成，代码长、执行速度慢。通常，只要求是求2n方的余数，均可使用位操作的方法来代替。</p>
<p><strong>（3）、平方运算</strong></p>
<p>&nbsp;<span class="cnblogs_code">a=pow(a, <span style="color: #800080;">2.0</span>);</span>&nbsp;</p>
<p>可以改为：</p>
<p>&nbsp;<span class="cnblogs_code">a=a*a;</span>&nbsp;</p>
<p>说明：在有内置硬件乘法器的单片机中(如51系列)，乘法运算比求平方运算快得多，因为浮点数的求平方是通过调用子程序来实现的，在自带硬件乘法器的AVR单片机中，如ATMega163中，乘法运算只需2个时钟周期就可以完成。既使是在没有内置硬件乘法器的AVR单片机中，乘法运算的子程序比平方运算的子程序代码短，执行速度快。</p>
<p>如果是求3次方，如：</p>
<p>&nbsp;<span class="cnblogs_code">a=pow(a，<span style="color: #800080;">3</span>。<span style="color: #800080;">0</span>);</span>&nbsp;</p>
<p>更改为：</p>
<p>&nbsp;<span class="cnblogs_code">a=a*a*a；</span>&nbsp;</p>
<p>则效率的改善更明显。</p>
<p><strong>（4）、用移位实现乘除法运算</strong></p>
<p>&nbsp;<span class="cnblogs_code"> a=a*<span style="color: #800080;">4</span><span style="color: #000000;">; b</span>=b/<span style="color: #800080;">4</span>;</span>&nbsp;</p>
<p>可以改为：</p>
<p>&nbsp;<span class="cnblogs_code"> a=a&lt;&lt;<span style="color: #800080;">2</span><span style="color: #000000;">; b</span>=b&gt;&gt;<span style="color: #800080;">2</span>;</span>&nbsp;</p>
<p>通常如果需要乘以或除以2n，都可以用移位的方法代替。在ICCAVR中，如果乘以2n，都可以生成左移的代码，而乘以其它的整数或除以任何数，均调用乘除法子程序。用移位的方法得到代码比调用乘除法子程序生成的代码效率高。实际上，只要是乘以或除以一个整数，均可以用移位的方法得到结果，如：</p>
<p>&nbsp;<span class="cnblogs_code"> a=a*<span style="color: #800080;">9</span></span>&nbsp;</p>
<p>可以改为：</p>
<p>&nbsp;<span class="cnblogs_code">a=(a&lt;&lt;<span style="color: #800080;">3</span>)+a</span>&nbsp;</p>
<p>采用运算量更小的表达式替换原来的表达式，下面是一个经典例子:</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre>    x = w % <span style="color: #800080;">8</span><span style="color: #000000;">;

    y </span>= pow(x， <span style="color: #800080;">2.0</span><span style="color: #000000;">);

    z </span>= y * <span style="color: #800080;">33</span><span style="color: #000000;">;

    </span><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>;i &lt; MAX;i++<span style="color: #000000;">)

    {

        h </span>= <span style="color: #800080;">14</span> *<span style="color: #000000;"> i;

        printf(</span><span style="color: #800000;">"</span><span style="color: #800000;">%d</span><span style="color: #800000;">"</span><span style="color: #000000;">， h);

    }</span></pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre>    x = w &amp; <span style="color: #800080;">7</span>;              <span style="color: #008000;">/*</span><span style="color: #008000;"> 位操作比求余运算快</span><span style="color: #008000;">*/</span><span style="color: #000000;">

    y </span>= x * x;               <span style="color: #008000;">/*</span><span style="color: #008000;"> 乘法比平方运算快</span><span style="color: #008000;">*/</span><span style="color: #000000;">

    z </span>= (y &lt;&lt; <span style="color: #800080;">5</span>) + y;          <span style="color: #008000;">/*</span><span style="color: #008000;"> 位移乘法比乘法快 </span><span style="color: #008000;">*/</span>

    <span style="color: #0000ff;">for</span> (i = h = <span style="color: #800080;">0</span>; i &lt; MAX; i++<span style="color: #000000;">)

    {

        h </span>+= <span style="color: #800080;">14</span>;                <span style="color: #008000;">/*</span><span style="color: #008000;"> 加法比乘法快 </span><span style="color: #008000;">*/</span><span style="color: #000000;">

        printf(</span><span style="color: #800000;">"</span><span style="color: #800000;">%d</span><span style="color: #800000;">"</span><span style="color: #000000;">，h);

}</span></pre>
</div>
<p>&nbsp;</p>
<p><strong>（5）、避免不必要的整数除法</strong></p>
<p>整数除法是整数运算中最慢的，所以应该尽可能避免。一种可能减少整数除法的地方是连除，这里除法可以由乘法代替。这个替换的副作用是有可能在算乘积时会溢出，所以只能在一定范围的除法中使用。</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">int</span><span style="color: #000000;"> , j, k, m;

m </span>= i / j / k;</pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">int</span><span style="color: #000000;"> i， j, k, m;

m </span>= i / (j * k);</pre>
</div>
<p>&nbsp;</p>
<p><strong>（6）、使用增量和减量操作符</strong></p>
<p>在使用到加一和减一操作时尽量使用增量和减量操作符，因为增量符语句比赋值语句更快，原因在于对大多数CPU来说，对内存字的增、减量操作不必明显地使用取内存和写内存的指令，比如下面这条语句：</p>
<p>&nbsp;<span class="cnblogs_code">x=x+<span style="color: #800080;">1</span>;</span>&nbsp;</p>
<p>模仿大多数微机汇编语言为例，产生的代码类似于：</p>
<div class="cnblogs_Highlighter">
<pre class="brush:as3;gutter:false;">move A，x      ;把x从内存取出存入累加器A

add A，1        ;累加器A加1

store x          ;把新值存回x
</pre>
</div>
<p>　　</p>
<p>如果使用增量操作符，生成的代码如下：</p>
<p>&nbsp;<span class="cnblogs_code">incr x ;x加1</span>&nbsp;</p>
<p>显然，不用取指令和存指令，增、减量操作执行的速度加快，同时长度也缩短了。</p>
<p><strong>（7）、使用复合赋值表达式</strong></p>
<p>复合赋值表达式(如a-=1及a+=1等)都能够生成高质量的程序代码。</p>
<p><strong>（8）、提取公共的子表达式</strong></p>
<p>在某些情况下，C++编译器不能从浮点表达式中提出公共的子表达式，因为这意味着相当于对表达式重新排序。需要特别指出的是，编译器在提取公共子表达式前不能按照代数的等价关系重新安排表达式。这时，程序员要手动地提出公共的子表达式（在VC.NET里有一项&ldquo;全局优化&rdquo;选项可以完成此工作，但效果就不得而知了）。</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， d， e， f；

。。。

e </span>= b * c /<span style="color: #000000;"> d；

f </span>= b / d * a；</pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， d， e， f；

。。。

</span><span style="color: #0000ff;">const</span> <span style="color: #0000ff;">float</span> t(b /<span style="color: #000000;"> d)；

e </span>= c *<span style="color: #000000;"> t；

f </span>= a * t；</pre>
</div>
<p>&nbsp;</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， e， f；

。。。

e </span>= a /<span style="color: #000000;"> c；

f </span>= b / c；</pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， e， f；

。。。

</span><span style="color: #0000ff;">const</span> <span style="color: #0000ff;">float</span> t(<span style="color: #800080;">1.0f</span> /<span style="color: #000000;"> c)；

e </span>= a *<span style="color: #000000;"> t；

f </span>= b * t；</pre>
</div>
<p>&nbsp;</p>
<h3><strong>4、结构体成员的布局</strong></h3>
<p>很多编译器有&ldquo;使结构体字，双字或四字对齐&rdquo;的选项。但是，还是需要改善结构体成员的对齐，有些编译器可能分配给结构体成员空间的顺序与他们声明的不同。但是，有些编译器并不提供这些功能，或者效果不好。所以，要在付出最少代价的情况下实现最好的结构体和结构体成员对齐，建议采取下列方法：</p>
<p><strong>（1）按数据类型的长度排序</strong></p>
<p>把结构体的成员按照它们的类型长度排序，声明成员时把长的类型放在短的前面。编译器要求把长型数据类型存放在偶数地址边界。在申明一个复杂的数据类型 (既有多字节数据又有单字节数据) 时，应该首先存放多字节数据，然后再存放单字节数据，这样可以避免内存的空洞。编译器自动地把结构的实例对齐在内存的偶数边界。</p>
<p><strong>（2）把结构体填充成最长类型长度的整倍数</strong></p>
<p>把结构体填充成最长类型长度的整倍数。照这样，如果结构体的第一个成员对齐了，所有整个结构体自然也就对齐了。下面的例子演示了如何对结构体成员进行重新排序：</p>
<p>不好的代码，普通顺序：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">struct</span><span style="color: #000000;">

{

</span><span style="color: #0000ff;">char</span> a[<span style="color: #800080;">5</span><span style="color: #000000;">]；

</span><span style="color: #0000ff;">long</span><span style="color: #000000;"> k；

</span><span style="color: #0000ff;">double</span><span style="color: #000000;"> x；

} baz；</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码，新的顺序并手动填充了几个字节：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">struct</span><span style="color: #000000;">

{

</span><span style="color: #0000ff;">double</span><span style="color: #000000;"> x；

</span><span style="color: #0000ff;">long</span><span style="color: #000000;"> k；

</span><span style="color: #0000ff;">char</span> a[<span style="color: #800080;">5</span><span style="color: #000000;">]；

</span><span style="color: #0000ff;">char</span> pad[<span style="color: #800080;">7</span><span style="color: #000000;">]；

} baz；</span></pre>
</div>
<p>&nbsp;</p>
<p>这个规则同样适用于类的成员的布局。</p>
<p><strong>（3）按数据类型的长度排序本地变量</strong></p>
<p>当编译器分配给本地变量空间时，它们的顺序和它们在源代码中声明的顺序一样，和上一条规则一样，应该把长的变量放在短的变量前面。如果第一个变量对齐了，其它变量就会连续的存放，而且不用填充字节自然就会对齐。有些编译器在分配变量时不会自动改变变量顺序，有些编译器不能产生4字节对齐的栈，所以4字节可能不对齐。下面这个例子演示了本地变量声明的重新排序：</p>
<p>不好的代码，普通顺序</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">short</span><span style="color: #000000;"> ga， gu， gi；

</span><span style="color: #0000ff;">long</span><span style="color: #000000;"> foo， bar；

</span><span style="color: #0000ff;">double</span> x， y， z[<span style="color: #800080;">3</span><span style="color: #000000;">]；

</span><span style="color: #0000ff;">char</span><span style="color: #000000;"> a， b；

</span><span style="color: #0000ff;">float</span> baz；</pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码，改进的顺序</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">double</span> z[<span style="color: #800080;">3</span><span style="color: #000000;">]；

</span><span style="color: #0000ff;">double</span><span style="color: #000000;"> x， y；

</span><span style="color: #0000ff;">long</span><span style="color: #000000;"> foo， bar；

</span><span style="color: #0000ff;">float</span><span style="color: #000000;"> baz；

</span><span style="color: #0000ff;">short</span> ga， gu， gi； </pre>
</div>
<p>&nbsp;</p>
<p><strong>（4）把频繁使用的指针型参数拷贝到本地变量</strong></p>
<p>避免在函数中频繁使用指针型参数指向的值。因为编译器不知道指针之间是否存在冲突，所以指针型参数往往不能被编译器优化。这样数据不能被存放在寄存器中，而且明显地占用了内存带宽。注意，很多编译器有&ldquo;假设不冲突&rdquo;优化开关（在VC里必须手动添加编译器命令行/Oa或/Ow），这允许编译器假设两个不同的指针总是有不同的内容，这样就不用把指针型参数保存到本地变量。否则，请在函数一开始把指针指向的数据保存到本地变量。如果需要的话，在函数结束前拷贝回去。</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #008000;">//</span><span style="color: #008000;"> 假设 q != r</span>

<span style="color: #0000ff;">void</span> isqrt(unsigned <span style="color: #0000ff;">long</span> a， unsigned <span style="color: #0000ff;">long</span>* q， unsigned <span style="color: #0000ff;">long</span>*<span style="color: #000000;"> r)

{

　　</span>*q =<span style="color: #000000;"> a；

　　</span><span style="color: #0000ff;">if</span> (a &gt; <span style="color: #800080;">0</span><span style="color: #000000;">)

　　{

　　　　</span><span style="color: #0000ff;">while</span> (*q &gt; (*r = a / *<span style="color: #000000;">q))

　　　　{

　　　　　　</span>*q = (*q + *r) &gt;&gt; <span style="color: #800080;">1</span><span style="color: #000000;">；

　　　　}

　　}

　　</span>*r = a - *q * *<span style="color: #000000;">q；

}</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #008000;">//</span><span style="color: #008000;"> 假设 q != r</span>

<span style="color: #0000ff;">void</span> isqrt(unsigned <span style="color: #0000ff;">long</span> a， unsigned <span style="color: #0000ff;">long</span>* q， unsigned <span style="color: #0000ff;">long</span>*<span style="color: #000000;"> r)

{

　　unsigned </span><span style="color: #0000ff;">long</span><span style="color: #000000;"> qq， rr；

　　qq </span>=<span style="color: #000000;"> a；

　　</span><span style="color: #0000ff;">if</span> (a &gt; <span style="color: #800080;">0</span><span style="color: #000000;">)

　　{

　　　　</span><span style="color: #0000ff;">while</span> (qq &gt; (rr = a /<span style="color: #000000;"> qq))

　　　　{

　　　　　　qq </span>= (qq + rr) &gt;&gt; <span style="color: #800080;">1</span><span style="color: #000000;">；

　　　　}

　　}

　　rr </span>= a - qq *<span style="color: #000000;"> qq；

　　</span>*q =<span style="color: #000000;"> qq；

　　</span>*r =<span style="color: #000000;"> rr；

}</span></pre>
</div>
<p>&nbsp;</p>
<h3><strong>5、循环优化</strong></h3>
<p><strong>（1）、充分分解小的循环</strong></p>
<p>要充分利用CPU的指令缓存，就要充分分解小的循环。特别是当循环体本身很小的时候，分解循环可以提高性能。注意:很多编译器并不能自动分解循环。 不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #008000;">//</span><span style="color: #008000;"> 3D转化：把矢量 V 和 4x4 矩阵 M 相乘</span>

<span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>； i &lt; <span style="color: #800080;">4</span>； i ++<span style="color: #000000;">)

{

　　r[i] </span>= <span style="color: #800080;">0</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">for</span> (j = <span style="color: #800080;">0</span>； j &lt; <span style="color: #800080;">4</span>； j ++<span style="color: #000000;">)

　　{

　　　　r[i] </span>+= M[j][i]*<span style="color: #000000;">V[j]；

　　}

}</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre>r[<span style="color: #800080;">0</span>] = M[<span style="color: #800080;">0</span>][<span style="color: #800080;">0</span>]*V[<span style="color: #800080;">0</span>] + M[<span style="color: #800080;">1</span>][<span style="color: #800080;">0</span>]*V[<span style="color: #800080;">1</span>] + M[<span style="color: #800080;">2</span>][<span style="color: #800080;">0</span>]*V[<span style="color: #800080;">2</span>] + M[<span style="color: #800080;">3</span>][<span style="color: #800080;">0</span>]*V[<span style="color: #800080;">3</span><span style="color: #000000;">]；

r[</span><span style="color: #800080;">1</span>] = M[<span style="color: #800080;">0</span>][<span style="color: #800080;">1</span>]*V[<span style="color: #800080;">0</span>] + M[<span style="color: #800080;">1</span>][<span style="color: #800080;">1</span>]*V[<span style="color: #800080;">1</span>] + M[<span style="color: #800080;">2</span>][<span style="color: #800080;">1</span>]*V[<span style="color: #800080;">2</span>] + M[<span style="color: #800080;">3</span>][<span style="color: #800080;">1</span>]*V[<span style="color: #800080;">3</span><span style="color: #000000;">]；

r[</span><span style="color: #800080;">2</span>] = M[<span style="color: #800080;">0</span>][<span style="color: #800080;">2</span>]*V[<span style="color: #800080;">0</span>] + M[<span style="color: #800080;">1</span>][<span style="color: #800080;">2</span>]*V[<span style="color: #800080;">1</span>] + M[<span style="color: #800080;">2</span>][<span style="color: #800080;">2</span>]*V[<span style="color: #800080;">2</span>] + M[<span style="color: #800080;">3</span>][<span style="color: #800080;">2</span>]*V[<span style="color: #800080;">3</span><span style="color: #000000;">]；

r[</span><span style="color: #800080;">3</span>] = M[<span style="color: #800080;">0</span>][<span style="color: #800080;">3</span>]*V[<span style="color: #800080;">0</span>] + M[<span style="color: #800080;">1</span>][<span style="color: #800080;">3</span>]*V[<span style="color: #800080;">1</span>] + M[<span style="color: #800080;">2</span>][<span style="color: #800080;">3</span>]*V[<span style="color: #800080;">2</span>] + M[<span style="color: #800080;">3</span>][<span style="color: #800080;">3</span>]*v[<span style="color: #800080;">3</span>]；</pre>
</div>
<p>&nbsp;</p>
<p><strong>（2）、提取公共部分</strong></p>
<p>对于一些不需要循环变量参加运算的任务可以把它们放到循环外面，这里的任务包括表达式、函数的调用、指针运算、数组访问等，应该将没有必要执行多次的操作全部集合在一起，放到一个init的初始化程序中进行。</p>
<div>
<p><strong>（3）、延时函数</strong></p>
</div>
<p>通常使用的延时函数均采用自加的形式：</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">void</span> delay (<span style="color: #0000ff;">void</span><span style="color: #000000;">)

    {

unsigned </span><span style="color: #0000ff;">int</span><span style="color: #000000;"> i;

    </span><span style="color: #0000ff;">for</span> (i=<span style="color: #800080;">0</span>;i&lt;<span style="color: #800080;">1000</span>;i++<span style="color: #000000;">) ;

    }</span></pre>
</div>
<p>&nbsp;</p>
<p>将其改为自减延时函数：</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">void</span> delay (<span style="color: #0000ff;">void</span><span style="color: #000000;">)

    {

unsigned </span><span style="color: #0000ff;">int</span><span style="color: #000000;"> i;

        </span><span style="color: #0000ff;">for</span> (i=<span style="color: #800080;">1000</span>;i&gt;<span style="color: #800080;">0</span>;i--<span style="color: #000000;">) ;

    }</span></pre>
</div>
<p>&nbsp;</p>
<p>两个函数的延时效果相似，但几乎所有的C编译对后一种函数生成的代码均比前一种代码少1~3个字节，因为几乎所有的MCU均有为0转移的指令，采用后一种方式能够生成这类指令。在使用while循环时也一样，使用自减指令控制循环会比使用自加指令控制循环生成的代码更少1~3个字母。但是在循环中有通过循环变量&ldquo;i&rdquo;读写数组的指令时，使用预减循环有可能使数组超界，要引起注意。</p>
<p><strong>（4）、while循环和do&hellip;while循环</strong></p>
<p>用while循环时有以下两种循环形式：</p>
<div class="cnblogs_code">
<pre>unsigned <span style="color: #0000ff;">int</span><span style="color: #000000;"> i;

    i</span>=<span style="color: #800080;">0</span><span style="color: #000000;">;

    </span><span style="color: #0000ff;">while</span> (i&lt;<span style="color: #800080;">1000</span><span style="color: #000000;">)

    {

        i</span>++<span style="color: #000000;">;

           </span><span style="color: #008000;">//</span><span style="color: #008000;">用户程序</span>
<span style="color: #000000;">
    }</span></pre>
</div>
<p>&nbsp;</p>
<p>或：</p>
<div class="cnblogs_code">
<pre>unsigned <span style="color: #0000ff;">int</span><span style="color: #000000;"> i;

    i</span>=<span style="color: #800080;">1000</span><span style="color: #000000;">;

</span><span style="color: #0000ff;">do</span><span style="color: #000000;">

{

          i</span>--<span style="color: #000000;">;

          </span><span style="color: #008000;">//</span><span style="color: #008000;">用户程序</span>
<span style="color: #000000;">
}

</span><span style="color: #0000ff;">while</span> (i&gt;<span style="color: #800080;">0</span>);</pre>
</div>
<p>&nbsp;</p>
<p>在这两种循环中，使用do&hellip;while循环编译后生成的代码的长度短于while循环。</p>
<p><strong>（6）、循环展开</strong></p>
<p>这是经典的速度优化，但许多编译程序(如gcc -funroll-loops)能自动完成这个事，所以现在你自己来优化这个显得效果不明显。</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>; i &lt; <span style="color: #800080;">100</span>; i++<span style="color: #000000;">)

{

do_stuff(i);

}</span></pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>; i &lt; <span style="color: #800080;">100</span><span style="color: #000000;">; )

{

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

do_stuff(i); i</span>++<span style="color: #000000;">;

}</span></pre>
</div>
<p>&nbsp;</p>
<p>可以看出，新代码里比较指令由100次降低为10次，循环时间节约了90%。不过注意:对于中间变量或结果被更改的循环，编译程序往往拒绝展开，(怕担责任呗)，这时候就需要你自己来做展开工作了。</p>
<p>还有一点请注意，在有内部指令cache的CPU上(如MMX芯片)，因为循环展开的代码很大，往往cache溢出，这时展开的代码会频繁地在CPU 的cache和内存之间调来调去，又因为cache速度很高，所以此时循环展开反而会变慢。还有就是循环展开会影响矢量运算优化。</p>
<p><strong>（6）、循环嵌套</strong></p>
<p>把相关循环放到一个循环里，也会加快速度。</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>; i &lt; MAX; i++)         <span style="color: #008000;">/*</span><span style="color: #008000;"> initialize 2d array to 0's </span><span style="color: #008000;">*/</span>

    <span style="color: #0000ff;">for</span> (j = <span style="color: #800080;">0</span>; j &lt; MAX; j++<span style="color: #000000;">)

        a[i][j] </span>= <span style="color: #800080;">0.0</span><span style="color: #000000;">;

    </span><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>; i &lt; MAX; i++)        <span style="color: #008000;">/*</span><span style="color: #008000;"> put 1's along the diagonal </span><span style="color: #008000;">*/</span><span style="color: #000000;">

        a[i][i] </span>= <span style="color: #800080;">1.0</span>;</pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>; i &lt; MAX; i++)         <span style="color: #008000;">/*</span><span style="color: #008000;"> initialize 2d array to 0's </span><span style="color: #008000;">*/</span><span style="color: #000000;">

{

    </span><span style="color: #0000ff;">for</span> (j = <span style="color: #800080;">0</span>; j &lt; MAX; j++<span style="color: #000000;">)

        a[i][j] </span>= <span style="color: #800080;">0.0</span><span style="color: #000000;">;

    a[i][i] </span>= <span style="color: #800080;">1.0</span>;                            <span style="color: #008000;">/*</span><span style="color: #008000;"> put 1's along the diagonal </span><span style="color: #008000;">*/</span><span style="color: #000000;">

}</span></pre>
</div>
<p>&nbsp;</p>
<p><strong>（7）、Switch语句中根据发生频率来进行case排序</strong></p>
<p>Switch 可能转化成多种不同算法的代码。其中最常见的是跳转表和比较链/树。当switch用比较链的方式转化时，编译器会产生if-else-if的嵌套代码，并按照顺序进行比较，匹配时就跳转到满足条件的语句执行。所以可以对case的值依照发生的可能性进行排序，把最有可能的放在第一位，这样可以提高性能。此外，在case中推荐使用小的连续的整数，因为在这种情况下，所有的编译器都可以把switch 转化成跳转表。</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">int</span><span style="color: #000000;"> days_in_month， short_months， normal_months， long_months；

。。。。。。

</span><span style="color: #0000ff;">switch</span><span style="color: #000000;"> (days_in_month)

{

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">28</span><span style="color: #000000;">:

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">29</span><span style="color: #000000;">:

　　　　short_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">30</span><span style="color: #000000;">:

　　　　normal_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">31</span><span style="color: #000000;">:

　　　　long_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">default</span><span style="color: #000000;">:

　　　　cout </span>&lt;&lt; <span style="color: #800000;">"</span><span style="color: #800000;">month has fewer than 28 or more than 31 days</span><span style="color: #800000;">"</span> &lt;&lt;<span style="color: #000000;"> endl；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

}</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">int</span><span style="color: #000000;"> days_in_month， short_months， normal_months， long_months；

。。。。。。

</span><span style="color: #0000ff;">switch</span><span style="color: #000000;"> (days_in_month)

{

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">31</span><span style="color: #000000;">:

　　　　long_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">30</span><span style="color: #000000;">:

　　　　normal_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">28</span><span style="color: #000000;">:

　　</span><span style="color: #0000ff;">case</span> <span style="color: #800080;">29</span><span style="color: #000000;">:

　　　　short_months </span>++<span style="color: #000000;">；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

　　</span><span style="color: #0000ff;">default</span><span style="color: #000000;">:

　　　　cout </span>&lt;&lt; <span style="color: #800000;">"</span><span style="color: #800000;">month has fewer than 28 or more than 31 days</span><span style="color: #800000;">"</span> &lt;&lt;<span style="color: #000000;"> endl；

　　　　</span><span style="color: #0000ff;">break</span><span style="color: #000000;">；

}  </span></pre>
</div>
<p>&nbsp;</p>
<p><strong>（8）、将大的switch语句转为嵌套switch语句</strong></p>
<p>当switch语句中的case标号很多时，为了减少比较的次数，明智的做法是把大switch语句转为嵌套switch语句。把发生频率高的case 标号放在一个switch语句中，并且是嵌套switch语句的最外层，发生相对频率相对低的case标号放在另一个switch语句中。比如，下面的程序段把相对发生频率低的情况放在缺省的case标号内。</p>
<div class="cnblogs_code">
<pre>pMsg=<span style="color: #000000;">ReceiveMessage();

        </span><span style="color: #0000ff;">switch</span> (pMsg-&gt;<span style="color: #000000;">type)

        {

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> FREQUENT_MSG1:

        handleFrequentMsg();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> FREQUENT_MSG2:

        handleFrequentMsg2();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        。。。。。。

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> FREQUENT_MSGn:

        handleFrequentMsgn();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        </span><span style="color: #0000ff;">default</span>:                     <span style="color: #008000;">//</span><span style="color: #008000;">嵌套部分用来处理不经常发生的消息</span>

        <span style="color: #0000ff;">switch</span> (pMsg-&gt;<span style="color: #000000;">type)

        {

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> INFREQUENT_MSG1:

        handleInfrequentMsg1();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> INFREQUENT_MSG2:

        handleInfrequentMsg2();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        。。。。。。

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> INFREQUENT_MSGm:

        handleInfrequentMsgm();

        </span><span style="color: #0000ff;">break</span><span style="color: #000000;">;

        }

        }<br /></span></pre>
</div>
<pre>如果switch中每一种情况下都有很多的工作要做，那么把整个switch语句用一个指向函数指针的表来替换会更加有效，比如下面的switch语句，有三种情况：</pre>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">enum</span><span style="color: #000000;"> MsgType{Msg1， Msg2， Msg3}

        </span><span style="color: #0000ff;">switch</span><span style="color: #000000;"> (ReceiveMessage()

        {

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> Msg1;

        。。。。。。

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> Msg2;

        。。。。。

        </span><span style="color: #0000ff;">case</span><span style="color: #000000;"> Msg3;

        。。。。。

        }</span></pre>
</div>
<p>&nbsp;</p>
<p>为了提高执行速度，用下面这段代码来替换这个上面的switch语句。</p>
<div class="cnblogs_code">
<pre>        <span style="color: #008000;">/*</span><span style="color: #008000;">准备工作</span><span style="color: #008000;">*/</span>

        <span style="color: #0000ff;">int</span> handleMsg1(<span style="color: #0000ff;">void</span><span style="color: #000000;">);

        </span><span style="color: #0000ff;">int</span> handleMsg2(<span style="color: #0000ff;">void</span><span style="color: #000000;">);

        </span><span style="color: #0000ff;">int</span> handleMsg3(<span style="color: #0000ff;">void</span><span style="color: #000000;">);

        </span><span style="color: #008000;">/*</span><span style="color: #008000;">创建一个函数指针数组</span><span style="color: #008000;">*/</span>

        <span style="color: #0000ff;">int</span> (*MsgFunction [])()=<span style="color: #000000;">{handleMsg1， handleMsg2， handleMsg3};

        </span><span style="color: #008000;">/*</span><span style="color: #008000;">用下面这行更有效的代码来替换switch语句</span><span style="color: #008000;">*/</span><span style="color: #000000;">

        status</span>=MsgFunction[ReceiveMessage()]();</pre>
</div>
<p>&nbsp;</p>
<div>
<p><strong>（9）、循环转置</strong></p>
</div>
<p>有些机器对JNZ(为0转移)有特别的指令处理，速度非常快，如果你的循环对方向不敏感，可以由大向小循环。</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">1</span>; i &lt;= MAX; i++<span style="color: #000000;">)

{

   。。。

 }</span></pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre>i = MAX+<span style="color: #800080;">1</span><span style="color: #000000;">;

</span><span style="color: #0000ff;">while</span> (--<span style="color: #000000;">i)

{

。。。

}</span></pre>
</div>
<p>&nbsp;</p>
<p>不过千万注意，如果指针操作使用了i值，这种方法可能引起指针越界的严重错误(i = MAX+1;)。当然你可以通过对i做加减运算来纠正，但是这样就起不到加速的作用，除非类似于以下情况：</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">char</span> a[MAX+<span style="color: #800080;">5</span><span style="color: #000000;">];

</span><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">1</span>; i &lt;= MAX; i++<span style="color: #000000;">)

{

</span>*(a+i+<span style="color: #800080;">4</span>)=<span style="color: #800080;">0</span><span style="color: #000000;">;

}</span></pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre>i = MAX+<span style="color: #800080;">1</span><span style="color: #000000;">;

</span><span style="color: #0000ff;">while</span> (--<span style="color: #000000;">i)

{

      </span>*(a+i+<span style="color: #800080;">4</span>)=<span style="color: #800080;">0</span><span style="color: #000000;">;

}</span></pre>
</div>
<p>&nbsp;</p>
<p><strong>（10）、公用代码块</strong></p>
<p>一些公用处理模块，为了满足各种不同的调用需要，往往在内部采用了大量的if-then-else结构，这样很不好，判断语句如果太复杂，会消耗大量的时间的，应该尽量减少公用代码块的使用。(任何情况下，空间优化和时间优化都是对立的--东楼)。当然，如果仅仅是一个(3==x)之类的简单判断，适当使用一下，也还是允许的。记住，优化永远是追求一种平衡，而不是走极端。</p>
<p><strong>（11）提升循环的性能</strong></p>
<p>要提升循环的性能，减少多余的常量计算非常有用（比如，不随循环变化的计算）。</p>
<p>不好的代码(在for()中包含不变的if())：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span><span style="color: #000000;">( i 。。。 )

{

　　</span><span style="color: #0000ff;">if</span><span style="color: #000000;">( CONSTANT0 )

　　{

　　　　DoWork0( i )； </span><span style="color: #008000;">//</span><span style="color: #008000;"> 假设这里不改变CONSTANT0的值</span>
<span style="color: #000000;">
　　}

　　</span><span style="color: #0000ff;">else</span><span style="color: #000000;">

　　{

　　　　DoWork1( i )； </span><span style="color: #008000;">//</span><span style="color: #008000;"> 假设这里不改变CONSTANT0的值</span>
<span style="color: #000000;">
　　}

}</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">if</span><span style="color: #000000;">( CONSTANT0 )

{

　　</span><span style="color: #0000ff;">for</span><span style="color: #000000;">( i 。。。 )

　　{

　　　　DoWork0( i )；

　　}

}

</span><span style="color: #0000ff;">else</span><span style="color: #000000;">

{

　　</span><span style="color: #0000ff;">for</span><span style="color: #000000;">( i 。。。 )

　　{

　　　　DoWork1( i )；

　　}

} </span></pre>
</div>
<p>&nbsp;</p>
<p>如果已经知道if()的值，这样可以避免重复计算。虽然不好的代码中的分支可以简单地预测，但是由于推荐的代码在进入循环前分支已经确定，就可以减少对分支预测的依赖。</p>
<p><strong>（12）、选择好的无限循环</strong></p>
<p>在编程中，我们常常需要用到无限循环，常用的两种方法是while (1) 和 for (；；)。这两种方法效果完全一样，但那一种更好呢？然我们看看它们编译后的代码：</p>
<p>编译前：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">while</span> (<span style="color: #800080;">1</span>)；</pre>
</div>
<p>&nbsp;</p>
<p>编译后：</p>
<div class="cnblogs_code">
<pre>mov eax，<span style="color: #800080;">1</span><span style="color: #000000;">

test eax，eax

je foo</span>+<span style="color: #000000;">23h

jmp foo</span>+18h </pre>
</div>
<p>&nbsp;</p>
<p>编译前：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">for</span> (；；)；</pre>
</div>
<p>&nbsp;</p>
<p>编译后：</p>
<div class="cnblogs_code">
<pre>jmp foo+23h</pre>
</div>
<p>&nbsp;</p>
<div>显然，for (；；)指令少，不占用寄存器，而且没有判断、跳转，比while (1)好。</div>
<h3><strong>6、提高CPU的并行性</strong></h3>
<p><strong>（1）使用并行代码</strong></p>
<p>尽可能把长的有依赖的代码链分解成几个可以在流水线执行单元中并行执行的没有依赖的代码链。很多高级语言，包括C++，并不对产生的浮点表达式重新排序，因为那是一个相当复杂的过程。需要注意的是，重排序的代码和原来的代码在代码上一致并不等价于计算结果一致，因为浮点操作缺乏精确度。在一些情况下，这些优化可能导致意料之外的结果。幸运的是，在大部分情况下，最后结果可能只有最不重要的位（即最低位）是错误的。</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">double</span> a[<span style="color: #800080;">100</span><span style="color: #000000;">]， sum；

</span><span style="color: #0000ff;">int</span><span style="color: #000000;"> i；

sum </span>= <span style="color: #800080;">0.0f</span><span style="color: #000000;">；

</span><span style="color: #0000ff;">for</span> (i=<span style="color: #800080;">0</span>； i&lt;<span style="color: #800080;">100</span>； i++<span style="color: #000000;">)

sum </span>+= a[i]；</pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">double</span> a[<span style="color: #800080;">100</span><span style="color: #000000;">]， sum1， sum2， sum3， sum4， sum；

</span><span style="color: #0000ff;">int</span><span style="color: #000000;"> i；

sum1 </span>= sum2 = sum3 = sum4 = <span style="color: #800080;">0.0</span><span style="color: #000000;">；

</span><span style="color: #0000ff;">for</span> (i = <span style="color: #800080;">0</span>； i &lt; <span style="color: #800080;">100</span>； i += <span style="color: #800080;">4</span><span style="color: #000000;">)

{

　　sum1 </span>+=<span style="color: #000000;"> a[i]；

　　sum2 </span>+= a[i+<span style="color: #800080;">1</span><span style="color: #000000;">]；

　　sum3 </span>+= a[i+<span style="color: #800080;">2</span><span style="color: #000000;">]；

　　sum4 </span>+= a[i+<span style="color: #800080;">3</span><span style="color: #000000;">]；

}

sum </span>= (sum4+sum3)+(sum1+sum2)； </pre>
</div>
<p>&nbsp;</p>
<p>要注意的是：使用4路分解是因为这样使用了4段流水线浮点加法，浮点加法的每一个段占用一个时钟周期，保证了最大的资源利用率。</p>
<p><strong>（2）避免没有必要的读写依赖</strong></p>
<p>当数据保存到内存时存在读写依赖，即数据必须在正确写入后才能再次读取。虽然AMD Athlon等CPU有加速读写依赖延迟的硬件，允许在要保存的数据被写入内存前读取出来，但是，如果避免了读写依赖并把数据保存在内部寄存器中，速度会更快。在一段很长的又互相依赖的代码链中，避免读写依赖显得尤其重要。如果读写依赖发生在操作数组时，许多编译器不能自动优化代码以避免读写依赖。所以推荐程序员手动去消除读写依赖，举例来说，引进一个可以保存在寄存器中的临时变量。这样可以有很大的性能提升。下面一段代码是一个例子：</p>
<p>不好的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> x[VECLEN]， y[VECLEN]， z[VECLEN]；

。。。。。。

</span><span style="color: #0000ff;">for</span> (unsigned <span style="color: #0000ff;">int</span> k = <span style="color: #800080;">1</span>； k &lt; VECLEN； k ++<span style="color: #000000;">)

{

　　x[k] </span>= x[k-<span style="color: #800080;">1</span>] +<span style="color: #000000;"> y[k]；

}

</span><span style="color: #0000ff;">for</span> (k = <span style="color: #800080;">1</span>； k &lt;VECLEN； k++<span style="color: #000000;">)

{

　　x[k] </span>= z[k] * (y[k] - x[k-<span style="color: #800080;">1</span><span style="color: #000000;">])；

}</span></pre>
</div>
<p>&nbsp;</p>
<p>推荐的代码：</p>
<div class="cnblogs_code">
<pre><span style="color: #0000ff;">float</span><span style="color: #000000;"> x[VECLEN]， y[VECLEN]， z[VECLEN]；

。。。。。。

</span><span style="color: #0000ff;">float</span> t(x[<span style="color: #800080;">0</span><span style="color: #000000;">])；

</span><span style="color: #0000ff;">for</span> (unsigned <span style="color: #0000ff;">int</span> k = <span style="color: #800080;">1</span>； k &lt; VECLEN； k ++<span style="color: #000000;">)

{

　　t </span>= t +<span style="color: #000000;"> y[k]；

　　x[k] </span>=<span style="color: #000000;"> t；

}

t </span>= x[<span style="color: #800080;">0</span><span style="color: #000000;">]；

</span><span style="color: #0000ff;">for</span> (k = <span style="color: #800080;">1</span>； k &lt;； VECLEN； k ++<span style="color: #000000;">)

{

　　t </span>= z[k] * (y[k] -<span style="color: #000000;"> t)；

　　x[k] </span>=<span style="color: #000000;"> t；

} </span></pre>
</div>
<p>&nbsp;</p>
<div>
<h3><strong>7、循环不变计算</strong></h3>
</div>
<p>对于一些不需要循环变量参加运算的计算任务可以把它们放到循环外面，现在许多编译器还是能自己干这件事，不过对于中间使用了变量的算式它们就不敢动了，所以很多情况下你还得自己干。对于那些在循环中调用的函数，凡是没必要执行多次的操作通通提出来，放到一个init函数里，循环前调用。另外尽量减少喂食次数，没必要的话尽量不给它传参，需要循环变量的话让它自己建立一个静态循环变量自己累加，速度会快一点。</p>
<p>还有就是结构体访问，东楼的经验，凡是在循环里对一个结构体的两个以上的元素执行了访问，就有必要建立中间变量了(结构这样，那C++的对象呢?想想看)，看下面的例子:</p>
<p>旧代码:</p>
<div class="cnblogs_code">
<pre>    total =<span style="color: #000000;">

    a</span>-&gt;b-&gt;c[<span style="color: #800080;">4</span>]-&gt;aardvark +<span style="color: #000000;">

    a</span>-&gt;b-&gt;c[<span style="color: #800080;">4</span>]-&gt;baboon +<span style="color: #000000;">

    a</span>-&gt;b-&gt;c[<span style="color: #800080;">4</span>]-&gt;cheetah +<span style="color: #000000;">

    a</span>-&gt;b-&gt;c[<span style="color: #800080;">4</span>]-&gt;dog;</pre>
</div>
<p>&nbsp;</p>
<p>新代码:</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">struct</span> animals * temp = a-&gt;b-&gt;c[<span style="color: #800080;">4</span><span style="color: #000000;">];

    total </span>=<span style="color: #000000;">

    temp</span>-&gt;aardvark +<span style="color: #000000;">

    temp</span>-&gt;baboon +<span style="color: #000000;">

    temp</span>-&gt;cheetah +<span style="color: #000000;">

    temp</span>-&gt;dog;</pre>
</div>
<p>&nbsp;</p>
<p>一些老的C语言编译器不做聚合优化，而符合ANSI规范的新的编译器可以自动完成这个优化，看例子:</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， d， f， g;

    。。。

    a </span>= b / c *<span style="color: #000000;"> d;

    f </span>= b * g / c;</pre>
</div>
<p>&nbsp;</p>
<p>这种写法当然要得，但是没有优化</p>
<div class="cnblogs_code">
<pre>    <span style="color: #0000ff;">float</span><span style="color: #000000;"> a， b， c， d， f， g;

    。。。

    a </span>= b / c *<span style="color: #000000;"> d;

    f </span>= b / c * g;</pre>
</div>
<p>&nbsp;</p>
<p>如果这么写的话，一个符合ANSI规范的新的编译器可以只计算b/c一次，然后将结果代入第二个式子，节约了一次除法运算。</p>
<h3><strong>8、函数优化</strong></h3>
<p><strong>（1）Inline函数</strong></p>
<p>在C++中，关键字Inline可以被加入到任何函数的声明中。这个关键字请求编译器用函数内部的代码替换所有对于指出的函数的调用。这样做在两个方面快于函数调用：第一，省去了调用指令需要的执行时间；第二，省去了传递变元和传递过程需要的时间。但是使用这种方法在优化程序速度的同时，程序长度变大了，因此需要更多的ROM。使用这种优化在Inline函数频繁调用并且只包含几行代码的时候是最有效的。</p>
<p><strong>（2）不定义不使用的返回值</strong></p>
<p>函数定义并不知道函数返回值是否被使用，假如返回值从来不会被用到，应该使用void来明确声明函数不返回任何值。</p>
<div>
<p><strong>（3）减少函数调用参数</strong></p>
</div>
<p>&nbsp;&nbsp;&nbsp; 使用全局变量比函数传递参数更加有效率。这样做去除了函数调用参数入栈和函数完成后参数出栈所需要的时间。然而决定使用全局变量会影响程序的模块化和重入，故要慎重使用。</p>
<p><strong>（4）所有函数都应该有原型定义</strong></p>
<p>一般来说，所有函数都应该有原型定义。原型定义可以传达给编译器更多的可能用于优化的信息。</p>
<p><strong>（5）尽可能使用常量(const)</strong></p>
<p>尽可能使用常量(const)。C++ 标准规定，如果一个const声明的对象的地址不被获取，允许编译器不对它分配储存空间。这样可以使代码更有效率，而且可以生成更好的代码。</p>
<p><strong>（6）把本地函数声明为静态的(static)</strong></p>
<p>如果一个函数只在实现它的文件中被使用，把它声明为静态的(static)以强制使用内部连接。否则，默认的情况下会把函数定义为外部连接。这样可能会影响某些编译器的优化&mdash;&mdash;比如，自动内联。</p>
<div>
<h3><strong>9、采用递归</strong></h3>
</div>
<p>与LISP之类的语言不同，C语言一开始就病态地喜欢用重复代码循环，许多C程序员都是除非算法要求，坚决不用递归。事实上，C编译器们对优化递归调用一点都不反感，相反，它们还很喜欢干这件事。只有在递归函数需要传递大量参数，可能造成瓶颈的时候，才应该使用循环代码，其他时候，还是用递归好些。</p>
<h3><strong>10、变量</strong></h3>
<p><strong>（1）register变量</strong></p>
<p>在声明局部变量的时候可以使用register关键字。这就使得编译器把变量放入一个多用途的寄存器中，而不是在堆栈中，合理使用这种方法可以提高执行速度。函数调用越是频繁，越是可能提高代码的速度。</p>
<p>在最内层循环避免使用全局变量和静态变量，除非你能确定它在循环周期中不会动态变化，大多数编译器优化变量都只有一个办法，就是将他们置成寄存器变量，而对于动态变量，它们干脆放弃对整个表达式的优化。尽量避免把一个变量地址传递给另一个函数，虽然这个还很常用。C语言的编译器们总是先假定每一个函数的变量都是内部变量，这是由它的机制决定的，在这种情况下，它们的优化完成得最好。但是，一旦一个变量有可能被别的函数改变，这帮兄弟就再也不敢把变量放到寄存器里了，严重影响速度。看例子：</p>
<p>a = b();</p>
<p>c(&amp;d);</p>
<p>因为d的地址被c函数使用，有可能被改变，编译器不敢把它长时间的放在寄存器里，一旦运行到c(&amp;d)，编译器就把它放回内存，如果在循环里，会造成N次频繁的在内存和寄存器之间读写d的动作，众所周知，CPU在系统总线上的读写速度慢得很。比如你的赛杨300，CPU主频300，总线速度最多66M，为了一个总线读，CPU可能要等4-5个周期，得。。得。。得。。想起来都打颤。</p>
<p><strong>（2）、同时声明多个变量优于单独声明变量</strong></p>
<p><strong>（3）、短变量名优于长变量名，应尽量使变量名短一点</strong></p>
<p><strong>（4）、在循环开始前声明变量</strong></p>
<div>
<h3><strong>11、使用嵌套的if结构</strong></h3>
</div>
<p>在if结构中如果要判断的并列条件较多，最好将它们拆分成多个if结构，然后嵌套在一起，这样可以避免无谓的判断。</p>
<p>说明：</p>
<p>上面的优化方案由王全明收集整理。很多资料来源与网上，出处不祥，在此对所有作者一并致谢！</p>
<p>该方案主要是考虑到在嵌入式开发中对程序执行速度的要求特别高，所以该方案主要是为了优化程序的执行速度。</p>
<p>注意：优化是有侧重点的，优化是一门平衡的艺术，它往往要以牺牲程序的可读性或者增加代码长度为代价。</p>
<p>(任何情况下，空间优化和时间优化都是对立的--东楼)。&nbsp;&nbsp;</p>