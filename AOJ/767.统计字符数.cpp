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

const int INF = 0x7FFFFFFF;
const int maxn = 500;

int cnt[maxn];

void Do() {
	memset(cnt,0,sizeof(cnt));
	char c = getchar();
	while(!((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')))
			c = getchar();
	while((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) {
		cnt[c]++;
		c = getchar();
	}
	int ans,Max = 0;
	for(int i = 0;i < maxn;i++) {
		if(cnt[i] > Max) {
			ans = i;
			Max = cnt[i];
		}
	}
	printf("%c %d\n",ans,Max);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}
