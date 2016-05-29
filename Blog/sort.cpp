
#include "stdafx.h"
//====================================================================


#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <memory> 

#define random(x) (rand()%x) 
#define REP(n) for(int o=0;o<n;o++) 

const bool SHOW = 1;
const int size = 10;
const int MAX = 100;
const int TIME = 10;

int a[size];
int b[size];
int ans[size];

long long start;

//冒泡排序 
void BubbleSort(int a[],int n) {
	int ThisSwapPosition = n;//本轮最后一个交换的位置 
	bool HasSwap = false;
	for(int i = 0;i < n;i++) {
		HasSwap = false;
		int LastSwapPosition = ThisSwapPosition;//上轮最后一个交换的位置 
		for(int j = 1;j < LastSwapPosition;j++) {
			if(a[j - 1] > a[j]) {
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				ThisSwapPosition = j;
				HasSwap = true;//本轮发生交换 
			}
		}
		if(!HasSwap)
			break;
	}
}

//归并排序 
void Merge(int a[],int l,int mid,int r) {
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
			}
		}
	}
	//memcpy(a+l,temp,sizeof(temp));
	for(int i = 0;i <= r - l;i++)
		a[l + i] = temp[i];
}

//对a[l]~a[r]排序 
void MergeSort(int a[],int l,int r) {
	if(l < r) {
		int mid = (l + r) / 2;
		MergeSort(a,l,mid);
		MergeSort(a,mid + 1,r);
		Merge(a,l,mid,r);
	}
}


//快速排序 
void QuickSort(int a[],int l,int r) {
	if(l >= r)
		return;
	int left = l;
	int right = r;
	int mid = (a[l] + a[r] + a[(l + r) / 2]) / 3;
	bool move = false;
	while(left < right) {
		move = false;
		while(left < right && a[right] > mid) {
			right--;
			move = true;
		}
		while(left < right && a[left] < mid) {
			left++;
			move = true;
		}
		if(left < right) {
			int temp = a[right];
			a[right] = a[left];
			a[left] = temp;
		}
		if(!move)
			right--;
	}
	QuickSort(a,l,left);
	QuickSort(a,right + 1,r);
}


//调整堆
void AdjustHeap(int a[],int i,int n) {
	int left = (i + 1) * 2 - 1;
	int right = (i + 1) * 2;
	if(left<n && a[left]>a[i]) {
		int temp = a[left];
		a[left] = a[i];
		a[i] = temp;
		AdjustHeap(a,left,n);
	}
	if(right<n && a[right]>a[i]) {
		int temp = a[right];
		a[right] = a[i];
		a[i] = temp;
		AdjustHeap(a,right,n);
	}

}

//堆排序
void HeapSort(int a[],int n) {
	for(int i = n / 2;i >= 0;i--) {
		AdjustHeap(a,i,n);
	}
	for(int i = 0;i < n - 1;i++) {
		int temp = a[0];
		a[0] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		AdjustHeap(a,0,n - i - 1);
	}
}


void Do() {
	//生成随机数 
	REP(size)
		a[o] = random(MAX);
	//输出随机数 
	printf("生成随机数	：	");
	if(SHOW)
		REP(size)
		printf("%d ",a[o]);
	printf("\n");

	//测试1 - 冒泡排序 
	printf("冒泡排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	BubbleSort(b,size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	memcpy(ans,b,sizeof(b));
	printf("\n");

	//测试2 - 归并排序 
	printf("归并排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	MergeSort(b,0,size - 1);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	//测试3 - 快速排序 
	printf("快速排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	QuickSort(b,0,size - 1);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	//测试4 - 堆排序 
	printf("堆排序\t");
	memcpy(b,a,sizeof(a));
	start = clock();
	HeapSort(b,size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	printf("\n");

}

int vs_main() {
	srand((int)time(0));
	REP(TIME)
		Do();
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