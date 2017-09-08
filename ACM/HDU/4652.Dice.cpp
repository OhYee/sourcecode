#include <cstdio>

double pow(double a, int n) {
    if (n == 0)
        return 1.0;
    double ans = pow(a, n >> 1);
    return ans * ans * (n & 1 ? a : 1);
}

double calc1(int n, int m) { return (pow(m, n) - m) / (m - 1) + 1; }
double calc2(int n, int m) {
    double sum = 0.0;
    double p = 1.0;
    for (int i = 0; i < n; ++i) {
        p *= (double)m / (m - i);
        sum += p;
    }
    return sum;
}

int main() {
    int T;
    int c, n, m;

    while (scanf("%d", &T) != EOF) {
        while (T--) {
            scanf("%d%d%d", &c, &m, &n);
            double (*calc)(int, int) = (!c ? &calc1 : &calc2);
            printf("%.16f\n", calc(n, m));
        }
    }
    return 0;
}