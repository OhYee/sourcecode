#include "stdafx.h"
//====================================================================
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

const int maxl = 1000005;

struct Node {
	int l,r;
	Node(int a,int b) {
		l = a,r = b;
	}
};

list<Node> List;
list<Node>::iterator it;
bool colored[maxl];

vector<Node> v;

//线段树
struct Tree {
	int l;
	int r;
	char Covered;//-1全部未染色 0 部分染色 1全部染色
};
Tree T[maxl * 4];
void Build(int l,int r,int n = 1) {
	T[n].l = l;
	T[n].r = r;
	T[n].Covered = -1;
	if(r - l == 1)
		return;
	int mid = (l + r) / 2;
	Build(l,mid,2 * n);
	Build(mid,r,2 * n + 1);
}
void Cover(int l,int r,int n = 1) {
	if(T[n].Covered != 1) {
		int mid = (T[n].l + T[n].r) / 2;

		if(l == T[n].l && r == T[n].r) {
			T[n].Covered = 1;
		} else {
			if(T[n].r - T[n].l == 1)
				return;

			if(r <= mid)
				Cover(l,r,2 * n);
			if(mid < l)
				Cover(l,r,2 * n + 1);
			if(l <= mid && mid < r) {
				Cover(l,mid,2 * n);
				Cover(mid,r,2 * n + 1);
			}
			if(T[2 * n].Covered == 1 && T[2 * n + 1].Covered == 1)
				T[n].Covered = 1;
			else
				if(T[2 * n].Covered != -1 || T[2 * n + 1].Covered != -1)
					T[n].Covered = 0;
		}
	}
}
void Uncovered(int l,int r,int &ans,int n = 1) {
	static int last;
	if(n == 1)
		last = -1;

	if(T[n].r == T[n].l || r < T[n].l || T[n].r < l)
		return;
	if(T[n].Covered == 1)
		return;
	if(T[n].Covered == -1) {
		if(l == T[n].l || (l <= T[n].l && T[n].r <= r)) {
			if(last != T[n].l)
				ans++;
			last = T[n].r;
		}
		return;
	}

	if(T[n].r - T[n].l == 1) {
		if(l == T[n].l || (l <= T[n].l && T[n].r <= r)) {
			if(last != T[n].l)
				ans++;
			last = T[n].r;
		}

	} else {
		int mid = (T[n].l + T[n].r) / 2;
		Uncovered(l,r,ans,n * 2);
		Uncovered(l,r,ans,2 * n + 1);
	}
}


void Do2() {
	Build(0,maxl);
	int n,q;
	scanf("%d%d",&n,&q);

	for(int i = 0;i < n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		Cover(a,b);
	}

	for(int i = 0;i < q;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = 0;
		Uncovered(a,b,ans);
		printf("%d\n",ans);
	}

	printf("\n");
	return;
}


int vs_main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		Do2();
	}
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
	printf("Time:%.5lf\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}
