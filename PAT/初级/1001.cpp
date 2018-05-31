#include <cstdio>

int getAns(int n) {
    int cnt = 0;
    while (n > 1) {
        ++cnt;
        if (n % 2) {
            n = (n * 3 + 1) / 2;
        } else {
            n /= 2;
        }
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", getAns(n));
    return 0;
}