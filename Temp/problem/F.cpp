#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const int maxn = 10005;
const int maxm = 100005;

bool hasin[maxn], hasout[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(hasin, false, (n + 5) * sizeof(bool));
        memset(hasout, false, (n + 5) * sizeof(bool));

        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            hasin[u] = hasout[v] = true;
        }

        int ans1 = 0;
        int ans2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (!hasin[i])
                ++ans1;
            if (!hasout[i])
                ++ans2;
        }

        printf("%d\n", ans1 * ans2);
    }
    return 0;
}