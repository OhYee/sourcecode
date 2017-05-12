/*/
#define debug
#include <ctime>
//*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

inline bool between(int l, int m, int r) { return l <= m && m <= r; }
//int ID = 0;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
};
struct Area {
    int x1, x2, y1, y2;
    //int id;
    Area(int _x1 = 0, int _x2 = 0, int _y1 = 0, int _y2 = 0) {
        init(_x1, _x2, _y1, _y2);
        // printf("A %d %d %d %d id:%d\n", x1, x2, y1, y2, id);
    }
    Area(int t[4]) {
        init(t[0], t[1], t[2], t[3]);
        // printf("B %d %d %d %d id:%d\n", x1, x2, y1, y2, id);
    }
    Area(const Area &rhs) {
        init(rhs.x1, rhs.x2, rhs.y1, rhs.y2);
        // printf("C %d %d %d %d id:%d\n", x1, x2, y1, y2, id);
    }
    //~Area() { printf("del %d %d %d %d id:%d\n", x1, x2, y1, y2, id); }
    Area operator=(const Area rhs) {
        init(rhs.x1, rhs.x2, rhs.y1, rhs.y2);
        // printf("D %d %d %d %d id:%d\n", x1, x2, y1, y2, id);
        return *this;
    }

    void init(int _x1 = 0, int _x2 = 0, int _y1 = 0, int _y2 = 0) {
        x1 = min(_x1, _x2);
        x2 = max(_x1, _x2);
        y1 = min(_y1, _y2);
        y2 = max(_y1, _y2);
        //id = ID++;
    }

    inline bool In(const Point p) const {
        return between(x1, p.x, x2) && between(y1, p.y, y2);
    }
    Area divide(int k) const {
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;
        int t[4] = {x1, x2, y1, y2};
        if (k == 1) {
            t[1] = midx;
            t[3] = midy;
        } else if (k == 2) {
            t[1] = midx;
            t[2] = midy + 1;
        } else if (k == 3) {
            t[0] = midx + 1;
            t[3] = midy;
        } else { // k == 4
            t[0] = midx + 1;
            t[2] = midy + 1;
        }
        Area area(t);
        return area;
    }
    //获取区域方位角坐标
    Point GetPoint(int k) const {
        Point t;
        if (k == 1)
            t = Point(x1, y1);
        else if (k == 2)
            t = Point(x1, y2);
        else if (k == 3)
            t = Point(x2, y1);
        else //  k == 4
            t = Point(x2, y2);

        return t;
    }
};
void show(const Point &p, int k/*, int deep*/) {
    // for (int i = 0; i < deep; i++)
    //     printf("    ");
    // printf("%d %d %d\n", p.x, p.y, k);
    printf("%d %d %d\n", p.x, p.y, k);
}

//通过左上顶点和方向获取拐角
Point GetCorner(const Point &p, int k) {
    Point t;
    if (k == 1)
        t = Point(p.x + 1, p.y + 1);
    else if (k == 2)
        t = Point(p.x + 1, p.y);
    else if (k == 3)
        t = Point(p.x, p.y + 1);
    else //  k == 4
        t = Point(p.x, p.y);
    return t;
}
int pow(int a, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    return pow(a, n / 2) * pow(a, n - n / 2);
}

void dfs(Area area, Point p/*, int deep*/) {
    // getchar();
    // for (int i = 0; i < deep; i++)
    //    printf("    ");
    // printf("Area: x1=%d x2=%d y1=%d y2=%d id=%d Point: (%d,%d)\n", area.x1,
    // area.x2, area.y1, area.y2, area.id, p.x, p.y);

    //递归终点
    if (area.x2 - area.x1 == 1) {
        for (int i = 1; i <= 4; i++) {
            if (area.GetPoint(i) == p)
                show(GetCorner(Point((area.x1 + area.x2) / 2, (area.y1 + area.y2) / 2), i), i/*, deep*/);
        }
        return;
    }

    Area t;
    for (int i = 1; i <= 4; i++) {
        t = area.divide(i);
        // printf("t %d %d %d %d id:%d\n", t.x1, t.x2, t.y1, t.y2, t.id);
        if (t.In(p)) {
            dfs(t, p/*, deep + 1*/);
            show(
                GetCorner(
                    Point((area.x1 + area.x2) / 2, (area.y1 + area.y2) / 2), i), i/*, deep*/);
        } else {
            dfs(t, t.GetPoint(5 - i)/*, deep + 1*/);
        }
    }
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    freopen("out.txt", "w", stdout);
    cin.tie(0);
    cin.sync_with_stdio(false);

    int k, x, y;
    while (scanf("%d%d%d", &k, &x, &y) != EOF) {
        Area area = Area(1, pow(2, k), 1, pow(2, k));
        Point point = Point(x, y);
        dfs(area, point/*, 0*/);
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}