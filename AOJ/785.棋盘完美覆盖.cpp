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
 
const int maxn = 45;
int f[maxn] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170};
void F(int i=2) {
    if(i == maxn)
        return;
    f[i] = f[i - 1] + f[i - 2];
    F(i + 1);
};
 
bool Do() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return false;
 
    printf("%d\n",f[n]);
 
    return true;
}
 
int main() {
    while(Do());
    return 0;
}