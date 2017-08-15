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
 
const int maxn = 45;
 
int prime[maxn] = {0},num_prime = 0;
bool isNotPrime[maxn] = {1,1};
 
void Prime() {
    for(long i = 2;i < maxn;i++) {
        if(!isNotPrime[i])prime[num_prime++] = i;
        for(int j = 0;j < num_prime&&i*prime[j] < maxn;j++) {
            isNotPrime[i*prime[j]] = true;
            if(!(i%prime[j]))break;
        }
    }
}
 
bool vis[maxn / 2];
int List[maxn / 2];
int pos;
bool dfs(){
    if(pos == 20) {
        if(isNotPrime[List[19] + List[0]])
            return false;
 
        bool first = true;
        for(int i = 0;i < 20;i++) {
            if(!first)
                printf(" ");
            first = false;
            printf("%d",List[i]);
        }
        return true;
    }
    for(int i = 1;i <= 20;i++) {
        if(vis[i])
            continue;
        if(isNotPrime[List[pos - 1] + i])
            continue;
        List[pos++] = i;
        vis[i] = true;
        if(dfs())
            return true;
        vis[i] = false;
        pos--;
    }
    return false;
}
 
bool  Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;
    memset(vis,false,sizeof(vis));
    pos = 0;
 
    List[pos++] = n;
    vis[n] = true;
    dfs();
    printf("\n");
 
    return true;
}
 
int main() {
    Prime();
    while(Do());
    return 0;
}