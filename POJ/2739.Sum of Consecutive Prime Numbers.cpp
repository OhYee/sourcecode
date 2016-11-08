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

typedef long long LL;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 100005;


int prime[maxn] = {0},num_prime = 0;
bool isNotPrime[maxn] = {1,1};

LL cnt[maxn];
LL sum[maxn];

bool Do() {
    int n;
    cin >> n;
    if(n==0)
        return false;
    cout << cnt[n] << endl;

    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    for(long i = 2;i<maxn;i++) {
        if(!isNotPrime[i])prime[num_prime++] = i;
        for(int j = 0;j<num_prime&&i*prime[j]<maxn;j++) {
            isNotPrime[i*prime[j]] = true;
            if(!(i%prime[j]))break;
        }
    }

    memset(cnt,0,sizeof(cnt));

    sum[0] = prime[0];
    for(int i = 1;i < num_prime;i++)
        sum[i] = sum[i - 1] + prime[i];

    for(int i = 0;i < num_prime;i++) {
        if(sum[i] < maxn)
            cnt[sum[i]]++;
        for(int j = i + 1;j < num_prime;j++) {
            LL s = sum[j] - sum[i];
            if(s < maxn)
                cnt[s]++;
        }
    }
            

    while(Do());

    return 0;
}