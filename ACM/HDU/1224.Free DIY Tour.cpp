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

const int maxn = 105;


int value[maxn];
bool Map[maxn][maxn];
int dp[maxn];
int last[maxn];
stack<int> s;

void Do() {
    memset(Map,false,sizeof(Map));
    memset(dp,false,sizeof(dp));

    int n,m;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> value[i];
    value[n + 1] = 0;

    cin >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        Map[a][b] = true;
    }

    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n + 1;j++)
            if(Map[i][j])
                if(dp[j] < dp[i] + value[j]) {
                    dp[j] = dp[i] + value[j];
                    last[j] = i;
                }
    last[1] = 0;

    cout << "points : " << dp[n + 1] << endl;
    int k = n + 1;
    while(k) {
        s.push(k);
        k = last[k];
    }
    cout << "circuit : ";
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        if(t != 1)
            cout << "->";
        if(t == n + 1)
            t = 1;
        cout << t;
    }
    cout << endl;
    return;
}
int main() {
    cin.tie(0);
    std::cin.sync_with_stdio(false);

    int T;
    cin >> T;
    for(int kase = 1;kase <= T;kase++) {
        if(kase != 1)
            cout << endl;
        cout << "CASE " << kase << "#" << endl;
        Do();
    }


    return 0;
}