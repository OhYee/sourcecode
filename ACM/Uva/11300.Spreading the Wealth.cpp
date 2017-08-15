/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

const int maxn = 1000005;

long long a[maxn];

bool Do() {
    int n;
    if(!(cin >> n))
        return false;

    long long sum = 0;
    for(int i = 0;i < n;i++) {
        long long t;
        cin >> t;
        sum += t;
        if(i == 0)
            a[0] = t;
        else
            a[i] = sum - a[0];
    }
    sum /= n;
    for(int i = 0;i < n;i++) {
        if(i == 0)
            a[0] = 0;
        else
            a[i] -= i*sum;
    }
    sort(a,a + n);

    sum = 0;
    for(int i = 0;i < n;i++)
        sum += abs(a[i] - a[n / 2 - 1]);

    cout << sum << endl;
    return true;
}

int main() {
    while(Do());
    return 0;
}