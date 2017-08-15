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
#include <bitset>
#include <iomanip> 
using namespace std;

const int maxn = 105;
int num[maxn];

bool Do() {
    int n,k;
    if(!(cin >> n >> k))
        return false;

    int p = n / k;

    memset(num,0,sizeof(num));

    for(int i = 1;i <= n;i++) {
        int t;
        cin >> t;
        if(t == 1)
            num[i%k]++;
    }


    int ans = 0;
    for(int i = 0;i < k;i++) {
        ans += min(p- num[i],num[i]);
    }

    cout << ans << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    while(Do());
    return 0;
}