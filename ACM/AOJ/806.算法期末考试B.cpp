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
 
const int maxn = 1000;
 
int Map[maxn][maxn];
 
bool Do() {
    int n;
     
    if(scanf("%d",&n) == EOF)
        return false;
 
    memset(Map,0,sizeof(Map));
 
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
            scanf("%d",&Map[i][j]);
 
    for(int i = n - 1;i > 0;i--)
        for(int j = 1;j <= i;j++)
            Map[i][j] += max(Map[i + 1][j],Map[i + 1][j + 1]);
    printf("%d\n",Map[1][1]);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}