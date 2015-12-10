#include <stdio.h>
main( )
{ 
  int x,y,r1,r2;
  printf("请输入x,y的值：\n");
  scanf("%d%d",&x,&y);
  r1=x+y;
  r2=x-y;
  printf("求得的结果是：\n");
  printf("r1=%d\n",r1);
  printf("%d-%d=%d\n",x,y,r2);
}