#include <cstdio>
#include<cstring> 
const int maxn = 105;
char s[maxn];

char pinyin[10][5] = {"ling", "yi",  "er", "san", "si",
                      "wu",   "liu", "qi", "ba",  "jiu"};

int numStack[maxn];

void toPinyin(int num) {
    int stackPos = 0;
    while (num) {
        numStack[stackPos++] = num % 10;
        num /= 10;
    }
    for (int i = stackPos - 1; i >= 0; --i) {
        printf("%s", pinyin[numStack[i]]);
        if (i)
            printf(" ");
    }
    printf("\n");
}

int main() {
    scanf("%s", s);
    int l = strlen(s);
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        ans += s[i] - '0';
    }
    toPinyin(ans);
    return 0;
}