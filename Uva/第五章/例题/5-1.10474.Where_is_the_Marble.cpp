#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(n) for(int o=0;o<n;o++)
int kase=0;

bool Do(){
	int N,m;
	int a[10000];
	if(scanf("%d %d",&N,&m),N==0||m==0)return false;
	printf("CASE# %d:\n",++kase);
	REP(N)
		scanf("%d",&a[o]);
	sort(a,a+N);
	REP(m){
		int b;
		int it=-1;
		scanf("%d",&b);
		for(int i=0;i<N||a[i]>b;i++)
			if(a[i]==b){
				it=i;
				break;
			}
		if(it==-1)printf("%d not found\n",b);
		else printf("%d found at %d\n",b,it+1);
	}
	return true;
}

int main(){
	//freopen("in.txt","r",stdin);
	while(Do());
	return 0;
}