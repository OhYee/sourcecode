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
bool Map[maxn][maxn];

int H[maxn][maxn];
int Left[maxn][maxn];
int Right[maxn][maxn];

//int S[maxn][maxn];

void Do() {
	int n,m;
	scanf("%d%d",&n,&m);
	memset(Map,0,sizeof(Map));
	memset(H,0,sizeof(H));
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			char temp;
			scanf("\n%c",&temp);
			if(temp == 'R')
				Map[i][j] = false;
			else
				Map[i][j] = true;
		}


	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Map[i][j]) {
				if(Map[i - 1][j])
					H[i][j] = H[i - 1][j] + 1;
				else
					H[i][j] = 1;
			}
		}

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Map[i][j]) {
				int t = j;
				while(t >= 1 && H[i][j] <= H[i][t - 1])
					t = Left[i][t - 1];
				Left[i][j] = t;
			}
		}

	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 1;j--) {
			if(Map[i][j]) {
				int t = j;
				while(t <= m && H[i][j] <= H[i][t + 1])
					t = Right[i][t + 1];
				Right[i][j] = t;
			}
		}

	int Max = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Map[i][j]) {
				int S = H[i][j]*(Right[i][j] - Left[i][j] + 1);
				Max = max(Max,S);
			}
		}


	printf("%d\n",Max*3);
}


int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}