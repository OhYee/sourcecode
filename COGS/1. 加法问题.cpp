#include<stdio.h>
float a, b;

long long plus(long long A,long long B){
  return ((A)&&(B))?(plus((A^B),(A&B)<<1)):(A^B);
}

int main(){
    FILE *f;
    f=fopen("aplusb.in","r");
    fscanf(f,"%f%f",&a,&b);
    fclose(f);

    f=fopen("aplusb.out","wb");
    fprintf(f,"%0.0f",(a+b));
    fclose(f);
    return 0;
}