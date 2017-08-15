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

typedef int LL;

const LL INF = 0x7FFFFFFF / 2;

const int maxn = 1000005;
const int maxm = 1000005;

LL dp[maxm],dp1[maxm];
int a[maxn];
int v;

bool Do() {
    int n,m;
    if(scanf("%d%d",&m,&n) == EOF)
        return false;

    dp[0] = dp1[0] = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
        dp[i] = 0;
        dp1[i] = 0;
    }

    LL Max;
    for(int j = 1;j <= m;j++) {
        Max = -INF;
        for(int i = j;i <= n;i++) {
            dp[i] = max(dp[i - 1] + a[i],dp1[i - 1] + a[i]);
            dp1[i - 1] = Max;
            Max = max(dp[i],Max);
        }
    }

    printf("%d\n",Max);
    return true;
}

int main() {
    while(Do());
    return 0;
}