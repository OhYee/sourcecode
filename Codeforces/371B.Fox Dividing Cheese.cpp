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
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <iomanip> 
using namespace std;

const int d[] = {2,3,5};

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a%b);
}

bool Do() {
    int a,b;
    if(!(cin >> a >> b))
        return false;

    if(a == b) {
        cout << 0 << endl;
        return true;
    }


    int ans = 0;
    int g = gcd(a,b);

    a /= g;
    b /= g;
    for(int i = 0;i < 3;i++) {
        while(a%d[i] == 0) {
            a /= d[i];
            ans++;
        }
        while(b%d[i] == 0) {
            b /= d[i];
            ans++;
        }
    }
    if(a == 1 && b == 1)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());
    return 0;
}
