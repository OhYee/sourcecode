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

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

int kase = 1;

int ST[(2 << 16) + 1];
int Size;
int n;


int Query(int a,int b) {
    int l = Size + a - 1;
    int r = Size + b - 1;

    int sum = 0;
    while(r - l > 1) {
        if(l & 1) {
            sum += ST[l];
            l = (l >> 1) + 1;
        } else {
            l >>= 1;
        }
        if(r & 1) {
            r >>= 1;
        } else {
            sum += ST[r];
            r = (r >> 1) - 1;
        }

    }
    if(l == r)
        sum += ST[l];
    else
        sum += ST[l] + ST[r];
    return sum;
}

void Add(int a,int b) {
    int pos = Size + a - 1;
    while(pos != 0) {
        ST[pos] += b;
        pos >>= 1;
    }

}

inline void Sub(int a,int b) {
    Add(a,-b);
}

void Build() {
    for(int i = 1;i < Size;i++)
        ST[i] = 0;
    for(int i = Size - 1;i >= 1;i--)
        ST[i] = ST[i << 1] + ST[(i << 1) + 1];
}

void Do() {
    cin >> n;
    Size = 1;
    while(Size < n)
        Size <<= 1;

    for(int i = 1;i < Size;i++) {
        if(i <= n)
            cin >> ST[Size + i - 1];
        else
            ST[Size + i - 1] = 0;
    }

    Build();

    cout << "Case " << kase++ << ":" << endl;

    string s;

    while(cin >> s,s != "End") {
        int a,b;
        cin >> a >> b;
        if(s == "Query")
            cout << Query(a,b) << endl;
        else if(s == "Sub")
            Sub(a,b);
        else
            Add(a,b);
    }

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