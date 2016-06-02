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
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 1005;

//使用HASH判重

struct Node {
	int Arrow;
	int TimeLeft;
	int Perfect;
	Node(int a,int b,int c) {
		Arrow = a;
		TimeLeft = b;
		Perfect = c;
	}
	bool operator < (const Node & rhs)const {
		return true;
	}
};

struct Time {
	int a,c;
};

int n;
int ans;
Time UseTime[maxn];

set<Node> s;


void DFS(int Arrow,int TimeLeft,int Perfect) {
	if(Arrow == n-1) {
		ans = max(ans,Perfect);
		return;
	}

	size_t t = s.size();
	s.insert(Node(Arrow,TimeLeft,Perfect));
	if(s.size() == t)
		return;

	int LT = TimeLeft - UseTime[Arrow + 1].a;
	if(LT >= 0)
		DFS(Arrow + 1,LT,Perfect + 1);

	LT = TimeLeft - UseTime[Arrow + 1].c;
	if(LT >= 0)
		DFS(Arrow + 1,LT,Perfect);
}

void Do() {
	int t;
	scanf("%d",&n);

	int sum = 0;
	REP(n) {
		scanf("%d%*d%d",&UseTime[o].a,&UseTime[o].c);
		sum += UseTime[o].c;
	}

	scanf("%d",&t);

	if(sum > t) {
		printf("Oh，my god!\n");
		return;
	}

	ans = 0;
	s.erase(s.begin(),s.end());
	DFS(-1,t,0);

	printf("%d\n",ans);


}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}