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

const int maxn = 1005;

struct Node {
    int a,b;
    int sum;
    bool operator < (const int &rhs)const {
        return sum < rhs;
    }
    bool operator < (const Node &rhs)const {
        return sum < rhs.sum;
    }
};

int n;
int a[maxn];
Node sum[maxn*maxn];

bool Do() {
    cin >> n;
    if(n == 0)
        return false;
    int pos = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a,a + n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < i;j++) {
            sum[pos].a = j;
            sum[pos].b = i;
            sum[pos++].sum = a[i] + a[j];
        }

    sort(sum,sum + pos);
    bool flag = true;
    int ans;

    for(int i = n - 1;i >= 0 && flag;i--)
        for(int j = n - 1;j >= 0 && flag;j--) {
            int minute = a[i] - a[j];
            int it = lower_bound(sum,sum + pos,minute) - sum;
            for(it;it < pos;it++) {
                if(sum[it].sum != minute)
                    break;
                if(sum[it].b < j && i != j) {
                    ans = a[i];
                    flag = false;
                    break;
                }
            }
        }

    if(flag)
        cout << "no solution" << endl;
    else
        cout << ans << endl;


    return true;
}

int main() {
    while(Do());
    return 0;
}