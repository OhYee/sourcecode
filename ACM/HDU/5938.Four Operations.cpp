
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

const int maxn = 25;

int kase = 1;
char s[maxn];

long long toInt(const char *s,int u,int v) {
    long long t = 0;
    for(int i = u;i <= v;i++) {
        t *= 10;
        t += s[i] - '0';
    }
    return t;
}

int vs_main() {
    cin.tie(0);
    cin.sync_with_stdio(false);


    int T;
    cin >> T;
    while(T--) {
        cin >> s;

        long long ans = 0;
        int n = strlen(s);
        if(n == 5) {
            ans = toInt(s,0,0) + toInt(s,1,1) - toInt(s,2,2) * toInt(s,3,3) / toInt(s,4,4);
        } else {
            long long a = toInt(s,0,n - 5) + toInt(s,n - 4,n - 4) - toInt(s,n - 3,n - 3)*toInt(s,n - 2,n - 2) / toInt(s,n - 1,n - 1);
            long long b = toInt(s,0,0) + toInt(s,1,n - 4) - toInt(s,n - 3,n - 3)*toInt(s,n - 2,n - 2) / toInt(s,n - 1,n - 1);
            long long c = toInt(s,0,n - 6) + toInt(s,n - 5,n - 5) - toInt(s,n - 4,n - 4)*toInt(s,n - 3,n - 3) / toInt(s,n - 2,n - 1);
            long long d = toInt(s,0,0) + toInt(s,1,n - 5) - toInt(s,n - 4,n - 4)*toInt(s,n - 3,n - 3) / toInt(s,n - 2,n - 1);
            ans = max(max(a,b),max(c,d));
        }

        cout << "Case #" << kase++ << ": " << ans << endl;
    }
    return 0;
}