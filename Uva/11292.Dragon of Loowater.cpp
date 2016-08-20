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

const int maxn = 20005;

int dragon[maxn];
int knight[maxn];
bool vis[maxn];

bool Do() {
	int n,m;
	cin >> n >> m;
	if(n == 0 && m == 0)
		return false;

	for(int i = 0;i < n;i++)
		cin >> dragon[i];
	for(int i = 0;i < m;i++)
		cin >> knight[i];

	int ans = 0;
	sort(dragon,dragon + n);
	sort(knight,knight + m);
	memset(vis,false,sizeof(vis));

	for(int i = 0;i < n;i++) {
		int it = lower_bound(knight,knight + m,dragon[i]) - knight;
		for(it;it<m;it++)
			if(!vis[it]) {
				ans += knight[it];
				vis[it] = true;
				break;
			}
		if(it == m) {
			ans = -1;
			break;
		}
	}
	if(ans == -1) {
		cout << "Loowater is doomed!" << endl;
	}else{
		cout << ans << endl;
	}
	
	return true;
}

int main() {
	while(Do());
	return 0;
}