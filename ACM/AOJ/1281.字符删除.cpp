#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 25;
char s[maxn];
char c[maxn];

void de(int pos)
{
    int len  = strlen(s);
    for(int i=pos; i<len;++i)
        s[i] = s[i+1];
}

int main()
{
    freopen("in.txt","r",stdin);

    gets(s);
    gets(c);
    //scanf("%s\n%c",s,&c);
    while(1){
        bool flag = true;
        int len = strlen(s);
        for(int i=0;i<len;++i){
            if(s[i]==c[0]){
                de(i);
                flag=false;
                break;
            }
        }
        if(flag)
            break;
    }
    printf("%s",s);
    return 0;
}


