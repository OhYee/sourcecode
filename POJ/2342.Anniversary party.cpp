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
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

const int maxn = 6005;

int happy[maxn];
int father[maxn];
vector<int> children[maxn];

int dp[maxn][2];

void tree(int t) {
	for(size_t i = 0;i < children[t].size();i++) {
		int &child = children[t][i];
		tree(child);
		dp[t][1] += dp[child][0];
		dp[t][0] += max(dp[child][1],dp[child][0]);
	}
}

bool Do() {
	int n;
	if(!(cin >> n))
		return false;

	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= n;i++) {
		cin >> dp[i][1];
		children[i].clear();
	}

	while(1) {
		int a,b;
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		father[a] = b;
		children[b].push_back(a);
	}

	int root = 1;
	while(father[root])
		root = father[root];

	tree(root);
	cout << max(dp[root][0],dp[root][1]) << endl;
	return true;
}

int main() {
	while(Do());
	return 0;
}