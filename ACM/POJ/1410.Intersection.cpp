#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

/* 计算几何模板 */
const double eps = 1e-8;
const double INF = 9e50;

inline int sgn(const double &x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
struct Vector {
    double x, y;
    Vector(double _x = 0, double _y = 0) : x(_x), y(_y) {}

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
    double squre() const { return x * x + y * y; }
    double distance() const { return sqrt(squre()); }
    void print() const { Log("(%.f %.f)", x, y); }
};

typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Vector toVector() const { return b - a; }
    double distance() const { return (b - a).distance(); }
    void print() const {
        a.print();
        Log(" -> ");
        b.print();
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
    p.print();
    Log("     ");
    L.print();
    Log("      %d\n", sgn(Cross(L.b - L.a, p - L.a)));
    return sgn(Cross(L.b - L.a, p - L.a));
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
inline int Segment_Segment(const Segment L1, const Segment L2,
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
    * @return   true 点在多边形内,false 点不在多边形内
    */
bool Point_Polygon(Point p, Point polygon[], int numberOfSide) {
    bool ok =
        Point_Segment(p, Segment(polygon[numberOfSide - 1], polygon[0])) >= 0;
    for (int i = 1; i < numberOfSide && ok; ++i) {
        if (!(Point_Segment(p, Segment(polygon[i - 1], polygon[i])) >= 0))
            ok = false;
    }
    return ok;
}

/**
    * 求点集的凸包
    * @param p              点集
    * @param numOfPoint     点集内的点的个数
    * @param ans            返回的凸包
    *
void Convex_Hull(Point p[], int numOfPoint, Point ans[]) {
    sort(p, p + numberOfPoint);
    bool *vis = new bool[numOfPoint + 5];
    ans[0] = p[0];
    for (int i = 0; i < numberOfPoint; ++i) {
    }
}
*/
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        Segment s;
        s.a = read_Point();
        s.b = read_Point();

        Point p1 = read_Point();
        Point p2 = read_Point();

        Point pots[4] = {p1, p2, Point(p1.x, p2.y), Point(p2.x, p1.y)};
        sort(pots, pots + 4);

        Segment segs[4] = {Segment(pots[0], pots[2]), Segment(pots[2], pots[3]),
                           Segment(pots[3], pots[1]),
                           Segment(pots[1], pots[0])};
        swap(pots[1], pots[2]);
        swap(pots[2], pots[3]);

        // 判断是否在多边形内部
        bool ans = Point_Polygon(s.a, pots, 4) && Point_Polygon(s.b, pots, 4);

        // 判断相交
        for (int i = 0; i < 4; ++i)
            ans |= Segment_Segment(segs[i], s) > 0;

        printf("%c\n", ans ? 'T' : 'F');
    }
    return 0;
}
