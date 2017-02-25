//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

const int maxn = 100005;
list<int> L[maxn*2];

int ans;

void dfs(int t,int d,int b){
    if(d==1){
        for(list<int>::iterator it = L[t].begin();it!=L[t].end();it++){
            dfs(*it,2,b);
        }
    }else if(d==2){
        for(list<int>::iterator it = L[t].begin();it!=L[t].end();it++){
            if(*it != b)
                dfs(*it,3,b);
        }
    }else{
        ans += L[t].size()-1;
    }
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=1;i<=a;i++)
            L[i].clear();
        for(int i=1;i<=b;i++)
            L[i+maxn].clear();
        
        for(int i=0;i<c;i++){
            int x,y;
            cin>>x>>y;
            L[x].push_back(y+maxn);
            L[y+maxn].push_back(x);
        }
        
        

        ans = 0;
        for(int i=1;i<=a;i++)
            dfs(i,1,i);
        for(int i=1;i<=b;i++)
            dfs(i+maxn,1,i+maxn);

        cout<<ans<<endl;
    }
    
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}