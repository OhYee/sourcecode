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


const int maxn = 155;

int N,M;
char Map[maxn][maxn];
pair<int,int> last[maxn][maxn];
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

int BFS() {
	priority_queue<point> Q;
	bool visited[maxn][maxn];
	memset(visited,false,sizeof(visited));
	memset(dis,-1,sizeof(dis));

	Q.push(point(0,0,0));
	dis[0][0] = 0;

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

			if (Map[next1][next2] != 'X' && next1 >= 0
				&& next1 < N && next2 >= 0 && next2 < M) {

				int weight;
				if (Map[next1][next2] == '.')
					weight = 1;
				else
					weight = Map[next1][next2] - '0' + 1;

				int temp = dis[next1][next2];

				dis[next1][next2] = dis[next1][next2] == -1 ?
					dis[th1][th2] + weight :
					min(dis[th1][th2] + weight,dis[next1][next2]);

				if (temp != dis[next1][next2]) {//记录路径
					last[next1][next2] = pair<int,int>(th1,th2);
					//printf("%d %d -> %d %d\n", th1, th2, next1, next2);
				}

				Q.push(point(next1,next2,dis[next1][next2]));

			}

		}

	}
	if (dis[N - 1][M - 1])
		return dis[N - 1][M - 1];
	else
		return -1;
}

bool Do() {
	if (scanf("%d%d",&N,&M) == EOF)
		return false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("\n%c\n",&Map[i][j]);
	/*
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++)
	printf("%c", Map[i][j]);
	printf("\n");
	}
	*/

	if (BFS() == -1) {
		printf("God please help our poor hero.\nFINISH\n");
	} else {
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",dis[N - 1][M - 1] );

		stack<pair<int,int> > s;
		int x = N - 1,y = M - 1;
		while (!(x == 0 && y == 0)) {
			//printf("s %d %d\n", x, y);
			s.push(pair<int,int>(x,y));
			pair<int,int> t = last[x][y];
			x = t.first;
			y = t.second;
		}
		//s.pop();
		//s.push(point(0, 0));

		REP(dis[N - 1][M - 1]) {
			printf("%ds:",o + 1);

			x = s.top().first;
			y = s.top().second;
			s.pop();
			printf("(%d,%d)->(%d,%d)\n",last[x][y].first,last[x][y].second,x,y);

			if (Map[x][y] >= '0'&&Map[x][y] <= '9') {
				int wait = Map[x][y] - '0';
				for (o++; wait; wait--,o++)
					printf("%ds:FIGHT AT (%d,%d)\n",o + 1,x,y);
				o--;
			}


		}
		printf("FINISH\n");

	}



	return true;
}

int main() {
	while (Do());
	return 0;
}