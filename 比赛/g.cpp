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

const int maxn = 500005;
int a[maxn];

bool Do() {
	int n;
	if (scanf("%d", &n), n == 0)
		return false;
	REP(n)
		scanf("%d", &a[o]);

	int cnt = 0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if (a[j] < a[i]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				cnt++;
			}

	printf("%d\n", cnt);
}


int vs_main() {
	while (Do());
	return 0;
}