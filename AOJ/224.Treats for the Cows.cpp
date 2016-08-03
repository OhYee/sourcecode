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

const int maxn = 2005;

int a[maxn];
int dp[maxn][maxn];

bool  Do() {
	int n;
	if(scanf("%d",&n) == EOF)
		return false;
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);



	for(int i = n;i >= 1;i--)
		for(int j = i;j <= n;j++) {
			if(i == j) {
				dp[i][i] = a[i] * n;
			} else {
				dp[i][j] = max(
					dp[i + 1][j] + a[i] * (n - j + i),
					dp[i][j - 1] + a[j] * (n - j + i)
				);
			}
		}

	printf("%d\n",dp[1][n]);

	return true;
}

int main() {
	while(Do());
	return 0;
}