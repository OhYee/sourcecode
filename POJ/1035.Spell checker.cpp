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

int ok;
int ldic,lstr;
string current;
vector<string> dic;


void replace(string dic) {
	int count = 0;
	for(size_t i = 0; i < dic.length(); i++) {
		if(current[i] != dic[i]) count++;
		if(count > 1) return;
	}
	ok = 1;
	cout << " " + dic;
}

void insert(string dic) {
	string tmp;
	for(size_t i = 0; i < current.length(); i++) {
		if(current[i] != dic[i]) {
			tmp = dic;
			tmp.insert(i,1,current[i]);
			if(tmp == current) {
				ok = 1;
				cout << " " + dic;
			}
			return;
		}
	}
}

void del(string dic) {
	string tmp;
	for(size_t i = 0; i < dic.length(); i++) {
		if(current[i] != dic[i]) {
			tmp = dic;
			tmp.erase(i,1);
			if(tmp == current) {
				ok = 1;
				cout << " " + dic;
			}
			return;
		}
	}
}

bool Do() {
	while(1) {
		if(!(cin >> current))
			return false;
		if(current == "#") break;
		dic.push_back(current);
	}

	while(1) {
		cin >> current;
		if(current == "#") break;

		ok = -1;
		lstr = current.length();

		for(size_t i = 0; i < dic.size(); i++) {
			if(dic[i] == current) {
				cout << current + " is correct";
				ok = 0;
				break;
			}
		}


		if(ok < 0) {
			cout << current + ':';
			for(size_t i = 0; i < dic.size(); i++) {
				ldic = dic[i].length();
				if(lstr == ldic) {
					replace(dic[i]);
				} else if(lstr == ldic + 1) {
					insert(dic[i]);
				} else if(lstr == ldic - 1) {
					del(dic[i]);
				}
			}
		}

		cout << endl;
	}

	return true;
}

int main() {
	while(Do());
	return 0;
}