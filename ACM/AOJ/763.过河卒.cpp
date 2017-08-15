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
#define mst(a,n) memset(a,n,sizeof(a))
 
int Map[25][25];
const int MOD = 1000000007;
 
bool Do() {
    int x1,y1,x2,y2;
    if(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) == EOF)
        return false;
 
    mst(Map,0);
 
    Map[x2][y2] = 1;
    for(int i = x2;i <= x1;i++)
        for(int j = y2;j <= y1;j++)
            if(!(i == x2&&j == y2))
                Map[i][j] = (Map[i][j - 1] + Map[i - 1][j]) % MOD;
    printf("%d\n",Map[x1][y1]);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}
