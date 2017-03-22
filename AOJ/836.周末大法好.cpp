/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
        int n;
        cin >> n;
        int mod = n % 7;

        int Min = 2 * (n / 7);
        if(mod > 5)
            Min += mod - 5;

        int Max = 2 * (n / 7) + min(mod,2);

        cout << Min << " " << Max << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}