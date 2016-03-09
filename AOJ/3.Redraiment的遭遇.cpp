#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

//bool first = true;
int main() {
	bool a[2][32];//是否停电
	memset(a, 0, sizeof(a));

	//停电日期打表
	int i = 1;
	bool *it = &a[0][1];
	bool first_8 = true;
	while (1) {
		if (it > &a[1][31])
			break;
		if (it >= &a[1][0] && first_8 == true) {
			first_8 = false;
			it++;
		}
		*it = true;
		it += ++i;
	}

	//日历输出调试
	/**
	for (int i = 0; i < 2; i++) {
		printf("%d\n", i + 7);
		for (int j = 1; j < 32; j++) {
			printf("%3d(%d) ", j, a[i][j]);
			if (j % 7 == 0)printf("\n");
		}
		printf("\n");
	}
	/**/

	//输出
	int m, d;
	scanf("%d/%d", &m, &d);
	while (m != 0 && d != 0) {
		/*
		if (!first)
			printf("\n");
		first = false;
		*/

		//月份不在7、8月
		if (m < 7) {
			printf("10\n");
			scanf("%d/%d", &m, &d);
			continue;
		}
		if (m > 8) {
			printf("0\n");
			scanf("%d/%d", &m, &d);
			continue;
		}

		int cnt = 0;
		for (bool *i = &a[m - 7][d]; i <= &a[1][31]; i++) {
			if (i == &a[1][0])
				continue;
			if (*i == true)
				cnt++;
		}
		printf("%d\n", cnt);
		scanf("%d/%d", &m, &d);
	}
	
	return 0;
}