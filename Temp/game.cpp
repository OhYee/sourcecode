#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 200005;
vector<int> Edges[maxn];
vector<int> Children[maxn];

queue<int> Q;
int deep[maxn];
int parent[maxn];

void addEdge(int u, int v) {
    Edges[u].push_back(v);
    Edges[v].push_back(u);
}

void makeDepth() {
    while (!Q.empty())
        Q.pop();

    parent[1] = -1;
    deep[1] = 1;
    Q.push(1);
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        for (auto i : Edges[t]) {
            if (parent[t] != i) {
                deep[i] = deep[t] + 1;
                parent[i] = t;
                Q.push(i);
            }
        }
    }
}

int getAns(int t, bool d = true) {
    int mx, mn;
    for (auto i : Edges[t]) {
        if (parent[t] != i) {
            mx=max(mx,deep[i]);
            mn=min(mn,deep[i]);
        }
    }
    
}

int main() {
    int T;
    scanf("%d", % T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        printf("%d\n", getAns(1));
    }
}