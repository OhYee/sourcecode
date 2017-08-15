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
#include <map>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 205;
int n,m;
char Map[maxn][maxn];
const int delta[] = {1,-1,0,0};

struct point {
    int x,y;
    point() {
        x = y = -1;
    }
    point(int a,int b) {
        x = a;
        y = b;
    }
};
int num;


int BFS(point s,int (&dis)[maxn][maxn]) {
    memset(dis,-1,sizeof(dis));
    queue<point> Q;

    Q.push(s);
    dis[s.x][s.y] = 0;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        REP(4) {
            int xx = x + delta[o];
            int yy = y + delta[3 - o];

            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (Map[xx][yy] == '#')
                continue;
            if (dis[xx][yy] == -1) {
                dis[xx][yy] = dis[x][y] + 1;
                Q.push(point(xx,yy));
            }
        }
    }
    return -1;
}

bool Do() {
    if (scanf("%d%d",&n,&m) == EOF)
        return false;
    point s1,s2;
    num = 0;
    point v[maxn*maxn];
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            scanf("\n%c",&Map[i][j]);
            if (Map[i][j] == 'Y')
                s1 = point(i,j);
            if (Map[i][j] == 'M')
                s2 = point(i,j);
            if (Map[i][j] == '@') 
                v[num++] = point(i,j);
        }

    int dis1[maxn][maxn];
    int dis2[maxn][maxn];

    BFS(s1,dis1);
    BFS(s2,dis2);

    int Min = 100000;
    for (int i = 0;i < num;i++)
        if(dis1[v[i].x][v[i].y]!=-1&& dis2[v[i].x][v[i].y]!=-1)
        Min = min(Min,dis1[v[i].x][v[i].y]+ dis2[v[i].x][v[i].y]);

    printf("%d\n",Min * 11);

    return true;
}

int main() {
    while (Do());
    return 0;
}