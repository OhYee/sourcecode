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

const int maxn = 200005;

int b,c;

int s[maxn];
int time[maxn];
int MinTime(int s,int v) {
	int Min = (v - s)*c;
	Min = min(Min,(v - s) / 5 * b + ((v - s) % 5)*c);
	return Min;
}



bool Do() {
	int n,k;
	if(scanf("%d%d%d%d",&n,&k,&b,&c) == EOF)
		return false;
	
	for(int i = 0;i < n;i++) {
		scanf("%d",&s[i]);
	}

	sort(s,s + n);

	
	while(1) {
		
	}

	return true;
}


int vs_main() {
	while(Do());
	return 0;
}