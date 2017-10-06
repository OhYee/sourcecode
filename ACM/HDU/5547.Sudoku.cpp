#include <cstdio>
#include <cstring>
using namespace std;

char m[5][5];
bool vis[5][5][5];
int p[4][2];

void output() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            if (m[i][j] == '*') {
                printf(" %d%d%d%d", vis[i][j][1], vis[i][j][2], vis[i][j][3],
                       vis[i][j][4]);
            } else
                printf("%5d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool _Change() {
    bool change = false;
    bool has[5];
    memset(has, false, sizeof(has));

    // for (int i = 0; i < 4; ++i) {
    //     printf("(%d %d) ", p[i][0], p[i][1]);
    // }
    // printf("\n");

    for (int i = 0; i < 4; ++i) {
        int x = p[i][0], y = p[i][1];
        if (m[x][y] != '*')
            has[(int)m[x][y]] = true;
    }

    for (int j = 1; j <= 4; ++j) {
        if (has[j] == true) {
            for (int i = 0; i < 4; ++i) {
                int x = p[i][0], y = p[i][1];
                if (m[x][y] == '*' && vis[x][y][j] == false) {
                    change = true;
                    vis[x][y][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        int x = p[i][0], y = p[i][1];
        if (m[x][y] == '*') {
            int ok = 0;
            for (int j = 1; j <= 4; ++j) {
                if (vis[x][y][j] == false) {
                    if (ok == 0) {
                        ok = j;
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0)
                m[x][y] = ok;
        }
    }
    return change;
}

bool Change() {
    bool ok = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            p[j][0] = i;
            p[j][1] = j;
        }
        ok |= _Change();
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            p[j][0] = j;
            p[j][1] = i;
        }
        ok |= _Change();
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p[i * 2 + j][0] = i;
            p[i * 2 + j][1] = j;
        }
    }
    ok |= _Change();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p[i * 2 + j][0] = i + 2;
            p[i * 2 + j][1] = j;
        }
    }
    ok |= _Change();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p[i * 2 + j][0] = i;
            p[i * 2 + j][1] = j + 2;
        }
    }
    ok |= _Change();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p[i * 2 + j][0] = i + 2;
            p[i * 2 + j][1] = j + 2;
        }
    }
    ok |= _Change();

    return ok;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        for (int i = 0; i < 4; ++i)
            scanf("%s", m[i]);

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (m[i][j] == '*')
                    memset(vis[i][j], false, sizeof(vis[i][j]));
                else
                    m[i][j] = m[i][j] - '0';

        while (Change()) ;
        printf("Case #%d:\n", kase);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                printf("%d", m[i][j]);
            printf("\n");
        }
    }
    return 0;
}