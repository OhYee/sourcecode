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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 1005;

const int delta[4] = {1,-1,0,0};

char Map[maxn][maxn];
bool vis[maxn][maxn];
bool fvis[maxn][maxn];
int n,m;

struct Node {
    int x,y,dis;
    Node(int x,int y,int dis) {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

queue<Node> Q;
queue<Node> Qf;

void fire(int d) {
    while(!Qf.empty()) {
        int x = Qf.front().x;
        int y = Qf.front().y;
        int dis = Qf.front().dis;

        if(dis > d) {
            break;
        } else {
            Qf.pop();
        }

        for(int i = 0;i <= 3;i++) {
            int xx = x + delta[i];
            int yy = y + delta[3 - i];

            if(xx<1 || xx>n || yy<1 || yy>m)
                continue;
            if(Map[xx][yy] == '#')
                continue;
            if(fvis[xx][yy])
                continue;

            fvis[xx][yy] = true;
            Map[xx][yy] = 'F';
            
            Qf.push(Node(xx,yy,dis + 1));
        }
    }
}

void Do() {
    int jx,jy;

    cin >> n >> m;

    memset(vis,false,sizeof(vis));
    memset(fvis,false,sizeof(fvis));
    while(!Q.empty())
        Q.pop();
    while(!Qf.empty())
        Qf.pop();

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> Map[i][j];

            if(Map[i][j] == 'J')
                jx = i,jy = j;
            if(Map[i][j] == 'F') {
                Qf.push(Node(i,j,0));
                fvis[i][j] = true;
            }
        }
    }
    Map[jx][jy] = '.';


    int ans = -1;

    Q.push(Node(jx,jy,0));
    vis[jx][jy] = true;

    int lastdis = -1;

    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int dis = Q.front().dis;
        Q.pop();

        if(dis != lastdis) {
            fire(dis);
            lastdis = dis;
        }

        for(int i = 0;i <= 3;i++) {
            int xx = x + delta[i];
            int yy = y + delta[3 - i];
            int dist = dis + 1;

            if(xx<1 || xx>n || yy<1 || yy>m) {
                ans = dist;
                break;
            }

            if(Map[xx][yy] == '.' && vis[xx][yy] == false) {
                vis[xx][yy] = true;
                Q.push(Node(xx,yy,dist));
            }

        }
        if(ans != -1)
            break;
    }

    if(ans == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)
        Do();

    return 0;
}