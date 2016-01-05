/*
By:OhYee
Email:oyohyee@oyohyee.com
QQ:896817156
GitHub:OhYee
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(n) for(int o=1;o<=n;o++)

const int maxn=200005;
const int INF=9999999;
int n;
int t[maxn];
int ans=INF;
bool mark[maxn];


int DFS(int begin);

int main(){
	//freopen("2015message.in","r",stdin);
	//freopen("2015message.out","w",stdout);

	memset(mark,0,sizeof(mark));

	scanf("%d",&n);
	REP(n)scanf("%d",&t[o]);

	REP(n){
		printf("%d:%d\n",o,DFS(o));
		ans=min(ans,DFS(o));
	}
	printf("%d",ans);
	return 0;
}


int DFS(int begin){
	int len[maxn];
	int it=begin;
	len[begin]=1;
	for(;;){
		if(mark[it]==true)
			return INF;
		if(mark[t[it]]==true)
			return len[it]-len[t[it]]+1;
		if(t[it]==begin)
			break;
		if(t[it]<begin||len[t[it]]>=ans)
			return INF;	

		len[t[it]]=len[it];
		mark[it]=true;
		it=t[it];
		

		len[it]++;
	}
	return len[it];
}