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

const int INF = 0x7FFFFFFF;
const int maxn = 10005;

int v;
long long dp[maxn];

void CompletePack(int cost) {
	for(int i = cost; i <= v; i++)
		dp[i] += dp[i - cost];
}

bool Do() {
	if(!(cin >> v))
		return false;
	
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

	for(int i = 1;i <= 21;i++)
		CompletePack(i*i*i);

	cout << dp[v]<<endl;

	return true;
}

int main() {
	while(Do());
	return 0;
}