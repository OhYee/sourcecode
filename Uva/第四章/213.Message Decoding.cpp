#include<cstdio>
#include<cstring>
using namespace std;

//Value



//Facation
int exp(int a,int b){//a^b
    ans=1;
    for(int i=0;i<b;i++)ans*=a;
    return ans;
}

int to_2(int n){//10 to 2


    int ans=0;
    while(n){
        ans*=10;
        ans+=n%2;
        n/=2;
    }
    return ans;
}
int to_10(int n){//2 to 10
    int ans=0;
    int u=1;
    while(n){
        ans+=(n%10)*u;
        u*=2;
        ans/=10;
    }
    return ans;
}

int read(int len,int * i){//From i read len
    int ans=0;
    for(int j=0;j<len;j++){
        ans+=s[i+j];
    }
    i+=j;
    return ans;
}

int get1(int len){
    ans=0;
    for(int i=0;i<len;i++){
        ans*=10;
        ans+=1;
    }
    return ans;
}

void Do(string s){
    int i=0;
    do{
        int temp=read(3,&i);
        int len=to_10(temp);
        do{
            int temp=read(len,&i);
            if(temp==get1(len))break;
            printf("%c",decord[len][to_10(temp)]);
        }while(1);
    }while(i==strlen(s)-1);
    printf("\n");
}

int main(){
    string s;
    scanf("%s",s);





    return 0;
}
