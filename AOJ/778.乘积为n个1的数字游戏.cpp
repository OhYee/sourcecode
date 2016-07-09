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
 
bool vis[10];
void Do() {
    int n;
    scanf("%d",&n);
 
    int cnt = 0;
    for(int i = 10000;i <= 31622 && i <= n;i++) {
        memset(vis,false,sizeof(vis));
        bool flag = true;
 
        int k = i*i;
        while(k) {
            if(vis[k % 10]) {
                flag = false;
                break;
            }
            vis[k % 10] = true;
            k /= 10;
        }
        if(flag)
            cnt++;
    }
    printf("%d\n",cnt);
}
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
        Do();
    return 0;
}