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

const int maxn = 5843;

int dp[maxn];
char *c[] = {"","st","nd","rd"};

bool  Do() {
	int n;
	scanf("%d",&n);
	if(n == 0)
		return false;

	char t[3]="th";
	if(n % 10 == 1 && n % 100 != 11)
		t[0] = 's',t[1]='t';
	else if(n % 10 == 2 && n % 100 != 12)
		t[0] = 'n',t[1] = 'd';
	else if(n % 10 == 3 && n % 100 != 13)
		t[0] = 'r',t[1] = 'd';

	printf("The %d%s humble number is %d.\n",n,t,dp[n]);
	return true;
}

int main() {
	int i1 = 1,i2 = 1,i3 = 1,i4 = 1;
	int n = 1;
	dp[1] = 1;
	while(n < maxn) {
		dp[++n] = min(min(2 * dp[i1],3 * dp[i2]),min(5 * dp[i3],7 * dp[i4]));
		if(dp[n] == 2 * dp[i1]) i1++;
		if(dp[n] == 3 * dp[i2]) i2++;
		if(dp[n] == 5 * dp[i3]) i3++;
		if(dp[n] == 7 * dp[i4]) i4++;
	}

	while(Do());
	return 0;
}