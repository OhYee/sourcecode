#include <cmath>
#include <cstdio>
int main() {
    double x, y;
    while (~scanf("%lf%lf", &x, &y))
        printf("%.6f\n", atan2(y, x));
    return 0;
}