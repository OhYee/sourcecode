#include<cstdio>
using namespace std;
const int maxn = 105;
char s[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);

    int ans = 0;
    for(int i=0;i<n;++i){
        scanf("%s",s);

        if(s[0]=='T')
            ans+=4;
        else if(s[0]=='C')
            ans+=6;
        else if(s[0]=='O')
            ans+=8;
        else if(s[0]=='D')
            ans+=12;
        else
            ans+=20;

    }
    printf("%d\n",ans);
    return 0;
}
