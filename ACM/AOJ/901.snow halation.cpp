#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 105;
const int INF = 99999;

int n, m;
int a[maxn];
int dp[maxn][maxn];
int w[maxn][maxn];

// 初始化

void init() {
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            if (i == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = -INF;
}

// 进行 dp
void f(int i, int l, int t) {
    if (dp[i][t] == -INF)
        dp[i][t] = dp[i - 1][l] + w[l][t];
    else
        dp[i][t] = max(dp[i][t], dp[i - 1][l] + w[l][t]);
}

// 枚举 t
void T(int i, int l) {
    if (a[i] == 0) {
        for (int t = 1; t <= n; ++t)
            f(i, l, t);
    } else {
        f(i, l, a[i]);
    }
}

// 枚举 l
void L(int i) {
    if (a[i - 1] == 0) {
        for (int l = 1; l <= n; ++l)
            T(i, l);
    } else {
        T(i, a[i - 1]);
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        // 读入数据
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &w[i][j]);

        for (int i = 1; i <= m; ++i)
            scanf("%d", &a[i]);

        // dp运算
        init();
        for (int i = 2; i <= m; ++i)
            L(i);

        // for (int i = 0; i <= m; ++i) {
        //     for (int j = 0; j <= n; ++j)
        //         printf("%d ", dp[i][j]);
        //     printf("\n");
        // }

        //找出最优解
        int ans = -INF;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, dp[m][i]);

        printf("%d\n", ans);
    }
    return 0;
}