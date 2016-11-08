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

const int maxn = 1005;
struct Node {
    int a,b;
    bool operator < (const Node &rhs)const {
        if(b == rhs.b)
            return a < rhs.a;
        return b > rhs.b;
    }
};

int kase = 1;
Node s[maxn];


bool Do() {
    int n;
    cin >> n;
    if(n == 0)
        return false;

    for(int i = 0;i < n;i++)
        cin >> s[i].a >> s[i].b;

    sort(s,s + n);

    int end = 0;
    int time = 0;
    for(int i = 0;i < n;i++) {
        time += s[i].a;
        end = max(end,time + s[i].b);
    }
    cout <<"Case "<<kase++<<": "<< end << endl;
    return true;
}

int main() {
    while(Do());
    return 0;
}