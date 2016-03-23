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
#include <queue>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)


int main() {
	int m,a,b,c;
	scanf("%d",&m);
	while(m--) {
		scanf("%d%d%d",&a,&b,&c);
		if(a + b > c && abs(a - b) < c) {
			printf("%d\n",a + b + c);
		} else {
			printf("Wrong\n");
		}
	}
	return 0;
}
