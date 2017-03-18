/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
     
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) 
            break;
 
        while(n>=10){
            int t = 0;
            while(n){
                t += n%10;
                n /= 10;
            }
            n = t;
        }
        printf("%d\n",n);
    }
 
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}