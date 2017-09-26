#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

const int maxn = 4;
const int m[maxn] = {1, 5, 10, 25};
int p;
int a[maxn];

int dfs(int coin, int sum, int ans) {
    Log("%d %d %d\n", coin, sum, ans);
    if (sum == p) // 找到答案
        return ans;
    if (sum > p) // 超过要求了
        return -1;

    int target = p - sum; //距离目标还差多少

    if (coin == maxn - 1) { // 已经遍历到最后一种硬币
        int num = target / m[coin];
        if (target % m[coin] == 0 && num <= a[coin])
            return ans + num;
        else
            return -1;
    }

    // long long allchoose = sum;
    // for (int i = coin; i < maxn; ++i)
    //     allchoose += m[i] * a[i];
    // if (allchoose < p) // 剩下的全加上也达不到要求
    //     return -1;

    // 往后遍历
    int tans = -1;
    int Begin = min(target / m[coin], a[coin]);
    int End = max(0, Begin - 30);
    for (int i = Begin; i >= End; --i) {
        int tans2 = dfs(coin + 1, sum + i * m[coin], ans + i);
        if (tans2 != -1) {
            tans = tans2;
            break;
        }
    }
    return tans;
}

int main() {
    while (~scanf("%d", &p)) {
        for (int i = 0; i < maxn; ++i)
            scanf("%d", &a[i]);

        int ans = dfs(0, 0, 0);
        if (ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}