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

const int maxn = 5;
const int order[24][6] = {
	{1,2,3,4,5,6},
	{1,3,5,2,4,6},
	{1,4,2,5,3,6},
	{1,5,4,3,2,6},
	{2,1,4,3,6,5},
	{2,3,1,6,4,5},
	{2,4,6,1,3,5},
	{2,6,3,4,1,5},
	{3,1,2,5,6,4},
	{3,2,6,1,5,4},
	{3,5,1,6,2,4},
	{3,6,5,2,1,4},
	{4,1,5,2,6,3},
	{4,2,1,6,5,3},
	{4,5,6,1,2,3},
	{4,6,2,5,1,3},
	{5,1,3,4,6,2},
	{5,3,6,1,4,2},
	{5,4,1,6,3,2},
	{5,6,4,3,1,2},
	{6,2,4,3,5,1},
	{6,3,2,5,4,1},
	{6,4,5,2,3,1},
	{6,5,3,4,2,1}
};

struct Cube {
	string v[6];
};

Cube cube[maxn];
int dis[maxn][maxn];

//计算n个正方体,分别取a b c d视图的最优解
int calc(int n,int a = -1,int b = -1,int c = -1,int d = -1) {
	int num[] = {a,b,c,d};
	map<string,int> m;
	int cnt[maxn];

	int sum = 0;
	for(int k = 0;k < 6;k++) {
		//循环计算6个面
		memset(cnt,0,sizeof(cnt));
		m.clear();
		int pos = 0;
		for(int i = 0;i < n;i++) {
			//第i个方块
			int str = order[num[i]][k] - 1;//第i个方块第k个面在制定次序下的编号
			if(m.count(cube[i].v[str]) == 0)
				m.insert(pair<string,int>(cube[i].v[str],pos++));
			cnt[m[cube[i].v[str]]]++;
		}
		sort(cnt,cnt + pos);
		sum += n - cnt[pos - 1];
	}

	return sum;
}

int dfs(int n,int it,int a = -1,int b = -1,int c = -1,int d = -1) {
	if(it == 0) {
		return calc(n,a,b,c,d);
	} else {
		int num[] = {a,b,c,d};
		int Min = INF;

		for(int i = 0;i < 24;i++) {
			num[n - it] = i;
			Min = min(Min,dfs(n,it - 1,num[0],num[1],num[2],num[3]));
			if(Min == 0)
				return 0;
		}

		return Min;
	}
}

bool Do() {
	int n;
	cin >> n;
	if(n == 0)
		return false;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < 6;j++)
			cin >> cube[i].v[j];

	cout << dfs(n,n - 1,0) << endl;

	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	while(Do());

	return 0;
}