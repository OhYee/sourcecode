/*

                賢い　可愛い　エリチカ Хорошо  保佑无BUG
                μ's は　大好き
                みんな　は　大好き
*/

#include<stdio.h>


int main(){
    /*
    int a[10]={0};
    long long num;
    printf("Ener a number:");
    scanf("%lld",&num);
    printf("Repeat digtal\n");
    while(num){
        a[num%10]++;
        num/=10;
    }
    int i;
    for(i=0;i<=9;i++){
        if(a[i]>1)printf("Digtal %d repeat %d times\n",i,a[i]);
    }
    */
    int a[10][2];
    int i,j;
    for(i=0;i<=9;i++)for(j=0;j<=1;j++)a[i][j]=0;
    long long num;
    printf("Ener a number:");
    scanf("%lld",&num);
    printf("Repeat digtal\n");
    while(num){
        a[num%10][1]++;
        if(a[num%10][1]>1)a[num%10][0]=1;
        num/=10;
    }
    for(i=0;i<=9;i++){
        if(a[i][0]==1)printf("Digtal %d repeat %d times\n",i,a[i][1]);
    }




    return 0;
}

