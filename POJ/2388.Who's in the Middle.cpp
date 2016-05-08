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

const int maxn = 10005;
int a[maxn];

bool Do() {
	int n;
	if(scanf("%d",&n) == EOF)
		return false;
	
	REP(n)
		scanf("%d",&a[o]);

	sort(a,a + n);

	printf("%d\n",a[n/2]);

	return true;
}

int main() {
	while(Do());
	return 0;
}