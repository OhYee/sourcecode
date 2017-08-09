#include <cstdio>
#include <cstring>

const int maxn = 10000;

const int x[3] = {1, 2, 5};

int a[maxn], b[maxn];

int main() {
    int num[3];
    while (scanf("%d%d%d", &num[0], &num[1], &num[2])) {
        if (!(num[0] || num[1] || num[2]))
            break;

        memset(a, 0, sizeof(a));
        a[0] = 1;
        int lasta = 0;
        for (int k = 0; k < 3; k++) {
            memset(b, 0, sizeof(b));
            for (int i = 0; i < num[k]; ++i)
                b[i * x[k]] = 1;
            int lastb = num[k] * x[k];

            for (int i = 0; i <= lasta; i++) {
                for (int j = 0; j <= lastb; j++) {
                    printf("%d*x^%d * %d*x^%d\n", a[i], i, b[j], j);
                    a[i + j] = a[i] * b[j];
                }
                lasta = lasta + lastb;
                
                for (int j = 0; j <= lasta; j++)
                    printf("%d*x^%d + ", a[j], j);
                printf("\n");
            }
        }

        for (int i = 0; i <= lasta; i++)
            printf("%d*x^%d + ", a[i], i);
        printf("\n");

        for (int i = 0; i <= lasta; i++)
            if (a[i] == 0) {
                printf("%d\n", i);
                break;
            }
    }
}