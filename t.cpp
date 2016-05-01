#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
   int member;
   struct node * pNext;
}Node,*pNode;

typedef struct stack
{
   pNode Top;
   pNode Bottom;
}Stack,*pStack;

int InitStack(pStack );
int Push(pStack,int);
void TraverseStack(pStack);
int Empty(pStack);
int Pop(pStack);
void Clear(pStack);

int main(void)
{
   Stack s;
   int i;
   int num;
   int data;
   int re_num;
   InitStack(&s);
   printf("璇疯緭鍏ヨ繘鏍堝厓绱犱釜鏁:\n");
   scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("绗%d涓暟锛",i+1);
        scanf("%d",&data);
        if (Push(&s,data))
        {
           continue;
        }
        else
        {
            printf("鎿嶄綔澶辫触\n");
            exit(-1);
        }
    }
    for(i=0;i<num;i++)
    {
      re_num=Pop(&s);
      printf("杈撳嚭鏍堝唴绗%d鍏冪礌涓猴細%d\n",i+1,re_num);}
      printf("璇ユ爤鐨勯暱搴︿负%d\n",num);
       if (Empty(&s) == 0)
         printf("鏍堜负绌篭n");
       else
         printf("鏍堜笉涓虹┖\n");

}
int InitStack(pStack ps)
{
    ps->Top = (pNode)malloc(sizeof(Node));
    if (NULL == ps->Top)
    {
        printf("鍔ㄦ佸垎閰嶅唴瀛樺け璐n");
        exit(-1);
    }
    else
    {
        ps->Bottom = ps->Top;
        ps->Top->pNext = NULL;
    }
    return 0;
}

int Push(pStack ps,int data)
{
     pNode pNew=(pNode)malloc(sizeof(Node));
     if(NULL == pNew)
     {
         return 0;
     }
    pNew->member = data;
    pNew->pNext = ps -> Top;
    ps->Top = pNew;

    return 1;
    }

void TraversesStack(pStack ps)
{
    pNode pNew = ps -> Top;
    while(pNew!=ps->Bottom)
    {
        printf("%d",pNew->member);
        pNew = pNew ->pNext;
    }
  return ;
  }
int Empty(pStack ps)
  {
    if(ps->Top == ps->Bottom)
        return 0;
  else
        return 1;
    }

  int Pop(pStack ps)
  {
      pNode pSwap =NULL;
      int return_val;
      if(Empty(ps))
      {
          exit(-1);
      }
  else
{
    return_val = ps->Top->member;
    pSwap =ps->Top;
    ps->Top = ps->Top->pNext;
    free(pSwap);
    return return_val;
    }
  }
