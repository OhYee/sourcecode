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

const int maxn = 15;
int n,m,k;
int dis[maxn][maxn][2];
char Map[maxn][maxn][2];

const int delta[] = {1,-1,0,0};

struct point {
    int x,y,z;
    point() {
        x = y = z = -1;
    }
    point(int a,int b,int c) {
        x = a;
        y = b;
        z = c;
    }
    bool operator == (const point &rhs)const {
        return (x == rhs.x && y == rhs.y && z == rhs.z);
    }
};

bool BFS(point s,point v,int t) {
    memset(dis,-1,sizeof(dis));
    queue<point> Q;

    Q.push(s);
    dis[s.x][s.y][s.z] = 0;

    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int z = Q.front().z;
        Q.pop();

        if(dis[x][y][z] >= t)
            return false;

        REP(4) {
            int xx = x + delta[o];
            int yy = y + delta[3 - o];
            int zz = z;

            if(xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if(Map[xx][yy][zz] == '#')
                zz = !zz;
            if(Map[xx][yy][zz] == '*' || Map[xx][yy][zz] == '#')
                continue;

            if(dis[xx][yy][zz] == -1) {
                dis[xx][yy][zz] = dis[x][y][z] + 1;
                if(point(xx,yy,zz) == v)
                    return true;
                Q.push(point(xx,yy,zz));
            }
        }
    }
    return false;
}

void Do() {
    scanf("%d%d%d",&n,&m,&k);
    point s,v;
    for(int k = 0;k < 2;k++)
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) {
                scanf("\n%c\n",&Map[i][j][k]);
                if(Map[i][j][k] == 'S')
                    s = point(i,j,k);
                if(Map[i][j][k] == 'P')
                    v = point(i,j,k);
            }

    #if debug
    for(int k = 0;k < 2;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++)
                printf("%c",Map[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
    #endif

    printf("%s\n",BFS(s,v,k) ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}