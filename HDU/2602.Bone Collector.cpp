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

const int maxn = 1005;

int v,n;
int dp[maxn];
int value[maxn];
int vol[maxn];

void ZeroOnePack(int cost,int weight) {
	for(int i = v; i >= cost; i--)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}


void Do() {
	scanf("%d%d",&n,&v);

	for(int i = 1;i <= n;i++)
		scanf("%d",&value[i]);
	for(int i = 1;i <= n;i++)
		scanf("%d",&vol[i]);
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
		ZeroOnePack(vol[i],value[i]);

	printf("%d\n",dp[v]);

}


int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}