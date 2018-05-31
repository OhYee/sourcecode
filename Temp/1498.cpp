#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    long long n, q;
    cin >> n >> q;

    long long robotTime = 0;
    long long robotNum = 1;
    long long ans = robotTime * q + n / robotNum + (n % robotNum ? 1 : 0);

    while (robotNum < n && robotTime < n) {
        robotTime += 1;
        robotNum *= 2;
        ans = min(ans, robotTime * q + n / robotNum + (n % robotNum ? 1 : 0));
    }

    cout << ans << endl;
    return 0;
}