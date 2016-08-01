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

const int maxn = 105;
int dp[maxn];
int v;

void ZeroOnePack(int cost,int weight) {
	for(int i = v; i >= cost; i--)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}
void CompletePack(int cost,int weight) {
	for(int i = cost; i <= v; i++)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}
void MultiplePack(int cost,int weight,int n) {
	if(cost * n > v) {
		CompletePack(cost,weight);
	} else {
		int k = 1;
		while(k < n) {
			ZeroOnePack(cost * k,weight * k);
			n -= k;
			k *= 2;
		}
		ZeroOnePack(cost * n,weight * n);
	}
}

void Do() {
	int n;
	scanf("%d%d",&v,&n);

	memset(dp,0,sizeof(dp));
	for(int i = 0;i < n;i++) {
		int c,w,num;
		scanf("%d%d%d",&c,&w,&num);
		MultiplePack(c,w,num);
	}
	
	printf("%d\n",dp[v]);
	return;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}