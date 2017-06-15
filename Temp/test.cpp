#include <stdio.h>
int f(int n) {
    int s = 1, i;
    for (i = 1; i <= n; i++)
        s *= i;
    return s;
}

int ans[45];
int ans2[45] = {0, 1};

int d(int M) {
    int m, n, k, i, sum, t;
    sum = 1;
    t = (M - 1) / 2;
    for (i = 1; i <= t; i++) {
        n = M - 1 - i * 2 + i * 1;
        m = i;
        k = f(n) / (f(n - m) * f(m));
        sum += k;
    }
    return ans[M] = m;
}

int main(void) {
    
    for (int i = 1; i <= 40; i++) { 
        if (i != 1)
            ans2[i] = ans2[i - 1] + ans2[i - 2];
            printf("%d %d %d\n",i,ans2[i],d(i));
    }

    return 0;
}