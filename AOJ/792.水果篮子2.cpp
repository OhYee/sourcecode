/*
By:OhYee
Github:OhYee
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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 15;
const int maxm = 1005;

bool Do() {
	int N,M;//N水果总数 M钱数
	int price[maxn];//第i个水果的价格
	int num_min[maxn];//第i个水果最少买几个
	int num_max[maxn];//第i个水果最多买几个

	//数据读入
	if(scanf("%d%d",&N,&M) == EOF)
		return false;
	REP(N)
		scanf("%d",&price[o + 1]);
	REP(N) {
		scanf("%d%d",&num_min[o + 1],&num_max[o + 1]);
	}

	int d[maxn][maxm];
	for(int i = 0;i <= N;i++)
		for(int j = 0;j <= M;j++)
			d[i][j] = 0;

	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++) 
			if(num >= num_min[i] &&
				num <= num_max[i] &&
				j-price[i]>=0)
				d[i][j] = d[i - 1][j] + d[i][j - price[i]] + 1;
	printf("\n\n");
	for(int i = 0;i <= N;i++) {
		for(int j = 0;j <= M;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	printf("\n\n");
	printf("%d\n",d[N][M]);

	return true;
}

int main() {
	while(Do());
	return 0;
}