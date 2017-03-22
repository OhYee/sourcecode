#include<cstdio>

inline int min(int a,int b){
    return a<b?a:b;
}
inline int max(int a,int b){
    return a>b?a:b;
}

const int maxn = 1005;
int f[maxn]={-1},c[maxn],k[maxn]={0};


int main(){
    freopen("in.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&f[i]);
            c[i] = 0;
            
            if(f[i]>f[i-1])
                k[i]=k[i-1]+1;
            else if(f[i]<f[i-1])
                k[i]=k[i-1]-1;
            else
                k[i]=k[i-1];
        }

        for(int i=1;i<=n;i++){
            if( (i==1 || k[i-1] > k[i]) && k[i+1]>=k[i]){
                //谷底
                c[i] = 1;
                for(int j=i-1;j>=1;j--){
                    if(k[j]>k[j+1])
                        c[j]=max(c[j],c[j+1]+1);
                    else if(k[j]<k[j+1])
                        break;
                    else
                        c[j]=c[j]?min(c[j],c[j+1]):
                        c[j+1];
                }
                for(int j=i+1;j<=n;j++){
                    if(k[j]>k[j-1])
                        c[j]=max(c[j],c[j-1]+1);
                    else if(k[j]<k[j-1])
                        break;
                    else
                        c[j]=c[j]?min(c[j],c[j-1]):c[j-1];
                }
            }
        }
        
         
         int ans=0;
         for(int i=1;i<=n;i++)
            ans+=c[i];
        
        /*
        printf("i:");
        for(int i=1;i<=n;i++)
            printf("%3d ",i);
        printf("\nf:");   
        for(int i=1;i<=n;i++)
            printf("%3d ",f[i]);
        printf("\nk:");   
        for(int i=1;i<=n;i++)
            printf("%3d ",k[i]);
        printf("\nc:");
        for(int i=1;i<=n;i++)
            printf("%3d ",c[i]);
        printf("\n");
        */
        
         printf("%d\n",ans);
    }    
    return 0;
}
