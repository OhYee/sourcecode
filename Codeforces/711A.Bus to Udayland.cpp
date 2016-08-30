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
using namespace std;

const int maxn = 1005;
const int INF = 0x7FFFFFFF;

char seat[maxn][8];

bool  Do() {
	int n;
	if(!(cin >> n))
		return false;

	bool yes = false;
	for(int i = 0;i < n;i++) {
		cin >> seat[i];
		if(!yes&&seat[i][0] == 'O'&&seat[i][1] == 'O') {
			seat[i][0] = seat[i][1] = '+';
			yes = true;
		}
		if(!yes&&seat[i][3] == 'O'&&seat[i][4] == 'O') {
			seat[i][3] = seat[i][4] = '+';
			yes = true;
		}
	}
	if(yes) {
		cout << "YES" << endl;
		for(int i = 0;i < n;i++) {
			cout << seat[i]<<endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return true;
}

int main() {
	while(Do());
	return 0;
}