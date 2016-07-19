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
#include <set>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 10005;

int v;
double dp[maxn];

void ZeroOnePack(int cost,double weight) {
	for(int i = v; i >= cost; i--)
		dp[i] = max(dp[i],1-((1 - dp[i - cost]) * (1-weight)));
}

bool Do() {
	int n;
	scanf("%d%d",&v,&n);
	if(n == 0 && v == 0)
		return false;
	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= n;i++) {
		int cost;
		double p;
		scanf("%d%lf",&cost,&p);
		ZeroOnePack(cost,p);
	}

	printf("%.1f%%\n",dp[v]*100);
	return true;
}

int main() {
	while(Do());
	return 0;
}