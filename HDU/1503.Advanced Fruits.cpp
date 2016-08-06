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

const int maxn = 205;
char a[maxn],b[maxn],c[maxn];

//最长公共子序列
//输入字符串a 及其长度 字符串b 及其长度 保存最长公共子序列的数组
//字符从0开始
int LCS(char *a,char *b,char s[] = NULL) {
	int len1 = strlen(a);
	int len2 = strlen(b);
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
	//如果c未传值
	if(s == NULL)
		return dp[len1][len2];
	//逆序推出一条符合串
	int ans = dp[len1][len2];
	int x = len1;
	int y = len2;
	int it = ans;
	int pos = len1 + len2 - it;
	s[pos] = '\0';

	while(x || y) {
		if(x - 1 >= 0 && dp[x - 1][y] == it) {
			s[--pos] = aa[x--];
			continue;
		}
		if(y - 1 >= 0 && dp[x][y - 1] == it) {
			s[--pos] = bb[y--];
			continue;
		}
		s[--pos] = aa[x];
		--it;

		x--;
		y--;
	}
	return ans;
}

bool Do() {
	if(scanf("%s%s",a,b) == EOF)
		return false;
	LCS(a,b,c);
	printf("%s\n",c);
	return true;
}

int main() {
	while(Do());
	return 0;
}