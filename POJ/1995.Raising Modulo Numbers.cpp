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
#include <iomanip>
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

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;


LL exp_mod(LL a,LL n,LL b) {
	LL t;
	if(n == 0) return 1 % b;
	if(n == 1) return a % b;
	t = exp_mod(a,n / 2,b);
	t = t * t % b;
	if((n & 1) == 1) t = t * a % b;
	return t;
}

void Do() {
	int M;
	cin >> M;
	int n;
	cin >> n;

	LL ans = 0;
	for(int i = 0;i < n;i++) {
		int a,b;
		cin >> a >> b;
		ans = (ans + exp_mod(a,b,M)) % M;
	}

	cout << ans<<endl;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int Z;
	cin >> Z;
	while(Z--)
		Do();

	return 0;
}