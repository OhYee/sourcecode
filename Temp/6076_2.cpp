#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 60005;
const int maxk = 11;

int queue_a[maxn], queue_b[maxn];
int DP[maxn][maxk << 2];
int n, k;

void init() { memset(DP, -1, sizeof(DP)); }

int dfs(int apos, int bpos) {
    int RETURN = -1;
    if (!apos || !bpos) {
        RETURN = apos | bpos;
    } else {
        if (abs(queue_a[apos] - queue_b[bpos]) <= k) {
            //暴力
            int &dp = DP[apos][queue_a[apos] - queue_b[bpos] + k];
            if (dp == -1)
                dp = min(dfs(apos - 1, bpos), dfs(apos, bpos - 1)) + 1;
            RETURN = dp;
        } else {
            RETURN = dfs(apos - 1, bpos - 1) + 1;
        }
    }
    return RETURN;
}

int main() {
    // freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);

        init();
        for (int i = 1; i <= n; i++)
            scanf("%d", &queue_a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &queue_b[i]);

        printf("%d\n", dfs(n, n));
    }
    return 0;
}
