//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 15;
const int maxm = 55;

bool Edge[maxn][maxn];
int color[maxn];
int n, m;
int sum;

bool judge(int t, int c) {
    for (int i = 1; i <= n; i++) {
        if (Edge[t][i]) {      //相邻
            if (color[i] == c) //有重复的颜色
                return false;
        }
    }
    return true;
}

//给t涂上c
void dfs(int t, int c, int deep) {
    if (!judge(t, c))
        return;

    // for (int i = 0; i < deep; i++)
    //     cout << "\t";
    // cout << "fill " << t << " in color " << c << endl;

    color[t] = c;

    if (t < n)
        for (int k = 1; k <= 4; k++)
            dfs(t + 1, k, deep + 1);
    else
        sum++;

    color[t] = 0;
}

//从 s 开始给连通分量内的点涂色
int begin(int s) {
    sum = 0;
    for (int k = 1; k <= 4; k++) {
        dfs(s, k, 0);
    }

    //cout << s << "  " << sum << endl;

    return sum;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    while (cin >> n >> m) {
        memset(Edge, false, sizeof(Edge));

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            Edge[a][b] = Edge[b][a] = true;
        }

        int ans = begin(1);

/*
        for (int i = 2; i <= n; i++) {
            if (color[i] == 0) {
                ans *= begin(i);
            }
        }
*/
        cout << ans << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}