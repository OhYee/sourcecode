#include <cstdio>
int main(){
       //freopen("in.txt","r",stdin);
       char ch;
       bool left=true;
       //scanf("%c",ch);

       while((ch=getchar())!=EOF){
              if(ch=='"'){printf("%s",left==true?"``":" ''");left=left==true?false:true;}
              else printf("%c",ch);
              //ch=getchar();
       }
       return 0;
}
