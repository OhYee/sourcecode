#include <stdio.h>
#include <malloc.h>

//˳�����洢�����ݵ�����
typedef int Element;
//˳������ʼʱ�ĳ���
#define InitSize 100
//˳����ÿ����չ�ĳ���
#define InsertSize 10
//ָ���±�λ�õ��ڴ�
#define point(n) (L->element + (n)*sizeof(Element))

struct SqList {
    //Ԫ��ָ��
    Element *element;
    //Ԫ�ظ���
    int Length;
    //˳��������
    int size;
};

//��ʼ��˳����
int InitList(SqList *L) {
    L->element = (Element*)malloc(InitSize*sizeof(Element));
    L->Length = 0;
    L->size = InitSize;
    //�ڴ�����ʧ��
    if(!L->element) {
        return -1;
    }
    return 1;
}

//����˳�������ͷ������ڴ�
void DestoryList(SqList *L) {
    free(L->element);
    L = NULL;
}

//�����ݲ��뵽posλ��֮ǰ
void ListInsert(SqList *L,int pos,Element e) {
    //�ڴ�����
    if(L->Length == L->size) {
        //���������ڴ�
        L->element = (Element*)realloc(L->element,(L->size + InsertSize)*sizeof(Element));
        //��������
        L->size += InsertSize;
    }

    //���ݺ���
    Element* it;
    it = point(L->Length + 1);
    while(it != point(pos)) {
        *it = *(it - sizeof(Element));
        it -= sizeof(Element);
    }
    //��ֵ
    *point(pos) = e;
    //��������
    L->Length++;
}

//ɾ��˳�����Ľڵ�
void ListDelete(SqList *L,int pos) {
    Element *it;
    it = point(pos);
    //����ǰ��
    while(it != point(L->Length - 1)) {
        *it = *(it + sizeof(Element));
        it += sizeof(Element);
    }
    //���ȼ���
    L->Length--;
}

//����ָ��Ԫ�ص��±�  δ�ҵ�����-1
int LocateElem(SqList *L,Element e) {
    int i;
    for(i = 0;i < L->Length;i++) {
        if(e == *point(i))
            return i;
    }
    return -1;
}

//����ָ���±���Ӧ��Ԫ�� �����������س�ʼλ��Ԫ��
Element GetElem(SqList* L,int pos) {
    if(pos >= L->Length || pos < 0)
        return *point(0);
    return *point(pos);
}

int ListLength(SqList *L) {
    return L->Length;
}

//�������ݱ�����
void ClearList(SqList *L) {
    L->Length = 0;
}

int main() {
    SqList L;
    printf("��ʼ��˳����\n");
    InitList(&L);
    printf("���� 1 2 3\n");
    ListInsert(&L,0,1);
    ListInsert(&L,1,2);
    ListInsert(&L,2,3);
    printf("�����±�1��Ӧ��Ԫ��\n");
    printf("%d\n",GetElem(&L,1));
    printf("����2��Ӧ���±�:%d\n",LocateElem(&L,2));
    printf("����˳��������:%d\n",ListLength(&L));
    LocateElem(&L,2);
    printf("ɾ���±�1��Ӧ��Ԫ��\n");
    ListDelete(&L,1);
    printf("�����±�1��Ӧ��Ԫ��\n");
    printf("%d\n",GetElem(&L,1));
    printf("����2��Ӧ���±�:%d\n",LocateElem(&L,2));
    printf("����˳��������:%d\n",ListLength(&L));
    printf("����\n");
    ClearList(&L);
    printf("����\n");
    DestoryList(&L);
    return 0;
}
