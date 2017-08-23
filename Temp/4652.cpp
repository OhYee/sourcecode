#include <cstdio>

double pow(double a, int n) {
    if (n == 0)
        return 1.0;
    double ans = pow(a, n / 2);
    return ans*ans*(n&1?a:1);
}

int main() {
    int T;
    int c, n, m;
    double ans;

    while (scanf("%d", &T) != EOF) {
        
        while (T--) {
            scanf("%d%d%d", &c, &m, &n);

                ans = pow(1.0/m,n-1);
          
            printf("%.10f\n",1.0/ans);
        }
    }
    return 0;
}