#include <stdio.h>

 long long n,m,k,x,s,i;
 FILE *f;

 void row(){
     x += m;
     x = x % n;
     i++;
 }

long exp_mod(long a,long n,long b){
    long t;
    if(n==0) return 1%b;
    if(n==1) return a%b;
    t=exp_mod(a,n/2,b);
    t=t*t%b;
    if((n&1)==1) t=t*a%b;
    return t;
    }


 int main(){

     f=fopen("CircleNOIP2013.in","r");
     fscanf(f,"%d%d%d%d",&n,&m,&k,&x);
     fclose(f);

     //scanf("%d%d%d%d",&n,&m,&k,&x);

     //s= 10;
     /*
     for (i = 1;i<k;i++){
         s = (s * 10) %n;
     }*/




     k = exp_mod(10,k,n);


     for (i=0;i<k;){
         row();
         //printf(" %5d : %d %5d\n",i,x);
         }

     //printf("%d",x);

       f=fopen("CircleNOIP2013.out","w");
       fprintf(f,"%d",x);
       fclose(f);

     return 0 ;
 }