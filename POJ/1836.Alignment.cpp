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
double num[maxn];
int ans[maxn];

int dp1[maxn];
int dp2[maxn];

//最长上升子序列
void LIS(double *a,int n,int *dp) {
	REP(n)
		dp[o] = 1;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < i;j++)
			if(a[i] > a[j])
				dp[i] = max(dp[i],dp[j] + 1);
}
void LIS2(double *a,int n,int *dp) {
	REP(n)
		dp[o] = 1;
	for(int i = n-1;i >= 0;i--)
		for(int j = n-1;j > i;j--)
			if(a[i] > a[j])
				dp[i] = max(dp[i],dp[j] + 1);
}

bool Do() {
	int n;
	if(scanf("%d",&n) == EOF)
		return false;

	REP(n)
		scanf("%lf",&num[o]);

	//最小上升子序列
	/*
		dp[i]为前i个数能生成的最小上升子序列长度
		对于第i个数有两种情况：

			若a[i]>a[j]
				dp[i]=max{dp[j]+1,dp[i]}
			若a[i]<a[j]
				dp[i]=max{1,dp[i]}
                
            即dp[i] = max(dp[i],dp[j] + 1) (a[i]>a[j])
            初始为1
	*/


	LIS(num,n,dp1);
	LIS2(num,n,dp2);

	/*
	int Max = -1;
	bool flag = false;
	REP(n) {
		ans[o] = dp1[o] + dp2[o];
		if(Max == ans[o] && ans[o-1] == Max) {
			flag = true;
		} else {
			if(Max < ans[o]) {
				Max = ans[o];
				flag = false;
			}
		}
	}
	*/

	int ans2 = -1;
	for(int i = 0;i < n ;i++)
		for(int j = i + 1;j < n ;j++)
			ans2 = max(ans2,dp1[i] + dp2[j]);
	/*
	REP(n)
		printf("%d ",dp1[o]);
	printf("\n");
	REP(n)
		printf("%d ",dp2[o]);
	printf("\n");
	REP(n)
		printf("%d ",ans[o]);
	printf("\n");
	*/

	//printf("%d\n",n - (Max - 1) - flag);
	printf("%d\n",n - ans2);

	return true;
}

int main() {
	while(Do());
	return 0;
}
