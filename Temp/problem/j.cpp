#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define Log(format, ...) //printf(format, ##__VA_ARGS__)

const int maxn = 10005;

int n;
map<string, int> Hash;
int cnt;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};
struct Node {
    int n, w, lst;
    Node(int _n, int _w, int _lst) : n(_n), w(_w), lst(_lst) {}
    bool operator<(const Node &rhs) const { return w > rhs.w; }
};

vector<Edge> Edges[maxn];

void init() {
    Hash.clear();
    cnt = 0;
    for (int i = 0; i <= n; ++i)
        Edges[i].clear();
}

int getHash(string s) {
    if (!Hash.count(s)) {
        Hash.insert(make_pair(s, cnt++));
    }
    return Hash[s];
}
void addEdge(int u, int v, int w) {
    Log("addEdge(%d,%d,%d)\n", u, v, w);
    Edges[u].push_back(Edge(v, w));
    Edges[v].push_back(Edge(u, w));
}

int lst[maxn];
bool vis[maxn];
priority_queue<Node> Q;
int dijkstra(int s, int w) {
    Log("dijkstra %d -> %d\n", s, w);
    while (!Q.empty())
        Q.pop();
    int ans = -1;
    Q.push(Node(s, 0, -1));
    while (!Q.empty()) {
        int t = Q.top().n;
        int dis = Q.top().w;
        int lst2 = Q.top().lst;
        Q.pop();
        Log("\t%d(%d %d)\n", t, dis, lst2);
        if (vis[t])
            continue;
        lst[t] = lst2;
        vis[t] = true;
        if (t == w) {
            ans = dis;
            break;
        }

        for (auto e : Edges[t]) {
            Log("\t\t%d + %d\n", dis, e.w);
            Q.push(Node(e.v, dis + e.w, t));
        }
    }
    Log("dijkstra %d -> %d     %d\n", s, w, ans);
    return ans;
}

// a -> b -> c
int calc(int a, int b, int c) {
    Log("calc %d -> %d -> %d\n", a, b, c);
    memset(lst, -1, (n + 5) * sizeof(int));
    memset(vis, false, (n + 5) * sizeof(bool));
    int dis = dijkstra(a, b);
    bool OK = (dis != -1);
    int ans = 0;
    if (OK) {
        ans = dis;
        memset(vis, false, (n + 5) * sizeof(bool));
        int t = b;
        while (t != -1) {
            vis[t] = true;
            t = lst[t];
        }
        vis[b] = false;
        dis = dijkstra(b, c);
        OK &= (dis != -1);
        if (OK)
            ans += dis;
    }
    if (!OK)
        ans = -1;
    Log("calc %d -> %d -> %d    %d\n", a, b, c, ans);
    return ans;
}

int getAns(int a, int b, int c) {
    Log("%d -> %d -> %d\n", a, b, c);
    return min(calc(a, b, c), calc(c, b, a));
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        init();
        string u, v;
        int d;
        for (int i = 0; i < n; ++i) {
            cin >> u >> v >> d;
            int ut = getHash(u);
            int vt = getHash(v);
            addEdge(ut, vt, d);
        }
        int a = getHash("Dalian");
        int b = getHash("Shanghai");
        int c = getHash("Xian");
        printf("%d\n", getAns(a, b, c));
    }
    return 0;
}