//中文
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


const int maxn = 60005;
const int maxk = 15;

int queue_a[maxn], queue_b[maxn];
int bposList[maxn];

int DP[maxn][maxk << 2];
vector<int> DisList[maxn << 2];

int n, k;

bool cmp(int a, int b) { return a > b; }

void init() {
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i <= n << 2; ++i)
        DisList[i].clear();
}

int dfs(int apos, int bpos, int deep) {
    int RETURN = -1;
    if (!apos || !bpos) {
        RETURN = apos | bpos;
    } else {
        if (abs(queue_a[apos] - queue_b[bpos]) <= k) {
            //暴力
            int &dp = DP[apos][queue_a[apos] - queue_b[bpos] + k];
            if (dp == -1) {
                dp = min(dfs(apos - 1, bpos, deep + 1),
                         dfs(apos, bpos - 1, deep + 1)) +
                     1;
            }
            RETURN = dp;
        } else {
            int dis = apos - bpos + n;
            vector<int> &List = DisList[dis];
            vector<int>::iterator it =
                lower_bound(List.begin(), List.end(), apos, cmp);
            if (it == List.end() || *it == apos) {
                RETURN = max(apos, bpos);
            } else {
                int lastapos = *it;
                RETURN = dfs(lastapos, bpos - apos + lastapos, deep + 1) +
                         apos - lastapos;
            }
        }
    }
    return RETURN;
}

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);

        init();
        for (int i = 1; i <= n; i++)
            scanf("%d", &queue_a[i]);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &queue_b[i]);
            bposList[queue_b[i]] = i;
        }


        for (int apos = n; apos >= 1; --apos) {
            int a = queue_a[apos];
            for (int b = a - k; b <= a + k; ++b) {
                int bpos = bposList[b];
                int dis = apos - bpos + n;
                DisList[dis].push_back(apos);
            }
        }

        printf("%d\n", dfs(n, n, 1));
    }
    return 0;
}
