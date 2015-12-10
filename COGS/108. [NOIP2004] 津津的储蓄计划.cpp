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

/*
#############################################################
*/

int main(){
    freopen("save.in","r",stdin);
    #if !debug
    freopen("save.out","w",stdout);
    #endif // debug

    int money=0,save=0,budget;
    REP(12){
        cin>>budget;
        money+=300;
        int temp=money-budget;
        #if debug
        printf("%d月预算%d 还有%d元\n",o+1,budget,money);
        #endif // debug
        if(temp<0){
            printf("-%d",o+1);
            return 0;
        }
        temp/=100;
        temp*=100;
        save+=temp;
        money-=temp+budget;
        #if debug
        printf("   存入%d元 还有%d元\n",temp,money);
        #endif // debug
    }
    double sum=money+save*1.2+0.5;
    printf("%d",(int)sum);
    return 0;
}
