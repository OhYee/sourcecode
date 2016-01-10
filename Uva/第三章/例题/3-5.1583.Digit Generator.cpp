#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
void Do(){
        char number;
        int ans[10]={0};
        while((number=getchar())!='\n'){
                if(number==EOF)break;
                ans[number-48]++;
        }
        for(int i=0;i<=9;i++){
                printf("%d ",ans[i]);
        }
        printf("\n");
}
int main(){
       freopen("in.txt","r",stdin);
       int n;
       scanf("%d",&n);
       getchar();
       while(n){
                n--;
                Do();
       }
       return 0;
}
