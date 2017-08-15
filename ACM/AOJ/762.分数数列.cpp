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

const int maxn = 6000;
bool Has[maxn];
bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
    memset(Has,false,sizeof(Has));
    int last = 1;
    for(int i = 1;i <= n;i++) {
        int j;
        for(j = last;Has[j];j++);
        Has[j] = true;
        Has[j + i] = true;
        last = j;
        if(i == n)
            printf("%d/%d\n",j,j + i);
    }
    return true;
}
 
int main() {
    while(Do());
    return 0;
}