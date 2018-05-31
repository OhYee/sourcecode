#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e5;

int getAns(int n) {
    int cnt = 0;
    while (n) {
        n >>= 1;
        cnt++;
    }
    return cnt;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", getAns(n));
    }

    return 0;
}