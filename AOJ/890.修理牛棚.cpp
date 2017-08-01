//*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 205;
int a[maxn], b[maxn];
int m, s, c;

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    while (cin >> m >> s >> c) {
        for (int i = 0; i < c; i++)
            cin >> a[i];
        sort(a,a+c);
        if (c == 0 || m >= c ) {
            cout << c << endl;
        } else {
            for (int i = 0; i < c - 1; i++)
                b[i] = a[i + 1] - a[i] - 1;
            sort(b, b + c - 1);

            int ans = a[c - 1] - a[0] + 1;
            // cout<<ans<<endl;
            for (int i = 0; i < m - 1; i++) {
                // cout<<b[c-1-i]<<endl;
                ans -= b[c - 2 - i];
            }
            cout << ans << endl;
        }
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}