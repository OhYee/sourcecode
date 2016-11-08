#include <stdio.h>

typedef enum {
    TRUE = 1,FALSE = 0
} Bool;
/*
����ʵ����ϰ�������Ļ������ݽṹ���㷨��
ʵ������Ϊ��
1���������������ṹ
2��ʵ�ְ�������˳������һ�ö�����
3�����ö�ջʵ�ֶ����������������㷨
4��ʵ�ֶ������ĺ��������㷨

*/
//��ʾ���뽫�������������޸�Ϊ����������ѧ��
char* name = "��֥��";
char* id = "E41514043";

//��ʾ�������ɶ����������ݽṹ
typedef struct _BiTreeNode {
    //��������д���Ĵ���
    char data;
    _BiTreeNode *lchild;
    _BiTreeNode *rchild;
}BiTreeNode,*BiTree;

//��ʾ:�벹������ջ�����ݽṹ
//��ջ����ʵ�ַǵݹ������������㷨
//ջ�е�Ԫ��Ϊ�������ڵ�
typedef struct _StackNode {
    BiTree data;
    _StackNode *next;
}StackNode;

typedef struct _Stack {
    //��������д���Ĵ���
    _StackNode *top;
}*Stack;

//��ʾ��������ջ����Ҫ������
//1.����һ��ջ
Bool CreateStack(Stack *T) {
    T = NULL;
    return TRUE;
}
//2.����ջ��Ԫ��
Bool Pop(Stack T,StackNode *a) {
    if(T == NULL)
        return FALSE;
    a = T->top;
    T->top = T->top->next;
    return TRUE;
}
//3.ѹ��Ԫ��a��ջ��
Bool Push(Stack T,StackNode *a) {
    a->next = T->top;
    T->top = a;
    return TRUE;
}
//4.����ջ���ڴ�
void Destroy(Stack T) {
    StackNode * temp = T->top;
    while(T) {
        T->top = T->top->next;
        free(temp);
        temp = T->top;
    }
}
//5.�ж�ջ�Ƿ�Ϊ��
//ջ�շ���TRUE,���򷵻�FALSE
Bool Empty(Stack T) {
    if(T)
        return FALSE;
    else
        return TRUE;
}


//��ʾ����������������Ԫ������S,�����������Ĵ洢�ṹT
//ע�⣺S�е��ַ�'#'��ʾ������
void InsertBiTree(BiTree T,char* S,int *pos) {
    //������
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
    //������
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



//��ʾ������һ�����������ͷ������ڴ�
void DestroyBiTree(BiTree &T) {
    if(!T)
        return;
    DestroyBiTree(T->lchild);
    DestroyBiTree(T->rchild);
    free(T);
    T = NULL;
}

//���ڵ��ķ��ʺ���
void Visit(char a) {
    putchar(a);
}

//��ʾ����������������T,�ڵ����ʺ���Ϊvisit
Bool InOrderTraverse(BiTree T,void(*visit)(char a)) {
    if(!T)
        return FALSE;
    InOrderTraverse(T->lchild,visit);
    Visit(T->data);
    InOrderTraverse(T->rchild,visit);
    return TRUE;
}

//��ʾ����������������T���ڵ����ʺ���Ϊvisit
Bool PostOrderTraverse(BiTree T,void(*visit)(char a)) {
    if(!T)
        return FALSE;
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    Visit(T->data);
    return TRUE;
}

int main(int argc,char* argv[]) {
    printf("ѧ��:%s, ����: %s\n",id,name);
    BiTree T = 0;

    char* S1 = "ABC##DE#G##F###";
    char* In1 = "CBEGDFA";
    char* Post1 = "CGEFDBA";
    CreateBiTree(T,S1);

    printf("�����������У�");
    InOrderTraverse(T,Visit);
    printf("\n�����������У�%s\n\n",In1);

    printf("�����������У�");
    PostOrderTraverse(T,Visit);
    printf("\n���պ������У�%s\n\n",Post1);


    DestroyBiTree(T);

    char* S2 = "ABD#G###CE##FH###";//��ʦԭ��������ABD#G##CE##FH### ��������
    char* In2 = "DGBAECHF";
    char* Post2 = "GDBEHFCA";
    CreateBiTree(T,S2);

    printf("�����������У�");
    InOrderTraverse(T,Visit);
    printf("\n�����������У�%s\n\n",In2);

    printf("�����������У�");
    PostOrderTraverse(T,Visit);
    printf("\n���պ������У�%s\n\n",Post2);

    DestroyBiTree(T);

    return 1;
}