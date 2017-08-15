//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1005;
int a[maxn], dp[maxn];

inline int abs(int a){
    return a>0?a:-a;
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int Max = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (abs(a[i] - a[j]) != 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            Max = max(Max, dp[i]);
        }
        cout << n-Max << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}