#include <stdio.h>  
int main(){
    int a=1,b=10;
    do{
        b-=a;
        a++;
        printf("%d,%d\n",a,b);
    }while(b--<0);
    printf("%d,%d\n",a,b);
}