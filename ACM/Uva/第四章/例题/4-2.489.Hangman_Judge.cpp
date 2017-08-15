#include <cstdio>
#include <iostream>
using namespace std;
int main(){
        //freopen("in.txt","r",stdin);
        int Round;
        for(scanf("\n%d\n",&Round);Round!=-1;scanf("\n%d\n",&Round)){
                printf("Round %d\n",Round);
                int sit=0;
                int wrong=0;
                int right=0;
                bool a[26]={0};
                bool b[26]={0};
                int len=0;
                char c;
                while((c=getchar())!='\n')a[c-97]=true;
                for(int i=0;i<26;i++)if(a[i]==true)len++;
                //printf("\nlen=%d\n",len);
                while((c=getchar())!='\n'){
                                //printf("      c=%c\n",c);
                        if(a[c-97]!=true)wrong++;
                        else if(b[c-97]!=true){
                                b[c-97]=true;
                                right++;
                                //printf("right ");
                        }

                        if(wrong>6){sit=1;break;}
                        if(right==len){sit=2;break;}
                }
                if(sit==0){
                        printf("You chickened out.");
                }else if(sit==1){
                        printf("You lose.");
                        while(getchar()!='\n'){;}
                }else{
                        printf("You win.");
                        while(getchar()!='\n'){;}
                }
                printf("\n");
        }
        return 0;
}
