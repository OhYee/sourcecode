/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

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
#include <functional>
using namespace std;

const int maxn = 35;

bool  Do() {
    int t,s,x;
    if(scanf("%d%d%d",&t,&s,&x) == EOF)
        return false;
    
    bool flag = true;
    for(int i = 0;;i++) {
        int time = t + i*s;
        if(x == time) {
            printf("YES\n");
            break;
        }

        if(i != 0) {
            int time = t + i*s + 1;
            if(x == time) {
                printf("YES\n");
                break;
            }
        }

        if(x < time) {
            printf("NO\n");
            break;
        }
    }
    
    return true;
}

int main() {
    while(Do());
    return 0;
}