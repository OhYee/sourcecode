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

const int maxn = 105;

char map[maxn][maxn];
const int delta[] = {0,0,1,-1};

bool Do() {
    int n,m;
    int x1,y1,x2,y2;
    if(scanf("%d%d",&n,&m) == EOF)
        return false;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            map[i][j] = '.';

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            char temp;
            scanf("\n%c\n",&temp);
            if(temp == 'A') {
                x1 = i;
                y1 = j;
            }
            if(temp == 'B') {
                x2 = i;
                y2 = j;
            }
            if(temp == 'T') {
                temp = '#';
                for(int k = 0;k < 4;k++) {
                    int xx = i + delta[k];
                    int yy = j + delta[3 - k];
                    if(xx >= 0 && xx < n && yy >=0 && yy < m)
                        map[xx][yy] = '#';
                }
                for(int k = 2;k < 4;k++) {
                    for(int l = 2;l < 4;l++) {
                        int xx = i + delta[k];
                        int yy = j + delta[l];
                        if(xx >= 0 && xx < n && yy >= 0 && yy < m)
                            map[xx][yy] = '#';
                    }
                }
            }
            if(temp == '#')
                map[i][j] = '#';
        }
    /*
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
    */

    queue <pair<int,int> > Q;
    int len[maxn][maxn] = {0};
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            len[i][j] = -1;
    len[x1][y1] = 0;
    Q.push(pair<int,int>(x1,y1));
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(x == x2 && y == y2)
            break;
        for(int i = 0;i < 4;i++) {
            int xx = x + delta[i];
            int yy = y + delta[3 - i];
            if(xx >= 0 && xx < n && yy>=0 && yy < m && map[xx][yy]=='.' && len[xx][yy] == -1) {
                len[xx][yy] = len[x][y] + 1;
                Q.push(pair<int,int>(xx,yy));
            }
        }
    }
    printf("%d\n",len[x2][y2]);

    return true;
}

int main() {
    while(Do());
    return 0;
}
