/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 10000005;

//优化输入
inline int read_int() {
    char c;
    int ans = 0;
    while(c = getchar(),!(c >= '0'&&c < '9'));
    while(c >= '0'&&c < '9') {
        ans *= 10;
        ans += (int)c - '0';
        c = getchar();
    }
    return ans;
}

//优化输出
inline void write_int(long long n) {
    char str[50];
    int len = 0;
    if(n < 0) {
        n = -n;
        putchar('-');
    }
    if(n == 0)
        putchar('0');
    while(n) {
        str[len++] = (int)(n % 10) + '0';
        n /= 10;
    }
    while(len)
        putchar(str[--len]);
    return;
}

bool is[maxn];

int vs_main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        memset(is,0,n + 1);
        REP(n + 1) {
            int temp = read_int();
            if(is[temp]) {
                write_int(o + 1);
                putchar('\n');
                while(getchar() != '\n');
                break;
            }
            is[temp] = 1;
        }
    }
    return 0;
}