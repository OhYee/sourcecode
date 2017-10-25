---
title: NWERC 2016 K-Kiwi Trees
date: 2017-10-25 19:45:31
categories: 题解
tags: 
 - Codeforces
 - 计算几何
---

# 题目

{% fold 点击显/隐题目 %}
<div class="oj"><div class="part" title="Description">
You are about to plant a pair of fine kiwi trees inside your big property.  

You are worried that tree branches would grow beyond the boundaries of your property, making your neighbours complain. You must also avoid planting the two trees too close to each other so that the branches of the trees grow into each other, because that could lead to a loss of fruit.  

The seller of the trees guaranteed that no branch or leaf will be farther than 4 meters from the trunk of its tree, thus we will model the trees as circles of radius 4 meters. The trunks are perfectly vertical.  

Local government regulations forbid certain shapes of properties. In particular, in order for government employees to be able to draw and handle maps of the area, each property must satisfy the following properties:  

1. The boundary is a simple polygon, i.e. the sides are non-intersecting and form a closed path.  

2. Each side length of the property is at least 30 meters long.  

3. The angle between any two consecutive sides of the property must be at least 18 degrees ($10%$ of a straight angle), and at most $144$ degrees ($80%$ of a straight angle, or if you will, the angle of a regular decagon).  

Non-convex properties are allowed as long as the angles of consecutive sides follow rule 3 above, so the inner angle at a vertex can also be between $360 − 144 = 216$ and $360 − 18 = 342$ degrees.  

See Figure K.1 for an example.  


![](/post/img/kiwitrees.png)
Figure K.1: Illustration of Sample Input 1 and the solution given in Sample Output 1. All the marked angles are at least 18 and at most 144 degrees.  

Your property follows these rules. Can you plant two trees inside the property such that their branches and leaves do not grow beyond its boundary, and that the branches and leaves of each tree do not grow into the other tree?  


</div><div class="part" title="Input">

The input consists of:  

• One line containing an integer n, where $3 ≤ n ≤ 2000$ is the number of vertices of the polygon describing your property.  

• n lines describing one vertex each. Each such line contains two integers $x$ and $y$, where $0 ≤ x, y ≤ 107$. These two numbers denote the x- and y-coordinates of a vertex in millimeters, in a clockwise order as they appear in the polygon.  

Also, each polygon side is at least 30 meters (30 000 millimeters) long and the angle of two segments at a vertex is at least 18 degrees and at most 144 degrees. The polygon is nonintersecting and closed, i.e. the last vertex is connected to the first vertex.  

</div><div class="part" title="Output">
If it is possible to plant two trees without their branches growing beyond the boundary of your property or into each other, output two lines, each containing two real numbers x and y giving the coordinates in millimeters of two points where the trees can be planted. Otherwise, print “impossible”.  

You may assume that increasing or decreasing the radius by 1 mm will not change whether or not it is possible to plant the trees. Your answer will be accepted if the tree locations are at least 3999 mm away from the boundary and at least 2 · 3999 mm away from each other  

</div><div class="samp"><div class="clear"></div><div class="input part" title="Sample Input">
4
0 3000
29000 38000
56000 0
28000 14000

3
50000 50000
69500 73000
99000 80000


</div><div class="output part" title="Sample Output">
32266.13633130 18219.22050526
24266.13633130 18219.22050526

impossible

</div><div class="clear"></div></div></div>
{% endfold %}

<!--more-->
# 题解
根据计算可以发现对于每一个角,可以完全放入一个圆,按照贪心的思想,尽可能地将两个圆距离更远,因此可以直接枚举每个角的内切圆,判断圆是否在图形内部后再枚举两个圆,判断是否相交,不相交则合法  

由于这里不是凸多边形,因此判断点是否在多边形内需要用射线法  


# 代码
{% fold 点击显/隐代码 %}```cpp Kiwi Trees https://github.com/OhYee/sourcecode/tree/master/ACM 代码备份
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

const double eps = 1e-6;
const double INF = 9e9;
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
        Log("(%.2f %.2f)%s", x, y, cr ? "\n" : "");
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

    p1.print();
    p2.print();
    p3.print(1);

    Log("V1: ");
    v1.print(1);
    Log("V2: ");
    v2.print(1);

    double ang = (v2.getAngle() - v1.getAngle()) * 0.5;

    Vector v = rotation(v1, ang);
    double dis = 4.0 / sin(ang);

    Point p = p2 + Point(dis, v.phi, true);

    Log("Circle Point:");
    p.print(1);

    return p;
}
inline double Cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
inline int Point_Segment(const Vector &p, const Segment &L) {
    // printf("Point_segment %d\n", sgn(Cross(L.b - L.a, p - L.a)));
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
inline int Segment_Segment(const Segment &L1, const Segment &L2,
                           Point *p = NULL) {
    double a = L1.b.x - L1.a.x;
    double b = L2.b.x - L2.a.x;
    double c = L1.b.y - L1.a.y;
    double d = L2.b.y - L2.a.y;
    double f = a * d - b * c;
    // 平行或重叠
    if (sgn(f) == 0) {
        return -1;
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

bool Point_Polygon(const Point &p, const Point polygon[], int numberOfSide) {
    bool ok =
        Point_Segment(p, Segment(polygon[numberOfSide - 1], polygon[0])) >= 0;
    for (int i = 1; i < numberOfSide && ok; ++i) {
        if (!(Point_Segment(p, Segment(polygon[i - 1], polygon[i])) >= 0))
            ok = false;
    }
    return ok;
}

bool Point_Polygon2(const Point &p, const Point polygon[], int numberOfSide) {
    Segment s = Segment(Point(INF, INF), p);
    int cnt = 0;
    for (int i = 0; i < numberOfSide; ++i) {
        if (Segment_Segment(
                s, Segment(polygon[i], polygon[(i + 1) % numberOfSide])) == 1)
            ++cnt;
    }
    return cnt % 2;
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
        if (Point_Polygon2(pp, p, n))
            c[pos++] = pp;
    }

    for (int i = 0; i < pos; ++i)
        c[i].print(1);

    bool ok = false;
    for (int i = 0; i < pos && !ok; ++i)
        for (int j = i + 1; j < pos && !ok; ++j)
            if (sgn(Distance(c[i], c[j]) - 8.0) >= 0) {
                printf("%9f %.9f\n%.9f %.9f\n", c[i].x*1000, c[i].y*1000, c[j].x*1000, c[j].y*1000);
                ok = true;
            }
    if (!ok)
        printf("impossible\n");
    return 0;
}
```
{% endfold %}


