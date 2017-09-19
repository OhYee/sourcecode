#include <cstdio>
using namespace std;
const long long mod = 1e9 + 7;

long long exp_mod(long long a, long long n, long long b) {
    long long t;
    if (n == 0)
        return 1 % b;
    if (n == 1)
        return a % b;
    t = exp_mod(a, n / 2, b);
    t = t * t % b;
    if ((n & 1) == 1)
        t = t * a % b;
    return t;
}

long long inv(long long p, long long mod) { return exp_mod(p, mod - 2, mod); }

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long q, p, k;
        scanf("%I64d%I64d%I64d", &p, &q, &k);
        printf(
            "%I64d %I64d\n", exp_mod((inv(p, mod) * p) % mod, k, mod),
            (inv(2, mod) *
             (1 + exp_mod((inv(p, mod) * ((p - 2 * q) % mod)) % mod, k, mod))) %
                mod);
        /*
        long long t = exp_mod(p - q, k, mod);
        long long fz = 0;
        for (int i = 0; i <= k; i = i + 2) {
            fz = (fz + t) % mod;
            t = (t * q * q / (p - q) / (p - q)) % mod;
        }
        */

        // printf("%I64d %I64d %I64d\n", fz, ny(exp_mod(p, k, mod)),
        //       (fz * ny(exp_mod(p, k, mod))) % mod);
    }
    return 0;
}