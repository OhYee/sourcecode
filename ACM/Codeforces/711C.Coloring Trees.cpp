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
using namespace std;

typedef __int64 LL;

const LL INF = 0x7FFFFFFFFFFFFFFF/2;
const int maxn = 105;

int tree[maxn];
int p[maxn][maxn];
LL dp[maxn][maxn][maxn];
int n,m,k;

void DP(int i,int ln,int tn) {
    for(int j = k;j >= 1;j--)
        if(ln == tn)
            dp[j][i][tn] = min(dp[j][i][tn],dp[j][i - 1][ln] + p[i][tn]);
        else
            dp[j][i][tn] = min(dp[j][i][tn],dp[j - 1][i - 1][ln] + p[i][tn]);
}

void TN(int i,int ln) {
    if(tree[i] == 0) {
        for(int j = 1;j <= m;j++)
            DP(i,ln,j);
    } else {
        DP(i,ln,tree[i]);
    }
}

void LN(int i) {
    if(tree[i - 1] == 0 && i != 1) {
        for(int j = 1;j <= m;j++)
            TN(i,j);
    } else {
        TN(i,tree[i - 1]);
    }
}

bool  Do() {

    if(!(cin >> n >> m >> k))
        return false;

    for(int i = 1;i <= n;i++)
        cin >> tree[i];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> p[i][j];
            if(j == tree[i])
                p[i][j] = 0;
        }

    for(int i = 0;i <= k;i++)
        for(int j = 0;j <= n;j++)
            for(int o = 0;o <= m;o++)
                dp[i][j][o] = INF;
    dp[0][0][0] = 0;

    for(int i = 1;i <= n;i++) {
        LN(i);
    }

    LL Min = INF;
    for(int i = 1;i <= m;i++)
        Min = min(Min,dp[k][n][i]);
    if(Min == INF)
        Min = -1;

    cout << Min << endl;

    return true;
}

int main() {
    while(Do());
    return 0;
}