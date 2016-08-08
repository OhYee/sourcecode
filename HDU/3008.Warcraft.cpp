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

const int maxn = 105;

int dp[2][maxn];
int magic[maxn];
int hurt[maxn];

bool Do() {
	int n,t,q;
	scanf("%d%d%d",&n,&t,&q);

	if(n == 0 && t == 0 && q == 0)
		return false;

	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= n;i++)
		scanf("%d%d",&magic[i],&hurt[i]);

	magic[0] = 0;
	hurt[0] = 1;

	int time = (100 % q == 0) ? 100 / q : 100 / q + 1;

	for(int i = 1;i <= time;i++) {
		int *thisdp = dp[i & 1];
		int *lastdp = dp[!(i & 1)];

		for(int j = 100;j >= 0;j--) {
			thisdp[j] = 0;
			if(j == 100)
				for(int k = 1;k <= t;k++)
					lastdp[100] = max(lastdp[100],lastdp[100 - k]);
			else
				if(j - t >= 0)
					lastdp[j] = lastdp[j - t];
				else
					lastdp[j] = 0;
		}
		for(int j = 100;j >= t;j--)
			for(int k = 0;k <= n;k++)
				if(j - magic[k] >= 0) {
					thisdp[j - magic[k]] = max(
						thisdp[j - magic[k]],
						lastdp[j] + hurt[k]
					);
					if(thisdp[j - magic[k]] >= 100) {
						printf("%d\n",i);
						return true;
					}
				}
	}

	printf("My god\n");
	return true;
}

int main() {
	while(Do());
	return 0;
}