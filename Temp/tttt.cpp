#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 4005;
int dp[maxn][2];
int a[maxn][2];
int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a[i][0], &a[i][1]);
        if ((a[0][0] - a[0][1]) > (a[1][0] - a[1][1])) {
            dp[0][0] = dp[1][1] = a[0][1] + a[1][0];
            dp[1][0] = dp[0][1] = a[0][0] + a[1][1];
        } else {
            dp[0][0] = dp[1][1] = a[0][0] + a[1][1];
            dp[1][0] = dp[0][1] = a[0][1] + a[1][0];
        }
        for (int i = 2; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + a[i][1];
            dp[i][1] = dp[i - 1][1] + a[i][0];
        }
        printf("Case #%d: %d\n", kase, min(dp[n - 1][0], dp[n - 1][1]));
        for (int i = 0; i < n; ++i)
            printf("%d %d\n", dp[i][0], dp[i][1]);
    }
    return 0;
}