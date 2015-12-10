#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char s1[110],s2[110];
void Do(){


        int len=strlen(s1);
        int a[26]={0};
        int b[26]={0};
        for(int i=0;i<len;i++){
                a[(int)s1[i]-65]++;
                b[(int)s2[i]-65]++;
        }
        sort(a,a+26);
        sort(b,b+26);
        for(int i=0;i<26;i++){
                if(a[i]!=b[i]){printf("NO");return;}
        }
        printf("YES");
        return;
}
int main(){
        //freopen("in.txt","r",stdin);
        while(scanf("%s%s",&s1,&s2)!=EOF){
                Do();
                printf("\n");
        }
        return 0;
}
