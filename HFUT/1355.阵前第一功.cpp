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

const int maxn = 1005;
int p[maxn];

void Do() {
    int n;
    scanf("%d",&n);
    REP(n)
        scanf("%d",&p[o]);
    int q;
    scanf("%d",&q);

    sort(p,p + n);
    int k = 1;
    int ans = p[n - 1];
    for(int i = n - 1;i >= 0;i--) {
        if(ans != p[i]) {
            ans = p[i];
            k++;
        }
        if(q == k)
            break;
    }
    printf("%d\n",ans);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) 
        Do();
    return 0;
}