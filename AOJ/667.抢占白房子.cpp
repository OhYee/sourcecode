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

int main() {
	int cnt = 0;
	for(int i = 0;i < 8;i++)
		for(int j = 0;j < 8;j++) {
			char temp;
			scanf("\n%c\n",&temp);
			//printf("i=%d j=%d -> %c\n",i,j,temp);
			if(temp == 'F')
				if(!((i % 2) ^ (j % 2)))//奇偶性相同的为白色，对2取模后异或取反
					cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}