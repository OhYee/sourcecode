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

const double INF = 0x7FFFFFFF / 2;
const int maxc = 105;
int p[maxc];

double dp[maxc];

inline int toint(double n) {
	return (int)(n + 0.01);
}

bool Do() {
	int L,N,C,T,VR,VT1,VT2;
	if(scanf("%d%d%d%d%d%d%d",&L,&N,&C,&T,&VR,&VT1,&VT2) == EOF)
		return false;
	for(int i = 1;i <= N;i++)
		scanf("%d",&p[i]);
	p[0] = 0;
	p[N + 1] = L;
	sort(p + 1,p + 1 + N);

	for(int i = 1;i <= N + 1;i++) {
		dp[i] = INF;
		for(int j = 0;j < i;j++) {
			int dis = p[i] - p[j];
			if(dis <= C) {
				dp[i] = min(dp[i],dp[j] + (double)dis / VT1);
			} else {
				dp[i] = min(dp[i],dp[j] + (double)C / VT1 + (double)(dis - C) / VT2);
			}
		}
		dp[i] += T;
	}

	double ans = dp[N + 1] - T;
	if(ans < (double)L / VR)
		printf("What a pity rabbit!\n");
	else
		printf("Good job,rabbit!\n");


	return true;
}

int main() {
	while(Do());
	return 0;
}