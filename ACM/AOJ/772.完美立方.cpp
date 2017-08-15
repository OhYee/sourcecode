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

const int maxn = 1000;

bool Do() {
    int N;
    if(scanf("%d",&N) == EOF)
        return false;
    int a,b,c,d;
    for(a = 1;a <= N;a++) {
        int a3 = a*a*a;
        for(b = 1;b <= N;b++) {
            int b3 = b*b*b;
            if(a3 < b3)
                break;
            for(c = b;c <= N;c++) {
                int c3 = c*c*c;
                if(a3 < b3 + c3)
                    break;
                for(d = c;d <= N;d++) {
                    int d3 = d*d*d;
                    if(a3 < b3 + c3 + d3)
                        break;
                    if(a3 == b3 + c3 + d3)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                }
            }
        }
    }
    return true;
}

int main() {
    while(Do());
    return 0;
}