#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 150000;

long long f[maxn];
void calc() {
    f[0] = f[1] = f[2] = f[3] = 0;
    f[4] = 2;
    f[5] = 2;
    f[6] = 4;
    f[7] = 5;
    for (long long i = 2; i < (maxn / 4) - 1; ++i) {
        f[i * 4] = i * i * 2;
        f[i * 4 + 1] = f[i * 4] + (i + i - 1) / 2;
        f[i * 4 + 2] = f[i * 4] + i * 2;
        f[i * 4 + 3] = f[i * 4 + 2] + (i + i + 1) / 2;
    }
}

int main() {
    // freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    calc();
    
    /*
    for (int i = 1; i < 100; ++i) {
        printf("%d %d\n", i, lower_bound(f, f + maxn, i) - f);
    }
    */
    
    while (T--) {
        long long n;
        scanf("%I64d", &n);
        printf("%d\n", lower_bound(f, f + maxn, n) - f);
    }
    
    return 0;
}