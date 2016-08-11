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
 
const int maxn = 100005;
const int maxk = 17;
 
int num[maxn];
int Max[maxn][maxk];
int Min[maxn][maxk];
 
int n,m;
 
int pow(int a,int n) {
    if(a == 2)
        return 1 << n;
    if(n == 1)
        return a;
    return pow(a,n / 2) * pow(a,n / 2) * (n & 1 ? a : 1);
}
 
bool Do() {
    if(!(cin >> n >> m))
        return false;
    for(int i = 1;i <= n;i++)
        cin >> num[i];
 
    /*ST算法*/
    for(int k = 0;pow(2,k) <= n;k++) {
        for(int i = 1;i + pow(2,k) - 1 <= n;i++) {
            //dp[i][k] 为 (i,j)区间的最值
            if(k == 0) {
                Max[i][k] = Min[i][k] = num[i];
            } else {
                Max[i][k] = max(Max[i][k - 1],Max[i + pow(2,k - 1)][k - 1]);
                Min[i][k] = min(Min[i][k - 1],Min[i + pow(2,k - 1)][k - 1]);
            }
        }
    }
 
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        int k = (int)(log(b - a + 1.0) / log(2.0));
        cout << max(Max[a][k],Max[b - pow(2,k) + 1][k]) - min(Min[a][k],Min[b - pow(2,k) + 1][k]) << endl;
    }
 
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
 
    while(Do());
    return 0;
}