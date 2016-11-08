#include <cstdio>
#include <cstring>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

struct node{
    int a,b;
};

bool Do();
int visited(int a,int b,node n[],int len);
int main(){
    //freopen("in.txt","r",stdin);
    while(Do());
    return 0;
}

bool Do(){
    int a,b;
    node mark[10000];
    int cnt=1;
    int decimal[10000];

    if(scanf("%d%d",&a,&b)==EOF)return false;
    REP(10000)mark[o]={0,b};
    REP(10000)decimal[o]=-1;
    
    int x=(a%b)*10;
    while(1){
        //printf("    %d / %d = %d ...... %d       mark[%d]={%d,%d}\n",x,b,x/b,x%b,cnt,x,b);
        decimal[cnt]=x/b;
        if(visited(x,b,mark,cnt))break;
        mark[cnt]={x,b};
        x=(x%b)*10;
        cnt++;
    }
    cnt--;
    //REP(cnt+1)printf("    mark[%d]={%d,%d}\n",o,mark[o].a,mark[o].b);
    int begin=visited((mark[cnt].a%b)*10,mark[cnt].b,mark,cnt);

    //printf("\n\n%d\n\n",begin);
    printf("%d/%d = %d.",a,b,a/b);
    for(int i=1;i<=cnt;i++){
        if(begin==i)printf("(");
        printf("%d",decimal[i]);
        if(i==50){
            printf("...");
            break;
        }
    }
    if(begin==0)printf("(0");
    printf(")\n   %d = number of digits in repeating cycle\n\n",begin==0?1:cnt-begin+1);
    return true;
}

int visited(int a,int b,node n[],int len){
    for(int o=1;o<=len;o++){
        if(n[o].a==a&&n[o].b==b){
            return o;
        }
    }
    return 0;
}