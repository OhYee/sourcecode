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

const int maxn = 105;
int n,m;
char Map[maxn][maxn];
int dis[maxn][maxn];

typedef pair<int,int> point;

const int delta[] = {1,-1,0,0};

bool BFS(int s1,int s2,int v1,int v2,int k) {
	if(k < 0)
		return false;
	if(s1 == v1 && s2 == v2)
		return true;

	memset(dis,-1,sizeof(dis));
	queue<point> Q;

	Q.push(point(s1,s2));
	dis[s1][s2] = 0;
	while(!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if(dis[x][y] == k+1)
			return false;

		REP(4) {
			int xx,yy;
			for(int i = 1;;i++) {
				xx = x + delta[o] * i;
				yy = y + delta[3 - o] * i;

				if(xx < 0 || xx > n || yy < 0 || yy > m || Map[xx][yy] == '*')
					break;
				if(dis[xx][yy] == -1) {
					dis[xx][yy] = dis[x][y] + 1;
					if(xx == v1 && yy == v2)
						return true;
					Q.push(point(xx,yy));
				}


			}
		}
	}
	return false;

}

void Do() {
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("\n%c\n",&Map[i][j]);
	int s1,s2,v1,v2,k;
	scanf("%d%d%d%d%d",&k,&s2,&s1,&v2,&v1);

	printf("%s\n",BFS(s1 - 1,s2 - 1,v1 - 1,v2 - 1,k) ? "yes" : "no");
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}