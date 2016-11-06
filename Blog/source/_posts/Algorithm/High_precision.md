---
title: 高精度算法
date: 2015-08-01 23:17:00
tags:
- 高精度算法
categories: 算法
---
c++中，变量的大小是有限制的。

比如int是 `-2147483648~2147483647`

long long是`-9223372036854775808~18446744073709551615`

然而他们都有一个范围，如果数据过大，就会出现错误。这时，我们需要高精度计算。

同过数组来存储各位上的情况，模拟计算加减乘除。

<!--more-->

首先，我们定义一个叫做`bigNumber`的类

然后，在里面声明一个整数数组（1000位）

其中，num[0]保存该数位数，num[i]表示对应数位上的数

数据的存储方式为(以13为例)

num     0   1   2   3  
数值      2   1   3   0  
备注      位数  个位  十位  百位    
 
接着，我们要定义构造函数来初始化它

要注意，构造函数本身被调用是没什么琴里用的，可以再写一个初始化函数，然后在构造函数里调用它，但需要初始化时，调用初始化函数，而不是构造函数

``` cpp
bigNumber(){//初始化
    init();
}
void init(){
    memset(num,0,sizeof(num));
}
```

然后，就是一些基本的功能的实现,例如等于、小于、大于……

这些都是比较容易实现的，不详细说明了

而四则运算则相对更为复杂

## 加法

首先是加法

我们先来看一下我们自己是如何计算加法的。

例如5135+139

 * 对齐数位  5 1 3 5

　　　　 +　 1 3 9  

 * 从低位开始加，当低位相加后大于9时，把较大数加到下一位上

    而且，我们可以知道，即使是9+9也才等于18。也即计算后，和的位数最多比加数的位数多1

    ``` cpp
    bigNumber operator + (const bigNumber rhs)const{
        bigNumber temp;
        int len;
        len=num[0]>rhs.num[0]?num[0]:rhs.num[0];
        len++;//两数相加，位数最多比较大的位数多1
        REP(len){
            temp.num[o+1]+=num[o+1]+rhs.num[o+1];
            temp.num[o+2]+=temp.num[o+1]/10;
            temp.num[o+1]%=10;
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    ```

## 乘法

而乘法相似，只是是乘数相乘加上进位(乘数与乘数各数位都要乘一次)

　　　　　5 1 3 5

　× 　  　　1 3 9  

\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-

　　　　4 6 2 1 5

　　　1 5 4 0 5

　　　5 1 3 5       

\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-  
　　　7 1 3 7 6 5

``` cpp
bigNumber operator * (const bigNumber rhs)const{
    bigNumber temp;
    int len;
    len=num[0]+rhs.num[0];
    //len++;
    for(int i=1;i<=num[0];i++){
        for(int j=1;j<=rhs.num[0];j++){
            temp.num[i+j-1]+=num[i]*rhs.num[j];
            temp.num[i+j]+=temp.num[i+j-1]/10;
            temp.num[i+j-1]%=10;
        }
    }
    REP(len){
        if(temp.num[len-o]!=0){
            temp.num[0]=len-o;
            break;
        }
    }
    return temp;
}
```

## 减法

而减法和除法则较为麻烦

首先，本高精度计算不考虑负数情况，不过负数也并不难写，可以再加上一个bool来储存是否为负数

不管减数和被减数谁大，都应该是绝对值大的减去绝对值小的（符号相同）

与加法不同，减法存在借数。不过如果不管需不需要借都借一下，然后如果结果是两位数再进上去更便于书写

模仿加法稍加修改

``` cpp
bigNumber operator - (const bigNumber rhs)const{
    bigNumber temp,a,b;
    temp=Max(*this,rhs);
    b=Min(*this,rhs);
    a=temp;
    temp=0;
    int len=a.num[0];
    REP(len){
        temp.num[o+1]+=10+a.num[o+1]-b.num[o+1];
        temp.num[o+2]--;
        temp.num[o+2]+=temp.num[o+1]/10;
        temp.num[o+1]%=10;
    }
    REP(len){
        if(temp.num[len-o]!=0){
            temp.num[0]=len-o;
            break;
        }
    }
    return temp;
}
```

## 除法

除法是最难写的一部分了，因为牵扯到试商的问题

我们先来理解一下除法的计算过程（以11311÷12为例）

1. 首先，从被除数的最高位开始除有1÷12=0······1

2. 余数乘10加上被除数的下一位11÷12=0······11

3. 余数乘10加上被除数的下一位113÷12=9······5

4. 余数乘10加上被除数的下一位51÷12=4·····3

5. 余数乘10加上被除数的下一位31÷12=2·····7

得到答案11311÷12=942······7


**2016.7.3 修正 0 不输出的问题**

``` cpp
bigNumber operator / (const bigNumber rhs)const{
    bigNumber a;
    int it=num[0];

    bigNumber d;
    bigNumber c;

    while(it>0){
        a=(d*10)+num[it];
        c=c*10;

        int t;
        REP(9){
            if(a < rhs * (o+1)){
                t=o;
                break;
            }
            t=9;
        }
        c=c+t;
        d=a-rhs*t;
        it--;
    }
    return c;
}
```

## 取余
稍加修改，就成了取余
``` cpp
bigNumber operator % (const bigNumber rhs)const{
    bigNumber a;
    int it=num[0];

    bigNumber d;
    bigNumber c;

    while(it>0){
        a=(d*10)+num[it];
        c=c*10;

        int t;
        REP(9){
            if(a < rhs * (o+1)){
                t=o;
                break;
            }
            t=9;
        }
        c=c+t;
        d=a-rhs*t;
        it--;
    }
    return d;
}
```

## 完整的代码  

高精度算法：

``` cpp
class bigNumber{
    private:
    int num[1001];

    public:
    bigNumber(){
        init();
    }
    void init(){
        memset(num,0,sizeof(num));
    }
    bigNumber operator = (const bigNumber& rhs){
        init();
        REP(rhs.num[0]+1)num[o]=rhs.num[o];
        return *this;
    }
    bigNumber operator = (long long rhs){
        init();
        int i=1;
        while(rhs){
            num[i]=rhs%10;
            rhs/=10;
            i++;
        }
        num[0]=i-1;
        return *this;
    }
    bool operator < (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]<rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-o;
            if(num[temp]!=rhs.num[temp])return (num[temp]<rhs.num[temp]);
        }
        return 0;
    }
    bool operator > (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]>rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-o;
            if(num[temp]!=rhs.num[temp])return (num[temp]>rhs.num[temp]);
        }
        return 0;
    }
    bool operator == (const bigNumber rhs)const{
        return !(*this>rhs||*this<rhs);
    }
    bool operator <= (const bigNumber rhs)const{
        return *this<rhs||*this ==rhs;
    }
    bigNumber operator + (const bigNumber rhs)const{
        bigNumber temp;
        int len;
        len=num[0]>rhs.num[0]?num[0]:rhs.num[0];
        len++;
        REP(len){
            temp.num[o+1]+=num[o+1]+rhs.num[o+1];
            temp.num[o+2]+=temp.num[o+1]/10;
            temp.num[o+1]%=10;
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator + (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 + temp2;
    }
    bigNumber operator * (const bigNumber rhs)const{
        bigNumber temp;
        int len;
        len=num[0]+rhs.num[0];
        //len++;
        for(int i=1;i<=num[0];i++){
            for(int j=1;j<=rhs.num[0];j++){
                temp.num[i+j-1]+=num[i]*rhs.num[j];
                temp.num[i+j]+=temp.num[i+j-1]/10;
                temp.num[i+j-1]%=10;
            }
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator * (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 * temp2;
    }
    bigNumber operator - (const bigNumber rhs)const{
        bigNumber temp,a,b;
        temp=Max(*this,rhs);
        b=Min(*this,rhs);
        a=temp;
        temp=0;
        int len=a.num[0];
        REP(len){
            temp.num[o+1]+=10+a.num[o+1]-b.num[o+1];
            temp.num[o+2]--;
            temp.num[o+2]+=temp.num[o+1]/10;
            temp.num[o+1]%=10;
        }
        REP(len){
            if(temp.num[len-o]!=0){
                temp.num[0]=len-o;
                break;
            }
        }
        return temp;
    }
    bigNumber operator - (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 - temp2;
    }
    bigNumber operator / (const bigNumber rhs)const{
        bigNumber a;
        int it=num[0];

        bigNumber d;
        bigNumber c;

        while(it>0){
            a=(d*10)+num[it];
            c=c*10;

            int t;
            REP(9){
                if(a < rhs * (o+1)){
                    t=o;
                    break;
                }
                t=9;
            }
            c=c+t;
            d=a-rhs*t;
            it--;
        }
        return c;
    }
    bigNumber operator / (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 / temp2;
    }
    bigNumber operator % (const bigNumber rhs)const{
        bigNumber a;
        int it=num[0];

        bigNumber d;
        bigNumber c;



        while(it>0){

            a=(d*10)+num[it];
            c=c*10;

            int t;
            REP(9){
                if(a < rhs * (o+1)){
                    t=o;
                    break;
                }
                t=9;
            }
            c=c+t;
            d=a-rhs*t;
            it--;
        }
        return d;
    }
    bigNumber operator % (const long long rhs)const{
        bigNumber temp1,temp2;
        temp1=*this;
        temp2=rhs;
        return temp1 % temp2;
    }
    void p(){
        if(num[0] == 0)
			printf("0");
        REP(num[0]){
            printf("%d",num[num[0]-o]);
        }
    }
};
```