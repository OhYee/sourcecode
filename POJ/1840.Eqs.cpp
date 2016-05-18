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

const int maxn = 6250001*5;
unsigned char cnt[maxn*2];

bool Do() {
	int a[5];
	REP(5)
		if(scanf("%d",&a[o]) == EOF)
			return false;

	memset(cnt,0,sizeof(cnt));

	//map<long long,int> m;
	for(int i = -50;i <= 50;i++)
		for(int j = -50;j <= 50;j++)
			if(i != 0 && j != 0) {
				long long temp = maxn + a[0] * i*i*i + a[1] * j*j*j;
				cnt[temp]++;
			}

	int ans = 0;
	for(int i = -50;i <= 50;i++)
		for(int j = -50;j <= 50;j++)
			for(int k = -50;k <= 50;k++)
				if(i != 0 && j != 0 && k != 0) {
					long long temp = maxn -(a[2] * i*i*i + a[3] * j*j*j + a[4] * k*k*k);
					ans += cnt[temp];
				}

	printf("%d\n",ans);
	return true;
}

int main() {
	while(Do());
	return 0;
}