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

 
const int maxn =2005;
bool Do(){
    char c;
    int ans=0;
    c=getchar();
    while(!(c=='M'||c=='W'||c=='O')){
        if(c==EOF)
            return false;
        c=getchar();
    }
    while(c=='M'||c=='W'||c=='O'){
        if(c=='M')
            ans+=8;
        if(c=='W')
            ans+=12;
        if(c=='O'){
            printf("%d\n",ans);
        }
        c=getchar();
    }
 
}
 
int main(){
    #if debug
    freopen("in.txt","r",stdin);
    #endif
    while(Do());
    return 0;
}