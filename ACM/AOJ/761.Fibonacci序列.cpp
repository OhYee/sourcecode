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
 
const int maxn = 100005;
int f[maxn];
int F(int n) {
    if(f[n] == -1) {
         f[n] = F(n - 1) + F(n - 2);
    }
    return f[n];
}
 
bool Do() {
    int n;
    if(scanf("%d",&n),n<0)
        return false;
 
    //printf("%d %d ",n,F(n));
    printf((F(n) % 3) == 0 ? "Yes\n" : "No\n");
 
    return true;
}
 
int main() {
    memset(f,-1,sizeof(f));
 
    f[0] = 7;
    f[1] = 11;
 
    while(Do());
    return 0;
}