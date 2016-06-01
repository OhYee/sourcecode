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

const int maxn = 1005;
const int maxt = 1000005;

struct Node {
	int a;
	int c;
};

Node UseTime[maxn];
int dp[maxt];

void Do() {
	memset(dp,-1,sizeof(dp));

	int n,t;
	scanf("%d",&n);
	REP(n)
		scanf("%d%*d%d",&UseTime[o + 1].a,&UseTime[o + 1].c);
	scanf("%d",&t);

	dp[0] = 0;
	//背包问题 dp[j]用去j时间的最多perfect
	for(int i = 1;i <= n;i++) {
		bool ThisISwap = false;
		for(int j = t;j >= 0;j--) {
			bool ThisJSwap = false;
			if(j - UseTime[i].c >= 0 && dp[j - UseTime[i].c] != -1) {
				dp[j] = dp[j - UseTime[i].c];
				ThisISwap = true;
				ThisJSwap = true;
			} else {
				if(!ThisJSwap)
					dp[j] = -1;
			}
			if(j - UseTime[i].a >= 0 && dp[j - UseTime[i].a] != -1) {
				dp[j] = max(dp[j - UseTime[i].a] + 1,dp[j]);
				ThisISwap = true;
				ThisJSwap = true;
			} else {
				if(!ThisJSwap)
					dp[j] = -1;
			}
		}
		if(!ThisISwap) {
			printf("Oh，my god!\n");
			return;
		}
	}
	printf("%d\n",dp[t]);
	return;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}