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
			//printf("	(%d,%d)%d %d\n", x,y,time,dis);
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

/*

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

typedef pair<int, int> point;

const int maxn = 10;
int n, m;
int Map[maxn][maxn];


const int delta[4] = { 1,-1,0,0 };

int BFS(int s1, int s2, int v1, int v2) {
	queue<pair<int, point> > Q;
	bool visited[maxn][maxn][maxn];
	memset(visited, false, sizeof(visited));
	int dis[maxn][maxn][maxn];
	memset(dis, -1, sizeof(dis));

	Q.push(pair<int, point>(6, point(s1, s2)));
	visited[6][s1][s2] = true;
	dis[6][s1][s2] = 0;
	while (!Q.empty()) {
		int time = Q.front().first;
		int th1 = Q.front().second.first;
		int th2 = Q.front().second.second;
		Q.pop();

		//达到终点
		if (th1 == v1 && th2 == v2)
			break;

		//拓展节点
		int next1, next2, nt;
		for (int i = 0; i < 4; i++) {
			nt = time-1;
			next1 = th1 + delta[i];
			next2 = th2 + delta[3 - i];
			
			if (next1 >= n || next1 < 0 || next2 >= m || next2 < 0
				|| Map[next1][next2] == 0 || nt == 0)
				continue;

			if (!visited[nt][next1][next2]) {
				if (Map[next1][next2] == 4)
					nt = 6;

				Q.push(pair<int, point>(nt, point(next1, next2)));
				visited[nt][next1][next2] = true;
				dis[nt][next1][next2] =
					dis[nt][next1][next2] == -1 ?
					dis[time][th1][th2] + 1 :
					min(dis[time][th1][th2] + 1, dis[nt][next1][next2]);
			}
		}
	}
	
	int ans = dis[0][v1][v2];
	for (int i = 0; i < 6; i++)
		if (dis[i][v1][v2] != -1)
			ans =ans==-1?dis[i][v1][v2]: min(ans, dis[i][v1][v2]);

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


int vs_main() {
	int T;
	scanf("%d", &T);
	while (T--)
		Do();
	return 0;
}
*/