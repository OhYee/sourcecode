//搜索循环串时 上一个不是循环串的可能把真正的循环串
/*

15
a
aa

aaa


ab

aba
abca

ababa
aabaa
aaabaa
aabaaa

abcabcabcd

aaaaaaaaab

abcdabce

aabaabaabaabaab

aabaaaba



*/


#include <cstdio>
#include <memory>
#include <cstdlib>
#include <cstring>
using namespace std;

char str[104];
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    while(n--){
        scanf("%s",str);
        int len=strlen(str); 
        for(int k,i=1;i<=len;++i)
            if(len%i==0) {
                for(k=i;k<len;++k)
                    if(str[k]!=str[k%i])
                        break;
                if(k==len){
                    printf("%d\n",i);
                    break;
                }
        }
        if(n)printf("\n");
    }
    return 0;
}

/*
int main(){
    freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    while(N){
        char s[105];
        scanf("%s",s);
        if(s[0]=='\0')continue;
        N--;
        int it,len=1;
        for(it=1;s[it]!='\0';it++)
            if(s[it]!=s[it%len])
                len=it+1;
        if(it%len)len=it;
        printf("%d\n\n",len);
    }
    return 0;
}
*/