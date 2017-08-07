#include <cstdio>
#include <iostream>
using namespace std;

// gcd(a,b)
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

// a*x + b*y = gcd(a,b)
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        long long d = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return d;
    }
}

// a*x + b*y = c
bool solve(long long a, long long &x, long long b, long long &y, long long c,
           long long minx) {
    long long d = ex_gcd(a, b, x, y);
    if (c % d)
        return false;

    long long m = b / d;
    if (m < 0)
        m = -m;
    x *= c / d;
    x = (x % m + m) % m;
    y = (c - a * x) / b;
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    long long s1, s2, v1, v2, m;
    while (cin >> s1 >> s2 >> v1 >> v2 >> m) {
        long long x, y;
        if (solve(v1 - v2, x, m, y, s2 - s1, 0))
            cout << x << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}