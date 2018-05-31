#include <cstdio>

const int maxn = 200005;
int a[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        int half = n / 2;
        bool first = true;
        if (n & 1) {
            // 奇数
            for (int i = 0; i <= half; ++i) {
                if (first)
                    first = false;
                else
                    printf(" ");
                printf("%d", a[n - 2 * i]);
            }
            for (int i = 2; i < n; i += 2) {
                printf(" %d", a[i]);
            }
        } else {
            // 偶数
            for (int i = 0; i < half; ++i) {
                if (first)
                    first = false;
                else
                    printf(" ");
                printf("%d", a[n - 2 * i]);
            }
            for (int i = 1; i < n; i += 2) {
                printf(" %d", a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}