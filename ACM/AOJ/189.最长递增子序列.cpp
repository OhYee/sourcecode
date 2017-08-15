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
 
const int maxn = 7005;
 
LL a[maxn];
LL dp[maxn];
 
inline LL max(LL a,LL b) {
    return a > b ? a : b;
}
 
bool Do() {
    LL n;
    if(scanf("%u",&n) == EOF)
        return false;
    for(LL i = 1;i <= n;i++) {
        scanf("%u",&a[i]);
        dp[i] = 0;
    }
 
    LL Max = 0;
    for(LL i = 1;i <= n;i++) {
        for(LL j = 0;j < i;j++)
            if(a[i] > a[j] || j == 0)
                dp[i] = max(dp[i],dp[j] + 1);
        Max = max(Max,dp[i]);
    }
 
    printf("%u\n",Max);
    return true;
}
int main() {
    while(Do());
    return 0;
}