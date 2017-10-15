#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define Log(format, ...) //  printf(format, ##__VA_ARGS__)

/* 计算几何模板 */

const double eps = 1e-8;
const double INF = 0x4242424242424242;
inline int sgn(const double &x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
struct Vector;
inline double Cross(const Vector &a, const Vector &b);

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
        return sgn(y - rhs.y) > 0;
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
            return sgn(Cross(rhs.toVector(), a)) > 0;
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
    //注意先判断平行和重合
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
    * 求多边形面积
    * @param p              点集
    * @param numOfSide     多边形边数
    * @return   返回多边形面积
    */
double getArea(Point p[], int numberOfSide) {
    double area = 0.0;
    for (int i = 2; i < numberOfSide; ++i)
        area += fabs(0.5 * Cross(p[i] - p[0], p[i - 1] - p[0]));
    return area;
}

/**
    * 求点集的凸包
    * @param p              点集,需要保证已经排序,并且点需要有不同的编号
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

/**
    * 求直线集合的半平面交(需要g++编译器)
    * @param s              线段集合
    * @param numOfSide      线段数目
    * @param ans            返回的多边形点
    * @return   返回结果多边形点的个数
    */
//用于计算的双端队列

//获取半平面交的多边形（多边形的核）
//参数：向量集合[l]，向量数量[ln];(半平面方向在向量左边）
//函数运行后如果n[即返回多边形的点数量]为0则不存在半平面交的多边形（不存在区域或区域面积无穷大）
int Half_Plane(Segment s[], int numOfSide, Point ans[]) {
    sort(s, s + numOfSide);

    int del = 0;
    for (int i = 1; i < numOfSide; ++i) {
        if (sgn(s[i].getAngle() - s[del].getAngle()) != 0)
            s[++del] = s[i];
    }
    numOfSide = 1 + del;

    Segment dequeue[numOfSide * 2];
    int bot = 0, top = 1;
    dequeue[0] = s[0];
    dequeue[1] = s[1];
    for (int i = 2; i < numOfSide; i++) {
        if (parallel(dequeue[top].toVector(), dequeue[top - 1].toVector()) ||
            parallel(dequeue[bot].toVector(), dequeue[bot + 1].toVector()))
            return 0;

        while (bot < top &&
               Point_Segment(getIntersection(dequeue[top], dequeue[top - 1]),
                             s[i]) < 0)
            top--;
        while (bot < top &&
               Point_Segment(getIntersection(dequeue[bot], dequeue[bot + 1]),
                             s[i]) < 0)
            bot++;
        dequeue[++top] = s[i];
    }

    while (bot < top &&
           Point_Segment(getIntersection(dequeue[top], dequeue[top - 1]),
                         dequeue[bot]) < 0)
        top--;
    while (bot < top &&
           Point_Segment(getIntersection(dequeue[bot], dequeue[bot + 1]),
                         dequeue[top]) < 0)
        bot++;

    //计算交点(注意不同直线形成的交点可能重合)
    if (top <= bot + 1) {
        return 0;
    }

    int len = 0;
    for (int i = bot; i < top; i++)
        ans[len++] = getIntersection(dequeue[i], dequeue[i + 1]);
    if (bot < top + 1)
        ans[len++] = getIntersection(dequeue[bot], dequeue[top]);

    return len;
}
// int Half_Plane3(Segment s[], int numOfSide, Point ans[]) {
//     sort(s, s + numOfSide);

//     int del = 1;
//     for (int i = 1; i < numOfSide; ++i) {
//         if (sgn(s[i].getAngle() - s[del].getAngle()) != 0)
//             s[del++] = s[i];
//     }
//     numOfSide = del;

//     int first, last;
//     Point *p = new Point[numOfSide];
//     Segment *q = new Segment[numOfSide];

//     q[first = last = 0] = s[0];

//     for (int i = 1; i < numOfSide; i++) {
//         while (first < last && Point_Segment(p[last - 1], s[i]) < 0)
//             last--;
//         while (first < last && Point_Segment(p[first], s[i]) < 0)
//             first++;
//         q[++last] = s[i];

//         if (first < last)
//             GetIntersection(q[last - 1], q[last], &p[last - 1]);
//     }
//     while (first < last && Point_Segment(p[last - 1], q[first]) < 0)
//         last--;
//     if (last - first <= 1)
//         return 0;

//     GetIntersection(q[last], q[first], &p[last]);

//     int m = 0;
//     for (int i = first; i <= last; i++)
//         ans[m++] = p[i];
//     return m;
// }
// int Half_Plane2(Segment s[], int numOfSide, Point ans[]) {
//     // s[numOfSide++] = Segment(Point(INF, INF), Point(-INF, INF));
//     // s[numOfSide++] = Segment(Point(-INF, INF), Point(-INF, -INF));
//     // s[numOfSide++] = Segment(Point(-INF, -INF), Point(INF, -INF));
//     // s[numOfSide++] = Segment(Point(INF, -INF), Point(INF, INF));
//     sort(s, s + numOfSide);

//     Log("\n\nHalf_Plane\n");

//     int del = 0;
//     for (int i = 1; i < numOfSide; ++i) {
//         if (sgn(s[i].getAngle() - s[del].getAngle()) != 0)
//             s[++del] = s[i];
//     }
//     numOfSide = del + 1;

//     for (int i = 0; i < numOfSide; ++i)
//         s[i].print(1);

//     int front = -1, rear = 0;
//     Segment q[numOfSide];

//     for (int i = 0; i < numOfSide; ++i) {
//         int it = i % numOfSide;

//         Log("%d Testing", i);
//         s[it].print(1);

//         while (front > rear && Point_Segment(ans[front], s[it]) < 0) {
//             front--;
//             Log("\tHead pop\n");
//         }

//         while (front > rear && Point_Segment(ans[rear + 1], s[it]) < 0) {
//             rear++;
//             Log("\tRear pop\n");
//         }

//         if (front - rear < 0) {
//             q[++front] = s[it];
//             Log("Add [%d]", front);
//             s[it].print(1);
//         } else {
//             Point p;
//             int po = Segment_Segment(s[it], q[front], &p);
//             //
//             Log("getpoint("),s[it].print(),q[front].print(),Log(")="),p.print(1);
//             if (po == 0 || po == 1) {
//                 ans[++front] = p;
//                 q[front] = s[it];
//                 Log("Add [%d]", front);
//                 p.print(0);
//                 Log(" [%d]", front);
//                 s[it].print(1);
//             } else {
//                 Log("ERROR\n");
//             }
//         }

//         Log("front:%d rear:%d\t", front, rear);
//         for (int j = rear + 1; j <= front; ++j) {
//             ans[j].print();
//             Log(" ");
//         }
//         Log("\n\n");
//     }

//     Log("front:%d rear:%d\n", front, rear);
//     int len = front - rear;
//     for (int i = 0; i < len; ++i)
//         ans[i] = ans[rear + i + 1];
//     for (int i = 1; i < len; ++i)
//         if (ans[i] == ans[i - 1]) {
//             ans[i] = ans[i + 1];
//             len--;
//         }
//     return len;
// }

const int maxn = 1505;
bool vis[maxn];
Point p[maxn];
Point ans[maxn];
Segment s[maxn];

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; ++i) {
            p[i] = read_Point();
        }
        for (int i = 0; i < n; ++i)
            s[i] = Segment(p[i], p[(i + 1) % n]);

        int len = Half_Plane(s, n, ans);

        printf("%.7f\n", getArea(ans, len));
    }
    return 0;
}