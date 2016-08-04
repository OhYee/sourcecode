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
using namespace std;
const int INF = 0x7FFFFFFF;

const int maxn = 100005;

int delta[2*maxn];
int Money[2*maxn];
int dp[2*maxn];

int n;

inline int standard(int i) {
	if(i < 0)
		return i + n;
	else if(i >= n)
		return i - n;
	else
		return i;
}

bool Do() {
	if(scanf("%d",&n) == EOF)
		return false;

	bool flag = true;

	int Maxpos = 0;//能结余最多钱的城市，从它开始
	for(int i = 1;i <= n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		delta[i] = delta[n+i] = a - b;

		if(delta[i] < 0)
			flag = false;
		if(delta[Maxpos] < delta[i])
			Maxpos = i;
	}

	if(flag) {
		printf("%d\n",n);
		return true;
	}
	if(delta[Maxpos] < 0) {
		printf("%d\n",0);
		return true;
	}

	int Max = 0;
	for(int i = 1;i <= 2*n;i++) {
		if(Money[i-1] + delta[i] < 0) {
			Money[i] = 0;
			dp[i] = 0;
		} else {
			Money[i] = Money[i-1] + delta[i];
			dp[i] = dp[i-1] + 1;
			Max = max(Max,dp[i]);
		}
	}

	Max = min(Max,n);

	printf("%d\n",Max);

	return true;
}

int main() {
	while(Do());
	return 0;
}