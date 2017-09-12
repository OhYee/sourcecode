#include <complex>
#include <cstdio>

using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

/* 计算几何模板 */
const double eps = 1e-8;
typedef complex<double> Vector;
typedef Vector Segment[2];

int sgn(const double &x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
inline bool operator==(const Vector &vec1, const Vector &vec2) {
    return sgn(vec1.real() - vec2.real()) == 0 &&
           sgn(vec1.imag() - vec2.imag()) == 0;
}
inline bool operator!=(const Vector &vec1, const Vector &vec2) {
    return !(vec1 == vec2);
}
int Cross(const Vector &a, const Vector &b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
int Dot(const Vector &a, const Vector &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

int dot_segment(const Vector &p, const Segment &L) {
    return sgn(Cross(L[1] - L[0], p - L[0]));
}

bool segment_segment(const Segment &L1, const Segment &L2) {
    if (L1[0] == L1[1] || L2[0] == L2[1])
        return false;
    int t1 = dot_segment(L1[0], L2) * dot_segment(L1[1], L2);
    int t2 = dot_segment(L2[0], L1) * dot_segment(L2[1], L1);
    return (t1 <= 0) && (t2 <= 0);
}

const int maxn = 105;
Segment s[maxn];
int n;

bool judge(int a, int b) {
    Log("%d %d\n", a, b);

    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        Segment temp = {s[a][0], s[b][0]};
        ok &= segment_segment(temp, s[i]);
    }
    if (ok)
        return true;
    ok = true;
    for (int i = 0; i < n && ok; ++i) {
        Segment temp = {s[a][0], s[b][1]};
        ok &= segment_segment(temp, s[i]);
    }
    if (ok)
        return true;
    ok = true;
    for (int i = 0; i < n && ok; ++i) {
        Segment temp = {s[a][1], s[b][0]};
        ok &= segment_segment(temp, s[i]);
    }
    if (ok)
        return true;
    ok = true;
    for (int i = 0; i < n && ok; ++i) {
        Segment temp = {s[a][1], s[b][1]};
        ok &= segment_segment(temp, s[i]);
    }
    if (ok)
        return true;
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            s[i][0] = Vector(x1, y1);
            s[i][1] = Vector(x2, y2);
        }

        bool ok = false;
        for (int i = 0; i < n && !ok; ++i)
            for (int j = i + 1; j < n && !ok; ++j)
                ok |= judge(i, j);

        printf("%s\n", ok ? "Yes!" : "No!");
    }
    return 0;
}