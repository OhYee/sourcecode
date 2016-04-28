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

int C,G;//C钩子数 G砝码数
const int maxn = 25;
int hook[maxn];//hook钩子位置
int weight[maxn];//weight砝码重量

int dp[maxn][15005];

bool Do() {
	if(scanf("%d%d",&C,&G) == EOF)
		return false;
	REP(C)
		scanf("%d",&hook[o+1]);
	REP(G)
		scanf("%d",&weight[o+1]);

	//DP
	/*
		状态分析

		采用动态规划，可以看出有一维是使用前i个砝码
		最后一层的意义是：将第i个砝码加入到天平系统中，使天平达到平衡
		则每一层的意义是：将第i个砝码加入到天平系统中，使天平达到特定的状态
		对于天平来说，平衡状态可以用力矩表示

		i为使用的砝码个数 j为力矩
		答案应该为dp[G][0],即使用G个砝码(全部用完)，并且力矩为0(保持平衡)
        初始状态为dp[0][0]=1(使用前0个砝码时保持平衡，即不放置砝码平衡)

		按照样例有：
		dp[4][0]=dp[3][16]+dp[3][-24]
			dp[3][16]=dp[2][26]+dp[2][1]
				dp[2][26]=dp[1][34]+dp[1][13]
					dp[1][13]=dp[0][19]+dp[0][4]
					dp[1][34]=dp[0][40]+dp[0][25]
				dp[2][1]=dp[1][9]+dp[1][-11]
					dp[1][9]=dp[0][15]+dp[0][0]
					dp[1][-11]=dp[0][-5]+dp[0][-20]
			dp[3][-24]=dp[2][-14]+dp[2][-39]
				dp[2][-14]=dp[1][-6]+dp[1][-28]
					dp[1][-6]=dp[0][0]+dp[0][-15]
					dp[1][-28]=dp[0][-22]+dp[0][-37]
				dp[2][-39]=dp[1][-31]+dp[1][-51]
					dp[1][-31]=dp[0][-25]+dp[0][-40]
					dp[1][-51]=dp[0][-45]+dp[0][-60]

		dp[i][j]=dp[i-1][j-weight[i]*hook[0]]+dp[i-1][j-weight[i]*hook[1]]+......
		即 使用i个砝码且力矩为j 等于 使用i-1个砝码且力矩为(j减去砝码i可能的力矩)

		也即dp[i][j]+=dp[i-1][j-weight[i]*hook[k]] k=0,1......k-1

		由于下标不能为负数，因此要将力矩变为正数
		钩子在-15~+15之间 砝码最多20个，每个最终25 即力矩最大为 15*20*25=7500

		原力矩范围为 -7500~0~7500
		加上7500后有 0~7500~15000

	*/
	memset(dp,0,sizeof(dp));

	dp[0][0+7500] = 1;
	for(int i = 1;i <= G;i++)
		for(int j = 1;j <= 15000;j++)
			for(int k = 1;k <= C;k++)
				if(j - weight[i] * hook[k] >= 0 && j-weight[i]*hook[k]<=15000)
					dp[i][j] += dp[i - 1][j - weight[i] * hook[k]];

	printf("%d\n",dp[G][7500]);

	return true;
}

int main() {
	while(Do());
	return 0;
}