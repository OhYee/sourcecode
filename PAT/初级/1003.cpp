#include <cstdio>
#include <cstring>

const int maxn = 105;
char s[maxn];

bool judge() {
    bool hasP = false;
    bool hasT = false;
    bool wrong = false;
    int aNums[3] = {0, 0, 0};
    int len = strlen(s);
    for (int i = 0; i < len && !wrong; ++i) {
        if (s[i] == 'A') {
            if (!hasP && !hasT)
                ++aNums[0];
            if (hasP && !hasT)
                ++aNums[1];
            if (hasP && hasT)
                ++aNums[2];
            if (!hasP && hasT)
                wrong = true;
            continue;
        }
        if (s[i] == 'P') {
            if (hasP)
                wrong = true;
            else
                hasP = true;
            continue;
        }
        if (s[i] == 'T') {
            if (hasT)
                wrong = true;
            else
                hasT = true;
            continue;
        }
        wrong = true;
    }
    return hasP && hasT && aNums[1] >= 1 && (aNums[1] * aNums[0] == aNums[2]) &&
           !wrong;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        printf("%s\n", judge() ? "YES" : "NO");
    }
    return 0;
}