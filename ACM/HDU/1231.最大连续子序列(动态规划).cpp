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

const int INF = 0x7FFFFFFF;

const int maxn = 10005;
int dp[maxn];
int a[maxn];

bool Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;

    memset(dp,0,sizeof(dp));

    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
        dp[i] = max(dp[i - 1] + a[i],a[i]);
    }


    int begin,end = a[1],Max = dp[1],pos=1;
    for(int i = 1;i <= n;i++) {
        if(dp[i] > Max) {
            Max = dp[i];
            end = a[i];
            pos = i;
        }
    }
    int sum = 0;
    begin = a[pos];
    for(int i = pos;i > 0;i--) {
        if(Max > sum) {
            sum += a[i];
            begin = a[i];
        } else {
            break;
        }
    }
    if(Max >= 0)
        printf("%d %d %d\n",Max,begin,end);
    else
        printf("%d %d %d\n",0,a[1],a[n]);
    return true;
}

int main() {

    while(Do());
    return 0;
}