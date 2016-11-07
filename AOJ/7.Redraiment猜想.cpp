#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 10000005;
bool is_prime[maxn];
int prime_cnt[maxn];

void prime() {
    memset(is_prime,true,sizeof(is_prime));
    int len = (int)sqrt(maxn + 0.5);
    for(int i = 2;i <= len;i++)
        if(is_prime[i])
            for(int j = i*i;j < maxn;j += i)
                is_prime[j] = false;
    is_prime[1] = false;


    prime_cnt[0] = 0;
    for(int i = 1;i < maxn;i++)
        prime_cnt[i] = prime_cnt[i - 1] + is_prime[i];
}

int main() {
    prime();

    int n;
    while(scanf("%d",&n), n!= 0) {
        printf("%d\n",prime_cnt[n]);
    }

    return 0;
}