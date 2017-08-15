/*
By:OhYee
Github:OhYee
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
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int Do(int N,int M) {
    int b = 0,a = 0,ans = 0;
    //a酒瓶 b酒瓶盖
    ans = N / M;//能买的酒数目

    ans += ans / 2;

    a = ans;
    b = ans;

    int t = 0;
    while(!(a < 4 && b < 10 && t != 1)) {
        t += a / 4 + b / 10;
        a -= (a / 4) * 4;
        b -= (b / 10) * 10;
        int add = (t / 2) * 2;

        //如果这一轮没有不能兑换，则兑换之前没兑换的
        if(add == 0)
            add = t;
        
        t -= add;
        add += add / 2;
        ans += add;
        a += add;
        b += add;
    }
    return ans;
}

int main() {
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF) {
        printf("%d\n",Do(a,b));
    }
    return 0;
}