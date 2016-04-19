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

const int maxn = 30;
int n,m;
char Map[maxn][maxn];

#if debug
pair<int,int> last[maxn][maxn];
#endif

const int delta[4] = {1,-1,0,0};

struct point {
	int x,y;
	int dis;//楼梯是否已变化
	point(int a,int b,int c) {
		x = a;
		y = b;
		dis = c;
	}
	bool operator < (const point &rhs) const {
		return dis>rhs.dis;
	}
};

int BFS(int s1,int s2,int v1,int v2) {
	priority_queue<point> Q;
	int dis[maxn][maxn];
	memset(dis,-1,sizeof(dis));

	Q.push(point(s1,s2,false));
	dis[s1][s2] = 0;

	while (!Q.empty()) {
		point temp = Q.top();
		Q.pop();

		int x = temp.x;
		int y = temp.y;
		int dist = temp.dis;

		REP(4) {
			int xx = x + delta[o];
			int yy = y + delta[3 - o];
			int dd = dist + 1;

			if (xx < 0 || xx >= m || yy < 0 || yy >= n || Map[xx][yy] == '*')
				continue;
			if (Map[xx][yy] == '-' || Map[xx][yy] == '|') {//是梯子
				if (x == xx) {//水平方向移动
					//需要等待一步
					if ((Map[xx][yy] == '-' && dist % 2 == 1) || (Map[xx][yy] == '|' && dist % 2 != 1))
						dd++;
					yy += yy - y;
				} else {//竖直方向移动
					//需要等待一步
					if ((Map[xx][yy] == '|' && dist % 2 == 1) || (Map[xx][yy] == '-' && dist % 2 != 1))
						dd++;
					xx += xx - x;
				}
			}
			if (xx < 0 || xx >= m || yy < 0 || yy >= n || Map[xx][yy] != '.')
				continue;

			if (dis[xx][yy] == -1) {
				dis[xx][yy] = dd;
#if debug
				last[xx][yy] = pair<int,int>(x,y);
#endif
				if (xx == v1 && yy == v2)
					break;
				Q.push(point(xx,yy,dd));

			}
		}
	}

#if debug
	pair<int,int> w;
	w = pair<int,int>(v1,v2);
	while (!(w.first == s1 && w.second == s2)) {
		printf("%d %d\n",w.first,w.second);
		w = last[w.first][w.second];
	}
#endif

	return dis[v1][v2];
}

bool Do() {
	int s1,v1;
	int s2,v2;
	if (scanf("%d%d\n",&m,&n) == EOF)
		return false;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("\n%c\n",&Map[i][j]);
			if (Map[i][j] == 'S') {
				s1 = i;
				s2 = j;
				Map[i][j] = '.';
			}
			if (Map[i][j] == 'T') {
				v1 = i;
				v2 = j;
				Map[i][j] = '.';
			}
		}

#if debug
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%c",Map[i][j]);
		printf("\n");
	}
#endif

	printf("%d\n",BFS(s1,s2,v1,v2));
	return true;
}


int main() {
	while (Do());
	return 0;
}