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
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

const int maxn = 105;
const int maxc = 1455;
const int INF = 999999999;

int GayHome[maxn];
int Road[maxc][maxc];

void Do() {
	int n,p,c;
	scanf("%d%d%d",&n,&p,&c);

	for(int i = 1;i <= p;i++)
		for(int j = 1;j <= p;j++)
			Road[i][j] = INF;

	for(int i = 1;i <= n;i++)
		scanf("%d",&GayHome[i]);
	for(int i = 0;i < c;i++) {
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		Road[a][b] = Road[b][a] = d;
	}

	for(int i = 1;i <= p;i++)
		Road[i][i] = 0;
	for(int k = 1;k <= p;k++)
		for(int i = 1;i <= p;i++)
			for(int j = 1;j <= p;j++)

				Road[i][j] = min(Road[i][k] + Road[k][j],Road[i][j]);

	/*for(int i = 1;i <= p;i++) {
		for(int j = 1;j <= p;j++)
			printf("%5d ",Road[i][j]);
		printf("\n");
	}*/

	long long Min = INF;
	for(int i = 1;i <= p;i++) {
		long long  sum = 0;
		for(int j = 1;j <= n;j++) {
			sum += Road[i][GayHome[j]];
		}
		Min = min(Min,sum);
	}
	printf("%lld\n",Min);

}

int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();
	return 0;
}