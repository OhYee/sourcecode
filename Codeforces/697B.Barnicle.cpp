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

double pow(int a,int b) {
    if(b == 0)
        return 1;
    return pow(a,b - 1) * a;
}

bool  Do() {
    char b[105];
    int a,d;
    if(scanf("%d",&a) == EOF)
        return false;
    char c=getchar();
    int pos = 0;
    c = getchar();
    while(c != 'e') {
        b[pos++] = c;
        c = getchar();
    }
    scanf("%d",&d);
    putchar(a + '0');
    for(int i = 0;i < pos;i++) {
        if(i == d)
            putchar('.');
        putchar(b[i]);
    }
    for(int i = pos;i < d;i++)
        putchar('0');
    putchar('\n');

    return true;
}

int main() {
    while(Do());
    return 0;
}