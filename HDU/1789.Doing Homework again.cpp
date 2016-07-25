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
using namespace std;

const int maxn = 1005;
const int maxt = 900000;
int Deadline[maxn],Score[maxn];
struct Node {
	int Deadline;
	int Score;
	bool operator < (const Node &rhs)const {
		if(Score == rhs.Score)
			return Deadline > rhs.Deadline;
		else
			return Score > rhs.Score;
	}
};
Node node[maxn];
int Time[maxt];

bool Do() {
	int n;
	scanf("%d",&n);
	int sum = 0;
	int mt = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&node[i].Deadline);
		mt = max(mt,node[i].Deadline);
	}
	for(int i = 1;i <= n;i++) {
		scanf("%d",&node[i].Score);
		sum += node[i].Score;
	}

	sort(node + 1,node + 1 + n);

	for(int i = 0;i <= mt + 1;i++)
		Time[i] = i;

	int ans = 0;
	for(int i = 1;i <= n;i++) {
		int k = node[i].Deadline;
		int t = Time[k];
		while(!(t == k || t == 0 || k == 0)) {
			k = Time[k];
			t = Time[t];
		}
		if(t == k && t != 0) {
			Time[k]--;
			ans += node[i].Score;
		}
	}

	printf("%d\n",sum - ans);

	return true;
}


int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}