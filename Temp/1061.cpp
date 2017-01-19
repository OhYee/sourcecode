//**//
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool exgcd(int a,int b,int &x,int &y,int c){
    if(!b){
        if(c%a==0){
            x=c/a;
            y=0;
        }else{
            return false;
        }
    }else{
        if(!exgcd())
            return false;
        y-=

        if(!exgcd(b,a%b,s,t,c))
            return false;
        y=s-(a/b)*t;
    }
    return true;
}

int main() {
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    //求解 (m-n)X ≡ (y-x) mod L


    #ifdef debug
    printf("Time:%.3f s.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}