/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 55;
char score[maxn][maxn];
set<int> ans;

struct Node{
    int n;
    int w;
    Node(int a=-1,int b=-1):n(a),w(b){}
    bool operator < (const Node &rhs)const{
        return w > rhs.w;
    }
}node[maxn];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while(T--){
        ans.clear();
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> score[i];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                node[j] = Node(j,score[j][i]);
            sort(node,node+n);
            int t = node[0].w;
            for(int j=0;j<n;j++){
                if(t == node[j].w)
                    ans.insert(node[j].n);
                else
                    break;
            }
        }
        cout << ans.size() << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}