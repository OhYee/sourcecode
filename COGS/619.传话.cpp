#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))
/*
#############################################################
*/
const int maxn=1001;
int n,m;
class Tree{
    private:
    struct Node{
        set<int> to;
    };
    vector<Node>node;
    bool d[maxn];//访问标记

    void bfs(int i){
        if(d[i])return;//已访问过
        d[i]=true;
        set<int>& next=node[i].to;
        set<int>::iterator it;
        it=next.begin();
        REP(next.size()){
            bfs(*it);
            it++;
        }
    }

    public:
    void build(int n){
        node.resize(n+1);//人的编号为1-n
    }
    void add(int from,int to){
        node[from].to.insert(to);
        #if debug
        cout<<"     关系构建 "<<from<<"认识"<<to<<endl;
        #endif // debug
    }
    bool message(int i){
        memset(d,0,sizeof(d));

        set<int>& next=node[i].to;
        set<int>::iterator it;
        it=next.begin();
        REP(next.size()){
            bfs(*it);
            it++;
        }

        return d[i];
    }
};
Tree T;
int main(){
    freopen("messagez.in","r",stdin);
    #if !debug
    freopen("messagez.out","w",stdout);
    #endif // debug

    cin>>n>>m;
    #if debug
    cout<<"人数读入:"<<n<<"   关系数读入:"<<m<<endl;
    #endif // debug

    T.build(n);


    REP(m){
        int from,to;
        cin>>from>>to;
        T.add(from,to);
    }

    #if debug
    cout<<"关系构建完成"<<m<<endl;
    #endif // debug

    REP(n){
        #if debug
        cout<<"尝试从"<<o+1<<" 开始传信"<<endl;
        #endif // debug
        cout<<(T.message(o+1)==true?"T":"F")<<endl;
    }


}

