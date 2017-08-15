//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 60005;
const double INF = 9e9;
const int K = 5;


struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator<(const Point &rhs) const { return x < rhs.x; }
};
Point point[maxn];

inline double pow(double a, double n) {
    if (n == 0)
        return 1.0;
    if (n == 1)
        return a;
    return pow(a, n / 2) * pow(a, n - n / 2);
}

inline double dis(Point a, Point b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

//[l,r)
double dfs(int l, int r) {
    int mid = (l + r) / 2;

    if (r - l < 2) {
        return INF;
    }
    if (r - l == 2) {
        return dis(point[l], point[l + 1]);
    }

    double mm = min(dfs(l, mid), dfs(mid, r));

    for (int i = mid - 1; i >= l && pow(point[mid].x - point[i].x,2) < mm; i--)
        for (int j = mid; j < r && pow(point[r].x - point[mid-1].x,2) < mm; j++)
            mm = min(mm, dis(point[i], point[j]));

    return mm;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &point[i].x, &point[i].y);

    sort(point, point + n);
    printf("%.4f\n", sqrt(dfs(0, n)));

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}
