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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

typedef long long LL;

const int maxn = 105;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int expand_knight[][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
const int expand_rook[] = {1,-1,0,0};

int n,m;
char Map[maxn][maxn];
int dist[4][maxn][maxn];
int kase = 1;

struct Point {
    int x,y;
    Point(int _x = 0,int _y = 0):x(_x),y(_y) {}
};

queue<Point> Q;

int judge(Point p) {
    int &x = p.x;
    int &y = p.y;
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(Map[x][y] == '#')
        return false;
    return true;
}

void bfs(Point s,Point t,int d,bool expand_type) {
    while(!Q.empty())
        Q.pop();

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            dist[d][i][j] = -1;

    dist[d][s.x][s.y] = 0;
    Q.push(s);

    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();
        if(expand_type) {//马
            for(int i = 0;i < 8;i++) {
                int xx = x + expand_knight[i][0];
                int yy = y + expand_knight[i][1];
                if(judge(Point(xx,yy)) && dist[d][xx][yy] == -1) {
                    dist[d][xx][yy] = dist[d][x][y] + 1;
                    if(memcmp(&t,&Point(xx,yy),sizeof(t)) == 0)
                        break;
                    Q.push(Point(xx,yy));
                }
            }
        } else {//车
            for(int i = 0;i < 4;i++) {
                int xx = x;
                int yy = y;
                while(xx += expand_rook[i],
                    yy += expand_rook[3 - i],
                    judge(Point(xx,yy))) {
                    if(dist[d][xx][yy] == -1) {
                        dist[d][xx][yy] = dist[d][x][y] + 1;
                        if(memcmp(&t,&Point(xx,yy),sizeof(t)) == 0)
                            break;
                        Q.push(Point(xx,yy));
                    }
                }
            }
        }
    }
}

void Do() {

    cin >> n >> m;
    Point s,t;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> Map[i][j];
            if(Map[i][j] == 's')
                s = Point(i,j);
            if(Map[i][j] == 't')
                t = Point(i,j);
        }
    }

    for(int i = 0;i < 4;i++) {
        if(i / 2)
            bfs(s,t,i,i % 2);
        else
            bfs(t,s,i,i % 2);
    }

    int ans = INF;
    for(int i = 0;i < 2;i++)
        for(int j = 2;j < 4;j++)
            for(int x = 1;x <= n;x++)
                for(int y = 1;y <= m;y++)
                    if(dist[i][x][y] != -1 && dist[j][x][y] != -1)
                        ans = min(ans,dist[i][x][y] + dist[j][x][y]);
    if(ans == INF)
        ans = -1;
    cout <<"Case #"<<kase++<<": " <<ans << endl;

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(0);

    int T;
    cin >> T;

    while(T--)
        Do();
    return 0;
}