/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 405;
const int INF = 0x3f3f3f;
int del[maxn];
int dis[maxn][maxn];
int ans[maxn];

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    while(cin >> n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> dis[i][j];

        for(int p=0;p<n;p++){
            cin >> del[p];
            del[p]--;
        }
            

        for(int p=n-1;p>=0;p--){
            int k = del[p];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);

            // cout << endl;
            // for(int i = 0;i < n;i++){
            //     for(int j = 0;j < n;j++)
            //         cout << dis[i][j] <<" ";
            //     cout << endl;
            // }
            // cout << endl;
            

            ans[p] = 0;
            for(int i=p;i<n;i++)
                for(int j=p;j<n;j++)
                        ans[p] += dis[del[i]][del[j]];
        }
        for(int i=0;i<n;i++){
            if(i)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}