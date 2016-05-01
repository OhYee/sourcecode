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

const int maxn = 1005;
int n;
int a[maxn];

class LIS_stack {
private:
	static const int SIZE = maxn;
	int len;//长度
	int Stack[SIZE];
public:
	LIS_stack() {
		len = 0;
		memset(Stack,0,sizeof(Stack));
	}
	void push(int num) {
		if(len == 0 || Stack[len - 1] < num) {
			Stack[len++] = num;
		} else {
			for(int i = 0;i < len;i++) {
				if(Stack[i] > num) {
					Stack[i] = num;
					break;
				}
			}
		}
	}
	int lenth() {
		return len;
	}

};

int LIS(int *a,int len) {
	LIS_stack s;
	for(int i = 0;i < len;i++) 
		s.push(a[i]);
	return s.lenth();
}

bool Do() {
	if(scanf("%d",&n) == EOF)
		return false;
	REP(n)
		scanf("%d",&a[o]);

	printf("%d\n",LIS(a,n));

	return true;
}

int main() {
	while(Do());
	return 0;
}