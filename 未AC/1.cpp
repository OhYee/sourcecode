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

char Map[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

const int maxn = 50;
char m[maxn];
char ans[maxn];


int r_map(char c) {
	for(int i = 0;i < 16;i++)
		if(Map[i] == c)
			return i;
	return -1;
}

bool Do() {
	int P,R;
	scanf("%d%d",&P,&R);
	if(P == 0)
		return false;

	scanf("\n%s",m);

	int len = strlen(m);
	int ten = 0;
	for(int i = len - 1;i >= 0;i--) {
		ten += r_map(m[i]) * (int)pow(P,len - i - 1);
	}

	int pos = 0;
	while(ten) {
		ans[pos++] = ten % R;
		ten /= R;
	}
	if(pos == 0)
		ans[pos++] = 0;

	reverse(ans,ans + pos);

	for(int i = 0;i < pos;i++)
		putchar(Map[ans[i]]);

	
	putchar('\n');

	return true;
}


int main() {
	while(Do());
	return 0;
}