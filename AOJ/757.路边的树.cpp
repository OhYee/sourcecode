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
bool tree[maxn];

bool Do() {
	int L,M;
	if(scanf("%d%d",&L,&M)==EOF)
		return false;

	memset(tree,true,sizeof(tree));

	REP(M) {
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i = a;i <= b;i++)
			tree[i] = false;
	}

	int cnt = 0;
	for(int i = 0;i <= L;i++)
		if(tree[i])
			cnt++;
	

	printf("%d\n",cnt);
	return true;
}

int main() {
	while(Do());
	return 0;
}