#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
 
#define REP(n) for(int o=0;o<n;o++)
 
pair<int,int> p[205];
bool Do() {
    int n;
    if(scanf("%d",&n) == EOF)
        return false;
    REP(n) {
        int x,y;
        scanf("%d%d",&x,&y);
        p[o] = pair<int,int>(x,y);
    }
    int cnt = 0;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
            for(int k = j + 1;k < n;k++) {
                if(i < j&&j < k) {
                    pair<int,int >a = p[i],b = p[j],c = p[k];
                    if(!(
                        (a.first == b.first&&a.first == c.first) ||
                        (a.second == b.second&&a.second == c.second) ||
                        ((double)(a.first - b.first) / (double)(a.second - b.second) ==
                            (double)(c.first - b.first) / (double)(c.second - b.second))
                        )) {
                        cnt++;
                        //printf("%d %d %d\n",i,j,k);
                    }
                }
            }
    printf("%d\n",cnt);
 
    return true;
}
 
int main() {
    while(Do());
    return 0;
}