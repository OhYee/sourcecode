#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

typedef long long LL;

LL mulmod(LL a, LL b, LL mod) {
    LL x = 0, y = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
LL modulo(LL base, LL exponent, LL mod) {
    LL x = 1;
    LL y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1) x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
bool MiLLer(LL p, int iteration) {
    if (p < 2) return false;
    if (p != 2 && p % 2 == 0) return false;
    LL s = p - 1;
    while (s % 2 == 0) s /= 2;
    for (int i = 0; i < iteration; i++) {
        LL a = rand() % (p - 1) + 1, temp = s;
        LL mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0) return false;
    }
    return true;
}

int main() {
    int last = 1000000000;
    int Max = 0;
    for (int i = 1000000000; i >= 0; i--) {
        if (i == 1000 || i == 1000000 || i == 100000000 || i == 10000000 ||
            i == 100000)
            cout << i << " " << Max << endl;
        if (MiLLer(i, 5)) {
            Max = max(last - i, Max);
            last = i;
        }
    }
    cout << Max << endl;

    return 0;
}