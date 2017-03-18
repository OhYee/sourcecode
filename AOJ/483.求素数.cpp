//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100005;
bool is_prime[maxn+1];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;

    int m=sqrt(n+0.5);
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i<=m;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i]==true){
            cout<<i<<endl;
        }
    }


    
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}