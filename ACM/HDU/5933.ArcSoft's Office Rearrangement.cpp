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
long long a[maxn];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        int n,m;
        cin >> n >> m;

        long long sum = 0;
        for(int i = 0;i<n;i++) {
            cin >> a[i];
            sum += a[i];
        }

        cout << "Case #" << kase++ << ": ";
        if(sum%m) {
            cout << "-1";
        } else {
            long long t = sum / m;
            long long ans = 0;
            for(int i = 0;i<n;i++) {
                while(a[i]>t) {
                    a[i] -= t;
                    ans++;
                }
                if(a[i]<t) {
                    a[i + 1] += a[i];
                    ans++;
                }
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}