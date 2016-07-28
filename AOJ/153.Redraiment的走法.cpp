/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
using namespace std;

const int maxn = 10005;

int dp[maxn];
int a[maxn];

bool  Do() {
	int n;
	if(scanf("%d",&n) == EOF)
		return false;

	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);

	memset(dp,0,sizeof(dp));

	int Max = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < i;j++)
			if(a[j] < a[i] || j == 0)
				dp[i] = max(dp[i],dp[j] + 1);
		Max = max(Max,dp[i]);
	}

	printf("%d\n",Max);

	return true;
}

int main() {
	while(Do());
	return 0;
}