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

bool Do() {
	int T;
	
	if(scanf("%d",&T) == EOF)
		return false;
	
	bool OK = false;
	for(int i = 0;i < T;i++) {
		int a,b;
		scanf("%*s%d%d",&a,&b);
		if(!OK)
			if(a >= 2400 && b > a)
				OK = true;
	}

	if(OK)
		printf("YES\n");
	else
		printf("NO\n");

	return true;
}

int main() {
	while(Do());
	return 0;
}