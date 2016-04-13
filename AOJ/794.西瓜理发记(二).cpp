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

int N;
/*
 
int ans=999999;
void DFS(int n,int cnt){
    //printf("%d %d\n",n,cnt);
    if(n==N)
        ans=min(cnt,ans);
    if(n+1==N)
        ans=min(cnt+1,ans);
    if(n>N)
        return ;
    DFS(2*n,cnt);
    DFS(2*(n+1),cnt+1);
    return;
}
*/
int niconiconi(int n){
    int cnt;
    for(cnt=0;n;n>>=1)
        cnt+=(n&1);
    return cnt;
}
 
bool Do(){
    if(scanf("%d",&N)==EOF)
        return false;
    //ans=999999;
    //DFS(1,1);
    printf("%d\n",niconiconi(N));
}
 
 
 
int main(){
    #if debug
    freopen("in.txt","r",stdin);
    #endif
    while(Do());
    return 0;
}