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
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int money[13] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};


int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        double x,y;
        scanf("%lf%lf",&x,&y);
        int xx = (int)(x * 1000)/10;
        int yy = (int)(y * 1000)/10;
        //printf("%d(%f) %d(%f)\n",xx,x,yy,y);
        //加入买（i/100）元的东西
        for(int i = 1;;++i) {
            bool ok = false;
            //要找的钱为m
            int m = xx - i;
            int ans = 0;
            //模拟找钱，还需找m元
            for(int j = 12;money[j] != yy;j--) 
                if(!((xx - i) % money[j])) {
                    ok = true;
                    break;
                }
            if(ok)
                continue;
            //从大往小找
            for(int j = 12;j >= 0;j--) {
                //已经找到所求的这一层
                if(money[j] == yy) {
                    if(m / yy) {
                        printf("%g\n",(double)i / 100);
                        ok = true;
                        break;
                    } else
                        continue;
                }
                m -= (m / money[j])*money[j];
            }
            if(ok)
                break;
        }
    }
    return 0;
}
