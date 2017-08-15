/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include<algorithm>
using namespace std;

const int maxn = 5000001;
const int maxm = 4;

int dp(int m,int n) {
    if(m == 0)
        return n + 1;
    if(m == 1)
        return n + 2;
    if(m == 2)
        return 3 + 2 * n;
    if(n == 0)
        return dp(m - 1,1);
    return 2 * dp(3,n - 1) + 3;
}

int main() {
    int m,n;
    while(cin >> m >> n) {
            cout << dp(m,n) << endl;
    }
    return 0;
}