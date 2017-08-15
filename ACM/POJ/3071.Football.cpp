//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 8;
const int maxm = 2 << 8;
double Pro[maxm][maxm];
double dp[maxn][maxm];

int getTeam(int number, int bit, int flag) {
    int ans = number ^ (1 << bit); //把bit位取反

    ans = (ans >> (bit)) << (bit);
    if (flag)
        ans += (1 << bit) - 1;

    return ans;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    while (cin >> n) {
        if (n == -1)
            continue;
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < (1 << n); j++)
                cin >> Pro[i][j];

        for (int i = 0; i < n; i++) {
            // cout << "Game round" << i + 1 << ": " << endl;
            for (int j = 0; j < (1 << n); j++) {
                if (i == 0) {
                    // cout << "\t" << j << " vs. " << getTeam(j, i, 1) << endl;
                    dp[i][j] = Pro[j][getTeam(j, i, 0)];
                } else {
                    dp[i][j] = 0;
                    for (int k = getTeam(j, i, 0); k <= getTeam(j, i, 1); k++) {
                        // cout << "\t" << j << " vs. " << k << endl;
                        dp[i][j] += dp[i - 1][k] * Pro[j][k];
                    }
                    dp[i][j] *= dp[i - 1][j];
                }
                // cout << "\t\tdp[i][j]=" << dp[i][j] << endl;
            }
        }

        int pos = 0;
        for (int i = 1; i < (1 << n); i++) {
            // cout << dp[n - 1][i] << endl;
            if (dp[n - 1][i] > dp[n - 1][pos])
                pos = i;
        }
        cout << pos + 1 << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}