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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxm = 55;
const int maxn = 105;

int n,m;
int score[maxm][maxm];
int note[maxn];
int dp[maxn][maxm];

void DP(int i,int ln,int tn) {
    dp[i][tn] = max(dp[i][tn],dp[i - 1][ln] + score[ln][tn]);
}

void TN(int i,int ln) {
    if(note[i] < 0) {
        for(int j = 1;j <= m;j++)
            DP(i,ln,j);
    } else {
        DP(i,ln,note[i]);
    }
}

void LN(int i) {
    if(note[i - 1] < 0) {
        for(int j = 1;j <= m;j++)
            TN(i,j);
    } else {
        TN(i,note[i - 1]);
    }
}

void Do() {

    cin >> n >> m;
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= m;j++)
            cin >> score[i][j];
    for(int i = 0;i < n;i++)
        cin >> note[i];

    memset(dp,0,sizeof(dp));
    for(int i = 1;i < n;i++) {
        LN(i);
    }

    int Max = 0;
    for(int i = 1;i <= m;i++)
        Max = max(Max,dp[n - 1][i]);

    cout << Max << endl;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)
        Do();

    return 0;
}