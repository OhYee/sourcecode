//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 25;
char isLove[maxn][maxn];
bool isUsed[maxn];

int n;
int ans;

void init(){
    ans = 0;
    memset(isUsed,false,sizeof(isUsed));
}

//第 t 个人
void dfs(int t) {
    if (t > n) {
        ans++;
        return;
    }
    bool ok = false;
    for (int i = 1; i <= n; i++)
        if (isLove[t][i]=='1' && !isUsed[i]) {
            //for(int k=0;k<t;k++)
            //    printf(" ");
            //printf("%d choose %d\n",t,i);
            ok = true;
            isUsed[i] = true;
            dfs(t + 1);
            isUsed[i] = false;
        }
    if (!ok)
        return;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    while (scanf("%d",&n) != EOF) {
        init();
        for (int i = 1; i <= n; i++){
            scanf("%s",isLove[i]+1);
            //printf("%c%c%c%c%c\n",isLove[i][1],isLove[i][2],isLove[i][3],isLove[i][4],isLove[i][5]);
        }
        dfs(1);
        printf("%d\n",ans);
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}