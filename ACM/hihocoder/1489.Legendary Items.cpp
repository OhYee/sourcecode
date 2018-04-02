#include <cstdio>

const int maxn = 1e6 + 5;
const double eps = 1e-9;
double dp[maxn];

int pow(int m) {
    const int pow2[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    m = m <= 8 ? m : 8;
    return pow2[m];
}

int main() {
    int P, Q, N;
    scanf("%d%d%d", &P, &Q, &N);

    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int thisP = P / pow(i - 1);

        double sum = 0;

        dp[i] = dp[i - 1];

        bool go = true;
        for (int j = 0; go && j <= 100; ++j) {
            int temp = (double)(thisP + j * Q);
            if (temp >= 100)
                temp = 100;
            double TEMP = (double)temp / 100;
            dp[i] += (1 - sum) * TEMP * (j + 1);
            sum += (1 - sum) * TEMP;

            if (temp == 100)
                go = false;
        }
    }

    printf("%.2f\n", dp[N]);
    return 0;
}
