#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#define REP(n) for(int o=0;o<n;o++)

const int money[13] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
	freopen("in.txt","w",stdout);
	for(int j=1;j<=15;j++)
		for(int i=j;i<=15;i++)
			printf("%d %d\n",i,j);
}