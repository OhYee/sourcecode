#include <iostream>  
#include <cmath>  
#include <cstdio>  
using namespace std;  
int main()  
{  
    //freopen("input.txt","r",stdin);  
    double M[10][31],a,c,x;  
    long long int E[10][31],b,d;  
    int i,j;  
    for(i=0;i<=9;i++)  
        for(j=1;j<=30;j++){  
            a=1-pow(2,-(i+1));  
            b=pow(2,j)-1;  
            x=log10(a)+b*log10(2);  
            d=floor(x);  
            c=pow(10,x-d);  
            M[i][j]=c;  
            E[i][j]=d;  
        }  
  
    char s[30];  
    double p;  
    int q;  
    while(cin>>s){  
        if(s=="0e0")  
            break;  
        s[17]=' ';  
        sscanf(s,"%lf %d",&p,&q);  
        for(i=0;i<10;i++)  
            for(j=1;j<=30;j++)  
                if(fabs(M[i][j]-p)<1e-4&&E[i][j]==q)  
                    cout<<i<<' '<<j<<endl;  
    }  
    return 0;  
}  