#include <cstdio>
using namespace std;

const int maxn = 10;
int n;
int r[maxn][maxn];

bool judge() {
    for (int i = 1; i <= n; ++i) {
        int friends = 0, notfriends = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                if (r[i][j] == 1)
                    ++friends;
                else
                    ++notfriends;
            }
        }
        if (friends >= 3 || notfriends >= 3)
            return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool ok;

        if (n >= 6) {
            for (int i = 1; i < n; i++)
                scanf("%*[^\n]");
            ok = false;
        } else {
            for (int i = 1; i < n; i++)
                for (int j = 1; j <= n - i; ++j) {
                    scanf("%d", &r[i][i + j]);
                    r[i + j][i] = r[i][i + j];
                }
            ok = judge();
        }
        printf("%s\n", ok ? "Great Team!" : "Bad Team!");
    }
    return 0;
}