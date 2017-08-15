/*
#define debug
#include <ctime>
//*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long LL;

/*  
* 匈牙利算法邻接表形式  
* 使用前用init()进行初始化，给uN赋值
* 加边使用函数addedge(u,v) 
*/ 
const int MAXN = 2005;//点数的最大值 
const int MAXM = MAXN*MAXN;//边数的最大值 
struct Edge {
    int to,next; 
}edge[MAXM]; 

int head[MAXN],tot,uN; 
void init(int un) {
    uN = un;
    tot = 0;     
    memset(head,-1,sizeof(head)); 
} 

void addedge(int u,int v) {
    edge[tot].to = v; 
    edge[tot].next = head[u];     
    head[u] = tot++; 
} 

int linker[MAXN]; 
bool used[MAXN]; 
bool dfs(int u) {     
    for(int i = head[u]; i != -1;i = edge[i].next){
        int v = edge[i].to;
        if(!used[v]){
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])){
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary(){
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 0; u < uN;u++){//点的编号0~uN-1
        memset(used,false,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
} 

bool Solve(int n,int s){
    if(s<n) swap(s,n);
    if(n>1000) return false; 

    //匈牙利算法 求解二分图
    init(n);
    for(int i=1;i<=n;i++){
        LL t = (LL)i+(LL)s;
        for(int j=1;j<=n;j++){
            if(t%j==0)
                addedge(j-1,i-1);
        }
    }
    //cout<<hungary()<<endl;
    return hungary()==n;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif

    int T;
    cin>>T;
    for(int kase=1;kase<=T;kase++){
        int n,s;
        cin>>n>>s;
        cout<<"Case #"<<kase<<": "<<(Solve(n,s)?"Yes":"No")<<endl;
    }

    #ifdef debug
    printf("Time:%.3lfs\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}