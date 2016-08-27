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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 50005;

int n,k;
long long a[maxn];

void Do() {
	cin >> n >> k;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	if(n - k > 1) {
		sort(a,a + n);
		long long Min = -1;
		long long sum = 0;
		long long sums = 0;
		for(int i = 0;i < n - k;i++) {
			sum += a[i];
			sums += a[i] * a[i];
		}

		for(int i = 0;i <= k;i++) {
			if(i) {
				sum -= a[i - 1];
				sum += a[n - k + i - 1];
				sums -= a[i - 1] * a[i - 1];
				sums += a[n - k + i - 1] * a[n - k + i - 1];
			}
			//double average = sum / (double)(n - k);

			//double ans = (double)(n - k)*average*average + sums - 2 * average*sum;

			long long ans = (n - k)*sums - sum*sum;

			if(Min == -1)
				Min = ans;
			else
				Min = min(Min,ans);
		}
		if(Min == -1)
			Min = 0;
		cout << fixed << setprecision(11) << (double)Min / (double)(n - k) << endl;
	} else {
		cout << 0 << endl;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	while(T--)
		Do();

	return 0;
}