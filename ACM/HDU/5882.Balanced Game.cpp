/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリ0隶�
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

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;


void Do() {
    int n;
    cin >> n;
    if(n & 1)
        cout << "Balanced" << endl;
    else
        cout << "Bad" << endl;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--)
        Do();

    return 0;
}