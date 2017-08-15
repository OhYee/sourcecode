/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com
 
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
#include <set>
#include <functional>
using namespace std;
 
const int maxn = 105;
const int delta[] = {-1,1,0,0};
 
int Map[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
 
bool Do() {
    int m,n;
 
    if(scanf("%d%d",&n,&m)==EOF)
        return false;
 
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&Map[i][j]);
 
    memset(vis,false,sizeof(vis));
 
    queue<pair<int,int> > Q;
    vis[1][1] = true;
    Q.push(pair<int,int>(1,1));
    dis[1][1] = 0;
    dis[n][m] = -1;
 
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(x == n && y == m)
            break;
 
        for(int i = 0;i < 4;i++) {
            int xx = x + delta[i];
            int yy = y + delta[3 - i];
            if(!(xx >= 1 && x <= n&&yy >= 1 && yy <= m))
                continue;
            if(vis[xx][yy])
                continue;
            if(Map[xx][yy])
                continue;
            vis[xx][yy] = true;
            dis[xx][yy] = dis[x][y] + 1;
            Q.push(pair<int,int>(xx,yy));
        }
    }
 
    printf("%d\n",dis[n][m]);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}