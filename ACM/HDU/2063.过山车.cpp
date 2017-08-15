///*
#define debug
#include <ctime>
//*/

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/*  
* 匈牙利算法邻接表形式  
* 使用前用init()进行初始化，给uN赋值
* 加边使用函数addedge(u,v) 
*/ 
const int MAXN = 1005;//点数的最大值 
const int MAXM = 1005;//边数的最大值 
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
    //cout<<"add"<<u<<" "<<v<<endl;
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

int Solve(int n,int girl,int boy){
    init(girl);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        addedge(u-1,v-1);
    }
    return hungary();
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif

    int n,girl,boy;
    while(cin>>n>>girl>>boy,n!=0)
        cout<<Solve(n,girl,boy)<<endl;

    #ifdef debug
    printf("Time:%.3lfs\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}