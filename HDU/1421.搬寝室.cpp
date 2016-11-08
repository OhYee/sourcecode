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

const int INF = 0x7FFFFFFF/2;
const int maxn = 2005;
int a[maxn];

int dp[maxn][maxn / 2];

bool  Do() {
    int n,k;
    if(scanf("%d%d",&n,&k) == EOF)
        return false;

    dp[0][0] = 0;
    for(int i = 0;i <= n;i++)
        for(int j = 1;j <= k;j++)
            dp[i][j] = INF;

    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);

    sort(a + 1,a + 1 + n);

    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            dp[i][j] = min(
                dp[i - 1][j],
                dp[i - 2][j - 1] + (a[i] - a[i - 1])*(a[i] - a[i - 1])
            );
        }
    }
    printf("%d\n",dp[n][k]);
    return true;
}

int main() {
    while(Do());
    return 0;
}