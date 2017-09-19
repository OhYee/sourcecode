#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

/* 计算几何模板 */
const double eps = 1e-8;

typedef complex<double> Vector;
typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Vector toVector() { return b - a; }
};

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
inline int Dot_Segment(const Vector &p, const Segment &L) {
    return sgn(Cross(L.b - L.a, p - L.a));
}
inline bool Segment_Segment(const Segment &L1, const Segment &L2) {
    if (sgn(Distance(L1.a, L1.b)) == 0 || sgn(Distance(L2.a, L2.b)) == 0)
        return 0;
    return (Dot_Segment(L1.a, L2) * Dot_Segment(L1.b, L2) <= 0) &&
           (Dot_Segment(L2.a, L1) * Dot_Segment(L2.b, L1) <= 0);
}
inline bool Segment_Line(const Segment &Seg, const Segment &Line) {
    Log("(%.f,%.f)->(%.f,%.f)   (%.f,%.f)->(%.f,%.f)\n", Seg.a.real(),
        Seg.a.imag(), Seg.b.real(), Seg.b.imag(), Line.a.real(), Line.a.imag(),
        Line.b.real(), Line.b.imag());
    if (sgn(Distance(Line.a, Line.b)) == 0)
        return 0;
    return Dot_Segment(Seg.a, Line) * Dot_Segment(Seg.b, Line) <= 0;
}

inline int getPoint(const Segment L1, const Segment L2) {
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
    if (t < 0 || t > 1)
        return 0;

    // 线段相交
    return 1;
}

const int maxn = 105;
Segment s[maxn];
vector<Point> p;
int n;

bool crossAllSegment(Segment L) {
    bool ok = true;
    for (int i = 0; i < n && ok; ++i)
        ok &= (getPoint(s[i], L) > 0);
    Log("crossAllSegment( (%.f,%.f)->(%.f,%.f) ) %d\n", L.a.real(), L.a.imag(),
        L.b.real(), L.b.imag(), ok);
    return ok;
}

// 判断两个线段上的点自由组合连城线段是否能与所有线段相交
bool judge(int a, int b) { return crossAllSegment(Segment(p[a], p[b])); }

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        p.clear();

        for (int i = 0; i < n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            s[i].a = Point(x1, y1);
            s[i].b = Point(x2, y2);
            p.push_back(s[i].a);
            p.push_back(s[i].b);
        }

        p.erase(unique(p.begin(), p.end()), p.end());

        bool ok = false;
        int sz = p.size();
        for (int i = 0; i < sz && !ok; ++i)
            for (int j = i + 1; j < sz && !ok; ++j)
                ok |= judge(i, j);

        printf("%s\n", (ok || sz == 1) ? "Yes!" : "No!");
    }
    return 0;
}