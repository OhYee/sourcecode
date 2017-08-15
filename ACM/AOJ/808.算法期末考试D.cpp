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
#include <set>
using namespace std;
 
//DEBUG MODE
#define debug 0
 
//循环
#define REP(n) for(int o=0;o<n;o++)
 
//const int INF = (2<<30)-1;
 
const int maxn = 55*2*2;
char flag[maxn];
 
 
void DFS(int a,int max,int pos) {
    if(a < 0)
        return;
    if(a == 0) {
        /*for(int i = 0;i < pos;i++) {
            if(i)
                printf("+");
            printf("%d",flag[i]);
        }
        printf("\n");*/
        flag[pos - 1] = '\0';
        printf("%s\n",flag);
        return;
    }
     
    for(int i = max;i >= 1;i--) {
        //将整数i转化成char
        int pos2 = pos;
        int bit = 1;
        int j = i;
        while(j) {
            j /= 10;
            bit *= 10;
        }
        bit /= 10;
        j = i;
        while(bit) {
            flag[pos2++] = (j / bit) + '0';
            j %= bit;
            bit /= 10;
        }
        //flag[pos] = i+'0';
        flag[pos2++] = '+';
        DFS(a - i,i,pos2);
        //flag[pos] = -1;
    }
}
 
bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
    DFS(n,n,0);
    return true;
}
 
int main() {
    while(Do());
    /*for(int i = 5;i <=6;i++)
        DFS(i,i,0);*/
    return 0;
}
