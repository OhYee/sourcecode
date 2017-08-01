//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 505;

int x[maxn], y[maxn];

const int mod = 1e9 + 7;

int n, m;
int f(int x, int y) {
    if (x == 1) {
        if (y == 1 || y == 2)
            return 1;
        else
            return (f(1, y - 1) + (2 * f(1, y - 2)) % mod) % mod;
    }
    int sum = 0;
    for (int i = y; i < y + n; i++)
        sum = (sum + f(x - 1, i)) % mod;
    return sum;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        cout << f(m, 1) << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}
