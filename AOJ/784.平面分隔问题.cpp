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
 
int Dp[maxn];
int dp(int n) {
    return Dp[n] = Dp[n]?Dp[n]:dp(n - 1) + 2*(n - 1);
}
 
bool  Do() {
    int n;
    scanf("%d",&n);
    if(n==0)
        return false;
 
    printf("%d\n",dp(n));
 
    return true;
}
 
int main() {
    Dp[1] = 2;
    while(Do());
    return 0;
}