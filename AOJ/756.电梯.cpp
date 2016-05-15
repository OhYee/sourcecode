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
 
bool Do() {
    int n;
    if(scanf("%d",&n),n == 0)
        return false;
 
    int floor = 0;
    int ans = 0;
    REP(n) {
        int temp;
        scanf("%d",&temp);
        if(temp < floor) {
            ans += 4 * (floor - temp);
            floor = temp;
        }
        if(temp > floor) {
            ans += 6 * (temp - floor);
            floor = temp;
        }
    }
    //ans += floor * 4;
    ans += n * 5;
    printf("%d\n",ans);
 
    return true;
}
 
int main() {
    while(Do());
    return 0;
}