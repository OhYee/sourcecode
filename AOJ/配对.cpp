#include <cstdio>
#include <cstring>
typedef long long LL;
const int maxn=1000000;
LL ans[maxn];
LL get(int n){
	return ans[n]?ans[n]:(get(n-1)*(2n-1))%mod;
}
int main(){
	memset(ans,0,sizeof(ans));
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%lld\n",get(n));
	return 0;
}