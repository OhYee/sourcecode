/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)



const int maxn = 10;
int n, m;
int Map[maxn][maxn];


const int delta[4] = { 1,-1,0,0 };

struct point {
    int x, y;
    int time;
    int dis;
    point(int a, int b, int c, int d) {
        x = a;
        y = b;
        time = c;
        dis = d;
    }
};

int BFS(int s1, int s2, int v1, int v2) {
    queue<point> Q;
    int mark[maxn][maxn];
    memset(mark, -1, sizeof(mark));
    int ans = -1;

    Q.push(point(s1, s2, 6, 0));
    mark[s1][s2] = 6;
    while (!Q.empty()) {
        point temp = Q.front();
        Q.pop();

        int x = temp.x;
        int y = temp.y;
        int time = temp.time;
        int dis = temp.dis;

        if (x == v1 && y == v2) {
            ans = ((ans == -1) ? (dis) : min(ans, dis));
            //printf("    (%d,%d)%d %d\n", x,y,time,dis);
        }

        //**
        REP(4) {
            int xx = x + delta[o];
            int yy = y + delta[3-o];
            int tt = time - 1;
            int dd = dis + 1;

            if (xx < 0 || xx >= n || yy < 0 || yy >= m
                || Map[xx][yy] == 0 || tt == 0)
                continue;
            if (Map[xx][yy] == 4)
                tt = 6;
            if (mark[xx][yy] < tt) {
                mark[xx][yy] = tt;
                //printf("%d %d %d %d\n", xx, yy, tt, dd);
                Q.push(point(xx, yy, tt, dd));
            }
        }
    }
    return ans;
}

void Do() {
    char s1, v1;
    int s2, v2;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &Map[i][j]);
            if (Map[i][j] == 2) {
                s1 = i;
                s2 = j;
                Map[i][j] = 1;
            }
            if (Map[i][j] == 3) {
                v1 = i;
                v2 = j;
                Map[i][j] = 1;
            }
        }
    printf("%d\n", BFS(s1, s2, v1, v2));
}


int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        Do();
    return 0;
}