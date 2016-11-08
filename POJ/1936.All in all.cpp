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

const int maxn = 100005;

bool Do() {
    char s[maxn],t[maxn];
    if(scanf("%s%s",s,t) == EOF)
        return false;
    
    int t_len = strlen(t);
    int s_len = strlen(s);

    int it = 0;
    for(int i = 0;i < t_len;i++) {
        if(s[it] == t[i])
            it++;
        if(it == s_len)
            break;
    }

    printf("%s\n",(it == s_len) ? "Yes" : "No");

    return true;
}

int main() {
    while(Do());
    return 0;
}