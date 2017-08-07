#include <cstdio>

const int maxn = 1005;
const double eps = 1e-12;

double dp[maxn][maxn];

void init(int w, int b) {
    for (int i = 0; i <= w; i++)
        for (int j = 0; j <= b; j++)
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = -1;
}

double getAns(int w, int b, int deep) {
    //for (int i = 0; i < deep; i++)
    //    printf("\t");
    //printf("dp[%d][%d]:\n", w, b);

    if (w < 0 || b < 0)
        return 0;

    if (dp[w][b] < 0) {
        // get white directly
        dp[w][b] = (double)w / (w + b);

        
        if (w + b >= 3) {
            // white
            dp[w][b] +=
                ((double)b / (w + b)) * ((double)(b - 1) / (w + b - 1)) *
                ((double)w / (w + b - 2)) * getAns(w - 1, b - 2, deep + 1);

            // black
            dp[w][b] +=
                ((double)b / (w + b)) * ((double)(b - 1) / (w + b - 1)) *
                ((double)(b - 2) / (w + b - 2)) * getAns(w, b - 3, deep + 1);
        }
    }

    //for (int i = 0; i < deep; i++)
    //    printf("\t");
    //printf("%.9f\n", dp[w][b]);

    return dp[w][b];
}

int main() {
    int w, b;
    while (scanf("%d%d", &w, &b) != EOF) {
        init(w, b);
        printf("%.10f\n", getAns(w, b, 1));
    }
    return 0;
}