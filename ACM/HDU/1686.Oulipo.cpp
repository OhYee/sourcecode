#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000005;

char s1[maxn], s2[maxn];
int next[maxn];
void getNext(char *s) {
    int len = strlen(s);
    next[0] = -1;
    for (int i = 1; i < len; ++i) {
        int t = next[i - 1];
        while (t != -1 && s[t] != s[i - 1])
            t = next[t];
        next[i] = (s[i - 1] == s[t] ? t + 1 : 0);
    }
    //for (int i = 0; i <= len; ++i)
    //    printf("next[%d]=%d\n", i, next[i]);
}
int KMP(char *a, char *b) {
    getNext(b);
    int alen = strlen(a);
    int blen = strlen(b);
    int i = 0, j = 0;
    int ans = 0;
    while (i != alen) {
        //printf("judge a[%d](%c) b[%d](%c)\n", i, a[i], j, b[j]);
        while (j != -1 && a[i] != b[j])
            j = next[j];
        ++i, ++j;
        if (j == blen) {
            //printf("match at %d\n", i - blen);
            ++ans;
            --i;
            j = next[j - 1];
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s1, s2);
        printf("%d\n", KMP(s2, s1));
    }
    return 0;
}
