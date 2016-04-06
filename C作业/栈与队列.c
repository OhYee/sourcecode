#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
#define Status int
#define FALSE 0
#define TRUE 1

#define Element char

//结点
struct Node {
	Element elem;
	Node * next;
};


//LinkStack

struct LinkStack {
	Node * top;
	int size;
};

//初始化栈
Status InitStack(LinkStack *S) {
	S->top = NULL;
	S->size = 0;
	return TRUE;
}

//入栈操作
Status Push(LinkStack *S,Element e) {
	//栈满
	if(S->size == MAXSIZE)
		return FALSE;
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->elem = e;
	temp->next = S->top;
	S->top = temp;
	S->size++;
	return TRUE;
}

//判断栈空 
Status IsEmpty(LinkStack *S) {
	return !(S->size);
}

//出栈操作
Status Pop(LinkStack *S) {
	//栈空
	if(IsEmpty(S))
		return FALSE;
	Node *temp = S->top;
	S->top = temp->next;
	free(temp);
	S->size--;
	return TRUE;
}

//取栈顶元素 
Status Top(LinkStack *S,Element *e) {
	if(IsEmpty(S))
		return FALSE;
	*e = S->top->elem;
	return TRUE;
}

//销毁栈
Status Destory(LinkStack *S) {
	while(!IsEmpty(S)) {
		S->Pop(S);
	}
	return TRUE;
}

//清空栈
Status Clear(LinkStack *S) {
	S->size = 0;
	S->top = NULL;
	return TRUE;
}

//打印
void Print(LinkStack* S) {
	Node *it = S->top;
	while(it != NULL) {
		printf("%c\n",it->elem);
		it = it->next;
	}
}


//LinkQueue
struct LinkQueue {
	Node *front;
	Node *rear;
};

//初始化队列
Status InitQueue(LinkQueue *Q) {
	Node *temp = (Node*)malloc(sizeof(Node));
	Q->front = Q->rear = temp;
	return TRUE;
}

//返回是否为空队列
Status EmptyQueue(LinkQueue *Q) {
	return !(Q->front == Q->rear);
}

//插入
Status EnQueue(LinkQueue *Q,Element e) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->elem = e;
	temp->next = NULL;
	Q->rear->next = temp;
	Q->rear = temp;
	return TRUE;
}

//销毁队列
Status DestoryQueue(LinkQueue *Q) {
	Node *it ;
	while(Q->front != Q->rear) {
		it = Q->front;
		Q->front = Q->front->next;
		free(it);
	}
	free(Q->front);
	Q->front = Q->rear = NULL;
	return TRUE;
}

Status GetHead(LinkQueue* Q,Element *e) {
	if(EmptyQueue(Q))
		return FALSE;
	*e = Q->front->next->elem;
	return TRUE;
}

Status GetHead(LinkQueue* Q,Element *e) {
	if(EmptyQueue(Q))
		return FALSE;
	Node *temp = Q->front->next;
	*e = temp->elem;
	Q->front->next = temp->next;
	free(temp);
	return TRUE;
}

//打印
void QueuePrint(LinkQueue * Q) {
	if(EmptyQueue(Q))
		return;
	Node *it = Q->front->next;
	while(it != NULL) {
		printf("%c\n",it->elem);
		it = it->next;
	}
}

//队列长度
int QueueLength(LinkQueue *Q) {
	if(EmptyQueue(Q))
		return 0;
	Node *it = Q->front->next;
	int cnt = 0;
	while(it != NULL) {
		cnt++;
		it = it->next;
	}
	return cnt;
}
