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
 
const int maxn = 50005;
char s[maxn];
int dp[maxn];
int ss[maxn];
 
bool Do() {
    scanf("%s",s);
    if(s[0] == '0')
        return false;
    int len = strlen(s);
 
    int pos = 1;
    for(int i = 0;i < len;i++) {
        ss[pos] = s[i] - '0';
        if(ss[pos] == 0) {
            ss[pos - 1] = ss[pos - 1] * 10 + ss[pos];
        } else {
            pos++;
        }
    }
 
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
 
 
    for(int i = 2;i < pos;i++) {
        int num = ss[i - 1];
        int k = ss[i];
        while(k) {
            num *= 10;
            k /= 10;
        }
        num += (ss[i]);
 
        if(num <= 26)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
 
    }
 
    printf("%d\n",dp[pos - 1]);
 
    return true;
}
 
 
 
int main() {
    while(Do());
    return 0;
}