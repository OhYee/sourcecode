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
 
const int maxn = 10005;
double dp[maxn];
int v;
 
void ZeroOnePack(int cost,double weight) {
    for(int i = v; i >= cost; i--)
        dp[i] = max(dp[i],dp[i - cost] + weight);
}
 
bool Do() {
    int n,m;
    double mt;
    if(scanf("%d%lf",&n,&mt) == EOF)
        return false;
 
    m = (int)(mt * 10+0.5);
    v = m;
    memset(dp,0,sizeof(dp));
 
    for(int i = 1;i <= n;i++) {
        double p,l;
        scanf("%lf%lf",&p,&l);
        ZeroOnePack((int)(p*10+0.5),l);
    }
 
    printf("%.1f\n",dp[m]);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}