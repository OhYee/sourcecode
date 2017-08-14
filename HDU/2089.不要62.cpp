#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 10;

int a[maxn];
int dp[maxn][10];

/* 第pos位 前一位状态为 pre 当前是否限制当前位(limit) */
int dfs(int pos, int pre, bool limit) {
    if (pos == -1)
        return 1;

    if (limit || dp[pos][pre] == -1) {
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int now = 0; now <= up; now++) {
            if (pre == 6 && now == 2)
                continue;
            if (now == 4)
                continue;
            ans += dfs(pos - 1, now, limit && now == a[pos]);
        }
        if (!limit)
            dp[pos][pre] = ans;
        return ans;
    }
    return dp[pos][pre];
}

int solve(int x) {
    int pos = 0;
    while (x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    int ans = dfs(pos - 1, -1, true);
    //printf("solve(%d) = %d\n", x, ans);
    return ans;
}
int main() {
    int l, r;
    while (scanf("%d%d", &l, &r) != EOF) {
        if (l == 0 && r == 0)
            break;
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(r) - solve(l - 1));
    }
    return 0;
}