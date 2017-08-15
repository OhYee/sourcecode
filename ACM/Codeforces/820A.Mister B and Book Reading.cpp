/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int c, v0, v1, a, l;

    while (cin >> c >> v0 >> v1 >> a >> l) {
        int ans = 0;
        int hr = 0;
        while (hr < c) {
            if(ans)
                hr -= l;
            v0 = min(v0, v1);
            hr += v0;
            ans++;

            v0 += a;
        }
        cout << ans << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}