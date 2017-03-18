//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    double a=1.0,b=2.0;
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=b/a;
        b = a + b;
        a = b - a;
    }
    cout << fixed << setprecision(6) << ans << endl;
    
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}