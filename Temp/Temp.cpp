#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    long long sum = 0;
    long long jc = 1;
    for (int i = 1; i <= 18; i++) {
        jc *= i;
        if (i % 3 == 0)
            sum += jc;
    }
    printf("%lld\n", sum);
    return 0;
}