#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) printf(format, ##__VA_ARGS__)
/* 向量模板 */

typedef complex<double> Vector;
int Cross(Vector a, Vector b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
int Dot(Vector a, Vector b) {
    return a.real() * b.real() + a.imag() * b.imag();
}
const int maxn = 5005;
Vector P1[maxn];
Vector P2[maxn];
int cnt[maxn], ans[maxn];

bool Could(Vector p, Vector L) { return (Cross(L, p) >= 0); }
int Division(int l, int r, Vector p) {
    // printf("%d %d (%.f,%.f)\n", l, r, p.real(), p.imag());
    if (r - l == 1)
        return l;
    int mid = (l + r) >> 1;
    if (Could(p - P1[mid], P2[mid] - P1[mid]))
        return Division(l, mid, p);
    else
        return Division(mid, r, p);
}

bool compare(Vector a, Vector b) { return a.real() < b.real(); }

int main() {
    int n, m, x1, y1, x2, y2;
    while (scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2), n != 0) {
        P1[0] = Vector(x1, y2);
        P2[0] = Vector(x1, y1);
        for (int i = 1; i <= n; ++i) {
            int u, l;
            scanf("%d%d", &u, &l);
            P2[i] = Vector(u, y1);
            P1[i] = Vector(l, y2);
        }
        P1[n + 1] = Vector(x2, y2);
        P2[n + 1] = Vector(x2, y1);

        sort(P1 + 1, P1 + 1 + n, compare);
        sort(P2 + 1, P2 + 1 + n, compare);
        // for (int i = 0; i <= n + 1; ++i) {
        //     printf("%d : (%.f,%.f) -> (%.f,%.f)\n", i, P1[i].real(),
        //            P1[i].imag(), P2[i].real(), P2[i].imag());
        // }
        memset(cnt, 0, sizeof(int) * (n + 5));
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            cnt[Division(0, n + 1, Vector(x, y))]++;
        }

        memset(ans, 0, sizeof(ans));
        for (int i = 0; i <= n; ++i)
            ans[cnt[i]]++;

        printf("Box\n");
        for (int i = 1; i <= n; ++i)
            if (ans[i] != 0)
                printf("%d: %d\n", i, ans[i]);
    }
    return 0;
}