#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 15;

int ans = -1;
int n,v;
int w[maxn],c[maxn];

int dfs(int i,int value,int weight){
    if(weight<0)
        return max(ans,value-w[i-1]);
    if(i>=n)
        return value;
    return max(dfs(i+1,value+w[i],weight-c[i]),dfs(i+1,value,weight));
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&v);
        for(int i=0;i<n;++i)
            scanf("%d%d",&w[i],&c[i]);
        printf("%d\n",dfs(0,0,v));
    }
    return 0;
}
