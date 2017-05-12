#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Map[1025][1025];

int main() {
    freopen("out.txt", "r", stdin);
    memset(Map, false, sizeof(Map));
    int x,y,k;
    int Max=0;
    while (scanf("%d%d%d", &x, &y, &k) != EOF) {
        Max=max(Max,x);
        Map[x][y] = true;
        if (k == 1) {
            Map[x - 1][y] = true;
            Map[x][y - 1] = true;
        } else if (k == 2) {
            Map[x - 1][y] = true;
            Map[x][y + 1] = true;
        } else if (k == 3) {
            Map[x][y - 1] = true;
            Map[x + 1][y] = true;
        } else {
            Map[x][y + 1] = true;
            Map[x + 1][y] = true;
        }
    }
    for (int i = 1; i <= Max; i++)
        for (int j = 1; j <= Max; j++)
            if (!Map[i][j])
                printf("%d %d\n", i, j);
    return 0;
}