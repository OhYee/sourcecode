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

const int maxn = 150005;


int weight[maxn];

struct Node {
	int n;
	Node(int a) {
		n = a;
	}
	bool operator < (const Node &rhs)const {
		return weight[n] > weight[rhs.n];
	}
};

priority_queue<Node> Q;
bool flag[maxn];


void init() {
	memset(flag,false,sizeof(flag));
	while(!Q.empty())
		Q.pop();
}

bool Do() {
	int n,k,q;
	if(scanf("%d%d%d",&n,&k,&q)==EOF)
		return false;
	init();
	for(int i = 1;i <= n;i++) 
		scanf("%d",&weight[i]);
	
	for(int i = 0;i < q;i++) {
		int com;
		scanf("%d",&com);
		if(com == 1) {
			int t;
			scanf("%d",&t);
			flag[t] = true;
			Q.push(Node(t));

			while((int)Q.size() > k) {
				flag[Q.top().n] = false;
				Q.pop();
			}

		} else {
			int t;
			scanf("%d",&t);

			if(flag[t])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	//printf("\n");
	return true;
}


int main() {
	while(Do());
	return 0;
}