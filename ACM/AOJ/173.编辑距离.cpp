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

typedef unsigned int LL;

const int maxn = 1050;
char a[maxn],b[maxn];

LL dp[maxn][maxn];


bool Do() {
    if(scanf("%s%s",a,b) == EOF)
        return false;

    LL lena = strlen(a);
    LL lenb = strlen(b);

    for(unsigned int i = 1;i <= lena;i++)
        for(unsigned int j = 1;j <= lenb;j++) {
            int ita = i - 1;
            int itb = j - 1;
            LL delta = (i > j) ? (i - j) : (j - i);
            LL Min = min(dp[i][j - 1],dp[i - 1][j]) + 1;
            if(a[ita] == b[itb]) {
                dp[i][j] = min(dp[i - 1][j - 1],Min);
            } else {
                dp[i][j] = min(dp[i - 1][j - 1] + 1,Min);
            }
            dp[i][j] = max(dp[i][j],delta);
        }

    printf("%u\n",dp[lena][lenb]);
    return true;
}
int main() {
    dp[0][0] = 0;
    for(int i = 1;i < maxn;i++) 
        dp[0][i]=dp[i][0] = i;
    while(Do());
    return 0;
}