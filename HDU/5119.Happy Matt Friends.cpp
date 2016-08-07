/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
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
#include <functional>
#include <bitset>
using namespace std;

const int maxn = 45;
const int maxm = 1000005;

int a[maxn];
int dp[maxn][maxm];

void Do() {
	int n,m;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	dp[0][0] = 1;

	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < maxm;j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j ^ a[i]] += dp[i - 1][j];
		}
	}

	long long ans = 0;
	for(int i = m;i <= maxm;i++)
		ans += dp[n][i];

	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++) {
		printf("Case #%d: ",i);
		Do();
	}
	return 0;
}