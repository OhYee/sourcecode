#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int d[3];// 0->1 0->2 1->2

int dfs(int deep,int pos,int cost){
    if(deep<=0)
        return cost;
    if(pos==0){
        return min(dfs(deep-1,1,cost+d[0]),dfs(deep-1,2,cost+d[1]));
    }else if(pos==1){
        return min(dfs(deep-1,0,cost+d[0]),dfs(deep-1,2,cost+d[2]));
    }else{
        return min(dfs(deep-1,0,cost+d[1]),dfs(deep-1,1,cost+d[2]));
    }
    return -1;
}

int main(){
    // freopen("in.txt","r",stdin);

    scanf("%d%d%d%d",&n,&d[0],&d[1],&d[2]);

    int ans;
    if(n>1){
        ans = dfs(1,0,0);
        ans += (n-2)*min(d[0],min(d[1],d[2]));
    }else{
        ans = dfs(n-1,0,0);
    }
    printf("%d\n",ans);

    return 0;
}
