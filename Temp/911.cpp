#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 200005;

vector<int> e[maxn];
int n;
int parent[maxn];
int dp[maxn][2];

void init() {
    memset(parent, 0, (n + 5) * sizeof(int));
    for (int i = 0; i <= n; ++i)
        e[i].clear();
}

void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}

void dfs(int t) {
    printf("dfs(%d)\n", t);
    dp[t][0] = dp[t][1] = 0;
    for (auto child : e[t]) {
        if (parent[t] != child) {
            parent[child] = t;
            dfs(child);
            dp[t][0] += max(dp[child][1], dp[child][0]);
            dp[t][1] = max(dp[t][1], dp[child][0] + 1);
        }
    }
    printf("dp[%d]={%d,%d}\n", t, dp[t][0], dp[t][1]);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b);
        }
        dfs(1);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}