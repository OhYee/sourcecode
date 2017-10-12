#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Log(format, ...) // printf(format, ##__VA_ARGS__)
/* 计算几何模板 */
const double eps = 1e-10;
const double INF = 0x4242424242424242;
inline int sgn(const double &x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
struct Vector;
struct Segment;
double Cross(const Vector &, const Vector &);
int Point_Segment(const Vector &, const Segment &);
struct Vector {
    double x, y;
    int n;
    Vector(double _x = 0, double _y = 0, int _n = 0) : x(_x), y(_y), n(_n) {}
    bool operator==(const Vector &rhs) const {
        return sgn(x - rhs.x) == 0 && sgn(y - rhs.y) == 0;
    }
    bool operator!=(const Vector &rhs) const { return !(*this == rhs); }
    bool operator<(const Vector &rhs) const {
        if (sgn(x - rhs.x) == 0)
            return sgn(y - rhs.y) < 0;
        return sgn(x - rhs.x) < 0;
    }
    Vector operator+(const Vector &rhs) const {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator-(const Vector &rhs) const {
        return Vector(x - rhs.x, y - rhs.y);
    }
    Vector operator*(const double &rhs) const {
        return Vector(x * rhs, y * rhs);
    }
    Vector operator/(const double &rhs) const {
        return Vector(x / rhs, y / rhs);
    }
    double getAngle() { return atan2(y, x); }
    double squre() const { return x * x + y * y; }
    double distance() const { return sqrt(squre()); }
    void print(bool flag = 0) const {
        Log("(%.2f %.2f)", x, y);
        if (flag)
            Log("\n");
    }
};
typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    bool operator<(const Segment &rhs) const {
        double angle1 = getAngle();
        double angle2 = rhs.getAngle();
        if (sgn(angle1 - angle2) == 0)
            return Point_Segment(a, rhs) > 0;
        return sgn(angle1 - angle2) < 0;
    }
    double getAngle() const { return toVector().getAngle(); }
    Vector toVector() const { return b - a; }
    double distance() const { return toVector().distance(); }
    void print(bool flag = 0) const {
        a.print();
        Log(" -> ");
        b.print();
        if (flag)
            Log("\n");
    }
};
/**
    * 读入一个点的坐标
    * @return   读入的点
    */
inline Point read_Point() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return Point(x, y);
}
inline double xmult(const Vector &a, const Vector &b, const Vector &c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
/**
    * 计算两个向量的叉积
    * @param a  向量1
    * @param b  向量2
    * @return   叉积
    */
inline double Cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
/**
    * 计算两个向量的点积
    * @param a  向量1
    * @param b  向量2
    * @return   点积
    */
inline double Dot(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
/**
    * 计算两点之间的距离
    * @param a  线段L1
    * @param b  线段L2
    * @return   两点间的距离
    */
inline double Distance(const Point &a, const Point &b) {
    return (a - b).distance();
}
/**
    * 点和直线的关系
    * @param p   目标点
    * @param L   目标直线
    * @return    1 在左侧,0 在直线上,-1在右侧
    */
inline int Point_Segment(const Vector &p, const Segment &L) {
    // printf("Point_segment %d\n", sgn(Cross(L.b - L.a, p - L.a)));
    return sgn(Cross(L.b - L.a, p - L.a));
}
/**
    * 计算两个线段(直线)是否平行
    * @param L1 L1的向量
    * @param L2 L2的向量
    * @return   返回是否平行
    */
bool parallel(const Vector &L1, const Vector &L2) {
    return sgn(Cross(L1, L2)) == 0;
}
/**
    * 计算两个直线的交点(需要确保不平行、重合)
    * @param L1 L1的向量
    * @param L2 L2的向量
    * @return   返回是否平行
    */
Point getIntersection(const Segment &L1, const Segment &L2) {
    Point ret = L1.a;
    double t = ((L1.a.x - L2.a.x) * (L2.a.y - L2.b.y) -
                (L1.a.y - L2.a.y) * (L2.a.x - L2.b.x)) /
               ((L1.a.x - L1.b.x) * (L2.a.y - L2.b.y) -
                (L1.a.y - L1.b.y) * (L2.a.x - L2.b.x));
    ret.x += (L1.b.x - L1.a.x) * t;
    ret.y += (L1.b.y - L1.a.y) * t;
    return ret;
}
/**
    * 计算两个线段的位置关系
    * @param L1 线段L1
    * @param L2 线段L2
    * @param p  返回交点坐标
    * @return   2   重叠
                1   相交
                0   延长线相交
                -1  平行
                -2  共线不交
    */
inline int Segment_Segment(const Segment &L1, const Segment &L2,
                           Point *p = NULL) {
    double a = L1.b.x - L1.a.x;
    double b = L2.b.x - L2.a.x;
    double c = L1.b.y - L1.a.y;
    double d = L2.b.y - L2.a.y;
    double f = a * d - b * c;
    // 平行或重叠
    if (sgn(f) == 0) {
        if (Point_Segment(L1.a, L2)) {
            // 平行
            return -1;
        } else {
            // 共线
            int len = max(max(Distance(L1.a, L2.a), Distance(L1.a, L2.b)),
                          max(Distance(L1.b, L2.a), Distance(L1.b, L2.b)));
            if (sgn(len - L1.distance() - L2.distance()) > 0) {
                // 共线不交
                return -2;
            } else {
                // 重叠
                return 2;
            }
        }
    }
    double g = L2.b.x - L1.a.x;
    double h = L2.b.y - L1.a.y;
    double t = (d * g - b * h) / f;
    double s = (-c * g + a * h) / f;
    if (p != NULL)
        *p = Point(L1.a.x + t * a, L1.a.y + t * c);
    // 在延长线上
    if (t < 0 || t > 1 || s < 0 || s > 1)
        return 0;
    // 线段相交
    return 1;
}
/**
    * 判断点是否在多边形内部
    * @param p              需要判断的点
    * @param polygon        多边形点集,需要保证有序
    * @param numberOfSide   多边形边数
    * @return   1 点在多边形内,0在多边形上, -1 点不在多边形内
    */
int Point_Polygon(const Point &p, const Point polygon[],
                  const int numberOfSide) {
    int res = Point_Segment(p, Segment(polygon[numberOfSide - 1], polygon[0]));
    for (int i = 1; i < numberOfSide; ++i)
        res = min(res, Point_Segment(p, Segment(polygon[i - 1], polygon[i])));
    return res;
}

const int maxn = 505;
Point Rec1[4], Rec2[4];
Segment s[maxn];
bool del[maxn];
int n;

// 保留里面的
bool judge1(int t, Point Rec[]) {
    bool era = false;

    int in[2]; // 两个点是否在矩形内
    in[0] = Point_Polygon(s[t].a, Rec, 4);
    in[1] = Point_Polygon(s[t].b, Rec, 4);

    if (in[0] == 0 && in[1] == 0) {
        // 正好在矩形上
        era = true;
    } else if (in[0] >= 0 && in[1] >= 0) {
        // 在矩形内部
        era = false;
    } else {
        // 交点个数
        int cnt = 0;
        Point p, pp[2];
        for (int i = 0; i < 4; i++) {
            if (1 ==
                Segment_Segment(s[t], Segment(Rec[i], Rec[(i + 1) % 4]), &p)) {
                pp[cnt++] = p;
            }
        }
        if (cnt == 2 && pp[0] == pp[1])
            --cnt;

        if (in[0] < 0 && in[1] < 0) {
            // 两个点都在矩形外部
            if (cnt == 0) {
                // 全部在矩形外部
                era = true;
            } else {
                if (cnt == 1) {
                    // 有一个交点
                    era = true;
                } else {
                    // 有两个交点
                    s[n++] = Segment(pp[0], pp[1]);
                    era = true;
                }
            }
        } else {
            // 一半在外面，一半在里面
            era = true;
            if (in[0] >= 0) {
                s[n++] = Segment(pp[0], s[t].a);
            } else {
                s[n++] = Segment(pp[0], s[t].b);
            }
        }
    }
    del[t] = era;
    return era;
}

// 保留外面的
bool judge2(int t, Point Rec[]) {
    bool era = false;

    int in[2]; // 两个点是否在矩形内
    in[0] = Point_Polygon(s[t].a, Rec, 4);
    in[1] = Point_Polygon(s[t].b, Rec, 4);

    if (in[0] == 0 && in[1] == 0) {
        // 正好在矩形上
        era = true;
    } else if (in[0] >= 0 && in[1] >= 0) {
        // 在矩形内部
        era = true;
    } else {
        // 交点个数
        int cnt = 0;
        Point p, pp[2];
        for (int i = 0; i < 4; i++) {
            if (1 ==
                Segment_Segment(s[t], Segment(Rec[i], Rec[(i + 1) % 4]), &p)) {
                pp[cnt++] = p;
            }
        }
        if (cnt == 2 && pp[0] == pp[1])
            --cnt;

        if (in[0] < 0 && in[1] < 0) {
            // 两个点都在矩形外部
            if (cnt == 0) {
                // 全部在矩形外部
                era = false;
            } else {
                if (cnt == 1) {
                    // 有一个交点
                    s[n++] = Segment(pp[0], s[t].a);
                    s[n++] = Segment(pp[0], s[t].b);
                    era = true;
                } else {
                    // 有两个交点
                    if (Distance(pp[0], s[t].a) + eps <
                        Distance(pp[1], s[t].b)) {
                        s[n++] = Segment(pp[0], s[t].a);
                        s[n++] = Segment(pp[1], s[t].b);
                    } else {
                        s[n++] = Segment(pp[1], s[t].a);
                        s[n++] = Segment(pp[0], s[t].b);
                    }

                    era = true;
                }
            }
        } else {
            // 一半在外面，一半在里面
            era = true;
            if (in[0] >= 0) {
                s[n++] = Segment(pp[0], s[t].b);
            } else {
                s[n++] = Segment(pp[0], s[t].a);
            }
        }
    }
    del[t] = era;
    return era;
}

void Erase() {
    int pos = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (del[i]) {
            ++cnt;
            continue;
        } else {
            s[pos++] = s[i];
        }
    }
    n -= cnt;
    memset(del, false, sizeof(del));
}

void cmp1(Segment &t) {
    if (t.b < t.a)
        swap(t.a, t.b);
}
bool cmp2(Segment a, Segment b) {
    if (a.a == b.a)
        return b.b < a.b;
    return b.a < a.a;
}

int main() {
    Rec1[0] = read_Point();
    Rec1[2] = read_Point();
    Rec1[1] = Point(Rec1[2].x, Rec1[0].y);
    Rec1[3] = Point(Rec1[0].x, Rec1[2].y);

    Rec2[0] = read_Point();
    Rec2[2] = read_Point();
    Rec2[1] = Point(Rec2[2].x, Rec2[0].y);
    Rec2[3] = Point(Rec2[0].x, Rec2[2].y);

    n = 0;
    memset(del, false, sizeof(del));

    double x1, x2, y1, y2;
    while (~scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2))
        s[n++] = Segment(Point(x1, y1), Point(x2, y2));

    // for (int i = 0; i < n; ++i)
    //     printf("%.4f %.4f %.4f %.4f\n", s[i].a.x, s[i].a.y, s[i].b.x,
    //     s[i].b.y);
    // printf("\n");

    int oldn = n;
    for (int i = 0; i < oldn; ++i)
        judge1(i, Rec1);
    Erase();

    // for (int i = 0; i < n; ++i)
    //     printf("%.4f %.4f %.4f %.4f\n", s[i].a.x, s[i].a.y, s[i].b.x,
    //     s[i].b.y);
    // printf("\n");

    oldn = n;
    for (int i = 0; i < oldn; ++i)
        judge2(i, Rec2);
    Erase();

    // for (int i = 0; i < n; ++i)
    //     printf("%.4f %.4f %.4f %.4f\n", s[i].a.x, s[i].a.y, s[i].b.x,
    //     s[i].b.y);
    // printf("\n");

    for (int i = 0; i < n; ++i)
        cmp1(s[i]);
    sort(s, s + n, cmp2);

    for (int i = 0; i < n; ++i)
        printf("%.4f %.4f %.4f %.4f\n", fabs(s[i].a.x), fabs(s[i].a.y),
               fabs(s[i].b.x), fabs(s[i].b.y));

    return 0;
}