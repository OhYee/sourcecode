/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5005;
string s[maxn];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n = 0;
    while(cin >> s[n++]);
    sort(s,s+n);

    int ans = s[0].size();
    for(int i=1;i<n;i++){
        int sz = s[i].size();
        for(int j=0;j<sz;j++){
            if(s[i-1][j] != s[i][j]){
                ans+=sz-j;
                break;
            }
        }
    }
    cout << ans+1 << endl;


    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
