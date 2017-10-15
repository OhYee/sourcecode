#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> Pair;
const int maxn = 205;
const int INF = 0x3f3f3f;

int p[maxn];
int c[maxn];
int x[maxn];
vector<Pair> hc[maxn];
int dp[10005];

int main() {
    int T;
    scanf("%d", &T);
    for(int kase= 1;kase<=T;++kase) {
        int n, m, k;
        scanf("%d%d%d", &m, &n, &k);

        for (int i = 0; i < k; ++i)
            hc[i].clear();

        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d", &t);
            if (t == 0) {
                c[i] = INF;
                scanf("%d", &p[i]);
            } else {
                scanf("%d%d", &c[i], &p[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            int y;
            scanf("%d%d", &x[i], &y);
            for (int j = 0; j < y; ++j) {
                int u, v;
                scanf("%d%d", &u, &v);
                hc[i].push_back(make_pair(u, v));
            }
        }

        bool change = true;
        while (change) {
            change = false;
            for (int i = 0; i < k; ++i) {
                int cost = 0;
                for (auto iter : hc[i])
                    cost += c[iter.first] * iter.second;
                if (cost < c[x[i]]) {
                    c[x[i]] = cost;
                    change = true;
                }
            }
        }

        // for (int i = 1; i <= n; ++i)
        //     printf("%d : %d %d\n", i, c[i], p[i]);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            for (int j = c[i]; j <= m; ++j)
                dp[j] = max(dp[j], dp[j - c[i]] + p[i]);

        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            // printf("dp[%d] = %d\n",i,dp[i]);
            ans = max(dp[i], ans);
        }
        printf("Case #%d: %d\n", kase,ans);
    }
    return 0;
}