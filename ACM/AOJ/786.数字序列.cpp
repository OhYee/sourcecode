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
 
const int maxn = 50;
int f[maxn];
int A,B;
 
bool flag[maxn][maxn];
 
bool Do() {
    int n;
    scanf("%d%d%d",&A,&B,&n);
    if(A == 0 && B == 0 && n == 0)
        return false;
    A %= 7;
    B %= 7;
    memset(f,0,sizeof(f));
    memset(flag,false,sizeof(flag));
    f[1] = f[2] = 1;
    int T;
    for(int i = 3;;i++) {
        int a = (A*f[i - 1]) % 7;
        int b = (B*f[i - 2]) % 7;
        f[i] = (a + b) % 7;
        if(flag[a][b]) {
            T = i - 3;
            break;
        }
        flag[a][b] = true;
    }
 
 
    printf("%d\n",f[n = (n % T) ? (n % T) : T]);
 
    return true;
}
 
int main() {
    while(Do());
    return 0;
}