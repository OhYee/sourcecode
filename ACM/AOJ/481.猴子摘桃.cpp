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
    
    int n;
    while(cin>>n){
        int ans = 1;
        for(int i=0;i<n-1;i++){
            ans += 1;
            ans *= 2;
        }
        cout << ans << endl; 
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}