#include <stdio.h>
#include <stdlib.h>

char map[10][10];
int round[4]={1,-1,0,0};
int r(){
    srand((unsigned)time(0));
    return rand()%3;
}
int can(int x,int y){
    if(x<0||y<0||x>10||y>10)return 0;
    if(map[x][y]!=',')return 0;
    return 1;
}
int go(int * x,int * y){
    //printf("\n(%d,%d) %c",*x,*y,map[*x][*y]);
    int i;
    if(map[*x][*y]=='Z')return 0;
    int has_road=0;
    for(i=0;i<4;i++){
        printf("  can  (%d,%d)   %d",*x+round[i],*y+round[3-i],can(*x+round[i],*y+3-round[i]));
        if(can(*x+round[i],*y+3-round[i])==1)has_road=1;
    }
    //printf("  %d   ",has_road);
    if(has_road==1){
        int xx,yy;
        do{
            int t=r();
            xx=*x+round[t];
            yy=*y+round[3-t];
        }while(can(xx,yy)!=1);
        map[xx][yy]=map[*x][*y]+1;
        *x=xx;
        *y=yy;
        //printf("   (%d,%d) %c",xx,yy,map[xx][yy]);
    }else return 0;
}

int main(){
    int i,j;
    for(i=0;i<10;i++)for(j=0;j<10;j++)map[i][j]=',';
    int x=0,y=0;
    map[x][y]='A';
    while(go(&x,&y)){
        ;
    }
    printf("\n");
    for(i=0;i<10;i++){
            for(j=0;j<10;j++)printf("%c",map[i][j]);
            printf("\n");
    }
}
