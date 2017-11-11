#include <cmath>
#include <cstdio>
using namespace std;

/*
* 匈牙利算法邻接表形式
* 使用前用init()进行初始化，给uN赋值
* 加边使用函数addedge(u,v)
*/
const int MAXN = 105;   //点数的最大值
const int MAXM = 10025; //边数的最大值
struct Edge {
    int to, next;
} edge[MAXM];
int head[MAXN], tot, uN;
void init(int un) {
    uN = un;
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
    // cout<<"add"<<u<<" "<<v<<endl;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
bool dfs(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++) { //点的编号0~uN-1
        memset(used, false, sizeof(used));
        if (dfs(u))
            res++;
    }
    return res;
}

struct Car {
    double x, y, v, a, t, l, w;
};

const double PI = acos(-1.0);
const double eps = 1e-5;
const int maxn = 105;
int n, m;
double t, a, b;

Car c1[maxn], c2[maxn];

struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
    double normal() { return x * x + y * y; }
    double abs() { return sqrt(normal()); }
    Point operator-(const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
};
int sgn(cosnt double x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
double Distance(const Point &a, const Point &b) { return (a - b).abs(); }

// 计算一辆车 t s后的状态
void afterT(&Car c) {
    double ang = c.t * 2 * pi / 360;
    c.y = t * c.v * cos(ang) + 0.5 * c.a * cos(ang) * t * t;
    c.y = t * c.v * sin(ang) + 0.5 * c.a * sin(ang) * t * t;
}

// 获取面积交
double getAreaV(const Point p1[], const int len1, const Point p2[],
                const int len2) {}

// 判断两辆车是否是一辆车
bool judge(int i1, int i2) {
    Car &car1 = c1[i1];
    Car &car2 = c2[i2];
    if (sgn(Distance(Point(car1.x, car1.y), Point(Car2.x, Car2.y)) - b) >= 0)
        return true;
    
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%lf%lf%lf", &n, &m, &t, &a, &b);
        for (int i = 0; i < n; ++i) {
            Car &c = c1[i];
            scanf("%lf%lf%lf%lf%lf%lf%lf", &c.x, &c.y, &c.v, &c.a, &c.t, &c.l,
                  &c.w);
            afterT(c1[i]);
        }
        for (int i = 0; i < m; ++i) {
            Car &c = c2[i];
            scanf("%lf%lf%lf%lf%lf", &c.x, &c.y, &c.t, &c.l, &c.w);
        }

        init(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (judge(i, j))
                    addedge(i, j);
        printf("%d\n", hungary());
    }
    return 0;
}