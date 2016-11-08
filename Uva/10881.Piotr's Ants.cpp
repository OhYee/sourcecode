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

const int maxn = 10005;

struct Node {
    int n;
    int pos;
    char d;
    bool operator < (const Node & rhs)const {
        return pos < rhs.pos;
    }
    static bool compare(Node &a,Node &b) {
        return a.n < b.n;
    }
};
Node ants[maxn];

int kase = 1;
int num[maxn];

void Do() {
    int L,T,n;
    cin >> L >> T >> n;

    for(int i = 0;i < n;i++) {
        cin >> ants[i].pos >> ants[i].d;
        ants[i].n = i;
    }

    sort(ants,ants + n);

    for(int i = 0;i < n;i++) {
        num[ants[i].n] = i;
        if(ants[i].d == 'L')
            ants[i].pos -= T;
        else
            ants[i].pos += T;
    }

    sort(ants,ants + n);

    for(int i = 1;i < n;i++)
        if(ants[i].pos == ants[i - 1].pos)
            ants[i].d = ants[i - 1].d = 'T';

    cout << "Case #" << kase++ << ":" << endl;
    for(int i = 0;i < n;i++) {
        int t = num[i];
        if(ants[t].pos > L || ants[t].pos < 0)
            cout << "Fell off" << endl;
        else
            if(ants[t].d == 'T')
                cout << ants[t].pos << " Turning" << endl;
            else
                cout << ants[t].pos << " " << ants[t].d << endl;
    }
    cout << endl;

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