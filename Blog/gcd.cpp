#include <cstdio>

int gcd(int a,int b,int &x,int &y){
    if(!b){x=1;y=0;}
    else{gcd(b,a%b,y,x);y-=x*(a/b);}
}

int main(){
    int x,y,d;
    gcd(3,6,x,y);printf("\n");
    gcd(1,2,x,y);printf("\n");
    gcd(2,5,x,y);printf("\n");
    return 0;
}
