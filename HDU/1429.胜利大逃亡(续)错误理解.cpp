/*
    HDU 1429.胜利大逃亡(续) 的错误理解
	
	理解为：t时间后强行传送到起点(不结束，还能继续走)
*/

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
int dis[maxn][maxn];
int n,m,t;
typedef pair<int,int> point;
const int delta[] = {1,-1,0,0};

int BFS(int s1,int s2,int v1,int v2) {
	queue<point> Q,door;
	memset(dis,-1,sizeof(dis));

	bool key[10];
	memset(key,false,sizeof(key));

	Q.push(point(s1,s2));
	dis[s1][s2] = 0;

	while(!Q.empty() || !door.empty()) {
		if(!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			REP(4) {
				int xx = x + delta[o];
				int yy = y + delta[3 - o];

				//非法访问
				if(xx < 0 || xx >= n || yy < 0 || yy >= m)
					continue;
				//墙
				if(Map[xx][yy] == '*')
					continue;
				//钥匙
				if(Map[xx][yy] >= 'a' && Map[xx][yy] <= 'j')
					key[Map[xx][yy] - 'a'] = true;
				//门
				if(Map[xx][yy] >= 'A' && Map[xx][yy] <= 'J')
					if(!key[Map[xx][yy] - 'A'])
						door.push(point(xx,yy));

				//更新节点
				int temp = dis[xx][yy];
				dis[xx][yy] = (dis[xx][yy] == -1 ? dis[x][y] + 1 : min(dis[x][y] + 1,dis[xx][yy]));
				//剪枝：如果已超过时间，就不再考虑
				if(dis[xx][yy] >= t)
					continue;
				if(temp != dis[xx][yy])
					Q.push(point(xx,yy));
			}
		} else {
			int size = door.size();
			bool flag = false;
			while(size--) {
				int x = door.front().first;
				int y = door.front().second;
				door.pop();
				if(key[Map[x][y] - 'A']) {
					Q.push(point(x,y));
					flag = true;
					break;
				}
				door.push(point(x,y));
			}
			if(flag)
				continue;
			else
				break;
		}
	}
	return dis[v1][v2];
}

bool Do() {
	if(scanf("%d%d%d",&n,&m,&t) == EOF)
		return false;

	int s1,s2,v1,v2;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++) {
			scanf("\n%c\n",&Map[i][j]);
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