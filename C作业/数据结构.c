#include "stdafx.h"
//====================================================================
/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
*/
/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct Node {
	int n;
	Node * next;
};
/*==============================================================
=============================第一题=============================
==============================================================*/
/*需要malloc头文件*/


/*删除所有大于x不大于y的节点*/
void delete_x_to_y(Node *it,int x,int y) {
	//前一节点
	Node *front = (Node*)malloc(sizeof(Node));
	Node *temp = front;
	while(it != NULL) {
		/*后移*/
		if(it->n <= x) {
			front = it;
			it = it->next;
		}
		/*需要删除的*/
		if(it->n > x) {
			front->next = it->next;
			free(it);
			it = front->next;
			continue;
		}
		/*大于y，由于链表有序，所以以后都符合要求*/
		if(it->n >= y)
			break;
	}
	//删除临时节点
	free(temp);
}
/*==============================================================
================================================================
==============================================================*/


/*==============================================================
=============================第二题=============================
==============================================================*/
/*需要malloc头文件*/

/*在值为y之前的节点插入值为x的节点,返回插入后链表的第一个节点的地址*/
Node* insert_front(Node *it,int x,int y) {
	Node *head = it;
	//建立节点
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->n = x;

	//如果遇到第一个就符合要求的特殊情况
	if(it->n == y) {
		temp->next = it;
		return temp;
	}
	//从第一个的下一个开始找符合要求的节点
	while(it->next != NULL) {
		if(it->next->n == y) {
			temp->next = it->next;
			it->next = temp;
			break;
		}
		it = it->next;
	}
	return head;
}
/*==============================================================
================================================================
==============================================================*/

/*==============================================================
=============================第三题=============================
==============================================================*/
/*需要math头文件*/

/*将最小的节点接到最前面，返回操作的链表第一个节点地址*/
Node* move_min(Node *head) {
	Node *min = head;
	Node *it = head;
	Node *front=NULL,*min_front=NULL;

	while(it != NULL) {
		if(it->n < min->n) {
			min = it;
			min_front = front;
		}
		front = it;
		it = it->next;
	}

	if(min != head) {
		min_front->next = min->next;
		min->next = head;
		head = min;
	}
	return head;
}
/*==============================================================
================================================================
==============================================================*/

/*输出链表*/
void print(Node *head) {
	Node *it = head;
	while(it != NULL) {
		printf("%d ",it->n);
		it = it->next;
	}
	printf("\n");
}

int vs_main() {
	Node *n = (Node *)malloc(10 * sizeof(Node));
	Node *head = n;
	//编译器需设置至C99及以上标准
	for(int i = 0;i < 9;i++) {
		n[i].next = &n[i + 1];
		n[i].n = i + 1;
	}
	n[9].n = 0;
	n[9].next = NULL;
	printf("初始链表\n");
	print(head);

	printf("最小的放最前面\n");
	head=move_min(head);
	print(head);

	printf("删除3-6\n");
	delete_x_to_y(head,3,6);
	print(head);

	printf("在8前插入1\n");
	head=insert_front(head,1,8);
	print(head);

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