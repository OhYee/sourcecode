#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 105;

typedef long long ll;
ll seats[maxn];

void add(int s, int t, ll k) {
    for (int i = s; i < t; ++i)
        seats[i] += k;
}

ll get() {
    ll Max = 0;
    for (int i = 1; i <= 100; ++i)
        Max = max(Max, seats[i]);
    return Max;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    while (cin >> n, n != 0) {
        memset(seats, 0, sizeof(seats));
        while (n--) {
            int s, t;
            ll k;
            cin >> s >> t >> k;
            add(s, t, k);
        }
        cout << get() << endl;
    }
    cout << "*" << endl;
    return 0;
}