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
#include <sstream>
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

map<string,int> mp;

int read_string(string &s) {
	char c;
	s = "";
	while(c=getchar(),!((c >= 'a'&&c <= 'z')||c=='#')) {
		if(c == '\n' || c == ',' || c == '.')
			return 0;
		if(c == EOF)
			return -1;
	}
	while(((c >= 'a'&&c <= 'z')||c=='#')) {
		s += c;
		c = getchar();
	}
	if(c == '\n' || c == ',' || c == '.')
		return 2;
	return 1;
}

int MapPush(string s) {
	if(mp.count(s) == 0)
		mp.insert(pair<string,int>(s,0));
	mp[s]++;
	return mp[s];
}

bool Do() {
	int Max = 0;
	mp.clear();

	string a="",b="";
	while(1) {
		int res = read_string(b);
		if(b == "####")
			break;

		if(res == -1)
			return false;
		if(res == 0) {
			a = b;
			b = "";
		} 
		if(res == 2) {
			if(a != "") {
				string Add = a + " " + b;
				Max = max(Max,MapPush(Add));
			}
			a = "";
			b = "";
		}
		if(res==1){
			if(a != "") {
				string Add = a + " " + b;
				Max = max(Max,MapPush(Add));
			}
			a = b;
			b = "";
		}
	}

	map<string,int>::iterator it = mp.begin();
	while(it != mp.end()) {
		if(it->second == Max) {
			cout << it->first << ":" << Max << endl;
			break;
		}
		++it;
	}

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());

	return 0;
}