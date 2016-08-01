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

const int INF = 0x7FFFFFFF / 2;
const int maxn = 10005;
int dp[maxn];
int v;

void CompletePack(int cost,int weight) {
	for(int i = cost; i <= v; i++)
		dp[i] = min(dp[i],dp[i - cost] + weight);
}

void Do() {
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	v = b - a;

	for(int i = 1;i <= v;i++)
		dp[i] = INF;
	dp[0] = 0;

	for(int i = 0;i < n;i++) {
		int c,w;
		scanf("%d%d",&w,&c);
		CompletePack(c,w);
	}
	if(dp[v] == INF)
		printf("This is impossible.\n");
	else
		printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
	return;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}