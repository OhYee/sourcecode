#include <cstdio>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

bool Do();

int main(){
	freopen("in.txt","r",stdin);
	while(Do());
	return 0;
}

bool Do(){
	const int maxn=1000000;
	char s[maxn];
	char t[maxn];

	REP(maxn)
		s[o]=t[o]='\0';

	if(scanf("%s%s",s,t)==EOF)
		return false;

	int si=0,ti=0;
	bool yes=false;
	while(1){
		if(s[si]=='\0'){
			yes=true;
			break;
		}
		if(t[ti]=='\0')break;
		if(s[si]==t[ti])si++;
		ti++;
	}
	printf("%s\n",yes?"Yes":"No");
	return true;
}