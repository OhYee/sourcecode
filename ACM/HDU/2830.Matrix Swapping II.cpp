/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

const int maxn = 1005;

bool Map[maxn][maxn];

int H[maxn][maxn];

int Left[maxn];
int Right[maxn];

int MaxMatrix(bool Matrix[maxn][maxn],int n,int m,bool target) {
    memset(H,0,sizeof(H));
    memset(Left,0,sizeof(Left));
    memset(Right,0,sizeof(Right));

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(Matrix[i][j] == target) {
                if(Matrix[i - 1][j])
                    H[i][j] = H[i - 1][j] + 1;
                else
                    H[i][j] = 1;
            }
        }

    int Max = 0;
    for(int i = 1;i <= n;i++) {
        sort(H[i] + 1,H[i] + 1 + m);

        for(int j = 1;j <= m;j++) {
            //if(Matrix[i][j] == target) {
                int t = j;
                while(t > 1 && H[i][j] <= H[i][t - 1])
                    t = Left[t - 1];
                Left[j] = t;
            //}
        }
        for(int j = m;j >= 1;j--) {
            //if(Matrix[i][j] == target) {
                int t = j;
                while(t < m && H[i][j] <= H[i][t + 1])
                    t = Right[t + 1];
                Right[j] = t;
            //}
        }

        for(int j = 1;j <= m;j++) {
            //if(Matrix[i][j] == target) {
                int S = H[i][j] * (Right[j] - Left[j] + 1);
                Max = max(Max,S);
            //}
        }

    }

    return Max;
}

bool  Do() {
    int n,m;
    if(scanf("%d%d",&n,&m) == EOF)
        return false;

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            char t;
            scanf("\n%c",&t);
            Map[i][j] = (t == '1');
        }

    int ans = MaxMatrix(Map,n,m,true);

    printf("%d\n",ans);
    return true;
}

int main() {
    while(Do());
    return 0;
}
