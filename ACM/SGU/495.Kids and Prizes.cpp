#include <algorithm>
#include <cstdio>
using namespace std;

const double eps = 1e-12;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        double ans = 0;
        for (int i = 0; i < m; i++) {
            ans = ((ans * ans) + (n - ans) * (ans + 1)) / n;
            if (fabs(ans - n) < eps)
                break;
        }
        printf("%.11f\n", ans);
    }
    return 0;
}