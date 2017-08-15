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
using namespace std;

const int maxn = 505;
const int INF = 0x7FFFFFFF;

typedef __int64 LL;

LL Map[maxn][maxn];
LL sum1[maxn];
LL sum2[maxn];
LL sum3,sum4;

bool  Do() {
    int n;
    if(!(cin >> n))
        return false;

    int tx,ty;

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            cin >> Map[i][j];
            if(Map[i][j] == 0) {
                tx = i;
                ty = j;
            }
        }
    LL ans = -1;
    bool can = true;

    if(n == 1) {
        ans = 1;
        can = true;
    } else {
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        sum3 = sum4 = 0;

        for(int i = 1;i <= n;i++) {
            sum3 += Map[i][i];
            sum4 += Map[i][n - i + 1];
            for(int j = 1;j <= n;j++) {
                sum1[i] += Map[i][j];
                sum2[j] += Map[i][j];
            }
        }


        LL sum = 0;
        if(tx == 1)
            sum = sum1[2];
        else
            sum = sum1[1];

        ans = sum - sum1[tx];
        sum1[tx] += ans;
        sum2[ty] += ans;
        if(tx == ty)
            sum3 += ans;
        if(tx == n - ty + 1)
            sum4 += ans;

        for(int i = 1;i <= n;i++) {
            if(sum1[i] != sum || sum2[i] != sum) {
                can = false;
                break;
            }
        }
        if(sum3 != sum || sum4 != sum)
            can = false;
    }

    if(can && ans > 0)
        cout << ans << endl;
    else
        cout << "-1" << endl;

    return true;
}

int main() {
    while(Do());
    return 0;
}