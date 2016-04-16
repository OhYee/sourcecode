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

const int maxn = 10000;
int n, m;
int Map[maxn][maxn];

void Do() {
	int n;
	scanf("%d", &n);
	int temp, ans;
	if (n==1) {
		REP(n) {
			if (o == 0) 
				scanf("%d", &ans);
			
			else 
				scanf("%*d", &temp);
		}
	}
	else {
		REP(n)
			scanf("%*d");
		ans = 0;
	}
	
	printf("%d\n", ans);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		Do();
	}
	return 0;
}