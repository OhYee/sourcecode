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
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <bitset>
using namespace std;

const int maxn = 105;

struct Edge {
    int u,v;
    int w;
    bool operator < (const Edge &rhs)const {
        return w < rhs.w;
    }
};


int f[maxn];
Edge e[maxn*maxn / 2];

int ufs(int x) {
    return f[x] == x ? x : f[x] = ufs(f[x]);
}
int Kruskal(int n,int m) {
    int w = 0;
    for(int i = 0; i < n; i++)
        f[i] = i;
    sort(e,e + m);
    for(int i = 0; i < m; i++) {
        int x = ufs(e[i].u),y = ufs(e[i].v);
        if(x != y) {
            f[x] = y;
            w += e[i].w;
        }
    }
    return w;
}

bool Do() {
    int n;
    if(!(cin >> n))
        return false;

    int pos = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) {
            if(i < j) {
                e[pos].u = i;
                e[pos].v = j;
                cin >> e[pos].w;
                pos++;
            } else {
                int t;
                cin >> t;
            }
        }



    cout << Kruskal(n,n*(n-1)/2) << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());
    return 0;
}