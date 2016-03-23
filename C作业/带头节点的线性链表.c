#include "stdafx.h"
//====================================================================

//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//using namespace std;
//
//#define REP(n) for(int o=0;o<n;o++)

#include "stdio.h"
#include "malloc.h"

#define Status int
#define TRUE 1
#define FALSE 0

//结构体定义
struct LinkList {
	char elem;
	LinkList *next;
};

//初始化链表
void InitList(LinkList *L) {
	L->next = NULL;
}

//在前方插入
void PushFront(LinkList *L,char e) {
	LinkList *t = (LinkList*)malloc(sizeof(LinkList));
	t->elem = e;
	t->next = L->next;
	L->next = t;
}

//在后方插入
void PushBack(LinkList *L,char e) {
	LinkList *t = (LinkList*)malloc(sizeof(LinkList));
	t->elem = e;
	t->next = NULL;
	LinkList *it = L;
	while(it->next != NULL)
		it = it->next;
	it->next = t;
}

//打印
void Print(LinkList *L) {
	LinkList *it = L->next;
	while(it != NULL) {
		printf("%c\n",it->elem);
		it = it->next;
	}
}

//查找元素是否存在
Status Find(LinkList *L,char e) {
	LinkList *it = L->next;
	while(it != NULL) {
		if(it->elem == e)
			return TRUE;
		it = it->next;
	}
	return FALSE;
}

//删除元素
Status Delete(LinkList *L,int k) {
	LinkList *it = L->next;
	for(int i = 0;i < k - 1;i++) {
		if(it->next == NULL)
			return FALSE;
		it = it->next;
	}
	LinkList *t = it->next;
	it->next = t->next;
	free(t);
	return TRUE;
}

//递归删除链表
void DFS_Destory(LinkList *L) {
	if(L == NULL)
		return;
	DFS_Destory(L->next);
	free(L);
}

//不删除头节点
void Destory(LinkList *L) {
	DFS_Destory(L->next);
}

//返回链表长度
int Length(LinkList *L) {
	LinkList *it = L->next;
	int len = 0;
	while(it != NULL) {
		len++;
		it = it->next;
	}
	return len;
}

int vs_main() {
	printf("声明链表\n");
	LinkList L;
	//头节点的元素不会被显示
	L.elem = 'X';

	printf("初始化链表\n");
	InitList(&L);

	printf("链表长度为%d\n",Length(&L));

	printf("在前方插入a\n");
	PushFront(&L,'a');
	printf("在前方插入b\n");
	PushFront(&L,'b');
	printf("在前方插入c\n");
	PushFront(&L,'c');

	printf("链表打印:\n");
	Print(&L);

	printf("检测是否存在d\n");
	if(Find(&L,'d') == TRUE)
		printf("存在\n");
	else
		printf("不存在\n");

	printf("在后方插入d\n");
	PushBack(&L,'d');
	printf("在后方插入e\n");
	PushBack(&L,'e');
	printf("在后方插入f\n");
	PushBack(&L,'f');

	printf("链表打印:\n");
	Print(&L);

	printf("检测是否存在d\n");
	if(Find(&L,'d') == TRUE)
		printf("存在\n");
	else
		printf("不存在\n");

	printf("链表长度为%d\n",Length(&L));

	printf("删除下标为3的元素");
	Delete(&L,3);

	printf("链表打印:\n");
	Print(&L);


	printf("销毁链表:\n");
	Destory(&L);

	return 0;
}

//====================================================================
int main() {
	int start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	vs_main();
	printf("\n===================\n");
	printf("Time:%.5lf\n",double(clock() - start) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}