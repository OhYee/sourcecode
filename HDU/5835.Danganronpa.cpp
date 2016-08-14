/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリ0隶�
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

const int maxn = 15;
int a[maxn];

void Do() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a + n);
    int ans = 0;
    if(sum / 2 < a[n - 1]) {
        ans = (sum - a[n - 1]) * 2 + 1;
    } else {
        ans = sum;
    }
    cout << min(ans,sum / 2)<<endl;

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": ";
        Do();
    }
    return 0;
}