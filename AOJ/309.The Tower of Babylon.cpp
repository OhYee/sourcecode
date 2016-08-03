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

const int maxn = 35;

int kase = 0;
struct Node {
	int x,y,h;
	Node(int x = 0,int y = 0,int h = 0) {
		this->x = min(x,y);
		this->y = max(x,y);
		this->h = h;
	}
	bool operator < (const Node &rhs)const {
		if(x == rhs.x)
			return y < rhs.y;
		else
			return x < rhs.x;
	}
	static bool cmp(Node &a,Node &b) {
		return (a.x < b.x && a.y < b.y);
	}
};
Node S[3 * maxn];
int dp[3 * maxn];

bool  Do() {
	int n;
	scanf("%d",&n);
	if(n == 0)
		return false;

	printf("Case %d: maximum height = ",++kase);

	for(int i = 0;i < n;i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		S[i * 3 + 1] = Node(x,y,z);
		S[i * 3 + 2] = Node(y,z,x);
		S[i * 3 + 3] = Node(z,x,y);
	}

	sort(S,S + 3 * n + 1);

	int Max = 0;

	for(int i = 1;i <= 3 * n;i++) {
		dp[i] = 0;
		for(int j = 0;j < i;j++) {
			if(Node::cmp(S[j],S[i])) {
				dp[i] = max(dp[i],dp[j] + S[i].h);
			}
		}
		Max = max(Max,dp[i]);
	}

	printf("%d\n",Max);
	return true;
}

int main() {
	while(Do());
	return 0;
}