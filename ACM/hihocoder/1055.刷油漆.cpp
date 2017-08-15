#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define Log(d, format, ...)

const int maxn = 105;

int w[maxn];
vector<int> children[maxn];
int dp[maxn][maxn];
int n, m;

void init() {
    for (int i = 0; i <= n; i++)
        children[i].clear();
    memset(dp, 0, sizeof(dp));
}
void addEdge(int u, int v) { children[u].push_back(v); }

void dfs(int x) {
    vector<int>::iterator child = children[x].begin();
    while (child != children[x].end()) {
        dfs(*child);
        for (int i = m; i > 1; --i) {
            for (int j = 1; j < i; ++j) {
                dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[*child][j]);
                Log(0, "dp[%d][%d]=%d\n", i, j, dp[i][j]);
            }
        }
        ++child;
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int i = 1; i <= n; i++)
            scanf("%d", &dp[i][1]);
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        dfs(1);
        printf("%d\n", dp[1][m]);
    }
}