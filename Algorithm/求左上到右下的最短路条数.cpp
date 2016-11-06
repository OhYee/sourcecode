/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

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
#include <set>
#include <functional>
#include <bitset>
using namespace std;

typedef int LL;

const int maxn = 55;
const int delta[] = {-1,1,0,0};

struct Node {
	int x;
	int y;
	int dis;
	Node(int a,int b,int c) {
		x = a;
		y = b;
		dis = c;
	}
	bool operator < (const Node &rhs)const {
		return dis > rhs.dis;
	}
};

priority_queue <Node> Q;
int Map[maxn][maxn];
bool vis[maxn][maxn];
long long cnt[maxn][maxn];
int dist[maxn][maxn];

bool Do() {
	int n;
	if(!(cin >> n))
		return false;

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> Map[i][j];



	while(!Q.empty())Q.pop();
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(dist,-1,sizeof(dist));


	cnt[1][1] = 1;
	dist[1][1] = Map[1][1];
	Q.push(Node(1,1,dist[1][1]));


	while(!Q.empty()) {
		int x = Q.top().x;
		int y = Q.top().y;
		int dis = Q.top().dis;
		Q.pop();

		if(x == n && y == n)
			break;

		if(vis[x][y])
			continue;
		vis[x][y] = true;

		for(int i = 0;i < 4;i++) {
			int xx = x + delta[i];
			int yy = y + delta[3 - i];
			if(xx<1 || yy<1 || xx>n || yy>n)
				continue;

			if(dist[xx][yy] != -1 && dist[xx][yy] < dis + Map[xx][yy])
				continue;

			if(dist[xx][yy] > dis + Map[xx][yy] || dist[xx][yy] == -1) {
				dist[xx][yy] = dis + Map[xx][yy];
				cnt[xx][yy] = cnt[x][y];
			} else {
				cnt[xx][yy] += cnt[x][y];
			}

			Q.push(Node(xx,yy,dis + Map[xx][yy]));
		}
	}

	cout << cnt[n][n] << endl;

	return true;
}

int main() {
	while(Do());
	return 0;
}