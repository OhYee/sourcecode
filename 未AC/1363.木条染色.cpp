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

const int maxl = 1000001;

struct Node {
	int l,r;
	Node(int a,int b) {
		l = a,r = b;
	}
};

list<Node> List;
list<Node>::iterator it;

inline void Init() {
	List.clear();
	List.insert(List.end(),Node(0,maxl));
}
void Color(int a,int b) {
	for(it = List.begin();it != List.end();it++) {
		if(it->r < a)
			continue;
		if(it->l > b)
			break;


		if(it->l < a && b < it->r) {
			List.insert(it,Node(it->l,a));
			it->l = b;
			break;
		}
		if(a <= it->l && it->r <= b) {
			it = List.erase(it);
			continue;
		}

		if(a <= it->l && b <= it->r) {
			it->l = b;
		}
		if(it->l <= a && it->r <= b) {
			it->r = a;
		}
	}
}
int ColorLen(int a,int b) {
	int cnt = 0;
	for(it = List.begin();it != List.end();it++) {
		if(it->r <= a)
			continue;
		if(it->l >= b)
			break;
		cnt++;
	}
	return cnt;
}

void Do() {
	Init();

	int n,q;
	scanf("%d%d",&n,&q);

	for(int i = 0;i < n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		Color(a,b);
	}

	for(int i = 0;i < q;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",ColorLen(a,b));
	}
	printf("\n");
	return;
}

int vs_main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		Do();
	}
	return 0;
}