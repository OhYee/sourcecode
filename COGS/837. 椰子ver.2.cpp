#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <time.h>
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

int T,N;
const int SHIFT=1;
const int maxn=1005;
const int maxH=500;
const int maxL=1000;
struct coconuts{
	int pos,h,weight;
};
coconuts c[maxn];
 Map[maxL][maxH]={0};//0代表可以到达

void fall(int pos,int h,int n){
	if(Map[pos-1][h-1]&&Map[pos-1][h-1]){//都不能到达
		Map[pos][h]=n;
		c[o].pos=pos;
		c[o].h=h;
		return;
	}
	if(!Map[pos-1][h-1]&&!Map[pos-1][h-1]){//都能到达
        m=Map[pos][h-1];
        if(c[n].weight<c[m].weight){
            fall(pos-1,h-1,n);
            return;
        }else{

        }
	}
}

int main(){


    //freopen("coconuts.in","r",stdin);
    #if !debug
    freopen("coconuts.out","w",stdout);
    #endif

    REP(maxL){
    	Map[o][0]=1;
    }

    cin>>T;
    while(T--){

        cin>>N;
        REP(N){
            int Pi,Wi;
            cin>>Pi>>Wi;
            c[o].pos=Pi;
            c[o].weight=Wi;
            for(int i=1;i<maxH;i++){
            	if(Map[Pi][i]==0){
            		fall(Pi,h,n)
            	}
        	}
        }
        cout<<endl;
    }



    return 0;

}
