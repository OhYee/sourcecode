#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-9;
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
        return sgn(y - rhs.y) > 0;
    }
    Vector operator+(const Vector &rhs) const {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator-(const Vector &rhs) const {
        return Vector(x - rhs.x, y - rhs.y);
    }
};
typedef Vector Point;
struct Segment {
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b) : a(_a), b(_b) {}
    Vector toVector() const { return b - a; }
};
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
    * 点和直线的关系
    * @param p   目标点
    * @param L   目标直线
    * @return    1 在左侧,0 在直线上,-1在右侧
    */
inline int Point_Segment(const Vector &p, const Segment &L) {
    return sgn(Cross(L.b - L.a, p - L.a));
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

int main() {
    Point p[] = {Point(1, 1), Point(-1, 1), Point(-1, -1), Point(1, -1)};

    printf("%d\n", Point_Polygon(Point(0, 0), p, 4));
    printf("%d\n", Point_Polygon(Point(2, 0), p, 4));
}