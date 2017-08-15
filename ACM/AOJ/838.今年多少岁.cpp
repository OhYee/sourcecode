/*/
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
    cin >> T;
    while(T--){
        int y,m,d;
        cin >> y >> m >> d;

        int ans = y - 1937 - 1;
        if(m > 7 || (m == 7 && d >= 7))
            ans++;
        cout << ans << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}