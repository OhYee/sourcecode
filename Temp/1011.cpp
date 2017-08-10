#include <cstdio>

using namespace std;

int num[10];

int calc() {
    int ABC = num[6];
    int AC = num[5] - ABC;
    int BC = num[4] - ABC;
    int AB = num[3] - ABC;
    int C = num[2] - ABC - AC - BC;
    int B = num[1] - ABC - AB - BC;
    int A = num[0] - ABC - AB - AC;
    if (A < 0 || B < 0 || C < 0 || AB < 0 || AC < 0 || BC < 0 || ABC < 0)
        return -1;
    else
        return A + B + C + AB + AC + BC + ABC;
}

int main() {
    int T;
    scanf("%d", &T);
    while (--T) {
        int n;
        int ans = -1;
        for (int i = 0; i < 7; i++) {
            scanf("%d"),&num[i]);
            if (ans == -1)
                ans = calc();
        }
        printf("%d\n", ans);
    }
}