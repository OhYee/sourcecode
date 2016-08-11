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

const int maxn = 15;

int ans;
int Map[maxn][maxn];
int n,m;

void dfs(int x,int y,int sum) {
	if(x > n || y > m)
		return;
	int tsum = sum + Map[x][y];
	if(x == n && y == m)
		if(tsum > 0)
			ans = ((ans == -1) ? tsum : min(ans,tsum));

	dfs(x + 1,y,tsum);
	dfs(x,y + 1,tsum);
}

bool Do() {

	if(!(cin >> n >> m))
		return false;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			cin >> Map[i][j];
		}

	ans = -1;
	dfs(1,1,0);
	cout << ans << endl;

	return true;
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}