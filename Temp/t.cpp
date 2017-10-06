#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define inf 0x7fffffff
#define exp 1e-10
#define PI 3.141592654
using namespace std;
const int maxn = 111;
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
} an[maxn];
typedef Point Vector;
struct Line {
    Point p;
    Vector v;
    double ang;
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) { ang = atan2(v.y, v.x); }
    // Line (Point p,Vector v):p(p),v(v) {ang=atan2(v.y,v.x); }
    friend bool operator<(Line a, Line b) { return a.ang < b.ang; }
} bn[maxn];
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
int dcmp(double x) {
    if (fabs(x) < exp)
        return 0;
    return x > 0 ? 1 : -1;
}
double cross(Vector A, Vector B) { return A.x * B.y - B.x * A.y; }
bool OnLeft(Line L, Point p) {
    return cross(L.v, p - L.p) >=
           0; ///点P在有向直线L的左边（>=0说明在线上也算）
}
Point GetIntersection(Line a, Line b) {
    Vector u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}
// Point GetIntersection(Line l1, Line l2) {
//    Point p;
//    double dot1,dot2;
//    //dot1 = multi(l2.a, l1.b, l1.a);
//    dot1=cross(l1.b-l2.a , l1.a-l2.a);
//    //dot2 = multi(l1.b, l2.b, l1.a);
//    dot2=cross(l2.b-l1.b , l1.a-l1.b);
//    p.x = (l2.a.x * dot2 + l2.b.x * dot1) / (dot2 + dot1);
//    p.y = (l2.a.y * dot2 + l2.b.y * dot1) / (dot2 + dot1);
//    return p;
//}
int HalfplaneIntersection(Line *L, int n, Point *poly) {
    sort(L, L + n);

    int first, last;
    Point *p = new Point[n];
    Line *q = new Line[n];
    q[first = last = 0] = L[0];
    for (int i = 1; i < n; i++) {
        while (first < last && !OnLeft(L[i], p[last - 1]))
            last--;
        while (first < last && !OnLeft(L[i], p[first]))
            first++;
        q[++last] = L[i];
        if (fabs(cross(q[last].v, q[last - 1].v)) < exp) {
            last--;
            if (OnLeft(q[last], L[i].p))
                q[last] = L[i];
        }
        if (first < last)
            p[last - 1] = GetIntersection(q[last - 1], q[last]);
    }
    while (first < last && !OnLeft(q[first], p[last - 1]))
        last--;
    if (last - first <= 1)
        return 0;
    p[last] = GetIntersection(q[last], q[first]);
    int m = 0;
    for (int i = first; i <= last; i++)
        poly[m++] = p[i];
    return m;
}
void calPolygon(Point *p, int n, double &area, bool &shun) {
    p[n] = p[0];
    area = 0;
    double tmp;
    for (int i = 0; i < n; i++)
        area += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
    area /= 2.0;
    if (shun = area < 0)
        area = -area;
}
bool calCore(Point *ps, int n) {
    Line l[maxn];
    ps[n] = ps[0];
    bool shun;
    double area;
    calPolygon(ps, n, area, shun);
    if (shun)
        for (int i = 0; i < n; i++)
            bn[i] = Line(ps[i], ps[i] - ps[i + 1]);
    else
        for (int i = 0; i < n; i++)
            bn[i] = Line(ps[i], ps[i + 1] - ps[i]);
    Point pp[maxn];
    return HalfplaneIntersection(bn, n, pp);
}
int main() {
    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        Point cn[maxn];
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &cn[i].x, &cn[i].y);
        }
        if (!calCore(cn, n))
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}