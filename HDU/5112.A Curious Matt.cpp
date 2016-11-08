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
using namespace std;

const int maxn = 10005;
struct Node {
    int x;
    int t;
    bool operator < (const Node &rhs)const {
        return t < rhs.t;
    }
};
Node node[maxn];

void Do() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&node[i].t,&node[i].x);
    }
    sort(node + 1,node + 1 + n);
    double Max = 0.0;
    for(int i = 2;i <= n;i++) {

        Max = max(Max,
            abs(
            (double)
            (node[i].x - node[i-1].x) / 
            (node[i].t - node[i-1].t)
            )
        );
    }
    printf("%.2f\n",Max);
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++) {
        printf("Case #%d: ",i);
        Do();
    }
        
    return 0;
}