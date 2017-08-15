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

const int maxn = 250;
int n,m;
char Map[maxn][maxn];

int s1,s2;

int dis[maxn][maxn];

const int delta[] = {1,-1,0,0};

struct point {
    int x,y;
    int dis;

    point(int a,int b,int c) {
        x = a;
        y = b;
        dis = c;
    }

    bool operator < (const point &rhs)const {
        return dis>rhs.dis;
    }
};

int BFS() {
    priority_queue<point> Q;
    memset(dis,-1,sizeof(dis));

    Q.push(point(s1,s2,0));
    dis[s1][s2] = 0;
    while(!Q.empty()) {
        int x = Q.top().x;
        int y = Q.top().y;
        int dist = Q.top().dis;

        Q.pop();

        REP(4) {
            int xx = x + delta[o];
            int yy = y + delta[3 - o];
            int dd = dist + 1;

            if(xx >= 0 && xx < n && yy>=0 && yy < m) {
                if(Map[xx][yy] != '#' && dis[xx][yy] == -1) {
                    if(Map[xx][yy] == 'x')
                        dd++;
                    if(Map[xx][yy] == 'r')
                        return dd;
                    dis[xx][yy] = dd;
                    Q.push(point(xx,yy,dd));
                }
            }
        }
    }
    return -1;
}

bool Do() {
    if(scanf("%d%d",&n,&m) == EOF)
        return false;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            scanf("\n%c\n",&Map[i][j]);
            if(Map[i][j] == 'a') {
                s1 = i;
                s2 = j;
            }
        }

    int ans = BFS();
    if(ans == -1)
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    else
        printf("%d\n",ans);

    return true;
}

int main() {
    while(Do());
    return 0;
}