/*
By:OhYee
Email:oyohyee@oyohyee.com
QQ:896817156
GitHub:OhYee
*/

#include <cstdio>
#include <cstring>

const int maxn=40;

int n;
int map[maxn][maxn];

void init();
void Do(int &x,int &y,int k);

int main(){
    freopen("2015magic.in","r",stdin);
    freopen("2015magic.out","w",stdout);

    void init();
    scanf("%d",&n);

    int x;
    int y;
    x=1;
    y=n/2+1;
    map[x][y]=1;

    for(int k=2;k<=n*n;k++){
        Do(x,y,k);
        map[x][y]=k;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void init(){
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            map[i][j]=0;
    return;
}

void Do(int &x,int &y,int k){
    //printf("%d %d - ",x,y);
    if(x==1&&y!=n){
        x=n;
        y++;
    }
    else{
    if(x!=1&&y!=n){
        if(map[x-1][y+1]==0){
            x--;
            y++;
        }else{
            x++;
        }
    }
    else{
    if(y==n&&x!=1){
        y=1;
        x--;
    }
    else{
    if(x==1&&y==n){
        x++;
    }
    }
    }
    }
    
    //printf("%d %d\n",x,y);
    return;
}