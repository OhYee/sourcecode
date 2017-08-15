//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int delta[] = {1, -1, 0, 0};
const int maxn = 105;
char Map[maxn][maxn];
bool vis[maxn][maxn][maxn];

int m, n, D;

struct Point {
    int x, y, d, t;
    Point(int _x = 0, int _y = 0, int _d = 0, int _t = 0)
        : x(_x), y(_y), d(_d), t(_t) {}
    bool operator<(const Point &rhs) const {
        if (t == rhs.t)
            return d > rhs.d;
        return t > rhs.t;
    }
};

//判断位置合法性
bool judge(int x, int y) { return (x >= 1 && x <= m && y >= 1 && y <= n); }

queue<Point> Q;
int bfs() {
    while (!Q.empty())
        Q.pop();
    int ans = -1;
    memset(vis, false, sizeof(vis));

    Q.push(Point(1, 1, D, 0));
    vis[1][1][D] = true;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int d = Q.front().d;
        int t = Q.front().t;
        Q.pop();

        //printf("x=%d y=%d d=%d t=%d \n", x, y, d, t);
        if (x == m && y == n) {
            ans = t;
            break;
        }

        //步行移动
        for (int i = 0; i < 4; i++) {
            int xx = x + delta[i];
            int yy = y + delta[3 - i];

            if (!judge(xx, yy))
                continue;
            if (Map[xx][yy] != 'P')
                continue;

            if (vis[xx][yy][d])
                continue;
            vis[xx][yy][d] = true;
            Q.push(Point(xx, yy, d, t + 1));
        }

        //飞行移动
        for (int i = 0; i < 4; i++) {
            for (int k = 1; k <= d; k++) {
                int xx = x + delta[i] * k;
                int yy = y + delta[3 - i] * k;

                if (!judge(xx, yy))
                    break;
                if (Map[xx][yy] != 'P')
                    continue;

                if (vis[xx][yy][d - k])
                    continue;
                vis[xx][yy][d - k] = true;

                Q.push(Point(xx, yy, d - k, t + 1));
            }
        }
    }
    return ans;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    scanf("%d%d%d", &m, &n, &D);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("\n%c", &Map[i][j]);
            // printf("%c", Map[i][j]);
        }
        // printf("\n");
    }
    int ans = bfs();
    if (ans == -1)
        printf("impossible\n");
    else
        printf("%d\n", ans);

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}