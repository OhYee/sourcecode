//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

const int maxn = 3005;
char s[1000][maxn];

int maxsize=0;
int n;

bool dfs(char *t){
    cout << " "<<t << endl;
    if(strlen(t) > maxsize)
        return true;
    for(int i = 0;i<n;i++){
        if(strstr(t,s[i]) == s[i])
            return false;
    }
    int sz = strlen(t);
    t[sz+1] = '\0';
    t[sz] = '0';
    if(dfs(t))
        return true;

    t[sz] = '1';
    if(dfs(t))
        return true;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(cin >> n){
        maxsize = 0;
        for(int i=0;i<n;i++){
            cin >> s[i];
            maxsize = max(maxsize,(int)strlen(s[i]));
        }
        char t[maxn]="0";
        cout << dfs(t)<< endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
