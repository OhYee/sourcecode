---
title: 康托（逆）展开
date: 2015-08-06 11:34:00
tags:
- 康托
categories: 算法
---

> 康托展开 X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0! 其中，a[i]为整数，并且X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!。这就是康托展开。康托展开可用代码实现。

> ——百度百科

<del>这个东西，我们高三的时候称作OhYee第一定理（还有第二第三）。当时做排列组合做到疯的时候推出来的。然而我们数学老师觉得没什么琴里用→_→</del>


对于八数码问题，在储存时有一个问题，就是八数码共有9！=362800种可能，但是如果用9维数组，包含了99=387420489项，显然造成了极大地浪费。

当然，我们可以采用哈希表来进行映射，而哈希函数便可以使用康托展开<del>（OhYee第一定理）</del>。

<del>当年我可是在有OhYee第一定理的情况下做过八数码的，可惜当时竟然没有想到用OhYee第一定理。。。</del>


嗯嗯，我们就不管是康托展开，还是康托逆展开了，反正都是OhYee定理的内容23333333333

 
----
## 含义  
> 对于｛1，2，3，4｝其排列有：1234，1243，1324，1342，1423，1432，2134，2143，2314，2341，2413，2431，3124，3142，3214，3241，3412，3421，4123，4132，4213，4231，4312，4321共24种。

这样我们就可以按照从小到大的顺序，给他们编上号，就有了一个映射关系

<br>

<table style="border-color:000000; border-width: 0px; float: left; height: 88px; width: 538px;" border="0">
<tbody>
<tr>
<td style="border: 1px solid000000; text-align: left;">1</td>
<td style="border: 1px solid000000;">2</td>
<td style="border: 1px solid000000;">3</td>
<td style="border: 1px solid000000;">4</td>
<td style="border: 1px solid000000;">5</td>
<td style="border: 1px solid000000;">6</td>
<td style="border: 1px solid000000;">7</td>
<td style="border: 1px solid000000;">8</td>
<td style="border: 1px solid000000;">9</td>
<td style="border: 1px solid000000;">10</td>
<td style="border: 1px solid000000;">11</td>
<td style="border: 1px solid000000;">12</td>
</tr>
<tr>
<td style="border: 1px solid000000;">1234</td>
<td style="border: 1px solid000000;">1243</td>
<td style="border: 1px solid000000;">1324</td>
<td style="border: 1px solid000000;">1342</td>
<td style="border: 1px solid000000;">1423</td>
<td style="border: 1px solid000000;">1432</td>
<td style="border: 1px solid000000;">2134</td>
<td style="border: 1px solid000000;">2143</td>
<td style="border: 1px solid000000;">2314</td>
<td style="border: 1px solid000000;">2341</td>
<td style="border: 1px solid000000;">2413</td>
<td style="border: 1px solid000000;">2431</td>
</tr>
<tr>
<td style="border: 1px solid000000;">13</td>
<td style="border: 1px solid000000;">14</td>
<td style="border: 1px solid000000;">15</td>
<td style="border: 1px solid000000;">16</td>
<td style="border: 1px solid000000;">17</td>
<td style="border: 1px solid000000;">18</td>
<td style="border: 1px solid000000;">19</td>
<td style="border: 1px solid000000;">20</td>
<td style="border: 1px solid000000;">21</td>
<td style="border: 1px solid000000;">22</td>
<td style="border: 1px solid000000;">23</td>
<td style="border: 1px solid000000;">24</td>
</tr>
<tr>
<td style="border: 1px solid000000;">3124</td>
<td style="border: 1px solid000000;">3142</td>
<td style="border: 1px solid000000;">3214</td>
<td style="border: 1px solid000000;">3241</td>
<td style="border: 1px solid000000;">3412</td>
<td style="border: 1px solid000000;">3421</td>
<td style="border: 1px solid000000;">4123</td>
<td style="border: 1px solid000000;">4132</td>
<td style="border: 1px solid000000;">4213</td>
<td style="border: 1px solid000000;">4231</td>
<td style="border: 1px solid000000;">4312</td>
<td style="border: 1px solid000000;">4321</td>
</tr>
</tbody>
</table>

<br>
  
这样将序号和数字的映射就是康托（逆）展开

----

## 原理 
由上面｛1，2，3，4｝的例子很容易发现，从小到大排列，有着一定的规律。

以每个数开头的，分别占据了总数（4!）的1/4，即3！。

第一个以1开头的在0×3！+1=1

第一个以2开头的在1×3！+1=7

……

也就是说N个数全排列，第一个数是x的数出现在(x-1)×(N-1)!+1处。

 

第一个数确定后，我们再看第二个数。假如第一个数是2，那么还有{1，3，4}三个数。

令1=1，2=3，3=4，我们便可看成{1，2，3}三个数的排列

假如是那么第一个2便在1×2!+1=3

 

再映射回去，也就是第二个是3的在第3个，对照上表看，在第一个是2的数中第二个是3的第一个数就是第3个

 

就这样，不断类比下去，就可以得到一个数在其排列中的位置。这就是OhYee第一定理

 

ps:最后的+1只需要加一次

 
----
## 例子 
假如我们想要计算在{1，2，3，4}的全排列中，2413的位置

首先有对2，比2小的有1，共1个。1×3！=6

此时剩下1，3，4。

然后对4，比4小的有1，3，共2个。2×2！=4

此时剩下1，3。

然后对1，比1小的有0个。0×1！=0

此时剩下3，比3小的有0个。0×0！=0

所以，2413的位置是6+4+0+0+1=11

---- 
## 逆着来一遍

排列中，第11个是什么呢~

首先划分区间3！=6，也就是6个一组（以相同的数字开头）

这样11-6=5<=6 在第2区间。第一个数是2

再往下划分区间2！=2

5-2=3　　3-2=1<=2在第3区间。第二个数是4

再往下划分1！=1

1<=1在第一区间。第三个数是1

再往下划分0！=1

1<=1在第一区间。第四个数是3

所以，第11个数是2413

 根据上面的分析，我们需要不断插入删除数字，需要用链表来记录还存在的数

用指针弄一个链表（输出了中间运算过程）

**链表**
``` cpp
class linked_list{
private:
    struct link{
        int num;
        link *next;
    };
    link *head;

public:
    linked_list(){
        head=NULL;
    }
    void Add(int n){
        link *it;
        if(head==NULL){
            head=new link;
            it=head;
        }else{
            it=head;
            while((it->next)!=NULL){
                it=it->next;
            }
            it->next=new link;
            it=it->next;
        }
        it->num=n;
        it->next=NULL;
        cout<<"add "<<n<<"  ("<<it<<")"<<endl;
    }
    void Del(int n){
        link *it=head;
        if(it->num==n){
            head=it->next;
            delete(it);
            cout<<"delete "<<n<<"   ("<<it<<")\n";
            return;
        }
        while(it->next->num!=n){
            it= it->next;
            if(it->next==NULL)return;
        }
        link *temp=it->next;
        it->next=it->next->next;
        delete(temp);
        cout<<"delete "<<n<<"   ("<<temp<<")\n";
    }
    int get(int n){
        link *it=head;
        int cnt=0;
        cout<<"begin ";
        while(it->num!=n){
            cout<<"---->"<<it<<"("<< it->num <<") ";
            it=it->next;
            cnt++;
        }
        cout<<endl;
        return cnt;
    }
    int get2(int n){
        link *it=head;
        cout<<"begin ";
        while(n>1){
            cout<<"---->"<<it<<"("<< it->num <<") ";
            it=it->next;
            n--;
        }
        cout<<"---->"<<it<<"("<< it->num <<") "<<endl;
        return it->num;
    }
};
```

其中Add()是向链表最后插入，Del()是删除存储制定数据的节点，get()是获取指定数据前面的节点数，get2()是获取指定节点存储的数

## 代码

``` cpp
int factorial[]={1,1,2,6,24,120,720,5040,40320};//n!
int KT(int N,int x){
    int ans=1;
    linked_list L;
    stack<int> S;
    while(x){
        S.push(x%10);
        x/=10;
    }
    REP(N){
        L.Add(o+1);
    }
    REP(N){
        int a=L.get(S.top());
        L.Del(S.top());
        S.pop();
        ans+=a*factorial[N-o-1];
    }
    return ans;
}
int KTN(int N,int n){
    int ans=0;
    linked_list L;
    REP(N){
        L.Add(o+1);
    }
    REP(N){
        ans*=10;
        int t=1;
        while(n>factorial[N-o-1]){
            n-=factorial[N-o-1];
            t++;
        }
        int temp=L.get2(t);
        ans+=temp;
        L.Del(temp);
    }
    return ans;
}
```