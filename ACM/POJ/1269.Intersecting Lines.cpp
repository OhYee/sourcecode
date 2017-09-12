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
inline bool Segment_Segment(const Segment &L1, const Segment &L2) {
    if (sgn(Distance(L1.a, L1.b)) == 0 || sgn(Distance(L2.a, L2.b)) == 0)
        return 0;
    return (Point_Segment(L1.a, L2) * Point_Segment(L1.b, L2) <= 0) &&
           (Point_Segment(L2.a, L1) * Point_Segment(L2.b, L1) <= 0);
}
inline int Segment_Line(const Segment &Seg, const Segment &Line) {
    Log("(%.f,%.f)->(%.f,%.f)   (%.f,%.f)->(%.f,%.f)\n", Seg.a.real(),
        Seg.a.imag(), Seg.b.real(), Seg.b.imag(), Line.a.real(), Line.a.imag(),
        Line.b.real(), Line.b.imag());
    if (sgn(Distance(Line.a, Line.b)) == 0)
        return 0;
    return Point_Segment(Seg.a, Line) * Point_Segment(Seg.b, Line) <= 0;
}
inline int getPoint(const Segment L1, const Segment L2, Point &p) {
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

    p = Point(L1.a.real() + t * a, L1.a.imag() + t * c);
    // 在延长线上
    if (t < 0 || t > 1 || s < 0 || s > 1)
        return 0;

    // 线段相交
    return 1;
}




int main() {
    int T;
    scanf("%d", &T);
    printf("INTERSECTING LINES OUTPUT\n");
    while (T--) {
        Point L1a = read_Point();
        Point L1b = read_Point();
        Point L2a = read_Point();
        Point L2b = read_Point();

        Segment L1 = Segment(L1a, L1b);
        Segment L2 = Segment(L2a, L2b);
        Point p;
        int state = getPoint(L1, L2, p);

        if (state >= 0) {
            printf("POINT %.2f %.2f\n", p.real(), p.imag());
        } else if (Point_Segment(L1.a, L2) == 0) {
            printf("LINE\n");
        } else {
            printf("NONE\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}