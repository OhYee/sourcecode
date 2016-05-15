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

//hash
int HASH(int a[6]) {
	int Min = 999999;
	for(int i = 0;i < 6;i++) { //初始位置
		for(int k = -1;k == 1 || k == -1;k+=2) {//方向
			int temp = 0;
			for(int j = 0;j < 6;j++) {//计数
				int pos = i + j*k;
				if(pos >= 6)
					pos -= 6;
				if(pos < 0)
					pos += 6;
				temp *= 10;
				temp += a[pos];
			}
			Min = min(Min,temp);
		}
	}
	return Min;
}
const int maxn = 1000010;
bool has[maxn];

bool Do() {
	int n;
	scanf("%d",&n);
	/*if(scanf("%d",&n) == EOF)
		return false;*/
	memset(has,false,sizeof(has));
	bool Finded = false;
	int a[6];
	REP(n) {
		for(int i = 0;i < 6;i++)
			scanf("%d",&a[i]);
		int h = HASH(a);
		if(has[h]) {
			Finded = true;
		} else {
			has[h] = true;
		}
	}

	if(Finded)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");

	return false;
}

int vs_main() {
	while(Do());
	return 0;
}