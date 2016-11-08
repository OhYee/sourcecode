/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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

const int maxn = 1005;

struct Node {
    int n;
    int speed;
    int weight;
    bool operator > (const Node& rhs)const {
        return (speed > rhs.speed) && (weight < rhs.weight);
    }
    bool operator < (const Node& rhs)const {
        if(weight == rhs.weight)
            return speed > rhs.speed;
        return weight < rhs.weight;
    }
};

Node mice[maxn];
int dp[maxn];
int last[maxn];
stack<int> s;

void Do() {
    while(!s.empty())
        s.pop();
    memset(dp,0,sizeof(dp));

    int n = 1;
    while(scanf("%d%d",&mice[n].weight,&mice[n].speed) != EOF) {
        mice[n].n = n;
        n++;
    }
    n--;

    sort(mice + 1,mice + n + 1);

    int Maxpos = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < i;j++)
            if(mice[j] > mice[i] || j == 0)
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }
        if(dp[Maxpos] < dp[i])
            Maxpos = i;
    }

    printf("%d\n",dp[Maxpos]);

    int k = Maxpos;
    while(k) {
        s.push(k);
        k = last[k];
    }
    while(!s.empty()) {
        int t = s.top();
        printf("%d\n",mice[t].n);
        s.pop();
    }

}

int main() {
    Do();
    return 0;
}