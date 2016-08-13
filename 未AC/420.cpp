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
using namespace std;

const int INF = 0x7FFFFFFF / 2;
const int maxn = 15;

int Map[maxn][maxn];
int dp[2 << maxn];

int SetI(int num,int i,bool flag) {
	if(flag)
		return num | (1 << i);
	else
		return num & (0 << i);
}
bool GetI(int num,int i) {
	return num >> i & 1;
}
int GetChange(int num1,int num2) {
	int n = num1 ^ num2;
	int i = 0;
	while(n) {
		if(n & 1)
			return i;
		n >>= 1;
		i++;
	}
	return 0;
}
bool Do() {
	int n;
	if(!(cin >> n))
		return false;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> Map[i][j];



	for(int i = 1;i <= (1 << n) - 1;i++)
		dp[i] = INF;
	dp[0] = 0;

	for(int i = 1;i < n;i++) {
		int NewState = SetI(0,i,1);
		dp[NewState] = Map[0][i];
	}

	for(int i = 1;i < (1 << n) - 1;i++) {
		int vis[maxn + 5];
		int unvis[maxn + 5];
		vis[0] = unvis[0] = 0;
		int k = i;
		int pos = 0;
		while(pos < n) {
			if(k & 1)
				vis[++vis[0]] = pos++;
			else
				unvis[++unvis[0]] = pos++;
			k >>= 1;
		}

		for(int u = 1;u <= vis[0];u++) {
			for(int v = 1;v <= unvis[0];v++) {
				int NewState = SetI(i,v,1);
				dp[NewState] = min(dp[NewState],dp[i] + Map[u][v]);
			}
		}

	}
	cout << dp[(1<<n)-1] << endl;

	return true;
}

int vs_main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}
