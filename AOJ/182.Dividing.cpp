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

int kase = 1;

const int maxn = 7;
const int maxv = 500000;
int a[maxn];
int dp[maxv];
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

bool Do() {
	int sum = 0;
	for(int i = 1;i <= 6;i++) {
		scanf("%d",&a[i]);
		sum += a[i] * i;
	}
	if(sum == 0)
		return false;

		
	printf("Collection #%d:\n",kase++);

	if(sum % 2) {
		printf("Can't be divided.\n\n");
		return true;
	}

	v = sum / 2;
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= 6;i++)
		MultiplePack(i,i,a[i]);

	if(dp[v] == v)
		printf("Can be divided.\n\n");
	else
		printf("Can't be divided.\n\n");

	return true;
}
int main() {
	while(Do());
	return 0;
}
