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



const int INF = 0x7FFFFFFF / 2;
const double eps = 1e-10;

const int maxn = 205;
const int maxm = 205*2;

struct Edge {
    int u,v,w;
    Edge():u(0),v(0),w(0) {}
    Edge(int a,int b,int c):u(a),v(b),w(c) {}
};

int pos;
Edge edge[maxm];
list<int> L[maxn];
queue<int> Q;
int dist[maxn];

inline void add(int u,int v,int w) {
    edge[pos] = Edge(u,v,w);
    L[u].push_back(pos);
    pos++;
}

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

bool Do() {
    int n,m;
    if(!(cin >> n >> m))
        return false;

    for(int i = 1;i <= m;i++)
        L[i].clear();
    pos = 0;

    for(int i = 0;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,0);
    }
    cout << Dinic(1,m) << endl;
    return true;
}



int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());

    return 0;
}