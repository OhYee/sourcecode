#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

#define debug 0

const int maxn = 105;
const int INF=10000;
int n,m;
int mindis=INF;
int reasult;

struct Road{
    int from,to,dist;
};
struct Node{
    int weight,id;
    bool operator < (const Node& rhs)const{
        return weight>rhs.weight;
    }
};

struct Dijkstra{
    int PointNumber,RoadNumber;
    vector<Road>road;
    vector<int>road_id[maxn];
    int d[maxn];
    bool done[maxn];

    void init(int n){//初始化
        PointNumber=n;
        for(int i=0;i<n;i++){
            road_id[i].clear();
        }
        road.clear();
        #if debug
        cout<<"Dijkstra初始化完成"<<endl;
        #endif // debug
    }

    void AddRoad(int from,int to,int dist){
        for(int i=0;i<road_id[from].size();i++){//坑爹的去除重边
            if(road[road_id[from][i]].to==to){
                road[road_id[from][i]].dist=dist;
                return;
            }
        }
        road.push_back(Road{from,to,dist});//插入到路径里
        road_id[from].push_back(road.size()-1);//记录路径的id
        #if debug
       cout<<"路径 "<<from<<"-"<<to<<"距离"<<dist<<" 已载入，路径id "<<(road.size()-1)<<endl;
        #endif // debug
    }

    void dijkstra(int s){
        priority_queue<Node> Q;
        for(int i=0;i<PointNumber;i++){
            d[i]=INF;
        }
        d[s]=0;
        memset(done,false,sizeof(done));
        Q.push((Node){0,s});
        while(!Q.empty()){
            Node a=Q.top();
            Q.pop();
            #if debug
            cout<<"  尝试进入节点"<<a.id<<endl;
            #endif // debug
            if(done[a.id]==true)continue;
            done[a.id]=true;
            #if debug
            cout<<"     成功进入节点"<<a.id<<endl;
            #endif // debug
            for(int i=0;i<road_id[a.id].size();i++){
                Road& b=road[road_id[a.id][i]];
                #if debug
                cout<<"     连接节点"<<b.to<<endl;
                #endif // debug
                if(d[b.to]>d[a.id]+b.dist){
                    d[b.to]=d[a.id]+b.dist;
                    #if debug
                    cout<<"     节点"<<b.to<<"权值更新至"<<d[b.to]<<endl;
                    #endif // debug
                    Q.push((Node){d[b.to],b.to});
                }
            }
        }

    }

};
Dijkstra D;


int main(){
    freopen("djsa.in","r",stdin);
    #if !debug
    freopen("djsa.out","w",stdout);
    #endif // debug

    cin>>n>>m;
    #if debug
    cout<<"城市共"<<n<<"个，道路共"<<m<<"个"<<endl;
    #endif // debug

    D.init(n);

    for(int i=0;i<m;i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        D.AddRoad(x,y,dis);
        D.AddRoad(y,x,dis);
    }
    #if debug
    cout<<"地图载入完成"<<endl;
    #endif // debug

    for(int i=0;i<n;i++){
        #if debug
        cout<<"若建在"<<i<<endl;
        #endif // debug

        D.dijkstra(i);
        int maxdis=0;


        for(int j=0;j<n;j++){
            maxdis=(maxdis>=D.d[j]?maxdis:D.d[j]);
            #if debug
            cout<<" 节点"<<i<<"权值为"<<D.d[j]<<endl;
            #endif // debug
        }
        #if debug
        cout<<"若建在"<<i<<"则最远距离为"<<maxdis<<endl;
        #endif // debug

        if(mindis>maxdis){
            mindis=maxdis;
            reasult=i;
        }
    }

    #if debug
    cout<<"最近应建在"<<reasult<<endl;
    #endif // debug

    printf("%d",reasult);
    return 0;
}
