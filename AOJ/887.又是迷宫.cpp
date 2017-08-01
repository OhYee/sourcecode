//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 105;
int Map[maxn][maxn];
int ans[maxn][maxn];
bool vis[maxn][maxn];

int n;

int dfs(int x, int y) {
    if (x > n || y > n)
        return 0;

    if (ans[x][y] == -1) {
        ans[x][y] = 0;
        if (x + Map [x][y] <= n)
            ans[x][y] += dfs(x + Map [x][y], y);
        if (y + Map [x][y] <= n)
            ans[x][y] += dfs(x, y + Map [x][y]);
    }

    return ans[x][y];
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> Map[i][j];
            }
        }
        memset(ans, -1, sizeof(ans));
        ans[n][n] = 1;

        cout << dfs(1, 1) << endl;

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << ans[i][j];
        //     }
        //     cout << endl;
        // }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}