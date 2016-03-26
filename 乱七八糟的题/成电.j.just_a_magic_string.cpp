/*
By:OhYee
Github:OhYee
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
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn=1000005;

int get(int n) {
	int cnt;//二进制中1的数量
	for(cnt = 0; n; ++cnt) {
		n &= (n - 1); // 清除最低位的1
	}
	return (cnt % 2) ? false : true;
}

char s[maxn];

int vs_main() {
	//读入字符串 字符长度为it （0~it-1）
	char c;
	int it = 0;
	c = getchar();
	while(c == 'a' || c == 'b') {
		s[it++] = c == 'a' ? true : false;
			c = getchar();
	}
	s[it] = '\0';

	//整个magic string中第一个匹配的字符个数i
	for(int i = 0;;i++) {
		bool ok = true;
		//字符串的第j个数
		for(int j = 0;j < it;j++) {
			if(!(s[j] == get(i + j))) {
				ok = false;
				break;
			}
		}
		if(ok) {
			printf("%d",i + 1);
			break;
		}
		if(i == maxn*5) {
			printf("-1");
			break;
		}
	}
	return 0;
}