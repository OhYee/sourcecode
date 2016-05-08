
#include "stdafx.h"
//====================================================================

/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
#include <queue>
#include <stack>
#include <map>
#include <array>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 100;
int len[2];
char gene[2][maxn];

inline int w(char a,char b) {
	if(a == b)
		return 5;
	#define equal(A,B) ((a==A&&b==B)||(a==B||b==A))
	if(equal('A','C') || equal('A','T') || equal('-','T'))
		return -1;
	if(equal('A','G') || equal('C','T') || equal('G','T') || equal('G','-'))
		return -2;
	if(equal('A','-') || equal('C','G'))
		return -3;
	if(equal('-','C'))
		return -4;
	return 0;
}

//最长公共子序列
//输入字符串a 及其长度 字符串b 及其长度 保存最长公共子序列的数组
//字符从0开始
int LCS(char *a,char *b,char s[] = NULL) {
	int len1 = strlen(a) ;
	int len2 = strlen(b) ;
	char *aa = a - 1;
	char *bb = b - 1;

	//声明二维数组
	int * m = new int[(len1 + 1)*(len2 + 1)];
	int **dp = new int *[len1 + 1];
	for(int i = 0;i <= len1;i++)
		dp[i] = m + i*(len2 + 1);

	//初始化
	for(int i = 0;i <= len1;i++)
		dp[i][0] = 0;
	for(int i = 0;i <= len2;i++)
		dp[0][i] = 0;

	//动态规划
	for(int i = 1;i <= len1;i++)
		for(int j = 1;j <= len2;j++)
			if(aa[i] == bb[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);

	/*for(int i = 0;i <= len1;i++){
		for(int j = 0;j <= len2;j++)
			printf("%d\t",dp[i][j]);
		printf("\n");
	}*/

	//如果c未传值
	if(s == NULL)
		return dp[len1][len2];

	//逆序推出一条符合串
	int ans = dp[len1][len2];
	int x = len1;
	int y = len2;
	int it = ans;
	s[it] = '\0';
	while(it) {
		if(dp[x - 1][y] == it) {
			x--;
			continue;
		}
		if(dp[x][y - 1] == it) {
			y--;
			continue;
		}
		s[--it] = aa[x];
		x--;
		y--;
	}
	return ans;
}

void Do() {
	REP(2)
		scanf("%d %s",&len[o],gene[o]);

	char lcs[maxn];
	int length = LCS(gene[0],gene[1],lcs);

	int ans = 0;

	ans += length * 5;

	for(int i = 0;i < 2;i++)
		for(int j = 0,it = 0;j < len[i];j++) {
			if(lcs[it] == gene[i][j])
				it++;
			else
				ans += w(gene[i][j],'-');
		}

	printf("%d\n",ans);
}

int vs_main() {
	int T;
	scanf("%d",&T);
	while(T--)
		Do();

	return 0;
}


//====================================================================
int main() {
	int start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	printf("#===================#\n");
	vs_main();
	printf("#===================#\n");
	printf("Time:%.5lf\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}
