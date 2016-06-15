
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
#include <set>
using namespace std;
 
//DEBUG MODE
#define debug 0
 
//循环
#define REP(n) for(int o=0;o<n;o++)
 
const int INF = 2<<30-1;
const int maxn = 50005;
int a[maxn];
 
int dfs(int *a,int l,int r) {
    if(l == r)
        return a[l];
    if(l > r)
        return -INF;
 
    int mid = (l + r) / 2;
    int Max;
    int ans;
    //中间
    ans = 0;
    int maxl = 0;
    for(int i = mid - 1;i >= l;i--) {
        ans += a[i];
        if(ans > maxl)
            maxl = ans;
    }
    ans = 0;
    int maxr = 0;
    for(int i = mid + 1;i <= r;i++) {
        ans += a[i];
        if(ans > maxr)
            maxr = ans;
    }
    Max = maxl + a[mid] + maxr;
 
    //左侧
    Max = max(Max,dfs(a,l,mid - 1));
 
    //右侧
    Max = max(Max,dfs(a,mid + 1,r));
 
    return Max;
}
 
bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
 
    printf("%d\n",dfs(a,0,n - 1));
    return true;
}
 
int main() {
    while(Do());
    return 0;
}