#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5+5;

map<string, int> Hash;
vector<string> HashList;
int parent[maxn];
bool vis[maxn];

void init() {
    Hash.clear();
    HashList.clear();
    memset(parent, -1, sizeof(parent));
}

int getHash(string s) {
    if (!Hash.count(s)) {
        Hash.insert(make_pair(s, HashList.size()));
        HashList.push_back(s);
    }
    return Hash[s];
}

void addEdge(int u, int v) { parent[v] = u; }


int find_parent(int n) {
    if (n == -1)
        return -1;
    if (vis[n])
        return n;
    vis[n] = true;
    return find_parent(parent[n]);
}

int main() {
    int n;
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int u = getHash(s1);
            int v = getHash(s2);
            addEdge(u, v);
        }

        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int u = getHash(s1);
            int v = getHash(s2);
            memset(vis, false, sizeof(vis));
            find_parent(u);
            cout << HashList[find_parent(v)] << endl;
        }
    }
}