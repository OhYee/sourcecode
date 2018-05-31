#include <cstdio>
#include <map>
using namespace std;

const int maxn = 1005;
struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

Point p[maxn];
typedef map<int, int> dict;
dict mapList[4];

int fac(int n) {
    // calc n!
    return (1+n)*n/2;
}

bool judge(const Point &a, const Point &b) {
    if (a.x == b.x || a.y == b.y)
        return true;
    if (a.x - a.y == b.x - b.y || a.x + a.y == b.x + b.y)
        return true;
    return false;
}

void record(dict &m, int value) {
    if (m.count(value) == 0)
        m[value] = 0;
    m[value] = m[value] + 1;
}
int calc(dict &m) {
    int cnt = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        cnt += fac(it->second - 1);
        // printf("%d %d %d\n", it->first, it->second, fac(it->second - 1));
    }
    return cnt;
}

int main() {
    for (auto m : mapList)
        m.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        record(mapList[0], x);
        record(mapList[1], y);
        record(mapList[2], x + y);
        record(mapList[3], x - y);
    }

    int cnt = 0;
    for (auto m : mapList)
        cnt += calc(m);

    // for (int i = 0; i < n; ++i)
    //     for (int j = i + 1; j < n; ++j)
    //         if (judge(p[i], p[j]))
    //             cnt++;

    printf("%d\n", cnt);
    return 0;
}