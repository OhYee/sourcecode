#include <cstdio>
#include <iostream>
using namespace std;

void ReadDouble(double *dou,char *ch){
        int zs=0;
        double xs=0;
        char c;
        bool is_zs=true;

        while(c=getchar(),(c>='0'&&c<='9')||c=='.'){
                if(c=='.'){
                        is_zs=false;
                        continue;
                }
                if(is_zs==true){
                        zs*=10;
                        zs+=(int)(c-'0');
                }else{
                        //printf("xs %f\n",xs);
                        xs*=10.0;
                        //printf("xs %f\n",xs);
                        //printf("%d\n",(c-'0'));
                        xs+=(int)(c-'0');
                        //printf("xs %f\n",xs);

                }
        }

        //printf("get %c\n",c);
        //printf("zs %d   xs %f\n",zs,xs);
        while(xs>=1)xs/=10;
        *ch=c;
        *dou=(double)zs+xs;
        //printf("zs %d   xs %f\n",zs,xs);
        return;
}

int main(){
        double ans=0;
        char ch,ch2='+';
        double a;

        cout<<"Enter a sentence:";
        while(ReadDouble(&a,&ch),ch!='\n'){
                //printf("READ %f %c\n",a,ch);
                if(ch2=='+')ans+=a;
                if(ch2=='-')ans-=a;
                if(ch2=='*')ans*=a;
                if(ch2=='/')ans/=a;
                ch2=ch;
        }
        //ReadDouble(&a,&ch);
        if(ch2=='+')ans+=a;
        if(ch2=='-')ans-=a;
        if(ch2=='*')ans*=a;
        if(ch2=='/')ans/=a;
        printf("eREAD %f %c\n",a,ch);

        cout<<"Value of sentence:"<<ans;
        //printf("\n%f",ans);
        return 0;
}
