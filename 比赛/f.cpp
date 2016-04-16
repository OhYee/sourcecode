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

int kase = 1;
typedef unsigned long long LL;

const int len = 700000;
short int num[len];
 
short int t(LL n) {
	short int cnt;
	LL m = n;

	for (cnt = 0; m; m >>= 1) {
		if (m < len) {
			return num[m] + cnt;
		}
		cnt += (m & 1);
	}

	return cnt;
}

void DFS(LL n,short int cnt) {
	if (n > len)
		return;
	num[n] = cnt;
	DFS(n << 1, cnt);
	DFS((n << 1) + 1, cnt + 1);
}

void init() {
	LL i = 1;
	short int cnt = 1;
	num[i] = cnt;
	DFS(i << 1, cnt);
	DFS((i << 1)+1, cnt + 1);
}

void Do() {
	printf("Case #%d: ", kase++);
	LL d;
	int s1, s2;
	scanf("%llu%d%d", &d,&s1,&s2);

	LL dd = d;

	//优化2^n的情况
	if (s1 == 1 && s2 == 1) {
		LL temp = 2;
		while (temp <= d)
			temp *= 2;
		printf("%llu\n", temp);
		return;
	}
	
	d++;
	int a;
	while (1) {
		a = t(d);
		if (a >= s1 && a <= s2)
			break;
		d++;
	}
	printf("%llu\n", d);
	return;
}


int main() {
	init();

	int T;
	scanf("%d", &T);
	while (T--) {
		Do();
	}
	return 0;
}