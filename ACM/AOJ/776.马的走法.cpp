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

const int maxn = 105;
const int delta[] = {-1,-1,1,1,2,-2,2,-2};
bool vis[10][10];

int vx,vy;
int cnt;

void DFS(int x,int y) {
    if(x == vx&&y == vy) {
        cnt++;
        if(cnt)
            return;
    }

    if(vis[x][y])
        return;
    vis[x][y] = true;

    for(int i = 0;i < 8;i++) {
        int xx = x + delta[i];
        int yy = y + delta[7 - i];
        if(!(xx >= 1 && xx <= 4 && yy >= 1 && yy <= 5))
            continue;
        DFS(xx,yy);
    }
    vis[x][y] = false;
}

bool Do() {
    if(scanf("%d%d",&vx,&vy) == EOF)
        return false;
    memset(vis,false,sizeof(vis));
    cnt = -1;
    DFS(vx,vy);
    printf("%d\n",cnt);
    return true;
}

int main() {
    while(Do());
    return 0;
}