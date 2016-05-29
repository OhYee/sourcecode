//====================================================================
/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

typedef long long LL;

typedef long long LL;
LL exp_mod(LL a,LL n,LL b) {
	LL t;
	if(n == 0) return 1 % b;
	if(n == 1) return a % b;
	t = exp_mod(a,n / 2,b);
	t = t * t % b;
	if((n & 1) == 1) t = t * a % b;
	return t;
}

bool Do() {
	int n;
	if(scanf("%d",&n),n == 0)
		return false;
	if(n < 0)
		return true;
	printf("%lld\n",exp_mod(2,n,9973) - 1);
	return true;
}

int main() {
	while(Do());
	return 0;
}
