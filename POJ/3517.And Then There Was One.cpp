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

bool Do() {
	int n,k,m;
	cin >> n >> k >> m;
	if(n == 0 && m == 0 && k == 0)
		return false;
	int ans = 0;
	for(int i = 2; i <= n; i++)
		ans = (ans + k) % i;
	ans = (m - k + 1 + ans) % n;
	if(ans <= 0)
		ans += n;
	cout << ans << endl;
	return true;
}

int main() {
	while(Do());
	return 0;
}