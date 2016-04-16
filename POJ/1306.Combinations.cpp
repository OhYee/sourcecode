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

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	return b == 0 ? a : gcd(b, a%b);
}

bool Do() {
	int n, m;
	if (scanf("%d%d", &n, &m), n == 0 && m == 0)
		return false;

	unsigned long long ans = 1;
	int a = max(m, n - m);
	int b = min(m, n - m);
	unsigned long long t = 1;
	for (int i = n, j = 2; i > a; i--, j++) {
		ans *= i;
		if (j <= b || t > 1) {
			if (j <= b)
				t *= j;
			if (t > 1) {
				unsigned long long q = gcd(ans, t);
				ans /= q;
				t /= q;
			}
		}

	}


	printf("%d things taken %d at a time is %llu exactly.\n", n, m, ans);

	return true;
}


int main() {
	while (Do());
	return 0;
}