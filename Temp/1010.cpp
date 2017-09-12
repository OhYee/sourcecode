#include <cstdio>
int main(){
    int T;
    scanf("%d",&T);
    int c=742;
    while(T--){
        printf("%s\n",c&1?"YES":"NO");
        c>>=1;
    }
    return 0;
}