/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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

char Mapa[maxn][maxn];
char Mapb[maxn][maxn];
char Mapc[maxn][maxn];

int H[maxn][maxn];
int Left[maxn][maxn];
int Right[maxn][maxn];
int MaxMatrix(char Matrix[maxn][maxn],int n,int m,char target) {
	memset(H,0,sizeof(H));
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				if(Matrix[i - 1][j])
					H[i][j] = H[i - 1][j] + 1;
				else
					H[i][j] = 1;
			}
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				int t = j;
				while(t >= 1 && H[i][j] <= H[i][t - 1])
					t = Left[i][t - 1];
				Left[i][j] = t;
			}
		}
	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 1;j--) {
			if(Matrix[i][j] == target) {
				int t = j;
				while(t <= m && H[i][j] <= H[i][t + 1])
					t = Right[i][t + 1];
				Right[i][j] = t;
			}
		}
	int Max = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			if(Matrix[i][j] == target) {
				int S = H[i][j] * (Right[i][j] - Left[i][j] + 1);
				Max = max(Max,S);
			}
		}
	return Max;
}

bool  Do() {
	int n,m;
	if(scanf("%d%d",&n,&m) == EOF)
		return false;
	int a = 0,b = 0,c = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) {
			char t;
			scanf("\n%c",&t);
			Mapa[i][j] = (t == 'w' || t == 'y' || t == 'z') ? 'a' : t;
			Mapb[i][j] = (t == 'w' || t == 'x' || t == 'z') ? 'b' : t;
			Mapc[i][j] = (t == 'x' || t == 'y' || t == 'z') ? 'c' : t;
		}

	int ans = 0;
	ans = max(ans,MaxMatrix(Mapa,n,m,'a'));
	ans = max(ans,MaxMatrix(Mapb,n,m,'b'));
	ans = max(ans,MaxMatrix(Mapc,n,m,'c'));

	printf("%d\n",ans);
	return true;
}

int main() {
	while(Do());
	return 0;
}
