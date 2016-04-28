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

/*
状态分析

背包问题
cash - 背包容量
D[i] - 物品的重量
n[i] - 物品的数量上限(下限为0)

答案为 dp[N][cash] (使用前N个物品，背包容量为cash时的总重量)

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

优化时间效率：
对于多重背包问题，可以采取二进制分解来优化
对于数量为0-n的物品i，可以将其分割成多个组合。
使得所有组合加起来能够等于n，并且选取一定量的组合可以组成0-n的任意数

例如13可以分解成1、2、4、6
	0=0
	1=1
	2=2
	3=1+2
	4=4
	5=1+4
	6=2+4
	7=1+2+4
	8=2+6
	9=1+2+6
	10=4+6
	11=1+4+6
	12=2+4+6
	13=1+2+4+6

	一个数可以分成两个数，两个数相加可以得到这个数
	而这两个数还能继续分成两个数
	…………
	如果分成的两个数相等，则可以再下次分割只分其中一个
	这样在保证尽可能少分的情况下分到最深就是需要的计算方法

	这样，对于一个最多有n个的物品，可以分成(近似)log(2)n个，然后对这些进行01背包求解

	如果物品i的总体积大于背包体积，则不必再分割(在范围内没有上限可以看作无限)。
	使用完全背包问题求解

	因此可以将多重背包问题转化为完全背包问题和01背包问题
	由于对于每一层，之前的算法循环了n[i]次，新算法循环<log n[i]次
	相当于O(V*∑n[i])优化到O(V*∑log n[i])


	
*/

const int maxn = 15;
const int maxv = 100001;


int cash,N;
int n[maxn],D[maxn];

int dp[maxv];

int v;

//0-1背包问题
void ZeroOnePack(int cost,int weight) {
	//printf("	ZeroOnePack cost:%d weight:%d\n",cost,weight);
	for (int i = v; i >= cost; i--)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}

//完全背包问题
void CompletePack(int cost,int weight) {
	//printf("	ComplatePack cost:%d weight:%d\n",cost,weight);
	for (int i = cost; i <= v; i++)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}

//多重背包问题
void MultiplePack(int cost,int weight,int n) {
	//printf("MultiplePack cost:%d weight:%d cnt:%d\n",cost,weight,n);
	if (cost * n > v) {
		CompletePack(cost,weight);
	} else {
		int k = 1;
		while (k < n) {
			ZeroOnePack(cost * k,weight * k);
			n -= k;
			k *= 2;
		}
		ZeroOnePack(cost * n,weight * n);
	}
}



bool Do() {
	if (scanf("%d%d",&cash,&N) == EOF)
		return false;
	REP(N)
		scanf("%d%d",&n[o + 1],&D[o + 1]);

	memset(dp,0,sizeof(dp));

	v = cash;

	for (int i = 1; i <= N; i++)
		MultiplePack(D[i],D[i],n[i]);

	printf("%d\n",dp[cash]);

	return true;
}

int main() {
	while (Do());
	return 0;
}