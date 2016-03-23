#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
 
#define REP(n) for(int o=0;o<n;o++)
 
const int maxn = 1005;
int edge[maxn][maxn];
 
inline void road(int a,int b) {
    edge[a][++edge[a][0]] = b;
    edge[b][++edge[b][0]] = a;
    //printf("     %d %d\n",a,b);
}
 
bool Do() {
    int n,m;
    if(scanf("%d%d",&n,&m) == EOF)
        return false;
    for(int i = 1;i <= n;i++)
        edge[i][0] = 0;
    REP(m) {
        int a,b;
        scanf("%d%d",&a,&b);
        road(a,b);
    }
    bool can[maxn] = {0};
     
    int cnt = 0;
 
    queue<int> Q;
    Q.push(1);
 
    while(!Q.empty()) {
        int top = Q.front();
        Q.pop();
        if(can[top])
            continue;
        can[top] = 1;
        REP(edge[top][0])
            Q.push(edge[top][o+1]);
    }
    /*
    printf("===\n");
    REP(n)
        printf("can[%d]=%d\n",o + 1,can[o + 1]);
        */
    while(1) {
        bool ok = true;
        REP(n) {
            if(!can[o + 1]) {
                road(1,o + 1);
                cnt++;
                Q.push(o + 1);
                while(!Q.empty()) {
                    int top = Q.front();
                    Q.pop();
                    if(can[top])
                        continue;
                    can[top] = 1;
                    REP(edge[top][0]) {
                        Q.push(edge[top][o+1]);
                    }
                }
                ok = false;
                break;
            }
        }
        if(ok)
            break;
    }
    printf("%d\n",cnt);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}