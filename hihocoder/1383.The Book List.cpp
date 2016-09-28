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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

int kase = 1;

struct CATEGORY {
	list<CATEGORY> *child;
	list<CATEGORY> *book;
	string s;
	CATEGORY(string b) {
		list<CATEGORY> *p = new list<CATEGORY>;
		p->clear();
		child = p;

		p = new list<CATEGORY>;
		p->clear();
		book = p;

		s = b;
	}
	bool operator < (string rhs) {
		return s < rhs;
	}
};

list<CATEGORY> L;

list<CATEGORY>::iterator pushsk(list<CATEGORY>::iterator t,string s) {
	list<CATEGORY>::iterator it = t->child->begin();
	it = lower_bound(t->child->begin(),t->child->end(),s);
	if(it == t->child->end() || it->s != s) {
		t->child->insert(it,CATEGORY(s));
		it--;
	}
	return it;
}

void pushs(list<CATEGORY>::iterator t,string s) {
	list<CATEGORY>::iterator it = t->book->begin();
	it = lower_bound(t->book->begin(),t->book->end(),s);
	if(it == t->book->end() || it->s != s) {
		t->book->insert(it,CATEGORY(s));
		it--;
	}
}

void DFS(list<CATEGORY> *L,int n) {
	if(L == NULL)
		return;
	list<CATEGORY>::iterator it = L->begin();
	while(it != L->end()) {
		for(int i = 0;i < n;i++)
			cout << "    ";
		if(n != -1)
			cout << it->s << endl;
		DFS(it->child,n + 1);
		DFS(it->book,n + 1);

		delete it->child;
		delete it->book;//处理内存泄露问题
		++it;
	}
}

bool Do() {
	L.clear();
	L.push_back(CATEGORY("MAIN"));//主书库

	string s;
	while(1) {
		if(!(getline(cin,s)))
			return false;
		if(s == "0")
			break;
		size_t len = s.size();
		string t = "";
		list<CATEGORY>::iterator it = L.begin();

		for(size_t i = 0;i < len;i++) {
			if(s[i] == '/') {
				it = pushsk(it,t);
				t = "";
			} else {
				t += s[i];
			}
		}
		pushs(it,t);
	}
	cout << "Case " << kase++ << ":" << endl;
	DFS(&L,-1);
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());

	return 0;
}