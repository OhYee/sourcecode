#include<cstdio>
int main(){
        double ans=1;
        int n=1;

        while(ans<2){
                ans*=(365)/(365-n);
                n++;

        }
        printf("%d",n);
}
