#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1005;

int F[maxn];
int f(int i) {
    if (!F[i])
        F[i] = (int)(((long long)f(i - 1) * (long long)i) % mod);
    return F[i] % mod;
}

int A(int sup, int sub) {
    //printf("A %d %d = %d\n", sup, sub, f(sub) / f(sup));
    return f(sub) / f(sup);
}

int main() {
    memset(F, 0, sizeof(F));
    F[0] = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = 1;
    for (int i = 1; i <= min(n, m); ++i) {
        //printf("%I64d\n", ans % mod);
        ans += (int)((long long)(A(n-i, n) * A(m-i, m) / f( i)) % mod);
    }
    printf("%I64d\n", ans % mod);
    return 0;
}