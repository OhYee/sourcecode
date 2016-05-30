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
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 100005;
const int maxm = 100;

inline int read_string(char s[]) {
	char c;
	int i = 0;
	//while(!(((c = getchar()) ==' ') || (c >= 'a'&&c <= 'z')))
	//	if(c == EOF)
	//		return 0;
	if((c = getchar())== EOF)
		return 0;
	while((c == ' ') || (c >= 'a'&&c <= 'z')) {
		s[i++] = c;
		c = getchar();
	}
	s[i] = '\0';
	return i;
}

bool Do() {
	char temp[maxm*2];
	map<string,string> dict;
	map<string,string>::iterator it;
	char a[maxm],b[maxm];

	while(read_string(temp)) {
		if(strcmp(temp,"") == 0)
			break;
		sscanf(temp,"%s %s",a,b);
		dict[b] = a;
	}

	while(scanf("\n%s",a) != EOF) {
		cout << (dict.count(a) ? dict[a] : "eh" )<< "\n";
	}
		

	return false;
}

int main() {
	while(Do());
	return 0;
}