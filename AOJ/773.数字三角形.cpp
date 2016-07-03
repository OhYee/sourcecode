/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

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
#include <set>
#include <functional>
using namespace std;

const int maxn = 1000;

int a[6];
bool visit[7];
bool flag = false;

bool Do() {
	if(scanf("%d",&a[0]) == EOF)
		return false;
	memset(visit,false,sizeof(visit));
	visit[a[0]] = true;

	for(a[1] = 1;a[1] <= 6;a[1]++) {
		if(visit[a[1]])
			continue;
		visit[a[1]] = true;

		for(a[2] = 1;a[2] <= 6;a[2]++) {
			if(visit[a[2]])
				continue;
			visit[a[2]] = true;

			for(a[3] = 1;a[3] <= 6;a[3]++) {
				if(visit[a[3]])
					continue;
				visit[a[3]] = true;

				for(a[4] = 1;a[4] <= 6;a[4]++) {
					if(visit[a[4]])
						continue;
					visit[a[4]] = true;

					for(a[5] = 1;a[5] <= 6;a[5]++) {
						if(visit[a[5]])
							continue;
						visit[a[5]] = true;

						if((a[1] + a[2] == a[5] + a[4]) && (a[0] + a[1] == a[3] + a[4]) && (a[2] + a[3] == a[0] + a[5])) {
							if(flag) {
								printf("\n");
							} else {
								flag = true;
							}
							printf("     %d\n   %d   %d\n %d   %d   %d\n",a[0],a[1],a[5],a[2],a[3],a[4]);
						}

						visit[a[5]] = false;
					}

					visit[a[4]] = false;
				}

				visit[a[3]] = false;
			}

			visit[a[2]] = false;
		}

		visit[a[1]] = false;
	}

	return true;
}

int main() {
	while(Do());
	return 0;
}
