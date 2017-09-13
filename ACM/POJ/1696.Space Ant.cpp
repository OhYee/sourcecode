#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstring>
#include <map>

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
    int n;
    Vector(double _x = 0, double _y = 0, int _n = 0) : x(_x), y(_y), n(_n) {}
    bool operator==(const Vector &rhs) const {
        return sgn(x - rhs.x) == 0 && sgn(y - rhs.y) == 0;
    }
    bool operator!=(const Vector &rhs) const { return !(*this == rhs); }
    bool operator<(const Vector &rhs) const {
        if (sgn(y - rhs.y) == 0)
            return sgn(x - rhs.x) < 0;
        return sgn(y - rhs.y) < 0;
    }
    Vector operator+(const Vector &rhs) const {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator-(const Vector &rhs) const {
        return Vector(x - rhs.x, y - rhs.y);
    }
    double squre() const { return x * x + y * y; }
    double distance() const { return sqrt(squre()); }
    void print(bool flag = 0) const {
        Log("(%.f %.f)", x, y);
        if (flag)
            Log("\n");
    }
};
typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Vector toVector() const { return b - a; }
    double distance() const { return (b - a).distance(); }
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
    * @param p              点集,需要保证已经排序
    * @param numOfPoint     点集内的点的个数
    * @param vis            记录点对应的编号是否可以选择
    * @param ans            返回的凸包
    * @param begin          起始位置
    * @return   返回凸包上点的个数
    */
int Convex_Hull(Point p[], int numOfPoint, bool vis[], Point ans[],
                int begin = 0) {
    int pos = begin - 1;
    // 右链
    for (int i = 0; i < numOfPoint; ++i) {
        if (!vis[p[i].n]) {
            while (pos > 0 &&
                   Point_Segment(p[i], Segment(ans[pos], ans[pos - 1])) > 0) {
                vis[ans[pos--].n] = false;
            }
            ans[++pos] = p[i];
            vis[ans[pos].n] = true;
        }
    }
    // 左链
    for (int i = numOfPoint - 2; i > 0; --i) {
        if (!vis[p[i].n]) {
            while (pos > 0 &&
                   Point_Segment(p[i], Segment(ans[pos], ans[pos - 1])) > 0) {
                vis[ans[pos--].n] = false;
            }
            ans[++pos] = p[i];
            vis[ans[pos].n] = true;
        }
    }
    return pos + 1;
}

const int maxn = 105;

int n;
Point points[maxn];
Point ans[maxn];
bool vis[maxn];

void solve() {
    int len = 0;
    sort(points, points + n);
    memset(vis, false, (n + 5) * sizeof(bool));

    while (len != n) {
        len = Convex_Hull(points, n, vis, ans, len);
        Log("%d\n", len);
    }

    printf("%d", len);
    for (int i = 0; i < len; ++i)
        printf(" %d", ans[i].n);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d", &t);
            points[i] = read_Point();
            points[i].n = t;
        }
        solve();
    }
    return 0;
}