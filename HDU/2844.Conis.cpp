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

const int maxn = 105;
const int maxm = 100005;
int v;
int dp[maxm];

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
int value[maxn];
int number[maxn];

bool Do() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 0 && m == 0)
        return false;

    for(int i = 1;i <= n;i++)
        scanf("%d",&value[i]);
    for(int i = 1;i <= n;i++)
        scanf("%d",&number[i]);

    v = m;
    memset(dp,0,sizeof(dp));

    for(int i = 1;i <= n;i++) {
        MultiplePack(value[i],value[i],number[i]);
    }
    int cnt = 0;
    for(int i = 1;i <= m;i++) {
        if(dp[i] != dp[i - 1])
            cnt++;
    }

    printf("%d\n",cnt);
    return true;
}

int main() {
    while(Do());
    return 0;
}