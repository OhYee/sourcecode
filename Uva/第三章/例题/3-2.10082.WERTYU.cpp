#include<cstdio>
char a[]={"`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./qwertyuiopasdfghjklzxcvbnm"};
int main(){
       //freopen("in.txt","r",stdin);
       char ch;
       bool has=false;
       while((ch=getchar())!=EOF){
              has=false;
              for(int i=0;i<72;i++){
                     if(ch==a[i]){
                            printf("%c",a[i-1]);
                            has=true;
                            break;
                     }
              }
              if(has==false)printf("%c",ch);
       }
       return 0;
}
