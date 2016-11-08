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


struct Point {
    int x,y;
    Point(int x,int y):x(x),y(y) {}
    static double distance(Point a,Point b) {
        long long t = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
        return sqrt(t);
    }
};

struct Node {
    Point pos;
    int r;
    int w;
    Node(Point pos,int r,int w):pos(pos),r(r),w(w) {}

};
Node node[maxn];


int vs_main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        for(int i = 1;i <= n;i++) {
            int x,y,r,w;
            cin >> x >> y >> r >> w;
            node[i] = Node(Point(x,y),r,w);
        }

        //缩点


    }
}