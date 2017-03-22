/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    int T;
    scanf("%d",&T);
    while(T--){
        set<int> s;
        s.clear();

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            if(t <= n && t >= 1)
                s.insert(t);
        }
        printf("%d\n",n-s.size());
    } 

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}