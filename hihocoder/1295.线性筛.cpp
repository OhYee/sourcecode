#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000005;

int prime[maxn], num_prime;
bool isNotPrime[maxn];

void PRIME(int n) {
    num_prime = 0;
    memset(prime, 0, sizeof(prime));
    memset(isNotPrime, false, sizeof(isNotPrime));
    isNotPrime[0] = isNotPrime[1] = true;

    for (long i = 2; i < n; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < n; j++) {
            isNotPrime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main() {
    int n;
    PRIME(maxn-2);

    while (scanf("%d", &n) != EOF)
        printf("%d\n", upper_bound(prime, prime + num_prime, n) - prime);
    return 0;
}