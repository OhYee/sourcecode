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
using namespace std;

typedef long long LL;
const int INF = 0x7FFFFFFF;
const int maxn = 10005;
const int maxh = 1000000005;

int Begin[maxn];
LL Min[maxn];

bool Do() {
	int n;
	scanf("%d",&n);
	if(n == 0)
		return false;

	LL dp = 0;
	LL Max = 0;

	for(int i = 1;i <= n;i++) {
		LL h;
		scanf("%lld",&h);





		int k = Begin[i - 1];
		dp = 0;
		while(k != 0) {
			if(dp < (i - k + 1)*Min[i - 1]) {
				dp = (i - k + 1)*Min[i - 1]);
				Begin[i] = k;
				Min[]
			}


			dp = max(dp,(i - k + 1)*Min[i - 1]);

			k = Begin[k - 1];
		}


		if(h > Min[i - 1]) {
			dp += Min[i];
			Begin[i] = Begin[i - 1];
		}

		Max = max(dp,Max);

	}

	printf("%lld\n",Max);
	return true;
}

int vs_main() {
	while(Do());
	return 0;
}