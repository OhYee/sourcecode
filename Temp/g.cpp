#include <cstdio>
using namespace std;
char s[20];

void dfs(int len,int t){
    if(t==len){
        s[t]='\0';
        for(int i=1;i<=len;++i){
            printf("%d\n%s\n",i,s);
        }
        return;
    }
    for(char i='a';i<='f';++i){
        s[t]=i;
        dfs(len,t+1);
    }
    
}

int main(){
    freopen("out.txt","w",stdout);
    for(int i=1;i<10;++i){
        dfs(i,0);
    }
    return 0;
}