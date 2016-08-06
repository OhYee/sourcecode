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

const int maxn = 405;
char a[maxn],b[maxn],c[maxn];
bool dp[maxn][maxn];

void Do() {
	scanf("%s%s%s",a + 1,b + 1,c + 1);

	memset(dp,false,sizeof(dp));
	a[0] = b[0] = c[0] = ' ';

	int lena = strlen(a) - 1;
	int lenb = strlen(b) - 1;

	if(lena + lenb != strlen(c) - 1) {
		printf("no");
		return;
	}

	for(int i = 0;i <= lena;i++)
		if(false == (dp[i][0] = (a[i] == c[i] && (i == 0 || dp[i - 1][0]))))
			break;
	for(int j = 0;j <= lenb;j++)
		if(false == (dp[0][j] = (b[j] == c[j] && (j == 0 || dp[0][j - 1]))))
			break;

	for(int i = 1;i <= lena;i++)
		for(int j = 1;j <= lenb;j++)
				dp[i][j] =
					(dp[i - 1][j] && a[i] == c[i + j]) ||
					(dp[i][j - 1] && b[j] == c[i + j]);

	if(dp[lena][lenb])
		printf("yes");
	else
		printf("no");
	//printf(" *%s*%s*%s* ",a,b,c);
	return;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++) {
		printf("Data set %d: ",i);
		Do();
		putchar('\n');
	}
	return 0;
}