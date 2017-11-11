#include <cmath>
#include <cstdio>
using namespace std;
const double PI = acos(-1.0);
int main() {
    double a;
    while (~scanf("%lf", &a)) {
        double b = a * 2 * PI / 360;
        printf("%.5f angle=%.5f cos=%.5f sin=%.5f\n", a, b, cos(b), sin(b));
    }
    return 0;
}