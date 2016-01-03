/*
By:OhYee
Email:oyohyee@oyohyee.com
QQ:896817156
GitHub:OhYee
*/
#include <cstdio>

using namespace std;

#define DEF(n) for(int o;o<n;o++)

const int maxn=200005;
int n;
int t[maxn];

int main(){
	freopen("2015message.in","r",stdin);
	freopen("2015message.out","w",stdout);

	scanf("%d",&n);
	DEF(n)scanf("%d",t[o]);

	return 0;
}


int SPFA(int begin){
	bool mark[maxn];
	memset(mark,0,sizeof(mark));
	int len;
	int it=begin;
	for(len=1;;len++){
		it=t[it];
		if(it==begin)break;
		if(mark[it]==true){
			len=-1;
			break;
		}
		mark[it]=true;
	}
}