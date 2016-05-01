#include <iostream>  
#include <cstdio>
using namespace std;  
  
int min(int a,int b)  
{  
    return a<b?a:b;  
}  
  
int main()  
{  
	int i;
	int j;
	freopen("in.txt","r",stdin);
    int test;  
    cin>>test;  
    while(test--)  
    {  
        /*Input & Initial*/  
  
        int c;  
        cin>>c;  
  
        int* a=new int[c+1];  //某类珍珠数目  
        int* p=new int[c+1];  //某类珍珠单价  
        int* dp=new int[c+1]; //dp[i]表示在已知第i类珍珠时,所需支付的最低价格  
        int* sum=new int[c+1];//sum[i]=∑a[i]  
  
        sum[0]=0;  
        for(i=1;i<=c;i++)  
        {  
            cin>>a[i]>>p[i];  
            sum[i]=sum[i-1]+a[i];  
        }  
  
        /*Dp*/  
  
        dp[0]=0;  //Dp初始化  
        for(i=1;i<=c;i++)  
        {  
            dp[i]=(a[i]+10)*p[i]+dp[i-1];   //当第i种珍珠出现时，未优化价格的情况  
            for(j=0;j<i;j++)  //枚举第i种珍珠前的每一种珍珠，寻找最优价格  
                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j]+10)*p[i]);  //在求dp[i]前，对于每一个j<i，dp[j]的最优值已求出  
        }                                                        //(sum[i]-sum[j]+10)*p[i]即第j+1~i种珍珠被第i种珍珠替代后的价格  
        cout<<dp[c]<<endl;  
  
        delete a,p,dp,sum;  
    }  
    return 0;  
}  