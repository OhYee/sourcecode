/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
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
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 55;


bool Do() {
    int N,a1,b1,c1,a2,b2,c2;
    int cnt = 0;
    if(scanf("%d%d%d%d%d%d%d",&N,&a1,&b1,&c1,&a2,&b2,&c2) == EOF)
        return false;

    bool map[maxn][maxn][maxn] = {0};

    for(int x = a1 - 2;x <= a1 + 2;x++)
        for(int y = b1 - 2;y <= b1 + 2;y++)
            for(int z = c1 - 2;z <= c1 + 2;z++) {
                int xx = x <= 0 ? N + x : x > N ? x - N : x;
                int yy = y <= 0 ? N + y : y > N ? y - N : y;
                int zz = z <= 0 ? N + z : z > N ? z - N : z;
                if(!map[xx][yy][zz] && xx > 0 && xx <= N&&yy > 0 && yy <= N&&zz > 0 && zz <= N)
                    cnt++;
                map[xx][yy][zz] = 1;
            }
    for(int x = a2 - 2;x <= a2 + 2;x++)
        for(int y = b2 - 2;y <= b2 + 2;y++)
            for(int z = c2 - 2;z <= c2 + 2;z++) {
                int xx = x <= 0 ? N + x : x > N ? x - N : x;
                int yy = y <= 0 ? N + y : y > N ? y - N : y;
                int zz = z <= 0 ? N + z : z > N ? z - N : z;
                if(!map[xx][yy][zz] && xx > 0 && xx <= N&&yy > 0 && yy <= N&&zz > 0 && zz <= N)
                    cnt++;
            }
    printf("%d\n",cnt);
    return true;
}


int main() {
    while(Do());
    return 0;
}