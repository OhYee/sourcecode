#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5005;
const int maxm = 505;
const int maxk = 2005;

vector<int> v, vt;
int pos = 0;

int main() {
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        printf("%d %d %d\n", n, m, k);

        int sum = 0;
        v.clear();
        vt.clear();

        for (int i = 1; i <= n; ++i) {
            if ((int)v.size() >= k) {
                printf("ok");
                int Maxm = 0;
                for (int j = 1; j <= m; ++j) {
                    int t;
                    scanf("%d", &t);
                    Maxm = max(Maxm, t);
                }
                sum += Maxm;
                printf(" Max:%d\n", Maxm);
            } else {
                printf("not ok ");
                vt = v;
                v.clear();
                for (int j = 1; j <= m; ++j) {
                    int t;
                    scanf("%d", &t);
                    for (auto it = vt.begin(); it != vt.end(); ++it) {
                        v.push_back(*it + t);
                    }
                }
                printf("size: %u\n",v.size());
            }
        }

        sort(v.begin(), v.end());
        for (auto it = v.begin(); it != v.end(); it++)
            printf("%d ", *it);
        printf("\n");
        printf("%d\n", v[k] + sum);
    }
    return 0;
}