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

const int maxn = 11;
int n;
int dis[maxn][maxn][maxn];
char Map[maxn][maxn][maxn];

const int delta[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

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
		return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
	}
};

inline int read_int() {
	char c;
	int ans = 0;
	while (c = getchar(),!(c >= '0' && c <= '9'));
	while (c >= '0'&&c <= '9') {
		ans *= 10;
		ans += (int)c - '0';
		c = getchar();
	}
	return ans;
}

int BFS(point s,point v) {
	if (s == v)
		return 0;

	memset(dis,-1,sizeof(dis));
	queue<point> Q;

	Q.push(s);
	dis[s.x][s.y][s.z] = 0;

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int z = Q.front().z;
		Q.pop();

		REP(6) {
			int xx = x + delta[o][0];
			int yy = y + delta[o][1];
			int zz = z + delta[o][2];

			//非法路径
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || zz < 0 || zz >= n)
				continue;
			//墙
			if (Map[xx][yy][zz] == 'X')
				continue;

			//尚未访问过
			if (dis[xx][yy][zz] == -1) {
				dis[xx][yy][zz] = dis[x][y][z] + 1;
				//到达终点
				if (point(xx,yy,zz) == v)
					return dis[xx][yy][zz];
				Q.push(point(xx,yy,zz));
			}
		}
	}
	return -1;
}

bool Do() {
	char c;
	if (scanf("\n%c",&c) == EOF)
		return false;
	n = read_int();
	//printf(" (%d) \n",n);

	for (int k = 0;k < n;k++)//块
		for (int i = 0;i < n;i++)//行
				scanf("%s",Map[k][i]);

	int s1,s2,s3,v1,v2,v3;
	s1 = read_int();
	s2 = read_int();
	s3 = read_int();
	v1 = read_int();
	v2 = read_int();
	v3 = read_int();
	//scanf("%d%d%d",&s1,&s2,&s3);
	//scanf("%d%d%d",&v1,&v2,&v3);
	point s = point(s3,s1,s2);
	point v = point(v3,v1,v2);


	

	int ans = BFS(s,v);

	if (ans == -1)
		printf("NO ROUTE\n");
	else
		printf("%d %d\n",n,ans);

	scanf("%*s");

	return true;
}

int main() {
	while (Do());
	return 0;
}
