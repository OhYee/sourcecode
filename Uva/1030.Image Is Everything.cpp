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
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

#define  REP(o,n) for(int o=0;o<n;o++)

const int maxn = 16;

//前 左 后 右 顶 底
char view[6][maxn][maxn];
char cube[maxn][maxn][maxn];
int n;

bool lp(bool sx,int &x,int &y,int &z,int a = -1,int b = -1,int c = -1) {
    int *i = &a;
    if(a == -1)
        i = &a;
    if(b == -1)
        i = &b;
    if(c == -1)
        i = &c;
    if(sx) {
        for((*i) = 0;(*i) < n;(*i)++) {
            if(cube[a][b][c] != -1) {
                x = a;
                y = b;
                z = c;
                return true;
            }
        }
    } else {
        for((*i) = n - 1;(*i) >= 0;(*i)--) {
            if(cube[a][b][c] != -1) {
                x = a;
                y = b;
                z = c;
                return true;
            }
        }
    }
    return false;
}

bool Get(int v,int a,int b,int &x,int &y,int &z) {
    if(v == 0)//从前往后
        return lp(true,x,y,z,-1,a,b);
    else if(v == 1)//从左往右
        return lp(true,x,y,z,n - 1 - b,a,-1);
    else if(v == 2)//从后往前
        return lp(false,x,y,z,-1,a,n - 1 - b);
    else if(v == 3)//从右往左
        return lp(false,x,y,z,b,a,-1);
    else if(v == 4)//从上到下
        return lp(true,x,y,z,n - 1 - a,-1,b);
    else//从下到上
        return lp(false,x,y,z,a,-1,b);
}

int Do() {
    cin >> n;
    if(n == 0)
        return false;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < 6;j++)
            for(int k = 0;k < n;k++)
                cin >> view[j][i][k];

    memset(cube,0,sizeof(cube));

    bool flag = true;

    while(flag) {
        flag = false;
        for(int i = 0;i < 6;i++)
            for(int j = 0;j < n;j++)
                for(int k = 0;k < n;k++) {
                    int x,y,z;
                    if(Get(i,j,k,x,y,z)) {
                        if(view[i][j][k] == '.') {
                            //可以看透
                            cube[x][y][z] = -1;
                            flag = true;
                        } else {
                            if(cube[x][y][z] == 0) {
                                //未涂色的方块
                                cube[x][y][z] = view[i][j][k];
                                flag = true;
                            } else if(cube[x][y][z] != view[i][j][k]) {
                                //涂色产生矛盾
                                cube[x][y][z] = -1;
                                flag = true;
                            }
                        }
                    }
                }
    }

    int ans = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            for(int k = 0;k < n;k++)
                if(cube[i][j][k] != -1)
                    ans++;

    cout << "Maximum weight: " << ans << " gram(s)" << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());

    return 0;
}