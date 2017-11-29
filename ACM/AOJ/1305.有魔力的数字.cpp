
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 15;
char s[maxn];
int k;

void de(int pos)
{
    int len  = strlen(s);
    for(int i=pos; i<len;++i)
        s[i] = s[i+1];

}

int main()
{
    //freopen("in.txt","r",stdin);

    scanf("%s%d",s,&k);
    int len = strlen(s);
    int ans = 0;
    bool flag = false;

    while(len >= k)
    {
        //printf("%s\n",s);
        flag = true;
        for(int i=0; i<k; ++i)
        {
            //printf("s[%d]=%c\n",len-1-i,s[len-1-i]);
            if(s[len-1-i]!='0')
            {
                ++ans;
                de(len-1-i);
                flag = false;
                break;
            }
        }
        //printf("flag:%d\n",flag);

        if(flag)
            break;
        len = strlen(s);
    }
    if(flag)
        printf("%d\n",ans);
    else
        printf("%d\n",ans+len-1);

    return 0;
}


