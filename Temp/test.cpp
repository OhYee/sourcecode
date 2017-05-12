#include<cstdio>
#include<algorithm>
#include<iostream>
#include <ctime>
#include<cstring>
using namespace std;
#define M(a, b) memset(a, b, sizeof(a))
const int N = 1050;
int nx, ny;
int G[N][N];

int judge(int xx, int yy, int x, int y) {
    if (xx>=x&&yy>=y) return 1;
    else if (xx>=x&&yy+1<=y) return 2;
    else if (xx+1<=x&&yy>=y) return 3;
    else return 4;
}

void Do(int x1, int y1, int x2, int y2, int x, int y) {
    if (x2 - x1 + 1 == 2) {
        if (G[x1][y1] == G[x1][y2] == G[x2][y1] == G[x2][y2] == 1) return;
        int xx, yy, tt;
        if (G[x1][y1]) xx = x1+1, yy = y1+1, tt = 1;
        else if (G[x1][y2]) xx = x1+1, yy = y2-1, tt = 2;
        else if (G[x2][y1]) xx = x2-1, yy = y1+1, tt = 3;
        else if (G[x2][y2]) xx = x2-1, yy = y2-1, tt = 4;
        printf("%d %d %d\n", xx, yy, tt);
        G[x1][y1] = G[x1][y2] = G[x2][y1] = G[x2][y2] = 1;
        return;
    }
    int xx = (x1+x2)/2, yy = (y1+y2)/2;
    int k = judge(xx, yy, x, y);
    if (k == 1) {
        printf("%d %d 1\n", xx+1, yy+1);
        G[xx+1][yy+1] = G[xx+1][yy] = G[xx][yy+1] = 1;
        Do(x1, y1, xx, yy, x, y);
        Do(x1, yy+1, xx, y2, xx, yy+1);
        Do(xx+1, y1, x2, yy, xx+1, yy);
        Do(xx+1, yy+1, x2, y2, xx+1, yy+1);
    }
    else if (k == 2) {
        printf("%d %d 2\n", xx+1, yy);
        G[xx+1][yy+1] = G[xx+1][yy] = G[xx][yy] = 1;
        Do(x1, y1, xx, yy, xx, yy);
        Do(x1, yy+1, xx, y2, x, y);
        Do(xx+1, y1, x2, yy, xx+1, yy);
        Do(xx+1, yy+1, x2, y2, xx+1, yy+1);
    }
    else if (k == 3) {
        printf("%d %d 3\n", xx, yy+1);
        G[xx+1][yy+1] = G[xx][yy] = G[xx][yy+1] = 1;
        Do(x1, y1, xx, yy, xx, yy);
        Do(x1, yy+1, xx, y2, xx, yy+1);
        Do(xx+1, y1, x2, yy, x, y);
        Do(xx+1, yy+1, x2, y2, xx+1, yy+1);
    }
    else if (k == 4) {
        printf("%d %d 4\n", xx, yy);
        G[xx][yy] = G[xx+1][yy] = G[xx][yy+1] = 1;
        Do(x1, y1, xx, yy, xx, yy);
        Do(x1, yy+1, xx, y2, xx, yy+1);
        Do(xx+1, y1, x2, yy, xx+1, yy);
        Do(xx+1, yy+1, x2, y2, x, y);
    }
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int START = clock();

    int n;
    while (~scanf("%d", &n)) {
        M(G, 0);
        scanf("%d%d", &nx, &ny);
        G[nx][ny] = 1;
        int nn = 1;
        for (int i = 0; i < n; ++i) nn *= 2;
        Do(1, 1, nn, nn, nx, ny);
    }
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    return 0;
}