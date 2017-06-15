//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 35;
const int delta[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int Map[maxn][maxn];

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
};

queue<Point> Q;
int dis[maxn][maxn];
int bfs(int m, int n, int d1, int d2, Point s, Point v) {
    memset(dis, 0, sizeof(dis));
    while (!Q.empty())
        Q.pop();

    Q.push(s);
    dis[s.x][s.y] = 0;

    while (!Q.empty()) {
        Point t = Q.front();
        Q.pop();
        if (t == v)
            break;

        for (int i = 0; i < 4; i++) {
            int xx = t.x + delta[i][0] * d1;
            int yy = t.y + delta[i][1] * d2;

            if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                continue;
            if (dis[xx][yy] || Map[xx][yy] == 0 || Map[xx][yy] == 2)
                continue;
            // if (!(Map[t.x][yy] == 1 || Map[xx][t.y] == 1 || Map[t.x][yy] == 4 || Map[xx][t.y] == 4))
            //     continue;

            dis[xx][yy] = dis[t.x][t.y] + 1;
            Q.push(Point(xx, yy));
        }
        for (int i = 0; i <= 3; i++) {
            int xx = t.x + delta[i][0] * d2;
            int yy = t.y + delta[i][1] * d1;

            if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                continue;
            if (dis[xx][yy] || Map[xx][yy] == 0 || Map[xx][yy] == 2)
                continue;
            // if (!(Map[t.x][yy] == 1 || Map[xx][t.y] == 1 || Map[t.x][yy] == 4 || Map[xx][t.y] == 4))
            //     continue;

            dis[xx][yy] = dis[t.x][t.y] + 1;
            Q.push(Point(xx, yy));
        }
    }
    return dis[v.x][v.y];
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif

    cin.tie(0);
    cin.sync_with_stdio(false);
    int M, N, M1, M2;
    Point s, v;
    while (scanf("%d%d%d%d", &M, &N, &M1, &M2) != EOF) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                scanf("%d", &Map[i][j]);
                if (Map[i][j] == 3) {
                    s.x = i;
                    s.y = j;
                }
                if (Map[i][j] == 4) {
                    v.x = i;
                    v.y = j;
                }
            }
    }
    printf("%d\n", bfs(M, N, M1, M2, s, v));
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++)
    //         printf("%d ", dis[i][j]);
    //     printf("\n");
    // }
#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}