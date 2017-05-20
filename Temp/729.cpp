//*/
#define debug
#include <ctime>
//*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e6 + 5;
int lenth[maxn], L[maxn], R[maxn];

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &lenth[i]);
            if (i)
                L[i] = min(L[i - 1], lenth[i]);
            else
                L[i] = lenth[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                R[i] = lenth[i];
            else
                R[i] = min(R[i + 1], lenth[i]);
        }

        printf("L:");
        for (int i = 0; i < n; i++)
            printf("%3d ", L[i]);
            printf("\n");

        printf("R:    ");
        for (int i = 0; i < n; i++)
            printf("%3d ", R[i]);
        printf("\n");

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans += max(L[i + 1], R[i]);

        printf("%d\n", ans);
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}