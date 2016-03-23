#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int N,M;
const int maxn = 15;
const int maxm = 205;
long long d[maxm];
int price[maxn];

bool Do() {
	if(scanf("%d%d",&N,&M) == EOF)
		return false;
	REP(N)
		scanf("%d",&price[o + 1]);

	memset(d,0,sizeof(d));
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
			d[j] +=  ((j - price[i] >= 0) ? (d[j - price[i]] + 1) : 0);

	printf("%lld\n",d[M]);
	return true;
}

int vs_main() {
	while(Do());
	return 0;
}