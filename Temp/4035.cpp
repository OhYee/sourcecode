#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define Log(format, ...) printf(format, ##__VA_ARGS__)
const int maxn = 10005;

int n;
int parent[maxn];
double E[maxn], K[maxn];
double dp[maxn];
vector<int> Edges[maxn];

void init() {
    memset(parent, 0, (n + 5) * sizeof(int));
    for (int i = 0; i <= n; ++i)
        Edges[i].clear();
}

void addEdge(int u, int v) {
    Edges[u].push_back(v);
    Edges[v].push_back(u);
}

void dfs(int t) {
    Log("dfs(%d)\n", t);
    dp[t] = 1.0;
    for (auto child : Edges[t]) {
        if (parent[t] != child) {
            parent[child] = t;
            dfs(child);
            dp[t] += dp[child] * (1 - K[child]) + 1.0 * E[child] / 100;
            Log("t:%d child:%d  dp+= %.9f + %.9f\n", t, child,
                dp[child] * (1 - K[child]), 1.0 * E[child] / 100);
        }
    }
    dp[t] *= (100.0 - K[t]) / 100;
    printf("dp[%d]=%.9f\n", t, dp[t]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d", &n);
        init();
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            int k, e;
            scanf("%d%d", &k, &e);
            K[i] = 1.0 * k / 100;
            E[i] = 1.0 * e / 100;
        }
        dfs(1);
        printf("Case %d: %.9f\n", kase, dp[1]);
    }

    return 0;
}