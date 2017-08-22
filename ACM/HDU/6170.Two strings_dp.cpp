#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 3505;

char a[maxn], b[maxn];
bool dp[maxn][maxn];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    // scanf("%d", &T);
    // getchar();
    while (T--) {
        cin >> a >> b;
        // scanf("\n%[^\n]\n%[^\n]", a, b);
        // fgets(a,maxn,stdin);
        // fgets(b,maxn,stdin);

        memset(dp, false, sizeof(dp));

        // printf("%d\na:%s\nb:%s\n",T, a, b);
        int n = strlen(a);
        int m = strlen(b);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                // 第一个位置
                if ((a[i] == b[j] || b[j] == '.') && i == 0 && j == 0)
                    dp[i][j] |= true;
                // 从左上角转移过来
                if ((a[i] == b[j] || b[j] == '.') && i > 0 && j > 0)
                    dp[i][j] |= dp[i - 1][j - 1];
                // 特判
                if ((a[i] == b[j] || b[j] == '.') && b[1] == '*' && i == 0)
                    dp[i][j] = true;
                // * 匹配
                // 从上面的上面转移过来（匹配0个）
                //从上面转移过来（匹配1个）
                if (b[j] == '*')
                    dp[i][j] |= (j >= 2 ? dp[i][j - 2] : 0) |
                                (j >= 1 ? dp[i][j - 1] : 0);
                // 从左面转移过来（*往后续）
                if (b[j] == '*' && i >= 1 && a[i - 1] == a[i])
                    dp[i][j] |= dp[i - 1][j];
            }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j)
        //         printf("%d ", dp[i][j]);
        //     printf("\n");
        // }
        // printf("%s\n", (dp[n - 1][m - 1] ? "yes" : "no"));
        cout << (dp[n - 1][m - 1] ? "yes" : "no") << endl;
    }
    return 0;
}