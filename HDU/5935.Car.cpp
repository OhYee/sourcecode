#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <functional>

using namespace std;

const int maxn = 100005;

int kase = 1;
int a[maxn];

int vs_main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    a[0] = 0;

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        long long sum = 0;
        for(int i = 1;i <= n;i++)
            cin >> a[i];

        double maxv = 99999999;
        int ans = 0;
        for(int i = n;i>0;i--) {
            int dis = a[i] - a[i - 1];
            double tt = (double)dis / maxv;
            int t = (int)(tt + 0.001);
            if((double)dis / (double)t > maxv)
                t++;

            maxv = (double)dis / (double)t;
            ans += t;
        }
        cout << "Case #" << kase++ << ": " << ans << endl;

    }
    return 0;
}