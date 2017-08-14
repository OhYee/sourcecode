#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int f[maxn];
struct Edge {
    int u, v;
    int w;
    bool operator<(const Edge rhs) const { return w < rhs.w; }
} e[maxm];
int pos;

int ufs(int x) { return f[x] == x ? x : f[x] = ufs(f[x]); }
int Kruskal(int n, int m) {
    int w = 0;
    for (int i = 0; i <= n; i++)
        f[i] = i;
    sort(e, e + m);
    for (int i = 0; i < m; i++) {
        int x = ufs(e[i].u), y = ufs(e[i].v);
        if (x != y) {
            f[x] = y;
            w += e[i].w;
        }
    }
    return w;
}
void addEdge(int u, int v, int w) {
    e[pos].u = u;
    e[pos].v = v;
    e[pos].w = w;
    pos++;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int u, v, w;
        pos = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        printf("%d\n", Kruskal(n, m));
    }
}