/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
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
#include <functional>
using namespace std;

const int maxn = 1000;
const int maxv = 300000;
const int INF = 0x7fffffff;
int dp[maxv];
int value[maxn],num[maxn];
int Max;
int v;

void ZeroOnePack(int cost,int weight) {
    for(int i = v; i >= cost; i--)
        dp[i] = max(dp[i],dp[i - cost] + weight);
}
void CompletePack(int cost,int weight) {
    for(int i = cost; i <= v; i++)
        dp[i] = max(dp[i],dp[i - cost] + weight);
}
void MultiplePack(int cost,int weight,int n) {
    if(cost * n > v) {
        CompletePack(cost,weight);
    } else {
        int k = 1;
        while(k < n) {
            ZeroOnePack(cost * k,weight * k);
            n -= k;
            k *= 2;
        }
        ZeroOnePack(cost * n,weight * n);
    }
}

bool  Do() {
    int n;
    scanf("%d",&n);
    if(n < 0)
        return false;

    Max = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&value[i],&num[i]);
        Max += value[i] * num[i];
    }

    v = Max / 2;
    memset(dp,0,sizeof(dp));

    for(int i = 1;i <= n;i++) {
        MultiplePack(value[i],value[i],num[i]);
    }

    int ans = 0;
    for(int i = v;i >= 0;i--) {
        if(dp[i] != 0) {
            ans = dp[i];
            break;
        }
    }

    printf("%d %d\n",Max - ans,ans);
    return true;
}

int main() {
    while(Do());
    return 0;
}