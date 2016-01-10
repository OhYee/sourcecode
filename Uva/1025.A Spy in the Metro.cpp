#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

#define REP(n) for(int o=1;o<=n;o++)

int n;
int T;
int t[51];
int M1;
int d1[51];
int M2;
int d2[51];

int main(){
       int cnt=0;
       scanf("%d",&n);
       while(n){
       cnt++;
       scanf("%d",&T);
       for(int o=1;o<=n-1;o++)scanf("%d",&t[o]);
       scanf("%d",&M1);
       REP(M1)scanf("%d",&d1[o]);
       scanf("%d",&M2);
       REP(M2)scanf("%d",&d2[o]);

       //printf("共%d站 需要在%d到达\n",n,T);
      // REP(n-1)printf("(%d)-%d-",o,t[o]);
      // printf("(%d)\n",n);


       int dp[201][51];
       for(int i=0;i<=T;i++)
              for(int j=0;j<=n;j++)
                     dp[i][j]=-1;
       dp[0][1]=0;

       bool has_train1[201][51];
       bool has_train2[201][51];
       memset(has_train1,false,sizeof(has_train1));
       memset(has_train2,false,sizeof(has_train2));
       //int dis[51];
       //dis[1]=0;
       //for(int i=1;i<=n;i++)dis[i+1]=dis[i]+t[i];
       for(int i=1;i<=M1;i++){
                     int temp=d1[i];
                     for(int j=1;j<=n;j++){
                            has_train1[temp][j]=true;
                          //  printf("→%d %d\n",temp,j);
                            temp+=t[j];
                     }
       }
       for(int i=1;i<=M2;i++){
                     int temp=d2[i];
                     for(int j=n;j>=1;j--){
                            has_train2[temp][j]=true;
                           // printf("←%d %d\n",temp,j);
                            temp+=t[j-1];
                     }
       }

       for(int i=0;i<=T;i++){
              for(int j=1;j<=n;j++){
                     if(dp[i][j]==-1)continue;

                     dp[i+1][j]=(dp[i+1][j]==-1)?(dp[i][j]+1):(min(dp[i+1][j],dp[i][j]+1));
                     //printf("      At %d %d  wait dp[%d][%d]=%d\n",i,j,i+1,j,dp[i+1][j]);
                     if(has_train2[i][j]&&j>=1)dp[i+t[j-1]][j-1]=(dp[i+t[j-1]][j-1]==-1)?(dp[i][j]):min(dp[i+t[j-1]][j-1],dp[i][j]);
                     //printf("      At %d %d  Left dp[%d][%d]=%d\n",i,j,i+t[j-1],j-1,dp[i+t[j-1]][j-1]);}
                     if(has_train1[i][j]&&j<=n)dp[i+t[j]][j+1]=(dp[i+t[j]][j+1]==-1)?(dp[i][j]):min(dp[i+t[j]][j+1],dp[i][j]);
                     //printf("      At %d %d  Right dp[%d][%d]=%d\n",i,j,i+t[j],j+1,dp[i+t[j]][j+1]);}
              }
       }
      // for(int i=0;i<=T;i++){
      //        for(int j=1;j<=n;j++){
      //               if(dp[i][j]!=-1)printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
      //        }
      // }
      printf("Case Number %d: ",cnt);
       if(dp[T][n]==-1){
              printf("impossable");
       }else{
              printf("%d",dp[T][n]);
       }
       printf("\n");

       scanf("%d",&n);
       }
       return 0;
}
