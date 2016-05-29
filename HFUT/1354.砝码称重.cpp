/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohye`e.com
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

void Do() {
	int a1,a2,b1,b2;
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	printf("%d\n",abs(a1*a2 - b1*b2));
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) 
		Do();
	return 0;
}
