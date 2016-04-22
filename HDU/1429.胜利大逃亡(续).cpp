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


const int maxn = 25;
char Map[maxn][maxn];
int dis[maxn][maxn][1024];
int n,m,t;
const int delta[] = {1,-1,0,0};

struct point {
	int x,y;
	int key;
	point(int a,int b,int c) {
		x = a;
		y = b;
		key = c;
	}
};

//返回新的钥匙集合 
//参数：原始的钥匙集合 获得的钥匙的编号
inline int get_key(int key,int num) {
	return key | (1 << num);
}

//返回是否存在门的钥匙
//参数：钥匙集合 门的编号
inline bool has_key(int key,int num) {
	return (key & (1 << num)) > 0;
}


int BFS(int s1,int s2,int v1,int v2) {
	int Min = -1;
	queue<point> Q;
	memset(dis,-1,sizeof(dis));

	Q.push(point(s1,s2,0));
	dis[s1][s2][0] = 0;


	while(!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int key = Q.front().key;
		Q.pop();

		REP(4) {
			int xx = x + delta[o];
			int yy = y + delta[3 - o];
			int kk = key;

			//非法访问
			if(xx < 0 || xx >= n || yy < 0 || yy >= m)
				continue;
			//墙
			if(Map[xx][yy] == '*')
				continue;
			//钥匙
			if(Map[xx][yy] >= 'a' && Map[xx][yy] <= 'j')
				kk = get_key(kk,Map[xx][yy] - 'a');
			//门
			if(Map[xx][yy] >= 'A' && Map[xx][yy] <= 'J')
				if(!has_key(kk,Map[xx][yy] - 'A'))
					continue;

			//更新节点
			if(dis[xx][yy][kk] == -1) {
				dis[xx][yy][kk] = dis[x][y][key] + 1;
				//剪枝：如果已超过时间，就不再考虑
				if(dis[xx][yy][kk] >= t)
					continue;
				if(xx == v1 && yy == v2) {
					Min = ((Min == -1) ? dis[xx][yy][kk] : min(Min,dis[xx][yy][kk]));
					continue;
				}
				Q.push(point(xx,yy,kk));
			}

		}
	}

	return Min;
}

bool Do() {
	if(scanf("%d%d%d",&n,&m,&t) == EOF)
		return false;

	int s1,s2,v1,v2;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++) {
			scanf("\n%c",&Map[i][j]);
			if(Map[i][j] == '@') {
				s1 = i;
				s2 = j;
			}
			if(Map[i][j] == '^') {
				v1 = i;
				v2 = j;
			}
		}

	printf("%d\n",BFS(s1,s2,v1,v2));

	return true;
}

int main() {
	while(Do());
	return 0;
}