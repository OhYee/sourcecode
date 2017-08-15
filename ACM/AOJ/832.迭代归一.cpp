/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
const int maxn = 100005;
char s[100005];

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
        int ans = 0;
        scanf("%s",s);
        int size = strlen(s);
        int n = 0;
        bool flag = false;
        for(int i = 0;i < size;i++){
            n += s[i]-'0';
            if(flag)
                ans=1;
            if(!flag && s[i] - '0' > 0)
                flag = true;
        }

        while(n>=10){
            ans++;
            int t = 0;
            while(n){
                t += n%10;
                n /= 10;
            }
            n = t;
        }
        printf("%d\n",ans);
    }
 
    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}