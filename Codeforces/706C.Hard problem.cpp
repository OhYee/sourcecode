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
#include <bitset>
#include <iomanip> 
using namespace std;

const long long INF = 0x7FFFFFFFFFFFFFFF / 2;

const int maxn = 100005;
int e[maxn];
string s[maxn];
string s2[maxn];

long long dp[2][maxn];

bool Do() {
	int n;
	if(!(cin >> n))
		return false;
	for(int i = 1;i <= n;i++)
		cin >> e[i];
	for(int i = 1;i <= n;i++) {
		cin >> s[i];
		s2[i] = s[i];
		reverse(s2[i].begin(),s2[i].end());
	}

	dp[0][1] = 0;
	dp[1][1] = e[1];

	for(int i = 2;i <= n;i++) {
		dp[0][i] = dp[1][i] = INF;

		if(dp[0][i - 1] != INF && s[i] >= s[i - 1])
			dp[0][i] = min(dp[0][i],dp[0][i - 1]);

		if(dp[1][i - 1] != INF && s[i] >= s2[i - 1])
			dp[0][i] = min(dp[0][i],dp[1][i - 1]);

		if(dp[0][i - 1] != INF && s2[i] >= s[i - 1])
			dp[1][i] = min(dp[1][i],dp[0][i - 1] + e[i]);

		if(dp[1][i - 1] != INF && s2[i] >= s2[i - 1])
			dp[1][i] = min(dp[1][i],dp[1][i - 1] + e[i]);
	

		if(dp[0][i] == INF && dp[1][i] == INF) {
			cout << -1 << endl;
			return true;
		}

	}

	cout << min(dp[0][n],dp[1][n]) << endl;

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}