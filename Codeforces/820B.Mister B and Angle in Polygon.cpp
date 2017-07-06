/*/
#define debug
#include <ctime>
//*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const double eps = 1e-5;

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    double n, a;
    while (cin >> n >> a) {
        double tot = 180 * (n - 2);
        double t = tot / n;
        double Min = 9e9;
        double pos = 0;
        for (int i = 1; i <= n - 2; i++) {
            double temp = (180 * i - t * i) / 2;
            //cout << "2 1 " << i + 2 << " " << temp << " " << fabs(temp - a)
                 //<< " "<<Min<<endl;
            if (fabs(temp - a) < Min) {
                Min = fabs(temp - a);
                pos = i;
            }
        }
        cout << "2 1 " << pos + 2 << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}