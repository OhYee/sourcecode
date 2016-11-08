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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 100005;

int n,k;
int a[maxn];
int dp[maxn];

map<int,int> m;

bool Do() {

    if(!(cin >> n >> k))
        return false;

    int pos;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i] == k)
            pos = i;
    }

    m.clear();
    dp[pos] = 0;
    int ans = 1;
    m.insert(pair<int,int>(0,1));

    for(int i = pos - 1;i >= 0;i--) {
        dp[i] = dp[i + 1] + ((a[i] > k) ? 1 : -1);
        
        if(dp[i] == 0)
            ans++;

        if(m.count(dp[i])==0)
            m.insert(pair<int,int>(dp[i],0));
        m[dp[i]]++;
    }

    for(int i = pos + 1;i < n;i++) {
        dp[i] = dp[i - 1] + ((a[i] > k) ? 1 : -1);

        if(m.count(-dp[i]) == 1)
            ans += m[-dp[i]];
    }

    cout << ans << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());

    return 0;
}