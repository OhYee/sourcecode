/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

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
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

const int maxn = 20;
const int maxm = maxn*maxn / 2;
const int maxp = maxm;

int n,m,k;

pair<int,int> edge[maxm];
pair<int,int> plan[maxp];

//并查集
int f[maxn];
int findx(int x) {
    int r = x;
    while(f[r] != r)
        r = f[r];
    return r;
}

int vs_main() {
    scanf("%d%d%d",&n,&m,&k);
    REP(m) {
        int a,b;
        scanf("%d%d",&a,&b);
        edge[o] = pair<int,int>(a,b);
    }
    REP(k) {
        int a,b;
        scanf("%d%d",&a,&b);
        plan[o] = pair<int,int>(a,b);
    }
    //初始化并查集
    REP(n)
        f[o + 1] = o + 1;

    //开始添加路径
    //路径数目
    int cnt = 0;
    while(cnt != -1) {
        //是否存在不能完成的计划
        bool ok = true;
        int it;
        for(it = 0;it < k;it++) {
            if(findx(plan[it].first) != findx(plan[it].second)) {
                ok = false;
                break;
            }
        }
        if(ok)
            break;

        //还存在不能完成的计划it
        //找到一条最省的路连接it的两个城市(BFS求最短路)
        int v = findx(plan[it].first);//起点
        int s = findx(plan[it].second);//终点
        queue<int> Q;
        bool visited[maxn];
        memset(visited,false,sizeof(visited));
        int last[maxn];//该节点的上一节点
        memset(last,0,sizeof(last));

        Q.push(v);
        visited[v] = true;
        int t;
        while(!Q.empty()) {
            //访问下一节点
            t = Q.front();
            Q.pop();

            //路径已找到
            if(t == s) {
                ok = true;
                //将路径上所有点连入并查集
                while(last[t]) {
                    cnt++;
                    f[t] = v;
                    //printf("%d %d\n",t,last[t]);
                    t = last[t];
                }
                //清空队列
                while(!Q.empty())
                    Q.pop();
                break;
            }

            for(int i = 0;i < m;i++) {
                //路径压缩
                int u = findx(edge[i].first);
                int w = findx(edge[i].second);

                if(u == t || w == t) {
                    //这条路可以走
                    w = ((u == t) ? w : u);
                    u = t;
                    //v->u(k)->w->s
                    //如果下一节点未访问过
                    if(!visited[w]) {
                        Q.push(w);//压入队列
                        visited[w] = true;//标记节点
                        last[w] = u;//记录路径
                    }
                }
            }
        }
        if(!ok)
            cnt = -1;
    }
    printf("%d",(cnt!=-1)?(m - cnt):-1);
    return 0;
}
P