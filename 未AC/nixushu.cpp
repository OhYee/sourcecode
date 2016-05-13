
#include "stdafx.h"
//====================================================================

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

const int maxn = 500005;
int a[maxn];

int ans;

//将已经排好序的a[l]~a[mid] a[mid+1]~a[r]拼合起来
void merge(int a[],int l,int mid,int r){
	int pos1 = l;//左侧的指针
	int pos2 = mid + 1;//右侧的指针
	int *temp = new int[r - l + 1];
	int pos = 0;//临时数组的指针
	while(pos1 <= mid || pos2 <= r) {
		if(pos1 > mid) {
			temp[pos++] = a[pos2++];
		}
		if(pos2 > r) {
			temp[pos++] = a[pos1++];
		}
		if(pos1 <= mid&&pos2 <= r) {
			if(a[pos1] <= a[pos2]) {
				temp[pos++] = a[pos1++];
			} else {
				temp[pos++] = a[pos2++];
				ans+=mid-pos1+1;//交换
			}
		}
	}
	for(int i = 0;i <= r - l;i++)
		a[l + i] = temp[i];
}

//归并排序 对a[l]~a[r]排序
void mergesort(int a[],int l,int r) {
	if(l<r) {
		int mid = (l + r) / 2;
		mergesort(a,l,mid);
		mergesort(a,mid + 1,r);
		merge(a,l,mid,r);
	}
}

bool Do() {
	int n;
	if(scanf("%d",&n),n==0)
		return false;

	REP(n)
		scanf("%d",&a[o]);

	ans = 0;
	mergesort(a,0,n - 1);
	printf("%d\n",ans);
	REP(n)
		printf("%d ",a[o]);
	printf("\n");

	return true;
}

int vs_main() {
	while(Do());
	return 0;
}


//====================================================================
int main() {
	int start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	printf("#===================#\n");
	vs_main();
	printf("#===================#\n");
	printf("Time:%.5lf\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}
