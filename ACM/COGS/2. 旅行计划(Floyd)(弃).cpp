#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=105;
const int MAXM=10000;
int n,m,v;
int MAP[maxn][maxn];
int K[maxn][maxn];
int F[maxn][maxn];

int main(){
    freopen("djs.in","r",stdin);
    //freopen("djs.out","w",stdout);






    cin>>n>>m>>v;



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            F[i][j]=MAXM;
        }
     }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            K[i][j]=j;
        }
     }



    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cin>>F[x][y];
    }

    //cout<<"Input ok";



    //memcpy(F,MAP,sizeof(MAP));


     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(F[i][k]+F[k][j]<F[i][j]){
                    F[i][j]=F[i][k]+F[k][j];
                    K[i][j]=k;
                }
            }
        }
     }


     for(int i=0;i<n;i++){
        cout<<i<<":"<<endl;
        if(i==v||F[v][i]==MAXM){
            cout<<"no"<<endl;
            continue;
        }
        cout<<"path:";
        int x=v;
        cout<<v<<" ";
        while(x!=i){
            x=K[x][i];
            cout<<x<<" ";
        }
        cout<<endl<<"cost"<<":"<<F[v][i]<<endl;
     }

    return 0;
}
