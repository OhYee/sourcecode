---
title: 筛法求素数
date: 2015-07-30 15:48:00
tags: 
- 质数
categories: 算法
---

> 质数（prime number）又称素数，有无限个。一个大于1的自然数，除了1和它本身外，不能被其他自然数（质数）整除，换句话说就是该数除了1和它本身以外不再有其他的因数；否则称为合数。

> ——百度百科

要想判断一个数是不是质数，就要看他能不能被除了1和自己之外的数分解

显然如果当需要多次判断数据是否是素数时，每次都计算一次是很慢的。

但是可以声明一个布尔型数组，保存对应下标是否为素数，这样只需要计算一次。

开始时，从2开始，分别乘上2以上的数，所得的数全都不是素数
  
 <!--more-->
 
## **<font color=RED>以下部分证明有误</font>** 

``` cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool is_prime[10001];
int main(){
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i<=100;i++){
        for(int j=2;j<=100;j++){
            is_prime[i*j]=false;
        }
    }
//    printf("%d",is_prime[4]);
    int num;
    //cin>>num;
    for (num=2;num<100;num++){
    if(is_prime[num]==true){
        cout<<num<<"是素数"<<endl;
    }else{
        cout<<num<<"不是素数"<<endl;
    }
    }
    return 0;
}
```

<del>显然，对于12，这样既计算了2*6，也计算了6*2（还有3*4，4*3），所以这样重复计算了大量数据</del>

<del>修改一下算法，可以让运算量稍小。</del>



合数可以分解成质数相乘，而根据算法，如果一个合数已经被确定，那么由它得出的合数也都被确定。

所以，如果发现一个数是合数，那么就不必再计算由它乘出的数

同时，保证相乘的两个数都是前一个小后一个大，这样可以避免同一组数的重复计算。
 
 
##  Eratosthenes筛法

``` cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=10000;
bool is_prime[maxn+1];
int main(){
    int m=sqrt(maxn+0.5);
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i<=m;i++){
        if(is_prime){
            for(int j=i*i;j<=maxn;j+=i){
                is_prime[j]=false;
            }
        }
    }

    for(int num=2;num<100;num++){
        if(is_prime[num]==true){
            cout<<num<<"是素数"<<endl;
        }else{
            cout<<num<<"不是素数"<<endl;
        }
    }
    return 0;
}
```

然而，如果我们添加一个count变量来记录每个数被重复运算的次数。会发现，仍然有好多数被重复运算。  

不过，线性的算法还是存在的

> 算术基本定理可表述为：任何一个大于1的自然数 N,如果N不为质数，那么N可以唯一分解成有限个质数的乘积N=P1a1P2a2P3a3......Pnan，这里P1<P2<P3......<Pn均为质数，其中指数ai是正整数。这样的分解称为 N 的标准分解式。最早证明是由欧几里得给出的，现代是由陈述证明。此定理可推广至更一般的交换代数和代数数论。

> ——百度百科

只需要计算出所有 i×(小于i的素数) ，那么我们便可以得到所有的合数。同时，通过排除掉i是(小于i的素数)的整倍数的情况来保证只计算一次  

``` cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=10000;
int main(){
    int count[maxn+1]={0};

    int prime[maxn]={0},num_prime=0;
    bool isNotPrime[maxn]={1,1};

    for(long i=2;i<maxn;i++){
        if(!isNotPrime[i])prime[num_prime++]=i;
        for(int j=0;j<num_prime&&i*prime[j]<maxn;j++){
            isNotPrime[i*prime[j]]=true;
            count[i*prime[j]]++;
            if(!(i%prime[j]))break;
        }
    }

    for(int num=1;num<100;num++){
        if(isNotPrime[num]!=true){
            cout<<num<<"是素数"<<endl;
        }else{
            cout<<num<<"不是素数"<<endl;
        }
    }

    for(int i=1;i<=maxn;i++)if(count[i]>1)cout<<i<<":"<<count[i]<<endl;
    return 0;
}
```