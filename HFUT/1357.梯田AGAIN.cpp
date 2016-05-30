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

const int maxh = 1000005;
int cnt[maxh];
int ans[maxh];

int Max = -1;

int Ans(int h) {
	if(h > Max)
		return 0;
	if(ans[h] == -1)
		ans[h] = cnt[h] + Ans(h + 1);

	return ans[h];
}

void Do() {
	memset(cnt,0,sizeof(cnt));
	memset(ans,-1,sizeof(cnt));
	Max = -1;


	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++) {
			int temp;
			scanf("%d",&temp);
			Max = max(Max,temp);
			cnt[temp]++;
		}

	REP(q) {
		int h;
		scanf("%d",&h);
		printf("%d\n",Ans(h)-cnt[h]);
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}