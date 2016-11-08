/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

#define t(n) (((n) * ((n)+1))/2)

const int maxn = 1005;
int n;
int a[t(maxn)];
int dp[t(maxn)];

int left(int n) {
    int i;
    for(i = 0;t(i) < n;i++);
    return n + i;
}

bool Do() {
    if(scanf("%d",&n) == EOF)
        return false;
    for(int i = 1;i <= t(n);i++)
        scanf("%d",&a[i]);

    memset(dp,0,sizeof(dp));
    for(int i = 0;i <= t(n - 1);i++) {
        dp[left(i)] = max(dp[left(i)],dp[i] + a[left(i)]);
        dp[left(i) + 1] = max(dp[left(i) + 1],dp[i] + a[left(i) + 1]);
    }

    int Max = -1;
    for(int i = t(n - 1) + 1;i <= t(n);i++)
        Max = max(Max,dp[i]);

    printf("%d\n",Max);
    return true;
}

int main() {
    while(Do());
    return 0;
}