#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=10000;
int main(){
    int count[maxn+1]={0};
    //memset(count,0,sizeof(count));


    long prime[maxn]={0},num_prime=0;
    bool isNotPrime[maxn]={1,1};

    for(long i=2;i<maxn;i++){//从2开始
        if(!isNotPrime[i])prime[num_prime++]=i;//如果是素数，记录i
        for(long j=0;j<num_prime&&i*prime[j]<maxn;j++){//从0开始
            isNotPrime[i*prime[j]]=true;//不是素数
            if(!(i%prime[j]))break;//
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

