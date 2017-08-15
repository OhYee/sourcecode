/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
using namespace std;
inline bool islower(char c) {
    return (c >= 'a'&&c <= 'z');
}
inline bool isupper(char c) {
    return (c >= 'A'&&c <= 'Z');
}
bool Do() {
    int dp=0;
    bool Cap = false;
    char c = getchar(),last = 'a';
    while(!(islower(c) || isupper(c)))
        c=getchar();
    while(islower(c) || isupper(c)) {
        if(islower(c)) {
            //字符是小写
            if(Cap) {
                if(islower(last)) {
                    dp += 1;
                    Cap = false;
                } else {
                    dp += 2;
                }
            } else {
                dp++;
            }
        } else {
            if(Cap) {
                dp++;
            } else {
                if(isupper(last)) {
                    dp++;
                    Cap = true;
                } else {
                    dp += 2;
                }
            }
        }
        last = c;
        c = getchar();
    }
    if(Cap)
        if(isupper(last))
            dp++;
    printf("%d\n",dp);
    return true;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}