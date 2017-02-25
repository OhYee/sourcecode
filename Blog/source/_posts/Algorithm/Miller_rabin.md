---
title: Miller_rabin 判断素数
date: 2017-02-10 20:08:37
categories: 算法
tags: 
  - 素数
  - Miller_rabin
  - 数学
keywords:
  - 费马小定理
  - 快速判断素数
---
素数在数论里是一个非常常用的内容  
而且当数非常大时,即使是 O(n) 的筛法求素数有可能也无法满足要求(空间和时间都不允许)  

因此,就有了该算法  


1. Fermat定理: 若 $n$ 是奇素数，$a$ 是任意正整数$(1≤ a≤ n−1)$，则 $a^{n-1} ≡ 1 \; mod \; n$。
2. 二次探测定理: 如果n是一个奇素数，将 $n−1$ 表示成 $2^s*r$ 的形式，$r$ 是奇数，$a$ 与 $n$ 是互素的任何随机整数，那么 $a^r ≡ 1 \; mod \; n$ 或者对某个 $j (0 ≤ j≤ s−1, j∈Z)$ 等式 $a^{2jr} ≡ −1 \; mod \; n $ 成立。

最后可知,当对于任意数 $a$,有 $a^r ≡ 1 \; mod \; n$ 或者对某个 $j (0 ≤ j≤ s−1, j∈Z)$ 等式 $a^(2jr) ≡ −1 \; mod \; n$ 则可得知 $a$ 为素数  

实际使用时,只需要随机出几个 $a$ ,只要这些情况下都满足,则可以近似认为待判断数为素数  

大概这个意思,反正会不会证明都不影响使用  

模板如下  
记得包含 `#include<ctime>` 和初始化随机数种子  
<div><div class="fold_hider"><div class="close hider_title">点击显/隐代码</div></div><div class="fold">```cpp Miller_rabin判断素数
// Miller_rabin 判断素数
const int times = 20; //测试次数

LL Random(LL n ){//生成[ 0 , n ]的随机数  
    return ((double)rand() / RAND_MAX*n + 0.5);  
}  

//快速计算 (a*b) % mod
/*
LL mul_mod(LL a, LL b, LL mod){
    LL ans = 0;  
    while(b){  
        if(b & 1){  
            b--;  
            ans =(ans+ a)%mod;  
        }  
        b /= 2;  
        a = (a + a) % mod;  
  
    }  
    return ans;  
}
*/
inline LL mul_mod(LL a,LL b,LL mod){
    a=(a % mod + mod) % mod;
    b=(b % mod + mod) % mod;
    return ((a*b-(LL)((long double)a/mod*b+.5L)*mod)%mod+mod)%mod;
}
  
LL exp_mod(LL a, LL b, LL mod ){ //快速计算 (a^b) % mod  
    LL ans = 1;  
    while(b){  
        if(b & 1)
            ans = mul_mod(ans,a,mod);  
        b /= 2;  
        a = mul_mod(a,a,mod);  
    }  
    return ans;  
}  
  
bool witness( LL a, LL n ){ //miller_rabin算法的精华  
    //用检验算子a来检验n是不是素数 
    //a^r ≡ 1 mod n或者对某个j (0 ≤ j≤ s−1, j∈Z) 等式a^(2jr) ≡ −1 mod n 
    LL tem = n - 1;  
    int j = 0;  
    while(tem % 2 == 0){  
        tem /= 2;  
        j++;  
    }  
    //将n-1拆分为a^r * s  
  
    LL x = exp_mod( a, tem, n ); //得到a^r mod n  
    if(x == 1 || x == n - 1) return true;   //余数为1则为素数  
    while(j--){ //否则试验条件2看是否有满足的 j    
        x = mul_mod( x, x, n );  
        if(x == n - 1) return true;  
    }  
    return false;  
}  
  
bool miller_rabin( LL n ){  //检验n是否是素数    
    if(n == 2)  
        return true;  
    if(n < 2 || n % 2 == 0)  //如果是2则是素数，如果<2或者是>2的偶数则不是素数
        return false;
  
    for(int i = 1; i <= times; i++){ //做times次随机检验   
        LL a = Random(n - 2) + 1; //得到随机检验算子 a  
        if(!witness(a, n)) //用a检验n是否是素数  
            return false;  
    }  
    return true;  
}  


int solve(ll n){
    ll p = 2;
    while(n>1){
        cout<<"\t"<<n<<" "<<p<<endl;
        if(n%p)
            p++;
        else
            n/=p;
    }
    return p;
}
```
</div></div>