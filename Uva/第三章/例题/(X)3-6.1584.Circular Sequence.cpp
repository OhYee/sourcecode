#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
/*
int n;
char t[101];
int ans=0;
int len;
int better(int a){
        for(int i=0;i<n;i++){
                int x=ans+i;
                int y=a+i;
                if(x>=len)x-=len;
                if(y>=len)y-=len;
                if(t[x]>t[y])return a;
                if(t[x]<t[y])return ans;
        }
        return ans;
}

int main(){
        //freopen("in.txt","w",stdin);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                ans=0;
                memset(t,0,sizeof(t));
                scanf("%s",&t[i]);
                for(int len=0;t[len]!=0;len++);
                len--;
                for(int j=0;j<len;j++){
                        ans=better(j);
                }
                printf("%d",ans);
                for(int j=ans;j==ans-1;j++){
                        if(j>len)j-=len;
                        printf("%c",t[j]);
                }
                printf("\n");
        }

        return 0;
}
*/

int better(string st){
        int len=strlen(st);
        int best=0;
        for(int i=1;i<len;i++){
                for(int j=0;j<len;j++){
                        int a=best+j>=len?best+j-len:best+j;
                        int b=i+j>=len?i+j-len:i+j;
                        if(st[a]<st[b])break;
                        if(st[a]>st[b]){best=i;break;}
                }
        }
        return best;
}

void Do(){
        string s;
        scanf("%s",&s);
        int begin=better(s);
        int len=strlen(s);
        int n=begin;
        for(int i=0;i<len;i++){
                n++;
                n=n>=len?n-len:n;
                printf("%c",s[n]);
        }
        printf("\n");
}
int main(){
        Do();
        return 0;
}
