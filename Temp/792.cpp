//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 15;
const int maxm = 1005;

int price[maxn];
int num[maxn];

int dp[maxm];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N,M;
    while(cin >> N >> M){
        for(int i=1;i<=N;i++)
            cin >> price[i];
        for(int i=1;i<=N;i++){
            int a,b;
            cin >> a >> b;
            num[i] = b - a;
            M -= a * price[i];
        }
 
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=N;i++){
            for(int j=M;j>0;j--)
                for(int k=1;k<=num[i];k++)
                    if(j - k * price[i] >= 0)
                        dp[j] += dp[j - k * price[i]];
            /*for(int j=0;j<=M;j++){
                cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[j]<<endl;
            }*/
        }
        int ans = 0;
        for(int i=0;i<=M;i++)
            ans += dp[i];
        cout << ans << endl;
    }
    
    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}