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

const int maxn = 205;
const int maxk = 35;

int kase = 1;

int restaurants[maxn];
int dp[maxk][maxn];
int Min[maxn][maxn];

bool Do() {
	memset(dp,0,sizeof(dp));

	int n,m;
	cin >> n >> m;

	if(n == 0 && m == 0)
		return false;

	for(int i = 1;i <= n;i++)
		cin >> restaurants[i];

	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			if(i == j) {
				Min[i][j] = 0;
			} else {
				int pos = restaurants[(i + j) / 2];
				Min[i][j] = 0;
				for(int k = i;k <= j;k++) {
					Min[i][j] += abs(pos - restaurants[k]);
				}
			}
		}
	}

	for(int i = 1;i <= m;i++)
		if(i == 1) {
			for(int j = 1;j <= n;j++)
				dp[1][j] = Min[1][j];
		} else {
			for(int j = 1;j <= n;j++) {
				dp[i][j] = INF;
				for(int k = 1;k < j;k++) {
					dp[i][j] = min(dp[i][j],dp[i - 1][k] + Min[k + 1][j]);
				}
			}
		}
	cout << "Chain "<<kase++ << endl <<"Total distance sum = "<<dp[m][n] << endl<<endl;

	return true;
}
int main() {
	cin.tie(0);
	std::cin.sync_with_stdio(false);

	while(Do());
	return 0;
}