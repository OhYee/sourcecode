#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10005;

int p1,p2,p3;
char s[maxn];
char s2[maxn];
char TEMP[maxn];

bool isdigit(char c)
{
    return c>='0'&&c<='9';
}
char xx(char c)
{
    if(c>='A'&&c<='Z')
        c+='a'-'A';
    return c;
}
char dx(char c)
{
    if(c>='a'&&c<='z')
        c-='a'-'A';
    return c;
}

void ins(int pos)
{
    strcpy(TEMP,s+pos+1);
    strcpy(s+pos,s2);
    int len = strlen(s);
    strcpy(s+len,TEMP);
}

void build(char a,char b)
{
    int pos = 0;

    for(int i=a+1; i<b; ++i)
    {
        char ch;

        // 处理顺序(p3)
        if(p3==1)
            ch=i;
        else
            ch=b-i+a;

        // 处理大小写(p1)
        if(p1==3)
            ch='*';
        else if(!isdigit(ch))
        {
            if(p1==1)
            {
                ch=xx(ch);
            }
            else
            {
                ch=dx(ch);
            }
        }

        //p2 重复次数
        for(int k=0; k<p2; ++k)
            s2[pos++]=ch;
    }
    s2[pos]='\0';
    //printf("build s2: %s\n",s2);
}


bool check(char c1,char c2){
    return ('0'<=c1&&c1<='9'&&'0'<=c2&&c2<='9')||('a'<=c1&&c1<='z'&&'a'<=c2&&c2<='z');
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d%d%s",&p1,&p2,&p3,s);

    while(1)
    {
        bool flag = true;
        int len = strlen(s);
        for(int i=1; i<len-1; ++i)
        {
            if(s[i]=='-' && s[i+1]>s[i-1])
            {
                if(!check(s[i-1],s[i+1]))
                    continue;

                build(s[i-1],s[i+1]);
                ins(i);
                flag=false;
                break;
            }
        }
        if(flag)
            break;
    }
    printf("%s\n",s);

    return 0;
}
