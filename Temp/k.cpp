#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-6;
struct Point {
    double x, y;
    double r, phi;
    Point(double a = 0, double b = 0, bool polar = false) {
        if (!polar) {
            x = a;
            y = b;
            r = sqrt(x * x + y * y);
            phi = atan2(y, x);
        } else {
            r = a;
            phi = b;
            x = r * cos(phi);
            y = r * sin(phi);
        }
    }
    Point operator-(const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator+(const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    double getAngle() { return atan2(y, x); }
    double normal() { return x * x + y * y; }
    double abs() { return r; }
    void print(bool cr = false) const {
        printf("(%.2f %.2f)%s", x, y, cr ? "\n" : "");
    }
};
typedef Point Vector;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
};

Point read_point() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return Point(x / 1000, y / 1000);
}

int sgn(const double x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}

double Distance(const Point &p1, const Point &p2) { return (p1 - p2).abs(); }
double Distance2(const Point &p1, const Point &p2) {
    return (p1 - p2).normal();
}

Vector rotation(Vector v, double phi) { return Vector(v.r, v.phi + phi, true); }

// p2->p1 p2->p3
Point getCircle(const Point &p1, const Point &p2, const Point &p3) {

    Vector v1 = p1 - p2;
    Vector v2 = p3 - p2;


    double ang = (v2.getAngle() - v1.getAngle()) * 0.5;

    Vector v = rotation(v1, ang);
    double dis = 4.0 / sin(ang);

    Point p = Point(dis, v.phi, true);

    return p;
}
inline double Cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
inline int Point_Segment(const Vector &p, const Segment &L) {
    // printf("Point_segment %d\n", sgn(Cross(L.b - L.a, p - L.a)));
    return sgn(Cross(L.b - L.a, p - L.a));
}
bool Point_Polygon(const Point &p, const Point polygon[], int numberOfSide) {
    bool ok =
        Point_Segment(p, Segment(polygon[numberOfSide - 1], polygon[0])) >= 0;
    for (int i = 1; i < numberOfSide && ok; ++i) {
        if (!(Point_Segment(p, Segment(polygon[i - 1], polygon[i])) >= 0))
            ok = false;
    }
    return ok;
}

const int maxn = 2005;
Point p[maxn], c[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        p[i] = read_point();
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        Point pp = getCircle(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (Point_Polygon(pp, p, n))
            c[pos++] = pp;
    }

    bool ok = false;
    for (int i = 0; i < pos && !ok; ++i)
        for (int j = i + 1; j < pos && !ok; ++j)
            if (sgn(Distance(c[i], c[j]) - 8.0) >= 0) {
                printf("%9f %.9f\n%.9f %.9f\n", c[i].x, c[i].y, c[j].x, c[j].y);
                ok = true;
            }
    if (!ok)
        printf("impossible\n");
    return 0;
}