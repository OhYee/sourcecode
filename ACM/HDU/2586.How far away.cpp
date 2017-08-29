#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

const int maxn = 40005;
const int maxlog = 17;

int n, m;

struct Edge {
    int c, w;
    Edge(int _c = 0, int _w = 0) : c(_c), w(_w) {}
};

vector<Edge> edges[maxn];

void addEdge(int u, int v, int w) {
    Log("addEdge(%d,%d,%d)\n", u, v, w);

    edges[u].push_back(Edge(v, w));
    edges[v].push_back(Edge(u, w));
}

int depth[maxn];
int parent[maxn][maxlog];
int weight[maxn][maxlog];

void lca() {
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            weight[i][j] = weight[i][j - 1] + weight[parent[i][j - 1]][j - 1];
        }
    }
}

int query(int a, int b) {
    Log("Log(%d,%d)\n", a, b);

    int ans = 0;
    if (depth[a] < depth[b])
        swap(a, b);
    while (depth[a] != depth[b]) {
        int dis = depth[a] - depth[b];
        int step = (int)(log(dis) / log(2));
        Log("\t%d->%d (%d)\n", a, parent[a][step], weight[a][step]);
        ans += weight[a][step]; // 由于这里还要用到a,因此a要在后面再赋值
        a = parent[a][step];
    }
    Log("\tthe same depth %d %d\n", a, b);
    while (a != b) {
        int step = 0;
        for (int i = 0; i < maxlog; ++i) {
            if (parent[a][i] == parent[b][i]) {
                step = i - (i ? 1 : 0);
                break;
            }
        }
        Log("\tstep: %d a: %d->%d (%d)  b: %d->%d (%d)\n", step, a,
            parent[a][step], weight[a][step], b, parent[b][step],
            weight[b][step]);
        ans += weight[a][step] + weight[b][step];
        a = parent[a][step];
        b = parent[b][step];
    }
    return ans;
}

void dfs(int t, int deep) {
    depth[t] = deep;
    for (auto edge : edges[t]) {
        int child = edge.c;
        if (parent[t][0] != child) {
            parent[child][0] = t;
            weight[child][0] = edge.w;
            dfs(child, deep + 1);
        }
    }
}

void init() {
    memset(parent, 0, sizeof(parent));
    for (int i = 0; i <= n; ++i) {
        edges[i].clear();
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();

        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }

        dfs(1, 0);
        lca();

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }
    return 0;
}