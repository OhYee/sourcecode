/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a[8];
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
        for(int i=0;i<8;i++)
            cin >> a[i];
        int ans = min(min(a[1]*a[2]/a[6],a[3]*a[4]),a[5]/a[7]);
        //cout << a[1]*a[2]/a[6] << " " << a[3]*a[4] << " " << a[5]/a[7] << endl;

        cout << ans/a[0] << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
