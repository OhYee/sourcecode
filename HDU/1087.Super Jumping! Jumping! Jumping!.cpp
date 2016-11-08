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

const int maxn = 1005;
int a[maxn];
int dp[maxn];

bool  Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    int Max = 0;
    a[0] = 0;
    for(int i = 0;i <= n;i++) {
        dp[i] = 0;
        for(int j = 0;j < i;j++) 
            if(a[i] > a[j])
                dp[i] = max(dp[i],dp[j] + a[i]);
        Max = max(Max,dp[i]);
    }
    printf("%d\n",Max);
    return true;
}

int main() {
    while(Do());
    return 0;
}