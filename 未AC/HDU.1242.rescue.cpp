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

int BFS(int s1,int s2,int v1,int v2) {
	priority_queue<point> Q;
	bool visited[maxn][maxn];
	memset(visited,false,sizeof(visited));
	memset(dis,-1,sizeof(dis));

	Q.push(point(s1,s2,0));
	dis[s1][s2] = 0;

	while (!Q.empty()) {

		int th1 = Q.top().x;
		int th2 = Q.top().y;
		int thdis = Q.top().dis;

		Q.pop();

		if (visited[th1][th2] == true)
			continue;
		visited[th1][th2] = true;

		//达到终点
		//if (th1 == N - 1 && th2 == M - 1)
		//	return dis[N - 1][M - 1];

		//拓展节点
		REP(4) {
			int next1 = th1 + delta[o];
			int next2 = th2 + delta[3 - o];

			if (Map[next1][next2] != '#' && next1 >= 0 && next1 < N && next2 >= 0 && next2 < M) {
				int dd = thdis + 1;

				if (Map[next1][next2] == 'x')
					dd++;

				dis[next1][next2] = ((dis[next1][next2] == -1) ? dd : min(dd,dis[next1][next2]));

				Q.push(point(next1,next2,dis[next1][next2]));

			}

		}

	}

	return dis[v1][v2];

}

bool Do() {
	if (scanf("%d%d",&N,&M) == EOF)
		return false;
	int s1,s2,v1,v2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("\n%c\n",&Map[i][j]);
			if (Map[i][j] == 'a') {
				Map[i][j] = '.';
				v1 = i;
				v2 = j;
			}
			if (Map[i][j] == 'r') {
				Map[i][j] = '.';
				s1 = i;
				s2 = j;
			}
		}

	int ans = BFS(s1,s2,v1,v2);

	if (ans == -1)
		printf("Poor ANGEL has to stay in the prison all his life.\n");
	else
		printf("%d\n",ans);

	return true;
}

int main() {
	while (Do());
	return 0;
}
