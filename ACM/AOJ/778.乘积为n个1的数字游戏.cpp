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
 
 
 
void Do() {
    int p;
    scanf("%d",&p);
    int k;
    int a = 0;
    bool flag = false;
    for(k = 1;;k++) {
        a = a * 10 + 1;
        if(a < p) {
            if(flag)
            printf("0");
                continue;
        }
        int b = a / p;
        int c = a % p;
        printf("%d",b);
        flag = true;
        if(c == 0) {
            printf(" %d\n",k);
            break;
        }
        a = c;
    }
}
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}