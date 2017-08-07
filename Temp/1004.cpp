//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e6 + 5;
const float eps = 1e-10;

int n;

bool Could(int n) {
    int 


    int money = 0;
    for(int i = 0;i < maxn;i++) 
        if(n*need[i] > num[i])
            money += p[i] * (n*need[i]-num[i]);
    return money > r;
}

double Division(double l,double r) {
    if(l == r) {
        return l;
    }
    double mid = (l + r) / 2;
    if(Could(mid))
        return Division(l,mid);
    else
        return Division(mid + 1,r);
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);

        printf("%.5f\n", Division(0, 1));
    }

#ifdef debug
    printf("Time:%.3fs.\n", float(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}