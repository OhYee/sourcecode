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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

typedef long long LL;

const int INF = 0x7FFFFFFF / 2;
const double eps = 1e-10;

const int maxn = 105;

const int Zero = 100 * 1000 + 5;
const int maxV = 2 * Zero;

int F[maxn],S[maxn];
int dp[maxV];
int *dp_zero = &dp[Zero];

int upv,lowv;

void ZeroOnePack(int cost,int weight) {
    if(cost > 0)
        for(int i = upv; i >= lowv; i--)
            dp_zero[i] = max(dp_zero[i],dp_zero[i - cost] + weight);
    else
        for(int i = lowv; i <= upv; i++)
            dp_zero[i] = max(dp_zero[i],dp_zero[i - cost] + weight);
}

bool Do() {
    int n;
    if(!(cin >> n))
        return false;

    for(int i = 1;i <= n;i++) {
        cin >> S[i] >> F[i];
        if(S[i] >= 0)
            upv += S[i];
        else
            lowv += S[i];
    }

    for(int i = 0;i < maxV;i++)
        dp[i] = -INF;
    dp_zero[0] = 0;

    for(int i = 1;i <= n;i++)
        ZeroOnePack(S[i],F[i]);

    int Max = 0;
    for(int i = 0;i < upv;i++) {
        if(dp_zero[i] >= 0)
            Max = max(dp_zero[i] + i,Max);
    }

    cout << Max << endl;
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    while(Do());

    return 0;
}