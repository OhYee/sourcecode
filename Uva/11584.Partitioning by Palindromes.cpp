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

int dp[maxn];
string s;

bool isPalindrome(int a,int b) {
    for(int it1 = a,it2 = b;it1 < it2;it1++,it2--)
        if(s[it1] != s[it2])
            return false;
    return true;
}

void Do() {
    cin >> s;
    int len = s.size();
    int ans = 0;

    dp[0] = 0;
    for(int i = 1;i <= len;i++) {
        dp[i] = dp[i - 1] + 1;
        for(int j = 1;j < i;j++)
            if(isPalindrome(j - 1,i - 1))
                dp[i] = min(dp[i],dp[j - 1] + 1);
    }

    cout << dp[len] << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++)
        Do();
    return 0;
}