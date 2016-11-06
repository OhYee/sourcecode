---
title: 排序算法
date: 2016-06-14 20:03:11
categories: 算法
tags: 
- 排序
---
排序算法是非常基础的算法  
这篇文章里记录了
- [插入排序](#插入排序)
 - [直接插入排序](#直接插入排序)
- [选择排序](#选择排序)
 - [简单选择排序](#简单选择排序)
 - [堆排序](#堆排序)
- [交换排序](#交换排序)
 - [冒泡排序](#冒泡排序)
 - [快速排序](#快速排序)
- [归并排序](#归并排序)
- [基数排序](#基数排序)
- [计数排序](#计数排序)
- [STL](#STL)
 - [qsort](#qsort)
 - [sort](#sort)
- [其他排序算法](#一些其他的奇怪的排序算法)
 - [睡眠排序](#睡眠排序)
<!--more-->  

# 插入排序

## 直接插入排序
对于一个数组，将数组中的数，按照大小插入到新数组的相应位置就是插入排序。  
对于其实现，有两种思路：
- [对内存进行优化](#对内存进行优化)
- [对时间进行优化](#对速度进行优化)

### 对内存进行优化
由于对于两个数组，他们真正有效的大小恰好就是一个数组的大小。  
因此，我们可以记录一个标记，来保存新数组和老数组的界限。  
不过，如果一个数应该插入到最前端，则其他数需要依次后移，因此在排序降序数时显得会非常慢。  

### 对速度进行优化
最擅长插入操作的必然是**链表**  
依次，我们可以使用链表来存储新数组。  
这样我们可以在较短的时间内完成插入。  
如果需要的话，再用O(n)把链表转化成数组就行。  

```cpp 对速度优化的直接插入排序
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
```
# 选择排序

## 简单选择排序

简单选择排序和直接插入排序比较像，只是其目的是不停把数组中最小的放到最前面  

``` cpp 简单选择排序
void SelectSort(int a[],int n) {
	for(int i = 0;i < n - 1;i++) {
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
```

## 堆排序

### 堆
堆是一种数据结构，其有以下特性
- 堆总是一棵完全二叉树
- 
 - 对于大根堆，堆的每一个结点，总有父节点不小于其子结点
 - 对于小根堆，堆的每一个结点，总有父节点不大于其子结点
 
 因此，堆有着一定的顺序
 
### 使用堆进行排序

根据堆天然的特性，对于一个大顶堆，我们可以直接将堆堆顶的元素放到数组尾部。 

也即，对于给定的一个数组，先把它转化成一个大顶堆，然后每次取堆顶元素与数组尾部的元素(需要标记位置)交换位置。  
从堆顶开始重新调整堆的结点使其满足大顶堆的特性。  

```cpp 堆排序
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
```

# 交换排序

## 冒泡排序

### 未优化的冒泡排序

经典的排序算法，易于实现。 

对于一组数据，从头开始循环，如果发现相邻的两个数，前面的数大于后面的数，则交换它们。  
这样，每一趟循环都能将最大的数放到最后。  

### 优化的冒泡排序
再分析冒泡排序的意义，我们可以知道，每一趟最后交换的位置就代表了该位置以后都已经排序完毕  
因此，我们可以记录下这一位置，每次循环只循环到上一次的位置即可。  
特别的，如果有一趟没有交换，则表示所有数据已排序完毕   

``` cpp 优化的冒泡排序
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
```

## 快速排序

一种非常快的交换排序。  
权衡空间和时间下非常好的一种排序算法。  

有以下经典的例子

> 省图书馆看见两个志愿者需要把还回来的一堆书按顺序入架，管理员大妈给他们教的时候说：“你先在这堆书里拉出一本来，把比它号小的扔到一边，比它大的扔到另一边，然后剩下两堆继续这样整，这样排的快！”这是我见识过最惊艳的算法使用，没有之一！

快速排序的思路是在待排序部分中取一个标准值，所有小于该标注的放在其左侧，大于标准值的放在其右侧。  
而后，分别对标准值左侧和右侧的部分进行快速排序。  

在交换位置时，可以先不交换，而是先找大于标准值的，当找到后，再去找小于标准值的，当找够一组时交换它们。  
这样可以省去了额外的数组，同时保证的算法的速度。  

``` cpp 快速排序
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
```


# 归并排序
与快速排序类似，归并排序也是一种使用递归的排序算法。  
对于一个数组，先对其左半部分进行归并排序，再对其右半部份进行归并排序。  
最后将排序完的两部分合到一起。  

```cpp 归并排序
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

void MergeSort(int a[],int l,int r) {
	if(l < r) {
		int mid = (l + r) / 2;
		MergeSort(a,l,mid);
		MergeSort(a,mid + 1,r);
		Merge(a,l,mid,r);
	}
}
```

# 基数排序
基数排序是一种特殊的桶排序。
其使用了类似**哈希(hash)**的思想。  
首先采取一定的方法，对数据进行分类，再在每类中继续分类，最终达到排序完成。

而基数排序，通过每一位的数进行排序。  
先按照个位数的大小进行排序，再按照十位数的大小进行排序…………  

不管是从高位开始排序，还是从低位开始，由于其之前的位已经按照顺序排好，因此当所有位排序完毕后就能得到排序好的数组。  

``` cpp 计数排序
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
```

# 计数排序
最后就是速度超级快，耗用内存超级大，适用范围非常小的计数排序(使用数组排序)。  

由于数组有着天然的顺序，我们可以用一个非常大的数组来记录数据，数组中的a<sub>i</sub>代表数字i在数据中有a[i]个

```cpp 计数排序
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
```

# STL 
## qsort
`qsort`使用的是快速排序，需要传入比较函数(`compare`)  

其参数应该是两个`void`型的指针,返回值是`int`小于0(不交换)或大于0(交换)  

如：
``` cpp 整形的compare
int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}
```

``` cpp char的compare
int cmp( const void *a , const void *b ){
    return *(char *)a - *(int *)b;
}
```

```cpp double的compare
int cmp( const void *a , const void *b ){
    return *(double *)a > *(double *)b ? 1 : -1;
}
```

结构体同上

## sort
`sort`是`qsort`的升级版，对于链表、向量都能够进行排序。  
根据数据量，还会有不同程度的优化。  

传入参数的时候，前两个参数是待排序数据的首地址指针和尾地址指针。  
对于结构体可以自行写自己的比较函数来进行排序  

由于非常广的适用性，因此在实际使用时，可能比不上特意为了具体情况而写的排序算法  
不过，与其自己写排序算法， 不如直接使用`sort`  

# 以上排序算法的比较

> 生成随机数      ：  
> 冒泡排序0.2470s :  
> 归并排序0.0040s :  
> 快速排序0.0020s :  
> 堆排序  0.0050s :  
> 基数排序0.0010s :  
> 计数排序0.0000s :  
> sort    0.0170s :  
> qsort   0.0050s :  
> 插入排序0.1090s :  
> 选择排序0.1190s :  
>   

可以看出，除了冒泡排序、插入排序、选择排序这些思路比较直接的排序外，其他排序都相差不过  

而当数据变得更大时，可以看出明显的差别  

> 生成随机数      ：  
> 冒泡排序29.7050s        :  
> 归并排序0.0440s :  
> 快速排序0.0200s :  
> 堆排序  0.0640s :  
> 基数排序0.0130s :  
> 计数排序0.0020s :  
> sort    0.2340s :  
> qsort   0.0590s :  
> 插入排序26.1630s        :  
> 选择排序12.1710s        :  

虽然`sort`在众多排序中表现的并不是很好，但是作为一个能够直接使用的函数，其在真正使用时还是值得一用的。  

测试用的代码
```cpp sort
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <memory> 
#include <algorithm>

#define random(x) (rand()%x) 
#define REP(n) for(int o=0;o<n;o++) 

const bool SHOW = 0;
const int size = 100000;
const int MAX = 1000000;
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
	for(int i = 0;i < n - 1;i++) {
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

int main() {
	srand((int)time(0));
	REP(TIME)
		Do();
	return 0;
}
```


# 一些其他的奇怪的排序算法

## 睡眠排序
对于一组数，有最大值max，则在max毫秒内完成排序的排序算法。

思路：  
使用多线程处理每一个数，每个线程的任务是休眠其对应的数的时间，而后输出  
这样在所有线程休眠完毕后，即可获得排序好的数据。  

