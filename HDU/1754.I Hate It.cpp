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

int ST[(2 << 18) + 1];
int Size;

int Query(int a,int b) {
    int l = Size + a - 1;
    int r = Size + b - 1;

    int Max = 0;
    while(r - l > 1) {
        if(l & 1) {
            Max = max(Max,ST[l]);
            l = (l >> 1) + 1;
        } else {
            l >>= 1;
        }
        if(r & 1) {
            r >>= 1;
        } else {
            Max = max(Max,ST[r]);
            r = (r >> 1) - 1;
        }

    }
    if(l == r)
        Max = max(Max,ST[l]);
    else
        Max = max(Max,max(ST[l],ST[r]));
    return Max;
}

void Update(int a,int b) {
    int pos = Size + a - 1;
    ST[pos] = b;
    pos >>= 1;
    while(pos != 0) {
        ST[pos] = max(ST[pos << 1],ST[(pos << 1) | 1]);
        pos >>= 1;
    }

}

void Build() {
    for(int i = 1;i < Size;i++)
        ST[i] = 0;
    for(int i = Size - 1;i >= 1;i--)
        ST[i] = max(ST[i << 1],ST[(i << 1) | 1]);
}

bool Do() {
    int n,m;
    if(!(cin >> n >> m))
        return false;

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

    while(m--) {
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == 'U')
            Update(a,b);
        else
            cout << Query(a,b) <<endl;
    }
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());

    return 0;
}