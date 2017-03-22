//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

const int maxn = 1000;
const int maxm = 10000;

struct Path{
    int u,v,w;
    bool used;
    Path(int a=-1,int b=-1,int c=-1):u(a),v(b),w(c),used(false){}
}path[maxm];

struct Node{
    int n,w;
    Node(int a,int b):n(a),w(b){}
    bool operator < (const Node &rhs)const {
        return w < rhs.w;
    }
};

list<int> L[maxn];

int dis[maxn];
int last[maxn];

int dijkstra(int n){
    //init
    memset(dis,-1,sizeof(dis));
    memset(last,-1,sizeof(last));

    priority_queue<Node> Q;
    while(!Q.empty())
        Q.pop();
    
    Q.push(Node(1,0));
    dis[1] = 0;

    while(!Q.empty()){
        int t = Q.top().n;
        int dist = Q.top().w;
        Q.pop();

        if(t == n)
            return dist;

        for(list<int>::iterator it = L[t].begin();it!=L[t].end();it++){
            int p = *it;
            if(!path[p].used){
                int tt = path[p].u ^ path[p].v ^ t;
                int distt = dist+path[p].w;
                dis[tt] = (dis[tt]==-1)?distt:min(distt,dis[tt]);
                if(dis[tt] == -1 || distt < dis[tt]){
                    dis[tt]  = distt;
                    last[tt] = p;
                }
                Q.push(Node(tt,dis[tt]));
            }
        }
    }
    return dis[n];
} 

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);


    int n,m;
    while(cin >> n >> m){
        for(int i=1;i<=n;i++)
            L[i].clear();

        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            path[i] = Path(u,v,w);
            L[u].push_back(i);
            L[v].push_back(i);
        }
        cout << 1 << endl;
        int ans1 = dijkstra(n);
        cout << ans1 << endl;

        int ls = n;
        while(ls != 1){
            int p = last[ls];
            int nx = path[p].u ^ path[p].v ^ ls;
            path[p].used = true;
            ls = nx;
        }
        int ans2 = dijkstra(n);

        cout << ans1 << " " << ans2 <<endl;

    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}