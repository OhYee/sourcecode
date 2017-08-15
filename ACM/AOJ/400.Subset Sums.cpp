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
#include <bitset>
using namespace std;
 
const int maxn = 1000;
 
int v;
long long dp[maxn];
 
void ZeroOnePack(int cost,int weight) {
    for(int i = v; i >= cost; i--)
        dp[i] += dp[i - cost];
}
 
bool Do() {
    int n;
    if(!(cin >> n))
        return false;
 
    v = (1 + n)*n / 2;
 
    if(v & 1) {
        cout << 0 << endl;
    } else {
        v /= 2;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i <= n;i++) {
            ZeroOnePack(i,i);
        }
        cout << dp[v] / 2 << endl;
    }
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
 
    while(Do());
    return 0;
}