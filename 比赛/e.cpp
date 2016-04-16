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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int mod = 1000000007;
const int maxn = 2005;
typedef unsigned long long LL;
LL dp[maxn][5];

//n层数 m连续数目
LL DP(int n, int m) {
	if (n == 0) {
		if (m == 1)
			return 0;
		else
			return 1;
	}

	if (m == 4)
		return 0;

	if (dp[n][m] == 0) {
		//(a+b) mod c = ((a mod c) + (b mod c)) mod c
		//(a*b) mod c = ((a mod c) * (b mod c)) mod c
		return (dp[n][m] = (DP(n - 1, m + 1) % mod) + ((25 * (DP(n - 1, 1) % mod)) % mod)) % mod;
	}
	else {
		return dp[n][m];
	}

}

void Do() {
	int n;
	scanf("%d", &n);
	LL ans = (DP(n, 1) % mod) * 26;
	printf("%llu\n", ans % mod);
	return;
}


int main() {
	memset(dp, 0, sizeof(dp));
	int T;
	scanf("%d", &T);
	while (T--) {
		Do();
	}
	return 0;
}