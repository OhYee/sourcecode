#include <cstdio>

int main(){
    while(){
        bool is[maxn]={0};
        REP(n){
            int temp=read();
            is[temp]=!is[temp];
        }
        REP(n){
            if(is[o]){
                printf("d",o);
                break;
            }
        }
    }
}