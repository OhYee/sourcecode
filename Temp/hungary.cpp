#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/*
* 匈牙利算法邻接表形式
* 使用前用init()进行初始化，给uN赋值
* 加边使用函数addedge(u,v)
*/
const int MAXN = 200005; //点数的最大值
const int MAXM = 2*200005; //边数的最大值
struct Edge {
    int to, next;
} edge[MAXM];
int head[MAXN], tot, uN;
void init(int un) {
    uN = un;
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
    // cout<<"add"<<u<<" "<<v<<endl;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
bool dfs(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++) { //点的编号0~uN-1
        memset(used, false, sizeof(used));
        if (dfs(u))
            res++;
    }
    return res;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        init(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u - 1, v - 1);
            addedge(v - 1, u - 1);
        }
        printf("%d\n", hungary()/2);
    }
    return 0;
}