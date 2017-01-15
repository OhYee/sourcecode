//**//
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


    #ifdef debug
    printf("Time:%.3f s.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}