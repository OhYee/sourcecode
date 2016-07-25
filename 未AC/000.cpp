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

const int maxn = 5005;

int a[maxn];
int dp[maxn];
bool vis[maxn];
int cnt[maxn];
int last[maxn];

bool Do() {
	int n;

	if(scanf("%d",&n) == EOF)
		return false;

	for(int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
	}

	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));

	int Maxpos = 0;
	int pos=0;
	for(int i = 1;i <= n;i++) {

		for(int j = 0;j < i;j++)
			if(a[j] > a[i] || j == 0)
				if(dp[i] <= dp[j] + 1) {
					if(dp[i] == dp[j] + 1) {
						last[++last[0]] = j;
					} else {
						last[0] = 0;
						dp[i] = dp[j] + 1;
					}
				}

		for(int j = 1;j <= i;j++)
			vis[j] = false;

		for(int j = 1;j <= last[last[0]];j++) {
			if(!vis[j]) {
				vis[j] = true;
				cnt[i] += cnt[j];
			}
		}

		if(dp[pos] < dp[i])
			pos = i;
	}


	printf("%d %d\n",dp[pos],cnt[pos]);

	return true;
}

int vs_main() {
	while(Do());
	return 0;
}