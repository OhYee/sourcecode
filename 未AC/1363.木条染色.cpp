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
const interestingma

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

inline void Init() {
	List.clear();
	List.insert(List.end(),Node(0,maxl));
	memset(colored,false,sizeof(colored));
}

void Color(int a,int b) {
	for(it = List.begin();it != List.end();it++) {
	mark:;

		if(it->r < a)
			continue;
		if(it->l > b)
			break;

		if(a <= it->l && it->r <= b) {
			it = List.erase(it);
			goto mark;
		}

		if(it->l < a && b < it->r) {
			List.insert(it,Node(it->l,a));
			it->l = b;
			break;
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
		//cnt++;
		cnt += min(it->r,b) - max(it->l,a)+1;
	}
	return cnt;
}

void Color2(int a,int b) {
	for(int i = a;i < b;i++)
		colored[i] = true;
}
int ColorLen2(int a,int b) {
	int cnt = 0;
	for(int i = a;i <= b;i++)
		if(!colored[i])
			cnt++;
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
		Color2(a,b);
	}

	for(int i = 0;i < q;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",ColorLen(a,b));
	}
	printf("\n");
	return;
}

void test() {
	int n,q;
	n = rand() % 100;
	q = rand() % 100000;
	v.clear();
	Init();
	bool out = false;

	int delta;
	for(int i = 0;i < n;i++) {
		delta = rand() % (100000 - 1);
		int a = rand() % (100000 - delta);
		int b = a + delta;
		Color(a,b);
		Color2(a,b);
		v.push_back(Node(a,b));
	}
	for(int i = 0;i < n;i++) {
		delta = rand() % (100000- 1);
		int a = rand() % (100000- delta);
		int b = a + delta;

		int t1 = ColorLen(a,b);
		int t2 = ColorLen2(a,b);

		if(t1 != t2) {
			if(!out) {
				out = true;
				printf("Color:\n");
				for(size_t j = 0;j < v.size();j++)
						printf("%d %d\n",v[j].l,v[j].r);
			}

			printf("\nX (%d,%d) (%d) (%d)\n",a,b,t1,t2);
		}

	}
	printf("End\n");
	if(out)
	system("pause");
}

int vs_main() {
	/*srand((int)time(0));
	while(1)
		test();*/
	int T;
	scanf("%d",&T);
	while(T--) {
		Do();
	}
	return 0;
}