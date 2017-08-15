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
 
const int maxn = 1000005;
 
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
 
bool  Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;
 
    printf("%d=",n);
    if((n < maxn) && (!isNotPrime[n] || n == 1)) {
        printf("%d\n",n);
    } else {
        bool first = true;
        for(int i = 0;i < num_prime && n>1;i++) {
            while(!(n%prime[i])) {
                if(!first)
                    printf("*");
                first = false;
                printf("%d",prime[i]);
                n /= prime[i];
            }
        }
        printf("\n");
    }
 
    return true;
}
 
int main() {
    Prime();
    while(Do());
    return 0;
}
