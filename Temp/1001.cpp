#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) printf(format, ##__VA_ARGS__)

/*
* 完全大数模板 修改版
* 输出cin>>a
* 输出a.print();
* 注意这个输入不能自动去掉前导0的，可以先读入到char数组，去掉前导0，再用构造函数。
* by kuangbin GG.
*/
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum {
  private:
    int a[5000]; //可以控制大数的位数
    int len;

  public:
    BigNum() {
        len = 1;
        memset(a, 0, sizeof(a));
    }                        //构造函数
    BigNum(const long long); //将一个int类型的变量转化成大数
    BigNum(const char *);    //将一个字符串类型的变量转化为大数
    BigNum(const BigNum &);  //拷贝构造函数
    BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算
    friend istream &operator>>(istream &, BigNum &); //重载输入运算符
    friend ostream &operator<<(ostream &, BigNum &); //重载输出运算符
    BigNum
    operator+(const BigNum &) const; //重载加法运算符，两个大数之间的相加运算
    BigNum
    operator-(const BigNum &) const; //重载减法运算符，两个大数之间的相减运算
    BigNum
    operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算
    BigNum
    operator/(const int &) const; //重载除法运算符，大数对一个整数进行相除运算
    BigNum operator^(const int &) const; //大数的n次方运算
    int operator%(const int &) const; //大数对一个int类型的变量进行取模运算
    bool operator>(const BigNum &T) const; //大数和另一个大数的大小比较
    bool operator>(const int &t) const; //大数和一个int类型的变量的大小比较
    void print();                       //输出大数
    void read(const char *s);           //从字符串读入
    void pre0(char *s);                 //取出字符串的前导0;
};
BigNum::BigNum(const long long b) //将一个int类型的变量转化为大数
{
    long long c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    while (d > MAXN) {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char *s) //将一个字符串类型的变量转化为大数
{
    int t, k, index, L, i;
    memset(a, 0, sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if (L % DLEN)
        len++;
    index = 0;
    for (i = L - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0)
            k = 0;
        for (int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
BigNum::BigNum(const BigNum &T)
    : len(T.len) //拷贝构造函数
{
    int i;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = T.a[i];
}
BigNum &BigNum::operator=(const BigNum &n) //重载赋值运算符，大数之间赋值运算
{
    int i;
    len = n.len;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = n.a[i];
    return *this;
}
istream &operator>>(istream &in, BigNum &b) {
    char ch[MAXSIZE * 4];
    int i = -1;
    in >> ch;
    int L = strlen(ch);
    int count = 0, sum = 0;
    for (i = L - 1; i >= 0;) {
        sum = 0;
        int t = 1;
        for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10) {
            sum += (ch[i] - '0') * t;
        }
        b.a[count] = sum;
        count++;
    }
    b.len = count++;
    return in;
}
ostream &operator<<(ostream &out, BigNum &b) //重载输出运算符
{
    int i;
    cout << b.a[b.len - 1];
    for (i = b.len - 2; i >= 0; i--) {
        printf("%04d", b.a[i]);
    }
    return out;
}
BigNum BigNum::operator+(const BigNum &T) const //两个大数之间的相加运算
{
    BigNum t(*this);
    int i, big;
    big = T.len > len ? T.len : len;
    for (i = 0; i < big; i++) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN) {
            t.a[i + 1]++;
            t.a[i] -= MAXN + 1;
        }
    }
    if (t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}
BigNum BigNum::operator-(const BigNum &T) const //两个大数之间的相减运算
{
    int i, j, big;
    bool flag;
    BigNum t1, t2;
    if (*this > T) {
        t1 = *this;
        t2 = T;
        flag = 0;
    } else {
        t1 = T;
        t2 = *this;
        flag = 1;
    }
    big = t1.len;
    for (i = 0; i < big; i++) {
        if (t1.a[i] < t2.a[i]) {
            j = i + 1;
            while (t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while (j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        } else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while (t1.a[len - 1] == 0 && t1.len > 1) {
        t1.len--;
        big--;
    }
    if (flag)
        t1.a[big - 1] = 0 - t1.a[big - 1];
    return t1;
}
BigNum BigNum::operator*(const BigNum &T) const //两个大数之间的相乘
{
    BigNum ret;
    int i, j, up;
    int temp, temp1;
    for (i = 0; i < len; i++) {
        up = 0;
        for (j = 0; j < T.len; j++) {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if (temp > MAXN) {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            } else {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if (up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int &b) const //大数对一个整数进行相除运算
{
    BigNum ret;
    int i, down = 0;
    for (i = len - 1; i >= 0; i--) {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
int BigNum::operator%(const int &b) const //大数对一个 int类型的变量进行取模
{
    int i, d = 0;
    for (i = len - 1; i >= 0; i--)
        d = ((d * (MAXN + 1)) % b + a[i]) % b;
    return d;
}
BigNum BigNum::operator^(const int &n) const //大数的n次方运算
{
    BigNum t, ret(1);
    int i;
    if (n < 0)
        exit(-1);
    if (n == 0)
        return 1;
    if (n == 1)
        return *this;
    int m = n;
    while (m > 1) {
        t = *this;
        for (i = 1; (i << 1) <= m; i <<= 1)
            t = t * t;
        m -= i;
        ret = ret * t;
        if (m == 1)
            ret = ret * (*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum &T) const //大数和另一个大数的大小比较
{
    int ln;
    if (len > T.len)
        return true;
    else if (len == T.len) {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if (ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    } else
        return false;
}
bool BigNum::operator>(const int &t) const //大数和一个int类型的变量的大小比较
{
    BigNum b(t);
    return *this > b;
}
void BigNum::print() //输出大数
{
    int i;
    printf("%d", a[len - 1]);
    for (i = len - 2; i >= 0; i--)
        printf("%04d", a[i]);
    printf("\n");
}
void BigNum::read(const char *s) {
    int t, k, index, L, i;
    memset(a, 0, sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if (L % DLEN)
        len++;
    index = 0;
    for (i = L - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0)
            k = 0;
        for (int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
void BigNum::pre0(char *s) {
    int pos = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] != '0') {
            pos = i;
            break;
        }
    }
    for (int i = pos; i < len; i++)
        s[i - pos] = s[i];
    s[len - pos] = '\0';
}

/* 计算几何模板 */
typedef BigNum ld;
const double eps = 1e-8;
const double INF = 9e50;
inline int sgn(const ld &x) {
    if (ld == BigNum(0LL))
        return 0;
    return x > 0 ? 1 : -1;
}

struct Vector {
    ld x, y;
    int n;
    Vector(ld _x = 0, ld _y = 0, int _n = 0) : x(_x), y(_y), n(_n) {}
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
    Vector operator*(const int &rhs) const { return Vector(x * rhs, y * rhs); }
    Vector operator/(const int &rhs) const { return Vector(x / rhs, y / rhs); }
    double getAngle() { return atan2(y, x); }
    ld squre() const { return x * x + y * y; }
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
    long long x, y;
    scanf("%I64d%I64d", &x, &y);
    return Point(BigNum(x), BigNum(y));
}

/**
    * 计算两个向量的叉积
    * @param a  向量1
    * @param b  向量2
    * @return   叉积
    */
inline ld Cross(const Vector &a, const Vector &b) {
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
    * 求点到线段中点距离
    * @param p              点
    * @param s              线段
    * @return   点到线段中点距离
    */
ld Point_Segment_Distance2(Point p, Segment s) {
    Point a = (s.a + s.b) / 2;
    return (a - p).squre();
    ;
}

bool calc(Segment s, Point a, Point p) {
    double angle = fabs(((s.a - p) - (s.b - p)).getAngle()) +
                   fabs(((s.a - a) - (s.b - a)).getAngle());
    return sgn(angle - atan2(0, -1)) >= 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        Point p[4];
        for (int i = 0; i < 4; ++i)
            p[i] = read_Point();

        bool Re = Point_Polygon(p[3], p, 3);
        if (!Re) {
            double dis[3];
            double Min = INF;
            int pos = -1;
            for (int i = 0; i < 3; ++i) {
                dis[i] = Point_Segment_Distance2(p[3],
                                                 Segment(p[i], p[(i + 1) % 3]));

                if (pos == -1 || sgn(Min - dis[i]) > 0) {
                    Min = dis[i];
                    pos = i;
                }
            }

            Re = calc(Segment(p[pos], p[(pos + 1) % 3]), p[(pos - 1 + 3) % 3],
                      p[3]);
        }
        printf("%s\n", Re ? "Rejected" : "Accepted");
    }
    return 0;
}