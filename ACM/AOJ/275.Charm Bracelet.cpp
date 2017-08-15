/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
 
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
 
const int maxn = 20000;
int dp[maxn];
int v;
 
void ZeroOnePack(int cost,int weight) {
    for(int i = v; i >= cost; i--)
        dp[i] = max(dp[i],dp[i - cost] + weight);
}
 
bool Do() {
    int n,m;
    if(scanf("%d%d",&n,&m) == EOF)
        return false;
 
    v = m;
    memset(dp,0,sizeof(dp));
 
    for(int i = 1;i <= n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        ZeroOnePack(a,b);
    }
 
    printf("%d\n",dp[m]);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}