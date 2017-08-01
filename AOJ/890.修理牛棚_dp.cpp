//*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 205;
const int INF = 0x3f3f3f;
int a[maxn];
int m, s, c;
int dp[maxn][maxn];

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    a[0] = 0;
    while (cin >> m >> s >> c) {
        for (int i = 1; i <= c; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + c);

        for (int i = 0; i <= c; i++)
            dp[i][0] = INF;
        memset(dp[0], 0, sizeof(dp[0]));

        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] =
                    min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + a[i] - a[i - 1]);
        cout << dp[c][m] << endl;

        // for (int i = 0; i <= c; i++){
        //     for (int j = 0; j <= m; j++)
        //         printf("%5d ",dp[i][j]);
        //     printf("\n");
        // }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}