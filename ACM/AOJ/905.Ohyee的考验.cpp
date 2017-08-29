#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

const int INF = 1000000005;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int maxlog = 18;

int n,m;
int f[maxn];
bool use[maxm];

vector<int> edges[maxn];
int parent[maxn][maxlog];
int depth[maxn];
int weight[maxn][maxlog];

struct Edge {
    int u, v;
    int w;
    int n;
    bool operator<(const Edge rhs) const { return w < rhs.w; }
} e[maxm];
bool compare(Edge a, Edge b) { return a.n < b.n; }

int pos;
int ufs(int x) { return f[x] == x ? x : f[x] = ufs(f[x]); }
int Kruskal(int n, int m) {
    int w = 0;
    for (int i = 0; i <= n; i++)
        f[i] = i;
    sort(e, e + m);
    for (int i = 0; i < m; i++) {
        int x = ufs(e[i].u), y = ufs(e[i].v);
        // printf("%d %d\n", x, y);
        if (x != y) {
            f[x] = y;
            w += e[i].w;
            use[e[i].n] = true;
            edges[e[i].u].push_back(i);
            edges[e[i].v].push_back(i);
        }
    }
    return w;
}

void addEdge(int u, int v, int w, int number = 0) {
    e[pos].u = u;
    e[pos].v = v;
    e[pos].w = w;
    e[pos].n = number;
    pos++;
}

void dfs(int t, int deep) {
    depth[t] = deep;
    for (auto edge : edges[t]) {
        int child = e[edge].u ^ e[edge].v ^ t;
        if (parent[t][0] != child) {
            parent[child][0] = t;
            weight[child][0] = e[edge].w;
            dfs(child, deep + 1);
        }
    }
}

void lca() {
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            weight[i][j] =
                min(weight[i][j - 1], weight[parent[i][j - 1]][j - 1]);
        }
    }
}

int query(int a, int b) {
    Log("Log(%d,%d)\n", a, b);

    int ans = INF;
    if (depth[a] < depth[b])
        swap(a, b);
    while (depth[a] != depth[b]) {
        int dis = depth[a] - depth[b];
        int step = (int)(log(dis) / log(2));
        Log("\t%d->%d (%d)\n", a, parent[a][step], weight[a][step]);
        ans =
            min(ans, weight[a][step]); // 由于这里还要用到a,因此a要在后面再赋值
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
        ans = min(ans, min(weight[a][step], weight[b][step]));
        a = parent[a][step];
        b = parent[b][step];
    }
    return ans;
}

/*
void lca(int t, int deep) {
    depth[t] = deep;
    vector<int>::iterator it = edges[t].begin();
    while (it != edges[t].end()) {
        int v = e[*it].u ^ e[*it].v ^ t;
        if (parent[t] != v) {
            parent[v] = t;
            weight[v] = e[*it].w;
            lca(v, deep + 1);
        }
        ++it;
    }
}

int query(int a, int b, int n) {
    int ans = INF;
    // printf("%d %d\n", a, b);
    if (depth[a] > depth[b])
        swap(a, b);

    while (depth[b] != depth[a]) {
        // printf("%d -> %d (%d)\n", b, parent[b], weight[b]);
        ans = min(ans, weight[b]);
        b = parent[b];
    }
    // printf("%d %d\n", a, b);
    while (a != b) {
        // printf("%d -> %d (%d)\n", a, parent[a], weight[a]);
        ans = min(ans, weight[a]);
        a = parent[a];

        // printf("%d -> %d (%d)\n", b, parent[b], weight[b]);
        ans = min(ans, weight[b]);
        b = parent[b];
    }

    return ans;
}
*/

int main() {
    // int size = 256 << 20; // 256MB
    // char *p = (char *)malloc(size) + size;
    //__asm__("movl %0, %%esp\n" ::"r"(p));

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (~scanf("%d%d", &n, &m)) {
        memset(use, false, (m + 5) * sizeof(bool));
        for (int i = 0; i <= n; ++i)
            edges[i].clear();

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w, i);
        }
        // printf("read finish\n");
        // printf("%d\n", Kruskal(n, m));
        Kruskal(n, m);
        // printf("build tree finish\n");

        parent[1][0] = 0;
        weight[1][0] = INF;
        dfs(1, 0);
        lca();

        sort(e, e + m, compare);

        for (int i = 0; i < m; ++i) {
            if (use[i]) {
                printf("Ohyee\n");
            } else {
                printf("%d\n", query(e[i].u, e[i].v));
            }
        }
    }

    return 0;
}