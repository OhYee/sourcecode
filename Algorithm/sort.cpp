#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <memory> 
#include <algorithm>

#define random(x) (rand()%x) 
#define REP(n) for(int o=0;o<n;o++) 

const bool SHOW = 0;
const int size = 10000;
const int MAX = 100000;
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

	int Max = i;

	if(left<n && a[left]>a[Max]) {
		Max = left;
	}
	if(right<n && a[right]>a[Max]) {
		Max = right;
	}
	if(i != Max) {
		int temp = a[Max];
		a[Max] = a[i];
		a[i] = temp;
		AdjustHeap(a,Max,n);
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

//基数排序 LSD
void LSD(int a[],int n,int bit = 1) {
	int bucket[10];
	int rear[10];
	int *link = new int[n];
	int *next = new int[n];
	bool flag = false;
	for(int i = 0;i < 10;i++)
		bucket[i] = rear[i] = -1;
	for(int i = 0;i < n;i++)
		next[i] = -1;
	int pos = 0;
	for(int i = 0;i < n;i++) {
		int h = a[i] / bit % 10;
		if(h)
			flag = true;
		if(bucket[h] == -1) {
			bucket[h] = pos;
		} else {
			next[rear[h]] = pos;
		}
		rear[h] = pos;
		link[pos++] = a[i];
	}

	if(flag) {
		for(int bu = 0,pos = 0;pos < n;bu++) {
			int t = bucket[bu];
			while(t != -1) {
				a[pos++] = link[t];
				t = next[t];
			}
		}
		LSD(a,n,bit * 10);
	}
	delete[] next;
	delete[] link;
}

//计数排序
void ArraySort(int a[],int n) {
	int Min = a[0];
	int Max = a[0];
	for(int i = 0;i < n;i++) {
		(a[i] < Min) ? (Min = a[i]) : Min;
		(a[i] > Max) ? (Max = a[i]) : Max;
	}
	int *arr = new int[Max - Min + 1];
	for(int i = 0;i < Max - Min + 1;i++)
		arr[i] = 0;
	for(int i = 0;i < n;i++)
		arr[a[i] - Min]++;
	int pos = 0;
	for(int i = 0;i < Max - Min + 1 && pos < n;i++)
		for(int j = 0;j < arr[i];j++)
			a[pos++] = i + Min;
	delete[]arr;
}

//qsort
int comp(const void*a,const void*b) {
	return *(int*)a - *(int*)b;
}


//插入排序
void InsertSort(int a[],int n) {
	int *link = new int[n];
	int *next = new int[n];

	for(int i = 0;i < n;i++)
		next[i] = -1;

	int pos = 0;
	link[pos++] = a[0];

	int f = 0;
	for(int i = 1;i < n;i++) {
		if(link[f] > a[i]) {
			next[pos] = f;
			f = pos;
		} else {
			int t = f;
			while(next[t] != -1 && a[i] > link[next[t]])
				t = next[t];
			next[pos] = next[t];
			next[t] = pos;
		}
		link[pos++] = a[i];
	}

	int t = f;
	pos = 0;
	while(t != -1) {
		a[pos++] = link[t];
		t = next[t];
	}

	delete[] link;
	delete[] next;

}

//选择排序
void SelectSort(int a[],int n) {
	for(int i = 0;i < n-1;i++) {
		int Min = a[i + 1];
		int pos = i + 1;

		for(int j = i;j < n;j++) {
			if(Min > a[j]) {
				Min = a[j];
				pos = j;
			}
		}
		int temp = a[i];
		a[i] = a[pos];
		a[pos] = temp;
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

	//测试5 - 基数排序
	printf("基数排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	LSD(b,size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	//测试6 - 计数排序
	printf("计数排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	ArraySort(b,size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");


	//测试7 - sort排序
	printf("sort\t");
	memcpy(b,a,sizeof(a));
	start = clock();
	std::sort(b,b + size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");


	//测试8 - qsort排序
	printf("qsort\t");
	memcpy(b,a,sizeof(a));
	start = clock();
	std::qsort(b,size,sizeof(int),comp);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	//测试8 - 插入排序
	printf("插入排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	InsertSort(b,size);
	printf("%.4fs	:	",double(clock() - start) / CLOCKS_PER_SEC);
	if(SHOW)
		REP(size)
		printf("%d ",b[o]);
	if(memcmp(ans,b,sizeof(b)) != 0)
		printf("Wrong");
	printf("\n");

	//测试9 - 选择排序
	printf("选择排序");
	memcpy(b,a,sizeof(a));
	start = clock();
	SelectSort(b,size);
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