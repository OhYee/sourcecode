//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 505;
const double eps = 0.9;
int dp[maxn];

int toInt(double a){
    return (int) a+eps;
}
int up(double a){
    int b = toInt(a);
    return (a -(double)b > eps)?b+1:b;
}
int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    int n,p;
    cin >> n >> p;

    cout<<up(0.5)<<endl;
    cout<<up(1.0000001)<<endl;
    cout<<up(1.9999999)<<endl;
    cout<<up(2)<<endl;
    cout<<up(sqrt(6))<<endl;

    //将 2~n 分成互质的两组
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        cout<<i<<":"<<endl;
        dp[i] = (3 * dp[i-1]) % p;
        for(int j=2;j<i;j++){
            if(i%j==0){
                cout<<"\t-"<<j<<endl;
                dp[i] = (dp[i] - 2*dp[j] + p)% p;
            }
        }
        cout<<"\t"<<dp[i]<<endl;
    }
        
    
    cout << dp[n] << endl;
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}