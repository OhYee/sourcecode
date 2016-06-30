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

const int maxn = 100005;
//const int INF = (1 << 31) - 1;
const int INF = 0x7fffffff;

int a[maxn];

int dfs(int *a,int l,int r,int &begin,int &end) {
	if(l == r) {
		begin = end = l;
		return a[l];
	}
	if(l > r) {

		begin = end = -1;
		return -INF;
	}



	int mid = (l + r) / 2;
	int Max;
	int ans;
	int tbegin,tend;
	begin = end = mid;


	//中间
	int i;

	ans = 0;
	int maxl = 0;
	for(i = mid - 1;i >= l;i--) {
		ans += a[i];
		if(ans >= maxl) {
			maxl = ans;
			begin = i;
		}
	}

	ans = 0;
	int maxr = 0;
	for(i = mid + 1;i <= r;i++) {
		ans += a[i];
		if(ans > maxr) {
			maxr = ans;
			end = i;
		}

	}


	Max = maxl + a[mid] + maxr;


	//左侧
	ans = dfs(a,l,mid - 1,tbegin,tend);
	if(ans >= Max) {
		Max = ans;
		begin = tbegin;
		end = tend;
	}


	//右侧
	ans = dfs(a,mid + 1,r,tbegin,tend);
	if(ans > Max) {
		Max = ans;
		begin = tbegin;
		end = tend;
	}

	return Max;
}


bool Do() {
	int n,l,r;
	scanf("%d",&n);
	if(n== 0)
		return false;

	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);

	int ans = dfs(a,1,n,l,r);

	if(ans >= 0)
		printf("%d %d %d\n",ans,a[l],a[r]);
	else
		printf("%d %d %d\n",0,a[1],a[n]);

	return true;
}

int main() {

	while(Do());
	return 0;
}