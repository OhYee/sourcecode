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
 
const int maxn = 100010;
 
struct node {
    int n;
    int speed;
};
 
bool compare(node a,node b) {
    return a.speed > b.speed;
}
 
int n;
int m;
long long money[maxn];
node s[maxn];
//int speed[maxn];
//int r[maxn];
 
 
 
//bool compare(int a,int b) {
//  return speed[a] > speed[b];
//}
 
//优化输入
inline int read() {
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
inline void write(long long n) {
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
 
int main() {
 
    //scanf("%d%d",&n,&m);
    n = read();
    m = read();
    memset(money,0,sizeof(money));
 
    REP(n) {
        //r[o + 1] = o + 1;
        //speed[o + 1] = read();
        //scanf("%d",&speed[o + 1]);
        s[o + 1].n = o + 1;
        s[o + 1].speed = read();
    }
 
    sort(s + 1,s + n + 1,compare);
 
    REP(m) {
        int a;
        long long b,c;
        //scanf("%lld%lld%lld",&a,&b,&c);
        a = read();
        b = (long long)read();
        c = (long long)read();
        money[a] -= b*c;
        for(int i = 1;i <= b;i++)
            money[s[i].n] += c;
    }
    REP(n) {
        write(money[o + 1]);
        putchar(' ');
    }
    //printf("%lld ",money[o+1]);
 
    return 0;
}