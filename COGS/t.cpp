#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
              double time_Start = (double)clock(); //开始时间
              	       double time_Finish;

	freopen ("pcount.in","r",stdin);
	freopen ("pcount.out","w",stdout);
	int i,n,j=0;
	scanf("%d",&n);

	       time_Finish = (double)clock(); //结束时间
       printf("\n read n finished operate time: %.2fms \n",time_Finish-time_Start); //输出

	static long int a[200005]={0},b[200005]={0},c[200005]={0};
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

              time_Finish = (double)clock(); //结束时间
       printf("\n read m finished operate time: %.2fms \n",time_Finish-time_Start); //输出

	sort(a,a+n);
	//for(i=0;i<n;i++) printf("%d\n",a[i]);
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
			{c[j]=a[i-1];j++;}
		else b[j]++;
	}
	c[j]=a[n-1];

	       time_Finish = (double)clock(); //结束时间
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //输出

	for(i=0;i<j;i++)
		printf("%d %d\n",c[i],b[i]+1);
	printf("%d %d",c[i],b[i]+1);

       time_Finish = (double)clock(); //结束时间
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //输出
	return 0;
}

