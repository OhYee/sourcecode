#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))
/*
#############################################################
*/
const int maxn=305;
int Map[maxn][maxn];
int C[maxn][maxn][maxn];
int M,N;
int Q;

int lowbit(int x){
	return x&(-x);
}

int work(int x,int y,int n){//计算矩形方块(1,1)(x,y)中指定类型的个数和
    int sum=0;
    #if debug
    cout<<"     work"<<endl;
    #endif // debug
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            #if debug
            cout<<"     sum("<<sum<<")+= C["<<i<<"]["<<j<<"]["<<n<<"]("<<C[i][j][n]<<")="<<sum+C[i][j][n]<<endl;
            #endif // dubug
            sum+=C[i][j][n];
        }
    }
    return sum;
}

void change(int x,int y,int n){
    int temp=Map[x][y];
    Map[x][y]=n;
    for(int p=x;p<=N;p+=lowbit(p)){
        for(int q=y;q<=M;q+=lowbit(q)){
            C[p][q][n]++;
            C[p][q][temp]--;
        }
    }
}

void add(int x,int y,int n){
    Map[x][y]=n;
    //int temp=Map[x][y];
    for(int p=x;p<=N;p+=lowbit(p)){
        for(int q=y;q<=M;q+=lowbit(q)){
            C[p][q][n]++;
            //C[p][q][temp]--;
        }
    }
}

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
            add(i,j,temp+1000);

        }
    }


    #if debug
    cout<<"地图读入完毕"<<endl;
    cout<<"#######################"<<endl;
    REP(M+1)printf("%5d",o);
    cout<<endl<<endl;
    for(int i=1;i<=N;i++){
        printf("%5d  ",i);
        for(int j=1;j<=M;j++){
            //cout<<" "<<Map[i][j]<<" ";
            printf("%5d",Map[i][j]);
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
            change(x,y,c);
            /*#if debug
            cout<<"地图更新完毕"<<endl;
            cout<<"#######################"<<endl;
            for(int p=1;p<=N;p++){
                for(int q=1;q<=M;q++){
                    cout<<" "<<C[p][q][2]<<" ";
                }
                cout<<endl;
            }
            cout<<"#######################"<<endl;
            #endif // debug*/
        }else{
            int x1,x2,y1,y2,c;
            cin>>x1>>x2>>y1>>y2>>c;
            //int sum=0;
            int xa=Min(x1,x2);
            int xb=Max(x1,x2);
            int ya=Min(y1,y2);
            int yb=Max(y1,y2);
            xa--;
            ya--;
            /*change(x,y,n);
            for(int p=xa;p<=xb;p++){
                for(int q=ya;q<=yb;q++){
                    if(Map[p][q]==c)sum+=1;
                }
            }*/


            int t=work(xb,yb,c)+work(xa,ya,c)-work(xa,yb,c)-work(xb,ya,c);
            //t=(t<0?0:t);
            cout<<t<<endl;
        }
    }


    return 0;
}
