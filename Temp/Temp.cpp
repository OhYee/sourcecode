
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#include<memory.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<math.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):(-(a)))
#define lowbit(a) (a&(-a))
#define sqr(a) ((a)*(a))
#define swap(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define eps (1e-8)
#define J 10000
#define mod 1000000007
#define MAX 0x7f7f7f7f
#define PI 3.14159265358979323
#define N 14
#define M 100004
using namespace std;
typedef long long LL;
double anss;
LL aans;
int cas,cass;
int n,m,lll,ans;
LL e[N];
LL mi[N][N],c[N][M],d[N][M];

bool cmp(int a,int b)
{
	return a<b;
}
void init()
{
	int i,j;
	for(e[0]=1,i=1;i<11;i++)e[i]=e[i-1]*10;
	for(i=0;i<10;i++)
	{
		mi[i][0]=1;
		for(j=1;j<10;j++)mi[i][j]=mi[i][j-1]*i;
	}
	for(j=1;j<10;j++)
	{
		for(i=0;i<e[5];i++)
			c[j][i]=mi[i/e[4]][j]+mi[i%e[4]/e[3]][j]+mi[i%e[3]/e[2]][j]+mi[i%e[2]/e[1]][j]+mi[i%e[1]][j]-i*e[5],
			d[j][i]=mi[i/e[4]][j]+mi[i%e[4]/e[3]][j]+mi[i%e[3]/e[2]][j]+mi[i%e[2]/e[1]][j]+mi[i%e[1]][j]-i;
		sort(c[j],c[j]+e[5],cmp);
		sort(d[j],d[j]+e[5],cmp);
	}
}
int main()
{   int start = clock();
     freopen("in.txt","r",stdin);
	#ifndef ONLINE_JUDGE

	#endif
	LL i,j;
	int x,y;
	init();

	for(scanf("%d",&cas),cass=1;cass<=cas;cass++)
	{
		printf("Case #%d: ",cass);
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=0,j=e[5]-1;i<e[5] && j;)
		{
			if(c[m][i]+d[m][j]>n)j--;
			else if(c[m][i]+d[m][j]<n)i++;
			else
			{
				x=y=1;
				while(c[m][++i]==c[m][i-1LL] && i < e[5])x++;
				while(d[m][--j]==d[m][j+1] && j)y++;
				ans+=x*y;
			}
		}
		printf("%d\n",ans-(n==0));
	}

    printf("Time:%.3lfs\n",double(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}

