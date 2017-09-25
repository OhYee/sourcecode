#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
double p[4][4];
int O[105];


double calc1() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    int lst = -1, ths = -1;
    double ans = 1.0;
    while (ss >> ths) {
        if (lst != -1)
            ans *= p[lst - 1][ths - 1];
        lst = ths;
    }
    return ans;
}

double calc2() {
    int t;
    cin >> t;
    double pp = p[t - 1][t - 1];
    return 1.0 + pp / (1 - pp);
}

int main() {
    //cin.tie(0);
    //cin.sync_with_stdio(false);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> p[i][j];
    getchar();

    cout << fixed << setprecision(8) << calc1() << endl;
    cout << fixed << setprecision(8) << calc1() << endl;
    cout << fixed << setprecision(8) << calc2() << endl;
    cout << fixed << setprecision(8) << calc2() << endl;

    return 0;
}