#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

#define Log(format, ...) printf(format, ##__VA_ARGS__)

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n;
int w[maxn], parent[maxn];
vector<Edge> Edges[maxn];
int dp_down[maxn][2], dp_up[maxn][2];
bool vis[maxn];

void init() {
    for (int i = 0; i <= n; ++i)
        Edges[i].clear();
}

void addEdge(int u, int v, int w) {
    Edges[u].push_back(Edge(u, v, w));
    Edges[v].push_back(Edge(v, u, w));
}

void find_parent(int t) {
    Log("find_parent(%d)\n", t);
    vector<Edge>::iterator it = Edges[t].begin();
    while (it != Edges[t].end()) {
        if (it->v != parent[t]) {
            parent[it->v] = t;
            find_parent(it->v);
        }
        ++it;
    }
}

void get_parent() {
    parent[1] = 0;
    find_parent(1);
    for (int i = 1; i <= n; ++i) {
        Log("%d %d\n", i, parent[i]);
    }
}

void dfs_up(int t) {
    Log("dfs_up(%d)\n", t);
    if (t == 0)
        return;
    if (vis[t])
        return;
    vis[t] = true;

    dp_up[t][0] = dp_up[t][1] = 0;

    int p = parent[t];
    dfs_up(p);

    int notReturnMax = 0;
    int notReturn, Return, fix = 0;
    int weight = 0;
    vector<Edge>::iterator it = Edges[p].begin();
    while (it != Edges[p].end()) {
        if (it->v != parent[p]) {
            if (it->v == t) {
                weight = it->w;
                Log("weight = %d\n", weight);

                notReturn = dp_up[p][0] + weight;
                Return = dp_up[p][1] + 2*weight;
            } else {
                notReturn = dp_down[it->v][0] + it->w;
                Return = dp_down[it->v][1] + 2 * it->w;
            }
            Log("  %d cousin %d edge weight %d dp[]=%d %d\n", t, it->v, it->w,
                notReturn, Return);
            if (notReturnMax < notReturn) {
                notReturnMax = notReturn;
                fix = Return;
            }
            dp_up[t][1] += max(0, Return);
        }
        ++it;
    }

    dp_up[t][0] = dp_up[t][1] - fix + notReturnMax;

    dp_up[t][0] += w[t] + weight + w[p];
    dp_up[t][1] += w[t] + weight * 2 + w[p];

    // dp_up[t][0] = max(w[t],dp_up[t][0]);
    // dp_up[t][1] = max(w[t],dp_up[t][1]);
}

void dfs_down(int t) {
    Log("dfs_down(%d)\n", t);
    vector<Edge>::iterator it = Edges[t].begin();

    dp_down[t][0] = dp_down[t][1] = 0;

    int notReturnMax = 0;
    int notReturn, Return, fix = 0;
    while (it != Edges[t].end()) {
        if (it->v != parent[t]) {
            dfs_down(it->v);

            notReturn = dp_down[it->v][0] + it->w;
            Return = dp_down[it->v][1] + 2 * it->w;
            Log("  %d child %d edge weight %d dp[]=%d %d\n", t, it->v, it->w,
                notReturn, Return);
            if (notReturnMax < notReturn) {
                notReturnMax = notReturn;
                fix = Return;
            }

            dp_down[t][1] += max(0, Return);
        }
        ++it;
    }
    dp_down[t][0] = dp_down[t][1] - fix + notReturnMax;

    dp_down[t][0] += w[t];
    dp_down[t][1] += w[t];
}

void dfs() {
    dfs_down(1);
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        dfs_up(i);

    for (int i = 1; i <= n; ++i) {
        Log("dp[%d] = {%d , %d , %d , %d}\n", i, dp_up[i][0], dp_up[i][1],
            dp_down[i][0], dp_down[i][1]);
    }
}

int getAns(int t) {
    return max(dp_down[t][0] + dp_up[t][1], dp_down[t][1] + dp_up[t][0]) - w[t];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        init();
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, -w);
        }
        get_parent();
        dfs();

        for (int i = 1; i <= n; ++i) {
            printf("%d\n", getAns(i));
        }
    }
}