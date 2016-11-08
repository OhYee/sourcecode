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

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 32;

bool Do() {
    int n;
    if(!(cin >> n))
        return false;

    cout << (int)(log(n)/log(2) + eps) + 1 << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());

    return 0;
}
