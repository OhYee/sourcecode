#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
 
#define REP(n) for(int o=0;o<n;o++)
 
int N,M;
int price[15];
long long cnt;
 
void dfs(int m,int i) {
    if(m < 0)
        return;
    if(i >= 0)
        for(int j = m;j>=0;j-=price[i]) {
            /*
            REP(N - i)
                printf(" ");
            printf("%d(%d:%d)\n",j,i,price[i]);
            */
            dfs(j,i - 1);
        }
    else
        cnt++;
}
 
bool Do() {
    if(scanf("%d%d",&N,&M) == EOF)
        return false;
    REP(N)
        scanf("%d",&price[o]);
    //sort(price,price + N);
    cnt = -1;
    dfs(M,N - 1);
    printf("%lld\n",cnt);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}