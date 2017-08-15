/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/
 
かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
 
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
//DEBUG MODE
#define debug 0
 
//循环
#define REP(n) for(int o=0;o<n;o++)
 
const int maxn = 500005;
 
int dp[maxn];
int value[maxn],per[maxn];
int v;
 
void CompletePack(int cost,int weight) {
    for(int i = cost; i <= v; i++)
        dp[i] = max(dp[i],dp[i - cost] + weight);
}
 
bool Do() {
    int n,m,p;
 
    if(scanf("%d%d%d",&n,&m,&p) == EOF)
        return false;
    for(int i = 1;i <= p;i++)
        scanf("%d%d",&value[i],&per[i]);
 
    v = n / 1000;
    while(m--) {
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= p;i++)
            CompletePack(value[i] / 1000,per[i]);
        n += dp[v];
        v = n / 1000;
    }
 
 
    printf("%d\n",n);
 
    return true;
}
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}   