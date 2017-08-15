#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define debug 0
#define REP(n) for(int i=0;i<n;i++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
/*
#############################################################
*/
const int INF=5000;
int T,N;
struct Point{
    int x,y,w;
};
Point c[1005];
int point[INF][INF];

void refresh(int id,int x,int y){
    if(point[c[id].x][c[id].y]==id)point[c[id].x][c[id].y]=-1;
    c[id].x=x;
    c[id].y=y;
    point[x][y]=id;
/*
    for(int q=0;q<10;q++){
        for(int p=0;p<10;p++){
            printf("%5d",point[p][10-q]);
        }
        cout<<endl;
    }
    cout<<"########################"<<endl;*/
}


void fall(int n){
    if(c[n].y==0)return;
    Point& a=c[n];
    REP(INF){
        if(point[a.x][i]==-1){
            refresh(n,a.x,i);
            if(i==0)return;
            Point& b=c[point[a.x][a.y-1]];
            point[b.x-1][b.y];
            point[b.x+1][b.y];
            bool l=true,r=true;
            //ÅÐ¶Ï×ó²à
            if(a.x==0||point[b.x-1][b.y]!=-1){
                l=false;
            }
            //ÅÐ¶ÏÓÒ²à
            if(point[b.x+1][b.y]!=-1){
                r=false;
            }
            if(a.w<b.w){
                if(l==true){
                    refresh(n,b.x-1,b.y);
                    fall(n);
                    return;
                }
                if(r==true){
                    refresh(n,b.x+1,b.y);
                    fall(n);
                    return;
                }
                return;
            }else{
                int m=point[a.x][a.y-1];
                if(r==true){
                    refresh(n,a.x,a.y-1);
                    refresh(m,b.x+1,b.y);
                    fall(m);
                    return;
                }
                if(l==true){
                    refresh(n,a.x,a.y-1);
                    refresh(m,b.x-1,b.y);
                    fall(m);
                    return;
                }
                return;
            }
            return;
        }
    }
}

int main(){
    freopen("coconuts.in","r",stdin);
    #if !debug
    freopen("coconuts.out","w",stdout);
    #endif

    cin>>T;
    for(int j=0;j<T;j++){
        if(j!=0)cout<<endl;

        cin>>N;
        REP(N){
            int x,y;
            cin>>x>>y;
            c[i]=(Point){x+2500,INF,y};
        }
        #if debug
        cout<<"Ò¬×ÓÒÑ¾­¹Òµ½Ê÷ÉÏÁË(*^__^*) ~"<<endl;
        #endif // debug

        REP(INF){
            memset(point[i],-1,sizeof(point[i]));
        }
        REP(N){
            fall(i);
        }
        REP(N){

            cout<<c[i].y+1<<" "<<c[i].x-2500<<-1<<endl;
        }
    }
    return 0;

}
