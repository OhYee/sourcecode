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

const int maxn = 105;

double P,p[maxn];
int N,m[maxn];

int v;

double dp[maxn*maxn];

void ZeroOnePack(int cost,double weight) {
    for(int i = v; i >= cost; i--)
        dp[i] = max(dp[i],dp[i - cost] * weight);
}

void Do() {
    //初始化数据
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    v = 0;

    //数据输入
    scanf("%lf%d",&P,&N);
    for(int i = 1;i <= N;i++) {
        scanf("%d%lf",&m[i],&p[i]);
        v += m[i];
    }

    //dp
    for(int i = 1;i <= N;i++)
        ZeroOnePack(m[i],1-p[i]);

    int ans;
    for(ans = v;ans > 0;ans--) {
        if(dp[ans] >= 1-P)
            break;
    }

    printf("%d\n",ans);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        Do();
    }
    return 0;
}