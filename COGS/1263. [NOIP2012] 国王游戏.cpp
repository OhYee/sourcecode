#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))

class bigNumber{//高精度计算
    int num[1001];
    bigNumber(){//初始化
        memset(num,0,sizeof(num));
    }
    operator = (const bigNumber rhs)const{
        memcpy(num,rhs.num,sizeof(rhs.num));
    }
    operator = (const long long rhs)const{
        int i=1;
        while(!rhs){
            num[i]=rhs%10;
            rhs/=10;
        }
        num[0]=i-1;
    }
    operator < (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]<rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-O
            if(num[num[temp]!=rhs.num[temp])return (num[temp]<rhs.num[temp]);
        }
        return 0;
    }
    operator > (const bigNumber rhs)const{
        if(num[0]!=rhs.num[0])return (num[0]>rhs.num[0]);
        REP(num[0]){
            int temp=num[0]-O
            if(num[num[temp]!=rhs.num[temp])return (num[temp]>rhs.num[temp]);
        }
        return 0;
    }
    operator == (const bigNumber rhs)const{
        return !(this>rhs||this<rhs);
    }
    operator + (const bigNumber rhs)const{

    }
};


/*
#############################################################
*/
typedef long long LL;
int n,a,b;
int main(){
    freopen("kinggame.in","r",stdin);
    #if !debug
    freopen("kinggame.out","w",stdout);
    #endif

    cin>>n;


    return 0;
}
