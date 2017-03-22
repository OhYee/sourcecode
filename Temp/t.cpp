#include <stdio.h>
int main(void)
{
    int M,N,i,j,sum;
    int a[1000],b[1000],c[1000];
    scanf("%d",&M);
    for(j=0;j<M;j++)
    {
        sum=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            b[i]=1;
        }
        for(i=1;i<=N-2;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])
            {
                if(a[i-1]>a[i+1])
                    b[i]=b[i-1]+1;
                else
                    b[i]=b[i+1]+1;
            }
           else if(a[i]>a[i-1]&&a[i]<a[i+1])
                b[i]=b[i-1]+1;
           else if(a[i]<a[i-1]&&a[i]>a[i+1])
                    b[i]=b[i+1]+1;
        }
        if(a[0]>a[1]) b[0]=b[1]+1;
        if(a[N-1]>a[N-2]) b[N-1]=b[N-2]+1;
        for(i=0;i<N;i++)
            sum+=b[i];
        c[j]=sum;
    }
    for(i=0;i<M;i++)
    printf("%d\n",c[i]);
    return 0;
}
