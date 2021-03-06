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

const int maxn = 1005;

struct Node {
    double t,x,y;
    bool operator < (const Node &rhs)const {
        return t < rhs.t;
    }
    double operator - (const Node &rhs)const {
        return sqrt((x - rhs.x)*(x - rhs.x) + (y - rhs.y)*(y-rhs.y));
    }
};

Node note[maxn];

void Do() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> note[i].t >> note[i].x >> note[i].y;
    sort(note,note + n);

    double Max = 0;
    for(int i = 1;i < n;i++)
        Max = max(Max,(note[i] - note[i - 1]) / (note[i].t - note[i - 1].t));

    cout << fixed << setprecision(20) << Max << endl;
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