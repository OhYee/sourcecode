#include <cstdio>
#include<ctime>
int f(int a){
       int c;
       c=a+1;
       return c;
}
int main(){
                     double time_Start = (double)clock(); //开始时间
                     for(int i=1;i<=50000000;i++)f(i);
                                   double time_Finish = (double)clock(); //结束时间
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //输出
       return 0;
}
