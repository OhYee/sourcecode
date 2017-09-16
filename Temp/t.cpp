#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int Ni = 5000000;
const int MAX = 1 << 26;
struct Edge {
    int u, v, c;
    int next;
} edge[20 * Ni];
int n, m;
int edn;   //边数
int p[Ni]; //父亲
int d[Ni];
int sp, tp; //原点，汇点

void addedge(int u, int v, int c) {
    edge[edn].u = u;
    edge[edn].v = v;
    edge[edn].c = c;
    edge[edn].next = p[u];
    p[u] = edn++;

    edge[edn].u = v;
    edge[edn].v = u;
    edge[edn].c = 0;
    edge[edn].next = p[v];
    p[v] = edn++;
}
int bfs() {
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[sp] = 0;
    q.push(sp);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = p[cur]; i != -1; i = edge[i].next) {
            int u = edge[i].v;
            if (d[u] == -1 && edge[i].c > 0) {
                d[u] = d[cur] + 1;
                q.push(u);
            }
        }
    }
    return d[tp] != -1;
}
int dfs(int a, int b) {
    int r = 0;
    if (a == tp)
        return b;
    for (int i = p[a]; i != -1 && r < b; i = edge[i].next) {
        int u = edge[i].v;
        if (edge[i].c > 0 && d[u] == d[a] + 1) {
            int x = min(edge[i].c, b - r);
            x = dfs(u, x);
            r += x;
            edge[i].c -= x;
            edge[i ^ 1].c += x;
        }
    }
    if (!r)
        d[a] = -2;
    return r;
}

int dinic(int sp, int tp) {
    int total = 0, t;
    while (bfs()) {
        while (t = dfs(sp, MAX))
            total += t;
    }
    return total;
}

int test(int n) {
    int ans = 0;
    for (int p = 1, i = 0; p < n; ++i, p <<= 2) {
        ans += (p) * n + i * p;
    }
    return ans;
}

int main() {
    int i, u, v, c;
    for (n = 2; n <= 10000000; n++) {
        edn = 0; //初始化
        memset(p, -1, sizeof(p));
        sp = 1;
        tp = n;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                addedge(i, j, (i - 1) ^ (j - 1));
        /*for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }*/
        int ans1 = dinic(sp, tp);
        int ans2 = test(n);
        printf("%d %d: %d %d %d\n", n, (int)(log(n - 1) / log(2) + 0.00001),
               ans1, ans2, ans1 - ans2);
        // printf("%d %d\n", n, dinic(sp, tp));
    }
    return 0;
}
