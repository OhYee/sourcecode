#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define LOG(format, ...) printf(format, ##__VA_ARGS__)

typedef long long ll;
const int INF = 1e9 + 7;
const int maxn = 6e4 + 7;
int n, k;
int que1[maxn], que2[maxn], pos2[maxn]; //两个队伍，以及第二个队伍每个人对应位置
bool cmp(int a, int b) { return a > b; }
vector<int> g[2 * maxn];
int dp[maxn][27];

int dfs(int x, int y, int deep) {
    // for (int i = 0; i < deep; i++)
    //    LOG("\t");
    // LOG("dfs(%d,%d)\n", x, y);

    if (!x || !y)
        return x + y; //如果某点为0，那么剩余的那个队伍就一个一个的减去
    if (abs(que1[x] - que2[y]) <= k) {
        int &v = dp[que1[x]][que1[x] - que2[y] + k];
        if (v)
            return v;
        return v = min(dfs(x - 1, y, deep + 1), dfs(x, y - 1, deep + 1)) + 1;
    } //两个值之差小于k，暴力dp

    LOG("lower_bound(%d) in dfs(%d,%d)\n", x,x,y);
    vector<int>::iterator it =
        lower_bound(g[x - y + n].begin(), g[x - y + n].end(), x,
                    cmp); //二分预先处理出来的数组。
    if (it == g[x - y + n].end()) {
        LOG("not find\n");
        return max(x, y); //如果以该距离差剩下的不存在小于k的
    }

    int v = *it;
    LOG("it = %d\n dfs(%d,%d)+%d\n",v, v, y - x + v, x - v);
    return dfs(v, y - x + v, deep + 1) + x -
           v; //把中间那些等距且差值大于k的加入
}

void solve() {
    for (int i = n; i >= 1; i--) {
        for (int j = que1[i] - k; j <= que1[i] + k; j++) {
            if (j >= 1 && j <= n) {
                g[i - pos2[j] + n].push_back(i);
                LOG("g[%d(%d)].push(%d)\n", i - pos2[j] + n, i - pos2[j], i);
            }
        }
    } //处理出位置差为某个固定值且对应的值之差小于k的数组（vector）
    memset(dp, 0, sizeof(dp));
    cout << dfs(n, n, 1) << endl;
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i <= 2 * n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", que1 + i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", que2 + i);
            pos2[que2[i]] = i;
        } //输入
        solve();
    }
    return 0;
}
