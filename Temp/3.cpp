//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

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
        int n,m;
        string s;
        cin>>n>>m>>s;
        m/=2;
        dfs()
    }
    
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}