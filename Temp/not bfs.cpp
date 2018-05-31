#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node {
    long long n;
    long long dis;
    Node(int _n, int _dis) : n(_n), dis(_dis) {}
};

const long long INF = 9999999999;

queue<Node> Q;
long long bfs(long long a, long long b) {
    if (a >= b)
        return a - b;
    while (!Q.empty()) {
        Q.pop();
    }

    long long ans = INF;

    Q.push(Node(a, 0));
    while (!Q.empty()) {
        printf("%lld\n",ans);
        int t = Q.front().n;
        int dis = Q.front().dis;
        Q.pop();
        if (a >= b)
            ans = min(ans, a - b + dis);
        if (dis >= ans)
            break;

        Q.push(Node(t * 2, dis + 1));
        Q.push(Node(t + 1, dis + 1));
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long a, b;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
    return 0;
}