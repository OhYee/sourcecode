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

const int maxn = 55;
int a,b,c;
int t;
int dis[maxn][maxn][maxn];
int Map[maxn][maxn][maxn];

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
};

//优化输入
int read_int() {
	char c;
	int ans = 0;
	while(c = getchar(),!(c >= '0' && c <= '9'));
	while(c >= '0' && c <= '9') {
		ans *= 10;
		ans += (int)c - '0';
		c = getchar();
	}
	return ans;
}


int BFS(point s,point v) {
	memset(dis,-1,sizeof(dis));
	queue<point> Q;

	Q.push(s);
	dis[s.x][s.y][s.z] = 0;

	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int z = Q.front().z;
		Q.pop();

		//时间已到
		if(dis[x][y][z] >= t)
			return -1;

		REP(6) {
			int xx = x + delta[o][0];
			int yy = y + delta[o][1];
			int zz = z + delta[o][2];

			//非法路径
			if(xx < 0 || xx >= a || yy < 0 || yy >= b || zz < 0 || zz >= c)
				continue;
			//墙
			if(Map[xx][yy][zz] == 1)
				continue;

			//尚未访问过
			if(dis[xx][yy][zz] == -1) {
				dis[xx][yy][zz] = dis[x][y][z] + 1;
				//到达终点
				if(xx == v.x && yy == v.y && zz == v.z)
					return dis[xx][yy][zz];
				Q.push(point(xx,yy,zz));
			}
		}
	}
	return -1;
}

void Do() {
	//scanf("%d%d%d%d",&a,&b,&c,&t);
	a = read_int();
	b = read_int();
	c = read_int();
	t = read_int();


	for(int k = 0;k < a;k++)//块
		for(int i = 0;i < b;i++)//行
			for(int j = 0;j < c;j++)//列
				//scanf("\n%c\n",&Map[k][i][j]);
				Map[k][i][j] = read_int();

	#if debug
	for(int k = 0;k < a;k++) {
		for(int i = 0;i < b;i++) {
			for(int j = 0;j < c;j++)
				printf("%d",Map[k][i][j]);
			printf("\n");
		}
		printf("\n");
	}
	#endif

	if(a*b*c == 1)
		printf("0\n");
	else
		printf("%d\n",BFS(point(0,0,0),point(a - 1,b - 1,c - 1)));
}

int main() {
	int T;
	T = read_int();
	//scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}