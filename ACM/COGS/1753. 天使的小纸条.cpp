#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define debug 1
#define REP(n) for(int o=0;o<n;o++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
/*
#############################################################
*/
const int maxn=305;
int Map[maxn][maxn];
int M,N;
int Q;


int main(){
    freopen("luvletter.in","r",stdin);
    #if !debug
    freopen("luvletter.out","w",stdout);
    #endif // debug


    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int temp;
            cin>>temp;
            Map[i][j]=temp;
        }
    }

    #if debug
    cout<<"地图读入完毕"<<endl;
    cout<<"#######################"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<" "<<Map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"#######################"<<endl;
    #endif // debug

    cin>>Q;
    REP(Q){
        int mode;
        cin>>mode;
        if(mode==1){
            int x,y,c;
            cin>>x>>y>>c;
            Map[x][y]=c;
            #if debug
            cout<<"地图更新完毕"<<endl;
            cout<<"#######################"<<endl;
            for(int p=1;p<=N;p++){
                for(int q=1;q<=M;q++){
                    cout<<" "<<Map[p][q]<<" ";
                }
                cout<<endl;
            }
            cout<<"#######################"<<endl;
            #endif // debug
        }else{
            int x1,x2,y1,y2,c;
            cin>>x1>>x2>>y1>>y2>>c;
            int sum=0;
            int xa=Min(x1,x2);
            int xb=Max(x1,x2);
            int ya=Min(y1,y2);
            int yb=Max(y1,y2);
            for(int p=xa;p<=xb;p++){
                for(int q=ya;q<=yb;q++){
                    if(Map[p][q]==c)sum+=1;
                }
            }
            cout<<sum<<endl;
        }
    }


    return 0;
}
