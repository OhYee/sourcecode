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

const int maxn = 150005;


bool Do() {
    int n,d,h;
    if(scanf("%d%d%d",&n,&d,&h) == EOF)
        return false;

    //printf("\n%d %d %d\n",n,d,h);

    if(h * 2 < d) {
        printf("-1\n");
        return true;
    }


    if(d == h) {
        if(d == 1 && n != 2) {
            printf("-1\n");
            return true;
        }

        int pos = 2;

        for(int i = 0;i < h;i++) {
            printf("%d %d\n",pos - 1,pos);
            pos++;
        }
        
        while(pos <= n)
            printf("2 %d\n",pos++);

    } else {
        int pos = 2;

        for(int i = 0;i < h;i++) {
            printf("%d %d\n",pos - 1,pos);
            pos++;
        }

        for(int i = 0;i < d - h;i++) {
            if(i == 0) {
                printf("1 %d\n",pos);
            } else {
                printf("%d %d\n",pos - 1,pos);
            }
            pos++;
        }

        while(pos <= n)
            printf("1 %d\n",pos++);

    }

    return true;
}


int main() {
    while(Do());
    return 0;
}