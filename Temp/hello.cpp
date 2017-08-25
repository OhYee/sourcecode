#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
typedef long long LL;
const int N=1e5;
double data[N];
int main()
{
    for(LL i=4;i<N;i++)
    {
        if(i%4==0) data[i]=(i*i)/8;
        if(i%4==1) data[i]=data[i-1]+i/4-0.5;
        if(i%4==2) data[i]=(i/4)*(i/4+1)*2;
        if(i%4==3) data[i]=data[i-1]+i/4+0.5;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=4;i<N;i++)
        {
            if(data[i]>=n)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
