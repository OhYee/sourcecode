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
 
char Map[maxn][maxn];
int cnt;
int m,n;
 
void DFS(int i,int j) {
    Map[i][j] = '*';
    for(int d1 = -1;d1 <= 1;d1++)
        for(int d2 = -1;d2 <= 1;d2++)
            if(!(d1 == 0 && d2 == 0))
                if(i + d1 >= 0 && i + d1 < n &&
                    j + d2 >= 0 && j + d2 < m)
                    if(Map[i + d1][j + d2] == '@')
                        DFS(i + d1,j + d2);
}
 
bool Do() {
    if(scanf("%d%d",&n,&m) == EOF)
        return false;
    if(m == 0 || n == 0)
        return false;
 
    cnt = 0;
 
    for(int i = 0;i < n;i++)
        scanf("\n%s",&Map[i]);
 
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(Map[i][j] == '@') {
                cnt++;
                DFS(i,j);
            }
 
    printf("%d\n",cnt);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}