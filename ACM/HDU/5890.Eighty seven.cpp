//*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 51;

int num[maxn];
bitset<90> dp[11];

int ans[maxn][maxn][maxn];
int n;

int read_int() {
    char c;
    int ans = 0;
    while (c = getchar(), !(c >= '0' && c <= '9'))
        ;
    while (c >= '0' && c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

bool getAns(int a, int b, int c) {
    if (ans[a][b][c] == -1) {
        for (int i = 0; i <= 10; i++)
            dp[i].reset();
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (i != a && i != b && i != c)
                for (int t = 10; t >= 1; --t)
                    dp[t] |= dp[t - 1] << num[i];
        }

        ans[a][b][c] = dp[10][87];
    }
    return ans[a][b][c] == 1;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int START = clock();
#endif

    int T = read_int();
    while (T--) {
        memset(ans, -1, sizeof(ans));

        n = read_int();
        for (int i = 1; i <= n; ++i)
            num[i] = read_int();

        int Q = read_int();
        int a[3];
        for (int q = 0; q < Q; ++q) {
            a[0] = read_int(), a[1] = read_int(), a[2] = read_int();
            sort(a, a + 3);
            printf("%s\n", (getAns(a[0], a[1], a[2]) ? "Yes" : "No"));
        }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}