#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

/* 计算几何模板 */
const double eps = 1e-8;
const double INF = 9e50;
typedef complex<double> Vector;
typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Vector toVector() { return b - a; }
};

inline Point read_Point() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return Point(x, y);
}
inline int sgn(const double &x) {
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

inline int Cross(const Vector &a, const Vector &b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
inline int Dot(const Vector &a, const Vector &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

inline double Distance(const Point &a, const Point &b) { return abs(a - b); }

inline int Point_Segment(const Vector &p, const Segment &L) {
    return sgn(Cross(L.b - L.a, p - L.a));
}
inline int Segment_Segment(const Segment L1, const Segment L2) {
    double a = L1.b.real() - L1.a.real();
    double b = L2.b.real() - L2.a.real();
    double c = L1.b.imag() - L1.a.imag();
    double d = L2.b.imag() - L2.a.imag();
    double f = a * d - b * c;

    // 平行或重叠
    if (sgn(f) == 0)
        return -1;

    double g = L2.b.real() - L1.a.real();
    double h = L2.b.imag() - L1.a.imag();
    double t = (d * g - b * h) / f;
    double s = (-c * g + a * h) / f;

    // 在延长线上
    if (t <= 0 || t >= 1 || s <= 0 || s >= 1)
        return 0;

    // 线段相交
    return 1;
}

const int maxn = 35;
int n;
Segment segments[maxn];

int calc(Segment L) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += (Segment_Segment(L, segments[i]) > 0);
    return cnt;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            segments[i].a = read_Point();
            segments[i].b = read_Point();
        }
        Point target = read_Point();

        int ans = 9999999;
        for (int i = 0; i < n; i++) {
            ans = min(ans, calc(Segment(target, segments[i].a)));
            ans = min(ans, calc(Segment(target, segments[i].b)));
        }
        if (n == 0)
            ans = 0;
        printf("Number of doors = %d\n", ans + 1);
    }
    return 0;
}