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




int *dp = NULL;

int v;

void ZeroOnePack(int cost,int weight) {
	for(int i = v; i >= cost; i--)
		dp[i] = max(dp[i],dp[i - cost] + weight);
}

bool Do() {
	double Q;
	int N;
	scanf("%lf%d",&Q,&N);
	if(N == 0)
		return false;

	v = (int)(Q * 100);

	if(!dp)
		delete[] dp;
	dp = NULL;

	while(dp == NULL)
		dp = new int[(int)(Q * 100) + 5];

	memset(dp,0,sizeof(int)*(int)(Q * 100) + 5);


	for(int i = 0;i < N;i++) {
		int m;
		scanf("%d",&m);
		double *money = new double[m + 5];
		double A,B,C,sum;
		A = B = C = sum = 0;
		for(int j = 0;j < m;j++) {
			char t;
			scanf("\n%c:%lf",&t,&money[j]);
			sum += money[j];
			if(t >= 'A'&&t <= 'C') {
				switch(t) {
					case 'A':
					A += money[j];
					break;
					case 'B':
					B += money[j];
					break;
					case 'C':
					C += money[j];
					break;
				}
			} else {
				sum += 1001;
			}
		}
		if(A <= 600 && B <= 600 && C <= 600 && sum <= 1000)
			ZeroOnePack((int)(sum * 100),(int)(sum * 100));
	}
	printf("%.2f\n",(double)dp[v] / 100);
	return true;
}

int main() {
	while(Do());
	return 0;
}