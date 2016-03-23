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
 
const int maxn = 1005;
int w[maxn];
 
bool Do() {
    int n,m,T;
    if(scanf("%d%d%d",&n,&m,&T) == EOF)
        return false;
    REP(n)
        scanf("%d",&w[o+1]);
    REP(m) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        for(;l <= r;l++)
            w[l] += k;
    }
    REP(T) {
        int L,R;
        int ans=0;
        scanf("%d%d",&L,&R);
        for(;L <= R;L++)
            ans += w[L];
        printf("%d\n",ans);
    }
    return true;
}
 
int main() {
    while(Do());
    return 0;
}