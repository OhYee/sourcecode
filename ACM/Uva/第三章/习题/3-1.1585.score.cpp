#include<cstdio>
#include<cstring>
using namespace std;
void Do(){
        char c[200];
        memset(c,0,sizeof(c));
        scanf("%s",&c);
        int a=0;
        int score=0;
        for(int i=0;c[i]!=0;i++){
                if(c[i]=='O')a++;
                if(c[i]=='X')a=0;
                score+=a;
        }
        printf("%d\n",score);
}

int main(){
        //freopen("in.txt","r",stdin);
        int n;
        scanf("%d",&n);
        while(n){
                n--;
                Do();
        }
        return 0;
}
