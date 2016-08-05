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

const int INF = 0x7FFFFFFF / 2;
const int maxn = 13;
const int maxp = 10000;

int p[maxn];
int dp[maxn][maxp];

int n;
int h,s,f;

int GetMoney(int ss,int vv) {
	if(ss > vv)
		return (ss - vv) * f + vv * s;
	return (vv - ss) * h + vv * s;
}

bool Do() {
	scanf("%d",&n);
	if(n == 0)
		return false;
	scanf("%d%d%d",&h,&s,&f);

	int mp = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&p[i]);
		mp = max(mp,p[i]);
	}
	p[0] = 0;


	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;

	for(int i = 1;i <= n;i++)
		for(int j = p[i];j <= mp;j++) {
			int Min = INF;
			for(int k = p[i - 1];k <= mp;k++) 
				if(dp[i - 1][k] != -1) 
					Min = min(Min,dp[i-1][k] + GetMoney(k,j));

			dp[i][j] = Min;
		}

	int ans = INF;
	for(int i = 1;i <= mp;i++)
		if(dp[n][i] != -1)
			ans = min(ans,dp[n][i]);

	printf("%d\n",ans);

	return true;
}

int main() {
	while(Do());
	return 0;
}