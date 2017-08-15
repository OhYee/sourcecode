#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

bool Do();

int main(){
    //freopen("in.txt","r",stdin);
    while(Do());
    return 0;
}

bool Do(){
    const int maxn=105;
    char s1[maxn],s2[maxn];
    REP(maxn)
        s1[o]=s2[o]='\0';
    if(scanf("%s%s",s1,s2)==EOF)
        return false;
    int len1=strlen(s1),len2=strlen(s2);
    int Min=len1+len2;
    for(int i=-len1;i<=len2;i++){
        bool can=true;
        for(int j=0;j<len1;j++)
            if(i+j>=0&&i+j<len2&&s1[j]=='2'&&s2[i+j]=='2')
                can=false;
        //printf("    %d %d\n",i,max(len2,len1+i)-min(i,0));
        if(can)
            Min=min(Min,max(len2,len1+i)-min(i,0));
    }
    printf("%d\n",Min);
    return true;
}
