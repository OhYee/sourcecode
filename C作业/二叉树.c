#include <stdio.h>

typedef enum {
	TRUE = 1,FALSE = 0
} Bool;
/*
本次实验练习二叉树的基本数据结构和算法。
实验内容为：
1）建立二叉链表结构
2）实现按照先序顺序生成一棵二叉树
3）利用堆栈实现二叉树的中序遍历算法
4）实现二叉树的后序遍历算法

*/
//提示：请将下面两个变量修改为你的姓名和学号
char* name = "李芝璇";
char* id = "E41514043";

//提示：请完成二叉树的数据结构
typedef struct _BiTreeNode {
	//在下面填写你的代码
	char data;
	_BiTreeNode *lchild;
	_BiTreeNode *rchild;
}BiTreeNode,*BiTree;

//提示:请补充完整栈的数据结构
//该栈用于实现非递归的中序遍历算法
//栈中的元素为二叉树节点
typedef struct _StackNode {
	BiTree data;
	_StackNode *next;
}StackNode;

typedef struct _Stack {
	//在下面填写你的代码
	_StackNode *top;
}*Stack;

//提示：请完成栈的主要操作：
//1.创建一个栈
Bool CreateStack(Stack *T) {
	T = NULL;
	return TRUE;
}
//2.弹出栈顶元素
Bool Pop(Stack T,StackNode *a) {
	if(T == NULL)
		return FALSE;
	a = T->top;
	T->top = T->top->next;
	return TRUE;
}
//3.压入元素a到栈顶
Bool Push(Stack T,StackNode *a) {
	a->next = T->top;
	T->top = a;
	return TRUE;
}
//4.销毁栈的内存
void Destroy(Stack T) {
	StackNode * temp = T->top;
	while(T) {
		T->top = T->top->next;
		free(temp);
		temp = T->top;
	}
}
//5.判断栈是否为空
//栈空返回TRUE,否则返回FALSE
Bool Empty(Stack T) {
	if(T)
		return FALSE;
	else
		return TRUE;
}


//提示：根据先序输入的元素序列S,建立二叉树的存储结构T
//注意：S中的字符'#'表示空树。
void InsertBiTree(BiTree T,char* S,int *pos) {
	//左子树
	if(S[*pos] == '#') {
		T->lchild = NULL;
		(*pos)++;
	} else {
		BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
		temp->data = S[*pos];
		temp->lchild=temp->rchild = NULL;
		T->lchild = temp;
		(*pos)++;
		InsertBiTree(temp,S,pos);
	}
	//右子树
	if(S[*pos] == '#') {
		T->rchild = NULL;
		(*pos)++;
	} else {
		BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
		temp->data = S[*pos];
		temp->lchild = temp->rchild = NULL;
		T->rchild = temp;
		(*pos)++;
		InsertBiTree(temp,S,pos);
	}
}

void CreateBiTree(BiTree &T,char* S) {
	int pos = 0;
	if(S[pos] == '#') {
		T->lchild = T->rchild = NULL;
	} else {
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->lchild = T->rchild = NULL;
		T->data = S[pos];
		pos++;
		InsertBiTree(T,S,&pos);
	}
}



//提示：销毁一个二叉树，释放所有内存
void DestroyBiTree(BiTree &T) {
	if(!T)
		return;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	T = NULL;
}

//树节点的访问函数
void Visit(char a) {
	putchar(a);
}

//提示：中序遍历二叉树T,节点访问函数为visit
Bool InOrderTraverse(BiTree T,void(*visit)(char a)) {
	if(!T)
		return FALSE;
	InOrderTraverse(T->lchild,visit);
	Visit(T->data);
	InOrderTraverse(T->rchild,visit);
	return TRUE;
}

//提示：后序遍历二叉树T，节点访问函数为visit
Bool PostOrderTraverse(BiTree T,void(*visit)(char a)) {
	if(!T)
		return FALSE;
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	Visit(T->data);
	return TRUE;
}

int main(int argc,char* argv[]) {
	printf("学号:%s, 姓名: %s\n",id,name);
	BiTree T = 0;

	char* S1 = "ABC##DE#G##F###";
	char* In1 = "CBEGDFA";
	char* Post1 = "CGEFDBA";
	CreateBiTree(T,S1);

	printf("中序遍历序列：");
	InOrderTraverse(T,Visit);
	printf("\n参照中序序列：%s\n\n",In1);

	printf("后序遍历序列：");
	PostOrderTraverse(T,Visit);
	printf("\n参照后序序列：%s\n\n",Post1);


	DestroyBiTree(T);

	char* S2 = "ABD#G###CE##FH###";//老师原来给的是ABD#G##CE##FH### 错误数据
	char* In2 = "DGBAECHF";
	char* Post2 = "GDBEHFCA";
	CreateBiTree(T,S2);

	printf("中序遍历序列：");
	InOrderTraverse(T,Visit);
	printf("\n参照中序序列：%s\n\n",In2);

	printf("后序遍历序列：");
	PostOrderTraverse(T,Visit);
	printf("\n参照后序序列：%s\n\n",Post2);

	DestroyBiTree(T);

	return 1;
}