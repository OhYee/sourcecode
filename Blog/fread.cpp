#include <stdio.h>

void read(){
       #define filepath "data.txt"
       FILE* file = fopen(filepath, "rb");

       int size = filelength(fileno(file));

       char *buf=new char[size];

       int len = fread(buf,1,size,stdin);
       buf[len] = '\0';

       for (char *p=buf;*p && p-buf<len;p++){
              if (*p == ' '||*p=='\n'){
                     numbers[++i]=0;
              }else{
                     numbers[i] = numbers[i] * 10 + *p - '0';
              }
       }
       fclose(file);
}

int main()
{

}



const int MAXS = 60*1024*1024;
char buf[MAXS];

void analyse(char *buf,int len = MAXS)
{

}


const int MAXN = 10000000;
const int MAXS = 60*1024*1024;

int numbers[MAXN];
char buf[MAXS];

void fread_analyse()
{

}
