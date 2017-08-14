#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL __int64
#define LL long long
#define eps 1e-9
#define PI acos(-1.0)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 4010;

double dp[1100000];
double a[22];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		double t = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf",&a[i]);
			t += a[i];
		}
		t = 1-t;
		memset(dp,0,sizeof(dp));
		int m = (1 << n) - 1;
		dp[m] = 0;

		for(int sta = m-1; sta >= 0; sta--)
		{
			double s1 = 0,s2 = 0;
			for(int j = 0; j < n; j++)
			{
				if(!(sta & (1<<j)))
				{
					s1 += a[j] * dp[sta|(1<<j)];
				}
				else
					s2 += a[j];
			}
			s1 += 1;
			dp[sta] = s1/(1-s2-t);
		}
		printf("%.41f\n",dp[0]);
	}
	return 0;
}

