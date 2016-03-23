/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
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

const char d[13] = {'3','4','5','6','7','8','9','1','J','Q','K','A','2'};

int main() {
	int T;
	scanf("%d",&T);
	REP(T) {
		char a[3],b[3];
		scanf("\n%s%s\n",&a,&b);
		if(a[0] == b[0]) {
			printf("=\n");
			continue;
		}
		int i,j;
		for(i = 0;i < 13;i++)
			if(d[i] == a[0])
				break;
		for(j = 0;j < 13;j++)
			if(d[j] == b[0])
				break;
		printf("%c\n",i < j ? '<' : '>');
	}
	return 0;
}