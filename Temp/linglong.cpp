51//*/
#define debug
#include <ctime>
//*/
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;


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


int solve(LL n){

    int p = n;
    int cnt=0;
    int ans=1;
    while(n>=p){
        while(p >=  2 && !miller_rabin(--p));
        if(p>=2){
            while(!(n%p)){
                n/=p;
                cnt++;
            }
            ans *= cnt?cnt+1:1;
            //cout<<p<<"-"<<cnt<<endl;
        }
    }
    //cout<<p<<"-"<<cnt<<endl;
    return ans *= cnt?cnt+1:1;
}

int main() {
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        LL a,b;
        cin>>a>>b;
        cout<<solve(a)<<endl;
    }


    #ifdef debug
    printf("Time:%.3fs.", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}