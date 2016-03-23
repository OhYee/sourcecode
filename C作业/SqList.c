#include <stdio.h>
#include <malloc.h>

//顺序表存储的数据的类型
typedef int Element;
//顺序表初始时的长度
#define InitSize 100
//顺序表每次拓展的长度
#define InsertSize 10
//指定下标位置的内存
#define point(n) (L->element + (n)*sizeof(Element))

struct SqList {
	//元素指针
	Element *element;
	//元素个数
	int Length;
	//顺序表长度
	int size;
};

//初始化顺序表
int InitList(SqList *L) {
	L->element = (Element*)malloc(InitSize*sizeof(Element));
	L->Length = 0;
	L->size = InitSize;
	//内存申请失败
	if(!L->element) {
		return -1;
	}
	return 1;
}

//销毁顺序表，释放所有内存
void DestoryList(SqList *L) {
	free(L->element);
	L = NULL;
}

//将数据插入到pos位置之前
void ListInsert(SqList *L,int pos,Element e) {
	//内存已满
	if(L->Length == L->size) {
		//重新申请内存
		L->element = (Element*)realloc(L->element,(L->size + InsertSize)*sizeof(Element));
		//表长增加
		L->size += InsertSize;
	}

	//数据后移
	Element* it;
	it = point(L->Length + 1);
	while(it != point(pos)) {
		*it = *(it - sizeof(Element));
		it -= sizeof(Element);
	}
	//赋值
	*point(pos) = e;
	//长度增加
	L->Length++;
}

//删除顺序表的节点
void ListDelete(SqList *L,int pos) {
	Element *it;
	it = point(pos);
	//数据前移
	while(it != point(L->Length - 1)) {
		*it = *(it + sizeof(Element));
		it += sizeof(Element);
	}
	//长度减少
	L->Length--;
}

//返回指定元素的下标  未找到返回-1
int LocateElem(SqList *L,Element e) {
	int i;
	for(i = 0;i < L->Length;i++) {
		if(e == *point(i))
			return i;
	}
	return -1;
}

//返回指定下标对应的元素 数据溢出返回初始位置元素
Element GetElem(SqList* L,int pos) {
	if(pos >= L->Length || pos < 0)
		return *point(0);
	return *point(pos);
}

int ListLength(SqList *L) {
	return L->Length;
}

//清空数据表数据
void ClearList(SqList *L) {
	L->Length = 0;
}

int main() {
	SqList L;
	printf("初始化顺序表\n");
	InitList(&L);
	printf("插入 1 2 3\n");
	ListInsert(&L,0,1);
	ListInsert(&L,1,2);
	ListInsert(&L,2,3);
	printf("输出下标1对应的元素\n");
	printf("%d\n",GetElem(&L,1));
	printf("输出2对应的下标:%d\n",LocateElem(&L,2));
	printf("输出顺序表长度:%d\n",ListLength(&L));
	LocateElem(&L,2);
	printf("删除下标1对应的元素\n");
	ListDelete(&L,1);
	printf("输出下标1对应的元素\n");
	printf("%d\n",GetElem(&L,1));
	printf("输出2对应的下标:%d\n",LocateElem(&L,2));
	printf("输出顺序表长度:%d\n",ListLength(&L));
	printf("清空\n");
	ClearList(&L);
	printf("销毁\n");
	DestoryList(&L);
	return 0;
}
