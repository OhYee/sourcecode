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
#include <bitset>
#include <iomanip> 
using namespace std;

const int maxn = 27;
bool vis[maxn];

void Do() {
    char c = getchar();;

    memset(vis,false,sizeof(vis));
    int ans = 0;
    while(!(c >= 'a'&&c <= 'z'))
        c=getchar();
    while(c >= 'a'&&c <= 'z') {
        int t = c - 'a';
        if(!vis[t]) {
            ans++;
            vis[t] = true;
        }

        c = getchar();
    }
    printf("%d\n",ans);
}

int main() {
    //cin.tie(0);
    //cin.sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++) {
        printf("Case #%d: ",i);
        Do();
    }
    return 0;
}