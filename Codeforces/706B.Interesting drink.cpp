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

const int maxn = 100005;
int a[maxn];

bool Do() {
	int n;
	if(!(cin >> n))
		return false;
	for(int i = 0;i < n;i++)
		cin >> a[i];

	sort(a,a + n);

	int q;
	cin >> q;
	for(int i = 0;i < q;i++) {
		int t;
		cin >> t;
		cout << upper_bound(a,a + n,t) - a << endl;
	}

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}
