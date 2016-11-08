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

const int maxn = 16;
const int delta[3][2] = {{-1,-1},{-1,1},{-2,0}};


int state[maxn];
int Map[maxn];

int n;
int kase = 1;

//比较两种状态,返回需要变成1的0的数量,不能完成返回-1
int Get(int res,int e) {
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int a = res & 1;
        int b = e & 1;

        res >>= 1;
        e >>= 1;

        if(a != b)
            if(a == 0)
                ans++;
            else
                return -1;
    }
    return ans;
}

inline int SetI(int num,int i,bool flag) {
    if(flag)
        return num | (1 << i);
    else
        return num & (~(1 << i));
}

inline bool GetI(int num,int i) {
    return num >> i & 1;
}

void Do() {
    cin >> n;
    int Min = INF;

    for(int i = 0;i < n;i++) {
        int m = 0;
        for(int j = 0;j < n;j++) {
            int t;
            cin >> t;
            m <<= 1;
            m = SetI(m,0,t);
        }
        Map[i] = m;
    }

    for(int k = 0;k < (1 << n);k++) {
        //枚举初始态
        int ans = 0;
        state[0] = k;

        int temp = Get(Map[0],state[0]);

        if(temp == -1)
            continue;
        else
            ans += temp;

        for(int i = 1;i < n;i++) {
            //处理第i行
            for(int j = 0;j < n;j++) {
                //处理第j个位置
                int sum = 0;
                for(int t = 0;t < 3;t++) {
                    int xx = i + delta[t][0];
                    int yy = j + delta[t][1];
                    if(xx >= 0 && yy >= 0 && xx < n && yy < n) {
                        sum += GetI(state[xx],yy);
                    }
                }
                if(sum & 1)
                    state[i] = SetI(state[i],j,1);
                else
                    state[i] = SetI(state[i],j,0);
            }

            temp = Get(Map[i],state[i]);
            if(temp == -1)
                break;
            else
                ans += temp;
        }

        if(temp == -1)
            continue;
        else 
            Min = min(Min,ans);
    }

    cout << "Case " << kase++ << ": ";
    if(Min == INF)
        cout << -1 << endl;
    else
        cout << Min << endl;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)
        Do();

    return 0;
}