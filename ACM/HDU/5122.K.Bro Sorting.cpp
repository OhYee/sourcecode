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
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <bitset>
using namespace std;

const int maxn = 1000005;

int a[maxn];


inline int read_int() {
    char c;
    bool fs = false;
    int ans = 0;
    while(c = getchar(),!(c >= '0'&&c <= '9'))
        if(c == '-')
            fs = true;
    while(c >= '0'&&c <= '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return fs ? -ans : ans;
}

void Do() {
    int n = read_int();
    int Max = 0;
    bool flag = false;

    for(int i = 1;i <= n;i++) {
        a[i] = read_int();
    }
    int ans = 0;
    int Min = n + 1;
    for(int i = n;i >= 1;i--)
        if(Min > a[i])
            Min = a[i];
        else
            ans++;
    printf("%d\n",ans);
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++) {
        printf("Case #%d: ",i);
        Do();
    }
    return 0;
}