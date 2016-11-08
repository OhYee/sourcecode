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

typedef long long LL;
const int INF = 0x7FFFFFFF;
const int maxn = 100005;

int l[maxn];
int r[maxn];

LL h[maxn];


bool Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;

    for(int i = 1;i <= n;i++)
        scanf("%lld",&h[i]);

    h[0] = h[n + 1] = 0;

    for(int i = 1;i <= n;i++) {
        int t = i;
        while(t > 1 && h[i] <= h[t - 1])
            t = l[t - 1];
        l[i] = t;
    }
    for(int i = n;i >= 1;i--) {
        int t = i;
        while(t < n && h[i] <= h[t + 1])
            t = r[t + 1];
        r[i] = t;
    }
    LL Max = 0;
    for(int i = 1;i <= n;i++) {
        Max = max(Max,(r[i] - l[i] + 1)*h[i]);
    }
    printf("%lld\n",Max);
    return true;
}

int main() {
    while(Do());
    return 0;
}