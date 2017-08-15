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
using namespace std;

const int maxn = 500005;
int kase = 1;

struct Node {
    int s;
    int v;
    int right;
    //bool operator < (const Node &rhs)const {
        //return s < rhs.s;
    //}
    bool operator < (const Node &rhs)const {
        return v < rhs.v;
    }
    bool operator > (const Node &rhs)const {
        return v > rhs.v;
    }
    static bool compare(Node &a,Node &b) {
        return a.s < b.s;
    }
};
Node node[maxn];
Node ans[maxn];


bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&node[i].s,&node[i].v);
        //dp[i] = 0;
    }

    /*
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < i;j++)
            if(node[i] > node[j] || j == 0) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        ans = max(ans,dp[i]);
    }
    */
    sort(node + 1,node + 1 + n,Node::compare);

    ans[1] = node[1];
    int len = 1;
    for(int i = 2; i <= n; ++i) {
        if(node[i] > ans[len])
            ans[++len] = node[i];
        else {
            Node *t = lower_bound(ans + 1,ans + 1 + len,node[i]);
            *(t) = node[i];
        }
    }

    if(len == 1)
        printf("Case %d:\nMy king, at most %d road can be built.\n\n",kase++,len);
    else
        printf("Case %d:\nMy king, at most %d roads can be built.\n\n",kase++,len);
    return true;
}

int main() {
    while(Do());
    return 0;
}