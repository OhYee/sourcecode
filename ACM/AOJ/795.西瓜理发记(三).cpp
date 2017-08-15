#include<cstdio>
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

const int maxn = 1e5+5;

struct path{
    int u,v;
    bool k;
    path(int a,int b,int c):u(a),v(b),k(c){}
};
struct Node{
    list<path> children;
    int father; 
};

Node node[maxn];

int dfs(int t){
    int ans=0;
    for(list<path>::iterator it=node[t].children.begin();it!=node[t].children.end();it++){
        int tt = it->v;
        if(tt == node[t].father)
            continue;
        node[tt].father = t;
        ans += max(dfs(tt),(int)it->k);
    }
    return ans;
}
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
     
    int n;
    while(cin >> n){
        for(int i=1;i<=n;i++){
            node[i].father=-1;
            node[i].children.clear();
        }
             
        int a,b,c;
        for(int i=1;i<n;i++){
            cin>>a>>b>>c;
            node[a].children.push_back(path(a,b,c-1));
            node[b].children.push_back(path(b,a,c-1));
        }   
        cout << dfs(1) << endl;
    }
}