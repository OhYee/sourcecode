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

const int maxn = 5005;

int a[maxn];
int dp[maxn];
int cnt[maxn];

bool Do() {
    int n;

    if(scanf("%d",&n) == EOF)
        return false;

    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
    }

    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    cnt[0] = 1;

    int Max = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i - 1;j >= 0;j--)
            if(a[j] > a[i] || j == 0)
                dp[i] = max(dp[i],dp[j] + 1);
        Max = max(dp[i],Max);
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i - 1;j >= 0;j--) {
            if(a[i] == a[j])
                break;
            if(dp[i] == dp[j] + 1 && (a[i] <= a[j] || j == 0)) {
                cnt[i] += cnt[j];
            }
        }
    }

    int num = 0;
    for(int i = 1;i <= n;i++) {
        if(Max == dp[i])
            num += cnt[i];
    }

    printf("%d %d\n",Max,num);

    return true;

}
int main() {
    while(Do());
    return 0;
}