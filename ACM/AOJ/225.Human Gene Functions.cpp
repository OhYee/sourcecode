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
const int INF = 0x7FFFFFFF;
const int maxn = 105;

int lena,lenb;
char a[maxn],b[maxn],lcs[maxn];
int dp[maxn][maxn];

int w[5][5] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,-INF}
};
inline int m(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return 4;
    }
}

void Do() {
    scanf("%d%s%d%s",&lena,a,&lenb,b);

    dp[0][0] = 0;
    for(int i = 1;i <= lena;i++)
        dp[i][0] = dp[i - 1][0] + w[m(a[i - 1])][4];
    for(int i = 1;i <= lenb;i++)
        dp[0][i] = dp[0][i - 1] + w[4][m(b[i - 1])];

    for(int i = 1;i <= lena;i++)
        for(int j = 1;j <= lenb;j++) {
            int ita = m(a[i - 1]),itb = m(b[j - 1]);
            dp[i][j] = dp[i - 1][j - 1] + w[ita][itb];
            dp[i][j] = max(dp[i][j],dp[i - 1][j] + w[ita][4]);
            dp[i][j] = max(dp[i][j],dp[i][j - 1] + w[4][itb]);
        }

    printf("%d\n",dp[lena][lenb]);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}