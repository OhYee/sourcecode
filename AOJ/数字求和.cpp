#include <cstdio>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		REP(n)
			ans+=read();
		ans*=n-1;
		write(ans);
		putchar('\n');
	}
	return 0;
}