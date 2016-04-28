/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

/*
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

const int maxn = 15;
const int maxv = 100001;
int cash;
int N;
int n[maxn],D[maxn];

int dp[maxv];

/*
int DP(int i,int j) {
	if(i == 0)
		return 0;
	if(dp[i][j] == -1)
		for(int k = 0;k <= n[i];k++)
			if(j - k * D[i] >= 0 && j - k * D[i] <= cash)
				dp[i][j] = max(DP(i - 1,j - k * D[i]) + k * D[i],dp[i][j]);
	return dp[i][j];
}
*/
/*
bool Do() {
	if(scanf("%d%d",&cash,&N) == EOF)
		return false;
	REP(N)
		scanf("%d%d",&n[o + 1],&D[o + 1]);

	//DP
	/*
		状态分析

		背包问题
		cash - 背包容量
		D[i] - 物品的重量
		n[i] - 物品的数量上限(下限为0)

		答案为 dp[N][cash] (使用前N个砝码，背包容量为cash时的总重量)

		按照第一组样例有
		dp[3][735] = dp[2][735] + dp[2][385] + dp[2][35] + dp[2][-325]
			dp[2][735] = dp[1][735] + dp[1][730] + dp[1][725] + dp[1][720] + dp[1][715] + dp[1][710] + dp[1][705]
				dp[1][735] = dp[0][735] + dp[0][610] + dp[0][485] + dp[0][360] + dp[0][235]
				……
			dp[2][385] = dp[1][385] + dp[1][380] + dp[1][375] + dp[1][370] + dp[1][365] + dp[1][360] + dp[1][355]
				……
			dp[2][35] = dp[1][35] + dp[1][30] + dp[1][25] + dp[1][20] + dp[1][15] + dp[1][10] + dp[1][5]
				……

		也即 dp[i][j] = max(dp[i-1][j-k*D[i]] + k*D[i] , dp[i][j]) (0 <= k <= D[i])
	*/
	/*
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= cash;j++)
			for(int k = 0;k <= n[i];k++)
				if(j - k * D[i] >= 0 && j - k * D[i] <= cash)
					dp[i][j] = max(dp[i - 1][j - k * D[i]] + k * D[i],dp[i][j]);
	*/

	/*
		优化空间成一维数组
	*/
	/*
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= N;i++)
		for(int j = cash;j >= 0;j--)
			for(int k = 0;k <= n[i];k++)
				if(j - k * D[i] >= 0 && j - k * D[i] <= cash)
					dp[j] = max(dp[j - k * D[i]] + k * D[i],dp[j]);
	printf("%d\n",dp[cash]);
	*/

	/*
		记忆化搜索
	*/

	/*
	memset(dp,-1,sizeof(dp));
	printf("%d\n",DP(N,cash));
	*/

	/*
		优化掉max函数
	*/
	/*
	memset(dp,false,sizeof(bool)*(cash+1));
	dp[0] = true;

	for(int i = 1;i <= N;i++)
		for(int j = cash;j >= 0;j--)
			for(int k = 0;k <= n[i];k++)
				if(dp[j] == false) {
					if(j - k * D[i] >= 0)
						dp[j] = dp[j - k * D[i]];
				} else {
					break;
				}

	int ans;
	for(ans = cash;dp[ans] == false && ans > 0;ans--);
	printf("%d\n",ans);
	*/
	/*
	return true;
}

int vs_main() {
	while(Do());
	return 0;
}
*/


///*
#include <stdlib.h>

#define MAX_N 11
#define MAX_CNT 100005
#define Max(a,b) (a) > (b) ? (a) : (b)

int dp[MAX_CNT] = {0};
int v;

void ZeroOnePack(int cost,int weight) {
	for(int i = v; i >= cost; i--)
		dp[i] = Max(dp[i],dp[i - cost] + weight);
}

void CompletePack(int cost,int weight) {
	for(int i = cost; i <= v; i++)
		dp[i] = Max(dp[i],dp[i - cost] + weight);
}

void MultiplePack(int cost,int weight,int n) {
	if(cost * n > v) {
		CompletePack(cost,weight);
	} else {
		int k = 1;
		while(k < n) {
			ZeroOnePack(cost * k,weight * k);
			n -= k;
			k *= 2;
		}
		ZeroOnePack(cost * n,weight * n);
	}
}

int vs_main() {
	int n;
	while(scanf("%d %d",&v,&n) != EOF) {
		//    Get input        
		int cnt[MAX_N] = {0},val[MAX_N] = {0};
		for(int i = 0; i < n; i++)    scanf("%d %d",cnt + i,val + i);

		if(v == 0 || n == 0) {
			printf("0\n"); continue;
		}

		//    Init
		for(int i = 0; i < MAX_CNT; i++) dp[i] = 0;

		//    背包九讲
		for(int i = 0; i < n; i++)
			MultiplePack(val[i],val[i],cnt[i]);

		printf("%d\n",dp[v]);
	}

	return 0;
}

//*/