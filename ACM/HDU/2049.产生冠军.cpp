#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int maxn = 2005;

map<string, int> M;

bool vis[maxn];
bool Edge[maxn][maxn];
int num = 0;

int getNum(string s) {
    if (M.count(s) == 0) {
        M.insert(make_pair(s, num++));
    }
    // cout << s << ":" << M[s] << endl;
    return M[s];
}
void init() {
    memset(vis, false, sizeof(vis));
    memset(Edge, false, sizeof(Edge));
    num = 0;
    M.clear();
}
void addEdge(int u, int v) { Edge[u][v] = true; }

bool IsStart(int k) {
    //判断是否入度为0
    for (int i = 0; i < num; i++)
        if (Edge[i][k])
            return false;
    return true;
}

bool dfs(int t) {
    if (vis[t])
        return false;
    vis[t] = true;

    bool OK = true;
    for (int i = 0; i < num; i++) {
        if (Edge[t][i])
            OK &= dfs(i);
    }
    return OK;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        init();
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            int apos = getNum(a);
            int bpos = getNum(b);
            addEdge(apos, bpos);
        }

        bool YES = true;
        int root = -1;

        for (int i = 0; i < num; i++) {
            if (IsStart(i)) {
                if (root == -1) {
                    root = i;
                }else{
                    YES = false;
                    //printf("%d\n",i);
                    break;
                }
            }
        }
        if(root == -1)
            YES = false;

        if (YES)
            printf("Yes\n");
        else
            printf("No\n");
    }
}