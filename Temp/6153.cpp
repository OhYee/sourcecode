#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) printf(format, ##__VA_ARGS__)

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

char s1[maxn], s2[maxn];
int cnt[maxn];
int Next[maxn];
void getNext(char *s) {
    int len = strlen(s);
    Next[0] = -1;
    for (int i = 1; i < len; ++i) {
        int t = Next[i - 1];
        while (t != -1 && s[t] != s[i - 1])
            t = Next[t];
        Next[i] = (s[i - 1] == s[t] ? t + 1 : 0);
    }
    // for (int i = 0; i <= len; ++i)
    //    printf("Next[%d]=%d\n", i, Next[i]);
}

int KMP(char *a, char *b) {
    getNext(b);
    int alen = strlen(a);
    int blen = strlen(b);

    // memset(cnt, 0, (blen + 5) * sizeof(int));
    // for (int i = 1; i < blen; ++i) {
    //     getCnt(i);
    // }

    int i = 0, j = 0;
    int ans = 0;
    bool back = false;
    while (i != alen) {
        // printf("judge a[%d](%c) b[%d](%c)\n", i, a[i], j, b[j]);
        while (j != -1 && a[i] != b[j])
            j = Next[j];

        ++i, ++j;
        if (j <= blen) {
            int w = cnt[j - 1] - (back ? 1 : 0);
            printf("    %d %d %d\n", i, j, w);
            ans = (int)((long long)ans + (long long)j * w) % mod;
            back = false;
        }
        if (j == blen) {
            --i;
            j = Next[j - 1];
            back = true;
        }
    }
    return ans;
}

void swap(auto &a, auto &b) {
    auto t = a;
    a = b;
    b = t;
}

void Reverse(char *s) {
    int n = strlen(s);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s1, s2);
        Reverse(s1);
        Reverse(s2);
        Log("%s %s\n", s1, s2);
        printf("%d\n", KMP(s1, s2));
    }
    return 0;
}