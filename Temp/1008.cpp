#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100005;

struct Edge{
    int v,w;
    Edge(int _v,int _w):v(_v),w(_w){}
};

int n;
int w[maxn];
int dp[maxn];       //以i为终点能达到的最大值
int dp2[maxn];      //以i为终点能达到的次大值
int dp_from[maxn];  //最大值来的方向
int parent[maxn];
vector<Edge> edges[maxn];

void dfs(int t){
    dp[t] = 0;
    dp[t] = 0;
    dp_from[t] = 0;
    for(auto e : edges[t]){
        if(parent[t] != e.v) {
            parent[e.v] = t;
            dfs(e.v);
            int m = dp[e.v]+w[e.v]-e.w-w[t];
            if(m > dp[t]){
                dp2[t] = dp[t];
                dp[t] = m;
                dp_from[t] = e.v;
            }
        }
    }
}
void dfs2(int t){
    for(auto e : edges[t]){
        if(parent[t] != e.v) {
            int p;
            if(dp_from[t] == e.v)
                p = dp2[t];
            else
                p = dp[t];
            
            int m = p + w[t] - e.w - w[e.v];
            dp[t] = max(dp[t],m);
        }
    }
}

void addEdge(int u,int v,int w){
    edges[u].push_back(Edge(v,w));
    edges[v].push_back(Edge(u,w));
}

void init(){
    for(int i=0;i<=n;++i)
        edges[i].clear();
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;++i){
            scanf("%d",&w[i]);
        }
        for(int i=1;i<n;++i){
            int u,v,wi;
            scanf("%d%d%d",&u,&v,&wi);
            addEdge(u,v,wi);
        }

        dfs(1);
        dfs2(1);
        int ans = 0;
        for(int i=1;i<=n;++i)
            ans = max(ans,dp[i]);

        printf("%d\n",ans);
    }
    return 0;
}