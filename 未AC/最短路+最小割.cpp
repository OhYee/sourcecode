/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

typedef long long LL;

const int INF = 0x7FFFFFFF/2;
const double eps = 1e-10;

const int maxn = 1005;
const int maxm = 10005 * 2;

struct Edge {
    int u,v,w;
    Edge():u(0),v(0),w(0) {}
    Edge(int a,int b,int c):u(a),v(b),w(c) {}
};

int pos;
Edge edge[maxm],road[maxm];
list<int> L[maxn];

int n,m;

queue<int> Q;
int dist[maxn];
bool vis[maxn];

void init() {
    pos = 0;
    for(int i = 1;i <= n;i++)
        L[i].clear();
}

//图中增加 u→v 权重为 w 的边
inline void add(int u,int v,int w) {
    edge[pos] = Edge(u,v,w);

    L[u].push_back(pos);
    pos++;
}

//Dinic
bool bfs(int s,int t) {
    memset(dist,0,sizeof(dist));
    while(!Q.empty())
        Q.pop();

    Q.push(s);
    dist[s] = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
            int v = edge[*it].v;
            if(!dist[v] && edge[*it].w) {
                dist[v] = dist[u] + 1;
                if(v == t)
                    return true;
                Q.push(v);
            }
        }
    }
    return false;
}
int dfs(int u,int t,int flow) {
    if(u == t)
        return flow;
    int remain = flow;
    for(list<int>::iterator it = L[u].begin();it != L[u].end() && remain;it++) {
        int v = edge[*it].v;
        if(dist[v] == dist[u] + 1 && edge[*it].w) {
            int k = dfs(v,t,min(remain,edge[*it].w));
            if(!k)
                dist[v] = 0;
            edge[*it].w -= k;
            edge[(*it) ^ 1].w += k;
            remain -= k;
        }
    }
    return flow - remain;
}
int Dinic(int u,int v) {
    int ans = 0;
    while(bfs(u,v))
        ans += dfs(u,v,INF);
    return ans;
}

void Do() {
    //读入并建图
    init();
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        cin >> road[i].u >> road[i].v >> road[i].w;
        add(road[i].u,road[i].v,1);
        add(road[i].v,road[i].u,1);
    }

    //BFS计算所有点到源点的距离
    while(!Q.empty())
        Q.pop();
    for(int i = 1;i <= n;i++)
        dist[i] = INF;
    memset(vis,false,sizeof(vis));

    Q.push(1);
    dist[1] = 0;
    vis[1] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
            int v = edge[*it].v;
            if(!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }

    //重新建图,新图中只有最短路和死路
    init();
    for(int i = 0;i < m;i++) {
        int mx,mi;
        if(dist[road[i].u] > dist[road[i].v]) {
            mx = road[i].u;
            mi = road[i].v;
        } else {
            mi = road[i].u;
            mx = road[i].v;
        }

        //较远点比较近点恰好远1个单位
        if(dist[mx] - dist[mi] == 1) {
            add(mi,mx,road[i].w);
            add(mx,mi,0);
        }
    }

    //Dinic模板求最大流(最小割)
    cout << Dinic(1,n) << endl;
}

int vs_main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--)
        Do();

    return 0;
}