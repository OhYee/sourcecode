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
const int maxk = 105;

double hl[maxn][maxn];
double dp[maxn][maxk];

inline double standard(double a) {
	return (double)((int)(a * 100 + 0.5)) / 100;
}

bool  Do() {
	int n,k;
	scanf("%d%d",&n,&k);
	if(n == 0 && k == 0)
		return false;
	scanf("%lf",&dp[1][0]);

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%lf",&hl[i][j]);


	for(int j = 1;j <= k;j++)
		for(int i = 1;i <= n;i++) {
			dp[i][j] = 0;
			for(int t = 1;t <= n;t++) {
				dp[i][j] = max(standard(dp[t][j - 1] * hl[t][i]),dp[i][j]);
			}

		}

	if(dp[1][k] - dp[1][0] < 0.0)
		printf("0.00\n");
	else
		printf("%.2f\n",dp[1][k] - dp[1][0]);

	return true;
}

int main() {
	while(Do());
	return 0;
}