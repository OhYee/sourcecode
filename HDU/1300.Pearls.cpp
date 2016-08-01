/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
	题意理解：
		珍珠有不同的价格，需要买一定数量指定价格的珍珠
		对于买的一种价格的珍珠，需要额外付出10个该类珍珠价格的手续费
		可以用更好的珠宝代替较差的珍珠

		求出所花费的最小价格
*/
typedef int LL;

const int maxn = 105;

struct Pearl {
	int num;
	int price;
	bool operator < (const Pearl &rhs)const {
		return price < rhs.price;
	}
};

Pearl p[maxn];

//买完前i种珍珠所需要的最小值
LL dp[maxn];

int m[maxn];

void Do() {
	int n;
	scanf("%d",&n);
	m[0] = 0;
	REP(n)
		scanf("%d%d",&p[o + 1].num,&p[o + 1].price);
	memset(dp,0,sizeof(dp));
	//sort(p + 1,p + 1 + n);
	REP(n)
		m[o + 1] = m[o] + p[o+1].num;

	for(int i = 1;i <= n;i++) {
		dp[i] = dp[i - 1] + (p[i].num + 10) * p[i].price;
		for(int j = 0;j < i;j++)
			dp[i] = min(dp[i],dp[j] + (LL)(m[i] - m[j] + 10) * p[i].price);
	}
	printf("%d\n",dp[n]);

	return;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}