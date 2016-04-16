/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい��
エリ�`チカ��
勣亟竃栖Хорошо議旗鷹填~
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

//DEBUG MODE
#define debug 0

//儉桟
#define REP(n) for(int o=0;o<n;o++)

//a海 b錐
int DFS(int a, int b) {
	if (a == b)
		return 1;
	return 1 + DFS(max(a - b, b), min(a - b, b));

}

void Do() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", DFS(max(m, n), min(m, n)));
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--)
		Do();
	return 0;
}