#include <cstdio>
const int maxn = 25;
double p[maxn];

inline bool GetI(int num, int i) { return (num >> i) & 1; }

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lf", &p[i]);

        double ans = 0.0;
        for (int state = (1 << n) - 1; state > 0; --state) {
            bool cnt = false;
            double sump = 0.0;
            for (int i = 0; i < n; i++) {
                bool t = GetI(state, i);
                if (t) {
                    cnt = !cnt;
                    sump += p[i];
                }
            }
            if (cnt) {
                ans += 1.0 / sump;
            } else {
                ans -= 1.0 / sump;
            }
        }
        printf("%f\n", ans);
    }
    return 0;
}