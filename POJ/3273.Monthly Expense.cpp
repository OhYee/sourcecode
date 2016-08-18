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
const int maxn = 100005;

int a[maxn];

long long sum;
int n,m;

bool Could(long long num) {
	int per = 0,g = 1;
	for(int i = 1;i <= n;i++) {
		if(per + a[i] > num) {
			g++;
			per = a[i];
			if(g > m)
				return false;
		} else {
			per += a[i];
		}
	}
	return true;
}

long long Division(long long l,long long r) {
	if(l == r) {
		return l;
	}
	long long mid = (l + r) / 2;
	if(Could(mid))
		return Division(l,mid);
	else
		return Division(mid + 1,r);
}

bool Do() {
	if(!(cin >> n >> m))
		return false;
	sum = 0;
	int Max = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum += a[i];
		Max = max(Max,a[i]);
	}

	cout << Division(Max,sum) << endl;

	return true;
}

int main() {
	while(Do());
	return 0;
}