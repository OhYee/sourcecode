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
#include <bitset>
using namespace std;

const int maxn = 15;

struct naive {
	int n;
	int f;
	bool operator < (const naive &rhs)const {
		return f < rhs.f;
	}
};

bool Map[maxn][maxn];

priority_queue <naive> Q1;
queue<naive> Q2;

void Do() {
	int n;
	cin >> n;

	while(!Q1.empty()) Q1.pop();
	while(!Q2.empty()) Q2.pop();
	bool flag = false;
	memset(Map,false,sizeof(Map));

	for(int i = 0;i < n;i++) {
		naive t;
		cin >> t.f;
		t.n = i;
		Q1.push(t);
	}

	while(!Q1.empty()) {
		naive qu = Q1.top();
		Q1.pop();
		while(!Q1.empty() && qu.f > 0) {
			naive qv = Q1.top();
			Q1.pop();
			if(qv.f == 0)
				continue;

			int u = qu.n;
			int v = qv.n;
			if(Map[u][v] == false) {
				Map[u][v] = Map[v][u] = true;
				qu.f--;
				qv.f--;
			}
			if(qv.f > 0)
				Q2.push(qv);
		}
		if(qu.f > 0) {
			flag = true;
			break;
		}
		while(!Q2.empty()) {
			Q1.push(Q2.front());
			Q2.pop();
		}
	}

	if(flag) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				if(j != 0)
					cout << " ";
				cout << Map[i][j] ? 1 : 0;

			}
			cout << endl;
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--) {
		Do();
		if(T)
			cout << endl;
	}

	return 0;
}