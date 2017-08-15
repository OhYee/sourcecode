#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

const int maxT = 1005;
const int maxM = 35;

double Prob[maxT][maxM];
double dp[maxT][maxM][maxM];

int main() {
    int M, T, N;
    while (scanf("%d%d%d", &M, &T, &N) != EOF) {
        if (!(M | T | N))
            break;

        for (int i = 1; i <= T; ++i)
            for (int j = 1; j <= M; ++j)
                scanf("%lf", &Prob[i][j]);

        for (int i = 1; i <= T; ++i)
            dp[i][0][0] = 1.0;

        // dp[i][j][k] 第i个队伍在前j道题中做出k题
        for (int i = 1; i <= T; ++i)
            for (int j = 1; j <= M; ++j)
                for (int k = 0; k <= j; ++k) {
                    dp[i][j][k] = 0.0;
                    if (k != 0)
                        dp[i][j][k] += dp[i][j - 1][k - 1] * Prob[i][j];
                    // if (k != j)
                    dp[i][j][k] += dp[i][j - 1][k] * (1 - Prob[i][j]);
                }

        double P1 = 1.0; //有队伍达到N题
        double P2 = 1.0; //有队伍未达到1题
        for (int i = 1; i <= T; ++i) {
            double sum = 0.0;
            for (int j = 1; j < N; ++j)
                sum += dp[i][M][j];
            P1 *= sum;
            P2 *= 1 - dp[i][M][0];
        }
        // P1 = 1 - P1;
        // P2 = 1 - P2;

        // printf("%.3f\n", P1 - P2);
        cout << fixed << setprecision(3) << P2 - P1 << endl;
    }
    return 0;
}