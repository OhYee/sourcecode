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
#include <iomanip> 
using namespace std;

const int maxn = 3;

long long need[maxn];
long long num[maxn];
long long p[maxn];
long long temp[maxn];
long long r;
long long per;

bool Could(long long n) {
	long long money = 0;
	for(int i = 0;i < maxn;i++) 
		if(n*need[i] > num[i])
			money += p[i] * (n*need[i]-num[i]);
	return money > r;
}

long long Division(long long l,long long r) {
	if(l == r) {
		return l;
	}
	long long mid = (l + r) / 2;
	if(Could(mid))
		return Division(l,mid);
	else
		return Division(mid + 1,r);

}

bool Do() {
	string s;
	if(!(cin >> s))
		return false;

	need[0] = need[1] = need[2] = 0;
	for(size_t i = 0;i < s.size();i++) {
		if(s[i] == 'B')
			need[0]++;
		if(s[i] == 'S')
			need[1]++;
		if(s[i] == 'C')
			need[2]++;
	}

	per = 0;

	for(int i = 0;i < 3;i++)
		cin >> num[i];
	for(int i = 0;i < 3;i++) {
		cin >> p[i];
		per += need[i] * p[i];
	}
	cin >> r;
	cout << Division(0,2000000000000) - 1 << endl;

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());
	return 0;
}