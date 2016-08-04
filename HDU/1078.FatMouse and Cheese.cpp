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
using namespace std;

const int maxn = 105;
const int delta[] = {1,-1,0,0};

int Map[maxn][maxn];
int dp[maxn][maxn];

int n,k;


int DFS(int x,int y) {
	if(dp[x][y] == 0) {
		for(int t = 1;t <= k;t++) //移动距离t
			//for(int i = 0;i <= k;i++) //x轴移动距离i
				for(int o = 0;o < 4;o++) { //移动方向
					int xx = x + delta[o] * t;//移动后的坐标
					int yy = y + delta[3 - o] * t;
					if(xx >= 0 && xx < n&&yy >= 0 && yy < n)
						if(Map[x][y] < Map[xx][yy])
							dp[x][y] = max(DFS(xx,yy),dp[x][y]);
				}
		dp[x][y] += Map[x][y];
	}
	return dp[x][y];
}

bool Do() {
	scanf("%d%d",&n,&k);
	if(n == -1 && k == -1)
		return false;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++) {
			scanf("%d",&Map[i][j]);
			dp[i][j] = 0;
		}

	printf("%d\n",DFS(0,0));
		
	return true;
}

int main() {
	while(Do());
	return 0;
}