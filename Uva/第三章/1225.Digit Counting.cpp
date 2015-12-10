#include<cstdio>
using namespace std;

void Do(){
        char c;
        int res[10]={0};
        for(c=getchar();c>=48&&c<=57;c=getchar()){
                res[(int)c-48]++;
        }
        for(int i=0;i<=9;i++)printf("%d ",res[i]);
        printf("\n");
}

int main(){
        //freopen("in.txt","r",stdin);
        int n;
        scanf("%d\n",&n);
        while(n){
                Do();
                n--;
        }
        return 0;
}
