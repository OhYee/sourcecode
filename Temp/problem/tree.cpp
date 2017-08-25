#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000005;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

int f[maxn];
bool use[maxm];

vector<int> edges[maxn];
int parent[maxn];
int depth[maxn];
int weight[maxn];

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

int main() {
    // int size = 256 << 20; // 256MB
    // char *p = (char *)malloc(size) + size;
    //__asm__("movl %0, %%esp\n" ::"r"(p));

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);

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

    parent[1] = 0;
    weight[1] = INF;
    lca(1, 0);

    sort(e, e + m, compare);

    for (int i = 0; i < m; ++i) {
        if (use[i]) {
            printf("Ohyee\n");
        } else {
            printf("%d\n", query(e[i].u, e[i].v, n));
        }
    }

    return 0;
}