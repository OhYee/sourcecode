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
const int MOD = 10000;
int Map[maxn][maxn];
int dp[maxn][maxn];

int n,m;

int DP(int x,int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    if(dp[x][y] == 0) {
        int k = Map[x][y];
        for(int i = x;i <= x + k&&i < n;i++)
            for(int j = y;j <= y + k - (i-x) && j < m;j++)
                if(i != x || j != y)
                    dp[x][y] = (dp[x][y] + DP(i,j))%MOD;
    }
    return dp[x][y];
}


void Do() {

    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            scanf("%d",&Map[i][j]);
    
    memset(dp,0,sizeof(dp));
    dp[n - 1][m - 1] = 1;
    printf("%d\n",DP(0,0));
    return;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}