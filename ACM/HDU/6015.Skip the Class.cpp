/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;

struct Node{
    string name;
    int value;
    bool operator < (const Node rhs)const{
        if(name == rhs.name)
            return value > rhs.value;
        return name < rhs.name;
    }
};

Node node[maxn];

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
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> node[i].name >> node[i].value;
        sort(node,node+n);

        string ls = "";
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ls == node[i].name){
                if(cnt == 2){
                    continue;
                }else{
                    cnt++;
                    ans += node[i].value;
                }
            }else{
                ls = node[i].name;
                cnt = 1;
                ans += node[i].value;
            }


        }
        cout << ans<<endl;
    }
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}