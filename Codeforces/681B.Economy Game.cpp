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

const long long A = 1234567;
const long long B = 123456;
const long long C = 1234;

const int maxn = 27406118;
bool dp[maxn];


bool Do() {

    int n;
    bool OK = false;

    if(scanf("%d",&n) == EOF)
        return false;

    

    /*for(long long i = 0;(i*C <= n) && !OK;i++) {
        for(long long j = 0;(i*C + j*B <= n) && !OK;j++) {
            for(long long k = 0;(i*C + j*B + k*A <= n) && !OK;k++) {
                if(i*C + j*B + k*A == n) {
                    OK = true;
                    printf("%lld %lld %lld \n",i,j,k);
                }
            }
        }
    }*/
    if(n>=maxn||dp[n])
        printf("YES\n");
    else
        printf("NO\n");

    return true;
}

int main() {
    memset(dp,false,sizeof(dp));
    dp[0] = true;
    for(int i = 1;i < maxn;i++) {
        if((i - A >= 0 && dp[i - A]) || (i - B >= 0 && dp[i - B]) || (i - C >= 0 && dp[i - C]))
            dp[i] = true;
    }
    while(Do());
    return 0;
}