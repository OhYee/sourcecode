#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-6;
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator+(const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    double getAngle() { return atan2(y, x); }
    double normal() { return x * x + y * y; }
    double abs() { return sqrt(normal()); }
    void print(bool cr = false) const {
        printf("(%.2f %.2f)%s", x, y, cr ? "\n" : "");
    }
};
typedef Point Vector;
           
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

Vector rotation(Vector v, double phi) {
    double Dis = v.abs();
    double newPhi = phi + v.getAngle();
    return Vector(Dis * cos(newPhi), Dis * sin(newPhi));
}

// p2->p1 p2->p3
Point getCircle(const Point &p1, const Point &p2, const Point &p3) {
    p1.print(0);
    p2.print(0);
    p3.print(1);

    Vector v1 = p1 - p2;
    Vector v2 = p3 - p2;
    v1.print(0);
    v2.print(1);

    double ang = (v2.getAngle() - v1.getAngle()) * 0.5;
    printf("%.2f %.2f %.2f\n",v2.getAngle(),v1.getAngle(),ang);
    Vector v = rotation(v1, ang);
    double vang = v.getAngle();
    double dis = 4.0 / tan(ang);
    printf("%.2f %.2f\n",dis,vang);
    Vector vv = Vector(dis * cos(vang), dis * sin(vang));
    Point p = vv + p2;
    p.print(1);
    printf("\n");
    return p;
}

const int maxn = 2005;
Point p[maxn], c[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        p[i] = read_point();
    for (int i = 0; i < n; ++i) {
        c[i] = getCircle(p[i], p[(i + 1) % n], p[(i + 2) % n]);
    }

    bool ok = false;
    for (int i = 0; i < n && !ok; ++i)
        for (int j = i + 1; j < n && !ok; ++j)
            if (sgn(Distance(c[i], c[j]) - 8.0) >= 0) {
                printf("%9f %.9f\n%.9f %.9f\n", c[i].x, c[i].y, c[j].x, c[j].y);
                ok = true;
            }
    if (!ok)
        printf("impossible\n");
    return 0;
}