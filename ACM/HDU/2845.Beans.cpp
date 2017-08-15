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

const int maxn = 200005;
int numt[maxn];
int num[maxn];
int dp[maxn];
int N,M;

bool Do() {
    if(scanf("%d%d",&N,&M) == EOF)
        return false;

    memset(dp,0,sizeof(dp));

    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= M;j++) {
            int temp;
            scanf("%d",&temp);
            if(j <= 2) {
                if(j == 1)
                    numt[j] = temp;
                else
                    numt[j] = max(numt[1],temp);
            } else {
                numt[j] = max(numt[j - 1],numt[j - 2] + temp);
            }
        }
        num[i] = numt[M];
    }

    dp[1] = num[1];
    dp[2] = max(num[1],num[2]);
    for(int i = 3;i <= N;i++) {
        dp[i] = max(dp[i - 1],dp[i - 2] + num[i]);
    }

    printf("%d\n",dp[N]);
    return true;
}

int main() {
    while(Do());
    return 0;
}