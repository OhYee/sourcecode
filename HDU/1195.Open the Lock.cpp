/*
By:OhYee
Github:OhYee
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

int del(int a,int b) {
	int cnt = 0;
	while (a) {
		int t1 = (a % 10);
		int t2 = (b % 10);
		cnt += abs(t1-t2)>4?(9 - abs(t1 - t2)): abs(t1 - t2);
		a /= 10;
		b /= 10;
	}
	return cnt;
}

int Swap(int s,int a,int b) {
	int t[4] = {0};
	for (int i = 3;i >= 0;i--) {
		t[i] = s % 10;
		s /= 10;
	}
	swap(t[a],t[b]);
	return t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
}

int BFS(int s,int v) {
	int Min = del(s,v);
	bool visited[9999];
	memset(visited,false,sizeof(visited));

	queue<pair<int,int> > Q;
	Q.push(pair<int,int>(s,0));
	visited[s] = true;
	while (!Q.empty()) {
		int k = Q.front().first;
		int n = Q.front().second;
		Q.pop();

		for (int i = 0;i < 3;i++) {
			int kk = Swap(k,i,i + 1);
			int nn = n + 1;
			if (visited[kk])
				continue;
			visited[kk] = true;
			Min = min(nn + del(kk,v),Min);
			//printf(" %d %d+%d=%d\n",kk,nn,del(kk,v),nn + del(kk,v));
			Q.push(pair<int,int>(kk,nn));
		}
	}
	return Min;
}

bool Do() {
	int s,v;
	scanf("%d%d",&s,&v);

	printf("%d\n",BFS(s,v));

	return true;
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--)
		Do();
	return 0;
}
