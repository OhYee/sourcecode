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

const int maxn = 105;
const int maxk = 15;
int n,m,k;
int dis[maxn][maxn][maxk];
char Map[maxn][maxn];

const int delta[] = {1,-1,0,0};

struct point {
    int x,y;
    int dis;
    point(int a,int b,int c) {
        x = a;
        y = b;
        dis = c;
    }
};

int BFS(int s1,int s2,int v1,int v2) {
    memset(dis,-1,sizeof(dis));
    queue<point> Q;

    Q.push(point(s1,s2,0));
    dis[s1][s2][0] = 0;
    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int dist = Q.front().dis;
        Q.pop();

        REP(4) {
            int xx = x + delta[o];
            int yy = y + delta[3 - o];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if(Map[xx][yy] != '#' || (Map[xx][yy] == '#' && (dist+1) % k == 0)) {
                int dd = dist + 1;
                if(dis[xx][yy][dd%k] == -1) {
                    dis[xx][yy][dd%k] = dd;
                    if(xx == v1 && yy == v2)
                        return dd;
                    Q.push(point(xx,yy,dd));

                }
            }
        }
    }
    return -1;
}

void Do() {
    scanf("%d%d%d",&n,&m,&k);
    int s1,s2,v1,v2;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            scanf("\n%c\n",&Map[i][j]);
            if(Map[i][j] == 'Y') {
                s1 = i;
                s2 = j;
            }
            if(Map[i][j] == 'G') {
                v1 = i;
                v2 = j;
            }
        }
    int ans = BFS(s1,s2,v1,v2);
    if(ans == -1)
        printf("Please give me another chance!\n");
    else
        printf("%d\n",ans);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}