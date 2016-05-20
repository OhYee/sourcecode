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
 
//初始化
#define mst(a) memset(a,-1,sizeof(a))
 
const int maxn = 1005;
int visited[maxn];
 
bool Do() {
    long long n;
    if(scanf("%lld",&n) == EOF)
        return false;
 
    mst(visited);
 
    int N,M,e = 1;
    long long k = n;
    while(k < 1000) {
        k *= n;
        e++;
    }
    k %= 1000;
    for(int i = 0;;i++) {
        if(visited[k] != -1) {
            N = e + i;
            M = visited[k];
            break;
        } else {
            visited[k] = e + i;
        }
        k *= n;
        k %= 1000;
    }
 
    printf("%d %d\n",M,N);
 
    return true;
}
 
int main() {
    while(Do());
    return 0;
}