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

const int maxn = 30005;

//hash
int hash(int a[6]){
	int Min = 999999;
	for(int i = 0;i < 6;i++){ //初始位置
		for(int k = -1;k == 1 || k == -1;k++) {//方向
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

bool Do() {
	int n;
	if(scanf("%d%d",&n)==EOF)
		return false;
	bool Finded = false;
	int a[6];
	REP(n) {
		for(int i = 0;i < 6;i++)
			scanf("%d",a[i]);
	}



	if(Finded)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");

	return true;
}

int vs_main() {
	while(Do());
	return 0;
}