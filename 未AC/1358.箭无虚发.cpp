#include "stdafx.h"
//====================================================================
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

const int maxn = 1005;

struct Node {
	int Arrow;
	int TimeLeft;
	int Perfect;
	Node(int c,int a,int b) {
		TimeLeft = a;
		Perfect = b;
		Arrow = c;
	}
};

struct Time {
	int a,b,c;
};

int n;
int LastArrow,ans;
Time UseTime[maxn];

void DFS(int Arrow,int TimeLeft,int Perfect) {

	LastArrow = Arrow;
	ans = max(ans,Perfect);

	if(TimeLeft == 0)
		return;

	int LT = TimeLeft - UseTime[Arrow + 1].a;
	if(LT >= 0 && Arrow + 1 < n)
		DFS(Arrow + 1,LT,Perfect + 1);

	LT = TimeLeft - UseTime[Arrow + 1].c;
	if(LT >= 0 && Arrow + 1 < n)
		DFS(Arrow + 1,LT,Perfect);
}

void Do() {
	
	int t;
	scanf("%d",&n);
	//Time *UseTime = new Time[n+1];
	REP(n)
		scanf("%d%d%d",&UseTime[o].a,&UseTime[o].b,&UseTime[o].c);
	scanf("%d",&t);

	ans = -1;
	LastArrow = -1;

	DFS(-1,t,0);

	//queue<Node> Q;
	//Q.push(Node(-1,t,0));

	//while(!Q.empty()) {
	//	int Arrow = Q.front().Arrow;
	//	int TimeLeft = Q.front().TimeLeft;
	//	int Perfect = Q.front().Perfect;
	//	Q.pop();

	//	ans = max(ans,Perfect);
	//	LastArrow = Arrow;
	//	if(TimeLeft == 0)
	//		continue;

	//	int LT = TimeLeft - UseTime[Arrow + 1].a;
	//	if(LT>=0 && Arrow+1 < n)
 //			Q.push(Node(Arrow + 1,LT,Perfect + 1));

	//	LT = TimeLeft - UseTime[Arrow + 1].b;
	//	if(LT >= 0 && Arrow + 1 < n)
	//		Q.push(Node(Arrow + 1,LT,Perfect));

	//	LT = TimeLeft - UseTime[Arrow + 1].c;
	//	if(LT >= 0 && Arrow + 1 < n)
	//		Q.push(Node(Arrow + 1,LT,Perfect));
	//}

	if(LastArrow!=n-1)
		printf("Oh，my god!\n");
	else
		printf("%d\n",ans);

	//delete UseTime;
}

int vs_main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}

//====================================================================
int main() {
	int start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	printf("#===================#\n");
	vs_main();
	printf("#===================#\n");
	printf("Time:%.4lfs\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}
