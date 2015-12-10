#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL exp_mod(LL a,LL n,LL b){
    LL t;
    if(n==0) return 1%b;
    if(n==1) return a%b;
    t=exp_mod(a,n/2,b);
    t=t*t%b;
    if((n&1)==1) t=t*a%b;
    return t;
}
int b,p,k;
int main(){
    freopen("dmod.in","r",stdin);
    freopen("dmod.out","w",stdout);
    cin>>b>>p>>k;
    cout<<exp_mod(b,p,k);
    return 0;
}
