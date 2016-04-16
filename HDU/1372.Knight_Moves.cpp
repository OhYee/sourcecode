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
int k[maxn];

const int delta[8] = {-1,-1,1,1,-2,2,2,-2};

int BFS(int s1,int s2,int v1,int v2) {
	if(s1 == v1 && s2 == v2)
		return 0;

	queue<pair<int,int> > Q;
	bool visited[maxn][maxn];
	memset(visited,false,sizeof(visited));
	int dis[maxn][maxn];
	memset(dis,0,sizeof(dis));

	Q.push(pair<int,int>(s1,s2));
	visited[s1][s2] = true;

	while(!Q.empty()) {
		int th1 = Q.front().first;
		int th2 = Q.front().second;
		Q.pop();

		//达到终点
		if(th1 == v1 && th2 == v2)
			break;

		//拓展节点
		int next1,next2;
		for(int i = 0;i < 8;i++) {
			next1 = th1 + delta[i];
			next2 = th2 + delta[7 - i];
			if(next1 > 8 || next1 < 1 || next2 > 8 || next2 < 1)
				continue;
			if(!visited[next1][next2]) {
				Q.push(pair<int,int>(next1,next2));
				visited[next1][next2] = true;
				dis[next1][next2] = dis[th1][th2] + 1;
			}
		}
	}

	if(dis[v1][v2])
		return dis[v1][v2];
	else
		return -1;
}

bool Do() {
	char s1,v1;
	int s2,v2;
	if(scanf("%c%d %c%d\n",&s1,&s2,&v1,&v2) == EOF)
		return false;
	printf("To get from %c%d to %c%d takes %d knight moves.\n",
		s1,s2,v1,v2,BFS(s1 - 'a' + 1,s2,v1 - 'a' + 1,v2));
	return true;
}

int main() {
	while(Do());
	return 0;
}