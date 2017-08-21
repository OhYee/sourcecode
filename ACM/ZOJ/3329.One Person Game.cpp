#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) //printf(format, ##__VA_ARGS__)

const int maxk = 3;
const int maxnum = 20;
const int maxn = 550;

int n, k[maxk], a[maxk];
double A[maxn], B[maxn], p[maxnum];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d%d%d", &n, &k[0], &k[1], &k[2], &a[0], &a[1], &a[2]);

        memset(p, 0, sizeof(p));
        for (int i = 1; i <= k[0]; ++i)
            for (int j = 1; j <= k[1]; ++j)
                for (int l = 1; l <= k[2]; ++l) {
                    if (i == a[0] && j == a[1] && l == a[2]) {
                        p[0] += 1;
                    } else {
                        p[i + j + l] += 1;
                    }
                }

        int sum = k[0] * k[1] * k[2];
        for (int i = 0; i < maxnum; ++i) {
            p[i] = p[i] / sum;
            Log("%d %f\n", i, p[i]);
        }

        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for (int i = n; i >= 0; --i) {
            for (int j = 3; j < maxnum; ++j) {
                Log("%d %d %f %f %f\n", i,j, p[j],A[i+j],B[i+j]);
                A[i] += p[j] * A[i + j];
                B[i] += p[j] * B[i + j];
            }
            Log("%d %f %f\n", i, A[i],B[i]);
            A[i] += p[0];
            B[i] += 1;
            Log("%d %f %f\n", i, A[i],B[i]);
        }

        printf("%.15f\n", B[0] / (1 - A[0]));
    }
    return 0;
}