/*
    By:OhYee
    Github:OhYee
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
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 512 + 5;
bool d[maxn][maxn];

//将1~n-1行的内容拷贝两份在n~2n-2行（超过maxn时返回）
void copy(int n) {
    for(int i = 1;i < n;i++) {
        if(i + n - 1 < maxn)
            for(int j = 1;j <= i;j++)
                d[i + n - 1][j] = d[i + n - 1][j + n - 1] = d[i][j];
        else
            break;
    }
}

int main() {
    memset(d,false,sizeof(d));
    d[1][1] = 1;

    for(int i = 2;i < maxn;i = 2 * i - 1)
        copy(i);

    int n;
    while(scanf("%d",&n) != EOF)
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= i;j++) {
                printf("%c",d[i][j] ? '*' : ' ');
            }
            printf("\n");
        }
    return 0;
}