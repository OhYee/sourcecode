#include<cstdio>
#include<string.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
       //freopen("in.txt","r",stdin);

       char ch[25];
       char Re1[]="AEHIJLMOSTUVWXYZ12358";
       char Re2[]="A3HILJMO2TUVWXY51SEZ8";

       string t[4]={" -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string."," -- is a mirrored palindrome."};
       while(scanf("%s",&ch)==1){
              bool palindrome=true;
              bool mirrored=true;
              int len=strlen(ch);
              for(int i=0;i<len;i++){
                     if(ch[i]!=ch[len-i-1])palindrome=false;
                     int temp=-1;
                     for(int j=0;j<21;j++)if(Re1[j]==ch[i])temp=j;
                     if(temp==-1||Re2[temp]!=ch[len-i-1])mirrored=false;
              }
              cout<<ch<<t[palindrome+mirrored*2]<<endl<<endl;
       }

       return 0;
}
