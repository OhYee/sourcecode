#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-10;

int sign(double x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point operator+(const Point rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator*(const double p) { return Point(p * x, p * y); }
    Point operator/(const double p) { return Point(x / p, y / p); }
    Point operator-() { return Point(-x, -y); }
    bool operator==(const Point &rhs) {
        return sign(x - rhs.x) == 0 && sign(y - rhs.y) == 0;
    }
};
// 向量运算,加减乘除取反
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(p * A.x, p * A.y); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
Point operator-(Point A) { return Point(-A.x, -A.y); }

double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double xmulti(Point p, Point a, Point b) {
    return (a.x - p.x) * (b.y - p.y) - (a.y - p.y) * (b.x - p.x);
}

struct Line {
    Point p1;
    Point p2;
    Line(Point _p1 = Point(), Point _p2 = Point()) : p1(_p1), p2(_p2) {}
};

// 判断是否重叠
bool judge(Line lx, Point v1, Point v2, Point p0) {
    Point p1 = lx.p1;
    Point p2 = lx.p2;
    double a = (p0.x - p1.x);
    double b = (p0.y - p2.y);
    double c = (p0.x - p2.x);
    double d = (p0.y - p1.y);
    double vx = v1.x - v2.x;
    double vy = v1.y - v2.y;
    if (sign(a * vy + b * vx - c * vy - d * vx) == 0) {
        if (sign(a * b - c * d) == 0)
            return true;
        else
            return false;
    }
    double t = (c * d - a * b) / (a * vy + b * vx - c * vy - d * vx);
    if (sign(t) < 0)
        return false;
    Point pxx = Point(p0.x + t * v1.x, p0.y + t * v1.y);
    Point p11 = Point(p1.x + t * v2.x, p1.y + t * v2.y);
    Point p22 = Point(p2.x + t * v2.x, p2.y + t * v2.y);
    double dd1 = pxx.x - p11.x;
    double dd2 = pxx.x - p22.x;
    double dd3 = pxx.y - p11.y;
    double dd4 = pxx.y - p22.y;
    int flag1 = sign(dd1) * sign(dd2);
    int flag2 = sign(dd3) * sign(dd4);
    if (flag1 > 0 || flag2 > 0)
        return false;
    else {
        return true;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    Point triangle[2][4];
    int Case = 1;
    while (T--) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                double x, y;
                scanf("%lf%lf", &x, &y);
                triangle[i][j] = Point(x, y);
            }
        }

        int ans = 0;
        Point term;
        Line test;
        for (int i = 1; i <= 3; i++) {
            term = triangle[0][i];
            test.p1 = triangle[1][1];
            test.p2 = triangle[1][2];
            if (judge(test, triangle[0][3], triangle[1][3], term)) {
                ans = 1;
                break;
            }
            test.p1 = triangle[1][1];
            test.p2 = triangle[1][3];
            if (judge(test, triangle[0][3], triangle[1][3], term)) {
                ans = 1;
                break;
            }
            test.p1 = triangle[1][2];
            test.p2 = triangle[1][3];
            if (judge(test, triangle[0][3], triangle[1][3], term)) {
                ans = 1;
                break;
            }
        }
        for (int i = 1; i <= 3; i++) {
            term = triangle[1][i];
            test.p1 = triangle[0][1];
            test.p2 = triangle[0][2];
            if (judge(test, triangle[1][3], triangle[0][3], term)) {
                ans = 1;
                break;
            }
            test.p1 = triangle[0][1];
            test.p2 = triangle[0][3];
            if (judge(test, triangle[1][3], triangle[0][3], term)) {
                ans = 1;
                break;
            }
            test.p1 = triangle[0][2];
            test.p2 = triangle[0][3];
            if (judge(test, triangle[1][3], triangle[0][3], term)) {
                ans = 1;
                break;
            }
        }
        if (ans)
            printf("Case #%d: YES\n", Case++);
        else
            printf("Case #%d: NO\n", Case++);
    }
    return 0;
}
