/*
	By:OhYee
	Github:OhYee
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
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 30 + 5;
const int maxm = 60 + 5;

//存储边(x1,y1,x2,y2)
int edge[maxn][4];
//离散化
int x[2 * maxn],y[2 * maxn];

vector<int> map[2 * maxn][2 * maxn];

int vs_main() {
	int n;
	scanf("%d",&n);
	//离散数据
	REP(n) {
		scanf("%d%d",&edge[o][0],&edge[o][1],&edge[o][2],&edge[o][3]);
		x[o] = edge[o][0];
		x[o + n] = edge[o][2];
		y[o] = edge[o][1];
		y[o + n] = edge[o][3];
	}
	sort(x,x + 2 * n);
	sort(y,y + 2 * n);
	REP(n) {
		for(int i = 0;i < 4;i++)
			for(int j = 0;j < 2 * n;j++)
				if(edge[o][i] == ((i % 2) ? y[j] : x[j]))
					edge[o][i] = j;
	}

	//画图
	REP(n) {
		int x1,x2,y1,y2;
		x1 = min(edge[o][0],edge[o][2]);
		x2 = max(edge[o][0],edge[o][2]);
		y1 = min(edge[o][1],edge[o][3]);
		y2 = max(edge[o][1],edge[o][3]);
		for(int i = x1;i <= x2;i++)
			for(int j = y1;j <= y2;j++)
				if((j - edge[o][3])*(edge[o][0] - edge[o][2])
					== (i - edge[o][2]) *(edge[o][1] - edge[o][3]))
					map[i][j].push_back(o);
	
	}

	return 0;
}