#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <memory>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
 
#define debug 0
 
/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
 
int a,b;
bool Do(){
    if(scanf("%d%d",&a,&b)==EOF)
        return false;
    int ans=0;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            if(i==j)
            ans+=(a-i+1)*(b-j+1);
    printf("%d\n",ans);
 
}
 
int main(){
    #if debug
    freopen("in.txt","r",stdin);
    #endif
    while(Do());
    return 0;
}