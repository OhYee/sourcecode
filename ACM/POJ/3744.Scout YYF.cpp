/*/
#define debug
#include <ctime>
//*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 15;

double pow(double a, int n) {
    if (n == 0)
        return 1.0;
    if (n == 1)
        return a;
    double ans = pow(a, n / 2);
    ans = ans * ans;
    if (n & 1)
        ans *= a;
    return ans;
}
double f(int n,double p){
    return 1 + (p - 1) * (1 - pow(p - 1, n - 1)) / (2 - p);
}

int mines[maxn];

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false); 
    int n;
    double p;
    while (cin >> n >> p) {
        mines[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> mines[i];

        sort(mines + 1, mines + 1 + n);

        double ans = 1;
        for (int i = 1; i <= n; i++) {
            int dis = mines[i] - mines[i - 1];

            double dp = f(dis,p); 
            //cout <<"\t "<<dis<<" "<< dp<<endl;
            ans *= (1 - dp);
        }

        cout << fixed << setprecision(7) << ans << endl;
    }

#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}