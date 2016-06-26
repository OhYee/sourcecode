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



void Do() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n % (m + 1) != 0)
		printf("first\n");
	else
		printf("second\n");
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		Do();
	}
	return 0;
}