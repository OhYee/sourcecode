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

const int maxn = 25;
const int maxm = 1005;

int Map[maxn][maxm];
int dp[maxn][maxm];

void  Do() {
	int n,m;
	scanf("%d%d",&n,&m);

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			scanf("%d",&Map[i][j]);

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(i == 1)
				if(j == 1)
					dp[i][j] = Map[i][j];
				else
					dp[i][j] = dp[1][1] + Map[i][j];
			else
				dp[i][j] = dp[i - 1][j] + Map[i][j];
			for(int k = 1;k < j;k++)
				if(j % k == 0 || k == j - 1)
					dp[i][j] = max(dp[i][j],dp[i][k] + Map[i][j]);
		}

	printf("%d\n",dp[n][m]);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}