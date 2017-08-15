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
#include <iomanip>
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

const double eps = 1e-6;
const double l = 10000;

bool equal(double a,double b) {
    return fabs(a - b) < eps;
}
int toInt(double a) {
    return (int)(a + 0.001);
}

bool Do() {
    double n,m;
    if(!(cin >> n >> m))
        return false;

    m += n;

    double per = l / n;
    double newper = l / m;

    double ans = 0;
    for(int i = 0;i < n;i++) {
        double pos = i * per;
        double newpos = pos / newper;
        if(!equal(newpos,(double)(toInt(newpos)))) {
            int a = toInt(newpos);
            ans += min(fabs(pos - a*newper),fabs(pos - (a + 1)*newper));
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
    return true;
}

int main() {
    while(Do());
    return 0;
}