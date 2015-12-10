#include<cstdio>
using namespace std;

const int maxn=25;
int L[maxn],R[maxn];//L逆时针 R顺时针
bool B[maxn]={0};
int num=0;
void init(int n){
        for(int i=1;i<=n;i++){
                L[i]=i-1;
                R[i]=i+1;
        }
        R[n]=1;
        L[1]=n;
}
void del(int i){
        R[L[i]]=R[i];
        L[R[i]]=L[i];
        B[i]=1;
        num++;
        //printf("\n    del %d\n",i);
}


int main(){
        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);
        init(n);

        int a=1,b=n;

        while(true){
                for(int i=k;i>1;i--)a=R[a];
                for(int i=m;i>1;i--)b=L[b];

                /*
                printf("\n");
                for(int i=a;L[i]!=a;i=L[i])printf("%d ",i);
                printf("%d ",R[a]);
                printf("\n");
                */

                printf("%d",a);
                del(a);
                if(a!=b){
                        printf(" %d",b);
                        del(b);
                }

                if(num==n)break;


                do{
                        a=R[a];
                }while(B[a]);
                do{
                        b=L[b];
                }while(B[b]);

                //printf("\n    a from %d b from %d\n",a,b);

                //for(a=R[a];!B[a];a=R[a]);
                //for(b=L[b];!B[b];b=L[b]);
                //a=R[a];
                //b=L[b];
                printf(",");
        }

        return 0;

}
