#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#define REP(n) for(int o=0;o<n;o++)


bool is_prime[510];

void prime() {
	memset(is_prime,1,sizeof(is_prime));
	int len = (int)sqrt(505 + 0.5);
	for(int i = 2;i <= len;i++)
		if(is_prime[i])
			for(int j = i*i;j < 505;j += i)
				is_prime[j] = 0;
	is_prime[1] = 0;
}

int main(){
	freopen("in.txt","w",stdout);
	prime();
	REP(505){
		printf("%d,",is_prime[o]);
	}
}