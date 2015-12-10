#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

string s1,s2;

void Do(){
        int len=s1.size();
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

}
int main(){
        freopen("in.txt","r",stdin);
        while(cin>>s1>>s2){
                Do();
                printf("\n");
        }
        return 0;
}
