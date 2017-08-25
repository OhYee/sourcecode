#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 5005;
const int maxm =505;
const int maxk = 2005;

int a[maxn][maxm];
int n,m,k;
int len;

bool compare(int a,int b){
    return a > b;
}

struct node {
    int s,b;
    node(int _s,int _b):s(_s),b(_b) {}
    bool operator < (node a)const {
        return a.s > s;
    }
};

void merge(int *a,int *b,int *c){
    priority_queue<node> Q;
    for(int i = 0;i < len;i++)
        Q.push(node(a[i]+b[0],0));

    len = 0;
    for(int i = 0;i < k && !Q.empty();i++){
        ++len;
        node r = Q.top();
        Q.pop();
        c[i] = r.s;
        int t = r.b;
        if(t+1 < m)
            Q.push(node(r.s-b[t]+b[t+1],t+1));
    }
}

int main() {
    while(~scanf("%d%d%d",&n,&m,&k)) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
            sort(a[i], a[i]+m,compare);
        }

        len = m;
        for(int i = 1;i < n; i++)
            merge(a[0],a[i],a[0]);

        // for(int i = 0;i < max(m,k); i++)
        //     printf("%d ",a[0][i]);
        // printf("\n");

        printf("%d\n",a[0][k-1]);
    }

    return 0;
}