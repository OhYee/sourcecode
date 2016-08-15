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

bool Do() {
	int n;
	if(!(cin >> n))
		return false;

	for(int i = 1;i <= n;i++) {
		if(i != 1)
			cout << " ";

		if(i == n)
			if(i % 2)
				cout << "I hate it";
			else
				cout << "I love it";
		else
			if(i % 2)
				cout << "I hate that";
			else
				cout << "I love that";
	}
	cout << endl;
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}