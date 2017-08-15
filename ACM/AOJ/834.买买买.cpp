/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 1000000005;

void extend_Euclid(int a, int b, int &x, int &y){  
    if(b == 0)  
    {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a % b, x, y);  
    int tmp = x;  
    x = y;  
    y = tmp - (a / b) * y;  
}  
  

int CRT(int a[],int m[],int n){  
    int M = 1;  
    int ans = 0;  
    for(int i=1; i<=n; i++)  
        M *= m[i];  
    for(int i=1; i<=n; i++)  
    {  
        int x, y;  
        int Mi = M / m[i];  
        extend_Euclid(Mi, m[i], x, y);  
        ans = (ans + Mi * x * a[i]) % M;  
    }  
    if(ans < 0) ans += M;  
    return ans;  
}  



int price[] = {1234567,123456,1234};

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
        LL n;
        cin >> n;
        bool flag = false;

        int max_fz = n / price[0];
        for(int i=0;i<=max_fz;i++){
            int max_cz = (n-i*price[0]) / price[1];
            for(int j=0;j<=max_cz;j++)
                if(!((n-i*price[0]-j*price[1]) % price[2])){
                    flag = true;
                    break;
                }
        }
        cout << (flag?"YES":"NO") << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}