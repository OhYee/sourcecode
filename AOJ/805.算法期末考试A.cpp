/*
By:OhYee
Github:OhYee
HomePage:http://www.oyohyee.com
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
#include <map>
#include <set>
using namespace std;
 
//DEBUG MODE
#define debug 0
 
//循环
#define REP(n) for(int o=0;o<n;o++)
 
//const int INF = (2<<30)-1;
 
const int maxn = 15;
char s[maxn];
bool flag[maxn];
char out[maxn];
 
void DFS(char *s,int pos) {
    int len = strlen(s);
    if(pos == len) {
        out[pos] = '\0';
        printf("%s\n",out);
    }
    for(int i = 0;i < len;i++) {
        if(!flag[i]) {
            flag[i] = true;
            out[pos] = s[i];
            DFS(s,pos+1);
            flag[i] = false;
        }
    }
}
 
bool Do() {
    if(scanf("%s",s) == EOF)
        return false;
    int len = strlen(s);
    sort(s,s + len);
    memset(flag,false,sizeof(flag));
 
    DFS(s,0);
    return true;
}
 
int main() {
    while(Do());
    return 0;
}