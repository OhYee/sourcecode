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

const int maxn = 30005;

//并查集
int uf[maxn];
int UF(int n) {
    int t = uf[n];
    while(t != uf[t])
        t = uf[t];
    return uf[n] = t;
}



bool Do() {
    int n,m;
    if(scanf("%d%d",&n,&m),m==0&&n==0)
        return false;


    //初始化并查集
    REP(n)
        uf[o] = o;

    for(int i = 0;i < m;i++) {
        int num;
        scanf("%d",&num);
        int captain;//社团第一个设为组长
        scanf("%d",&captain);
        REP(num-1) {
            int temp;
            scanf("%d",&temp);
            uf[UF(temp)] = UF(captain);//将temp的根链接到captain的根上
        }
    }

    int cnt = 0;
    REP(n)
        if(UF(o)==UF(0))
            cnt++;

    /*REP(n)
        printf("%d %d\n",o,UF(o));*/

    printf("%d\n",cnt);


    return true;
}

int main() {
    while(Do());
    return 0;
}
