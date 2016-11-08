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
const int INF = 0x7FFFFFFF;
const int maxn = 105;
const int delta[] = {1,-1,0,0};

int Map[maxn][maxn];
int dp[maxn];
int sum[maxn][maxn];

int n;

int DP(int s,int v) {
    int Max = -INF;
    for(int i = 1;i <= n;i++) {
        int t = sum[v][i] - sum[s][i];
        dp[i] = max(dp[i - 1] + t,t);
        Max = max(Max,dp[i]);
    }
    return Max;
}

bool Do() {
    if(scanf("%d",&n) == EOF)
        return false;

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            scanf("%d",&Map[i][j]);
            sum[i][j] = sum[i - 1][j] + Map[i][j];
        }
    int Max = -INF;
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < i;j++) {
            Max = max(Max,DP(j,i));
        }

    printf("%d\n",Max);

    return true;
}

int main() {
    while(Do());
    return 0;
}