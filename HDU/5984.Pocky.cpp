/*//
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        double a, b;
        cin >> a >> b;
        if (a <= b)
            cout << "0.000000" << endl;
        else
            cout << fixed << setprecision(6) << 1.0 + log(a / b) << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
