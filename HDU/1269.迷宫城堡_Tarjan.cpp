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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 10005;

//Tarjan
const int maxm = 100005;

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];

stack<int> s;
bool inStack[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表
int cnt,Index;
int DFN[maxn],Low[maxn];

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    pos++;
}

void tarjan(int u) {
    if(DFN[u] != -1)
        return;

    DFN[u] = Low[u] = ++Index;
    s.push(u);
    inStack[u] = true;

    for(list<int>::iterator it = L[u].begin();it != L[u].end();it++) {
        int v = edge[*it].v;

        if(DFN[v] == -1) {
            tarjan(v);
            Low[u] = min(Low[u],Low[v]);
        } else if(inStack[v]) {
            Low[u] = min(Low[u],DFN[v]);
        }

    }
    if(DFN[u] == Low[u]) {
        int v = s.top();
        s.pop();
        inStack[v] = false;

        SCC[cnt++].push_back(v);

        while(u != v) {
            v = s.top();
            s.pop();
            inStack[v] = false;

            SCC[cnt - 1].push_back(v);
        }
    }
}

int Tarjan(int n) {
    cnt = 0;
    Index = 0;
    while(!s.empty())s.pop();
    memset(inStack,false,sizeof(inStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));

    for(int i = 0;i < n;i++)
        tarjan(i);
    return cnt;

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n,m;
    while(cin >> n >> m,!(n == 0 && m == 0)) {
        for(int i = 0;i < n;i++) {
            L[i].clear();
            SCC[i].clear();
        }
        while(!s.empty())s.pop();
        pos = 0;

        for(int i = 0;i < m;i++) {
            int a,b;
            cin >> a >> b;
            add(a - 1,b - 1);
        }

        cout << (Tarjan(n) == 1 ? "Yes" : "No") << endl;


    }
    return 0;
}