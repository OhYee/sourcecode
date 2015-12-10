#include<cstdio>
#include<cstring>
using namespace std;
const double mol[4]={12.01,1.008,16.00,14.01};
void Do(){
        char c[100];
        double ans=0;
        memset(c,0,sizeof(c));
        scanf("%s",&c);

        for(int i=0;c[i]!=0;i++){
                double m=0;
                int n=0;
                int j=i+1;
                for(;c[j]!=0&&c[j]<=57;j++){
                        n*=10;
                        n+=(int)c[j]-48;
                }
                if(n==0)n=1;
                if(c[i]=='C')m=mol[0];
                if(c[i]=='H')m=mol[1];
                if(c[i]=='O')m=mol[2];
                if(c[i]=='N')m=mol[3];
                //printf("%f * %d = %f \n",m,n,m*(double)n);
                ans+=m*(double)n;
                i=j-1;
        }
        printf("%.3f\n",ans);
}
int main(){
        //freopen("in.txt","r",stdin);
        int n;
        scanf("%d",&n);
        while(n){
                n--;
                Do();
        }
        return 0;
}
