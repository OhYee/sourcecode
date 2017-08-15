#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define REP(n) for(int o=0;o<n;o++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define Abs(a) (((a)>0)?(a):(-a))
const int MAX=1000001;
const int MIN=-1000001;
int T,a,b,n;

long long Do(){
        //printf("        Do %d %d %d\n",n,a,b);
        int t;
        vector <int>tt;
        REP(n){

        }
        long long sum=0;

        for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                        if(i==j)continue;
                        sum=Max(sum,a*tttt[j]*tttt[j]+b*tttt[i]);
                }
        }

        return sum;

}
int main(){
        scanf("%d",&T);
        REP(T){
                scanf("%d%d%d",&n,&a,&b);
                //printf("Case #%d:%d\n",o+1,Do(a1,b1));
                cout<<"Case #"<<o+1<<": "<<Do()<<endl;
        }

        return 0;
}
