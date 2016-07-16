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

const int maxT = 100005;
const int maxpos = 11;

int pie[maxT];
int *dp;
int *dp2;

bool Do() {
	int n;
	scanf("%d",&n);
	if(n == 0)
		return false;

	memset(pie,0,sizeof(pie));
	memset(dp,0,maxpos * sizeof(int));
	memset(dp2,0,maxpos * sizeof(int));

	int maxt = 0;
	for(int i = 1;i <= n;i++) {
		int t,x;
		scanf("%d%d",&t,&x);
		pie[t] += x;
		maxt = max(maxt,t);
	}


	for(int i = 1;i <= maxt;i++) {
		for(int j = 0;j < maxpos;j++) {
			dp2[j] = dp[j];
			if(j != 0)
				dp2[j] = max(dp[j],dp[j - 1]);
			if(j != maxpos - 1)
				dp2[j] = max(dp[j],dp[j + 1]);
			dp2[j] += pie[i];
		}
		int *temp = dp;
		dp = dp2;
		dp2 = temp;
	}
	int Max = 0;
	for(int i = 0;i < maxpos;i++)
		Max = max(Max,dp[i]);
	printf("%d\n",Max);
	return true;
}

int vs_main() {
	dp = new int[maxpos];
	dp2 = new int[maxpos];

	while(Do());
	return 0;
}