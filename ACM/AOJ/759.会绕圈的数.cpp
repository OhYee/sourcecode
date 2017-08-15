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
  
const int maxn = 1005;
bool visited[maxn];
  
inline int sq(int n) {
    int ans = 0;
    while(n) {
        ans += (n % 10)*(n % 10);
        n /= 10;
    }
    return ans;
}
  
bool Do() {
    int n;
    if(scanf("%d",&n),n == 0)
        return false;
  
    memset(visited,false,sizeof(visited));
    int k = n;
    while(k>maxn||!visited[k]) {
        if(k < maxn)
            visited[k] = true;
        printf("%d   ",k);
        k = sq(k);
    }
    printf("%d   \n",k);
    return true;
}
  
int main() {
    while(Do());
    return 0;
}
