#include <cstdio>
using namespace std;
int M,N,A,B,C,D;
int X[1001][1001];
int Map[1001][1001];
int main(){
    scanf("%d%d%d%d%d%d",&M,&N,&A,&B,&C,&D);
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&X[i][j]);
       for(int i=1;i<=M;i++){
              for(int j=1;j<=N;j++){
                     if(i==1){
                            if(j==1){
                                   Map[1][1]=X[1][1];
                                   continue;
                            }
                            Map[i][j]=Map[i][j-1]+X[i][j];
                            continue;
                     }
                     if(j==1)
                            Map[i][j]=Map[i-1][j]+X[i][j];
                     else
                            Map[i][j]=Map[i-1][j]+Map[i][j-1]-Map[i-1][j-1]+X[i][j];
              }
       }
       /*
       printf("\n");
       for(int i=1;i<=M;i++){
              for(int j=1;j<=N;j++)
                     printf("%d ",Map[i][j]);
              printf("\n");
       }
       */
       for(int i=1;i<=M-A;i++)
              for(int j=1;j<=N-B;j++){

              }





    return 0;
}
