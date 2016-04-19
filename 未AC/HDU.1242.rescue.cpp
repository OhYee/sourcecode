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


const int maxn = 210;

int N,M;
char Map[maxn][maxn];
int dis[maxn][maxn];

struct point {
	int x,y;
	int dis;
	point(int a,int b,int c) {
		x = a;
		y = b;
		dis = c;
	}
	bool operator < (const point &rhs)const {
		return dis > rhs.dis;
	}
};


const int delta[] = {1,-1,0,0};

int BFS(int s1,int s2) {
	priority_queue<point> Q;
	bool visited[maxn][maxn];
	memset(visited,false,sizeof(visited));
	memset(dis,-1,sizeof(dis));

	Q.push(point(s1,s2,0));
	dis[s1][s2] = 0;

	while(!Q.empty()) {
		int x = Q.top().x;
		int y = Q.top().y;
		int dist = Q.top().dis;

		Q.pop();

		if(visited[x][y] == true)
			continue;
		visited[x][y] = true;

		//拓展节点
		REP(4) {
			int xx = x + delta[o];
			int yy = y + delta[3 - o];

			if(xx >= 0 && xx < N && yy >= 0 && yy < M && Map[xx][yy] != '#' && visited[xx][yy] == false) {
				int dd = dist + 1;

				if(Map[xx][yy] == 'x')
					dd++;

				dis[xx][yy] = ((dis[xx][yy] == -1) ? dd : min(dd,dis[xx][yy]));

				if(Map[xx][yy] == 'r')
					return dis[xx][yy];

				Q.push(point(xx,yy,dis[xx][yy]));

			}

		}

	}

	return -1;

}

bool Do() {
	if(scanf("%d%d",&N,&M) == EOF)
		return false;

	int s1,s2;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) {
			scanf("\n%c\n",&Map[i][j]);
			if(Map[i][j] == 'a') {
				Map[i][j] = '.';
				s1 = i;
				s2 = j;
			}
		}

	#if debug
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++)
			printf("%c",Map[i][j]);
		printf("\n");
	}
	#endif

	int ans = BFS(s1,s2);

	if(ans == -1)
		printf("Poor ANGEL has to stay in the prison all his life.\n");
	else
		printf("%d\n",ans);

	return true;
}

int vs_main() {
	while(Do());
	return 0;
}

