#include <cstdio>
using namespace std;

const int maxn = 1005;
int n;
int cnt[maxn];
void addEdge(int a, int b) {
    ++cnt[a];
    ++cnt[b];
}

int main() {
    int T;
    while (~scanf("%d", &T)) {
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b);
        }
    }
}