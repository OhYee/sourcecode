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

int N,M;//N水果数 M钱数
const int maxn = 15;
const int maxm = 205;
long long d[maxm];
int price[maxn];

bool Do() {
    if(scanf("%d%d",&N,&M) == EOF)
        return false;
    REP(N)
        scanf("%d",&price[o + 1]);

    //d[i][j]=d[i-1][j]+d[i][j-price[i]];
    /*买前i件物品，用去j元钱时，方案总数d[i][j]为
        (买上一个物品用去j元钱d[i-1][j])
            与
        (再买一个这个物品d[i][j-price[i]])的和加1
        
        (j-price[i])/price[i] 为第i件买的个数
    */
    
    memset(d,0,sizeof(d));
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= M;j++)
            d[j] +=  ((j - price[i] >= 0) ? (d[j - price[i]] + 1) : 0);

    printf("%lld\n",d[M]);
    return true;
}

int main() {
    while(Do());
    return 0;
}