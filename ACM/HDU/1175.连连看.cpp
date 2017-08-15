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

const int maxn = 1005;

int m,n;
int Map[maxn][maxn];
int dis[maxn][maxn];

typedef pair<int,int> point;

int BFS(int s1,int s2,int v1,int v2) {
    #define con1(nn) (nn<=0||nn>n) 
    #define con2(mm) (mm<=0||mm>m)
    //位置错误
    if(con1(s1) || con1(v1) || con2(s2) || con2(v2))
        return -1;
    //同一位置
    if(s1 == v1 && s2 == v2)
        return -1;
    //棋子不同 或 无棋子
    if(Map[s1][s2] != Map[v1][v2] || Map[s1][s2]==0)
        return -1;

    queue<point> Q;
    memset(dis,-1,sizeof(dis));

    Q.push(point(s1,s2));
    dis[s1][s2] = 0;

    while(!Q.empty()) {
        int th1 = Q.front().first;
        int th2 = Q.front().second;
        Q.pop();

        //达到终点
        if(th1 == v1 && th2 == v2)
            break;

        //拓展节点
        #define condition \
        (next1 > 0 && next1 <= n && next2 > 0 && next2 <= m \
        && (Map[next1][next2] == 0||(next1==v1 && next2==v2)))

        #define push \
        if(dis[next1][next2]==-1 && dis[th1][th2]<=2) {\
            Q.push(point(next1,next2));\
            dis[next1][next2] = dis[th1][th2] + 1;\
        }\

        int next1,next2;
        for(next1 = th1,next2 = th2 + 1;condition;next2++) {
            push;
        }
        for(next1 = th1 + 1,next2 = th2;condition;next1++) {
            push;
        }
        for(next1 = th1,next2 = th2 - 1;condition;next2--) {
            push;
        }
        for(next1 = th1 - 1,next2 = th2;condition;next1--) {
            push;
        }

    }
    return dis[v1][v2];
}

bool Do() {
    if(scanf("%d%d",&n,&m),n == 0 && m == 0)
        return false;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&Map[i][j]);
    int T;
    scanf("%d",&T);
    while(T--) {
        int s1,s2,v1,v2;
        scanf("%d%d%d%d",&s1,&s2,&v1,&v2);
        printf("%s\n",BFS(s1,s2,v1,v2)==-1?"NO":"YES");
    }
    return true;
}

int main() {
    while(Do());
    return 0;
}