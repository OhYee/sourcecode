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
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)

const int maxn = 1005;

struct Time {
    int PTime,MTime;
    int delta;
    Time(int x=0,int y=0) {
        PTime = x;
        MTime = y;
        delta = x - y;
    }
    bool operator < (const Time &rhs)const {
        return delta > rhs.delta;
    }
};

Time UseTime[maxn];

void Do() {
    int t,n,UT=0;
    scanf("%d",&n);

    int sum = 0;
    REP(n) {
        int a,c;
        scanf("%d%*d%d",&a,&c);
        sum += c;
        UT += a;
        UseTime[o] = Time(a,c);
    }

    scanf("%d",&t);

    if(sum > t) {
        printf("Oh,my god!\n");
        return;
    }

    sort(UseTime,UseTime + n);

    int ans = n;
    for(int i = 0;UT > t;i++) {
        ans--;
        UT -= UseTime[i].delta;
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