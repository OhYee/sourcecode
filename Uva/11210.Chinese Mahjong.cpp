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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 32;

const string mj[34] = {
	"1T","2T","3T","4T","5T","6T","7T","8T","9T",
	"1S","2S","3S","4S","5S","6S","7S","8S","9S",
	"1W","2W","3W","4W","5W","6W","7W","8W","9W",
	"DONG","NAN","XI","BEI","ZHONG","FA","BAI"
};
map<string,int> mjmap;

int mjlist[34];
int ans[34];
int kase = 1;

void init() {
	mjmap.clear();
	for(int i = 0;i < 34;i++)
		mjmap.insert(pair<string,int>(mj[i],i));
}

bool xp(int a = -1,int b = -1,int c = -1) {
	//删除3张可以顺或者刻牌
	if(a != -1) {
		mjlist[a]--;
		mjlist[b]--;
		mjlist[c]--;
	}

	bool empty = true;
	bool win = false;
	for(int i = 0;i < 34;i++) {
		if(mjlist[i] != 0) {
			empty = false;
			bool can = false;

			if(mjlist[i] >= 3) {
				can = true;
				if(xp(i,i,i)) {
					win = true;
					break;
				}
			}

			if(mjlist[i] >= 1 && (
				(i >= 0 && i <= 6) ||
				(i >= 9 && i <= 15) ||
				(i >= 18 && i <= 24)) &&
				mjlist[i + 1] >= 1 &&
				mjlist[i + 2] >= 1) {
				can = true;
				if(xp(i,i + 1,i + 2)) {
					win = true;
					break;
				}
			}

			if(!can)
				break;
		}
	}

	if(a != -1) {
		mjlist[a]++;
		mjlist[b]++;
		mjlist[c]++;
	}

	return empty || win;
}

bool shun(int j) {
	//用 j 做将时,是否能赢
	mjlist[j] -= 2;

	bool win = false;
	for(int i = 0;i < 34;i++)
		if(xp()) {
			win = true;
			break;
		}

	mjlist[j] += 2;
	return win;
}

bool ting(int p) {
	//判断加上编号为 p 的牌是否能赢  
	if(mjlist[p] == 4)
		return false;

	bool win = false;
	mjlist[p]++;

	for(int i = 0;i < 34;i++)
		if(mjlist[i] >= 2)
			if(shun(i)) {
				win = true;
				break;
			}

	mjlist[p]--;
	return win;

}


bool Do() {
	memset(mjlist,0,sizeof(mjlist));
	int pos = 0;

	for(int i = 0;i < 13;i++) {
		string t;
		cin >> t;
		if(t == "0")
			return false;
		mjlist[mjmap[t]]++;
	}

	for(int i = 0;i < 34;i++) {
		if(ting(i))
			ans[pos++] = i;
	}

	cout << "Case " << kase++ << ":";
	if(pos) {
		for(int i = 0;i < pos;i++)
			cout << " " << mj[ans[i]];
		cout << endl;
	} else {
		cout << " Not ready" << endl;
	}
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	init();
	while(Do());

	return 0;
}