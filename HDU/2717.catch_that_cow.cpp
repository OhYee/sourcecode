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

const int maxn = 100005;

int BFS(int s,int v) {
	if(s == v)
		return 0;
	if(s > v)
		return s - v;

	queue<int> Q;
	bool visited[maxn];
	memset(visited,false,sizeof(visited));
	int dis[maxn];
	memset(dis,0,sizeof(dis));

	Q.push(s);
	visited[s] = true;
	while(!Q.empty()) {
		int th = Q.front();
		Q.pop();

		//达到终点
		if(th == v)
			break;

		//拓展节点

		#define push \
		if(next > maxn || next <= 0) \
			continue;\
		if(!visited[next]) {\
			Q.push(next);\
			visited[next] = true;\
			dis[next] = dis[th] + 1;\
		}\


		int next;
		next = th + 1;
		push;
		next = th - 1;
		push;
		next = th * 2;
		push;
	}

	if(dis[v])
		return dis[v];
	else
		return -1;
}

bool Do() {
	int s,v;
	if(scanf("%d%d",&s,&v)==EOF)
		return false;
	printf("%d\n",BFS(s,v));
	return true;
}

int main() {
	while(Do());
	return 0;
}