#include <algorithm>
#include <bitset>
#include <cstdio>
#include <ctime>
using namespace std;

const int maxn = 50005;

int T, n, m, q;
int a[maxn], b[maxn];
bitset<maxn> ans;

//优化输入
int read_int() {
    char c;
    int ans = 0;
    while (c = getchar(), !(c >= '0' && c <= '9'))
        ;
    while (c >= '0' && c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

int main() {
    //freopen("out.txt","w",stdout);
    int START = clock();

    T = read_int();
    while (T--) {
        n = read_int();
        m = read_int();
        q = read_int();
        for (int i = 0; i < n; ++i)
            a[i] = read_int();
        for (int i = 0; i < m; ++i)
            b[i] = read_int();
        sort(a, a + n);
        sort(b, b + n);

        ans.reset();
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < b[0]) {
                if (((n - i) * m) & 1)
                    ans.flip(a[i]);
                break;
            }
            for (int j = 0; j < m; ++j) {
                if (a[i] < b[j]) {
                    if ((m - j) & 1)
                        ans.flip(a[i]);
                    break;
                } else {
                    ans.flip(a[i] % b[j]);
                }
            }
        }

        for (int i = 0; i < q; ++i) {
            printf("%d: ",i);
            putchar(ans[read_int()] + '0');
            putchar('\n');
        }
    }
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    return 0;
}