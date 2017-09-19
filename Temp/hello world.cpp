#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int l = 0, n;
    while (~scanf("%d", &n)) {
        printf("%d ", (int)(log(n - l + 1) / log(2)));
        l = n;
    }
    return 0;
}
