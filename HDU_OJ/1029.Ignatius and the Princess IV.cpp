#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)

/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/

/*
	题意：
		输入N个数
		找出其中一个数目最多的(至少一半)
    由于答案至少有一半，所以其数目可以抵消其他所有数值
    因此，记录当前答案，每有一个相同的，权值+1，否则权值-1
    当权值为0时更新答案
    最后保留的答案就是最终答案
*/

bool Do(){
    int N;
    if(scanf("%d",&N)==EOF)
        return false;

    int ans;//答案
    int cnt=0;//已有答案的权值

    REP(N){
        int temp;//读入的数
        scanf("%d",&temp);
        if(cnt==0){//更新答案
            ans=temp;
            cnt++;
        }else{
            if(temp==ans)//更新权值
                cnt++;
            else
                cnt--;
        }
    }
    printf("%d\n",ans);
    return true;
}

int main(){
    #if debug
    freopen("in.txt","r",stdin);
    #endif // debug
    while(Do());
    return 0;
}
