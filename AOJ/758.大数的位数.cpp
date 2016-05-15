/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/
 
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
using namespace std;
 
//DEBUG MODE
#define debug 0
 
//循环
#define REP(n) for(int o=0;o<n;o++)
 
const int maxn = 10005;
bool tree[maxn];
 
int bit(int n) {
    int a = 1;
    int e = 0;
 
    for(int i = 1;i <= n;i++) {
        a *= i;
        while(a / 100000) {//保证精度
            a /= 10;
            e++;
        }
    }
 
    while(a) {//转化为位数
        a /= 10;
        e++;
    }
 
    return e;
}
 
//n! = 1*2*3*4*5*......*(n-1)*n
//ln n! = ln 1+len2+......ln(n-1)+ln n
int mathbit(int n) {
    double ans = 0;
    for(int i = 1;i <= n;i++)
        ans += log10(i);
    return (int)ans+1;
}
 
 
bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
 
 
    printf("%d\n",mathbit(n));
    return true;
}
 
int main() {
    while(Do());
    return 0;
}