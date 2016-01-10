#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int first=true;
int main(){
       //freopen("in.txt","r",stdin);
       scanf("%d",&n);
       int Case=0;
       while(n!=0){
              //if(first==true)first=false;
              //else printf("\n");

              Case++;
              printf("Game %d:\n",Case);
              int A=0,B=0;
              int a[1005];
              int b[1005];
              int c[11]={0};
              int d[11]={0};

              for(int i=0;i<n;i++){
                     scanf("%d",&a[i]);
                     c[a[i]]++;
              }

              for(int i=0;i<n;i++){
                     scanf("%d",&b[i]);
                     d[b[i]]++;
                     if(a[i]==b[i])A++;
              }
              while(b[0]!=0){
                     for(int j=1;j<=9;j++){
                            B+=min(c[j],d[j]);
                     }
                     B-=A;
                     printf("    (%d,%d)\n",A,B);

                     A=B=0;
                     memset(d,0,sizeof(d));
                     for(int i=0;i<n;i++){
                            scanf("%d",&b[i]);
                            d[b[i]]++;
                            if(a[i]==b[i])A++;
                     }
              }
       scanf("%d",&n);
       }
       return 0;
}
