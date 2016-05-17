//数据结构实验测试
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
本次实验测试二叉树的基本数据结构和算法。
测试内容为：
1）实现按照先序顺序生成一棵二叉树（30分）
2）实现二叉树的中序遍历算法（10分）
3）实现二叉树的后序遍历算法（10分）
4）实现二叉树的层序遍历算法（10分）
4）实现二叉树的销毁算法（10分）
5）实现插入节点的算法（20分）
6）实现计算树深度的算法（10分）
*/

//提示：请将下面两个变量修改为你的姓名和学号
char* name = "张三";
char* id = "E10010001";

typedef enum {FALSE, TRUE} BOOL;

#define BOOL bool
#define TRUE true;
#define FALSE false;

/*二叉树的结构定义*/
typedef struct _BiTreeNode
{
	char data;
	struct _BiTreeNode *lchild;//左孩子
	struct _BiTreeNode *rchild;//右孩子
	struct _BiTreeNode *parent;//双亲
}BiTNode,*BiTree;

//提示：根据先序输入的元素序列S,建立二叉树的存储结构T
//参数idx表示当前遍历的序列S中字符的下标，每次生成一
//个节点之后，要修改idx，使它指示下一个字符
//注意：S中的字符'#'表示空树。
//注意：要建立双亲指针。
BOOL CreateBiTree(BiTree *T, char* S, int *idx)
{
	if(T==0 || S==0) return FALSE;
	if( strlen(S) <= (*idx) ) return FALSE;
	//请在下面补充你的代码
	
	if(S[*idx]=='#'){
		(*T)=NULL;
		(*idx)++;
	}else{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = S[(*idx)++];
		(*T)->lchild = 0;
		(*T)->rchild = 0;
		(*T)->parent = 0;

		CreateBiTree(&((*T)->lchild),S,idx);
		if((*T)->lchild)
			(*T)->lchild->parent=*T;
		CreateBiTree(&((*T)->rchild),S,idx);
		if((*T)->rchild)
			(*T)->rchild->parent=*T;
	}

	return TRUE;
}

//销毁二叉树，要释放所有节点的内存
void DestroyBiTree(BiTree *T)
{
	if((*T)==0) return;
	
	//递归地释放树中节点的内存：
	//首先释放左右子树的内存，然后释放树根的内存
	//请在下面补充你的代码
	
	DestroyBiTree(&(*T)->lchild);
	DestroyBiTree(&(*T)->rchild);
	free(*T);

	*T = 0;
}
void Visit(char data)
{
	putchar(data);
}

//先序遍历一颗二叉树
void PreOrderTraverse(BiTree T, void(*visit)(char data))
{
	if(T==0) return;
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit);
}
//中序遍历
void InOrderTraverse(BiTree T, void(*visit)(char data))
{
	if(T==0) return;
	//请在下面补充你的代码
	InOrderTraverse(T->lchild,visit);
	visit(T->data);
	InOrderTraverse(T->rchild,visit);

}

//后序遍历
void PostOrderTraverse(BiTree T, void(*visit)(char data))
{
	if(T==0) return;
	//请在下面补充你的代码
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	visit(T->data);

}

/*队列数据结构，用于层序遍历二叉树*/
#define MAX_ELEMENTS		100
typedef struct
{
	BiTree elem[100];
	int front;
	int rear;
}Queue;

void InitQueue(Queue *Q)
{
	if(Q)
	{
		Q->rear = 0;
		Q->front = 0;
	}
}
BOOL IsEmpty(Queue* Q)
{
	if(Q) return Q->rear==Q->front;
	return TRUE;
}
BOOL IsFull(Queue* Q)
{
	if(Q)	 return (Q->rear+1)%MAX_ELEMENTS ==Q->front;
	return FALSE;
}

BOOL EnQueue(Queue *Q,BiTree t)
{
	if(Q==0 || IsFull(Q)) return FALSE;
	Q->elem[Q->rear] = t;
	Q->rear = (Q->rear+1)%MAX_ELEMENTS;
	return TRUE;
}
BiTree DeQueue(Queue *Q)
{
	if(Q==0) return 0;
	BiTree e = Q->elem[Q->front];
	Q->front = (Q->front+1)%MAX_ELEMENTS;
	return e;
}
//用队列实现层序遍历二叉树
void LevelOrderTraverse(BiTree T,void(*visit)(char data))
{
	if(T==0) return;
	Queue Q;
	InitQueue(&Q);
	//请在下面补充你的代码
	EnQueue(&Q,T);
	while(!IsEmpty(&Q)){
		BiTree k = DeQueue(&Q);
		visit(k->data);
		if(k->lchild)
			EnQueue(&Q,k->lchild);
		if(k->rchild)
			EnQueue(&Q,k->rchild);
	}

}

//计算树的深度
int TreeDepth(BiTree T)
{
	#define MAX(a,b) ((a)>(b)?(a):(b))
	if(T==0)
		return 0;
	return MAX(TreeDepth(T->lchild),TreeDepth(T->rchild))+1;
}
//获取数据为c的节点的指针，作为返回值，
//如果没有数据为c的节点，返回0
BiTree GetNode(BiTree T, char c)
{
	if(T==0) return 0;
	//请在下面补充你的代码

	if(T->data == c)
		return T;
	BiTree k;
	k = GetNode(T->lchild,c);
	if(k)
		return k;
	k = GetNode(T->rchild,c);
	if(k)
		return k;
	return 0;

}

//获取数据为c的节点的双亲节点
BiTree GetParent(BiTree T, char c)
{
	BiTree p = GetNode(T,c);
	if(p) return p->parent;
	return 0;
}
//插入孩子节点：
//为数据为c的节点插入一个孩子
//tag=0表示插入节点为左孩子，tag=1表示插入为右孩子
//原有的左、右孩子分别变为新孩子的左、右孩子
BOOL InsertChild(BiTree T, char c, int tag, char data)
{
	if(T==0) return FALSE;
	//获取数据为c的节点,该节点为新插入节点的双亲节点
	BiTree P = GetNode(T,c);

	if(P==0) return FALSE;

	//请在下面补充你的代码
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data=data;
	temp->parent = P;

	if(tag==0){
		temp->lchild=P->lchild;
		temp->rchild=0;
		if(temp->lchild)
			temp->lchild = P->lchild;

		P->lchild=temp;
	}else{
		temp->rchild=P->rchild;
		temp->lchild=0;
		if(temp->rchild)
			temp->rchild = P->rchild;

		P->rchild=temp;
	}

	return TRUE;
}

int main(int argc, char* argv[])
{
	printf("学号:%s, 姓名: %s\n",id,name);

	BiTree T1 = 0;
	char* S1 = "ABD##E##C#FG###";
	int idx = 0;
	CreateBiTree(&T1,S1,&idx);
	int d1 = TreeDepth(T1);
	printf("T1深度: %d\n",d1);

	printf("先序遍历序列：");
	PreOrderTraverse(T1,Visit);
	printf("\n参照先序序列：ABDECFG\n\n");

	printf("层序遍历序列：");
	LevelOrderTraverse(T1,Visit);
	printf("\n参照层序序列：ABCDEFG\n\n");

	printf("中序遍历序列：");
	InOrderTraverse(T1,Visit);
	printf("\n参照中序序列：DBEACGF\n\n");

	printf("插入A的右孩子M：\n");
	InsertChild(T1,'A',1,'M');

	printf("插入M的右孩子L：\n");
	InsertChild(T1,'M',1,'L');

	printf("插入M的左孩子P：\n");
	InsertChild(T1,'M',0,'P');

	printf("插入E的左孩子X：\n");
	InsertChild(T1,'E',0,'X');

	printf("插入Y的右孩子X：\n");
	InsertChild(T1,'Y',1,'X');

	printf("中序遍历序列：");
	InOrderTraverse(T1,Visit);
	printf("\n参照中序序列：DBXEAPMLCGF\n\n");

	printf("后序遍历序列：");
	PostOrderTraverse(T1,Visit);
	printf("\n参照后序序列：DXEBPGFCLMA\n\n");

	printf("层序遍历序列：");
	LevelOrderTraverse(T1,Visit);
	printf("\n参照层序序列：ABMDEPLXCFG\n\n");

	d1 = TreeDepth(T1);
	printf("T1深度: %d\n",d1);

	DestroyBiTree(&T1);
	d1 = TreeDepth(T1);
	printf("T1深度: %d\n",d1);

	putchar('\n');
	BiTree T2 = 0;
	char* S2 = "RAD#E##B#CFG#H#K###";
	idx = 0;
	CreateBiTree(&T2,S2,&idx);
	int d2 = TreeDepth(T2);
	printf("T2深度: %d\n",d2);

	printf("先序遍历序列：");
	PreOrderTraverse(T2,Visit);
	printf("\n参照先序序列：RADEBCFGHK\n\n");

	printf("层序遍历序列：");
	LevelOrderTraverse(T2,Visit);
	printf("\n参照层序序列：RADBECFGHK\n\n");

	printf("后序遍历序列：");
	PostOrderTraverse(T2,Visit);
	printf("\n参照后序序列：EDKHGFCBAR\n\n");

	printf("插入R的右孩子M：\n");
	InsertChild(T2,'R',1,'M');

	printf("插入M的右孩子L：\n");
	InsertChild(T2,'M',1,'L');

	printf("插入M的左孩子P：\n");
	InsertChild(T2,'M',0,'P');

	printf("插入X的左孩子Y：\n");
	InsertChild(T2,'X',0,'Y');

	printf("后序遍历序列：");
	PostOrderTraverse(T2,Visit);
	printf("\n参照后序序列：EDKHGFCBAPLMR\n\n");

	printf("层序遍历序列：");
	LevelOrderTraverse(T2,Visit);
	printf("\n参照层序序列：RAMDBPLECFGHK\n\n");

	d2 = TreeDepth(T2);
	printf("T2深度: %d\n",d2);

	DestroyBiTree(&T2);
	d2 = TreeDepth(T2);
	printf("T2深度: %d\n",d2);

	putchar('\n');
	return 1;
}
