#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <ctime>
using namespace std;
 
#define REP(n) for(int o=0;o<n;o++)
 
pair<int,int> p[205];
const int maxn =205;

int cob(int n)  {
  if (n == 3) return 1;
  else {
    int i = n, a = n, b = n - 3;
    while (i >= 2) a *= --i;
    i = n - 3;
    while (i >= 2) b *= --i;
    return a / (6 * b);
  }
}

bool Do() {
    int n;

    int count = 0, i = 0;
    signed int x[maxn], y[maxn];

    n = rand()%100;
    REP(n) {
        int tx,ty;
        x[o]=tx = rand()%100;
        y[o]=ty = rand()%100;
        p[o] = pair<int,int>(tx,ty);
    }
    printf("in\n");
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
printf("a\n");
            int ans=0;
    if (n == 1 || n == 2) ans=0;
    else {
    int j = 0, k = 0;
    for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n - 1; j++) {
    for (k = j + 1; k < n; k++) {
    if (((x[j] - x[i]) == 0) || ((x[k] - x[j] == 0))) {
    if (((x[j] - x[i]) == 0) && ((x[k] - x[j] == 0))) {
    count++; 
    continue;
    }
    }
    else if ((y[j] - y[i]) / (x[j] - x[i]) == (y[k] - y[j]) / (x[k] - x[j])) count++;
    }
    }
    ans =cob(n)-count;
    }

    printf("%d %d\n",cnt,ans);
 
    return true;
}
 
int main() {
  srand((int)time(0));
    while(Do());
    return 0;
}

