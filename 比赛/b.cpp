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

const int maxn = 100005;
long long sum[maxn];
int kase = 1;
int fs[maxn];

void Do() {
	if (kase != 1)
		printf("\n");
	printf("Case %d:\n", kase++);
	int n;
	scanf("%d", &n);
	memset(sum, 0, sizeof(sum));

	fs[0] = 0;
	fs[++fs[0]] = 0;
	REP(n) {
		long long temp;
		scanf("%lld", &temp);
		if (temp < 0)
			fs[++fs[0]] = o;
		sum[o + 1] = sum[o] + temp;
	}
	fs[++fs[0]] = n+1;

	int begin = 1, end = 1;
	long long ans = sum[1];
	for (int i = 1; i <= fs[0]; i++)
		for (int j = 1; j <= fs[0]; j++) {
			int ii = fs[i] - 1;
			int jj = fs[j] + 1;
			if (jj <= ii && jj >= 1 && ii <= n && (sum[ii] - sum[jj - 1]) > ans) {
				begin = jj;
				end = ii;
				ans = sum[ii] - sum[jj - 1];
			}
		}
	printf("%lld %d %d\n", ans, begin, end);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--)
		Do();

	return 0;
}