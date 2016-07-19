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

int v;
int dp[maxn];

void CompletePack(int cost,int weight) {
	for(int i = cost; i <= v; i++)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}

bool Do() {
	int exp,lp,n,maxnum;
	if(scanf("%d%d%d%d",&exp,&lp,&n,&maxnum)==EOF)
		return false;
	memset(dp,0,sizeof(dp));
	v = lp;

	double cheapest = 0;
	for(int i = 1;i <= n;i++) {
		int getexp,lostlp;
		scanf("%d%d",&getexp,&lostlp);
		cheapest = max(cheapest,(double)getexp / lostlp);
		CompletePack(lostlp,getexp);
	}
	
	if(cheapest*maxnum < exp) {
		printf("-1\n");
	} else {
		for(int i = lp;i >= 0;i--) {
			if(dp[i] < exp) {
				printf("%d\n",lp-i-1);
				break;
			}
		}
		
	}
	
	return true;
}

int main() {
	while(Do());
	return 0;
}
