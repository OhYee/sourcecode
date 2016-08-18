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

int n,s;
int a[maxn];
long long sum[maxn];

bool Could(int n,int i) {
	return sum[i] - sum[n - 1] < s;
}

int Division(int l,int r,int i) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	if(Could(mid,i))
		return Division(l,mid,i);
	else
		return Division(mid + 1,r,i);
}

bool Do() {
	if(!(cin >> n >> s))
		return false;

	int Min = INF;
	sum[0] = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		int begin = Division(1,i,i);
		if(a[i] >= s)
			Min = min(Min,1);
		else if(begin != 1)
			Min = min(Min,i - begin + 2);
	}

	if(Min == INF)
		Min = 0;
	cout << Min << endl;

	return true;
}

int main() {
	while(Do());
	return 0;
}