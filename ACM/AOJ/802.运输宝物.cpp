#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <memory>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
 
#define debug 0
 
/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#define REP(n) for(int o=0;o<n;o++)
const int maxn=100005;
const int maxk=50005;
 
int n,k;
int s[maxn];
 
bool Do(){
    if(scanf("%d%d",&n,&k)==EOF)
        return false;
    REP(n)
        scanf("%d",&s[o]);
 
    if(k>=n){
        printf("%d\n",s[n-1]);
        return true;
    }
 
    int w[maxk];
    REP(k){
        w[o]=s[n-k+o];
    }
 
    #if debug
    REP(n)
        printf("s[%d]=%d\n",o,s[o]);
    printf("\n");
    REP(k)
        printf("w[%d]=%d\n",o,w[o]);
    printf("\n");
    #endif // debug
 
    for(int i=0;i<n-k;i++){
        w[i]+=s[n-k-1-i];
    }
 
 
 
    int M=w[0];
    REP(k){
        M=max(M,w[o]);
    }
    #if debug
    REP(k)
        printf("w[%d]=%d\n",o,w[o]);
    #endif // debug
    printf("%d\n",M);
 
    return true;
 
}
 
 
 
int main(){
    #if debug
    freopen("in.txt","r",stdin);
    #endif
    while(Do());
    return 0;
}